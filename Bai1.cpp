#include <iostream>
#include <vector>
using namespace std;

class Line
{
public:
    int begin, end;
    Line(int x = 0, int y = 0) : begin(x), end(y) {};
    Line operator+(const Line other) const;
    bool operator<(const Line other);
    bool isMeeted(const Line other);
};

void sortLines(vector<Line> lines);
void mergeLines(vector<Line> &lines);
void printLines(vector<Line> lines);

int main()
{
    int n;
    cin >> n;

    vector<Line> lines;
    for (int i = 0; i < n; i++)
    {
        Line tmp;
        cin >> tmp.begin >> tmp.end;
        lines.push_back(tmp);
    }

    sortLines(lines);
    mergeLines(lines);
    printLines(lines);

    return 0;
}

bool Line::isMeeted(const Line other)
{
    return ((end >= other.begin && begin <= other.end) || (other.end >= begin && other.begin <= end));
}

Line Line::operator+(const Line other) const
{
    Line tmp(0, 0);
    tmp.begin = min(begin, other.begin);
    tmp.end = max(end, other.end);

    return tmp;
}

bool Line::operator<(const Line other)
{
    return (begin < other.begin || (begin = other.begin && end < other.end));
}

void mergeLines(vector<Line> &lines)
{
    int i = 1;

    while (i < lines.size())
    {
        if (lines[i].isMeeted(lines[i - 1]))
        {
            lines[i] = lines[i] + lines[i - 1];
            lines.erase(lines.begin() + i - 1);
        }
        else
        {
            i++;
        }
    }
}

void sortLines(vector<Line> lines)
{
    int n = lines.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (lines[j] < lines[i])
            {
                swap(lines[i], lines[j]);
            }
        }
    }
}

void printLines(vector<Line> lines)
{
    for (int i = 0; i < lines.size(); i++)
    {
        cout << '[' << lines[i].begin << ", " << lines[i].end << ']';
    }
}
