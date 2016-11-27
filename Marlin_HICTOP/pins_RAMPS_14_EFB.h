/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with RAMPS v1.4 pin assignments
 *
 *  RAMPS_14_EFB (Extruder, Fan, Bed)
 */

//#define IS_RAMPS_EFB

//#include "pins_RAMPS_14.h"

/**
 * MPX-3 with RAMPS v1.4 pin assignments EEB + fan
 *
 *  ie RAMPS_14_EBFE (Extruder, Bed, Fan, Extruder)
 */

#define IS_RAMPS_EEB

#include "pins_RAMPS_13.h"

#undef HEATER_BED_PIN
#define HEATER_BED_PIN    8    // BED

#undef FAN_PIN
#define FAN_PIN           9    // FAN

#undef HEATER_0_PIN
#define HEATER_0_PIN     10    // E0

#undef HEATER_1_PIN
#define HEATER_1_PIN      7    // E1
