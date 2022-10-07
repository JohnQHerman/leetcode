// find prime factors of given array
// Input: array of integers
// Output: array of prime factors of numbers in input array

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int prime_factors[n];
	for (int i = 0; i < n; i++)
	{
		int j = 2;
		while (arr[i] > 1)
		{
			if (arr[i] % j == 0)
			{
				prime_factors[i] = j;
				arr[i] = arr[i] / j;
			}
			else
			{
				j++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << prime_factors[i] << " ";
	}
	return 0;
}