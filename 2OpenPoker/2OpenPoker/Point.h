#pragma once
class Point
{
private:
	int player_pt = 5000;
	int cpu_pt[3] = { 5000, 5000, 5000 };

	int cpu_pt_posX[3] = { 150, 585, 1030 };
	int cpu_pt_posY[3] = { 330, 50, 330 };

	int sum_bet = 0;

	int Phese = 0;

	int bet_selectFlg = 99;

protected:
	const int anty = 20;
	const int bet[3] = { 100, 200, 300 };
	const int reiz = 100;

public:
	void DrawHavePoints();
	void DrawSumBetPoints();
	void Anty();
	void CPU_Bet();
	void Player_Bet();
	void BetSelectFlg(int x);

	int GetPlayerPt();
	int GetCPUPt_left();
	int GetCPUPt_senter();
	int GetCPUPt_right();
};