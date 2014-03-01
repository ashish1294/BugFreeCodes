#http://www.spoj.com/problems/SUPOVR/
#Author - Ashish Kedia, NITK SUrathkal
#@ashish1294

x = raw_input().split()
b = [0,0,0]
s = 0
ns = 1
w = 0
for i in x:
        if w==2:
                break
        elif i == 'O' or i == 'o':
                w += 1
                s = 2
        elif i in ('W','w','n','N'):
                pass
        else:
                b[s] += int(i)
                if int(i)%2:
                        s,ns = ns,s
for i in b:
        print i
