# util<a name="EN-US_TOPIC_0000001162859486"></a>

>**NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

This module provides common utility functions, such as  **TextEncoder**  and  **TextDecoder**  for string encoding and decoding,  **RationalNumber**  for rational number operations,  **LruBuffer**  for buffer management,  **Scope**  for range determination,  **Base64**  for Base64 encoding and decoding, and  **Types**  for checks of built-in object types.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import util from '@ohos.util';
```

## Required Permissions<a name="section11257113618419"></a>

None.

## util.printf<a name="section192192415554"></a>

printf\(format: string,  ...args: Object\[\]\): string

Prints the input content in a formatted string.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>format</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18899105910192"><a name="p18899105910192"></a><a name="p18899105910192"></a>Format of the string to print.</p>
    </td>
    </tr>
    <tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13702016205012"><a name="p13702016205012"></a><a name="p13702016205012"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p478592912504"><a name="p478592912504"></a><a name="p478592912504"></a>Object[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14582313152114"><a name="p14582313152114"></a><a name="p14582313152114"></a>Data to format.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table16391145317913"></a>
    <table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p16358176115311"><a name="p16358176115311"></a><a name="p16358176115311"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p107511844112312"><a name="p107511844112312"></a><a name="p107511844112312"></a>String in the specified format.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var res = util.printf("%s", "hello world!");
    console.log(res);
    ```


## util.getErrorString<a name="section858912895313"></a>

getErrorString\(errno: number\): string

Obtains detailed information about a system error code.

-   Parameters

    <a name="table55891528185315"></a>
    <table><thead align="left"><tr id="row115891228145313"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p35901828175317"><a name="p35901828175317"></a><a name="p35901828175317"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p18590152820538"><a name="p18590152820538"></a><a name="p18590152820538"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p95900289534"><a name="p95900289534"></a><a name="p95900289534"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1359016288531"><a name="p1359016288531"></a><a name="p1359016288531"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6590122819538"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p17590428115313"><a name="p17590428115313"></a><a name="p17590428115313"></a>errno</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13405179222"><a name="p13405179222"></a><a name="p13405179222"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p959032865319"><a name="p959032865319"></a><a name="p959032865319"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p95901128125320"><a name="p95901128125320"></a><a name="p95901128125320"></a>Error code generated.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table959218285533"></a>
    <table><thead align="left"><tr id="row259252820539"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p175921928175319"><a name="p175921928175319"></a><a name="p175921928175319"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1759262819538"><a name="p1759262819538"></a><a name="p1759262819538"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15592142812531"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p959252813537"><a name="p959252813537"></a><a name="p959252813537"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p459272810535"><a name="p459272810535"></a><a name="p459272810535"></a>Detailed information about the error code.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var errnum = 10; // 10 is the system error code.
    var result = util.getErrorString(errnum);
    console.log("result = " + result);
    ```


## util.callbackWrapper<a name="section15594104112592"></a>

callbackWrapper\(original: Function\): \(err: Object, value: Object \)=\>void

Calls back an asynchronous function. In the callback, the first parameter indicates the cause of the rejection \(the value is  **null**  if the promise has been resolved\), and the second parameter indicates the resolved value.

-   Parameters

    <a name="table8595841155910"></a>
    <table><thead align="left"><tr id="row45953415598"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p15953414591"><a name="p15953414591"></a><a name="p15953414591"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2596144175918"><a name="p2596144175918"></a><a name="p2596144175918"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p35961341115918"><a name="p35961341115918"></a><a name="p35961341115918"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p105966412596"><a name="p105966412596"></a><a name="p105966412596"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12596124113592"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p19596174135912"><a name="p19596174135912"></a><a name="p19596174135912"></a>original</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p020217118113"><a name="p020217118113"></a><a name="p020217118113"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p2596154118591"><a name="p2596154118591"></a><a name="p2596154118591"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1471526810"><a name="p1471526810"></a><a name="p1471526810"></a>Asynchronous function to process.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table3598104111591"></a>
    <table><thead align="left"><tr id="row16598144112599"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p20598144115597"><a name="p20598144115597"></a><a name="p20598144115597"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p4598114135912"><a name="p4598114135912"></a><a name="p4598114135912"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row059994114593"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p15521135919118"><a name="p15521135919118"></a><a name="p15521135919118"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1759984114595"><a name="p1759984114595"></a><a name="p1759984114595"></a>Callback, in which the first parameter indicates the cause of the rejection (the value is <strong id="b565098921111155"><a name="b565098921111155"></a><a name="b565098921111155"></a>null</strong> if the promise has been resolved) and the second parameter indicates the resolved value.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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


## util.promiseWrapper<a name="section172381917987"></a>

promiseWrapper\(original: \(err: Object, value: Object\) =\> void\): Object

Processes an asynchronous function and returns a promise version.

-   Parameters

    <a name="table1239191711810"></a>
    <table><thead align="left"><tr id="row423919171389"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p823941711816"><a name="p823941711816"></a><a name="p823941711816"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p15240017482"><a name="p15240017482"></a><a name="p15240017482"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p624015171185"><a name="p624015171185"></a><a name="p624015171185"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p22403179814"><a name="p22403179814"></a><a name="p22403179814"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9240141716812"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1124019171984"><a name="p1124019171984"></a><a name="p1124019171984"></a>original</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p32401617886"><a name="p32401617886"></a><a name="p32401617886"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p990643291112"><a name="p990643291112"></a><a name="p990643291112"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Asynchronous function to process.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table17243191712818"></a>
    <table><thead align="left"><tr id="row62431017981"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p11243617785"><a name="p11243617785"></a><a name="p11243617785"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p172431317182"><a name="p172431317182"></a><a name="p172431317182"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1243201714811"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p73929531797"><a name="p73929531797"></a><a name="p73929531797"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p125051140151213"><a name="p125051140151213"></a><a name="p125051140151213"></a>Function in the error-first style (that is, <strong id="b201030558493"><a name="b201030558493"></a><a name="b201030558493"></a>(err, value) =&gt;...</strong> is called as the last parameter) and the promise version.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

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


## TextDecoder<a name="section143808167355"></a>

### Attributes<a name="section18482944113517"></a>

<a name="table20482104463514"></a>
<table><thead align="left"><tr id="row1348214444357"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p184822443351"><a name="p184822443351"></a><a name="p184822443351"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p1648254415353"><a name="p1648254415353"></a><a name="p1648254415353"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p9482124413355"><a name="p9482124413355"></a><a name="p9482124413355"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p3482124493515"><a name="p3482124493515"></a><a name="p3482124493515"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p12482104483513"><a name="p12482104483513"></a><a name="p12482104483513"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p2482444163514"><a name="p2482444163514"></a><a name="p2482444163514"></a>encoding</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p3482124417356"><a name="p3482124417356"></a><a name="p3482124417356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p16483194443514"><a name="p16483194443514"></a><a name="p16483194443514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p64838449351"><a name="p64838449351"></a><a name="p64838449351"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p196691820172118"><a name="p196691820172118"></a><a name="p196691820172118"></a>Encoding format.</p>
<a name="ul18284919122516"></a><a name="ul18284919122516"></a><ul id="ul18284919122516"><li>Supported formats: utf-8, ibm866, iso-8859-2, iso-8859-3, iso-8859-4, iso-8859-5, iso-8859-6, iso-8859-7, iso-8859-8, iso-8859-8-i, iso-8859-10, iso-8859-13, iso-8859-14, iso-8859-15, koi8-r, koi8-u, macintosh, windows-874, windows-1250, windows-1251, windows-1252, windows-1253, windows-1254, windows-1255, windows-1256, windows-1257, windows-1258, x-mac-cyrilli, gbk, gb18030, big5, euc-jp, iso-2022-jp, shift_jis, euc-kr, utf-16be, utf-16le</li></ul>
</td>
</tr>
<tr id="row1483164414352"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p17483184419352"><a name="p17483184419352"></a><a name="p17483184419352"></a>fatal</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p9483184410355"><a name="p9483184410355"></a><a name="p9483184410355"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1348384415359"><a name="p1348384415359"></a><a name="p1348384415359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1448312449355"><a name="p1448312449355"></a><a name="p1448312449355"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p8483124473515"><a name="p8483124473515"></a><a name="p8483124473515"></a>Whether to display fatal errors.</p>
</td>
</tr>
<tr id="row13483164419353"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p4483154463514"><a name="p4483154463514"></a><a name="p4483154463514"></a>ignoreBOM</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p4483174443517"><a name="p4483174443517"></a><a name="p4483174443517"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1483134419353"><a name="p1483134419353"></a><a name="p1483134419353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p648354483510"><a name="p648354483510"></a><a name="p648354483510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p348319442351"><a name="p348319442351"></a><a name="p348319442351"></a>Whether to ignore the byte order marker (BOM). The default value is <strong id="b090644153111"><a name="b090644153111"></a><a name="b090644153111"></a>false</strong>, which indicates that the result contains the BOM.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section6179915133611"></a>

constructor\(encoding?:string, options?:\{ fatal?:boolean;ignoreBOM?:boolean \}\)

A constructor used to create a  **TextDecoder**  object.

-   Parameters

    <a name="table51212237384"></a>
    <table><thead align="left"><tr id="row1512182373816"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p5121112319386"><a name="p5121112319386"></a><a name="p5121112319386"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1712122383810"><a name="p1712122383810"></a><a name="p1712122383810"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p712112373813"><a name="p712112373813"></a><a name="p712112373813"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p71218236389"><a name="p71218236389"></a><a name="p71218236389"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2121923123819"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p112132393816"><a name="p112132393816"></a><a name="p112132393816"></a>encoding</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1212102383818"><a name="p1212102383818"></a><a name="p1212102383818"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6121323143812"><a name="p6121323143812"></a><a name="p6121323143812"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p16121182313387"><a name="p16121182313387"></a><a name="p16121182313387"></a>Encoding format.</p>
    </td>
    </tr>
    <tr id="row512116231383"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p141211823113818"><a name="p141211823113818"></a><a name="p141211823113818"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p81221923163816"><a name="p81221923163816"></a><a name="p81221923163816"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p201229236384"><a name="p201229236384"></a><a name="p201229236384"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p7122142317382"><a name="p7122142317382"></a><a name="p7122142317382"></a>Encoding-related options, which include <strong id="b230458226111155"><a name="b230458226111155"></a><a name="b230458226111155"></a>fatal</strong> and <strong id="b1566649813111155"><a name="b1566649813111155"></a><a name="b1566649813111155"></a>ignoreBOM</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  options

    <a name="table468420114018"></a>
    <table><thead align="left"><tr id="row1768412134017"><th class="cellrowborder" valign="top" width="17.549999999999997%" id="mcps1.2.5.1.1"><p id="p86842124013"><a name="p86842124013"></a><a name="p86842124013"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.2.5.1.2"><p id="p16848194014"><a name="p16848194014"></a><a name="p16848194014"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.16%" id="mcps1.2.5.1.3"><p id="p146848118406"><a name="p146848118406"></a><a name="p146848118406"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="p66848113409"><a name="p66848113409"></a><a name="p66848113409"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row96841013407"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="p126849184010"><a name="p126849184010"></a><a name="p126849184010"></a>fatal</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="p368421104017"><a name="p368421104017"></a><a name="p368421104017"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="p17684818404"><a name="p17684818404"></a><a name="p17684818404"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p9845227114216"><a name="p9845227114216"></a><a name="p9845227114216"></a>Whether to display fatal errors.</p>
    </td>
    </tr>
    <tr id="row13751843114014"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="p11938165615400"><a name="p11938165615400"></a><a name="p11938165615400"></a>ignoreBOM</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="p67614394017"><a name="p67614394017"></a><a name="p67614394017"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="p1676154394020"><a name="p1676154394020"></a><a name="p1676154394020"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p38458271423"><a name="p38458271423"></a><a name="p38458271423"></a>Whether to ignore the BOM.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM:true});
    ```


### decode<a name="section9594134194318"></a>

decode\(input: Unit8Array, options?:\{stream?:false\}\):string

Decodes the input content.

-   Parameters

    <a name="table157841181443"></a>
    <table><thead align="left"><tr id="row10784188164412"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p167847814420"><a name="p167847814420"></a><a name="p167847814420"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p078418815441"><a name="p078418815441"></a><a name="p078418815441"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p14784082449"><a name="p14784082449"></a><a name="p14784082449"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1878468104412"><a name="p1878468104412"></a><a name="p1878468104412"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row27851385447"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2785284442"><a name="p2785284442"></a><a name="p2785284442"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p47857813448"><a name="p47857813448"></a><a name="p47857813448"></a>Unit8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p147859815443"><a name="p147859815443"></a><a name="p147859815443"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2078588194411"><a name="p2078588194411"></a><a name="p2078588194411"></a>Uint8Array to decode.</p>
    </td>
    </tr>
    <tr id="row187851287441"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p187851487447"><a name="p187851487447"></a><a name="p187851487447"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13785987448"><a name="p13785987448"></a><a name="p13785987448"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1878538154411"><a name="p1878538154411"></a><a name="p1878538154411"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p127684914432"><a name="p127684914432"></a><a name="p127684914432"></a>Options related to decoding.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  2**  options

    <a name="table395819335512"></a>
    <table><thead align="left"><tr id="row4958133185116"><th class="cellrowborder" valign="top" width="17.549999999999997%" id="mcps1.2.5.1.1"><p id="p1795813315511"><a name="p1795813315511"></a><a name="p1795813315511"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.2.5.1.2"><p id="p1895883395120"><a name="p1895883395120"></a><a name="p1895883395120"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.16%" id="mcps1.2.5.1.3"><p id="p17958633125116"><a name="p17958633125116"></a><a name="p17958633125116"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="p15958133312518"><a name="p15958133312518"></a><a name="p15958133312518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1958833125117"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.2.5.1.1 "><p id="p1984204213513"><a name="p1984204213513"></a><a name="p1984204213513"></a>stream</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.2.5.1.2 "><p id="p11958733115110"><a name="p11958733115110"></a><a name="p11958733115110"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.2.5.1.3 "><p id="p1995817337517"><a name="p1995817337517"></a><a name="p1995817337517"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p3958113385114"><a name="p3958113385114"></a><a name="p3958113385114"></a>Whether to allow data blocks in subsequent <strong id="b14425141105616"><a name="b14425141105616"></a><a name="b14425141105616"></a>decode()</strong>. If data is processed in blocks, set this parameter to <strong id="b1694314336561"><a name="b1694314336561"></a><a name="b1694314336561"></a>true</strong>. If this is the last data block to process or data is not divided into blocks, set this parameter to <strong id="b163821851577"><a name="b163821851577"></a><a name="b163821851577"></a>false</strong>. The default value is <strong id="b1566293609111155"><a name="b1566293609111155"></a><a name="b1566293609111155"></a>false</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table37864874412"></a>
    <table><thead align="left"><tr id="row1778638104418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1778613834415"><a name="p1778613834415"></a><a name="p1778613834415"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p6786118124414"><a name="p6786118124414"></a><a name="p6786118124414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row678611818445"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1278638184418"><a name="p1278638184418"></a><a name="p1278638184418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p6786118144419"><a name="p6786118144419"></a><a name="p6786118144419"></a>Data decoded.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var textDecoder = new util.TextDecoder("utf-8",{ignoreBOM:true});
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


## TextEncoder<a name="section7299123218370"></a>

### Attributes<a name="section46449515265"></a>

<a name="table16644251192617"></a>
<table><thead align="left"><tr id="row264545172611"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p12645145152618"><a name="p12645145152618"></a><a name="p12645145152618"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p664635172620"><a name="p664635172620"></a><a name="p664635172620"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p46461151172619"><a name="p46461151172619"></a><a name="p46461151172619"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p264695120267"><a name="p264695120267"></a><a name="p264695120267"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p2646175115265"><a name="p2646175115265"></a><a name="p2646175115265"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1664616519264"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p9577155632715"><a name="p9577155632715"></a><a name="p9577155632715"></a>encoding</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p146471519262"><a name="p146471519262"></a><a name="p146471519262"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p176471051112619"><a name="p176471051112619"></a><a name="p176471051112619"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1928801914148"><a name="p1928801914148"></a><a name="p1928801914148"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7288893020"><a name="p7288893020"></a><a name="p7288893020"></a>Encoding format. The default format is <strong id="b582142748111155"><a name="b582142748111155"></a><a name="b582142748111155"></a>utf-8</strong>.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section19850195154719"></a>

constructor\(\)

A constructor used to create a  **TextEncoder**  object.

-   Example

    ```
    var textEncoder = new util.TextEncoder();
    ```


### encode<a name="section16144104844716"></a>

encode\(input?:string\):Uint8Array

Encodes the input content.

-   Parameters

    <a name="table240355411539"></a>
    <table><thead align="left"><tr id="row13404135415531"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1140485425310"><a name="p1140485425310"></a><a name="p1140485425310"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p134041954145318"><a name="p134041954145318"></a><a name="p134041954145318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p204041854135312"><a name="p204041854135312"></a><a name="p204041854135312"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p144041854175312"><a name="p144041854175312"></a><a name="p144041854175312"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1640414544532"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1840513545531"><a name="p1840513545531"></a><a name="p1840513545531"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p84051254195315"><a name="p84051254195315"></a><a name="p84051254195315"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p104051454145312"><a name="p104051454145312"></a><a name="p104051454145312"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p11405145416535"><a name="p11405145416535"></a><a name="p11405145416535"></a>String to encode.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1040545414534"></a>
    <table><thead align="left"><tr id="row8405115495316"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p9405155418538"><a name="p9405155418538"></a><a name="p9405155418538"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p164051954205320"><a name="p164051954205320"></a><a name="p164051954205320"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9406165415538"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p840675415537"><a name="p840675415537"></a><a name="p840675415537"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1640612547535"><a name="p1640612547535"></a><a name="p1640612547535"></a>Encoded text.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var textEncoder = new util.TextEncoder();
    var result = new Uint8Array(buffer);
    result = textEncoder.encode("\uD800¥¥");
    ```


### encodeInto<a name="section106591864813"></a>

encodeInto\(input:string, dest:Uint8Array, \):\{ read:number; written:number \}

Stores the UTF-8 encoded text.

-   Parameters

    <a name="table19836147194911"></a>
    <table><thead align="left"><tr id="row28361472490"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p783647164910"><a name="p783647164910"></a><a name="p783647164910"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p148361478498"><a name="p148361478498"></a><a name="p148361478498"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p4836127194916"><a name="p4836127194916"></a><a name="p4836127194916"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6837187154914"><a name="p6837187154914"></a><a name="p6837187154914"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row383711716494"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p208373714498"><a name="p208373714498"></a><a name="p208373714498"></a>input</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p5837147164919"><a name="p5837147164919"></a><a name="p5837147164919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1837127184919"><a name="p1837127184919"></a><a name="p1837127184919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5837571492"><a name="p5837571492"></a><a name="p5837571492"></a>String to encode.</p>
    </td>
    </tr>
    <tr id="row208371178497"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p98372719499"><a name="p98372719499"></a><a name="p98372719499"></a>dest</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1483715754912"><a name="p1483715754912"></a><a name="p1483715754912"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p38373712497"><a name="p38373712497"></a><a name="p38373712497"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13837107144913"><a name="p13837107144913"></a><a name="p13837107144913"></a>Uint8Array object used to hold the UTF-8 encoded text.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table783787164915"></a>
    <table><thead align="left"><tr id="row9837167174916"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p11837972492"><a name="p11837972492"></a><a name="p11837972492"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1283713716490"><a name="p1283713716490"></a><a name="p1283713716490"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1483717194915"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p18379717495"><a name="p18379717495"></a><a name="p18379717495"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p18371071491"><a name="p18371071491"></a><a name="p18371071491"></a>Encoded text.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.TextEncoder();
    var buffer = new ArrayBuffer(4);
    this.dest = new Uint8Array(buffer);
    var result = that.encodeInto("abcd", this.dest);
    ```


