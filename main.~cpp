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
  string data;
};

class Thread
{
HANDLE hThread;
//funkcja wywo³ywana w w¹tku
functionThread wskThreadFunc;
LPVOID data;

//metoda wykonuj¹ca ¿¹dania
static DWORD WINAPI process(LPVOID p);

public:
   Thread();
   void setThreadFunction(functionThread func);
   void setData(LPVOID data);
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
  hThread = CreateThread(NULL, 0, process, (LPVOID)&data, 0, NULL);
}

DWORD WINAPI Thread::process(LPVOID p)
{
     ThreadArguments *args = (ThreadArguments*)p;
     functionThread c = args->func;
     string str = args->data;
     c( (LPVOID)&args->data);
}

void Thread::setThreadFunction(functionThread func)
{
  this->wskThreadFunc = func;
}

void Thread::setData(LPVOID data)
{
  this->data = data;
}

