//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <windows.h>

using namespace std;

//---------------------------------------------------------------------------



typedef void ( * functionThread )(LPVOID);

struct ThreadArguments
{
  functionThread func;
  LPVOID data;
};

class Thread
{
HANDLE hThread;
functionThread wskThreadFunc;

//metoda wykonuj¹ca ¿¹dania
static DWORD WINAPI process(LPVOID p);

public:
   Thread();
   void setThreadFunction(functionThread func);

   void run();

};


void czytajCos(LPVOID p)
{
 cout << *((string*)p) << endl;
}

#pragma argsused
int main(int argc, char* argv[])
{
   Thread *t = new Thread();
   functionThread fr = czytajCos;
   t->setThreadFunction(czytajCos);
   t->run();
   delete t;
   getchar();
   return 0;
}
//---------------------------------------------------------------------------




Thread::Thread()
{
   hThread = NULL;
}


void Thread::run()
{
  ThreadArguments *args = new ThreadArguments();
  string str = "xdd";
  args->func = this->wskThreadFunc;
  args->data = (LPVOID*)&str;
  hThread = CreateThread(NULL, 0, process, (LPVOID)args, 0, NULL);
}

DWORD WINAPI Thread::process(LPVOID p)
{
     ThreadArguments *args = (ThreadArguments*)p;
     functionThread c = args->func;
     string str = *((string*)args->data);
     c( args->data);
}

void Thread::setThreadFunction(functionThread func)
{
  this->wskThreadFunc = func;
}