## RationalNumber<sup>8+</sup><a name="section7205192575218"></a>

### constructor<sup>8+</sup><a name="section12888318553"></a>

constructor\(numerator:number,denominator:number\)

A constructor used to create a  **RationalNumber**  object.

-   Parameters

    <a name="table13924191512612"></a>
    <table><thead align="left"><tr id="row16924615182615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p20924415142616"><a name="p20924415142616"></a><a name="p20924415142616"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2924121562618"><a name="p2924121562618"></a><a name="p2924121562618"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1392431542612"><a name="p1392431542612"></a><a name="p1392431542612"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p692581552616"><a name="p692581552616"></a><a name="p692581552616"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8925181518268"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p139252151264"><a name="p139252151264"></a><a name="p139252151264"></a>numerator</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p992511157264"><a name="p992511157264"></a><a name="p992511157264"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p139259152265"><a name="p139259152265"></a><a name="p139259152265"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p12925201582618"><a name="p12925201582618"></a><a name="p12925201582618"></a>Numerator, which is an integer.</p>
    </td>
    </tr>
    <tr id="row5925015102610"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p992581512612"><a name="p992581512612"></a><a name="p992581512612"></a>denominator</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p59250159264"><a name="p59250159264"></a><a name="p59250159264"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p16925181542613"><a name="p16925181542613"></a><a name="p16925181542613"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p149261015152611"><a name="p149261015152611"></a><a name="p149261015152611"></a>Denominator, which is an integer.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    ```


### createRationalFromString<sup>8+</sup><a name="section19091742192215"></a>

static createRationalFromString​\(rationalString:string\):RationalNumber​

Creates a  **RationalNumber**  object using the given string.

-   Parameters

    <a name="table14799118143219"></a>
    <table><thead align="left"><tr id="row147995813217"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p479948173215"><a name="p479948173215"></a><a name="p479948173215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1979918863219"><a name="p1979918863219"></a><a name="p1979918863219"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p198007883210"><a name="p198007883210"></a><a name="p198007883210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p28001083322"><a name="p28001083322"></a><a name="p28001083322"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0800188123213"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p20800208153220"><a name="p20800208153220"></a><a name="p20800208153220"></a>rationalString</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p7800684327"><a name="p7800684327"></a><a name="p7800684327"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1980068153213"><a name="p1980068153213"></a><a name="p1980068153213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p080012813216"><a name="p080012813216"></a><a name="p080012813216"></a>String used to create the <strong id="b27014813510"><a name="b27014813510"></a><a name="b27014813510"></a>RationalNumber</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table880017823210"></a>
    <table><thead align="left"><tr id="row880188103215"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1580148143217"><a name="p1580148143217"></a><a name="p1580148143217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1380188133218"><a name="p1380188133218"></a><a name="p1380188133218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row178011893220"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p2011117019332"><a name="p2011117019332"></a><a name="p2011117019332"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1280110810329"><a name="p1280110810329"></a><a name="p1280110810329"></a><strong id="b208600248513"><a name="b208600248513"></a><a name="b208600248513"></a>RationalNumber</strong> object created.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var rational = rationalNumer.creatRationalFromString("3/4");
    ```


### compareTo<sup>8+</sup><a name="section448184033617"></a>

compareTo​\(another:RationalNumber\):number​

Compares this  **RationalNumber**  object with a given object.

-   Parameters

    <a name="table1848104020361"></a>
    <table><thead align="left"><tr id="row24944083610"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11491408367"><a name="p11491408367"></a><a name="p11491408367"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p10492405366"><a name="p10492405366"></a><a name="p10492405366"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p5501340153610"><a name="p5501340153610"></a><a name="p5501340153610"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p050440153611"><a name="p050440153611"></a><a name="p050440153611"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row175004033614"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p95014409365"><a name="p95014409365"></a><a name="p95014409365"></a>another</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p550144019361"><a name="p550144019361"></a><a name="p550144019361"></a>RationalNumber</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p950164023617"><a name="p950164023617"></a><a name="p950164023617"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1812615318392"><a name="p1812615318392"></a><a name="p1812615318392"></a>Object used to compare with this <strong id="b981716226720"><a name="b981716226720"></a><a name="b981716226720"></a>RationalNumber</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table351440173619"></a>
    <table><thead align="left"><tr id="row85194019364"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p145114033617"><a name="p145114033617"></a><a name="p145114033617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p7515403367"><a name="p7515403367"></a><a name="p7515403367"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row35117408367"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1545301911405"><a name="p1545301911405"></a><a name="p1545301911405"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p5705105094017"><a name="p5705105094017"></a><a name="p5705105094017"></a>Returns <strong id="b1590417591772"><a name="b1590417591772"></a><a name="b1590417591772"></a>0</strong> if the two objects are equal; returns <strong id="b1645363412813"><a name="b1645363412813"></a><a name="b1645363412813"></a>1</strong> if the given object is less than this object; return <strong id="b142220095"><a name="b142220095"></a><a name="b142220095"></a>-1</strong> if the given object is greater than this object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var rational = rationalNumer.creatRationalFromString("3/4");
    var result = rationalNumber.compareTo(rational);
    ```


### valueOf<sup>8+</sup><a name="section4353582461"></a>

valueOf\(\):number

Obtains the value of this  **RationalNumber**  object as an integer or a floating-point number.

-   Return values

    <a name="table6357138194617"></a>
    <table><thead align="left"><tr id="row935819810465"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1135818104620"><a name="p1135818104620"></a><a name="p1135818104620"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1235812816467"><a name="p1235812816467"></a><a name="p1235812816467"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19358483463"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p23583813462"><a name="p23583813462"></a><a name="p23583813462"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p103593854610"><a name="p103593854610"></a><a name="p103593854610"></a>An integer or a floating-point number.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.valueOf();
    ```


### equals<sup>8+</sup><a name="section1933191019519"></a>

equals​\(obj:Object\):boolean

Checks whether this  **RationalNumber**  object equals the given object.

-   Parameters

    <a name="table1893311018512"></a>
    <table><thead align="left"><tr id="row593421055116"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p69347101517"><a name="p69347101517"></a><a name="p69347101517"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1193451025115"><a name="p1193451025115"></a><a name="p1193451025115"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p149341010145120"><a name="p149341010145120"></a><a name="p149341010145120"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p393421005116"><a name="p393421005116"></a><a name="p393421005116"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row39341710115117"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10935151015511"><a name="p10935151015511"></a><a name="p10935151015511"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13935410105118"><a name="p13935410105118"></a><a name="p13935410105118"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19935131012516"><a name="p19935131012516"></a><a name="p19935131012516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14935151075117"><a name="p14935151075117"></a><a name="p14935151075117"></a>Object used to compare with this <strong id="b144653112164"><a name="b144653112164"></a><a name="b144653112164"></a>RationalNumber</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table59350109517"></a>
    <table><thead align="left"><tr id="row1936141014510"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p593661045119"><a name="p593661045119"></a><a name="p593661045119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1293614102518"><a name="p1293614102518"></a><a name="p1293614102518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row139361410165112"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1936111014515"><a name="p1936111014515"></a><a name="p1936111014515"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p39361410105116"><a name="p39361410105116"></a><a name="p39361410105116"></a>Returns <strong id="b1271511818175"><a name="b1271511818175"></a><a name="b1271511818175"></a>true</strong> if the two objects are equal; returns <strong id="b28941376185"><a name="b28941376185"></a><a name="b28941376185"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var rational = rationalNumer.creatRationalFromString("3/4");
    var result = rationalNumber.equals(rational);
    ```


### getCommonDivisor<sup>8+</sup><a name="section14359112375611"></a>

static getCommonDivisor​\(number1:number,number2:number\):number

Obtains the greatest common divisor of the two specified integers.

-   Parameters

    <a name="table1235914233561"></a>
    <table><thead align="left"><tr id="row836014237568"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17360142320562"><a name="p17360142320562"></a><a name="p17360142320562"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1360132385611"><a name="p1360132385611"></a><a name="p1360132385611"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p436092313565"><a name="p436092313565"></a><a name="p436092313565"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p636022314565"><a name="p636022314565"></a><a name="p636022314565"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row236022313569"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12360162311565"><a name="p12360162311565"></a><a name="p12360162311565"></a>number1</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4360152355610"><a name="p4360152355610"></a><a name="p4360152355610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1636182335618"><a name="p1636182335618"></a><a name="p1636182335618"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9361623135610"><a name="p9361623135610"></a><a name="p9361623135610"></a>The first integer used to get the greatest common divisor.</p>
    </td>
    </tr>
    <tr id="row153611123185618"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p93611323205612"><a name="p93611323205612"></a><a name="p93611323205612"></a>number2</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p43615236562"><a name="p43615236562"></a><a name="p43615236562"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1136114232565"><a name="p1136114232565"></a><a name="p1136114232565"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10361162315565"><a name="p10361162315565"></a><a name="p10361162315565"></a>The second integer used to get the greatest common divisor.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1616322335810"></a>
    <table><thead align="left"><tr id="row1616311230583"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1516312235585"><a name="p1516312235585"></a><a name="p1516312235585"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p111633233583"><a name="p111633233583"></a><a name="p111633233583"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row171631523175813"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p816418237588"><a name="p816418237588"></a><a name="p816418237588"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1016442315819"><a name="p1016442315819"></a><a name="p1016442315819"></a>Greatest common divisor obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.getCommonDivisor(4,6);
    ```


### getNumerator<sup>8+</sup><a name="section13527521910"></a>

getNumerator​\(\):number

Obtains the numerator of this  **RationalNumber**  object.

-   Return values

    <a name="table16528321013"></a>
    <table><thead align="left"><tr id="row1752810218113"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p7529112012"><a name="p7529112012"></a><a name="p7529112012"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p205297217111"><a name="p205297217111"></a><a name="p205297217111"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1852982614"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1652918213115"><a name="p1652918213115"></a><a name="p1652918213115"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p3529121715"><a name="p3529121715"></a><a name="p3529121715"></a>Numerator of this <strong id="b259188201611"><a name="b259188201611"></a><a name="b259188201611"></a>RationalNumber</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.getNumerator();
    ```


### getDenominator<sup>8+</sup><a name="section469583819220"></a>

getDenominator​\(\):number

Obtains the denominator of this  **RationalNumber**  object.

-   Return values

    <a name="table869516386215"></a>
    <table><thead align="left"><tr id="row1769610381222"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p269673818213"><a name="p269673818213"></a><a name="p269673818213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p9696203810210"><a name="p9696203810210"></a><a name="p9696203810210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1369653814211"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1769613819218"><a name="p1769613819218"></a><a name="p1769613819218"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1169618386210"><a name="p1169618386210"></a><a name="p1169618386210"></a>Denominator of this <strong id="b311144651616"><a name="b311144651616"></a><a name="b311144651616"></a>RationalNumber</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.getDenominator();
    ```


### isZero<sup>8+</sup><a name="section10651133112516"></a>

isZero​\(\):boolean

Checks whether this  **RationalNumber**  object is  **0**.

-   Return values

    <a name="table126511331859"></a>
    <table><thead align="left"><tr id="row6652103111510"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1965243118519"><a name="p1965243118519"></a><a name="p1965243118519"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p865243117513"><a name="p865243117513"></a><a name="p865243117513"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row156521531457"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p14765102316719"><a name="p14765102316719"></a><a name="p14765102316719"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1765218311952"><a name="p1765218311952"></a><a name="p1765218311952"></a>Returns <strong id="b77906207175"><a name="b77906207175"></a><a name="b77906207175"></a>true</strong> if the value of this <strong id="b05355312171"><a name="b05355312171"></a><a name="b05355312171"></a>RationalNumber</strong> object is <strong id="b96871946185"><a name="b96871946185"></a><a name="b96871946185"></a>0</strong>; returns <strong id="b73181720201811"><a name="b73181720201811"></a><a name="b73181720201811"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.isZero();
    ```


### isNaN<sup>8+</sup><a name="section7585819812"></a>

isNaN​\(\):boolean

Checks whether this  **RationalNumber**  object is a Not a Number \(NaN\).

-   Return values

    <a name="table2591880812"></a>
    <table><thead align="left"><tr id="row165988781"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p95911815815"><a name="p95911815815"></a><a name="p95911815815"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p105919810819"><a name="p105919810819"></a><a name="p105919810819"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14601882084"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p060108788"><a name="p060108788"></a><a name="p060108788"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1358313581988"><a name="p1358313581988"></a><a name="p1358313581988"></a>Returns <strong id="b64577814266"><a name="b64577814266"></a><a name="b64577814266"></a>true</strong> if this <strong id="b115819312715"><a name="b115819312715"></a><a name="b115819312715"></a>RationalNumber</strong> object is a NaN (the denominator and numerator are both <strong id="b180810195264"><a name="b180810195264"></a><a name="b180810195264"></a>0</strong>); returns <strong id="b449654362617"><a name="b449654362617"></a><a name="b449654362617"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.isNaN();
    ```


### isFinite<sup>8+</sup><a name="section5914301597"></a>

isFinite​\(\):boolean

Checks whether this  **RationalNumber**  object represents a finite value.

-   Return values

    <a name="table0105305916"></a>
    <table><thead align="left"><tr id="row121083018918"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1110173011920"><a name="p1110173011920"></a><a name="p1110173011920"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p91119300916"><a name="p91119300916"></a><a name="p91119300916"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13119303913"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p10111930192"><a name="p10111930192"></a><a name="p10111930192"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p14921538131019"><a name="p14921538131019"></a><a name="p14921538131019"></a>Returns <strong id="b157945212717"><a name="b157945212717"></a><a name="b157945212717"></a>true</strong> if this <strong id="b730011315551"><a name="b730011315551"></a><a name="b730011315551"></a>RationalNumber</strong> object represents a finite value (the denominator is not <strong id="b1791952182712"><a name="b1791952182712"></a><a name="b1791952182712"></a>0</strong>); returns <strong id="b97917527272"><a name="b97917527272"></a><a name="b97917527272"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.isFinite();
    ```


### toString<sup>8+</sup><a name="section6870414111110"></a>

toString​\(\):string

Obtains the string representation of this  **RationalNumber**  object.

-   Return values

    <a name="table10870171416113"></a>
    <table><thead align="left"><tr id="row148711214131119"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p2871191410114"><a name="p2871191410114"></a><a name="p2871191410114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p10871171461120"><a name="p10871171461120"></a><a name="p10871171461120"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1087101451119"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1787121441111"><a name="p1787121441111"></a><a name="p1787121441111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p78721714171116"><a name="p78721714171116"></a><a name="p78721714171116"></a>Returns <strong id="b205211759320"><a name="b205211759320"></a><a name="b205211759320"></a>NaN</strong> if the numerator and denominator of this object are both <strong id="b4426123014323"><a name="b4426123014323"></a><a name="b4426123014323"></a>0</strong>; returns a string in Numerator/Denominator format otherwise, for example, <strong id="b325892210337"><a name="b325892210337"></a><a name="b325892210337"></a>3/5</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var rationalNumber = new util.RationalNumber(1,2);
    var result = rationalNumber.toString();
    ```


## LruBuffer<sup>8+</sup><a name="section5880354101018"></a>

### Attributes<a name="section15126114115156"></a>

<a name="table11454105725410"></a>
<table><thead align="left"><tr id="row7455457115414"><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.6.1.1"><p id="p84551257175410"><a name="p84551257175410"></a><a name="p84551257175410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.16%" id="mcps1.1.6.1.2"><p id="p134557578549"><a name="p134557578549"></a><a name="p134557578549"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.39%" id="mcps1.1.6.1.3"><p id="p34551957175411"><a name="p34551957175411"></a><a name="p34551957175411"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.6.1.4"><p id="p2045510572545"><a name="p2045510572545"></a><a name="p2045510572545"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="47.94%" id="mcps1.1.6.1.5"><p id="p145575714544"><a name="p145575714544"></a><a name="p145575714544"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16455135745414"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p8665161117164"><a name="p8665161117164"></a><a name="p8665161117164"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p15664111181617"><a name="p15664111181617"></a><a name="p15664111181617"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p186641011121617"><a name="p186641011121617"></a><a name="p186641011121617"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p344021322114"><a name="p344021322114"></a><a name="p344021322114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p16662811171617"><a name="p16662811171617"></a><a name="p16662811171617"></a>Total number of values in this buffer.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.put(1,8);
    var result = pro.length;
    ```


### constructor<sup>8+</sup><a name="section152345274514"></a>

constructor\(capacity?:number\)

A constructor used to create an  **LruBuffer**  instance. The default capacity of the buffer is 64.

-   Parameters

    <a name="table139762444467"></a>
    <table><thead align="left"><tr id="row1097713449468"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p89771644194619"><a name="p89771644194619"></a><a name="p89771644194619"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p697711447461"><a name="p697711447461"></a><a name="p697711447461"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p0977444134614"><a name="p0977444134614"></a><a name="p0977444134614"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1797717442466"><a name="p1797717442466"></a><a name="p1797717442466"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row497764454611"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1397719447467"><a name="p1397719447467"></a><a name="p1397719447467"></a>capacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p179771644174619"><a name="p179771644174619"></a><a name="p179771644174619"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10977184414467"><a name="p10977184414467"></a><a name="p10977184414467"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15977344134616"><a name="p15977344134616"></a><a name="p15977344134616"></a>Capacity of the <strong id="b123804214362"><a name="b123804214362"></a><a name="b123804214362"></a>LruBuffer</strong> to create.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var lrubuffer= new util.LruBuffer();
    ```


