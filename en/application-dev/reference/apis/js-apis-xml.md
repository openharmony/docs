# XML Parsing and Generation<a name="EN-US_TOPIC_0000001166576450"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import xml from '@ohos.xml';
```

## Required Permissions<a name="section11257113618419"></a>

None

## XmlSerializer<a name="section10300157155214"></a>

### constructor<a name="section22631719185510"></a>

constructor\(buffer: ArrayBuffer | DataView, encoding?: string\)

A constructor used to create an  **XmlSerializer**  instance.

-   Parameters

    <a name="table371837193011"></a>
    <table><thead align="left"><tr id="row672173723013"><th class="cellrowborder" valign="top" width="10.05%" id="mcps1.1.5.1.1"><p id="p1272203710304"><a name="p1272203710304"></a><a name="p1272203710304"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.8%" id="mcps1.1.5.1.2"><p id="p1172103715308"><a name="p1172103715308"></a><a name="p1172103715308"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.86%" id="mcps1.1.5.1.3"><p id="p2072537153017"><a name="p2072537153017"></a><a name="p2072537153017"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1572193715303"><a name="p1572193715303"></a><a name="p1572193715303"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row673153793010"><td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.1 "><p id="p197373763013"><a name="p197373763013"></a><a name="p197373763013"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.8%" headers="mcps1.1.5.1.2 "><p id="p1773337193020"><a name="p1773337193020"></a><a name="p1773337193020"></a>ArrayBuffer | DataView</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.86%" headers="mcps1.1.5.1.3 "><p id="p27313376302"><a name="p27313376302"></a><a name="p27313376302"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19731837133019"><a name="p19731837133019"></a><a name="p19731837133019"></a><strong id="b176576351735"><a name="b176576351735"></a><a name="b176576351735"></a>ArrayBuffer</strong> or <strong id="b14983539439"><a name="b14983539439"></a><a name="b14983539439"></a>DataView</strong> for storing the XML information to write.</p>
    </td>
    </tr>
    <tr id="row873937133017"><td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.1 "><p id="p573837113014"><a name="p573837113014"></a><a name="p573837113014"></a>encoding</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.8%" headers="mcps1.1.5.1.2 "><p id="p1473837163016"><a name="p1473837163016"></a><a name="p1473837163016"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.86%" headers="mcps1.1.5.1.3 "><p id="p1574153711306"><a name="p1574153711306"></a><a name="p1574153711306"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p107416372308"><a name="p107416372308"></a><a name="p107416372308"></a>Encoding format.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var bufView = new DataView(arrayBuffer);
    var thatSer = new xml.XmlSerializer(bufView);
    ```


### setAttributes<a name="section2473132013521"></a>

setAttributes\(name: string, value: string\): void

Sets an attribute.

-   Parameters

    <a name="table89671419586"></a>
    <table><thead align="left"><tr id="row1296813405817"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p9968649587"><a name="p9968649587"></a><a name="p9968649587"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p896816415583"><a name="p896816415583"></a><a name="p896816415583"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p19684475811"><a name="p19684475811"></a><a name="p19684475811"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p15969124195818"><a name="p15969124195818"></a><a name="p15969124195818"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1096919414582"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p19764172525816"><a name="p19764172525816"></a><a name="p19764172525816"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p209702418584"><a name="p209702418584"></a><a name="p209702418584"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p20970240582"><a name="p20970240582"></a><a name="p20970240582"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5218548142218"><a name="p5218548142218"></a><a name="p5218548142218"></a>Key of the attribute.</p>
    </td>
    </tr>
    <tr id="row14970184165815"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1996411319585"><a name="p1996411319585"></a><a name="p1996411319585"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p7961171375814"><a name="p7961171375814"></a><a name="p7961171375814"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1995771345820"><a name="p1995771345820"></a><a name="p1995771345820"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19532013165816"><a name="p19532013165816"></a><a name="p19532013165816"></a>Value of the attribute.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var thatSer = new xml.XmlSerializer(bufView);
    thatSer.setAttributes("importance", "high");
    ```


### addEmptyElement<a name="section66211195611"></a>

addEmptyElement\(name: string\): void

Adds an empty element.

-   Parameters

    <a name="table14404194817135"></a>
    <table><thead align="left"><tr id="row14051748131319"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1440574821316"><a name="p1440574821316"></a><a name="p1440574821316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p204051548111311"><a name="p204051548111311"></a><a name="p204051548111311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p34056481132"><a name="p34056481132"></a><a name="p34056481132"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p5405548161318"><a name="p5405548161318"></a><a name="p5405548161318"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14063484130"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13406348101319"><a name="p13406348101319"></a><a name="p13406348101319"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p340613481134"><a name="p340613481134"></a><a name="p340613481134"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p14062486135"><a name="p14062486135"></a><a name="p14062486135"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2406248191315"><a name="p2406248191315"></a><a name="p2406248191315"></a>Name of the empty element to add.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var thatSer = new xml.XmlSerializer(bufView);
    thatSer.addEmptyElement("b"); // => <b/>
    ```


