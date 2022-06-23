#include<iostream>
using namespace std;
int reverse(int n)
{
	if (n / 10 == 0)
		return n;
	else
	{
		int x = int(log10(n));
		x = pow(10, x);
		return (n % 10)*x + reverse(n / 10);
	}

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y = rand() % 1000000 + 1;
		cout << y << ' ' << reverse(y) << endl;


	}
		
	return 0;

}
