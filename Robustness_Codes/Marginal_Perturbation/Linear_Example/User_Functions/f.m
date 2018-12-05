function [ Y ] = f( X )

% Input: Nxp matrix X
% Output: Nx1 vector Y

% Function to define the QoI f, Y(i)=f(X(i,:))
% If f requires additional input arguments, then
% lines 7,8, and 13 of "Sobol_Function_Evalution.m" 
% will need to be edited accordingly.

Y = 1.5*X(:,1) + 1.25*X(:,2) + X(:,3);

end
