# Exception Debugging

## Basic Concepts

The OpenHarmony LiteOS-M provides exception handling and debugging measures to help locate and analyze problems. Exception handling involves a series of actions taken by the OS to respond to exceptions occurred during the OS running, for example, printing the exception type, system status, call stack information of the current function, CPU information, and call stack information of tasks.

## Working Principles

A stack frame contains information such as function parameters, variables, and return value in a function call process. When a function is called, a stack frame of the subfunction is created, and the input parameters, local variables, and registers of the function are stored into the stack. Stack frames grow towards lower addresses. The ARM32 CPU architecture is used as an example. Each stack frame stores the historical values of the program counter \(PC\), LR \(link register\), stack pointer \(SP\), and frame pointer \(FP\) registers. The LR points to the return address of a function, and the FP points to the start address of the stack frame of the function's parent function. The FP helps locate the parent function's stack frame, which further helps locate the parent function's FP. The parent function's FP helps locate the grandparent function's stack frame and FP... In this way, the call stack of the program can be traced to obtain the relationship between the functions called.

When an exception occurs in the system, the system prints the register information in the stack frame of the abnormal function as well as the LRs and FPs in the stack frames of its parent function and grandfather function. The relationships between the functions help you locate the cause of the exception.

The following figure illustrates the stack analysis mechanism for your reference. The actual stack information varies depending on the CPU architecture.

**Figure  1**  Stack analysis mechanism
![](figures/stack-analysis-mechanism.png "stack-analysis-mechanism")

In the figure, the registers in different colors indicate different functions. The registers save related data when functions are called. The FP register helps track the stack to the parent function of the abnormal function and further presents the relationships between the functions called.

## Available APIs

The following table describes APIs available for the OpenHarmony LiteOS-M stack trace module. For more details about the APIs, see the API reference.

**Table  1**  APIs of the stack trace module

<a name="table1415203765610"></a>
<table><thead align="left"><tr id="row134151837125611"><th class="cellrowborder" valign="top" width="12.85128512851285%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="29.8029802980298%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1841519376561"><td class="cellrowborder" rowspan="2" valign="top" width="12.85128512851285%" headers="mcps1.2.4.1.1 "><p id="p294964222410"><a name="p294964222410"></a><a name="p294964222410"></a>Stack trace</p>
</td>
<td class="cellrowborder" valign="top" width="29.8029802980298%" headers="mcps1.2.4.1.2 "><p id="p4166128181614"><a name="p4166128181614"></a><a name="p4166128181614"></a>LOS_BackTrace</p>
</td>
<td class="cellrowborder" valign="top" width="57.34573457345735%" headers="mcps1.2.4.1.3 "><p id="p1516617282165"><a name="p1516617282165"></a><a name="p1516617282165"></a>Prints the call stack relationship at the function calling point.</p>
</td>
</tr>
<tr id="row1187514443616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p682431610715"><a name="p682431610715"></a><a name="p682431610715"></a>LOS_RecordLR</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4969192715710"><a name="p4969192715710"></a><a name="p4969192715710"></a>Obtains the call stack relationship at the function calling point when print is unavailable.</p>
</td>
</tr>
</tbody>
</table>

## Usage Guidelines

### How to Develop

The typical process for enabling exception debugging is as follows:

1.  Configure the macros related to exception handling.

    Modify the configuration in the  **target\_config.h**  file.

    <a name="table1078714915105"></a>
    <table><thead align="left"><tr id="row1280518971010"><th class="cellrowborder" valign="top" width="20.1%" id="mcps1.1.4.1.1"><p id="p1380510912104"><a name="p1380510912104"></a><a name="p1380510912104"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.47%" id="mcps1.1.4.1.2"><p id="p08051291106"><a name="p08051291106"></a><a name="p08051291106"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.43%" id="mcps1.1.4.1.3"><p id="p12805149151012"><a name="p12805149151012"></a><a name="p12805149151012"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row168052913104"><td class="cellrowborder" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p180618915101"><a name="p180618915101"></a><a name="p180618915101"></a>LOSCFG_BACKTRACE_DEPTH</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.47%" headers="mcps1.1.4.1.2 "><p id="p198061196105"><a name="p198061196105"></a><a name="p198061196105"></a>Depth of the function call stack. The default value is <strong id="b1041811416176"><a name="b1041811416176"></a><a name="b1041811416176"></a>15</strong>.</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.43%" headers="mcps1.1.4.1.3 "><p id="p1980609121010"><a name="p1980609121010"></a><a name="p1980609121010"></a>15</p>
    </td>
    </tr>
    <tr id="row4806990105"><td class="cellrowborder" valign="top" width="20.1%" headers="mcps1.1.4.1.1 "><p id="p18940141181618"><a name="p18940141181618"></a><a name="p18940141181618"></a>LOSCFG_BACKTRACE_TYPE</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.47%" headers="mcps1.1.4.1.2 "><p id="p280620917109"><a name="p280620917109"></a><a name="p280620917109"></a>Type of the stack trace.</p>
    <p id="p9133142211184"><a name="p9133142211184"></a><a name="p9133142211184"></a><strong id="b9882230181814"><a name="b9882230181814"></a><a name="b9882230181814"></a>0</strong>: disabled</p>
    <p id="p1133122212183"><a name="p1133122212183"></a><a name="p1133122212183"></a><strong id="b1863620373182"><a name="b1863620373182"></a><a name="b1863620373182"></a>1</strong>: supports function call stack analysis of the Cortex-m series hardware.</p>
    <p id="p1133822101814"><a name="p1133822101814"></a><a name="p1133822101814"></a><strong id="b106211355191914"><a name="b106211355191914"></a><a name="b106211355191914"></a>2</strong>: supports function call stack analysis of the RISC-V series hardware.</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.43%" headers="mcps1.1.4.1.3 "><p id="p780614919107"><a name="p780614919107"></a><a name="p780614919107"></a>Set this parameter to <strong id="b1926720398209"><a name="b1926720398209"></a><a name="b1926720398209"></a>1</strong> or <strong id="b149341042172017"><a name="b149341042172017"></a><a name="b149341042172017"></a>2</strong> based on the toolchain type.</p>
    </td>
    </tr>
    </tbody>
    </table>


