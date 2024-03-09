#include <iostream>
using namespace std;

int maxProfit(int a[], int start, int end)
{
	if (end - start == 1) return 0;
	int Max = a[start + 1], tMax;
	int Min = a[start + 1], tMin;
	for (int i = start + 1; i < end; i++)
	{
		if (a[i] > Max)
		{
			Max = a[i];
			tMax = i;
		}
		else if (a[i] < Min)
		{
			Min = a[i];
			tMin = i;
		}
	}

	if (tMax > tMin) return Max - Min;
	else if (Max == Min) return 0;
	else
	{
		int Max2 = Min;
		int Min2 = Max;
		for (int i = start + 1; i < tMax; i++)
		{
			if (a[i] < Min2) Min2 = a[i];
		}

		for (int i = tMin + 1; i < end; i++)
		{
			if (a[i] > Max2) Max2 = a[i];
		}

		int kq;
		if (Max2 - Min > Max - Min2) kq = Max2 - Min;
		else kq = Max - Min2;

		int kq2 = maxProfit(a, tMax, tMin);

		return max(kq, kq2);
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int kq = maxProfit(a, -1, n);
	cout << kq << endl;

	return 0;
}