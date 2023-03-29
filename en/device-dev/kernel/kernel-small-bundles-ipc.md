# LiteIPC


## Basic Concepts

LiteIPC is a new inter-process communication (IPC) mechanism provided by the OpenHarmony LiteOS-A kernel. Different from the traditional System V IPC, LiteIPC is designed for Remote Procedure Call (RPC). In addition, it provides APIs for the upper layer through device files, not through traditional API functions.

LiteIPC has two important concepts: ServiceManager and Service. The entire system can have one ServiceManager and multiple Services.

ServiceManager provides the following functions:

- Registers and deregisters services.

- Manages the access permission of services. Only authorized tasks can send IPC messages to the service.


## Working Principles

ServiceManager registers the task that needs to receive IPC messages as a Service, and sets the access permission for the Service task (specifies the tasks that can send IPC messages to the Service).

LiteIPC maintains an IPC message queue for each Service task in kernel mode. The message queue provides the upper-layer user-mode programs with the read operation (receiving IPC messages) and the write operations (sending IPC messages) through LiteIPC device files.


## Development Guidelines


### Available APIs

  **Table 1** APIs of the LiteIPC module (applicable to LiteOS-A only)

| Category     | API Description                                                    |
| ------------- | ------------------------------------------------------------ |
| Module initialization   | **OsLiteIpcInit**: initializes the LiteIPC module.                            |
| IPC message memory pool| - **LiteIpcPoolInit**: initializes the IPC message memory pool of a process.<br>- **LiteIpcPoolReInit**: reinitializes the IPC message memory pool of a process.<br>- **LiteIpcPoolDelete**: releases the IPC message memory pool of a process. |
| Service management  | **LiteIpcRemoveServiceHandle**: deletes a service.               |

> **NOTE**<br>
>  The APIs of the LiteIPC module are dedicated for LiteOS-A internal use only.
