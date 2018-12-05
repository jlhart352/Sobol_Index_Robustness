function [ Y ] = Eval_Phi_Marginals( X )

% Input: Nxp matrix X
% Output: Nxp matrix Y

% Evaluate the marginal PDF for X_k at the k^th column of the matrix X,
% k=1,2,...,p

[N,p] = size(X);
a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];

Y = zeros(N,p);

for k = 1:p
   Y(:,k) = betapdf(X(:,k),a(k),b(k)); 
end


end

