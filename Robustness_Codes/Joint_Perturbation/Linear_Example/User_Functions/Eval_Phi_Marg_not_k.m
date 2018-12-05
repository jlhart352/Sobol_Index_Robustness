function [ Y ] = Eval_Phi_Marg_not_k( X,k )

% Input: Nxp matrix Xk, integer k
% Output: Nx1 vector Y

% Evaluate \phi_{not k}(x_{not k}) at each row in X(:,not_k)

a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];
u = setdiff(1:3,k);

Y = ones(size(X,1),1);

for j = u
   Y = Y.*betapdf(X(:,j),a(j),b(j)); 
end


end