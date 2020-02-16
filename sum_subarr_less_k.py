def check_less_k(list_inp , k , len):
    for i in range(0 , n-len):
        if(list_inp[i + len] - list_inp[i] > k):
            return False
    return True

n = int(input())
l = []
for i in range(n):
    l.append(int(input()))

k = int(input())

prefix_sum = []
prefix_sum.append(l[0])

for i in range(1 , n):
    prefix_sum.append(prefix_sum[i-1] + l[i])

lb = 1
ub = n

while(lb<ub):
    mid = int((lb + ub)/2)
    if(check_less_k(prefix_sum , k , mid)):
        lb = mid + 1
    else:
        ub = mid - 1

print(lb)
