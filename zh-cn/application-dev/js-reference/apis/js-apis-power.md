# 系统电源管理<a name="ZH-CN_TOPIC_0000001133775514"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import power from '@ohos.power';
```

## 权限<a name="section11257113618419"></a>

关机权限： ohos.permission.SHUTDOWN

重启权限： ohos.permission.REBOOT

重启并进入recovery模式的权限：ohos.permission.REBOOT\_RECOVERY

## power.shutdownDevice<a name="section192192415554"></a>

shutdownDevice\(reason: string\): void

系统关机。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p5518501625"><a name="p5518501625"></a><a name="p5518501625"></a>reason</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>关机原因。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    power.shutdownDevice("shutdown_test");
    console.info('power_shutdown_device_test success')
    ```


## power.rebootDevice<a name="section1773218207620"></a>

rebootDevice\(reason: string\): void

重启设备。

-   参数：

    <a name="table8732192015611"></a>
    <table><thead align="left"><tr id="row1173216204612"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p973222015615"><a name="p973222015615"></a><a name="p973222015615"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.1.5.1.2"><p id="p273232015612"><a name="p273232015612"></a><a name="p273232015612"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p id="p9732202013618"><a name="p9732202013618"></a><a name="p9732202013618"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.47%" id="mcps1.1.5.1.4"><p id="p167326201566"><a name="p167326201566"></a><a name="p167326201566"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row773292016614"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p57320201162"><a name="p57320201162"></a><a name="p57320201162"></a>reason</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p973216201164"><a name="p973216201164"></a><a name="p973216201164"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.3 "><p id="p5732132020612"><a name="p5732132020612"></a><a name="p5732132020612"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.47%" headers="mcps1.1.5.1.4 "><p id="p4733720662"><a name="p4733720662"></a><a name="p4733720662"></a>重启原因。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    power.rebootDevice("reboot_test");
    console.info('power_reboot_device_test success')
    ```


## power.isScreenOn<a name="section69511458115312"></a>

isScreenOn\(callback: AsyncCallback<boolean\>\): void

检测当前设备的亮灭屏状态。

-   参数：

    <a name="table183681450191519"></a>
    <table><thead align="left"><tr id="row20368050151519"><th class="cellrowborder" valign="top" width="15.989999999999998%" id="mcps1.1.5.1.1"><p id="p13681150121519"><a name="p13681150121519"></a><a name="p13681150121519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.27%" id="mcps1.1.5.1.2"><p id="p1636895015154"><a name="p1636895015154"></a><a name="p1636895015154"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.64%" id="mcps1.1.5.1.3"><p id="p7565410191617"><a name="p7565410191617"></a><a name="p7565410191617"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p43681350181515"><a name="p43681350181515"></a><a name="p43681350181515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row636865081513"><td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.5.1.1 "><p id="p4368165091513"><a name="p4368165091513"></a><a name="p4368165091513"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.27%" headers="mcps1.1.5.1.2 "><p id="p83691450151519"><a name="p83691450151519"></a><a name="p83691450151519"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p17565310191610"><a name="p17565310191610"></a><a name="p17565310191610"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p163691850191515"><a name="p163691850191515"></a><a name="p163691850191515"></a>指定的callback回调方法，用于获取返回值。</p>
    <p id="p3566124615812"><a name="p3566124615812"></a><a name="p3566124615812"></a>callback返回值：亮屏返回true，灭屏返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    power.isScreenOn((error, screenOn) => {
        if (typeof error === "undefined") {
            console.info('screenOn status is ' + screenOn);
        } else {
            console.log('error: ' + error);
        }
    })
    ```


## power.isScreenOn<a name="section143367619119"></a>

isScreenOn\(\): Promise<boolean\>

检测当前设备的亮灭屏状态。

-   返回值：

    <a name="table1730417311314"></a>
    <table><thead align="left"><tr id="row1930412311018"><th class="cellrowborder" valign="top" width="23.87%" id="mcps1.1.3.1.1"><p id="p15304113117114"><a name="p15304113117114"></a><a name="p15304113117114"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.13%" id="mcps1.1.3.1.2"><p id="p830411311017"><a name="p830411311017"></a><a name="p830411311017"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row173045311711"><td class="cellrowborder" valign="top" width="23.87%" headers="mcps1.1.3.1.1 "><p id="p686517815914"><a name="p686517815914"></a><a name="p686517815914"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.13%" headers="mcps1.1.3.1.2 "><p id="p163041531916"><a name="p163041531916"></a><a name="p163041531916"></a>Promise实例，用于异步获取返回值，亮屏返回true，灭屏返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    power.isScreenOn()
    .then(screenOn => {
        console.info('screenOn status is ' + screenOn);
    })
    .catch(error => {
        console.log('error: ' + error);
    })
    ```


