// EventHandling_Test.cpp

#pragma warning( disable: 4786 )

#include <windows.h>
#include <iostream>
#include <memory>
#include "..\..\..\..\Reusable\thread.h"
#include ".\EventHandling\EventSource.h"
#include ".\EventHandling\EventSink.h"
#include ".\EventHandling\SimpleEvent.h"


using namespace std ;
using namespace Technogym::EventHandling ;
using namespace Technogym::Reusable ;

EventSource gui ;
Tag tag10 = 10 ;
Tag tag20 = 20 ;
Tag tag30 = 30 ;

class ExtendedEvent30 : public SimpleEvent
  {
  public :
    ExtendedEvent30() : SimpleEvent( tag30 )
      {
		cout << "ExtendedEvent30 costruttore";
      }
	~ExtendedEvent30()
	{
		cout << "ExtendedEvent30 distruttore";
	}
    virtual Event* Clone() const { return new ExtendedEvent30( *this ) ; }
    int test_x;
  } ;


class TrainingProgram : public EventSink, public Thread
{
public :
	TrainingProgram()
	{
       SubscribeEvent( gui, tag10, &TrainingProgram::Event10Handler ) ;
	}


  void Event10Handler( const Event* e )
    {
		cout << "evento con tag " << e->GetTag() << " ricevuto in TrainingProgram::Event10Handler\n" ;
		static int count = 0 ;
  	++count ;
		if( count == 2 )
       SubscribeEvent( gui, tag30, &TrainingProgram::Event30Handler ) ;
		}

  void Event30Handler( const ExtendedEvent30* e )
    {
		cout << "evento con tag " << e->GetTag() << " ricevuto in TrainingProgram::Event30Handler (" ;
		cout << "test_x = " << e->test_x << ")\n" ;
    }

	virtual void Main()
	{
		while( true )
		{
			Sleep( 500 ) ;
      HandleFirstEvent() ;
		}
	}
} ;


class VirtualTrainer : public EventSink, public Thread
{
public :
	VirtualTrainer()
	{
        gui.Subscribe( tag10, this ) ;
		gui.Subscribe( tag20, this ) ;
	}

	virtual void Main()
	{

		while( true )
		{
			Sleep( 500 ) ;
			auto_ptr< Event > e( GetEvent() ) ;
			if( e.get() != NULL )
			{
				cout << "evento con tag " << e->GetTag() << " ricevuto in VirtualTrainer\n" ;
			}
		}
	}
} ;


#include <iostream>


int main()
  {
	std::cout << "Hello World!\n";
  TrainingProgram t ;
  VirtualTrainer o ;
  t.Run() ;
  o.Run() ;

  SimpleEvent e10( tag10 );

  SimpleEvent e20( tag20 ) ;

  ExtendedEvent30 e30 ;
  e30.test_x = 42 ;

  gui.Dispatch( e10 ) ;  // TP, OT
  gui.Dispatch( e20 ) ;  // OT
  gui.Dispatch( e30 ) ;  // NONE

  gui.Dispatch( e10 ) ;  // TP, OT, + causa sottoscrizione di e30 da parte di TrainingProgram

  Sleep( 2000 ) ;

  cout << "----------------\n" ;
  gui.Dispatch( e30 ) ;  // TP

  Sleep( 2000 ) ;

  return 0 ;
  }