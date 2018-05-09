//Bai 1
#include <iostream>
#include <vector>
#include <algorithm>

bool myCompare(const std::pair <int, int>& first, const std::pair <int, int>& second)
{
    if (first.first < second.first)
    {
        return true;
    }
    else if (first.first == second.first)
    {
        if (first.second <= second.second)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector <std::pair <int, int>> data;
    int size, tmpFirst, tmpSec;

    std::cin >> size;
    data.reserve(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> tmpFirst >> tmpSec;
        data.emplace_back(tmpFirst, tmpSec);
    }

    std::sort(data.begin(), data.end(), myCompare);
    for (int i = 0; i < data.size() - 1;)
    {
        if (data[i + 1].first <= data[i].second)
        {
            data[i + 1].first = data[i].first;
            if (data[i + 1].second < data[i].second)
            {
                data[i + 1].second = data[i].second;
            }
            data.erase(data.begin() + i);
        }
        else
        {
            i++;
        }
    }

    for (auto itr : data)
    {
        std::cout << itr.first << ' ' << itr.second << std::endl;
    }
}