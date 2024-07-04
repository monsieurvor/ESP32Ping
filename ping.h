#ifndef PING_H
#define PING_H
#include <Arduino.h>

typedef void(*ping_recv_function)(void* arg, void *pdata, void *instance);
typedef void(*ping_sent_function)(void* arg, void *pdata, void *instance);

struct ping_option {
    uint32_t count = 0;
    uint32_t ip = 0;
    uint32_t coarse_time = 500;
    uint16_t timeout = 1000;
    ping_recv_function recv_function;
    ping_sent_function sent_function;
    void* reverse;
};

struct ping_resp {
    uint32_t total_count = 0;
    float resp_time = 0;
    uint32_t seqno = 0;
    uint32_t timeout_count = 0;
    uint32_t bytes = 0;
    uint32_t total_bytes = 0;
    float total_time = 0;
    int8_t  ping_err = 0;
};

bool ping_start(struct ping_option *ping_opt, void *instance);
void ping(const char *name, int count, int interval, int size, int timeout);
bool ping_start(IPAddress adr, int count, int interval, int size, int timeout, struct ping_option *ping_o = NULL, void *instance = NULL);

#endif // PING_H
