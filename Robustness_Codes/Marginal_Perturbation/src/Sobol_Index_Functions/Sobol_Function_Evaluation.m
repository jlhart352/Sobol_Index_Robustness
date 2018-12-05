function [YA,YB,YC] = Sobol_Function_Evaluation(A,B)

N = size(A,1);
p = size(A,2);

% Evaluate f at samples
YA = f(A);
YB = f(B);
YC = zeros(N,p);
for k = 1:p
   C = A;
   C(:,k) = B(:,k);
   YC(:,k) = f(C); 
end

end

