while(True):
 a,b = sorted(map(int,raw_input().split()))
 if(b == 0): break
 try:
  s = [str(i) for i in range(a,b+1)]
  s = ''.join(s)
 except:
  pass
 c = ['0']*10
 for i in range(10):
  c[i] = str(s.count(str(i)))
 print ' '.join(c)
