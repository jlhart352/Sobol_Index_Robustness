function [Phi_Data] = Precompute_Phi_Data(Sobol_Output)
% Unpack data from computing Sobol' indices
A = Sobol_Output.A;
C = Sobol_Output.C;
N = size(A,1);
p = size(A,2);

% Precompute phi at sample points and determine psi values
phi_A = Eval_Phi(A);
phi_A_marg_not_k = zeros(N,p);
phi_C = zeros(N,p);
phi_C_Cond_not_k = zeros(N,p);
phi_C_marg_not_k = zeros(N,p);
for k = 1:p
   phi_A_marg_not_k(:,k) = Eval_Phi_Marg_not_k(A,k);
   Ck = reshape(C(k,:,:),N,p);
   phi_C(:,k) = Eval_Phi(Ck);
   phi_C_Cond_not_k(:,k) = Eval_Phi_Cond_not_k(Ck,k);
   phi_C_marg_not_k(:,k) = Eval_Phi_Marg_not_k(Ck,k);
end

Phi_Data = struct;
Phi_Data.phi_A = phi_A;
Phi_Data.phi_A_marg_not_k = phi_A_marg_not_k;
Phi_Data.phi_C = phi_C;
Phi_Data.phi_C_Cond_not_k = phi_C_Cond_not_k;
Phi_Data.phi_C_marg_not_k = phi_C_marg_not_k;

end

