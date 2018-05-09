#include<iostream>
#include<map>
#include<stack>

using namespace std;
int main()
{
    stack<int> s;
    map <int, int> nearestBigger;
    int n1, n2;
    cin >> n1;
    int nums1[n1];
    for(int i = 0; i < n1 ; i++)
    {
        cin >> nums1[i];
    }
    cin >> n2;
    int nums2[n2];
    for(int i = 0; i < n2 ; i++)
    {
        cin >> nums2[i];
    }
    for(int i = 0; i < n2; i++)
    {
        while(!s.empty() && s.top() < nums2[i])
        {
            nearestBigger[s.top()] = nums2[i];
            s.pop();
        }
        s.push(nums2[i]);
    }
    while(!s.empty())
    {
        nearestBigger[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < n1; i++)
    {
        cout << nearestBigger[nums1[i]] << " ";
    }
    return 0;
}
