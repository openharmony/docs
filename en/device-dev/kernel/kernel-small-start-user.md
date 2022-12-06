# Startup in User Mode

## Startup of the Root Process in User Mode<a name="section79911135647"></a>

The root process is the first user-mode process in the system. The process ID is 1. The root process is the ancestor of all user-mode processes.

**Figure  1**  Process tree<a name="fig427516409375"></a>  
![](figures/process-tree.png "process-tree")

### Startup Process of the Root Process<a name="section1184317581349"></a>

Use the link script to place the following init startup code to the specified location in the system image.

```
#define LITE_USER_SEC_ENTRY   __attribute__((section(".user.entry")))
LITE_USER_SEC_ENTRY VOID OsUserInit(VOID *args)
{
#ifdef LOSCFG_KERNEL_DYNLOAD
    sys_call3(__NR_execve, (UINTPTR)g_initPath, 0, 0);
#endif
    while (true) {
    }
}
```

During system startup,  **OsUserInitProcess**  is called to start the  **init**  process. The procedure is as follows:

1.  The kernel calls  **OsLoadUserInit**  to load the code.
2.  A process space is created to start the  **/bin/init**  process.

### Responsibilities of the Root Process<a name="section1590220321759"></a>

-   Starts key system programs or services, such as shell.

    >![](../public_sys-resources/icon-note.gif) **NOTE**
    >
    >In OpenHarmony, the  **init**  process reads the  **/etc/init.cfg**  file and runs specified commands or starts specified processes based on configurations. For details, see [init Module](../subsystems/subsys-boot-init-cfg.md).


-   Monitors the process for reclaiming the orphan process and clears the zombie processes in child processes.

## Running Programs in User Mode<a name="section194576310611"></a>


A user-mode program can be started in either of the following ways:

-   Run the shell command to start the process.

    ```
    OHOS $ exec helloworld
    OHOS $ ./helloworld
    OHOS $ /bin/helloworld
    ```


-   Start a new process by calling the POSIX API.

    Use the  **Fork\(\)**  method to create a process, and call the  **exec\(\)**  method to execute a new process.


