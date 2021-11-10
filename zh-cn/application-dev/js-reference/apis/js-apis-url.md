# URL字符串解析<a name="ZH-CN_TOPIC_0000001151274864"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="section2080512344162"></a>

```
import Url from '@ohos.url' 
```

## 权限<a name="section11257113618419"></a>

无

## URLSearchParams<a name="section143808167355"></a>

### constructor<a name="section694710593283"></a>

constructor\(init?: string\[\]\[\] | Record<string, string\> | string | URLSearchParams\)

URLSearchParams的构造函数。

-   参数：

    <a name="table1540155452420"></a>
    <table><thead align="left"><tr id="row1947713549244"><th class="cellrowborder" valign="top" width="12.959999999999999%" id="mcps1.1.5.1.1"><p id="p74771754102410"><a name="p74771754102410"></a><a name="p74771754102410"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.06%" id="mcps1.1.5.1.2"><p id="p1047755412411"><a name="p1047755412411"></a><a name="p1047755412411"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.569999999999999%" id="mcps1.1.5.1.3"><p id="p34782054192412"><a name="p34782054192412"></a><a name="p34782054192412"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.41%" id="mcps1.1.5.1.4"><p id="p12478954132419"><a name="p12478954132419"></a><a name="p12478954132419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1247811541240"><td class="cellrowborder" valign="top" width="12.959999999999999%" headers="mcps1.1.5.1.1 "><p id="p2089352474715"><a name="p2089352474715"></a><a name="p2089352474715"></a>init</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.06%" headers="mcps1.1.5.1.2 "><p id="p81221923163816"><a name="p81221923163816"></a><a name="p81221923163816"></a>string[][] | Record&lt;string, string&gt; | string | URLSearchParams</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.5.1.3 "><p id="p1247885492411"><a name="p1247885492411"></a><a name="p1247885492411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.41%" headers="mcps1.1.5.1.4 "><p id="p12478654172415"><a name="p12478654172415"></a><a name="p12478654172415"></a>入参对象。</p>
    <a name="ul11644162993910"></a><a name="ul11644162993910"></a><ul id="ul11644162993910"><li>string[][]：字符串二维数组</li><li>Record&lt;string, string&gt;：对象列表</li><li>string：字符串</li><li>URLSearchParams：对象</li></ul>
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


### append<a name="section31006818349"></a>

append\(name: string, value: string\): void

将新的键值对插入到查询字符串。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>需要插入搜索参数的键名。</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>需要插入搜索参数的值。</p>
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


### delete<a name="section25256353342"></a>

delete\(name: string\): void

删除指定名称的键值对。

-   参数：

    <a name="table06501420123810"></a>
    <table><thead align="left"><tr id="row7651202014381"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p465112013817"><a name="p465112013817"></a><a name="p465112013817"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1651152053811"><a name="p1651152053811"></a><a name="p1651152053811"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p10651102018383"><a name="p10651102018383"></a><a name="p10651102018383"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p16511220143812"><a name="p16511220143812"></a><a name="p16511220143812"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19651202063816"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p176511020113820"><a name="p176511020113820"></a><a name="p176511020113820"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1865152043815"><a name="p1865152043815"></a><a name="p1865152043815"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p365292023811"><a name="p365292023811"></a><a name="p365292023811"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4652192063817"><a name="p4652192063817"></a><a name="p4652192063817"></a>需要删除的键值名称。</p>
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


### getAll<a name="section2178125553415"></a>

getAll\(name: string\): string\[\]

获取指定名称的所有键值对。

-   参数：

    <a name="table344935313917"></a>
    <table><thead align="left"><tr id="row1344915383919"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p134498535393"><a name="p134498535393"></a><a name="p134498535393"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p445055343918"><a name="p445055343918"></a><a name="p445055343918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p17450153173914"><a name="p17450153173914"></a><a name="p17450153173914"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1945045312399"><a name="p1945045312399"></a><a name="p1945045312399"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row184505536396"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p174501853103913"><a name="p174501853103913"></a><a name="p174501853103913"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p114501753123918"><a name="p114501753123918"></a><a name="p114501753123918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1245015534394"><a name="p1245015534394"></a><a name="p1245015534394"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p44501153143910"><a name="p44501153143910"></a><a name="p44501153143910"></a>指定的键值名称。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table37864874412"></a>
    <table><thead align="left"><tr id="row1778638104418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1778613834415"><a name="p1778613834415"></a><a name="p1778613834415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p6786118124414"><a name="p6786118124414"></a><a name="p6786118124414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row678611818445"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p83451276515"><a name="p83451276515"></a><a name="p83451276515"></a>string[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p6786118144419"><a name="p6786118144419"></a><a name="p6786118144419"></a>返回指定名称的所有键值对。</p>
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


