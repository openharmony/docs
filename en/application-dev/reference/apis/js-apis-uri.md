# URI String Parsing<a name="EN-US_TOPIC_0000001206361591"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="section2080512344162"></a>

```
import uri from '@ohos.uri'  
```

## Required Permissions<a name="section11257113618419"></a>

None

## URI<a name="section148871646203714"></a>

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
<tbody><tr id="row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1832319183511"><a name="p1832319183511"></a><a name="p1832319183511"></a>scheme</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p3482124417356"><a name="p3482124417356"></a><a name="p3482124417356"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p16483194443514"><a name="p16483194443514"></a><a name="p16483194443514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p630714163422"><a name="p630714163422"></a><a name="p630714163422"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p72131224114411"><a name="p72131224114411"></a><a name="p72131224114411"></a>Protocol in the URI.</p>
</td>
</tr>
<tr id="row58631729183511"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1669917383355"><a name="p1669917383355"></a><a name="p1669917383355"></a>userinfo</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p986510296359"><a name="p986510296359"></a><a name="p986510296359"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p14865182993518"><a name="p14865182993518"></a><a name="p14865182993518"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1586552915355"><a name="p1586552915355"></a><a name="p1586552915355"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p12865829133514"><a name="p12865829133514"></a><a name="p12865829133514"></a>User information in the URI.</p>
</td>
</tr>
<tr id="row173737374371"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p73744376373"><a name="p73744376373"></a><a name="p73744376373"></a>host</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p183741337173714"><a name="p183741337173714"></a><a name="p183741337173714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p13374237173711"><a name="p13374237173711"></a><a name="p13374237173711"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1737416372376"><a name="p1737416372376"></a><a name="p1737416372376"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p737414373372"><a name="p737414373372"></a><a name="p737414373372"></a>Host name (without the port number) in the URI.</p>
</td>
</tr>
<tr id="row18603545143715"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1360410454373"><a name="p1360410454373"></a><a name="p1360410454373"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1260410456378"><a name="p1260410456378"></a><a name="p1260410456378"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p146042453371"><a name="p146042453371"></a><a name="p146042453371"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p460416456374"><a name="p460416456374"></a><a name="p460416456374"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p3153171613242"><a name="p3153171613242"></a><a name="p3153171613242"></a>Port number in the URI.</p>
</td>
</tr>
<tr id="row15118124793712"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p9121914204110"><a name="p9121914204110"></a><a name="p9121914204110"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p41181471376"><a name="p41181471376"></a><a name="p41181471376"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p10118447153719"><a name="p10118447153719"></a><a name="p10118447153719"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1111884793714"><a name="p1111884793714"></a><a name="p1111884793714"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18565132916244"><a name="p18565132916244"></a><a name="p18565132916244"></a>Path in the URI.</p>
</td>
</tr>
<tr id="row2998164312378"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p20998643103713"><a name="p20998643103713"></a><a name="p20998643103713"></a>query</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p1899804315372"><a name="p1899804315372"></a><a name="p1899804315372"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1399820431377"><a name="p1399820431377"></a><a name="p1399820431377"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p29980434371"><a name="p29980434371"></a><a name="p29980434371"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1299814373714"><a name="p1299814373714"></a><a name="p1299814373714"></a>Query part in the URI.</p>
</td>
</tr>
<tr id="row6527542193711"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1852784212370"><a name="p1852784212370"></a><a name="p1852784212370"></a>fragment</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p205271742183711"><a name="p205271742183711"></a><a name="p205271742183711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p952724233717"><a name="p952724233717"></a><a name="p952724233717"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1452784214373"><a name="p1452784214373"></a><a name="p1452784214373"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18527842143718"><a name="p18527842143718"></a><a name="p18527842143718"></a>Fragment part in the URI.</p>
</td>
</tr>
<tr id="row1221604019378"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p12161040193711"><a name="p12161040193711"></a><a name="p12161040193711"></a>authority</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p12161040103714"><a name="p12161040103714"></a><a name="p12161040103714"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p621674073715"><a name="p621674073715"></a><a name="p621674073715"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1821624033711"><a name="p1821624033711"></a><a name="p1821624033711"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1421614403377"><a name="p1421614403377"></a><a name="p1421614403377"></a>Authority part in the URI.</p>
</td>
</tr>
<tr id="row763211357376"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1863313520378"><a name="p1863313520378"></a><a name="p1863313520378"></a>ssp</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p8633113583715"><a name="p8633113583715"></a><a name="p8633113583715"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1663363533710"><a name="p1663363533710"></a><a name="p1663363533710"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1763312358374"><a name="p1763312358374"></a><a name="p1763312358374"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p363383518374"><a name="p363383518374"></a><a name="p363383518374"></a>Scheme-specific part in the URI.</p>
</td>
</tr>
</tbody>
</table>

