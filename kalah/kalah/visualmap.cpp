#include <iostream>
#include <Windows.h>


void Lfunc(int j,int scal,int r,int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25
			; l++)
		{
			SetPixel(dc, j + scal + l, i, RGB(r, g, b));
		}
		if (i % 3 == 0) {
			j++;
		}
	}
}

void Jfunc(int j, int scal, int r, int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25
			; l++)
		{
			SetPixel(dc, j + scal + l, i, RGB(r,g,b));
		}
		if (i % 3 == 0) {
			j--;
		}
	}

}

void Ifunc(int j, int scal, int r, int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25
			; l++)
		{
			SetPixel(dc, j + scal + l, i, RGB(r,g,b));
		}

	}
}

void Zfunc(int j, int scal, int r, int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);

	for (int i = 40; i < 40 + 20; i++)
	{
		for (int l = j; l < j + 80; l++)
		{
			SetPixel(dc, l + scal, i, RGB(r,g,b));
		}
	}
}

void zfunc(int j, int scal, int r, int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);
	for (int i = 40 + 100; i < 40 + 120; i++)
	{
		for (int l = j; l < j + 80; l++)
		{
			SetPixel(dc, l + scal, i, RGB(r,g,b));
		}
	}
}

void _zfunc(int j, int scal, int r, int g, int b) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd);
	for (int i = 40 + 50; i < 40 + 70; i++)
	{
		for (int l = j; l < j + 80; l++)
		{
			SetPixel(dc, l + scal, i, RGB(r, g, b));
		}
	}
}

void visualmap(int map[10][10]) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания


	//1. Рисуем фон

	brush = CreateSolidBrush(RGB(239, 228, 176)); // Создаём кисть определённого стиля и цвета
	SelectObject(dc, brush); //Выбираем кисть


	RoundRect(dc, 10, 10, 620, 220, 30,30); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти

	brush = CreateSolidBrush(RGB(136, 0, 21));
	SelectObject(dc, brush);
	RoundRect(dc, 23, 37, 544, 100, 30, 30);
	RoundRect(dc, 23, 37, 78, 179, 30, 30);
	for (int i = 0; i < 7; i++) {
			Ellipse(dc, 90+i*65, 40, 145+i*65, 95);
		}
	DeleteObject(brush);

	brush = CreateSolidBrush(RGB(112, 146, 190));
	SelectObject(dc, brush);
	RoundRect(dc, 81,104, 604,176, 30, 30);
	RoundRect(dc, 547,32, 604, 176, 30, 30);
	for (int i = 0; i < 7; i++) {
			Ellipse(dc, 90 + i * 65, 40+70, 145 + i * 65, 95+70);
		}

	MoveToEx(dc, 110, 190, NULL);
	LineTo(dc,110, 200);

	MoveToEx(dc, 110+65*1, 190, NULL);
	LineTo(dc, 110+65*1, 200);
	MoveToEx(dc, 115 + 65 * 1, 190, NULL);
	LineTo(dc, 115 + 65 * 1, 200);

	MoveToEx(dc, 110 + 65 * 2, 190, NULL);
	LineTo(dc, 110 + 65 * 2, 200);
	MoveToEx(dc, 115 + 65 * 2, 190, NULL);
	LineTo(dc, 115 + 65 * 2, 200);
	MoveToEx(dc, 120 + 65 * 2, 190, NULL);
	LineTo(dc, 120 + 65 * 2, 200);

	MoveToEx(dc, 110 + 65 * 3, 190, NULL);
	LineTo(dc, 110 + 65 * 3, 200);
	MoveToEx(dc, 115 + 65 * 3, 190, NULL);
	LineTo(dc, 117 + 65 * 3, 200);
	MoveToEx(dc, 120 + 65 * 3, 190, NULL);
	LineTo(dc, 117 + 65 * 3, 200);

	MoveToEx(dc, 110 + 65 * 4, 190, NULL);
	LineTo(dc, 112 + 65 * 4, 200);
	MoveToEx(dc, 115 + 65 * 4, 190, NULL);
	LineTo(dc, 112 + 65 * 4, 200);

	MoveToEx(dc, 110 + 65 * 5, 190, NULL);
	LineTo(dc, 112 + 65 * 5, 200);
	MoveToEx(dc, 115 + 65 * 5, 190, NULL);
	LineTo(dc, 112 + 65 * 5, 200);
	MoveToEx(dc, 120 + 65 * 5, 190, NULL);
	LineTo(dc, 120 + 65 * 5, 200);

	MoveToEx(dc, 110 + 65 * 6, 190, NULL);
	LineTo(dc, 112 + 65 * 6, 200);
	MoveToEx(dc, 115 + 65 * 6, 190, NULL);
	LineTo(dc, 112 + 65 * 6, 200);
	MoveToEx(dc, 120 + 65 * 6, 190, NULL);
	LineTo(dc, 120 + 65 * 6, 200);
	MoveToEx(dc, 125 + 65 * 6, 190, NULL);
	LineTo(dc, 125 + 65 * 6, 200);

	DeleteObject(brush);

	brush = CreateSolidBrush(RGB(163, 73, 164));
	SelectObject(dc, brush);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			int k = 0;
			int y = 0;
			for (int l = map[i][j]; l > 0; l--) {
				k++;
				if (k == 3) {
					k = 0;
					y++;
				}
				Ellipse(dc, 100 + j * 65 + k * 10, 45 + i * 70 + y * 10, 110 + j * 65 + k * 10, 55 + i * 70 + y * 10);

			}
		}
	}
	int k = 0;
	int y = 0;
	int row = 0;
	for (int l = map[0][7]; l > 0; l--) {
		k++;
		if (k == 3) {
			k = 0;
			y++;
		}
		if (y == 8) {
			row += 5;
			DeleteObject(brush);
			brush = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(dc, brush);
			y = 0;
		}
		Ellipse(dc, 35  + k * 15 + row,    40 + y * 15,      45 + k * 15 + row,     50 + y * 15);

	}
	k = 0;
	y = 0;
	row = 0;
	for (int l = map[1][7]; l > 0; l--) {
		k++;
		if (k == 3) {
			k = 0;
			y++;
		}
		if (y == 8) {
			row += 5;
			DeleteObject(brush);
			brush = CreateSolidBrush(RGB(0,255,255));
			SelectObject(dc, brush);
			y = 0;
		}
		Ellipse(dc, 555 + k * 15 + row,		 40 + y * 15,		565 + k * 15 + row,		 50 + y * 15);

	}

	DeleteObject(brush);



}

