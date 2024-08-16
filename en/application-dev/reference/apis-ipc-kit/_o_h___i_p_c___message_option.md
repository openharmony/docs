# OH_IPC_MessageOption


## Overview

Defines an IPC message.

**Since**: 12

**Related module**: [OHIPCRemoteObject](_o_h_i_p_c_remote_object.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_IPC_RequestMode](_o_h_i_p_c_remote_object.md#oh_ipc_requestmode)[mode](#mode) | Message request mode.| 
| uint32_t [timeout](#timeout) | Parameter reserved for RPC. It is invalid for IPC.| 
| void \* [reserved](#reserved) | Reserved parameter, which must be NULL.| 


## Member Variable Description


### mode

```
OH_IPC_RequestMode OH_IPC_MessageOption::mode
```

**Description**

Message request mode.


### reserved

```
void* OH_IPC_MessageOption::reserved
```

**Description**

Reserved parameter, which must be NULL.


### timeout

```
uint32_t OH_IPC_MessageOption::timeout
```

**Description**

Parameter reserved for RPC. It is invalid for IPC.
