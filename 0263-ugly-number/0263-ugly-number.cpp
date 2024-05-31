class Solution {
public:

    bool isUgly(int n) 
    {
        vector<int> primeFactors;
        // Check for the number of 2s that divide n
        while (n % 2 == 0) 
        {
            primeFactors.push_back(2);
            n /= 2;
        }

        // Check for the number of 3s that divide n
        while (n % 3 == 0) 
        {
            primeFactors.push_back(3);
            n /= 3;
        }

        // n must be odd at this point, so we can skip even numbers
        for (int i = 5; i * i <= n; i += 6) 
        {
            while (n % i == 0) 
            {
                primeFactors.push_back(i);
                n /= i;
            }
            while (n % (i + 2) == 0) 
            {
                primeFactors.push_back(i + 2);
                n /= (i + 2);
            }
        }

        // This condition is to check if n is a prime number
        // greater than 4
        if (n > 4) 
        {
            primeFactors.push_back(n);
        }

        for(auto it : primeFactors)
        {
            if(it!=2 && it!=3 && it!=5)
            {
                return false;
            }
        }
        return true;
    }
};