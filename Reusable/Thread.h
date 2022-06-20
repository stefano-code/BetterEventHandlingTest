#ifndef THREAD_

#define THREAD_
#include <Windows.h>

namespace Reusable
{
	class Thread
	{
	private:
		static DWORD WINAPI ThreadBoot(LPVOID);
		HANDLE hThread;
	protected:
		virtual void Main(void);
	public:
		Thread();
		~Thread();
		virtual DWORD Run(void);
	//##	virtual DWORD Kill(void);
		bool WaitForTermination( int timeout ) ;
	};
}

#endif