void _win(int r, int g, int b, int scal) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну

	int j = 100;
	Lfunc(100, scal, r, g, b);
	Jfunc(190, scal, r, g, b);
	Lfunc(190, scal, r, g, b);
	Jfunc(280, scal, r, g, b);
	j = 320;
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25; l++)
		{
			if (i < 65 || i>75) {
				SetPixel(dc, j + scal + l, i, RGB(r, g, b));
			}
		}
	}//Ileter
	Ifunc(370, scal, r, g, b);
	j = 370;
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25; l++)
		{
			SetPixel(dc, j + scal + l, i, RGB(r, g, b));
		}
		if (i % 2 == 0) {
			j++;
		}
	}
	Ifunc(430, scal, r, g, b);
}

void win() {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну

	_win(237, 28, 36, 0);
	_win(255, 127, 39, 20);

	ReleaseDC(hwnd, dc); 
	std::cin.get();
}

void _lose(int r,int g,int b,int scal) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну

	Ifunc(100, scal, r, g, b);
	zfunc(100, scal, r, g, b);
	Ifunc(200, scal, r, g, b);
	zfunc(200, scal, r, g, b);
	Ifunc(270, scal, r, g, b);
	Zfunc(200, scal, r, g, b);
	Zfunc(310, scal, r, g, b);
	zfunc(310, scal, r, g, b);
	_zfunc(310, scal, r, g, b);
	int j = 310;
	for (int i = 40; i < 40 + 120; i++)
	{
		for (int l = 0; l < 25; l++)
		{
			SetPixel(dc, j + scal + l, i, RGB(r, g, b));
		}
		if (i > 105) {
			j = 365;
		}

	}

	Zfunc(410, scal, r, g, b);
	zfunc(410, scal, r, g, b);
	_zfunc(410, scal, r, g, b);
	Ifunc(410, scal, r, g, b);
}

void lose() {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	_lose(163, 73, 164,0);
	_lose(34,177,76,10);
	ReleaseDC(hwnd, dc);
	std::cin.get();
}