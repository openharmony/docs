# WLAN<a name="EN-US_TOPIC_0000001185356878"></a>

>**NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import wifi from '@ohos.wifi';
```

## wifi.isWifiActive<a name="section1513433143816"></a>

isWifiActive\(\): boolean

Checks whether the WLAN is activated.

-   Return values

    <a name="table1051453373812"></a>
    <table><thead align="left"><tr id="row19514633173816"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p851423310387"><a name="p851423310387"></a><a name="p851423310387"></a><strong id="b188968211505"><a name="b188968211505"></a><a name="b188968211505"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p1251483373814"><a name="p1251483373814"></a><a name="p1251483373814"></a><strong id="b1780702395019"><a name="b1780702395019"></a><a name="b1780702395019"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1751416332386"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p751463317382"><a name="p751463317382"></a><a name="p751463317382"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p3514193373811"><a name="p3514193373811"></a><a name="p3514193373811"></a>Returns <strong id="b29011040204610"><a name="b29011040204610"></a><a name="b29011040204610"></a>true</strong> if the WLAN is activated; returns <strong id="b82234576461"><a name="b82234576461"></a><a name="b82234576461"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.scan<a name="section1289134478"></a>

scan\(\): boolean

Starts a scan for WLAN.

-   Return values

    <a name="table4426131312411"></a>
    <table><thead align="left"><tr id="row16254131415416"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p42540148412"><a name="p42540148412"></a><a name="p42540148412"></a><strong id="b724853201"><a name="b724853201"></a><a name="b724853201"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p725461404118"><a name="p725461404118"></a><a name="p725461404118"></a><strong id="b392222784"><a name="b392222784"></a><a name="b392222784"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1825451415411"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p92545149412"><a name="p92545149412"></a><a name="p92545149412"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p925481474110"><a name="p925481474110"></a><a name="p925481474110"></a>Returns <strong id="b5332102301711"><a name="b5332102301711"></a><a name="b5332102301711"></a>true</strong> if the scan is successful; returns <strong id="b1116115111814"><a name="b1116115111814"></a><a name="b1116115111814"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getScanInfos<a name="section20747137419"></a>

getScanInfos\(\): Promise<Array<WifiScanInfo\>\>

Obtains the scan result. This method uses a promise to return the result.

-   Return values

    <a name="table042741320417"></a>
    <table><thead align="left"><tr id="row1825451419414"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p102541146416"><a name="p102541146416"></a><a name="p102541146416"></a><strong id="b1781552976"><a name="b1781552976"></a><a name="b1781552976"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p225419141411"><a name="p225419141411"></a><a name="p225419141411"></a><strong id="b107941518304"><a name="b107941518304"></a><a name="b107941518304"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5254214194111"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p8254614154113"><a name="p8254614154113"></a><a name="p8254614154113"></a>Promise&lt; Array&lt;<a href="#section138641312414">WifiScanInfo</a>&gt; &gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p02548143416"><a name="p02548143416"></a><a name="p02548143416"></a>Promise used to return the scan result, which is a list of hotspot information.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getScanInfos<a name="section1781133414"></a>

getScanInfos\(callback: AsyncCallback<Array<WifiScanInfo\>\>\): void

Obtains the scan result. This method uses an asynchronous callback to return the result.

-   Parameters

    <a name="table742911314110"></a>
    <table><thead align="left"><tr id="row18254111454118"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p10254151474111"><a name="p10254151474111"></a><a name="p10254151474111"></a><strong id="b16264827175615"><a name="b16264827175615"></a><a name="b16264827175615"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p3254201417411"><a name="p3254201417411"></a><a name="p3254201417411"></a><strong id="b1223144113286"><a name="b1223144113286"></a><a name="b1223144113286"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p1255151413415"><a name="p1255151413415"></a><a name="p1255151413415"></a><strong id="b74431742132818"><a name="b74431742132818"></a><a name="b74431742132818"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p17255131416411"><a name="p17255131416411"></a><a name="p17255131416411"></a><strong id="b679651113014"><a name="b679651113014"></a><a name="b679651113014"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1255181444110"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p10255614204115"><a name="p10255614204115"></a><a name="p10255614204115"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p525516143417"><a name="p525516143417"></a><a name="p525516143417"></a>AsyncCallback&lt; Array&lt;<a href="#section138641312414">WifiScanInfo</a>&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p7255214174113"><a name="p7255214174113"></a><a name="p7255214174113"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p142551714104114"><a name="p142551714104114"></a><a name="p142551714104114"></a>Callback invoked to return the scan result, which is a list of hotspot information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    import wifi from '@ohos.wifi';
    
    wifi.getScanInfos(result => {
        var len = Object.keys(result).length;
        console.log("wifi received scan info call back: " + len);
        for (var i = 0; i < len; ++i) {
            console.info("ssid: " + result[i].ssid);
            console.info("bssid: " + result[i].bssid);
            console.info("securityType: " + result[i].securityType);
            console.info("rssi: " + result[i].rssi);
            console.info("band: " + result[i].band);
            console.info("frequency: " + result[i].frequency);
            console.info("timestamp: " + result[i].timestamp);
        }
    });
    
    wifi.getScanInfos().then(result => {
        var len = Object.keys(result).length;
        console.log("wifi received scan info promise: " + len);
        for (var i = 0; i < len; ++i) {
            console.info("ssid: " + result[i].ssid);
            console.info("bssid: " + result[i].bssid);
            console.info("securityType: " + result[i].securityType);
            console.info("rssi: " + result[i].rssi);
            console.info("band: " + result[i].band);
            console.info("frequency: " + result[i].frequency);
            console.info("timestamp: " + result[i].timestamp);
        }
    });
    ```


## WifiScanInfo<a name="section138641312414"></a>

Defines the WLAN hotspot information.

<a name="table1443151310414"></a>
<table><thead align="left"><tr id="row3255101434118"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p12255201444112"><a name="p12255201444112"></a><a name="p12255201444112"></a><strong id="b15295727175618"><a name="b15295727175618"></a><a name="b15295727175618"></a>Name</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p17255914204111"><a name="p17255914204111"></a><a name="p17255914204111"></a><strong id="b1222535459"><a name="b1222535459"></a><a name="b1222535459"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p62551914144114"><a name="p62551914144114"></a><a name="p62551914144114"></a><strong id="b176226501217"><a name="b176226501217"></a><a name="b176226501217"></a>Readable/Writable</strong></p>
</th>
<th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p7255151410419"><a name="p7255151410419"></a><a name="p7255151410419"></a><strong id="b286319330"><a name="b286319330"></a><a name="b286319330"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row525581484110"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p1925551434111"><a name="p1925551434111"></a><a name="p1925551434111"></a>ssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p925561474115"><a name="p925561474115"></a><a name="p925561474115"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p192551814174118"><a name="p192551814174118"></a><a name="p192551814174118"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p825591416410"><a name="p825591416410"></a><a name="p825591416410"></a>Hotspot service set identifier (SSID), in UTF-8 format.</p>
</td>
</tr>
<tr id="row225521416415"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p13255514134118"><a name="p13255514134118"></a><a name="p13255514134118"></a>bssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p2255161444110"><a name="p2255161444110"></a><a name="p2255161444110"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p925614141414"><a name="p925614141414"></a><a name="p925614141414"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12256121419419"><a name="p12256121419419"></a><a name="p12256121419419"></a>Basic service set identifier (BSSID) of the hotspot.</p>
</td>
</tr>
<tr id="row525621413414"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p1625651417419"><a name="p1625651417419"></a><a name="p1625651417419"></a>securityType</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p1025651484113"><a name="p1025651484113"></a><a name="p1025651484113"></a><a href="#section1027316502560">WifiSecurityType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p202567143410"><a name="p202567143410"></a><a name="p202567143410"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12256714184116"><a name="p12256714184116"></a><a name="p12256714184116"></a>WLAN encryption type.</p>
</td>
</tr>
<tr id="row16256161404114"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p12256151420418"><a name="p12256151420418"></a><a name="p12256151420418"></a>rssi</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p11256161419416"><a name="p11256161419416"></a><a name="p11256161419416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p92565145414"><a name="p92565145414"></a><a name="p92565145414"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p1425621424114"><a name="p1425621424114"></a><a name="p1425621424114"></a>Received Signal Strength Indicator (RSSI) of the hotspot, in dBm.</p>
</td>
</tr>
<tr id="row14256181415411"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p12256101415419"><a name="p12256101415419"></a><a name="p12256101415419"></a>band</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p9256161412415"><a name="p9256161412415"></a><a name="p9256161412415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p425691464112"><a name="p425691464112"></a><a name="p425691464112"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12257111454112"><a name="p12257111454112"></a><a name="p12257111454112"></a>Frequency band of the WLAN access point (AP).</p>
</td>
</tr>
<tr id="row1125751434117"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p122571514114120"><a name="p122571514114120"></a><a name="p122571514114120"></a>frequency</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p72575148416"><a name="p72575148416"></a><a name="p72575148416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p825711413415"><a name="p825711413415"></a><a name="p825711413415"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p52571514134116"><a name="p52571514134116"></a><a name="p52571514134116"></a>Frequency of the WLAN AP.</p>
</td>
</tr>
<tr id="row425701454119"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p3257914104118"><a name="p3257914104118"></a><a name="p3257914104118"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p4257514104118"><a name="p4257514104118"></a><a name="p4257514104118"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p3257151434119"><a name="p3257151434119"></a><a name="p3257151434119"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p192579145417"><a name="p192579145417"></a><a name="p192579145417"></a>Timestamp.</p>
</td>
</tr>
</tbody>
</table>

