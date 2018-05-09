#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Pair
{
public:
    int first, second;
    Pair(int x, int y) : first(x), second(y) {};
};

vector<Pair> getPairs(int n, int arr[]);
int getHigherValue(int value, vector<Pair> pairs);

int main()
{
    int n, m;

    cin >> m;
    int child[m];
    for (int i = 0; i < m; i++)
    {
        cin >> child[i];
    }

    cin >> n;
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
    }

    vector<Pair> pairs = getPairs(n, parent);
    for (int i = 0; i < m; i++)
    {
       cout << getHigherValue(child[i], pairs) << " ";
    }

    return 0;
}
vector<Pair> getPairs(int n, int arr[])
{
    vector<Pair> pairs;
    stack<int> tmpStack;
    int i = 0;
    while (i < n)
    {
        if (tmpStack.empty() || arr[i] <= tmpStack.top())
        {
            tmpStack.push(arr[i]);
            i++;
        }
        else
        {
            Pair tmpPair(tmpStack.top(), arr[i]);
            pairs.push_back(tmpPair);
            tmpStack.pop();
        }
    }

    return pairs;
}

int getHigherValue(int value, vector<Pair> pairs)
{
    for (int i = 0; i < pairs.size(); i++)
    {
        if (value == pairs[i].first)
        {
            return pairs[i].second;
        }
    }
    return -1;
}
