#pragma once
class Card
{
private:
	int* card[12][3];
	int joker;

public:
	void LoadImages();
	int getCard();
};