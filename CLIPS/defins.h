   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*               CLIPS Version 6.24  06/05/06          */
   /*                                                     */
   /*                                                     */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Brian L. Dantes                                      */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*************************************************************/

#ifndef _H_defins
#define _H_defins

#if DEFINSTANCES_CONSTRUCT

#define EnvGetDefinstancesName(theEnv,x) GetConstructNameString((struct constructHeader *) x)
#define EnvGetDefinstancesPPForm(theEnv,x) GetConstructPPForm(theEnv,(struct constructHeader *) x)

#define GetDefinstancesNamePointer(x) GetConstructNamePointer((struct constructHeader *) x)
#define SetDefinstancesPPForm(d,ppf) SetConstructPPForm(theEnv,(struct constructHeader *) d,ppf)

#define GetDefinstancesModuleName(x) GetConstructModuleName((struct constructHeader *) x)
#define EnvDefinstancesModule(theEnv,x) GetConstructModuleName((struct constructHeader *) x)

struct definstances;

#ifndef _H_conscomp
#include "conscomp.h"
#endif
#ifndef _H_constrct
#include "constrct.h"
#endif
#ifndef _H_cstrccom
#include "cstrccom.h"
#endif
#ifndef _H_moduldef
#include "moduldef.h"
#endif
#ifndef _H_object
#include "object.h"
#endif

typedef struct definstancesModule
  {
   struct defmoduleItemHeader header;
  } DEFINSTANCES_MODULE;

typedef struct definstances
  {
   struct constructHeader header;
   unsigned busy;
   EXPRESSION *mkinstance;
  } DEFINSTANCES;

#define DEFINSTANCES_DATA 22

struct definstancesData
  { 
   struct construct *DefinstancesConstruct;
   int DefinstancesModuleIndex;
#if CONSTRUCT_COMPILER && (! RUN_TIME)
   struct CodeGeneratorItem *DefinstancesCodeItem;
#endif
  };

#define DefinstancesData(theEnv) ((struct definstancesData *) GetEnvironmentData(theEnv,DEFINSTANCES_DATA))


#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _DEFINS_SOURCE_
#define LOCALE
#else
#define LOCALE extern "C"
#endif

#define DefinstancesModule(x) GetConstructModuleName((struct constructHeader *) x)
#define FindDefinstances(a) EnvFindDefinstances(GetCurrentEnvironment(),a)
#define GetDefinstancesList(a,b) EnvGetDefinstancesList(GetCurrentEnvironment(),a,b)
#define GetDefinstancesName(x) GetConstructNameString((struct constructHeader *) x)
#define GetDefinstancesPPForm(x) GetConstructPPForm(GetCurrentEnvironment(),(struct constructHeader *) x)
#define GetNextDefinstances(a) EnvGetNextDefinstances(GetCurrentEnvironment(),a)
#define IsDefinstancesDeletable(a) EnvIsDefinstancesDeletable(GetCurrentEnvironment(),a)
#define ListDefinstances(a,b) EnvListDefinstances(GetCurrentEnvironment(),a,b)
#define Undefinstances(a) EnvUndefinstances(GetCurrentEnvironment(),a)

LOCALE void SetupDefinstances(void *);
LOCALE void *EnvGetNextDefinstances(void *,void *);
LOCALE void *EnvFindDefinstances(void *,char *);
LOCALE int EnvIsDefinstancesDeletable(void *,void *);
LOCALE void UndefinstancesCommand(void *);
LOCALE void *GetDefinstancesModuleCommand(void *);
LOCALE intBool EnvUndefinstances(void *,void *);

#if DEBUGGING_FUNCTIONS
LOCALE void PPDefinstancesCommand(void *);
LOCALE void ListDefinstancesCommand(void *);
LOCALE void EnvListDefinstances(void *,char *,struct defmodule *);
#endif

LOCALE void GetDefinstancesListFunction(void *,DATA_OBJECT *);
LOCALE void EnvGetDefinstancesList(void *,DATA_OBJECT *,struct defmodule *);

#endif

#endif





