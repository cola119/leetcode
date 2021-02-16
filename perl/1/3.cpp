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
    int i;
    for (i = 0; i < N; i++)
    {
        clr(i);
    }
    while (scanf("%d", &i) != EOF)
    {
        set(i);
    }
    for (i = 0; i < N; i++)
    {
        if (test(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}