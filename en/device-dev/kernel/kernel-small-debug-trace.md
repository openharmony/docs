# Trace

## Basic Concepts<a name="section531482192018"></a>

Trace helps you learn about the kernel running process and the execution sequence of modules and tasks. With the information, you can better understand the code running process of the kernel and locate time sequence problems.

## Working Principles<a name="section5125124532010"></a>

The kernel provides a hook framework to embed hooks in the main process of each module. In the initial startup phase of the kernel, the trace function is initialized and the trace handlers are registered with the hooks.

When a hook is triggered, the trace module encapsulates the input information and adds the trace frame header information, including the event type, ID of the running CPU, ID of the running task, and relative timestamp.

The trace module provides two working modes: offline mode and online mode.

In offline mode, trace frames are stored in a circular buffer. If too many frames are stored in the circular buffer, earlier frames will be overwritten to ensure that the information in the buffer is always the latest. Data in the circular buffer can be exported by running the shell command for further analysis. The exported information is sorted by timestamp.

![](figures/kernel-small-mode-process-4.png)

The online mode must be used with the integrated development environment \(IDE\). Trace frames are sent to the IDE in real time. The IDE parses the records and displays them in a visualized manner.

## **Available APIs**<a name="section17747184017458"></a>

### Kernel Mode<a name="section104473014465"></a>

The trace module of the OpenHarmony LiteOS-A kernel provides the following functions. For details about the APIs, see the  [API](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_trace.h)  reference.

**Table  1**  Trace module APIs

<a name="table1290750144615"></a>
<table><thead align="left"><tr id="row92916507464"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1429185074615"><a name="p1429185074615"></a><a name="p1429185074615"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1729115010467"><a name="p1729115010467"></a><a name="p1729115010467"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p12911501463"><a name="p12911501463"></a><a name="p12911501463"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9287279472"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12191827104720"><a name="p12191827104720"></a><a name="p12191827104720"></a>Starting and stopping trace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1519152774719"><a name="p1519152774719"></a><a name="p1519152774719"></a>LOS_TraceStart</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p619102714475"><a name="p619102714475"></a><a name="p619102714475"></a>Starts trace.</p>
</td>
</tr>
<tr id="row17281727204713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p519162715477"><a name="p519162715477"></a><a name="p519162715477"></a>LOS_TraceStop</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p12191827164710"><a name="p12191827164710"></a><a name="p12191827164710"></a>Stops trace.</p>
</td>
</tr>
<tr id="row428102714719"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1019327194717"><a name="p1019327194717"></a><a name="p1019327194717"></a>Managing trace records</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1319142714474"><a name="p1319142714474"></a><a name="p1319142714474"></a>LOS_TraceRecordDump</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p0192275474"><a name="p0192275474"></a><a name="p0192275474"></a>Exports data in the trace buffer.</p>
</td>
</tr>
<tr id="row192852794713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1419827104715"><a name="p1419827104715"></a><a name="p1419827104715"></a>LOS_TraceRecordGet</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1619162715479"><a name="p1619162715479"></a><a name="p1619162715479"></a>Obtains the start address of the trace buffer.</p>
</td>
</tr>
<tr id="row172882764719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1019527134714"><a name="p1019527134714"></a><a name="p1019527134714"></a>LOS_TraceReset</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1619192720473"><a name="p1619192720473"></a><a name="p1619192720473"></a>Clears events in the trace buffer.</p>
</td>
</tr>
<tr id="row82715275472"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1419122716473"><a name="p1419122716473"></a><a name="p1419122716473"></a>Filtering trace records</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p121917278472"><a name="p121917278472"></a><a name="p121917278472"></a>LOS_TraceEventMaskSet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1419927154711"><a name="p1419927154711"></a><a name="p1419927154711"></a>Sets the event mask to trace only events of the specified modules.</p>
</td>
</tr>
<tr id="row827827174718"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p9201275471"><a name="p9201275471"></a><a name="p9201275471"></a>Masking events of specified interrupt IDs</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p720112717476"><a name="p720112717476"></a><a name="p720112717476"></a>LOS_TraceHwiFilterHookReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p192042713475"><a name="p192042713475"></a><a name="p192042713475"></a>Registers a hook to filter out events of specified interrupt IDs.</p>
</td>
</tr>
<tr id="row42714279476"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p172011270476"><a name="p172011270476"></a><a name="p172011270476"></a>Performing function instrumentation</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1120122754714"><a name="p1120122754714"></a><a name="p1120122754714"></a>LOS_TRACE_EASY</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12032714717"><a name="p12032714717"></a><a name="p12032714717"></a>Performs simple instrumentation.</p>
</td>
</tr>
<tr id="row1927122734715"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p52062712478"><a name="p52062712478"></a><a name="p52062712478"></a>LOS_TRACE</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p182062734713"><a name="p182062734713"></a><a name="p182062734713"></a>Performs standard instrumentation.</p>
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

            Example:

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

            Example:

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