### entries<a name="section139696402356"></a>

entries\(\): IterableIterator<\[string, string\]\>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

-   返回值：

    <a name="table092116152217"></a>
    <table><thead align="left"><tr id="row792256172217"><th class="cellrowborder" valign="top" width="33.660000000000004%" id="mcps1.1.3.1.1"><p id="p392286122211"><a name="p392286122211"></a><a name="p392286122211"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.34%" id="mcps1.1.3.1.2"><p id="p7922463223"><a name="p7922463223"></a><a name="p7922463223"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row189221612226"><td class="cellrowborder" valign="top" width="33.660000000000004%" headers="mcps1.1.3.1.1 "><p id="p11940347163112"><a name="p11940347163112"></a><a name="p11940347163112"></a>IterableIterator&lt;[string, string]&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.34%" headers="mcps1.1.3.1.2 "><p id="p310681516226"><a name="p310681516226"></a><a name="p310681516226"></a>返回一个ES6的迭代器。</p>
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


### forEach<a name="section299942113617"></a>

forEach\(callbackfn: \(value: string, key: string, searchParams: Object\) =\> void, thisArg?: Object\): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

-   参数：

    <a name="table127915306330"></a>
    <table><thead align="left"><tr id="row1727910302334"><th class="cellrowborder" valign="top" width="16.43%" id="mcps1.1.5.1.1"><p id="p1237183514330"><a name="p1237183514330"></a><a name="p1237183514330"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.2%" id="mcps1.1.5.1.2"><p id="p73716356332"><a name="p73716356332"></a><a name="p73716356332"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.14%" id="mcps1.1.5.1.3"><p id="p203711435133319"><a name="p203711435133319"></a><a name="p203711435133319"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.1.5.1.4"><p id="p2037111353332"><a name="p2037111353332"></a><a name="p2037111353332"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1728073073310"><td class="cellrowborder" valign="top" width="16.43%" headers="mcps1.1.5.1.1 "><p id="p1728014306336"><a name="p1728014306336"></a><a name="p1728014306336"></a>callbackfn</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.2%" headers="mcps1.1.5.1.2 "><p id="p1928014303336"><a name="p1928014303336"></a><a name="p1928014303336"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.5.1.3 "><p id="p82801930193317"><a name="p82801930193317"></a><a name="p82801930193317"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.1.5.1.4 "><p id="p2280133023319"><a name="p2280133023319"></a><a name="p2280133023319"></a>回调函数。</p>
    </td>
    </tr>
    <tr id="row1061141371920"><td class="cellrowborder" valign="top" width="16.43%" headers="mcps1.1.5.1.1 "><p id="p1962171319197"><a name="p1962171319197"></a><a name="p1962171319197"></a>thisArg</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.2%" headers="mcps1.1.5.1.2 "><p id="p56291331918"><a name="p56291331918"></a><a name="p56291331918"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.14%" headers="mcps1.1.5.1.3 "><p id="p136251321915"><a name="p136251321915"></a><a name="p136251321915"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.1.5.1.4 "><p id="p16631613131917"><a name="p16631613131917"></a><a name="p16631613131917"></a>callbackfn被调用时用作this值</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  callbackfn的参数说明

    <a name="table11630163925517"></a>
    <table><thead align="left"><tr id="row18630183913556"><th class="cellrowborder" valign="top" width="16.46%" id="mcps1.2.5.1.1"><p id="p6630939115517"><a name="p6630939115517"></a><a name="p6630939115517"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.8%" id="mcps1.2.5.1.2"><p id="p156301439145520"><a name="p156301439145520"></a><a name="p156301439145520"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.520000000000001%" id="mcps1.2.5.1.3"><p id="p166319395559"><a name="p166319395559"></a><a name="p166319395559"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.220000000000006%" id="mcps1.2.5.1.4"><p id="p206311039115511"><a name="p206311039115511"></a><a name="p206311039115511"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row963193918557"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="p16631163925512"><a name="p16631163925512"></a><a name="p16631163925512"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="p10631113915550"><a name="p10631113915550"></a><a name="p10631113915550"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="p36311239105519"><a name="p36311239105519"></a><a name="p36311239105519"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="p17767351572"><a name="p17767351572"></a><a name="p17767351572"></a>当前遍历到的键值。</p>
    </td>
    </tr>
    <tr id="row1463119397553"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="p19631103985517"><a name="p19631103985517"></a><a name="p19631103985517"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="p7631113965516"><a name="p7631113965516"></a><a name="p7631113965516"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="p2631203918552"><a name="p2631203918552"></a><a name="p2631203918552"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="p186310399556"><a name="p186310399556"></a><a name="p186310399556"></a>当前遍历到的键名。</p>
    </td>
    </tr>
    <tr id="row19539259115610"><td class="cellrowborder" valign="top" width="16.46%" headers="mcps1.2.5.1.1 "><p id="p980433316187"><a name="p980433316187"></a><a name="p980433316187"></a>searchParams</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.2.5.1.2 "><p id="p1453910594565"><a name="p1453910594565"></a><a name="p1453910594565"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.520000000000001%" headers="mcps1.2.5.1.3 "><p id="p35412590563"><a name="p35412590563"></a><a name="p35412590563"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.220000000000006%" headers="mcps1.2.5.1.4 "><p id="p1323294318182"><a name="p1323294318182"></a><a name="p1323294318182"></a>当前调用forEach方法的实例对象。</p>
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


