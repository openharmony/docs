# timer.h


## Overview

The **timer.h** file declares the timer interfaces in C.

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 12

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t)[ffrt_timer_start](_f_f_r_t.md#ffrt_timer_start) ([ffrt_qos_t](_f_f_r_t.md) qos, uint64_t timeout, void\* data, [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb) cb, bool repeat) | Starts the timer. | 
| FFRT_C_API int [ffrt_timer_stop](_f_f_r_t.md#ffrt_timer_stop) ([ffrt_qos_t](_f_f_r_t.md) qos, [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) handle) | Stops the timer. | 
