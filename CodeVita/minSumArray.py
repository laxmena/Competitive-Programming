n,k = input().strip().split(' ')
n,k = int(n), int(k)

a1 = [int(i) for i in input().strip().split(' ')]
a2 = [int(i) for i in input().strip().split(' ')]

minSum = 0
maxDiff = 0

for i in range(len(a1)):
	product = a1[i] * a2[i]
	if product<0 and a1[i]<0:
		temp = (a1[i]-2*k)*a2[i]
	elif product<0 and a2[i]<0:
		temp = (a1[i]+2*k)*a2[i]
	elif product>0 and a1[i]>0:
		temp = (a1[i]-2*k)*a2[i]
	elif product>0 and a1[i]<0:
		temp = (a1[i]+2*k)*a2[i]
	elif product==0 and a1[i] == 0 and a2[i] > 0:
		temp = (a1[i]-2*k)*a2[i]
	elif product==0 and a1[i] == 0 and a2[i] < 0:
		temp = (a1+2*k)*a2[i]

	diff = abs(product-temp)
	if diff>maxDiff:
		maxDiff = diff
	minSum += product

print (minSum-maxDiff)
