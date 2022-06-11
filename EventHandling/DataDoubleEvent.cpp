#include "stdafx.h"
#include "DataDoubleEvent.h"

using namespace Technogym::EventHandling ;

DataDoubleEvent :: DataDoubleEvent( Tag t,double v ) :
Event(t)
{
	val = v ;
}

double DataDoubleEvent :: GetValue() const
{
	return( val ) ;
}


Event* DataDoubleEvent :: Clone() const
{
	DataDoubleEvent* clone = new DataDoubleEvent( *this ) ;
	return( clone ) ;
}

std::string DataDoubleEvent :: SerializeOut() const
{
	std::string result ;
	char buf[ 10 ] ;
	sprintf( buf, "%f", val ) ;
	result += buf ;
	return result ;
}