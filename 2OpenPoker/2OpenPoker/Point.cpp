#include "DxLib.h"
#include "Point.h"

void Point::DrawHavePoints()
{
	SetFontSize(10);
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			DrawBox(850, 550, 950, 590, GetColor(255, 255, 255), TRUE);
			DrawString(870, 555, "プレイヤー", GetColor(0, 0, 0));
			DrawString(860, 570, "所持pt :", GetColor(0, 0, 0));
			/*DrawString(910, 540, "0pt", GetColor(0, 0, 0));*/
			DrawFormatString(910, 570, GetColor(0, 0, 0), "%dpt", player_pt);
		}
		else
		{
			DrawBox(cpu_pt_posX[i], cpu_pt_posY[i], cpu_pt_posX[i] + 100, cpu_pt_posY[i] + 40, 
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 35, cpu_pt_posY[i] + 5, "CPU", GetColor(0, 0, 0));
			DrawString(cpu_pt_posX[i] + 10, cpu_pt_posY[i] + 20, "所持pt :", GetColor(0, 0, 0));
			/*DrawString(cpu_pt_posX[i] + 60, cpu_pt_posY[i] + 20, "0pt", GetColor(0, 0, 0));*/
			DrawFormatString(cpu_pt_posX[i] + 60, cpu_pt_posY[i] + 20, GetColor(0, 0, 0), "%dpt", cpu_pt[i]);
		}
	}
}

void Point::DrawSumBetPoints()
{
	DrawCircle(640, 360, 45, GetColor(255, 255, 255), TRUE);
	SetFontSize(12);
	DrawString(610, 345, "ベット合計", GetColor(0, 0, 0));
	SetFontSize(14);
	/*DrawString(620, 365, "2200pt", GetColor(0, 0, 0));*/
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