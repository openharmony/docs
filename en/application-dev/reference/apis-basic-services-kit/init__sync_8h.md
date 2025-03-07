# init_sync.h


## Overview

Declares the API for notifying the Init process of events.

\@kit BasicServicesKit

**System capability**: SystemCapability.Startup.SystemInfo

**Since**: 10

**Related module**: [InitSync](_init_sync.md)


## Summary


### Macros

| Name| Description| 
| -------- | -------- |
| **EVENT1**&nbsp;&nbsp;&nbsp;0xf | Defines the event **EVENT1**.| 
| **EVENT1_WAITTIME**&nbsp;&nbsp;&nbsp;10000 | The value **10000** indicates that the waiting time for **EVENT1** is 10s.| 
| **EVENT2**&nbsp;&nbsp;&nbsp;0xf0 | Defines the event **EVENT2**.| 
| **EVENT2_WAITTIME**&nbsp;&nbsp;&nbsp;0 | The value **0** indicates that QS_STAGE2 is not used.| 
| **EVENT3**&nbsp;&nbsp;&nbsp;0xf00 | Defines the event **EVENT3**.| 
| **EVENT3_WAITTIME**&nbsp;&nbsp;&nbsp;0 | The value **0** indicates that QS_STAGE3 is not used.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int [NotifyInit](_init_sync.md#notifyinit) (unsigned long event) | Notifies the Init process of an event. This API can be called by all processes, especially the listened process.| 
