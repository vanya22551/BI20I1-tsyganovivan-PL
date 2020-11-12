#include <iostream>


unsigned long long fibonacci(int n)
{
    if (n == 0) { return 0; };
    if (n == 1 || n == 2) { return 1; };

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    for (int i=0; i < 51; i++) 
    {
        std::cout << fibonacci(i); std::cout << " "; std::cout << i << std::endl;
    }
    return 0;
}