### setDeclaration<a name="section86274211981"></a>

setDeclaration\(\): void

Sets a declaration.

-   Example

    ```
    var thatSer = new xml.XmlSerializer(bufView);
    thatSer.setDeclaration() // => <?xml version="1.0" encoding="utf-8"?>;
    ```


### startElement<a name="section7242102181610"></a>

startElement\(name: string\): void

Writes the start tag based on the given element name.

-   Parameters

    <a name="table181414461248"></a>
    <table><thead align="left"><tr id="row714104612417"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8141546112417"><a name="p8141546112417"></a><a name="p8141546112417"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p14151546172412"><a name="p14151546172412"></a><a name="p14151546172412"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1615114619244"><a name="p1615114619244"></a><a name="p1615114619244"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p121514469247"><a name="p121514469247"></a><a name="p121514469247"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1615204662414"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p415114614249"><a name="p415114614249"></a><a name="p415114614249"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p6151246192420"><a name="p6151246192420"></a><a name="p6151246192420"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p71574612247"><a name="p71574612247"></a><a name="p71574612247"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p415946132417"><a name="p415946132417"></a><a name="p415946132417"></a>Name of the element.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.startElement("notel");
    thatSer.endElement();// => '<notel/>';
    ```


### endElement<a name="section357918382815"></a>

endElement\(\): void

Writes the end tag of the element.

-   Example

    ```
    var thatSer = new xml.XmlSerializer(bufView);
    thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
    thatSer.startElement("table");
    thatSer.setAttributes("importance", "high");
    thatSer.setText("Happy");
    endElement(); // => <h:table importance="high" xmlns:h="http://www.w3.org/TR/html4/">Happy</h:table>
    ```


### setNamespace<a name="section04112422818"></a>

setNamespace\(prefix: string, namespace: string\): void

Sets the namespace for an element tag.

-   Parameters

    <a name="table8646118202914"></a>
    <table><thead align="left"><tr id="row18646131812296"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19646118172919"><a name="p19646118172919"></a><a name="p19646118172919"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p364731813291"><a name="p364731813291"></a><a name="p364731813291"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p06473184299"><a name="p06473184299"></a><a name="p06473184299"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p66471618172920"><a name="p66471618172920"></a><a name="p66471618172920"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1564701813298"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7647101892919"><a name="p7647101892919"></a><a name="p7647101892919"></a>prefix</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p064761822918"><a name="p064761822918"></a><a name="p064761822918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p36471718162912"><a name="p36471718162912"></a><a name="p36471718162912"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1564731811292"><a name="p1564731811292"></a><a name="p1564731811292"></a>Prefix of the element and its child elements.</p>
    </td>
    </tr>
    <tr id="row5285142452918"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p112861824192919"><a name="p112861824192919"></a><a name="p112861824192919"></a>namespace</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1728692413299"><a name="p1728692413299"></a><a name="p1728692413299"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p14994496295"><a name="p14994496295"></a><a name="p14994496295"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1428714245297"><a name="p1428714245297"></a><a name="p1428714245297"></a>Namespace to set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.setDeclaration();
    thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
    thatSer.startElement("note");
    thatSer.endElement();// = >'<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';
    ```


### setComment<a name="section1174418441186"></a>

setComment\(text: string\): void

Sets the comment.

