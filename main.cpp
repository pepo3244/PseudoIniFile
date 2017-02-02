#include <iostream>
#include <string>
using namespace std;

#include "Setting.hpp"

int main()
{
	File::Setting setting( "setting.txt" );

	string str;
	setting.get( "test", &str );

	int i;
	setting.get( "int", &i );

	double d;
	setting.get( "double", &d );

	bool b;
	setting.get( "bool", &b );
	
	cout << str << endl;
	cout << i << endl;
	cout << d << endl;
	cout << boolalpha << b << endl;

	cout << setting.get< string >( "test" ) << endl;
	cout << setting.get< int >( "int" ) << endl;
	cout << setting.get< double >( "double" ) << endl;
	cout << setting.get< bool >( "bool" ) << endl;

	return 0;
}
