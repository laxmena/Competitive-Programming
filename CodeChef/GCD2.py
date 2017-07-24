t = int(input())

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

for _ in range(t):
    a,b = input().strip().split(' ')
    a,b = int(a),int(b)
    print(gcd(b,a))
    
