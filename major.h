#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
void game_start_UI()
{
	SetColor(15);
	cout << "*********************************";SetColor(13); cout << "�ϥΫe�`�N�ƶ�"; SetColor(15); cout << "************************************" << endl;
	printf("\n");
	printf("*  1.  W A S D �i�ޱ��D �W �U �� �k                                               *\n");
	printf("*  2.  ��Jspace �Ů���Y�i�Ȱ��C��                                               *\n");
	printf("*  3.  ²��Ҧ��Y�@�ӭ����[�@��                                                   *\n");
	printf("*  4.  ���q�Ҧ��Y�@�ӭ����[���                                                   *\n");
	printf("*  5.  �x���Ҧ��Y�@�ӭ����[�T��                                                   *\n");
	printf("*  6.  �C���w�]���׬����q����,�Y�n�վ����סA��J2!                                *\n");
	printf("*  7.                                                                             *\n");
	printf("*  8.                                                                             *\n");
	printf("*                                                                                 *\n");
	printf("*                                ��J 1 �}�l�C��                                  *\n");
	printf("*                                ��J 2 ���׳]�w                                  *\n");
	printf("*                                ��J 3 �����{��                                  *\n");
	printf("*                                                                                 *\n\n");
	printf("***********************************************************************************\n");
}
void major(int& menu)
{
	srand((unsigned int)time(NULL)); //���í����ͦ����y��
	c.X = 24, c.Y = 12;
	o.X = 22, o.Y = 12;
	snake_body b(c.X, c.Y); //�Y�I /20 
	b.set_body(c);
	f.X = (rand() % 47) + 1, f.Y = (rand() % 23) + 1;
	tmp = 0;
	score = 0;
	key = 'd';
	old_key = 0, new_key = 0;
	while (1)
	{
		display_snake(b);
		Sleep(speed);
		if (_kbhit()) //�P�_�ϧ_���s�������J
		{
			old_key = new_key;
			key = _getch();
			new_key = key;
		}
		if (check_key() == false)  //�s��M����õL�Ĭ� ���ʳD
		{
			if (key == 32)
			{
				key = old_key;
				new_key = key;
				goxy(55, 13);
				cout << "�C���H�Ȱ�!";
				goxy(52, 15);
				system("pause");
				goxy(52, 15);
				cout << "                                ";
				goxy(52, 13);
				cout << "                                ";
			}
			key_way(b);
		}
		else                                       //�s��O���䪺�Ϥ�V �����䭫�]���s�� �÷ӱ`���ʮy��
		{
			key = old_key;
			new_key = key;
			key_way(b);
		}
		if (add_score() == true)
		{
			generate_body(b, o);
		}
		new_pos(b);
		update_data();
		check_food(b);
		if (Collision(b) == true)
		{
			menu = 2;
			break;
		}
		hide_snake(b);
	}
	clear_body(b);
}
