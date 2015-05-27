   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.24  06/05/06            */
   /*                                                     */
   /*              FACT FUNCTIONS HEADER FILE             */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Added ppfact command.                          */
/*                                                           */
/*************************************************************/

#ifndef _H_factfun
#define _H_factfun

#ifndef _H_factmngr
#include "factmngr.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _FACTFUN_SOURCE_
#define LOCALE
#else
#ifdef __cplusplus
#define LOCALE extern "C"
#else
#define LOCALE extern
#endif
#endif

#define FactDeftemplate(a) EnvFactDeftemplate(GetCurrentEnvironment(),a)
#define FactExistp(a) EnvFactExistp(GetCurrentEnvironment(),a)
#define FactSlotNames(a,b) EnvFactSlotNames(GetCurrentEnvironment(),a,b)
#define GetFactList(a,b) EnvGetFactList(GetCurrentEnvironment(),a,b)
#define PPFact(a,b,c) EnvPPFact(GetCurrentEnvironment(),a,b,c)

   LOCALE void                           FactFunctionDefinitions(void *);
   LOCALE void                          *FactRelationFunction(void *);
   LOCALE void                          *FactRelation(void *);
   LOCALE void                          *EnvFactDeftemplate(void *,void *);
   LOCALE int                            FactExistpFunction(void *);
   LOCALE int                            EnvFactExistp(void *,void *);
   LOCALE void                           FactSlotValueFunction(void *,DATA_OBJECT *);
   LOCALE void                           FactSlotValue(void *,void *,char *,DATA_OBJECT *);
   LOCALE void                           FactSlotNamesFunction(void *,DATA_OBJECT *);
   LOCALE void                           EnvFactSlotNames(void *,void *,DATA_OBJECT *);
   LOCALE void                           GetFactListFunction(void *,DATA_OBJECT *);
   LOCALE void                           EnvGetFactList(void *,DATA_OBJECT *,void *);
   LOCALE void                           PPFactFunction(void *);
   LOCALE void                           EnvPPFact(void *,void *,char *,int);
   LOCALE struct fact                   *GetFactAddressOrIndexArgument(void *,char *,int,int);

#endif

