#include "pityCore.h"

// This function will check every enemy right after the save file gets loaded
THUMB void getSoulList(int type)
{
	switch (type)
	{
		case 0:
		return 0x0201331C;
		break;

		case 1:
		return 0x02013354;
		break;

		case 2:
		return 0x0201336E;
		break;

		case 3:
		return 0x02013392;
		break;
	}
}

// Call this right after loading a game or in the game's update loop
THUMB void pityCoreStart()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		EnemyDef* curEnemy = &enemyList[i];

		uint8_t* curSoulList = getSoulList(curEnemy->soulType);
		if (curSoulList[ curEnemy->soulIdx ])
		{
			currentEnemyPity[i] = 0xFF;
		}
	}
}

THUMB uint32_t pityCoreUpdate(unsigned char enemy)
{
	uint8_t curPity = currentEnemyPity[enemy];

	if ( curPity & ENEMY_PITY_SPENT ) return NO_PITY_DROP;
	if ( (curPity + 1) >= enemyPityTable[enemy] )
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