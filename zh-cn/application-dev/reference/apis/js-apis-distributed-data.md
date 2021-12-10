# 分布式数据管理<a name="ZH-CN_TOPIC_0000001200444541"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import distributedData from '@ohos.data.distributedData';
```

## 权限<a name="section11257113618419"></a>

无

## distributedData.createKVManager<a name="section2771164881119"></a>

createKVManager\(config: KVManagerConfig, callback: AsyncCallback<KVManager\>\): void

创建一个KVManager对象实例，用于管理数据库对象，并通过callback方式返回，此方法为异步方法。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.349999999999998%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.38%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.449999999999996%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1759964375212"><a name="p1759964375212"></a><a name="p1759964375212"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.349999999999998%" headers="mcps1.1.5.1.2 "><p id="p1238416585528"><a name="p1238416585528"></a><a name="p1238416585528"></a><a href="#section15135528163015">KVManagerConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.38%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.449999999999996%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>提供KVManager实例的配置信息，包括调用方的包名和用户信息。</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.349999999999998%" headers="mcps1.1.5.1.2 "><p id="p36441515115320"><a name="p36441515115320"></a><a name="p36441515115320"></a>AsyncCallback&lt;<a href="#section10510185414111">KVManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.38%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.449999999999996%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>KVManager实例创建时调用的回调，返回KVManager对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let kvManager;
    try {
        const kvManagerConfig = {
            bundleName : 'com.example.datamanagertest',
            userInfo : {
                userId : '0',
                userType : 0
            }
        }
        distributedData.createKVManager(kvManagerConfig, function (err, manager) {
            if (err) {
                console.log("createKVManager err: "  + JSON.stringify(err));
                return;
            }
            console.log("createKVManager success");
            kvManager = manager;
        });
    } catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


## distributedData.createKVManager<a name="section15751121117223"></a>

createKVManager\(config: KVManagerConfig\): Promise<KVManager\>

创建一个KVManager对象实例，用于管理数据库对象，并通过Promise方式返回，此方法为异步方法。

-   参数：

    <a name="table2751161162210"></a>
    <table><thead align="left"><tr id="row9752311102214"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p147524114228"><a name="p147524114228"></a><a name="p147524114228"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.349999999999998%" id="mcps1.1.5.1.2"><p id="p87521111223"><a name="p87521111223"></a><a name="p87521111223"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.38%" id="mcps1.1.5.1.3"><p id="p7752181112223"><a name="p7752181112223"></a><a name="p7752181112223"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.449999999999996%" id="mcps1.1.5.1.4"><p id="p14752141162212"><a name="p14752141162212"></a><a name="p14752141162212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row127524118221"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p17531911202216"><a name="p17531911202216"></a><a name="p17531911202216"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.349999999999998%" headers="mcps1.1.5.1.2 "><p id="p17534113223"><a name="p17534113223"></a><a name="p17534113223"></a><a href="#section15135528163015">KVManagerConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.38%" headers="mcps1.1.5.1.3 "><p id="p1175371142211"><a name="p1175371142211"></a><a name="p1175371142211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.449999999999996%" headers="mcps1.1.5.1.4 "><p id="p475315118226"><a name="p475315118226"></a><a name="p475315118226"></a>提供KVManager实例的配置信息，包括调用方的包名和用户信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table14773154913191"></a>
    <table><thead align="left"><tr id="row877314991912"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="p1077313493199"><a name="p1077313493199"></a><a name="p1077313493199"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="p1677411498195"><a name="p1677411498195"></a><a name="p1677411498195"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1977413496194"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="p67742498197"><a name="p67742498197"></a><a name="p67742498197"></a>Promise&lt;<a href="#section10510185414111">KVManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="p4774164916199"><a name="p4774164916199"></a><a name="p4774164916199"></a>指定的Promise回调方法，返回创建的KVManager对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let kvManager;
    try {
        const kvManagerConfig = {
            bundleName : 'com.example.datamanagertest',
            userInfo : {
                userId : '0',
                userType : 0
            }
        }
        distributedData.createKVManager(kvManagerConfig).then((manager) => {
            console.log("createKVManager success");
            kvManager = manager;
        }).catch((err) => {
            console.log("createKVManager err: "  + JSON.stringify(err));
        });
    } catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


## KVManagerConfig<a name="section15135528163015"></a>

提供KVManager实例的配置信息，包括调用方的包名和用户信息。

<a name="table104081425154213"></a>
<table><thead align="left"><tr id="row15409122514217"><th class="cellrowborder" valign="top" width="17.378262173782623%" id="mcps1.1.5.1.1"><p id="p1340952594210"><a name="p1340952594210"></a><a name="p1340952594210"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.547845215478453%" id="mcps1.1.5.1.2"><p id="p15409525144213"><a name="p15409525144213"></a><a name="p15409525144213"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p104096254423"><a name="p104096254423"></a><a name="p104096254423"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.554644535546444%" id="mcps1.1.5.1.4"><p id="p840962515424"><a name="p840962515424"></a><a name="p840962515424"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row12409172544213"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p184101525184212"><a name="p184101525184212"></a><a name="p184101525184212"></a>userInfo</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p7410152519420"><a name="p7410152519420"></a><a name="p7410152519420"></a><a href="#section859346103617">UserInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p9410825194216"><a name="p9410825194216"></a><a name="p9410825194216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p1559785083517"><a name="p1559785083517"></a><a name="p1559785083517"></a>调用方的用户信息。</p>
</td>
</tr>
<tr id="row1841142594215"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p44121225174218"><a name="p44121225174218"></a><a name="p44121225174218"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p1541314251427"><a name="p1541314251427"></a><a name="p1541314251427"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p141317253428"><a name="p141317253428"></a><a name="p141317253428"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p74131525104217"><a name="p74131525104217"></a><a name="p74131525104217"></a>调用方的包名。</p>
</td>
</tr>
</tbody>
</table>

## UserInfo<a name="section859346103617"></a>

用户信息。

<a name="table8594165366"></a>
<table><thead align="left"><tr id="row15594068361"><th class="cellrowborder" valign="top" width="17.378262173782623%" id="mcps1.1.5.1.1"><p id="p1559411673614"><a name="p1559411673614"></a><a name="p1559411673614"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.547845215478453%" id="mcps1.1.5.1.2"><p id="p12594962363"><a name="p12594962363"></a><a name="p12594962363"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p165942673620"><a name="p165942673620"></a><a name="p165942673620"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.554644535546444%" id="mcps1.1.5.1.4"><p id="p259412623613"><a name="p259412623613"></a><a name="p259412623613"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row25955663611"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p13595867365"><a name="p13595867365"></a><a name="p13595867365"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p659506113610"><a name="p659506113610"></a><a name="p659506113610"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p1559517612362"><a name="p1559517612362"></a><a name="p1559517612362"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p195951669362"><a name="p195951669362"></a><a name="p195951669362"></a>指示要设置的用户ID。</p>
</td>
</tr>
<tr id="row85951613360"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p55951263361"><a name="p55951263361"></a><a name="p55951263361"></a>userType</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p1459511610365"><a name="p1459511610365"></a><a name="p1459511610365"></a><a href="#section156981915134813">UserType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p20595106123619"><a name="p20595106123619"></a><a name="p20595106123619"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p359596143617"><a name="p359596143617"></a><a name="p359596143617"></a>指示要设置的用户类型。</p>
</td>
</tr>
</tbody>
</table>

## UserType<a name="section156981915134813"></a>

用户类型。

<a name="table6699101504818"></a>
<table><thead align="left"><tr id="row15699315154810"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p1369961514489"><a name="p1369961514489"></a><a name="p1369961514489"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p206991915184810"><a name="p206991915184810"></a><a name="p206991915184810"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p7700141594810"><a name="p7700141594810"></a><a name="p7700141594810"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1270061514484"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p870051512486"><a name="p870051512486"></a><a name="p870051512486"></a>SAME_USER_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p970015156487"><a name="p970015156487"></a><a name="p970015156487"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p167001015104813"><a name="p167001015104813"></a><a name="p167001015104813"></a>使用同一帐户登录不同设备的用户。</p>
</td>
</tr>
</tbody>
</table>

## KVManager<a name="section10510185414111"></a>

数据管理实例，用于获取KVStore的相关信息。在调用KVManager的方法前，需要先通过createKVManager构建一个KVManager实例。

### getKVStore<a name="section163838594447"></a>

getKVStore<T extends KVStore\>\(storeId: string, options: Options, callback: AsyncCallback<T\>\): void

通过指定Options和storeId，创建并获取KVStore数据库，并通过callback方式返回，此方法为异步方法。

-   参数：

    <a name="table1815218719376"></a>
    <table><thead align="left"><tr id="row1515237113720"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p171523743712"><a name="p171523743712"></a><a name="p171523743712"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.47%" id="mcps1.1.5.1.2"><p id="p161521716375"><a name="p161521716375"></a><a name="p161521716375"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.16%" id="mcps1.1.5.1.3"><p id="p215318763718"><a name="p215318763718"></a><a name="p215318763718"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.550000000000004%" id="mcps1.1.5.1.4"><p id="p11531713374"><a name="p11531713374"></a><a name="p11531713374"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4442165763919"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9442757113913"><a name="p9442757113913"></a><a name="p9442757113913"></a>storeId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.47%" headers="mcps1.1.5.1.2 "><p id="p124431057193915"><a name="p124431057193915"></a><a name="p124431057193915"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.16%" headers="mcps1.1.5.1.3 "><p id="p1444311572398"><a name="p1444311572398"></a><a name="p1444311572398"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.550000000000004%" headers="mcps1.1.5.1.4 "><p id="p244311575391"><a name="p244311575391"></a><a name="p244311575391"></a>数据库唯一标识符，长度不大于<a href="#p1370641813465">MAX_STORE_ID_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row815319713379"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9153167113712"><a name="p9153167113712"></a><a name="p9153167113712"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.47%" headers="mcps1.1.5.1.2 "><p id="p41531872379"><a name="p41531872379"></a><a name="p41531872379"></a><a href="#section20151177103716">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.16%" headers="mcps1.1.5.1.3 "><p id="p31534710378"><a name="p31534710378"></a><a name="p31534710378"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.550000000000004%" headers="mcps1.1.5.1.4 "><p id="p1015318713717"><a name="p1015318713717"></a><a name="p1015318713717"></a>创建KVStore实例的配置信息。</p>
    </td>
    </tr>
    <tr id="row11531713372"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14153176376"><a name="p14153176376"></a><a name="p14153176376"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.47%" headers="mcps1.1.5.1.2 "><p id="p194274693318"><a name="p194274693318"></a><a name="p194274693318"></a>AsyncCallback&lt;T&gt;，</p>
    <p id="p915487143715"><a name="p915487143715"></a><a name="p915487143715"></a>&lt;T extends KVStore&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.16%" headers="mcps1.1.5.1.3 "><p id="p4154272372"><a name="p4154272372"></a><a name="p4154272372"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.550000000000004%" headers="mcps1.1.5.1.4 "><p id="p1015487153711"><a name="p1015487153711"></a><a name="p1015487153711"></a>创建KVStore实例的回调，返回KVStore对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let kvStore;
    try {
        const options = {
            createIfMissing : true,
            encrypt : false,
            backup : false,
            autoSync : true,
            kvStoreType : 1,
            securityLevel : 3,
        };
        kvManager.getKVStore('storeId', options, function (err, store) {
            if (err) {
                console.log("getKVStore err: "  + JSON.stringify(err));
                return;
            }
            console.log("getKVStore success");
            kvStore = store;
        });
    } catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### getKVStore<a name="section1614918420469"></a>

getKVStore<T extends KVStore\>\(storeId: string, options: Options\): Promise<T\>

通过指定Options和storeId，创建并获取KVStore数据库，并通过Promise方式返回，此方法为异步方法。

-   参数：

    <a name="table12128750203"></a>
    <table><thead align="left"><tr id="row131281159201"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p3129452205"><a name="p3129452205"></a><a name="p3129452205"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p31291454205"><a name="p31291454205"></a><a name="p31291454205"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p191291515203"><a name="p191291515203"></a><a name="p191291515203"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p1613085202012"><a name="p1613085202012"></a><a name="p1613085202012"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1613012514207"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1113012511203"><a name="p1113012511203"></a><a name="p1113012511203"></a>storeId</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p3130858207"><a name="p3130858207"></a><a name="p3130858207"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p8131145102014"><a name="p8131145102014"></a><a name="p8131145102014"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p51317516204"><a name="p51317516204"></a><a name="p51317516204"></a>数据库唯一标识符，长度不大于<a href="#p1370641813465">MAX_STORE_ID_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row151312522012"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p513119515209"><a name="p513119515209"></a><a name="p513119515209"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p91312514209"><a name="p91312514209"></a><a name="p91312514209"></a><a href="#section20151177103716">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p0132551205"><a name="p0132551205"></a><a name="p0132551205"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p1132105172011"><a name="p1132105172011"></a><a name="p1132105172011"></a>创建KVStore实例的配置信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1527413113225"></a>
    <table><thead align="left"><tr id="row827519116223"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="p827512192212"><a name="p827512192212"></a><a name="p827512192212"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="p127515142218"><a name="p127515142218"></a><a name="p127515142218"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22758142211"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="p92758118220"><a name="p92758118220"></a><a name="p92758118220"></a>Promise&lt;T&gt;</p>
    <p id="p383111612212"><a name="p383111612212"></a><a name="p383111612212"></a>&lt;T extends KVStore&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="p72751413225"><a name="p72751413225"></a><a name="p72751413225"></a>指定的Promise回调方法，返回创建的KVStore数据库实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let kvStore;
    try {
        const options = {
            createIfMissing : true,
            encrypt : false,
            backup : false,
            autoSync : true,
            kvStoreType : 1,
            securityLevel : 3,
        };
        kvManager.getKVStore('storeId', options).then((store) => {
            console.log("getKVStore success");
            kvStore = store;
        }).catch((err) => {
            console.log("getKVStore err: "  + JSON.stringify(err));
        });
    } catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


## Options<a name="section20151177103716"></a>

用于提供创建数据库的配置信息。

<a name="table139428218117"></a>
<table><thead align="left"><tr id="row8943821510"><th class="cellrowborder" valign="top" width="16.32%" id="mcps1.1.5.1.1"><p id="p139439212111"><a name="p139439212111"></a><a name="p139439212111"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="20.61%" id="mcps1.1.5.1.2"><p id="p5943721919"><a name="p5943721919"></a><a name="p5943721919"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.41%" id="mcps1.1.5.1.3"><p id="p189431218119"><a name="p189431218119"></a><a name="p189431218119"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.66%" id="mcps1.1.5.1.4"><p id="p11943142518"><a name="p11943142518"></a><a name="p11943142518"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1794311214119"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p15237173214282"><a name="p15237173214282"></a><a name="p15237173214282"></a>createIfMissing</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p794412718"><a name="p794412718"></a><a name="p794412718"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p79441213120"><a name="p79441213120"></a><a name="p79441213120"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p2944424110"><a name="p2944424110"></a><a name="p2944424110"></a>当数据库文件不存在时是否创建数据库，默认创建。</p>
</td>
</tr>
<tr id="row5944129113"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p8944929118"><a name="p8944929118"></a><a name="p8944929118"></a>encrypt</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p1294420220114"><a name="p1294420220114"></a><a name="p1294420220114"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p29447211119"><a name="p29447211119"></a><a name="p29447211119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p89451526118"><a name="p89451526118"></a><a name="p89451526118"></a>设置数据库文件是否加密，默认不加密。</p>
</td>
</tr>
<tr id="row109451529112"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p199911462912"><a name="p199911462912"></a><a name="p199911462912"></a>backup</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p19455210120"><a name="p19455210120"></a><a name="p19455210120"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p89451721915"><a name="p89451721915"></a><a name="p89451721915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p139457210111"><a name="p139457210111"></a><a name="p139457210111"></a>设置数据库文件是否备份，默认备份。</p>
</td>
</tr>
<tr id="row897612832918"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p1977152810299"><a name="p1977152810299"></a><a name="p1977152810299"></a>autoSync</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p119771328102918"><a name="p119771328102918"></a><a name="p119771328102918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p2977152892910"><a name="p2977152892910"></a><a name="p2977152892910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p997722815297"><a name="p997722815297"></a><a name="p997722815297"></a>设置数据库文件是否自动同步，默认不自动同步。</p>
</td>
</tr>
<tr id="row13783123212295"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p107838327292"><a name="p107838327292"></a><a name="p107838327292"></a>kvStoreType</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p10783113292916"><a name="p10783113292916"></a><a name="p10783113292916"></a><a href="#section720518449379">KVStoreType</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p5784432182914"><a name="p5784432182914"></a><a name="p5784432182914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p478417326295"><a name="p478417326295"></a><a name="p478417326295"></a>设置要创建的数据库类型，默认为多设备协同数据库。</p>
</td>
</tr>
<tr id="row41583015306"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="p51583020305"><a name="p51583020305"></a><a name="p51583020305"></a>securityLevel</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="p81596014308"><a name="p81596014308"></a><a name="p81596014308"></a><a href="#section205876465372">SecurityLevel</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p181591400305"><a name="p181591400305"></a><a name="p181591400305"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="p121591808302"><a name="p121591808302"></a><a name="p121591808302"></a>设置数据库安全级别，默认不设置安全级别。</p>
</td>
</tr>
</tbody>
</table>

## KVStoreType<a name="section720518449379"></a>

用于指定创建的数据库的类型。

<a name="table20205174420379"></a>
<table><thead align="left"><tr id="row1620654416375"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p820614447373"><a name="p820614447373"></a><a name="p820614447373"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p1520611449379"><a name="p1520611449379"></a><a name="p1520611449379"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p1820654413373"><a name="p1820654413373"></a><a name="p1820654413373"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8206144420370"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1206744133718"><a name="p1206744133718"></a><a name="p1206744133718"></a>DEVICE_COLLABORATION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p102065442377"><a name="p102065442377"></a><a name="p102065442377"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p720618443371"><a name="p720618443371"></a><a name="p720618443371"></a>表示多设备协同数据库。</p>
</td>
</tr>
<tr id="row4206104463714"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p220604419371"><a name="p220604419371"></a><a name="p220604419371"></a>SINGLE_VERSION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p320674473712"><a name="p320674473712"></a><a name="p320674473712"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p6822541173610"><a name="p6822541173610"></a><a name="p6822541173610"></a>表示单版本数据库。</p>
</td>
</tr>
<tr id="row5952210133711"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1895321017372"><a name="p1895321017372"></a><a name="p1895321017372"></a>MULTI_VERSION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p395341016374"><a name="p395341016374"></a><a name="p395341016374"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p995381014377"><a name="p995381014377"></a><a name="p995381014377"></a>表示多版本数据库。此类型当前不允许使用。</p>
</td>
</tr>
</tbody>
</table>

## SecurityLevel<a name="section205876465372"></a>

用于指定创建的数据库的安全级别。

<a name="table1558710464373"></a>
<table><thead align="left"><tr id="row35874465377"><th class="cellrowborder" valign="top" width="20.849999999999998%" id="mcps1.1.4.1.1"><p id="p2587346173718"><a name="p2587346173718"></a><a name="p2587346173718"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.879999999999999%" id="mcps1.1.4.1.2"><p id="p105874461372"><a name="p105874461372"></a><a name="p105874461372"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="68.27%" id="mcps1.1.4.1.3"><p id="p858804612376"><a name="p858804612376"></a><a name="p858804612376"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row195888462377"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p85881846133712"><a name="p85881846133712"></a><a name="p85881846133712"></a>NO_LEVEL</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p155881146183714"><a name="p155881146183714"></a><a name="p155881146183714"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p058820464374"><a name="p058820464374"></a><a name="p058820464374"></a>表示数据库不设置安全级别。</p>
</td>
</tr>
<tr id="row6588204620378"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p958884623720"><a name="p958884623720"></a><a name="p958884623720"></a>S0</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p75881146173720"><a name="p75881146173720"></a><a name="p75881146173720"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p358834673718"><a name="p358834673718"></a><a name="p358834673718"></a>表示数据库的安全级别为公共级别安全。</p>
</td>
</tr>
<tr id="row858810465372"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p25881146133714"><a name="p25881146133714"></a><a name="p25881146133714"></a>S1</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p1958874612370"><a name="p1958874612370"></a><a name="p1958874612370"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p205885469370"><a name="p205885469370"></a><a name="p205885469370"></a>表示数据库的安全级别为低级别安全，当数据泄露时会产生较低影响。</p>
</td>
</tr>
<tr id="row93891331184019"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p23904313405"><a name="p23904313405"></a><a name="p23904313405"></a>S2</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p10390133119408"><a name="p10390133119408"></a><a name="p10390133119408"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p8390153114014"><a name="p8390153114014"></a><a name="p8390153114014"></a>表示数据库的安全级别为中级别安全，当数据泄露时会产生较大影响。</p>
</td>
</tr>
<tr id="row18665352407"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p26613351409"><a name="p26613351409"></a><a name="p26613351409"></a>S3</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p1066735114011"><a name="p1066735114011"></a><a name="p1066735114011"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p9671535174014"><a name="p9671535174014"></a><a name="p9671535174014"></a>表示数据库的安全级别为高级别安全，当数据泄露时会产生重大影响。</p>
</td>
</tr>
<tr id="row2698955134015"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="p7699165512403"><a name="p7699165512403"></a><a name="p7699165512403"></a>S4</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="p869935594018"><a name="p869935594018"></a><a name="p869935594018"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="p06991755174017"><a name="p06991755174017"></a><a name="p06991755174017"></a>表示数据库的安全级别为关键级别安全，当数据泄露时会产生严重影响。</p>
</td>
</tr>
</tbody>
</table>

## Constants<a name="section14196103954210"></a>

KVStore常量。

<a name="table7197639134211"></a>
<table><thead align="left"><tr id="row21971939104211"><th class="cellrowborder" valign="top" width="27.87%" id="mcps1.1.4.1.1"><p id="p1719718399424"><a name="p1719718399424"></a><a name="p1719718399424"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.46%" id="mcps1.1.4.1.2"><p id="p11198539114210"><a name="p11198539114210"></a><a name="p11198539114210"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p919873920429"><a name="p919873920429"></a><a name="p919873920429"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row4198173934210"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p10198639174218"><a name="p10198639174218"></a><a name="p10198639174218"></a>MAX_KEY_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p121990396425"><a name="p121990396425"></a><a name="p121990396425"></a>1024</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p119918393420"><a name="p119918393420"></a><a name="p119918393420"></a>数据库中Key允许最大长度，单位字节。</p>
</td>
</tr>
<tr id="row6252120194618"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p9253605466"><a name="p9253605466"></a><a name="p9253605466"></a>MAX_VALUE_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p225313034612"><a name="p225313034612"></a><a name="p225313034612"></a>4194303</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p0253170194618"><a name="p0253170194618"></a><a name="p0253170194618"></a>数据库中Value允许的最大长度，单位字节。</p>
</td>
</tr>
<tr id="row563462174610"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p56351521184610"><a name="p56351521184610"></a><a name="p56351521184610"></a>MAX_KEY_LENGTH_DEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p1863502154618"><a name="p1863502154618"></a><a name="p1863502154618"></a>896</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1063542134612"><a name="p1063542134612"></a><a name="p1063542134612"></a>最大设备坐标密钥长度。</p>
</td>
</tr>
<tr id="row37051018134612"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p1370641813465"><a name="p1370641813465"></a><a name="p1370641813465"></a>MAX_STORE_ID_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p5706718194613"><a name="p5706718194613"></a><a name="p5706718194613"></a>128</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p199711939175015"><a name="p199711939175015"></a><a name="p199711939175015"></a>数据库标识符允许的最大长度，单位字节。</p>
</td>
</tr>
<tr id="row470671512464"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p107061115144612"><a name="p107061115144612"></a><a name="p107061115144612"></a>MAX_QUERY_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p3707171514610"><a name="p3707171514610"></a><a name="p3707171514610"></a>512000</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1670741514614"><a name="p1670741514614"></a><a name="p1670741514614"></a>最大查询长度。</p>
</td>
</tr>
<tr id="row161151120464"><td class="cellrowborder" valign="top" width="27.87%" headers="mcps1.1.4.1.1 "><p id="p211681204618"><a name="p211681204618"></a><a name="p211681204618"></a>MAX_BATCH_SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.1.4.1.2 "><p id="p10116101212462"><a name="p10116101212462"></a><a name="p10116101212462"></a>128</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p151161812174616"><a name="p151161812174616"></a><a name="p151161812174616"></a>最大批处理操作大小。</p>
</td>
</tr>
</tbody>
</table>

## KVStore<a name="section12882825611"></a>

KVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅同步完成的方法。在调用KVStore的方法前，需要先通过getKVStore构建一个KVStore实例。

### put<a name="section1942221513"></a>

put\(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback<void\>\): void

添加指定类型键值对到数据库，并通过callback方式返回，此方法为异步方法。

-   参数：

    <a name="table174118324413"></a>
    <table><thead align="left"><tr id="row164211354413"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17426384419"><a name="p17426384419"></a><a name="p17426384419"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p8421238446"><a name="p8421238446"></a><a name="p8421238446"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p1642103124416"><a name="p1642103124416"></a><a name="p1642103124416"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p154263204411"><a name="p154263204411"></a><a name="p154263204411"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row124314315442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p54315374420"><a name="p54315374420"></a><a name="p54315374420"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p134303144416"><a name="p134303144416"></a><a name="p134303144416"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p1643203134415"><a name="p1643203134415"></a><a name="p1643203134415"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p285519208464"><a name="p285519208464"></a><a name="p285519208464"></a>要添加数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row6433310449"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p64310318449"><a name="p64310318449"></a><a name="p64310318449"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p154363104410"><a name="p154363104410"></a><a name="p154363104410"></a>Uint8Array | string | number | boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p14437311447"><a name="p14437311447"></a><a name="p14437311447"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p208917378472"><a name="p208917378472"></a><a name="p208917378472"></a>要添加数据的value，支持Uint8Array、number 、 string 、boolean，</p>
    <p id="p08911379478"><a name="p08911379478"></a><a name="p08911379478"></a>Uint8Array、string 的长度不大于<a href="#p9253605466">MAX_VALUE_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row16388151513442"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16389151524410"><a name="p16389151524410"></a><a name="p16389151524410"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p1738911594418"><a name="p1738911594418"></a><a name="p1738911594418"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p13389101564417"><a name="p13389101564417"></a><a name="p13389101564417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p583654210476"><a name="p583654210476"></a><a name="p583654210476"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
            if (err != undefined) {
                console.log("put err: " + JSON.stringify(err));
                return;
            }
            console.log("put success");
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### put<a name="section43065440019"></a>

put\(key: string, value: Uint8Array | string | number | boolean\): Promise<void\>

添加指定类型键值对到数据库，并通过Promise方式返回，此方法为异步方法。

-   参数：

    <a name="table11608159175910"></a>
    <table><thead align="left"><tr id="row46080919599"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2609697598"><a name="p2609697598"></a><a name="p2609697598"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p126094985911"><a name="p126094985911"></a><a name="p126094985911"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p146090912597"><a name="p146090912597"></a><a name="p146090912597"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p1660912919597"><a name="p1660912919597"></a><a name="p1660912919597"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row156091915910"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1260929175919"><a name="p1260929175919"></a><a name="p1260929175919"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p1460918913596"><a name="p1460918913596"></a><a name="p1460918913596"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p461014916591"><a name="p461014916591"></a><a name="p461014916591"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p156109985911"><a name="p156109985911"></a><a name="p156109985911"></a>要添加数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row18610199195919"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p19610139175917"><a name="p19610139175917"></a><a name="p19610139175917"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p96111919595"><a name="p96111919595"></a><a name="p96111919595"></a>Uint8Array | string | number | boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p66113916595"><a name="p66113916595"></a><a name="p66113916595"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p1861118925915"><a name="p1861118925915"></a><a name="p1861118925915"></a>要添加数据的value，支持Uint8Array、number 、 string 、boolean，</p>
    <p id="p1561149125919"><a name="p1561149125919"></a><a name="p1561149125919"></a>Uint8Array、string 的长度不大于<a href="#p9253605466">MAX_VALUE_LENGTH</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table59499217114"></a>
    <table><thead align="left"><tr id="row5949322117"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p129505214113"><a name="p129505214113"></a><a name="p129505214113"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p395018214112"><a name="p395018214112"></a><a name="p395018214112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9950162310"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p149501621616"><a name="p149501621616"></a><a name="p149501621616"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1695072011"><a name="p1695072011"></a><a name="p1695072011"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
            console.log("put success: " + JSON.stringify(data));
        }).catch((err) => {
            console.log("put err: " + JSON.stringify(err));
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### delete<a name="section15564125555713"></a>

delete\(key: string, callback: AsyncCallback<void\>\): void

从数据库中删除指定键值的数据，并通过callback方式返回，此方法为异步方法。

-   参数：

    <a name="table588435711415"></a>
    <table><thead align="left"><tr id="row1688513572414"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p78857576420"><a name="p78857576420"></a><a name="p78857576420"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.529999999999998%" id="mcps1.1.5.1.2"><p id="p178851571417"><a name="p178851571417"></a><a name="p178851571417"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.58%" id="mcps1.1.5.1.3"><p id="p18885205710416"><a name="p18885205710416"></a><a name="p18885205710416"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.07%" id="mcps1.1.5.1.4"><p id="p1688510571649"><a name="p1688510571649"></a><a name="p1688510571649"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row188855571749"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14886457340"><a name="p14886457340"></a><a name="p14886457340"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.529999999999998%" headers="mcps1.1.5.1.2 "><p id="p20886175717412"><a name="p20886175717412"></a><a name="p20886175717412"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.58%" headers="mcps1.1.5.1.3 "><p id="p138866579416"><a name="p138866579416"></a><a name="p138866579416"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.07%" headers="mcps1.1.5.1.4 "><p id="p18868572411"><a name="p18868572411"></a><a name="p18868572411"></a>要删除数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row9887165719417"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p188717571048"><a name="p188717571048"></a><a name="p188717571048"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.529999999999998%" headers="mcps1.1.5.1.2 "><p id="p158871157242"><a name="p158871157242"></a><a name="p158871157242"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.58%" headers="mcps1.1.5.1.3 "><p id="p1588719571148"><a name="p1588719571148"></a><a name="p1588719571148"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.07%" headers="mcps1.1.5.1.4 "><p id="p688714574414"><a name="p688714574414"></a><a name="p688714574414"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
            if (err != undefined) {
                console.log("put err: " + JSON.stringify(err));
                return;
            }
            console.log("put success");
            kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err,data) {
                if (err != undefined) {
                    console.log("delete err: " + JSON.stringify(err));
                    return;
                }
                console.log("delete success");
            });
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### delete<a name="section1298265189"></a>

delete\(key: string\): Promise<void\>

从数据库中删除指定键值的数据，并通过Promise方式返回，此方法为异步方法。

-   参数：

    <a name="table4202936063"></a>
    <table><thead align="left"><tr id="row6202536565"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p152029362618"><a name="p152029362618"></a><a name="p152029362618"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p9203123619614"><a name="p9203123619614"></a><a name="p9203123619614"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p62039360614"><a name="p62039360614"></a><a name="p62039360614"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p62037369618"><a name="p62037369618"></a><a name="p62037369618"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row220323617610"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p120343619611"><a name="p120343619611"></a><a name="p120343619611"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p17203236167"><a name="p17203236167"></a><a name="p17203236167"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p1420343611616"><a name="p1420343611616"></a><a name="p1420343611616"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p120313364610"><a name="p120313364610"></a><a name="p120313364610"></a>要删除数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table898511515811"></a>
    <table><thead align="left"><tr id="row1398616518817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p19860516812"><a name="p19860516812"></a><a name="p19860516812"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p17986115489"><a name="p17986115489"></a><a name="p17986115489"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row898611514813"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p39861451811"><a name="p39861451811"></a><a name="p39861451811"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p69870519814"><a name="p69870519814"></a><a name="p69870519814"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
            console.log("put success: " + JSON.stringify(data));
            kvStore.delete(KEY_TEST_STRING_ELEMENT).then((data) => {
                console.log("delete success");
            }).catch((err) => {
                console.log("delete err: " + JSON.stringify(err));
            });
        }).catch((err) => {
            console.log("put err: " + JSON.stringify(err));
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### on<a name="section9748071812"></a>

on\(event: 'dataChange', type: SubscribeType, observer: Callback<ChangeNotification\>\): void

订阅指定类型的数据变更通知，此方法为同步方法。

-   参数：

    <a name="table074609186"></a>
    <table><thead align="left"><tr id="row1274120111815"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="p18751803180"><a name="p18751803180"></a><a name="p18751803180"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.14%" id="mcps1.1.4.1.2"><p id="p13752021816"><a name="p13752021816"></a><a name="p13752021816"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.32%" id="mcps1.1.4.1.3"><p id="p17751081815"><a name="p17751081815"></a><a name="p17751081815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8751009186"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="p17752091815"><a name="p17752091815"></a><a name="p17752091815"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="p1675120191811"><a name="p1675120191811"></a><a name="p1675120191811"></a>'dataChange'</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="p9755012181"><a name="p9755012181"></a><a name="p9755012181"></a>回调函数名称。</p>
    </td>
    </tr>
    <tr id="row5751709182"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="p17751602182"><a name="p17751602182"></a><a name="p17751602182"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="p137613011189"><a name="p137613011189"></a><a name="p137613011189"></a><a href="#section099619567453">SubscribeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="p117616061817"><a name="p117616061817"></a><a name="p117616061817"></a>表示订阅的类型。</p>
    </td>
    </tr>
    <tr id="row476140141813"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="p16768011189"><a name="p16768011189"></a><a name="p16768011189"></a>observer</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="p107614014186"><a name="p107614014186"></a><a name="p107614014186"></a>Callback&lt;<a href="#section5607141204713">ChangeNotification</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="p576180111819"><a name="p576180111819"></a><a name="p576180111819"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    kvStore.on('dataChange', 2, function (data) {
        console.log("dataChange callback call data: " + JSON.stringify(data));
    });
    ```


