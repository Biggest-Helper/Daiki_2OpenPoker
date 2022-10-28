#pragma once
class Point
{
private:
	int player_pt = 5000;
	int cpu1_pt = 5000;
	int cpu2_pt = 5000;
	int cpu3_pt = 5000;

	int cpu_pt_posX[3] = { 330, 150, 1130 };
	int cpu_pt_posY[3] = { 50, 550, 170 };

protected:
	const int anty = 20;
	const int bet[3] = { 100, 200, 300 };
	const int reiz = 100;

public:
	void DrawHavePoints();
	void DrawSumBetPoints();

	int GetPlayerPt();
	int GetCPU1Pt();
	int GetCPU2Pt();
	int GetCPU3Pt();
};