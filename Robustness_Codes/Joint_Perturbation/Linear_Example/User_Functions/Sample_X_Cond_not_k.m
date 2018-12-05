function [ Xk ] = Sample_X_Cond_not_k( X,k )

% Input: Nxp matrix X, integer k
% Output: Nxp matrix Xk

% Draw N samples of X given X_{not k}
N = size(X,1);
Xk = X;

a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];
Xk(:,k) = betarnd(a(k),b(k),N,1); 

end