function [ Psi ] = Eval_Psi_Sign( X,R,a )

% Evaluate \psi(x) for each row in X

N = size(X,1);
Psi = ones(N,1);
I = Find_Rectangle(X,R);
J = find(a == -1);
for k = 1:length(J)
    Psi(I == J(k)) = -1;
end


end

