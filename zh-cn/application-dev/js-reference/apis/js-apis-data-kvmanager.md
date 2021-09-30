# 创建和获取分布式数据库<a name="ZH-CN_TOPIC_0000001164130784"></a>

-   [导入模块](#zh-cn_topic_0000001179090937_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001179090937_section11257113618419)
-   [createKVManager\(config: KVManagerConfig, callback: AsyncCallback<KVManager\>\): void](#zh-cn_topic_0000001179090937_section192192415554)
-   [createKVManager\(config: KVManagerConfig\): Promise<KVManager\>](#zh-cn_topic_0000001179090937_section19618143402218)
-   [KVManager](#zh-cn_topic_0000001179090937_section12882825611)
    -   [getKVStore<T extends KVStore\>\(storeId: string, options: Options\): Promise<T\>](#zh-cn_topic_0000001179090937_section51960467216)
    -   [getKVStore<T extends KVStore\>\(storeId: string, options: Options, callback: AsyncCallback<T\>\): void](#zh-cn_topic_0000001179090937_section06419235582)


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001179090937_s56d19203690d4782bfc74069abb6bd71"></a>

```
import factory from '@ohos.data.distributeddata';
```

## 权限<a name="zh-cn_topic_0000001179090937_section11257113618419"></a>

无

## createKVManager\(config: KVManagerConfig, callback: AsyncCallback<KVManager\>\): void<a name="zh-cn_topic_0000001179090937_section192192415554"></a>

创建分布式数据库管理对象。

此方法为异步callback方法。

-   参数：

    <a name="zh-cn_topic_0000001179090937_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row149668318915"><th class="cellrowborder" valign="top" width="18.13%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001179090937_p7966738914"><a name="zh-cn_topic_0000001179090937_p7966738914"></a><a name="zh-cn_topic_0000001179090937_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001179090937_p296713699"><a name="zh-cn_topic_0000001179090937_p296713699"></a><a name="zh-cn_topic_0000001179090937_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.84%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001179090937_p9967231197"><a name="zh-cn_topic_0000001179090937_p9967231197"></a><a name="zh-cn_topic_0000001179090937_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row99671533914"><td class="cellrowborder" valign="top" width="18.13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p79671633910"><a name="zh-cn_topic_0000001179090937_p79671633910"></a><a name="zh-cn_topic_0000001179090937_p79671633910"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p11967433914"><a name="zh-cn_topic_0000001179090937_p11967433914"></a><a name="zh-cn_topic_0000001179090937_p11967433914"></a><a href="js-apis-data-kvmanager-config.md#zh-cn_topic_0000001175852127_section4346145712159">KVManagerConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="54.84%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p69671631796"><a name="zh-cn_topic_0000001179090937_p69671631796"></a><a name="zh-cn_topic_0000001179090937_p69671631796"></a>用于配置管理对象，包括用户信息和应用包名。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001179090937_row5826185610187"><td class="cellrowborder" valign="top" width="18.13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p1482895641811"><a name="zh-cn_topic_0000001179090937_p1482895641811"></a><a name="zh-cn_topic_0000001179090937_p1482895641811"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p1482845617187"><a name="zh-cn_topic_0000001179090937_p1482845617187"></a><a name="zh-cn_topic_0000001179090937_p1482845617187"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001179090937_section12882825611">KVManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.84%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p118284566187"><a name="zh-cn_topic_0000001179090937_p118284566187"></a><a name="zh-cn_topic_0000001179090937_p118284566187"></a>回调函数，获取数据库管理对象实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    factory.createKVManager(config, function (err, manager) {
                kvManager = manager;
            });
    ```


## createKVManager\(config: KVManagerConfig\): Promise<KVManager\><a name="zh-cn_topic_0000001179090937_section19618143402218"></a>

创建分布式数据库管理对象。

此方法为异步promise方法。

-   参数：

    <a name="zh-cn_topic_0000001179090937_table1861873492218"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row11619163419226"><th class="cellrowborder" valign="top" width="18.13%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001179090937_p1361953472215"><a name="zh-cn_topic_0000001179090937_p1361953472215"></a><a name="zh-cn_topic_0000001179090937_p1361953472215"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001179090937_p116191334162215"><a name="zh-cn_topic_0000001179090937_p116191334162215"></a><a name="zh-cn_topic_0000001179090937_p116191334162215"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.84%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001179090937_p15619734192217"><a name="zh-cn_topic_0000001179090937_p15619734192217"></a><a name="zh-cn_topic_0000001179090937_p15619734192217"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row361903412218"><td class="cellrowborder" valign="top" width="18.13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p126191134162215"><a name="zh-cn_topic_0000001179090937_p126191134162215"></a><a name="zh-cn_topic_0000001179090937_p126191134162215"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p68611843483"><a name="zh-cn_topic_0000001179090937_p68611843483"></a><a name="zh-cn_topic_0000001179090937_p68611843483"></a><a href="js-apis-data-kvmanager-config.md#zh-cn_topic_0000001175852127_section4346145712159">KVManagerConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="54.84%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p9619183422211"><a name="zh-cn_topic_0000001179090937_p9619183422211"></a><a name="zh-cn_topic_0000001179090937_p9619183422211"></a>用于配置管理对象，包括用户信息和应用包名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001179090937_table4620834182216"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row362014348227"><th class="cellrowborder" valign="top" width="25.1%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001179090937_p186203346224"><a name="zh-cn_topic_0000001179090937_p186203346224"></a><a name="zh-cn_topic_0000001179090937_p186203346224"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.9%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001179090937_p11620113414229"><a name="zh-cn_topic_0000001179090937_p11620113414229"></a><a name="zh-cn_topic_0000001179090937_p11620113414229"></a>类型</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row186201834102218"><td class="cellrowborder" valign="top" width="25.1%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001179090937_p4620203417221"><a name="zh-cn_topic_0000001179090937_p4620203417221"></a><a name="zh-cn_topic_0000001179090937_p4620203417221"></a>Promise&lt;<a href="#zh-cn_topic_0000001179090937_section12882825611">KVManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.9%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001179090937_p9621234172213"><a name="zh-cn_topic_0000001179090937_p9621234172213"></a><a name="zh-cn_topic_0000001179090937_p9621234172213"></a>promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = factory.createKVManager(config);
    promise.then((manager) => {
                kvManager = manager;
            }).catch((err) => {
            });
    ```


## KVManager<a name="zh-cn_topic_0000001179090937_section12882825611"></a>

提供管理分布式数据库的接口。

### getKVStore<T extends KVStore\>\(storeId: string, options: Options\): Promise<T\><a name="zh-cn_topic_0000001179090937_section51960467216"></a>

创建或获取数据库实例。需要先通过[createKVManager](#zh-cn_topic_0000001179090937_section192192415554)创建或获取KVStore实例。

此方法为异步promise方法。

-   参数：

    <a name="zh-cn_topic_0000001179090937_table1819714611216"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row151971464215"><th class="cellrowborder" valign="top" width="16.31%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001179090937_p1719718463214"><a name="zh-cn_topic_0000001179090937_p1719718463214"></a><a name="zh-cn_topic_0000001179090937_p1719718463214"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.220000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001179090937_p01972461429"><a name="zh-cn_topic_0000001179090937_p01972461429"></a><a name="zh-cn_topic_0000001179090937_p01972461429"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.47%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001179090937_p171977461523"><a name="zh-cn_topic_0000001179090937_p171977461523"></a><a name="zh-cn_topic_0000001179090937_p171977461523"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row1219818462214"><td class="cellrowborder" valign="top" width="16.31%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p191984461828"><a name="zh-cn_topic_0000001179090937_p191984461828"></a><a name="zh-cn_topic_0000001179090937_p191984461828"></a>storeId</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p191988464218"><a name="zh-cn_topic_0000001179090937_p191988464218"></a><a name="zh-cn_topic_0000001179090937_p191988464218"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.47%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p1419834615216"><a name="zh-cn_topic_0000001179090937_p1419834615216"></a><a name="zh-cn_topic_0000001179090937_p1419834615216"></a>用于标识数据库。同一应用下该参数值必须唯一且长度应小于1KB。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001179090937_row1198746820"><td class="cellrowborder" valign="top" width="16.31%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p51981467220"><a name="zh-cn_topic_0000001179090937_p51981467220"></a><a name="zh-cn_topic_0000001179090937_p51981467220"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p1719819464212"><a name="zh-cn_topic_0000001179090937_p1719819464212"></a><a name="zh-cn_topic_0000001179090937_p1719819464212"></a><a href="js-apis-data-type.md#zh-cn_topic_0000001129943828_section16417114202216">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="67.47%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p8198746421"><a name="zh-cn_topic_0000001179090937_p8198746421"></a><a name="zh-cn_topic_0000001179090937_p8198746421"></a>数据库实例的配置信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001179090937_table0198144610210"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row2199134611213"><th class="cellrowborder" valign="top" width="20.66%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001179090937_p1919916467217"><a name="zh-cn_topic_0000001179090937_p1919916467217"></a><a name="zh-cn_topic_0000001179090937_p1919916467217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.34%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001179090937_p1119964610216"><a name="zh-cn_topic_0000001179090937_p1119964610216"></a><a name="zh-cn_topic_0000001179090937_p1119964610216"></a>类型</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row2019914467216"><td class="cellrowborder" valign="top" width="20.66%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001179090937_p191994461026"><a name="zh-cn_topic_0000001179090937_p191994461026"></a><a name="zh-cn_topic_0000001179090937_p191994461026"></a>Promise&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.34%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001179090937_p131998462029"><a name="zh-cn_topic_0000001179090937_p131998462029"></a><a name="zh-cn_topic_0000001179090937_p131998462029"></a>promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = kvManager.getKVStore(options);
            promise.then((store) => {
                kvStore = store;
            }).catch((err) => {
            });
    ```


### getKVStore<T extends KVStore\>\(storeId: string, options: Options, callback: AsyncCallback<T\>\): void<a name="zh-cn_topic_0000001179090937_section06419235582"></a>

创建并获取数据库实例。

此方法为异步callback方法。

-   参数：

    <a name="zh-cn_topic_0000001179090937_table16642172313584"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001179090937_row1064292310587"><th class="cellrowborder" valign="top" width="16.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001179090937_p9642172345810"><a name="zh-cn_topic_0000001179090937_p9642172345810"></a><a name="zh-cn_topic_0000001179090937_p9642172345810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.42%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001179090937_p1264242365813"><a name="zh-cn_topic_0000001179090937_p1264242365813"></a><a name="zh-cn_topic_0000001179090937_p1264242365813"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.29%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001179090937_p16426231582"><a name="zh-cn_topic_0000001179090937_p16426231582"></a><a name="zh-cn_topic_0000001179090937_p16426231582"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001179090937_row196421223165820"><td class="cellrowborder" valign="top" width="16.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p176426239586"><a name="zh-cn_topic_0000001179090937_p176426239586"></a><a name="zh-cn_topic_0000001179090937_p176426239586"></a>storeId</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p11642192345813"><a name="zh-cn_topic_0000001179090937_p11642192345813"></a><a name="zh-cn_topic_0000001179090937_p11642192345813"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.29%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p22701218122217"><a name="zh-cn_topic_0000001179090937_p22701218122217"></a><a name="zh-cn_topic_0000001179090937_p22701218122217"></a>用于标识数据库。同一应用下该参数值必须唯一且长度应小于1KB。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001179090937_row1864252325813"><td class="cellrowborder" valign="top" width="16.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p1664342385817"><a name="zh-cn_topic_0000001179090937_p1664342385817"></a><a name="zh-cn_topic_0000001179090937_p1664342385817"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p46635302565"><a name="zh-cn_topic_0000001179090937_p46635302565"></a><a name="zh-cn_topic_0000001179090937_p46635302565"></a><a href="js-apis-data-type.md#zh-cn_topic_0000001129943828_section16417114202216">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="65.29%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p86431923185818"><a name="zh-cn_topic_0000001179090937_p86431923185818"></a><a name="zh-cn_topic_0000001179090937_p86431923185818"></a>数据库实例的配置信息。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001179090937_row91703271930"><td class="cellrowborder" valign="top" width="16.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001179090937_p9805195012318"><a name="zh-cn_topic_0000001179090937_p9805195012318"></a><a name="zh-cn_topic_0000001179090937_p9805195012318"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.42%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001179090937_p1180517508312"><a name="zh-cn_topic_0000001179090937_p1180517508312"></a><a name="zh-cn_topic_0000001179090937_p1180517508312"></a>AsyncCallback&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.29%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001179090937_p580516505314"><a name="zh-cn_topic_0000001179090937_p580516505314"></a><a name="zh-cn_topic_0000001179090937_p580516505314"></a>回调函数，获取数据库实例。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    kvManager.getKVStore('storeId', options, function(err, store){
    	kvStore = store;
    });
    ```


