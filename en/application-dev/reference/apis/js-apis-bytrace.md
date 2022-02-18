# Performance Tracing<a name="EN-US_TOPIC_0000001165886716"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import bytrace from '@ohos.bytrace';
```

## System Capabilities

SystemCapability.Developtools.Bytrace

## bytrace.startTrace<a name="section785191510485"></a>

startTrace\(name: string, taskId: number, expectedTime?: number\): void

Starts a trace of a task.  **expectedTime**  is an optional parameter, which specifies the expected duration of the trace.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2084833211463"><a name="p2084833211463"></a><a name="p2084833211463"></a>Name of the trace task to start.</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16813106387"><a name="p16813106387"></a><a name="p16813106387"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p976115416386"><a name="p976115416386"></a><a name="p976115416386"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>Task ID.</p>
    </td>
    </tr>
    <tr id="row1225911163813"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p132250110380"><a name="p132250110380"></a><a name="p132250110380"></a>expectedTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1622551113381"><a name="p1622551113381"></a><a name="p1622551113381"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p5226151110383"><a name="p5226151110383"></a><a name="p5226151110383"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p22262111381"><a name="p22262111381"></a><a name="p22262111381"></a>Expected duration of the trace, in ms.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **NOTE:** 
    >If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different  **taskId**s must be specified in  **startTrace**. If the trace tasks with the same name are not performed at the same time, the same  **taskId**  can be used. For details, see the  **bytrace.finishTrace**  example.

-   Example

    ```
    bytrace.startTrace("myTestFunc", 1);
    bytrace.startTrace("myTestFunc", 1, 5); // The expected duration of the trace is 5 ms.
    ```


## bytrace.finishTrace<a name="section7895134841213"></a>

finishTrace\(name: string, taskId: number\): void

Stops a trace task.

-   Parameters

    <a name="table1589613488127"></a>
    <table><thead align="left"><tr id="row208961448131215"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1089674831216"><a name="p1089674831216"></a><a name="p1089674831216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p1689613481128"><a name="p1689613481128"></a><a name="p1689613481128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p989613483125"><a name="p989613483125"></a><a name="p989613483125"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p13896148111215"><a name="p13896148111215"></a><a name="p13896148111215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14896204817125"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10896174817128"><a name="p10896174817128"></a><a name="p10896174817128"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p189618483125"><a name="p189618483125"></a><a name="p189618483125"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p118961548101215"><a name="p118961548101215"></a><a name="p118961548101215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1989674810124"><a name="p1989674810124"></a><a name="p1989674810124"></a>Name of the trace task to stop.</p>
    </td>
    </tr>
    <tr id="row5896548101211"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10896164811121"><a name="p10896164811121"></a><a name="p10896164811121"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1789694821215"><a name="p1789694821215"></a><a name="p1789694821215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p08962488128"><a name="p08962488128"></a><a name="p08962488128"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8896194831214"><a name="p8896194831214"></a><a name="p8896194831214"></a>Task ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **NOTE:** 
    >To stop a trace task, the values of  **name**  and  **taskId**  in  **finishTrace**  must be the same as those in  **startTrace**.

-   Example

    ```
    bytrace.finishTrace("myTestFunc", 1);
    ```

    ```
    // Start track tasks with the same name concurrently.
    bytrace.startTrace("myTestFunc", 1);
    ...... // Service flow
    bytrace.startTrace ("myTestFunc", 2); // The second trace task starts while the first task is still running. The first and second tasks have the same name but different task IDs.
    ...... // Service flow
    bytrace.finishTrace("myTestFunc", 1);
    ...... // Service flow
    bytrace.finishTrace("myTestFunc", 2);
    ```

    ```
    // Start track tasks with the same name at different times.
    bytrace.startTrace("myTestFunc", 1);
    ...... // Service flow
    bytrace.finishTrace("myTestFunc", 1); // The first trace task ends.
    ...... // Service flow
    bytrace.startTrace("myTestFunc", 1); // The second trace task starts after the first task ends. The two tasks have the same name and task ID. 
    ...... // Service flow
    bytrace.finishTrace("myTestFunc", 1);
    ```


## bytrace.traceByValue<a name="section1388414179173"></a>

traceByValue\(name: string, value: number\): void

Traces the value changes of a variable.

-   Parameters

    <a name="table0884617171718"></a>
    <table><thead align="left"><tr id="row1188481771714"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p488419174178"><a name="p488419174178"></a><a name="p488419174178"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p12884131721718"><a name="p12884131721718"></a><a name="p12884131721718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p188481714178"><a name="p188481714178"></a><a name="p188481714178"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p188411174177"><a name="p188411174177"></a><a name="p188411174177"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row38849172174"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7884121719172"><a name="p7884121719172"></a><a name="p7884121719172"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1488415174171"><a name="p1488415174171"></a><a name="p1488415174171"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p7884171711717"><a name="p7884171711717"></a><a name="p7884171711717"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17884517161715"><a name="p17884517161715"></a><a name="p17884517161715"></a>Name of the variable to trace.</p>
    </td>
    </tr>
    <tr id="row188419179172"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p206756457267"><a name="p206756457267"></a><a name="p206756457267"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p9884917111710"><a name="p9884917111710"></a><a name="p9884917111710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p18841217141719"><a name="p18841217141719"></a><a name="p18841217141719"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p178842174174"><a name="p178842174174"></a><a name="p178842174174"></a>Value of the variable to trace.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let traceCount = 3;
    bytrace.traceByValue("myTestCount", traceCount);
    ......
    traceCount = 5;
    bytrace.traceByValue("myTestCount", traceCount);
    ```


