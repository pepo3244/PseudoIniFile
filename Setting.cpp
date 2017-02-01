#include <cassert>
#include <fstream>
#include <sstream>

#include "Setting.hpp"

namespace File {

Setting::Setting( const std::string& aFilename )
{
	std::ifstream ifs( aFilename );

	assert( ifs && "setting file does not exist" );

	//	��s���ǂ�ł���
	while( !ifs.eof() ){

		//	��s�擾
		std::string line;
		std::getline( ifs, line );

		//	= �ŋ�؂邽�߂ɂ������� istringstream ��
		std::istringstream iss( line );

		//	= �̍����擾
		std::string key;
		std::getline( iss, key, '=' );

		std::istringstream( key ) >> key;//�������邱�ƂŖ��ʂȃX�y�[�X������

		//	= �̉E���擾
		std::string value;
		std::getline( iss, value, '=' );

		std::istringstream( value ) >> value;//�������邱�ƂŖ��ʂȃX�y�[�X������

		mMap[ key ] = value;
	}
}

//	�ȉ��A���ꉻ
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
