# Print_PrintDocCallback


## Overview

Defines the print job callback struct.

**Since**: 13

**Related module**: [OH_Print](_o_h___print.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Print_OnStartLayoutWrite](_o_h___print.md#print_onstartlayoutwrite) [startLayoutWriteCb](#startlayoutwritecb) | Defines a callback to be invoked when the file write-back starts. | 
| [Print_OnJobStateChanged](_o_h___print.md#print_onjobstatechanged) [jobStateChangedCb](#jobstatechangedcb) | Defines a callback used to return the print job state. | 


## Member Variable Description


### jobStateChangedCb

```
Print_OnJobStateChanged Print_PrintDocCallback::jobStateChangedCb
```
**Description**
Defines a callback used to return the print job state.


### startLayoutWriteCb

```
Print_OnStartLayoutWrite Print_PrintDocCallback::startLayoutWriteCb
```
**Description**
Defines a callback to be invoked when the file write-back starts.
