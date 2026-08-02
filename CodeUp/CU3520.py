n=int(input())
ans_l=[]
used_col=[False for _ in range(n)]
used_ru_d=[False for _ in range(2*n-1)]
used_lu_d=[False for _ in range(2*n-1)]
def recur(row,q_l):
    global n,ans_l,used_col,used_ru_d,used_lu_d
    #print(row,*q_l)
    if(row==n+1):
        ans_l.append([col for _,col in q_l])
        return
    for i in range(n):
        if(not used_col[i] and not used_ru_d[row+i-1] and not used_lu_d[n-row+i-1]):
            q_l.append((row,i+1))
            used_col[i]=True
            used_ru_d[row+i-1]=True
            used_lu_d[n-row+i-1]=True
            recur(row+1,q_l)
            del q_l[-1]
            used_col[i]=False
            used_ru_d[row+i-1]=False
            used_lu_d[n-row+i-1]=False
recur(1,[])
ans_l.sort()
print(*ans_l[0])
print(*ans_l[1])
print(*ans_l[2])
print(len(ans_l))
#그나마 할..만 했다.
#비트마스크를 이용하니 그럭저럭 잘 풀렸다.
#체커 도전 (N-Queen Problem)
