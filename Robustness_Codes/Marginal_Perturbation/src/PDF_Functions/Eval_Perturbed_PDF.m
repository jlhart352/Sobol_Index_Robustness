function [ Y ] = Eval_Perturbed_PDF( phi_X,psi_X,delta,c,delta_weights )

% Evaluate \frac{\phi(x) + delta*\psi(x)}{1+int delta*psi} for each row in X

N = size(phi_X,1);
p = size(phi_X,2);

Y = zeros(N,p);
for k = 1:p
    Y(:,k) = (phi_X(:,k) + delta_weights(k)*delta*psi_X(:,k))/(1+delta_weights(k)*delta*c(k));
end


end

