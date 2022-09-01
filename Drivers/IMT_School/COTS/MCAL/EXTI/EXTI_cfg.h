/*
 * EXTI_cfg.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_EXTI_EXTI_CFG_H_
#define IMT_SCHOOL_COTS_MCAL_EXTI_EXTI_CFG_H_

#define EXTI_INT0         ENABLE
#define EXTI_INT1         DISABLE
#define EXTI_INT2         DISABLE

/*
 * EXTI_INT0_SENSE_CTRL , EXTI_INT1_SENSE_CTRL
 * Options:
 * EXTI_FALLING ,
 * EXTI_RISING ,
 * EXTI_LOW_LVL ,
 * EXTI_ONCHANGE
 *       ----------------------------
 * EXTI_INT2_SENSE_CTRL
 * Options:
 * EXTI_FALLING ,
 * EXTI_RISING
 *
 **/
#define EXTI_INT0_SENSE_CTRL  EXTI_LOW_LVL
#define EXTI_INT1_SENSE_CTRL  EXTI_FALLING
#define EXTI_INT2_SENSE_CTRL  EXTI_FALLING

#endif /* IMT_SCHOOL_COTS_MCAL_EXTI_EXTI_CFG_H_ */
