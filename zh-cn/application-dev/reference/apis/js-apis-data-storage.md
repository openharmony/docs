# 轻量级存储<a name="ZH-CN_TOPIC_0000001154532408"></a>

轻量级存储为应用提供key-value键值型的文件数据处理能力，支持应用对数据进行轻量级存储及查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 6 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import dataStorage from '@ohos.data.storage';
```

## 权限<a name="section11257113618419"></a>

无

## 属性<a name="section7299123218370"></a>

<a name="table1540155452420"></a>
<table><thead align="left"><tr id="row1947713549244"><th class="cellrowborder" valign="top" width="22.720000000000002%" id="mcps1.1.6.1.1"><p id="p74771754102410"><a name="p74771754102410"></a><a name="p74771754102410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.839999999999998%" id="mcps1.1.6.1.2"><p id="p1047755412411"><a name="p1047755412411"></a><a name="p1047755412411"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.97%" id="mcps1.1.6.1.3"><p id="p34782054192412"><a name="p34782054192412"></a><a name="p34782054192412"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.95%" id="mcps1.1.6.1.4"><p id="p1847865452413"><a name="p1847865452413"></a><a name="p1847865452413"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="44.519999999999996%" id="mcps1.1.6.1.5"><p id="p12478954132419"><a name="p12478954132419"></a><a name="p12478954132419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1247811541240"><td class="cellrowborder" valign="top" width="22.720000000000002%" headers="mcps1.1.6.1.1 "><p id="p51525360147"><a name="p51525360147"></a><a name="p51525360147"></a>MAX_KEY_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.839999999999998%" headers="mcps1.1.6.1.2 "><p id="p9478135414243"><a name="p9478135414243"></a><a name="p9478135414243"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="p1247885492411"><a name="p1247885492411"></a><a name="p1247885492411"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.6.1.4 "><p id="p3478054192416"><a name="p3478054192416"></a><a name="p3478054192416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.519999999999996%" headers="mcps1.1.6.1.5 "><p id="p12478654172415"><a name="p12478654172415"></a><a name="p12478654172415"></a>key的最大长度限制，大小为80字节。</p>
</td>
</tr>
<tr id="row184789546249"><td class="cellrowborder" valign="top" width="22.720000000000002%" headers="mcps1.1.6.1.1 "><p id="p1971014525154"><a name="p1971014525154"></a><a name="p1971014525154"></a>MAX_VALUE_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.839999999999998%" headers="mcps1.1.6.1.2 "><p id="p1392172791820"><a name="p1392172791820"></a><a name="p1392172791820"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="p1870905231512"><a name="p1870905231512"></a><a name="p1870905231512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.6.1.4 "><p id="p137081152141516"><a name="p137081152141516"></a><a name="p137081152141516"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.519999999999996%" headers="mcps1.1.6.1.5 "><p id="p1470645211154"><a name="p1470645211154"></a><a name="p1470645211154"></a>string类型value的最大长度限制，大小为8192字节。</p>
</td>
</tr>
</tbody>
</table>

## dataStorage.getStorageSync<a name="section172447329132"></a>

getStorageSync\(path: string\): Storage

读取指定文件，将数据加载到Storage实例，用于数据操作，此方法为同步方法。

-   参数：

    <a name="table2720134112170"></a>
    <table><thead align="left"><tr id="row18721041131710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19721184111716"><a name="p19721184111716"></a><a name="p19721184111716"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p672184171715"><a name="p672184171715"></a><a name="p672184171715"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p972174116173"><a name="p972174116173"></a><a name="p972174116173"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1372134161712"><a name="p1372134161712"></a><a name="p1372134161712"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11721541121717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1472154117175"><a name="p1472154117175"></a><a name="p1472154117175"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p372134110175"><a name="p372134110175"></a><a name="p372134110175"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19721134101713"><a name="p19721134101713"></a><a name="p19721134101713"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1068312615010"><a name="p1068312615010"></a><a name="p1068312615010"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table372204131719"></a>
    <table><thead align="left"><tr id="row8722124116175"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p4722041171712"><a name="p4722041171712"></a><a name="p4722041171712"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p072234114173"><a name="p072234114173"></a><a name="p072234114173"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4722144111715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p16723164161713"><a name="p16723164161713"></a><a name="p16723164161713"></a><a href="#section12882825611">Storage</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p12723741161713"><a name="p12723741161713"></a><a name="p12723741161713"></a>获取到要操作的Storage实例，用于进行数据存储操作。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const PATH = '{storage_path_name_in_working_folder}';
    let store = dataStorage.getStorageSync(PATH);
    ```


## dataStorage.getStorage<a name="section192192415554"></a>

getStorage\(path: string, callback: AsyncCallback<Storage\>\): void