## WifiSecurityType<a name="section1027316502560"></a>

Enumerates the WLAN encryption types.

<a name="table9273175020566"></a>
<table><thead align="left"><tr id="row1327445012563"><th class="cellrowborder" valign="top" width="29.592959295929592%" id="mcps1.1.4.1.1"><p id="p1327415507562"><a name="p1327415507562"></a><a name="p1327415507562"></a><strong id="b146091828205319"><a name="b146091828205319"></a><a name="b146091828205319"></a>Name</strong></p>
</th>
<th class="cellrowborder" valign="top" width="9.18091809180918%" id="mcps1.1.4.1.2"><p id="p12274105018561"><a name="p12274105018561"></a><a name="p12274105018561"></a><strong id="en-us_topic_0058055320_en-us_topic_0048961051_af61172aa7b7e45ada2563c2f0b56c60b"><a name="en-us_topic_0058055320_en-us_topic_0048961051_af61172aa7b7e45ada2563c2f0b56c60b"></a><a name="en-us_topic_0058055320_en-us_topic_0048961051_af61172aa7b7e45ada2563c2f0b56c60b"></a>Default Value</strong></p>
</th>
<th class="cellrowborder" valign="top" width="61.22612261226122%" id="mcps1.1.4.1.3"><p id="p9274150195618"><a name="p9274150195618"></a><a name="p9274150195618"></a><strong id="b57815118306"><a name="b57815118306"></a><a name="b57815118306"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row182741950115619"><td class="cellrowborder" valign="top" width="29.592959295929592%" headers="mcps1.1.4.1.1 "><p id="p6274155016567"><a name="p6274155016567"></a><a name="p6274155016567"></a>WIFI_SEC_TYPE_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="9.18091809180918%" headers="mcps1.1.4.1.2 "><p id="p1527455015617"><a name="p1527455015617"></a><a name="p1527455015617"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="61.22612261226122%" headers="mcps1.1.4.1.3 "><p id="p2274135035615"><a name="p2274135035615"></a><a name="p2274135035615"></a>Invalid encryption.</p>
</td>
</tr>
<tr id="row127465016568"><td class="cellrowborder" valign="top" width="29.592959295929592%" headers="mcps1.1.4.1.1 "><p id="p927475035616"><a name="p927475035616"></a><a name="p927475035616"></a>WIFI_SEC_TYPE_OPEN</p>
</td>
<td class="cellrowborder" valign="top" width="9.18091809180918%" headers="mcps1.1.4.1.2 "><p id="p42751650185615"><a name="p42751650185615"></a><a name="p42751650185615"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.22612261226122%" headers="mcps1.1.4.1.3 "><p id="p1627545065612"><a name="p1627545065612"></a><a name="p1627545065612"></a>Open encryption.</p>
</td>
</tr>
<tr id="row0275150125617"><td class="cellrowborder" valign="top" width="29.592959295929592%" headers="mcps1.1.4.1.1 "><p id="p10275750145618"><a name="p10275750145618"></a><a name="p10275750145618"></a>WIFI_SEC_TYPE_WEP</p>
</td>
<td class="cellrowborder" valign="top" width="9.18091809180918%" headers="mcps1.1.4.1.2 "><p id="p1827516506565"><a name="p1827516506565"></a><a name="p1827516506565"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="61.22612261226122%" headers="mcps1.1.4.1.3 "><p id="p15275165015614"><a name="p15275165015614"></a><a name="p15275165015614"></a>Wired equivalent privacy (WEP) encryption.</p>
</td>
</tr>
<tr id="row102757501567"><td class="cellrowborder" valign="top" width="29.592959295929592%" headers="mcps1.1.4.1.1 "><p id="p18275350125617"><a name="p18275350125617"></a><a name="p18275350125617"></a>WIFI_SEC_TYPE_PSK</p>
</td>
<td class="cellrowborder" valign="top" width="9.18091809180918%" headers="mcps1.1.4.1.2 "><p id="p1927512503560"><a name="p1927512503560"></a><a name="p1927512503560"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="61.22612261226122%" headers="mcps1.1.4.1.3 "><p id="p1527518506563"><a name="p1527518506563"></a><a name="p1527518506563"></a>PSK encryption.</p>
</td>
</tr>
<tr id="row192751750105619"><td class="cellrowborder" valign="top" width="29.592959295929592%" headers="mcps1.1.4.1.1 "><p id="p727505085611"><a name="p727505085611"></a><a name="p727505085611"></a>WIFI_SEC_TYPE_SAE</p>
</td>
<td class="cellrowborder" valign="top" width="9.18091809180918%" headers="mcps1.1.4.1.2 "><p id="p1027555045612"><a name="p1027555045612"></a><a name="p1027555045612"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="61.22612261226122%" headers="mcps1.1.4.1.3 "><p id="p9275115010565"><a name="p9275115010565"></a><a name="p9275115010565"></a>Simultaneous authentication of equals (SAE) encryption.</p>
</td>
</tr>
</tbody>
</table>

## wifi.getSignalLevel<a name="section04714574165"></a>

getSignalLevel\(rssi: number, band: number\): number

Obtains the WLAN signal strength.

-   Parameters

    <a name="table123664139419"></a>
    <table><thead align="left"><tr id="row224131444117"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p162411414194112"><a name="p162411414194112"></a><a name="p162411414194112"></a><strong id="b1290134374"><a name="b1290134374"></a><a name="b1290134374"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p112419148419"><a name="p112419148419"></a><a name="p112419148419"></a><strong id="b2112703228"><a name="b2112703228"></a><a name="b2112703228"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p124111444112"><a name="p124111444112"></a><a name="p124111444112"></a><strong id="b799854840"><a name="b799854840"></a><a name="b799854840"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p10241201404111"><a name="p10241201404111"></a><a name="p10241201404111"></a><strong id="b15432443122814"><a name="b15432443122814"></a><a name="b15432443122814"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row162411314184113"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p52411514124117"><a name="p52411514124117"></a><a name="p52411514124117"></a>rssi</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p7241414144116"><a name="p7241414144116"></a><a name="p7241414144116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p524112141412"><a name="p524112141412"></a><a name="p524112141412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p13241114144112"><a name="p13241114144112"></a><a name="p13241114144112"></a>RSSI of the hotspot, in dBm.</p>
    </td>
    </tr>
    <tr id="row224141444119"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p124191434119"><a name="p124191434119"></a><a name="p124191434119"></a>band</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p162411514164116"><a name="p162411514164116"></a><a name="p162411514164116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p11241141414115"><a name="p11241141414115"></a><a name="p11241141414115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p92411214204119"><a name="p92411214204119"></a><a name="p92411214204119"></a>Frequency band of the WLAN AP.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table12369141364112"></a>
    <table><thead align="left"><tr id="row924121464110"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p1724121412419"><a name="p1724121412419"></a><a name="p1724121412419"></a><strong id="b197391717"><a name="b197391717"></a><a name="b197391717"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p324114144414"><a name="p324114144414"></a><a name="p324114144414"></a><strong id="b89441159293"><a name="b89441159293"></a><a name="b89441159293"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row124191414415"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p182421014184112"><a name="p182421014184112"></a><a name="p182421014184112"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p142423146417"><a name="p142423146417"></a><a name="p142423146417"></a>Signal strength obtained. The value range is 0 to 4.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getIpInfo<sup>7+</sup><a name="section7102161354113"></a>

