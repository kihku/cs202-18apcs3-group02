#pragma once
#include"Library.h"
int CTRAFFIC::numTraffic = 0;
int CCAR::numCar = 0;
void CDINAUSOR::Move(int x, int y)
{
	const int height = 3;
	const int width = 4;
	for (int i = y; i < y + height; ++i)
	{
		for (int j = x; j < x + width; ++j)
		{
			if (i == y && j == x + 3 || i == y && j == x + 2)
			{
				continue;
			}
			gotoxy(j, i);
			cout << char(219);
			if (i == y + height - 1 && j == x + width - 1)
			{
				for (int k = 0; k < width / 4; ++k) //lam tron len xuong?
				{
					gotoxy(j + 1, i);
					cout << char(219);
				}
			}
		}
		x -= 2;
	}
	for (int j = x - width; j < x; ++j)
	{
		gotoxy(j, y);
		cout << "      ";
		gotoxy(j, y + 1);
		cout << "    ";
		gotoxy(j, y + 2);
		cout << "  ";
	}
}

void CCAR::Move()
{
	int l = 4, r = 85, bk=4;
	if (dir) {
		//di lo khung thi di lai
		if (r <= pos.x+bk+1) {
			gotoxy(pos.x - bk, pos.y - 1);
			cout << "         ";
			gotoxy(pos.x - bk, pos.y);
			cout << "         ";
			gotoxy(pos.x - bk, pos.y + 1);
			cout << "         ";
			pos.x = l+bk, drawVeh();
		}
		else {
			gotoxy(pos.x - bk, pos.y - 1);
			cout << " ";
			gotoxy(pos.x - bk, pos.y);
			cout << " ";
			gotoxy(pos.x - bk, pos.y + 1);
			cout << " ";
			++pos.x, drawVeh();
		}
	}
	else {
		//di lo khung thi di lai
		if (pos.x-bk-1 <= l) {
			gotoxy(pos.x-bk, pos.y - 1);
			cout << "         ";
			gotoxy(pos.x-bk, pos.y);
			cout << "         ";
			gotoxy(pos.x-bk, pos.y + 1);
			cout << "         ";
			pos.x = r-bk, drawVeh();
		}
		else {
			gotoxy(pos.x + bk, pos.y - 1);
			cout << " ";
			gotoxy(pos.x + bk, pos.y);
			cout << " ";
			gotoxy(pos.x + bk, pos.y + 1);
			cout << " ";
			--pos.x, drawVeh();
		}
	}
}
void CCAR::pause()
{
	drawVeh();
}
void CTRUCK::Move(int x, int y)
{
	//for (int i = 5; i < 100; ++i)
	//{
	//	truck.Move(i, 10);
	//	Sleep(200);
	//}
}

void CTRUCK::pause()
{
	drawVeh();
}