-   Parameters

    <a name="table59902223516"></a>
    <table><thead align="left"><tr id="row1699117253518"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p09911122354"><a name="p09911122354"></a><a name="p09911122354"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p209911128359"><a name="p209911128359"></a><a name="p209911128359"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1899119203517"><a name="p1899119203517"></a><a name="p1899119203517"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p19991725355"><a name="p19991725355"></a><a name="p19991725355"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row59921026357"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2099232153520"><a name="p2099232153520"></a><a name="p2099232153520"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1992729353"><a name="p1992729353"></a><a name="p1992729353"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p9992182173517"><a name="p9992182173517"></a><a name="p9992182173517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1399210223514"><a name="p1399210223514"></a><a name="p1399210223514"></a>Comment to set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.startElement("note");
    thatSer.setComment("Hi!");
    thatSer.endElement(); // => '<note>\r\n  <!--Hi!-->\r\n</note>';
    ```


### setCDATA<a name="section812915481985"></a>

setCDATA\(text: string\): void

Sets CDATA attributes.

-   Parameters

    <a name="table374175311366"></a>
    <table><thead align="left"><tr id="row475175323615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1775553183620"><a name="p1775553183620"></a><a name="p1775553183620"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2075053103617"><a name="p2075053103617"></a><a name="p2075053103617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p67565310368"><a name="p67565310368"></a><a name="p67565310368"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1575153143612"><a name="p1575153143612"></a><a name="p1575153143612"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17525323615"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p47575316364"><a name="p47575316364"></a><a name="p47575316364"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2076105323611"><a name="p2076105323611"></a><a name="p2076105323611"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1776653183610"><a name="p1776653183610"></a><a name="p1776653183610"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p276135313620"><a name="p276135313620"></a><a name="p276135313620"></a>CDATA attribute to set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1028);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.setCDATA('root SYSTEM') // => '<![CDATA[root SYSTEM]]>';
    ```


### setText<a name="section265019491814"></a>

setText\(text: string\): void

Sets  **Text**.

-   Parameters

    <a name="table136227583373"></a>
    <table><thead align="left"><tr id="row1662355863713"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p86235584376"><a name="p86235584376"></a><a name="p86235584376"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p106231958103718"><a name="p106231958103718"></a><a name="p106231958103718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p3624458193719"><a name="p3624458193719"></a><a name="p3624458193719"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1762425863715"><a name="p1762425863715"></a><a name="p1762425863715"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row762405815376"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p062475843712"><a name="p062475843712"></a><a name="p062475843712"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1362412588379"><a name="p1362412588379"></a><a name="p1362412588379"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1062435814373"><a name="p1062435814373"></a><a name="p1062435814373"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17625105833713"><a name="p17625105833713"></a><a name="p17625105833713"></a>Content of the <strong id="b47250195582"><a name="b47250195582"></a><a name="b47250195582"></a>Text</strong> to set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.startElement("note");
    thatSer.setAttributes("importance", "high");
    thatSer.setText("Happy1");
    thatSer.endElement(); // => '<note importance="high">Happy1</note>';
    ```


### setDocType<a name="section104216510819"></a>

setDocType\(text: string\): void

Sets  **DocType**.

-   Parameters

    <a name="table144314794016"></a>
    <table><thead align="left"><tr id="row1443167184014"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p174437734018"><a name="p174437734018"></a><a name="p174437734018"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.719999999999999%" id="mcps1.1.5.1.2"><p id="p2443177184017"><a name="p2443177184017"></a><a name="p2443177184017"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.5.1.3"><p id="p1544467124019"><a name="p1544467124019"></a><a name="p1544467124019"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1444117134017"><a name="p1444117134017"></a><a name="p1444117134017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2444975406"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p544497124013"><a name="p544497124013"></a><a name="p544497124013"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.719999999999999%" headers="mcps1.1.5.1.2 "><p id="p1644411764014"><a name="p1644411764014"></a><a name="p1644411764014"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.5.1.3 "><p id="p12444117204011"><a name="p12444117204011"></a><a name="p12444117204011"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1944520774014"><a name="p1944520774014"></a><a name="p1944520774014"></a>Content of <strong id="b18701135915"><a name="b18701135915"></a><a name="b18701135915"></a>DocType</strong> to set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var arrayBuffer = new ArrayBuffer(1024);
    var thatSer = new xml.XmlSerializer(arrayBuffer);
    thatSer.setDocType('root SYSTEM'); // => '<!DOCTYPE root SYSTEM>';
    ```


## XmlPullParser<a name="section13701854986"></a>

### XmlPullParser<a name="section837014541082"></a>

