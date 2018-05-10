#include <stdio.h>

#define MAX 100

int main()
{
	int a[MAX][MAX], n, i;
	int head, tail, check;
	printf("\nNhap n: ");
	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i][0]);
		scanf("%d", &a[i][1]);
	}
	
	for (i = 0; i < n; ++i)
	{
		if (a[i][1] < a[i + 1][0])
		{
			head = a[i][0];
			tail = a[i][1];
			i++;
		}
		else
		{
			head = a[i][0];
			if (i == n - 1)
			{
				tail = a[i][1];
			}
			else
			{
				tail = a[i + 1][1];
				i++;
			}
			
		}
		printf("[%d %d] ", head, tail);
	}

	return 0;
}
