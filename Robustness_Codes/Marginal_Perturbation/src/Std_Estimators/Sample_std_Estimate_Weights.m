function [sd_S,sd_T] = Sample_std_Estimate_Weights(m,YA,YB,YCi,weight_A,weight_B,i)

N = length(YA);
samps_S = zeros(m,1);
samps_T = zeros(m,1);
for k = 1:m
    I = sort(randperm(N,round(.5*N)));
    weight_A_tmp = weight_A(I,:);
    weight_B_tmp = weight_B(I,:);
    weight_A_tmp_prod = prod(weight_A_tmp,2);
    weight_B_tmp_prod = prod(weight_B_tmp,2);
    YA_tmp = YA(I);
    YB_tmp = YB(I);
    YCi_tmp = YCi(I);
    
    % Estimate mean and variance
    muYA = mean(YA_tmp.*weight_A_tmp_prod);
    muYB = mean(YB_tmp.*weight_B_tmp_prod);
    Var_Y = (1/2)*( mean( weight_A_tmp_prod.*(YA_tmp-muYA).^2 ) + mean( weight_B_tmp_prod.*(YB_tmp-muYB).^2 ) );

    samps_S(k) = mean( YB_tmp.*(YCi_tmp-YA_tmp).*weight_A_tmp_prod.*weight_B_tmp_prod )/Var_Y;
    weight_Ck = weight_A_tmp_prod.*weight_B_tmp(:,i);
    samps_T(k) = (1/2)*mean( ( (YA_tmp - YCi_tmp).^2 ) .* weight_Ck )/Var_Y;
    
end

sd_S = std(samps_S)/mean(samps_S);
sd_T = std(samps_T)/mean(samps_T);

end