### on<a name="section06419235582"></a>

on\(event: 'syncComplete', syncCallback: Callback<Array<\[string, number\]\>\>\): void

订阅数据同步完成通知，此方法为同步方法。

-   参数：

    <a name="table16642172313584"></a>
    <table><thead align="left"><tr id="row1064292310587"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="p9642172345810"><a name="p9642172345810"></a><a name="p9642172345810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.160000000000004%" id="mcps1.1.4.1.2"><p id="p1264242365813"><a name="p1264242365813"></a><a name="p1264242365813"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.3%" id="mcps1.1.4.1.3"><p id="p16426231582"><a name="p16426231582"></a><a name="p16426231582"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row196421223165820"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="p13944834181016"><a name="p13944834181016"></a><a name="p13944834181016"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.160000000000004%" headers="mcps1.1.4.1.2 "><p id="p14715174110107"><a name="p14715174110107"></a><a name="p14715174110107"></a>'syncComplete'</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.3%" headers="mcps1.1.4.1.3 "><p id="p564282316586"><a name="p564282316586"></a><a name="p564282316586"></a>回调函数名称。</p>
    </td>
    </tr>
    <tr id="row629323499"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="p629393496"><a name="p629393496"></a><a name="p629393496"></a>syncCallback</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.160000000000004%" headers="mcps1.1.4.1.2 "><p id="p92931231917"><a name="p92931231917"></a><a name="p92931231917"></a>Callback&lt;Array&lt;[string, number]&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.3%" headers="mcps1.1.4.1.3 "><p id="p529433197"><a name="p529433197"></a><a name="p529433197"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    kvStore.on('syncComplete', function (data) {
        console.log("syncComplete callback call data: " + data);
    });
    ```


## SubscribeType<a name="section099619567453"></a>

描述订阅类型。

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p52851329122117"><a name="p52851329122117"></a><a name="p52851329122117"></a>SUBSCRIBE_TYPE_LOCAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>表示订阅本地数据变更。</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p12106173918219"><a name="p12106173918219"></a><a name="p12106173918219"></a>SUBSCRIBE_TYPE_REMOTE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15865395215"><a name="p15865395215"></a><a name="p15865395215"></a>表示订阅远端数据变更。</p>
</td>
</tr>
<tr id="row1424110293364"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p8242729133612"><a name="p8242729133612"></a><a name="p8242729133612"></a>SUBSCRIBE_TYPE_ALL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1243629153617"><a name="p1243629153617"></a><a name="p1243629153617"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p202430293369"><a name="p202430293369"></a><a name="p202430293369"></a>表示订阅远端和本地数据变更。</p>
</td>
</tr>
</tbody>
</table>

## ChangeNotification<a name="section5607141204713"></a>

数据变更时通知的对象，包括数据插入的数据、更新的数据、删除的数据和设备ID。

<a name="table78681657195717"></a>
<table><thead align="left"><tr id="row138681857165718"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p0868205785716"><a name="p0868205785716"></a><a name="p0868205785716"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.6.1.2"><p id="p2086805735714"><a name="p2086805735714"></a><a name="p2086805735714"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.6.1.3"><p id="p13869145775710"><a name="p13869145775710"></a><a name="p13869145775710"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.4"><p id="p1886919575575"><a name="p1886919575575"></a><a name="p1886919575575"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.6.1.5"><p id="p9869175715718"><a name="p9869175715718"></a><a name="p9869175715718"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row7869155795710"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p81594559583"><a name="p81594559583"></a><a name="p81594559583"></a>insertEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p3869457195712"><a name="p3869457195712"></a><a name="p3869457195712"></a><a href="#section15495151319483">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p6869115735719"><a name="p6869115735719"></a><a name="p6869115735719"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p286925765713"><a name="p286925765713"></a><a name="p286925765713"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p188701857135710"><a name="p188701857135710"></a><a name="p188701857135710"></a>数据添加记录。</p>
</td>
</tr>
<tr id="row787019578574"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1287045745715"><a name="p1287045745715"></a><a name="p1287045745715"></a>updateEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p5212185939"><a name="p5212185939"></a><a name="p5212185939"></a><a href="#section15495151319483">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p1087045713577"><a name="p1087045713577"></a><a name="p1087045713577"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p1487035713575"><a name="p1487035713575"></a><a name="p1487035713575"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p3870145711570"><a name="p3870145711570"></a><a name="p3870145711570"></a>数据更新记录。</p>
</td>
</tr>
<tr id="row18863111108"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p18864111506"><a name="p18864111506"></a><a name="p18864111506"></a>deleteEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p13119713317"><a name="p13119713317"></a><a name="p13119713317"></a><a href="#section15495151319483">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p48641111301"><a name="p48641111301"></a><a name="p48641111301"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p1864617019"><a name="p1864617019"></a><a name="p1864617019"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p2864414014"><a name="p2864414014"></a><a name="p2864414014"></a>数据删除记录。</p>
</td>
</tr>
<tr id="row79531857013"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p0953151013"><a name="p0953151013"></a><a name="p0953151013"></a>deviceId</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p1953451208"><a name="p1953451208"></a><a name="p1953451208"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p169541959012"><a name="p169541959012"></a><a name="p169541959012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p295485903"><a name="p295485903"></a><a name="p295485903"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p109541451017"><a name="p109541451017"></a><a name="p109541451017"></a>设备ID，此处为设备UUID。</p>
</td>
</tr>
</tbody>
</table>

## Entry<a name="section15495151319483"></a>

存储在数据库中的键值对。

<a name="table1678101205113"></a>
<table><thead align="left"><tr id="row11678161175117"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p106785111512"><a name="p106785111512"></a><a name="p106785111512"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.6.1.2"><p id="p1567817115512"><a name="p1567817115512"></a><a name="p1567817115512"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.6.1.3"><p id="p1678101125110"><a name="p1678101125110"></a><a name="p1678101125110"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.4"><p id="p1767831195117"><a name="p1767831195117"></a><a name="p1767831195117"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.6.1.5"><p id="p196786118515"><a name="p196786118515"></a><a name="p196786118515"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1667919113510"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1632904315112"><a name="p1632904315112"></a><a name="p1632904315112"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p7679111185111"><a name="p7679111185111"></a><a name="p7679111185111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p136792135115"><a name="p136792135115"></a><a name="p136792135115"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p186799120516"><a name="p186799120516"></a><a name="p186799120516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p26792013514"><a name="p26792013514"></a><a name="p26792013514"></a>键值。</p>
</td>
</tr>
<tr id="row267931185113"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p867951145114"><a name="p867951145114"></a><a name="p867951145114"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="p86791318519"><a name="p86791318519"></a><a name="p86791318519"></a><a href="#section12882825611">Value</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="p14679181175114"><a name="p14679181175114"></a><a name="p14679181175114"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="p16797195110"><a name="p16797195110"></a><a name="p16797195110"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="p166791011516"><a name="p166791011516"></a><a name="p166791011516"></a>值对象。</p>
</td>
</tr>
</tbody>
</table>

## Value<a name="section1351132114819"></a>

存储在数据库中的对象。

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000003%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.030000000000005%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.850000000000001%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="5.98%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="43.27%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000003%" headers="mcps1.1.6.1.1 "><p id="p85976431431"><a name="p85976431431"></a><a name="p85976431431"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="27.030000000000005%" headers="mcps1.1.6.1.2 "><p id="p1670245834819"><a name="p1670245834819"></a><a name="p1670245834819"></a><a href="#section1327437134818">ValueType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.3 "><p id="p1059711439317"><a name="p1059711439317"></a><a name="p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="5.98%" headers="mcps1.1.6.1.4 "><p id="p659715430317"><a name="p659715430317"></a><a name="p659715430317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.27%" headers="mcps1.1.6.1.5 "><p id="p2059719436313"><a name="p2059719436313"></a><a name="p2059719436313"></a>值类型。</p>
</td>
</tr>
<tr id="row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000003%" headers="mcps1.1.6.1.1 "><p id="p1559710432310"><a name="p1559710432310"></a><a name="p1559710432310"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="27.030000000000005%" headers="mcps1.1.6.1.2 "><p id="p16597144318312"><a name="p16597144318312"></a><a name="p16597144318312"></a>Uint8Array | string | number | boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.3 "><p id="p12597194313317"><a name="p12597194313317"></a><a name="p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="5.98%" headers="mcps1.1.6.1.4 "><p id="p1259710431236"><a name="p1259710431236"></a><a name="p1259710431236"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.27%" headers="mcps1.1.6.1.5 "><p id="p10597843034"><a name="p10597843034"></a><a name="p10597843034"></a>值，Uint8Array、string 的长度不大于<a href="#p9253605466">MAX_VALUE_LENGTH</a>。</p>
</td>
</tr>
</tbody>
</table>

## ValueType<a name="section1327437134818"></a>

用于表示数据类型。

只能被内部应用使用。

<a name="table1923665410559"></a>
<table><thead align="left"><tr id="row2236185411552"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p1723755417554"><a name="p1723755417554"></a><a name="p1723755417554"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p1523745410556"><a name="p1523745410556"></a><a name="p1523745410556"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p10237454125510"><a name="p10237454125510"></a><a name="p10237454125510"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13237165420553"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p623715475519"><a name="p623715475519"></a><a name="p623715475519"></a>STRING</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p12237125410557"><a name="p12237125410557"></a><a name="p12237125410557"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p3237175419556"><a name="p3237175419556"></a><a name="p3237175419556"></a>表示值类型为字符串。</p>
</td>
</tr>
<tr id="row16237185419559"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p202378547551"><a name="p202378547551"></a><a name="p202378547551"></a>INTEGER</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p11238175416559"><a name="p11238175416559"></a><a name="p11238175416559"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p2023820548551"><a name="p2023820548551"></a><a name="p2023820548551"></a>表示值类型为整数。</p>
</td>
</tr>
<tr id="row1123865425514"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p122381554145510"><a name="p122381554145510"></a><a name="p122381554145510"></a>FLOAT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p923819542558"><a name="p923819542558"></a><a name="p923819542558"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p17238454105516"><a name="p17238454105516"></a><a name="p17238454105516"></a>表示值类型为浮点数。</p>
</td>
</tr>
<tr id="row068212344590"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p66831534145911"><a name="p66831534145911"></a><a name="p66831534145911"></a>BYTE_ARRAY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1768343455917"><a name="p1768343455917"></a><a name="p1768343455917"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1684173416596"><a name="p1684173416596"></a><a name="p1684173416596"></a>表示值类型为字节数组。</p>
</td>
</tr>
<tr id="row28813815919"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1389123814598"><a name="p1389123814598"></a><a name="p1389123814598"></a>BOOLEAN</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1089338195918"><a name="p1089338195918"></a><a name="p1089338195918"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p589538175910"><a name="p589538175910"></a><a name="p589538175910"></a>表示值类型为布尔值。</p>
</td>
</tr>
<tr id="row59211240145919"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1921114013599"><a name="p1921114013599"></a><a name="p1921114013599"></a>DOUBLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1921124018594"><a name="p1921124018594"></a><a name="p1921124018594"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p4921174085915"><a name="p4921174085915"></a><a name="p4921174085915"></a>表示值类型为双浮点数。</p>
</td>
</tr>
</tbody>
</table>

## SingleKVStore<a name="section87965384295"></a>

单版本分布式数据库，继承自KVStore，提供查询数据和同步数据的方法。在调用SingleKVStore的方法前，需要先通过getKVStore构建一个KVStore实例。

### get<a name="section107972383294"></a>

get\(key: string, callback: AsyncCallback<Uint8Array | string | boolean | number\>\): void

获取指定键的值，并通过callback方式返回，此方法为异步方法。

-   参数：

    <a name="table127971038192914"></a>
    <table><thead align="left"><tr id="row1979813832919"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p197982388292"><a name="p197982388292"></a><a name="p197982388292"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p147988381296"><a name="p147988381296"></a><a name="p147988381296"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p8798193818295"><a name="p8798193818295"></a><a name="p8798193818295"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p1579853822920"><a name="p1579853822920"></a><a name="p1579853822920"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row37981380296"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12798183818294"><a name="p12798183818294"></a><a name="p12798183818294"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p1879813386295"><a name="p1879813386295"></a><a name="p1879813386295"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p37994380299"><a name="p37994380299"></a><a name="p37994380299"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p1879913882919"><a name="p1879913882919"></a><a name="p1879913882919"></a>要查询数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    <tr id="row78002038172916"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1080073812920"><a name="p1080073812920"></a><a name="p1080073812920"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p380043819290"><a name="p380043819290"></a><a name="p380043819290"></a>AsyncCallback&lt;Uint8Array | string | boolean | number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p280093882916"><a name="p280093882916"></a><a name="p280093882916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p1280033815294"><a name="p1280033815294"></a><a name="p1280033815294"></a>回调函数，获取查询的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
            if (err != undefined) {
                console.log("put err: " + JSON.stringify(err));
                return;
            }
            console.log("put success");
            kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {
                console.log("get success data: " + data);
            });
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### get<a name="section1326485818382"></a>

get\(key: string\): Promise<Uint8Array | string | boolean | number\>

获取指定键的值，并通过Promise方式返回，此方法为异步方法。

-   参数：

    <a name="table5264458143812"></a>
    <table><thead align="left"><tr id="row1226518580386"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8265155813820"><a name="p8265155813820"></a><a name="p8265155813820"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.44%" id="mcps1.1.5.1.2"><p id="p1926655893820"><a name="p1926655893820"></a><a name="p1926655893820"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.4799999999999995%" id="mcps1.1.5.1.3"><p id="p162661758193810"><a name="p162661758193810"></a><a name="p162661758193810"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.260000000000005%" id="mcps1.1.5.1.4"><p id="p19266155815388"><a name="p19266155815388"></a><a name="p19266155815388"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1226655811388"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6266125823812"><a name="p6266125823812"></a><a name="p6266125823812"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.44%" headers="mcps1.1.5.1.2 "><p id="p1526605883820"><a name="p1526605883820"></a><a name="p1526605883820"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.4799999999999995%" headers="mcps1.1.5.1.3 "><p id="p0267105820381"><a name="p0267105820381"></a><a name="p0267105820381"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p192675585380"><a name="p192675585380"></a><a name="p192675585380"></a>要查询数据的key，不能为空且长度不大于<a href="#p10198639174218">MAX_KEY_LENGTH</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table3268158153812"></a>
    <table><thead align="left"><tr id="row2269195833813"><th class="cellrowborder" valign="top" width="33.44%" id="mcps1.1.3.1.1"><p id="p1626945818384"><a name="p1626945818384"></a><a name="p1626945818384"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.56%" id="mcps1.1.3.1.2"><p id="p12691758123818"><a name="p12691758123818"></a><a name="p12691758123818"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row726916586386"><td class="cellrowborder" valign="top" width="33.44%" headers="mcps1.1.3.1.1 "><p id="p162691058173812"><a name="p162691058173812"></a><a name="p162691058173812"></a>Promise&lt;Uint8Array | string | boolean | number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.56%" headers="mcps1.1.3.1.2 "><p id="p8270175814388"><a name="p8270175814388"></a><a name="p8270175814388"></a>Promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
    try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
            console.log("put success: " + JSON.stringify(data));
            kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
                console.log("get success data: " + data);
            }).catch((err) => {
                console.log("get err: " + JSON.stringify(err));
            });
        }).catch((err) => {
            console.log("put err: " + JSON.stringify(err));
        });
    }catch (e) {
        console.log("An unexpected error occurred. Error:" + e);
    }
    ```