### get<a name="section1229318155373"></a>

get\(name: string\): string | null

获取指定名称对应的第一个值。

-   参数：

    <a name="table377217542586"></a>
    <table><thead align="left"><tr id="row1877275419580"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p277225412589"><a name="p277225412589"></a><a name="p277225412589"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p10772175495820"><a name="p10772175495820"></a><a name="p10772175495820"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p277265412588"><a name="p277265412588"></a><a name="p277265412588"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p77731254105819"><a name="p77731254105819"></a><a name="p77731254105819"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4773854175820"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p137734549583"><a name="p137734549583"></a><a name="p137734549583"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p107730545586"><a name="p107730545586"></a><a name="p107730545586"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p277355418585"><a name="p277355418585"></a><a name="p277355418585"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p877335412588"><a name="p877335412588"></a><a name="p877335412588"></a>指定键值对的名称。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table18354510245"></a>
    <table><thead align="left"><tr id="row133612552415"><th class="cellrowborder" valign="top" width="20.96%" id="mcps1.1.3.1.1"><p id="p8369592415"><a name="p8369592415"></a><a name="p8369592415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.03999999999999%" id="mcps1.1.3.1.2"><p id="p1363514249"><a name="p1363514249"></a><a name="p1363514249"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row43614517248"><td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.3.1.1 "><p id="p193611582417"><a name="p193611582417"></a><a name="p193611582417"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p136452242"><a name="p136452242"></a><a name="p136452242"></a>返回第一个值。</p>
    </td>
    </tr>
    <tr id="row1190673810242"><td class="cellrowborder" valign="top" width="20.96%" headers="mcps1.1.3.1.1 "><p id="p11907163819242"><a name="p11907163819242"></a><a name="p11907163819242"></a>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.03999999999999%" headers="mcps1.1.3.1.2 "><p id="p7907183802419"><a name="p7907183802419"></a><a name="p7907183802419"></a>如果没找到，返回 null。</p>
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


### has<a name="section1385211103813"></a>

has\(name: string\): boolean

判断一个指定的键名对应的值是否存在。