### User Mode<a name="section1996920294531"></a>

The trace character device is added in  **/dev/trace**. You can use  **read\(\)**,  **write\(\)**, and  **ioctl\(\)**  on the device node to read, write, and control trace in user mode.

-   **read\(\)**: reads the trace data in user mode.
-   **write\(\)**: writes an event in user mode.
-   **ioctl\(\)**: performs user-mode trace operations, including:

```
#define TRACE_IOC_MAGIC   'T'
#define TRACE_START      _IO(TRACE_IOC_MAGIC, 1)
#define TRACE_STOP       _IO(TRACE_IOC_MAGIC, 2)
#define TRACE_RESET      _IO(TRACE_IOC_MAGIC, 3)
#define TRACE_DUMP		 _IO(TRACE_IOC_MAGIC, 4)
#define TRACE_SET_MASK	 _IO(TRACE_IOC_MAGIC, 5)
```

The operations specified by the input parameter of  **ioctl\(\)**  correspond to  **LOS\_TraceStart**,  **LOS\_TraceStop**,  **LOS\_TraceReset**,  **LOS\_TraceRecordDump**, and  **LOS\_TraceEventMaskSet**, respectively.

For more details, see  [User-mode Programming Example](https://gitee.com/openharmony/docs/blob/70744e1e0e34d66e11108a00c8db494eea49dd02/en/device-dev/kernel/kernel-small-debug-trace.md#section4.2.2).

## Development Guidelines<a name="section10302175017543"></a>

### Kernel-mode Development Process<a name="section04021008552"></a>

The typical trace process is as follows:

1.  Configure the macro related to the trace module.

    Configure the trace macro  **LOSCFG\_KERNEL\_TRACE**, which is disabled by default. Run the  **make update\_config**  command in the  **kernel/liteos\_a**  directory, choose  **Kernel**  \>  **Enable Hook Feature**, and set  **Enable Trace Feature**  to  **YES**.

    <a name="table16145182665619"></a>
    <table><thead align="left"><tr id="row16145192611566"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p18145726175614"><a name="p18145726175614"></a><a name="p18145726175614"></a>Configuration</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p15145162613562"><a name="p15145162613562"></a><a name="p15145162613562"></a>menuconfig Option</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p111451263569"><a name="p111451263569"></a><a name="p111451263569"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p12145112616562"><a name="p12145112616562"></a><a name="p12145112616562"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5318402576"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p330560125717"><a name="p330560125717"></a><a name="p330560125717"></a>LOSCFG_KERNEL_TRACE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p83051406576"><a name="p83051406576"></a><a name="p83051406576"></a>Enable Trace Feature</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1530512018572"><a name="p1530512018572"></a><a name="p1530512018572"></a>Specifies whether to enable the trace feature.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p123051600573"><a name="p123051600573"></a><a name="p123051600573"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row1731810085715"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1930514019579"><a name="p1930514019579"></a><a name="p1930514019579"></a>LOSCFG_RECORDER_MODE_OFFLINE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1830511011573"><a name="p1830511011573"></a><a name="p1830511011573"></a>Trace work mode -&gt;Offline mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p23051509577"><a name="p23051509577"></a><a name="p23051509577"></a>Specifies whether to enable the online trace mode.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p630514085717"><a name="p630514085717"></a><a name="p630514085717"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row13189005711"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1305110165716"><a name="p1305110165716"></a><a name="p1305110165716"></a>LOSCFG_RECORDER_MODE_ONLINE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p9305709579"><a name="p9305709579"></a><a name="p9305709579"></a>Trace work mode -&gt;Online mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1330610175717"><a name="p1330610175717"></a><a name="p1330610175717"></a>Specifies whether to enable the offline trace mode.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p18306180185715"><a name="p18306180185715"></a><a name="p18306180185715"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row3318603579"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1830616035713"><a name="p1830616035713"></a><a name="p1830616035713"></a>LOSCFG_TRACE_CLIENT_INTERACT</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p230613005719"><a name="p230613005719"></a><a name="p230613005719"></a>Enable Trace Client Visualization and Control</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p19306200125711"><a name="p19306200125711"></a><a name="p19306200125711"></a>Specifies whether to enable interaction with Trace IDE (dev tools), including data visualization and process control.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p16306130155720"><a name="p16306130155720"></a><a name="p16306130155720"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row23181607578"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p83064095720"><a name="p83064095720"></a><a name="p83064095720"></a>LOSCFG_TRACE_FRAME_CORE_MSG</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p730611075711"><a name="p730611075711"></a><a name="p730611075711"></a>Enable Record more extended content -&gt;Record cpuid, hardware interrupt status, task lock status</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p83061018576"><a name="p83061018576"></a><a name="p83061018576"></a>Specifies whether to enable recording of the CPU ID, interruption state, and lock task state.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p19306805574"><a name="p19306805574"></a><a name="p19306805574"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row8318904574"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p430617095718"><a name="p430617095718"></a><a name="p430617095718"></a>LOSCFG_TRACE_FRAME_EVENT_COUNT</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p13064013576"><a name="p13064013576"></a><a name="p13064013576"></a>Enable Record more extended content -&gt;Record event count, which indicate the sequence of happend events</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p133061203576"><a name="p133061203576"></a><a name="p133061203576"></a>Specifies whether to enables recording of the event sequence number.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p13306190105710"><a name="p13306190105710"></a><a name="p13306190105710"></a>YES/NO</p>
    </td>
    </tr>
    <tr id="row4318406577"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p183068010574"><a name="p183068010574"></a><a name="p183068010574"></a>LOSCFG_TRACE_FRAME_MAX_PARAMS</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p7306160125716"><a name="p7306160125716"></a><a name="p7306160125716"></a>Record max params</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p030610020572"><a name="p030610020572"></a><a name="p030610020572"></a>Specifies the maximum number of parameters for event recording.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p93065012570"><a name="p93065012570"></a><a name="p93065012570"></a>INT</p>
    </td>
    </tr>
    <tr id="row17317102571"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p330616014570"><a name="p330616014570"></a><a name="p330616014570"></a>LOSCFG_TRACE_BUFFER_SIZE</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p03061903577"><a name="p03061903577"></a><a name="p03061903577"></a>Trace record buffer size</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p14306120115713"><a name="p14306120115713"></a><a name="p14306120115713"></a>Specifies the trace buffer size.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p230613012578"><a name="p230613012578"></a><a name="p230613012578"></a>INT</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  \(Optional\) Preset event parameters and stubs \(or use the default event parameter settings and event stubs\).
3.  \(Optional\) Call  **LOS\_TraceStop**  to stop trace and call  **LOS\_TraceReset**  to clear the trace buffer. \(Trace is started by default.\)
4.  \(Optional\) Call  **LOS\_TraceEventMaskSet**  to set the event mask for trace \(only the interrupts and task events are enabled by default\). For details about the event mask, see  **LOS\_TRACE\_MASK**  in  **los\_trace.h**.
5.  Call  **LOS\_TraceStart**  at the start of the code where the event needs to be traced.
6.  Call  **LOS\_TraceStop**  at the end of the code where the event needs to be traced.
7.  Call  **LOS\_TraceRecordDump**  to output the data in the buffer. \(The input parameter of the function is of the Boolean type. The value  **FALSE**  means to output data in the specified format, and the value  **TRUE**  means to output data to Trace IDE.\)

The methods in steps 3 to 7 are encapsulated with shell commands. After the shell is enabled, the corresponding commands can be executed. The mapping is as follows:

-   LOS\_TraceReset —— trace\_reset
-   LOS\_TraceEventMaskSet —— trace\_mask
-   LOS\_TraceStart —— trace\_start
-   LOS\_TraceStop —— trace\_stop
-   LOS\_TraceRecordDump —— trace\_dump

## Kernel-mode Programming Example<a name="section112034213583"></a>

This example implements the following:

1.  Create a trace task.
2.  Set the event mask.
3.  Start trace.
4.  Stop trace.
5.  Output trace data in the specified format.

## Kernel-mode Sample Code<a name="section10348549155812"></a>

The code is as follows:

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
LOS_MODULE_INIT(Example_Trace_test, LOS_INIT_LEVEL_KMOD_EXTENDED);
```

## Verification<a name="section8601444165916"></a>

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
>The number of  **param**s is specified by the  **LOSCFG\_TRACE\_FRAME\_MAX\_PARAMS**  parameter. The default value is  **3**. Excess parameters are not recorded. You need to set  **LOSCFG\_TRACE\_FRAME\_MAX\_PARAMS**  based on service requirements.

Task 0x1 is switched to Task 0x0. The priority of task 0x1 is  **0x1f**, and the state is  **0x4**. The priority of the task 0x0 is  **0x0**.