constructor\(buffer: ArrayBuffer | DataView, encoding?: string\)

Creates and returns an  **XmlPullParser**  object. The  **XmlPullParser**  object passes two parameters. The first parameter is the memory of the  **ArrayBuffer**  or  **DataView**  type, and the second parameter is the file format \(UTF-8 by default\).

-   Parameters

    <a name="table288473334210"></a>
    <table><thead align="left"><tr id="row388512334421"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p188523334214"><a name="p188523334214"></a><a name="p188523334214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p108851333154211"><a name="p108851333154211"></a><a name="p108851333154211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p78851433124211"><a name="p78851433124211"></a><a name="p78851433124211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p7885183304220"><a name="p7885183304220"></a><a name="p7885183304220"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row388515334428"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p18856335429"><a name="p18856335429"></a><a name="p18856335429"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p11886173344210"><a name="p11886173344210"></a><a name="p11886173344210"></a>ArrayBuffer | DataView</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p688613334215"><a name="p688613334215"></a><a name="p688613334215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1937471913416"><a name="p1937471913416"></a><a name="p1937471913416"></a><strong id="b245371713210"><a name="b245371713210"></a><a name="b245371713210"></a>ArrayBuffer</strong> or <strong id="b178682213217"><a name="b178682213217"></a><a name="b178682213217"></a>DataView</strong> that contains XML text information.</p>
    </td>
    </tr>
    <tr id="row1991038194214"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12101538134210"><a name="p12101538134210"></a><a name="p12101538134210"></a>encoding</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1761135812426"><a name="p1761135812426"></a><a name="p1761135812426"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p154915214436"><a name="p154915214436"></a><a name="p154915214436"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10101138164219"><a name="p10101138164219"></a><a name="p10101138164219"></a>Encoding format. Only UTF-8 is supported.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var strXml =
                '<?xml version="1.0" encoding="utf-8"?>' +
                '<note importance="high" logged="true">' +
                '    <title>Happy</title>' +
                '    <todo>Work</todo>' +
                '    <todo>Play</todo>' +
                '</note>';
    var arrayBuffer = new ArrayBuffer(strXml.length*2);
    var bufView = new Uint8Array(arrayBuffer);
    var strLen = strXml.length;
    for (var i = 0; i < strLen; ++i) {
        bufView[i] = strXml.charCodeAt(i);// Set the ArrayBuffer mode.
    }
    var that = new xml.XmlPullParser(arrayBuffer);
    ```


### parse<a name="section12316561182"></a>

parse\(option: ParseOptions\): void

Parses XML information.

-   Parameters

    <a name="table12343577453"></a>
    <table><thead align="left"><tr id="row03443744517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p434416704519"><a name="p434416704519"></a><a name="p434416704519"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p634418734515"><a name="p634418734515"></a><a name="p634418734515"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p43441777454"><a name="p43441777454"></a><a name="p43441777454"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p20344571453"><a name="p20344571453"></a><a name="p20344571453"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row634412719455"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16344117154513"><a name="p16344117154513"></a><a name="p16344117154513"></a>option</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p834513718453"><a name="p834513718453"></a><a name="p834513718453"></a><a href="#section983614244916">ParseOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p134518714457"><a name="p134518714457"></a><a name="p134518714457"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p83458744511"><a name="p83458744511"></a><a name="p83458744511"></a>Options for controlling and obtaining the parsed information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var strXml =
                '<?xml version="1.0" encoding="utf-8"?>' +
                '<note importance="high" logged="true">' +
                '    <title>Happy</title>' +
                '    <todo>Work</todo>' +
                '    <todo>Play</todo>' +
                '</note>';
    var arrayBuffer = new ArrayBuffer(strXml.length*2);
    var bufView = new Uint8Array(arrayBuffer);
    var strLen = strXml.length;
    for (var i = 0; i < strLen; ++i) {
        bufView[i] = strXml.charCodeAt(i);
    }
    var that = new xml.XmlPullParser(arrayBuffer);
    var arrTag = {};
    arrTag[0] = '132';
    var i = 1;
    function func(key, value){
        arrTag[i] = 'key:'+key+' value:'+ value.getDepth();
        i++;
        return true;
    }
    var options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
    that.parse(options);
    ```


## ParseOptions<a name="section983614244916"></a>

Defines the XML parsing options.

