#include <iostream>
#include <stack>
#include <map>

int main()
{
    int* num1 = NULL, size1, size2, tmp;
    std::stack <int> num2;
    std::map <int, int> result;

    std::cin >> size1;
    num1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        std::cin >> num1[i];
    }
    std::cin >> size2;
    while (size2--)
    {
        std::cin >> tmp;
        while ( (!num2.empty()) && tmp > num2.top())
        {
            result[num2.top()] = tmp;
            num2.pop();
        }
        num2.push(tmp);
    }
    while (!num2.empty())
    {
        result[num2.top()] = -1;
        num2.pop();
    }

    for (int i = 0; i < size1; i++)
    {
        std::cout << result[num1[i]] << ' ';
    }
    delete[] num1;
    num1 = NULL;
}