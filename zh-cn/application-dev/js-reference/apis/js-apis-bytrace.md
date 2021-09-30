# 性能打点<a name="ZH-CN_TOPIC_0000001209509395"></a>

-   [导入模块](#zh-cn_topic_0000001209019195_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001209019195_section11257113618419)
-   [bytrace.startTrace](#zh-cn_topic_0000001209019195_section785191510485)
-   [bytrace.finishTrace](#zh-cn_topic_0000001209019195_section7895134841213)
-   [bytrace.traceByValue](#zh-cn_topic_0000001209019195_section1388414179173)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001209019195_s56d19203690d4782bfc74069abb6bd71"></a>

```
import bytrace from '@ohos.bytrace';
```

## 权限<a name="zh-cn_topic_0000001209019195_section11257113618419"></a>

无

## bytrace.startTrace<a name="zh-cn_topic_0000001209019195_section785191510485"></a>

startTrace\(name: string, taskId: number, expectedTime?: number\): void

标记一个预追踪耗时任务的开始，expectedTime是可选参数，标识该任务的期望耗时。

-   参数：

    <a name="zh-cn_topic_0000001209019195_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209019195_row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209019195_p7966738914"><a name="zh-cn_topic_0000001209019195_p7966738914"></a><a name="zh-cn_topic_0000001209019195_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209019195_p296713699"><a name="zh-cn_topic_0000001209019195_p296713699"></a><a name="zh-cn_topic_0000001209019195_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209019195_p196718315911"><a name="zh-cn_topic_0000001209019195_p196718315911"></a><a name="zh-cn_topic_0000001209019195_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209019195_p9967231197"><a name="zh-cn_topic_0000001209019195_p9967231197"></a><a name="zh-cn_topic_0000001209019195_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209019195_row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p79671633910"><a name="zh-cn_topic_0000001209019195_p79671633910"></a><a name="zh-cn_topic_0000001209019195_p79671633910"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p11967433914"><a name="zh-cn_topic_0000001209019195_p11967433914"></a><a name="zh-cn_topic_0000001209019195_p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p19671336916"><a name="zh-cn_topic_0000001209019195_p19671336916"></a><a name="zh-cn_topic_0000001209019195_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p2084833211463"><a name="zh-cn_topic_0000001209019195_p2084833211463"></a><a name="zh-cn_topic_0000001209019195_p2084833211463"></a>要追踪的任务名称</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209019195_row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p16813106387"><a name="zh-cn_topic_0000001209019195_p16813106387"></a><a name="zh-cn_topic_0000001209019195_p16813106387"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p976115416386"><a name="zh-cn_topic_0000001209019195_p976115416386"></a><a name="zh-cn_topic_0000001209019195_p976115416386"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p149671932919"><a name="zh-cn_topic_0000001209019195_p149671932919"></a><a name="zh-cn_topic_0000001209019195_p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p19675312911"><a name="zh-cn_topic_0000001209019195_p19675312911"></a><a name="zh-cn_topic_0000001209019195_p19675312911"></a>任务id</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209019195_row1225911163813"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p132250110380"><a name="zh-cn_topic_0000001209019195_p132250110380"></a><a name="zh-cn_topic_0000001209019195_p132250110380"></a>expectedTime</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p1622551113381"><a name="zh-cn_topic_0000001209019195_p1622551113381"></a><a name="zh-cn_topic_0000001209019195_p1622551113381"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p5226151110383"><a name="zh-cn_topic_0000001209019195_p5226151110383"></a><a name="zh-cn_topic_0000001209019195_p5226151110383"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p22262111381"><a name="zh-cn_topic_0000001209019195_p22262111381"></a><a name="zh-cn_topic_0000001209019195_p22262111381"></a>期望的耗时时间，单位：ms</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >如果多个要追踪任务的name相同，taskId必须不一致。通过name和taskId来唯一标识一个任务。

-   示例：

    ```
    bytrace.startTrace("myTestFunc", 1);
    bytrace.startTrace("myTestFunc", 1, 5); //从startTrace到finishTrace流程的耗时期望为5ms
    ```


## bytrace.finishTrace<a name="zh-cn_topic_0000001209019195_section7895134841213"></a>

finishTrace\(name: string, taskId: number\): void

标记一个预追踪耗时任务的结束。

-   参数：

    <a name="zh-cn_topic_0000001209019195_table1589613488127"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209019195_row208961448131215"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209019195_p1089674831216"><a name="zh-cn_topic_0000001209019195_p1089674831216"></a><a name="zh-cn_topic_0000001209019195_p1089674831216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209019195_p1689613481128"><a name="zh-cn_topic_0000001209019195_p1689613481128"></a><a name="zh-cn_topic_0000001209019195_p1689613481128"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209019195_p989613483125"><a name="zh-cn_topic_0000001209019195_p989613483125"></a><a name="zh-cn_topic_0000001209019195_p989613483125"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209019195_p13896148111215"><a name="zh-cn_topic_0000001209019195_p13896148111215"></a><a name="zh-cn_topic_0000001209019195_p13896148111215"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209019195_row14896204817125"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p10896174817128"><a name="zh-cn_topic_0000001209019195_p10896174817128"></a><a name="zh-cn_topic_0000001209019195_p10896174817128"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p189618483125"><a name="zh-cn_topic_0000001209019195_p189618483125"></a><a name="zh-cn_topic_0000001209019195_p189618483125"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p118961548101215"><a name="zh-cn_topic_0000001209019195_p118961548101215"></a><a name="zh-cn_topic_0000001209019195_p118961548101215"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p1989674810124"><a name="zh-cn_topic_0000001209019195_p1989674810124"></a><a name="zh-cn_topic_0000001209019195_p1989674810124"></a>要追踪的任务名称</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209019195_row5896548101211"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p10896164811121"><a name="zh-cn_topic_0000001209019195_p10896164811121"></a><a name="zh-cn_topic_0000001209019195_p10896164811121"></a>taskId</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p1789694821215"><a name="zh-cn_topic_0000001209019195_p1789694821215"></a><a name="zh-cn_topic_0000001209019195_p1789694821215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p08962488128"><a name="zh-cn_topic_0000001209019195_p08962488128"></a><a name="zh-cn_topic_0000001209019195_p08962488128"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p8896194831214"><a name="zh-cn_topic_0000001209019195_p8896194831214"></a><a name="zh-cn_topic_0000001209019195_p8896194831214"></a>任务id</p>
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


## bytrace.traceByValue<a name="zh-cn_topic_0000001209019195_section1388414179173"></a>

traceByValue\(name: string, count: number\): void

用来标记一个预追踪的数值变量，该变量的数值会不断变化。

-   参数：

    <a name="zh-cn_topic_0000001209019195_table0884617171718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209019195_row1188481771714"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209019195_p488419174178"><a name="zh-cn_topic_0000001209019195_p488419174178"></a><a name="zh-cn_topic_0000001209019195_p488419174178"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.22%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209019195_p12884131721718"><a name="zh-cn_topic_0000001209019195_p12884131721718"></a><a name="zh-cn_topic_0000001209019195_p12884131721718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.67%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209019195_p188481714178"><a name="zh-cn_topic_0000001209019195_p188481714178"></a><a name="zh-cn_topic_0000001209019195_p188481714178"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209019195_p188411174177"><a name="zh-cn_topic_0000001209019195_p188411174177"></a><a name="zh-cn_topic_0000001209019195_p188411174177"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209019195_row38849172174"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p7884121719172"><a name="zh-cn_topic_0000001209019195_p7884121719172"></a><a name="zh-cn_topic_0000001209019195_p7884121719172"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p1488415174171"><a name="zh-cn_topic_0000001209019195_p1488415174171"></a><a name="zh-cn_topic_0000001209019195_p1488415174171"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p7884171711717"><a name="zh-cn_topic_0000001209019195_p7884171711717"></a><a name="zh-cn_topic_0000001209019195_p7884171711717"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p17884517161715"><a name="zh-cn_topic_0000001209019195_p17884517161715"></a><a name="zh-cn_topic_0000001209019195_p17884517161715"></a>要追踪的数值变量名称</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209019195_row188419179172"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209019195_p206756457267"><a name="zh-cn_topic_0000001209019195_p206756457267"></a><a name="zh-cn_topic_0000001209019195_p206756457267"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.22%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209019195_p9884917111710"><a name="zh-cn_topic_0000001209019195_p9884917111710"></a><a name="zh-cn_topic_0000001209019195_p9884917111710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.67%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209019195_p18841217141719"><a name="zh-cn_topic_0000001209019195_p18841217141719"></a><a name="zh-cn_topic_0000001209019195_p18841217141719"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209019195_p178842174174"><a name="zh-cn_topic_0000001209019195_p178842174174"></a><a name="zh-cn_topic_0000001209019195_p178842174174"></a>变量的值</p>
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


