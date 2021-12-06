# 字符串编解码<a name="ZH-CN_TOPIC_0000001210366345"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001210206021_s56d19203690d4782bfc74069abb6bd71"></a>

```
import util from '@ohos.util' 
```

## 权限<a name="zh-cn_topic_0000001210206021_section11257113618419"></a>

无

## util.printf<a name="zh-cn_topic_0000001210206021_section192192415554"></a>

printf\(format: string, ...args: Object\[\]\): string

通过式样化字符串对输入的内容按特定格式输出。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p7966738914"><a name="zh-cn_topic_0000001210206021_p7966738914"></a><a name="zh-cn_topic_0000001210206021_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p296713699"><a name="zh-cn_topic_0000001210206021_p296713699"></a><a name="zh-cn_topic_0000001210206021_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p196718315911"><a name="zh-cn_topic_0000001210206021_p196718315911"></a><a name="zh-cn_topic_0000001210206021_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p9967231197"><a name="zh-cn_topic_0000001210206021_p9967231197"></a><a name="zh-cn_topic_0000001210206021_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p79671633910"><a name="zh-cn_topic_0000001210206021_p79671633910"></a><a name="zh-cn_topic_0000001210206021_p79671633910"></a>format</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p11967433914"><a name="zh-cn_topic_0000001210206021_p11967433914"></a><a name="zh-cn_topic_0000001210206021_p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p19671336916"><a name="zh-cn_topic_0000001210206021_p19671336916"></a><a name="zh-cn_topic_0000001210206021_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p18899105910192"><a name="zh-cn_topic_0000001210206021_p18899105910192"></a><a name="zh-cn_topic_0000001210206021_p18899105910192"></a>式样化字符串。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001210206021_row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p13702016205012"><a name="zh-cn_topic_0000001210206021_p13702016205012"></a><a name="zh-cn_topic_0000001210206021_p13702016205012"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p478592912504"><a name="zh-cn_topic_0000001210206021_p478592912504"></a><a name="zh-cn_topic_0000001210206021_p478592912504"></a>Object[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p149671932919"><a name="zh-cn_topic_0000001210206021_p149671932919"></a><a name="zh-cn_topic_0000001210206021_p149671932919"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p14582313152114"><a name="zh-cn_topic_0000001210206021_p14582313152114"></a><a name="zh-cn_topic_0000001210206021_p14582313152114"></a>待式样化数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table16391145317913"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row2391145319910"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p13911353991"><a name="zh-cn_topic_0000001210206021_p13911353991"></a><a name="zh-cn_topic_0000001210206021_p13911353991"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p193911531395"><a name="zh-cn_topic_0000001210206021_p193911531395"></a><a name="zh-cn_topic_0000001210206021_p193911531395"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row1339114531391"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p16358176115311"><a name="zh-cn_topic_0000001210206021_p16358176115311"></a><a name="zh-cn_topic_0000001210206021_p16358176115311"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p107511844112312"><a name="zh-cn_topic_0000001210206021_p107511844112312"></a><a name="zh-cn_topic_0000001210206021_p107511844112312"></a>按特定格式式样化后的字符串。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var res = util.printf("%s", "hello world!");
    console.log(res);
    ```


## util.getErrorString<a name="zh-cn_topic_0000001210206021_section858912895313"></a>

getErrorString\(errno: number\): string

获取系统错误码对应的详细信息。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table55891528185315"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row115891228145313"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p35901828175317"><a name="zh-cn_topic_0000001210206021_p35901828175317"></a><a name="zh-cn_topic_0000001210206021_p35901828175317"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p18590152820538"><a name="zh-cn_topic_0000001210206021_p18590152820538"></a><a name="zh-cn_topic_0000001210206021_p18590152820538"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p95900289534"><a name="zh-cn_topic_0000001210206021_p95900289534"></a><a name="zh-cn_topic_0000001210206021_p95900289534"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p1359016288531"><a name="zh-cn_topic_0000001210206021_p1359016288531"></a><a name="zh-cn_topic_0000001210206021_p1359016288531"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row6590122819538"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p17590428115313"><a name="zh-cn_topic_0000001210206021_p17590428115313"></a><a name="zh-cn_topic_0000001210206021_p17590428115313"></a>errno</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p13405179222"><a name="zh-cn_topic_0000001210206021_p13405179222"></a><a name="zh-cn_topic_0000001210206021_p13405179222"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p959032865319"><a name="zh-cn_topic_0000001210206021_p959032865319"></a><a name="zh-cn_topic_0000001210206021_p959032865319"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p95901128125320"><a name="zh-cn_topic_0000001210206021_p95901128125320"></a><a name="zh-cn_topic_0000001210206021_p95901128125320"></a>系统发生错误产生的错误码。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table959218285533"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row259252820539"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p175921928175319"><a name="zh-cn_topic_0000001210206021_p175921928175319"></a><a name="zh-cn_topic_0000001210206021_p175921928175319"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p1759262819538"><a name="zh-cn_topic_0000001210206021_p1759262819538"></a><a name="zh-cn_topic_0000001210206021_p1759262819538"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row15592142812531"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p959252813537"><a name="zh-cn_topic_0000001210206021_p959252813537"></a><a name="zh-cn_topic_0000001210206021_p959252813537"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p459272810535"><a name="zh-cn_topic_0000001210206021_p459272810535"></a><a name="zh-cn_topic_0000001210206021_p459272810535"></a>错误码对应的详细信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var errnum = 10; // 10：a system error number
    var result = util.getErrorString(errnum);
    console.log("result = " + result);
    ```


## util.callbackWrapper<a name="zh-cn_topic_0000001210206021_section15594104112592"></a>

callbackWrapper\(original: Function\): \(err: Object, value: Object\)=\>void

对异步函数进行回调化处理，回调中第一个参数将是拒绝原因（如果 Promise 已解决，则为 null），第二个参数将是已解决的值。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table8595841155910"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row45953415598"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p15953414591"><a name="zh-cn_topic_0000001210206021_p15953414591"></a><a name="zh-cn_topic_0000001210206021_p15953414591"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p2596144175918"><a name="zh-cn_topic_0000001210206021_p2596144175918"></a><a name="zh-cn_topic_0000001210206021_p2596144175918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p35961341115918"><a name="zh-cn_topic_0000001210206021_p35961341115918"></a><a name="zh-cn_topic_0000001210206021_p35961341115918"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p105966412596"><a name="zh-cn_topic_0000001210206021_p105966412596"></a><a name="zh-cn_topic_0000001210206021_p105966412596"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row12596124113592"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p19596174135912"><a name="zh-cn_topic_0000001210206021_p19596174135912"></a><a name="zh-cn_topic_0000001210206021_p19596174135912"></a>original</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p020217118113"><a name="zh-cn_topic_0000001210206021_p020217118113"></a><a name="zh-cn_topic_0000001210206021_p020217118113"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p2596154118591"><a name="zh-cn_topic_0000001210206021_p2596154118591"></a><a name="zh-cn_topic_0000001210206021_p2596154118591"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p1471526810"><a name="zh-cn_topic_0000001210206021_p1471526810"></a><a name="zh-cn_topic_0000001210206021_p1471526810"></a>异步函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table3598104111591"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row16598144112599"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p20598144115597"><a name="zh-cn_topic_0000001210206021_p20598144115597"></a><a name="zh-cn_topic_0000001210206021_p20598144115597"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p4598114135912"><a name="zh-cn_topic_0000001210206021_p4598114135912"></a><a name="zh-cn_topic_0000001210206021_p4598114135912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row059994114593"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p15521135919118"><a name="zh-cn_topic_0000001210206021_p15521135919118"></a><a name="zh-cn_topic_0000001210206021_p15521135919118"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p1759984114595"><a name="zh-cn_topic_0000001210206021_p1759984114595"></a><a name="zh-cn_topic_0000001210206021_p1759984114595"></a>返回一个第一个参数是拒绝原因（如果 Promise 已解决，则为 null），第二个参数是已解决的回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    async function promiseFn() {
        return Promise.reject('value');
    }
    var cb = util.callbackWrapper(promiseFn);
    cb((err, ret) => {
        expect(err).strictEqual('value');
        expect(ret).strictEqual(undefined);
    })
    ```


## util.promiseWrapper<a name="zh-cn_topic_0000001210206021_section172381917987"></a>

promiseWrapper\(original: \(err: Object, value: Object\) =\> void\): Object

对异步函数处理并返回一个promise的版本。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table1239191711810"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row423919171389"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p823941711816"><a name="zh-cn_topic_0000001210206021_p823941711816"></a><a name="zh-cn_topic_0000001210206021_p823941711816"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p15240017482"><a name="zh-cn_topic_0000001210206021_p15240017482"></a><a name="zh-cn_topic_0000001210206021_p15240017482"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p624015171185"><a name="zh-cn_topic_0000001210206021_p624015171185"></a><a name="zh-cn_topic_0000001210206021_p624015171185"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p22403179814"><a name="zh-cn_topic_0000001210206021_p22403179814"></a><a name="zh-cn_topic_0000001210206021_p22403179814"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row9240141716812"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p1124019171984"><a name="zh-cn_topic_0000001210206021_p1124019171984"></a><a name="zh-cn_topic_0000001210206021_p1124019171984"></a>original</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p32401617886"><a name="zh-cn_topic_0000001210206021_p32401617886"></a><a name="zh-cn_topic_0000001210206021_p32401617886"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p990643291112"><a name="zh-cn_topic_0000001210206021_p990643291112"></a><a name="zh-cn_topic_0000001210206021_p990643291112"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p69671631796"><a name="zh-cn_topic_0000001210206021_p69671631796"></a><a name="zh-cn_topic_0000001210206021_p69671631796"></a>异步函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table17243191712818"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row62431017981"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p11243617785"><a name="zh-cn_topic_0000001210206021_p11243617785"></a><a name="zh-cn_topic_0000001210206021_p11243617785"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p172431317182"><a name="zh-cn_topic_0000001210206021_p172431317182"></a><a name="zh-cn_topic_0000001210206021_p172431317182"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row1243201714811"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p73929531797"><a name="zh-cn_topic_0000001210206021_p73929531797"></a><a name="zh-cn_topic_0000001210206021_p73929531797"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p125051140151213"><a name="zh-cn_topic_0000001210206021_p125051140151213"></a><a name="zh-cn_topic_0000001210206021_p125051140151213"></a>采用遵循常见的错误优先的回调风格的函数（也就是将 (err, value) =&gt; ... 回调作为最后一个参数），并返回一个返回 promise 的版本。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    function aysnFun(str1, str2, callback) {
        if (typeof str1 === 'string' && typeof str1 === 'string') {
            callback(null, str1 + str2);
        } else {
            callback('type err');
        }
    }
    let newPromiseObj = util.promiseWrapper(aysnFun)("Hello", 'World');
    newPromiseObj.then(res => {
        expect(res).strictEqual('HelloWorld');
    })
    ```


## TextDecoder<a name="zh-cn_topic_0000001210206021_section143808167355"></a>

### 属性<a name="zh-cn_topic_0000001210206021_section18482944113517"></a>

<a name="zh-cn_topic_0000001210206021_table20482104463514"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row1348214444357"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001210206021_p184822443351"><a name="zh-cn_topic_0000001210206021_p184822443351"></a><a name="zh-cn_topic_0000001210206021_p184822443351"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001210206021_p1648254415353"><a name="zh-cn_topic_0000001210206021_p1648254415353"></a><a name="zh-cn_topic_0000001210206021_p1648254415353"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001210206021_p9482124413355"><a name="zh-cn_topic_0000001210206021_p9482124413355"></a><a name="zh-cn_topic_0000001210206021_p9482124413355"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001210206021_p3482124493515"><a name="zh-cn_topic_0000001210206021_p3482124493515"></a><a name="zh-cn_topic_0000001210206021_p3482124493515"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001210206021_p12482104483513"><a name="zh-cn_topic_0000001210206021_p12482104483513"></a><a name="zh-cn_topic_0000001210206021_p12482104483513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001210206021_row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001210206021_p2482444163514"><a name="zh-cn_topic_0000001210206021_p2482444163514"></a><a name="zh-cn_topic_0000001210206021_p2482444163514"></a>encoding</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001210206021_p3482124417356"><a name="zh-cn_topic_0000001210206021_p3482124417356"></a><a name="zh-cn_topic_0000001210206021_p3482124417356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001210206021_p16483194443514"><a name="zh-cn_topic_0000001210206021_p16483194443514"></a><a name="zh-cn_topic_0000001210206021_p16483194443514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001210206021_p64838449351"><a name="zh-cn_topic_0000001210206021_p64838449351"></a><a name="zh-cn_topic_0000001210206021_p64838449351"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001210206021_p164831444113515"><a name="zh-cn_topic_0000001210206021_p164831444113515"></a><a name="zh-cn_topic_0000001210206021_p164831444113515"></a>编码格式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001210206021_row1483164414352"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001210206021_p17483184419352"><a name="zh-cn_topic_0000001210206021_p17483184419352"></a><a name="zh-cn_topic_0000001210206021_p17483184419352"></a>fatal</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001210206021_p9483184410355"><a name="zh-cn_topic_0000001210206021_p9483184410355"></a><a name="zh-cn_topic_0000001210206021_p9483184410355"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001210206021_p1348384415359"><a name="zh-cn_topic_0000001210206021_p1348384415359"></a><a name="zh-cn_topic_0000001210206021_p1348384415359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001210206021_p1448312449355"><a name="zh-cn_topic_0000001210206021_p1448312449355"></a><a name="zh-cn_topic_0000001210206021_p1448312449355"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001210206021_p8483124473515"><a name="zh-cn_topic_0000001210206021_p8483124473515"></a><a name="zh-cn_topic_0000001210206021_p8483124473515"></a>是否显示致命错误。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001210206021_row13483164419353"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001210206021_p4483154463514"><a name="zh-cn_topic_0000001210206021_p4483154463514"></a><a name="zh-cn_topic_0000001210206021_p4483154463514"></a>ignoreBOM</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001210206021_p4483174443517"><a name="zh-cn_topic_0000001210206021_p4483174443517"></a><a name="zh-cn_topic_0000001210206021_p4483174443517"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001210206021_p1483134419353"><a name="zh-cn_topic_0000001210206021_p1483134419353"></a><a name="zh-cn_topic_0000001210206021_p1483134419353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001210206021_p648354483510"><a name="zh-cn_topic_0000001210206021_p648354483510"></a><a name="zh-cn_topic_0000001210206021_p648354483510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001210206021_p348319442351"><a name="zh-cn_topic_0000001210206021_p348319442351"></a><a name="zh-cn_topic_0000001210206021_p348319442351"></a>是否忽略BOM（byte order marker）标记，默认值是false。</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="zh-cn_topic_0000001210206021_section6179915133611"></a>

constructor\(encoding?: string, options?: \{ fatal?: boolean; ignoreBOM?: boolean \},\)

TextDecoder的构造函数。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table51212237384"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row1512182373816"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p5121112319386"><a name="zh-cn_topic_0000001210206021_p5121112319386"></a><a name="zh-cn_topic_0000001210206021_p5121112319386"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p1712122383810"><a name="zh-cn_topic_0000001210206021_p1712122383810"></a><a name="zh-cn_topic_0000001210206021_p1712122383810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p712112373813"><a name="zh-cn_topic_0000001210206021_p712112373813"></a><a name="zh-cn_topic_0000001210206021_p712112373813"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p71218236389"><a name="zh-cn_topic_0000001210206021_p71218236389"></a><a name="zh-cn_topic_0000001210206021_p71218236389"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row2121923123819"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p112132393816"><a name="zh-cn_topic_0000001210206021_p112132393816"></a><a name="zh-cn_topic_0000001210206021_p112132393816"></a>encoding</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p1212102383818"><a name="zh-cn_topic_0000001210206021_p1212102383818"></a><a name="zh-cn_topic_0000001210206021_p1212102383818"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p6121323143812"><a name="zh-cn_topic_0000001210206021_p6121323143812"></a><a name="zh-cn_topic_0000001210206021_p6121323143812"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p16121182313387"><a name="zh-cn_topic_0000001210206021_p16121182313387"></a><a name="zh-cn_topic_0000001210206021_p16121182313387"></a>编码格式。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001210206021_row512116231383"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p141211823113818"><a name="zh-cn_topic_0000001210206021_p141211823113818"></a><a name="zh-cn_topic_0000001210206021_p141211823113818"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p81221923163816"><a name="zh-cn_topic_0000001210206021_p81221923163816"></a><a name="zh-cn_topic_0000001210206021_p81221923163816"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p201229236384"><a name="zh-cn_topic_0000001210206021_p201229236384"></a><a name="zh-cn_topic_0000001210206021_p201229236384"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p7122142317382"><a name="zh-cn_topic_0000001210206021_p7122142317382"></a><a name="zh-cn_topic_0000001210206021_p7122142317382"></a>编码相关选项参数，存在两个属性fatal和ignoreBOM。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  options

    <a name="zh-cn_topic_0000001210206021_table468420114018"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row1768412134017"><th class="cellrowborder" valign="top" width="17.549999999999997%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001210206021_p86842124013"><a name="zh-cn_topic_0000001210206021_p86842124013"></a><a name="zh-cn_topic_0000001210206021_p86842124013"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001210206021_p16848194014"><a name="zh-cn_topic_0000001210206021_p16848194014"></a><a name="zh-cn_topic_0000001210206021_p16848194014"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.16%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001210206021_p146848118406"><a name="zh-cn_topic_0000001210206021_p146848118406"></a><a name="zh-cn_topic_0000001210206021_p146848118406"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001210206021_p66848113409"><a name="zh-cn_topic_0000001210206021_p66848113409"></a><a name="zh-cn_topic_0000001210206021_p66848113409"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row96841013407"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001210206021_p126849184010"><a name="zh-cn_topic_0000001210206021_p126849184010"></a><a name="zh-cn_topic_0000001210206021_p126849184010"></a>fatal</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001210206021_p368421104017"><a name="zh-cn_topic_0000001210206021_p368421104017"></a><a name="zh-cn_topic_0000001210206021_p368421104017"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001210206021_p17684818404"><a name="zh-cn_topic_0000001210206021_p17684818404"></a><a name="zh-cn_topic_0000001210206021_p17684818404"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001210206021_p9845227114216"><a name="zh-cn_topic_0000001210206021_p9845227114216"></a><a name="zh-cn_topic_0000001210206021_p9845227114216"></a>是否显示致命错误。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001210206021_row13751843114014"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001210206021_p11938165615400"><a name="zh-cn_topic_0000001210206021_p11938165615400"></a><a name="zh-cn_topic_0000001210206021_p11938165615400"></a>ignoreBOM</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001210206021_p67614394017"><a name="zh-cn_topic_0000001210206021_p67614394017"></a><a name="zh-cn_topic_0000001210206021_p67614394017"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001210206021_p1676154394020"><a name="zh-cn_topic_0000001210206021_p1676154394020"></a><a name="zh-cn_topic_0000001210206021_p1676154394020"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001210206021_p38458271423"><a name="zh-cn_topic_0000001210206021_p38458271423"></a><a name="zh-cn_topic_0000001210206021_p38458271423"></a>是否忽略BOM标记。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var textDecoder = util.TextDecoder("utf-8",{ignoreBOM:true})
    ```


### decode<a name="zh-cn_topic_0000001210206021_section9594134194318"></a>

decode\(input: Uint8Array, options?:\{stream?:false\}\): string

通过输入参数解码后输出对应文本。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table157841181443"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row10784188164412"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p167847814420"><a name="zh-cn_topic_0000001210206021_p167847814420"></a><a name="zh-cn_topic_0000001210206021_p167847814420"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p078418815441"><a name="zh-cn_topic_0000001210206021_p078418815441"></a><a name="zh-cn_topic_0000001210206021_p078418815441"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p14784082449"><a name="zh-cn_topic_0000001210206021_p14784082449"></a><a name="zh-cn_topic_0000001210206021_p14784082449"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p1878468104412"><a name="zh-cn_topic_0000001210206021_p1878468104412"></a><a name="zh-cn_topic_0000001210206021_p1878468104412"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row27851385447"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p2785284442"><a name="zh-cn_topic_0000001210206021_p2785284442"></a><a name="zh-cn_topic_0000001210206021_p2785284442"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p47857813448"><a name="zh-cn_topic_0000001210206021_p47857813448"></a><a name="zh-cn_topic_0000001210206021_p47857813448"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p147859815443"><a name="zh-cn_topic_0000001210206021_p147859815443"></a><a name="zh-cn_topic_0000001210206021_p147859815443"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p2078588194411"><a name="zh-cn_topic_0000001210206021_p2078588194411"></a><a name="zh-cn_topic_0000001210206021_p2078588194411"></a>数字。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001210206021_row187851287441"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p187851487447"><a name="zh-cn_topic_0000001210206021_p187851487447"></a><a name="zh-cn_topic_0000001210206021_p187851487447"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p13785987448"><a name="zh-cn_topic_0000001210206021_p13785987448"></a><a name="zh-cn_topic_0000001210206021_p13785987448"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p1878538154411"><a name="zh-cn_topic_0000001210206021_p1878538154411"></a><a name="zh-cn_topic_0000001210206021_p1878538154411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p127684914432"><a name="zh-cn_topic_0000001210206021_p127684914432"></a><a name="zh-cn_topic_0000001210206021_p127684914432"></a>解码相关选项参数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 2**  options

    <a name="zh-cn_topic_0000001210206021_table395819335512"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row4958133185116"><th class="cellrowborder" valign="top" width="17.549999999999997%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001210206021_p1795813315511"><a name="zh-cn_topic_0000001210206021_p1795813315511"></a><a name="zh-cn_topic_0000001210206021_p1795813315511"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001210206021_p1895883395120"><a name="zh-cn_topic_0000001210206021_p1895883395120"></a><a name="zh-cn_topic_0000001210206021_p1895883395120"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.16%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001210206021_p17958633125116"><a name="zh-cn_topic_0000001210206021_p17958633125116"></a><a name="zh-cn_topic_0000001210206021_p17958633125116"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001210206021_p15958133312518"><a name="zh-cn_topic_0000001210206021_p15958133312518"></a><a name="zh-cn_topic_0000001210206021_p15958133312518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row1958833125117"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001210206021_p1984204213513"><a name="zh-cn_topic_0000001210206021_p1984204213513"></a><a name="zh-cn_topic_0000001210206021_p1984204213513"></a>stream</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001210206021_p11958733115110"><a name="zh-cn_topic_0000001210206021_p11958733115110"></a><a name="zh-cn_topic_0000001210206021_p11958733115110"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001210206021_p1995817337517"><a name="zh-cn_topic_0000001210206021_p1995817337517"></a><a name="zh-cn_topic_0000001210206021_p1995817337517"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001210206021_p3958113385114"><a name="zh-cn_topic_0000001210206021_p3958113385114"></a><a name="zh-cn_topic_0000001210206021_p3958113385114"></a>在随后的decode()调用中是否跟随附加数据。如果以块的形式处理数据，则设置为true；如果处理最后的块或数据未分块，则设置为false。默认为false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table37864874412"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row1778638104418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p1778613834415"><a name="zh-cn_topic_0000001210206021_p1778613834415"></a><a name="zh-cn_topic_0000001210206021_p1778613834415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p6786118124414"><a name="zh-cn_topic_0000001210206021_p6786118124414"></a><a name="zh-cn_topic_0000001210206021_p6786118124414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row678611818445"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p1278638184418"><a name="zh-cn_topic_0000001210206021_p1278638184418"></a><a name="zh-cn_topic_0000001210206021_p1278638184418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p6786118144419"><a name="zh-cn_topic_0000001210206021_p6786118144419"></a><a name="zh-cn_topic_0000001210206021_p6786118144419"></a>解码后的数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var textDecoder = util.TextDecoder("utf-8",{ignoreBOM:true});
    var result = new Uint8Array(6);
    result[0] = 0xEF;
    result[1] = 0xBB;
    result[2] = 0xBF;
    result[3] = 0x61;
    result[4] = 0x62;
    result[5] = 0x63;
    console.log("input num:");
    for(var j= 0; j < 6; j++) {
        console.log(result[j]);
    }
    var retStr = textDecoder.decode( result , {stream:false});
    console.log("retStr = " + retStr);
    ```


## TextEncoder<a name="zh-cn_topic_0000001210206021_section7299123218370"></a>

### 属性<a name="zh-cn_topic_0000001210206021_section46449515265"></a>

<a name="zh-cn_topic_0000001210206021_table16644251192617"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row264545172611"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001210206021_p12645145152618"><a name="zh-cn_topic_0000001210206021_p12645145152618"></a><a name="zh-cn_topic_0000001210206021_p12645145152618"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001210206021_p664635172620"><a name="zh-cn_topic_0000001210206021_p664635172620"></a><a name="zh-cn_topic_0000001210206021_p664635172620"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001210206021_p46461151172619"><a name="zh-cn_topic_0000001210206021_p46461151172619"></a><a name="zh-cn_topic_0000001210206021_p46461151172619"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001210206021_p264695120267"><a name="zh-cn_topic_0000001210206021_p264695120267"></a><a name="zh-cn_topic_0000001210206021_p264695120267"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001210206021_p2646175115265"><a name="zh-cn_topic_0000001210206021_p2646175115265"></a><a name="zh-cn_topic_0000001210206021_p2646175115265"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001210206021_row1664616519264"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001210206021_p9577155632715"><a name="zh-cn_topic_0000001210206021_p9577155632715"></a><a name="zh-cn_topic_0000001210206021_p9577155632715"></a>encoding</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001210206021_p146471519262"><a name="zh-cn_topic_0000001210206021_p146471519262"></a><a name="zh-cn_topic_0000001210206021_p146471519262"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001210206021_p176471051112619"><a name="zh-cn_topic_0000001210206021_p176471051112619"></a><a name="zh-cn_topic_0000001210206021_p176471051112619"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001210206021_p1928801914148"><a name="zh-cn_topic_0000001210206021_p1928801914148"></a><a name="zh-cn_topic_0000001210206021_p1928801914148"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001210206021_p7288893020"><a name="zh-cn_topic_0000001210206021_p7288893020"></a><a name="zh-cn_topic_0000001210206021_p7288893020"></a>编码格式，默认值是utf-8。</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="zh-cn_topic_0000001210206021_section19850195154719"></a>

constructor\(\)

TextEncoder的构造函数。

-   示例：

    ```
    var textEncoder = new  util.TextEncoder()
    ```


### encode<a name="zh-cn_topic_0000001210206021_section16144104844716"></a>

encode\(input?: string\): Uint8Array

通过输入参数编码后输出对应文本。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table240355411539"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row13404135415531"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p1140485425310"><a name="zh-cn_topic_0000001210206021_p1140485425310"></a><a name="zh-cn_topic_0000001210206021_p1140485425310"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p134041954145318"><a name="zh-cn_topic_0000001210206021_p134041954145318"></a><a name="zh-cn_topic_0000001210206021_p134041954145318"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p204041854135312"><a name="zh-cn_topic_0000001210206021_p204041854135312"></a><a name="zh-cn_topic_0000001210206021_p204041854135312"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p144041854175312"><a name="zh-cn_topic_0000001210206021_p144041854175312"></a><a name="zh-cn_topic_0000001210206021_p144041854175312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row1640414544532"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p1840513545531"><a name="zh-cn_topic_0000001210206021_p1840513545531"></a><a name="zh-cn_topic_0000001210206021_p1840513545531"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p84051254195315"><a name="zh-cn_topic_0000001210206021_p84051254195315"></a><a name="zh-cn_topic_0000001210206021_p84051254195315"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p104051454145312"><a name="zh-cn_topic_0000001210206021_p104051454145312"></a><a name="zh-cn_topic_0000001210206021_p104051454145312"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p11405145416535"><a name="zh-cn_topic_0000001210206021_p11405145416535"></a><a name="zh-cn_topic_0000001210206021_p11405145416535"></a>需要编码的格式。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table1040545414534"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row8405115495316"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p9405155418538"><a name="zh-cn_topic_0000001210206021_p9405155418538"></a><a name="zh-cn_topic_0000001210206021_p9405155418538"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p164051954205320"><a name="zh-cn_topic_0000001210206021_p164051954205320"></a><a name="zh-cn_topic_0000001210206021_p164051954205320"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row9406165415538"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p840675415537"><a name="zh-cn_topic_0000001210206021_p840675415537"></a><a name="zh-cn_topic_0000001210206021_p840675415537"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p1640612547535"><a name="zh-cn_topic_0000001210206021_p1640612547535"></a><a name="zh-cn_topic_0000001210206021_p1640612547535"></a>返回编码后的文本。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var textEncoder = new  util.TextEncoder()
    var result = new Uint8Array(buffer);
    result = textEncoder.encode("\uD800¥¥");
    ```


### encodeInto<a name="zh-cn_topic_0000001210206021_section106591864813"></a>

encodeInto\(input: string, dest: Uint8Array,\):\{ read: number; written: number \}

放置生成的UTF-8编码文本。

-   参数：

    <a name="zh-cn_topic_0000001210206021_table19836147194911"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row28361472490"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001210206021_p783647164910"><a name="zh-cn_topic_0000001210206021_p783647164910"></a><a name="zh-cn_topic_0000001210206021_p783647164910"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001210206021_p148361478498"><a name="zh-cn_topic_0000001210206021_p148361478498"></a><a name="zh-cn_topic_0000001210206021_p148361478498"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001210206021_p4836127194916"><a name="zh-cn_topic_0000001210206021_p4836127194916"></a><a name="zh-cn_topic_0000001210206021_p4836127194916"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001210206021_p6837187154914"><a name="zh-cn_topic_0000001210206021_p6837187154914"></a><a name="zh-cn_topic_0000001210206021_p6837187154914"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row383711716494"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p208373714498"><a name="zh-cn_topic_0000001210206021_p208373714498"></a><a name="zh-cn_topic_0000001210206021_p208373714498"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p5837147164919"><a name="zh-cn_topic_0000001210206021_p5837147164919"></a><a name="zh-cn_topic_0000001210206021_p5837147164919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p1837127184919"><a name="zh-cn_topic_0000001210206021_p1837127184919"></a><a name="zh-cn_topic_0000001210206021_p1837127184919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p5837571492"><a name="zh-cn_topic_0000001210206021_p5837571492"></a><a name="zh-cn_topic_0000001210206021_p5837571492"></a>需要编码的格式。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001210206021_row208371178497"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001210206021_p98372719499"><a name="zh-cn_topic_0000001210206021_p98372719499"></a><a name="zh-cn_topic_0000001210206021_p98372719499"></a>dest</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001210206021_p1483715754912"><a name="zh-cn_topic_0000001210206021_p1483715754912"></a><a name="zh-cn_topic_0000001210206021_p1483715754912"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001210206021_p38373712497"><a name="zh-cn_topic_0000001210206021_p38373712497"></a><a name="zh-cn_topic_0000001210206021_p38373712497"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001210206021_p13837107144913"><a name="zh-cn_topic_0000001210206021_p13837107144913"></a><a name="zh-cn_topic_0000001210206021_p13837107144913"></a>Uint8Array对象实例，用于将生成的UTF-8编码文本放入其中</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001210206021_table783787164915"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001210206021_row9837167174916"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001210206021_p11837972492"><a name="zh-cn_topic_0000001210206021_p11837972492"></a><a name="zh-cn_topic_0000001210206021_p11837972492"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001210206021_p1283713716490"><a name="zh-cn_topic_0000001210206021_p1283713716490"></a><a name="zh-cn_topic_0000001210206021_p1283713716490"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001210206021_row1483717194915"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001210206021_p18379717495"><a name="zh-cn_topic_0000001210206021_p18379717495"></a><a name="zh-cn_topic_0000001210206021_p18379717495"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001210206021_p18371071491"><a name="zh-cn_topic_0000001210206021_p18371071491"></a><a name="zh-cn_topic_0000001210206021_p18371071491"></a>返回编码后的文本。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    var that = new util.TextEncoder()
    var buffer = new ArrayBuffer(4)
    this.dest = new Uint8Array(buffer)
    var result = that.encodeInto("abcd", this.dest)
    ```