getIpInfo\(\): IpInfo

Obtains IP information.

-   Return values

    <a name="table144091319413"></a>
    <table><thead align="left"><tr id="row62571114134116"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p18257214104113"><a name="p18257214104113"></a><a name="p18257214104113"></a><strong id="b1468023483"><a name="b1468023483"></a><a name="b1468023483"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p1125741434110"><a name="p1125741434110"></a><a name="p1125741434110"></a><strong id="b15800417304"><a name="b15800417304"></a><a name="b15800417304"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row225851444118"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1225831414419"><a name="p1225831414419"></a><a name="p1225831414419"></a><a href="#section17107151312418">IpInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p42581214114112"><a name="p42581214114112"></a><a name="p42581214114112"></a>IP information obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


## IpInfo<a name="section17107151312418"></a>

Defines IP information.

<a name="table18441121314417"></a>
<table><thead align="left"><tr id="row825815143414"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p132580146417"><a name="p132580146417"></a><a name="p132580146417"></a><strong id="b1729919273567"><a name="b1729919273567"></a><a name="b1729919273567"></a>Name</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p1525811484116"><a name="p1525811484116"></a><a name="p1525811484116"></a><strong id="b1740436804"><a name="b1740436804"></a><a name="b1740436804"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p19258121474117"><a name="p19258121474117"></a><a name="p19258121474117"></a><strong id="b11524185832114"><a name="b11524185832114"></a><a name="b11524185832114"></a>Readable/Writable</strong></p>
</th>
<th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p725861494110"><a name="p725861494110"></a><a name="p725861494110"></a><strong id="b1208503355"><a name="b1208503355"></a><a name="b1208503355"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row225811404112"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p9258714144118"><a name="p9258714144118"></a><a name="p9258714144118"></a>ipAddress</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p10258151494119"><a name="p10258151494119"></a><a name="p10258151494119"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p425871414118"><a name="p425871414118"></a><a name="p425871414118"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p5258714114114"><a name="p5258714114114"></a><a name="p5258714114114"></a>IP address.</p>
</td>
</tr>
<tr id="row2025819147411"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p725851414119"><a name="p725851414119"></a><a name="p725851414119"></a>gateway</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p6258141410414"><a name="p6258141410414"></a><a name="p6258141410414"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p16259171416414"><a name="p16259171416414"></a><a name="p16259171416414"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p152596145414"><a name="p152596145414"></a><a name="p152596145414"></a>Gateway.</p>
</td>
</tr>
<tr id="row1025941411419"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p10259191424119"><a name="p10259191424119"></a><a name="p10259191424119"></a>netmask</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p11259141454120"><a name="p11259141454120"></a><a name="p11259141454120"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p5259714154118"><a name="p5259714154118"></a><a name="p5259714154118"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p52593141416"><a name="p52593141416"></a><a name="p52593141416"></a>Subnet mask.</p>
</td>
</tr>
<tr id="row16259191411417"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p62592143414"><a name="p62592143414"></a><a name="p62592143414"></a>primaryDns</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p42591714144116"><a name="p42591714144116"></a><a name="p42591714144116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p182592146411"><a name="p182592146411"></a><a name="p182592146411"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p182591314174119"><a name="p182591314174119"></a><a name="p182591314174119"></a>IP address of the preferred DNS server.</p>
</td>
</tr>
<tr id="row112596142417"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p22601014154120"><a name="p22601014154120"></a><a name="p22601014154120"></a>secondDns</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p6260131424118"><a name="p6260131424118"></a><a name="p6260131424118"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p20260111414111"><a name="p20260111414111"></a><a name="p20260111414111"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p8260214194119"><a name="p8260214194119"></a><a name="p8260214194119"></a>IP address of the alternate DNS server.</p>
</td>
</tr>
<tr id="row526019146414"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p0260121416415"><a name="p0260121416415"></a><a name="p0260121416415"></a>serverIp</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p132600146415"><a name="p132600146415"></a><a name="p132600146415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p18260161411417"><a name="p18260161411417"></a><a name="p18260161411417"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p3260101411417"><a name="p3260101411417"></a><a name="p3260101411417"></a>IP address of the DHCP server.</p>
</td>
</tr>
<tr id="row726071411412"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p02601214164115"><a name="p02601214164115"></a><a name="p02601214164115"></a>leaseDuration</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p426013149415"><a name="p426013149415"></a><a name="p426013149415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p172609147412"><a name="p172609147412"></a><a name="p172609147412"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p6260514124114"><a name="p6260514124114"></a><a name="p6260514124114"></a>Lease duration of the IP address.</p>
</td>
</tr>
</tbody>
</table>

## wifi.isConnected<sup>7+</sup><a name="section1051333314382"></a>

isConnected\(\): boolean

Checks whether the WLAN is connected.

-   Return values

    <a name="table851316332385"></a>
    <table><thead align="left"><tr id="row1251320339382"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p19513173313381"><a name="p19513173313381"></a><a name="p19513173313381"></a><strong id="b1464614664"><a name="b1464614664"></a><a name="b1464614664"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p1513193333810"><a name="p1513193333810"></a><a name="p1513193333810"></a><strong id="b172332699"><a name="b172332699"></a><a name="b172332699"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row851310334380"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p18513193343817"><a name="p18513193343817"></a><a name="p18513193343817"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p1513163314388"><a name="p1513163314388"></a><a name="p1513163314388"></a>Returns <strong id="b366823117452"><a name="b366823117452"></a><a name="b366823117452"></a>true</strong> if the WLAN is connected; returns <strong id="b67811355124514"><a name="b67811355124514"></a><a name="b67811355124514"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getLinkedInfo<sup>7+</sup><a name="section34081726164514"></a>

getLinkedInfo\(\): Promise<WifiLinkedInfo\>

Obtains WLAN connection information. This method uses a promise to return the result.

-   Return values

    <a name="table106721328171713"></a>
    <table><thead align="left"><tr id="row9672122817176"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p106728288171"><a name="p106728288171"></a><a name="p106728288171"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p5672112817178"><a name="p5672112817178"></a><a name="p5672112817178"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row06721528191711"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p107821612171919"><a name="p107821612171919"></a><a name="p107821612171919"></a>Promise&lt;<a href="#section1804168559">WifiLinkedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p4672828141718"><a name="p4672828141718"></a><a name="p4672828141718"></a>Promise used to return the WLAN connection information</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getLinkedInfo<sup>7+</sup><a name="section1853612361618"></a>

getLinkedInfo\(callback: AsyncCallback<WifiLinkedInfo\>\): void

Obtains WLAN connection information. This method uses a callback to return the result.

