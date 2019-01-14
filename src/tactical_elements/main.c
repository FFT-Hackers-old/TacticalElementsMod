#include <windows.h>
#include "damage_formulas.h"
#include "command_mechanics.h"
#include "elemental_modifiers.h"
#include "impl.h"

/*SisRay re-exported mog functions*/
PFNSRREPLACEFUNCTIONPROC srReplaceFunction;
PFNSRREDIRECTFUNCTIONPROC srRedirectFunction;

/*TacticalMod internal trampolines*/
PFNCOMMANDMAINPROC* oldCommandMain;
PFNRUNANIMSCRIPT* oldRunAnimationScript;
PFNDECREMENTCOUNTERS* oldDecrementCounters;
PFNAPPLYDAMAGE*  oldApplyDamage;

__declspec(dllexport) void ModMain(const void* unused)
{
	srReplaceFunction = srLoadFunction("srReplaceFunction");
	srRedirectFunction = srLoadFunction("srRedirectFunction");

	MessageBoxA(NULL, "Loading FFVII tactical elements mod", 0, 0);
	oldCommandMain = srRedirectFunction(MAIN_COMMAND_FORMULA, &CommandMainRewrite);
	oldRunAnimationScript = srRedirectFunction(RUN_ANIMATION_SCRIPT, &AnimationScriptRewrite);
	oldDecrementCounters = srRedirectFunction(DECREMENT_COUNTERS, &DecrementCountersRewrite);
	oldApplyDamage = srRedirectFunction(APPLY_DAMAGE_ROUTINE, &applyDamageHook);
	srReplaceFunction(PHYSICAL_DAMAGE_FORMULA, &PhysicalFormulaRewrite);
	srReplaceFunction(POISON_SETUP_ROUTINE, &ModifyPoisonTest);
	srReplaceFunction(APPLY_ELEMENTAL_MODIFIERS, &ApplyElementalModifiers);
}