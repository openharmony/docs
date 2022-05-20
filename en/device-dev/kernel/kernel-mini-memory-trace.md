# Trace

## Basic Concepts

Trace helps you learn about the kernel running process and the execution sequence of modules and tasks. With the information, you can better understand the code running process of the kernel and locate time sequence problems.

## Working Principles

The kernel provides a hook framework to embed hooks in the main process of each module. In the initial startup phase of the kernel, the trace function is initialized and the trace handlers are registered with the hooks.

When a hook is triggered, the trace module encapsulates the input information and adds the trace frame header information, including the event type, ID of the running CPU, ID of the running task, and relative timestamp.

The trace module provides two working modes: offline mode and online mode.

In offline mode, trace frames are stored in a circular buffer. If too many frames are stored in the circular buffer, earlier frames will be overwritten to ensure that the information in the buffer is always the latest. Data in the circular buffer can be exported by running the shell command for further analysis. The exported information is sorted by timestamp.

![](figures/kernel-small-mode-process.png)

The online mode must be used with the integrated development environment \(IDE\). Trace frames are sent to the IDE in real time. The IDE parses the records and displays them in a visualized manner.

## Available APIs

The trace module of the OpenHarmony LiteOS-M kernel provides the following functions. For more details about the APIs, see the API reference.

**Table  1**  Trace module APIs

<a name="table208266479117"></a>
<table><thead align="left"><tr id="row19826947121114"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7235182719585"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p92241727105816"><a name="p92241727105816"></a><a name="p92241727105816"></a>Starting and stopping trace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p222418279581"><a name="p222418279581"></a><a name="p222418279581"></a>LOS_TraceStart</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p18224112711581"><a name="p18224112711581"></a><a name="p18224112711581"></a>Starts trace.</p>
</td>
</tr>
<tr id="row142340271586"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2224152795812"><a name="p2224152795812"></a><a name="p2224152795812"></a>LOS_TraceStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p722492710584"><a name="p722492710584"></a><a name="p722492710584"></a>Stops trace.</p>
</td>
</tr>
<tr id="row12341278583"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p14224627175816"><a name="p14224627175816"></a><a name="p14224627175816"></a>Managing trace records</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p0224827145816"><a name="p0224827145816"></a><a name="p0224827145816"></a>LOS_TraceRecordDump</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p16224427125810"><a name="p16224427125810"></a><a name="p16224427125810"></a>Exports data in the trace buffer.</p>
</td>
</tr>
<tr id="row14234527185811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p152241327165810"><a name="p152241327165810"></a><a name="p152241327165810"></a>LOS_TraceRecordGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1422412274584"><a name="p1422412274584"></a><a name="p1422412274584"></a>Obtains the start address of the trace buffer.</p>
</td>
</tr>
<tr id="row16234112725816"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p122244272582"><a name="p122244272582"></a><a name="p122244272582"></a>LOS_TraceReset</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1222413276581"><a name="p1222413276581"></a><a name="p1222413276581"></a>Clears events in the trace buffer.</p>
</td>
</tr>
<tr id="row14234727155817"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p19224227205814"><a name="p19224227205814"></a><a name="p19224227205814"></a>Filtering trace records</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1922410277585"><a name="p1922410277585"></a><a name="p1922410277585"></a>LOS_TraceEventMaskSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p122242272585"><a name="p122242272585"></a><a name="p122242272585"></a>Sets the event mask to trace only events of the specified modules.</p>
</td>
</tr>
<tr id="row5234627145818"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p152244272589"><a name="p152244272589"></a><a name="p152244272589"></a>Masking events of specified interrupt IDs</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p182244276586"><a name="p182244276586"></a><a name="p182244276586"></a>LOS_TraceHwiFilterHookReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12224627135819"><a name="p12224627135819"></a><a name="p12224627135819"></a>Registers a hook to filter out events of specified interrupt IDs.</p>
</td>
</tr>
<tr id="row22341027115815"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1222462716588"><a name="p1222462716588"></a><a name="p1222462716588"></a>Performing function instrumentation</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p42242271585"><a name="p42242271585"></a><a name="p42242271585"></a>LOS_TRACE_EASY</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1622416274584"><a name="p1622416274584"></a><a name="p1622416274584"></a>Performs simple instrumentation.</p>
</td>
</tr>
<tr id="row16234627175820"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p622515274583"><a name="p622515274583"></a><a name="p622515274583"></a>LOS_TRACE</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2225527185810"><a name="p2225527185810"></a><a name="p2225527185810"></a>Performs standard instrumentation.</p>
</td>
</tr>
</tbody>
</table>

