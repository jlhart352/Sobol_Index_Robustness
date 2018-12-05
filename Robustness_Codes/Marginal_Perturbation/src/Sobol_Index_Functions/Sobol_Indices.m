function [ Sobol_Output ] = Sobol_Indices( A,B,YA,YB,YC )

p = size(A,2);

% Estimate mean and variance
muYA = mean(YA);
muYB = mean(YB);
Var_Y = (1/2)*mean( (YA-muYA).^2 + (YB-muYB).^2 );

% Estimate Sobol' indices
S = zeros(p,1);
T = zeros(p,1);
for k = 1:p
   S(k) = mean( YB.*(YC(:,k)-YA) )/Var_Y;
   T(k) = (1/2)*mean( (YA - YC(:,k)).^2 )/Var_Y;
end

% Organize output into a struct
Sobol_Output = struct;
Sobol_Output.S = S;
Sobol_Output.T = T;
Sobol_Output.A = A;
Sobol_Output.B = B;
Sobol_Output.YA = YA;
Sobol_Output.YB = YB;
Sobol_Output.YC = YC;
Sobol_Output.Var_Y = Var_Y;
Sobol_Output.muYA = muYA;
Sobol_Output.muYB = muYB;

end

