#include<iostream>
#include<algorithm>
using namespace std;
struct doanThang
{
    int first, last;
};
bool soSanh(doanThang dt1, doanThang dt2)
{
    if(dt1.first == dt2.first) return (dt1.last > dt2.first);
    return (dt1.first < dt2.first);
}
int main()
{
    int n;
    cin >> n;
    doanThang arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].last;
    }
    sort(arr, arr + n, soSanh);
    int i = 0;
    while(i < n)
    {
        int j = i;
        while(j < n - 1 && arr[j].last >= arr[j + 1].first)
        {
            j++;
        }
        cout << "[" << arr[i].first << ", " << arr[j].last <<"] ";
        i = j + 1;
    }
    return 0;
}
