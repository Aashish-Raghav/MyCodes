#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num);

//using Sieve of Erathostheses;
int countPrime(int num);

int main()
{
    // int n,count = 0;
    // cout << "enter the number : ";
    // cin >> n;
    // for (int i = 2;i <= n;i++)
    // {
    //     if (isPrime(i))
    //     {
    //         count++;
    //         cout << i << " ";
    //     }
    // }
    // cout << "try" << endl;
    cout << "count = " << countPrime(47);
    return 0;
}

bool isPrime(int num)
{
    if ( num == 1 || num == 2)
        return false;
    for (int i = 2;i < num/2;i++)
    {
        if (num % i == 0)
        return false;
    }
    return true;
}

int countPrime(int num)
{
    int count = 0;
    //create a vector with all no as prime;
    vector<int> prime(num+1,true);
    
    //setting 0 and 1 as non prime;
    prime[0] = prime[1] = false;
    int i = 2;
    while ( i < num)
    {
        if (prime[i] == true)
        {
            count++;

            for (int j = 2*i;j <= num;j+=i)
            {
                prime[j] = false;
            }
        }
        i++;
    }
    return count;

}