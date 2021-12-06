# 单版本分布式数据库<a name="ZH-CN_TOPIC_0000001209252187"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001129947446_s56d19203690d4782bfc74069abb6bd71"></a>

```
import factory from '@ohos.data.distributeddata';
```

## 权限<a name="zh-cn_topic_0000001129947446_section11257113618419"></a>

无

## SingleKVStore<a name="zh-cn_topic_0000001129947446_section12882825611"></a>

单版本分布式数据库，继承自分布式数据库，支持查询、同步数据，也具备分布式数据库的所有的接口能力。需要先通过[getKVStore](js-apis-data-kvmanager.md#zh-cn_topic_0000001179090937_section51960467216)获取实例。

### get\(key: string, callback: AsyncCallback<Uint8Array | string | boolean | number\>\): void<a name="zh-cn_topic_0000001129947446_section2013623011386"></a>

获取指定键的值。

此方法为异步callback方法。

-   参数：

    <a name="zh-cn_topic_0000001129947446_table1913714301387"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001129947446_row20137730143813"><th class="cellrowborder" valign="top" width="19.541954195419542%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129947446_p14137153017383"><a name="zh-cn_topic_0000001129947446_p14137153017383"></a><a name="zh-cn_topic_0000001129947446_p14137153017383"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.14291429142914%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129947446_p11137113011389"><a name="zh-cn_topic_0000001129947446_p11137113011389"></a><a name="zh-cn_topic_0000001129947446_p11137113011389"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.315131513151314%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129947446_p9137143011385"><a name="zh-cn_topic_0000001129947446_p9137143011385"></a><a name="zh-cn_topic_0000001129947446_p9137143011385"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001129947446_row15137173014380"><td class="cellrowborder" valign="top" width="19.541954195419542%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129947446_p15137330173815"><a name="zh-cn_topic_0000001129947446_p15137330173815"></a><a name="zh-cn_topic_0000001129947446_p15137330173815"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.14291429142914%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129947446_p1713863017383"><a name="zh-cn_topic_0000001129947446_p1713863017383"></a><a name="zh-cn_topic_0000001129947446_p1713863017383"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.315131513151314%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129947446_p513843019386"><a name="zh-cn_topic_0000001129947446_p513843019386"></a><a name="zh-cn_topic_0000001129947446_p513843019386"></a>要查询数据的key。不能为空且长度不大于1KB</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001129947446_row111381630143817"><td class="cellrowborder" valign="top" width="19.541954195419542%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129947446_p51381130173814"><a name="zh-cn_topic_0000001129947446_p51381130173814"></a><a name="zh-cn_topic_0000001129947446_p51381130173814"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.14291429142914%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129947446_p1013823015387"><a name="zh-cn_topic_0000001129947446_p1013823015387"></a><a name="zh-cn_topic_0000001129947446_p1013823015387"></a>AsyncCallback&lt;Uint8Array | string | boolean | number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.315131513151314%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129947446_p813819305384"><a name="zh-cn_topic_0000001129947446_p813819305384"></a><a name="zh-cn_topic_0000001129947446_p813819305384"></a>回调函数，获取查询的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    kvStore.get('key-001', function(err, value){
        console.info(value);
    });
    ```


### get\(key: string\): Promise<Uint8Array | string | boolean | number\><a name="zh-cn_topic_0000001129947446_section5647141894316"></a>

获取指定键的值。

此方法为异步promise方法。

-   参数：

    <a name="zh-cn_topic_0000001129947446_table4647818164315"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001129947446_row16481918184315"><th class="cellrowborder" valign="top" width="19.541954195419542%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129947446_p186481918104313"><a name="zh-cn_topic_0000001129947446_p186481918104313"></a><a name="zh-cn_topic_0000001129947446_p186481918104313"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.14291429142914%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129947446_p264851804315"><a name="zh-cn_topic_0000001129947446_p264851804315"></a><a name="zh-cn_topic_0000001129947446_p264851804315"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.315131513151314%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129947446_p206486189432"><a name="zh-cn_topic_0000001129947446_p206486189432"></a><a name="zh-cn_topic_0000001129947446_p206486189432"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001129947446_row136493184436"><td class="cellrowborder" valign="top" width="19.541954195419542%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129947446_p164931854319"><a name="zh-cn_topic_0000001129947446_p164931854319"></a><a name="zh-cn_topic_0000001129947446_p164931854319"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.14291429142914%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129947446_p1064991854311"><a name="zh-cn_topic_0000001129947446_p1064991854311"></a><a name="zh-cn_topic_0000001129947446_p1064991854311"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.315131513151314%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129947446_p15650141834319"><a name="zh-cn_topic_0000001129947446_p15650141834319"></a><a name="zh-cn_topic_0000001129947446_p15650141834319"></a>要查询数据的key。不能为空且长度不大于1KB</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001129947446_table20650161884312"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001129947446_row11650121820433"><th class="cellrowborder" valign="top" width="39.94%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001129947446_p4650181884318"><a name="zh-cn_topic_0000001129947446_p4650181884318"></a><a name="zh-cn_topic_0000001129947446_p4650181884318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.06%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001129947446_p96501118194314"><a name="zh-cn_topic_0000001129947446_p96501118194314"></a><a name="zh-cn_topic_0000001129947446_p96501118194314"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001129947446_row2065071884319"><td class="cellrowborder" valign="top" width="39.94%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001129947446_p1065131812433"><a name="zh-cn_topic_0000001129947446_p1065131812433"></a><a name="zh-cn_topic_0000001129947446_p1065131812433"></a>Promise&lt;Uint8Array | string | boolean | number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.06%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001129947446_p2065191813435"><a name="zh-cn_topic_0000001129947446_p2065191813435"></a><a name="zh-cn_topic_0000001129947446_p2065191813435"></a>promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const promise = kvStore.get('key-001');
            promise.then((data) => {
               console.info(value);
            }).catch((err) => {
            });
    ```


