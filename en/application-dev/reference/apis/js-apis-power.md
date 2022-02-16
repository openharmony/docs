# Power Management<a name="EN-US_TOPIC_0000001133775514"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import power from '@ohos.power';
```

## System Capabilities

SystemCapability.PowerManager.PowerManager


## power.shutdownDevice<a name="section192192415554"></a>

shutdownDevice\(reason: string\): void

Shuts down the system.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p5518501625"><a name="p5518501625"></a><a name="p5518501625"></a>reason</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Reason for system shutdown.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    power.shutdownDevice("shutdown_test");
    console.info('power_shutdown_device_test success')
    ```


## power.rebootDevice<a name="section1773218207620"></a>

rebootDevice\(reason: string\): void

Reboots the system.

-   Parameters

    <a name="table8732192015611"></a>
    <table><thead align="left"><tr id="row1173216204612"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p973222015615"><a name="p973222015615"></a><a name="p973222015615"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.830000000000002%" id="mcps1.1.5.1.2"><p id="p273232015612"><a name="p273232015612"></a><a name="p273232015612"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p id="p9732202013618"><a name="p9732202013618"></a><a name="p9732202013618"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.47%" id="mcps1.1.5.1.4"><p id="p167326201566"><a name="p167326201566"></a><a name="p167326201566"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row773292016614"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p57320201162"><a name="p57320201162"></a><a name="p57320201162"></a>reason</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p973216201164"><a name="p973216201164"></a><a name="p973216201164"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.3 "><p id="p5732132020612"><a name="p5732132020612"></a><a name="p5732132020612"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.47%" headers="mcps1.1.5.1.4 "><p id="p4733720662"><a name="p4733720662"></a><a name="p4733720662"></a>Reason for system reboot.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    power.rebootDevice("reboot_test");
    console.info('power_reboot_device_test success')
    ```


## power.isScreenOn<a name="section69511458115312"></a>

isScreenOn\(callback: AsyncCallback<boolean\>\): void

Checks the screen status of the current device.

-   Parameters

    <a name="table183681450191519"></a>
    <table><thead align="left"><tr id="row20368050151519"><th class="cellrowborder" valign="top" width="15.989999999999998%" id="mcps1.1.5.1.1"><p id="p13681150121519"><a name="p13681150121519"></a><a name="p13681150121519"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.27%" id="mcps1.1.5.1.2"><p id="p1636895015154"><a name="p1636895015154"></a><a name="p1636895015154"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.64%" id="mcps1.1.5.1.3"><p id="p7565410191617"><a name="p7565410191617"></a><a name="p7565410191617"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.1%" id="mcps1.1.5.1.4"><p id="p43681350181515"><a name="p43681350181515"></a><a name="p43681350181515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row636865081513"><td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.5.1.1 "><p id="p4368165091513"><a name="p4368165091513"></a><a name="p4368165091513"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.27%" headers="mcps1.1.5.1.2 "><p id="p83691450151519"><a name="p83691450151519"></a><a name="p83691450151519"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p17565310191610"><a name="p17565310191610"></a><a name="p17565310191610"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.1%" headers="mcps1.1.5.1.4 "><p id="p163691850191515"><a name="p163691850191515"></a><a name="p163691850191515"></a>Callback used to obtain the return value.</p>
    <p id="p3566124615812"><a name="p3566124615812"></a><a name="p3566124615812"></a>The value <strong id="b4350172620165"><a name="b4350172620165"></a><a name="b4350172620165"></a>true</strong> indicates that the screen is on, and value <strong id="b035432613168"><a name="b035432613168"></a><a name="b035432613168"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

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

Checks the screen status of the current device.

-   Return values

    <a name="table1730417311314"></a>
    <table><thead align="left"><tr id="row1930412311018"><th class="cellrowborder" valign="top" width="23.87%" id="mcps1.1.3.1.1"><p id="p15304113117114"><a name="p15304113117114"></a><a name="p15304113117114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.13%" id="mcps1.1.3.1.2"><p id="p830411311017"><a name="p830411311017"></a><a name="p830411311017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row173045311711"><td class="cellrowborder" valign="top" width="23.87%" headers="mcps1.1.3.1.1 "><p id="p686517815914"><a name="p686517815914"></a><a name="p686517815914"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.13%" headers="mcps1.1.3.1.2 "><p id="p163041531916"><a name="p163041531916"></a><a name="p163041531916"></a>Promise used to asynchronously obtain the return value. The value <strong id="b1934154320392"><a name="b1934154320392"></a><a name="b1934154320392"></a>true</strong> indicates that the screen is on, and value <strong id="b1693454393914"><a name="b1693454393914"></a><a name="b1693454393914"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    power.isScreenOn()
    .then(screenOn => {
        console.info('screenOn status is ' + screenOn);
    })
    .catch(error => {
        console.log('error: ' + error);
    })
    ```