-   Parameters

    <a name="table276820378555"></a>
    <table><thead align="left"><tr id="row197681937175519"><th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.5.1.1"><p id="p6768163719555"><a name="p6768163719555"></a><a name="p6768163719555"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.470000000000002%" id="mcps1.1.5.1.2"><p id="p87681437105513"><a name="p87681437105513"></a><a name="p87681437105513"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.5.1.3"><p id="p176843765514"><a name="p176843765514"></a><a name="p176843765514"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.5%" id="mcps1.1.5.1.4"><p id="p17769337205510"><a name="p17769337205510"></a><a name="p17769337205510"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2769153713559"><td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.5.1.1 "><p id="p376913718556"><a name="p376913718556"></a><a name="p376913718556"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.470000000000002%" headers="mcps1.1.5.1.2 "><p id="p9769113785519"><a name="p9769113785519"></a><a name="p9769113785519"></a>AsyncCallback&lt;<a href="#section1804168559">WifiLinkedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.5.1.3 "><p id="p97691837125513"><a name="p97691837125513"></a><a name="p97691837125513"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.5%" headers="mcps1.1.5.1.4 "><p id="p127691437145519"><a name="p127691437145519"></a><a name="p127691437145519"></a>Callback invoked to return the WLAN connection information.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    import wifi from '@ohos.wifi';
    
    wifi.getLinkedInfo(data => {
        console.info("get wifi linked info [callback]: " + JSON.stringify(data));
    });
    
    wifi.getLinkedInfo().then(data => {
        console.info("get wifi linked info [promise]: " + JSON.stringify(data));
    }).catch(error => {
        console.info("linked info promise then error");
    });
    ```


## WifiLinkedInfo<a name="section1804168559"></a>

Defines the WLAN connection information.

<a name="table39811964553"></a>
<table><thead align="left"><tr id="row4978206125519"><th class="cellrowborder" valign="top" width="23.43765623437656%" id="mcps1.1.5.1.1"><p id="p6978146115515"><a name="p6978146115515"></a><a name="p6978146115515"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.308169183081695%" id="mcps1.1.5.1.2"><p id="p79789611554"><a name="p79789611554"></a><a name="p79789611554"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.709029097090292%" id="mcps1.1.5.1.3"><p id="p0294509576"><a name="p0294509576"></a><a name="p0294509576"></a>Readable/Writable</p>
</th>
<th class="cellrowborder" valign="top" width="48.54514548545145%" id="mcps1.1.5.1.4"><p id="p1797815635517"><a name="p1797815635517"></a><a name="p1797815635517"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row797836205516"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p7978146145511"><a name="p7978146145511"></a><a name="p7978146145511"></a>ssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p49786619551"><a name="p49786619551"></a><a name="p49786619551"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p142941703576"><a name="p142941703576"></a><a name="p142941703576"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p189788695514"><a name="p189788695514"></a><a name="p189788695514"></a>Hotspot SSID, in UTF-8 format.</p>
</td>
</tr>
<tr id="row69781769555"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p129788675519"><a name="p129788675519"></a><a name="p129788675519"></a>bssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p7978864552"><a name="p7978864552"></a><a name="p7978864552"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p1329430105715"><a name="p1329430105715"></a><a name="p1329430105715"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p1597826195510"><a name="p1597826195510"></a><a name="p1597826195510"></a>BSSID of the hotspot.</p>
</td>
</tr>
<tr id="row14979156115515"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p159786635510"><a name="p159786635510"></a><a name="p159786635510"></a>rssi</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p597914615558"><a name="p597914615558"></a><a name="p597914615558"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p12294200125715"><a name="p12294200125715"></a><a name="p12294200125715"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p197914615552"><a name="p197914615552"></a><a name="p197914615552"></a>RSSI of the hotspot, in dBm.</p>
</td>
</tr>
<tr id="row16979863550"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p1797936195512"><a name="p1797936195512"></a><a name="p1797936195512"></a>band</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p129792617555"><a name="p129792617555"></a><a name="p129792617555"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p192948085715"><a name="p192948085715"></a><a name="p192948085715"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p19979165557"><a name="p19979165557"></a><a name="p19979165557"></a>Frequency band of the WLAN AP.</p>
</td>
</tr>
<tr id="row897918655514"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p59791361558"><a name="p59791361558"></a><a name="p59791361558"></a>linkSpeed</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p1997919685517"><a name="p1997919685517"></a><a name="p1997919685517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p1829417014575"><a name="p1829417014575"></a><a name="p1829417014575"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p199794615552"><a name="p199794615552"></a><a name="p199794615552"></a>Speed of the WLAN AP.</p>
</td>
</tr>
<tr id="row1997996125516"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p139794615550"><a name="p139794615550"></a><a name="p139794615550"></a>frequency</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p29791169557"><a name="p29791169557"></a><a name="p29791169557"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p0294701579"><a name="p0294701579"></a><a name="p0294701579"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p149791617552"><a name="p149791617552"></a><a name="p149791617552"></a>Frequency of the WLAN AP.</p>
</td>
</tr>
<tr id="row8979868554"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p1597919610552"><a name="p1597919610552"></a><a name="p1597919610552"></a>isHidden</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p697913645518"><a name="p697913645518"></a><a name="p697913645518"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p12294190125719"><a name="p12294190125719"></a><a name="p12294190125719"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p15979863558"><a name="p15979863558"></a><a name="p15979863558"></a>Whether the WLAN AP is hidden.</p>
</td>
</tr>
<tr id="row119807655513"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p097976195518"><a name="p097976195518"></a><a name="p097976195518"></a>isRestricted</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p198012695511"><a name="p198012695511"></a><a name="p198012695511"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p16294109571"><a name="p16294109571"></a><a name="p16294109571"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p698011635515"><a name="p698011635515"></a><a name="p698011635515"></a>Whether data volume is restricted at the WLAN AP.</p>
</td>
</tr>
<tr id="row598011613553"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p159805675512"><a name="p159805675512"></a><a name="p159805675512"></a>macAddress</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p39801761553"><a name="p39801761553"></a><a name="p39801761553"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p13295103577"><a name="p13295103577"></a><a name="p13295103577"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p5980116145514"><a name="p5980116145514"></a><a name="p5980116145514"></a>MAC address of the device that sets up the WLAN connection.</p>
</td>
</tr>
<tr id="row4980464554"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p198013616559"><a name="p198013616559"></a><a name="p198013616559"></a>ipAddress</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p1198026155515"><a name="p1198026155515"></a><a name="p1198026155515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p152951100573"><a name="p152951100573"></a><a name="p152951100573"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p89801611556"><a name="p89801611556"></a><a name="p89801611556"></a>IP address of the device that sets up the WLAN connection.</p>
</td>
</tr>
<tr id="row398110615510"><td class="cellrowborder" valign="top" width="23.43765623437656%" headers="mcps1.1.5.1.1 "><p id="p1098116618550"><a name="p1098116618550"></a><a name="p1098116618550"></a>connState</p>
</td>
<td class="cellrowborder" valign="top" width="18.308169183081695%" headers="mcps1.1.5.1.2 "><p id="p398119618556"><a name="p398119618556"></a><a name="p398119618556"></a>ConnState</p>
</td>
<td class="cellrowborder" valign="top" width="9.709029097090292%" headers="mcps1.1.5.1.3 "><p id="p8295405576"><a name="p8295405576"></a><a name="p8295405576"></a>Read-only</p>
</td>
<td class="cellrowborder" valign="top" width="48.54514548545145%" headers="mcps1.1.5.1.4 "><p id="p09813675513"><a name="p09813675513"></a><a name="p09813675513"></a>WLAN connection state.</p>
</td>
</tr>
</tbody>
</table>

## ConnState<a name="section163306433912"></a>

Enumerates the WLAN connection states.

<a name="table1398414611551"></a>
<table><thead align="left"><tr id="row1498326195516"><th class="cellrowborder" valign="top" width="29.73%" id="mcps1.1.4.1.1"><p id="p11983126145510"><a name="p11983126145510"></a><a name="p11983126145510"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.4.1.2"><p id="p135811535141120"><a name="p135811535141120"></a><a name="p135811535141120"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="60.199999999999996%" id="mcps1.1.4.1.3"><p id="p798317611555"><a name="p798317611555"></a><a name="p798317611555"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15983669554"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p198366105511"><a name="p198366105511"></a><a name="p198366105511"></a>SCANNING</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p35815353114"><a name="p35815353114"></a><a name="p35815353114"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p149831768559"><a name="p149831768559"></a><a name="p149831768559"></a>The device is scanning for available APs.</p>
</td>
</tr>
<tr id="row16983176125516"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p18983146115516"><a name="p18983146115516"></a><a name="p18983146115516"></a>CONNECTING</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p10581163521110"><a name="p10581163521110"></a><a name="p10581163521110"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p1298317611557"><a name="p1298317611557"></a><a name="p1298317611557"></a>A WLAN connection is being established.</p>
</td>
</tr>
<tr id="row69843675516"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p1098418615518"><a name="p1098418615518"></a><a name="p1098418615518"></a>AUTHENTICATING</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p105814358115"><a name="p105814358115"></a><a name="p105814358115"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p109844610557"><a name="p109844610557"></a><a name="p109844610557"></a>An authentication is being performed for a WLAN connection.</p>
</td>
</tr>
<tr id="row1298417617552"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p598414611559"><a name="p598414611559"></a><a name="p598414611559"></a>OBTAINING_IPADDR</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p75822035181119"><a name="p75822035181119"></a><a name="p75822035181119"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p169844619556"><a name="p169844619556"></a><a name="p169844619556"></a>The IP address of the WLAN connection is being acquired.</p>
</td>
</tr>
<tr id="row17984196185517"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p1298416605520"><a name="p1298416605520"></a><a name="p1298416605520"></a>CONNECTED</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p135828357119"><a name="p135828357119"></a><a name="p135828357119"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p109842655518"><a name="p109842655518"></a><a name="p109842655518"></a>A WLAN connection is established.</p>
</td>
</tr>
<tr id="row69840617552"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p11984369554"><a name="p11984369554"></a><a name="p11984369554"></a>DISCONNECTING</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p9582123518115"><a name="p9582123518115"></a><a name="p9582123518115"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p20984264555"><a name="p20984264555"></a><a name="p20984264555"></a>The WLAN connection is being disconnected.</p>
</td>
</tr>
<tr id="row19847613555"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p698413612553"><a name="p698413612553"></a><a name="p698413612553"></a>DISCONNECTED</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p55825356110"><a name="p55825356110"></a><a name="p55825356110"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p79841563551"><a name="p79841563551"></a><a name="p79841563551"></a>The WLAN connection is disconnected.</p>
</td>
</tr>
<tr id="row12984186205512"><td class="cellrowborder" valign="top" width="29.73%" headers="mcps1.1.4.1.1 "><p id="p698418612556"><a name="p698418612556"></a><a name="p698418612556"></a>UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.4.1.2 "><p id="p258243511111"><a name="p258243511111"></a><a name="p258243511111"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="60.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p59841465550"><a name="p59841465550"></a><a name="p59841465550"></a>Failed to set up a WLAN connection.</p>
</td>
</tr>
</tbody>
</table>

## wifi.getCountryCode<sup>7+</sup><a name="section11487202212598"></a>

getCountryCode\(\): string

Obtains the country code.

-   Return values

    <a name="table2489022125919"></a>
    <table><thead align="left"><tr id="row448942245913"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p11489322175919"><a name="p11489322175919"></a><a name="p11489322175919"></a><strong id="b1101062272"><a name="b1101062272"></a><a name="b1101062272"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p19489172210598"><a name="p19489172210598"></a><a name="p19489172210598"></a><strong id="b668154175"><a name="b668154175"></a><a name="b668154175"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row548942205918"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p74898221591"><a name="p74898221591"></a><a name="p74898221591"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p148932245917"><a name="p148932245917"></a><a name="p148932245917"></a>Country code obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.isFeatureSupported<sup>7+</sup><a name="section7360192181816"></a>

isFeatureSupported\(featureId: number\): boolean

Checks whether the device supports the specified WLAN feature.

-   Parameters

    <a name="table7371111314115"></a>
    <table><thead align="left"><tr id="row5242161454120"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p9242121494119"><a name="p9242121494119"></a><a name="p9242121494119"></a><strong id="b1325941900"><a name="b1325941900"></a><a name="b1325941900"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p1124251434111"><a name="p1124251434111"></a><a name="p1124251434111"></a><strong id="b223631462917"><a name="b223631462917"></a><a name="b223631462917"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p324215146411"><a name="p324215146411"></a><a name="p324215146411"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p19242101419411"><a name="p19242101419411"></a><a name="p19242101419411"></a><strong id="b10249102042920"><a name="b10249102042920"></a><a name="b10249102042920"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row92427149419"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p1324291464118"><a name="p1324291464118"></a><a name="p1324291464118"></a>featureId</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p1024211434120"><a name="p1024211434120"></a><a name="p1024211434120"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p1124291494118"><a name="p1124291494118"></a><a name="p1124291494118"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12421714144112"><a name="p12421714144112"></a><a name="p12421714144112"></a>Feature ID.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table737418135416"></a>
    <table><thead align="left"><tr id="row3242191434110"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p624211494110"><a name="p624211494110"></a><a name="p624211494110"></a><strong id="b1955776713"><a name="b1955776713"></a><a name="b1955776713"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p1242131454118"><a name="p1242131454118"></a><a name="p1242131454118"></a><strong id="b900808766"><a name="b900808766"></a><a name="b900808766"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13242121474116"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1243514194114"><a name="p1243514194114"></a><a name="p1243514194114"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p1024361434115"><a name="p1024361434115"></a><a name="p1024361434115"></a>Returns <strong id="b173986430502"><a name="b173986430502"></a><a name="b173986430502"></a>true</strong> if the feature is supported; returns <strong id="b124682584509"><a name="b124682584509"></a><a name="b124682584509"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Enumerates the WLAN features.

    <a name="table183033135457"></a>
    <table><thead align="left"><tr id="row1430321316450"><th class="cellrowborder" valign="top" width="36.480000000000004%" id="mcps1.1.3.1.1"><p id="p123034137456"><a name="p123034137456"></a><a name="p123034137456"></a>Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.519999999999996%" id="mcps1.1.3.1.2"><p id="p203036132455"><a name="p203036132455"></a><a name="p203036132455"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19303171319457"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p2304111314450"><a name="p2304111314450"></a><a name="p2304111314450"></a>0x0001</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p11304151319453"><a name="p11304151319453"></a><a name="p11304151319453"></a>WLAN infrastructure mode.</p>
    </td>
    </tr>
    <tr id="row030413133458"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p43041213204511"><a name="p43041213204511"></a><a name="p43041213204511"></a>0x0002</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p030431319454"><a name="p030431319454"></a><a name="p030431319454"></a>5 GHz bandwidth.</p>
    </td>
    </tr>
    <tr id="row163041513174519"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p1304213144518"><a name="p1304213144518"></a><a name="p1304213144518"></a>0x0004</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p4304813144510"><a name="p4304813144510"></a><a name="p4304813144510"></a>Generic Advertisement Service (GAS)/Access Network Query Protocol (ANQP) feature.</p>
    </td>
    </tr>
    <tr id="row630415135453"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p33042131457"><a name="p33042131457"></a><a name="p33042131457"></a>0x0008</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p113051713184517"><a name="p113051713184517"></a><a name="p113051713184517"></a>Wi-Fi Direct.</p>
    </td>
    </tr>
    <tr id="row23051413174516"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p93056134457"><a name="p93056134457"></a><a name="p93056134457"></a>0x0010</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p13305101313456"><a name="p13305101313456"></a><a name="p13305101313456"></a>SoftAP.</p>
    </td>
    </tr>
    <tr id="row23051913104516"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p15305413204519"><a name="p15305413204519"></a><a name="p15305413204519"></a>0x0040</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p1430561311459"><a name="p1430561311459"></a><a name="p1430561311459"></a>Wi-Fi AWare.</p>
    </td>
    </tr>
    <tr id="row13305161320458"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p133057135451"><a name="p133057135451"></a><a name="p133057135451"></a>0x8000</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p16305151344518"><a name="p16305151344518"></a><a name="p16305151344518"></a>WLAN AP/STA concurrency</p>
    </td>
    </tr>
    <tr id="row10305613164513"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p1030541316452"><a name="p1030541316452"></a><a name="p1030541316452"></a>0x8000000</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p73061813194518"><a name="p73061813194518"></a><a name="p73061813194518"></a>WPA3 Personal (WPA-3 SAE) feature.</p>
    </td>
    </tr>
    <tr id="row166184824715"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p11714884716"><a name="p11714884716"></a><a name="p11714884716"></a>0x10000000</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p137194811472"><a name="p137194811472"></a><a name="p137194811472"></a>WPA3 Enterprise Suite B feature.</p>
    </td>
    </tr>
    <tr id="row1365116011483"><td class="cellrowborder" valign="top" width="36.480000000000004%" headers="mcps1.1.3.1.1 "><p id="p176516013482"><a name="p176516013482"></a><a name="p176516013482"></a>0x20000000</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.519999999999996%" headers="mcps1.1.3.1.2 "><p id="p16511010486"><a name="p16511010486"></a><a name="p16511010486"></a>Enhanced open feature.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.on\('wifiStateChange'\)<sup>7+</sup><a name="section1222351314113"></a>

on\(type: "wifiStateChange", callback: Callback<number\>\): void

Registers the WLAN state change events.

-   Parameters

    <a name="table20505201317418"></a>
    <table><thead align="left"><tr id="row18269914134114"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p5269614154120"><a name="p5269614154120"></a><a name="p5269614154120"></a><strong id="b1321395344"><a name="b1321395344"></a><a name="b1321395344"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p18269914164117"><a name="p18269914164117"></a><a name="p18269914164117"></a><strong id="b840696537"><a name="b840696537"></a><a name="b840696537"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p926911415418"><a name="p926911415418"></a><a name="p926911415418"></a><strong id="b1163912197"><a name="b1163912197"></a><a name="b1163912197"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p1027001474118"><a name="p1027001474118"></a><a name="p1027001474118"></a><strong id="b1280361113018"><a name="b1280361113018"></a><a name="b1280361113018"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1627001494114"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p727018142416"><a name="p727018142416"></a><a name="p727018142416"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p327061416413"><a name="p327061416413"></a><a name="p327061416413"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p82701914184116"><a name="p82701914184116"></a><a name="p82701914184116"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p927091494120"><a name="p927091494120"></a><a name="p927091494120"></a>Event type. The value is <strong id="b39123222313"><a name="b39123222313"></a><a name="b39123222313"></a>wifiStateChange</strong>.</p>
    </td>
    </tr>
    <tr id="row5270111494116"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1227071412418"><a name="p1227071412418"></a><a name="p1227071412418"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p1527001464114"><a name="p1527001464114"></a><a name="p1527001464114"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p027014143417"><a name="p027014143417"></a><a name="p027014143417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1827018142412"><a name="p1827018142412"></a><a name="p1827018142412"></a>Callback invoked to return the WLAN state.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Enumerates the WLAN states.

    <a name="table1509101314119"></a>
    <table><thead align="left"><tr id="row6270114184115"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p12270101424118"><a name="p12270101424118"></a><a name="p12270101424118"></a><strong id="b126916913312"><a name="b126916913312"></a><a name="b126916913312"></a>Value</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p2270151414413"><a name="p2270151414413"></a><a name="p2270151414413"></a><strong id="b28052019309"><a name="b28052019309"></a><a name="b28052019309"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10270181419413"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p172703146417"><a name="p172703146417"></a><a name="p172703146417"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p5270171413419"><a name="p5270171413419"></a><a name="p5270171413419"></a>Deactivated.</p>
    </td>
    </tr>
    <tr id="row827019144412"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1627018142417"><a name="p1627018142417"></a><a name="p1627018142417"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p122709146414"><a name="p122709146414"></a><a name="p122709146414"></a>Activated.</p>
    </td>
    </tr>
    <tr id="row527031420413"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p427011418412"><a name="p427011418412"></a><a name="p427011418412"></a>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p327014144417"><a name="p327014144417"></a><a name="p327014144417"></a>Activating.</p>
    </td>
    </tr>
    <tr id="row13270414124117"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p10270714144119"><a name="p10270714144119"></a><a name="p10270714144119"></a>3</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p1927011411417"><a name="p1927011411417"></a><a name="p1927011411417"></a>Deactivating.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.off\('wifiStateChange'\)<sup>7+</sup><a name="section1623417132414"></a>

off\(type: "wifiStateChange", callback?: Callback<number\>\): void

Unregisters the WLAN state change events.

-   Parameters

    <a name="table1251131312412"></a>
    <table><thead align="left"><tr id="row1927115148413"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p1271141411418"><a name="p1271141411418"></a><a name="p1271141411418"></a><strong id="b487647697"><a name="b487647697"></a><a name="b487647697"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p427117149411"><a name="p427117149411"></a><a name="p427117149411"></a><strong id="b452779545"><a name="b452779545"></a><a name="b452779545"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p627120140413"><a name="p627120140413"></a><a name="p627120140413"></a><strong id="b1357883393"><a name="b1357883393"></a><a name="b1357883393"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p927181410415"><a name="p927181410415"></a><a name="p927181410415"></a><strong id="b1018511114"><a name="b1018511114"></a><a name="b1018511114"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row627141417413"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1927121415411"><a name="p1927121415411"></a><a name="p1927121415411"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p10271151412411"><a name="p10271151412411"></a><a name="p10271151412411"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p1271914204110"><a name="p1271914204110"></a><a name="p1271914204110"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p20271171416414"><a name="p20271171416414"></a><a name="p20271171416414"></a>Event type. The value is <strong id="b1883340244"><a name="b1883340244"></a><a name="b1883340244"></a>wifiStateChange</strong>.</p>
    </td>
    </tr>
    <tr id="row1627114144417"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p12271414104114"><a name="p12271414104114"></a><a name="p12271414104114"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p127141434117"><a name="p127141434117"></a><a name="p127141434117"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p192718145415"><a name="p192718145415"></a><a name="p192718145415"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p7271131416411"><a name="p7271131416411"></a><a name="p7271131416411"></a>Callback used to report the WLAN state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    import wifi from '@ohos.wifi';
    import { EventListener } from '@ohos.wifi';
    
    var WIFI_POWER_STATE = "wifiStateChange";
    var listener = new EventListener();
    
    var recvPowerNotifyFunc = result => {
        console.info("power state receive event: " + result);
    }
    
    // Register event
    listener.on(WIFI_POWER_STATE, recvPowerNotifyFunc);
    
    // Unregister event
    listener.off(WIFI_POWER_STATE, recvPowerNotifyFunc);
    ```


