# loop.h


## Overview

The **loop.h** file declares the FFRT loop interfaces in C.

**System capability**: SystemCapability.Resourceschedule.Ffrt.Core

**Since**: 12

**Related module**: [FFRT](_f_f_r_t.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
|  typedef void\*&nbsp;&nbsp;**ffrt_loop_t** |  | 


### Functions

| Name| Description| 
| -------- | -------- |
| FFRT_C_API ffrt_loop_t [ffrt_loop_create](_f_f_r_t.md#ffrt_loop_create) ([ffrt_queue_t](_f_f_r_t.md) queue) | Creates a loop. | 
| FFRT_C_API int [ffrt_loop_destroy](_f_f_r_t.md#ffrt_loop_destroy) (ffrt_loop_t loop) | Destroys a loop. | 
| FFRT_C_API int [ffrt_loop_run](_f_f_r_t.md#ffrt_loop_run) (ffrt_loop_t loop) | Runs a loop. | 
| FFRT_C_API void [ffrt_loop_stop](_f_f_r_t.md#ffrt_loop_stop) (ffrt_loop_t loop) | Stops a loop. | 
| FFRT_C_API int [ffrt_loop_epoll_ctl](_f_f_r_t.md#ffrt_loop_epoll_ctl) (ffrt_loop_t loop, int op, int fd, uint32_t events, void\* data, [ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb) cb) | Manages listening events on a loop. | 
| FFRT_C_API [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t)[ffrt_loop_timer_start](_f_f_r_t.md#ffrt_loop_timer_start) (ffrt_loop_t loop, uint64_t timeout, void\* data, [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb) cb, bool repeat) | Starts the timer on a loop. | 
| FFRT_C_API int [ffrt_loop_timer_stop](_f_f_r_t.md#ffrt_loop_timer_stop) (ffrt_loop_t loop, [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) handle) | Stops the timer on a loop. | 