-   参数：

    <a name="table746711171833"></a>
    <table><thead align="left"><tr id="row174684171316"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p154681517736"><a name="p154681517736"></a><a name="p154681517736"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p24684172312"><a name="p24684172312"></a><a name="p24684172312"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p94681817736"><a name="p94681817736"></a><a name="p94681817736"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p646817171331"><a name="p646817171331"></a><a name="p646817171331"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row134681171135"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p64692017333"><a name="p64692017333"></a><a name="p64692017333"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1946910174320"><a name="p1946910174320"></a><a name="p1946910174320"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10469717231"><a name="p10469717231"></a><a name="p10469717231"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p24691217436"><a name="p24691217436"></a><a name="p24691217436"></a>要查找的参数的键名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table156691044124411"></a>
    <table><thead align="left"><tr id="row6670164444419"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p10670114414449"><a name="p10670114414449"></a><a name="p10670114414449"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p3670144424418"><a name="p3670144424418"></a><a name="p3670144424418"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13670184418448"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1667064474420"><a name="p1667064474420"></a><a name="p1667064474420"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p5592172072510"><a name="p5592172072510"></a><a name="p5592172072510"></a>是否存在相对应的key值，存在返回true，否则返回false。</p>
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


### set<a name="section186091516203910"></a>

set\(name: string, value: string\): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

-   参数：

    <a name="table1653110211471"></a>
    <table><thead align="left"><tr id="row7531721778"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p75312021371"><a name="p75312021371"></a><a name="p75312021371"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p105313219716"><a name="p105313219716"></a><a name="p105313219716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1553216216717"><a name="p1553216216717"></a><a name="p1553216216717"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p13532102114716"><a name="p13532102114716"></a><a name="p13532102114716"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row185321921572"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10532172118711"><a name="p10532172118711"></a><a name="p10532172118711"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10532152114718"><a name="p10532152114718"></a><a name="p10532152114718"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1453220215713"><a name="p1453220215713"></a><a name="p1453220215713"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p053215214717"><a name="p053215214717"></a><a name="p053215214717"></a>将要设置的参数的键值名。</p>
    </td>
    </tr>
    <tr id="row18550750182"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p655013501184"><a name="p655013501184"></a><a name="p655013501184"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p196231541790"><a name="p196231541790"></a><a name="p196231541790"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p355120502810"><a name="p355120502810"></a><a name="p355120502810"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p145514507816"><a name="p145514507816"></a><a name="p145514507816"></a>所要设置的参数值。</p>
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


### sort<a name="section102851552183915"></a>

sort\(\): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

-   示例：

    ```
    var searchParamsObject = new URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
    searchParamsObject.sort(); // Sort the key/value pairs
    console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
    ```


### keys<a name="section816918183413"></a>

keys\(\): IterableIterator<string\>

返回一个所有键值对的name的ES6迭代器。

-   返回值：

    <a name="table15822151784820"></a>
    <table><thead align="left"><tr id="row38222172484"><th class="cellrowborder" valign="top" width="32.550000000000004%" id="mcps1.1.3.1.1"><p id="p158225175483"><a name="p158225175483"></a><a name="p158225175483"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.45%" id="mcps1.1.3.1.2"><p id="p3822131718485"><a name="p3822131718485"></a><a name="p3822131718485"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row58231817124817"><td class="cellrowborder" valign="top" width="32.550000000000004%" headers="mcps1.1.3.1.1 "><p id="p118232017164813"><a name="p118232017164813"></a><a name="p118232017164813"></a>IterableIterator&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.45%" headers="mcps1.1.3.1.2 "><p id="p1128142484911"><a name="p1128142484911"></a><a name="p1128142484911"></a>返回一个所有键值对的name的ES6迭代器。</p>
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


### values<a name="section0542174314413"></a>

values\(\): IterableIterator<string\>

返回一个所有键值对的value的ES6迭代器。

-   返回值：

    <a name="table44901259134916"></a>
    <table><thead align="left"><tr id="row44901859124916"><th class="cellrowborder" valign="top" width="36.51%" id="mcps1.1.3.1.1"><p id="p19491175912499"><a name="p19491175912499"></a><a name="p19491175912499"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.49%" id="mcps1.1.3.1.2"><p id="p1491145934914"><a name="p1491145934914"></a><a name="p1491145934914"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6491125914919"><td class="cellrowborder" valign="top" width="36.51%" headers="mcps1.1.3.1.1 "><p id="p13812011488"><a name="p13812011488"></a><a name="p13812011488"></a>IterableIterator&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.49%" headers="mcps1.1.3.1.2 "><p id="p38375645210"><a name="p38375645210"></a><a name="p38375645210"></a>返回一个所有键值对的value的ES6迭代器。</p>
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