### sync\(deviceIdList: string\[\], mode: SyncMode, allowedDelayMs?: number\): void<a name="zh-cn_topic_0000001129947446_section06419235582"></a>

在手动模式下，触发数据库同步。

此方法为同步方法。

-   参数：

    <a name="zh-cn_topic_0000001129947446_table16642172313584"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001129947446_row1064292310587"><th class="cellrowborder" valign="top" width="17.91%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001129947446_p9642172345810"><a name="zh-cn_topic_0000001129947446_p9642172345810"></a><a name="zh-cn_topic_0000001129947446_p9642172345810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.009999999999998%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001129947446_p1264242365813"><a name="zh-cn_topic_0000001129947446_p1264242365813"></a><a name="zh-cn_topic_0000001129947446_p1264242365813"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.169999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001129947446_p46421923185813"><a name="zh-cn_topic_0000001129947446_p46421923185813"></a><a name="zh-cn_topic_0000001129947446_p46421923185813"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.91%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001129947446_p16426231582"><a name="zh-cn_topic_0000001129947446_p16426231582"></a><a name="zh-cn_topic_0000001129947446_p16426231582"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001129947446_row196421223165820"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129947446_p176426239586"><a name="zh-cn_topic_0000001129947446_p176426239586"></a><a name="zh-cn_topic_0000001129947446_p176426239586"></a>deviceIdList</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129947446_p11642192345813"><a name="zh-cn_topic_0000001129947446_p11642192345813"></a><a name="zh-cn_topic_0000001129947446_p11642192345813"></a>string[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129947446_p196428238584"><a name="zh-cn_topic_0000001129947446_p196428238584"></a><a name="zh-cn_topic_0000001129947446_p196428238584"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.91%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129947446_p564282316586"><a name="zh-cn_topic_0000001129947446_p564282316586"></a><a name="zh-cn_topic_0000001129947446_p564282316586"></a>同一组网环境下，需要同步的设备networkid列表。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001129947446_row15290171774817"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129947446_p52919178483"><a name="zh-cn_topic_0000001129947446_p52919178483"></a><a name="zh-cn_topic_0000001129947446_p52919178483"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129947446_p0291617134819"><a name="zh-cn_topic_0000001129947446_p0291617134819"></a><a name="zh-cn_topic_0000001129947446_p0291617134819"></a><a href="js-apis-data-type.md#zh-cn_topic_0000001129943828_section53541759205119">SyncMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="24.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129947446_p1829171719482"><a name="zh-cn_topic_0000001129947446_p1829171719482"></a><a name="zh-cn_topic_0000001129947446_p1829171719482"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.91%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129947446_p219412514334"><a name="zh-cn_topic_0000001129947446_p219412514334"></a><a name="zh-cn_topic_0000001129947446_p219412514334"></a>同步类型。</p>
    <p id="zh-cn_topic_0000001129947446_p72914177486"><a name="zh-cn_topic_0000001129947446_p72914177486"></a><a name="zh-cn_topic_0000001129947446_p72914177486"></a>0：PUSH_ONLY, 1: PULL_ONLY, 2: PUSH_PULL</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001129947446_row7797191217527"><td class="cellrowborder" valign="top" width="17.91%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129947446_p11797512195211"><a name="zh-cn_topic_0000001129947446_p11797512195211"></a><a name="zh-cn_topic_0000001129947446_p11797512195211"></a>allowedDelayMs</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.009999999999998%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129947446_p15797181210529"><a name="zh-cn_topic_0000001129947446_p15797181210529"></a><a name="zh-cn_topic_0000001129947446_p15797181210529"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129947446_p10797712145215"><a name="zh-cn_topic_0000001129947446_p10797712145215"></a><a name="zh-cn_topic_0000001129947446_p10797712145215"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.91%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129947446_p20797912145218"><a name="zh-cn_topic_0000001129947446_p20797912145218"></a><a name="zh-cn_topic_0000001129947446_p20797912145218"></a>可选参数。允许延时时间，单位毫秒。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    无

-   示例：

    ```
    kvStore.sync(deviceIds, 1, 1000);
    ```


