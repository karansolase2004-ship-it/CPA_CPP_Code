#include <iostream>
#include <exception> 
#include <typeinfo>

void server_function(int N);

int main(void)
{
	try
	{
		int n;
		std::cout << "Enter an integer:";
		std::cin >> n;
		server_function(n);
	}
	catch (std::exception& e)
	{
		// generic catch block 
		std::cout << "Generic exception handler" << std::endl;
		std::cout << "Exception Name:" << typeid(e).name() << std::endl; 
		std::cout << "Exception Data:" << e.what() << std::endl; 
	}

	std::cout << "Client Continuing after handling the exception" << std::endl;
	std::cout << "Process terminated normally" << std::endl;

	return 0;
}

void server_function(int N)
{
	if (N < 0)
	{
		throw std::range_error("Negative number is sent");
	}
	else if (N > 0)
	{
		throw std::out_of_range("positive number is sent");
	}
	else
	{
		throw std::overflow_error("Overflow occurred");
	}
}