读取指定文件，将数据加载到Storage实例，用于数据操作，使用callback形式返回结果。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.42174549000487%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.511945392491468%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.614822038030226%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p77021147102715"><a name="p77021147102715"></a><a name="p77021147102715"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    <tr id="row128961021101812"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p6897172121814"><a name="p6897172121814"></a><a name="p6897172121814"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p9897102181813"><a name="p9897102181813"></a><a name="p9897102181813"></a>AsyncCallback&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p188982219189"><a name="p188982219189"></a><a name="p188982219189"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p989815213187"><a name="p989815213187"></a><a name="p989815213187"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    dataStorage.getStorage(PATH, function(err, data) {    
       store = data;
    });
    ```


## dataStorage.getStorage<a name="section761705115251"></a>

getStorage\(path: string\): Promise<Storage\>

读取指定文件，将数据加载到Storage实例，用于数据操作，使用Promise方式作为异步方法。

-   参数：

    <a name="table206180511253"></a>
    <table><thead align="left"><tr id="row126181951152513"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p20618155112513"><a name="p20618155112513"></a><a name="p20618155112513"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.700633837152608%" id="mcps1.1.5.1.2"><p id="p561885114256"><a name="p561885114256"></a><a name="p561885114256"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.628961482203803%" id="mcps1.1.5.1.3"><p id="p561814519259"><a name="p561814519259"></a><a name="p561814519259"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21891760117016%" id="mcps1.1.5.1.4"><p id="p1861845120252"><a name="p1861845120252"></a><a name="p1861845120252"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6619751162515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p196192514253"><a name="p196192514253"></a><a name="p196192514253"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.700633837152608%" headers="mcps1.1.5.1.2 "><p id="p36191951162515"><a name="p36191951162515"></a><a name="p36191951162515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.628961482203803%" headers="mcps1.1.5.1.3 "><p id="p16191051162511"><a name="p16191051162511"></a><a name="p16191051162511"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21891760117016%" headers="mcps1.1.5.1.4 "><p id="p7722105418272"><a name="p7722105418272"></a><a name="p7722105418272"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table2619551122516"></a>
    <table><thead align="left"><tr id="row46201751152513"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1162075110255"><a name="p1162075110255"></a><a name="p1162075110255"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p46202512251"><a name="p46202512251"></a><a name="p46202512251"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row562015514258"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p146201551122516"><a name="p146201551122516"></a><a name="p146201551122516"></a>Promise&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1062005172514"><a name="p1062005172514"></a><a name="p1062005172514"></a>Promise实例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = dataStorage.getStorage(PATH);
    promise.then((data) => {   
       data.clearSync();
    }).catch((err) => {
    });
    ```


## dataStorage.deleteStorageSync<a name="section1396463815379"></a>

deleteStorageSync\(path: string\): void

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，此方法为同步方法。

-   参数：

    <a name="table99651538193711"></a>
    <table><thead align="left"><tr id="row1296553843712"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19965183833714"><a name="p19965183833714"></a><a name="p19965183833714"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p9965153863713"><a name="p9965153863713"></a><a name="p9965153863713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15965133819375"><a name="p15965133819375"></a><a name="p15965133819375"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p496518383377"><a name="p496518383377"></a><a name="p496518383377"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6965238143718"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p18965163816378"><a name="p18965163816378"></a><a name="p18965163816378"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10965193816372"><a name="p10965193816372"></a><a name="p10965193816372"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p896623833719"><a name="p896623833719"></a><a name="p896623833719"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p157012058162714"><a name="p157012058162714"></a><a name="p157012058162714"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    dataStorage.deleteStorageSync(PATH);
    ```


## dataStorage.deleteStorage<a name="section17967123883712"></a>

deleteStorage\(path: string, callback: AsyncCallback<Storage\>\)

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，使用callback方式作为异步方法。

-   参数：

    <a name="table1296893843713"></a>
    <table><thead align="left"><tr id="row5968193863710"><th class="cellrowborder" valign="top" width="11.59434422233057%" id="mcps1.1.5.1.1"><p id="p99681338103714"><a name="p99681338103714"></a><a name="p99681338103714"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.67528035104826%" id="mcps1.1.5.1.2"><p id="p1968838123715"><a name="p1968838123715"></a><a name="p1968838123715"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.3373963920039%" id="mcps1.1.5.1.3"><p id="p14968123803720"><a name="p14968123803720"></a><a name="p14968123803720"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.39297903461725%" id="mcps1.1.5.1.4"><p id="p7968238143715"><a name="p7968238143715"></a><a name="p7968238143715"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row129691538133719"><td class="cellrowborder" valign="top" width="11.59434422233057%" headers="mcps1.1.5.1.1 "><p id="p14969438143718"><a name="p14969438143718"></a><a name="p14969438143718"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.67528035104826%" headers="mcps1.1.5.1.2 "><p id="p9969123873716"><a name="p9969123873716"></a><a name="p9969123873716"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.3373963920039%" headers="mcps1.1.5.1.3 "><p id="p159691438173711"><a name="p159691438173711"></a><a name="p159691438173711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.39297903461725%" headers="mcps1.1.5.1.4 "><p id="p06171654601"><a name="p06171654601"></a><a name="p06171654601"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    <tr id="row9969173819374"><td class="cellrowborder" valign="top" width="11.59434422233057%" headers="mcps1.1.5.1.1 "><p id="p69691238153715"><a name="p69691238153715"></a><a name="p69691238153715"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.67528035104826%" headers="mcps1.1.5.1.2 "><p id="p149691380378"><a name="p149691380378"></a><a name="p149691380378"></a>AsyncCallback&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.3373963920039%" headers="mcps1.1.5.1.3 "><p id="p2969103843715"><a name="p2969103843715"></a><a name="p2969103843715"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.39297903461725%" headers="mcps1.1.5.1.4 "><p id="p396915388374"><a name="p396915388374"></a><a name="p396915388374"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    dataStorage.deleteStorage(PATH, function(err, data) {
    });
    ```


## dataStorage.deleteStorage<a name="section1497163823719"></a>

deleteStorage\(path: string\): Promise<void\>

从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题，使用promise方式作为异步方法。

-   参数：

    <a name="table597293815378"></a>
    <table><thead align="left"><tr id="row29721938203716"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p19972173883714"><a name="p19972173883714"></a><a name="p19972173883714"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p49721938103718"><a name="p49721938103718"></a><a name="p49721938103718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p17972113863711"><a name="p17972113863711"></a><a name="p17972113863711"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p15972838123714"><a name="p15972838123714"></a><a name="p15972838123714"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1972163818374"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p597373833717"><a name="p597373833717"></a><a name="p597373833717"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p11973173814378"><a name="p11973173814378"></a><a name="p11973173814378"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p209732388379"><a name="p209732388379"></a><a name="p209732388379"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p7812982288"><a name="p7812982288"></a><a name="p7812982288"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table5973738153710"></a>
    <table><thead align="left"><tr id="row17973238123713"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p17973538183719"><a name="p17973538183719"></a><a name="p17973538183719"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p109731385374"><a name="p109731385374"></a><a name="p109731385374"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row89731838173711"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p34467362719"><a name="p34467362719"></a><a name="p34467362719"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p15446536474"><a name="p15446536474"></a><a name="p15446536474"></a>Promise实例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = dataStorage.deleteStorage(PATH);
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


