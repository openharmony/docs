# LiteIPC driver

## Overview
LiteIPC is a HarmonyOS extension to the LiteOS(a) kernel which provides a means for processes on the same device to communicate with each other.  It is a somewhat higher level mechanism than POSIX IPC methods such as message queues or shared memory, providing automatic management of resources used for IPC and control of access rights to send messages to other processes.  IPC messages are exchanged between tasks.  An IPC service is a task which has been set up to receive request type messages.  Access rights are granted to processes, if a process has access to a service then all tasks in the process are able to send requests to the service.

## API
*Interface*  
//foundation/communication/frameworks/ipc_lite/liteipc/include/liteipc.h  
//foundation/communication/interfaces/kits/ipc_lite/liteipc_adapter.h  

*Implementation*  
//kernel/liteos_a/kernel/extended/liteipc/hm_liteipc.h  
//kernel/liteos_a/kernel/extended/liteipc/hm_liteipc.c  

`LITEIPC_DRIVER` specifies the name of the character device used to communicate with the LiteIPC driver (currently /dev/lite_ipc).

Memory mapping allocates a memory area for storing messages the process receives.  ioctl calls to the driver before it has been memory mapped return with error **ENOMEM**.

The IpcMsg structure is the basic unit of transaction for LiteIPC.
| Member    | Type        | Description |
| --------- | ----------- | ----------- |
| type      | MsgType     | The message's type.  It can be one of the following values **MT_REQUEST**, **MT_REPLY**, **MT_FAILED_REPLY**, **MT_DEATH_NOTIFY**. |
| target    | SvcIdentity | Specifies the message's recipient. |
| flag      | IpcFlag     | Indicates whether the message can be replied to or is one-way.  It can be one of the following values **LITEIPC_FLAG_DEFAULT**, **LITEIPC_FLAG_ONEWAY**. |
| dataSz    | UINT32      | The size of the message data in bytes pointed to by data (cannot exceed IPC_MSG_DATA_SZ_MAX, currently 1024 bytes). |
| data      | void*       | Pointer to the message data. |
| spObjNum  | UINT32      | The number of special objects contained in the message data (cannot exceed IPC_MSG_OBJECT_NUM_MAX). |
| offsets   | void*       | An array of offsets relative to data pointing to SpecialObj special objects in data. |
| code      | UINT32      | Service function code. |
| timestamp | UINT64      | Timestamp for when the message was sent.  Automatically set by the IPC system for requests and death notifications. |
| taskID    | UINT32      | Specifies the message's sender.  Automatically set by the IPC system. |

SpecialObj
| Member  | Type       | Description |
| ------- | ---------- | ----------- |
| type    | ObjType    | The type of special object.  It can be one of the following values **OBJ_FD**, **OBJ_PTR**, **OBJ_SVC**. |
| content | ObjContent | The special object. |

ObjContent
| SpecialObj type | Member | Type        | Description |
| --------------- | ------ | ----------- | ----------- |
| OBJ_FD          | fd     | UINT32      | Currently does nothing. |
| OBJ_PTR         | ptr    | BuffPtr     | Auxiliary data to be sent (not limited by IPC_MSG_DATA_SZ_MAX). |
| OBJ_SVC         | svc    | SvcIdentity | A service to give the recipient permission to send requests to. |

`IPC_SEND_RECV_MSG` is the primary request which provides the ability to send and receive IpcMsg messages as well as free memory used by unneeded messages.  Its argument is a pointer to an IpcContent structure.

IpcContent
| Member     | Type        | Description |
| ---------- | ----------- | ----------- |
| flag       | UINT32      | Specifies the operation(s) to be performed.  It is the bitwise-or of one or more of the following flags **SEND**, **RECV**, **BUFF_FREE**. |
| outMsg     | IpcMsg*     | Points to a message to be sent. |
| inMsg      | IpcMsg*     | Points to a message that has been received. |
| buffToFree | void*       | Points to IPC memory to be freed (a previously received message which is no longer needed). |

