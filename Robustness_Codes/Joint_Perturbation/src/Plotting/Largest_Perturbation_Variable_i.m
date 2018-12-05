function [  ] = Largest_Perturbation_Variable_i( T,T_pert,i )

r = size(T_pert,2);

T_max = T;
current_max = T(i);
for k = 1:r
       if T_pert(i,k)>current_max
          T_max = T_pert(:,k);
          current_max = T_pert(i,k);
       end
end

T_min = T;
current_min = T(i);
for k = 1:r
       if T_pert(i,k)<current_min
          T_min = T_pert(:,k);
          current_min = T_pert(i,k);
       end
end

figure()
bar([T,T_max,T_min])


end

