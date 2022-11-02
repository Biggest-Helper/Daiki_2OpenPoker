#include "DxLib.h"
#include "Card.h"

int Card::LoadImages()
{
	if (LoadDivGraph("../images/Card_Sozai_3.png", 52, 13, 5, 49, 75, LoadCard) == -1)return -1;
	if (joker = LoadGraph("../images/Joker.png") == -1)return -1;
	if (card_back = LoadGraph("../images/Back_Card.png") == -1)return -1;

	return 0;
}

int Card::CardDistribution()
{
	int x = rand() % 54;
	if(x > 52)
	{
		return joker;
	}
	return LoadCard[x];
}

//ジョーカーを返す
int Card::GetJoker()
{
	return joker;
}

int Card::GetBack()
{
	return card_back;
}

//スペードのカードを返す
int Card::s_1()
{
	return LoadCard[0];
}
int Card::s_2()
{
	return LoadCard[12];
}
int Card::s_3()
{
	return LoadCard[11];
}
int Card::s_4()
{
	return LoadCard[10];
}
int Card::s_5()
{
	return LoadCard[9];
}
int Card::s_6()
{
	return LoadCard[8];
}
int Card::s_7()
{
	return LoadCard[7];
}
int Card::s_8()
{
	return LoadCard[6];
}
int Card::s_9()
{
	return LoadCard[5];
}
int Card::s_10()
{
	return LoadCard[4];
}
int Card::s_11()
{
	return LoadCard[3];
}
int Card::s_12()
{
	return LoadCard[2];
}
int Card::s_13()
{
	return LoadCard[1];
}

//ハートのカードを返す
int Card::h_1()
{
	return LoadCard[13];
}
int Card::h_2()
{
	return LoadCard[25];
}
int Card::h_3()
{
	return LoadCard[24];
}
int Card::h_4()
{
	return LoadCard[23];
}
int Card::h_5()
{
	return LoadCard[22];
}
int Card::h_6()
{
	return LoadCard[21];
}
int Card::h_7()
{
	return LoadCard[20];
}
int Card::h_8()
{
	return LoadCard[19];
}
int Card::h_9()
{
	return LoadCard[18];
}
int Card::h_10()
{
	return LoadCard[17];
}
int Card::h_11()
{
	return LoadCard[16];
}
int Card::h_12()
{
	return LoadCard[15];
}
int Card::h_13()
{
	return LoadCard[14];
}

//クラブのカード描画処理
int Card::c_1()
{
	return LoadCard[26];
}
int Card::c_2()
{
	return LoadCard[38];
}
int Card::c_3()
{
	return LoadCard[37];
}
int Card::c_4()
{
	return LoadCard[36];
}
int Card::c_5()
{
	return LoadCard[35];
}
int Card::c_6()
{
	return LoadCard[34];
}
int Card::c_7()
{
	return LoadCard[33];
}
int Card::c_8()
{
	return LoadCard[32];
}
int Card::c_9()
{
	return LoadCard[31];
}
int Card::c_10()
{
	return LoadCard[30];
}
int Card::c_11()
{
	return LoadCard[29];
}
int Card::c_12()
{
	return LoadCard[28];
}
int Card::c_13()
{
	return LoadCard[27];
}

//ダイヤのカードを返す
int Card::d_1()
{
	return LoadCard[39];
}
int Card::d_2()
{
	return LoadCard[51];
}
int Card::d_3()
{
	return LoadCard[50];
}
int Card::d_4()
{
	return LoadCard[49];
}
int Card::d_5()
{
	return LoadCard[48];
}
int Card::d_6()
{
	return LoadCard[47];
}
int Card::d_7()
{
	return LoadCard[46];
}
int Card::d_8()
{
	return LoadCard[45];
}
int Card::d_9()
{
	return LoadCard[44];
}
int Card::d_10()
{
	return LoadCard[43];
}
int Card::d_11()
{
	return LoadCard[42];
}
int Card::d_12()
{
	return LoadCard[41];
}
int Card::d_13()
{
	return LoadCard[40];
}