## dataStorage.removeStorageFromCacheSync<a name="section1212418572425"></a>

removeStorageFromCacheSync\(path: string\): void

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为同步方法。

-   参数：

    <a name="table121245571424"></a>
    <table><thead align="left"><tr id="row61241257164218"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13125165744216"><a name="p13125165744216"></a><a name="p13125165744216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p141259575429"><a name="p141259575429"></a><a name="p141259575429"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1312515724213"><a name="p1312515724213"></a><a name="p1312515724213"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6125157124212"><a name="p6125157124212"></a><a name="p6125157124212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1112595715421"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1712610572429"><a name="p1712610572429"></a><a name="p1712610572429"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p5126457164217"><a name="p5126457164217"></a><a name="p5126457164217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19126457134212"><a name="p19126457134212"></a><a name="p19126457134212"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1724911392818"><a name="p1724911392818"></a><a name="p1724911392818"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    dataStorage.removeStorageFromCacheSync(PATH);
    ```


## dataStorage.removeStorageFromCache<a name="section141288570429"></a>

removeStorageFromCache\(path: string, callback: AsyncCallback<Storage\>\): void

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

-   参数：

    <a name="table12128115713423"></a>
    <table><thead align="left"><tr id="row131291857124212"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p181291157174220"><a name="p181291157174220"></a><a name="p181291157174220"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.29497805948318%" id="mcps1.1.5.1.2"><p id="p20129205715426"><a name="p20129205715426"></a><a name="p20129205715426"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.664553876157972%" id="mcps1.1.5.1.3"><p id="p21294574428"><a name="p21294574428"></a><a name="p21294574428"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.58898098488542%" id="mcps1.1.5.1.4"><p id="p512965716425"><a name="p512965716425"></a><a name="p512965716425"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row21299574423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p17129105714421"><a name="p17129105714421"></a><a name="p17129105714421"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.29497805948318%" headers="mcps1.1.5.1.2 "><p id="p7129185794217"><a name="p7129185794217"></a><a name="p7129185794217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.664553876157972%" headers="mcps1.1.5.1.3 "><p id="p813075717426"><a name="p813075717426"></a><a name="p813075717426"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.58898098488542%" headers="mcps1.1.5.1.4 "><p id="p3442141014113"><a name="p3442141014113"></a><a name="p3442141014113"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    <tr id="row1813015717423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p813085711421"><a name="p813085711421"></a><a name="p813085711421"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.29497805948318%" headers="mcps1.1.5.1.2 "><p id="p013085719427"><a name="p013085719427"></a><a name="p013085719427"></a>AsyncCallback&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.664553876157972%" headers="mcps1.1.5.1.3 "><p id="p181301457184219"><a name="p181301457184219"></a><a name="p181301457184219"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.58898098488542%" headers="mcps1.1.5.1.4 "><p id="p191301575425"><a name="p191301575425"></a><a name="p191301575425"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    dataStorage.removeStorageFromCache(PATH, function(err, data) {
    });
    ```


## dataStorage.removeStorageFromCache<a name="section1813245718422"></a>

removeStorageFromCache\(path: string\): Promise<void\>

从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。

此方法为异步方法。

-   参数：

    <a name="table2133125713429"></a>
    <table><thead align="left"><tr id="row9133857194218"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p813355716423"><a name="p813355716423"></a><a name="p813355716423"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p213495712420"><a name="p213495712420"></a><a name="p213495712420"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p713465724210"><a name="p713465724210"></a><a name="p713465724210"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p413425734218"><a name="p413425734218"></a><a name="p413425734218"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0134105716421"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14134135744212"><a name="p14134135744212"></a><a name="p14134135744212"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p613417578427"><a name="p613417578427"></a><a name="p613417578427"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p313555724217"><a name="p313555724217"></a><a name="p313555724217"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p88981021172812"><a name="p88981021172812"></a><a name="p88981021172812"></a>应用程序内部数据存储路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table513585718424"></a>
    <table><thead align="left"><tr id="row191352576429"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p51351257104220"><a name="p51351257104220"></a><a name="p51351257104220"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p113611571421"><a name="p113611571421"></a><a name="p113611571421"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0136165744213"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p159416454718"><a name="p159416454718"></a><a name="p159416454718"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p13941645472"><a name="p13941645472"></a><a name="p13941645472"></a>Promise实例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = dataStorage.removeStorageFromCache(PATH);
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


## Storage<a name="section12882825611"></a>

提供获取和修改存储数据的接口。

### getSync<a name="section1984422131910"></a>

getSync\(key: string, defValue: ValueType\): ValueType

获取键对应的值，如果值为null或者非默认值类型，返回默认数据。

此方法为同步方法。

