/**
 * @file       main.c
 * @brief      Main routine
 * @details    
 * @author     Noah Huetter (noahhuetter@gmail.com)
 * @date       23 March 2017
 * 
 *
 * @addtogroup MAIN
 * @brief main routine and UX
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "defs.h"
// #include "chprintf.h"

#include "usbcdc.h"
#include "usbcfg.h"

/*===========================================================================*/
/* settings                                                                */
/*===========================================================================*/

/*===========================================================================*/
/* private data                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* prototypes                                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module static functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* callbacks                                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module public functions.                                                  */
/*===========================================================================*/
/*
 * Application entry point.
 */
int main(void) 
{
  /*
  * System initializations.
  */
  halInit();
  chSysInit();

  /**
  * User init
  */
  usbcdcInit();

  palSetPadMode(GPIOE, 14, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPad(GPIOE,14);

  /**
   * Idle thread
   */
  chRegSetThreadName(DEFS_THD_IDLE_NAME);
  while (true) 
  {
    chThdSleepMilliseconds(100);
    palTogglePad(GPIOE,14);
    usbcdcHandleShell();
  }
}

/** @} */
