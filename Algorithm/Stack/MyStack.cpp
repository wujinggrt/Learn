#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Status = int;

const int TRUE = 1;
const int OK = 1;
const int FALSE = 0;
const int ERROR = 0;
const int INFEASIBLE = -1;
const int MY_OVERFLOW = - 2;

const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

template <typename T>
class SqStack
{
public:
	SqStack()
		: base(nullptr),
		top(nullptr),
		stackSize(0)
	{
		InitStack();
	}
	SqStack(const int size)
		: base(new  T[size]),
		top(base),
		stackSize(size)
	{
	}

	~SqStack()
	{
		if (stackSize != 0)
		{
			DestroyStack();
		}
	}

	Status InitStack()
	{
		base= new T[STACK_INIT_SIZE];
		top = base;
		stackSize = STACK_INIT_SIZE;
		return OK;
	}
	// InitStack

	Status DestroyStack()
	{
		delete [] base;
		base = top = nullptr;
		stackSize = 0;
		return OK;
	}
	// DestroyStack

	Status ClearStack()
	{
		top = base;
		return OK;
	}
	// ClearStack

	bool StackEmpty() const
	{
		return base == top ? true : false;
	}
	// StackEmpty

	int StackLength()
	{
		return top - base;
	}
	// StackLength

	Status GetTop(T &e) const
	{
		if (StackEmpty()) // should confirm the method const first
		{
			return ERROR;
		}
		e = *(top - 1);
		return TRUE;
	}
	// GetTop

	Status Push(const T e)
	{
		// realloc
		if (top - base == stackSize) // after base[stackSize - 1]
		{
			auto newBase = new T[stackSize + STACKINCREMENT];
			top = nullptr;
			for (int i = 0; i < stackSize; ++i)
			{
				newBase[i] = base[i];
			}
			delete [] base;
			base = newBase;
			top = base + stackSize;
			stackSize += STACKINCREMENT;
		}
		*top = e;
		++top;
		return OK;
	}
	// Push

	Status Pop(T &e)
	{
		if (StackEmpty())
		{
			return ERROR;
		}
		e = *--top;
		return OK;
	}
	// Pop

	Status StackTraverse();

private:
	T *base = nullptr;
	T *top = nullptr;
	int stackSize;
};
// Class SqStack

// enter decimal number and output octal format
void Coversion()
{
	SqStack<int> st;
	int decimal = 0;
	int octal = 0;
	cout << "enter demcial number:";
	cin >> decimal;
	while (decimal)
	{
		st.Push(decimal % 8);
		decimal /= 8;
	}
	while (!st.StackEmpty())
	{
		int out;
		st.Pop(out);
		cout << out;
	}
	cout << endl;
}

void ParentheseCheck()
{
	cout << "Enter parenthese:";
	SqStack<char> st;
	bool status = true;
	string data;
	cin >> data;
	for(auto c : data)
	{
		cout << c << endl;
		switch (c)
		{
		case '(':
			st.Push(c);
			break;
		case ')':
			if (st.StackEmpty()) 
			{
				status == false;
			}
			else
			{
				char temp;
				st.Pop(temp);
			}
			break;
		default:
			break;
		}
	}
	if (status && st.StackEmpty()) 
	{
		cout << "right" << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void EvaluatePostfixExpress()
{
	SqStack<char> st;
	cout << "enter numbers you want to calculate, and separat them by at least one space" << endl;
	string lines;
	getline(cin, lines);
	istringstream is(lines);
	string data;
	SqStack<int> numStack;
	SqStack<string> operatorStack;
	while (is >> data)
	{
		if (IsDigit(data))
		{
			numStack.Push(stoi(data));
		}
		else
		{
			if (data == "+")
			{

			}
			else if (data == "-")
			{

			}
			operatorStack.Push(data);
		}
	}

}

// ÅÐ¶ÏstringÊÇ·ñÊý×Ö
bool IsDigit(const string &s)
{
	for (const auto &c : s)
	{
		if (c > '9' || c < '0')
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.ignore();
	cin.get();
	return 0;
}
