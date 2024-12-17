// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 Aashish Poudel

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_out;       // The pin where the analog data will be output
  uint32_t tds_value;        // Timer ID for periodic updates
} chip_state_t;


void chip_timer_event(void *user_data){
  chip_state_t *chip = (chip_state_t*)user_data;
  float tds = attr_read_float(chip->tds_value);
  float voltage = tds * 5.0/1000;
  printf("voltage:%.2f\n",voltage);
  pin_dac_write(chip->pin_out, voltage);
}


void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  // TODO: Initialize the chip, set up IO pins, create timers, etc.
  chip->pin_out = pin_init("OUT",ANALOG);        // Assign the analog pin
  chip->tds_value = attr_init_float("tds",0);   // Update every 1000 ms (1 second)

  const timer_config_t timer_config={
    .callback = chip_timer_event,
    .user_data = chip,
  };

  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id,1000,true);
  printf("Hello from custom chip!\n");
}