<a name="table160910591211"></a>
<table><thead align="left"><tr id="row176096590111"><th class="cellrowborder" valign="top" width="21.990000000000002%" id="mcps1.1.5.1.1"><p id="p176091259315"><a name="p176091259315"></a><a name="p176091259315"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="36.309999999999995%" id="mcps1.1.5.1.2"><p id="p260914591118"><a name="p260914591118"></a><a name="p260914591118"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="5.52%" id="mcps1.1.5.1.3"><p id="p66092593113"><a name="p66092593113"></a><a name="p66092593113"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="36.18%" id="mcps1.1.5.1.4"><p id="p160910591312"><a name="p160910591312"></a><a name="p160910591312"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1860911593112"><td class="cellrowborder" valign="top" width="21.990000000000002%" headers="mcps1.1.5.1.1 "><p id="p46091159419"><a name="p46091159419"></a><a name="p46091159419"></a>supportDoctype</p>
</td>
<td class="cellrowborder" valign="top" width="36.309999999999995%" headers="mcps1.1.5.1.2 "><p id="p136094597118"><a name="p136094597118"></a><a name="p136094597118"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="5.52%" headers="mcps1.1.5.1.3 "><p id="p660918591814"><a name="p660918591814"></a><a name="p660918591814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.18%" headers="mcps1.1.5.1.4 "><p id="p15609259215"><a name="p15609259215"></a><a name="p15609259215"></a>Whether to ignore <strong id="b1456884321714"><a name="b1456884321714"></a><a name="b1456884321714"></a>Doctype</strong>. The default value is <strong id="b1626514489171"><a name="b1626514489171"></a><a name="b1626514489171"></a>false</strong>.</p>
</td>
</tr>
<tr id="row7610175913118"><td class="cellrowborder" valign="top" width="21.990000000000002%" headers="mcps1.1.5.1.1 "><p id="p46108597120"><a name="p46108597120"></a><a name="p46108597120"></a>ignoreNameSpace</p>
</td>
<td class="cellrowborder" valign="top" width="36.309999999999995%" headers="mcps1.1.5.1.2 "><p id="p1661095916114"><a name="p1661095916114"></a><a name="p1661095916114"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="5.52%" headers="mcps1.1.5.1.3 "><p id="p13610559117"><a name="p13610559117"></a><a name="p13610559117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.18%" headers="mcps1.1.5.1.4 "><p id="p1261012591114"><a name="p1261012591114"></a><a name="p1261012591114"></a>Whether to ignore <strong id="b649517181815"><a name="b649517181815"></a><a name="b649517181815"></a>Namespace</strong>. The default value is <strong id="b154747521819"><a name="b154747521819"></a><a name="b154747521819"></a>false</strong>.</p>
</td>
</tr>
<tr id="row16101595112"><td class="cellrowborder" valign="top" width="21.990000000000002%" headers="mcps1.1.5.1.1 "><p id="p561013591916"><a name="p561013591916"></a><a name="p561013591916"></a>tagValueCallbackFunction</p>
</td>
<td class="cellrowborder" valign="top" width="36.309999999999995%" headers="mcps1.1.5.1.2 "><p id="p1861035916118"><a name="p1861035916118"></a><a name="p1861035916118"></a>(name: string, value: string)=&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="5.52%" headers="mcps1.1.5.1.3 "><p id="p1961025917117"><a name="p1961025917117"></a><a name="p1961025917117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.18%" headers="mcps1.1.5.1.4 "><p id="p1561095911110"><a name="p1561095911110"></a><a name="p1561095911110"></a>Callback used to return <strong id="b16819155133814"><a name="b16819155133814"></a><a name="b16819155133814"></a>tagValue</strong>.</p>
</td>
</tr>
<tr id="row14610859616"><td class="cellrowborder" valign="top" width="21.990000000000002%" headers="mcps1.1.5.1.1 "><p id="p76101359214"><a name="p76101359214"></a><a name="p76101359214"></a>attributeValueCallbackFunction</p>
</td>
<td class="cellrowborder" valign="top" width="36.309999999999995%" headers="mcps1.1.5.1.2 "><p id="p2061014591118"><a name="p2061014591118"></a><a name="p2061014591118"></a>(name: string, value: string)=&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="5.52%" headers="mcps1.1.5.1.3 "><p id="p1161012591018"><a name="p1161012591018"></a><a name="p1161012591018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.18%" headers="mcps1.1.5.1.4 "><p id="p1361010593112"><a name="p1361010593112"></a><a name="p1361010593112"></a>Callback used to return <strong id="b126354223386"><a name="b126354223386"></a><a name="b126354223386"></a>attributeValue</strong>.</p>
</td>
</tr>
<tr id="row5610185911117"><td class="cellrowborder" valign="top" width="21.990000000000002%" headers="mcps1.1.5.1.1 "><p id="p56101359912"><a name="p56101359912"></a><a name="p56101359912"></a>tokenValueCallbackFunction</p>
</td>
<td class="cellrowborder" valign="top" width="36.309999999999995%" headers="mcps1.1.5.1.2 "><p id="p1761011596112"><a name="p1761011596112"></a><a name="p1761011596112"></a>(eventType: <a href="#section8364114132911">EventType</a>, value: <a href="#section436931815497">ParseInfo</a>)=&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="5.52%" headers="mcps1.1.5.1.3 "><p id="p46104591014"><a name="p46104591014"></a><a name="p46104591014"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.18%" headers="mcps1.1.5.1.4 "><p id="p156118592117"><a name="p156118592117"></a><a name="p156118592117"></a>Callback used to return <strong id="b1063617437387"><a name="b1063617437387"></a><a name="b1063617437387"></a>tokenValue</strong>.</p>
</td>
</tr>
</tbody>
</table>

