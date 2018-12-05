function [ T,Est_sd ] = Perturbed_Sobol_Indices( Sobol_Output,Phi_Data,Perturbed_PDF_Data,h,sd_nom,m )

% Evaluate Sobol' indices with perturbed PDF via importance sampling

% Unpack data
YA = Sobol_Output.YA;
YC = Sobol_Output.YC;
p = size(YC,2);

psi_A = Perturbed_PDF_Data.psi_A;
psi_C = Perturbed_PDF_Data.psi_C;
psi_C_marg_not_k = Perturbed_PDF_Data.psi_C_marg_not_k;
c = Perturbed_PDF_Data.c;

phi_A = Phi_Data.phi_A;
phi_C = Phi_Data.phi_C;
phi_C_Cond_not_k = Phi_Data.phi_C_Cond_not_k;
phi_C_marg_not_k = Phi_Data.phi_C_marg_not_k;

% Evaluate PDF and perturbed PDF
Perturbed_PDF_A = Eval_Perturbed_PDF(phi_A,psi_A,h,c);

% Evaluate importance sampling weights
weight_A = Perturbed_PDF_A./phi_A;

% Estimate mean and variance
muYA = mean(YA.*weight_A);
Var_Y = mean( weight_A.*(YA-muYA).^2 );

% Estimate total Sobol' indices
T = zeros(p,1);
Est_sd = zeros(p,1);

for k = 1:p
   Perturbed_PDF_Cond = Eval_Perturbed_PDF_Cond_not_k( phi_C(:,k),psi_C(:,k),phi_C_marg_not_k(:,k),psi_C_marg_not_k(:,k),h,c );
   weight_Ck = ( Perturbed_PDF_A.*Perturbed_PDF_Cond ) ./ ( phi_A.*phi_C_Cond_not_k(:,k));
   T(k) = (1/2)*mean( ( (YA - YC(:,k)).^2 ) .* weight_Ck )/Var_Y;
   Est_sd(k) = Sample_std_Estimate_Weights(m,YA,YC(:,k),weight_A,weight_Ck)/sd_nom(k);
end

end

