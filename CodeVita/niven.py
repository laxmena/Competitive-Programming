# t = 0
# base = 2

# def toBase10(num,b):
#     ans = 0
#     i = 0
#     while(num>0):
#         r = num%10
#         num //= 10
#         ans += r*pow(b,i)
#         i += 1
#     return ans
    
# def sumDigits(n,base):
#     ans = []
#     while(n):
#         ans.append(n%base)
#         n = n//base
#     return sum(ans)

# l = []
# i = 1

# it = 1

# while it < 3000000:
#      variable = toBase10(it,base)
#      s = sumDigits(variable,base)
#      #print(it,variable,s)
#      if(variable%s == 0):
#          l.append(it)
#      it += 1

# i = 2
# print(base)
# res = [0,0,0,0,0,0,0,0,0,0,0]

# for i in range(1,8):
#     window = [l[0]]
#     for each in range(1,len(l)):
#         if(len(window) == 0):
#             window.append(l[each])
#             continue
#         if(l[each] == window[-1]+1):
#             window.append(l[each])
#             if(len(window) > i):
#                 window = []
#         else:
#             if(len(window) == i):
#                 print(i,window)
#                 res[i] = window[0]
#                 break
#             window = [l[each]]
#     #print(window)
# print(res)


memory = [	[0,0,0,0,0,0,0,0,0,0,0], #0
			[0,0,0,0,0,0,0,0,0,0,0], #1
			[0,4,1,198799,0,0,0,0,0,0,0],#2
			[0,6,19,15,1,29896,29978,0,0,0,0],#3
			[0,6,14,8,1,286899,0,0,0,0,0,0],#4
			[0,8,10,95,50,44,1,0,0,0,0],#5
			[0, 10, 19, 68, 3598, 244700, 1, 0, 0, 0, 0], #6
			[0, 15, 36, 91, 4998, 99, 17, 87, 0, 0, 0], #7
			[0, 10, 7, 3798, 58, 6328, 8818, 0, 0, 0, 0], #8
			[0, 11, 10, 9, 88, 7, 29148, 9189, 0, 0, 0], #9
			[0, 12, 20, 110, 510, 131052, 12751220, 10000095, 0, 0, 0] #10
			]

b,n = input().strip().split(' ')
b,n = int(b),int(n)

print(memory[b][n])

#rDpFtKg