-   You can perform function instrumentation in the source code to trace specific events. The system provides the following APIs for instrumentation:
    -   **LOS\_TRACE\_EASY\(TYPE, IDENTITY, params...\)**  for simple instrumentation
        -   You only need to insert this API into the source code.
        -   **TYPE**  specifies the event type. The value range is 0 to 0xF. The meaning of each value is user-defined.
        -   **IDENTITY**  specifies the object of the event operation. The value is of the  **UIntPtr**  type.
        -   **Params**  specifies the event parameters. The value is of the  **UIntPtr**  type.
        -   Example:

            ```
            Perform simple instrumentation for reading and writing files fd1 and fd2.
            Set TYPE to 1 for read operations and 2 for write operations.
            Insert the following to the position where the fd1 file is read:
            LOS_TRACE_EASY(1, fd1, flag, size);
            Insert the following to the position where the fd2 file is read:
            LOS_TRACE_EASY(1, fd2, flag, size);
            Insert the following to the position where the fd1 file is written:
            LOS_TRACE_EASY(2, fd1, flag, size);
            Insert the following in the position where the fd2 file is written:
            LOS_TRACE_EASY(2, fd2, flag, size);
            ```

    -   **LOS\_TRACE\(TYPE, IDENTITY, params...\)**  for standard instrumentation.
        -   Compared with simple instrumentation, standard instrumentation supports dynamic event filtering and parameter tailoring. However, you need to extend the functions based on rules.
        -   **TYPE**  specifies the event type. You can define the event type in  **enum LOS\_TRACE\_TYPE**  in the header file  **los\_trace.h**. For details about methods and rules for defining events, see other event types.
        -   The  **IDENTITY**  and  **Params**  are the same as those of simple instrumentation.
        -   Example:

            ```
            1. Set the event mask (module-level event type) in enum LOS_TRACE_MASK.
              Format: TRACE_#MOD#_FLAG (MOD indicates the module name)
              Example:
              TRACE_FS_FLAG = 0x4000
            2. Define the event type in enum LOS_TRACE_TYPE.
              Format: #TYPE# = TRACE_#MOD#_FLAG | NUMBER
              Example:
              FS_READ  = TRACE_FS_FLAG | 0; // Read files
              FS_WRITE = TRACE_FS_FLAG | 1; // Write files
            3. Set event parameters in the #TYPE#_PARAMS(IDENTITY, parma1...) IDENTITY, ... format.
              #TYPE# is the #TYPE# defined in step 2.
              Example:
              #define FS_READ_PARAMS(fp, fd, flag, size)    fp, fd, flag, size
              The parameters defined by the macro correspond to the event parameters recorded in the trace buffer. You can modify the parameters as required.
              If no parameter is specified, events of this type are not traced.
              #define FS_READ_PARAMS(fp, fd, flag, size) // File reading events are not traced.
            4. Insert a code stub in a proper position.
              Format: LOS_TRACE(#TYPE#, #TYPE#_PARAMS(IDENTITY, parma1...))
              LOS_TRACE(FS_READ, fp, fd, flag, size); // Code stub for reading files
              The parameters following #TYPE# are the input parameter of the FS_READ_PARAMS function in step 3.
            ```

            >![](../public_sys-resources/icon-note.gif) **NOTE:** 
            >The trace event types and parameters can be modified as required. For details about the parameters, see  **kernel\\include\\los\_trace.h**.