- The **SEND** flag indicates a request to send outMsg.  Returns with error **EINVAL** if any member of the message has been given an invalid value.
  - Sending a message with type **MT_REQUEST** returns with error **EACCES** if the task doesn't have access rights to the recipient, and **EINVAL** for an invalid recipient.  All tasks have access rights to the CMS (see IPC_SET_CMS), and to their own process' IPC services.
  - Sending a message with type **MT_REPLY** or **MT_FAILED_REPLY** returns with error **EINVAL** if any of the following are not satisifed:
    - buffToFree must point at the message being replied to and the **BUFF_FREE** flag must be set.
    - The outMsg recipient (target.handle) must match the buffToFree sender (taskID).
    - The outMsg and buffToFree timestamps must match.
    - buffToFree must be a **MT_REQUEST** type message and cannot be marked as **LITEIPC_FLAG_ONEWAY**.
    - buffToFree must be addressed to a service of the current process.

    Trying to reply to a message sent more than LITEIPC_TIMEOUT_NS nanoseconds ago (currently 5 seconds) returns with error **ETIME**.

  The message is copied into memory allocated from the IPC memory area of the process for the recipient task specified by target.handle.  Returns with error **ENOMEM** if the memory cannot be allocated.   Special objects in offsets are then processed.  **OBJ_PTR** objects' data is copied into memory allocated from the recipient's IPC memory area, discards the message and returns with error **EINVAL** if unable to allocate enough memory.  **OBJ_SVC** objects grant the recipient access rights to the service specified by the object if the sender already has access and the service is set as an IPC task (see IPC_SET_IPC_THREAD), discards the message and returns with error **EACCES** if the sender doesn't have access or **EINVAL** if the service isn't running.  Access rights are not revokable, on error any access rights granted before the special object which caused the error will remain.  The message is then added to the tail end of the recipient's list of received messages, the recipient is woken and the scheduler is called.
- The **BUFF_FREE** flag indicates a request to free the memory used by the buffToFree message so it can be used again later for receiving messages.  Returns with error **EFAULT** if buffToFree doesn't point to a received message.  Returns with error **EINVAL** if an invalid address.
- The **RECV** flag indicates a request to receive a message.
  - If the **SEND** flag is set the task will wait for a message for up to LITEIPC_TIMEOUT_MS milliseconds (currently 5 seconds).  Returns with error **ETIME** on timeout.  Messages with a type of **MT_REQUEST** and **MT_REPLY** or **MT_FAILED_REPLY** type messages which don't match outMsg (matching timestamp or matching code and target.token depending on kernel configuration) are discarded (resets timer).  Sets inMsg to point at the received message and removes it from the list of received messages for **MT_REPLY** or **MT_DEATH_NOTIFY** type messages.  Note that receiving  a **MT_DEATH_NOTIFY** makes it impossible to receive the reply so send/receive requests shouldn't be used by services which might receive death notifications.  Discards the message and returns with error **ENOENT** without changing inMsg if the received message has type **MT_FAILED_REPLY**.
  - If the **SEND** flag is not set, the task will sleep until a message with type **MT_REQUEST** or **MT_DEATH_NOTIFY** is received.  Sets inMsg to point at the received message, and removes the message from its list of received messages.  Discards **MT_REPLY** or **MT_FAILED_REPLY** type messages received while waiting.

For a single request the operations are processed in the order **SEND**->**BUFF_FREE**->**RECV** with **BUFF_FREE** being processed even if there was an error in **SEND**.  Error checking on buffToFree occurs before **SEND**, an error in buffToFree will abort the request without doing anything.

The `IPC_SET_IPC_THREAD` request designates the current task as the IPC task for the current process.  It can only be performed once per process.  Returns the ID of the task set as IPC task on success, subsequent calls return with error **EINVAL**.  The IPC task receives the death notifications from IPC services the process has access rights to when those services terminate.  A service which has been set as IPC task can have access rights to itself distributed through special objects without using the CMS.

IPC_SEND_RECV_MSG and IPC_SET_IPC_THREAD both return with error **EINVAL** if the CMS has not been set.

### Internal functions
The first task to use the `IPC_SET_CMS` request sets itself as the system's CMS.  HarmonyOS assigns this role to the distributed scheduler's samgr.  Once set it cannot be changed.  Returns with error **EEXIST** if the CMS has already been set.  Messages are sent to the CMS by setting a recipient handle of 0.  The argument to the request specifies the maximum size of a message sent to the CMS.  Sending a message whose total size including IpcMsg data structure, data size, size of special object offsets, and data in any BuffPtr special objects exceeds the maximum size (currently 256 bytes) returns with error **EINVAL**.