1.  Use the error code in the example to build and run a project, and check the error information displayed on the serial port terminal. The sample code simulates error code. During actual product development, use the exception debugging mechanism to locate exceptions.

    The following example demonstrates the exception output through a task. The task entry function simulates calling of multiple functions and finally calls a function that simulates an exception. The sample code is as follows:

    ```
    #include <stdio.h>
    #include "los_config.h"
    #include "los_interrupt.h"
    #include "los_task.h"
    
    UINT32 g_taskExcId;
    #define TSK_PRIOR 4
    
    /* Simulate an abnormal function. */
    
    UINT32 Get_Result_Exception_0(UINT16 dividend){
        UINT32 divisor = 0;
        UINT32 result = dividend / divisor;
        return result;
    }
    
    UINT32 Get_Result_Exception_1(UINT16 dividend){
        return Get_Result_Exception_0(dividend);
    }
    
    UINT32 Get_Result_Exception_2(UINT16 dividend){
        return Get_Result_Exception_1(dividend);
    }
    
    UINT32 Example_Exc(VOID)
    {
        UINT32 ret;
    
        printf("Enter Example_Exc Handler.\r\n");
    
        /* Simulate the function calling. */
        ret = Get_Result_Exception_2(TSK_PRIOR);
        printf("Divided result =%u.\r\n", ret);
    
        printf("Exit Example_Exc Handler.\r\n");
        return ret;
    }
    
    
    /* Task entry function used to create a task with an exception. */
    UINT32 Example_Exc_Entry(VOID)
    {
        UINT32 ret;
        TSK_INIT_PARAM_S initParam;
    
        /* Lock task scheduling to prevent newly created tasks from being scheduled prior to this task due to higher priority.*/
        LOS_TaskLock();
    
        printf("LOS_TaskLock() Success!\r\n");
    
        initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Exc;
        initParam.usTaskPrio = TSK_PRIOR;
        initParam.pcName = "Example_Exc";
        initParam.uwStackSize = LOSCFG_SECURE_STACK_DEFAULT_SIZE;
        /* Create a task with higher priority. The task will not be executed immediately after being created, because task scheduling is locked.*/
        ret = LOS_TaskCreate(&g_taskExcId, &initParam);
        if (ret != LOS_OK) {
            LOS_TaskUnlock();
    
            printf("Example_Exc create Failed!\r\n");
            return LOS_NOK;
        }
    
        printf("Example_Exc create Success!\r\n");
    
        /* Unlock task scheduling. The task with the highest priority in the Ready queue will be executed.*/
        LOS_TaskUnlock();
    
        return LOS_OK;
    }
    ```