### \[Symbol.iterator\]<a name="section1152151784210"></a>

\[Symbol.iterator\]\(\): IterableIterator<\[string, string\]\>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

-   返回值：

    <a name="table8247125417537"></a>
    <table><thead align="left"><tr id="row1424715435311"><th class="cellrowborder" valign="top" width="38.99%" id="mcps1.1.3.1.1"><p id="p17247125419532"><a name="p17247125419532"></a><a name="p17247125419532"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.01%" id="mcps1.1.3.1.2"><p id="p424795415313"><a name="p424795415313"></a><a name="p424795415313"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row72471054115317"><td class="cellrowborder" valign="top" width="38.99%" headers="mcps1.1.3.1.1 "><p id="p8576493492"><a name="p8576493492"></a><a name="p8576493492"></a>IterableIterator&lt;[string, string]&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.01%" headers="mcps1.1.3.1.2 "><p id="p16248185414532"><a name="p16248185414532"></a><a name="p16248185414532"></a>返回一个ES6的迭代器。</p>
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


### tostring<a name="section228585911428"></a>

toString\(\): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

-   返回值：

    <a name="table016316018566"></a>
    <table><thead align="left"><tr id="row171632010566"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p71631308563"><a name="p71631308563"></a><a name="p71631308563"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p2164120205610"><a name="p2164120205610"></a><a name="p2164120205610"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14164110145610"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1516413016565"><a name="p1516413016565"></a><a name="p1516413016565"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p516412017563"><a name="p516412017563"></a><a name="p516412017563"></a>返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。</p>
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


## URL<a name="section148871646203714"></a>

### 属性<a name="section18482944113517"></a>

