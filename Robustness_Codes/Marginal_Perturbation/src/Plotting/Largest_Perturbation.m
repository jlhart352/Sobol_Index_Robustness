function [  ] = Largest_Perturbation(Index,Sobol_Output,Perturbation_Output,tau)

if Index == 'S'
    Acpt = sort(find(max(Perturbation_Output.S_sd_pert,[],2)<tau));
elseif Index == 'T'
    Acpt = sort(find(max(Perturbation_Output.T_sd_pert,[],2)<tau));
else
    Acpt = sort(intersect(find(max(Perturbation_Output.S_sd_pert,[],2)<tau),find(max(Perturbation_Output.T_sd_pert,[],2)<tau)));  
end

S_pert = Perturbation_Output.S_pert(Acpt,:);
T_pert = Perturbation_Output.T_pert(Acpt,:);
S = Sobol_Output.S;
T = Sobol_Output.T;
S_min = min(S_pert);
S_max = max(S_pert);
T_min = min(T_pert);
T_max = max(T_pert);

p = length(S);

if Index~='T'

figure()
marg = max(S_max)/200;
xlim([.3,p+.7])
ylim([min(-.0001,min(S_min)),1.02*max(S_max)])
for k =1:p
    rectangle('Position',[k-.45,S(k)+marg,.4,max((S_max(k)-S(k)-marg),0)],'FaceColor','g')
    rectangle('Position',[k-.45,S(k)-marg,.4,2*marg],'FaceColor','b')
    rectangle('Position',[k-.45,S_min(k),.4,max(S(k)-marg-S_min(k),0)],'FaceColor','magenta')
end
title('First Order Sobol'' Indices')
xticks(1:p)

end

if Index~='S'

figure()
marg = max(T_max)/200;
xlim([.3,p+.7])
ylim([min(-.0001,min(T_min)),1.02*max(T_max)])
for k =1:p
    rectangle('Position',[k-.45,T(k)+marg,.4,max((T_max(k)-T(k)-marg),0)],'FaceColor','g')
    rectangle('Position',[k-.45,T(k)-marg,.4,2*marg],'FaceColor','b')
    rectangle('Position',[k-.45,T_min(k),.4,max(T(k)-marg-T_min(k),0)],'FaceColor','magenta')
end
title('Total Sobol'' Indices')
xticks(1:p)

end

end

