//Hashing1
//Simple problem of division using Hashing

#include <iostream>
#include <algorithm>

using namespace std;

/*
Returns True if all the elements can be paired and
sum of each pair is completely divisible by k
else returns False
*/

/* Hashing is used */
bool is_pair(int *list_number, int k, int n)
{
    int frequency[k];

    // initializes all the elements of the array to 0
    fill_n(frequency, k, 0);

    // if the size of the array is odd, cannot pair
    if(n & 1)
        return false;

    // finds the frequency of each remainder
    for(int i = 0; i < n; i++)
    {
        frequency[list_number[i] % k] += 1;
    }

    // checks if the frequency of complementary remainders 
    // (remainders 2 and 8 for k = 10)
    // are same
    for(int i = 1; i < k; i++)
    {
        //int remainder = list_number[i] % k;
        if(frequency[i] != frequency[k - i])
            return false;
    }
    return true;
}

int main()
{
    int list_number[] =  {92, 75, 65, 48, 45, 35, 90, 91, 99, 100};
    int k = 10;
    int n = sizeof(list_number)/sizeof(list_number[0]);
    bool result = is_pair(list_number, k, n);
    cout << ((result) ? "True" : "False") << endl;
    return 0;
}