<a name="table20482104463514"></a>
<table><thead align="left"><tr id="row1348214444357"><th class="cellrowborder" valign="top" width="11.84%" id="mcps1.1.6.1.1"><p id="p184822443351"><a name="p184822443351"></a><a name="p184822443351"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.75%" id="mcps1.1.6.1.2"><p id="p1648254415353"><a name="p1648254415353"></a><a name="p1648254415353"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="5.34%" id="mcps1.1.6.1.3"><p id="p9482124413355"><a name="p9482124413355"></a><a name="p9482124413355"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.65%" id="mcps1.1.6.1.4"><p id="p3482124493515"><a name="p3482124493515"></a><a name="p3482124493515"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p12482104483513"><a name="p12482104483513"></a><a name="p12482104483513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row148254473513"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p1832319183511"><a name="p1832319183511"></a><a name="p1832319183511"></a>hash</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p3482124417356"><a name="p3482124417356"></a><a name="p3482124417356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p16483194443514"><a name="p16483194443514"></a><a name="p16483194443514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p630714163422"><a name="p630714163422"></a><a name="p630714163422"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p72131224114411"><a name="p72131224114411"></a><a name="p72131224114411"></a>获取和设置URL的片段部分。</p>
</td>
</tr>
<tr id="row58631729183511"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p1669917383355"><a name="p1669917383355"></a><a name="p1669917383355"></a>host</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p986510296359"><a name="p986510296359"></a><a name="p986510296359"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p14865182993518"><a name="p14865182993518"></a><a name="p14865182993518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1586552915355"><a name="p1586552915355"></a><a name="p1586552915355"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12865829133514"><a name="p12865829133514"></a><a name="p12865829133514"></a>获取和设置URL的主机部分。</p>
</td>
</tr>
<tr id="row173737374371"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p73744376373"><a name="p73744376373"></a><a name="p73744376373"></a>hostname</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p183741337173714"><a name="p183741337173714"></a><a name="p183741337173714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p13374237173711"><a name="p13374237173711"></a><a name="p13374237173711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1737416372376"><a name="p1737416372376"></a><a name="p1737416372376"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p737414373372"><a name="p737414373372"></a><a name="p737414373372"></a>获取和设置URL的主机名部分，不带端口。</p>
</td>
</tr>
<tr id="row18603545143715"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p1360410454373"><a name="p1360410454373"></a><a name="p1360410454373"></a>href</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p1260410456378"><a name="p1260410456378"></a><a name="p1260410456378"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p146042453371"><a name="p146042453371"></a><a name="p146042453371"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p460416456374"><a name="p460416456374"></a><a name="p460416456374"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1560554514376"><a name="p1560554514376"></a><a name="p1560554514376"></a>获取和设置序列化的URL。</p>
</td>
</tr>
<tr id="row15118124793712"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p9121914204110"><a name="p9121914204110"></a><a name="p9121914204110"></a>origin</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p41181471376"><a name="p41181471376"></a><a name="p41181471376"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p10118447153719"><a name="p10118447153719"></a><a name="p10118447153719"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1111884793714"><a name="p1111884793714"></a><a name="p1111884793714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11181479377"><a name="p11181479377"></a><a name="p11181479377"></a>获取URL源的只读序列化。</p>
</td>
</tr>
<tr id="row2998164312378"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p20998643103713"><a name="p20998643103713"></a><a name="p20998643103713"></a>password</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p1899804315372"><a name="p1899804315372"></a><a name="p1899804315372"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p1399820431377"><a name="p1399820431377"></a><a name="p1399820431377"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p29980434371"><a name="p29980434371"></a><a name="p29980434371"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1299814373714"><a name="p1299814373714"></a><a name="p1299814373714"></a>获取和设置URL的密码部分。</p>
</td>
</tr>
<tr id="row6527542193711"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p1852784212370"><a name="p1852784212370"></a><a name="p1852784212370"></a>pathname</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p205271742183711"><a name="p205271742183711"></a><a name="p205271742183711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p952724233717"><a name="p952724233717"></a><a name="p952724233717"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1452784214373"><a name="p1452784214373"></a><a name="p1452784214373"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18527842143718"><a name="p18527842143718"></a><a name="p18527842143718"></a>获取和设置URL的路径部分。</p>
</td>
</tr>
<tr id="row1221604019378"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p12161040193711"><a name="p12161040193711"></a><a name="p12161040193711"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p12161040103714"><a name="p12161040103714"></a><a name="p12161040103714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p621674073715"><a name="p621674073715"></a><a name="p621674073715"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1821624033711"><a name="p1821624033711"></a><a name="p1821624033711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1421614403377"><a name="p1421614403377"></a><a name="p1421614403377"></a>获取和设置URL的端口部分。</p>
</td>
</tr>
<tr id="row763211357376"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p1863313520378"><a name="p1863313520378"></a><a name="p1863313520378"></a>protocol</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p8633113583715"><a name="p8633113583715"></a><a name="p8633113583715"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p1663363533710"><a name="p1663363533710"></a><a name="p1663363533710"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1763312358374"><a name="p1763312358374"></a><a name="p1763312358374"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p363383518374"><a name="p363383518374"></a><a name="p363383518374"></a>获取和设置URL的协议部分。</p>
</td>
</tr>
<tr id="row252344113516"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p852414113510"><a name="p852414113510"></a><a name="p852414113510"></a>search</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p115241141203517"><a name="p115241141203517"></a><a name="p115241141203517"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p3524134183519"><a name="p3524134183519"></a><a name="p3524134183519"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p752464173511"><a name="p752464173511"></a><a name="p752464173511"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12524144111358"><a name="p12524144111358"></a><a name="p12524144111358"></a>获取和设置URL的序列化查询部分。</p>
</td>
</tr>
<tr id="row1483164414352"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p0747823153511"><a name="p0747823153511"></a><a name="p0747823153511"></a>searchParams</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p133371031194316"><a name="p133371031194316"></a><a name="p133371031194316"></a>URLsearchParams</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p1348384415359"><a name="p1348384415359"></a><a name="p1348384415359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p1448312449355"><a name="p1448312449355"></a><a name="p1448312449355"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p8483124473515"><a name="p8483124473515"></a><a name="p8483124473515"></a>获取URLSearchParams表示URL查询参数的对象。</p>
</td>
</tr>
<tr id="row13483164419353"><td class="cellrowborder" valign="top" width="11.84%" headers="mcps1.1.6.1.1 "><p id="p4483154463514"><a name="p4483154463514"></a><a name="p4483154463514"></a>username</p>
</td>
<td class="cellrowborder" valign="top" width="20.75%" headers="mcps1.1.6.1.2 "><p id="p1887911084315"><a name="p1887911084315"></a><a name="p1887911084315"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="5.34%" headers="mcps1.1.6.1.3 "><p id="p1483134419353"><a name="p1483134419353"></a><a name="p1483134419353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.65%" headers="mcps1.1.6.1.4 "><p id="p648354483510"><a name="p648354483510"></a><a name="p648354483510"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p348319442351"><a name="p348319442351"></a><a name="p348319442351"></a>获取和设置URL的用户名部分。</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section712011584410"></a>

