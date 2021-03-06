   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.30  10/19/06            */
   /*                                                     */
   /*                 AGENDA HEADER FILE                  */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*   Provides functionality for examining, manipulating,     */
/*   adding, and removing activations from the agenda.       */
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
/*      6.24: Removed CONFLICT_RESOLUTION_STRATEGIES and     */
/*            DYNAMIC_SALIENCE compilation flags.            */
/*                                                           */
/*            Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*            Added EnvGetActivationBasisPPForm function.    */
/*                                                           */
/*      6.30: Added salience groups to improve performance   */
/*            with large numbers of activations of different */
/*            saliences.                                     */
/*                                                           */
/*************************************************************/

#ifndef _H_agenda

#define _H_agenda

#ifndef _H_ruledef
#include "ruledef.h"
#endif
#ifndef _H_symbol
#include "symbol.h"
#endif
#ifndef _H_match
#include "match.h"
#endif

#define WHEN_DEFINED 0
#define WHEN_ACTIVATED 1
#define EVERY_CYCLE 2

#define MAX_DEFRULE_SALIENCE  10000
#define MIN_DEFRULE_SALIENCE -10000
  
/*******************/
/* DATA STRUCTURES */
/*******************/

struct activation
  {
   struct defrule *theRule;
   struct partialMatch *basis;
   int salience;
   unsigned long long timetag;
   int randomID;
   struct activation *prev;
   struct activation *next;
  };

struct salienceGroup
  {
   int salience;
   struct activation *first;
   struct activation *last;
   struct salienceGroup *next;
   struct salienceGroup *prev;
  };

typedef struct activation ACTIVATION;

#define AGENDA_DATA 17

struct agendaData
  { 
#if DEBUGGING_FUNCTIONS
   unsigned WatchActivations;
#endif
   unsigned long NumberOfActivations;
   unsigned long long CurrentTimetag;
   int AgendaChanged;
   intBool SalienceEvaluation;
   int Strategy;
  };

#define EnvGetActivationSalience(theEnv,actPtr) (((struct activation *) actPtr)->salience)
#define GetActivationRule(actPtr) (((struct activation *) actPtr)->theRule)
#define GetActivationBasis(actPtr) (((struct activation *) actPtr)->basis)
#define AgendaData(theEnv) ((struct agendaData *) GetEnvironmentData(theEnv,AGENDA_DATA))

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _AGENDA_SOURCE_
#define LOCALE
#else
#ifdef __cplusplus
#define LOCALE extern "C"
#else
#define LOCALE extern
#endif
#endif

/****************************************/
/* GLOBAL EXTERNAL FUNCTION DEFINITIONS */
/****************************************/

#define Agenda(a,b) EnvAgenda(GetCurrentEnvironment(),a,b)
#define DeleteActivation(a) EnvDeleteActivation(GetCurrentEnvironment(),a)
#define GetActivationName(a) EnvGetActivationName(GetCurrentEnvironment(),a)
#define GetActivationPPForm(a,b,c) EnvGetActivationPPForm(GetCurrentEnvironment(),a,b,c)
#define GetActivationSalience(actPtr) (((struct activation *) actPtr)->salience)
#define GetAgendaChanged() EnvGetAgendaChanged(GetCurrentEnvironment())
#define GetNextActivation(a) EnvGetNextActivation(GetCurrentEnvironment(),a)
#define GetSalienceEvaluation() EnvGetSalienceEvaluation(GetCurrentEnvironment())
#define Refresh(a) EnvRefresh(GetCurrentEnvironment(),a)
#define RefreshAgenda(a) EnvRefreshAgenda(GetCurrentEnvironment(),a)
#define ReorderAgenda(a) EnvReorderAgenda(GetCurrentEnvironment(),a)
#define SetActivationSalience(a,b) EnvSetActivationSalience(GetCurrentEnvironment(),a,b)
#define SetAgendaChanged(a) EnvSetAgendaChanged(GetCurrentEnvironment(),a)
#define SetSalienceEvaluation(a) EnvSetSalienceEvaluation(GetCurrentEnvironment(),a)

   LOCALE void                    AddActivation(void *,void *,void *);
   LOCALE void                    ClearRuleFromAgenda(void *,void *);
   LOCALE void                   *EnvGetNextActivation(void *,void *);
   LOCALE char                   *EnvGetActivationName(void *,void *);
   LOCALE int                     EnvSetActivationSalience(void *,void *,int);
   LOCALE void                    EnvGetActivationPPForm(void *,char *,unsigned,void *);
   LOCALE void                    EnvGetActivationBasisPPForm(void *,char *,unsigned,void *);
   LOCALE intBool                 MoveActivationToTop(void *,void *);
   LOCALE intBool                 EnvDeleteActivation(void *,void *);
   LOCALE intBool                 DetachActivation(void *,void *);
   LOCALE void                    EnvAgenda(void *,char *,void *);
   LOCALE void                    RemoveActivation(void *,void *,int,int);
   LOCALE void                    RemoveAllActivations(void *);
   LOCALE int                     EnvGetAgendaChanged(void *);
   LOCALE void                    EnvSetAgendaChanged(void *,int);
   LOCALE unsigned long           GetNumberOfActivations(void *);
   LOCALE intBool                 EnvGetSalienceEvaluation(void *);
   LOCALE intBool                 EnvSetSalienceEvaluation(void *,intBool);
   LOCALE void                    EnvRefreshAgenda(void *,void *);
   LOCALE void                    EnvReorderAgenda(void *,void *);
   LOCALE void                    InitializeAgenda(void *);
   LOCALE void                   *SetSalienceEvaluationCommand(void *);
   LOCALE void                   *GetSalienceEvaluationCommand(void *);
   LOCALE void                    RefreshAgendaCommand(void *);
   LOCALE void                    RefreshCommand(void *);
   LOCALE intBool                 EnvRefresh(void *,void *);
#if DEBUGGING_FUNCTIONS
   LOCALE void                    AgendaCommand(void *);
#endif

#endif