## ParseInfo<a name="section436931815497"></a>

Provides methods to manage the parsed XML information.

### getColumnNumber<a name="section7268152661315"></a>

getColumnNumber\(\): number

Obtains the column line number, which starts from 1.

-   Return values

    <a name="table8583171852312"></a>
    <table><thead align="left"><tr id="row1583118122320"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p95841118182314"><a name="p95841118182314"></a><a name="p95841118182314"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p12584111819235"><a name="p12584111819235"></a><a name="p12584111819235"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1058411189235"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p165841118182318"><a name="p165841118182318"></a><a name="p165841118182318"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p185841618162312"><a name="p185841618162312"></a><a name="p185841618162312"></a>Column number obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getDepth<a name="section15616143563517"></a>

getDepth\(\): number

Obtains the depth of this element.

-   Return values

    <a name="table15525115213712"></a>
    <table><thead align="left"><tr id="row125251952133718"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p752514520377"><a name="p752514520377"></a><a name="p752514520377"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p145251552143713"><a name="p145251552143713"></a><a name="p145251552143713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1152518527376"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p15991162995116"><a name="p15991162995116"></a><a name="p15991162995116"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p185251152153715"><a name="p185251152153715"></a><a name="p185251152153715"></a>Depth obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getLineNumber<a name="section8712911183819"></a>

getLineNumber\(\): number

Obtains the current line number, starting from 1.

-   Return values

    <a name="table485342915385"></a>
    <table><thead align="left"><tr id="row885302983818"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p1085313295388"><a name="p1085313295388"></a><a name="p1085313295388"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p185319296386"><a name="p185319296386"></a><a name="p185319296386"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4853102919386"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p108541629123819"><a name="p108541629123819"></a><a name="p108541629123819"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p12854229113810"><a name="p12854229113810"></a><a name="p12854229113810"></a>Line number obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getName<a name="section183355915386"></a>

getName\(\): string

Obtains the name of this element.

-   Return values

    <a name="table1083372573916"></a>
    <table><thead align="left"><tr id="row68331025193910"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p2833225153912"><a name="p2833225153912"></a><a name="p2833225153912"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p183362519395"><a name="p183362519395"></a><a name="p183362519395"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2833172523915"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p2834132533918"><a name="p2834132533918"></a><a name="p2834132533918"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p083452543915"><a name="p083452543915"></a><a name="p083452543915"></a>Element name obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getNamespace<a name="section5884344103915"></a>

getNamespace\(\): string

Obtains the namespace of this element.

-   Return values

    <a name="table555314417409"></a>
    <table><thead align="left"><tr id="row145533420401"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p15553046403"><a name="p15553046403"></a><a name="p15553046403"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p1255314454015"><a name="p1255314454015"></a><a name="p1255314454015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1555313424017"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p175531042409"><a name="p175531042409"></a><a name="p175531042409"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p2055414416400"><a name="p2055414416400"></a><a name="p2055414416400"></a>Namespace obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getPrefix<a name="section6425182414016"></a>