constructor\(url: string, base?: string | URL\)

URL的构造函数。

-   参数：

    <a name="table1723015271384"></a>
    <table><thead align="left"><tr id="row42301327153814"><th class="cellrowborder" valign="top" width="17.5%" id="mcps1.1.5.1.1"><p id="p102307272383"><a name="p102307272383"></a><a name="p102307272383"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.139999999999997%" id="mcps1.1.5.1.2"><p id="p202307278382"><a name="p202307278382"></a><a name="p202307278382"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.81%" id="mcps1.1.5.1.3"><p id="p1123113278381"><a name="p1123113278381"></a><a name="p1123113278381"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.55%" id="mcps1.1.5.1.4"><p id="p5231172773815"><a name="p5231172773815"></a><a name="p5231172773815"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row122318279387"><td class="cellrowborder" valign="top" width="17.5%" headers="mcps1.1.5.1.1 "><p id="p161271253807"><a name="p161271253807"></a><a name="p161271253807"></a>url</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.139999999999997%" headers="mcps1.1.5.1.2 "><p id="p11231102719382"><a name="p11231102719382"></a><a name="p11231102719382"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.81%" headers="mcps1.1.5.1.3 "><p id="p1023152712389"><a name="p1023152712389"></a><a name="p1023152712389"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.55%" headers="mcps1.1.5.1.4 "><p id="p323132783819"><a name="p323132783819"></a><a name="p323132783819"></a>入参对象。</p>
    </td>
    </tr>
    <tr id="row189010267539"><td class="cellrowborder" valign="top" width="17.5%" headers="mcps1.1.5.1.1 "><p id="p1990210261536"><a name="p1990210261536"></a><a name="p1990210261536"></a>base</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.139999999999997%" headers="mcps1.1.5.1.2 "><p id="p159024261532"><a name="p159024261532"></a><a name="p159024261532"></a>string | URL</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.81%" headers="mcps1.1.5.1.3 "><p id="p10902426145317"><a name="p10902426145317"></a><a name="p10902426145317"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.55%" headers="mcps1.1.5.1.4 "><p id="p16902126135313"><a name="p16902126135313"></a><a name="p16902126135313"></a>入参字符串或者对象。</p>
    <a name="ul1755124022517"></a><a name="ul1755124022517"></a><ul id="ul1755124022517"><li>string：字符串</li><li>URL：字符串或对象</li></ul>
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


### tostring<a name="section2849448104520"></a>

toString\(\): string

将解析过后的URL转化为字符串。

-   返回值：

    <a name="table201041412244"></a>
    <table><thead align="left"><tr id="row410431122411"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p110413182418"><a name="p110413182418"></a><a name="p110413182418"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p181042116249"><a name="p181042116249"></a><a name="p181042116249"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row110421182413"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p510461102411"><a name="p510461102411"></a><a name="p510461102411"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p159992542327"><a name="p159992542327"></a><a name="p159992542327"></a>用于返回网址的字符串序列化。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    const url = new URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    url.toString()
    ```


### toJSON<a name="section3488111554611"></a>

toJSON\(\): string

将解析过后的URL转化为JSON字符串。

-   返回值：

    <a name="table981932613263"></a>
    <table><thead align="left"><tr id="row38194264264"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p178208263269"><a name="p178208263269"></a><a name="p178208263269"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p15820112672617"><a name="p15820112672617"></a><a name="p15820112672617"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2820172622610"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p13820122613264"><a name="p13820122613264"></a><a name="p13820122613264"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p18497141212339"><a name="p18497141212339"></a><a name="p18497141212339"></a>用于返回网址的字符串序列化。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    const url = new URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    url.toString()
    ```


