function [sd] = Sample_std_Estimate_Weights(m,YA,YCk,weight_A,weight_Ck)

N = length(YA);
samps = zeros(m,1);
for k = 1:m
    I = sort(randsample(N,round(.5*N)));
    Var_Y = mean(weight_A(I).*(YA(I)-mean(weight_A(I).*YA(I))).^2);
    samps(k) = (1/2)*mean( weight_Ck(I).*(YA(I)-YCk(I)).^2 )/Var_Y; 
end

sd = std(samps)/mean(samps);

end

