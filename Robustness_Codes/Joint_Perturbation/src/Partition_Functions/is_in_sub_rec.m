function [ J_Sub ] = is_in_sub_rec( B,A,k )

N = size(A,1);
p = size(A,2);
J1 = zeros(N,p-1);
J2 = zeros(N,p-1);
A = A(:,setdiff(1:p,k));
B = B(setdiff(1:p,k),:);

for i = 1:(p-1)
    J1(:,i) = B(i,1)<=A(:,i);
    J2(:,i) = B(i,2)>=A(:,i);
end

J = J1.*J2;
J_Sub = find(sum(J,2)==p-1);

end

