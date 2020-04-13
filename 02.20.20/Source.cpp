#include <string>
#include <ctime>
#include <utility>
#include <iostream>

using namespace std;

class Employee
{
protected:
	string empName, empSSN;
public:
	Employee(string n, string ssn)
	{
		empName = n;
		empSSN = ssn;
	}
	string getName()const { return empName; }
	void setName(string stName) { empName = stName; }
	string getSSN()const { return empSSN; }
	void setSSN(string ssn) { empSSN = ssn; }
	virtual void displayInfo() { cout << "NAME:  " << empName << "  SSN:  " << empSSN << endl; }
	virtual double getWage()const = 0;

};

class salaryEmployee : public Employee
{
public: 
	salaryEmployee(const string& name, const string& ssn, int sal): Employee(name, ssn)
	{
		salary = sal;
	}
	int getSalary()const { return salary; }
	void setSalary(int sal) { salary = sal; }
	void displayInfo()
	{
		Employee::displayInfo();
		cout << "Salary:  " << salary << endl;
	}
	double getWage()const
	{
		return salary / 52;
	}
private:
	int salary;

};
class hourlyEmployee : public Employee
{
public:
	hourlyEmployee(const string& name, const string& ssn, double payR, double h) : Employee(name, ssn)
	{
		 payRate = payR;
		 hours = h;
	}
	double getPayRate()const { return payRate; }
	void setPayRate(double payR) { payRate = payR; }
	double getHours()const { return hours; }
	void setHours(double h) { hours = h; }
	void displayInfo()
	{
		Employee::displayInfo();
		cout << "Rate: $" << payRate << " Hours: " << hours << endl;
	}
	double getWage()const
	{
		return hours * payRate;
	}
private:
	double payRate;
	double hours;

};
int main()
{
	salaryEmployee Ben("Ben", "246-89-2567",400000);
	hourlyEmployee Dylan("Dylan", "333-45-3678", 200.0, 40.0);

	Employee* ptr;
	salaryEmployee a("Ken", "123-44-5555", 120000);
	hourlyEmployee b("Cole", "222-33-4444", 12.50, 40);
	ptr = &a;
	ptr->displayInfo();
	ptr = &b;
	ptr->displayInfo();



	return 0;
}
//virtual functions provide a way for pointers to dynamically bind to a
//version of the function that matches the object.
//Pure virtual functions do the same plus make the class in which they are declared abstract.