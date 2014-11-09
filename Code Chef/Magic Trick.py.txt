# http://www.codechef.com/JAN14/problems/MTRICK
# Author - Ashish Kedia, NITK Surathkal
# @ashish1294
import sys

T=int(sys.stdin.readline())
while T>0:
	T-=1
	N=int(input())
	L=list(map(int,input().split()))
	a,b,c=map(int,input().split())
	a = a%c
	b = b%c
	str = input()
	toadd = 0
	tomul = 1
	rev=0
	co=0
	f=0
	for i in str:
		co+=1
		if (i=='R'):
			#rev^=1
			L.reverse()
		elif (i=='A'):
			toadd += a
			toadd = toadd%c;
			f=1
		elif (i=='M'):
			tomul *= b
			toadd *= b
			tomul = tomul%c
			toadd = toadd%c
			f=1
		if (rev==0):
			ans=L[0]
			L.pop(0)
		else:
			ans=L[N-co]
			L.pop(N-co)
		if (f==1):
			ans *= tomul
			ans += toadd
		ans = ans%c
		print (ans,end=' ')
	print('')
