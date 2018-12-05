function [T_pert] = Joint_Perturbation_Analysis(Sobol_Output,Phi_Data,sd_nom,R,r,tau,m)

p = length(Sobol_Output.T);

% Compute paritition and Frechet derivatives
[ a, a_normalized, Psi_Data ] = Sobol_Frechet_Derivatives(Sobol_Output,Phi_Data,R);

d = round(r/2);
h = linspace(-1,1,2*d+1);
h = h([2:d,(d+2):(2*d)]);

% Find unique rows to avoid excess computation
A = [a,a_normalized]';
C = unique(A,'rows')';

% Preallocate array
H = length(h);
r = size(C,2);
T_a = zeros(p,r,H);
sd_a = zeros(r,H,p);

disp('Computing perturbed index')
% Compute indices via weighted sampling
for k = 1:r
    disp(k)
    Perturbed_PDF_Data = Perturbed_Sobol_Indices_Preprocess( Sobol_Output,Phi_Data,Psi_Data,C(:,k),R );
    for j = 1:H
        [T_a(:,k,j),sd_a(k,j,:)] = Perturbed_Sobol_Indices( Sobol_Output,Phi_Data,Perturbed_PDF_Data,h(j),sd_nom,m );
    end
end

sd = max(sd_a,[],3);
T_pert = zeros(p,sum(sum(sd<tau)));

count = 1;
for i = 1:size(sd,1)
   for j = 1:size(sd,2)
      if sd(i,j) < tau
         T_pert(:,count) = T_a(:,i,j);
         count = count+1;
      end
   end
end


end

