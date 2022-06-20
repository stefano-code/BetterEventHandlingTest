// CheckedCast.h

#ifndef CHECKEDCAST_

#define CHECKEDCAST_

#include "CE_Assert.h"

namespace Reusable
{
#ifdef RELEASE_MODE_
	template< class T2, class T1 > T2 checked_cast( const T1 t ) 
	{
		return( static_cast< T2 >( t ) ) ;
	}
#else
	template< class T2, class T1 > T2 checked_cast( const T1 t ) 
	{
		T2 staticRes = static_cast< T2 >( t ) ;
		/* ## RTTI not enabled on Windows CE ??
		T2 dynamicRes = dynamic_cast< T2 >( t ) ;
		CE_ASSERT( staticRes == dynamicRes ) ; // if different, the type of t is NOT T2.
		*/
		return( staticRes ) ;
	}
#endif
}

#endif

