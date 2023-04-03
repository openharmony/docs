# Signal


## Basic Concepts

Signal is a common asynchronous communication mechanism between processes. It uses software-simulated interrupt signals. When a process needs to communicate with another process, it sends a signal to the kernel. The kernel transfers the signal to the target process. The target process does not need to wait for the signal.


## Working Principles

The following table describes the APIs for signal operations.

  **Table 1** Signal APIs (user-mode APIs)

| Category        | API                                       | Description                                                        |
| ---------------- | --------------------------------------------------- | ------------------------------------------------------------ |
| Registering/Unregistering a signal callback| signal                                              | Registers the main signal entry, and registers or unregisters a callback for a signal.              |
| Registering a signal callback| sigaction                                           | Same as **signal**. This API is added with configuration options related to signal transmission. Currently, only some parameters in the **SIGINFO** structure are supported.|
| Sending a signal        | kill<br>pthread_kill<br>raise<br>alarm<br>abort | Sends a signal to a process or sends a message to a thread in a process, and sets the signal flag for a thread in a process. |
| Invoking a callback        | NA                                                 | Called by a system call or an interrupt. Before the switching between the kernel mode and user mode, the callback in the specified function in user mode is processed. After that, the original user-mode program continues to run.|

> **NOTE**<br>
>  The signal mechanism enables communication between user-mode programs. The user-mode POSIX APIs listed in the above table are recommended.
>
>  **Registering a Callback**
>
>
>  ```
>  void *signal(int sig, void (*func)(int))(int);
>  ```
>
>  -  Signal 31 is used to register the handling entry of the process callback. Repeated registration is not allowed.
>
>
>  -  Signals 0 to 30 are used to register and unregister callbacks.
>
>
>  **Registering a Callback**
>
>
>  ```
>  int sigaction(int, const struct sigaction ***restrict, struct sigaction ***restrict);
>  ```
>
>  You can obtain and modify the configuration of signal registration. Currently, only the **SIGINFO** options are supported. For details, see the description of the **sigtimedwait** API.
>
>  **Sending a Signal**
>
>  - Among the default signal-receiving behaviors, the process does not support **STOP**, **COTINUE**, and **COREDUMP** defined in POSIX.
>
>
>  - The **SIGSTOP**, **SIGKILL**, and **SIGCONT** signals cannot be shielded.
>
>
>  - If a process killed is not reclaimed by its parent process, the process becomes a zombie process.
>
>
>  - A process will not call back the signal received until the process is scheduled.
>
>
>  - When a process is killed, **SIGCHLD** is sent to its parent process. The signal sending action cannot be canceled.
>
>
>  - A process in the DELAY state cannot be woken up by a signal.