-   参数：

    <a name="table134047259197"></a>
    <table><thead align="left"><tr id="row134041225191915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7404172513199"><a name="p7404172513199"></a><a name="p7404172513199"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1740422518197"><a name="p1740422518197"></a><a name="p1740422518197"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18404122513192"><a name="p18404122513192"></a><a name="p18404122513192"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2404025121912"><a name="p2404025121912"></a><a name="p2404025121912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20404172517195"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3404625101912"><a name="p3404625101912"></a><a name="p3404625101912"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p114047255192"><a name="p114047255192"></a><a name="p114047255192"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10404162571912"><a name="p10404162571912"></a><a name="p10404162571912"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10404192513199"><a name="p10404192513199"></a><a name="p10404192513199"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    <tr id="row1740492512196"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1540432551910"><a name="p1540432551910"></a><a name="p1540432551910"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p8404102516199"><a name="p8404102516199"></a><a name="p8404102516199"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6405202516196"><a name="p6405202516196"></a><a name="p6405202516196"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1140502514190"><a name="p1140502514190"></a><a name="p1140502514190"></a>给定key的存储不存在，则要返回的默认值。支持number、string、boolean。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table432284131914"></a>
    <table><thead align="left"><tr id="row14322941161913"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p83221416199"><a name="p83221416199"></a><a name="p83221416199"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p732219418192"><a name="p732219418192"></a><a name="p732219418192"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63221941101918"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p932204131910"><a name="p932204131910"></a><a name="p932204131910"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1832294181917"><a name="p1832294181917"></a><a name="p1832294181917"></a>键对应的值，如果值为null或者非默认值类型，返回默认数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ret = store.getSync(key, 'defValue');
    ```


### get<a name="section12293161972016"></a>

get\(key: string, defValue: ValueType, callback: AsyncCallback<ValueType\>\): void

获取键对应的值，如果值为null或者非默认值类型，返回默认数据。

此方法为异步方法。

-   参数：

    <a name="table4937172922016"></a>
    <table><thead align="left"><tr id="row3937162917202"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p39377296202"><a name="p39377296202"></a><a name="p39377296202"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p1093712917202"><a name="p1093712917202"></a><a name="p1093712917202"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p5937142915201"><a name="p5937142915201"></a><a name="p5937142915201"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p693722972018"><a name="p693722972018"></a><a name="p693722972018"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0937829202013"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1993718293203"><a name="p1993718293203"></a><a name="p1993718293203"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p1937122922018"><a name="p1937122922018"></a><a name="p1937122922018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p10937152962019"><a name="p10937152962019"></a><a name="p10937152962019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p793710294206"><a name="p793710294206"></a><a name="p793710294206"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    <tr id="row1293752912012"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1893714292206"><a name="p1893714292206"></a><a name="p1893714292206"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p119371729132012"><a name="p119371729132012"></a><a name="p119371729132012"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p12937429102016"><a name="p12937429102016"></a><a name="p12937429102016"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p129372299204"><a name="p129372299204"></a><a name="p129372299204"></a>默认返回值。支持number、string、boolean。</p>
    </td>
    </tr>
    <tr id="row109381229142014"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1693815299207"><a name="p1693815299207"></a><a name="p1693815299207"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p15938329142010"><a name="p15938329142010"></a><a name="p15938329142010"></a>AsyncCallback&lt;ValueType&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p10938929162017"><a name="p10938929162017"></a><a name="p10938929162017"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p893812912201"><a name="p893812912201"></a><a name="p893812912201"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.get(key, 'test', function(err, data) {    
        console.info(data);
    });
    ```


### get<a name="section18984643152118"></a>

get\(key: string, defValue: ValueType\): Promise<ValueType\>

获取键对应的值，如果值为null或者非默认值类型，返默认数据。

此方法为异步方法。

-   **参数：**

    <a name="table18177853162110"></a>
    <table><thead align="left"><tr id="row181781453102111"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p13178953122112"><a name="p13178953122112"></a><a name="p13178953122112"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p111781153172115"><a name="p111781153172115"></a><a name="p111781153172115"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p5178125342118"><a name="p5178125342118"></a><a name="p5178125342118"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p17178105320210"><a name="p17178105320210"></a><a name="p17178105320210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row81781153162116"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p91786538215"><a name="p91786538215"></a><a name="p91786538215"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p11178105316219"><a name="p11178105316219"></a><a name="p11178105316219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p71781653142115"><a name="p71781653142115"></a><a name="p71781653142115"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p717812534216"><a name="p717812534216"></a><a name="p717812534216"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    <tr id="row191781653182116"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p7178185315217"><a name="p7178185315217"></a><a name="p7178185315217"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p6178105319217"><a name="p6178105319217"></a><a name="p6178105319217"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p17178653132119"><a name="p17178653132119"></a><a name="p17178653132119"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p817813533210"><a name="p817813533210"></a><a name="p817813533210"></a>默认返回值。支持number、string、boolean。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table17633151592210"></a>
    <table><thead align="left"><tr id="row12633615192219"><th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.3.1.1"><p id="p15633161517226"><a name="p15633161517226"></a><a name="p15633161517226"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.41%" id="mcps1.1.3.1.2"><p id="p106331915142212"><a name="p106331915142212"></a><a name="p106331915142212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14633115142215"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.3.1.1 "><p id="p56331015142214"><a name="p56331015142214"></a><a name="p56331015142214"></a>Promise&lt;ValueType&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.41%" headers="mcps1.1.3.1.2 "><p id="p15633101522214"><a name="p15633101522214"></a><a name="p15633101522214"></a>Promise实例，用于异步获取结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.get(key, 'test');
    promise.then((data) => {   
        console.info(data);
    }).catch((err) => {
    });
    ```


### putSync<a name="section2042914810266"></a>

putSync\(key: string, value: ValueType\): void

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为同步方法。

-   参数：

    <a name="table18627821182614"></a>
    <table><thead align="left"><tr id="row162782182615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p36278211263"><a name="p36278211263"></a><a name="p36278211263"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1662732192616"><a name="p1662732192616"></a><a name="p1662732192616"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1362762182616"><a name="p1362762182616"></a><a name="p1362762182616"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p186282218261"><a name="p186282218261"></a><a name="p186282218261"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1262810215268"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p196284210266"><a name="p196284210266"></a><a name="p196284210266"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1462802113268"><a name="p1462802113268"></a><a name="p1462802113268"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1628192192612"><a name="p1628192192612"></a><a name="p1628192192612"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6628521122615"><a name="p6628521122615"></a><a name="p6628521122615"></a>要修改的存储的key。它不能为空。</p>
    </td>
    </tr>
    <tr id="row5628202152619"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8628102192617"><a name="p8628102192617"></a><a name="p8628102192617"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p66281421192620"><a name="p66281421192620"></a><a name="p66281421192620"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p96281217267"><a name="p96281217267"></a><a name="p96281217267"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15628721142612"><a name="p15628721142612"></a><a name="p15628721142612"></a>存储的新值。支持number、string、boolean。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let data = store.putSync(key, 'defValue');
    ```


