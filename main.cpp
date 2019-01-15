/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stats_report.h"

DigitalOut led1(LED1);
EventQueue *queue = mbed_event_queue();

#define SLEEP_TIME                  500 // (msec)
#define REPORT_TIME                 10000

// main() runs in its own thread in the OS
int main()
{
    SystemReport sys_state( REPORT_TIME ); // Report loop delay time in ms
    queue->call_every(REPORT_TIME, &sys_state, &SystemReport::report_state);

    int count = 0;
    while (true) {
        // Blink LED and wait 0.5 seconds
        led1 = !led1;
        wait_ms(SLEEP_TIME);
    }
}
