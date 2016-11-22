d={'a':'apple','g':'grape','l':'lemon','o':'olive'}
p=lambda x:print(x)
A=''.join([chr(i)+chr(i+32)for i in range(65,91)])
a=A[1::2]
p(A[::2]+a)
p(A)
h='-'*23+'\n| '
p(h+' '.join([(b,b+' |\n|')[b in'ejoty']for b in A])+' '*16+h[::-1])
for b in a:p(([b],[b+': ',d.get(b,)])[b in d])
p(', '.join(d[f]+' begins with '+f for f in sorted(d)))