### put<a name="section141693514276"></a>

put\(key: string, value: ValueType, callback: AsyncCallback<void\>\): void

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为异步方法。

-   参数：

    <a name="table875524602811"></a>
    <table><thead align="left"><tr id="row2075518465285"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1075574672815"><a name="p1075574672815"></a><a name="p1075574672815"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.539736713798145%" id="mcps1.1.5.1.2"><p id="p6755114618283"><a name="p6755114618283"></a><a name="p6755114618283"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.4534373476353%" id="mcps1.1.5.1.3"><p id="p137551446142814"><a name="p137551446142814"></a><a name="p137551446142814"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.55533885909311%" id="mcps1.1.5.1.4"><p id="p1275544652813"><a name="p1275544652813"></a><a name="p1275544652813"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7755124692813"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p17755346102818"><a name="p17755346102818"></a><a name="p17755346102818"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p177551846172817"><a name="p177551846172817"></a><a name="p177551846172817"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p16756946182810"><a name="p16756946182810"></a><a name="p16756946182810"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p775614662815"><a name="p775614662815"></a><a name="p775614662815"></a>要修改的存储的key。它不能为空。</p>
    </td>
    </tr>
    <tr id="row1875674613284"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1175634652819"><a name="p1175634652819"></a><a name="p1175634652819"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p37561846152814"><a name="p37561846152814"></a><a name="p37561846152814"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p075684619281"><a name="p075684619281"></a><a name="p075684619281"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p117561246192811"><a name="p117561246192811"></a><a name="p117561246192811"></a>存储的新值。支持number、string、boolean。</p>
    </td>
    </tr>
    <tr id="row375674614288"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14756134672812"><a name="p14756134672812"></a><a name="p14756134672812"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p1075614612285"><a name="p1075614612285"></a><a name="p1075614612285"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p2756746202817"><a name="p2756746202817"></a><a name="p2756746202817"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p375610463287"><a name="p375610463287"></a><a name="p375610463287"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.put(key, 'test', function(err, data) {    
    });
    ```


### put<a name="section594485413298"></a>

put\(key: string, value: ValueType\): Promise<void\>

首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。

此方法为异步方法。

-   参数：

    <a name="table144341091305"></a>
    <table><thead align="left"><tr id="row7434691304"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1343429163015"><a name="p1343429163015"></a><a name="p1343429163015"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p04349953017"><a name="p04349953017"></a><a name="p04349953017"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p3434395307"><a name="p3434395307"></a><a name="p3434395307"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p154349963020"><a name="p154349963020"></a><a name="p154349963020"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16434196302"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14345943014"><a name="p14345943014"></a><a name="p14345943014"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p8434159163014"><a name="p8434159163014"></a><a name="p8434159163014"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p124341963010"><a name="p124341963010"></a><a name="p124341963010"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p144354963019"><a name="p144354963019"></a><a name="p144354963019"></a>要修改的存储的key。它不能为空。</p>
    </td>
    </tr>
    <tr id="row18435109123019"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p194354913309"><a name="p194354913309"></a><a name="p194354913309"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p24358918307"><a name="p24358918307"></a><a name="p24358918307"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p5435994306"><a name="p5435994306"></a><a name="p5435994306"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p17435149123016"><a name="p17435149123016"></a><a name="p17435149123016"></a>存储的新值。支持number、string、boolean。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table3877202333010"></a>
    <table><thead align="left"><tr id="row1687722319306"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p187722311304"><a name="p187722311304"></a><a name="p187722311304"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p18772239307"><a name="p18772239307"></a><a name="p18772239307"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1287820238301"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p987892315302"><a name="p987892315302"></a><a name="p987892315302"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p208781523143017"><a name="p208781523143017"></a><a name="p208781523143017"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.put(key, 'test');
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


### hasSync<a name="section7273343143018"></a>

hasSync\(key: string\): boolean

检查存储对象是否包含名为给定key的存储。

此方法为同步方法。

-   参数：

    <a name="table206971230310"></a>
    <table><thead align="left"><tr id="row13697434313"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1169763133112"><a name="p1169763133112"></a><a name="p1169763133112"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p669716343112"><a name="p669716343112"></a><a name="p669716343112"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1869717312318"><a name="p1869717312318"></a><a name="p1869717312318"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p146971031315"><a name="p146971031315"></a><a name="p146971031315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row169719323119"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1269713323114"><a name="p1269713323114"></a><a name="p1269713323114"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1697193193119"><a name="p1697193193119"></a><a name="p1697193193119"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1669716313310"><a name="p1669716313310"></a><a name="p1669716313310"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8697139312"><a name="p8697139312"></a><a name="p8697139312"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table269819353119"></a>
    <table><thead align="left"><tr id="row10698153173115"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p46983317313"><a name="p46983317313"></a><a name="p46983317313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p769815310315"><a name="p769815310315"></a><a name="p769815310315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1769815310313"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p869833203110"><a name="p869833203110"></a><a name="p869833203110"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p166981339312"><a name="p166981339312"></a><a name="p166981339312"></a>true 表示存在，false表示不存在。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let ret = store.hasSync(key);
    ```


### has<a name="section185676222325"></a>

has\(key: string, callback: AsyncCallback<boolean\>\): boolean

检查存储对象是否包含名为给定key的存储。

此方法为异步方法。

