#define ENEMY_PITY_SPENT 0b10000000
#define THUMB __attribute__((target("thumb")))
#define MAX_ENEMIES 112

#define PITY_DROP 0x8
#define NO_PITY_DROP 0x40

typedef _Bool bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

THUMB uint32_t pityCoreUpdate(unsigned char);
THUMB void pityCoreStart();
THUMB void pityCoreDisable(unsigned char);

extern const uint8_t enemyPityTable[ MAX_ENEMIES ];
extern uint8_t currentEnemyPity[ MAX_ENEMIES ];
extern bool checkForSouls;

typedef struct
{
	uint32_t createFunction;
	uint32_t updateFunction;

	uint16_t item1;
	uint16_t item2;

	uint16_t maxHP;
	uint16_t maxMP;
	uint16_t givenXP;

	uint8_t soulRarity;
	uint8_t attack;
	uint8_t defense;
	uint8_t item1Rarity;
	uint8_t item2Rarity;
	uint8_t soulType;
	uint8_t soulIdx;
	uint8_t unk_19;
	
	uint16_t weaknesses;
	uint16_t resistances;
	uint16_t unk_1E;
	uint16_t unk_20;
	uint16_t unk_22;
} EnemyDef

extern unsigned const enemydef_t enemyList[ MAX_ENEMIES ];
extern