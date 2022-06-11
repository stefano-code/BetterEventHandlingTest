// Invoker.h

#ifndef INVOKER_

#define INVOKER_


namespace Technogym
{
	namespace EventHandling
	{
  class Event ;

  class Invoker
    {
    public : 
    virtual ~Invoker() {} ;
    virtual void InvokeHandler( const Event* e ) const = 0 ;
    } ;

  template< class T1, class T2 >
  class TypeSafeInvoker : public Invoker
    {
    public :
      typedef void (T1::*HandlingFunction)( const T2* ) ;
      TypeSafeInvoker( T1* theSink, HandlingFunction theHandler )
        {
        sink = theSink ;
        f = theHandler ;
        }
      virtual void InvokeHandler( const Event* e ) const
        {
        const T2* e2 = Reusable::checked_cast< const T2* >( e ) ;
        (sink->*f)( e2 ) ;
        }
    private :
      T1* sink ;
      HandlingFunction f ;
    } ;
  }
}

#endif
