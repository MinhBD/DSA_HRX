#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        a[i] = make_pair(x1, x2);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i].second <= a[j].second && a[i].second >= a[j].first)
            {
                cout << (a[i].first <= a[j].first? a[i].first : a[j].first) << " " << a[j].second << endl;
            }
            else if(a[j].second <= a[i].second && a[j].second >= a[i].first)
            {
                cout <<  (a[i].first <= a[j].first? a[i].first : a[j].first) << " " << a[i].second << endl;
            }
        }
    }
    return 0;
}
