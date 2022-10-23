#include "DxLib.h"
#include "Card.h"

void Card::LoadImages()
{
	*card[0][0] = LoadDivGraph("../images/Card_Sozai.png", 13, 3, 3, 10, 10, card[12][0]);
}

int Card::getCard()
{
	return *card[0][0];
}

//ÇÌÇ¡Ç©ÇÒÇÀÇ•Ç‚...ÅB