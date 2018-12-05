function [ Y ] = Eval_Perturbed_PDF( phi_X,psi_X,h,c )

% Evaluate \frac{\phi(x) + h*\psi(x)}{1+c} for each row in X

Y = (phi_X+h*psi_X)/(1+h*c);


end