### sync<a name="section619117584517"></a>

sync\(deviceIdList: string\[\], mode: SyncMode, allowedDelayMs?: number\): void

在手动同步模式下，触发数据库同步，此方法为同步方法。

-   参数：

    <a name="table31921253453"></a>
    <table><thead align="left"><tr id="row1519317519458"><th class="cellrowborder" valign="top" width="17.91%" id="mcps1.1.5.1.1"><p id="p719317510452"><a name="p719317510452"></a><a name="p719317510452"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.2"><p id="p12194957458"><a name="p12194957458"></a><a name="p12194957458"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.290000000000001%" id="mcps1.1.5.1.3"><p id="p46421923185813"><a name="p46421923185813"></a><a name="p46421923185813"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.22%" id="mcps1.1.5.1.4"><p id="p101944512459"><a name="p101944512459"></a><a name="p101944512459"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1519413534519"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="p176426239586"><a name="p176426239586"></a><a name="p176426239586"></a>deviceIdList</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.2 "><p id="p11642192345813"><a name="p11642192345813"></a><a name="p11642192345813"></a>string[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.290000000000001%" headers="mcps1.1.5.1.3 "><p id="p196428238584"><a name="p196428238584"></a><a name="p196428238584"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.22%" headers="mcps1.1.5.1.4 "><p id="p1619614544513"><a name="p1619614544513"></a><a name="p1619614544513"></a>同一组网环境下，需要同步的设备的deviceId列表。</p>
    </td>
    </tr>
    <tr id="row15290171774817"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="p52919178483"><a name="p52919178483"></a><a name="p52919178483"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.2 "><p id="p0291617134819"><a name="p0291617134819"></a><a name="p0291617134819"></a><a href="#section1226994713484">SyncMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.290000000000001%" headers="mcps1.1.5.1.3 "><p id="p1829171719482"><a name="p1829171719482"></a><a name="p1829171719482"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.22%" headers="mcps1.1.5.1.4 "><p id="p219412514334"><a name="p219412514334"></a><a name="p219412514334"></a>同步类型。</p>
    </td>
    </tr>
    <tr id="row7797191217527"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="p11797512195211"><a name="p11797512195211"></a><a name="p11797512195211"></a>allowedDelayMs</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.2 "><p id="p15797181210529"><a name="p15797181210529"></a><a name="p15797181210529"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.290000000000001%" headers="mcps1.1.5.1.3 "><p id="p10797712145215"><a name="p10797712145215"></a><a name="p10797712145215"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.22%" headers="mcps1.1.5.1.4 "><p id="p20797912145218"><a name="p20797912145218"></a><a name="p20797912145218"></a>可选参数，允许延时时间，单位：ms（毫秒）。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    kvStore.sync(deviceIds, 1, 1000);
    ```


## SyncMode<a name="section1226994713484"></a>

用于指定同步模式。

<a name="table8354105916513"></a>
<table><thead align="left"><tr id="row1354105910516"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p33541759165113"><a name="p33541759165113"></a><a name="p33541759165113"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p235418596518"><a name="p235418596518"></a><a name="p235418596518"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p183541159105112"><a name="p183541159105112"></a><a name="p183541159105112"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row7354175995119"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p6355155955114"><a name="p6355155955114"></a><a name="p6355155955114"></a>PULL_ONLY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p10355195935119"><a name="p10355195935119"></a><a name="p10355195935119"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p33554599512"><a name="p33554599512"></a><a name="p33554599512"></a>表示只能从远端拉取数据到本端。</p>
</td>
</tr>
<tr id="row1035565965119"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p193147910536"><a name="p193147910536"></a><a name="p193147910536"></a>PUSH_ONLY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p11355185965112"><a name="p11355185965112"></a><a name="p11355185965112"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p143551959205110"><a name="p143551959205110"></a><a name="p143551959205110"></a>表示只能从本端推送数据到对端。</p>
</td>
</tr>
<tr id="row935516595516"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p482031615539"><a name="p482031615539"></a><a name="p482031615539"></a>PUSH_PULL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p15355145995118"><a name="p15355145995118"></a><a name="p15355145995118"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p83561598516"><a name="p83561598516"></a><a name="p83561598516"></a>表示从本端推送数据到远端，然后从远端拉取数据到本端。</p>
</td>
</tr>
</tbody>
</table>

