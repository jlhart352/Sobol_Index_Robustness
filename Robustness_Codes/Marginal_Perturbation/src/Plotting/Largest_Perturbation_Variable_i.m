function [  ] = Largest_Perturbation_Variable_i( i,Index,Sobol_Output,Perturbation_Output,tau )

if Index=='S'
    Acpt = sort(find(max(Perturbation_Output.S_sd_pert,[],2)<tau));
elseif Index =='T'
    Acpt = sort(find(max(Perturbation_Output.T_sd_pert,[],2)<tau));
else
    Acpt = sort(intersect(find(max(Perturbation_Output.S_sd_pert,[],2)<tau),find(max(Perturbation_Output.T_sd_pert,[],2)<tau)));  
end

S_pert = Perturbation_Output.S_pert(Acpt,:);
T_pert = Perturbation_Output.T_pert(Acpt,:);
Acc_Rej_Bound = Perturbation_Output.Acc_Rej_Bound(Acpt,:);
R = Perturbation_Output.R;
a = Perturbation_Output.a;
psi_val = Perturbation_Output.psi_val;
delta_val = Perturbation_Output.delta_val(Acpt);
perturbation_marker = Perturbation_Output.perturbation_marker(Acpt);
S = Sobol_Output.S;
T = Sobol_Output.T;

r = size(T_pert,1);

if Index~='T'

    current_max = S(i);
    max_indices = 0;
    for k = 1:r
        if S_pert(k,i)>current_max
            current_max = S_pert(k,i);
            max_indices = k;
        end
    end

    current_min = S(i);
    min_indices = 0;
    for k = 1:r
        if S_pert(k,i)<current_min
            current_min = S_pert(k,i);
            min_indices = k;
        end
    end

    figure()
    b = bar([S,S_pert(max_indices,:)',S_pert(min_indices,:)']);
    b(1).FaceColor = 'b';
    b(2).FaceColor = 'r';
    b(3).FaceColor = 'c';
    title('First Order Sobol'' Indices')

    N = 10^5;
    X = Sample_X(N);
    p = size(X,2);
    Acc = zeros(N,p);

    phi_X = Eval_Phi_Marginals(X);
    psi_X = zeros(N,p);
    c = zeros(p,1);
    L = size(R,1)-1;
    for k = 1:p
        for i = 1:L
            J = intersect(find(X(:,k)>R(i)),find(X(:,k)<R(i+1)));
            psi_X(J,k) = a(i,k,perturbation_marker(max_indices))*psi_val(i,k);
            c(k) = c(k) + (R(i+1)-R(i))*a(i,k,perturbation_marker(max_indices))*psi_val(i,k);
        end
    end

    Perturbed_PDF_X = Eval_Perturbed_PDF(phi_X,psi_X,delta_val(max_indices),c,Perturbation_Output.delta_weights);

    for k = 1:p
       ratio = Perturbed_PDF_X(:,k)./(Acc_Rej_Bound(max_indices,k)*phi_X(:,k)); 
       for i = 1:N
          u = rand;
          if ratio(i)>u
             Acc(i,k) = 1; 
          end
       end
    end

    Ymax = cell(p,1);
    for k = 1:p
       Ymax{k} = X(Acc(:,k)==1,k); 
    end

    Acc = zeros(N,p);

    psi_X = zeros(N,p);
    c = zeros(p,1);
    L = size(R,1)-1;
    for k = 1:p
        for i = 1:L
            J = intersect(find(X(:,k)>R(i)),find(X(:,k)<R(i+1)));
            psi_X(J,k) = a(i,k,perturbation_marker(min_indices))*psi_val(i,k);
            c(k) = c(k) + (R(i+1)-R(i))*a(i,k,perturbation_marker(min_indices))*psi_val(i,k);
        end
    end

    Perturbed_PDF_X = Eval_Perturbed_PDF(phi_X,psi_X,delta_val(min_indices),c,Perturbation_Output.delta_weights);

    for k = 1:p
       ratio = Perturbed_PDF_X(:,k)./(Acc_Rej_Bound(min_indices,k)*phi_X(:,k)); 
       for i = 1:N
          u = rand;
          if ratio(i)>u
             Acc(i,k) = 1; 
          end
       end
    end

    Ymin = cell(p,1);
    for k = 1:p
       Ymin{k} = X(Acc(:,k)==1,k); 
    end
    
    figure()
    for k = 1:p
        subplot(p,3,3*k-2);
        hist = histogram(X(:,k),'normalization','pdf');
        ymax = max(hist.Values);
        hist = histogram(Ymin{k},'normalization','pdf');
        ymax = max(ymax,max(hist.Values));
        hist = histogram(Ymax{k},'normalization','pdf');
        ymax = max(ymax,max(hist.Values));
        histogram(X(:,k),'normalization','pdf','FaceColor','b')
        ylim([0,ymax*1.1])
        set(gca,'xtick',[])
        set(gca,'ytick',[])
        subplot(p,3,3*k-1);
        histogram(Ymax{k},'normalization','pdf','FaceColor','r')
        ylim([0,ymax*1.1])
        set(gca,'xtick',[])
        set(gca,'ytick',[])
        subplot(p,3,3*k);
        histogram(Ymin{k},'normalization','pdf','FaceColor','c')
        set(gca,'xtick',[])
        set(gca,'ytick',[])
    end
