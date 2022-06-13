#include<iostream>
#include<chrono>
using namespace std;
void ShellSort(int n, int mas[])
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for(i = step;i < n;i++)
	{
		tmp = mas[i];
		for (j = i; j >= step; j -= step)
		{
			if (tmp < mas[j - step])
				mas[j] = mas[j - step];
			else
				break;
		}
		mas[j] = tmp;
	}

}
int main()
{
	int N;
	cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; i++)
		cin >> mas[i];
	ShellSort(N, mas );
	for (int i=0;i<N;i++)
		cout << mas[i] << endl;
	
	return 0;
}

//при N=5
//Заданный массив: -10 0 9 4 -6
//Отсортированный :-10 -6 0 4 9
//Cложность O(N^2)