## wifi.on\('wifiConnectionChange'\)<sup>7+</sup><a name="section172451139414"></a>

on\(type: "wifiConnectionChange", callback: Callback<number\>\): void

Registers the WLAN connection state change events.

-   Parameters

    <a name="table051541344111"></a>
    <table><thead align="left"><tr id="row11271101412412"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p14271171454112"><a name="p14271171454112"></a><a name="p14271171454112"></a><strong id="b1696918677"><a name="b1696918677"></a><a name="b1696918677"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p327181413413"><a name="p327181413413"></a><a name="p327181413413"></a><strong id="b550529507"><a name="b550529507"></a><a name="b550529507"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p19272141419413"><a name="p19272141419413"></a><a name="p19272141419413"></a><strong id="b492137111"><a name="b492137111"></a><a name="b492137111"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p182721214174111"><a name="p182721214174111"></a><a name="p182721214174111"></a><strong id="b1670462665"><a name="b1670462665"></a><a name="b1670462665"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3272191411415"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p17272114194117"><a name="p17272114194117"></a><a name="p17272114194117"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p12272914144111"><a name="p12272914144111"></a><a name="p12272914144111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p19272914154115"><a name="p19272914154115"></a><a name="p19272914154115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1727214141417"><a name="p1727214141417"></a><a name="p1727214141417"></a>Event type. The value is <strong id="b17757152513712"><a name="b17757152513712"></a><a name="b17757152513712"></a>wifiConnectionChange</strong>.</p>
    </td>
    </tr>
    <tr id="row19272101474112"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1272151413418"><a name="p1272151413418"></a><a name="p1272151413418"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p62727143412"><a name="p62727143412"></a><a name="p62727143412"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p127231413415"><a name="p127231413415"></a><a name="p127231413415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p142721814104111"><a name="p142721814104111"></a><a name="p142721814104111"></a>Callback invoked to return the WLAN connection state.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Enumerates the WLAN connection states.

    <a name="table6520513104113"></a>
    <table><thead align="left"><tr id="row827281494118"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p1527221494110"><a name="p1527221494110"></a><a name="p1527221494110"></a><strong id="b7656164863711"><a name="b7656164863711"></a><a name="b7656164863711"></a>Value</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p327218147413"><a name="p327218147413"></a><a name="p327218147413"></a><strong id="b811496594"><a name="b811496594"></a><a name="b811496594"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8272141416416"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1272111484115"><a name="p1272111484115"></a><a name="p1272111484115"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p72721414124116"><a name="p72721414124116"></a><a name="p72721414124116"></a>Disconnected.</p>
    </td>
    </tr>
    <tr id="row1427216141419"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p6272181418415"><a name="p6272181418415"></a><a name="p6272181418415"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p62725143415"><a name="p62725143415"></a><a name="p62725143415"></a>Connected.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.off\('wifiConnectionChange'\)<sup>7+</sup><a name="section82555133416"></a>

