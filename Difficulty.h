#include <iostream>
void reload_difficult(int& input_dif);
void test();
void difficulty(int& input_dif, int& speed)
{
restart:
	system("CLS");
	difficuly_UI();
	goxy(38, 5);
	cout << "1.²��Ҧ�";
	goxy(38, 10);
	cout << "2.���q�Ҧ�";
	goxy(38, 15);
	cout << "3.�x���Ҧ�";
	goxy(35, 25);
	cout << "�п�J�A�n�o����:";
	cin >> input_dif;
	reload_difficult(input_dif);
	if (input_dif != 1 && input_dif != 2 && input_dif != 3)
	{
		goxy(30, 25);
		cout << "                                            ";
		goxy(30, 25);
		cout << "�S�����ﶵ�A�ЦA���s��J�@��!" << endl;
		goxy(30, 26);
		system("pause");
		goto restart;
	}
		
}
void reload_difficult(int& input_dif) //���׼ƾڰ�
{
	switch (input_dif)
	{
	case 1:
		total_speed = 400;
		speed = 400;
		judge = 2;
		score_judge = 1;
		restart_food_time = 30;
		break;
	case 2:
		total_speed = 250;
		speed = 250;
		judge = 3;
		score_judge = 2;
		restart_food_time = 30;
		break;
	case 3:
		total_speed = 150;
		speed = 150;
		judge = 5;
		score_judge = 3;
		restart_food_time = 50;
		break;
	}
}