#include <bits/stdc++.h>
using namespace std;

long long modmul(long long a, long long b, long long mod) {
    return (__int128)a * b % mod; // overflow önleme
}

long long f(long long x, long long c, long long n) {
    return (modmul(x, x, n) + c) % n;
}

long long gcdll(long long a, long long b) {
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

long long pollardRho(long long n) {
    if (n % 2 == 0) return 2;
    
    srand(time(0));
    long long x, y, c, d = 1;
    while (d == 1) {
        x = rand() % (n - 2) + 2;
        y = x;
        c = rand() % (n - 1) + 1;
        d = 1;
        while (d == 1) {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            d = gcdll(abs(x - y), n);
        }
    }
    if (d == n) return pollardRho(n); // başarısızsa tekrar dene
    return d;
}

void factorize(long long n, vector<long long> &factors) {
    if (n == 1) return;
    if (isPrime(n)) { 
        factors.push_back(n); 
        return;
    }
    long long d = pollardRho(n);
    factorize(d, factors);
    factorize(n / d, factors);
}

