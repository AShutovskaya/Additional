﻿//5 вариант
#include<iostream>
#include<chrono>
#define M 10000
#define N 100000
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
void quicksort(int a, int b, int(&mas)[N])
{
	if (a >= b)
		return;
	int l = a - 1;
	int r = b + 1;
	int m = rand() % (b - a + 1) + a;
	int k = mas[m];

	while (1)
	{
		do l = l + 1; while (mas[l] < k);
		do r = r - 1; while (mas[r] > k);
		if (l >= r)
			break;
		std::swap(mas[l], mas[r]);
	}

	r++;
	l--;
	quicksort(a, l, mas);
	quicksort(r, b, mas);
}
int binarysearch(int n, int mas1[N], int k)
{
	if (k < mas1[0])
		return -1;
	if (k == mas1[0])
		return 0;
	if (k > mas1[N-1])
		return -1;
	int a = 0;
	int b = n - 1;
	while (a + 1 < b)
	{
		int c = (a + b) / 2;
		if (k > mas1[c])
			a = c;
		else
			b = c;
	}
	if (mas1[b] == k)
		return b;
	else
		return -1;

}
int main()
{
	srand(time(0));
	int mas1[N];
	for (int i = 0; i < N; i++)
		mas1[i] = rand();

	int mas2[M];
	for (int i = 0; i < M; i++)
		mas2[i] = rand();


	int a = 0;
	int b = N - 1;
	int c;
	//быстрая сортировка
	quicksort(a, b, mas1);
	

	Timer t;
	//поиск данных
	for (int i = 0; i < M; i++)
	{
		int j = binarysearch(N - 1, mas1, mas2[i]);

	} 
	/*обычный перебор*/
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mas1[i] == mas2[j])
				break;*/
	
	std::cout << "Time elapsed: " << t.elapsed() << '\n';


	return 0;
}
//C помощью бинарного поиска время выполнения: 0.007735, сложность: O(N*LogN)+Тета(M*LogN)
//C помощью обычного перебора время выполнения : 1.16427 , сложность: O(M*N)
