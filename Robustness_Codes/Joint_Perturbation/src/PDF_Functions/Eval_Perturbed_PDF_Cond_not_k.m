function [ Y ] = Eval_Perturbed_PDF_Cond_not_k( phi_X,psi_X,phi_X_marg_not_k,psi_X_marg_not_k, h, c )

% Evaluate the conditional perturbed PDF conditioned X_j, j not equal k,
% i.e. \frac{\phi(x) + h*\psi(x)}{1+h*int_\Omega \psi(x)dx}

Y1 = Eval_Perturbed_PDF( phi_X,psi_X,h,c );
Y2 = Eval_Int_Perturbed_PDF_not_k( phi_X_marg_not_k,psi_X_marg_not_k,h,c );
Y = Y1./Y2;

end

