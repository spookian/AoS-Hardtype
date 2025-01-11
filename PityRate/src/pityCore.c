#include "pityCore.h"

THUMB int pityCoreStart(unsigned char enemy)
{
	unsigned char curPity = currentEnemyPity[enemy];

	if ( curPity & ENEMY_PITY_SPENT ) return NO_PITY_DROP;
	if ( curPity >= enemyPityTable[enemy] )
	{
		curPity |= ENEMY_PITY_SPENT;
		currentEnemyPity[enemy] = curPity;

		return PITY_DROP;
	}

	currentEnemyPity[enemy]++;
	return NO_PITY_DROP;
}

THUMB void pityCoreDisable(unsigned char enemy)
{
	currentEnemyPity[enemy] |= ENEMY_PITY_SPENT;
	return;
}