-   For  **LOS\_TraceEventMaskSet\(UINT32 mask\)**, only the most significant 28 bits \(corresponding to the enable bit of the module in  **LOS\_TRACE\_MASK**\) of the mask take effect and are used only for module-based tracing. Currently, fine-grained event-based tracing is not supported. For example, in  **LOS\_TraceEventMaskSet\(0x202\)**, the effective mask is  **0x200 \(TRACE\_QUE\_FLAG\)**  and all events of the QUE module are collected. The recommended method is  **LOS\_TraceEventMaskSet\(TRACE\_EVENT\_FLAG | TRACE\_MUX\_FLAG | TRACE\_SEM\_FLAG | TRACE\_QUE\_FLAG\);**.
-   To enable trace of only simple instrumentation events, set  **Trace Mask**  to  **TRACE\_MAX\_FLAG**.
-   The trace buffer has limited capacity. When the trace buffer is full, events will be overwritten. You can use  **LOS\_TraceRecordDump**  to export data from the trace buffer and locate the latest records by  **CurEvtIndex**.
-   The typical trace operation process includes  **LOS\_TraceStart**,  **LOS\_TraceStop**, and  **LOS\_TraceRecordDump**.
-   You can filter out interrupt events by interrupt ID to prevent other events from being overwritten due to frequent triggering of a specific interrupt in some scenarios. You can customize interrupt filtering rules.

    The sample code is as follows:

    ```
    BOOL Example_HwiNumFilter(UINT32 hwiNum)
    {
           if ((hwiNum == TIMER_INT) || (hwiNum == DMA_INT)) {
            return TRUE;
        }
        return FALSE;
    }
    LOS_TraceHwiFilterHookReg(Example_HwiNumFilter);
    ```

    The interrupt events with interrupt ID of  **TIMER\_INT**  or  **DMA\_INT**  are not traced.


## Development Guidelines

### How to Develop

The typical trace process is as follows:

1.  Configure the macro related to the trace module.

    Modify the configuration in the  **target\_config.h**  file.

    <a name="table86631147151516"></a>
    <table><thead align="left"><tr id="row5664134715156"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p1466404761518"><a name="p1466404761518"></a><a name="p1466404761518"></a>Configuration</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p18664347131518"><a name="p18664347131518"></a><a name="p18664347131518"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p166413478159"><a name="p166413478159"></a><a name="p166413478159"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22591620121620"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p225117203162"><a name="p225117203162"></a><a name="p225117203162"></a>LOSCFG_KERNEL_TRACE</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p72519205167"><a name="p72519205167"></a><a name="p72519205167"></a>Specifies whether to enable the trace feature.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p925182081614"><a name="p925182081614"></a><a name="p925182081614"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row4259182012168"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p72515204168"><a name="p72515204168"></a><a name="p72515204168"></a>LOSCFG_RECORDER_MODE_OFFLINE</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p4251620111614"><a name="p4251620111614"></a><a name="p4251620111614"></a>Specifies whether to enable the online trace mode.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p425162020167"><a name="p425162020167"></a><a name="p425162020167"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1825902061611"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p122511220191613"><a name="p122511220191613"></a><a name="p122511220191613"></a>LOSCFG_RECORDER_MODE_ONLINE</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p7251192018169"><a name="p7251192018169"></a><a name="p7251192018169"></a>Specifies whether to enable the offline trace mode.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1225115205163"><a name="p1225115205163"></a><a name="p1225115205163"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row3259152015163"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p225118205169"><a name="p225118205169"></a><a name="p225118205169"></a>LOSCFG_TRACE_CLIENT_INTERACT</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p225182016163"><a name="p225182016163"></a><a name="p225182016163"></a>Specifies whether to enable interaction with Trace IDE (dev tools), including data visualization and process control.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p182512208167"><a name="p182512208167"></a><a name="p182512208167"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row02591120201618"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p82511920101615"><a name="p82511920101615"></a><a name="p82511920101615"></a>LOSCFG_TRACE_FRAME_CORE_MSG</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p425192015165"><a name="p425192015165"></a><a name="p425192015165"></a>Specifies whether to enable recording of the CPU ID, interruption state, and lock task state.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1925119204166"><a name="p1925119204166"></a><a name="p1925119204166"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1525916202166"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p3251162017161"><a name="p3251162017161"></a><a name="p3251162017161"></a>LOSCFG_TRACE_FRAME_EVENT_COUNT</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p18251142021619"><a name="p18251142021619"></a><a name="p18251142021619"></a>Specifies whether to enables recording of the event sequence number.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1251020171616"><a name="p1251020171616"></a><a name="p1251020171616"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1025920204167"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p2025172010166"><a name="p2025172010166"></a><a name="p2025172010166"></a>LOSCFG_TRACE_FRAME_MAX_PARAMS</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p172511020141611"><a name="p172511020141611"></a><a name="p172511020141611"></a>Specifies the maximum number of parameters for event recording.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p12251182041610"><a name="p12251182041610"></a><a name="p12251182041610"></a>INT</p>
    </td>
    </tr>
    <tr id="row225982091614"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1725114206168"><a name="p1725114206168"></a><a name="p1725114206168"></a>LOSCFG_TRACE_BUFFER_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p4251142014161"><a name="p4251142014161"></a><a name="p4251142014161"></a>Specifies the trace buffer size.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p2251152014162"><a name="p2251152014162"></a><a name="p2251152014162"></a>INT</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  \(Optional\) Preset event parameters and stubs \(or use the default event parameter settings and event stubs\).
