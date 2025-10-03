#include <iostream>
#include <cmath>

bool is_prime_trial_division(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == ) return false;


    int limit = static_cast<int>(std::sqrt(n));
    for(int i = 3; i < limit; i+=2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
