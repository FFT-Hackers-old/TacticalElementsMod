#ifndef TACTICAL_ELEMENTS_H
#define TACTICAL_ELEMENTS_H

/*Defines for new status effect masks*/
#define STATUS_BLEED           ((u16)0x8000)
#define STATUS_WOUNDED		   ((u16)0x4000)
#define STATUS_BURN            ((u16)0x2000)
#define STATUS_OVERHEAT        ((u16)0x1000)
#define STATUS_CHILLED         ((u16)0x0800)
#define STATUS_FROZEN          ((u16)0x0400)
#define STATUS_SOAKED          ((u16)0x0200)
#define STATUS_CHARGED         ((u16)0x0100)
#define STATUS_FLOAT           ((u16)0x0080)

/*Defines for default values of new status effects*/
#define defaultPoisonTimer      ((u16)0x08)
#define defaultBleedIntensity   ((u16)0x06)
#define defaultBleedExpiration  ((u16)0x0A)
#define defaultBurnIntensity    ((u16)0x06)
#define defaultBurnExpiration   ((u16)0x0A)
#define defaultSoakedDuration   ((u16)0x0C)
#define defaultFloatDuration    ((u16)0x20)
#define defaultChilledIntensity ((u16)0x06)

/*Struct for holding actor data for new status effects*/
typedef struct {
	u8 bleedIntensity;
	i8 bleedTickRate;
	u8 SeriousWoundCount;
	u8 SeriousWoundTickRate;
	u8 GrievousWoundCount;
	u8 GrievousWoundTickRate;
	u8 burnIntensity;
	i8 burnTickRate;
	i8 chilledIntensity;
	u8 feezeDuration;
	u8 soakedDuration;
	u8 floatDuration;
	u8 chargeIntensity;
} newStatusActorBlock;

/*create a new array for holding counters associated with new status effects*/
extern newStatusActorBlock statusConstantArray[10];
extern int arc_enabled;
extern int disable_burn;

#endif