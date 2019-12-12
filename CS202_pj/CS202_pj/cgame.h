﻿#pragma once
#include"Library.h"
class CGame {
	Truck* axt;
	Car* axh;
	Dinosaur* akl;
	Bird* ac;
	CPEOPLE cn;
	int map[85][24];
	bool mode;	//0: easy, 1: hard
	//Level clevel;
public:
	CGame(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGame(); // Hủy tài nguyên đã cấp phát
	CPEOPLE getPeople();//Lấy thông tin người
	Enemy* getVehicle();//Lấy danh sách các xe
	//CANIMAL* getAnimal(); //Lấy danh sách các thú
	void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(ofstream &fout); // Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho Truck & Car di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBird di chuyển
	void menu();
	void setting();
	//For arrayTesting
	bool exportMap(const char* a);
	Point peoplePos();
	static mutex mtx;
};
