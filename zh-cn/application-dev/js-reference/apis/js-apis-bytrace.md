# 性能打点<a name="ZH-CN_TOPIC_0000001165886716"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import bytrace from '@ohos.bytrace';
```

## 权限<a name="section11257113618419"></a>

无

## bytrace.startTrace<a name="section785191510485"></a>

startTrace\(name: string, taskId: number, expectedTime?: number\): void

标记一个预追踪耗时任务的开始，expectedTime是可选参数，标识该任务的期望耗时。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2084833211463"><a name="p2084833211463"></a><a name="p2084833211463"></a>要追踪的任务名称</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16813106387"><a name="p16813106387"></a><a name="p16813106387"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p976115416386"><a name="p976115416386"></a><a name="p976115416386"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>任务id</p>
    </td>
    </tr>
    <tr id="row1225911163813"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p132250110380"><a name="p132250110380"></a><a name="p132250110380"></a>expectedTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1622551113381"><a name="p1622551113381"></a><a name="p1622551113381"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p5226151110383"><a name="p5226151110383"></a><a name="p5226151110383"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p22262111381"><a name="p22262111381"></a><a name="p22262111381"></a>期望的耗时时间，单位：ms</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >如果有多个相同name的任务需要追踪或者对同一个任务要追踪多次，并且这些会同时被执行，则每次调用startTrace的taskId必须不一致。如果具有相同name的任务是串行执行的，则taskId可以相同。在下面bytrace.finishTrace的示例中会举例说明。

-   示例：

    ```
    bytrace.startTrace("myTestFunc", 1);
    bytrace.startTrace("myTestFunc", 1, 5); //从startTrace到finishTrace流程的耗时期望为5ms
    ```


## bytrace.finishTrace<a name="section7895134841213"></a>

finishTrace\(name: string, taskId: number\): void

标记一个预追踪耗时任务的结束。

-   参数：

    <a name="table1589613488127"></a>
    <table><thead align="left"><tr id="row208961448131215"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1089674831216"><a name="p1089674831216"></a><a name="p1089674831216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p1689613481128"><a name="p1689613481128"></a><a name="p1689613481128"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p989613483125"><a name="p989613483125"></a><a name="p989613483125"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p13896148111215"><a name="p13896148111215"></a><a name="p13896148111215"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14896204817125"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10896174817128"><a name="p10896174817128"></a><a name="p10896174817128"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p189618483125"><a name="p189618483125"></a><a name="p189618483125"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p118961548101215"><a name="p118961548101215"></a><a name="p118961548101215"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1989674810124"><a name="p1989674810124"></a><a name="p1989674810124"></a>要追踪的任务名称</p>
    </td>
    </tr>
    <tr id="row5896548101211"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10896164811121"><a name="p10896164811121"></a><a name="p10896164811121"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1789694821215"><a name="p1789694821215"></a><a name="p1789694821215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p08962488128"><a name="p08962488128"></a><a name="p08962488128"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8896194831214"><a name="p8896194831214"></a><a name="p8896194831214"></a>任务id</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >finishTrace的name和taskId必须与流程开始的startTrace对应参数值一致。

-   示例：

    ```
    bytrace.finishTrace("myTestFunc", 1);
    ```

    ```
    //追踪并行执行的同名任务
    bytrace.startTrace("myTestFunc", 1);
    ...... //业务流程
    bytrace.startTrace("myTestFunc", 2);  //第二个追踪的任务开始，同时第一个追踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
    ...... //业务流程
    bytrace.finishTrace("myTestFunc", 1);
    ...... //业务流程
    bytrace.finishTrace("myTestFunc", 2);
    ```

    ```
    //追踪串行执行的同名任务
    bytrace.startTrace("myTestFunc", 1);
    ...... //业务流程
    bytrace.finishTrace("myTestFunc", 1);  //第一个追踪的任务结束
    ...... //业务流程
    bytrace.startTrace("myTestFunc", 1);   //第二个追踪的同名任务开始，同名的待追踪任务串行执行。
    ...... //业务流程
    bytrace.finishTrace("myTestFunc", 1);
    ```


## bytrace.traceByValue<a name="section1388414179173"></a>

traceByValue\(name: string, value: number\): void

用来标记一个预追踪的数值变量，该变量的数值会不断变化。

-   参数：

    <a name="table0884617171718"></a>
    <table><thead align="left"><tr id="row1188481771714"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p488419174178"><a name="p488419174178"></a><a name="p488419174178"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="p12884131721718"><a name="p12884131721718"></a><a name="p12884131721718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="p188481714178"><a name="p188481714178"></a><a name="p188481714178"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p188411174177"><a name="p188411174177"></a><a name="p188411174177"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row38849172174"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7884121719172"><a name="p7884121719172"></a><a name="p7884121719172"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p1488415174171"><a name="p1488415174171"></a><a name="p1488415174171"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p7884171711717"><a name="p7884171711717"></a><a name="p7884171711717"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17884517161715"><a name="p17884517161715"></a><a name="p17884517161715"></a>要追踪的数值变量名称</p>
    </td>
    </tr>
    <tr id="row188419179172"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p206756457267"><a name="p206756457267"></a><a name="p206756457267"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="p9884917111710"><a name="p9884917111710"></a><a name="p9884917111710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="p18841217141719"><a name="p18841217141719"></a><a name="p18841217141719"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p178842174174"><a name="p178842174174"></a><a name="p178842174174"></a>变量的值</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let traceCount = 3;
    bytrace.traceByValue("myTestCount", traceCount);
    ......
    traceCount = 5;
    bytrace.traceByValue("myTestCount", traceCount);
    ```


