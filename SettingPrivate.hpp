#pragma once

namespace File {

template< typename T >
bool Setting::get( const std::string& aKey, T* aDst ) const
{
	auto itr = mMap.find( aKey );

	if( itr == mMap.end() ){
		return false;
	}

	*aDst = itr->second;

	return true;
}

template< typename T >
T Setting::get( const std::string& aKey ) const
{
	return mMap.at( aKey );
}

}//namespace File