1.  The error information displayed on the serial port terminal is as follows:

    ```
    entering kernel init...
    LOS_TaskLock() Success!
    Example_Exc create Success!
    Entering scheduler
    Enter Example_Exc Handler.
    *************Exception Information**************
    Type      = 10
    ThrdPid   = 4
    Phase     = exc in task
    FaultAddr = 0xabababab
    Current task info:
    Task name = Example_Exc
    Task ID   = 4
    Task SP   = 0x200051ac
    Task ST   = 0x20004ff0
    Task SS   = 0x200
    Exception reg dump:
    PC        = 0x80037da
    LR        = 0x80037fe
    SP        = 0x20005190
    R0        = 0x4
    R1        = 0x40
    R2        = 0x4
    R3        = 0x0
    R4        = 0x4040404
    R5        = 0x5050505
    R6        = 0x6060606
    R7        = 0x20005190
    R8        = 0x8080808
    R9        = 0x9090909
    R10       = 0x10101010
    R11       = 0x11111111
    R12       = 0x12121212
    PriMask   = 0x0
    xPSR      = 0x41000000
    ----- backtrace start -----
    backtrace 0 -- lr = 0x800381a
    backtrace 1 -- lr = 0x8003836
    backtrace 2 -- lr = 0x8005a4e
    backtrace 3 -- lr = 0x8000494
    backtrace 4 -- lr = 0x8008620
    backtrace 5 -- lr = 0x800282c
    backtrace 6 -- lr = 0x80008a0
    backtrace 7 -- lr = 0x80099f8
    backtrace 8 -- lr = 0x800a01a
    backtrace 9 -- lr = 0x800282c
    backtrace 10 -- lr = 0x80008a0
    backtrace 11 -- lr = 0x80099f8
    backtrace 12 -- lr = 0x8009bf0
    backtrace 13 -- lr = 0x8009c52
    backtrace 14 -- lr = 0x80099aa
    ----- backtrace end -----
    
    TID  Priority   Status     StackSize    WaterLine    StackPoint  TopOfStack   EventMask  SemID  name
    ---  --------   --------   ---------    ----------   ----------  ----------   ---------  -----  ----
    0    0    Pend    0x2d0    0x104    0x200029bc    0x200027f0    0x0    0xffff    Swt_Task
    1    31    Ready    0x500    0x44    0x20002f84    0x20002ac8    0x0    0xffff    IdleCore000
    2    6    Ready    0x1000    0x44    0x20003f94    0x20002fd8    0x0    0xffff    TaskSampleEntry1
    3    7    Ready    0x1000    0x44    0x20004f9c    0x20003fe0    0x0    0xffff    TaskSampleEntry2
    4    4    Running    0x200    0xec    0x200051ac    0x20004ff0    0x0    0xffff    Example_Exc
    
    OS exception NVIC dump:
    interrupt enable register, base address: 0xe000e100, size: 0x20
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    interrupt pending register, base address: 0xe000e200, size: 0x20
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    interrupt active register, base address: 0xe000e300, size: 0x20
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    interrupt priority register, base address: 0xe000e400, size: 0xf0
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
    interrupt exception register, base address: 0xe000ed18, size: 0xc
    0x0 0x0 0xf0f00000 
    interrupt shcsr register, base address: 0xe000ed24, size: 0x4
    0x70008 
    interrupt control register, base address: 0xe000ed04, size: 0x4
    0x400f806 
    
    memory pools check:
    system heap memcheck over, all passed!
    memory pool check end!
    ```


### How to Locate Exceptions

The procedure for locating the exception is as follows:

1.  Open the image disassembly file \(.asm\) generated after compilation. If the file is not generated by default, use the objdump tool to generate it. Run the following command:

    ```
     arm-none-eabi-objdump -S -l XXX.elf
    ```


1.  Search for the PC \(pointing to the instruction being executed\) in the ASM file to locate the abnormal function.

    The PC address directs to the instruction being executed when the exception occurs. In the ASM file corresponding to the currently executed binary file, search for the PC value  **0x80037da**  and locate the instruction being executed by the CPU. Disassemble the code as follows:

    ```
    UINT32 Get_Result_Exception_0(UINT16 dividend){
     80037c8: b480       push {r7}
     80037ca: b085       sub sp, #20
     80037cc: af00       add r7, sp, #0
     80037ce: 4603       mov r3, r0
     80037d0: 80fb       strh r3, [r7, #6]
    kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:10
        UINT32 divisor = 0;
     80037d2: 2300       movs r3, #0
     80037d4: 60fb       str r3, [r7, #12]
    kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:11
        UINT32 result = dividend / divisor;
     80037d6: 88fa       ldrh r2, [r7, #6]
     80037d8: 68fb       ldr r3, [r7, #12]
     80037da: fbb2 f3f3  udiv r3, r2, r3
     80037de: 60bb       str r3, [r7, #8]
    ```


1.  <a name="li18973161743110"></a>As indicated by the code:
    1.  When the exception occurs, the CPU is executing  **udiv  r3, r2, r3**. The value of  **r3**  is  **0**, which causes the divide-by-zero error.
    2.  The exception occurs in the  **Get\_Result\_Exception\_0**  function.

2.  Locate the parent function of the abnormal function based on the LR value.

    The code disassembly of the LR value  **0x80037fe**  is as follows:

    ```
    080037ec <Get_Result_Exception_1>:
    Get_Result_Exception_1():
    kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:15
    UINT32 Get_Result_Exception_1(UINT16 dividend){
     80037ec: b580       push {r7, lr}
     80037ee: b082       sub sp, #8
     80037f0: af00       add r7, sp, #0
     80037f2: 4603       mov r3, r0
     80037f4: 80fb       strh r3, [r7, #6]
    kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:16
        return Get_Result_Exception_0(dividend);
     80037f6: 88fb       ldrh r3, [r7, #6]
     80037f8: 4618       mov r0, r3
     80037fa: f7ff ffe5  bl 80037c8 <Get_Result_Exception_0>
     80037fe: 4603       mov r3, r0
    ```


1.  The previous line of LR  **80037fe**  is  **bl	80037c8 <Get\_Result\_Exception\_0\>**, which calls the abnormal function. The parent function that calls the abnormal function is  **Get\_Result\_Exception\_1\(\)**.
2.  Repeat  [3](#li18973161743110)  to analyze the LR values between  **backtrace start**  and  **backtrace end**  in the exception information to obtain the call stack relationship and find the exception cause.

