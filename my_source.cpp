/*1.Define struct with at least 3 different data fields.
Including pointer type as a data member, which allocates data on dynamic storage,
that is does new inside a constructor
(whatever type you want e.g.[int, float, std::string,
yourType or some ptr]).
	a.Lets say int _id, std::string _nameand char* _additionalInformation
2.Write constructors with parameters that initialize data members.
(try to use list initialization and delegating constructors)
3.Write copy constructors, both[const T & andT&] which copies all the members.
4.Create an object of your defined struct myObject_1 and initialize with values.
5.Provide gettersand setters so that you can change its data members.(do not change members directly)
6.Create another objectand copy it, so that it can use a copy constructor.
7.Write copy assignment operator and use it as well
8.Write destructor for the class
9.At the end create a method called toString() which prints all data members of your object.
*/

#include <iostream>

class Student
{
public:
	Student() : m_name{ "Ann" }, m_age{ 20 }, m_rating{ new int }{}//initialization list

	Student(std::string name, int age, int* rating)//constructor with parameters
	{
		m_name = name;
		m_age = age;
		m_rating = new int;
		*m_rating = *rating;
	}
	Student(int age) : Student() { m_age = age; }//delegating constructor

	Student(const Student& obj) {//copy constructor(for consts)
		m_name = obj.m_age;
		m_age = obj.m_age;
		m_rating = new int;
		*m_rating = *(obj.m_rating);
	}

	Student(Student& obj) {//copy constructor
		m_name = obj.m_name;
		m_age = obj.m_age;
		m_rating = new int;
		*m_rating = *(obj.m_rating);
	}

	~Student() {
		if (m_rating) {
			delete m_rating;
			m_rating = nullptr;
		}
	}
	void set_name(std::string name)
	{
		m_name = name;
	}

	void set_age(int age)
	{
		if (age >= 18 && age <= 70) {
			m_age = age;
		}
	}

	void set_rating(int* rating)
	{
		m_rating = rating;
		rating = nullptr;
	}

	std::string const get_name()
	{
		return m_name;
	}

	int  const get_age()
	{
		return m_age;
	}

	int const get_rating()
	{
		return *m_rating;
	}

	Student& operator=(const Student& other)//copy assignment operator
	{
		if (this == &other) {
			return *this;
		}
		m_name = other.m_name;
		m_age = other.m_age;
		m_rating = new int;
		*m_rating = *(other.m_rating);
		return *this;
	}

	void toString()
	{
		std::cout << get_name() << " "
			<< get_age() << " " << get_rating() << std::endl;
	}

private:
	std::string m_name{};
	int m_age{};
	int* m_rating;
};

int main() {
	int* rating = new int;
	*rating = 94;
	Student st1("Ann", 25, rating);//calls ctor with parameters
	Student st2(st1);//calls copy ctor
	Student st3;
	st3 = st2;//calls copy assignment ctor
	st3.toString();
}