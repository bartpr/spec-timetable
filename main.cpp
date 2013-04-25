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
	//odno�nik w�tku
	HANDLE hThread;
	//funkcja wywo�ywana w w�tku
	functionThread wskThreadFunc;
	LPVOID data;

	//metoda wykonuj�ca ��dania
	static DWORD WINAPI process(LPVOID p);

	public:
	
	//Inicjalizacja
	Thread();
	
	//Funkcje dla argument�w
	void setThreadFunction(functionThread func);
	void setData(LPVOID data);
	
	//Dzia�anie
	void run();

};


void czytajCos(LPVOID p)
{
cout << (*((daneWyslane*)p)).a << endl;


}

#pragma argsused
int main(int argc, char* argv[])
{
	//Utworzenie obiektu w�tku
	Thread *t = new Thread();
	
	//Przypisanie funkcji wywo�ywanej w w�tku
	t->setThreadFunction(czytajCos);
	
	//Dodanie struktury z argumentami
	daneWyslane p;
	p.a = 3;
	p.b = 6;
	
	//Ustawienie i utworzenie w�tku
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

