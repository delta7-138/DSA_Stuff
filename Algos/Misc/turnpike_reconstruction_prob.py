from math import *
def check_turnpike(l_dist , l_pikes , index , element):
    if(len(l_dist)==0):
        print("hi")
        if(0 not in l_pikes[1:]):
            return True
        else:
            return False

    elif(0 not in l_pikes[1:]):
        print("hi")
        if(len(l_dist)==0):
            return True
        else:
            return False

    else:
        l_pikes[index] = element
        l_diff = []

        for i in l_pikes[1:]:
            l_diff.append(i)
        for i in l_pikes[1:]:
            for j in l_pikes[i+1:]:
                l_diff.append(abs(l_pikes[i] - l_pikes[j]))
        start_ind_res = len(reserve_list)-1
        
        for i in l_diff:
            if i in l_dist:
                l_dist.remove(i)
                reserve_list.append(i)
            else:
                return False


        check_turnpike(l_dist , l_pikes , index + 1 , l_dist[len(l_dist)-1])
        check_turnpike(l_dist , l_pikes , len(l_pikes) - index , l_pikes[len(l_pikes)-1]-l_dist[len(l_dist)-1])

        for i in reserve_list[start_ind_res:]:
            l_dist.append(i)

        sort(l_dist)


n = int(input())
l_dist = l_pikes = reserve_list = []

for i in range(n):
    l_dist.append(int(input()))

discr = sqrt(1 + 8 * n)
gif = floor(discr)


if(gif!=discr):
    print("NO")
else:
    len_pikes = int((1 + int(discr))/2)
    for i in range(len_pikes):
        l_pikes.append(0)

    l_dist.pop()
    l_pikes[len_pikes-1] = l_dist[n-1]
    print(check_turnpike(l_dist , l_pikes , len_pikes-2 , l_dist[len(l_dist)-1]))
