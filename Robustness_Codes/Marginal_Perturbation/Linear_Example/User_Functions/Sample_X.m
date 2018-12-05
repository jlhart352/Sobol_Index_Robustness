function [ X ] = Sample_X( N )

% Input: Integer N
% Output: Nxp matrix X

% Draw N samples from the random vector X 

a = [1.2,1.4,1.6];
b = [1.2,1.4,1.6];

X = zeros(N,3);
for k = 1:3
   X(:,k) = betarnd(a(k),b(k),N,1); 
end

end
