#include <iostream>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N / BITSPERWORD];

void set(int i)
{
    a[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i)
{
    a[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i)
{
    return a[i >> SHIFT] & (i << (i & MASK));
}

void print_array(int array[1 + N / BITSPERWORD])
{
    for (int i = 0; i < (1 + N / BITSPERWORD); i++)
    {
        std::cout << array[i];
    }
    std::cout << "" << std::endl;
}

int main()
{
    // ??
    set(10);
    set(1);
    std::cout << test(10) << std::endl;
    std::cout << test(2) << std::endl;
    std::cout << test(1) << std::endl;
    return 0;
}