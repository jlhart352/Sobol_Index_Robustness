restoredefaultpath
clear
clc

load Robustness_Codes/Marginal_Perturbation/Linear_Example/Preprocessed_Data.mat

p = size(A,2);

% Set constants
L = 50;

C = zeros(p,N,p);
for k = 1:p
   C(k,:,:) = A;
   C(k,:,k) = B(:,k);
end

sd_nom = sd_T_nom;

addpath(genpath('Robustness_Codes/Joint_Perturbation/'))
R = Regression_Tree_Partition(Sobol_Output.A,Sobol_Output.YA,L);

T = Sobol_Output.T;
Var_Y = Sobol_Output.Var_Y;
muYA = Sobol_Output.muYA;

clear Sobol_Output
Sobol_Output = struct;
Sobol_Output.T = T;
Sobol_Output.A = A;
Sobol_Output.C = C;
Sobol_Output.YA = YA;
Sobol_Output.YC = YC;
Sobol_Output.Var_Y = Var_Y;
Sobol_Output.muYA = muYA;

phi_A = Phi_Data.phi_A;
phi_B = Phi_Data.phi_B;
phi_C = zeros(N,p);
phi_A_marg_not_k = zeros(N,p);
phi_C_Cond_not_k = zeros(N,p);
for k = 1:p
   u = setdiff(1:p,k);
   phi_A_marg_not_k(:,k) = prod(phi_A(:,u),2);
   phi_C(:,k) =  phi_A_marg_not_k(:,k).*phi_B(:,k);
   phi_C_Cond_not_k(:,k) = phi_B(:,k);
end
phi_C_marg_not_k = phi_A_marg_not_k;
phi_A = prod(phi_A,2);

clear Phi_Data
Phi_Data = struct;
Phi_Data.phi_A = phi_A;
Phi_Data.phi_A_marg_not_k = phi_A_marg_not_k;
Phi_Data.phi_C = phi_C;
Phi_Data.phi_C_Cond_not_k = phi_C_Cond_not_k;
Phi_Data.phi_C_marg_not_k = phi_C_marg_not_k;

cd Robustness_Codes/Joint_Perturbation/Linear_Example/
save('Preprocessed_Data.mat','N','L','r','tau','m','A','C','YA','YC','Sobol_Output','sd_nom','R','Phi_Data')
