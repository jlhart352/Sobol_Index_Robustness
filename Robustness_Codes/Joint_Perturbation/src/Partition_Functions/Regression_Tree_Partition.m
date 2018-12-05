function [ R ] = Regression_Tree_Partition( X,Y,data_per_rec )

% Input a Nxp matrix X and Nx1 vector Y where Y=f(X)
% Return a cell R whose jth matrix is the bounds defining the jth rectangle

% Set dimensions
p = size(X,2);

num_var = p;
tree = fitrtree(X,Y,'MinLeafSize',data_per_rec,'NumVariablesToSample',num_var);

% Find the index of leaf nodes
Nodes = find(tree.Children(:,1)==0);
m = length(Nodes);

% Preallocate R
Omega = zeros(p,2);
Omega(:,2) = ones(p,1);

R = zeros(m,p,2);
for k = 1:m
   R(k,:,:) = Omega;
   L = Nodes(k);
   while L>0
      T1 = find(tree.Children(:,1)==L); 
      T2 = find(tree.Children(:,2)==L);
      
      if ~isempty(T1)
         v = str2double(tree.CutPredictor{T1}(2:end));
         R(k,v,2) = min(tree.CutPoint(T1),R(k,v,2));
         L = T1;
      elseif ~isempty(T2)
         v = str2double(tree.CutPredictor{T2}(2:end));
         R(k,v,1) = max(tree.CutPoint(T2),R(k,v,1));
         L = T2;
      else
          L = 0;
      end
      
   end
   
end


end

