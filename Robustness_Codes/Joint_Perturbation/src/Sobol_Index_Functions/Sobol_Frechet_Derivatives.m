function [ a, a_normalized,Psi_Data ] = Sobol_Frechet_Derivatives( Sobol_Output,Phi_Data,R )

% Unpack data from computing Sobol' indices
T = Sobol_Output.T;
A = Sobol_Output.A;
C = Sobol_Output.C;
YA = Sobol_Output.YA;
YC = Sobol_Output.YC;
Var_Y = Sobol_Output.Var_Y;
muYA = Sobol_Output.muYA;
N = size(A,1);
p = size(A,2);

phi_A = Phi_Data.phi_A;
phi_A_marg_not_k = Phi_Data.phi_A_marg_not_k;
phi_C = Phi_Data.phi_C;

% Preallocate arrays
M = length(R);
a = zeros(M,p);
a_normalized = zeros(M,p);

% determine psi values
IA = Find_Rectangle(A,R);
IC = zeros(N,p);
for k = 1:p
   Ck = reshape(C(k,:,:),N,p);
   IC(:,k) = Find_Rectangle(Ck,R);
end

psi_val = zeros(M,p+1);

for c = 1:M
   psi_val(c,p+1) = min(phi_A(IA==c));
   for k = 1:p
       if(sum(IC(:,k)==c)>0)
           psi_val(c,k) = min(phi_C(IC(:,k)==c,k));
       else
           psi_val(c,k) = 0;
       end
   end
end

psi_val = min(psi_val,[],2);

psi_A_val = zeros(N,1);
psi_C_val = zeros(N,p);

for c = 1:M
   psi_A_val(IA==c) = psi_val(c);
   for k = 1:p
      psi_C_val(IC(:,k)==c,k) = psi_val(c); 
   end
end

D = zeros(M,p);
% Loop over Sobol indices
disp('Computing Frechet derivative for operator')
for k = 1:p
    
disp(k)

% Construct the vector d elementwise
for j = 1:M
    
JA = find(IA == j);
JC = find(IC(:,k) == j);

vol = R(j,k,2)-R(j,k,1);

J_Sub = is_in_sub_rec(reshape(R(j,:,:),p,2),A,k);

DF = psi_val(j)*sum( ((YA(JC)-YC(JC,k)).^2) .* (1./phi_C(JC,k)) )/N;
DF = DF + psi_val(j)*sum( ((YA(JA)-YC(JA,k)).^2) .* (1./phi_A(JA)) )/N;
DF = DF - psi_val(j)*vol*sum( ((YA(J_Sub)-YC(J_Sub,k)).^2) .* (1./phi_A_marg_not_k(J_Sub)) )/N;

DF = (1/2)*DF;

DG = psi_val(j)*sum( (YA(JA).^2) .* (1./phi_A(JA)) )/N;
DG = DG - psi_val(j)*2*muYA * sum( YA(JA) .* (1./phi_A(JA)) )/N;
DG = DG + psi_val(j)*prod(R(j,:,2)-R(j,:,1))*(muYA^2);

D(j,k) = DF/Var_Y - T(k)*DG/Var_Y;
end

end

S = sum(T);
SD = sum(D,2);

for k = 1:p
   a(:,k) = sign(D(:,k));
   a_normalized(:,k) = sign((S*D(:,k) - T(k)*SD)/(S^2));
end

Psi_Data = struct;
Psi_Data.psi_A_val = psi_A_val;
Psi_Data.psi_C_val = psi_C_val;
Psi_Data.psi_val = psi_val;

end

