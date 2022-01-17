# String Encoding and Decoding<a name="EN-US_TOPIC_0000001126516726"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import util from '@ohos.util';
```

## Required Permissions<a name="section11257113618419"></a>

None

## util.printf<a name="section192192415554"></a>

printf\(format: string, ...args: Object\[\]\): string

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
    var errnum = 10; // 10: a system error number
    var result = util.getErrorString(errnum);
    console.log("result = " + result);
    ```


## util.callbackWrapper<a name="section15594104112592"></a>

callbackWrapper\(original: Function\): \(err: Object, value: Object\)=\>void

Calls back an asynchronous function. In the callback, the first parameter indicates the cause of the rejection \(if the promise has been resolved, the value is  **null**\), and the second parameter indicates the resolved value.

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
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1471526810"><a name="p1471526810"></a><a name="p1471526810"></a>Asynchronous function.</p>
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
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1759984114595"><a name="p1759984114595"></a><a name="p1759984114595"></a>Callback, in which the first parameter indicates the cause of the rejection (the value is <strong id="b351412011344"><a name="b351412011344"></a><a name="b351412011344"></a>null</strong> if the promise has been resolved) and the second parameter indicates the resolved value.</p>
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
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p125051140151213"><a name="p125051140151213"></a><a name="p125051140151213"></a>Function in the common error-first style (that is, (err, uses value) =&gt;... is used as the last parameter) and the promise version.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p348319442351"><a name="p348319442351"></a><a name="p348319442351"></a>Whether to ignore the byte order marker (BOM). The default value is <strong id="b1171310374438"><a name="b1171310374438"></a><a name="b1171310374438"></a>false</strong>.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section6179915133611"></a>

constructor\(encoding?: string, options?: \{ fatal?: boolean; ignoreBOM?: boolean \},\)

A constructor used to create a  **TextDecoder**  instance.

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
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p7122142317382"><a name="p7122142317382"></a><a name="p7122142317382"></a>Encoding-related options, which include <strong id="b259414100519"><a name="b259414100519"></a><a name="b259414100519"></a>fatal</strong> and <strong id="b172344154512"><a name="b172344154512"></a><a name="b172344154512"></a>ignoreBOM</strong>.</p>
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

decode\(input: Uint8Array, options?:\{stream?:false\}\): string

Decodes the input parameters and outputs the text.

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p47857813448"><a name="p47857813448"></a><a name="p47857813448"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p147859815443"><a name="p147859815443"></a><a name="p147859815443"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2713276190"><a name="p2713276190"></a><a name="p2713276190"></a>Uint8Array to decode.</p>
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
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p3958113385114"><a name="p3958113385114"></a><a name="p3958113385114"></a>Whether to allow data blocks in the subsequent <strong id="b41311461508"><a name="b41311461508"></a><a name="b41311461508"></a>decode()</strong>. Set this parameter to <strong id="b2441154617557"><a name="b2441154617557"></a><a name="b2441154617557"></a>true</strong> if data blocks are processed. If data is not divided into blocks or the last data block is processed, set this parameter to <strong id="b31551822185816"><a name="b31551822185816"></a><a name="b31551822185816"></a>false</strong>. The default value is <strong id="b14741141010919"><a name="b14741141010919"></a><a name="b14741141010919"></a>false</strong>.</p>
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
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7288893020"><a name="p7288893020"></a><a name="p7288893020"></a>Encoding format. The default value is <strong id="b1752715273495"><a name="b1752715273495"></a><a name="b1752715273495"></a>utf-8</strong>.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section19850195154719"></a>

constructor\(\)

A constructor used to create a  **TextEncoder**  instance.

-   Example

    ```
    var textEncoder = new util.TextEncoder();
    ```


### encode<a name="section16144104844716"></a>

encode\(input?: string\): Uint8Array

Encodes the input parameter.

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

encodeInto\(input: string, dest: Uint8Array,\):\{ read: number; written: number \}

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
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p176551313171516"><a name="p176551313171516"></a><a name="p176551313171516"></a>String to encode.</p>
    </td>
    </tr>
    <tr id="row208371178497"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p98372719499"><a name="p98372719499"></a><a name="p98372719499"></a>dest</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1483715754912"><a name="p1483715754912"></a><a name="p1483715754912"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p38373712497"><a name="p38373712497"></a><a name="p38373712497"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13837107144913"><a name="p13837107144913"></a><a name="p13837107144913"></a>Uint8Array instance used to store the UTF-8 encoded text.</p>
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


