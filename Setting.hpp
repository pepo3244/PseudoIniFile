#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

namespace File {

class Setting {
public:

	Setting( const std::string& aFilename );
	virtual ~Setting(){}

	//	�߂�l�ŃL�[�����݂��邩�킩��܂�
	template< typename T >
	bool get( const std::string& aKey, T* aDst ) const;

	//	�߂�l�Œ��ڎ󂯎��܂�
	//	�L�[�����݂��Ȃ���Η�O����т܂�
	template< typename T >
	T get( const std::string& aKey ) const;

private:

	std::unordered_map< std::string, std::string > mMap;

};

//	���ꉻ���Ă܂�
template<>
bool Setting::get< bool >( const std::string&, bool* ) const;
template<>
bool Setting::get< int >( const std::string&, int* ) const;
template<>
bool Setting::get< double >( const std::string&, double* ) const;

template<>
bool Setting::get< bool >( const std::string& ) const;
template<>
int Setting::get< int >( const std::string& ) const;
template<>
double Setting::get< double >( const std::string& ) const;

}

//	�ȉ��A����
#include "SettingPrivate.hpp"
