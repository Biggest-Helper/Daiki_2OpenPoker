#include "DxLib.h"
#include "Point.h"

void Point::DrawPhese()
{
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

	if (Phese == 3)
	{
		
	}

	//プレイヤー、CPUの所持ベット描画
	DrawHavePoints();

	//ベット合計描画
	DrawSumBetPoints();

}

void Point::DrawHavePoints()
{
	SetFontSize(15);

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
	//CPU アンティ
	for (int i = 0; i < 3; i++)
	{
		int num = cpu_pt[i] - anty;
		int num2 = sum_bet + anty;
		
		while (cpu_pt[i] != num && sum_bet != num2)
		{
			cpu_pt[i]--;
			sum_bet++;
		}
	}

	//プレイヤー アンティ
	int num = player_pt - anty;
	int num2 = sum_bet + anty;
	while (player_pt != num && sum_bet != num2)
	{
		player_pt--;
		sum_bet++;
	}
}

void Point::CPU_Bet()
{
	for (int i = 0; i < 3; i++)
	{
		//CPUベッティング処理
		int num = cpu_pt[i] - bet[0];
		int num2 = sum_bet + bet[0];
		while (cpu_pt[i] != num && sum_bet != num2)
		{
			cpu_pt[i]--;
			sum_bet++;
		}

		/*cpu_pt[i] -= bet[0];
		sum_bet += bet[0];*/

		if (i == 0)
		{
			SetFontSize(15);
			DrawBox(cpu_pt_posX[i] + 45, cpu_pt_posY[i] + 75, cpu_pt_posX[i] + 105, cpu_pt_posY[i] + 105,
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 50, cpu_pt_posY[i] + 82, "ベット", GetColor(0, 0, 0));
		}
		else if (i == 1)
		{
			DrawBox(cpu_pt_posX[i] + 185, cpu_pt_posY[i] + 10, cpu_pt_posX[i] + 245, cpu_pt_posY[i] + 40,
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 190, cpu_pt_posY[i] + 17, "コール", GetColor(0, 0, 0));
		}
		else if (i == 2)
		{
			DrawBox(cpu_pt_posX[i] + 45, cpu_pt_posY[i] + 75, cpu_pt_posX[i] + 105, cpu_pt_posY[i] + 105,
				GetColor(255, 255, 255), TRUE);
			DrawString(cpu_pt_posX[i] + 50, cpu_pt_posY[i] + 82, "コール", GetColor(0, 0, 0));
		}
		else
		{

		}
	}
}

void Point::Player_Bet()
{
	if (bet_selectFlg == 0)
	{
		player_pt -= bet[0] * 2;
		sum_bet += bet[0] * 2;
		Phese = 1;
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
	}
	else if (selectNum == 1)
	{
		bet_selectFlg = 1;
	}
	else if (selectNum == 2)
	{
		bet_selectFlg = 2;
	}
	DrawPhese();
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