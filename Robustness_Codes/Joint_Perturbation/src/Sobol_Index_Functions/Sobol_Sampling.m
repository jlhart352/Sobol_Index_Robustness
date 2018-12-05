function [A,C] = Sobol_Sampling(N)
% Draw samples
A = Sample_X(N);
p = size(A,2);
C = zeros(p,N,p);
for k = 1:p
   C(k,:,:) = Sample_X_Cond_not_k(A,k);
end

end

