n=int(input())
l=list(map(int,input().split()))
lu,ld=sorted(l),sorted(l,reverse=True)
if(l==lu and l==ld):
	print('섞임')
elif(l==lu):
    print("오름차순")
elif(l==ld):
    print("내림차순")
else:
    print('섞임')
  #오름차순? 내림차순? 2
