#include <stdlib.h>
int i;
// Modular Exponentiation
unsigned int mod_exp(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned int result = 1;
    base = base % mod; // Ensure base is less than mod

    while (exp > 0) {
        if (exp % 2 == 1) { // If the least significant bit is 1
            result = (result * base) % mod;
        }
        exp = exp >> 1;       // Right shift exponent (divide by 2)
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Fermat Primality Test
int is_prime(unsigned int n, int iterations) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    for ( i = 0; i < iterations; i++) {
        unsigned int a = 2 + (rand() % (n - 4));  // Random a in [2, n-2]
        if (mod_exp(a, n - 1, n) != 1) return 0;
    }
    return 1;
}
// Compute the greatest common divisor using the Euclidean algorithm
unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Compute Euler's Function phi(n)
unsigned int compute_phi(unsigned int p, unsigned int q) {
    return (p - 1) * (q - 1);
}

// Find the smallest valid e
unsigned int find_e(unsigned int phi) {
    unsigned int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            return e;  // Return the first valid e
        }
    }
    return 0;  // Should never happen if phi > 2
}
// Extended Euclidean Algorithm to find the modular inverse of e modulo phi(n)
unsigned int mod_inverse(unsigned int e, unsigned int phi_n) {
    int t = 0, new_t = 1;
    int r = phi_n, new_r = e;
    int quotient, temp;

    while (new_r != 0) {
        quotient = r / new_r;

        // Update t and new_t
        temp = t;
        t = new_t;
        new_t = temp - quotient * new_t;

        // Update r and new_r
        temp = r;
        r = new_r;
        new_r = temp - quotient * new_r;
    }

    if (r > 1) {
        // No modular inverse exists if gcd(e, phi_n) is not 1
        return 0;
    }

    if (t < 0) {
        t = t + phi_n;  // Ensure positive result
    }

    return t;
}


unsigned int decrypt_crt(unsigned int y, unsigned int d, unsigned int p, unsigned int q) {
    unsigned int dp = d % (p - 1); // d mod (p-1)
    unsigned int dq = d % (q - 1); // d mod (q-1)
    unsigned int yp, yq, xp, xq, cp,cq,x,x1,x2;

    // Compute modular inverses: cp,cq 
	cp = mod_inverse(q, p);
	cq = mod_inverse(p, q);

    // Compute modular exceptions: yp,yq 
	yp= mod_exp(y,p);
	yq= mod_exp(y,q);
    // Compute xp and xq
    xp = mod_exp(yp, dp, p);
    xq = mod_exp(yq, dq, q);

    // Combine results using CRT
    x1=q*cp*xp;
    x2=p*cq*xq;
	x=mod_exp(x1+x2,p*q);
    return x;
}
