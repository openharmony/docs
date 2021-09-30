# 网络搜索<a name="ZH-CN_TOPIC_0000001145113322"></a>

-   [导入模块](#s56d19203690d4782bfc74069abb6bd71)
-   [radio.getRadioTech](#section18401172810207)
-   [radio.getRadioTech](#section686385662419)
-   [radio.getNetworkState](#section2090641619263)
-   [radio.getNetworkState](#section392520433402)
-   [radio.getNetworkState](#section20661545182918)
-   [radio.getNetworkSelectionMode](#section79561056114711)
-   [radio.getNetworkSelectionMode](#section553074612507)
-   [radio.getISOCountryCodeForNetwork7+](#section16183194320525)
-   [radio.getISOCountryCodeForNetwork7+](#section56144132559)
-   [radio.getSignalInformation](#section1153532721018)
-   [radio.getSignalInformation](#section1859512161511)
-   [radio.isRadioOn7+](#section5456161711228)
-   [radio.isRadioOn7+](#section178817520243)
-   [RadioTechnology](#section1072135204020)
-   [SignalInformation](#section10701756164212)
-   [NetworkType](#section519718112466)
-   [NetworkState](#section1691213911470)
-   [RegState](#section18174131911514)
-   [NsaState](#section448018155317)
-   [NetworkSelectionMode](#section14219361268)

>**说明：**
>
>标记7+的表示从API Version 7开始支持，未标记的表示从API Version 6开始支持。


## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import radio from '@ohos.telephony.radio'
```

## radio.getRadioTech<a name="section18401172810207"></a>

getRadioTech\(slotId: number, callback: AsyncCallback<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>\): void

获取当前接入的CS域和PS域无线接入技术，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table799351710213"></a>
    <table><thead align="left"><tr id="row1799411175217"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p899411179212"><a name="p899411179212"></a><a name="p899411179212"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.76%" id="mcps1.1.5.1.2"><p id="p9994017112117"><a name="p9994017112117"></a><a name="p9994017112117"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.26%" id="mcps1.1.5.1.3"><p id="p169941617192115"><a name="p169941617192115"></a><a name="p169941617192115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.93%" id="mcps1.1.5.1.4"><p id="p499491722118"><a name="p499491722118"></a><a name="p499491722118"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row107581022174417"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1231917335444"><a name="p1231917335444"></a><a name="p1231917335444"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.76%" headers="mcps1.1.5.1.2 "><p id="p275912223446"><a name="p275912223446"></a><a name="p275912223446"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26%" headers="mcps1.1.5.1.3 "><p id="p27599224442"><a name="p27599224442"></a><a name="p27599224442"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.93%" headers="mcps1.1.5.1.4 "><p id="p111750457258"><a name="p111750457258"></a><a name="p111750457258"></a>卡槽ID。</p>
    <p id="p39541754174217"><a name="p39541754174217"></a><a name="p39541754174217"></a>0：卡槽1</p>
    <p id="p1016919004317"><a name="p1016919004317"></a><a name="p1016919004317"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row79942177215"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1299481713210"><a name="p1299481713210"></a><a name="p1299481713210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.76%" headers="mcps1.1.5.1.2 "><p id="p112321515195213"><a name="p112321515195213"></a><a name="p112321515195213"></a>AsyncCallback&lt;{psRadioTech: <a href="#section1072135204020">RadioTechnology</a>, csRadioTech: <a href="#section1072135204020">RadioTechnology</a>}&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26%" headers="mcps1.1.5.1.3 "><p id="p1599411782114"><a name="p1599411782114"></a><a name="p1599411782114"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.93%" headers="mcps1.1.5.1.4 "><p id="p10994181720215"><a name="p10994181720215"></a><a name="p10994181720215"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    radio.getRadioTech(slotId, (err, data) =>{ 
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getRadioTech<a name="section686385662419"></a>

getRadioTech\(slotId: number\): Promise<\{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology\}\>

获取当前接入的CS域和PS域无线接入技术，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table125907710127"></a>
    <table><thead align="left"><tr id="row1659112714124"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p175911273125"><a name="p175911273125"></a><a name="p175911273125"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p14591157191213"><a name="p14591157191213"></a><a name="p14591157191213"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p125911791210"><a name="p125911791210"></a><a name="p125911791210"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p1459110712122"><a name="p1459110712122"></a><a name="p1459110712122"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row159111720120"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p14591177151217"><a name="p14591177151217"></a><a name="p14591177151217"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p11591177201215"><a name="p11591177201215"></a><a name="p11591177201215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p7591117181212"><a name="p7591117181212"></a><a name="p7591117181212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p359112718122"><a name="p359112718122"></a><a name="p359112718122"></a>卡槽ID。</p>
    <p id="p19591137181219"><a name="p19591137181219"></a><a name="p19591137181219"></a>0：卡槽1</p>
    <p id="p5591072124"><a name="p5591072124"></a><a name="p5591072124"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table11130132420365"></a>
    <table><thead align="left"><tr id="row1213092453617"><th class="cellrowborder" valign="top" width="50.94%" id="mcps1.1.3.1.1"><p id="p191308246365"><a name="p191308246365"></a><a name="p191308246365"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.059999999999995%" id="mcps1.1.3.1.2"><p id="p513092453618"><a name="p513092453618"></a><a name="p513092453618"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row01311524183615"><td class="cellrowborder" valign="top" width="50.94%" headers="mcps1.1.3.1.1 "><p id="p28631116886"><a name="p28631116886"></a><a name="p28631116886"></a>Promise&lt;{psRadioTech: <a href="#section1072135204020">RadioTechnology</a>, csRadioTech: <a href="#section1072135204020">RadioTechnology</a>}&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.059999999999995%" headers="mcps1.1.3.1.2 "><p id="p11311424123610"><a name="p11311424123610"></a><a name="p11311424123610"></a>以Promise形式<span>返回</span><span>获取当前接入的CS域和PS域技术</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = radio.getRadioTech(slotId);
    promise.then(data => {
        console.log(`getRadioTech success, data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getRadioTech fail, err->${JSON.stringify(err)}`);
    });
    ```


## radio.getNetworkState<a name="section2090641619263"></a>

getNetworkState\(callback: AsyncCallback<NetworkState\>\): void

获取网络状态，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table1133014121782"></a>
    <table><thead align="left"><tr id="row4330111211811"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p833161216811"><a name="p833161216811"></a><a name="p833161216811"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p033111121185"><a name="p033111121185"></a><a name="p033111121185"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p1233110127818"><a name="p1233110127818"></a><a name="p1233110127818"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p1233119121882"><a name="p1233119121882"></a><a name="p1233119121882"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63317121487"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p633118122815"><a name="p633118122815"></a><a name="p633118122815"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p150313319819"><a name="p150313319819"></a><a name="p150313319819"></a>AsyncCallback&lt;<a href="#section1691213911470">NetworkState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p3331171217820"><a name="p3331171217820"></a><a name="p3331171217820"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p1533161212817"><a name="p1533161212817"></a><a name="p1533161212817"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    radio.getNetworkState((err, data) =>{
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkState<a name="section392520433402"></a>

getNetworkState\(slotId: number, callback: AsyncCallback<NetworkState\>\): void

获取网络状态，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table11928163052718"></a>
    <table><thead align="left"><tr id="row199283309273"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p49281530182712"><a name="p49281530182712"></a><a name="p49281530182712"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p129283306273"><a name="p129283306273"></a><a name="p129283306273"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p15928123012278"><a name="p15928123012278"></a><a name="p15928123012278"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p79284305276"><a name="p79284305276"></a><a name="p79284305276"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1292853016277"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p9928143082716"><a name="p9928143082716"></a><a name="p9928143082716"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p09298306275"><a name="p09298306275"></a><a name="p09298306275"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p1892914308275"><a name="p1892914308275"></a><a name="p1892914308275"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p1092913032717"><a name="p1092913032717"></a><a name="p1092913032717"></a>卡槽ID。</p>
    <p id="p392918309278"><a name="p392918309278"></a><a name="p392918309278"></a>0：卡槽1</p>
    <p id="p15929030192713"><a name="p15929030192713"></a><a name="p15929030192713"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row199291302270"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p0929130162711"><a name="p0929130162711"></a><a name="p0929130162711"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1992993032712"><a name="p1992993032712"></a><a name="p1992993032712"></a>AsyncCallback&lt;<a href="#section1691213911470">NetworkState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p2929183042710"><a name="p2929183042710"></a><a name="p2929183042710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p129291308276"><a name="p129291308276"></a><a name="p129291308276"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    radio.getNetworkState(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkState<a name="section20661545182918"></a>

getNetworkState\(slotId?: number\): Promise<NetworkState\>

获取网络状态，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table65021374111"></a>
    <table><thead align="left"><tr id="row150151312414"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p175061334120"><a name="p175061334120"></a><a name="p175061334120"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p195021364111"><a name="p195021364111"></a><a name="p195021364111"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p1350913134110"><a name="p1350913134110"></a><a name="p1350913134110"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p205091319419"><a name="p205091319419"></a><a name="p205091319419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6501513184114"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1931012820452"><a name="p1931012820452"></a><a name="p1931012820452"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1031014286451"><a name="p1031014286451"></a><a name="p1031014286451"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p1131022813452"><a name="p1131022813452"></a><a name="p1131022813452"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p10310928164516"><a name="p10310928164516"></a><a name="p10310928164516"></a>卡槽ID。</p>
    <p id="p10311928124516"><a name="p10311928124516"></a><a name="p10311928124516"></a>0：卡槽1</p>
    <p id="p131142814456"><a name="p131142814456"></a><a name="p131142814456"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table041714530438"></a>
    <table><thead align="left"><tr id="row18418853104314"><th class="cellrowborder" valign="top" width="26.419999999999998%" id="mcps1.1.3.1.1"><p id="p11418553184319"><a name="p11418553184319"></a><a name="p11418553184319"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.58%" id="mcps1.1.3.1.2"><p id="p1941885354313"><a name="p1941885354313"></a><a name="p1941885354313"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16418253194313"><td class="cellrowborder" valign="top" width="26.419999999999998%" headers="mcps1.1.3.1.1 "><p id="p84416171396"><a name="p84416171396"></a><a name="p84416171396"></a>Promise&lt;<a href="#section1691213911470">NetworkState</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.58%" headers="mcps1.1.3.1.2 "><p id="p1537012718231"><a name="p1537012718231"></a><a name="p1537012718231"></a>以Promise形式返回网络状态。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = radio.getNetworkState(slotId);
    promise.then(data => {
        console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getNetworkState fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## radio.getNetworkSelectionMode<a name="section79561056114711"></a>

getNetworkSelectionMode\(slotId: number, callback: AsyncCallback<NetworkSelectionMode\>\): void

获取当前选网模式，使用callback方式作为异步方法。

-   参数

    <a name="table474813715499"></a>
    <table><thead align="left"><tr id="row1374814711498"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p13748137194915"><a name="p13748137194915"></a><a name="p13748137194915"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p37481719495"><a name="p37481719495"></a><a name="p37481719495"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p87481714913"><a name="p87481714913"></a><a name="p87481714913"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p9748157124912"><a name="p9748157124912"></a><a name="p9748157124912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1074857154914"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1074837134913"><a name="p1074837134913"></a><a name="p1074837134913"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p07489714919"><a name="p07489714919"></a><a name="p07489714919"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p37481717493"><a name="p37481717493"></a><a name="p37481717493"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p17748176496"><a name="p17748176496"></a><a name="p17748176496"></a>卡槽ID。</p>
    <p id="p2748673497"><a name="p2748673497"></a><a name="p2748673497"></a>0：卡槽1</p>
    <p id="p8748970499"><a name="p8748970499"></a><a name="p8748970499"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row127482774919"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p177481764920"><a name="p177481764920"></a><a name="p177481764920"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p14749275495"><a name="p14749275495"></a><a name="p14749275495"></a>AsyncCallback&lt;<a href="#section14219361268">NetworkSelectionMode</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p874910724910"><a name="p874910724910"></a><a name="p874910724910"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p474917710499"><a name="p474917710499"></a><a name="p474917710499"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    radio.getNetworkSelectionMode(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getNetworkSelectionMode<a name="section553074612507"></a>

getNetworkSelectionMode\(slotId: number\): Promise<NetworkSelectionMode\>

获取当前选网模式，使用Promise方式作为异步方法。

-   参数

    <a name="table2530104655016"></a>
    <table><thead align="left"><tr id="row125311446175016"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p1353110468506"><a name="p1353110468506"></a><a name="p1353110468506"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p115311468502"><a name="p115311468502"></a><a name="p115311468502"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p15531204685014"><a name="p15531204685014"></a><a name="p15531204685014"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p10531546105013"><a name="p10531546105013"></a><a name="p10531546105013"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4531174695017"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p165311746125015"><a name="p165311746125015"></a><a name="p165311746125015"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p185312463502"><a name="p185312463502"></a><a name="p185312463502"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p165311546155018"><a name="p165311546155018"></a><a name="p165311546155018"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p20531204614508"><a name="p20531204614508"></a><a name="p20531204614508"></a>卡槽ID。</p>
    <p id="p353134613501"><a name="p353134613501"></a><a name="p353134613501"></a>0：卡槽1</p>
    <p id="p85313462508"><a name="p85313462508"></a><a name="p85313462508"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table549425625112"></a>
    <table><thead align="left"><tr id="row1249475613515"><th class="cellrowborder" valign="top" width="39.129999999999995%" id="mcps1.1.3.1.1"><p id="p9494185617519"><a name="p9494185617519"></a><a name="p9494185617519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.870000000000005%" id="mcps1.1.3.1.2"><p id="p1449415610512"><a name="p1449415610512"></a><a name="p1449415610512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1749495611517"><td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.3.1.1 "><p id="p184941456145112"><a name="p184941456145112"></a><a name="p184941456145112"></a>Promise&lt;<a href="#section14219361268">NetworkSelectionMode</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.870000000000005%" headers="mcps1.1.3.1.2 "><p id="p849415562515"><a name="p849415562515"></a><a name="p849415562515"></a>以Promise形式返回当前选网模式。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = radio.getNetworkSelectionMode(slotId);
    promise.then(data => {
        console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getNetworkSelectionMode fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name="section16183194320525"></a>

getISOCountryCodeForNetwork\(slotId: number, callback: AsyncCallback<string\>\): void

获取注册网络所在国家的ISO国家码，使用callback方式作为异步方法。

-   参数

    <a name="table577030205412"></a>
    <table><thead align="left"><tr id="row197719017543"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p577117016544"><a name="p577117016544"></a><a name="p577117016544"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p1177150125418"><a name="p1177150125418"></a><a name="p1177150125418"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p187717019541"><a name="p187717019541"></a><a name="p187717019541"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p87718015419"><a name="p87718015419"></a><a name="p87718015419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row077118019543"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1377117013545"><a name="p1377117013545"></a><a name="p1377117013545"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p1572174331119"><a name="p1572174331119"></a><a name="p1572174331119"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p377112016542"><a name="p377112016542"></a><a name="p377112016542"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p13148175975910"><a name="p13148175975910"></a><a name="p13148175975910"></a>卡槽ID。</p>
    <p id="p2148659155913"><a name="p2148659155913"></a><a name="p2148659155913"></a>0：卡槽1</p>
    <p id="p214855925911"><a name="p214855925911"></a><a name="p214855925911"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row9772701543"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1977220014542"><a name="p1977220014542"></a><a name="p1977220014542"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p6772160205414"><a name="p6772160205414"></a><a name="p6772160205414"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p777220017542"><a name="p777220017542"></a><a name="p777220017542"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p12772150105420"><a name="p12772150105420"></a><a name="p12772150105420"></a>回调函数。返回国家码，例如：CN（中国）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    radio.getISOCountryCodeForNetwork(slotId, (err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getISOCountryCodeForNetwork<sup>7+</sup><a name="section56144132559"></a>

getISOCountryCodeForNetwork\(slotId: number\): Promise<string\>

获取注册网络所在国家的ISO国家码，使用Promise方式作为异步方法。

-   参数

    <a name="table152728255611"></a>
    <table><thead align="left"><tr id="row927352125610"><th class="cellrowborder" valign="top" width="11.05%" id="mcps1.1.5.1.1"><p id="p1327372165611"><a name="p1327372165611"></a><a name="p1327372165611"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="42%" id="mcps1.1.5.1.2"><p id="p172731224566"><a name="p172731224566"></a><a name="p172731224566"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.42%" id="mcps1.1.5.1.3"><p id="p9273626569"><a name="p9273626569"></a><a name="p9273626569"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.53%" id="mcps1.1.5.1.4"><p id="p72733245613"><a name="p72733245613"></a><a name="p72733245613"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row32737215613"><td class="cellrowborder" valign="top" width="11.05%" headers="mcps1.1.5.1.1 "><p id="p1427311216568"><a name="p1427311216568"></a><a name="p1427311216568"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="42%" headers="mcps1.1.5.1.2 "><p id="p202739212562"><a name="p202739212562"></a><a name="p202739212562"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.42%" headers="mcps1.1.5.1.3 "><p id="p122731323565"><a name="p122731323565"></a><a name="p122731323565"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.53%" headers="mcps1.1.5.1.4 "><p id="p15811441804"><a name="p15811441804"></a><a name="p15811441804"></a>卡槽ID。</p>
    <p id="p181241801"><a name="p181241801"></a><a name="p181241801"></a>0：卡槽1</p>
    <p id="p18254701"><a name="p18254701"></a><a name="p18254701"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table13274112165615"></a>
    <table><thead align="left"><tr id="row2274152185612"><th class="cellrowborder" valign="top" width="26.419999999999998%" id="mcps1.1.3.1.1"><p id="p927412275611"><a name="p927412275611"></a><a name="p927412275611"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.58%" id="mcps1.1.3.1.2"><p id="p2027415216563"><a name="p2027415216563"></a><a name="p2027415216563"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row32748295615"><td class="cellrowborder" valign="top" width="26.419999999999998%" headers="mcps1.1.3.1.1 "><p id="p12274102115614"><a name="p12274102115614"></a><a name="p12274102115614"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.58%" headers="mcps1.1.3.1.2 "><p id="p132743214560"><a name="p132743214560"></a><a name="p132743214560"></a>以Promise形式返回注册网络所在国家的ISO国家码，例如CN（中国）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = radio.getISOCountryCodeForNetwork(slotId);
    promise.then(data => {
        console.log(`getISOCountryCodeForNetwork success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.log(`getISOCountryCodeForNetwork fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## radio.getSignalInformation<a name="section1153532721018"></a>

getSignalInformation\(slotId: number, callback: AsyncCallback<Array<SignalInformation\>\>\): void

获取指定SIM卡槽对应的注册网络信号强度信息列表，使用callback方式作为异步方法。

-   参数

    <a name="table1061723612116"></a>
    <table><thead align="left"><tr id="row5617336171118"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p661833613111"><a name="p661833613111"></a><a name="p661833613111"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.550000000000004%" id="mcps1.1.5.1.2"><p id="p4618133681114"><a name="p4618133681114"></a><a name="p4618133681114"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.92%" id="mcps1.1.5.1.3"><p id="p18618173610115"><a name="p18618173610115"></a><a name="p18618173610115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.5%" id="mcps1.1.5.1.4"><p id="p56180360114"><a name="p56180360114"></a><a name="p56180360114"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1361816361115"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1661843641119"><a name="p1661843641119"></a><a name="p1661843641119"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.5.1.2 "><p id="p1061843651117"><a name="p1061843651117"></a><a name="p1061843651117"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.1.5.1.3 "><p id="p761175974216"><a name="p761175974216"></a><a name="p761175974216"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.5%" headers="mcps1.1.5.1.4 "><p id="p971654194213"><a name="p971654194213"></a><a name="p971654194213"></a>卡槽ID。</p>
    <p id="p8719545423"><a name="p8719545423"></a><a name="p8719545423"></a>0：卡槽1</p>
    <p id="p0711254194218"><a name="p0711254194218"></a><a name="p0711254194218"></a>1：卡槽2</p>
    </td>
    </tr>
    <tr id="row1661913611113"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p10619103610112"><a name="p10619103610112"></a><a name="p10619103610112"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.5.1.2 "><p id="p8619173671111"><a name="p8619173671111"></a><a name="p8619173671111"></a>AsyncCallback&lt;Array&lt;<a href="#section10701756164212">SignalInformation</a>&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.1.5.1.3 "><p id="p861933610118"><a name="p861933610118"></a><a name="p861933610118"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.5%" headers="mcps1.1.5.1.4 "><p id="p861912364116"><a name="p861912364116"></a><a name="p861912364116"></a>回调函数，返回<a href="#section10701756164212">SignalInformation</a>对象的数组。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    radio.getSignalInformation(slotId, (err, data) => {
       console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.getSignalInformation<a name="section1859512161511"></a>

getSignalInformation\(slotId: number\): Promise<Array<SignalInformation\>\>

获取指定SIM卡槽对应的注册网络信号强度信息列表，使用Promise方式作为异步方法。

-   参数

    <a name="table11589811191613"></a>
    <table><thead align="left"><tr id="row558971111617"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p658961121619"><a name="p658961121619"></a><a name="p658961121619"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.550000000000004%" id="mcps1.1.5.1.2"><p id="p1758941151610"><a name="p1758941151610"></a><a name="p1758941151610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.139999999999999%" id="mcps1.1.5.1.3"><p id="p1758919111164"><a name="p1758919111164"></a><a name="p1758919111164"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.28%" id="mcps1.1.5.1.4"><p id="p658916113164"><a name="p658916113164"></a><a name="p658916113164"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15589191118166"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p258921171613"><a name="p258921171613"></a><a name="p258921171613"></a>slotId</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.5.1.2 "><p id="p1759018111168"><a name="p1759018111168"></a><a name="p1759018111168"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.139999999999999%" headers="mcps1.1.5.1.3 "><p id="p1359051110161"><a name="p1359051110161"></a><a name="p1359051110161"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.28%" headers="mcps1.1.5.1.4 "><p id="p488718104314"><a name="p488718104314"></a><a name="p488718104314"></a>卡槽ID。</p>
    <p id="p88872817438"><a name="p88872817438"></a><a name="p88872817438"></a>0：卡槽1</p>
    <p id="p11887138144315"><a name="p11887138144315"></a><a name="p11887138144315"></a>1：卡槽2</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table1159021111163"></a>
    <table><thead align="left"><tr id="row7590811181610"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p115901114164"><a name="p115901114164"></a><a name="p115901114164"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p859016114165"><a name="p859016114165"></a><a name="p859016114165"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row75911811101617"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p8591171115160"><a name="p8591171115160"></a><a name="p8591171115160"></a>Promise&lt;Array&lt;<a href="#section10701756164212">SignalInformation</a>&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p159191118166"><a name="p159191118166"></a><a name="p159191118166"></a>以Promise形式返回网络信号强度<a href="#section10701756164212">SignalInformation</a>对象的数组。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let slotId = 0;
    let promise = radio.getSignalInformation(slotId);
    promise.then(data => {
        console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`getSignalInformation fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## radio.isRadioOn<sup>7+</sup><a name="section5456161711228"></a>

isRadioOn\(callback: AsyncCallback<boolean\>\): void

判断Radio是否打开，使用callback方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   参数

    <a name="table16621218192311"></a>
    <table><thead align="left"><tr id="row16628188235"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p766231810235"><a name="p766231810235"></a><a name="p766231810235"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.77%" id="mcps1.1.5.1.2"><p id="p4663131812313"><a name="p4663131812313"></a><a name="p4663131812313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.45%" id="mcps1.1.5.1.3"><p id="p19663121892310"><a name="p19663121892310"></a><a name="p19663121892310"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.75%" id="mcps1.1.5.1.4"><p id="p11663418112315"><a name="p11663418112315"></a><a name="p11663418112315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row166637182231"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p116632186237"><a name="p116632186237"></a><a name="p116632186237"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.77%" headers="mcps1.1.5.1.2 "><p id="p12663518122318"><a name="p12663518122318"></a><a name="p12663518122318"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.45%" headers="mcps1.1.5.1.3 "><p id="p17663121813232"><a name="p17663121813232"></a><a name="p17663121813232"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.75%" headers="mcps1.1.5.1.4 "><p id="p766310184235"><a name="p766310184235"></a><a name="p766310184235"></a>回调函数。</p>
    <p id="p12663101892317"><a name="p12663101892317"></a><a name="p12663101892317"></a>true：Radio打开</p>
    <p id="p8663181852316"><a name="p8663181852316"></a><a name="p8663181852316"></a>false：Radio关闭</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    radio.isRadioOn((err, data) => {
        console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    });
    ```


## radio.isRadioOn<sup>7+</sup><a name="section178817520243"></a>

isRadioOn\(\): Promise<boolean\>

判断Radio是否打开，使用Promise方式作为异步方法。

需要ohos.permission.GET\_NETWORK\_INFO权限。

-   返回值

    <a name="table1089962622517"></a>
    <table><thead align="left"><tr id="row1290042613253"><th class="cellrowborder" valign="top" width="26.419999999999998%" id="mcps1.1.3.1.1"><p id="p1590072682510"><a name="p1590072682510"></a><a name="p1590072682510"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.58%" id="mcps1.1.3.1.2"><p id="p1190042652517"><a name="p1190042652517"></a><a name="p1190042652517"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14900152617253"><td class="cellrowborder" valign="top" width="26.419999999999998%" headers="mcps1.1.3.1.1 "><p id="p2900172614252"><a name="p2900172614252"></a><a name="p2900172614252"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.58%" headers="mcps1.1.3.1.2 "><p id="p11900182612518"><a name="p11900182612518"></a><a name="p11900182612518"></a>以Promise形式返回判断Radio是否打开的结果。</p>
    <p id="p290052615251"><a name="p290052615251"></a><a name="p290052615251"></a>true：Radio打开</p>
    <p id="p290018264259"><a name="p290018264259"></a><a name="p290018264259"></a>false：Radio关闭</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let promise = radio.isRadioOn();
    promise.then(data => {
        console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
    }).catch(err => {
        console.error(`isRadioOn fail, promise: err->${JSON.stringify(err)}`);
    });
    ```


## RadioTechnology<a name="section1072135204020"></a>

无线接入技术。

<a name="table0381514104112"></a>

<table><thead align="left"><tr id="row9381121434113"><th class="cellrowborder" valign="top" width="34.953495349534954%" id="mcps1.1.4.1.1"><p id="p1538171414110"><a name="p1538171414110"></a><a name="p1538171414110"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="11.021102110211022%" id="mcps1.1.4.1.2"><p id="p923145715145"><a name="p923145715145"></a><a name="p923145715145"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="54.02540254025403%" id="mcps1.1.4.1.3"><p id="p738101484113"><a name="p738101484113"></a><a name="p738101484113"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row20381111417414"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p18382151414110"><a name="p18382151414110"></a><a name="p18382151414110"></a>RADIO_TECHNOLOGY_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p1123125741418"><a name="p1123125741418"></a><a name="p1123125741418"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p738221417411"><a name="p738221417411"></a><a name="p738221417411"></a>未知无线接入技术（RAT）。</p>
</td>
</tr>
<tr id="row6382171434119"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p5382014134114"><a name="p5382014134114"></a><a name="p5382014134114"></a>RADIO_TECHNOLOGY_GSM</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p5231257131412"><a name="p5231257131412"></a><a name="p5231257131412"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p1426645312125"><a name="p1426645312125"></a><a name="p1426645312125"></a>无线接入技术GSM（Global System For Mobile Communication）。</p>
</td>
</tr>
<tr id="row4382914104115"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p10382181464115"><a name="p10382181464115"></a><a name="p10382181464115"></a>RADIO_TECHNOLOGY_1XRTT</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p823195781418"><a name="p823195781418"></a><a name="p823195781418"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p63831214174116"><a name="p63831214174116"></a><a name="p63831214174116"></a>无线接入技术1XRTT（Single-Carrier Radio Transmission Technology）。</p>
</td>
</tr>
<tr id="row1383201444113"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p16383121420413"><a name="p16383121420413"></a><a name="p16383121420413"></a>RADIO_TECHNOLOGY_WCDMA</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p172345717145"><a name="p172345717145"></a><a name="p172345717145"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p838431454114"><a name="p838431454114"></a><a name="p838431454114"></a>无线接入技术WCDMA（Wideband Code Division Multiple Access）。</p>
</td>
</tr>
<tr id="row123841214204119"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p19384314164111"><a name="p19384314164111"></a><a name="p19384314164111"></a>RADIO_TECHNOLOGY_HSPA</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p1023457161417"><a name="p1023457161417"></a><a name="p1023457161417"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p153841414164111"><a name="p153841414164111"></a><a name="p153841414164111"></a>无线接入技术HSPA（High Speed Packet Access）。</p>
</td>
</tr>
<tr id="row1438561454118"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p238581418410"><a name="p238581418410"></a><a name="p238581418410"></a>RADIO_TECHNOLOGY_HSPAP</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p623125720142"><a name="p623125720142"></a><a name="p623125720142"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p654462715234"><a name="p654462715234"></a><a name="p654462715234"></a>无线接入技术HSPAP（High Speed packet access (HSPA+) ）。</p>
</td>
</tr>
<tr id="row153856148415"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p153854146414"><a name="p153854146414"></a><a name="p153854146414"></a>RADIO_TECHNOLOGY_TD_SCDMA</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p5238578147"><a name="p5238578147"></a><a name="p5238578147"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p73851614144114"><a name="p73851614144114"></a><a name="p73851614144114"></a>无线接入技术TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。</p>
</td>
</tr>
<tr id="row20385914144118"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p12386614144116"><a name="p12386614144116"></a><a name="p12386614144116"></a>RADIO_TECHNOLOGY_EVDO</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p13235578149"><a name="p13235578149"></a><a name="p13235578149"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p18386214164119"><a name="p18386214164119"></a><a name="p18386214164119"></a>无线接入技术EVDO（Evolution、Data Only）。</p>
</td>
</tr>
<tr id="row14386181444117"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p1386161420417"><a name="p1386161420417"></a><a name="p1386161420417"></a>RADIO_TECHNOLOGY_EHRPD</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p4236579145"><a name="p4236579145"></a><a name="p4236579145"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p0815111425214"><a name="p0815111425214"></a><a name="p0815111425214"></a>无线接入技术EHRPD（Evolved High Rate Package Data）。</p>
</td>
</tr>
<tr id="row16389101413415"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p1139091474115"><a name="p1139091474115"></a><a name="p1139091474115"></a>RADIO_TECHNOLOGY_LTE</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p122395715146"><a name="p122395715146"></a><a name="p122395715146"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p639011418416"><a name="p639011418416"></a><a name="p639011418416"></a>无线接入技术LTE（Long Term Evolution）。</p>
</td>
</tr>
<tr id="row53901144414"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p4390181484116"><a name="p4390181484116"></a><a name="p4390181484116"></a>RADIO_TECHNOLOGY_LTE_CA</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p162385719147"><a name="p162385719147"></a><a name="p162385719147"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p16390121464116"><a name="p16390121464116"></a><a name="p16390121464116"></a>无线接入技术LTE_CA（Long Term Evolution_Carrier Aggregation）。</p>
</td>
</tr>
<tr id="row43905141411"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p1739091414110"><a name="p1739091414110"></a><a name="p1739091414110"></a>RADIO_TECHNOLOGY_IWLAN</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p8232057121414"><a name="p8232057121414"></a><a name="p8232057121414"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p9391191474110"><a name="p9391191474110"></a><a name="p9391191474110"></a>无线接入技术IWLAN（Industrial Wireless LAN）。</p>
</td>
</tr>
<tr id="row153917149411"><td class="cellrowborder" valign="top" width="34.953495349534954%" headers="mcps1.1.4.1.1 "><p id="p239118143418"><a name="p239118143418"></a><a name="p239118143418"></a>RADIO_TECHNOLOGY_NR</p>
</td>
<td class="cellrowborder" valign="top" width="11.021102110211022%" headers="mcps1.1.4.1.2 "><p id="p7237573146"><a name="p7237573146"></a><a name="p7237573146"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="54.02540254025403%" headers="mcps1.1.4.1.3 "><p id="p9391121419416"><a name="p9391121419416"></a><a name="p9391121419416"></a>无线接入技术NR（New Radio）。</p>
</td>
</tr>
</tbody>
</table>

## SignalInformation<a name="section10701756164212"></a>

网络信号强度信息对象。

<a name="table15599174814312"></a>
<table><thead align="left"><tr id="row125991548184313"><th class="cellrowborder" valign="top" width="34.4034403440344%" id="mcps1.1.4.1.1"><p id="p17599848174311"><a name="p17599848174311"></a><a name="p17599848174311"></a>属性名</p>
</th>
<th class="cellrowborder" valign="top" width="20.89208920892089%" id="mcps1.1.4.1.2"><p id="p165996488433"><a name="p165996488433"></a><a name="p165996488433"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.704470447044706%" id="mcps1.1.4.1.3"><p id="p559954854315"><a name="p559954854315"></a><a name="p559954854315"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1360044844315"><td class="cellrowborder" valign="top" width="34.4034403440344%" headers="mcps1.1.4.1.1 "><p id="p2600154864317"><a name="p2600154864317"></a><a name="p2600154864317"></a>signalType</p>
</td>
<td class="cellrowborder" valign="top" width="20.89208920892089%" headers="mcps1.1.4.1.2 "><p id="p1960014844311"><a name="p1960014844311"></a><a name="p1960014844311"></a><a href="#section519718112466">NetworkType</a></p>
</td>
<td class="cellrowborder" valign="top" width="44.704470447044706%" headers="mcps1.1.4.1.3 "><p id="p760084810435"><a name="p760084810435"></a><a name="p760084810435"></a>网络信号强度类型。</p>
</td>
</tr>
<tr id="row5600648124317"><td class="cellrowborder" valign="top" width="34.4034403440344%" headers="mcps1.1.4.1.1 "><p id="p1060014884311"><a name="p1060014884311"></a><a name="p1060014884311"></a>signalLevel</p>
</td>
<td class="cellrowborder" valign="top" width="20.89208920892089%" headers="mcps1.1.4.1.2 "><p id="p14600144814436"><a name="p14600144814436"></a><a name="p14600144814436"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.704470447044706%" headers="mcps1.1.4.1.3 "><p id="p1360094874317"><a name="p1360094874317"></a><a name="p1360094874317"></a>网络信号强度等级。</p>
</td>
</tr>
</tbody>
</table>

## NetworkType<a name="section519718112466"></a>

网络类型。

<a name="table169468114719"></a>

<table><thead align="left"><tr id="row19946141204716"><th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.4.1.1"><p id="p19946111184714"><a name="p19946111184714"></a><a name="p19946111184714"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="11.85%" id="mcps1.1.4.1.2"><p id="p199467115477"><a name="p199467115477"></a><a name="p199467115477"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="58.56%" id="mcps1.1.4.1.3"><p id="p1387273215116"><a name="p1387273215116"></a><a name="p1387273215116"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18947191134714"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p10947215473"><a name="p10947215473"></a><a name="p10947215473"></a>NETWORK_TYPE_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p694715114717"><a name="p694715114717"></a><a name="p694715114717"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p13872123215111"><a name="p13872123215111"></a><a name="p13872123215111"></a>未知网络类型。</p>
</td>
</tr>
<tr id="row19947512478"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p1994716112477"><a name="p1994716112477"></a><a name="p1994716112477"></a>NETWORK_TYPE_GSM</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p09471311474"><a name="p09471311474"></a><a name="p09471311474"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p18872133231117"><a name="p18872133231117"></a><a name="p18872133231117"></a>网络类型为GSM（Global System For Mobile Communication）。</p>
</td>
</tr>
<tr id="row194716112479"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p5947181154720"><a name="p5947181154720"></a><a name="p5947181154720"></a>NETWORK_TYPE_CDMA</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p494861154718"><a name="p494861154718"></a><a name="p494861154718"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p76281531111318"><a name="p76281531111318"></a><a name="p76281531111318"></a>网络类型为CDMA（Code Division Multiple Access）。</p>
</td>
</tr>
<tr id="row294817154719"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p6948121134711"><a name="p6948121134711"></a><a name="p6948121134711"></a>NETWORK_TYPE_WCDMA</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p11948612475"><a name="p11948612475"></a><a name="p11948612475"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p956153291315"><a name="p956153291315"></a><a name="p956153291315"></a>网络类型为WCDMA（Wideband Code Division Multiple Access）。</p>
</td>
</tr>
<tr id="row1794817118475"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p8948311475"><a name="p8948311475"></a><a name="p8948311475"></a>NETWORK_TYPE_TDSCDMA</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p39492134718"><a name="p39492134718"></a><a name="p39492134718"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p17358203301314"><a name="p17358203301314"></a><a name="p17358203301314"></a>网络类型为TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。</p>
</td>
</tr>
<tr id="row39491314476"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p139491712474"><a name="p139491712474"></a><a name="p139491712474"></a>NETWORK_TYPE_LTE</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p139493113479"><a name="p139493113479"></a><a name="p139493113479"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p17282834141317"><a name="p17282834141317"></a><a name="p17282834141317"></a>网络类型为LTE（Long Term Evolution）。</p>
</td>
</tr>
<tr id="row7949515473"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.4.1.1 "><p id="p20950151114718"><a name="p20950151114718"></a><a name="p20950151114718"></a>NETWORK_TYPE_NR</p>
</td>
<td class="cellrowborder" valign="top" width="11.85%" headers="mcps1.1.4.1.2 "><p id="p1950131164710"><a name="p1950131164710"></a><a name="p1950131164710"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="58.56%" headers="mcps1.1.4.1.3 "><p id="p12872143291113"><a name="p12872143291113"></a><a name="p12872143291113"></a>网络类型为5G NR（New Radio）。</p>
</td>
</tr>
</tbody>
</table>


## NetworkState<a name="section1691213911470"></a>

网络注册状态。

<a name="table14636181774820"></a>
<table><thead align="left"><tr id="row1263781714819"><th class="cellrowborder" valign="top" width="21.57%" id="mcps1.1.4.1.1"><p id="p8637131764817"><a name="p8637131764817"></a><a name="p8637131764817"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="17.14%" id="mcps1.1.4.1.2"><p id="p16637317174815"><a name="p16637317174815"></a><a name="p16637317174815"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.4.1.3"><p id="p1041654112217"><a name="p1041654112217"></a><a name="p1041654112217"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15637917164813"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p17637617174816"><a name="p17637617174816"></a><a name="p17637617174816"></a>longOperatorName</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p86378179487"><a name="p86378179487"></a><a name="p86378179487"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p124161741172213"><a name="p124161741172213"></a><a name="p124161741172213"></a>注册网络的长运营商名称。</p>
</td>
</tr>
<tr id="row963719172483"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p6637131716488"><a name="p6637131716488"></a><a name="p6637131716488"></a>shortOperatorName</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p8638417184820"><a name="p8638417184820"></a><a name="p8638417184820"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p16416174117229"><a name="p16416174117229"></a><a name="p16416174117229"></a>注册网络的短运营商名称。</p>
</td>
</tr>
<tr id="row15638917184813"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p063891718484"><a name="p063891718484"></a><a name="p063891718484"></a>plmnNumeric</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p126387173485"><a name="p126387173485"></a><a name="p126387173485"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p54168419229"><a name="p54168419229"></a><a name="p54168419229"></a>注册网络的PLMN码。</p>
</td>
</tr>
<tr id="row663811784813"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p1263811712484"><a name="p1263811712484"></a><a name="p1263811712484"></a>isRoaming</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p13638181734816"><a name="p13638181734816"></a><a name="p13638181734816"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p9416114118220"><a name="p9416114118220"></a><a name="p9416114118220"></a>是否处于漫游状态。</p>
</td>
</tr>
<tr id="row063861734816"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p116394172485"><a name="p116394172485"></a><a name="p116394172485"></a>regState</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p1963951713482"><a name="p1963951713482"></a><a name="p1963951713482"></a><a href="#section18174131911514">RegState</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p12416114142214"><a name="p12416114142214"></a><a name="p12416114142214"></a>设备的网络注册状态。</p>
</td>
</tr>
<tr id="row963941719485"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p1763919175480"><a name="p1763919175480"></a><a name="p1763919175480"></a>nsaState</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p13639111794814"><a name="p13639111794814"></a><a name="p13639111794814"></a><a href="#section448018155317">NsaState</a></p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p641684114224"><a name="p641684114224"></a><a name="p641684114224"></a>设备的NSA网络注册状态。</p>
</td>
</tr>
<tr id="row163901754816"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p10639181717481"><a name="p10639181717481"></a><a name="p10639181717481"></a>isCaActive</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p96391178489"><a name="p96391178489"></a><a name="p96391178489"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p10416124119227"><a name="p10416124119227"></a><a name="p10416124119227"></a>CA的状态。</p>
</td>
</tr>
<tr id="row126392017124814"><td class="cellrowborder" valign="top" width="21.57%" headers="mcps1.1.4.1.1 "><p id="p1164061784815"><a name="p1164061784815"></a><a name="p1164061784815"></a>isEmergency</p>
</td>
<td class="cellrowborder" valign="top" width="17.14%" headers="mcps1.1.4.1.2 "><p id="p56401317204812"><a name="p56401317204812"></a><a name="p56401317204812"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.4.1.3 "><p id="p1141624122217"><a name="p1141624122217"></a><a name="p1141624122217"></a>此设备是否只允许拨打紧急呼叫。</p>
</td>
</tr>
</tbody>
</table>

## RegState<a name="section18174131911514"></a>

网络注册状态。

<a name="table10902144118519"></a>
<table><thead align="left"><tr id="row1290316411519"><th class="cellrowborder" valign="top" width="39.89%" id="mcps1.1.4.1.1"><p id="p13903441175110"><a name="p13903441175110"></a><a name="p13903441175110"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="8.6%" id="mcps1.1.4.1.2"><p id="p114671121109"><a name="p114671121109"></a><a name="p114671121109"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="51.51%" id="mcps1.1.4.1.3"><p id="p15903144110513"><a name="p15903144110513"></a><a name="p15903144110513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row890394125118"><td class="cellrowborder" valign="top" width="39.89%" headers="mcps1.1.4.1.1 "><p id="p4903114117517"><a name="p4903114117517"></a><a name="p4903114117517"></a>REG_STATE_NO_SERVICE</p>
</td>
<td class="cellrowborder" valign="top" width="8.6%" headers="mcps1.1.4.1.2 "><p id="p63116311601"><a name="p63116311601"></a><a name="p63116311601"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="51.51%" headers="mcps1.1.4.1.3 "><p id="p11904204116516"><a name="p11904204116516"></a><a name="p11904204116516"></a>设备不能使用任何服务。</p>
</td>
</tr>
<tr id="row69041416512"><td class="cellrowborder" valign="top" width="39.89%" headers="mcps1.1.4.1.1 "><p id="p1990464145113"><a name="p1990464145113"></a><a name="p1990464145113"></a>REG_STATE_IN_SERVICE</p>
</td>
<td class="cellrowborder" valign="top" width="8.6%" headers="mcps1.1.4.1.2 "><p id="p12318311201"><a name="p12318311201"></a><a name="p12318311201"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="51.51%" headers="mcps1.1.4.1.3 "><p id="p5904124117510"><a name="p5904124117510"></a><a name="p5904124117510"></a>设备可以正常使用业务。</p>
</td>
</tr>
<tr id="row1790444111513"><td class="cellrowborder" valign="top" width="39.89%" headers="mcps1.1.4.1.1 "><p id="p4904124115114"><a name="p4904124115114"></a><a name="p4904124115114"></a>REG_STATE_EMERGENCY_CALL_ONLY</p>
</td>
<td class="cellrowborder" valign="top" width="8.6%" headers="mcps1.1.4.1.2 "><p id="p831103116014"><a name="p831103116014"></a><a name="p831103116014"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="51.51%" headers="mcps1.1.4.1.3 "><p id="p2905164125113"><a name="p2905164125113"></a><a name="p2905164125113"></a>设备只能使用紧急呼叫业务。</p>
</td>
</tr>
<tr id="row13905134155112"><td class="cellrowborder" valign="top" width="39.89%" headers="mcps1.1.4.1.1 "><p id="p2090554114517"><a name="p2090554114517"></a><a name="p2090554114517"></a>REG_STATE_POWER_OFF</p>
</td>
<td class="cellrowborder" valign="top" width="8.6%" headers="mcps1.1.4.1.2 "><p id="p17311831701"><a name="p17311831701"></a><a name="p17311831701"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="51.51%" headers="mcps1.1.4.1.3 "><p id="p49051241195116"><a name="p49051241195116"></a><a name="p49051241195116"></a>蜂窝无线电已关闭。</p>
</td>
</tr>
</tbody>
</table>

## NsaState<a name="section448018155317"></a>

非独立组网状态。

<a name="table14733122165317"></a>
<table><thead align="left"><tr id="row17734172155311"><th class="cellrowborder" valign="top" width="31.64%" id="mcps1.1.4.1.1"><p id="p573442114538"><a name="p573442114538"></a><a name="p573442114538"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="8.19%" id="mcps1.1.4.1.2"><p id="p93344475918"><a name="p93344475918"></a><a name="p93344475918"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="60.17%" id="mcps1.1.4.1.3"><p id="p147341921155319"><a name="p147341921155319"></a><a name="p147341921155319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1973402111537"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p1073502120538"><a name="p1073502120538"></a><a name="p1073502120538"></a>NSA_STATE_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p941614817596"><a name="p941614817596"></a><a name="p941614817596"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p207355214533"><a name="p207355214533"></a><a name="p207355214533"></a>设备在不支持NSA的LTE小区下处于空闲状态或连接状态。</p>
</td>
</tr>
<tr id="row773514215536"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p273552135316"><a name="p273552135316"></a><a name="p273552135316"></a>NSA_STATE_NO_DETECT</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p24167488593"><a name="p24167488593"></a><a name="p24167488593"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p1973562110534"><a name="p1973562110534"></a><a name="p1973562110534"></a>在支持NSA但不支持NR覆盖检测的LTE小区下，设备处于空闲状态。</p>
</td>
</tr>
<tr id="row073512214530"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p1873615217534"><a name="p1873615217534"></a><a name="p1873615217534"></a>NSA_STATE_CONNECTED_DETECT</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p164163487594"><a name="p164163487594"></a><a name="p164163487594"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p14601215104116"><a name="p14601215104116"></a><a name="p14601215104116"></a>设备在LTE小区下连接到LTE网络支持NSA和NR覆盖检测。</p>
</td>
</tr>
<tr id="row873672165310"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p1873642117539"><a name="p1873642117539"></a><a name="p1873642117539"></a>NSA_STATE_IDLE_DETECT</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p141714484593"><a name="p141714484593"></a><a name="p141714484593"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p0736122115536"><a name="p0736122115536"></a><a name="p0736122115536"></a>支持NSA和NR覆盖检测的LTE小区下设备处于空闲状态。</p>
</td>
</tr>
<tr id="row5736132165315"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p47378214537"><a name="p47378214537"></a><a name="p47378214537"></a>NSA_STATE_DUAL_CONNECTED</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p7417144895917"><a name="p7417144895917"></a><a name="p7417144895917"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p273710215539"><a name="p273710215539"></a><a name="p273710215539"></a>设备在支持NSA的LTE小区下连接到LTE + NR网络。</p>
</td>
</tr>
<tr id="row17737121165319"><td class="cellrowborder" valign="top" width="31.64%" headers="mcps1.1.4.1.1 "><p id="p1873732111538"><a name="p1873732111538"></a><a name="p1873732111538"></a>NSA_STATE_SA_ATTACHED</p>
</td>
<td class="cellrowborder" valign="top" width="8.19%" headers="mcps1.1.4.1.2 "><p id="p2417154810591"><a name="p2417154810591"></a><a name="p2417154810591"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="60.17%" headers="mcps1.1.4.1.3 "><p id="p197371921165317"><a name="p197371921165317"></a><a name="p197371921165317"></a>设备在5GC附着时在NG-RAN小区下空闲或连接到NG-RAN小区。</p>
</td>
</tr>
</tbody>
</table>

## NetworkSelectionMode<a name="section14219361268"></a>

选网模式。

<a name="table15891165716617"></a>

<table><thead align="left"><tr id="row689105713614"><th class="cellrowborder" valign="top" width="33.78%" id="mcps1.1.4.1.1"><p id="p589165719612"><a name="p589165719612"></a><a name="p589165719612"></a>变量</p>
</th>
<th class="cellrowborder" valign="top" width="15.43%" id="mcps1.1.4.1.2"><p id="p889114571869"><a name="p889114571869"></a><a name="p889114571869"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="50.79%" id="mcps1.1.4.1.3"><p id="p04101554174620"><a name="p04101554174620"></a><a name="p04101554174620"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1589117571365"><td class="cellrowborder" valign="top" width="33.78%" headers="mcps1.1.4.1.1 "><p id="p1989275716618"><a name="p1989275716618"></a><a name="p1989275716618"></a>NETWORK_SELECTION_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="15.43%" headers="mcps1.1.4.1.2 "><p id="p178921578616"><a name="p178921578616"></a><a name="p178921578616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.79%" headers="mcps1.1.4.1.3 "><p id="p541011547461"><a name="p541011547461"></a><a name="p541011547461"></a>未知选网模式。</p>
</td>
</tr>
<tr id="row1089245714617"><td class="cellrowborder" valign="top" width="33.78%" headers="mcps1.1.4.1.1 "><p id="p18921557369"><a name="p18921557369"></a><a name="p18921557369"></a>NETWORK_SELECTION_AUTOMATIC</p>
</td>
<td class="cellrowborder" valign="top" width="15.43%" headers="mcps1.1.4.1.2 "><p id="p489255718612"><a name="p489255718612"></a><a name="p489255718612"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="50.79%" headers="mcps1.1.4.1.3 "><p id="p104105544465"><a name="p104105544465"></a><a name="p104105544465"></a>自动选网模式。</p>
</td>
</tr>
<tr id="row13892155719619"><td class="cellrowborder" valign="top" width="33.78%" headers="mcps1.1.4.1.1 "><p id="p18921571165"><a name="p18921571165"></a><a name="p18921571165"></a>NETWORK_SELECTION_MANUAL</p>
</td>
<td class="cellrowborder" valign="top" width="15.43%" headers="mcps1.1.4.1.2 "><p id="p1489345710611"><a name="p1489345710611"></a><a name="p1489345710611"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="50.79%" headers="mcps1.1.4.1.3 "><p id="p741015444617"><a name="p741015444617"></a><a name="p741015444617"></a>手动选网模式。</p>
</td>
</tr>
</tbody>
</table>