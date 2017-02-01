#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

namespace File {

class Setting {
public:

	Setting( const std::string& aFilename );
	virtual ~Setting(){}

	//	戻り値でキーが存在するかわかります
	template< typename T >
	bool get( const std::string& aKey, T* aDst ) const;

	//	戻り値で直接受け取ります
	//	キーが存在しなければ例外が飛びます
	template< typename T >
	T get( const std::string& aKey ) const;

private:

	std::unordered_map< std::string, std::string > mMap;

};

//	特殊化してます
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

//	以下、実装
#include "SettingPrivate.hpp"
