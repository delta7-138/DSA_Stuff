n = int(input())
str_inp = input()
l = []
for i in range(len(str_inp)):
    l.append(int(str_inp[i]))
    if(l[i]==0):
        l[i] = -1

#print(l)

prefix_sum = []
prefix_sum.append(l[0])

#print(prefix_sum)

for i in range(1 , len(l)):
    prefix_sum.append(0)

#print(prefix_sum)
for i in range(1 , len(l)):
    prefix_sum[i] = prefix_sum[i-1] + l[i]

dict_sum = {}

for i in prefix_sum:
    if i not in dict_sum:
        dict_sum[i] = 0

for i in dict_sum:
    str_ind = prefix_sum.index(i)
    end_ind = len(prefix_sum) - prefix_sum[::-1].index(i) - 1

    dict_sum[i] = end_ind - str_ind

max_len = 0
for i in dict_sum:
    if(max_len < dict_sum[i]):
        max_len = dict_sum[i]

print(max_len)



#print(l)
#print(prefix_sum)
