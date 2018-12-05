function [ Y ] = Eval_Phi_Cond_not_k( X,k )

% Input: Nxp matrix X, integer k
% Output: Nx1 vector Y

% Evaluate the PDF of X|X_{not k}, i.e. phi_{X|X_{not k} at the rows of X

a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];

Y = betapdf(X(:,k),a(k),b(k));

end

