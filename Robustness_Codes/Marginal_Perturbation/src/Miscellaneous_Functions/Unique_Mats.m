function [B,idx] = Unique_Mats(A)

Il = size(A,1);
p = size(A,2);

is_new = true;
I = zeros(p,1);
I(1) = 1;
for k = 2:p

    for j = 1:(k-1)
          if(norm(A(:,:,k)-A(:,:,j))==0)
             is_new = false; 
          end
    end
    
    if is_new == true
       I(k) = 1;
    end
    is_new = true;
end

l = sum(I);
B = zeros(Il,p,l);
idx = zeros(l,1);
count = 1;
for k = 1:p
   if I(k) == 1
      B(:,:,count) = A(:,:,k);
      idx(count) = k;
      count = count + 1;
   end
end

end
