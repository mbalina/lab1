#include <iostream>
#include <string>
#include "funcLib.h"


using namespace std;

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const string ABOUT_MESSAGE = "Output: the most frequent number.";
const string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";
const string INPUT_MESSAGE = "Input an integer>";
const string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const string OUTPUT_MESSAGE = "Result: ";
const string SKIP_CHARACTERS = " ";

void ClearInputStream(istream& in) {
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}

int Seek(istream& in)
{
	while (in.peek() != EOLN &&
		SKIP_CHARACTERS.find((char)in.peek()) !=
		string::npos)
	{
		in.get();
	}
	return in.peek();
}

bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		cout << OUT_OF_BOUNDS_MESSAGE << " ["
			<< LEFT_BOUND << ", " << RIGHT_BOUND << "]" <<
			endl;
	}
	return ok;
}

int ReadInt(istream& in)
{
	cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	while (!in || Seek(in) != EOLN ||
		!CheckBounds(ans))
	{
		ClearInputStream(in);
		cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}

bool NeedContinue(istream& in)
{
	cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR
		&& ans != NO_CHAR)
	{
		ClearInputStream(in);
		cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main()
{
	cout << ABOUT_MESSAGE << endl;
	bool cont = true;
	bool flag = false;
	while (cont)
	{
		cout << "Enter the number of elements\n";
		int n = ReadInt(cin);
		int* a = new int[n];
		cout << "Enter elements a set of numbers\n";
		for (int i = 0; i < n; i++) {
			a[i] = ReadInt(cin);
		}
		cout << OUTPUT_MESSAGE << findNum(a, n) << endl;
		delete[] a;
		cont = NeedContinue(cin);
	}
	return 0;
}