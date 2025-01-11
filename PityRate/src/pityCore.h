#define ENEMY_PITY_SPENT 0b10000000
#define THUMB __attribute__((target("thumb")))
#define MAX_ENEMIES 112

#define PITY_DROP 0x8
#define NO_PITY_DROP 0x40

THUMB int pityCoreStart(unsigned char);
THUMB void pityCoreDisable(unsigned char);

extern unsigned const char enemyPityTable[ MAX_ENEMIES ];
extern unsigned char currentEnemyPity[ MAX_ENEMIES ];