#include <iostream>

using namespace std;

int main () {
	int s1;
	cin >> s1;
	int arr1[s1];
	for (int i = 0; i < s1; i ++) {
		cin >> arr1[i];
	}
	int s2;
	cin >> s2;
	int arr2[s2];
	for (int i = 0; i < s2; i ++) {
		cin >> arr2[i];
	}
	cout << "[";
	for (int i = 0; i < s1; i ++) {
		for (int j = 0; j < s2; j ++) {
			if (arr1[i] == arr2[j]) {
				bool exist = false;
				for (int k = j; k < s2; k ++) {
					if (arr2[j] < arr2[k]) {
						cout << arr2[k];
						break;
					}
					exist = true;
				}
				if (!exist) {
					cout << -1;
				}
			}
		}
		if (i < s1 - 1) {
			cout << ", ";
		}
	}
	cout << "]";
}