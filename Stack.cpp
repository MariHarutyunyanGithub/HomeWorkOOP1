/*	1.Define a struct called MyStack which will provide 
you with the functionality of stack(LIFO).
	2.The MyStack object will accept only int numbers and it 
will be limited in size 0 - 10 (can hold maximum 10 integers)
	3.Struct must have user defined special member functions, 
we are familiar with(Constructor, Copy constructor, 
copy assignment operator and destructor)
	4.Also you should provide the following functionality :
		a.Implement pop() member function that will give you 
	the last inserted integer value and will remove it, 
	if there is no such print message “There is no value 
	in stack” and terminate the program.
		b.Implement push(int) member function that will insert 
	int value, if the limit is reached print “There is no 
	space left”and terminate program.
		c.Implement size() member function that will give you 
	correct size in real time(how many elements object holds)
		d.Implement clear() member function that will clear content.
	After this call there will be no elements left in struct
*/

#include <iostream>

const int max_size = 10;

class MyStack
{
public:
	MyStack() {}//constructor

	MyStack(const MyStack& obj)//copy constructor
	{
		for (int i{}; i < max_size; ++i) {
			m_num[i] = obj.m_num[i];
		}
	}

	MyStack& operator=(const MyStack& other)//copy assignment operator
	{
		for (int i{}; i < max_size; ++i) {
			m_num[i] = other.m_num[i];
		}
		return *this;
	}

	~MyStack() {}

	int pop()
	{
		if (top <= 0) {
			std::cout << "There is no value in stack";
			exit(0);
		}
		return m_num[top--];
	}

	bool push(int x)
	{
		if (top >= (max_size - 1)) {
			std::cout << "There is no space left";
			exit(0);
		}
		m_num[++top] = x;
		return true;
	}

	int size()
	{	
		return top;
	}

	void clear()
	{
		if (top <= 0) {
			return;
		}
		do {
			pop();
		} while (top != 0);
	}

private:
	int m_num[max_size]{};
	int top{};
};

int main() {
	MyStack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.pop();
	obj.pop();
	obj.clear();
	std::cout << obj.size();
	return 0;
}