off\(type: "wifiConnectionChange", callback?: Callback<number\>\): void

Unregisters the WLAN connection state change events.

-   Parameters

    <a name="table10521171318417"></a>
    <table><thead align="left"><tr id="row17272171410411"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p20272171418416"><a name="p20272171418416"></a><a name="p20272171418416"></a><strong id="b579370986"><a name="b579370986"></a><a name="b579370986"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p42729140419"><a name="p42729140419"></a><a name="p42729140419"></a><strong id="b370960486"><a name="b370960486"></a><a name="b370960486"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p1327261494115"><a name="p1327261494115"></a><a name="p1327261494115"></a><strong id="b448980613"><a name="b448980613"></a><a name="b448980613"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p2027301454113"><a name="p2027301454113"></a><a name="p2027301454113"></a><strong id="b330193117"><a name="b330193117"></a><a name="b330193117"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2273101484114"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p2273714124114"><a name="p2273714124114"></a><a name="p2273714124114"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p172734148416"><a name="p172734148416"></a><a name="p172734148416"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p112731014134114"><a name="p112731014134114"></a><a name="p112731014134114"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1127341494112"><a name="p1127341494112"></a><a name="p1127341494112"></a>Event type. The value is <strong id="b1337369553"><a name="b1337369553"></a><a name="b1337369553"></a>wifiConnectionChange</strong>.</p>
    </td>
    </tr>
    <tr id="row927319143412"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1327371412416"><a name="p1327371412416"></a><a name="p1327371412416"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p15273111419412"><a name="p15273111419412"></a><a name="p15273111419412"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p122737144416"><a name="p122737144416"></a><a name="p122737144416"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p20273171416419"><a name="p20273171416419"></a><a name="p20273171416419"></a>Callback used to report the WLAN connection state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.on\('wifiScanStateChange'\)<sup>7+</sup><a name="section026251312414"></a>

