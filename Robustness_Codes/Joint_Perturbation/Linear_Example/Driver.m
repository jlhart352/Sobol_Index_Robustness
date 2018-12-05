restoredefaultpath
clear
clc
addpath(genpath('../src'))
addpath User_Functions/

rng(10123)

% Set constants
N = 5*10^3;
L = 50;
r = 60;
tau = 1.5;
m = 50;

% Compute indices, construct partition, precompute PDF evaluations
[A,C] = Sobol_Sampling(N);
[YA,YC] = Sobol_Function_Evaluation(A,C);
Sobol_Output = Sobol_Indices(A,C,YA,YC);
sd_nom = Sample_std_Estimate(m,Sobol_Output.YA,Sobol_Output.YC);
R = Regression_Tree_Partition(Sobol_Output.A,Sobol_Output.YA,L);
Phi_Data = Precompute_Phi_Data(Sobol_Output);
save('Preprocessed_Data.mat')

% Run perturbation analysis, this can be precompiled
% T_pert = Joint_Perturbation_Analysis(Sobol_Output,Phi_Data,sd_nom,R,r,tau,m);
T_pert = Joint_Perturbation_Analysis_mex(Sobol_Output,Phi_Data,sd_nom,R,r,tau,m);
save('Perturbed_Indices.mat')

% Largest_Perturbation(Sobol_Output.T,T_pert)
% Largest_Perturbation_Variable_i(Sobol_Output.T,T_pert,1)