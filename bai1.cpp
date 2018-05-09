#include <iostream>
#include <vector>

using namespace std;

struct line
{
	int start;
	int end;
};

bool operator>(line line1, line line2);
int main()
{
	int size;
	cin >> size;
	vector<line> input;
	line temp;

	for (int i = 0; i < size; ++i)
	{
		cin >> temp.start;
		cin >> temp.end;
		input.push_back(temp);
	}

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				swap(input[i], input[j]);
			}
		}
	}

	int i = 0;
	while (i < input.size() - 1)
	{
		if (input[i].end > input[i + 1].start)
		{
			input[i + 1].start = input[i].start;
			input.erase( input.begin() + i );
		}
		else
		{
			i++;
		}
	}

	cout << '[';
	for (i = 0; i < input.size(); ++i)
	{
		cout << '[' << input[i].start << ',' << input[i].end << ']';
		if (i == input.size() - 1)
		{
			break;	
		}
		else
		{
			cout << ',';
		}
	}
	cout << ']';

	return 0;
}

bool operator>(line line1, line line2)
{
	if (line1.start > line2.start)
	{
		return true;
	}
	if (line1.start == line2.start)
	{
		if (line1.end > line2.end)
		{
			return true;
		}
	}
	return false;
}