on\(type: "wifiScanStateChange", callback: Callback<number\>\): void

Registers the WLAN scan state change events.

-   Parameters

    <a name="table145251313154118"></a>
    <table><thead align="left"><tr id="row1227313149418"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p927321424114"><a name="p927321424114"></a><a name="p927321424114"></a><strong id="b336585036"><a name="b336585036"></a><a name="b336585036"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p52732143417"><a name="p52732143417"></a><a name="p52732143417"></a><strong id="b1738861383"><a name="b1738861383"></a><a name="b1738861383"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p22731144413"><a name="p22731144413"></a><a name="p22731144413"></a><strong id="b481819501"><a name="b481819501"></a><a name="b481819501"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p172731914174112"><a name="p172731914174112"></a><a name="p172731914174112"></a><strong id="b973552999"><a name="b973552999"></a><a name="b973552999"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row127312146412"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p132731214174116"><a name="p132731214174116"></a><a name="p132731214174116"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p92731014184111"><a name="p92731014184111"></a><a name="p92731014184111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p8273141474113"><a name="p8273141474113"></a><a name="p8273141474113"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p10273201414113"><a name="p10273201414113"></a><a name="p10273201414113"></a>Event type. The value is <strong id="b137741515439"><a name="b137741515439"></a><a name="b137741515439"></a>wifiScanStateChange</strong>.</p>
    </td>
    </tr>
    <tr id="row3273171444117"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1127316143415"><a name="p1127316143415"></a><a name="p1127316143415"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p7273614144112"><a name="p7273614144112"></a><a name="p7273614144112"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p72731214144119"><a name="p72731214144119"></a><a name="p72731214144119"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p13273101444114"><a name="p13273101444114"></a><a name="p13273101444114"></a>Callback invoked to return the WLAN scan state.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Enumerates the WLAN scan states.

    <a name="table1052811314414"></a>
    <table><thead align="left"><tr id="row327412143413"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p327461464119"><a name="p327461464119"></a><a name="p327461464119"></a><strong id="b1847111541431"><a name="b1847111541431"></a><a name="b1847111541431"></a>Value</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p5274214114115"><a name="p5274214114115"></a><a name="p5274214114115"></a><strong id="b1199065089"><a name="b1199065089"></a><a name="b1199065089"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1627419142412"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p327461474113"><a name="p327461474113"></a><a name="p327461474113"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p32741814164116"><a name="p32741814164116"></a><a name="p32741814164116"></a>The scan failed.</p>
    </td>
    </tr>
    <tr id="row827414141419"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1274151464120"><a name="p1274151464120"></a><a name="p1274151464120"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p72741614144118"><a name="p72741614144118"></a><a name="p72741614144118"></a>The scan is successful.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.off\('wifiScanStateChange'\)<sup>7+</sup><a name="section192732136414"></a>

off\(type: "wifiScanStateChange", callback?: Callback<number\>\): void

Unregisters the WLAN scan state change events.

-   Parameters

<a name="table4529111318411"></a>
<table><thead align="left"><tr id="row1427411474111"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p1127416144413"><a name="p1127416144413"></a><a name="p1127416144413"></a><strong id="b604874249"><a name="b604874249"></a><a name="b604874249"></a>Name</strong></p>
</th>
<th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p727451416418"><a name="p727451416418"></a><a name="p727451416418"></a><strong id="b383454517"><a name="b383454517"></a><a name="b383454517"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p12274151416416"><a name="p12274151416416"></a><a name="p12274151416416"></a><strong id="b971850131"><a name="b971850131"></a><a name="b971850131"></a>Mandatory</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p1927471434116"><a name="p1927471434116"></a><a name="p1927471434116"></a><strong id="b766318594"><a name="b766318594"></a><a name="b766318594"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row9274191414410"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p15274151484113"><a name="p15274151484113"></a><a name="p15274151484113"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p5274191444110"><a name="p5274191444110"></a><a name="p5274191444110"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p4274101411410"><a name="p4274101411410"></a><a name="p4274101411410"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1927417146415"><a name="p1927417146415"></a><a name="p1927417146415"></a>Event type. The value is <strong id="b2048976800"><a name="b2048976800"></a><a name="b2048976800"></a>wifiScanStateChange</strong>.</p>
</td>
</tr>
<tr id="row122741147419"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p9274141419416"><a name="p9274141419416"></a><a name="p9274141419416"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p112741314184117"><a name="p112741314184117"></a><a name="p112741314184117"></a>Callback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p1127410141418"><a name="p1127410141418"></a><a name="p1127410141418"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p202741014174114"><a name="p202741014174114"></a><a name="p202741014174114"></a>Callback used to report the WLAN scan state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.</p>
</td>
</tr>
</tbody>
</table>

## wifi.on\('wifiRssiChange'\)<sup>7+</sup><a name="section112800132412"></a>

on\(type: "wifiRssiChange", callback: Callback<number\>\): void

Registers the RSSI state change events.

