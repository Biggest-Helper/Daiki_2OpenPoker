#pragma once
class Card
{
private:
	int LoadCard[54];
	int joker;
	int card_back;

public:
	int LoadImages();
	int GetJoker();
	int GetBack();

	int Card_RanNum();              //カード配布関数(乱数)
	int CardDistribution(int num);  //カード配布関数

	//スペードのカード
	int s_1();
	int s_2();
	int s_3();
	int s_4();
	int s_5();
	int s_6();
	int s_7();
	int s_8();
	int s_9();
	int s_10();
	int s_11();
	int s_12();
	int s_13();
	//ハートのカード
	int h_1();
	int h_2();
	int h_3();
	int h_4();
	int h_5();
	int h_6();
	int h_7();
	int h_8();
	int h_9();
	int h_10();
	int h_11();
	int h_12();
	int h_13();
	//クラブのカード
	int c_1();
	int c_2();
	int c_3();
	int c_4();
	int c_5();
	int c_6();
	int c_7();
	int c_8();
	int c_9();
	int c_10();
	int c_11();
	int c_12();
	int c_13();
	//ダイヤのカード
	int d_1();
	int d_2();
	int d_3();
	int d_4();
	int d_5();
	int d_6();
	int d_7();
	int d_8();
	int d_9();
	int d_10();
	int d_11();
	int d_12();
	int d_13();
};