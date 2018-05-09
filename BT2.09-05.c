#include<stdio.h>

int main()
{
	int nums1[10], nums2[15], i, j, k, n, m;
	printf("Nhap so phan tu cua day 1 la: ");
	scanf("%d", &n);
	printf("Cac phan tu cua day 1:\n");
	for(i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &nums1[i]);
	}
	printf("\n\nNhap so phan tu cua day 2 la: ");
	scanf("%d", &m);
	printf("Cac phan tu cua day 2:\n");
	for(i = 0; i < m; i++)
	{
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &nums1[i]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(nums2[j] == nums1[i])
			{
				for(k = j + 1; k < m; k++)
				{
					if(nums2[k] > nums2[j])
					{
						printf("%d ", nums2[k]);
					}
				}
			}
		}
	}
	return 0;
}
