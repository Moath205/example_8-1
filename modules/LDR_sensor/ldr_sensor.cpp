// ldr_sensor.cpp
#include "ldr_sensor.h"

static AnalogIn ldrIn(A2);
static float    ldrRaw      = 0.0f;
static float    ldrFiltered = 0.0f;

/// α for one‑pole IIR: higher α → faster, but noisier
static constexpr float FILTER_ALPHA = 0.1f;

void ldrInit() {
    ldrRaw      = 0.0f;
    ldrFiltered = 0.0f;
}

void ldrUpdate() {
    ldrRaw = ldrIn.read();  
    // exponential moving average
    ldrFiltered = FILTER_ALPHA * ldrRaw
                + (1.0f - FILTER_ALPHA) * ldrFiltered;
}

float ldrGetRaw() {
    return ldrRaw;
}

float ldrGetFiltered() {
    return ldrFiltered;
}
