#http://www.spoj.com/problems/CANDY3/
#Author - Ashish Kedia, NITK Surathkal
#@ashish1294
T=int(input())
while T>0:
	T-=1
	str=input()
	N=int(input())
	su=0

	for i in range(N):
		su += int(input())

	if su%N==0:
		print "YES"
	else:
		print "NO"
