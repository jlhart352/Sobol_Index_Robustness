function [ I ] = Find_Rectangle( X,R )

% Input a Nxp matrix X of points and a cell R whose jth matrix is the bounds defining the jth rectangle
% Return a Nx1 vector whose jth entry identifies the rectangle containing X(j,:)

N = size(X,1);
I = zeros(N,1);

p = size(X,2);

for k = 1:N
    j = 0;
    while I(k)==0
        j = j+1;
       if min(X(k,:)-reshape(R(j,:,1),1,p))>=0 && min(reshape(R(j,:,2),1,p) - X(k,:))>=0
          I(k) = j;
       end
    end
end

end

