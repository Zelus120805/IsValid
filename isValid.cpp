#include <iostream>
#include <string>
using namespace std;

void xoaPhanTu(char a[], int i, int j, long& n)
{
	for (int k = j; k < n - 1; k++)
	{
		a[k] = a[k + 1];
	}
	n--;
	for (int k = i; k < n - 1; k++)
	{
		a[k] = a[k + 1];
	}
	n--;
}

bool isValid(char a[], long n)
{
	if (n % 2 != 0) return false;
	else if (n == 0) return true;

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == '(')
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] == ')' && (j - (i + 1)) % 2 == 0)
				{
					xoaPhanTu(a, i, j, n);
					if (isValid(a, n)) return true;
				}
			}
			return false;
		}

		else if (a[i] == '[')
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] == ']' && (j - (i + 1)) % 2 == 0)
				{
					xoaPhanTu(a, i, j, n);
					if (isValid(a, n)) return true;
				}
			}
			return false;
		}

		else if (a[i] == '{')
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] == '}' && (j - (i + 1)) % 2 == 0)
				{
					xoaPhanTu(a, i, j, n);
					if (isValid(a, n)) return true;
				}
			}
			return false;
		}
	}

	return false;
}

int main()
{
	char a[100];
	cin.getline(a, 100);
	long n = strlen(a);
	
	if (isValid(a, n)) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}