getPrefix\(\): string

Obtains the prefix of this element.

-   Return values

    <a name="table953805664113"></a>
    <table><thead align="left"><tr id="row115381356174119"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p653885613412"><a name="p653885613412"></a><a name="p653885613412"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p19538105624118"><a name="p19538105624118"></a><a name="p19538105624118"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row125385562414"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p1538175654111"><a name="p1538175654111"></a><a name="p1538175654111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p1953965664113"><a name="p1953965664113"></a><a name="p1953965664113"></a>Element prefix obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getText<a name="section17411131414518"></a>

getText\(\): string

Obtains the text of the current event.

-   Return values

    <a name="table1970175444514"></a>
    <table><thead align="left"><tr id="row99701054154517"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p697075417456"><a name="p697075417456"></a><a name="p697075417456"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p497017543454"><a name="p497017543454"></a><a name="p497017543454"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row097010542454"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p18970454174511"><a name="p18970454174511"></a><a name="p18970454174511"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p6970954184516"><a name="p6970954184516"></a><a name="p6970954184516"></a>Text content obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


### isEmptyElementTag<a name="section1817544617"></a>

isEmptyElementTag\(\): boolean

Checks whether the current element is empty.

-   Return values

    <a name="table19505839154618"></a>
    <table><thead align="left"><tr id="row3505143984617"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p15505163954616"><a name="p15505163954616"></a><a name="p15505163954616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p8505113934610"><a name="p8505113934610"></a><a name="p8505113934610"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1505139144620"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p1350583916465"><a name="p1350583916465"></a><a name="p1350583916465"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p11506139134613"><a name="p11506139134613"></a><a name="p11506139134613"></a>Returns <strong id="b695884461016"><a name="b695884461016"></a><a name="b695884461016"></a>true</strong> if the element is empty; returns <strong id="b1774315414113"><a name="b1774315414113"></a><a name="b1774315414113"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


### isWhitespace<a name="section91661610476"></a>

isWhitespace\(\): boolean

Checks whether the current text event contains only whitespace characters.

-   Return values

    <a name="table6645101004814"></a>
    <table><thead align="left"><tr id="row7645101014811"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p8645510154813"><a name="p8645510154813"></a><a name="p8645510154813"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p146451510184813"><a name="p146451510184813"></a><a name="p146451510184813"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6645131019485"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p11645161016486"><a name="p11645161016486"></a><a name="p11645161016486"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p20645910194820"><a name="p20645910194820"></a><a name="p20645910194820"></a>Returns <strong id="b2851155413019"><a name="b2851155413019"></a><a name="b2851155413019"></a>true</strong> if the text event contains only whitespace characters; returns <strong id="b16337271114"><a name="b16337271114"></a><a name="b16337271114"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


### getAttributeCount<a name="section736553519482"></a>

getAttributeCount\(\): number

Obtains the number of attributes for the current start tag.

-   Return values

    <a name="table18597165219484"></a>
    <table><thead align="left"><tr id="row859713527484"><th class="cellrowborder" valign="top" width="29.880000000000003%" id="mcps1.1.3.1.1"><p id="p14597125254813"><a name="p14597125254813"></a><a name="p14597125254813"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.12%" id="mcps1.1.3.1.2"><p id="p1459711528485"><a name="p1459711528485"></a><a name="p1459711528485"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2597135214813"><td class="cellrowborder" valign="top" width="29.880000000000003%" headers="mcps1.1.3.1.1 "><p id="p1059785244818"><a name="p1059785244818"></a><a name="p1059785244818"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.12%" headers="mcps1.1.3.1.2 "><p id="p45983522483"><a name="p45983522483"></a><a name="p45983522483"></a>Number of attributes obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


## EventType<a name="section8364114132911"></a>

Enumerates the events.

