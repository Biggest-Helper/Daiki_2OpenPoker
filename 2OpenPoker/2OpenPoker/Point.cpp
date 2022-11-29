#include "DxLib.h"
#include "Point.h"

void Point::DrawHavePoints()
{
	SetFontSize(15);

	if (Phese == 0)
	{
		Anty();
		Phese = 1;
	}
	
	if (Phese == 1)
	{
		CPU_Bet();
		Phese = 2;
	}

	if (Phese == 2)
	{
		Player_Bet();
		Phese = 3;
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			DrawBox(900, 580, 1050, 630, GetColor(255, 255, 255), TRUE);
			DrawString(933, 587, "プレイヤー", GetColor(0, 0, 0));
			DrawString(910, 605, "所持pt :", GetColor(0, 0, 0));
			DrawFormatString(990, 605, GetColor(0, 0, 0), "%dpt", player_pt);
		}
		else
		{
			DrawBox(cpu_pt_posX[i], cpu_pt_posY[i], cpu_pt_posX[i] + 150, cpu_pt_posY[i] + 50, 
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 60, cpu_pt_posY[i] + 7, "CPU", GetColor(0, 0, 0));
			DrawString(cpu_pt_posX[i] + 10, cpu_pt_posY[i] + 25, "所持pt :", GetColor(0, 0, 0));
			DrawFormatString(cpu_pt_posX[i] + 90, cpu_pt_posY[i] + 25, GetColor(0, 0, 0), "%dpt", cpu_pt[i]);
		}
	}
}

void Point::DrawSumBetPoints()
{
	DrawCircle(640, 360, 45, GetColor(255, 255, 255), TRUE);
	SetFontSize(12);
	DrawString(610, 345, "ベット合計", GetColor(0, 0, 0));
	SetFontSize(14);
	DrawFormatString(627, 365, GetColor(0, 0, 0), "%d", sum_bet);
}

void Point::Anty()
{
	for (int i = 0; i < 3; i++)
	{
		cpu_pt[i] -= anty;
		sum_bet += anty;
	}
	player_pt -= anty;
	sum_bet += anty;

}

void Point::CPU_Bet()
{
	for (int i = 0; i < 3; i++)
	{
		cpu_pt[i] -= bet[0];
		sum_bet += bet[0];
		/*if (i == 0)
		{
			DrawBox(cpu_pt_posX[i] + 50, cpu_pt_posY[i] + 85, cpu_pt_posX[i] + 100, cpu_pt_posY[i] + 115,
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 50, cpu_pt_posY[i] + 90, "ベット", GetColor(0, 0, 0));
		}*/

	}
}

void Point::Player_Bet()
{
	if (bet_selectFlg == 0)
	{
		player_pt -= bet[0] * 2;
		sum_bet += bet[0] * 2;
	
	}
	else if (bet_selectFlg == 1)
	{
		player_pt -= bet[0];
		sum_bet += bet[0];
	
	}
	else if (bet_selectFlg == 2)
	{

	}
}

void Point::BetSelectFlg(int selectNum)
{
	if (selectNum == 0)
	{
		bet_selectFlg = 0;
		Phese = 3;
	}
}

int Point::GetPlayerPt()
{
	return player_pt;
}

int Point::GetCPUPt_left()
{
	return cpu_pt[0];
}

int Point::GetCPUPt_senter()
{
	return cpu_pt[1];
}

int Point::GetCPUPt_right()
{
	return cpu_pt[2];
}