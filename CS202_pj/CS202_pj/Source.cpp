#include"Library.h"
//start x,y CDINAUSOR is (4,3)
//for testing purpose
void vehicleMove()
{
	VEHLANE l(5);
	l.updatePosVehicle();
}
int main()
{
	ShowConsoleCursor(false);
	char keyPressed;
	bool pause_game = false;
	CGAME game;
	game.drawGame();
	thread th1(vehicleMove);
	HANDLE th1_handle= th1.native_handle();
	while (1)
	{
		keyPressed = _getch();
		if (keyPressed == 0)
			keyPressed = _getch();
		if (keyPressed == 13 && pause_game == false)
		{
			game.pauseGame(th1_handle);
			pause_game = true;
		}
		else if (keyPressed == 13 && pause_game == true)
		{
			game.resumeGame(th1_handle);
			pause_game = false;
		}
		if (pause_game == false)
			game.updatePosPeople(keyPressed);
	}
	if (th1.joinable())
		th1.join();
	return 0;
}