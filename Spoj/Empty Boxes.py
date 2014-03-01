#http://www.spoj.com/problems/EBOXES/
#Author - Ashish Kedia, NITK Surathkal
#@ashish1294
tt=int(input())
while tt>0:
	tt-=1
	x=list(raw_input().split(' '))
	N=int(x[0])
	K=int(x[1])
	T=int(x[2])
	F=int(x[3])
	ans= N + (((F-N)*K)/(K-1));
	print ans
