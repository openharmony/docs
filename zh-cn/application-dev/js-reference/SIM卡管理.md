# SIM卡管理<a name="ZH-CN_TOPIC_0000001149458512"></a>

-   [导入模块](#s56d19203690d4782bfc74069abb6bd71)
-   [sim.getSimIccId](#section18529027065)
-   [sim.getSimIccId](#section9200164911401)
-   [sim.getDefaultVoiceSlotId7+](#section3313193864611)
-   [sim.getDefaultVoiceSlotId7+](#section19013665018)
-   [sim.getISOCountryCodeForSim](#section1429719645712)
-   [sim.getISOCountryCodeForSim](#section1087375135713)
-   [sim.getSimOperatorNumeric](#section1245831911019)
-   [sim.getSimOperatorNumeric](#section450711512119)
-   [sim.getSimSpn](#section18826326532)
-   [sim.getSimSpn](#section1862714201148)
-   [sim.getSimState](#section19837481195)
-   [sim.getSimState](#section1763675061914)
-   [sim.getSimGid1](#section18536193963119)
-   [sim.getSimGid1](#section14446155983211)
-   [SimState](#section17389192625218)

>**说明：** 
>
>标记7+的表示从API Version 7开始支持，未标记的表示从API Version 6开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import sim from '@ohos.telephony.sim';
```

## sim.getSimIccId<a name="section18529027065"></a>

getSimIccId\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ICCID（Integrate Circuit Card Identity），使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table799351710213"></a>
    <table><thead align="left"><tr id="row1799411175217"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p899411179212"><a name="p899411179212"></a><a name="p899411179212"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p9994017112117"><a name="p9994017112117"></a><a name="p9994017112117"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p169941617192115"><a name="p169941617192115"></a><a name="p169941617192115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p499491722118"><a name="p499491722118"></a><a name="p499491722118"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row107581022174417"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1231917335444"><a name="p1231917335444"></a><a name="p1231917335444"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p275912223446"><a name="p275912223446"></a><a name="p275912223446"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p27599224442"><a name="p27599224442"></a><a name="p27599224442"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p111750457258"><a name="p111750457258"></a><a name="p111750457258"></a>卡槽ID。</p>
    <p id="p39541754174217"><a name="p39541754174217"></a><a name="p39541754174217"></a>0：卡槽1</p>
    <p id="p1016919004317"><a name="p1016919004317"></a><a name="p1016919004317"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row79942177215"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1299481713210"><a name="p1299481713210"></a><a name="p1299481713210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p112321515195213"><a name="p112321515195213"></a><a name="p112321515195213"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p1599411782114"><a name="p1599411782114"></a><a name="p1599411782114"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p10994181720215"><a name="p10994181720215"></a><a name="p10994181720215"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    sim.getSimIccId(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimIccId<a name="section9200164911401"></a>

getSimIccId\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的ICCID（Integrate Circuit Card Identity），使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table12755202114013"></a>
    <table><thead align="left"><tr id="row167561021508"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p475616211004"><a name="p475616211004"></a><a name="p475616211004"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p157569215016"><a name="p157569215016"></a><a name="p157569215016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p675682117012"><a name="p675682117012"></a><a name="p675682117012"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p167569211502"><a name="p167569211502"></a><a name="p167569211502"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row375616211805"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p77564211303"><a name="p77564211303"></a><a name="p77564211303"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p88212171916"><a name="p88212171916"></a><a name="p88212171916"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p175711211908"><a name="p175711211908"></a><a name="p175711211908"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p11168161813252"><a name="p11168161813252"></a><a name="p11168161813252"></a>卡槽ID。</p>
    <p id="p13165516277"><a name="p13165516277"></a><a name="p13165516277"></a>0：卡槽1</p>
    <p id="p31763112279"><a name="p31763112279"></a><a name="p31763112279"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

- 返回值

    <a name="table11130132420365"></a>
    <table><thead align="left"><tr id="row1213092453617"><th class="cellrowborder" valign="top" width="27.700000000000003%" id="mcps1.1.3.1.1"><p id="p191308246365"><a name="p191308246365"></a><a name="p191308246365"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.3%" id="mcps1.1.3.1.2"><p id="p513092453618"><a name="p513092453618"></a><a name="p513092453618"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row01311524183615"><td class="cellrowborder" valign="top" width="27.700000000000003%" headers="mcps1.1.3.1.1 "><p id="p28631116886"><a name="p28631116886"></a><a name="p28631116886"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.3%" headers="mcps1.1.3.1.2 "><p id="p11311424123610"><a name="p11311424123610"></a><a name="p11311424123610"></a>以Promise形式返回指定卡槽的ICCID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getSimIccId(0);
    promise.then(data => {
        console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimIccId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getDefaultVoiceSlotId<sup>7+</sup><a name="section3313193864611"></a>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void<sup>7+</sup>

获取默认语音业务的卡槽ID，使用callback方式作为异步方法。

-   参数

    <a name="table833910237269"></a>
    <table><thead align="left"><tr id="row20339112312269"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p1533932312268"><a name="p1533932312268"></a><a name="p1533932312268"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.36%" id="mcps1.1.5.1.2"><p id="p1733922332612"><a name="p1733922332612"></a><a name="p1733922332612"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.209999999999999%" id="mcps1.1.5.1.3"><p id="p3339823192619"><a name="p3339823192619"></a><a name="p3339823192619"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.38%" id="mcps1.1.5.1.4"><p id="p3339423102617"><a name="p3339423102617"></a><a name="p3339423102617"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row43400238269"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p18340102382611"><a name="p18340102382611"></a><a name="p18340102382611"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.36%" headers="mcps1.1.5.1.2 "><p id="p1125151014279"><a name="p1125151014279"></a><a name="p1125151014279"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.209999999999999%" headers="mcps1.1.5.1.3 "><p id="p6340142310267"><a name="p6340142310267"></a><a name="p6340142310267"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.1.5.1.4 "><p id="p19176162817"><a name="p19176162817"></a><a name="p19176162817"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getDefaultVoiceSlotId((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getDefaultVoiceSlotId<sup>7+</sup><a name="section19013665018"></a>

getDefaultVoiceSlotId\(\): Promise<number\><sup>7+</sup>

获取默认语音业务的卡槽ID，使用Promise方式作为异步方法。

-   返回值

    <a name="table5831925122216"></a>
    <table><thead align="left"><tr id="row8849255224"><th class="cellrowborder" valign="top" width="27.700000000000003%" id="mcps1.1.3.1.1"><p id="p178452514225"><a name="p178452514225"></a><a name="p178452514225"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.3%" id="mcps1.1.3.1.2"><p id="p3841925152214"><a name="p3841925152214"></a><a name="p3841925152214"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row208482592212"><td class="cellrowborder" valign="top" width="27.700000000000003%" headers="mcps1.1.3.1.1 "><p id="p98415253228"><a name="p98415253228"></a><a name="p98415253228"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.3%" headers="mcps1.1.3.1.2 "><p id="p18841525112217"><a name="p18841525112217"></a><a name="p18841525112217"></a>以Promise形式返回默认语音业务的卡槽ID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getDefaultVoiceSlotId();
    promise.then(data => {
        console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getISOCountryCodeForSim<a name="section1429719645712"></a>

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ISO国家码，使用callback方式作为异步方法。

-   参数

    <a name="table1338013136526"></a>
    <table><thead align="left"><tr id="row1638121318523"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p6381813195216"><a name="p6381813195216"></a><a name="p6381813195216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p238121335213"><a name="p238121335213"></a><a name="p238121335213"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p17381191312526"><a name="p17381191312526"></a><a name="p17381191312526"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p6381141365218"><a name="p6381141365218"></a><a name="p6381141365218"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row163815133526"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p183811313155210"><a name="p183811313155210"></a><a name="p183811313155210"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p8381121335218"><a name="p8381121335218"></a><a name="p8381121335218"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p938110135522"><a name="p938110135522"></a><a name="p938110135522"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p109301512133912"><a name="p109301512133912"></a><a name="p109301512133912"></a>卡槽ID。</p>
    <p id="p3106151812284"><a name="p3106151812284"></a><a name="p3106151812284"></a>0：卡槽1</p>
    <p id="p39219204289"><a name="p39219204289"></a><a name="p39219204289"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row53821913115213"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p13382201312525"><a name="p13382201312525"></a><a name="p13382201312525"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p123821313175215"><a name="p123821313175215"></a><a name="p123821313175215"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p83821613165212"><a name="p83821613165212"></a><a name="p83821613165212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p103822139529"><a name="p103822139529"></a><a name="p103822139529"></a>回调函数。返回国家码，例如：CN（中国）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getISOCountryCodeForSim(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getISOCountryCodeForSim<a name="section1087375135713"></a>

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的ISO国家码，使用Promise方式作为异步方法。

-   参数

    <a name="table53861613185210"></a>
    <table><thead align="left"><tr id="row1138611138529"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p10387813145211"><a name="p10387813145211"></a><a name="p10387813145211"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p16387161365211"><a name="p16387161365211"></a><a name="p16387161365211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p14387171375217"><a name="p14387171375217"></a><a name="p14387171375217"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p83871813195220"><a name="p83871813195220"></a><a name="p83871813195220"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row038710134529"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p338712139523"><a name="p338712139523"></a><a name="p338712139523"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p193871213125217"><a name="p193871213125217"></a><a name="p193871213125217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p9387101311525"><a name="p9387101311525"></a><a name="p9387101311525"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p8855241394"><a name="p8855241394"></a><a name="p8855241394"></a>卡槽ID。</p>
    <p id="p18408326162810"><a name="p18408326162810"></a><a name="p18408326162810"></a>0：卡槽1</p>
    <p id="p14944152992813"><a name="p14944152992813"></a><a name="p14944152992813"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table101095213292"></a>
    <table><thead align="left"><tr id="row1910911213290"><th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.3.1.1"><p id="p6110112122911"><a name="p6110112122911"></a><a name="p6110112122911"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.26%" id="mcps1.1.3.1.2"><p id="p1511072112913"><a name="p1511072112913"></a><a name="p1511072112913"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row31101126298"><td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.3.1.1 "><p id="p14110152132916"><a name="p14110152132916"></a><a name="p14110152132916"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.26%" headers="mcps1.1.3.1.2 "><p id="p711013292911"><a name="p711013292911"></a><a name="p711013292911"></a>以Promise形式返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getISOCountryCodeForSim(0);
    promise.then(data => {
        console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getISOCountryCodeForSim fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name="section1245831911019"></a>

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用callback方式作为异步方法。

-   参数

    <a name="table36924245527"></a>
    <table><thead align="left"><tr id="row1469302475210"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p15693102435213"><a name="p15693102435213"></a><a name="p15693102435213"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p1769382417529"><a name="p1769382417529"></a><a name="p1769382417529"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p1769392415218"><a name="p1769392415218"></a><a name="p1769392415218"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p66931245526"><a name="p66931245526"></a><a name="p66931245526"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row146938245526"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p2693324125216"><a name="p2693324125216"></a><a name="p2693324125216"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p16693124155211"><a name="p16693124155211"></a><a name="p16693124155211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p6693122412528"><a name="p6693122412528"></a><a name="p6693122412528"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p16957193416397"><a name="p16957193416397"></a><a name="p16957193416397"></a>卡槽ID。</p>
    <p id="p82725356289"><a name="p82725356289"></a><a name="p82725356289"></a>0：卡槽1</p>
    <p id="p372173862816"><a name="p372173862816"></a><a name="p372173862816"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row1369332417528"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p96931324115213"><a name="p96931324115213"></a><a name="p96931324115213"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p12694162410529"><a name="p12694162410529"></a><a name="p12694162410529"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p166946245524"><a name="p166946245524"></a><a name="p166946245524"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p4694142485210"><a name="p4694142485210"></a><a name="p4694142485210"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getSimOperatorNumeric(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimOperatorNumeric<a name="section450711512119"></a>

getSimOperatorNumeric\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用Promise方式作为异步方法。

-   参数

    <a name="table66971424195211"></a>
    <table><thead align="left"><tr id="row56971624155210"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p1697142418521"><a name="p1697142418521"></a><a name="p1697142418521"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p11697182485211"><a name="p11697182485211"></a><a name="p11697182485211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p18697124195218"><a name="p18697124195218"></a><a name="p18697124195218"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p6697102415218"><a name="p6697102415218"></a><a name="p6697102415218"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1269722415213"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p269715247521"><a name="p269715247521"></a><a name="p269715247521"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1769722435211"><a name="p1769722435211"></a><a name="p1769722435211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p2698182415211"><a name="p2698182415211"></a><a name="p2698182415211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p1024894853914"><a name="p1024894853914"></a><a name="p1024894853914"></a>卡槽ID。</p>
    <p id="p12400194317285"><a name="p12400194317285"></a><a name="p12400194317285"></a>0：卡槽1</p>
    <p id="p548124592817"><a name="p548124592817"></a><a name="p548124592817"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table107971952142916"></a>
    <table><thead align="left"><tr id="row11797752112911"><th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.3.1.1"><p id="p479735216290"><a name="p479735216290"></a><a name="p479735216290"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.26%" id="mcps1.1.3.1.2"><p id="p17798105212910"><a name="p17798105212910"></a><a name="p17798105212910"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1798185216299"><td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.3.1.1 "><p id="p12798452132920"><a name="p12798452132920"></a><a name="p12798452132920"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.26%" headers="mcps1.1.3.1.2 "><p id="p11798252142918"><a name="p11798252142918"></a><a name="p11798252142918"></a>以Promise形式返回获取指定卡槽SIM卡的归属PLMN号。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getSimOperatorNumeric(0);
    promise.then(data => {
        console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimOperatorNumeric fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimSpn<a name="section18826326532"></a>

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用callback方式作为异步方法。

-   参数

    <a name="table15424192985216"></a>
    <table><thead align="left"><tr id="row10424729155218"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p16424182913523"><a name="p16424182913523"></a><a name="p16424182913523"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p342482955215"><a name="p342482955215"></a><a name="p342482955215"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p5425142935212"><a name="p5425142935212"></a><a name="p5425142935212"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p54252029185215"><a name="p54252029185215"></a><a name="p54252029185215"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16425129205213"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p4425329135210"><a name="p4425329135210"></a><a name="p4425329135210"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p16425132955212"><a name="p16425132955212"></a><a name="p16425132955212"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p1442502935219"><a name="p1442502935219"></a><a name="p1442502935219"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p149631058153912"><a name="p149631058153912"></a><a name="p149631058153912"></a>卡槽ID。</p>
    <p id="p1310535019282"><a name="p1310535019282"></a><a name="p1310535019282"></a>0：卡槽1</p>
    <p id="p1680115312819"><a name="p1680115312819"></a><a name="p1680115312819"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row18425102919524"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p164254292525"><a name="p164254292525"></a><a name="p164254292525"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p6425192935210"><a name="p6425192935210"></a><a name="p6425192935210"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p24251529135211"><a name="p24251529135211"></a><a name="p24251529135211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p1542552915219"><a name="p1542552915219"></a><a name="p1542552915219"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getSimSpn(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimSpn<a name="section1862714201148"></a>

getSimSpn\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用Promise方式作为异步方法。

- 参数

    <a name="table17428182905213"></a>

    <table><thead align="left"><tr id="row1342912296525"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p8429202935220"><a name="p8429202935220"></a><a name="p8429202935220"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p04292295521"><a name="p04292295521"></a><a name="p04292295521"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p17429132955219"><a name="p17429132955219"></a><a name="p17429132955219"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p9429529185210"><a name="p9429529185210"></a><a name="p9429529185210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8429122965213"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p34291329165216"><a name="p34291329165216"></a><a name="p34291329165216"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p114291929145211"><a name="p114291929145211"></a><a name="p114291929145211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p842912975212"><a name="p842912975212"></a><a name="p842912975212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p1662589405"><a name="p1662589405"></a><a name="p1662589405"></a>卡槽ID。</p>
    <p id="p224575932817"><a name="p224575932817"></a><a name="p224575932817"></a>0：卡槽1</p>
    <p id="p1268210222917"><a name="p1268210222917"></a><a name="p1268210222917"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

- 返回值

    <a name="table7107236143015"></a>

    <table><thead align="left"><tr id="row101081836103012"><th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.3.1.1"><p id="p41081536153012"><a name="p41081536153012"></a><a name="p41081536153012"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.26%" id="mcps1.1.3.1.2"><p id="p121081936153019"><a name="p121081936153019"></a><a name="p121081936153019"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row151083369306"><td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.3.1.1 "><p id="p81082036153019"><a name="p81082036153019"></a><a name="p81082036153019"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.26%" headers="mcps1.1.3.1.2 "><p id="p11082036113014"><a name="p11082036113014"></a><a name="p11082036113014"></a>以Promise形式返回获取指定卡槽SIM卡的SPN。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getSimSpn(0);
    promise.then(data => {
        console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimSpn fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## sim.getSimState<a name="section19837481195"></a>

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

获取指定卡槽的SIM卡状态，使用callback方式作为异步方法。

-   参数

    <a name="table3741034155218"></a>
    <table><thead align="left"><tr id="row5741153475215"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p1074143412527"><a name="p1074143412527"></a><a name="p1074143412527"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p374116349525"><a name="p374116349525"></a><a name="p374116349525"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p187417346522"><a name="p187417346522"></a><a name="p187417346522"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p07411434195213"><a name="p07411434195213"></a><a name="p07411434195213"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row187411634145216"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p16741173411524"><a name="p16741173411524"></a><a name="p16741173411524"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p374214340522"><a name="p374214340522"></a><a name="p374214340522"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p19742183495212"><a name="p19742183495212"></a><a name="p19742183495212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p167256163406"><a name="p167256163406"></a><a name="p167256163406"></a>卡槽ID。</p>
    <p id="p74971912299"><a name="p74971912299"></a><a name="p74971912299"></a>0：卡槽1</p>
    <p id="p15870412122918"><a name="p15870412122918"></a><a name="p15870412122918"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row37420349521"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1274214346524"><a name="p1274214346524"></a><a name="p1274214346524"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1274253465216"><a name="p1274253465216"></a><a name="p1274253465216"></a>AsyncCallback&lt;<a href="#section17389192625218">SimState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p374210348528"><a name="p374210348528"></a><a name="p374210348528"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p167426348528"><a name="p167426348528"></a><a name="p167426348528"></a>回调函数。参考<a href="#section17389192625218">SimState</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getSimState(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimState<a name="section1763675061914"></a>

getSimState\(slotId: number\): Promise<SimState\>

获取指定卡槽的SIM卡状态，使用Promise方式作为异步方法。

-   参数

    <a name="table12745113465219"></a>
    <table><thead align="left"><tr id="row57451334165214"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p4745183412527"><a name="p4745183412527"></a><a name="p4745183412527"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p974543414525"><a name="p974543414525"></a><a name="p974543414525"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p14745123425212"><a name="p14745123425212"></a><a name="p14745123425212"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p174543417526"><a name="p174543417526"></a><a name="p174543417526"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11745103425211"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p147451334125212"><a name="p147451334125212"></a><a name="p147451334125212"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1874553416527"><a name="p1874553416527"></a><a name="p1874553416527"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p15746834175211"><a name="p15746834175211"></a><a name="p15746834175211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p37423382401"><a name="p37423382401"></a><a name="p37423382401"></a>卡槽ID。</p>
    <p id="p2792112682919"><a name="p2792112682919"></a><a name="p2792112682919"></a>0：卡槽1</p>
    <p id="p124241530202914"><a name="p124241530202914"></a><a name="p124241530202914"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

- 返回值

    <a name="table152481329173113"></a>

    <table><thead align="left"><tr id="row17249162917318"><th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.3.1.1"><p id="p162492291310"><a name="p162492291310"></a><a name="p162492291310"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.26%" id="mcps1.1.3.1.2"><p id="p8249202919312"><a name="p8249202919312"></a><a name="p8249202919312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8249152912315"><td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.3.1.1 "><p id="p324972915312"><a name="p324972915312"></a><a name="p324972915312"></a>Promise&lt;<a href="#section17389192625218">SimState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.26%" headers="mcps1.1.3.1.2 "><p id="p7249162973117"><a name="p7249162973117"></a><a name="p7249162973117"></a>以Promise形式<span>返回获取指定卡槽的SIM卡状态</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getSimState(0);
    promise.then(data => {
        console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimState fail, promise: err->${JSON.stringify(err)}`);
    });
    ```

## sim.getSimGid1<a name="section18536193963119"></a>

getSimGid1\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的GID1\(Group Identifier Level 1\)，使用callback方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table52601722175313"></a>
    <table><thead align="left"><tr id="row19260152225317"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p626062211535"><a name="p626062211535"></a><a name="p626062211535"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p112601422185317"><a name="p112601422185317"></a><a name="p112601422185317"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p52611225533"><a name="p52611225533"></a><a name="p52611225533"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p1826172275316"><a name="p1826172275316"></a><a name="p1826172275316"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row726115222538"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p152617229536"><a name="p152617229536"></a><a name="p152617229536"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p2261622205312"><a name="p2261622205312"></a><a name="p2261622205312"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p726162265319"><a name="p726162265319"></a><a name="p726162265319"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p411418572423"><a name="p411418572423"></a><a name="p411418572423"></a>卡槽ID。</p>
    <p id="p86321728103111"><a name="p86321728103111"></a><a name="p86321728103111"></a>0：卡槽1</p>
    <p id="p147921430123118"><a name="p147921430123118"></a><a name="p147921430123118"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row1626142285315"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p5261102213538"><a name="p5261102213538"></a><a name="p5261102213538"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p6261422145315"><a name="p6261422145315"></a><a name="p6261422145315"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p32618225531"><a name="p32618225531"></a><a name="p32618225531"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p726142210538"><a name="p726142210538"></a><a name="p726142210538"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    sim.getSimGid1(0, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## sim.getSimGid1<a name="section14446155983211"></a>

getSimGid1\(slotId: number\): Promise<string\>

获取指定卡槽SIM卡的GID1\(Group Identifier Level 1\)，使用Promise方式作为异步方法。

需要ohos.permission.GET\_TELEPHONY\_STATE权限，该权限为系统权限。

-   参数

    <a name="table326442215314"></a>
    <table><thead align="left"><tr id="row1126572235313"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p20265152275313"><a name="p20265152275313"></a><a name="p20265152275313"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p12265222155316"><a name="p12265222155316"></a><a name="p12265222155316"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p02651122185318"><a name="p02651122185318"></a><a name="p02651122185318"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p102657221535"><a name="p102657221535"></a><a name="p102657221535"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1126515227534"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1326532215316"><a name="p1326532215316"></a><a name="p1326532215316"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p82658227535"><a name="p82658227535"></a><a name="p82658227535"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p42651722155320"><a name="p42651722155320"></a><a name="p42651722155320"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p96421581435"><a name="p96421581435"></a><a name="p96421581435"></a>卡槽ID。</p>
    <p id="p157051139103117"><a name="p157051139103117"></a><a name="p157051139103117"></a>0：卡槽1</p>
    <p id="p92821426319"><a name="p92821426319"></a><a name="p92821426319"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

- 返回值

    <a name="table293710220374"></a>

    <table><thead align="left"><tr id="row15938629377"><th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.3.1.1"><p id="p169381727373"><a name="p169381727373"></a><a name="p169381727373"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.26%" id="mcps1.1.3.1.2"><p id="p493813211374"><a name="p493813211374"></a><a name="p493813211374"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1993811216371"><td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.3.1.1 "><p id="p13939172173714"><a name="p13939172173714"></a><a name="p13939172173714"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.26%" headers="mcps1.1.3.1.2 "><p id="p29391023371"><a name="p29391023371"></a><a name="p29391023371"></a>以Promise形式<span>返回</span><span>获取指定卡槽SIM卡的GID1(Group Identifier Level 1)</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = sim.getSimGid1(0);
    promise.then(data => {
        console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getSimGid1 fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## SimState<a name="section17389192625218"></a>

SIM卡状态。

<a name="table5304315818"></a>

<table><thead align="left"><tr id="row1034431582"><th class="cellrowborder" valign="top" width="27.37%" id="mcps1.1.3.1.1"><p id="p741843988"><a name="p741843988"></a><a name="p741843988"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="72.63%" id="mcps1.1.3.1.2"><p id="p94134310819"><a name="p94134310819"></a><a name="p94134310819"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1641643886"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p341243889"><a name="p341243889"></a><a name="p341243889"></a>SIM_STATE_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p548431482"><a name="p548431482"></a><a name="p548431482"></a>SIM卡状态未知，即无法获取准确的状态。</p>
</td>
</tr>
<tr id="row041431811"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p849431084"><a name="p849431084"></a><a name="p849431084"></a>SIM_STATE_NOT_PRESENT</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p19424317818"><a name="p19424317818"></a><a name="p19424317818"></a>表示SIM卡处于not present状态，即卡槽中没有插入SIM卡。</p>
</td>
</tr>
<tr id="row14413431480"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p84643089"><a name="p84643089"></a><a name="p84643089"></a>SIM_STATE_LOCKED</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p194343083"><a name="p194343083"></a><a name="p194343083"></a>表示SIM卡处于locked状态，即SIM卡被PIN、PUK或网络锁锁定。</p>
</td>
</tr>
<tr id="row9474320819"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p1641143489"><a name="p1641143489"></a><a name="p1641143489"></a>SIM_STATE_NOT_READY</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p155443783"><a name="p155443783"></a><a name="p155443783"></a>表示SIM卡处于not ready状态，即SIM卡在位但无法正常工作。</p>
</td>
</tr>
<tr id="row7517431188"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p3512433818"><a name="p3512433818"></a><a name="p3512433818"></a>SIM_STATE_READY</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p165943185"><a name="p165943185"></a><a name="p165943185"></a>表示SIM卡处于ready状态，即SIM卡在位且工作正常。</p>
</td>
</tr>
<tr id="row17518431181"><td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.3.1.1 "><p id="p3514319812"><a name="p3514319812"></a><a name="p3514319812"></a>SIM_STATE_LOADED</p>
</td>
<td class="cellrowborder" valign="top" width="72.63%" headers="mcps1.1.3.1.2 "><p id="p5512436812"><a name="p5512436812"></a><a name="p5512436812"></a>表示SIM卡处于loaded状态，即SIM卡在位且所有卡文件加载完毕。</p>
</td>
</tr>
</tbody>
</table>