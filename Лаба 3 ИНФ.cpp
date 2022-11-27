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

			if (res > 0 && inp.size() == to_string(res).size())
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
		catch (out_of_range)
		{
			cout << "\nOh, out of range!!!\n" << endl;
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

int check_start(string str, int n)
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

			if (res < n && res > 0 && inp.size() == to_string(res).size())
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
		catch (out_of_range)
		{
			cout << "\nOh, out of range!!!\n" << endl;
		}

	}

}

int check_end(string str, int n, int start)
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

			if (start < res && res <= n && inp.size() == to_string(res).size())
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
		catch (out_of_range)
		{
			cout << "\nOh, out of range!!!\n" << endl;
		}

	}

}

void check_bounds(int n, int& start, int &end, string str)
{
	start = check_start("\nEnter the upper bound: ", n);
	end = check_end("\nEnter the lower bound: ", n, start);	
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

void sortingdesc(vector<int>& vec, int start, int end)
{
	reverse(vec.begin() + (start - 1), vec.end() - (vec.size() - end));
}

void mergesortimpl(vector<int>& arr, vector<int>& buf, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;

		// разделяем и сортируем
		mergesortimpl(arr, buf, left, middle);

		mergesortimpl(arr, buf, middle + 1, right);

		int k = left;

		// слияние двух отсортированных половин
		for (int i = left, j = middle + 1; i <= middle || j <= right; )
		{
			if (j > right || (i <= middle && arr[i] < arr[j]))
			{
				buf[k] = arr[i];
				++i;
			}
			else
			{
				buf[k] = arr[j];
				++j;
			}
			++k;
		}

		for (int i = left; i <= right; ++i)
		{
			arr[i] = buf[i];
		}
	}
}

void mergesort(vector<int>& vec, int start, int end)  // сортировка слиянием
{
	if (!vec.empty()) 
	{
		vector<int> buf(vec.size());  // создаем вектор buf, по размеру равный первоначальному вектору
		mergesortimpl(vec, buf, start - 1, (vec.size() - 1 - (vec.size() - end)));
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
		check_bounds(n, start, end, "\nInput bounds of the segment: ");  // entering the boundaries of the array

		string order;
		check_order_of_sorting(order, "\nInput an order of sorting (asc/desc): ");  // entering the sorting order

		mergesort(vec, start, end); // sorting the array

		if (order == "desc")
			sortingdesc(vec, start, end);

		arrayoutput(vec);

		ans = check_Y_N("\nContinue? (Y/N): ");

	}

}