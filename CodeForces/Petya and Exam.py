inpSet = set(list(input().strip()))
pattern = input()

t = int(input().strip())

for _ in range(t):
	test = input()

	# if( ('*' not in pattern) and 
	# 	(len(test) != len(pattern)) ):
	# 		print ("NO")
	# 		continue

	flag = True
	inc = 1
	i,j = 0,0
	print("Output: #",_,end=" ")
	while(i<len(pattern) and j<len(test)):
		if(pattern[i] == '?'):
			if(test[j] not in inpSet):
				flag = False
				break

		elif(pattern[i] == '*'):
			while((j<len(test))):
				if(test[j] in inpSet):
					if(pattern[i] != test[j]):
						flag = False
					break
				else:
					j += 1
			if(j==len(test) and i<(len(pattern)-1)):
				flag = False

		elif(pattern[i] != test[j] or test[j] not in inpSet):
			flag = False
			break

		i += 1
		j += 1

	if(flag == True):
		print("YES")
	else:
		print("NO")
# abc
# a?a?a*
# 4
# abacaba
# abaca
# apapa
# aaaaax

# ab
# a?a
# 2
# aaa
# aab

