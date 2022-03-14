/*
 * stepper_manual.h
 *
 *  Created on: Mar 6, 2022
 *      Author: Beheerder
 */

#ifndef INC_STEPPER_MANUAL_H_
#define INC_STEPPER_MANUAL_H_

int stepper_speed;

void stepper_manual(LX_to_back, LX_to_front, LY_to_top, LY_to_below, LZ_go_in, LZ_go_out, LW_cw, LW_ccw,
                    RX_to_back, RX_to_front, RY_to_top, RY_to_below, RZ_go_in, RZ_go_out, RW_cw, RW_ccw  );

#endif /* INC_STEPPER_MANUAL_H_ */

#include "main.h"