3.  \(Optional\) Call  **LOS\_TraceStop**  to stop trace and call  **LOS\_TraceReset**  to clear the trace buffer. \(Trace is started by default.\)
4.  \(Optional\) Call  **LOS\_TraceEventMaskSet**  to set the event mask for trace \(only the interrupts and task events are enabled by default\). For details about the event mask, see  **LOS\_TRACE\_MASK**  in  **los\_trace.h**.
5.  Call  **LOS\_TraceStart**  at the start of the code where the event needs to be traced.
6.  Call  **LOS\_TraceStop**  at the end of the code where the event needs to be traced.
7.  Call  **LOS\_TraceRecordDump**  to output the data in the buffer. \(The input parameter of the function is of the Boolean type. The value  **FALSE**  means to output data in the specified format, and the value  **TRUE**  means to output data to a Windows client.\)

The methods in steps 3 to 7 are encapsulated with shell commands. After the shell is enabled, the corresponding commands can be executed. The mapping is as follows:

-   LOS\_TraceReset —— trace\_reset
-   LOS\_TraceEventMaskSet —— trace\_mask
-   LOS\_TraceStart —— trace\_start
-   LOS\_TraceStop —— trace\_stop
-   LOS\_TraceRecordDump —— trace\_dump

### Development Example

This example implements the following:

1.  Create a trace task.
2.  Set the event mask.
3.  Start trace.
4.  Stop trace.
5.  Output trace data in the specified format.

### Sample Code

The sample code is as follows:

