# URL字符串解析<a name="ZH-CN_TOPIC_0000001164647878"></a>

-   [导入模块](#zh-cn_topic_0000001164966152_section2080512344162)
-   [权限](#zh-cn_topic_0000001164966152_section11257113618419)
-   [URLSearchParams](#zh-cn_topic_0000001164966152_section143808167355)
    -   [constructor](#zh-cn_topic_0000001164966152_section694710593283)
    -   [append](#zh-cn_topic_0000001164966152_section31006818349)
    -   [delete](#zh-cn_topic_0000001164966152_section25256353342)
    -   [getAll](#zh-cn_topic_0000001164966152_section2178125553415)
    -   [entries](#zh-cn_topic_0000001164966152_section139696402356)
    -   [forEach](#zh-cn_topic_0000001164966152_section299942113617)
    -   [get](#zh-cn_topic_0000001164966152_section1229318155373)
    -   [has](#zh-cn_topic_0000001164966152_section1385211103813)
    -   [set](#zh-cn_topic_0000001164966152_section186091516203910)
    -   [sort](#zh-cn_topic_0000001164966152_section102851552183915)
    -   [keys](#zh-cn_topic_0000001164966152_section816918183413)
    -   [values](#zh-cn_topic_0000001164966152_section0542174314413)
    -   [\[Symbol.iterator\]](#zh-cn_topic_0000001164966152_section1152151784210)
    -   [tostring](#zh-cn_topic_0000001164966152_section228585911428)

-   [URL](#zh-cn_topic_0000001164966152_section148871646203714)
    -   [属性](#zh-cn_topic_0000001164966152_section18482944113517)
    -   [constructor](#zh-cn_topic_0000001164966152_section712011584410)
    -   [tostring](#zh-cn_topic_0000001164966152_section2849448104520)
    -   [toJSON](#zh-cn_topic_0000001164966152_section3488111554611)


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001164966152_section2080512344162"></a>

```
import Url from '@ohos.url' 
```

## 权限<a name="zh-cn_topic_0000001164966152_section11257113618419"></a>

无

## URLSearchParams<a name="zh-cn_topic_0000001164966152_section143808167355"></a>

### constructor<a name="zh-cn_topic_0000001164966152_section694710593283"></a>

constructor\(init?: string\[\]\[\] | Record<string, string\> | string | URLSearchParams\)

URLSearchParams的构造函数。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table1540155452420"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1947713549244"><th class="cellrowborder" valign="top" width="12.959999999999999%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p74771754102410"><a name="zh-cn_topic_0000001164966152_p74771754102410"></a><a name="zh-cn_topic_0000001164966152_p74771754102410"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.06%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p1047755412411"><a name="zh-cn_topic_0000001164966152_p1047755412411"></a><a name="zh-cn_topic_0000001164966152_p1047755412411"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.569999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p34782054192412"><a name="zh-cn_topic_0000001164966152_p34782054192412"></a><a name="zh-cn_topic_0000001164966152_p34782054192412"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.41%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p12478954132419"><a name="zh-cn_topic_0000001164966152_p12478954132419"></a><a name="zh-cn_topic_0000001164966152_p12478954132419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row1247811541240"><td class="cellrowborder" valign="top" width="12.959999999999999%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p2089352474715"><a name="zh-cn_topic_0000001164966152_p2089352474715"></a><a name="zh-cn_topic_0000001164966152_p2089352474715"></a>init</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.06%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p81221923163816"><a name="zh-cn_topic_0000001164966152_p81221923163816"></a><a name="zh-cn_topic_0000001164966152_p81221923163816"></a>string[][] | Record&lt;string, string&gt; | string | URLSearchParams</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p1247885492411"><a name="zh-cn_topic_0000001164966152_p1247885492411"></a><a name="zh-cn_topic_0000001164966152_p1247885492411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.41%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p12478654172415"><a name="zh-cn_topic_0000001164966152_p12478654172415"></a><a name="zh-cn_topic_0000001164966152_p12478654172415"></a>入参对象。</p>
    <a name="zh-cn_topic_0000001164966152_ul11644162993910"></a><a name="zh-cn_topic_0000001164966152_ul11644162993910"></a><ul id="zh-cn_topic_0000001164966152_ul11644162993910"><li>string[][]：字符串二维数组</li><li>Record&lt;string, string&gt;：对象列表</li><li>string：字符串</li><li>URLSearchParams：对象</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var objectParams = new URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
    var objectParams1 = new URLSearchParams({"fod" : 1 , "bard" : 2});
    var objectParams2 = new URLSearchParams('?fod=1&bard=2');
    var urlObject = new URL('https://developer.mozilla.org/?fod=1&bard=2');
    var params = new URLSearchParams(urlObject .search);
    ```


### append<a name="zh-cn_topic_0000001164966152_section31006818349"></a>

append\(name: string, value: string\): void

将新的键值对插入到查询字符串。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p7966738914"><a name="zh-cn_topic_0000001164966152_p7966738914"></a><a name="zh-cn_topic_0000001164966152_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p296713699"><a name="zh-cn_topic_0000001164966152_p296713699"></a><a name="zh-cn_topic_0000001164966152_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p196718315911"><a name="zh-cn_topic_0000001164966152_p196718315911"></a><a name="zh-cn_topic_0000001164966152_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p9967231197"><a name="zh-cn_topic_0000001164966152_p9967231197"></a><a name="zh-cn_topic_0000001164966152_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p79671633910"><a name="zh-cn_topic_0000001164966152_p79671633910"></a><a name="zh-cn_topic_0000001164966152_p79671633910"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p11967433914"><a name="zh-cn_topic_0000001164966152_p11967433914"></a><a name="zh-cn_topic_0000001164966152_p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p19671336916"><a name="zh-cn_topic_0000001164966152_p19671336916"></a><a name="zh-cn_topic_0000001164966152_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p69671631796"><a name="zh-cn_topic_0000001164966152_p69671631796"></a><a name="zh-cn_topic_0000001164966152_p69671631796"></a>需要插入搜索参数的键名。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p39671131590"><a name="zh-cn_topic_0000001164966152_p39671131590"></a><a name="zh-cn_topic_0000001164966152_p39671131590"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p126051952172518"><a name="zh-cn_topic_0000001164966152_p126051952172518"></a><a name="zh-cn_topic_0000001164966152_p126051952172518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p149671932919"><a name="zh-cn_topic_0000001164966152_p149671932919"></a><a name="zh-cn_topic_0000001164966152_p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p19675312911"><a name="zh-cn_topic_0000001164966152_p19675312911"></a><a name="zh-cn_topic_0000001164966152_p19675312911"></a>需要插入搜索参数的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let urlObject = new URL('https://developer.exampleUrl/?fod=1&bard=2');
    let paramsObject = new URLSearchParams(urlObject.search.slice(1));
    paramsObject.append('fod', 3);
    ```


### delete<a name="zh-cn_topic_0000001164966152_section25256353342"></a>

delete\(name: string\): void

删除指定名称的键值对。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table06501420123810"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row7651202014381"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p465112013817"><a name="zh-cn_topic_0000001164966152_p465112013817"></a><a name="zh-cn_topic_0000001164966152_p465112013817"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p1651152053811"><a name="zh-cn_topic_0000001164966152_p1651152053811"></a><a name="zh-cn_topic_0000001164966152_p1651152053811"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p10651102018383"><a name="zh-cn_topic_0000001164966152_p10651102018383"></a><a name="zh-cn_topic_0000001164966152_p10651102018383"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p16511220143812"><a name="zh-cn_topic_0000001164966152_p16511220143812"></a><a name="zh-cn_topic_0000001164966152_p16511220143812"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row19651202063816"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p176511020113820"><a name="zh-cn_topic_0000001164966152_p176511020113820"></a><a name="zh-cn_topic_0000001164966152_p176511020113820"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p1865152043815"><a name="zh-cn_topic_0000001164966152_p1865152043815"></a><a name="zh-cn_topic_0000001164966152_p1865152043815"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p365292023811"><a name="zh-cn_topic_0000001164966152_p365292023811"></a><a name="zh-cn_topic_0000001164966152_p365292023811"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p4652192063817"><a name="zh-cn_topic_0000001164966152_p4652192063817"></a><a name="zh-cn_topic_0000001164966152_p4652192063817"></a>需要删除的键值名称。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    let urlObject = new URL('https://developer.exampleUrl/?fod=1&bard=2');
    let paramsobject = new URLSearchParams(urlObject.search.slice(1));
    paramsobject.delete('foo');
    ```


### getAll<a name="zh-cn_topic_0000001164966152_section2178125553415"></a>

getAll\(name: string\): string\[\]

获取指定名称的所有键值对。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table344935313917"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1344915383919"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p134498535393"><a name="zh-cn_topic_0000001164966152_p134498535393"></a><a name="zh-cn_topic_0000001164966152_p134498535393"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p445055343918"><a name="zh-cn_topic_0000001164966152_p445055343918"></a><a name="zh-cn_topic_0000001164966152_p445055343918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p17450153173914"><a name="zh-cn_topic_0000001164966152_p17450153173914"></a><a name="zh-cn_topic_0000001164966152_p17450153173914"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p1945045312399"><a name="zh-cn_topic_0000001164966152_p1945045312399"></a><a name="zh-cn_topic_0000001164966152_p1945045312399"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row184505536396"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p174501853103913"><a name="zh-cn_topic_0000001164966152_p174501853103913"></a><a name="zh-cn_topic_0000001164966152_p174501853103913"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p114501753123918"><a name="zh-cn_topic_0000001164966152_p114501753123918"></a><a name="zh-cn_topic_0000001164966152_p114501753123918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p1245015534394"><a name="zh-cn_topic_0000001164966152_p1245015534394"></a><a name="zh-cn_topic_0000001164966152_p1245015534394"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p44501153143910"><a name="zh-cn_topic_0000001164966152_p44501153143910"></a><a name="zh-cn_topic_0000001164966152_p44501153143910"></a>指定的键值名称。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="zh-cn_topic_0000001164966152_table37864874412"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1778638104418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p1778613834415"><a name="zh-cn_topic_0000001164966152_p1778613834415"></a><a name="zh-cn_topic_0000001164966152_p1778613834415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p6786118124414"><a name="zh-cn_topic_0000001164966152_p6786118124414"></a><a name="zh-cn_topic_0000001164966152_p6786118124414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row678611818445"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p83451276515"><a name="zh-cn_topic_0000001164966152_p83451276515"></a><a name="zh-cn_topic_0000001164966152_p83451276515"></a>string[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p6786118144419"><a name="zh-cn_topic_0000001164966152_p6786118144419"></a><a name="zh-cn_topic_0000001164966152_p6786118144419"></a>返回指定名称的所有键值对。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    let urlObject = new URL('https://developer.exampleUrl/?fod=1&bard=2'); 
    let paramsObject = new URLSearchParams(urlObject.search.slice(1)); 
    paramsObject.append('fod', 3); // Add a second value for the foo parameter.
    console.log(params.getAll('fod')) // Output ["1","3"].
    ```


### entries<a name="zh-cn_topic_0000001164966152_section139696402356"></a>

entries\(\): IterableIterator<\[string, string\]\>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table092116152217"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row792256172217"><th class="cellrowborder" valign="top" width="33.660000000000004%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p392286122211"><a name="zh-cn_topic_0000001164966152_p392286122211"></a><a name="zh-cn_topic_0000001164966152_p392286122211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.34%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p7922463223"><a name="zh-cn_topic_0000001164966152_p7922463223"></a><a name="zh-cn_topic_0000001164966152_p7922463223"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row189221612226"><td class="cellrowborder" valign="top" width="33.660000000000004%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p11940347163112"><a name="zh-cn_topic_0000001164966152_p11940347163112"></a><a name="zh-cn_topic_0000001164966152_p11940347163112"></a>IterableIterator&lt;[string, string]&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.34%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p310681516226"><a name="zh-cn_topic_0000001164966152_p310681516226"></a><a name="zh-cn_topic_0000001164966152_p310681516226"></a>返回一个ES6的迭代器。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var searchParamsObject = new URLSearchParams("keyName1=valueName1&keyName2=valueName2"); 
    for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
        console.log(pair[0]+ ', '+ pair[1]);
    }
    ```


### forEach<a name="zh-cn_topic_0000001164966152_section299942113617"></a>

forEach\(callbackfn: \(value: string, key: string, parent: this\) =\> void\): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table127915306330"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1727910302334"><th class="cellrowborder" valign="top" width="16.43%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p1237183514330"><a name="zh-cn_topic_0000001164966152_p1237183514330"></a><a name="zh-cn_topic_0000001164966152_p1237183514330"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.2%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p73716356332"><a name="zh-cn_topic_0000001164966152_p73716356332"></a><a name="zh-cn_topic_0000001164966152_p73716356332"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.14%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p203711435133319"><a name="zh-cn_topic_0000001164966152_p203711435133319"></a><a name="zh-cn_topic_0000001164966152_p203711435133319"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p2037111353332"><a name="zh-cn_topic_0000001164966152_p2037111353332"></a><a name="zh-cn_topic_0000001164966152_p2037111353332"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row1728073073310"><td class="cellrowborder" valign="top" width="16.43%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p1728014306336"><a name="zh-cn_topic_0000001164966152_p1728014306336"></a><a name="zh-cn_topic_0000001164966152_p1728014306336"></a>callbackfn</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.2%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p1928014303336"><a name="zh-cn_topic_0000001164966152_p1928014303336"></a><a name="zh-cn_topic_0000001164966152_p1928014303336"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p82801930193317"><a name="zh-cn_topic_0000001164966152_p82801930193317"></a><a name="zh-cn_topic_0000001164966152_p82801930193317"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p2280133023319"><a name="zh-cn_topic_0000001164966152_p2280133023319"></a><a name="zh-cn_topic_0000001164966152_p2280133023319"></a>回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  callbackfn的参数说明

    <a name="zh-cn_topic_0000001164966152_table11630163925517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row18630183913556"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001164966152_p6630939115517"><a name="zh-cn_topic_0000001164966152_p6630939115517"></a><a name="zh-cn_topic_0000001164966152_p6630939115517"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.8%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001164966152_p156301439145520"><a name="zh-cn_topic_0000001164966152_p156301439145520"></a><a name="zh-cn_topic_0000001164966152_p156301439145520"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.520000000000001%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001164966152_p166319395559"><a name="zh-cn_topic_0000001164966152_p166319395559"></a><a name="zh-cn_topic_0000001164966152_p166319395559"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.220000000000006%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001164966152_p206311039115511"><a name="zh-cn_topic_0000001164966152_p206311039115511"></a><a name="zh-cn_topic_0000001164966152_p206311039115511"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row963193918557"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164966152_p16631163925512"><a name="zh-cn_topic_0000001164966152_p16631163925512"></a><a name="zh-cn_topic_0000001164966152_p16631163925512"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164966152_p10631113915550"><a name="zh-cn_topic_0000001164966152_p10631113915550"></a><a name="zh-cn_topic_0000001164966152_p10631113915550"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164966152_p36311239105519"><a name="zh-cn_topic_0000001164966152_p36311239105519"></a><a name="zh-cn_topic_0000001164966152_p36311239105519"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164966152_p17767351572"><a name="zh-cn_topic_0000001164966152_p17767351572"></a><a name="zh-cn_topic_0000001164966152_p17767351572"></a>当前遍历到的键值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row1463119397553"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164966152_p19631103985517"><a name="zh-cn_topic_0000001164966152_p19631103985517"></a><a name="zh-cn_topic_0000001164966152_p19631103985517"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164966152_p7631113965516"><a name="zh-cn_topic_0000001164966152_p7631113965516"></a><a name="zh-cn_topic_0000001164966152_p7631113965516"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164966152_p2631203918552"><a name="zh-cn_topic_0000001164966152_p2631203918552"></a><a name="zh-cn_topic_0000001164966152_p2631203918552"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164966152_p186310399556"><a name="zh-cn_topic_0000001164966152_p186310399556"></a><a name="zh-cn_topic_0000001164966152_p186310399556"></a>当前遍历到的键名。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row19539259115610"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164966152_p980433316187"><a name="zh-cn_topic_0000001164966152_p980433316187"></a><a name="zh-cn_topic_0000001164966152_p980433316187"></a>searchParams</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164966152_p1453910594565"><a name="zh-cn_topic_0000001164966152_p1453910594565"></a><a name="zh-cn_topic_0000001164966152_p1453910594565"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164966152_p35412590563"><a name="zh-cn_topic_0000001164966152_p35412590563"></a><a name="zh-cn_topic_0000001164966152_p35412590563"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164966152_p1323294318182"><a name="zh-cn_topic_0000001164966152_p1323294318182"></a><a name="zh-cn_topic_0000001164966152_p1323294318182"></a>当前调用forEach方法的实例对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const myURLObject = new URL('https://developer.exampleUrl/?fod=1&bard=2'); 
    myURLObject.searchParams.forEach((value, name, searchParams) => {  
        console.log(name, value, myURLObject.searchParams === searchParams);
    });
    ```


### get<a name="zh-cn_topic_0000001164966152_section1229318155373"></a>

get\(name: string\): string | null

获取指定名称对应的第一个值。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table377217542586"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1877275419580"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p277225412589"><a name="zh-cn_topic_0000001164966152_p277225412589"></a><a name="zh-cn_topic_0000001164966152_p277225412589"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p10772175495820"><a name="zh-cn_topic_0000001164966152_p10772175495820"></a><a name="zh-cn_topic_0000001164966152_p10772175495820"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p277265412588"><a name="zh-cn_topic_0000001164966152_p277265412588"></a><a name="zh-cn_topic_0000001164966152_p277265412588"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p77731254105819"><a name="zh-cn_topic_0000001164966152_p77731254105819"></a><a name="zh-cn_topic_0000001164966152_p77731254105819"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row4773854175820"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p137734549583"><a name="zh-cn_topic_0000001164966152_p137734549583"></a><a name="zh-cn_topic_0000001164966152_p137734549583"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p107730545586"><a name="zh-cn_topic_0000001164966152_p107730545586"></a><a name="zh-cn_topic_0000001164966152_p107730545586"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p277355418585"><a name="zh-cn_topic_0000001164966152_p277355418585"></a><a name="zh-cn_topic_0000001164966152_p277355418585"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p877335412588"><a name="zh-cn_topic_0000001164966152_p877335412588"></a><a name="zh-cn_topic_0000001164966152_p877335412588"></a>指定键值对的名称。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table18354510245"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row133612552415"><th class="cellrowborder" valign="top" width="20.96%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p8369592415"><a name="zh-cn_topic_0000001164966152_p8369592415"></a><a name="zh-cn_topic_0000001164966152_p8369592415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.03999999999999%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p1363514249"><a name="zh-cn_topic_0000001164966152_p1363514249"></a><a name="zh-cn_topic_0000001164966152_p1363514249"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row43614517248"><td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p193611582417"><a name="zh-cn_topic_0000001164966152_p193611582417"></a><a name="zh-cn_topic_0000001164966152_p193611582417"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.03999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p136452242"><a name="zh-cn_topic_0000001164966152_p136452242"></a><a name="zh-cn_topic_0000001164966152_p136452242"></a>返回第一个值。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row1190673810242"><td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p11907163819242"><a name="zh-cn_topic_0000001164966152_p11907163819242"></a><a name="zh-cn_topic_0000001164966152_p11907163819242"></a>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.03999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p7907183802419"><a name="zh-cn_topic_0000001164966152_p7907183802419"></a><a name="zh-cn_topic_0000001164966152_p7907183802419"></a>如果没找到，返回 null。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var paramsOject = new URLSearchParams(document.location.search.substring(1)); 
    var name = paramsOject.get("name"); // is the string "Jonathan" 
    var age = parseInt(paramsOject.get("age"), 10); // is the number 18
    var address = paramsOject.get("address"); // null
    ```


### has<a name="zh-cn_topic_0000001164966152_section1385211103813"></a>

has\(name: string\): boolean

判断一个指定的键名对应的值是否存在。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table746711171833"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row174684171316"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p154681517736"><a name="zh-cn_topic_0000001164966152_p154681517736"></a><a name="zh-cn_topic_0000001164966152_p154681517736"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p24684172312"><a name="zh-cn_topic_0000001164966152_p24684172312"></a><a name="zh-cn_topic_0000001164966152_p24684172312"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p94681817736"><a name="zh-cn_topic_0000001164966152_p94681817736"></a><a name="zh-cn_topic_0000001164966152_p94681817736"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p646817171331"><a name="zh-cn_topic_0000001164966152_p646817171331"></a><a name="zh-cn_topic_0000001164966152_p646817171331"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row134681171135"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p64692017333"><a name="zh-cn_topic_0000001164966152_p64692017333"></a><a name="zh-cn_topic_0000001164966152_p64692017333"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p1946910174320"><a name="zh-cn_topic_0000001164966152_p1946910174320"></a><a name="zh-cn_topic_0000001164966152_p1946910174320"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p10469717231"><a name="zh-cn_topic_0000001164966152_p10469717231"></a><a name="zh-cn_topic_0000001164966152_p10469717231"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p24691217436"><a name="zh-cn_topic_0000001164966152_p24691217436"></a><a name="zh-cn_topic_0000001164966152_p24691217436"></a>要查找的参数的键名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table156691044124411"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row6670164444419"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p10670114414449"><a name="zh-cn_topic_0000001164966152_p10670114414449"></a><a name="zh-cn_topic_0000001164966152_p10670114414449"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p3670144424418"><a name="zh-cn_topic_0000001164966152_p3670144424418"></a><a name="zh-cn_topic_0000001164966152_p3670144424418"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row13670184418448"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p1667064474420"><a name="zh-cn_topic_0000001164966152_p1667064474420"></a><a name="zh-cn_topic_0000001164966152_p1667064474420"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p5592172072510"><a name="zh-cn_topic_0000001164966152_p5592172072510"></a><a name="zh-cn_topic_0000001164966152_p5592172072510"></a>是否存在相对应的key值，存在返回true，否则返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let urlObject = new URL('https://developer.exampleUrl/?fod=1&bard=2');
    let paramsObject = new URLSearchParams(urlObject.search.slice(1)); 
    paramsObject.has('bard') === true;
    ```


### set<a name="zh-cn_topic_0000001164966152_section186091516203910"></a>

set\(name: string, value: string\): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table1653110211471"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row7531721778"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p75312021371"><a name="zh-cn_topic_0000001164966152_p75312021371"></a><a name="zh-cn_topic_0000001164966152_p75312021371"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p105313219716"><a name="zh-cn_topic_0000001164966152_p105313219716"></a><a name="zh-cn_topic_0000001164966152_p105313219716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p1553216216717"><a name="zh-cn_topic_0000001164966152_p1553216216717"></a><a name="zh-cn_topic_0000001164966152_p1553216216717"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p13532102114716"><a name="zh-cn_topic_0000001164966152_p13532102114716"></a><a name="zh-cn_topic_0000001164966152_p13532102114716"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row185321921572"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p10532172118711"><a name="zh-cn_topic_0000001164966152_p10532172118711"></a><a name="zh-cn_topic_0000001164966152_p10532172118711"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p10532152114718"><a name="zh-cn_topic_0000001164966152_p10532152114718"></a><a name="zh-cn_topic_0000001164966152_p10532152114718"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p1453220215713"><a name="zh-cn_topic_0000001164966152_p1453220215713"></a><a name="zh-cn_topic_0000001164966152_p1453220215713"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p053215214717"><a name="zh-cn_topic_0000001164966152_p053215214717"></a><a name="zh-cn_topic_0000001164966152_p053215214717"></a>将要设置的参数的键值名。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row18550750182"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p655013501184"><a name="zh-cn_topic_0000001164966152_p655013501184"></a><a name="zh-cn_topic_0000001164966152_p655013501184"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p196231541790"><a name="zh-cn_topic_0000001164966152_p196231541790"></a><a name="zh-cn_topic_0000001164966152_p196231541790"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p355120502810"><a name="zh-cn_topic_0000001164966152_p355120502810"></a><a name="zh-cn_topic_0000001164966152_p355120502810"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p145514507816"><a name="zh-cn_topic_0000001164966152_p145514507816"></a><a name="zh-cn_topic_0000001164966152_p145514507816"></a>所要设置的参数值。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    let urlObject = new URL('https://developer.exampleUrl/?fod=1&bard=2');
    let paramsObject = new URLSearchParams(urlObject.search.slice(1));
    paramsObject.set('baz', 3); // Add a third parameter.
    ```


### sort<a name="zh-cn_topic_0000001164966152_section102851552183915"></a>

sort\(\): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

-   示例：

    ```
    var searchParamsObject = new URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
    searchParamsObject.sort(); // Sort the key/value pairs
    console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
    ```


### keys<a name="zh-cn_topic_0000001164966152_section816918183413"></a>

keys\(\): IterableIterator<string\>

返回一个所有键值对的name的ES6迭代器。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table15822151784820"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row38222172484"><th class="cellrowborder" valign="top" width="32.550000000000004%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p158225175483"><a name="zh-cn_topic_0000001164966152_p158225175483"></a><a name="zh-cn_topic_0000001164966152_p158225175483"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.45%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p3822131718485"><a name="zh-cn_topic_0000001164966152_p3822131718485"></a><a name="zh-cn_topic_0000001164966152_p3822131718485"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row58231817124817"><td class="cellrowborder" valign="top" width="32.550000000000004%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p118232017164813"><a name="zh-cn_topic_0000001164966152_p118232017164813"></a><a name="zh-cn_topic_0000001164966152_p118232017164813"></a>IterableIterator&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.45%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p1128142484911"><a name="zh-cn_topic_0000001164966152_p1128142484911"></a><a name="zh-cn_topic_0000001164966152_p1128142484911"></a>返回一个所有键值对的name的ES6迭代器。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var searchParamsObject = new URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
    for (var key of searchParamsObject .keys()) { // Output key-value pairs
        console.log(key);
    }
    ```


### values<a name="zh-cn_topic_0000001164966152_section0542174314413"></a>

values\(\): IterableIterator<string\>

返回一个所有键值对的value的ES6迭代器。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table44901259134916"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row44901859124916"><th class="cellrowborder" valign="top" width="36.51%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p19491175912499"><a name="zh-cn_topic_0000001164966152_p19491175912499"></a><a name="zh-cn_topic_0000001164966152_p19491175912499"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.49%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p1491145934914"><a name="zh-cn_topic_0000001164966152_p1491145934914"></a><a name="zh-cn_topic_0000001164966152_p1491145934914"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row6491125914919"><td class="cellrowborder" valign="top" width="36.51%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p13812011488"><a name="zh-cn_topic_0000001164966152_p13812011488"></a><a name="zh-cn_topic_0000001164966152_p13812011488"></a>IterableIterator&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.49%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p38375645210"><a name="zh-cn_topic_0000001164966152_p38375645210"></a><a name="zh-cn_topic_0000001164966152_p38375645210"></a>返回一个所有键值对的value的ES6迭代器。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例

    ```
    var searchParams = new URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
    for (var value of searchParams.values()) { 
        console.log(value);
    }
    ```


### \[Symbol.iterator\]<a name="zh-cn_topic_0000001164966152_section1152151784210"></a>

\[Symbol.iterator\]\(\): IterableIterator<\[string, string\]\>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table8247125417537"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1424715435311"><th class="cellrowborder" valign="top" width="38.99%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p17247125419532"><a name="zh-cn_topic_0000001164966152_p17247125419532"></a><a name="zh-cn_topic_0000001164966152_p17247125419532"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p424795415313"><a name="zh-cn_topic_0000001164966152_p424795415313"></a><a name="zh-cn_topic_0000001164966152_p424795415313"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row72471054115317"><td class="cellrowborder" valign="top" width="38.99%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p8576493492"><a name="zh-cn_topic_0000001164966152_p8576493492"></a><a name="zh-cn_topic_0000001164966152_p8576493492"></a>IterableIterator&lt;[string, string]&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p16248185414532"><a name="zh-cn_topic_0000001164966152_p16248185414532"></a><a name="zh-cn_topic_0000001164966152_p16248185414532"></a>返回一个ES6的迭代器。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    const paramsObject = new URLSearchParams('fod=bay&edg=bap');
    for (const [name, value] of paramsObject) { 
        console.log(name, value); 
    } 
    ```


### tostring<a name="zh-cn_topic_0000001164966152_section228585911428"></a>

toString\(\): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table016316018566"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row171632010566"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p71631308563"><a name="zh-cn_topic_0000001164966152_p71631308563"></a><a name="zh-cn_topic_0000001164966152_p71631308563"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p2164120205610"><a name="zh-cn_topic_0000001164966152_p2164120205610"></a><a name="zh-cn_topic_0000001164966152_p2164120205610"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row14164110145610"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p1516413016565"><a name="zh-cn_topic_0000001164966152_p1516413016565"></a><a name="zh-cn_topic_0000001164966152_p1516413016565"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p516412017563"><a name="zh-cn_topic_0000001164966152_p516412017563"></a><a name="zh-cn_topic_0000001164966152_p516412017563"></a>返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    let url = new URL('https://developer.exampleUrl/?fod=1&bard=2');
    let params = new URLSearchParams(url.search.slice(1)); 
    params.append('fod', 3);
    console.log(params.toString());
    ```


## URL<a name="zh-cn_topic_0000001164966152_section148871646203714"></a>

### 属性<a name="zh-cn_topic_0000001164966152_section18482944113517"></a>

<a name="zh-cn_topic_0000001164966152_table20482104463514"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row1348214444357"><th class="cellrowborder" valign="top" width="11.84%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001164966152_p184822443351"><a name="zh-cn_topic_0000001164966152_p184822443351"></a><a name="zh-cn_topic_0000001164966152_p184822443351"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.75%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001164966152_p1648254415353"><a name="zh-cn_topic_0000001164966152_p1648254415353"></a><a name="zh-cn_topic_0000001164966152_p1648254415353"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="5.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001164966152_p9482124413355"><a name="zh-cn_topic_0000001164966152_p9482124413355"></a><a name="zh-cn_topic_0000001164966152_p9482124413355"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.65%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001164966152_p3482124493515"><a name="zh-cn_topic_0000001164966152_p3482124493515"></a><a name="zh-cn_topic_0000001164966152_p3482124493515"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001164966152_p12482104483513"><a name="zh-cn_topic_0000001164966152_p12482104483513"></a><a name="zh-cn_topic_0000001164966152_p12482104483513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164966152_row148254473513"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p1832319183511"><a name="zh-cn_topic_0000001164966152_p1832319183511"></a><a name="zh-cn_topic_0000001164966152_p1832319183511"></a>hash</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p3482124417356"><a name="zh-cn_topic_0000001164966152_p3482124417356"></a><a name="zh-cn_topic_0000001164966152_p3482124417356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p16483194443514"><a name="zh-cn_topic_0000001164966152_p16483194443514"></a><a name="zh-cn_topic_0000001164966152_p16483194443514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p630714163422"><a name="zh-cn_topic_0000001164966152_p630714163422"></a><a name="zh-cn_topic_0000001164966152_p630714163422"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p72131224114411"><a name="zh-cn_topic_0000001164966152_p72131224114411"></a><a name="zh-cn_topic_0000001164966152_p72131224114411"></a>获取和设置URL的片段部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row58631729183511"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p1669917383355"><a name="zh-cn_topic_0000001164966152_p1669917383355"></a><a name="zh-cn_topic_0000001164966152_p1669917383355"></a>host</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p986510296359"><a name="zh-cn_topic_0000001164966152_p986510296359"></a><a name="zh-cn_topic_0000001164966152_p986510296359"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p14865182993518"><a name="zh-cn_topic_0000001164966152_p14865182993518"></a><a name="zh-cn_topic_0000001164966152_p14865182993518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1586552915355"><a name="zh-cn_topic_0000001164966152_p1586552915355"></a><a name="zh-cn_topic_0000001164966152_p1586552915355"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p12865829133514"><a name="zh-cn_topic_0000001164966152_p12865829133514"></a><a name="zh-cn_topic_0000001164966152_p12865829133514"></a>获取和设置URL的主机部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row173737374371"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p73744376373"><a name="zh-cn_topic_0000001164966152_p73744376373"></a><a name="zh-cn_topic_0000001164966152_p73744376373"></a>hostname</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p183741337173714"><a name="zh-cn_topic_0000001164966152_p183741337173714"></a><a name="zh-cn_topic_0000001164966152_p183741337173714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p13374237173711"><a name="zh-cn_topic_0000001164966152_p13374237173711"></a><a name="zh-cn_topic_0000001164966152_p13374237173711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1737416372376"><a name="zh-cn_topic_0000001164966152_p1737416372376"></a><a name="zh-cn_topic_0000001164966152_p1737416372376"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p737414373372"><a name="zh-cn_topic_0000001164966152_p737414373372"></a><a name="zh-cn_topic_0000001164966152_p737414373372"></a>获取和设置URL的主机名部分，不带端口。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row18603545143715"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p1360410454373"><a name="zh-cn_topic_0000001164966152_p1360410454373"></a><a name="zh-cn_topic_0000001164966152_p1360410454373"></a>href</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p1260410456378"><a name="zh-cn_topic_0000001164966152_p1260410456378"></a><a name="zh-cn_topic_0000001164966152_p1260410456378"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p146042453371"><a name="zh-cn_topic_0000001164966152_p146042453371"></a><a name="zh-cn_topic_0000001164966152_p146042453371"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p460416456374"><a name="zh-cn_topic_0000001164966152_p460416456374"></a><a name="zh-cn_topic_0000001164966152_p460416456374"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p1560554514376"><a name="zh-cn_topic_0000001164966152_p1560554514376"></a><a name="zh-cn_topic_0000001164966152_p1560554514376"></a>获取和设置序列化的URL。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row15118124793712"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p9121914204110"><a name="zh-cn_topic_0000001164966152_p9121914204110"></a><a name="zh-cn_topic_0000001164966152_p9121914204110"></a>origin</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p41181471376"><a name="zh-cn_topic_0000001164966152_p41181471376"></a><a name="zh-cn_topic_0000001164966152_p41181471376"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p10118447153719"><a name="zh-cn_topic_0000001164966152_p10118447153719"></a><a name="zh-cn_topic_0000001164966152_p10118447153719"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1111884793714"><a name="zh-cn_topic_0000001164966152_p1111884793714"></a><a name="zh-cn_topic_0000001164966152_p1111884793714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p11181479377"><a name="zh-cn_topic_0000001164966152_p11181479377"></a><a name="zh-cn_topic_0000001164966152_p11181479377"></a>获取URL源的只读序列化。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row2998164312378"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p20998643103713"><a name="zh-cn_topic_0000001164966152_p20998643103713"></a><a name="zh-cn_topic_0000001164966152_p20998643103713"></a>password</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p1899804315372"><a name="zh-cn_topic_0000001164966152_p1899804315372"></a><a name="zh-cn_topic_0000001164966152_p1899804315372"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p1399820431377"><a name="zh-cn_topic_0000001164966152_p1399820431377"></a><a name="zh-cn_topic_0000001164966152_p1399820431377"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p29980434371"><a name="zh-cn_topic_0000001164966152_p29980434371"></a><a name="zh-cn_topic_0000001164966152_p29980434371"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p1299814373714"><a name="zh-cn_topic_0000001164966152_p1299814373714"></a><a name="zh-cn_topic_0000001164966152_p1299814373714"></a>获取和设置URL的密码部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row6527542193711"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p1852784212370"><a name="zh-cn_topic_0000001164966152_p1852784212370"></a><a name="zh-cn_topic_0000001164966152_p1852784212370"></a>pathname</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p205271742183711"><a name="zh-cn_topic_0000001164966152_p205271742183711"></a><a name="zh-cn_topic_0000001164966152_p205271742183711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p952724233717"><a name="zh-cn_topic_0000001164966152_p952724233717"></a><a name="zh-cn_topic_0000001164966152_p952724233717"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1452784214373"><a name="zh-cn_topic_0000001164966152_p1452784214373"></a><a name="zh-cn_topic_0000001164966152_p1452784214373"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p18527842143718"><a name="zh-cn_topic_0000001164966152_p18527842143718"></a><a name="zh-cn_topic_0000001164966152_p18527842143718"></a>获取和设置URL的路径部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row1221604019378"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p12161040193711"><a name="zh-cn_topic_0000001164966152_p12161040193711"></a><a name="zh-cn_topic_0000001164966152_p12161040193711"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p12161040103714"><a name="zh-cn_topic_0000001164966152_p12161040103714"></a><a name="zh-cn_topic_0000001164966152_p12161040103714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p621674073715"><a name="zh-cn_topic_0000001164966152_p621674073715"></a><a name="zh-cn_topic_0000001164966152_p621674073715"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1821624033711"><a name="zh-cn_topic_0000001164966152_p1821624033711"></a><a name="zh-cn_topic_0000001164966152_p1821624033711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p1421614403377"><a name="zh-cn_topic_0000001164966152_p1421614403377"></a><a name="zh-cn_topic_0000001164966152_p1421614403377"></a>获取和设置URL的端口部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row763211357376"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p1863313520378"><a name="zh-cn_topic_0000001164966152_p1863313520378"></a><a name="zh-cn_topic_0000001164966152_p1863313520378"></a>protocol</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p8633113583715"><a name="zh-cn_topic_0000001164966152_p8633113583715"></a><a name="zh-cn_topic_0000001164966152_p8633113583715"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p1663363533710"><a name="zh-cn_topic_0000001164966152_p1663363533710"></a><a name="zh-cn_topic_0000001164966152_p1663363533710"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1763312358374"><a name="zh-cn_topic_0000001164966152_p1763312358374"></a><a name="zh-cn_topic_0000001164966152_p1763312358374"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p363383518374"><a name="zh-cn_topic_0000001164966152_p363383518374"></a><a name="zh-cn_topic_0000001164966152_p363383518374"></a>获取和设置URL的协议部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row252344113516"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p852414113510"><a name="zh-cn_topic_0000001164966152_p852414113510"></a><a name="zh-cn_topic_0000001164966152_p852414113510"></a>search</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p115241141203517"><a name="zh-cn_topic_0000001164966152_p115241141203517"></a><a name="zh-cn_topic_0000001164966152_p115241141203517"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p3524134183519"><a name="zh-cn_topic_0000001164966152_p3524134183519"></a><a name="zh-cn_topic_0000001164966152_p3524134183519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p752464173511"><a name="zh-cn_topic_0000001164966152_p752464173511"></a><a name="zh-cn_topic_0000001164966152_p752464173511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p12524144111358"><a name="zh-cn_topic_0000001164966152_p12524144111358"></a><a name="zh-cn_topic_0000001164966152_p12524144111358"></a>获取和设置URL的序列化查询部分。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row1483164414352"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p0747823153511"><a name="zh-cn_topic_0000001164966152_p0747823153511"></a><a name="zh-cn_topic_0000001164966152_p0747823153511"></a>searchParams</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p133371031194316"><a name="zh-cn_topic_0000001164966152_p133371031194316"></a><a name="zh-cn_topic_0000001164966152_p133371031194316"></a>URLsearchParams</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p1348384415359"><a name="zh-cn_topic_0000001164966152_p1348384415359"></a><a name="zh-cn_topic_0000001164966152_p1348384415359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p1448312449355"><a name="zh-cn_topic_0000001164966152_p1448312449355"></a><a name="zh-cn_topic_0000001164966152_p1448312449355"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p8483124473515"><a name="zh-cn_topic_0000001164966152_p8483124473515"></a><a name="zh-cn_topic_0000001164966152_p8483124473515"></a>获取URLSearchParams表示URL查询参数的对象。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164966152_row13483164419353"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164966152_p4483154463514"><a name="zh-cn_topic_0000001164966152_p4483154463514"></a><a name="zh-cn_topic_0000001164966152_p4483154463514"></a>username</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164966152_p1887911084315"><a name="zh-cn_topic_0000001164966152_p1887911084315"></a><a name="zh-cn_topic_0000001164966152_p1887911084315"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164966152_p1483134419353"><a name="zh-cn_topic_0000001164966152_p1483134419353"></a><a name="zh-cn_topic_0000001164966152_p1483134419353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164966152_p648354483510"><a name="zh-cn_topic_0000001164966152_p648354483510"></a><a name="zh-cn_topic_0000001164966152_p648354483510"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164966152_p348319442351"><a name="zh-cn_topic_0000001164966152_p348319442351"></a><a name="zh-cn_topic_0000001164966152_p348319442351"></a>获取和设置URL的用户名部分。</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="zh-cn_topic_0000001164966152_section712011584410"></a>

constructor\(url: string, base?: string | URL\)

URL的构造函数。

-   参数：

    <a name="zh-cn_topic_0000001164966152_table1723015271384"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row42301327153814"><th class="cellrowborder" valign="top" width="17.5%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164966152_p102307272383"><a name="zh-cn_topic_0000001164966152_p102307272383"></a><a name="zh-cn_topic_0000001164966152_p102307272383"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.139999999999997%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164966152_p202307278382"><a name="zh-cn_topic_0000001164966152_p202307278382"></a><a name="zh-cn_topic_0000001164966152_p202307278382"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.81%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164966152_p1123113278381"><a name="zh-cn_topic_0000001164966152_p1123113278381"></a><a name="zh-cn_topic_0000001164966152_p1123113278381"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.55%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164966152_p5231172773815"><a name="zh-cn_topic_0000001164966152_p5231172773815"></a><a name="zh-cn_topic_0000001164966152_p5231172773815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row122318279387"><td class="cellrowborder" valign="top" width="17.5%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p161271253807"><a name="zh-cn_topic_0000001164966152_p161271253807"></a><a name="zh-cn_topic_0000001164966152_p161271253807"></a>url</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.139999999999997%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p11231102719382"><a name="zh-cn_topic_0000001164966152_p11231102719382"></a><a name="zh-cn_topic_0000001164966152_p11231102719382"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.81%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p1023152712389"><a name="zh-cn_topic_0000001164966152_p1023152712389"></a><a name="zh-cn_topic_0000001164966152_p1023152712389"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.55%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p323132783819"><a name="zh-cn_topic_0000001164966152_p323132783819"></a><a name="zh-cn_topic_0000001164966152_p323132783819"></a>入参对象。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164966152_row189010267539"><td class="cellrowborder" valign="top" width="17.5%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164966152_p1990210261536"><a name="zh-cn_topic_0000001164966152_p1990210261536"></a><a name="zh-cn_topic_0000001164966152_p1990210261536"></a>base</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.139999999999997%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164966152_p159024261532"><a name="zh-cn_topic_0000001164966152_p159024261532"></a><a name="zh-cn_topic_0000001164966152_p159024261532"></a>string | URL</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.81%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164966152_p10902426145317"><a name="zh-cn_topic_0000001164966152_p10902426145317"></a><a name="zh-cn_topic_0000001164966152_p10902426145317"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.55%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164966152_p16902126135313"><a name="zh-cn_topic_0000001164966152_p16902126135313"></a><a name="zh-cn_topic_0000001164966152_p16902126135313"></a>入参字符串或者对象。</p>
    <a name="zh-cn_topic_0000001164966152_ul1755124022517"></a><a name="zh-cn_topic_0000001164966152_ul1755124022517"></a><ul id="zh-cn_topic_0000001164966152_ul1755124022517"><li>string：字符串</li><li>URL：字符串或对象</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    var mm = 'http://username:password@host:8080';
    var a = new URL("/", mm); // Output 'http://username:password@host:8080/';
    var b = new URL(mm); // Output 'http://username:password@host:8080/';
    new URL('path/path1', b); // Output 'http://username:password@host:8080/path/path1';
    var c = new URL('/path/path1', b);  // Output 'http://username:password@host:8080/path/path1'; 
    new URL('/path/path1', c); // Output 'http://username:password@host:8080/path/path1';
    new URL('/path/path1', a); // Output 'http://username:password@host:8080/path/path1';
    new URL('/path/path1', "https://www.exampleUrl/fr-FR/toto"); // Output https://www.exampleUrl/path/path1
    new URL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
    new URL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
    new URL('http://www.shanxi.com', ); // Output http://www.shanxi.com/
    new URL('http://www.shanxi.com', b); // Output http://www.shanxi.com/
    ```


### tostring<a name="zh-cn_topic_0000001164966152_section2849448104520"></a>

toString\(\): string

将解析过后的URL转化为字符串。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table201041412244"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row410431122411"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p110413182418"><a name="zh-cn_topic_0000001164966152_p110413182418"></a><a name="zh-cn_topic_0000001164966152_p110413182418"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p181042116249"><a name="zh-cn_topic_0000001164966152_p181042116249"></a><a name="zh-cn_topic_0000001164966152_p181042116249"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row110421182413"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p510461102411"><a name="zh-cn_topic_0000001164966152_p510461102411"></a><a name="zh-cn_topic_0000001164966152_p510461102411"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p159992542327"><a name="zh-cn_topic_0000001164966152_p159992542327"></a><a name="zh-cn_topic_0000001164966152_p159992542327"></a>用于返回网址的字符串序列化。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    const url = new URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    url.toString()
    ```


### toJSON<a name="zh-cn_topic_0000001164966152_section3488111554611"></a>

toJSON\(\): string

将解析过后的URL转化为JSON字符串。

-   返回值：

    <a name="zh-cn_topic_0000001164966152_table981932613263"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164966152_row38194264264"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164966152_p178208263269"><a name="zh-cn_topic_0000001164966152_p178208263269"></a><a name="zh-cn_topic_0000001164966152_p178208263269"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164966152_p15820112672617"><a name="zh-cn_topic_0000001164966152_p15820112672617"></a><a name="zh-cn_topic_0000001164966152_p15820112672617"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164966152_row2820172622610"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164966152_p13820122613264"><a name="zh-cn_topic_0000001164966152_p13820122613264"></a><a name="zh-cn_topic_0000001164966152_p13820122613264"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164966152_p18497141212339"><a name="zh-cn_topic_0000001164966152_p18497141212339"></a><a name="zh-cn_topic_0000001164966152_p18497141212339"></a>用于返回网址的字符串序列化。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    const url = new URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    url.toString()
    ```