### updateCapacity<sup>8+</sup><a name="section1684113399119"></a>

updateCapacity\(newCapacity:number\):void

Changes the  **LruBuffer**  capacity. If the new capacity is less than or equal to  **0**, an exception will be thrown.

-   Parameters

    <a name="table584423951119"></a>
    <table><thead align="left"><tr id="row3844239171114"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7844153961115"><a name="p7844153961115"></a><a name="p7844153961115"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1184413397114"><a name="p1184413397114"></a><a name="p1184413397114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p884511398116"><a name="p884511398116"></a><a name="p884511398116"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1284519393111"><a name="p1284519393111"></a><a name="p1284519393111"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1845839141110"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p28451139161119"><a name="p28451139161119"></a><a name="p28451139161119"></a>newCapacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p78456398116"><a name="p78456398116"></a><a name="p78456398116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p68453396111"><a name="p68453396111"></a><a name="p68453396111"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p871384521216"><a name="p871384521216"></a><a name="p871384521216"></a>New capacity of the buffer.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var pro = new util.LruBuffer();
    var result = pro.updateCapacity(100);
    ```


### toString<sup>8+</sup><a name="section182715710325"></a>

toString\(\):string

Obtains the string representation of this  **LruBuffer**  object.

-   Return values

    <a name="table068116817114"></a>
    <table><thead align="left"><tr id="row2068258191113"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p36823816110"><a name="p36823816110"></a><a name="p36823816110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p168248181112"><a name="p168248181112"></a><a name="p168248181112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row56821684111"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p18682148141111"><a name="p18682148141111"></a><a name="p18682148141111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p17682982114"><a name="p17682982114"></a><a name="p17682982114"></a>String representation of this object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.get(2);
    pro.remove(20);
    var result = pro.toString();
    ```


### getCapacity<sup>8+</sup><a name="section1392420763519"></a>

getCapacity\(\):number

Obtains the capacity of this buffer.

-   Return values

    <a name="table1633115261213"></a>
    <table><thead align="left"><tr id="row136332522129"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p126331252171215"><a name="p126331252171215"></a><a name="p126331252171215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p66331952181216"><a name="p66331952181216"></a><a name="p66331952181216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1263455261214"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p16634552151215"><a name="p16634552151215"></a><a name="p16634552151215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1737710103139"><a name="p1737710103139"></a><a name="p1737710103139"></a>Capacity of this buffer.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    var result = pro.getCapacity();
    ```


### clear<sup>8+</sup><a name="section72485103611"></a>

clear\(\):void

Clears key-value pairs from this buffer. The  **afterRemoval\(\)**  method will be called to perform subsequent operations.

-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.size();
    pro.clear();
    ```


### getCreateCount<sup>8+</sup><a name="section1153310555365"></a>

getCreateCount\(\):number

Obtains the number of return values for  **createDefault\(\)**.

-   Return values

    <a name="table20126851141310"></a>
    <table><thead align="left"><tr id="row11261051201318"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p18126651191318"><a name="p18126651191318"></a><a name="p18126651191318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p141271651131313"><a name="p141271651131313"></a><a name="p141271651131313"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row141291251141311"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p5129751181314"><a name="p5129751181314"></a><a name="p5129751181314"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p17549162219178"><a name="p17549162219178"></a><a name="p17549162219178"></a>Number of return values for <strong id="b896648145213"><a name="b896648145213"></a><a name="b896648145213"></a>createDefault()</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(1,8);
    var result = pro.getCreateCount();
    ```


### getMissCount<sup>8+</sup><a name="section11341014203812"></a>

getMissCount\(\):number

Obtains the number of times that the queried values are mismatched.

-   Return values

    <a name="table2061511112144"></a>
    <table><thead align="left"><tr id="row166151216143"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p176156112145"><a name="p176156112145"></a><a name="p176156112145"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1161519111141"><a name="p1161519111141"></a><a name="p1161519111141"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12615161161415"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1744191718155"><a name="p1744191718155"></a><a name="p1744191718155"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p361641101418"><a name="p361641101418"></a><a name="p361641101418"></a>Number of times that the queried values are mismatched.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.get(2)
    var result = pro.getMissCount();
    ```


### getRemovalCount<sup>8+</sup><a name="section1632610296396"></a>

getRemovalCount\(\):number

Obtains the number of removals from this buffer.

-   Return values

    <a name="table95524941413"></a>
    <table><thead align="left"><tr id="row255259131412"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p55528911417"><a name="p55528911417"></a><a name="p55528911417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p205523961419"><a name="p205523961419"></a><a name="p205523961419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row155531894144"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1997651911516"><a name="p1997651911516"></a><a name="p1997651911516"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p16553169151413"><a name="p16553169151413"></a><a name="p16553169151413"></a>Number of removals from the buffer.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.updateCapacity(2);
    pro.put(50,22);
    var result = pro.getRemovalCount();
    ```


### getMatchCount<sup>8+</sup><a name="section1649318379408"></a>

getMatchCount\(\):number

Obtains the number of times that the queried values are matched.

-   Return values

    <a name="table68151213145"></a>
    <table><thead align="left"><tr id="row781512101411"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1596123146"><a name="p1596123146"></a><a name="p1596123146"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1491127144"><a name="p1491127144"></a><a name="p1491127144"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1291312171413"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p3262152221517"><a name="p3262152221517"></a><a name="p3262152221517"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1015325317160"><a name="p1015325317160"></a><a name="p1015325317160"></a>Number of times that the queried values are matched.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.get(2);
    var result = pro.getMatchCount();
    ```


### getPutCount<sup>8+</sup><a name="section6811115591516"></a>

getPutCount\(\):number

Obtains the number of additions to this buffer.

-   Return values

    <a name="table12811135551516"></a>
    <table><thead align="left"><tr id="row881215581519"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1581275591515"><a name="p1581275591515"></a><a name="p1581275591515"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p18812455121517"><a name="p18812455121517"></a><a name="p18812455121517"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18812105518155"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p38121955191516"><a name="p38121955191516"></a><a name="p38121955191516"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p19213124961618"><a name="p19213124961618"></a><a name="p19213124961618"></a>Number of additions to the buffer.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.getPutCount();
    ```


### isEmpty<sup>8+</sup><a name="section1373154834313"></a>

isEmpty\(\):boolean

Checks whether this buffer is empty.

-   Return values

    <a name="table1267531461415"></a>
    <table><thead align="left"><tr id="row1567561431418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p196751146141"><a name="p196751146141"></a><a name="p196751146141"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p86752148141"><a name="p86752148141"></a><a name="p86752148141"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167515149145"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p166761714101413"><a name="p166761714101413"></a><a name="p166761714101413"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p96761914101417"><a name="p96761914101417"></a><a name="p96761914101417"></a>Returns <strong id="b187453121051"><a name="b187453121051"></a><a name="b187453121051"></a>true</strong> if the buffer does not contain any value.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.isEmpty();
    ```


### get<sup>8+</sup><a name="section16841953135318"></a>

get\(key:K\):V | undefined

Obtains the value of the specified key.

-   Parameters

    <a name="table154841613133610"></a>
    <table><thead align="left"><tr id="row54841613173611"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p84853137369"><a name="p84853137369"></a><a name="p84853137369"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p34850138364"><a name="p34850138364"></a><a name="p34850138364"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1648520139368"><a name="p1648520139368"></a><a name="p1648520139368"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1948591315363"><a name="p1948591315363"></a><a name="p1948591315363"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0485713203615"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p048792912464"><a name="p048792912464"></a><a name="p048792912464"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1148611138366"><a name="p1148611138366"></a><a name="p1148611138366"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p164866132367"><a name="p164866132367"></a><a name="p164866132367"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8323171315819"><a name="p8323171315819"></a><a name="p8323171315819"></a>Key based on which the value is queried.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table048417176145"></a>
    <table><thead align="left"><tr id="row748491719143"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1548411174141"><a name="p1548411174141"></a><a name="p1548411174141"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p14485111791418"><a name="p14485111791418"></a><a name="p14485111791418"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1048501751411"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p10485317111416"><a name="p10485317111416"></a><a name="p10485317111416"></a>V | undefind</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p5485141717145"><a name="p5485141717145"></a><a name="p5485141717145"></a>Returns the value of the key if a match is found in the buffer; returns <strong id="b6416133412117"><a name="b6416133412117"></a><a name="b6416133412117"></a>undefined</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result  = pro.get(2);
    ```


### put<sup>8+</sup><a name="section1410374485420"></a>

put\(key:K,value:V\):V

Adds a key-value pair to this buffer.

-   Parameters

    <a name="table1364231113618"></a>
    <table><thead align="left"><tr id="row173641031103612"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p12364163123611"><a name="p12364163123611"></a><a name="p12364163123611"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p19364731173615"><a name="p19364731173615"></a><a name="p19364731173615"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1636453120369"><a name="p1636453120369"></a><a name="p1636453120369"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11364163120361"><a name="p11364163120361"></a><a name="p11364163120361"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row936413117365"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p133651731163610"><a name="p133651731163610"></a><a name="p133651731163610"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p43657314367"><a name="p43657314367"></a><a name="p43657314367"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1636510311369"><a name="p1636510311369"></a><a name="p1636510311369"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p3365431113610"><a name="p3365431113610"></a><a name="p3365431113610"></a>Key of the key-value pair to add.</p>
    </td>
    </tr>
    <tr id="row436518317365"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6365103120369"><a name="p6365103120369"></a><a name="p6365103120369"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p183651431193612"><a name="p183651431193612"></a><a name="p183651431193612"></a>V</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1836593119363"><a name="p1836593119363"></a><a name="p1836593119363"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p195537519506"><a name="p195537519506"></a><a name="p195537519506"></a>Value of the key-value pair to add.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table5591142011410"></a>
    <table><thead align="left"><tr id="row8592102011418"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p6592152017142"><a name="p6592152017142"></a><a name="p6592152017142"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p15921320171418"><a name="p15921320171418"></a><a name="p15921320171418"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9592320181419"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1859292014146"><a name="p1859292014146"></a><a name="p1859292014146"></a>V</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1559292018147"><a name="p1559292018147"></a><a name="p1559292018147"></a>Returns the existing value if the key already exists; returns the value added otherwise. If the key or value is null, an exception will be thrown. </p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    var result = pro.put(2,10);
    ```


### values<sup>8+</sup><a name="section166951848165719"></a>

values\(\):V\[\]

Obtains all values in this buffer, listed from the most to the least recently accessed.

-   Return values

    <a name="table7977112341418"></a>
    <table><thead align="left"><tr id="row697722317146"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p14977423201416"><a name="p14977423201416"></a><a name="p14977423201416"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p6977182391415"><a name="p6977182391415"></a><a name="p6977182391415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row189771123191413"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p169771123141413"><a name="p169771123141413"></a><a name="p169771123141413"></a>V []</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1997732341414"><a name="p1997732341414"></a><a name="p1997732341414"></a>All values in the buffer, listed from the most to the least recently accessed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    pro.put(2,"anhu");
    pro.put("afaf","grfb");
    var result = pro.values();
    ```


### keys<sup>8+</sup><a name="section166517232592"></a>

keys\(\):K\[\]

Obtains all keys in this buffer, listed from the most to the least recently accessed.

-   Return values

    <a name="table9108142731414"></a>
    <table><thead align="left"><tr id="row11081279140"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1110802791413"><a name="p1110802791413"></a><a name="p1110802791413"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p31081727101414"><a name="p31081727101414"></a><a name="p31081727101414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1210852716144"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p310872781418"><a name="p310872781418"></a><a name="p310872781418"></a>K []</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p410815275147"><a name="p410815275147"></a><a name="p410815275147"></a>All keys in the buffer, listed from the most to the least recently accessed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.keys();
    ```


### remove<sup>8+</sup><a name="section25597191303"></a>

remove\(key:K\):V | undefined

Deletes the specified key and its value from this buffer.

-   Parameters

    <a name="table2342913927"></a>
    <table><thead align="left"><tr id="row73439135219"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19343101315215"><a name="p19343101315215"></a><a name="p19343101315215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p10343013222"><a name="p10343013222"></a><a name="p10343013222"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15343171319217"><a name="p15343171319217"></a><a name="p15343171319217"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1934314138219"><a name="p1934314138219"></a><a name="p1934314138219"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row33431213524"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p93430132214"><a name="p93430132214"></a><a name="p93430132214"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1934318131725"><a name="p1934318131725"></a><a name="p1934318131725"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13343191313217"><a name="p13343191313217"></a><a name="p13343191313217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p143507271521"><a name="p143507271521"></a><a name="p143507271521"></a>Key to delete.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table17392153614147"></a>
    <table><thead align="left"><tr id="row15392183612149"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1739253691411"><a name="p1739253691411"></a><a name="p1739253691411"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p14392336141416"><a name="p14392336141416"></a><a name="p14392336141416"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183926365142"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p618194461915"><a name="p618194461915"></a><a name="p618194461915"></a>V | undefind</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p16392183619142"><a name="p16392183619142"></a><a name="p16392183619142"></a>Returns an <strong id="b16263125114014"><a name="b16263125114014"></a><a name="b16263125114014"></a>Optional</strong> object containing the deleted key-value pair if the key exists in the buffer; returns an empty <strong id="b19134168901"><a name="b19134168901"></a><a name="b19134168901"></a>Optional</strong> object otherwise. If the key is null, an exception will be thrown.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.remove(20);
    ```


### afterRemoval<sup>8+</sup><a name="section819104711119"></a>

afterRemoval\(isEvict:boolean,key:K,value:V,newValue:V\):void

Performs subsequent operations after a value is deleted.

-   Parameters

    <a name="table1953311311452"></a>
    <table><thead align="left"><tr id="row195334314516"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p15533123117517"><a name="p15533123117517"></a><a name="p15533123117517"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p25331311959"><a name="p25331311959"></a><a name="p25331311959"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p165336311658"><a name="p165336311658"></a><a name="p165336311658"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p35334317513"><a name="p35334317513"></a><a name="p35334317513"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row45331531559"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15671316614"><a name="p15671316614"></a><a name="p15671316614"></a>isEvict</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4830192818611"><a name="p4830192818611"></a><a name="p4830192818611"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p155331931459"><a name="p155331931459"></a><a name="p155331931459"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p185817183715"><a name="p185817183715"></a><a name="p185817183715"></a>Whether the buffer capacity is insufficient. If the value is <strong id="b156762037114316"><a name="b156762037114316"></a><a name="b156762037114316"></a>true</strong>, this method is called due to insufficient capacity.</p>
    </td>
    </tr>
    <tr id="row179265423515"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1092615427516"><a name="p1092615427516"></a><a name="p1092615427516"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p169261442950"><a name="p169261442950"></a><a name="p169261442950"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1692619428513"><a name="p1692619428513"></a><a name="p1692619428513"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p692614421353"><a name="p692614421353"></a><a name="p692614421353"></a>Key deleted.</p>
    </td>
    </tr>
    <tr id="row77205489518"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7720148559"><a name="p7720148559"></a><a name="p7720148559"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1672011481654"><a name="p1672011481654"></a><a name="p1672011481654"></a>V</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1572017481252"><a name="p1572017481252"></a><a name="p1572017481252"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p072024819516"><a name="p072024819516"></a><a name="p072024819516"></a>Value deleted.</p>
    </td>
    </tr>
    <tr id="row7408053750"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1940813531513"><a name="p1940813531513"></a><a name="p1940813531513"></a>newValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p84081253251"><a name="p84081253251"></a><a name="p84081253251"></a>V</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p440855314519"><a name="p440855314519"></a><a name="p440855314519"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p184081353453"><a name="p184081353453"></a><a name="p184081353453"></a>New value for the key if the <strong id="b7628339194617"><a name="b7628339194617"></a><a name="b7628339194617"></a>put()</strong> method is called and the key to be added already exists. In other cases, this parameter is left blank.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arr = [];
    class ChildLruBuffer extends util.LruBuffer
    {
    	constructor()
    	{
    		super();
    	}
    	static getInstance()
    	{
    		if(this.instance ==  null)
    		{
    			this.instance = new ChildLruBuffer();
    		}
    		return this.instance;  
    	}
    	afterRemoval(isEvict, key, value, newValue)
    	{
    		if (isEvict === false)
    		{
    			arr = [key, value, newValue];
    		}
    	}
    }
    ChildLruBuffer.getInstance().afterRemoval(false,10,30,null);
    ```


### contains<sup>8+</sup><a name="section798151316317"></a>

contains\(key:K\):boolean

Checks whether this buffer contains the specified key.

-   Parameters

    <a name="table13400771888"></a>
    <table><thead align="left"><tr id="row1940087286"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p174008714819"><a name="p174008714819"></a><a name="p174008714819"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p24001771083"><a name="p24001771083"></a><a name="p24001771083"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p174001171785"><a name="p174001171785"></a><a name="p174001171785"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p24001671481"><a name="p24001671481"></a><a name="p24001671481"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row240013710812"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1640016711817"><a name="p1640016711817"></a><a name="p1640016711817"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p840019719814"><a name="p840019719814"></a><a name="p840019719814"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3401272811"><a name="p3401272811"></a><a name="p3401272811"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p16904135218815"><a name="p16904135218815"></a><a name="p16904135218815"></a>Key to check.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table13606134314143"></a>
    <table><thead align="left"><tr id="row26063437147"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p9606144319143"><a name="p9606144319143"></a><a name="p9606144319143"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p36061043161416"><a name="p36061043161416"></a><a name="p36061043161416"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1860644313142"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1660618434142"><a name="p1660618434142"></a><a name="p1660618434142"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p160614435145"><a name="p160614435145"></a><a name="p160614435145"></a>Returns <strong id="b185664441693"><a name="b185664441693"></a><a name="b185664441693"></a>true</strong> if the buffer contains the specified key; returns <strong id="b586815017107"><a name="b586815017107"></a><a name="b586815017107"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.contains(20);
    ```


### createDefault<sup>8+</sup><a name="section429772220411"></a>

createDefault\(key:K\):V

Creates a value if the value of the specified key is not available.

-   Parameters

    <a name="table791794220912"></a>
    <table><thead align="left"><tr id="row1091811424913"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p6918174219910"><a name="p6918174219910"></a><a name="p6918174219910"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.719999999999999%" id="mcps1.1.5.1.2"><p id="p109182424913"><a name="p109182424913"></a><a name="p109182424913"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.5.1.3"><p id="p1191818421892"><a name="p1191818421892"></a><a name="p1191818421892"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11918342595"><a name="p11918342595"></a><a name="p11918342595"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row39187424910"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p391816428919"><a name="p391816428919"></a><a name="p391816428919"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.719999999999999%" headers="mcps1.1.5.1.2 "><p id="p12918174211912"><a name="p12918174211912"></a><a name="p12918174211912"></a>K</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.5.1.3 "><p id="p10918204210918"><a name="p10918204210918"></a><a name="p10918204210918"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5464174171017"><a name="p5464174171017"></a><a name="p5464174171017"></a>Key of which the value is missing.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table1383615450144"></a>
    <table><thead align="left"><tr id="row1883618459143"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p138371145141412"><a name="p138371145141412"></a><a name="p138371145141412"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p283734581414"><a name="p283734581414"></a><a name="p283734581414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17837174514143"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p12837945191410"><a name="p12837945191410"></a><a name="p12837945191410"></a>V</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p7837154531413"><a name="p7837154531413"></a><a name="p7837154531413"></a>Value of the key.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    var result = pro.createDefault(50);
    ```