```
#include "los_trace.h"
UINT32 g_traceTestTaskId;
VOID Example_Trace(VOID)
{ 
    UINT32 ret;    
    LOS_TaskDelay(10);
    /* Start trace. */
    ret = LOS_TraceStart();    
    if (ret != LOS_OK) {        
        dprintf("trace start error\n");        
        return;    
    }    
 /* Trigger a task switching event.*/
    LOS_TaskDelay(1);    
    LOS_TaskDelay(1);    
    LOS_TaskDelay(1);    
 /* Stop trace.*/
    LOS_TraceStop();    
    LOS_TraceRecordDump(FALSE);
}
UINT32 Example_Trace_test(VOID){
    UINT32 ret;    
    TSK_INIT_PARAM_S traceTestTask;
 /* Create a trace task. */
    memset(&traceTestTask, 0, sizeof(TSK_INIT_PARAM_S));    
    traceTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Trace;    
 traceTestTask.pcName = "TestTraceTsk"; /* Trace task name*/
    traceTestTask.uwStackSize  = 0x800;    
    traceTestTask.usTaskPrio   = 5;    
    traceTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;    
    ret = LOS_TaskCreate(&g_traceTestTaskId, &traceTestTask);    
    if(ret != LOS_OK){        
        dprintf("TraceTestTask create failed .\n");        
        return LOS_NOK;    
    }    
 /* Trace is started by default. Therefore, you can stop trace, clear the buffer, and then restart trace. */
    LOS_TraceStop();    
    LOS_TraceReset();    
 /* Enable trace of the Task module events. */
    LOS_TraceEventMaskSet(TRACE_TASK_FLAG);    
    return LOS_OK;
}
```

### Verification

The output is as follows:

```
*******TraceInfo begin*******
clockFreq = 50000000
CurEvtIndex = 7
Index   Time(cycles)      EventType      CurTask   Identity      params    
0       0x366d5e88        0x45           0x1       0x0           0x1f         0x4       0x0
1       0x366d74ae        0x45           0x0       0x1           0x0          0x8       0x1f
2       0x36940da6        0x45           0x1       0xc           0x1f         0x4       0x9
3       0x3694337c        0x45           0xc       0x1           0x9          0x8       0x1f
4       0x36eea56e        0x45           0x1       0xc           0x1f         0x4       0x9
5       0x36eec810        0x45           0xc       0x1           0x9          0x8       0x1f
6       0x3706f804        0x45           0x1       0x0           0x1f         0x4       0x0
7       0x37070e59        0x45           0x0       0x1           0x0          0x8       0x1f
*******TraceInfo end*******
```

The output event information includes the occurrence time, event type, task in which the event occurs, object of the event operation, and other parameters of the event.

-   **EventType**: event type. For details, see  **enum LOS\_TRACE\_TYPE**  in the header file  **los\_trace.h**.
-   **CurrentTask**: ID of the running task.
-   **Identity**: object of the event operation. For details, see  **\#TYPE\#\_PARAMS**  in the header file  **los\_trace.h**.
-   **params**: event parameters. For details, see  **\#TYPE\#\_PARAMS**  in the header file  **los\_trace.h**.

The following uses output No. 0 as an example.

```
Index   Time(cycles)      EventType      CurTask   Identity      params
0       0x366d5e88        0x45           0x1       0x0           0x1f         0x4
```

-   **Time \(cycles\)**  can be converted into time \(in seconds\) by dividing the cycles by clockFreq.
-   **0x45**  indicates the task switching event.  **0x1**  is the ID of the task in running. 
-   For details about the meanings of  **Identity**  and  **params**, see the  **TASK\_SWITCH\_PARAMS**  macro.

```
#define TASK_SWITCH_PARAMS(taskId, oldPriority, oldTaskStatus, newPriority, newTaskStatus) \
taskId, oldPriority, oldTaskStatus, newPriority, newTaskStatus
```

Because of  **\#TYPE\#\_PARAMS\(IDENTITY, parma1...\) IDENTITY, ...**,  **Identity**  is  **taskId \(0x0\)**  and the first parameter is  **oldPriority \(0x1f\)**.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The number of parameters in  **params**  is specified by the  **LOSCFG\_TRACE\_FRAME\_MAX\_PARAMS**  parameter. The default value is  **3**. Excess parameters are not recorded. You need to set  **LOSCFG\_TRACE\_FRAME\_MAX\_PARAMS**  based on service requirements.

Task 0x1 is switched to Task 0x0. The priority of task 0x1 is  **0x1f**, and the state is  **0x4**. The priority of the task 0x0 is  **0x0**.

