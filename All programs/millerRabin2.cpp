
#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

int tab[32][32];
inline void compute(){
    register int i, j, sfx, tfx;
    for (i = 1; i <= 31; ++i)
        for (j = 0; j < i; ++j) {
            sfx = 1 << (i - 1);
            if (j == 0){
                tab[i][j] = sfx;
            } else if (i - j == 1) {
                tab[i][j] = sfx >> 1;
            } else {
                tfx = (1 << j) - 1;
                tab[i][j] = sfx - tfx;
            }
        }
}
const int TEST = 10;
int main() {

    compute();
    int t;
    cin >> t;
    assert(1 <= t && t <= 1e6);
    register int N, X, tot, targ, px, i, ans, tx, mx;
    while (scanf("%d", &N) != EOF) {
        assert(1 <= N && N <= 1e9);
        if (N == 1 || N == 2) {printf("1\n");continue;}
        X = 1, px = 1;
        while(X <= N) {X <<= 1; ++px;}
        X >>= 1, --px;
        tot = N - X + 1;
        if (tot & 1) {
            targ = 1 ^ px, ans = X - 1, mx = px - (tot == 1);
            for (i = 2; i <= mx; ++i) {
                tx = targ ^ i;
                if (tx < i) { 
                    if (ans == -1 || ans > tab[i][tx])
                        ans = tab[i][tx];
                }
            }
            printf("%d\n", ans);
        }
        else printf("1\n");
    }
    return 0;
}