### entries<sup>8+</sup><a name="section1198814119615"></a>

entries\(\):IterableIterator<\[K,V\]\>

Obtains a new iterator object that contains all key-value pairs in this object.

-   Return values

    <a name="table095316474142"></a>
    <table><thead align="left"><tr id="row9953124715142"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p19953144717140"><a name="p19953144717140"></a><a name="p19953144717140"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p19541447101415"><a name="p19541447101415"></a><a name="p19541447101415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4954447161420"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1695444712147"><a name="p1695444712147"></a><a name="p1695444712147"></a>[K, V]</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p167720309383"><a name="p167720309383"></a><a name="p167720309383"></a>Returns an iterable array.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro.entries();
    ```


### \[Symbol.iterator\]<sup>8+</sup><a name="section86413191972"></a>

\[Symbol.iterator\]\(\): IterableIterator<\[K, V\]\>

Obtains a two-dimensional array in key-value pairs.

-   Return values

    <a name="table13352450151419"></a>
    <table><thead align="left"><tr id="row1735214509144"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p18352105013145"><a name="p18352105013145"></a><a name="p18352105013145"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p63533501143"><a name="p63533501143"></a><a name="p63533501143"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8353115041417"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p6353650111415"><a name="p6353650111415"></a><a name="p6353650111415"></a>[K, V]</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p678913913220"><a name="p678913913220"></a><a name="p678913913220"></a>A two-dimensional array in key-value pairs.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var pro = new util.LruBuffer();
    pro.put(2,10);
    var result = pro[symbol.iterator]();
    ```


## Scope<sup>8+</sup><a name="section14134189623"></a>

### ScopeType<sup>8+</sup><a name="section876116244471"></a>

Defines the type of values in a  **Scope**  object. The value type can be  **ScopeComparable**  or  **number**.

The values of the  **ScopeComparable**  type are used to implement the  **compareTo**  method. Therefore, ensure that the input parameters are comparable.

```
interface ScopeComparable{
    compareTo(other:ScopeComparable):boolean;
}
type ScopeType = ScopeComparable | number;
```

