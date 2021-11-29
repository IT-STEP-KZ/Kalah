#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "minimaxfunc.cpp"
#include "visualmap.cpp"

bool visualisation = false;

int doturn(int(&map)[10][10], int turn, int , int cd) {
	int Turn = 0;
	bool side = true;

	if (turn == 1) {
		Turn = 0;
		side = false;
	}
	else if (turn == -1) {
		Turn = 1;
		side = true;
	}
	int j1 = map[Turn][cd];
	map[Turn][cd] = 0;
	if (j1 > 0) {
		for (int i = j1; i > 0; i--) {
			if (side == false) {
				cd--;
			}
			if (side == true) {
				cd++;
			}

			if (cd == 7) {
				side = false;
				Turn = 0;
				cd--;
				if (turn == -1) {
					map[1][7]++;
					i--;
				}
			}
			if (cd == -1) {
				side = true;
				Turn = 1;
				cd++;
				if (turn == 1) {
					map[0][7]++;
					i--;
				}
			}

			if (i == 0) {
				break;
			}

			map[Turn][cd]++;
			if (visualisation == true) {
				visualmap(map);
				Sleep(100);
			}
			
			
		}
		if (map[Turn][cd] == 1) {
			if (Turn == 0 && turn == 1) {
				map[Turn][7] += map[1][cd];
				map[1][cd] = 0;
			}
			if (Turn == 1 && turn == -1) {
				map[Turn][7] += map[0][cd];
				map[0][cd] = 0;
			}
		}
		if (turn == -1) {
			return map[1][7];
		}
		if (turn == 1) {
			return map[0][7];
		}
	}
	else {
		return -1;
	}
}

int winCheck(int map[10][10]) {
	int sum = 0;
	int sum1 = 0;
	
	for (int i = 0; i < 7; i++) {
		sum += map[0][i];
	}
	for (int i = 0; i < 7; i++) {
		sum1 += map[1][i];
	}
	if (sum == 0||sum1==0) {
		for (int i = 0; i < 7; i++) {
			map[0][7] += map[0][i];
		}
		for (int i = 0; i < 7; i++) {
			map[1][7] += map[1][i];
		}
		
		if (map[1][7] > map[0][7]) {
			return -100;
		}
		else if (map[1][7] < map[0][7]) {
			return 100;
		}
		else {
			
			return 0;
		}
	}
	return 0;
}

int getCd() {
	char _cd = _getch();
	switch (_cd)
	{
	case '1':
		return 0;
		break;
	case '2':
		return 1;
		break;
	case '3':
		return 2;
		break;
	case '4':
		return 3;
		break;
	case '5':
		return 4;
		break;
	case '6':
		return 5;
		break;
	case '7':
		return 6;
		break;
	default:
		return 1;
		break;
	}
}

int main(int argc, char** argv) {

	SetConsoleTitle(L"KaLaH");
	system("mode con cols=57 lines=10");

	int num=4;
	int map[10][10] = { {num,num,num,num,num,num,num,0},{num,num,num,num,num,num,num,0} };
	int turn = -1;
	visualmap(map);
	while(winCheck(map) == 0) {
		int cd;
		
		if (turn == -1) {
			
			cd = getCd();
		}
		else {
			cd=(nextt(map, 1, 8, turn, 1, winCheck, doturn)-1)/10-1;
		}

		visualisation = true;
		doturn(map, turn, NULL, cd);
		visualisation = false;
		visualmap(map);
		turn *= -1;
	}
	if (winCheck(map) < 0) {
		win();
	}
	else if (winCheck(map) > 0) {
		lose();
	}
	visualmap(map);
	

	return 0;
}