-   Parameters

    <a name="table1553315137418"></a>
    <table><thead align="left"><tr id="row1727581415416"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p6275214194110"><a name="p6275214194110"></a><a name="p6275214194110"></a><strong id="b1026295863"><a name="b1026295863"></a><a name="b1026295863"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p627541417417"><a name="p627541417417"></a><a name="p627541417417"></a><strong id="b777752246"><a name="b777752246"></a><a name="b777752246"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p1127591464119"><a name="p1127591464119"></a><a name="p1127591464119"></a><strong id="b801688387"><a name="b801688387"></a><a name="b801688387"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p927551419418"><a name="p927551419418"></a><a name="p927551419418"></a><strong id="b1442780958"><a name="b1442780958"></a><a name="b1442780958"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row62753146413"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p2027515148416"><a name="p2027515148416"></a><a name="p2027515148416"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p1927521484117"><a name="p1927521484117"></a><a name="p1927521484117"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p15275131404117"><a name="p15275131404117"></a><a name="p15275131404117"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p142751014134119"><a name="p142751014134119"></a><a name="p142751014134119"></a>Event type. The value is <strong id="b115361619456"><a name="b115361619456"></a><a name="b115361619456"></a>wifiRssiChange</strong>.</p>
    </td>
    </tr>
    <tr id="row1127521418411"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p122754146412"><a name="p122754146412"></a><a name="p122754146412"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p627531464112"><a name="p627531464112"></a><a name="p627531464112"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p192751914114115"><a name="p192751914114115"></a><a name="p192751914114115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1427512146419"><a name="p1427512146419"></a><a name="p1427512146419"></a>Callback invoked to return the RSSI, in dBm.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.off\('wifiRssiChange'\)<sup>7+</sup><a name="section78809479514"></a>

off\(type: "wifiRssiChange", callback?: Callback<number\>\): void

Unregisters the RSSI state change events.

-   Parameters

    <a name="table49041816532"></a>
    <table><thead align="left"><tr id="row169071835316"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p1390191825320"><a name="p1390191825320"></a><a name="p1390191825320"></a><strong id="b1606918534"><a name="b1606918534"></a><a name="b1606918534"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p1690161835313"><a name="p1690161835313"></a><a name="p1690161835313"></a><strong id="b316702654"><a name="b316702654"></a><a name="b316702654"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p209121818535"><a name="p209121818535"></a><a name="p209121818535"></a><strong id="b2113105334"><a name="b2113105334"></a><a name="b2113105334"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p2091111865312"><a name="p2091111865312"></a><a name="p2091111865312"></a><strong id="b1386420052"><a name="b1386420052"></a><a name="b1386420052"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19151820537"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p14911418105311"><a name="p14911418105311"></a><a name="p14911418105311"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p11914185530"><a name="p11914185530"></a><a name="p11914185530"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p1691118195311"><a name="p1691118195311"></a><a name="p1691118195311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p991161811534"><a name="p991161811534"></a><a name="p991161811534"></a>Event type. The value is <strong id="b183928517"><a name="b183928517"></a><a name="b183928517"></a>wifiRssiChange</strong>.</p>
    </td>
    </tr>
    <tr id="row091171845313"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p1791018195319"><a name="p1791018195319"></a><a name="p1791018195319"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p12916183536"><a name="p12916183536"></a><a name="p12916183536"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p179161811533"><a name="p179161811533"></a><a name="p179161811533"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1892151845312"><a name="p1892151845312"></a><a name="p1892151845312"></a>Callback used to report the RSSI. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.on\('hotspotStateChange'\)<sup>7+</sup><a name="section13315111314110"></a>

on\(type: "hotspotStateChange", callback: Callback<number\>\): void

Registers the hotspot state change events.

-   Parameters

    <a name="table75501213134117"></a>
    <table><thead align="left"><tr id="row727841444114"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p727841411411"><a name="p727841411411"></a><a name="p727841411411"></a><strong id="b695539727"><a name="b695539727"></a><a name="b695539727"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p17278314184112"><a name="p17278314184112"></a><a name="p17278314184112"></a><strong id="b1428007906"><a name="b1428007906"></a><a name="b1428007906"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p727818141410"><a name="p727818141410"></a><a name="p727818141410"></a><strong id="b2130314063"><a name="b2130314063"></a><a name="b2130314063"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p8278131411416"><a name="p8278131411416"></a><a name="p8278131411416"></a><strong id="b2108814263"><a name="b2108814263"></a><a name="b2108814263"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1327831464112"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p4278314124114"><a name="p4278314124114"></a><a name="p4278314124114"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p12278101474118"><a name="p12278101474118"></a><a name="p12278101474118"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p927871412411"><a name="p927871412411"></a><a name="p927871412411"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p8278121434115"><a name="p8278121434115"></a><a name="p8278121434115"></a>Event type. The value is <strong id="b1111619278489"><a name="b1111619278489"></a><a name="b1111619278489"></a>hotspotStateChange</strong>.</p>
    </td>
    </tr>
    <tr id="row727811149416"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p0278614134111"><a name="p0278614134111"></a><a name="p0278614134111"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p3278014114115"><a name="p3278014114115"></a><a name="p3278014114115"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p1127811415413"><a name="p1127811415413"></a><a name="p1127811415413"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p11278814134116"><a name="p11278814134116"></a><a name="p11278814134116"></a>Callback invoked to return the hotspot state.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Enumerates the hotspot states.

    <a name="table20553171316418"></a>
    <table><thead align="left"><tr id="row17278131415415"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p9278171444111"><a name="p9278171444111"></a><a name="p9278171444111"></a><strong id="b149731215164918"><a name="b149731215164918"></a><a name="b149731215164918"></a>Value</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p10279181404115"><a name="p10279181404115"></a><a name="p10279181404115"></a><strong id="b47058714"><a name="b47058714"></a><a name="b47058714"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row192791014194118"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p92797149414"><a name="p92797149414"></a><a name="p92797149414"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p182791314104118"><a name="p182791314104118"></a><a name="p182791314104118"></a>Deactivated.</p>
    </td>
    </tr>
    <tr id="row1279151464112"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p2279314154118"><a name="p2279314154118"></a><a name="p2279314154118"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p627981414111"><a name="p627981414111"></a><a name="p627981414111"></a>Activated.</p>
    </td>
    </tr>
    <tr id="row182799148414"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p927916142411"><a name="p927916142411"></a><a name="p927916142411"></a>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p427911142415"><a name="p427911142415"></a><a name="p427911142415"></a>Activating.</p>
    </td>
    </tr>
    <tr id="row112791814104114"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p027971413417"><a name="p027971413417"></a><a name="p027971413417"></a>3</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p1027991417419"><a name="p1027991417419"></a><a name="p1027991417419"></a>Deactivating.</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.off\('hotspotStateChange'\)<sup>7+</sup><a name="section13263136414"></a>

off\(type: "hotspotStateChange", callback?: Callback<number\>\): void

Unregisters the hotspot state change events.

-   Parameters

    <a name="table125561313144119"></a>
    <table><thead align="left"><tr id="row19279191454116"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p42793146414"><a name="p42793146414"></a><a name="p42793146414"></a><strong id="b2076717184"><a name="b2076717184"></a><a name="b2076717184"></a>Name</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p22791314194110"><a name="p22791314194110"></a><a name="p22791314194110"></a><strong id="b1735453769"><a name="b1735453769"></a><a name="b1735453769"></a>Type</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p1927951410419"><a name="p1927951410419"></a><a name="p1927951410419"></a><strong id="b236295997"><a name="b236295997"></a><a name="b236295997"></a>Mandatory</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p1227921454112"><a name="p1227921454112"></a><a name="p1227921454112"></a><strong id="b1535069134"><a name="b1535069134"></a><a name="b1535069134"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1227971454118"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p6279191418411"><a name="p6279191418411"></a><a name="p6279191418411"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p6279614114115"><a name="p6279614114115"></a><a name="p6279614114115"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p17279111474116"><a name="p17279111474116"></a><a name="p17279111474116"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p627941464115"><a name="p627941464115"></a><a name="p627941464115"></a>Event type. The value is <strong id="b121432633"><a name="b121432633"></a><a name="b121432633"></a>hotspotStateChange</strong>.</p>
    </td>
    </tr>
    <tr id="row14279141424118"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p927921410410"><a name="p927921410410"></a><a name="p927921410410"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p62791214104119"><a name="p62791214104119"></a><a name="p62791214104119"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p1279191464118"><a name="p1279191464118"></a><a name="p1279191464118"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p5279161411417"><a name="p5279161411417"></a><a name="p5279161411417"></a>Callback used to report the hotspot state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.</p>
    </td>
    </tr>
    </tbody>
    </table>


