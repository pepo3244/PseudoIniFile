#include <cassert>
#include <fstream>
#include <sstream>

#include "Setting.hpp"

namespace File {

Setting::Setting( const std::string& aFilename )
{
	std::ifstream ifs( aFilename );

	assert( ifs && "setting file does not exist" );

	//	一行ずつ読んでいく
	while( !ifs.eof() ){

		//	一行取得
		std::string line;
		std::getline( ifs, line );

		//	= で区切るためにいったん istringstream へ
		std::istringstream iss( line );

		//	= の左を取得
		std::string key;
		std::getline( iss, key, '=' );

		std::istringstream( key ) >> key;//こうすることで無駄なスペースが減る

		//	= の右を取得
		std::string value;
		std::getline( iss, value, '=' );

		std::istringstream( value ) >> value;//こうすることで無駄なスペースが減る

		mMap[ key ] = value;
	}
}

//	以下、特殊化
template<>
bool Setting::get< int >( const std::string& aKey, int* aDst ) const
{
	auto itr = mMap.find( aKey );

	if( itr == mMap.end() ){
		return false;
	}

	*aDst = std::stoi( itr->second );

	return true;
}

template<>
bool Setting::get< bool >( const std::string& aKey, bool* aDst ) const
{
	auto itr = mMap.find( aKey );

	if( itr == mMap.end() ){
		return false;
	}

	std::istringstream( itr->second ) >> std::boolalpha >> *aDst;

	return true;
}

template<>
bool Setting::get< double >( const std::string& aKey, double* aDst ) const
{
	auto itr = mMap.find( aKey );

	if( itr == mMap.end() ){
		return false;
	}

	*aDst = std::stod( itr->second );

	return true;
}

template<>
bool Setting::get< bool >( const std::string& aKey ) const
{
	bool value;
	std::istringstream( mMap.at( aKey ) ) >> std::boolalpha >> value;
	return value;
}

template<>
int Setting::get< int >( const std::string& aKey ) const
{
	return std::stoi( mMap.at( aKey ) );
}

template<>
double Setting::get< double >( const std::string& aKey ) const
{
	return std::stod( mMap.at( aKey ) );
}

}//namespace File