### constructor<a name="section796748155213"></a>

constructor\(uri: string\)

A constructor used to create a URI instance.

-   Parameters

    <a name="table1723015271384"></a>
    <table><thead align="left"><tr id="row42301327153814"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p102307272383"><a name="p102307272383"></a><a name="p102307272383"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p202307278382"><a name="p202307278382"></a><a name="p202307278382"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p19231227113813"><a name="p19231227113813"></a><a name="p19231227113813"></a>Readable</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1123113278381"><a name="p1123113278381"></a><a name="p1123113278381"></a>Writable</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p5231172773815"><a name="p5231172773815"></a><a name="p5231172773815"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row122318279387"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p161271253807"><a name="p161271253807"></a><a name="p161271253807"></a>url</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p11231102719382"><a name="p11231102719382"></a><a name="p11231102719382"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p182311827173812"><a name="p182311827173812"></a><a name="p182311827173812"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1023152712389"><a name="p1023152712389"></a><a name="p1023152712389"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p323132783819"><a name="p323132783819"></a><a name="p323132783819"></a>Input parameter object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var mm = 'http://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
    new uri.URI(mm); // Output 'http://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
    ```

    ```
    new uri.URI('http://username:password@host:8080'); // Output 'http://username:password@host:8080';
    ```


### toString<a name="section1520812025513"></a>

toString\(\): string

Obtains the query string applicable to this URL.

-   Return values

    <a name="table201041412244"></a>
    <table><thead align="left"><tr id="row410431122411"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p110413182418"><a name="p110413182418"></a><a name="p110413182418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p181042116249"><a name="p181042116249"></a><a name="p181042116249"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row110421182413"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p510461102411"><a name="p510461102411"></a><a name="p510461102411"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p159992542327"><a name="p159992542327"></a><a name="p159992542327"></a>Website address in a serialized string.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    const url = new uri.URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    url.toString()
    ```


### equals<a name="section8201184114551"></a>

equals\(other: URI\): boolean

Checks whether this URI is the same as another URI object.

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
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>other</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p780818507106"><a name="p780818507106"></a><a name="p780818507106"></a><a href="#section148871646203714">URI</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>URI object to compare.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table648816575178"></a>
    <table><thead align="left"><tr id="row54897577177"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p548916576172"><a name="p548916576172"></a><a name="p548916576172"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p748995711718"><a name="p748995711718"></a><a name="p748995711718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row448917570178"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p848910579172"><a name="p848910579172"></a><a name="p848910579172"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p18489257161712"><a name="p18489257161712"></a><a name="p18489257161712"></a>Returns <strong id="b137321971865"><a name="b137321971865"></a><a name="b137321971865"></a>true</strong> if the two URIs are the same; returns <strong id="b1160661310617"><a name="b1160661310617"></a><a name="b1160661310617"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    const uriInstance = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
    const uriInstance1 = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da#fragment');
    uriInstance.equals(uriInstance1);
    ```


### checkIsAbsolute<a name="section17961333135611"></a>

checkIsAbsolute\(\): boolean

Checks whether this URI is an absolute URI \(whether the scheme component is defined\).

-   Return values

    <a name="table10605130142117"></a>
    <table><thead align="left"><tr id="row156051502216"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1260640112112"><a name="p1260640112112"></a><a name="p1260640112112"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p136062012215"><a name="p136062012215"></a><a name="p136062012215"></a><strong id="b33155560324644"><a name="b33155560324644"></a><a name="b33155560324644"></a>Description</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row176062022120"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p19606140142119"><a name="p19606140142119"></a><a name="p19606140142119"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p2060690182114"><a name="p2060690182114"></a><a name="p2060690182114"></a>Returns <strong id="b1461184214711"><a name="b1461184214711"></a><a name="b1461184214711"></a>true</strong> if the URI is an absolute URI; returns <strong id="b13725458815"><a name="b13725458815"></a><a name="b13725458815"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    const uriInstance = new uri.URI('http://username:password@www.qwer.com:8080?query=pppppp');
    uriInstance.checkIsAbsolute();
    ```


### normalize<a name="section974214585573"></a>

normalize\(\): URI

Normalizes the path of this URI.

-   Return values

    <a name="table981932613263"></a>
    <table><thead align="left"><tr id="row38194264264"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p178208263269"><a name="p178208263269"></a><a name="p178208263269"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p15820112672617"><a name="p15820112672617"></a><a name="p15820112672617"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2820172622610"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p13820122613264"><a name="p13820122613264"></a><a name="p13820122613264"></a>URI</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p18497141212339"><a name="p18497141212339"></a><a name="p18497141212339"></a>URI with the normalized path.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    const uriInstance = new uri.URI('http://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
    let uriInstance1 = uriInstance.normalize();
    uriInstance1.path;
    ```


