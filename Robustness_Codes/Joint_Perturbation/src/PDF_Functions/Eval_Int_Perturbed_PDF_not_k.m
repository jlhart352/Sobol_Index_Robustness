function [ Y ] = Eval_Int_Perturbed_PDF_not_k( phi_X_marg_not_k,psi_X_marg_not_k,h,c )

% Evaluate int_{\Omega_k} \frac{\phi(x) + h*\psi(x)}{1+c} dx_k for each row in X

Y = ( 1 / (1+h*c) )* (phi_X_marg_not_k + h*psi_X_marg_not_k);

end

