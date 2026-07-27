blank=[]
l=[list(map(int,input().split())) for _ in range(9)]
row=[[False for _ in range(9)] for _ in range(9)]
col=[[False for _ in range(9)] for _ in range(9)]
box=[[False for _ in range(9)] for _ in range(9)]
for y in range(9):
    for x in range(9):
        if(l[y][x]!=0):
            row[y][l[y][x]-1]=True
            col[x][l[y][x]-1]=True
            box[(y//3)*3+x//3][l[y][x]-1]=True
def check(x,y,num):
    if(col[x][num-1]):
        return False
    if(row[y][num-1]):
        return False
    if(box[(y//3)*3+x//3][num-1]):
        return False
    return True
def sudoku_backtrack(idx):
    if(idx==len(blank)):
        for k in l:
            print(*k)
        return True
    x,y=blank[idx]
    for i in range(1,10):
        if(check(x,y,i)):
            l[y][x]=i
            row[y][i-1]=True
            col[x][i-1]=True
            box[(y//3)*3+x//3][i-1]=True
            if(sudoku_backtrack(idx+1)):
                return True
            l[y][x]=0
            row[y][i-1]=False
            col[x][i-1]=False
            box[(y//3)*3+x//3][i-1]=False
for x in range(9):
    for y in range(9):
        if(l[y][x]==0):
            blank.append((x,y))
if blank:
    if not sudoku_backtrack(0):
        print("Not Possible")
else:
    for k in l:
        print(k)
#.... 힘들었다.각 행,열,박스마다 있는 수를 저장해 놓는 시스템을 도입했더니 바로 되긴 했다.
#스도쿠
