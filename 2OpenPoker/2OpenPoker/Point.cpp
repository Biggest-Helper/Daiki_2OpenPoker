#include "DxLib.h"
#include "Point.h"

void Point::DrawHavePoints()
{
	SetFontSize(10);
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
		{
			DrawBox(850, 520, 950, 560, GetColor(255, 255, 255), TRUE);
			DrawString(870, 525, "プレイヤー", GetColor(0, 0, 0));
			DrawString(860, 540, "所持pt :", GetColor(0, 0, 0));
			DrawString(910, 540, "0pt", GetColor(0, 0, 0));
		}
		else
		{
			DrawBox(cpu_pt_posX[i], cpu_pt_posY[i], cpu_pt_posX[i] + 100, cpu_pt_posY[i] + 40, 
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 35, cpu_pt_posY[i] + 5, "CPU", GetColor(0, 0, 0));
			DrawString(cpu_pt_posX[i] + 10, cpu_pt_posY[i] + 20, "所持pt :", GetColor(0, 0, 0));
			DrawString(cpu_pt_posX[i] + 60, cpu_pt_posY[i] + 20, "0pt", GetColor(0, 0, 0));
		}
	}
}

void Point::DrawSumBetPoints()
{
	DrawCircle(640, 360, 45, GetColor(255, 255, 255), TRUE);
	SetFontSize(12);
	DrawString(610, 345, "ベット合計", GetColor(0, 0, 0));
	SetFontSize(14);
	DrawString(620, 365, "2200pt", GetColor(0, 0, 0));
}

int Point::GetPlayerPt()
{
	return player_pt;
}

int Point::GetCPU1Pt()
{
	return cpu1_pt;
}

int Point::GetCPU2Pt()
{
	return cpu2_pt;
}

int Point::GetCPU3Pt()
{
	return cpu3_pt;
}