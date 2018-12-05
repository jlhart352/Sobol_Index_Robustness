function [sd_S,sd_T] = Sample_std_Estimate(m,YA,YB,YC)

N = length(YA);
p = size(YC,2);
samps_S = zeros(m,p);
samps_T = zeros(m,p);
for k = 1:m
    I = sort(randperm(N,round(.5*N)));
    Var_Y = mean((YA(I)-mean(YA(I))).^2);
    for i = 1:p
        samps_S(k,i) = mean( YB(I).*(YC(I,i)-YA(I)) )/Var_Y;
        samps_T(k,i) = (1/2)*mean( (YA(I)-YC(I,i)).^2 )/Var_Y; 
    end
end

sd_S = std(samps_S)./mean(samps_S);
sd_T = std(samps_T)./mean(samps_T);

end

