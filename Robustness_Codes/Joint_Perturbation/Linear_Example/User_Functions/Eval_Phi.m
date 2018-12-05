function [ Y ] = Eval_Phi( X )

% Input: Nxp matrix X
% Output: Nx1 vector Y

% Evaluate the PDF \phi(x) at each row in X

a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];

Y = ones(size(X,1),1);

for k = 1:3
   Y = Y.*betapdf(X(:,k),a(k),b(k)); 
end

end

