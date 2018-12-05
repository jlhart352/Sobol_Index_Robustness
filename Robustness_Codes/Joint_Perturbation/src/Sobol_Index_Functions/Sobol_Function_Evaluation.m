function [YA,YC] = Sobol_Function_Evaluation(A,C)
% Evaluate f at samples
N = size(A,1);
p = size(A,2);
YA = f(A);
YC = zeros(N,p);
for k = 1:p
   YC(:,k) = f(reshape(C(k,:,:),N,p)); 
end

end

