#include<stdio.h>
#define max 20
int main()
{
	int arr[max][2], clear[max - 1], count = 0;
	int i, j, n;
	printf("Nhap so doan: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("\n\nNhap doan %d:\n", i + 1);
		printf("Gioi han duoi: ");
		scanf("%d", &arr[i][0]);
		printf("Gioi han tren: ");
		scanf("%d", &arr[i][1]);
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(arr[j][0] <= arr[i][1] && arr[i][1] <= arr[j][1])
			{
				arr[i][1] = arr[j][1];
				clear[count++] = j;
			}
		}	
	}
	printf("\n\nKet qua:\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < count; j++)
		{
			if(i == clear[j])
			{
				break;
			}
		}
		if(j < count   )
			continue;
				printf("[%d %d] ", arr[i][0], arr[i][1]);	
	}
	return 0;	
}
