/*
Kevin Lehman - 1463553
Tarrant County College - COSC 1437 - Fall 2017
Assignment  3-3 Source Code
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
bool checkSort(vector<string>);
bool bubbleSort(vector<string>, int);

vector<string> split(const string& s, const string& delim)
{
	const bool keep_empty = true;
	vector<string> result;

	if (delim.empty())
	{
		result.push_back(s);
		return result;
	}
	string::const_iterator substart = s.begin(), subend;
	while (true)
	{
		subend = search(substart, s.end(), delim.begin(), delim.end());
		string temp(substart, subend);
		if (keep_empty || !temp.empty())
		{
			result.push_back(temp);
		}
		if (subend == s.end())
		{
			break;
		}
		substart = subend + delim.size();
	}
	return result;
}

int main()
{
	ifstream inputFile;
	string input;
	vector<string> airportCode;
	vector<string> result;
	int size;
	int length;
	bool sortResult;

	inputFile.open("airports.dat");

	if (inputFile)
	{
		cout << "Step 1: Opening File." << endl;

		getline(inputFile, input);

		cout << "Step 2: Reading a line from airport.dat." << endl;

		while (inputFile)
		{
			cout << " Passing current line to split method." << endl;

			result = split(input, ",");

			cout << "Validating airport code is 3 letters in length." << endl;

			cout << result[4] << endl;

			size = result[4].size();

			if (size == 3)
			{
				cout << "Storing valid airport code in new vector." << endl;
				airportCode.push_back(result[4]);
			}
			getline(inputFile, input);
		}

		length = airportCode.size();

		cout << "Step 3: The new vector Airport Code is " << length << " codes long." << endl;

		cout << "Step 4: Checking if vector is sorted." << endl;

		checkSort(airportCode);

		if (!checkSort(airportCode))
		{
			cout << "Vector Airport Code is not sorted." << endl;
			cout << "Step 5: Sorting Vector." << endl;
			sortResult = bubbleSort(airportCode, length);
		}
		if (sortResult = true)
		{
			cout << "Step 6: Checking if vector is sorted." << endl;
			cout << "Vector Airport Code is sorted." << endl;
		}
	}
	else
	{
		cout << "There was an error opening the file." << endl;
	}

	inputFile.close();
	system("Pause");
	return 0;
}

bool checkSort(vector<string> airportCode)
{
	if (is_sorted(airportCode.begin(), airportCode.end()))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool bubbleSort(vector<string> airportCode, int length)
{
	bool swap;
	string temp;

	do
	{
		swap = false;
		for (int count = 0; count < (length - 1); count++)
		{
			if (airportCode[count] > airportCode[count + 1])
			{
				temp = airportCode[count];
				airportCode[count] = airportCode[count + 1];
				airportCode[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	return true;
}