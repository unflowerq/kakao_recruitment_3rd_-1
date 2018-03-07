#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> number_set;

void ginbup_transform(int ginbup, int input_number)
{
	string result = "";
	char lit;

	while (input_number != 0)
	{
		lit = input_number%ginbup;

		switch (lit)
		{
		case 10:
			lit = 'A';
			break;
		case 11:
			lit = 'B';
			break;
		case 12:
			lit = 'C';
			break;
		case 13:
			lit = 'D';
			break;
		case 14:
			lit = 'E';
			break;
		case 15:
			lit = 'F';
			break;
		default:
			lit = lit + 48;
			break;
		}

		result = lit + result;
		input_number /= ginbup;
	}

	for (int i = 0; i < result.length(); i++)
	{
		number_set.push_back(result[i]);
	}
}

int main()
{
	int ginbup = 0;
	int want_num_count = 0;
	int people = 0;
	int sequence = 0;
	int output_count = 0;
	int number_set_index = 0;
	int add_number = 1;

	string result = "";

	cin >> ginbup >> want_num_count >> people >> sequence;

	number_set.push_back('0');

	//ginbup_transform(ginbup, 6);

	while (output_count != want_num_count)
	{
		if (sequence - 1 >= number_set.size())
		{
			ginbup_transform(ginbup, add_number);
			add_number++;
		}

		if (number_set_index == sequence - 1)
		{
			result += number_set[number_set_index];
			sequence += people;
			output_count++;
		}
		
		number_set_index++;
	}

	cout << result << endl;

	return 0;
}