The `IPC_CMS_CMD` request provides various service related utility functions to the CMS.  It can only be used by the CMS, any other task making this request will get an **EACCES** error.  The argument to the request is a pointer to a CmsCmdContent structure.  The cmd member indicates the function to be performed.
- **CMS_GEN_HANDLE** creates a service handle for the task specified by taskID member and stores the handle in the serviceHandle member.  The CMS always has access rights to any created IPC services.
- **CMS_REMOVE_HANDLE** unregisters the service handle specified by the serviceHandle member.
- **CMS_ADD_ACCESS** gives the task specified by the taskID member access rights to the service specified by the serviceHandle member.

LiteIPC includes utility functions for the kernel to manage the IPC system.  
`LiteIpcInit` initializes the IPC system and must be called before it can be used.  
`LiteIpcPoolInit` performs basic initialization of a ProcIpcInfo.  Called by the kernel on task creation to initialize the IPC variables in the task's control block.  
`LiteIpcPoolReInit` initializes the IPC variables of a child task from it's parent's task.  Called by the kernel on the creation of child tasks for basic initialization.  
`LiteIpcPoolDelete` removes a process' IPC memory pool allocated by memory mapping.  Also clears the processes access rights list and removes access to the process from any processes which had access rights to it.  Called by the kernel on process deletion for automatic memory and IPC resource management.  
`LiteIpcRemoveServiceHandle` deregisters a service, clearing out the service task's message list and the list of processes with access rights to the service and sending death notification messages to any services with a set IPC task which had access.  Death notification messages are only sent once, if there is an error in the send (**ENOMEM**) the recipient will not get the death notification.  Death notification messages set target.token to the sevice handle of the service which terminated.  Called by the kernel on task deletion for automatic IPC resource management.  

### Sample code
```
#include "liteipc_adapter.h"
#include "liteipc.h"

int fd = open(LITEIPC_DRIVER, O_RDONLY);
mmap(NULL, 10000, PROT_READ, MAP_PRIVATE, fd, 0);

#define SVCNAME "wakeup service"
IpcMsg msg = {
    .type = MT_REQUEST,
    .target = { 0, 0, 0 },
    .flag = LITEIPC_FLAG_DEFAULT,
    .dataSz = sizeof(SVCNAME),
    .data = SVCNAME,
    .spObjNum = 0,
    .offsets = NULL
};
IpcContent content = {
    .flag = SEND | RECV,
    .outMsg = &msg
};

// Send a message to the CMS
if (ioctl(fd, IPC_SEND_RECV_MSG, &content) < 0) {
    goto ERROR;
}

// Set ourselves as IPC task
int myId = ioctl(fd, IPC_SET_IPC_THREAD, 0);

struct {
    char summary[20];
    BuffPtr command;
    SvcIdentity svc;
} wakeupData = {
    .summary = "one wakeup"
};
char commandStr[100] = "Wake me up at 9:00 in the morning.";
void* wakeupOffsets[2] = {
    (void*)((uintptr_t)&wakeupData.command - (uintptr_t)&wakeupData),
    (void*)((uintptr_t)&wakeupData.svc - (uintptr_t)&wakeupData)
};

// Send a request to the wakeup service and free the CMS's reply
content.flag = SEND | BUFF_FREE;
content.buffToFree = content.inMsg;
msg.type = MT_REQUEST;
// Let's say our CMS gives us access to and returns the handle
// of the service we named in the request we sent to it.
msg.target.handle = *(uint32_t*)content.inMsg->data;
// Add the auxiliary data.
wakeupData.command.buffSz = sizeof(commandStr);
wakeupData.command.buff = commandStr;
// Give the wakeup service access to send us requests.
wakeupData.svc.handle = myId;
msg.data = &wakeupData;
msg.dataSz = sizeof(wakeupData);
msg.offsets = wakeupOffsets;
msg.spObjNum = 2;
if (ioctl(fd, IPC_SEND_RECV_MSG, &content) < 0) {
    goto ERROR;
}

// Enter "server" mode, wait for the service to wake us up.
content.flag = RECV;
ioctl(fd, IPC_SEND_RECV_MSG, &content);

// Free the received message
content.flag = BUFF_FREE;
content.buffToFree = content.inMsg;
ioctl(fd, IPC_SEND_RECV_MSG, &content);

ERROR:
close(fd);
```
