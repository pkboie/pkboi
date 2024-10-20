#include <stdio.h>
#include <string.h>

long long memo_f[81], memo_g[81];

long long f(int i);
long long g(int i);

int main(){
    int a, b, c, d ,n;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);

    
    for(int i = 0; i <= n; i++) memo_f[i] = memo_g[i] = -1;
    memo_f[0] = a;
    memo_f[1] = b;
    memo_g[0] = c;
    memo_g[1] = d;

    printf("%lld %lld\n", f(n), g(n));
    return 0;
}

long long f(int i){
    if(i == 0) return memo_f[0];
    else if(i == 1) return memo_f[1];
    else if(memo_f[i] != -1) return memo_f[i];

    if(i%3 == 0){
        memo_f[i] = f(i-1) + g(f(i/3) % i);
        return memo_f[i];
    }
    else{
        memo_f[i] = f(i-1) + g(i-2);
        return memo_f[i];
    }
}

long long g(int i){
    if(i == 0) return memo_g[0];
    else if(i == 1) return memo_g[1];
    else if(memo_g[i] != -1) return memo_g[i];

    if(i%5 == 0){
        memo_g[i] = g(i-1) + f(g(i/5) % i);
        return memo_g[i];
    }
    else{
        memo_g[i] = g(i-1) + f(i-2);
        return memo_g[i];
    }
}
