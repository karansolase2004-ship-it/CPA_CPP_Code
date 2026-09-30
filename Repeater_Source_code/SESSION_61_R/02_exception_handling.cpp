#include <iostream>
#include <exception> 

void server_function(int N);

int main(void)
{
	try 
	{
		std::cout << "Calling server_function() with input data 100" << std::endl;
		server_function(100);	// works 
		std::cout << "Calling server_function() with input data -100" << std::endl;
		server_function(-100);
		std::cout << "Last statement in try block" << std::endl; // control flow will not reach here
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl; 
	}
	
	std::cout << "Client Continuing after handling the exception" << std::endl; 
	std::cout << "Process terminated normally" << std::endl;
	
	return 0;
}

void server_function(int N)
{
	if (N < 0)
	{
		throw std::runtime_error("Negative number is sent");
	}
	else
	{
		std::cout << "Server side opereation on non-negative number will be performed" << std::endl;
	}
} 