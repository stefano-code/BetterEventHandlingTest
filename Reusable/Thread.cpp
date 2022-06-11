//SSSSSSSS #include <windows.h>
//SS #include "stdafx.h"
#include "Thread.h"


using namespace Technogym::Reusable ;



Thread::Thread()
{
	hThread = 0 ;
}


Thread::~Thread()
{
	if( hThread )
		CloseHandle(hThread);
}

void Thread::Main(void){}

DWORD WINAPI Thread::ThreadBoot(LPVOID lpdwParam)
{
	Thread* that=(Thread*) lpdwParam;
    that->Main();
	return 0;
}

DWORD Thread::Run(void)
{
	DWORD dwThreadID;

	hThread=CreateThread(NULL,0,ThreadBoot,this,0,&dwThreadID);
	SetThreadPriority(hThread,THREAD_PRIORITY_NORMAL);

	return dwThreadID;
}

/*
DWORD Thread::Kill(void)
{
	DWORD dwExitCode;

	//## set event+flag, wait su handle thread con timeout, eventuale terminatethread
	GetExitCodeThread(hThread,&dwExitCode);
	CloseHandle(hThread);
	hThread = 0 ;

	return dwExitCode;
}
*/


bool Thread::WaitForTermination( int timeout )
{
	DWORD res = WaitForSingleObject( hThread, timeout ) ;
	return( res == WAIT_OBJECT_0 ) ;
}