#include <iostream>
#include <random>
#include <cmath>

using namespace std;

// (a^d) % n (modular exponentiation)
long long modexp(long long a, long long d, long long n) {
    long long result = 1;
    a = a % n;
    while (d > 0) {
        if (d & 1) result = (result * a) % n;
        a = (a * a) % n;
        d >>= 1;
    }
    return result;
}

bool miller_rabin(long long n, int k = 5) { // k = number of test
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    // n-1 = 2^r * d 
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    //generate random number
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dist(2, n - 2);

    // test k times..
    for (int i = 0; i < k; i++) {
        long long a = dist(gen);
        long long x = modexp(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int j = 0; j < r - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false; // kesin asal değil
    }
    return true; // büyük ihtimalle asal
}

