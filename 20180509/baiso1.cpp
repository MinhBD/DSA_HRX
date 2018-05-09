#include <iostream>
#include <cstring>
using namespace std;

int main () {
	int len;
	cin >> len;
	string output;
	int arr[2][len];
	for (int i = 0; i < len; i ++) {
		cin >> arr[0][i];
		cin >> arr[1][i];
	}
	
	if (len != 2) {
		cout << "[[" << arr[0][0] << ", ";
		for (int i = 0; i < len - 1; i ++) {

			if (arr[1][i] < arr[0][i + 1]) {
				cout << arr[1][i] << "], [" << arr[0][i + 1] << ", ";
			}

			if (arr[1][i] >= arr[0][i + 1]) {
				i ++;
				cout << arr[1][i] << "], [" << arr[0][i + 1] << ", ";
				
			}

		}
	cout << arr[1][len - 1] << "]]";
	}
	else {
		if (arr[0][1] < arr[1][0]) {
			cout << "[[" << arr[0][0] << ", " << arr[0][1] << "], [" << arr[1][0] << ", " << arr[1][1] << "]]";
		}
		else {
			cout << "[[" << arr[0][0] << ", " << arr[1][1] << "]]";
		}
	}
}
