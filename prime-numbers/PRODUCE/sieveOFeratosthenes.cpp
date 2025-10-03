#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieveOfEratosthenes(int n) {

    //creating array
    vector<bool> isPrime(n + 1, true);

    // 0 & 1 not prime
    isPrime[0] = false;
    isPrime[1] = false;

    // check is prime numbers to √n
    for (int p = 2; p * p <= n; p++) {
        // if already p is prime
        if (isPrime[p]) {
            // sign as false multiples of p
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }
    return isPrime;
}