end

if Index~='S'

    current_max = T(i);
    max_indices = 0;
    for k = 1:r
        if T_pert(k,i)>current_max
           current_max = T_pert(k,i);
           max_indices = k;
        end
    end

    current_min = T(i);
    min_indices = 0;
    for k = 1:r
        if T_pert(k,i)<current_min
            current_min = T_pert(k,i);
            min_indices = k;
        end
    end

    figure()
    b = bar([T,T_pert(max_indices,:)',T_pert(min_indices,:)']);
    b(1).FaceColor = 'b';
    b(2).FaceColor = 'r';
    b(3).FaceColor = 'c';
    title('Total Sobol'' Indices')

    N = 10^5;
    
    X = Sample_X(N);
    
    p = size(X,2);
    Acc = zeros(N,p);

    phi_X = Eval_Phi_Marginals(X);
    psi_X = zeros(N,p);
    c = zeros(p,1);
    L = size(R,1)-1;
    for k = 1:p
        for i = 1:L
            J = intersect(find(X(:,k)>R(i)),find(X(:,k)<R(i+1)));
            psi_X(J,k) = a(i,k,perturbation_marker(max_indices))*psi_val(i,k);
            c(k) = c(k) + (R(i+1)-R(i))*a(i,k,perturbation_marker(max_indices))*psi_val(i,k);
        end
    end

    Perturbed_PDF_X = Eval_Perturbed_PDF(phi_X,psi_X,delta_val(max_indices),c,Perturbation_Output.delta_weights);

    for k = 1:p
       ratio = Perturbed_PDF_X(:,k)./(Acc_Rej_Bound(max_indices,k)*phi_X(:,k)); 
       for i = 1:N
          u = rand;
          if ratio(i)>u
             Acc(i,k) = 1; 
          end
       end
    end

    Ymax = cell(p,1);
    for k = 1:p
       Ymax{k} = X(Acc(:,k)==1,k); 
    end
    
    Acc = zeros(N,p);

    psi_X = zeros(N,p);
    c = zeros(p,1);
    L = size(R,1)-1;
    for k = 1:p
        for i = 1:L
            J = intersect(find(X(:,k)>R(i)),find(X(:,k)<R(i+1)));
            psi_X(J,k) = a(i,k,perturbation_marker(min_indices))*psi_val(i,k);
            c(k) = c(k) + (R(i+1)-R(i))*a(i,k,perturbation_marker(min_indices))*psi_val(i,k);
        end
    end

    Perturbed_PDF_X = Eval_Perturbed_PDF(phi_X,psi_X,delta_val(min_indices),c,Perturbation_Output.delta_weights);

    for k = 1:p
       ratio = Perturbed_PDF_X(:,k)./(Acc_Rej_Bound(min_indices,k)*phi_X(:,k)); 
       for i = 1:N
          u = rand;
          if ratio(i)>u
             Acc(i,k) = 1; 
          end
       end
    end

    Ymin = cell(p,1);
    for k = 1:p
       Ymin{k} = X(Acc(:,k)==1,k); 
    end

    figure()
    ymax = 0;
    for k = 1:p
        hist = histogram(X(:,k),'normalization','pdf');
        ymax = max(ymax,max(hist.Values));
        hist = histogram(Ymin{k},'normalization','pdf');
        ymax = max(ymax,max(hist.Values));
        hist = histogram(Ymax{k},'normalization','pdf');
        ymax = max(ymax,max(hist.Values));
    end
    ymax = 1.1*ymax;

    for k = 1:p
        subplot(p,3,3*k-2);
        histogram(X(:,k),'normalization','pdf','FaceColor','b')
        ylim([0,ymax])
        set(gca,'xtick',[])
        set(gca,'ytick',[])
        subplot(p,3,3*k-1);
        histogram(Ymax{k},'normalization','pdf','FaceColor','r')
        ylim([0,ymax])
        set(gca,'xtick',[])
        set(gca,'ytick',[])
        subplot(p,3,3*k);
        histogram(Ymin{k},'normalization','pdf','FaceColor','c')
        ylim([0,ymax])
        set(gca,'xtick',[])
        set(gca,'ytick',[])
    end

end

end

