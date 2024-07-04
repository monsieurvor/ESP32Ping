/*
  ESP32Ping - Ping library for ESP32
  Copyright (c) 2018 Marian Craciunescu. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef ESP32PING_H
#define ESP32PING_H

#include <Arduino.h>
#include <WiFi.h>

//extern "C" {
#include <ping.h>
//}

#ifdef ENABLE_DEBUG_PING
#define DEBUG_PING(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_PING(...)
#endif

#ifdef __cplusplus
extern "C"{
#endif

void esp_schedule(void);
void esp_yield(void);

#ifdef __cplusplus
} // extern "C"
#endif

class PingClass {
public:
    bool ping(IPAddress dest, byte count = 2, uint16_t interval = 500, uint16_t timeout = 1000);

    bool ping(const char *host, byte count = 2, uint16_t interval = 500, uint16_t timeout = 1000);

    float averageTime();

protected:
    static void _ping_sent_cb(void *opt, void *pdata);

    static void _ping_recv_cb(void *opt, void *pdata, void *inst);

    IPAddress _dest;
    ping_option _options;

    byte _expected_count = 0, _errors = 0, _success = 0;
    float _avg_time = 0;
};

#endif