-   参数：

    <a name="table1769918466400"></a>
    <table><thead align="left"><tr id="row19699194616406"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p76991946164012"><a name="p76991946164012"></a><a name="p76991946164012"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.738176499268647%" id="mcps1.1.5.1.2"><p id="p669954618400"><a name="p669954618400"></a><a name="p669954618400"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.68746952705997%" id="mcps1.1.5.1.3"><p id="p136994463402"><a name="p136994463402"></a><a name="p136994463402"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.12286689419795%" id="mcps1.1.5.1.4"><p id="p1069984634014"><a name="p1069984634014"></a><a name="p1069984634014"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17699646184013"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1769917466409"><a name="p1769917466409"></a><a name="p1769917466409"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.738176499268647%" headers="mcps1.1.5.1.2 "><p id="p3699124614409"><a name="p3699124614409"></a><a name="p3699124614409"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.68746952705997%" headers="mcps1.1.5.1.3 "><p id="p176992461406"><a name="p176992461406"></a><a name="p176992461406"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.12286689419795%" headers="mcps1.1.5.1.4 "><p id="p14699746114020"><a name="p14699746114020"></a><a name="p14699746114020"></a>要获取的存储key名称，不能为空。</p>
    </td>
    </tr>
    <tr id="row10699164684011"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p166994467401"><a name="p166994467401"></a><a name="p166994467401"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.738176499268647%" headers="mcps1.1.5.1.2 "><p id="p3699746194019"><a name="p3699746194019"></a><a name="p3699746194019"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.68746952705997%" headers="mcps1.1.5.1.3 "><p id="p8700746114012"><a name="p8700746114012"></a><a name="p8700746114012"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.12286689419795%" headers="mcps1.1.5.1.4 "><p id="p147004466406"><a name="p147004466406"></a><a name="p147004466406"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1150162734110"></a>
    <table><thead align="left"><tr id="row1950110276414"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p75011227194112"><a name="p75011227194112"></a><a name="p75011227194112"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1550192794116"><a name="p1550192794116"></a><a name="p1550192794116"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9501627134110"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p11501112734115"><a name="p11501112734115"></a><a name="p11501112734115"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1350212774110"><a name="p1350212774110"></a><a name="p1350212774110"></a>true表示存在，false表示不存在。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.has(key, function(err, data) {   
        console.info(data);
    });
    ```


### has<a name="section415084610412"></a>

has\(key: string\): Promise<boolean\>

检查存储对象是否包含名为给定key的存储。

此方法为异步方法。

-   参数：

    <a name="table10418320457"></a>
    <table><thead align="left"><tr id="row15414329454"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p6423294518"><a name="p6423294518"></a><a name="p6423294518"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p11443274517"><a name="p11443274517"></a><a name="p11443274517"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p104132164511"><a name="p104132164511"></a><a name="p104132164511"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p5423224514"><a name="p5423224514"></a><a name="p5423224514"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row34732194515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p641232154519"><a name="p641232154519"></a><a name="p641232154519"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p2047321454"><a name="p2047321454"></a><a name="p2047321454"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p64203213458"><a name="p64203213458"></a><a name="p64203213458"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p1433213456"><a name="p1433213456"></a><a name="p1433213456"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1120619131462"></a>
    <table><thead align="left"><tr id="row12063139466"><th class="cellrowborder" valign="top" width="30.56%" id="mcps1.1.3.1.1"><p id="p15206213154614"><a name="p15206213154614"></a><a name="p15206213154614"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.44%" id="mcps1.1.3.1.2"><p id="p1920651317466"><a name="p1920651317466"></a><a name="p1920651317466"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1620731334615"><td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.3.1.1 "><p id="p9207161324612"><a name="p9207161324612"></a><a name="p9207161324612"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.44%" headers="mcps1.1.3.1.2 "><p id="p202076136463"><a name="p202076136463"></a><a name="p202076136463"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.has(key);
    promise.then((data) => {   
        console.info(data);
    }).catch((err) => {
    });
    ```


### deleteSync<a name="section31481447174613"></a>

deleteSync\(key: string\): void

从存储对象中删除名为给定key的存储。

此方法为同步方法。

-   参数：

    <a name="table733743144711"></a>
    <table><thead align="left"><tr id="row233733114710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18337137471"><a name="p18337137471"></a><a name="p18337137471"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p23378324711"><a name="p23378324711"></a><a name="p23378324711"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p53377324710"><a name="p53377324710"></a><a name="p53377324710"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p73371133477"><a name="p73371133477"></a><a name="p73371133477"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row733793124714"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p123378374715"><a name="p123378374715"></a><a name="p123378374715"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16338836476"><a name="p16338836476"></a><a name="p16338836476"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12338193194714"><a name="p12338193194714"></a><a name="p12338193194714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9338731476"><a name="p9338731476"></a><a name="p9338731476"></a>要获取的存储key名称。它不能为空。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.deleteSync(key);
    ```


### delete<a name="section31755184812"></a>

delete\(key: string, callback: AsyncCallback<void\>\): void

从存储对象中删除名为给定key的存储。

此方法为异步方法。

-   参数：

    <a name="table1463510520490"></a>
    <table><thead align="left"><tr id="row116351594920"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1963515554910"><a name="p1963515554910"></a><a name="p1963515554910"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.48561677230619%" id="mcps1.1.5.1.2"><p id="p1263535104918"><a name="p1263535104918"></a><a name="p1263535104918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.985372988785958%" id="mcps1.1.5.1.3"><p id="p063513511492"><a name="p063513511492"></a><a name="p063513511492"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.07752315943442%" id="mcps1.1.5.1.4"><p id="p463555174910"><a name="p463555174910"></a><a name="p463555174910"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13636175124918"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1663635174919"><a name="p1663635174919"></a><a name="p1663635174919"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.48561677230619%" headers="mcps1.1.5.1.2 "><p id="p12636145184919"><a name="p12636145184919"></a><a name="p12636145184919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.985372988785958%" headers="mcps1.1.5.1.3 "><p id="p76361652495"><a name="p76361652495"></a><a name="p76361652495"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07752315943442%" headers="mcps1.1.5.1.4 "><p id="p76361658497"><a name="p76361658497"></a><a name="p76361658497"></a>要获取的存储key名称，不能为空。</p>
    </td>
    </tr>
    <tr id="row96363574913"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p763616510498"><a name="p763616510498"></a><a name="p763616510498"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.48561677230619%" headers="mcps1.1.5.1.2 "><p id="p1636125174918"><a name="p1636125174918"></a><a name="p1636125174918"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.985372988785958%" headers="mcps1.1.5.1.3 "><p id="p463615517491"><a name="p463615517491"></a><a name="p463615517491"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07752315943442%" headers="mcps1.1.5.1.4 "><p id="p156361259495"><a name="p156361259495"></a><a name="p156361259495"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.delete(key, function(err, data) {   
    });
    ```


