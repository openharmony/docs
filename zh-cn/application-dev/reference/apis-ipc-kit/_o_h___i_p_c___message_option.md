# OH_IPC_MessageOption


## 概述

IPC消息选项定义。

**起始版本：** 12

**相关模块：**[OHIPCRemoteObject](_o_h_i_p_c_remote_object.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_IPC_RequestMode](_o_h_i_p_c_remote_object.md#oh_ipc_requestmode) [mode](#mode) | 消息请求模式。 | 
| uint32_t [timeout](#timeout) | RPC预留参数，该参数对IPC无效。 | 
| void \* [reserved](#reserved) | 保留参数，必须为空。 | 


## 结构体成员变量说明


### mode

```
OH_IPC_RequestMode OH_IPC_MessageOption::mode
```

**描述**

消息请求模式。


### reserved

```
void* OH_IPC_MessageOption::reserved
```

**描述**

保留参数，必须为空。


### timeout

```
uint32_t OH_IPC_MessageOption::timeout
```

**描述**

RPC预留参数，该参数对IPC无效。
