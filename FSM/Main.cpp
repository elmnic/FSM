#include <Windows.h>
#include <random>
#include "Wolf.h"
int main()
{
	srand(NULL);

	Wolf wolf;
	
	for (int i = 0; i < 100; i++)
	{
		wolf.update();
		Sleep(800);
	}

	system("Pause");
	return 0;
}