### delete<a name="section11711858125016"></a>

delete\(key: string\): Promise<void\>

从存储对象删除名为给定key的存储。

此方法为异步方法。

-   参数：

    <a name="table193166815517"></a>
    <table><thead align="left"><tr id="row16316784518"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1331615865119"><a name="p1331615865119"></a><a name="p1331615865119"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p9316178135110"><a name="p9316178135110"></a><a name="p9316178135110"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p11316158115115"><a name="p11316158115115"></a><a name="p11316158115115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p1631613812519"><a name="p1631613812519"></a><a name="p1631613812519"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1231618811515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1831613813513"><a name="p1831613813513"></a><a name="p1831613813513"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p83162805112"><a name="p83162805112"></a><a name="p83162805112"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p43161845116"><a name="p43161845116"></a><a name="p43161845116"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p183171819512"><a name="p183171819512"></a><a name="p183171819512"></a>要获取的存储key名称。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table6698194765112"></a>
    <table><thead align="left"><tr id="row36984478516"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p15698124745118"><a name="p15698124745118"></a><a name="p15698124745118"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1269816474513"><a name="p1269816474513"></a><a name="p1269816474513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16698247205114"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p18698447105115"><a name="p18698447105115"></a><a name="p18698447105115"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p36981947155117"><a name="p36981947155117"></a><a name="p36981947155117"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.delete(key);
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


### flushSync<a name="section1952191618523"></a>

flushSync\(\): void

将当前storage对象中的修改保存到当前的storage，并同步存储到文件中。

此方法为同步方法。

-   示例：

    ```
    store.flushSync();
    ```


### flush<a name="section65806875414"></a>

flush\(callback: AsyncCallback<void\>\): void

将当前storage对象中的修改保存到当前的storage，并异步存储到文件中。

此方法为异步方法。

-   参数：

    <a name="table158501215125418"></a>
    <table><thead align="left"><tr id="row9850415125415"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p17850115155417"><a name="p17850115155417"></a><a name="p17850115155417"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.041443198439783%" id="mcps1.1.5.1.2"><p id="p1585081595414"><a name="p1585081595414"></a><a name="p1585081595414"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.372013651877133%" id="mcps1.1.5.1.3"><p id="p18509157544"><a name="p18509157544"></a><a name="p18509157544"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.13505607020965%" id="mcps1.1.5.1.4"><p id="p785020151545"><a name="p785020151545"></a><a name="p785020151545"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row198503159545"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p785118152548"><a name="p785118152548"></a><a name="p785118152548"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.041443198439783%" headers="mcps1.1.5.1.2 "><p id="p48511715105417"><a name="p48511715105417"></a><a name="p48511715105417"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.372013651877133%" headers="mcps1.1.5.1.3 "><p id="p20851201513548"><a name="p20851201513548"></a><a name="p20851201513548"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.13505607020965%" headers="mcps1.1.5.1.4 "><p id="p19851715105412"><a name="p19851715105412"></a><a name="p19851715105412"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.flush(function(err, data) {   
    });
    ```


### flush<a name="section524213130551"></a>

flush\(\): Promise<void\>

将当前storage对象中的修改保存到当前的storage，并异步存储到文件中。

此方法为异步方法。

-   返回值：

    <a name="table197324403552"></a>
    <table><thead align="left"><tr id="row197328403555"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1173344085511"><a name="p1173344085511"></a><a name="p1173344085511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p87336404552"><a name="p87336404552"></a><a name="p87336404552"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row573324045513"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p773318409553"><a name="p773318409553"></a><a name="p773318409553"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1273364018550"><a name="p1273364018550"></a><a name="p1273364018550"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.flush();
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


### clearSync<a name="section119861517115914"></a>

clearSync\(\): void

清除此存储对象中的所有存储。

此方法为同步方法。

-   示例：

    ```
    store.clearSync();
    ```


### clear<a name="section15671520306"></a>

clear\(callback: AsyncCallback<void\>\): void

清除此存储对象中的所有存储。

此方法为异步方法。

-   参数：

    <a name="table84588321621"></a>
    <table><thead align="left"><tr id="row154589321724"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p17458732925"><a name="p17458732925"></a><a name="p17458732925"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.837640175524133%" id="mcps1.1.5.1.2"><p id="p1945893212211"><a name="p1945893212211"></a><a name="p1945893212211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.389566065333982%" id="mcps1.1.5.1.3"><p id="p24590321822"><a name="p24590321822"></a><a name="p24590321822"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.32130667966845%" id="mcps1.1.5.1.4"><p id="p194593321528"><a name="p194593321528"></a><a name="p194593321528"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2459163212210"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p11459832229"><a name="p11459832229"></a><a name="p11459832229"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.837640175524133%" headers="mcps1.1.5.1.2 "><p id="p1145913211215"><a name="p1145913211215"></a><a name="p1145913211215"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.389566065333982%" headers="mcps1.1.5.1.3 "><p id="p13459183218216"><a name="p13459183218216"></a><a name="p13459183218216"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.32130667966845%" headers="mcps1.1.5.1.4 "><p id="p84590321224"><a name="p84590321224"></a><a name="p84590321224"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    store.clear(function(err, data) {   
    });
    ```


