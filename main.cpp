#include <iostream>
#include <string>
//using namespace std;

#include "Setting.hpp"

int main()
{
	File::Setting setting( "setting.txt" );

	std::string str;
	setting.get< std::string >( "test", &str );

	int i;
	setting.get< int >( "int", &i );

	double d;
	setting.get< double >( "double", &d );

	bool b;
	setting.get< bool >( "bool", &b );

	std::cout << str << std::endl;
	std::cout << i << std::endl;
	std::cout << d << std::endl;
	std::cout << std::boolalpha << b << std::endl;

	std::cout << setting.get< std::string >( "test" ) << std::endl;
	std::cout << setting.get< int >( "int" ) << std::endl;
	std::cout << setting.get< double >( "double" ) << std::endl;
	std::cout << setting.get< bool >( "bool" ) << std::endl;

	return 0;
}
