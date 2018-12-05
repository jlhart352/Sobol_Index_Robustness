function [sd] = Sample_std_Estimate(m,YA,YC)

N = length(YA);
p = size(YC,2);
samps = zeros(m,p);
for k = 1:m
    I = sort(randsample(N,round(.5*N)));
    Var_Y = mean((YA(I)-mean(YA(I))).^2);
    for i = 1:p
       samps(k,i) = (1/2)*mean( (YA(I)-YC(I,i)).^2 )/Var_Y; 
    end
end

sd = std(samps)./mean(samps);

end