### clear<a name="section21300181536"></a>

clear\(\): Promise<void\>

清除此存储对象中的所有存储。

此方法为异步方法。

-   返回值：

    <a name="table123728475316"></a>
    <table><thead align="left"><tr id="row11372947131"><th class="cellrowborder" valign="top" width="20.380000000000003%" id="mcps1.1.3.1.1"><p id="p13372104710314"><a name="p13372104710314"></a><a name="p13372104710314"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.62%" id="mcps1.1.3.1.2"><p id="p1737316471834"><a name="p1737316471834"></a><a name="p1737316471834"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row337374719310"><td class="cellrowborder" valign="top" width="20.380000000000003%" headers="mcps1.1.3.1.1 "><p id="p1937313478315"><a name="p1937313478315"></a><a name="p1937313478315"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.62%" headers="mcps1.1.3.1.2 "><p id="p1337317471631"><a name="p1337317471631"></a><a name="p1337317471631"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = store.clear();
    promise.then((data) => {   
    }).catch((err) => {
    });
    ```


### on（'change'）<a name="section189332511954"></a>

on\(type: 'change', callback: Callback<StorageObserver\>\): void

监听者类需要实现StorageObserver接口，当数据发生改变时，监听者的 StorageObserver\#onChange会被回调。

-   参数：

    <a name="table61212334717"></a>
    <table><thead align="left"><tr id="row6122133313720"><th class="cellrowborder" valign="top" width="17.119999999999997%" id="mcps1.1.4.1.1"><p id="p112215335718"><a name="p112215335718"></a><a name="p112215335718"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.18%" id="mcps1.1.4.1.2"><p id="p1912223317713"><a name="p1912223317713"></a><a name="p1912223317713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.7%" id="mcps1.1.4.1.3"><p id="p912219331374"><a name="p912219331374"></a><a name="p912219331374"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1412293319714"><td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.4.1.1 "><p id="p11122203314718"><a name="p11122203314718"></a><a name="p11122203314718"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.18%" headers="mcps1.1.4.1.2 "><p id="p15941366336"><a name="p15941366336"></a><a name="p15941366336"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.7%" headers="mcps1.1.4.1.3 "><p id="p11227331716"><a name="p11227331716"></a><a name="p11227331716"></a>事件类型，固定值'change'，表示数据变更。</p>
    </td>
    </tr>
    <tr id="row41225333715"><td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.4.1.1 "><p id="p11122183312719"><a name="p11122183312719"></a><a name="p11122183312719"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.18%" headers="mcps1.1.4.1.2 "><p id="p1012218331376"><a name="p1012218331376"></a><a name="p1012218331376"></a>Callback&lt;<a href="#section256244135613">StorageObserver</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.7%" headers="mcps1.1.4.1.3 "><p id="p181227334710"><a name="p181227334710"></a><a name="p181227334710"></a>需要监听的回调对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var observer = function (data) {  
        console.info(data);  
    };
    store.on('change', observer);
    ```


### off（'change'）<a name="section6421153815"></a>

off\(type: 'change', callback: Callback<StorageObserver\>\): void

监听者类需要实现StorageObserver接口，当不再进行数据监听时，使用此接口取消监听。

-   参数：

    <a name="table84837251480"></a>
    <table><thead align="left"><tr id="row1648312251283"><th class="cellrowborder" valign="top" width="17.05%" id="mcps1.1.4.1.1"><p id="p1448317251186"><a name="p1448317251186"></a><a name="p1448317251186"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.26%" id="mcps1.1.4.1.2"><p id="p1748352512812"><a name="p1748352512812"></a><a name="p1748352512812"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="p1448382520818"><a name="p1448382520818"></a><a name="p1448382520818"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row94831251086"><td class="cellrowborder" valign="top" width="17.05%" headers="mcps1.1.4.1.1 "><p id="p348332516813"><a name="p348332516813"></a><a name="p348332516813"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.26%" headers="mcps1.1.4.1.2 "><p id="p88671011183314"><a name="p88671011183314"></a><a name="p88671011183314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p1486721113334"><a name="p1486721113334"></a><a name="p1486721113334"></a>事件类型，固定值'change'，表示数据变更。</p>
    </td>
    </tr>
    <tr id="row148410251888"><td class="cellrowborder" valign="top" width="17.05%" headers="mcps1.1.4.1.1 "><p id="p9484142519818"><a name="p9484142519818"></a><a name="p9484142519818"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.26%" headers="mcps1.1.4.1.2 "><p id="p1448412251388"><a name="p1448412251388"></a><a name="p1448412251388"></a>Callback&lt;<a href="#section256244135613">StorageObserver</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p34843252811"><a name="p34843252811"></a><a name="p34843252811"></a>需要取消的回调对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var observer = function (data) {  
        console.info(data);  
    };
    store.off('change', observer);
    ```


## StorageObserver<a name="section256244135613"></a>

<a name="table0103172561814"></a>
<table><thead align="left"><tr id="row12103152513185"><th class="cellrowborder" valign="top" width="17.911791179117913%" id="mcps1.1.5.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.291229122912291%" id="mcps1.1.5.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="p1103172518188"><a name="p1103172518188"></a><a name="p1103172518188"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row201031125101812"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p5549181319415"><a name="p5549181319415"></a><a name="p5549181319415"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p39351925253"><a name="p39351925253"></a><a name="p39351925253"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p8935162182512"><a name="p8935162182512"></a><a name="p8935162182512"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1179214508910"><a name="p1179214508910"></a><a name="p1179214508910"></a>变更的数据内容。</p>
</td>
</tr>
</tbody>
</table>

