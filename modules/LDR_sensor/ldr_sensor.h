// ldr_sensor.h
#pragma once

#include "mbed.h"

/// Initialize the LDR subsystem (zeroes filter state).
void ldrInit();

/// Sample the LDR once: read raw, update filter, store both.
void ldrUpdate();

/// Get the last raw reading [0.0–1.0].
float ldrGetRaw();

/// Get the last filtered reading [0.0–1.0].
float ldrGetFiltered();
