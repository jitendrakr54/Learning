
// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 1;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 1;
    }
    return max_so_far;
}

int maxSubArrayProduct(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 1;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here * a[i]; 
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here; 
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, -1, -1, -2, -1, -5};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << "\n";
    int max_prod = maxSubArrayProduct(a, n);
    cout << "Maximum contiguous Prod is " << max_prod << "\n";
    return 0;
}
