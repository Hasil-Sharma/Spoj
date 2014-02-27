from sys import exit
def div(num , x) :
    s=[int(i) for i in num]
    a=int(num[0]) * pow(10,x-1)
    mul=1  
    for i in s[1:]:
        mul*=(i+1)
    c[str(num[0])]+=mul
    a-=1
    l=len(str(a))
    b=str(a)
    for i in range(1,10):
        z=pow(10,l-1)
        y=((z/10)*(int(b[0])+1))*(l-1)
        z=z+(y*(l-1))
        if(i<=int(b[0])):
            c[str(i)]+=z
        else:
            c[str(i)]+=y  
 
while(True):
    global c
    c={}
    d={}
    for i in range(0,10):
        c.update({str(i):0})
        d.update({str(i):0})
    a=raw_input()
    if(a == '0 0'):
        exit(0)
    a=a.split()
    a[0]=str(int(a[0])-1)
    j=0
    for i in range(len(a[j])):        
        if a[j][i]!='0':
            x=len(a[j])-i
            div(a[j][i:] , x)
    e=c.copy()
    c = d.copy()
    j=1
    for i in range(len(a[j])):        
        if a[j][i]!='0':
            x=len(a[j])-i
            div(a[j][i:] , x)
    for i in e:
        c[i]-=e[i]
        c[i]=abs(c[i])
    for i in c:
        if i!='0':
            print c[i],