#ifndef ADVANCEDTHERMOSTAT_SYS_MAIN_H
#define ADVANCEDTHERMOSTAT_SYS_MAIN_H


#ifdef	__cplusplus
extern	"C"	{
#endif

 
static void ApplicationLevelInitialization( void );

int advancedThermostat_sys_mainRunner();

int advancedThermostat_sys_mainTerminateComponents();

#ifdef	__cplusplus
}
#endif

#endif  /* ADVANCEDTHERMOSTAT_SYS_MAIN_H */
