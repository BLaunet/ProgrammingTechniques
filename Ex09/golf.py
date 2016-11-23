d=dict(a='apple',g='grape',l='lemon',o='olive')
p=lambda x:print(x)
A=''
for i in range(65,91):A+=chr(i)+chr(i+32)
a=A[1::2]
p(A[::2]+a)
p(A)
J='-'*23+'\n| '
for b in A:J+=b+(' ',' |\n| ')[b in'ejoty']
p(J+' '*15+J[25::-1])
K=''
for b in a:
 if b in d:K+=', '+d[b]+' begins with '+b;b+=': '+d[b]
 p([b])
p(K[2:])
