function [psi_val] = Psi_Data_Generation(Sobol_Output,Phi_Data,I)
% Unpack data from computing Sobol' indices
A = Sobol_Output.A;
B = Sobol_Output.B;
p = size(A,2);

phi_A = Phi_Data.phi_A;
phi_B = Phi_Data.phi_B;

% Preallocate arrays
L = size(I,1)-1;
psi_val = zeros(L,p);

for k = 1:L
   for i = 1:p
      IA = intersect(find(A(:,i)>I(k,i)),find(A(:,i)<I(k+1,i)));
      IB = intersect(find(B(:,i)>I(k,i)),find(B(:,i)<I(k+1,i)));
      if isempty(min(min(phi_A(IA,i)),min(phi_B(IB,i))))
          psi_val(k,i) = 0;
      else
          psi_val(k,i) = min(min(phi_A(IA,i)),min(phi_B(IB,i)));
      end
   end
end

end

