class Solution {
public:
    double power(double b, int e) {
        if (b == 0) return 0;   // Base case: 0^e is 0 for e > 0
        if (e == 0) return 1;   // Base case: b^0 is 1

        // Handle negative exponents
        long long exp = e;  // Use long long to avoid overflow with large negative e
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If e is odd, multiply result by b
                result *= b;
            }
            b *= b;  // Square the base
            exp /= 2; // Divide exponent by 2
        }

        return result;
    }
};
