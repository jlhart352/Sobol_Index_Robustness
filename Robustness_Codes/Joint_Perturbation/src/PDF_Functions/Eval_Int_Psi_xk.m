function [ Psi_k ] = Eval_Int_Psi_xk( X,k,R,a,psi_val )

% Evaluate int_{\Omega_k} \psi(x) dx_k for each row in X
N = size(X,1);
p = size(X,2);
Psi_k = zeros(N,1);
u = setdiff(1:p,k);
M = length(R);
c = 0;

for i = 1:N
   
    for j = 1:M 
        if min(X(i,u)-reshape(R(j,u,1),1,length(u))) >= 0 && min(reshape(R(j,u,2),1,length(u)) - X(i,u)) >= 0
            c = c + psi_val(j)*a(j)*prod(R(j,k,2)-R(j,k,1));
        end  
    end
    
    Psi_k(i) = c;
    c = 0;
end


end