Create a class to implement the  **compareTo**  method. In the subsequent sample code,  **Temperature**  is used as an example of the  [ScopeType](#section876116244471)  object.

Example

```
class Temperature{
    constructor(value){
       this._temp = value;
    }
    comapreTo(value){
       return this._temp >= value.getTemp();
    }
    getTemp(){
       return this._temp;
    }
    toString(){
       return this._temp.toString();
    }
}
```

### constructor<sup>8+</sup><a name="section12612142153016"></a>

constructor\(lowerObj:ScopeType,upperObje:ScopeType\)

A constructor used to create a  **Scope**  object with the specified upper and lower limits.

-   Parameters

    <a name="table37241513145916"></a>
    <table><thead align="left"><tr id="row7724113115912"><th class="cellrowborder" valign="top" width="14.799999999999999%" id="mcps1.1.5.1.1"><p id="p1072412134599"><a name="p1072412134599"></a><a name="p1072412134599"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.75%" id="mcps1.1.5.1.2"><p id="p2724313115914"><a name="p2724313115914"></a><a name="p2724313115914"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p572510138596"><a name="p572510138596"></a><a name="p572510138596"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1872551315918"><a name="p1872551315918"></a><a name="p1872551315918"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row872571365910"><td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.5.1.1 "><p id="p11237172518542"><a name="p11237172518542"></a><a name="p11237172518542"></a>lowerObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.75%" headers="mcps1.1.5.1.2 "><p id="p2237132575411"><a name="p2237132575411"></a><a name="p2237132575411"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1923732516546"><a name="p1923732516546"></a><a name="p1923732516546"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14238825205411"><a name="p14238825205411"></a><a name="p14238825205411"></a>Lower limit of the <strong id="b461952123016"><a name="b461952123016"></a><a name="b461952123016"></a>Scope</strong> object.</p>
    </td>
    </tr>
    <tr id="row1484447125414"><td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.5.1.1 "><p id="p1047874719543"><a name="p1047874719543"></a><a name="p1047874719543"></a>upperObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.75%" headers="mcps1.1.5.1.2 "><p id="p14478194765415"><a name="p14478194765415"></a><a name="p14478194765415"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p847884795412"><a name="p847884795412"></a><a name="p847884795412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1647814716544"><a name="p1647814716544"></a><a name="p1647814716544"></a>Upper limit of the <strong id="b62109238307"><a name="b62109238307"></a><a name="b62109238307"></a>Scope</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    ```


### toString<sup>8+</sup><a name="section695413375319"></a>

toString\(\):string

Obtains a string representation that contains this  **Scope**.

-   Return values

    <a name="table1372714138599"></a>
    <table><thead align="left"><tr id="row77278135596"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p4727121311593"><a name="p4727121311593"></a><a name="p4727121311593"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p177271113125911"><a name="p177271113125911"></a><a name="p177271113125911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row972715134592"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1572711137590"><a name="p1572711137590"></a><a name="p1572711137590"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p9727313145919"><a name="p9727313145919"></a><a name="p9727313145919"></a>String representation containing the <strong id="b1623012216361"><a name="b1623012216361"></a><a name="b1623012216361"></a>Scope</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.toString();
    ```


### intersect<sup>8+</sup><a name="section415504173214"></a>

intersect\(range:Scope\):Scope

Obtains the intersection of this  **Scope**  and the given  **Scope**.

-   Parameters

    <a name="table2158164676"></a>
    <table><thead align="left"><tr id="row17158541470"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p201591344710"><a name="p201591344710"></a><a name="p201591344710"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p215919418710"><a name="p215919418710"></a><a name="p215919418710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13159134175"><a name="p13159134175"></a><a name="p13159134175"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p191591449719"><a name="p191591449719"></a><a name="p191591449719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1159141574"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1915934679"><a name="p1915934679"></a><a name="p1915934679"></a>range</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p3159194576"><a name="p3159194576"></a><a name="p3159194576"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p18159941179"><a name="p18159941179"></a><a name="p18159941179"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1815914476"><a name="p1815914476"></a><a name="p1815914476"></a><strong id="b1621713384316"><a name="b1621713384316"></a><a name="b1621713384316"></a>Scope</strong> specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table11730813115919"></a>
    <table><thead align="left"><tr id="row15730813145917"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1673021311595"><a name="p1673021311595"></a><a name="p1673021311595"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1973019137596"><a name="p1973019137596"></a><a name="p1973019137596"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3730213195913"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1073071345917"><a name="p1073071345917"></a><a name="p1073071345917"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p137302013115920"><a name="p137302013115920"></a><a name="p137302013115920"></a>Intersection of this <strong id="b1394311515419"><a name="b1394311515419"></a><a name="b1394311515419"></a>Scope</strong> and the given <strong id="b10161586318"><a name="b10161586318"></a><a name="b10161586318"></a>Scope</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    var tempMiDF = new Temperature(35);
    var tempMidS = new Temperature(39);
    var rangeFir = new util.Scope(tempMiDF, tempMidS);
    range.intersect(rangeFir );
    ```


### intersect<sup>8+</sup><a name="section1586223883211"></a>

intersect\(lowerObj:ScopeType,upperObj:ScopeType\):Scope

Obtains the intersection of this  **Scope**  and the given lower and upper limits.

-   Parameters

    <a name="table1516153111131"></a>
    <table><thead align="left"><tr id="row4516113116139"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p85168319132"><a name="p85168319132"></a><a name="p85168319132"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p19516193191312"><a name="p19516193191312"></a><a name="p19516193191312"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p185161431161312"><a name="p185161431161312"></a><a name="p185161431161312"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11516123116131"><a name="p11516123116131"></a><a name="p11516123116131"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1451623161320"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15162312137"><a name="p15162312137"></a><a name="p15162312137"></a>lowerObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1351643118133"><a name="p1351643118133"></a><a name="p1351643118133"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p851610313131"><a name="p851610313131"></a><a name="p851610313131"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1451623171310"><a name="p1451623171310"></a><a name="p1451623171310"></a>Lower limit.</p>
    </td>
    </tr>
    <tr id="row3517173101319"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2517103131316"><a name="p2517103131316"></a><a name="p2517103131316"></a>upperObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15517113161320"><a name="p15517113161320"></a><a name="p15517113161320"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1151719316137"><a name="p1151719316137"></a><a name="p1151719316137"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p135176316132"><a name="p135176316132"></a><a name="p135176316132"></a>Upper limit.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table473312137599"></a>
    <table><thead align="left"><tr id="row3733161335916"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p167335139592"><a name="p167335139592"></a><a name="p167335139592"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p16733813175914"><a name="p16733813175914"></a><a name="p16733813175914"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1973315139595"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p5734151317592"><a name="p5734151317592"></a><a name="p5734151317592"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1973417131598"><a name="p1973417131598"></a><a name="p1973417131598"></a>Intersection of this <strong id="b741311084214"><a name="b741311084214"></a><a name="b741311084214"></a>Scope</strong> and the given lower and upper limits.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var tempMidS = new Temperature(39);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.intersect(tempMiDF, tempMidS);
    ```


### getUpper<sup>8+</sup><a name="section1846111215336"></a>

getUpper\(\):ScopeType

Obtains the upper limit of this  **Scope**.

-   Return values

    <a name="table26201118191319"></a>
    <table><thead align="left"><tr id="row18621151811312"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p13621518111318"><a name="p13621518111318"></a><a name="p13621518111318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1662113183130"><a name="p1662113183130"></a><a name="p1662113183130"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10621141813137"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p116211318111312"><a name="p116211318111312"></a><a name="p116211318111312"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1147212518294"><a name="p1147212518294"></a><a name="p1147212518294"></a>Upper limit of this <strong id="b35058351050"><a name="b35058351050"></a><a name="b35058351050"></a>Scope</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.getUpper();
    ```


### getLower<sup>8+</sup><a name="section122661240183311"></a>

getLower\(\):ScopeType

Obtains the lower limit of this  **Scope**.

-   Return values

    <a name="table1073614131593"></a>
    <table><thead align="left"><tr id="row47361113125911"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p8736161320597"><a name="p8736161320597"></a><a name="p8736161320597"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p18736813135914"><a name="p18736813135914"></a><a name="p18736813135914"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4737113185920"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p147374132598"><a name="p147374132598"></a><a name="p147374132598"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p677054992620"><a name="p677054992620"></a><a name="p677054992620"></a>Lower limit of this <strong id="b133316414614"><a name="b133316414614"></a><a name="b133316414614"></a>Scope</strong>. </p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.getLower();
    ```


### expand<sup>8+</sup><a name="section1750818183417"></a>

expand\(lowerObj:ScopeType,upperObj:ScopeType\):Scope

Obtains the union set of this  **Scope**  and the given lower and upper limits.

-   Parameters

    <a name="table39251255192718"></a>
    <table><thead align="left"><tr id="row0925125592720"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1292575512718"><a name="p1292575512718"></a><a name="p1292575512718"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p16925105542718"><a name="p16925105542718"></a><a name="p16925105542718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p392595582717"><a name="p392595582717"></a><a name="p392595582717"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1292525512712"><a name="p1292525512712"></a><a name="p1292525512712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row192665520272"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p149261552277"><a name="p149261552277"></a><a name="p149261552277"></a>lowerObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p17926855192713"><a name="p17926855192713"></a><a name="p17926855192713"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p179261055162713"><a name="p179261055162713"></a><a name="p179261055162713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1892618552272"><a name="p1892618552272"></a><a name="p1892618552272"></a>Lower limit.</p>
    </td>
    </tr>
    <tr id="row1092635512718"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p992655582718"><a name="p992655582718"></a><a name="p992655582718"></a>upperObj</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1192615552274"><a name="p1192615552274"></a><a name="p1192615552274"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p99261555112715"><a name="p99261555112715"></a><a name="p99261555112715"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18926755172715"><a name="p18926755172715"></a><a name="p18926755172715"></a>Upper limit.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table4739201315912"></a>
    <table><thead align="left"><tr id="row973920137591"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p187401913145910"><a name="p187401913145910"></a><a name="p187401913145910"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p197401913175919"><a name="p197401913175919"></a><a name="p197401913175919"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8740113175917"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p174051345914"><a name="p174051345914"></a><a name="p174051345914"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1974051318590"><a name="p1974051318590"></a><a name="p1974051318590"></a>Union set of this <strong id="b13465184213619"><a name="b13465184213619"></a><a name="b13465184213619"></a>Scope</strong> and the given lower and upper limits.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var tempMidS = new Temperature(39);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.expand(tempMiDF, tempMidS);
    ```


### expand<sup>8+</sup><a name="section452411522343"></a>

expand\(range:Scope\):Scope

Obtains the union set of this  **Scope**  and the given  **Scope**.

-   Parameters

    <a name="table157161331193217"></a>
    <table><thead align="left"><tr id="row14716123123216"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p471663133210"><a name="p471663133210"></a><a name="p471663133210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1171613313324"><a name="p1171613313324"></a><a name="p1171613313324"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p137161831163211"><a name="p137161831163211"></a><a name="p137161831163211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11716113123219"><a name="p11716113123219"></a><a name="p11716113123219"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6716113163218"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p97161231113216"><a name="p97161231113216"></a><a name="p97161231113216"></a>range</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1071712313323"><a name="p1071712313323"></a><a name="p1071712313323"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1171714318328"><a name="p1171714318328"></a><a name="p1171714318328"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p97191431113218"><a name="p97191431113218"></a><a name="p97191431113218"></a><strong id="b127212032479"><a name="b127212032479"></a><a name="b127212032479"></a>Scope</strong> specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table17743111318590"></a>
    <table><thead align="left"><tr id="row18743171313599"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1474361313594"><a name="p1474361313594"></a><a name="p1474361313594"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p10743513125914"><a name="p10743513125914"></a><a name="p10743513125914"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row174320133596"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p9743513105916"><a name="p9743513105916"></a><a name="p9743513105916"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p2743161313596"><a name="p2743161313596"></a><a name="p2743161313596"></a>Union set of this <strong id="b187858499711"><a name="b187858499711"></a><a name="b187858499711"></a>Scope</strong> and the given <strong id="b207441058972"><a name="b207441058972"></a><a name="b207441058972"></a>Scope</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var tempMidS = new Temperature(39);
    var range = new util.Scope(tempLower, tempUpper);
    var rangeFir = new util.Scope(tempMiDF, tempMidS);
    var result = range.expand(rangeFir);
    ```


### expand<sup>8+</sup><a name="section12650172517353"></a>

expand\(value:ScopeType\):Scope

Obtains the union set of this  **Scope**  and the given value.

-   Parameters

    <a name="table155353016340"></a>
    <table><thead align="left"><tr id="row195539301348"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18553153015349"><a name="p18553153015349"></a><a name="p18553153015349"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p125531430193410"><a name="p125531430193410"></a><a name="p125531430193410"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p755443033413"><a name="p755443033413"></a><a name="p755443033413"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1455419307347"><a name="p1455419307347"></a><a name="p1455419307347"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19554183063412"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p4554130123415"><a name="p4554130123415"></a><a name="p4554130123415"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11554143043418"><a name="p11554143043418"></a><a name="p11554143043418"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7554183093418"><a name="p7554183093418"></a><a name="p7554183093418"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p155541730153418"><a name="p155541730153418"></a><a name="p155541730153418"></a>Value specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table67461213165912"></a>
    <table><thead align="left"><tr id="row157465132594"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p0746171319598"><a name="p0746171319598"></a><a name="p0746171319598"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p6746131314595"><a name="p6746131314595"></a><a name="p6746131314595"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17461113185918"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p9747201319592"><a name="p9747201319592"></a><a name="p9747201319592"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p19747181315916"><a name="p19747181315916"></a><a name="p19747181315916"></a>Union set of this <strong id="b947420291093"><a name="b947420291093"></a><a name="b947420291093"></a>Scope</strong> and the given value.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.expand(tempMiDF);
    ```


### contains<sup>8+</sup><a name="section185046548354"></a>

contains\(value:ScopeType\):boolean

Checks whether a value is within this  **Scope**.

-   Parameters

    <a name="table84492261363"></a>
    <table><thead align="left"><tr id="row16450132623611"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1450126173612"><a name="p1450126173612"></a><a name="p1450126173612"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p545002663618"><a name="p545002663618"></a><a name="p545002663618"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18451626193612"><a name="p18451626193612"></a><a name="p18451626193612"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9451142613361"><a name="p9451142613361"></a><a name="p9451142613361"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row104511726163610"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p18451192611366"><a name="p18451192611366"></a><a name="p18451192611366"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p204513263364"><a name="p204513263364"></a><a name="p204513263364"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p245212611363"><a name="p245212611363"></a><a name="p245212611363"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2452122613616"><a name="p2452122613616"></a><a name="p2452122613616"></a>Value specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table07494134598"></a>
    <table><thead align="left"><tr id="row1674961312596"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p774921315597"><a name="p774921315597"></a><a name="p774921315597"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1974911314597"><a name="p1974911314597"></a><a name="p1974911314597"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1674911365914"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p157509139594"><a name="p157509139594"></a><a name="p157509139594"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p19750613175914"><a name="p19750613175914"></a><a name="p19750613175914"></a>Returns <strong id="b1235314522548"><a name="b1235314522548"></a><a name="b1235314522548"></a>true</strong> if the value is within this <strong id="b2074205131020"><a name="b2074205131020"></a><a name="b2074205131020"></a>Scope</strong>; returns <strong id="b184968214551"><a name="b184968214551"></a><a name="b184968214551"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var range = new util.Scope(tempLower, tempUpper);
    range.contains(tempMiDF);
    ```


### contains<sup>8+</sup><a name="section13131514153617"></a>

contains\(range:Scope\):boolean

Checks whether a range is within this  **Scope**.

-   Parameters

    <a name="table10561121018398"></a>
    <table><thead align="left"><tr id="row1656218102397"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1056291016393"><a name="p1056291016393"></a><a name="p1056291016393"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p45621610123915"><a name="p45621610123915"></a><a name="p45621610123915"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15562171011396"><a name="p15562171011396"></a><a name="p15562171011396"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11562191063911"><a name="p11562191063911"></a><a name="p11562191063911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15621210153915"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16562910153918"><a name="p16562910153918"></a><a name="p16562910153918"></a>range</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1056261073915"><a name="p1056261073915"></a><a name="p1056261073915"></a><a href="#section14134189623">Scope</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1562110173920"><a name="p1562110173920"></a><a name="p1562110173920"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18562151017392"><a name="p18562151017392"></a><a name="p18562151017392"></a>Range specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table175214132592"></a>
    <table><thead align="left"><tr id="row187521313105919"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p18752201315914"><a name="p18752201315914"></a><a name="p18752201315914"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p2075212134594"><a name="p2075212134594"></a><a name="p2075212134594"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2075291311598"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p47521813125919"><a name="p47521813125919"></a><a name="p47521813125919"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p17753101314598"><a name="p17753101314598"></a><a name="p17753101314598"></a>Returns <strong id="b1464394612579"><a name="b1464394612579"></a><a name="b1464394612579"></a>true</strong> if the range is within this <strong id="b135813117111"><a name="b135813117111"></a><a name="b135813117111"></a>Scope</strong>; returns <strong id="b352192475816"><a name="b352192475816"></a><a name="b352192475816"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var range = new util.Scope(tempLower, tempUpper);
    var tempLess = new Temperature(20);
    var tempMore = new Temperature(45);
    var rangeSec = new util.Scope(tempLess, tempMore);
    var result = range.contains(rangeSec);
    ```


### clamp<sup>8+</sup><a name="section11457203818361"></a>

clamp\(value:ScopeType\):ScopeType

Limits a value to this  **Scope**.

-   Parameters

    <a name="table87536132594"></a>
    <table><thead align="left"><tr id="row97541132596"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1475411325910"><a name="p1475411325910"></a><a name="p1475411325910"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p875451311595"><a name="p875451311595"></a><a name="p875451311595"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1875413131599"><a name="p1875413131599"></a><a name="p1875413131599"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p77541413155917"><a name="p77541413155917"></a><a name="p77541413155917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17541713135913"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3754113155912"><a name="p3754113155912"></a><a name="p3754113155912"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15754101316590"><a name="p15754101316590"></a><a name="p15754101316590"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p127547131591"><a name="p127547131591"></a><a name="p127547131591"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1275411316597"><a name="p1275411316597"></a><a name="p1275411316597"></a>Value specified.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table1175416138592"></a>
    <table><thead align="left"><tr id="row275510133592"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1275510132596"><a name="p1275510132596"></a><a name="p1275510132596"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p15755151319591"><a name="p15755151319591"></a><a name="p15755151319591"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row175531312595"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1175581375911"><a name="p1175581375911"></a><a name="p1175581375911"></a><a href="#section876116244471">ScopeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p9279191915435"><a name="p9279191915435"></a><a name="p9279191915435"></a>Returns <strong id="b837381711914"><a name="b837381711914"></a><a name="b837381711914"></a>lowerObj</strong> if the specified value is less than the lower limit; returns <strong id="b51885478913"><a name="b51885478913"></a><a name="b51885478913"></a>upperObj</strong> if the specified value is greater than the upper limit; returns the specified value if it is within this <strong id="b189634154133"><a name="b189634154133"></a><a name="b189634154133"></a>Scope</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var tempLower = new Temperature(30);
    var tempUpper = new Temperature(40);
    var tempMiDF = new Temperature(35);
    var range = new util.Scope(tempLower, tempUpper);
    var result = range.clamp(tempMiDF);
    ```


## Base64<sup>8+</sup><a name="section019185432010"></a>

### constructor<sup>8+</sup><a name="section922264811280"></a>

constructor\(\)

A constructor used to create a  **Base64**  object.

-   Example

    ```
    var base64 = new util.Base64();
    ```


### encodeSync<sup>8+</sup><a name="section16259020163616"></a>

encodeSync\(src:Uint8Array\):Uint8Array

Encodes the input content.

-   Parameters

    <a name="table6260720143615"></a>
    <table><thead align="left"><tr id="row14261112023614"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p72611320103611"><a name="p72611320103611"></a><a name="p72611320103611"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p7261132013362"><a name="p7261132013362"></a><a name="p7261132013362"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p326152003616"><a name="p326152003616"></a><a name="p326152003616"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p7261020193616"><a name="p7261020193616"></a><a name="p7261020193616"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row92621320163617"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p42621020133614"><a name="p42621020133614"></a><a name="p42621020133614"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p142628209363"><a name="p142628209363"></a><a name="p142628209363"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p726282033612"><a name="p726282033612"></a><a name="p726282033612"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1026242033619"><a name="p1026242033619"></a><a name="p1026242033619"></a>Uint8Array to encode.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table12263202023616"></a>
    <table><thead align="left"><tr id="row62631520203618"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p626302073618"><a name="p626302073618"></a><a name="p626302073618"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p32631220133610"><a name="p32631220133610"></a><a name="p32631220133610"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11263142017361"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1326412053612"><a name="p1326412053612"></a><a name="p1326412053612"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p19264172033611"><a name="p19264172033611"></a><a name="p19264172033611"></a>Uint8Array encoded.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var array = new Uint8Array([115,49,51]);
    var result = that.encodeSync(array);
    ```


### encodeToStringSync<sup>8+</sup><a name="section29464052017"></a>

encodeToStringSync\(src:Uint8Array\):string

Encodes the input content into a string.

-   Parameters

    <a name="table8954403209"></a>
    <table><thead align="left"><tr id="row14966407207"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1996440172016"><a name="p1996440172016"></a><a name="p1996440172016"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p159714407206"><a name="p159714407206"></a><a name="p159714407206"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p19774019208"><a name="p19774019208"></a><a name="p19774019208"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p209784019207"><a name="p209784019207"></a><a name="p209784019207"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row119894010209"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p89834015204"><a name="p89834015204"></a><a name="p89834015204"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p17989403203"><a name="p17989403203"></a><a name="p17989403203"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p699940172012"><a name="p699940172012"></a><a name="p699940172012"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p39924062012"><a name="p39924062012"></a><a name="p39924062012"></a>Uint8Array to encode.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table210084014209"></a>
    <table><thead align="left"><tr id="row1100124013206"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p7101134002012"><a name="p7101134002012"></a><a name="p7101134002012"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p31011240162012"><a name="p31011240162012"></a><a name="p31011240162012"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row81011240112010"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p15101134012202"><a name="p15101134012202"></a><a name="p15101134012202"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p110264082016"><a name="p110264082016"></a><a name="p110264082016"></a>String encoded from the Uint8Array.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var array = new Uint8Array([115,49,51]);
    var result = that.encodeToStringSync(array);
    ```


### decodeSync<sup>8+</sup><a name="section101661027192312"></a>

decodeSync\(src:Uint8Array | string\):Uint8Array

Decodes the input content.

-   Parameters

    <a name="table116917279231"></a>
    <table><thead align="left"><tr id="row4170927182314"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1917116270234"><a name="p1917116270234"></a><a name="p1917116270234"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.06%" id="mcps1.1.5.1.2"><p id="p1917182717235"><a name="p1917182717235"></a><a name="p1917182717235"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.09%" id="mcps1.1.5.1.3"><p id="p817111277235"><a name="p817111277235"></a><a name="p817111277235"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.03%" id="mcps1.1.5.1.4"><p id="p217220275234"><a name="p217220275234"></a><a name="p217220275234"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11176427102318"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9177102782313"><a name="p9177102782313"></a><a name="p9177102782313"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.06%" headers="mcps1.1.5.1.2 "><p id="p9490108182416"><a name="p9490108182416"></a><a name="p9490108182416"></a>Uint8Array | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.09%" headers="mcps1.1.5.1.3 "><p id="p51782277236"><a name="p51782277236"></a><a name="p51782277236"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.03%" headers="mcps1.1.5.1.4 "><p id="p1178727122310"><a name="p1178727122310"></a><a name="p1178727122310"></a>Uint8Array or string to decode.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table31797276230"></a>
    <table><thead align="left"><tr id="row917982711239"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p818012762311"><a name="p818012762311"></a><a name="p818012762311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p71803279235"><a name="p71803279235"></a><a name="p71803279235"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row918142792312"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p21813274233"><a name="p21813274233"></a><a name="p21813274233"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p22761840256"><a name="p22761840256"></a><a name="p22761840256"></a>Uint8Array decoded.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var buff = 'czEz';
    var result = that.decodeSync(buff);
    ```


### encode<sup>8+</sup><a name="section1877083032719"></a>

encode\(src:Uint8Array\):Promise<Uint8Array\>

Encodes the input content asynchronously.

-   Parameters

    <a name="table1477173012274"></a>
    <table><thead align="left"><tr id="row577263010272"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p20772530172717"><a name="p20772530172717"></a><a name="p20772530172717"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p157731730112719"><a name="p157731730112719"></a><a name="p157731730112719"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1677393018272"><a name="p1677393018272"></a><a name="p1677393018272"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p17773930142711"><a name="p17773930142711"></a><a name="p17773930142711"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4774173002713"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1774113012711"><a name="p1774113012711"></a><a name="p1774113012711"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p17741330122711"><a name="p17741330122711"></a><a name="p17741330122711"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p15775730182712"><a name="p15775730182712"></a><a name="p15775730182712"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15775173011272"><a name="p15775173011272"></a><a name="p15775173011272"></a>Uint8Array to encode asynchronously.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table147751530202718"></a>
    <table><thead align="left"><tr id="row14776103022715"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p11777730162716"><a name="p11777730162716"></a><a name="p11777730162716"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p147771230122718"><a name="p147771230122718"></a><a name="p147771230122718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1877793015276"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p477753017273"><a name="p477753017273"></a><a name="p477753017273"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p377817308278"><a name="p377817308278"></a><a name="p377817308278"></a>Uint8Array obtained after asynchronous encoding.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var array = new Uint8Array([115,49,51]);
    var rarray = new Uint8Array([99,122,69,122]);
    await that.encode(array).then(val=>{    
        for (var i = 0; i < rarray.length; i++) {        
            expect(val[i]).assertEqual(rarray[i])
        }
    })
    done();
    ```


### encodeToString<sup>8+</sup><a name="section2660345143420"></a>

encodeToString\(src:Uint8Array\):Promise<string\>

Encodes the input content asynchronously into a string.

-   Parameters

    <a name="table1661184573414"></a>
    <table><thead align="left"><tr id="row566234513418"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p66631945183420"><a name="p66631945183420"></a><a name="p66631945183420"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p566364511340"><a name="p566364511340"></a><a name="p566364511340"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p2066412457346"><a name="p2066412457346"></a><a name="p2066412457346"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p16664184514343"><a name="p16664184514343"></a><a name="p16664184514343"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row466444516349"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1666424518344"><a name="p1666424518344"></a><a name="p1666424518344"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11665445183410"><a name="p11665445183410"></a><a name="p11665445183410"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p4665154513412"><a name="p4665154513412"></a><a name="p4665154513412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p566512457349"><a name="p566512457349"></a><a name="p566512457349"></a>Uint8Array to encode asynchronously.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table46661045173417"></a>
    <table><thead align="left"><tr id="row136661455347"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p2066712452343"><a name="p2066712452343"></a><a name="p2066712452343"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p176674453345"><a name="p176674453345"></a><a name="p176674453345"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14667154513341"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p11668124563418"><a name="p11668124563418"></a><a name="p11668124563418"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p186682045133415"><a name="p186682045133415"></a><a name="p186682045133415"></a>String obtained after asynchronous encoding.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var array = new Uint8Array([115,49,51]);
    await that.encodeToString(array).then(val=>{    
        expect(val).assertEqual('czEz')
    })
    done();
    ```


### decode<sup>8+</sup><a name="section175421615134111"></a>

decode\(src:Uint8Array | string\):Promise<Uint8Array\>

Decodes the input content asynchronously.

-   Parameters

    <a name="table19544171574117"></a>
    <table><thead align="left"><tr id="row9545141584112"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p4546101518416"><a name="p4546101518416"></a><a name="p4546101518416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.75%" id="mcps1.1.5.1.2"><p id="p19546315114118"><a name="p19546315114118"></a><a name="p19546315114118"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.24%" id="mcps1.1.5.1.3"><p id="p1554661519415"><a name="p1554661519415"></a><a name="p1554661519415"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.19%" id="mcps1.1.5.1.4"><p id="p165471015184114"><a name="p165471015184114"></a><a name="p165471015184114"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195471915104114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2547181515411"><a name="p2547181515411"></a><a name="p2547181515411"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.75%" headers="mcps1.1.5.1.2 "><p id="p254721564110"><a name="p254721564110"></a><a name="p254721564110"></a>Uint8Array | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.24%" headers="mcps1.1.5.1.3 "><p id="p14548101515419"><a name="p14548101515419"></a><a name="p14548101515419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.19%" headers="mcps1.1.5.1.4 "><p id="p19548161554113"><a name="p19548161554113"></a><a name="p19548161554113"></a>Uint8Array or string to decode asynchronously.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table354981519411"></a>
    <table><thead align="left"><tr id="row15491153413"><th class="cellrowborder" valign="top" width="27.83%" id="mcps1.1.3.1.1"><p id="p14550915154120"><a name="p14550915154120"></a><a name="p14550915154120"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.17%" id="mcps1.1.3.1.2"><p id="p85504154411"><a name="p85504154411"></a><a name="p85504154411"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row145501315194117"><td class="cellrowborder" valign="top" width="27.83%" headers="mcps1.1.3.1.1 "><p id="p1869252334511"><a name="p1869252334511"></a><a name="p1869252334511"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.17%" headers="mcps1.1.3.1.2 "><p id="p055161534115"><a name="p055161534115"></a><a name="p055161534115"></a>Uint8Array obtained after asynchronous decoding.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Base64();
    var array = new Uint8Array([99,122,69,122]);
    var rarray = new Uint8Array([115,49,51]);
    await that.decode(array).then(val=>{    
        for (var i = 0; i < rarray.length; i++) {        
            expect(val[i]).assertEqual(rarray[i])
        }
    })
    done();
    ```


## Types<sup>8+</sup><a name="section166241674120"></a>

### constructor<sup>8+</sup><a name="section1036241194313"></a>

constructor\(\)

A constructor used to create a  **Types**  object.

-   Example

    ```
    var type = new util.Types();
    ```


### isAnyArrayBuffer<sup>8+</sup><a name="section533514174510"></a>

isAnyArrayBuffer\(value: Object\):boolean

Checks whether the input value is of the  **ArrayBuffer**  type.

-   Parameters

    <a name="table6337131204519"></a>
    <table><thead align="left"><tr id="row9338121114518"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1433820118457"><a name="p1433820118457"></a><a name="p1433820118457"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p933931194513"><a name="p933931194513"></a><a name="p933931194513"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1733910144515"><a name="p1733910144515"></a><a name="p1733910144515"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p23390112453"><a name="p23390112453"></a><a name="p23390112453"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1934015154516"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p143401174520"><a name="p143401174520"></a><a name="p143401174520"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p19340216458"><a name="p19340216458"></a><a name="p19340216458"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p334061114517"><a name="p334061114517"></a><a name="p334061114517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p76161851121719"><a name="p76161851121719"></a><a name="p76161851121719"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table183411814456"></a>
    <table><thead align="left"><tr id="row1434214117454"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1434201164511"><a name="p1434201164511"></a><a name="p1434201164511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1334219144514"><a name="p1334219144514"></a><a name="p1334219144514"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1134319134514"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1834316174511"><a name="p1834316174511"></a><a name="p1834316174511"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p183431419458"><a name="p183431419458"></a><a name="p183431419458"></a>Returns <strong id="b4482618142217"><a name="b4482618142217"></a><a name="b4482618142217"></a>true</strong> if the input value is of the <strong id="b1455613716914"><a name="b1455613716914"></a><a name="b1455613716914"></a>ArrayBuffer</strong> type; returns <strong id="b1829935718228"><a name="b1829935718228"></a><a name="b1829935718228"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isAnyArrayBuffer(new ArrayBuffer([]));
    ```


### isArrayBufferView<sup>8+</sup><a name="section12448512546"></a>

isArrayBufferView\(value: Object\):boolean

Checks whether the input value is of the  **ArrayBufferView**  type.

**ArrayBufferView**  is a helper type representing any of the following:  **Int8Array**,  **Int16Array**,  **Int32Array**,  **Uint8Array**,  **Uint8ClampedArray**,  **Uint32Array**,  **Float32Array**,  **Float64Array**, and  **DataView**.

-   Parameters

    <a name="table14450141105411"></a>
    <table><thead align="left"><tr id="row10451171175413"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19451201145417"><a name="p19451201145417"></a><a name="p19451201145417"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p164519111545"><a name="p164519111545"></a><a name="p164519111545"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p2045217135413"><a name="p2045217135413"></a><a name="p2045217135413"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11452311541"><a name="p11452311541"></a><a name="p11452311541"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row114528175413"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13453615543"><a name="p13453615543"></a><a name="p13453615543"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1345311185410"><a name="p1345311185410"></a><a name="p1345311185410"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1645318117543"><a name="p1645318117543"></a><a name="p1645318117543"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p543575711186"><a name="p543575711186"></a><a name="p543575711186"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Return values

    <a name="table16454181165414"></a>
    <table><thead align="left"><tr id="row84542185410"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p8455141125415"><a name="p8455141125415"></a><a name="p8455141125415"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p8455111165411"><a name="p8455111165411"></a><a name="p8455111165411"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18455121185417"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1245514112541"><a name="p1245514112541"></a><a name="p1245514112541"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1945618117541"><a name="p1945618117541"></a><a name="p1945618117541"></a>Returns <strong id="b111214595598"><a name="b111214595598"></a><a name="b111214595598"></a>true</strong> if the input value is of the <strong id="b1779133415109"><a name="b1779133415109"></a><a name="b1779133415109"></a>ArrayBufferView</strong> type; returns <strong id="b15740125517010"><a name="b15740125517010"></a><a name="b15740125517010"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isArrayBufferView(new Int8Array([]));
    ```


### isArgumentsObject<sup>8+</sup><a name="section7225346115718"></a>

isArgumentsObject\(value: Object\):boolean

Checks whether the input value is of the  **arguments**  type.

-   Parameters

    <a name="table62271846195712"></a>
    <table><thead align="left"><tr id="row6228134625718"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p522894605714"><a name="p522894605714"></a><a name="p522894605714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1322844612575"><a name="p1322844612575"></a><a name="p1322844612575"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p7229124613577"><a name="p7229124613577"></a><a name="p7229124613577"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p12229646105713"><a name="p12229646105713"></a><a name="p12229646105713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16230184695712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8230194635716"><a name="p8230194635716"></a><a name="p8230194635716"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p823014645712"><a name="p823014645712"></a><a name="p823014645712"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p2231194614575"><a name="p2231194614575"></a><a name="p2231194614575"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p168811623102014"><a name="p168811623102014"></a><a name="p168811623102014"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table14231134611573"></a>
    <table><thead align="left"><tr id="row62321946115719"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p2232946105713"><a name="p2232946105713"></a><a name="p2232946105713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p112321746125712"><a name="p112321746125712"></a><a name="p112321746125712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10233446125712"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p6233946175720"><a name="p6233946175720"></a><a name="p6233946175720"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p023324615715"><a name="p023324615715"></a><a name="p023324615715"></a>Returns <strong id="b277814815115"><a name="b277814815115"></a><a name="b277814815115"></a>true</strong> if the input value is of the <strong id="b477818141111"><a name="b477818141111"></a><a name="b477818141111"></a>arguments</strong> type; returns <strong id="b187791889115"><a name="b187791889115"></a><a name="b187791889115"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    function foo() {
        var result = that.isArgumentsObject(arguments);
    }
    var f = foo();
    ```


### isArrayBuffer<sup>8+</sup><a name="section16551581119"></a>

isArrayBuffer\(value: Object\):boolean

Checks whether the input value is of the  **ArrayBuffer**  type.

-   Parameters

    <a name="table465712581818"></a>
    <table><thead align="left"><tr id="row36571358911"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8658175820115"><a name="p8658175820115"></a><a name="p8658175820115"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p0658125818117"><a name="p0658125818117"></a><a name="p0658125818117"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1665810587111"><a name="p1665810587111"></a><a name="p1665810587111"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p18658155816111"><a name="p18658155816111"></a><a name="p18658155816111"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row116592581615"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p66595581617"><a name="p66595581617"></a><a name="p66595581617"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p3659658316"><a name="p3659658316"></a><a name="p3659658316"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p36601558611"><a name="p36601558611"></a><a name="p36601558611"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p475105013206"><a name="p475105013206"></a><a name="p475105013206"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table11661105812116"></a>
    <table><thead align="left"><tr id="row16661195812112"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p866218581811"><a name="p866218581811"></a><a name="p866218581811"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p20662658718"><a name="p20662658718"></a><a name="p20662658718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row466285814111"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p166312583111"><a name="p166312583111"></a><a name="p166312583111"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p6663758314"><a name="p6663758314"></a><a name="p6663758314"></a>Returns <strong id="b15468125391515"><a name="b15468125391515"></a><a name="b15468125391515"></a>true</strong> if the input value is of the <strong id="b15469115315154"><a name="b15469115315154"></a><a name="b15469115315154"></a>ArrayBuffer</strong> type; returns <strong id="b0469115310158"><a name="b0469115310158"></a><a name="b0469115310158"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isArrayBuffer(new ArrayBuffer([]));
    ```


### isAsyncFunction<sup>8+</sup><a name="section96296571642"></a>

isAsyncFunction\(value: Object\):boolean

Checks whether the input value is an asynchronous function.

-   Parameters

    <a name="table463195711420"></a>
    <table><thead align="left"><tr id="row86312571048"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1663215714413"><a name="p1663215714413"></a><a name="p1663215714413"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p156328575412"><a name="p156328575412"></a><a name="p156328575412"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p156321057348"><a name="p156321057348"></a><a name="p156321057348"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p96331571143"><a name="p96331571143"></a><a name="p96331571143"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8633057342"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p76331857449"><a name="p76331857449"></a><a name="p76331857449"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p163312571442"><a name="p163312571442"></a><a name="p163312571442"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1463465710420"><a name="p1463465710420"></a><a name="p1463465710420"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p86341957146"><a name="p86341957146"></a><a name="p86341957146"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table96351577413"></a>
    <table><thead align="left"><tr id="row86359571646"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p146351857546"><a name="p146351857546"></a><a name="p146351857546"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p2636115713420"><a name="p2636115713420"></a><a name="p2636115713420"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4636175715418"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p06361057241"><a name="p06361057241"></a><a name="p06361057241"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p86374571440"><a name="p86374571440"></a><a name="p86374571440"></a>Returns <strong id="b11594144532014"><a name="b11594144532014"></a><a name="b11594144532014"></a>true</strong> if the input value is an asynchronous function; returns <strong id="b259410459209"><a name="b259410459209"></a><a name="b259410459209"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isAsyncFunction(async function foo() {});
    ```


### isBooleanObject<sup>8+</sup><a name="section494175372920"></a>

isBooleanObject\(value: Object\):boolean

Checks whether the input value is of the  **Boolean**  type.

-   Parameters

    <a name="table109437538296"></a>
    <table><thead align="left"><tr id="row149433538294"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p69441653132915"><a name="p69441653132915"></a><a name="p69441653132915"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1394415342910"><a name="p1394415342910"></a><a name="p1394415342910"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p9945105312912"><a name="p9945105312912"></a><a name="p9945105312912"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1945175362911"><a name="p1945175362911"></a><a name="p1945175362911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1945145362912"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p119461553142917"><a name="p119461553142917"></a><a name="p119461553142917"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p169461353172914"><a name="p169461353172914"></a><a name="p169461353172914"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p394635312294"><a name="p394635312294"></a><a name="p394635312294"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p194715382912"><a name="p194715382912"></a><a name="p194715382912"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table39472534293"></a>
    <table><thead align="left"><tr id="row394817535291"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p149482053202916"><a name="p149482053202916"></a><a name="p149482053202916"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1894913538295"><a name="p1894913538295"></a><a name="p1894913538295"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1894911534298"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p179490534299"><a name="p179490534299"></a><a name="p179490534299"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p8950155319295"><a name="p8950155319295"></a><a name="p8950155319295"></a>Returns <strong id="b1766355614418"><a name="b1766355614418"></a><a name="b1766355614418"></a>true</strong> if the input value is of the <strong id="b116691756134411"><a name="b116691756134411"></a><a name="b116691756134411"></a>Boolean</strong> type; returns <strong id="b17669556194412"><a name="b17669556194412"></a><a name="b17669556194412"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isBooleanObject(new Boolean(true));
    ```


### isBoxedPrimitive<sup>8+</sup><a name="section14635556330"></a>

isBoxedPrimitive\(value: Object\):boolean

Checks whether the input value is of the  **Boolean**,  **Number**,  **String**, or  **Symbol**  type.

-   Parameters

    <a name="table26374543312"></a>
    <table><thead align="left"><tr id="row563885103317"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p76383512333"><a name="p76383512333"></a><a name="p76383512333"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p06381654333"><a name="p06381654333"></a><a name="p06381654333"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p19639105183320"><a name="p19639105183320"></a><a name="p19639105183320"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p146391356334"><a name="p146391356334"></a><a name="p146391356334"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row36399516333"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p26409563314"><a name="p26409563314"></a><a name="p26409563314"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p116407516334"><a name="p116407516334"></a><a name="p116407516334"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p564035113313"><a name="p564035113313"></a><a name="p564035113313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1264112512339"><a name="p1264112512339"></a><a name="p1264112512339"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1064110563314"></a>
    <table><thead align="left"><tr id="row8642205183318"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p156425513313"><a name="p156425513313"></a><a name="p156425513313"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p26425513339"><a name="p26425513339"></a><a name="p26425513339"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15642458336"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p146431255337"><a name="p146431255337"></a><a name="p146431255337"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p13643155123316"><a name="p13643155123316"></a><a name="p13643155123316"></a>Returns <strong id="b819165219457"><a name="b819165219457"></a><a name="b819165219457"></a>true</strong> if the input value is of the <strong id="b1177071120464"><a name="b1177071120464"></a><a name="b1177071120464"></a>Boolean</strong>, <strong id="b137702118466"><a name="b137702118466"></a><a name="b137702118466"></a>Number</strong>, <strong id="b17704114462"><a name="b17704114462"></a><a name="b17704114462"></a>String</strong>, or <strong id="b14770171111463"><a name="b14770171111463"></a><a name="b14770171111463"></a>Symbol</strong> type; returns <strong id="b819745211458"><a name="b819745211458"></a><a name="b819745211458"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isBoxedPrimitive(new Boolean(false));
    ```


### isDataView<sup>8+</sup><a name="section325873693614"></a>

isDataView\(value: Object\):boolean

Checks whether the input value is of the  **DataView**  type.

-   Parameters

    <a name="table182608369361"></a>
    <table><thead align="left"><tr id="row2262103683618"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17262436173610"><a name="p17262436173610"></a><a name="p17262436173610"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2262133653611"><a name="p2262133653611"></a><a name="p2262133653611"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p82631336123619"><a name="p82631336123619"></a><a name="p82631336123619"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6263183613616"><a name="p6263183613616"></a><a name="p6263183613616"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18264936193620"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p626453643618"><a name="p626453643618"></a><a name="p626453643618"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4264536193611"><a name="p4264536193611"></a><a name="p4264536193611"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p15265173613611"><a name="p15265173613611"></a><a name="p15265173613611"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1926583623614"><a name="p1926583623614"></a><a name="p1926583623614"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table72661736113612"></a>
    <table><thead align="left"><tr id="row826653623611"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p22671736113613"><a name="p22671736113613"></a><a name="p22671736113613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p10267736123619"><a name="p10267736123619"></a><a name="p10267736123619"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22676366363"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p2026833614366"><a name="p2026833614366"></a><a name="p2026833614366"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p132688364369"><a name="p132688364369"></a><a name="p132688364369"></a>Returns <strong id="b1577517478"><a name="b1577517478"></a><a name="b1577517478"></a>true</strong> if the input value is of the <strong id="b78481164710"><a name="b78481164710"></a><a name="b78481164710"></a>DataView</strong> type; returns <strong id="b13849119479"><a name="b13849119479"></a><a name="b13849119479"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const ab = new ArrayBuffer(20);
    var result = that.isDataView(new DataView(ab));
    ```


### isDate<sup>8+</sup><a name="section44281335143812"></a>

isDate\(value: Object\):boolean

Checks whether the input value is of the  **Date**  type.

-   Parameters

    <a name="table342993518383"></a>
    <table><thead align="left"><tr id="row443019353380"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p16430193573812"><a name="p16430193573812"></a><a name="p16430193573812"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1543173513385"><a name="p1543173513385"></a><a name="p1543173513385"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1043143533818"><a name="p1043143533818"></a><a name="p1043143533818"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p64313353388"><a name="p64313353388"></a><a name="p64313353388"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1443183514386"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p543233573817"><a name="p543233573817"></a><a name="p543233573817"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p24321935183816"><a name="p24321935183816"></a><a name="p24321935183816"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1143273513387"><a name="p1143273513387"></a><a name="p1143273513387"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13432203512385"><a name="p13432203512385"></a><a name="p13432203512385"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table443314355380"></a>
    <table><thead align="left"><tr id="row643453512382"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p204341935123814"><a name="p204341935123814"></a><a name="p204341935123814"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p12434193519382"><a name="p12434193519382"></a><a name="p12434193519382"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20435113523820"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p843593517386"><a name="p843593517386"></a><a name="p843593517386"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p24351435173817"><a name="p24351435173817"></a><a name="p24351435173817"></a>Returns <strong id="b11341112814472"><a name="b11341112814472"></a><a name="b11341112814472"></a>true</strong> if the input value is of the <strong id="b14348122811472"><a name="b14348122811472"></a><a name="b14348122811472"></a>Data</strong> type; returns <strong id="b634832814714"><a name="b634832814714"></a><a name="b634832814714"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isDate(new Date());
    ```


### isExternal<sup>8+</sup><a name="section13670154612392"></a>

isExternal\(value: Object\):boolean

Checks whether the input value is of the  **native external**  type.

-   Parameters

    <a name="table1067210460399"></a>
    <table><thead align="left"><tr id="row767312469398"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8673114613391"><a name="p8673114613391"></a><a name="p8673114613391"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1167312461396"><a name="p1167312461396"></a><a name="p1167312461396"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p26742046103910"><a name="p26742046103910"></a><a name="p26742046103910"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p86746464393"><a name="p86746464393"></a><a name="p86746464393"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row66742465399"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1675946183915"><a name="p1675946183915"></a><a name="p1675946183915"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p196751146143918"><a name="p196751146143918"></a><a name="p196751146143918"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p18675184618391"><a name="p18675184618391"></a><a name="p18675184618391"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p206762469391"><a name="p206762469391"></a><a name="p206762469391"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table4676154617394"></a>
    <table><thead align="left"><tr id="row167711463391"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1467724633918"><a name="p1467724633918"></a><a name="p1467724633918"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1867814612392"><a name="p1867814612392"></a><a name="p1867814612392"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row96781146123913"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p14678124612393"><a name="p14678124612393"></a><a name="p14678124612393"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p967916468391"><a name="p967916468391"></a><a name="p967916468391"></a>Returns <strong id="b1419413556478"><a name="b1419413556478"></a><a name="b1419413556478"></a>true</strong> if the input value is of the <strong id="b102004554479"><a name="b102004554479"></a><a name="b102004554479"></a>native external</strong> type; returns <strong id="b2020095554716"><a name="b2020095554716"></a><a name="b2020095554716"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const data = util.createExternalType();
    var result = that.isExternal(data);
    ```


### isFloat32Array<sup>8+</sup><a name="section15442154854820"></a>

isFloat32Array\(value: Object\):boolean

Checks whether the input value is of the  **Float32Array**  type.

-   Parameters

    <a name="table344417483483"></a>
    <table><thead align="left"><tr id="row14445144854811"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p04451548134819"><a name="p04451548134819"></a><a name="p04451548134819"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p15446164818482"><a name="p15446164818482"></a><a name="p15446164818482"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p044694814487"><a name="p044694814487"></a><a name="p044694814487"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p94461048204816"><a name="p94461048204816"></a><a name="p94461048204816"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1744844816489"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p164481648134818"><a name="p164481648134818"></a><a name="p164481648134818"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9448114813485"><a name="p9448114813485"></a><a name="p9448114813485"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6449144884813"><a name="p6449144884813"></a><a name="p6449144884813"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1844954804814"><a name="p1844954804814"></a><a name="p1844954804814"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table12450154818485"></a>
    <table><thead align="left"><tr id="row0450174864817"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p14451114817485"><a name="p14451114817485"></a><a name="p14451114817485"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p10451348134814"><a name="p10451348134814"></a><a name="p10451348134814"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6451114864812"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p164511348204810"><a name="p164511348204810"></a><a name="p164511348204810"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1445274894818"><a name="p1445274894818"></a><a name="p1445274894818"></a>Returns <strong id="b076631919483"><a name="b076631919483"></a><a name="b076631919483"></a>true</strong> if the input value is of the <strong id="b3772151914816"><a name="b3772151914816"></a><a name="b3772151914816"></a>Float32Array</strong> type; returns <strong id="b167721519114816"><a name="b167721519114816"></a><a name="b167721519114816"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isFloat32Array(new Float32Array());
    ```


### isFloat64Array<sup>8+</sup><a name="section202363815015"></a>

isFloat64Array\(value: Object\):boolean

Checks whether the input value is of the  **Float64Array**  type.

-   Parameters

    <a name="table223716816016"></a>
    <table><thead align="left"><tr id="row1923820810013"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p12239128809"><a name="p12239128809"></a><a name="p12239128809"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p824218509"><a name="p824218509"></a><a name="p824218509"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p7242882019"><a name="p7242882019"></a><a name="p7242882019"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p102438810013"><a name="p102438810013"></a><a name="p102438810013"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1424310816010"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3244981202"><a name="p3244981202"></a><a name="p3244981202"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p82448817010"><a name="p82448817010"></a><a name="p82448817010"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p22441381015"><a name="p22441381015"></a><a name="p22441381015"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6245182010"><a name="p6245182010"></a><a name="p6245182010"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5245981402"></a>
    <table><thead align="left"><tr id="row1524717819013"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p15247786019"><a name="p15247786019"></a><a name="p15247786019"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p3248198908"><a name="p3248198908"></a><a name="p3248198908"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1524817818018"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p14249281806"><a name="p14249281806"></a><a name="p14249281806"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p7249281305"><a name="p7249281305"></a><a name="p7249281305"></a>Returns <strong id="b8346175354811"><a name="b8346175354811"></a><a name="b8346175354811"></a>true</strong> if the input value is of the <strong id="b93518536487"><a name="b93518536487"></a><a name="b93518536487"></a>Float64Array</strong> type; returns <strong id="b535125313484"><a name="b535125313484"></a><a name="b535125313484"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isFloat64Array(new Float64Array());
    ```


### isGeneratorFunction<sup>8+</sup><a name="section204411338217"></a>

isGeneratorFunction\(value: Object\):boolean

Checks whether the input value is a generator function.

-   Parameters

    <a name="table2045173315215"></a>
    <table><thead align="left"><tr id="row74723316212"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p847233420"><a name="p847233420"></a><a name="p847233420"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p3472331321"><a name="p3472331321"></a><a name="p3472331321"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p184810331628"><a name="p184810331628"></a><a name="p184810331628"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1548123320217"><a name="p1548123320217"></a><a name="p1548123320217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15481333829"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p34973315213"><a name="p34973315213"></a><a name="p34973315213"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4493330213"><a name="p4493330213"></a><a name="p4493330213"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13495331428"><a name="p13495331428"></a><a name="p13495331428"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1050163317216"><a name="p1050163317216"></a><a name="p1050163317216"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table18505331927"></a>
    <table><thead align="left"><tr id="row15119331423"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p155115331524"><a name="p155115331524"></a><a name="p155115331524"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p12516331928"><a name="p12516331928"></a><a name="p12516331928"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row185210331523"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p105218331823"><a name="p105218331823"></a><a name="p105218331823"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1652123310219"><a name="p1652123310219"></a><a name="p1652123310219"></a>Returns <strong id="b522262145014"><a name="b522262145014"></a><a name="b522262145014"></a>true</strong> if the input value is a generator function; returns <strong id="b17230142175016"><a name="b17230142175016"></a><a name="b17230142175016"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isGeneratorFunction(function* foo() {});
    ```


### isGeneratorObject<sup>8+</sup><a name="section11906181812612"></a>

isGeneratorObject\(value: Object\):boolean

Checks whether the input value is a generator object.

-   Parameters

    <a name="table1390831813619"></a>
    <table><thead align="left"><tr id="row1290911181669"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p290914186616"><a name="p290914186616"></a><a name="p290914186616"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p591010188612"><a name="p591010188612"></a><a name="p591010188612"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p169108181965"><a name="p169108181965"></a><a name="p169108181965"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p99106186619"><a name="p99106186619"></a><a name="p99106186619"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row179116183613"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p991118181166"><a name="p991118181166"></a><a name="p991118181166"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1591131812619"><a name="p1591131812619"></a><a name="p1591131812619"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p17911111811610"><a name="p17911111811610"></a><a name="p17911111811610"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p149123181616"><a name="p149123181616"></a><a name="p149123181616"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table19912131815612"></a>
    <table><thead align="left"><tr id="row1691318181164"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p15913218262"><a name="p15913218262"></a><a name="p15913218262"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1791391815618"><a name="p1791391815618"></a><a name="p1791391815618"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row49141181261"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p091417181263"><a name="p091417181263"></a><a name="p091417181263"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p691415181262"><a name="p691415181262"></a><a name="p691415181262"></a>Returns <strong id="b154805410505"><a name="b154805410505"></a><a name="b154805410505"></a>true</strong> if the input value is a generator object; returns <strong id="b455435405017"><a name="b455435405017"></a><a name="b455435405017"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    function* foo() {}
    const generator = foo();
    var result = that.isGeneratorObject(generator);
    ```


### isInt8Array<sup>8+</sup><a name="section47016751114"></a>

isInt8Array\(value: Object\):boolean

Checks whether the input value is of the  **Int8Array**  type.

-   Parameters

    <a name="table37031474114"></a>
    <table><thead align="left"><tr id="row1270416717114"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17041573119"><a name="p17041573119"></a><a name="p17041573119"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p670413731119"><a name="p670413731119"></a><a name="p670413731119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1170477161115"><a name="p1170477161115"></a><a name="p1170477161115"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p97051873112"><a name="p97051873112"></a><a name="p97051873112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row47059711119"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p970527171114"><a name="p970527171114"></a><a name="p970527171114"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4706376112"><a name="p4706376112"></a><a name="p4706376112"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p0706147171118"><a name="p0706147171118"></a><a name="p0706147171118"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p127061876112"><a name="p127061876112"></a><a name="p127061876112"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table170714791114"></a>
    <table><thead align="left"><tr id="row4707117141114"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p187088716119"><a name="p187088716119"></a><a name="p187088716119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p37087710114"><a name="p37087710114"></a><a name="p37087710114"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row37081378114"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p19709278116"><a name="p19709278116"></a><a name="p19709278116"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p197094715113"><a name="p197094715113"></a><a name="p197094715113"></a>Returns <strong id="b17934631115113"><a name="b17934631115113"></a><a name="b17934631115113"></a>true</strong> if the input value is of the <strong id="b1935123113516"><a name="b1935123113516"></a><a name="b1935123113516"></a>Int8Array</strong> type; returns <strong id="b19935103175111"><a name="b19935103175111"></a><a name="b19935103175111"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isInt8Array(new Int8Array([]));
    ```


### isInt16Array<sup>8+</sup><a name="section1666916810178"></a>

isInt16Array\(value: Object\):boolean

Checks whether the input value is of the  **Int16Array**  type.

-   Parameters

    <a name="table26717821711"></a>
    <table><thead align="left"><tr id="row067218812176"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1267216814175"><a name="p1267216814175"></a><a name="p1267216814175"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p267311812174"><a name="p267311812174"></a><a name="p267311812174"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p20673198151713"><a name="p20673198151713"></a><a name="p20673198151713"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p867315871719"><a name="p867315871719"></a><a name="p867315871719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1267413812175"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1667417861716"><a name="p1667417861716"></a><a name="p1667417861716"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p176751583179"><a name="p176751583179"></a><a name="p176751583179"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p5675108101715"><a name="p5675108101715"></a><a name="p5675108101715"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p06766817172"><a name="p06766817172"></a><a name="p06766817172"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table13676118191716"></a>
    <table><thead align="left"><tr id="row1067714813173"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p18678168121711"><a name="p18678168121711"></a><a name="p18678168121711"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1067815820174"><a name="p1067815820174"></a><a name="p1067815820174"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row166781583179"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p267918861718"><a name="p267918861718"></a><a name="p267918861718"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p768058181719"><a name="p768058181719"></a><a name="p768058181719"></a>Returns <strong id="b13941085220"><a name="b13941085220"></a><a name="b13941085220"></a>true</strong> if the input value is of the <strong id="b184011108528"><a name="b184011108528"></a><a name="b184011108528"></a>Int16Array</strong> type; returns <strong id="b340110155216"><a name="b340110155216"></a><a name="b340110155216"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isInt16Array(new Int16Array([]));
    ```


### isInt32Array<sup>8+</sup><a name="section12441102817256"></a>

isInt32Array\(value: Object\):boolean

Checks whether the input value is of the  **Int32Array**  type.

-   Parameters

    <a name="table12443192882518"></a>
    <table><thead align="left"><tr id="row044422802516"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p3444142832511"><a name="p3444142832511"></a><a name="p3444142832511"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p17445628112511"><a name="p17445628112511"></a><a name="p17445628112511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p3445428192510"><a name="p3445428192510"></a><a name="p3445428192510"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p194451828162513"><a name="p194451828162513"></a><a name="p194451828162513"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row154463288259"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1344642872514"><a name="p1344642872514"></a><a name="p1344642872514"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p44461128162511"><a name="p44461128162511"></a><a name="p44461128162511"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19447928172512"><a name="p19447928172512"></a><a name="p19447928172512"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1344712816252"><a name="p1344712816252"></a><a name="p1344712816252"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table9448132812256"></a>
    <table><thead align="left"><tr id="row444818289250"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p54481328202510"><a name="p54481328202510"></a><a name="p54481328202510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p134493285256"><a name="p134493285256"></a><a name="p134493285256"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1044922818255"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p9449528152510"><a name="p9449528152510"></a><a name="p9449528152510"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p17450112818257"><a name="p17450112818257"></a><a name="p17450112818257"></a>Returns <strong id="b15581820165213"><a name="b15581820165213"></a><a name="b15581820165213"></a>true</strong> if the input value is of the <strong id="b9564132095213"><a name="b9564132095213"></a><a name="b9564132095213"></a>Int32Array</strong> type; returns <strong id="b16564520175217"><a name="b16564520175217"></a><a name="b16564520175217"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isInt32Array(new Int32Array([]));
    ```


### isMap<sup>8+</sup><a name="section1384661815275"></a>

isMap\(value: Object\):boolean

Checks whether the input value is of the  **Map**  type.

-   Parameters

    <a name="table284831812274"></a>
    <table><thead align="left"><tr id="row2085011812277"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1985041815272"><a name="p1985041815272"></a><a name="p1985041815272"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p88511018142714"><a name="p88511018142714"></a><a name="p88511018142714"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p585141819276"><a name="p585141819276"></a><a name="p585141819276"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p108511518122719"><a name="p108511518122719"></a><a name="p108511518122719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17852191815275"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p585212185275"><a name="p585212185275"></a><a name="p585212185275"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p18852171810277"><a name="p18852171810277"></a><a name="p18852171810277"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p168531518102711"><a name="p168531518102711"></a><a name="p168531518102711"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p108531818172716"><a name="p108531818172716"></a><a name="p108531818172716"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table2854618182711"></a>
    <table><thead align="left"><tr id="row2854111818273"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p18855101852712"><a name="p18855101852712"></a><a name="p18855101852712"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p5855161852716"><a name="p5855161852716"></a><a name="p5855161852716"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1785691892714"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p158571518172720"><a name="p158571518172720"></a><a name="p158571518172720"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p385701811272"><a name="p385701811272"></a><a name="p385701811272"></a>Returns <strong id="b147254819523"><a name="b147254819523"></a><a name="b147254819523"></a>true</strong> if the input value is of the <strong id="b378194814529"><a name="b378194814529"></a><a name="b378194814529"></a>Map</strong> type; returns <strong id="b1478184845213"><a name="b1478184845213"></a><a name="b1478184845213"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isMap(new Map());
    ```


### isMapIterator<sup>8+</sup><a name="section946511231295"></a>

isMapIterator\(value: Object\):boolean

Checks whether the input value is of the  **MapIterator**  type.

-   Parameters

    <a name="table1467142319295"></a>
    <table><thead align="left"><tr id="row1246842392913"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p54681223202912"><a name="p54681223202912"></a><a name="p54681223202912"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p15469142311296"><a name="p15469142311296"></a><a name="p15469142311296"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1646952314299"><a name="p1646952314299"></a><a name="p1646952314299"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p947022311292"><a name="p947022311292"></a><a name="p947022311292"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row847020237295"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1947014236291"><a name="p1947014236291"></a><a name="p1947014236291"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16471123172916"><a name="p16471123172916"></a><a name="p16471123172916"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3471723172919"><a name="p3471723172919"></a><a name="p3471723172919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1347210234299"><a name="p1347210234299"></a><a name="p1347210234299"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table84727239299"></a>
    <table><thead align="left"><tr id="row20473202392912"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1847319237295"><a name="p1847319237295"></a><a name="p1847319237295"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p447422322916"><a name="p447422322916"></a><a name="p447422322916"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1947462314297"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p11475162317297"><a name="p11475162317297"></a><a name="p11475162317297"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p17475182342912"><a name="p17475182342912"></a><a name="p17475182342912"></a>Returns <strong id="b2442155211535"><a name="b2442155211535"></a><a name="b2442155211535"></a>true</strong> if the input value is of the <strong id="b15448195225317"><a name="b15448195225317"></a><a name="b15448195225317"></a>MapIterator</strong> type; returns <strong id="b13448125217533"><a name="b13448125217533"></a><a name="b13448125217533"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const map = new Map();
    var result = that.isMapIterator(map.keys());
    ```


### isNativeError<sup>8+</sup><a name="section34951303404"></a>

isNativeError\(value: Object\):boolean

Checks whether the input value is of the  **Error**  type.

-   Parameters

    <a name="table1849719015402"></a>
    <table><thead align="left"><tr id="row949810094010"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p12499120194017"><a name="p12499120194017"></a><a name="p12499120194017"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p449930134014"><a name="p449930134014"></a><a name="p449930134014"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1049910019401"><a name="p1049910019401"></a><a name="p1049910019401"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1550018010408"><a name="p1550018010408"></a><a name="p1550018010408"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row35001709404"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p125012034015"><a name="p125012034015"></a><a name="p125012034015"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16501190164011"><a name="p16501190164011"></a><a name="p16501190164011"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1650111074019"><a name="p1650111074019"></a><a name="p1650111074019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p12502104401"><a name="p12502104401"></a><a name="p12502104401"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1850230134012"></a>
    <table><thead align="left"><tr id="row65035024018"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p115035094014"><a name="p115035094014"></a><a name="p115035094014"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p145041805406"><a name="p145041805406"></a><a name="p145041805406"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2504190174014"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p550519016401"><a name="p550519016401"></a><a name="p550519016401"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p85051064014"><a name="p85051064014"></a><a name="p85051064014"></a>Returns <strong id="b153371157135610"><a name="b153371157135610"></a><a name="b153371157135610"></a>true</strong> if the input value is of the <strong id="b33431557175614"><a name="b33431557175614"></a><a name="b33431557175614"></a>Error</strong> type; returns <strong id="b7343115718569"><a name="b7343115718569"></a><a name="b7343115718569"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isNativeError(new TypeError());
    ```


### isNumberObject<sup>8+</sup><a name="section11436189171018"></a>

isNumberObject\(value: Object\):boolean

Checks whether the input value is a number object.

-   Parameters

    <a name="table124391692102"></a>
    <table><thead align="left"><tr id="row1044029111011"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p164401696109"><a name="p164401696109"></a><a name="p164401696109"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1744118911015"><a name="p1744118911015"></a><a name="p1744118911015"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1744119141018"><a name="p1744119141018"></a><a name="p1744119141018"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p14442599107"><a name="p14442599107"></a><a name="p14442599107"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row64428991015"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p5442693104"><a name="p5442693104"></a><a name="p5442693104"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p144435920108"><a name="p144435920108"></a><a name="p144435920108"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p9443393102"><a name="p9443393102"></a><a name="p9443393102"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p11443179151020"><a name="p11443179151020"></a><a name="p11443179151020"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table114441196109"></a>
    <table><thead align="left"><tr id="row144451393107"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p14445179171018"><a name="p14445179171018"></a><a name="p14445179171018"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p544619921015"><a name="p544619921015"></a><a name="p544619921015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row64461395106"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1744649111013"><a name="p1744649111013"></a><a name="p1744649111013"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p24475910104"><a name="p24475910104"></a><a name="p24475910104"></a>Returns <strong id="b1512742914573"><a name="b1512742914573"></a><a name="b1512742914573"></a>true</strong> if the input value is a number object; returns <strong id="b4133929195713"><a name="b4133929195713"></a><a name="b4133929195713"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isNumberObject(new Number(0));
    ```


### isPromise<sup>8+</sup><a name="section150812137"></a>

isPromise\(value: Object\):boolean

Checks whether the input value is a promise.

-   Parameters

    <a name="table2521317137"></a>
    <table><thead align="left"><tr id="row17549161318"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p654121131317"><a name="p654121131317"></a><a name="p654121131317"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p8555171311"><a name="p8555171311"></a><a name="p8555171311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1955518138"><a name="p1955518138"></a><a name="p1955518138"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p256181141317"><a name="p256181141317"></a><a name="p256181141317"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row856914134"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16564114136"><a name="p16564114136"></a><a name="p16564114136"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p115711111314"><a name="p115711111314"></a><a name="p115711111314"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p2057101121313"><a name="p2057101121313"></a><a name="p2057101121313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8571919138"><a name="p8571919138"></a><a name="p8571919138"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table14585111319"></a>
    <table><thead align="left"><tr id="row5593113136"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p660115139"><a name="p660115139"></a><a name="p660115139"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1460131111315"><a name="p1460131111315"></a><a name="p1460131111315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2061217139"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p116191121317"><a name="p116191121317"></a><a name="p116191121317"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p19612171313"><a name="p19612171313"></a><a name="p19612171313"></a>Returns <strong id="b16936124105817"><a name="b16936124105817"></a><a name="b16936124105817"></a>true</strong> if the input value is a promise; returns <strong id="b1394374185817"><a name="b1394374185817"></a><a name="b1394374185817"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isPromise(Promise.resolve(1));
    ```


### isProxy<sup>8+</sup><a name="section13818171212161"></a>

isProxy\(value: Object\):boolean

Checks whether the input value is a proxy.

-   Parameters

    <a name="table11820151251615"></a>
    <table><thead align="left"><tr id="row1821111215162"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p58211112121620"><a name="p58211112121620"></a><a name="p58211112121620"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p12821191211165"><a name="p12821191211165"></a><a name="p12821191211165"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p78226126162"><a name="p78226126162"></a><a name="p78226126162"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p118223125168"><a name="p118223125168"></a><a name="p118223125168"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18823131220162"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15823101221619"><a name="p15823101221619"></a><a name="p15823101221619"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p12823151281616"><a name="p12823151281616"></a><a name="p12823151281616"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p282351291618"><a name="p282351291618"></a><a name="p282351291618"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1824612151614"><a name="p1824612151614"></a><a name="p1824612151614"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1782441216167"></a>
    <table><thead align="left"><tr id="row1382516120167"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p11826121211617"><a name="p11826121211617"></a><a name="p11826121211617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p18826151211614"><a name="p18826151211614"></a><a name="p18826151211614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1182661220167"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p182713121165"><a name="p182713121165"></a><a name="p182713121165"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1982781215163"><a name="p1982781215163"></a><a name="p1982781215163"></a>Returns <strong id="b132191634195812"><a name="b132191634195812"></a><a name="b132191634195812"></a>true</strong> if the input value is a proxy; returns <strong id="b92261834145810"><a name="b92261834145810"></a><a name="b92261834145810"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const target = {};
    const proxy = new Proxy(target, {});
    var result = that.isProxy(proxy);
    ```


### isRegExp<sup>8+</sup><a name="section2265125951815"></a>

isRegExp\(value: Object\):boolean

Checks whether the input value is of the  **RegExp**  type.

-   Parameters

    <a name="table4267135910185"></a>
    <table><thead align="left"><tr id="row82684598182"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p16268125913186"><a name="p16268125913186"></a><a name="p16268125913186"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p8269195911818"><a name="p8269195911818"></a><a name="p8269195911818"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15269659151812"><a name="p15269659151812"></a><a name="p15269659151812"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1269185941812"><a name="p1269185941812"></a><a name="p1269185941812"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1027025941812"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p72709597185"><a name="p72709597185"></a><a name="p72709597185"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p0270185991814"><a name="p0270185991814"></a><a name="p0270185991814"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1927165913181"><a name="p1927165913181"></a><a name="p1927165913181"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6271125991812"><a name="p6271125991812"></a><a name="p6271125991812"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1527255961817"></a>
    <table><thead align="left"><tr id="row6272359191816"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1727320591185"><a name="p1727320591185"></a><a name="p1727320591185"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p12273105921818"><a name="p12273105921818"></a><a name="p12273105921818"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1327314594187"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p7274159141814"><a name="p7274159141814"></a><a name="p7274159141814"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p12741259161818"><a name="p12741259161818"></a><a name="p12741259161818"></a>Returns <strong id="b1521304816489"><a name="b1521304816489"></a><a name="b1521304816489"></a>true</strong> if the input value is of the <strong id="b1512617712517"><a name="b1512617712517"></a><a name="b1512617712517"></a>RegExp</strong> type; returns <strong id="b112191487480"><a name="b112191487480"></a><a name="b112191487480"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isRegExp(new RegExp('abc'));
    ```


### isSet<sup>8+</sup><a name="section15520151262119"></a>

isSet\(value: Object\):boolean

Checks whether the input value is of the  **Set**  type.

-   Parameters

    <a name="table1652251222115"></a>
    <table><thead align="left"><tr id="row65231312122115"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p165232127219"><a name="p165232127219"></a><a name="p165232127219"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p135241412102113"><a name="p135241412102113"></a><a name="p135241412102113"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1452417121214"><a name="p1452417121214"></a><a name="p1452417121214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p552511123214"><a name="p552511123214"></a><a name="p552511123214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row852521292120"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3525712122116"><a name="p3525712122116"></a><a name="p3525712122116"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11526712162110"><a name="p11526712162110"></a><a name="p11526712162110"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p115261512192118"><a name="p115261512192118"></a><a name="p115261512192118"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p252661292112"><a name="p252661292112"></a><a name="p252661292112"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10527412132117"></a>
    <table><thead align="left"><tr id="row13528512132110"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p452816127213"><a name="p452816127213"></a><a name="p452816127213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p852891212214"><a name="p852891212214"></a><a name="p852891212214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1452941210216"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p19530101219218"><a name="p19530101219218"></a><a name="p19530101219218"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p18530312202118"><a name="p18530312202118"></a><a name="p18530312202118"></a>Returns <strong id="b846453119524"><a name="b846453119524"></a><a name="b846453119524"></a>true</strong> if the input value is of the <strong id="b104723314525"><a name="b104723314525"></a><a name="b104723314525"></a>Set</strong> type; returns <strong id="b1447223175215"><a name="b1447223175215"></a><a name="b1447223175215"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isSet(new Set());
    ```


### isSetIterator<sup>8+</sup><a name="section189373192312"></a>

isSetIterator\(value: Object\):boolean

Checks whether the input value is of the  **SetIterator**  type.

-   Parameters

    <a name="table16895173202312"></a>
    <table><thead align="left"><tr id="row20896153142312"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p158971239230"><a name="p158971239230"></a><a name="p158971239230"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1689719302313"><a name="p1689719302313"></a><a name="p1689719302313"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1789716315235"><a name="p1789716315235"></a><a name="p1789716315235"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p16898935239"><a name="p16898935239"></a><a name="p16898935239"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row198981134235"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p48990318230"><a name="p48990318230"></a><a name="p48990318230"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p389913312319"><a name="p389913312319"></a><a name="p389913312319"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1290018342310"><a name="p1290018342310"></a><a name="p1290018342310"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p490019315234"><a name="p490019315234"></a><a name="p490019315234"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1890117332315"></a>
    <table><thead align="left"><tr id="row169011632239"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p109028382310"><a name="p109028382310"></a><a name="p109028382310"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p129021033237"><a name="p129021033237"></a><a name="p129021033237"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99039322316"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1190323142319"><a name="p1190323142319"></a><a name="p1190323142319"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p119035322319"><a name="p119035322319"></a><a name="p119035322319"></a>Returns <strong id="b42921866557"><a name="b42921866557"></a><a name="b42921866557"></a>true</strong> if the input value is of the <strong id="b10298156115518"><a name="b10298156115518"></a><a name="b10298156115518"></a>SetIterator</strong> type; returns <strong id="b152981665553"><a name="b152981665553"></a><a name="b152981665553"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const set = new Set();
    var result = that.isSetIterator(set.keys());
    ```


### isStringObject<sup>8+</sup><a name="section1387616310288"></a>

isStringObject\(value: Object\):boolean

Checks whether the input value is a string object.

-   Parameters

    <a name="table1087810310289"></a>
    <table><thead align="left"><tr id="row188782342813"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1087910315289"><a name="p1087910315289"></a><a name="p1087910315289"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p198795382816"><a name="p198795382816"></a><a name="p198795382816"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p28791335285"><a name="p28791335285"></a><a name="p28791335285"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p14880734287"><a name="p14880734287"></a><a name="p14880734287"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1488014342820"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p188801531289"><a name="p188801531289"></a><a name="p188801531289"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p108813318280"><a name="p108813318280"></a><a name="p108813318280"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19881183152817"><a name="p19881183152817"></a><a name="p19881183152817"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p388233152815"><a name="p388233152815"></a><a name="p388233152815"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1888212382810"></a>
    <table><thead align="left"><tr id="row1988383172814"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p158838319286"><a name="p158838319286"></a><a name="p158838319286"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p28841318289"><a name="p28841318289"></a><a name="p28841318289"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11884634282"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p688403152820"><a name="p688403152820"></a><a name="p688403152820"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p388513142817"><a name="p388513142817"></a><a name="p388513142817"></a>Returns <strong id="b7532162317577"><a name="b7532162317577"></a><a name="b7532162317577"></a>true</strong> if the input value is a string object; returns <strong id="b5532523125711"><a name="b5532523125711"></a><a name="b5532523125711"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isStringObject(new String('foo'));
    ```


### isSymbolObjec<sup>8+</sup><a name="section73596103212"></a>

isSymbolObjec\(value: Object\):boolean

Checks whether the input value is a symbol object.

-   Parameters

    <a name="table14371464328"></a>
    <table><thead align="left"><tr id="row138176123210"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p143826193215"><a name="p143826193215"></a><a name="p143826193215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2039766323"><a name="p2039766323"></a><a name="p2039766323"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p739116143213"><a name="p739116143213"></a><a name="p739116143213"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1393603212"><a name="p1393603212"></a><a name="p1393603212"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1240863320"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p5405663212"><a name="p5405663212"></a><a name="p5405663212"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p941763328"><a name="p941763328"></a><a name="p941763328"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p04196173217"><a name="p04196173217"></a><a name="p04196173217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p04136133212"><a name="p04136133212"></a><a name="p04136133212"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table24276173211"></a>
    <table><thead align="left"><tr id="row134315612322"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p164414683212"><a name="p164414683212"></a><a name="p164414683212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p11441066322"><a name="p11441066322"></a><a name="p11441066322"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row74576173214"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p5451361322"><a name="p5451361322"></a><a name="p5451361322"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p64515623214"><a name="p64515623214"></a><a name="p64515623214"></a>Returns <strong id="b187563538573"><a name="b187563538573"></a><a name="b187563538573"></a>true</strong> if the input value is a symbol object; returns <strong id="b19761153175711"><a name="b19761153175711"></a><a name="b19761153175711"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    const symbols = Symbol('foo');
    var result = that.isSymbolObject(Object(symbols));
    ```


### isTypedArray<sup>8+</sup><a name="section16521458173316"></a>

isTypedArray\(value: Object\):boolean

Checks whether the input value is of the  **TypedArray**  type.

**TypedArray**  is a helper type representing any of the following:  **Int8Array**,  **Int16Array**,  **Int32Array**,  **Uint8Array**,  **Uint8ClampedArray**,  **Uint16Array**,  **Uint32Array**,  **Float32Array**,  **Float64Array**, and  **DataView**.

-   Parameters

    <a name="table1054125863314"></a>
    <table><thead align="left"><tr id="row16565589332"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1856115811332"><a name="p1856115811332"></a><a name="p1856115811332"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1571558193318"><a name="p1571558193318"></a><a name="p1571558193318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p257258153314"><a name="p257258153314"></a><a name="p257258153314"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p857115893315"><a name="p857115893315"></a><a name="p857115893315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195895873312"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1558105853313"><a name="p1558105853313"></a><a name="p1558105853313"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16591758113311"><a name="p16591758113311"></a><a name="p16591758113311"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1460858173313"><a name="p1460858173313"></a><a name="p1460858173313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p186010583337"><a name="p186010583337"></a><a name="p186010583337"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table17610582332"></a>
    <table><thead align="left"><tr id="row136265811338"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1063145815332"><a name="p1063145815332"></a><a name="p1063145815332"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1563758173315"><a name="p1563758173315"></a><a name="p1563758173315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1064195833317"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p464158153316"><a name="p464158153316"></a><a name="p464158153316"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p265205812339"><a name="p265205812339"></a><a name="p265205812339"></a>Returns <strong id="b361151215911"><a name="b361151215911"></a><a name="b361151215911"></a>true</strong> if the input value is of the <strong id="b0278125216593"><a name="b0278125216593"></a><a name="b0278125216593"></a>TypedArray</strong> type; returns <strong id="b8616141225917"><a name="b8616141225917"></a><a name="b8616141225917"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isTypedArray(new Float64Array([]));
    ```


### isUint8Array<sup>8+</sup><a name="section65351014392"></a>

isUint8Array\(value: Object\):boolean

Checks whether the input value is of the  **Uint8Array**  type.

-   Parameters

    <a name="table125541023910"></a>
    <table><thead align="left"><tr id="row1056191018394"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p105731013397"><a name="p105731013397"></a><a name="p105731013397"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p125715104392"><a name="p125715104392"></a><a name="p125715104392"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p05841093920"><a name="p05841093920"></a><a name="p05841093920"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p858111017393"><a name="p858111017393"></a><a name="p858111017393"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row45913108396"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p185991020393"><a name="p185991020393"></a><a name="p185991020393"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1660310163915"><a name="p1660310163915"></a><a name="p1660310163915"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3601210163918"><a name="p3601210163918"></a><a name="p3601210163918"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p116161073917"><a name="p116161073917"></a><a name="p116161073917"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table176141053914"></a>
    <table><thead align="left"><tr id="row163121023914"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p863181017391"><a name="p863181017391"></a><a name="p863181017391"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1964131015394"><a name="p1964131015394"></a><a name="p1964131015394"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1565131023911"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p76591017393"><a name="p76591017393"></a><a name="p76591017393"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p156621093917"><a name="p156621093917"></a><a name="p156621093917"></a>Returns <strong id="b32061315504"><a name="b32061315504"></a><a name="b32061315504"></a>true</strong> if the input value is of the <strong id="b1821220156017"><a name="b1821220156017"></a><a name="b1821220156017"></a>Uint8Array</strong> type; returns <strong id="b1121211513017"><a name="b1121211513017"></a><a name="b1121211513017"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isUint8Array(new Uint8Array([]));
    ```


### isUint8ClampedArray<sup>8+</sup><a name="section13121164016419"></a>

isUint8ClampedArray\(value: Object\):boolean

Checks whether the input value is of the  **Uint8ClampedArray**  type.

-   Parameters

    <a name="table21231940164113"></a>
    <table><thead align="left"><tr id="row21247404419"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11125940194110"><a name="p11125940194110"></a><a name="p11125940194110"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p201251540164114"><a name="p201251540164114"></a><a name="p201251540164114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1512644019419"><a name="p1512644019419"></a><a name="p1512644019419"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p171261640204117"><a name="p171261640204117"></a><a name="p171261640204117"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11261140124111"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2127174013414"><a name="p2127174013414"></a><a name="p2127174013414"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p8127194013418"><a name="p8127194013418"></a><a name="p8127194013418"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p16128154011417"><a name="p16128154011417"></a><a name="p16128154011417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18128540154116"><a name="p18128540154116"></a><a name="p18128540154116"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table19128240164110"></a>
    <table><thead align="left"><tr id="row161295408419"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p7129204014118"><a name="p7129204014118"></a><a name="p7129204014118"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p3130740104110"><a name="p3130740104110"></a><a name="p3130740104110"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row121303401416"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1313120405413"><a name="p1313120405413"></a><a name="p1313120405413"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p51314408419"><a name="p51314408419"></a><a name="p51314408419"></a>Returns <strong id="b107504431019"><a name="b107504431019"></a><a name="b107504431019"></a>true</strong> if the input value is of the <strong id="b275514432009"><a name="b275514432009"></a><a name="b275514432009"></a>Uint8ClampedArray</strong> type; returns <strong id="b13755174310016"><a name="b13755174310016"></a><a name="b13755174310016"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isUint8ClampedArray(new Uint8ClampedArray([]));
    ```


### isUint16Array<sup>8+</sup><a name="section9290141310444"></a>

isUint16Array\(value: Object\):boolean

Checks whether the input value is of the  **Uint16Array**  type.

-   Parameters

    <a name="table329261394414"></a>
    <table><thead align="left"><tr id="row1129451312447"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p162949136448"><a name="p162949136448"></a><a name="p162949136448"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p11295913154415"><a name="p11295913154415"></a><a name="p11295913154415"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p102951913164416"><a name="p102951913164416"></a><a name="p102951913164416"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p329601316447"><a name="p329601316447"></a><a name="p329601316447"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row729641317448"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1429711310440"><a name="p1429711310440"></a><a name="p1429711310440"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p17297413194410"><a name="p17297413194410"></a><a name="p17297413194410"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1729801313445"><a name="p1729801313445"></a><a name="p1729801313445"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p429811314445"><a name="p429811314445"></a><a name="p429811314445"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1299141384419"></a>
    <table><thead align="left"><tr id="row730031374412"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p19301713164418"><a name="p19301713164418"></a><a name="p19301713164418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p17302413114415"><a name="p17302413114415"></a><a name="p17302413114415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183025131443"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p330341374414"><a name="p330341374414"></a><a name="p330341374414"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p930381310449"><a name="p930381310449"></a><a name="p930381310449"></a>Returns <strong id="b2598413910"><a name="b2598413910"></a><a name="b2598413910"></a>true</strong> if the input value is of the <strong id="b136031131613"><a name="b136031131613"></a><a name="b136031131613"></a>Uint16Array</strong> type; returns <strong id="b160320131519"><a name="b160320131519"></a><a name="b160320131519"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isUint16Array(new Uint16Array([]));
    ```


### isUint32Array<sup>8+</sup><a name="section1586411524611"></a>

isUint32Array\(value: Object\):boolean

Checks whether the input value is of the  **Uint32Array**  type.

-   Parameters

    <a name="table1886719158462"></a>
    <table><thead align="left"><tr id="row148691815174613"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p3869121564618"><a name="p3869121564618"></a><a name="p3869121564618"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p10870215184614"><a name="p10870215184614"></a><a name="p10870215184614"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p138721715154615"><a name="p138721715154615"></a><a name="p138721715154615"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p208731815174620"><a name="p208731815174620"></a><a name="p208731815174620"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15873101564616"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11874141514469"><a name="p11874141514469"></a><a name="p11874141514469"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4874131584613"><a name="p4874131584613"></a><a name="p4874131584613"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13874161516460"><a name="p13874161516460"></a><a name="p13874161516460"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p187591514620"><a name="p187591514620"></a><a name="p187591514620"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table8876715164616"></a>
    <table><thead align="left"><tr id="row17877191517468"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p148780159465"><a name="p148780159465"></a><a name="p148780159465"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p68781015164614"><a name="p68781015164614"></a><a name="p68781015164614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row148781515104611"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p6879111510462"><a name="p6879111510462"></a><a name="p6879111510462"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p8880115104616"><a name="p8880115104616"></a><a name="p8880115104616"></a>Returns <strong id="b172068381115"><a name="b172068381115"></a><a name="b172068381115"></a>true</strong> if the input value is of the <strong id="b421203810119"><a name="b421203810119"></a><a name="b421203810119"></a>Uint32Array</strong> type; returns <strong id="b521217388120"><a name="b521217388120"></a><a name="b521217388120"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isUint32Array(new Uint32Array([]));
    ```


### isWeakMap<sup>8+</sup><a name="section112812117472"></a>

isWeakMap\(value: Object\):boolean

Checks whether the input value is of the  **WeakMap**  type.

-   Parameters

    <a name="table7311011114713"></a>
    <table><thead align="left"><tr id="row12345112471"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13431144713"><a name="p13431144713"></a><a name="p13431144713"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1535191114710"><a name="p1535191114710"></a><a name="p1535191114710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p93591184716"><a name="p93591184716"></a><a name="p93591184716"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p83581116470"><a name="p83581116470"></a><a name="p83581116470"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7361811134717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p123651164718"><a name="p123651164718"></a><a name="p123651164718"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10371911154714"><a name="p10371911154714"></a><a name="p10371911154714"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1837101115470"><a name="p1837101115470"></a><a name="p1837101115470"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1238141134713"><a name="p1238141134713"></a><a name="p1238141134713"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table17382112473"></a>
    <table><thead align="left"><tr id="row1639111134710"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p4391111154718"><a name="p4391111154718"></a><a name="p4391111154718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p84031164712"><a name="p84031164712"></a><a name="p84031164712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row440161113474"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p20415117478"><a name="p20415117478"></a><a name="p20415117478"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p641191111471"><a name="p641191111471"></a><a name="p641191111471"></a>Returns <strong id="b185011731321"><a name="b185011731321"></a><a name="b185011731321"></a>true</strong> if the input value is of the <strong id="b850613028"><a name="b850613028"></a><a name="b850613028"></a>WeakMap</strong> type; returns <strong id="b9507633211"><a name="b9507633211"></a><a name="b9507633211"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isWeakMap(new WeakMap());
    ```


### isWeakSet<sup>8+</sup><a name="section25413820516"></a>

isWeakSet\(value: Object\):boolean

Checks whether the input value is of the  **WeakSet**  type.

-   Parameters

    <a name="table654313816516"></a>
    <table><thead align="left"><tr id="row65441865111"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p754588115118"><a name="p754588115118"></a><a name="p754588115118"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1654513817515"><a name="p1654513817515"></a><a name="p1654513817515"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p65467816518"><a name="p65467816518"></a><a name="p65467816518"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1854608135112"><a name="p1854608135112"></a><a name="p1854608135112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19547081518"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p154798165110"><a name="p154798165110"></a><a name="p154798165110"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p554868175114"><a name="p554868175114"></a><a name="p554868175114"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p85481981515"><a name="p85481981515"></a><a name="p85481981515"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p135492084517"><a name="p135492084517"></a><a name="p135492084517"></a>Object to check.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1154919815119"></a>
    <table><thead align="left"><tr id="row125513855111"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p145525816516"><a name="p145525816516"></a><a name="p145525816516"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p145524815512"><a name="p145524815512"></a><a name="p145524815512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row35534865115"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p165535835117"><a name="p165535835117"></a><a name="p165535835117"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p855448155119"><a name="p855448155119"></a><a name="p855448155119"></a>Returns <strong id="b239417235210"><a name="b239417235210"></a><a name="b239417235210"></a>true</strong> if the input value is of the <strong id="b184004232215"><a name="b184004232215"></a><a name="b184004232215"></a>WeakSet</strong> type; returns <strong id="b1140015231521"><a name="b1140015231521"></a><a name="b1140015231521"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var that = new util.Types();
    var result = that.isWeakSet(new WeakSet());
    ```


