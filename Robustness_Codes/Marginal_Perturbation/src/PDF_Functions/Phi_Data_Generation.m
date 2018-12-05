function [Phi_Data] = Phi_Data_Generation(Sobol_Output)

% Precompute phi at sample points and determine psi values
phi_A = Eval_Phi_Marginals(Sobol_Output.A);
phi_B = Eval_Phi_Marginals(Sobol_Output.B);

Phi_Data = struct;
Phi_Data.phi_A = phi_A;
Phi_Data.phi_B = phi_B;

end

