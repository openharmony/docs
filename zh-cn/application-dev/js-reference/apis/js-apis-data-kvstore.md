# 分布式数据库操作描述<a name="ZH-CN_TOPIC_0000001209210727"></a>

-   [导入模块](#zh-cn_topic_0000001175986853_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001175986853_section11257113618419)
-   [KVStore](#zh-cn_topic_0000001175986853_section12882825611)
    -   [put\(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback<void\>\): void](#zh-cn_topic_0000001175986853_section1942221513)
    -   [put\(key: string, value: Uint8Array | string | number | boolean\): Promise<void\>](#zh-cn_topic_0000001175986853_section43065440019)
    -   [delete\(key: string, callback: AsyncCallback<void\>\): void](#zh-cn_topic_0000001175986853_section15564125555713)
    -   [delete\(key: string\): Promise<void\>](#zh-cn_topic_0000001175986853_section1298265189)
    -   [on\(event: 'dataChange', type: SubscribeType, observer: Callback<ChangeNotification\>\): void](#zh-cn_topic_0000001175986853_section9748071812)
    -   [on\(event: 'syncComplete', syncCallback: Callback<Array<\[string, number\]\>\>\): void](#zh-cn_topic_0000001175986853_section06419235582)


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001175986853_s56d19203690d4782bfc74069abb6bd71"></a>

```
import factory from '@ohos.data.distributeddata';
```

## 权限<a name="zh-cn_topic_0000001175986853_section11257113618419"></a>

无

## KVStore<a name="zh-cn_topic_0000001175986853_section12882825611"></a>

表示分布式数据库，并提供添加数据、删除数据和订阅数据变更的方法。

### put\(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback<void\>\): void<a name="zh-cn_topic_0000001175986853_section1942221513"></a>

添加指定类型键值对到数据库。

此方法是异步callback方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table139428218117"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row8943821510"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p139439212111"><a name="zh-cn_topic_0000001175986853_p139439212111"></a><a name="zh-cn_topic_0000001175986853_p139439212111"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.68%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p5943721919"><a name="zh-cn_topic_0000001175986853_p5943721919"></a><a name="zh-cn_topic_0000001175986853_p5943721919"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.78%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p11943142518"><a name="zh-cn_topic_0000001175986853_p11943142518"></a><a name="zh-cn_topic_0000001175986853_p11943142518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row1794311214119"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p1094402916"><a name="zh-cn_topic_0000001175986853_p1094402916"></a><a name="zh-cn_topic_0000001175986853_p1094402916"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p794412718"><a name="zh-cn_topic_0000001175986853_p794412718"></a><a name="zh-cn_topic_0000001175986853_p794412718"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p2944424110"><a name="zh-cn_topic_0000001175986853_p2944424110"></a><a name="zh-cn_topic_0000001175986853_p2944424110"></a>要添加数据的key。不能为空且长度不大于1KB。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row5944129113"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p8944929118"><a name="zh-cn_topic_0000001175986853_p8944929118"></a><a name="zh-cn_topic_0000001175986853_p8944929118"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p1294420220114"><a name="zh-cn_topic_0000001175986853_p1294420220114"></a><a name="zh-cn_topic_0000001175986853_p1294420220114"></a>Uint8Array | string | number | boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p248495010524"><a name="zh-cn_topic_0000001175986853_p248495010524"></a><a name="zh-cn_topic_0000001175986853_p248495010524"></a>存储的新值。支持Uint8Array、number 、 string 、boolean。</p>
    <p id="zh-cn_topic_0000001175986853_p89451526118"><a name="zh-cn_topic_0000001175986853_p89451526118"></a><a name="zh-cn_topic_0000001175986853_p89451526118"></a>Uint8Array的长度小于4M。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row109451529112"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p1494552214"><a name="zh-cn_topic_0000001175986853_p1494552214"></a><a name="zh-cn_topic_0000001175986853_p1494552214"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p19455210120"><a name="zh-cn_topic_0000001175986853_p19455210120"></a><a name="zh-cn_topic_0000001175986853_p19455210120"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p139457210111"><a name="zh-cn_topic_0000001175986853_p139457210111"></a><a name="zh-cn_topic_0000001175986853_p139457210111"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例

    ```
    kvStore.put('key-001', 'value-001', function(err, value){
    });
    ```


### put\(key: string, value: Uint8Array | string | number | boolean\): Promise<void\><a name="zh-cn_topic_0000001175986853_section43065440019"></a>

添加指定类型键值对到数据库。

此方法是异步promise方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table794711212116"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row3947021118"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p99471028116"><a name="zh-cn_topic_0000001175986853_p99471028116"></a><a name="zh-cn_topic_0000001175986853_p99471028116"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.68%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p169471620118"><a name="zh-cn_topic_0000001175986853_p169471620118"></a><a name="zh-cn_topic_0000001175986853_p169471620118"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.78%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p119481921315"><a name="zh-cn_topic_0000001175986853_p119481921315"></a><a name="zh-cn_topic_0000001175986853_p119481921315"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row7948820112"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p109481021916"><a name="zh-cn_topic_0000001175986853_p109481021916"></a><a name="zh-cn_topic_0000001175986853_p109481021916"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p1694816216111"><a name="zh-cn_topic_0000001175986853_p1694816216111"></a><a name="zh-cn_topic_0000001175986853_p1694816216111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p119481124114"><a name="zh-cn_topic_0000001175986853_p119481124114"></a><a name="zh-cn_topic_0000001175986853_p119481124114"></a>要添加数据的key。不能为空且长度不大于1KB。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row1948112913"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p19948824120"><a name="zh-cn_topic_0000001175986853_p19948824120"></a><a name="zh-cn_topic_0000001175986853_p19948824120"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p694910210110"><a name="zh-cn_topic_0000001175986853_p694910210110"></a><a name="zh-cn_topic_0000001175986853_p694910210110"></a>Uint8Array | string | number | boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p794962318"><a name="zh-cn_topic_0000001175986853_p794962318"></a><a name="zh-cn_topic_0000001175986853_p794962318"></a>要添加的数据。支持Uint8Array、number 、 string 、boolean。</p>
    <p id="zh-cn_topic_0000001175986853_p19822171715312"><a name="zh-cn_topic_0000001175986853_p19822171715312"></a><a name="zh-cn_topic_0000001175986853_p19822171715312"></a>Uint8Array和string类型的value长度必须小于4MB。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001175986853_table59499217114"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row5949322117"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001175986853_p129505214113"><a name="zh-cn_topic_0000001175986853_p129505214113"></a><a name="zh-cn_topic_0000001175986853_p129505214113"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001175986853_p395018214112"><a name="zh-cn_topic_0000001175986853_p395018214112"></a><a name="zh-cn_topic_0000001175986853_p395018214112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row9950162310"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001175986853_p149501621616"><a name="zh-cn_topic_0000001175986853_p149501621616"></a><a name="zh-cn_topic_0000001175986853_p149501621616"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001175986853_p1695072011"><a name="zh-cn_topic_0000001175986853_p1695072011"></a><a name="zh-cn_topic_0000001175986853_p1695072011"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    const promise = kvStore.put('key-001', 'value-001');
        promise.then((data) => {
        }).catch((err) => {
        });
    ```


### delete\(key: string, callback: AsyncCallback<void\>\): void<a name="zh-cn_topic_0000001175986853_section15564125555713"></a>

从数据库中删除指定键值的数据。

此方法是异步callback方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table19564125545715"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row5565135518577"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p1856518555576"><a name="zh-cn_topic_0000001175986853_p1856518555576"></a><a name="zh-cn_topic_0000001175986853_p1856518555576"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.68%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p10565105518570"><a name="zh-cn_topic_0000001175986853_p10565105518570"></a><a name="zh-cn_topic_0000001175986853_p10565105518570"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.78%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p356525525718"><a name="zh-cn_topic_0000001175986853_p356525525718"></a><a name="zh-cn_topic_0000001175986853_p356525525718"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row1756535515573"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p17565125525717"><a name="zh-cn_topic_0000001175986853_p17565125525717"></a><a name="zh-cn_topic_0000001175986853_p17565125525717"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p1156514559576"><a name="zh-cn_topic_0000001175986853_p1156514559576"></a><a name="zh-cn_topic_0000001175986853_p1156514559576"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p9565145511574"><a name="zh-cn_topic_0000001175986853_p9565145511574"></a><a name="zh-cn_topic_0000001175986853_p9565145511574"></a>要删除数据的key。不能为空且长度不大于1KB。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row175661255105713"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p15566135505713"><a name="zh-cn_topic_0000001175986853_p15566135505713"></a><a name="zh-cn_topic_0000001175986853_p15566135505713"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p13566115513572"><a name="zh-cn_topic_0000001175986853_p13566115513572"></a><a name="zh-cn_topic_0000001175986853_p13566115513572"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p65661550577"><a name="zh-cn_topic_0000001175986853_p65661550577"></a><a name="zh-cn_topic_0000001175986853_p65661550577"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例

    ```
    kvStore.delete('key-001', function(err, value){
    });
    ```


### delete\(key: string\): Promise<void\><a name="zh-cn_topic_0000001175986853_section1298265189"></a>

从数据库中删除指定键值的数据。

此方法是异步promise方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table9983952086"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row1798311511811"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p16983145787"><a name="zh-cn_topic_0000001175986853_p16983145787"></a><a name="zh-cn_topic_0000001175986853_p16983145787"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.68%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p15983058812"><a name="zh-cn_topic_0000001175986853_p15983058812"></a><a name="zh-cn_topic_0000001175986853_p15983058812"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.78%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p16984205389"><a name="zh-cn_topic_0000001175986853_p16984205389"></a><a name="zh-cn_topic_0000001175986853_p16984205389"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row99841511816"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p169841354817"><a name="zh-cn_topic_0000001175986853_p169841354817"></a><a name="zh-cn_topic_0000001175986853_p169841354817"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.68%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p498416517813"><a name="zh-cn_topic_0000001175986853_p498416517813"></a><a name="zh-cn_topic_0000001175986853_p498416517813"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.78%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p19851051887"><a name="zh-cn_topic_0000001175986853_p19851051887"></a><a name="zh-cn_topic_0000001175986853_p19851051887"></a>要删除数据的key。不能为空且长度不大于1KB。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001175986853_table898511515811"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row1398616518817"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001175986853_p19860516812"><a name="zh-cn_topic_0000001175986853_p19860516812"></a><a name="zh-cn_topic_0000001175986853_p19860516812"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001175986853_p17986115489"><a name="zh-cn_topic_0000001175986853_p17986115489"></a><a name="zh-cn_topic_0000001175986853_p17986115489"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row898611514813"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001175986853_p39861451811"><a name="zh-cn_topic_0000001175986853_p39861451811"></a><a name="zh-cn_topic_0000001175986853_p39861451811"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001175986853_p69870519814"><a name="zh-cn_topic_0000001175986853_p69870519814"></a><a name="zh-cn_topic_0000001175986853_p69870519814"></a>Promise实例，用于异步处理。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    const promise = kvStore.delete('key-001');
          promise.then((data) => {
          }).catch((err) => {
          });
    ```


### on\(event: 'dataChange', type: SubscribeType, observer: Callback<ChangeNotification\>\): void<a name="zh-cn_topic_0000001175986853_section9748071812"></a>

订阅指定类型的数据更改通知。

此方法是同步方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table074609186"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row1274120111815"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p18751803180"><a name="zh-cn_topic_0000001175986853_p18751803180"></a><a name="zh-cn_topic_0000001175986853_p18751803180"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.14%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p13752021816"><a name="zh-cn_topic_0000001175986853_p13752021816"></a><a name="zh-cn_topic_0000001175986853_p13752021816"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.32%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p17751081815"><a name="zh-cn_topic_0000001175986853_p17751081815"></a><a name="zh-cn_topic_0000001175986853_p17751081815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row8751009186"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p17752091815"><a name="zh-cn_topic_0000001175986853_p17752091815"></a><a name="zh-cn_topic_0000001175986853_p17752091815"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p1675120191811"><a name="zh-cn_topic_0000001175986853_p1675120191811"></a><a name="zh-cn_topic_0000001175986853_p1675120191811"></a>'dataChange'</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p9755012181"><a name="zh-cn_topic_0000001175986853_p9755012181"></a><a name="zh-cn_topic_0000001175986853_p9755012181"></a>回调函数名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row5751709182"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p17751602182"><a name="zh-cn_topic_0000001175986853_p17751602182"></a><a name="zh-cn_topic_0000001175986853_p17751602182"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p137613011189"><a name="zh-cn_topic_0000001175986853_p137613011189"></a><a name="zh-cn_topic_0000001175986853_p137613011189"></a><a href="js-apis-data-type.md#zh-cn_topic_0000001129943828_section099619567453">SubscribeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p117616061817"><a name="zh-cn_topic_0000001175986853_p117616061817"></a><a name="zh-cn_topic_0000001175986853_p117616061817"></a>表示订阅的类型。具体参考SubscribeType。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row476140141813"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p16768011189"><a name="zh-cn_topic_0000001175986853_p16768011189"></a><a name="zh-cn_topic_0000001175986853_p16768011189"></a>observer</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.14%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p107614014186"><a name="zh-cn_topic_0000001175986853_p107614014186"></a><a name="zh-cn_topic_0000001175986853_p107614014186"></a>Callback&lt;<a href="js-apis-data-type.md#zh-cn_topic_0000001129943828_section9868357105716">ChangeNotification</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.32%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p576180111819"><a name="zh-cn_topic_0000001175986853_p576180111819"></a><a name="zh-cn_topic_0000001175986853_p576180111819"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例

    ```
    kvStore.on('dataChange', 0, function(notification){
    });
    ```


### on\(event: 'syncComplete', syncCallback: Callback<Array<\[string, number\]\>\>\): void<a name="zh-cn_topic_0000001175986853_section06419235582"></a>

订阅指定类型的数据更改通知。

此方法是同步方法。

-   参数：

    <a name="zh-cn_topic_0000001175986853_table16642172313584"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001175986853_row1064292310587"><th class="cellrowborder" valign="top" width="16.54%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175986853_p9642172345810"><a name="zh-cn_topic_0000001175986853_p9642172345810"></a><a name="zh-cn_topic_0000001175986853_p9642172345810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.160000000000004%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175986853_p1264242365813"><a name="zh-cn_topic_0000001175986853_p1264242365813"></a><a name="zh-cn_topic_0000001175986853_p1264242365813"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.3%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175986853_p16426231582"><a name="zh-cn_topic_0000001175986853_p16426231582"></a><a name="zh-cn_topic_0000001175986853_p16426231582"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001175986853_row196421223165820"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p13944834181016"><a name="zh-cn_topic_0000001175986853_p13944834181016"></a><a name="zh-cn_topic_0000001175986853_p13944834181016"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.160000000000004%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p14715174110107"><a name="zh-cn_topic_0000001175986853_p14715174110107"></a><a name="zh-cn_topic_0000001175986853_p14715174110107"></a>'syncComplete'</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.3%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p564282316586"><a name="zh-cn_topic_0000001175986853_p564282316586"></a><a name="zh-cn_topic_0000001175986853_p564282316586"></a>回调函数名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001175986853_row629323499"><td class="cellrowborder" valign="top" width="16.54%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175986853_p629393496"><a name="zh-cn_topic_0000001175986853_p629393496"></a><a name="zh-cn_topic_0000001175986853_p629393496"></a>syncCallback</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.160000000000004%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175986853_p92931231917"><a name="zh-cn_topic_0000001175986853_p92931231917"></a><a name="zh-cn_topic_0000001175986853_p92931231917"></a>Callback&lt;Array&lt;[string, number]&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.3%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175986853_p529433197"><a name="zh-cn_topic_0000001175986853_p529433197"></a><a name="zh-cn_topic_0000001175986853_p529433197"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例

    ```
    kvStore.on('syncComplete', function(data){
    });
    ```


