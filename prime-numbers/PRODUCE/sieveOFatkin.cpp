#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieveOfAtkin(int limit) {
    vector<bool> isPrime(limit + 1, false);
    int sqrtLimit = sqrt(limit);

    
    if (limit >= 2) isPrime[2] = true;
    if (limit >= 3) isPrime[3] = true;

    for (int x = 1; x <= sqrtLimit; x++) {
        for (int y = 1; y <= sqrtLimit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                isPrime[n] = !isPrime[n];

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                isPrime[n] = !isPrime[n];

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                isPrime[n] = !isPrime[n];
        }
    }

    // Clear square divisors
    for (int r = 5; r <= sqrtLimit; r++) {
        if (isPrime[r]) {
            int k = r * r;
            for (int i = k; i <= limit; i += k)
                isPrime[i] = false;
        }
    }

    return isPrime;
}

