#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
COORD c, o, f, clear; //current �y��  old �y�� food �y��
int tmp = 0;
char key = 'd';  //�D�@�}�l�ܷ|���k��
int speed = 250;//�D�����t��
int total_speed;
int judge = 3; //�t�׮t
int score_judge = 2;//���Ʈt
int score = 0;
int restart_food_time=30;
char old_key = 0, new_key = 0; //�s�«���
#include "snake_body.h"
#include "game.h"
#include "major.h"
#include "Difficulty.h"
int main()
{
	system("mode con cols=85 lines=30");
	system("title �g�Y�Dv1.1        created by Majitoo");
	system("color 2");
	int menu, input_dif = 2;
	while (1)
	{
		system("cls");
		game_start_UI();
		goxy(30, 18);
		cout << "�п�J�A�Q�n���檺�\��:";
		goxy(42, 20);
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			show_UI(input_dif);
			reload_difficult(input_dif);
			score = 0;
			major(menu);
			goxy(20, 12);
			cout<<"�C������!";
			goxy(20, 14);
			system("pause");
			goxy(20, 12);
			cout << "                         ";
			goxy(20, 14);
			system("                          ");
			goxy(20, 12);
			cout << "�z�����Ƭ�:" << score << endl;
			goxy(20, 14);
			system("pause");
			system("cls");
			break;
		case 2:
			difficulty(input_dif, speed);
			break;
		case 3:
			exit(0);
		default:
			game_start_UI();
			goxy(20, 18);
			cout << "��J���~! �Э��s��J!";
			system("pause");
		}
	}
}
