#include<iostream>
#include<stack>

using namespace std;

int n;
void printStack(stack<int> &s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void check(int arr1[], int arr2[])
{
    stack<int> my;
    int i, j;
    for(i = 1; i <= n; i++)
    {
        if(my.top() >= arr1[i] || my.top() == 0)
        {
            for(j = arr1[i]; j <= arr2[i]; j++)
            {
                if(my.top() < j)
                    my.push(j);
            }
        }
        else
        {
            printStack(my);
            my.top() = 0;
        }

    }

//}
}

int main()
{
    cout << "nhap n: ";
    cin >> n;
    int arr1[10], arr2[10], i, j;
    for(i = 1; i <= n; i++)
    {
        cin >> arr1[i];
        cin >> arr2[i];
    }
    check(arr1, arr2);
}

