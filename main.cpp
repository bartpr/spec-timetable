//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <windows.h>

using namespace std;

//---------------------------------------------------------------------------



typedef void ( * functionThread )(LPVOID);

struct daneWyslane
{
	int a;
	int b;
};

struct ThreadArguments
{
	functionThread func;
	LPVOID data;
};

class Thread
{
	//odnoœnik w¹tku
	HANDLE hThread;
	//funkcja wywo³ywana w w¹tku
	functionThread wskThreadFunc;
	LPVOID data;

	//metoda wykonuj¹ca ¿¹dania
	static DWORD WINAPI process(LPVOID p);

	public:
	
	//Inicjalizacja
	Thread();
	
	//Funkcje dla argumentów
	void setThreadFunction(functionThread func);
	void setData(LPVOID data);
	
	//Dzia³anie
	void run();

};


void czytajCos(LPVOID p)
{
cout << (*((daneWyslane*)p)).a << endl;


}

#pragma argsused
int main(int argc, char* argv[])
{
	//Utworzenie obiektu w¹tku
	Thread *t = new Thread();
	
	//Przypisanie funkcji wywo³ywanej w w¹tku
	t->setThreadFunction(czytajCos);
	
	//Dodanie struktury z argumentami
	daneWyslane p;
	p.a = 3;
	p.b = 6;
	
	//Ustawienie i utworzenie w¹tku
	t->setData((LPVOID)&p);
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
ThreadArguments *args = new ThreadArguments;
args->func = this->wskThreadFunc;
args->data = this->data;
hThread = CreateThread(NULL, 0, process, (LPVOID)args, 0, NULL);

}

DWORD WINAPI Thread::process(LPVOID p)
{
ThreadArguments *args = (ThreadArguments*)p;
functionThread c = args->func;
c(args->data);
}

void Thread::setThreadFunction(functionThread func)
{
this->wskThreadFunc = func;
}

void Thread::setData(LPVOID data)
{
this->data = data;
}

