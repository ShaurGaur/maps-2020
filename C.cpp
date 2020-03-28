#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

vector<int>& prime_factors(int n) {
    vector<int> primes;
    while (n % 2 == 0) {
        primes.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }

    if (n > 2) primes.push_back(n);
    return primes; 
}

int bits_on(int n) {
    int count = 0;
    if (n > 1) count += bits_on(n / 2);
    count += n % 2;
    return count;
}

int main() {
    int range, n;
    scanf("%d\n", &range);

    for (int i = 0; i < range; i++) {
        scanf("%d\n", &n);
        vector<int> primes = prime_factors(n);
        int bits = bits_on(n);

        printf("bits on: %d\t factors: ", bits);
        for (int p : primes) printf("%d ", p);
        printf("\n");
    }
    return 0;
}