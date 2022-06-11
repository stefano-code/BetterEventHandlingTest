// CE_Assert.h
#ifndef CE_ASSERT_
#define CE_ASSERT_

namespace Technogym
{
	namespace Reusable
	{
	void AssertionViolation( const char* fileName, int lineNum ) ;
	}
}




#ifdef RELEASE_MODE_
	#define CE_ASSERT( cond ) 0 
#else
	#define CE_ASSERT( cond ) if( !(cond) ) { Technogym::Reusable::AssertionViolation( TEXT(__FILE__), __LINE__ ) ; }
#endif

#endif