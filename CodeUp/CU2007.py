n=int(input())
l=list(map(int,input().split()))
lu,ld=sorted(l),sorted(l,reverse=True)
if(l==lu):
    print("오름차순")
elif(l==ld):
    print("내림차순")
else:
    print('섞임')
  #오름차순? 내림차순? 1
