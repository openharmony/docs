# WLAN<a name="ZH-CN_TOPIC_0000001198455181"></a>

>**说明：** 
>从 API Version 6 开始支持。


## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import wifi from '@ohos.wifi_native_js';
```


## wifi.isWifiActive<a name="section18961103371615"></a>

isWifiActive\(\): boolean

查询WLAN是否已激活。

-   返回值：

    <a name="table103651813144111"></a>
    <table><thead align="left"><tr id="row924121416413"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p172411514114111"><a name="p172411514114111"></a><a name="p172411514114111"></a><strong id="b12411614164118"><a name="b12411614164118"></a><a name="b12411614164118"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p10241714204114"><a name="p10241714204114"></a><a name="p10241714204114"></a><strong id="b524171484117"><a name="b524171484117"></a><a name="b524171484117"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1024191414110"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p1724121412418"><a name="p1724121412418"></a><a name="p1724121412418"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p132411514194116"><a name="p132411514194116"></a><a name="p132411514194116"></a>true:已激活， false:未激活。</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getSignalLevel<a name="section04714574165"></a>

getSignalLevel\(rssi: number, band: number\): number

查询WLAN信号强度。

-   参数：

    <a name="table123664139419"></a>
    <table><thead align="left"><tr id="row224131444117"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p162411414194112"><a name="p162411414194112"></a><a name="p162411414194112"></a><strong id="b1241714154110"><a name="b1241714154110"></a><a name="b1241714154110"></a>参数名</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p112419148419"><a name="p112419148419"></a><a name="p112419148419"></a><strong id="b13241614164119"><a name="b13241614164119"></a><a name="b13241614164119"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p124111444112"><a name="p124111444112"></a><a name="p124111444112"></a><strong id="b1524118144415"><a name="b1524118144415"></a><a name="b1524118144415"></a>必填</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p10241201404111"><a name="p10241201404111"></a><a name="p10241201404111"></a><strong id="b324151484120"><a name="b324151484120"></a><a name="b324151484120"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row162411314184113"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p52411514124117"><a name="p52411514124117"></a><a name="p52411514124117"></a>rssi</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p7241414144116"><a name="p7241414144116"></a><a name="p7241414144116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p524112141412"><a name="p524112141412"></a><a name="p524112141412"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p13241114144112"><a name="p13241114144112"></a><a name="p13241114144112"></a>热点的信号强度(dBm)。</p>
    </td>
    </tr>
    <tr id="row224141444119"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p124191434119"><a name="p124191434119"></a><a name="p124191434119"></a>band</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p162411514164116"><a name="p162411514164116"></a><a name="p162411514164116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p11241141414115"><a name="p11241141414115"></a><a name="p11241141414115"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p92411214204119"><a name="p92411214204119"></a><a name="p92411214204119"></a>WLAN接入点的频段。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table12369141364112"></a>
    <table><thead align="left"><tr id="row924121464110"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p1724121412419"><a name="p1724121412419"></a><a name="p1724121412419"></a><strong id="b62413143414"><a name="b62413143414"></a><a name="b62413143414"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p324114144414"><a name="p324114144414"></a><a name="p324114144414"></a><strong id="b1224111415412"><a name="b1224111415412"></a><a name="b1224111415412"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row124191414415"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p182421014184112"><a name="p182421014184112"></a><a name="p182421014184112"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p142423146417"><a name="p142423146417"></a><a name="p142423146417"></a>信号强度，取值范围为[0, 4]。</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.scan<a name="section1289134478"></a>

scan\(\): boolean

启动WLAN扫描。

-   返回值：

    <a name="table4426131312411"></a>
    <table><thead align="left"><tr id="row16254131415416"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p42540148412"><a name="p42540148412"></a><a name="p42540148412"></a><strong id="b6254181414112"><a name="b6254181414112"></a><a name="b6254181414112"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p725461404118"><a name="p725461404118"></a><a name="p725461404118"></a><strong id="b8254161414415"><a name="b8254161414415"></a><a name="b8254161414415"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1825451415411"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p92545149412"><a name="p92545149412"></a><a name="p92545149412"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p925481474110"><a name="p925481474110"></a><a name="p925481474110"></a>true:扫描操作成功， false:扫描操作执行失败。</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getScanInfos<a name="section20747137419"></a>

getScanInfos\(\): Promise<Array<WifiScanInfo\>\>

获取扫描结果，使用promise方式作为异步方法。

-   返回值：

    <a name="table042741320417"></a>
    <table><thead align="left"><tr id="row1825451419414"><th class="cellrowborder" valign="top" width="26.26%" id="mcps1.1.3.1.1"><p id="p102541146416"><a name="p102541146416"></a><a name="p102541146416"></a><strong id="b8254514164113"><a name="b8254514164113"></a><a name="b8254514164113"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="73.74000000000001%" id="mcps1.1.3.1.2"><p id="p225419141411"><a name="p225419141411"></a><a name="p225419141411"></a><strong id="b22541149418"><a name="b22541149418"></a><a name="b22541149418"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5254214194111"><td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.1.3.1.1 "><p id="p8254614154113"><a name="p8254614154113"></a><a name="p8254614154113"></a>Promise&lt; Array&lt;<a href="#section138641312414">WifiScanInfo</a>&gt; &gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.74000000000001%" headers="mcps1.1.3.1.2 "><p id="p02548143416"><a name="p02548143416"></a><a name="p02548143416"></a>返回扫描到的热点列表。</p>
    </td>
    </tr>
    </tbody>
    </table>


## wifi.getScanInfos<a name="section1781133414"></a>

getScanInfos\(callback: AsyncCallback<Array<WifiScanInfo\>\>\): void

获取扫描结果，使用callback方式作为异步方法。

-   参数

    <a name="table742911314110"></a>
    
    <table><thead align="left"><tr id="row18254111454118"><th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.1"><p id="p10254151474111"><a name="p10254151474111"></a><a name="p10254151474111"></a><strong id="b7254161410412"><a name="b7254161410412"></a><a name="b7254161410412"></a>参数名</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.5.1.2"><p id="p3254201417411"><a name="p3254201417411"></a><a name="p3254201417411"></a><strong id="b4255171412411"><a name="b4255171412411"></a><a name="b4255171412411"></a>类型</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="7.140000000000001%" id="mcps1.1.5.1.3"><p id="p1255151413415"><a name="p1255151413415"></a><a name="p1255151413415"></a><strong id="b182551214124115"><a name="b182551214124115"></a><a name="b182551214124115"></a>必填</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p17255131416411"><a name="p17255131416411"></a><a name="p17255131416411"></a><strong id="b0255121454116"><a name="b0255121454116"></a><a name="b0255121454116"></a>说明</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1255181444110"><td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.1 "><p id="p10255614204115"><a name="p10255614204115"></a><a name="p10255614204115"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.5.1.2 "><p id="p525516143417"><a name="p525516143417"></a><a name="p525516143417"></a>AsyncCallback&lt; Array&lt;WifiScanInfo&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.140000000000001%" headers="mcps1.1.5.1.3 "><p id="p7255214174113"><a name="p7255214174113"></a><a name="p7255214174113"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p142551714104114"><a name="p142551714104114"></a><a name="p142551714104114"></a>扫描到的热点列表结果回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    import wifi from '@ohos.wifi_native_js';
    
    
    wifi.getScanInfos(result => {
        var len = Object.keys(result).length;
        console.log("received scan info size: " + len);
        for (var i = 0; i < len; ++j) {
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
        console.log("received scan info size: " + len);
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

WLAN热点信息。

<a name="table1443151310414"></a>
<table><thead align="left"><tr id="row3255101434118"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.5.1.1"><p id="p12255201444112"><a name="p12255201444112"></a><a name="p12255201444112"></a><strong id="b82552145417"><a name="b82552145417"></a><a name="b82552145417"></a>参数名</strong></p>
</th>
<th class="cellrowborder" valign="top" width="18.37%" id="mcps1.1.5.1.2"><p id="p17255914204111"><a name="p17255914204111"></a><a name="p17255914204111"></a><strong id="b7255161415417"><a name="b7255161415417"></a><a name="b7255161415417"></a>类型</strong></p>
</th>
<th class="cellrowborder" valign="top" width="9.180000000000001%" id="mcps1.1.5.1.3"><p id="p62551914144114"><a name="p62551914144114"></a><a name="p62551914144114"></a><strong id="b925514143416"><a name="b925514143416"></a><a name="b925514143416"></a>读写属性</strong></p>
</th>
<th class="cellrowborder" valign="top" width="48.980000000000004%" id="mcps1.1.5.1.4"><p id="p7255151410419"><a name="p7255151410419"></a><a name="p7255151410419"></a><strong id="b7255101414118"><a name="b7255101414118"></a><a name="b7255101414118"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row525581484110"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p1925551434111"><a name="p1925551434111"></a><a name="p1925551434111"></a>ssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p925561474115"><a name="p925561474115"></a><a name="p925561474115"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p192551814174118"><a name="p192551814174118"></a><a name="p192551814174118"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p825591416410"><a name="p825591416410"></a><a name="p825591416410"></a>热点的SSID，编码格式为UTF-8。</p>
</td>
</tr>
<tr id="row225521416415"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p13255514134118"><a name="p13255514134118"></a><a name="p13255514134118"></a>bssid</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p2255161444110"><a name="p2255161444110"></a><a name="p2255161444110"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p925614141414"><a name="p925614141414"></a><a name="p925614141414"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12256121419419"><a name="p12256121419419"></a><a name="p12256121419419"></a>热点的BSSID。</p>
</td>
</tr>
<tr id="row525621413414"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p1625651417419"><a name="p1625651417419"></a><a name="p1625651417419"></a>securityType</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p1025651484113"><a name="p1025651484113"></a><a name="p1025651484113"></a>WifiSecurityType</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p202567143410"><a name="p202567143410"></a><a name="p202567143410"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12256714184116"><a name="p12256714184116"></a><a name="p12256714184116"></a>WLAN加密类型。</p>
</td>
</tr>
<tr id="row16256161404114"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p12256151420418"><a name="p12256151420418"></a><a name="p12256151420418"></a>rssi</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p11256161419416"><a name="p11256161419416"></a><a name="p11256161419416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p92565145414"><a name="p92565145414"></a><a name="p92565145414"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p1425621424114"><a name="p1425621424114"></a><a name="p1425621424114"></a>热点的信号强度(dBm)。</p>
</td>
</tr>
<tr id="row14256181415411"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p12256101415419"><a name="p12256101415419"></a><a name="p12256101415419"></a>band</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p9256161412415"><a name="p9256161412415"></a><a name="p9256161412415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p425691464112"><a name="p425691464112"></a><a name="p425691464112"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p12257111454112"><a name="p12257111454112"></a><a name="p12257111454112"></a>WLAN接入点的频段。</p>
</td>
</tr>
<tr id="row1125751434117"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p122571514114120"><a name="p122571514114120"></a><a name="p122571514114120"></a>frequency</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p72575148416"><a name="p72575148416"></a><a name="p72575148416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p825711413415"><a name="p825711413415"></a><a name="p825711413415"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p52571514134116"><a name="p52571514134116"></a><a name="p52571514134116"></a>WLAN接入点的频率。</p>
</td>
</tr>
<tr id="row425701454119"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.5.1.1 "><p id="p3257914104118"><a name="p3257914104118"></a><a name="p3257914104118"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.1.5.1.2 "><p id="p4257514104118"><a name="p4257514104118"></a><a name="p4257514104118"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.180000000000001%" headers="mcps1.1.5.1.3 "><p id="p3257151434119"><a name="p3257151434119"></a><a name="p3257151434119"></a>只读</p>
</td>
<td class="cellrowborder" valign="top" width="48.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p192579145417"><a name="p192579145417"></a><a name="p192579145417"></a>时间戳。</p>
</td>
</tr>
</tbody>
</table>


