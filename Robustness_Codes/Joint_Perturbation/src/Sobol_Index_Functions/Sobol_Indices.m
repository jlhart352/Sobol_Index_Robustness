function [ Sobol_Output ] = Sobol_Indices( A,C,YA,YC )

p = size(A,2);
% Estimate mean and variance
muYA = mean(YA);
Var_Y = mean( (YA-muYA).^2);

% Estimate total Sobol' indices
T = zeros(p,1);
for k = 1:p
   T(k) = (1/2)*mean( (YA - YC(:,k)).^2 )/Var_Y;
end

% Organize output into a struct
Sobol_Output = struct;
Sobol_Output.T = T;
Sobol_Output.A = A;
Sobol_Output.C = C;
Sobol_Output.YA = YA;
Sobol_Output.YC = YC;
Sobol_Output.Var_Y = Var_Y;
Sobol_Output.muYA = muYA;

end

