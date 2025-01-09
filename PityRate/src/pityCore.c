#define ENEMY_PITY_SPENT 0b10000000
#define THUMB __attribute__((target("thumb")))
#define MAX_ENEMIES 112

#define PITY_DROP 0x2
#define NO_PITY_DROP 0x3C

extern unsigned const char enemyPityTable[ MAX_ENEMIES ];
extern unsigned char currentEnemyPity[ MAX_ENEMIES ];

THUMB int pityCoreStart(unsigned char enemy)
{
	unsigned char curPity = currentEnemyPity[enemy];

	if ( curPity & ENEMY_PITY_SPENT ) return NO_PITY_DROP;
	if ( curPity >= enemyPityTable[enemy] )
	{
		curPity |= ENEMY_PITY_SPENT;
		currentEnemyPity = curPity;

		return PITY_DROP;
	}

	currentEnemyPity[enemy]++;
	return NO_PITY_DROP;
}