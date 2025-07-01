# InitSync


## Overview

Provides APIs for notifying the Init process of events.

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [init_sync.h](init__sync_8h.md) | Declares the API for notifying the Init process of events.| 


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
| int [NotifyInit](#notifyinit) (unsigned long event) | Notifies the Init process of an event. This API can be called by all processes, especially the listened process.| 


## Function Description


### NotifyInit()

```
int NotifyInit (unsigned long event)
```

**Description**

Notifies the Init process of an event. This API can be called by all processes, especially the listened process.

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | The events should be consistent between the listener (init process) and the notifier.| 

**Returns**

Returns **-1** if the operation fails.
