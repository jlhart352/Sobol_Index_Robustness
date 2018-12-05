function [ a_S, a_T, weights_S, weights_T] = Sobol_Frechet_Derivatives( Sobol_Output,Phi_Data,psi_val,I,k )

% Unpack data from computing Sobol' indices
S = Sobol_Output.S;
T = Sobol_Output.T;
A = Sobol_Output.A;
B = Sobol_Output.B;
YA = Sobol_Output.YA;
YB = Sobol_Output.YB;
YC = Sobol_Output.YC;
Var_Y = Sobol_Output.Var_Y;
muYA = Sobol_Output.muYA;
muYB = Sobol_Output.muYB;
N = size(YA,1);
p = length(T);

phi_A = Phi_Data.phi_A;
phi_B = Phi_Data.phi_B;

% Preallocate arrays
L = size(I,1)-1;
a_S = zeros(L,p);
a_T = zeros(L,p);
weights_S = zeros(p,1);
weights_T = zeros(p,1);

for i = 1:p
    D_S = zeros(L,1);
    D_T = zeros(L,1);
    % Construct the vector D elementwise
    for j = 1:L
        JA = intersect(find(A(:,i)>I(j,i)),find(A(:,i)<I(j+1,i)));
        JB = intersect(find(B(:,i)>I(j,i)),find(B(:,i)<I(j+1,i))); 
        
        DF = psi_val(j,i)*sum( YB(JA).*(YC(JA,k)-YA(JA)).*(1./phi_A(JA,i)) )/N; 
        DF = DF + psi_val(j,i)*sum( YB(JB).*(YC(JB,k)-YA(JB)).*(1./phi_B(JB,i)) )/N; 
        DF = DF - psi_val(j,i)*(I(j+1,i)-I(j,i))*sum( YB.*(YC(:,k)-YA) )/N;
        DG = psi_val(j,i)*sum( ((YA(JA)-YC(JA,k)).^2).*(1./phi_A(JA,i)) )/N;
        if i==k
            DG = DG + psi_val(j,i)*sum( ((YA(JB)-YC(JB,k)).^2).*(1./phi_B(JB,i)) )/N;
            DG = DG - psi_val(j,i)*(I(j+1,i)-I(j,i))*sum((YA-YC(:,k)).^2)/N;
        end
        DG = (1/2)*DG;
        DH = psi_val(j,i)*sum( (YA(JA).^2) .* (1./phi_A(JA,i)) )/N;
        DH = DH + psi_val(j,i)*(I(j+1,i)-I(j,i))*((1/2)*(muYA + muYB))^2;
        DH = DH - psi_val(j,i)*2*(1/2)*(muYA + muYB) * sum( YA(JA) .* (1./phi_A(JA,i)) )/N;
        
        D_S(j) = DF/Var_Y - S(k)*DH/Var_Y;
        D_T(j) = DG/Var_Y - T(k)*DH/Var_Y;
    end

    a_S(:,i) = sign(D_S);
    a_T(:,i) = sign(D_T);
    weights_S(i) = sum(abs(D_S));
    weights_T(i) = sum(abs(D_T));
    
end

    weights_S = weights_S/sum(weights_S);
    weights_T = weights_T/sum(weights_T);

end