<a name="table71051154194714"></a>
<table><thead align="left"><tr id="row9105105494718"><th class="cellrowborder" valign="top" width="27.47%" id="mcps1.1.4.1.1"><p id="p510575413474"><a name="p510575413474"></a><a name="p510575413474"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.719999999999999%" id="mcps1.1.4.1.2"><p id="p151052542470"><a name="p151052542470"></a><a name="p151052542470"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="58.809999999999995%" id="mcps1.1.4.1.3"><p id="p161061541473"><a name="p161061541473"></a><a name="p161061541473"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13106254164718"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p717845685110"><a name="p717845685110"></a><a name="p717845685110"></a>START_DOCUMENT</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p914153211523"><a name="p914153211523"></a><a name="p914153211523"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p810715420474"><a name="p810715420474"></a><a name="p810715420474"></a>Indicates a start document event.</p>
</td>
</tr>
<tr id="row610785417479"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p117818566513"><a name="p117818566513"></a><a name="p117818566513"></a>END_DOCUMENT</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p15141143210523"><a name="p15141143210523"></a><a name="p15141143210523"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p820172175515"><a name="p820172175515"></a><a name="p820172175515"></a>Indicates an end document event.</p>
</td>
</tr>
<tr id="row12107145411474"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p13178165612512"><a name="p13178165612512"></a><a name="p13178165612512"></a>START_TAG</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p414133213520"><a name="p414133213520"></a><a name="p414133213520"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p27463438553"><a name="p27463438553"></a><a name="p27463438553"></a>Indicates a start tag event.</p>
</td>
</tr>
<tr id="row1110719544472"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p917885619516"><a name="p917885619516"></a><a name="p917885619516"></a>END_TAG</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p7141113215529"><a name="p7141113215529"></a><a name="p7141113215529"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p1279231415617"><a name="p1279231415617"></a><a name="p1279231415617"></a>Indicates an end tag event.</p>
</td>
</tr>
<tr id="row11081454164717"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p12178185612518"><a name="p12178185612518"></a><a name="p12178185612518"></a>TEXT</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p1614116324529"><a name="p1614116324529"></a><a name="p1614116324529"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p135559523569"><a name="p135559523569"></a><a name="p135559523569"></a>Indicates a text event.</p>
</td>
</tr>
<tr id="row710825415478"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p11781056175115"><a name="p11781056175115"></a><a name="p11781056175115"></a>CDSECT</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p1141113225212"><a name="p1141113225212"></a><a name="p1141113225212"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p28815319573"><a name="p28815319573"></a><a name="p28815319573"></a>Indicates a CDATA section event.</p>
</td>
</tr>
<tr id="row16108115414713"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p4178135613518"><a name="p4178135613518"></a><a name="p4178135613518"></a>COMMENT</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p9141832145218"><a name="p9141832145218"></a><a name="p9141832145218"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p11109135404716"><a name="p11109135404716"></a><a name="p11109135404716"></a>Indicates an XML comment event.</p>
</td>
</tr>
<tr id="row1710914548477"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p61796563515"><a name="p61796563515"></a><a name="p61796563515"></a>DOCDECL</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p8141163235220"><a name="p8141163235220"></a><a name="p8141163235220"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p5109115444715"><a name="p5109115444715"></a><a name="p5109115444715"></a>Indicates an XML document type declaration event.</p>
</td>
</tr>
<tr id="row1710965434712"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p171791056135119"><a name="p171791056135119"></a><a name="p171791056135119"></a>INSTRUCTION</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p141428328524"><a name="p141428328524"></a><a name="p141428328524"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p1685554515718"><a name="p1685554515718"></a><a name="p1685554515718"></a>Indicates an XML processing instruction event.</p>
</td>
</tr>
<tr id="row1511012545475"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p10179456165111"><a name="p10179456165111"></a><a name="p10179456165111"></a>ENTITY_REFERENCE</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p12142183265212"><a name="p12142183265212"></a><a name="p12142183265212"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p91101054174716"><a name="p91101054174716"></a><a name="p91101054174716"></a>Indicates an entity reference event.</p>
</td>
</tr>
<tr id="row20989135175118"><td class="cellrowborder" valign="top" width="27.47%" headers="mcps1.1.4.1.1 "><p id="p1417955615511"><a name="p1417955615511"></a><a name="p1417955615511"></a>WHITESPACE</p>
</td>
<td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.4.1.2 "><p id="p191421832195217"><a name="p191421832195217"></a><a name="p191421832195217"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="58.809999999999995%" headers="mcps1.1.4.1.3 "><p id="p19990155145115"><a name="p19990155145115"></a><a name="p19990155145115"></a>Indicates a whitespace character event.</p>
</td>
</tr>
</tbody>
</table>

