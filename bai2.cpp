#include <iostream>

using namespace std;

int main()
{
	int size1;
	cin >> size1;
	int nums1[size1];
	for (int i = 0; i < size1; ++i)
	{
		cin >> nums1[i];
	}

	int size2;
	cin >> size2;
	int nums2[size2];
	for (int i = 0; i < size2; ++i)
	{
		cin >> nums2[i];
	}


	cout << '[';

	for (int i = 0; i < size1; ++i)
	{
		int j = 0;
		while (j < size2 && nums2[j] != nums1[i]) j++;
		while (j < size2 && nums2[j] <= nums1[i]) j++;
		if (j == size2)
		{
			cout << -1;
			if (i != size1 - 1)
			{
				cout << ", ";
			}
		}
		else
		{
			cout << nums2[j];
			if (i != size1 - 1)
			{
				cout << ", ";
			}
		}
	}


	cout << ']';
	return 0;

}