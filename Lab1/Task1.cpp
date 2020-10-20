#include <iostream>

using namespace std;

void bubble_sort(char **tab, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (atoi(tab[j]) > atoi(tab[j + 1]))
			{
				swap(tab[j], tab[j + 1]);
			}
		}
	}
	cout << "out = ";
	for (int i = 1; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "Empty input";
		return 0;
	}
	bubble_sort(argv, argc);

	return 0;
}