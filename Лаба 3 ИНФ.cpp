#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
using namespace std;

int check_N(string str)
{
	cout << str;
	int res;
	string inp;
	bool state = true;

	while (state)
	{
		getline(cin, inp);
		try
		{
			res = stoi(inp);
			if (inp.size() == to_string(res).size() && res < 10000000 && res > -10000000)
			{
				state = false;
				return res;
			}
			else
				cout << "\nError! Repeat the input!\n";

		}
		catch (invalid_argument)
		{
			cout << "\nError! Repeat the input!!!\n";
		}

	}

}

int check_num() 
{
	int res;
	string inp;
	bool state = true; 

	while (state)
	{
		getline(cin, inp);
		try
		{
			res = stoi(inp);
			if (inp.size() == to_string(res).size() && res < 10000000 && res > -10000000)
			{
				state = false;
				return res;
			}
			else
				cout << "\nError! Repeat the input!\n";

		}
		catch (invalid_argument)
		{
			cout << "\nError! Repeat the input!!!\n";
		}

	}

}

void fillarray(vector<int>& vec, int &n)
{
	n = check_N("\nInput the number integers: ");
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Input the integer #" << i + 1 << ": ";
		int num = check_num();
		vec.push_back(num);
	}
}

void arrayoutput(vector<int>& vec)
{
	cout << "\nCurrent array: [ ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}

void check_bounds(int n, int& start, int &end, string str)
{
	cout << str;
	string inp;
	bool state = true;

	while (state)
	{
		getline(cin, inp);
		try
		{
			if (inp[1] != ' ')
				throw runtime_error("\nError!!! Incorrect format!\n");

			regex regex("\\ ");
			vector<string> out(sregex_token_iterator(inp.begin(), inp.end(), regex, -1), sregex_token_iterator());

			start = stoi(out[0]);
			end = stoi(out[1]);

			if (inp.size() == 3 && start < end && end <= n)
			{
				state = false;
			}
			else
				cout << "\nError! Repeat the input!\n";

		}
		catch (invalid_argument)
		{
			cout << "\nError!!! Repeat the input!\n";
		}
		catch (runtime_error& e)
		{
			cout << e.what() << endl;
		}

	}

}

void check_order_of_sorting(string &order,string str)
{
	cout << str;
	string inp;
	bool state = true;

	while (state)
	{
		getline(cin, inp);
	
		if (inp == "asc" || inp == "desc")
		{
			state = false;
			order = inp;
		}
		else
			cout << "\nError! Repeat the input!\n";
	}

}

void sortingarray(vector<int>& vec, int start, int end, string order)
{
	sort(vec.begin() + (start - 1), vec.end() - (vec.size() - end));

	if (order == "desc")
	{
		reverse(vec.begin() + (start - 1), vec.end() - (vec.size() - end));
	}
}

bool check_Y_N(string str) // Y и N через while
{
	cout << str;
	string inp;
	bool cont;
	bool state = true;

	while (state)
	{
		getline(cin, inp);
	
		if (inp.size() == 1 && (inp[0] == 'Y' || inp[0] == 'N'))
		{
			state = false;
			if (inp[0] == 'Y')
				cont = true;
			else
				cont = false;
			return cont;
		}
		else
		cout << "\nError! Repeat the input!\n";
	}

}

int main()
{
	bool ans = true;
    cout << "\nArray modification" << endl;

    vector<int> vec;
	int n;

	fillarray(vec, n);  // filling in the array

	arrayoutput(vec);  // output an array 

	while (ans)
	{
		int start, end;
		check_bounds(n, start, end, "\nInput bounds of the segment in the format '0 0': ");  // entering the boundaries of the array

		string order;
		check_order_of_sorting(order, "\nInput an order of sorting (asc/desc): ");  // entering the sorting order

		sortingarray(vec, start, end, order); // sorting the array according to the order

		arrayoutput(vec);

		ans = check_Y_N("\nContinue? (Y/N): ");

	}

}