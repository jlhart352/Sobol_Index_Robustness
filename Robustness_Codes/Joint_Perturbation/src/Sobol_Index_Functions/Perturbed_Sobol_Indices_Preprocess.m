function [ Perturbed_PDF_Data ] = Perturbed_Sobol_Indices_Preprocess( Sobol_Output,Phi_Data,Psi_Data,a,R )

% Evaluate Sobol' indices with perturbed PDF via importance sampling

% Unpack data
A = Sobol_Output.A;
C = Sobol_Output.C;
N = size(A,1);
p = size(A,2);

psi_A_val = Psi_Data.psi_A_val;
psi_C_val = Psi_Data.psi_C_val;
psi_val = Psi_Data.psi_val;

phi_A = Phi_Data.phi_A;

% Evaluate PDF
psi_A = Eval_Psi_Sign(A,R,a).*psi_A_val;
psi_C = zeros(N,p);

c = mean(psi_A./phi_A);

psi_C_marg_not_k = zeros(N,p);
for k = 1:p
   Ck = reshape(C(k,:,:),N,p);
   psi_C(:,k) = Eval_Psi_Sign(Ck,R,a).*psi_C_val(:,k);
   psi_C_marg_not_k(:,k) = Eval_Int_Psi_xk(Ck,k,R,a,psi_val);
end

Perturbed_PDF_Data = struct;
Perturbed_PDF_Data.psi_A = psi_A;
Perturbed_PDF_Data.psi_C = psi_C;
Perturbed_PDF_Data.psi_C_marg_not_k = psi_C_marg_not_k;
Perturbed_PDF_Data.c = c;



end