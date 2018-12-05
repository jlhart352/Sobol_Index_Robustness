function [ S,Est_sd_S,T,Est_sd_T,Acc_Rej_Bound ] = Perturbed_Sobol_Indices( a,delta_weights,Sobol_Output,Phi_Data,psi_val,I,delta,sd_S_nom,sd_T_nom,m )

% Evaluate Sobol' indices with perturbed PDF via importance sampling

% Unpack data
A = Sobol_Output.A;
B = Sobol_Output.B;
YA = Sobol_Output.YA;
YB = Sobol_Output.YB;
YC = Sobol_Output.YC;
p = size(YC,2);

phi_A = Phi_Data.phi_A;
phi_B = Phi_Data.phi_B;

psi_A = zeros(size(phi_A));
psi_B = zeros(size(phi_B));
c = zeros(p,1);
L = size(I,1)-1;
for k = 1:p
    for i = 1:L
        JA = intersect(find(A(:,k)>I(i,k)),find(A(:,k)<I(i+1,k)));
        JB = intersect(find(B(:,k)>I(i,k)),find(B(:,k)<I(i+1,k)));
        psi_A(JA,k) = a(i,k)*psi_val(i,k);
        psi_B(JB,k) = a(i,k)*psi_val(i,k);
        c(k) = c(k) + (I(i+1,k)-I(i,k))*a(i,k)*psi_val(i,k);
    end
end

% Evaluate PDF and perturbed PDF
Perturbed_PDF_A = Eval_Perturbed_PDF(phi_A,psi_A,delta,c,delta_weights);
Perturbed_PDF_B = Eval_Perturbed_PDF(phi_B,psi_B,delta,c,delta_weights);

% Evaluate importance sampling weights
weight_A = Perturbed_PDF_A./phi_A;
weight_B = Perturbed_PDF_B./phi_B;

weight_A_prod = prod(weight_A,2);
weight_B_prod = prod(weight_B,2);

% Estimate mean and variance
muYA = mean(YA.*weight_A_prod);
muYB = mean(YB.*weight_B_prod);
Var_Y = (1/2)*( mean( weight_A_prod.*(YA-muYA).^2 ) + mean( weight_B_prod.*(YB-muYB).^2 ) );

% Estimate Sobol' indices
S = zeros(p,1);
T = zeros(p,1);
Est_sd_S = zeros(p,1);
Est_sd_T = zeros(p,1);

for k = 1:p
   S(k) = mean( YB.*(YC(:,k)-YA).*weight_A_prod.*weight_B_prod )/Var_Y; 
   weight_Ck = weight_A_prod.*weight_B(:,k);
   T(k) = (1/2)*mean( ( (YA - YC(:,k)).^2 ) .* weight_Ck )/Var_Y;
   
   [sd_S,sd_T] = Sample_std_Estimate_Weights(m,YA,YB,YC(:,k),weight_A,weight_B,k);
   Est_sd_S(k) = sd_S/sd_S_nom(k);
   Est_sd_T(k) = sd_T/sd_T_nom(k);
end
Acc_Rej_Bound = max([max(weight_A,[],1);max(weight_B,[],1)],[],1);

end

