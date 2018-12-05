function [Perturbation_Output] = Marginal_Perturbation_Analysis(Sobol_Output,Phi_Data,r,m,R,sd_S_nom,sd_T_nom)

p = size(Sobol_Output.YC,2);
Il = size(R,1)-1;
psi_val = Psi_Data_Generation(Sobol_Output,Phi_Data,R);

a = zeros(Il,p,2*p);
delta_weights = zeros(2*p,p);
disp('Computing Frechet derivative for operator')
for k = 1:p
    disp(k)
    [ a(:,:,k), a(:,:,k+p), delta_weights(k,:), delta_weights(k+p,:) ] = Sobol_Frechet_Derivatives(Sobol_Output,Phi_Data,psi_val,R,k);
end
[a,idx] = Unique_Mats(a);
delta_weights = delta_weights(idx,:);

max_weight_rec = 1/max(max(delta_weights));
d = round(r/2);
delta = linspace(-max_weight_rec,max_weight_rec,2*d+1);
delta = delta([2:d,(d+2):(2*d)]);

% Preallocate array
H = length(delta);
num_pert = size(a,3);
S_pert = zeros(num_pert*H,p);
S_sd_pert = zeros(num_pert*H,p);
T_pert = zeros(num_pert*H,p);
T_sd_pert = zeros(num_pert*H,p);
Acc_Rej_Bound = zeros(num_pert*H,p);
delta_val = zeros(num_pert*H);
perturbation_marker = zeros(num_pert*H,1);

% Compute indices via importance sampling
disp('Computing perturbed index')
for k = 1:num_pert
    disp(k)
    for j = 1:H
        loop_index = (k-1)*H+j;
        delta_val(loop_index) = delta(j);
        perturbation_marker(loop_index) = k;
        [S_pert(loop_index,:),S_sd_pert(loop_index,:),T_pert(loop_index,:),T_sd_pert(loop_index,:),Acc_Rej_Bound(loop_index,:)] = Perturbed_Sobol_Indices( a(:,:,k),delta_weights(k,:),Sobol_Output,Phi_Data,psi_val,R,delta(j),sd_S_nom,sd_T_nom,m );
    end
end

Perturbation_Output = struct;
Perturbation_Output.delta_val = delta_val;
Perturbation_Output.S_sd_pert = S_sd_pert;
Perturbation_Output.S_pert = S_pert;
Perturbation_Output.T_sd_pert = T_sd_pert;
Perturbation_Output.T_pert = T_pert;
Perturbation_Output.Acc_Rej_Bound = Acc_Rej_Bound;
Perturbation_Output.R = R;
Perturbation_Output.a = a;
Perturbation_Output.delta_weights = delta_weights;
Perturbation_Output.psi_val = psi_val;
Perturbation_Output.perturbation_marker = perturbation_marker;

end

