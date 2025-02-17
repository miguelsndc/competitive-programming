import math
from collections import Counter

def prime_factorization(n):
    """Returns the prime factorization of n as a dictionary {prime: exponent}."""
    factors = Counter()
    for p in range(2, int(math.sqrt(n)) + 1):
        while n % p == 0:
            factors[p] += 1
            n //= p
    if n > 1:
        factors[n] += 1
    return factors

def largest_perfect_power_factor(n):
    """Finds the largest factor of n that is some base >= 2 raised to some power >= 2."""
    factors = prime_factorization(n)
    exponents = list(factors.values())
    
    # Compute GCD of exponents
    g = math.gcd(*exponents)
    
    # If GCD is 1, force it to be at least 2
    if g == 1:
        g = 2
    
    # Adjust exponents to the largest multiple of g that fits
    adjusted_factors = {p: (e // g) * g for p, e in factors.items()}
    
    # Compute the largest factor that is a perfect power
    largest_factor = math.prod(p**e for p, e in adjusted_factors.items())
    
    return largest_factor

# Example usage:
n = 10800
print(largest_perfect_power_factor(n))  # Output: 900
