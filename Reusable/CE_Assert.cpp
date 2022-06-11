// CE_Assert.cpp


#include "stdio.h"
#include "CE_Assert.h" 
#include <iostream>


namespace Technogym 
{
	namespace Reusable 
	{
		void AssertionViolation( const char* fileName, int lineNum )
		{
			char buf[ 1000 ] ;
			sprintf_s( buf, "Assertion Violation\r\n File: %s\r\n Line: %d", fileName, lineNum ) ;
			// Note: NULL may be changed with a lookup for the topmost window of the program.
			std::cout << buf;
		}
	}
}
