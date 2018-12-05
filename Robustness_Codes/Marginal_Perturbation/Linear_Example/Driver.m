restoredefaultpath
clear
clc
addpath(genpath('../src'))
addpath User_Functions/

rng(10123)

% Set constants
N = 5*10^3;
R = (0:.1:1)'*ones(1,3);
tau = 1.5;
r = 60;
m = 50;

[A,B] = Sobol_Sampling(N);
[YA,YB,YC] = Sobol_Function_Evaluation(A,B);
Sobol_Output = Sobol_Indices(A,B,YA,YB,YC);
[sd_S_nom,sd_T_nom] = Sample_std_Estimate(m,Sobol_Output.YA,Sobol_Output.YB,Sobol_Output.YC);
Phi_Data = Phi_Data_Generation(Sobol_Output);
save('Preprocessed_Data.mat')

% Perturbation_Output = Marginal_Perturbation_Analysis(Sobol_Output,Phi_Data,r,m,R,sd_S_nom,sd_T_nom);
Perturbation_Output = Marginal_Perturbation_Analysis_mex(Sobol_Output,Phi_Data,r,m,R,sd_S_nom,sd_T_nom);

% Largest_Perturbation('T',Sobol_Output,Perturbation_Output,tau)
% Largest_Perturbation_Variable_i(1,'T',Sobol_Output,Perturbation_Output,tau)

save('Output.mat')

