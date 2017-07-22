#include<iostream>
#include<cstring>

using namespace std;

bool judge(long long n, long long k){
	if (n >= 4){
		if (n % 2 == 0) return k <= n / 2;
		else return (k - 1) <= (n - 3) / 2;
	}
	return false;
}

long long modMult(long long a, long long b, long long mod){
	if (a == 0 || b < mod / a)
		return (a*b) % mod;
	long long sum;
	sum = 0;
	while (b>0){
		if (b & 1)
			sum = (sum + a) % mod;
		a = (2 * a) % mod;
		b >>= 1;
	}
	return sum;
}

long long modPower(long long a, long long b, long long mod){
	long long product, pseq;
	product = 1;
	pseq = a%mod;
	while (b>0){
		if (b & 1)
			product = modMult(product, pseq, mod);
		pseq = modMult(pseq, pseq, mod);
		b >>= 1;
	}
	return product;
}

bool MRabin(long long n, int seed){
	int k = 0;
	if (n < 2) return false;
	if (n == 2) return true;
	if (!(n & 1)) return false;

	long long m = n - 1;
	while (!(m & 1)) m >>= 1, k++;

	long long a = seed;
	a = modPower(a, m, n);
	if (a == 1 || a == n - 1) return true;
	
	for (int j = 0; j < k - 1; j++){
		a = modPower(a, 2, n);
		if (a == 1) return false;
		if (a == n - 1) return true;
	}
	return false;
}

const int MAXN = 1000000;
bool isprime[MAXN + 10];

void Sieve(){
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i*i <= MAXN; i++)
		if (isprime[i])
			for (int j = 2 * i; j <= MAXN; j += i)
				isprime[j] = false;
}



int main(){
	Sieve();
	int t;
	cin >> t;
	while (t-->0){
		long long n, k;
		cin >> n >> k;
		if (k > 2)
			cout << (judge(n, k) ? "Yes" : "No") << endl;
		else if (k == 2){
			if (n % 2 == 0) cout << (n > 2 ? "Yes" : "No") << endl;
			else cout << (PrimalityTest(n - 2) ? "Yes" : "No") << endl;
		}
		else cout << (PrimalityTest(n) ? "Yes" : "No") << endl;
	}
	return 0;
}