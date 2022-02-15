# XML-to-JavaScript Conversion<a name="EN-US_TOPIC_0000001196742158"></a>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import convertxml from '@ohos.convertxml';
```

## Required Permissions<a name="section11257113618419"></a>

None

## ConvertXML<a name="section143808167355"></a>

### convert<a name="section518224213325"></a>

convert\(xml: string, options?: ConvertOptions\) : Object

Converts an XML text into a JavaScript object.

-   Parameters

    <a name="table114831131512"></a>
    <table><thead align="left"><tr id="row914851141517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p214819113159"><a name="p214819113159"></a><a name="p214819113159"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1214921121519"><a name="p1214921121519"></a><a name="p1214921121519"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p11491711141512"><a name="p11491711141512"></a><a name="p11491711141512"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p171491011171512"><a name="p171491011171512"></a><a name="p171491011171512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row91491211131519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p114158183811"><a name="p114158183811"></a><a name="p114158183811"></a>xml</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1114918116154"><a name="p1114918116154"></a><a name="p1114918116154"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p314916118154"><a name="p314916118154"></a><a name="p314916118154"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p814951171516"><a name="p814951171516"></a><a name="p814951171516"></a>XML text to convert.</p>
    </td>
    </tr>
    <tr id="row5149511191511"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p161491511151511"><a name="p161491511151511"></a><a name="p161491511151511"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15196201663916"><a name="p15196201663916"></a><a name="p15196201663916"></a><a href="#section843574515413">ConvertOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p61491811131518"><a name="p61491811131518"></a><a name="p61491811131518"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17372181015412"><a name="p17372181015412"></a><a name="p17372181015412"></a>Settings of the convert operation.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table115061181517"></a>
    <table><thead align="left"><tr id="row1150161121510"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1015015113159"><a name="p1015015113159"></a><a name="p1015015113159"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p2150211201512"><a name="p2150211201512"></a><a name="p2150211201512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17150811131514"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1150161110157"><a name="p1150161110157"></a><a name="p1150161110157"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p51501611141518"><a name="p51501611141518"></a><a name="p51501611141518"></a>JavaScript object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var xml =
        '<?xml version="1.0" encoding="utf-8"?>' +
        '<note importance="high" logged="true">' +
        '    <title>Happy</title>' +
        '    <todo>Work</todo>' +
        '    <todo>Play</todo>' +
        '</note>';
    var conv = new convertxml.ConvertXML();
    var result1 = conv.convert(xml, {trim: false, ignoreDeclaration: false});
    console.log(result1)
    ```


## ConvertOptions<a name="section843574515413"></a>

<a name="table468420114018"></a>
<table><thead align="left"><tr id="row1768412134017"><th class="cellrowborder" valign="top" width="17.549999999999997%" id="mcps1.1.5.1.1"><p id="p86842124013"><a name="p86842124013"></a><a name="p86842124013"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p id="p16848194014"><a name="p16848194014"></a><a name="p16848194014"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.16%" id="mcps1.1.5.1.3"><p id="p146848118406"><a name="p146848118406"></a><a name="p146848118406"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="55.26%" id="mcps1.1.5.1.4"><p id="p66848113409"><a name="p66848113409"></a><a name="p66848113409"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row96841013407"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p1285031713269"><a name="p1285031713269"></a><a name="p1285031713269"></a>trim</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p368421104017"><a name="p368421104017"></a><a name="p368421104017"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p17684818404"><a name="p17684818404"></a><a name="p17684818404"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p9845227114216"><a name="p9845227114216"></a><a name="p9845227114216"></a>Whether to trim the whitespace characters before and after the text. The default value is <strong id="b6928115525311"><a name="b6928115525311"></a><a name="b6928115525311"></a>false</strong>.</p>
</td>
</tr>
<tr id="row13751843114014"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p11938165615400"><a name="p11938165615400"></a><a name="p11938165615400"></a>ignoreDeclaration</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p67614394017"><a name="p67614394017"></a><a name="p67614394017"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p1676154394020"><a name="p1676154394020"></a><a name="p1676154394020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p4833610345"><a name="p4833610345"></a><a name="p4833610345"></a>Whether to ignore the XML declaration. The default value is <strong id="b1986182720517"><a name="b1986182720517"></a><a name="b1986182720517"></a>false</strong>.</p>
</td>
</tr>
<tr id="row7473642142619"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p134733429261"><a name="p134733429261"></a><a name="p134733429261"></a>ignoreInstruction</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1922562513291"><a name="p1922562513291"></a><a name="p1922562513291"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p10671250142915"><a name="p10671250142915"></a><a name="p10671250142915"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p142083683419"><a name="p142083683419"></a><a name="p142083683419"></a>Whether to ignore the XML processing instruction. The default value is <strong id="b9507112714198"><a name="b9507112714198"></a><a name="b9507112714198"></a>false</strong>.</p>
</td>
</tr>
<tr id="row3747194620264"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p12748134611264"><a name="p12748134611264"></a><a name="p12748134611264"></a>ignoreAttributes</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1624022512911"><a name="p1624022512911"></a><a name="p1624022512911"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p107925092913"><a name="p107925092913"></a><a name="p107925092913"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p15291036153412"><a name="p15291036153412"></a><a name="p15291036153412"></a>Whether to print attributes across multiple lines and indent attributes. The default value is <strong id="b214910972014"><a name="b214910972014"></a><a name="b214910972014"></a>false</strong>.</p>
</td>
</tr>
<tr id="row42161882710"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p42141812713"><a name="p42141812713"></a><a name="p42141812713"></a>ignoreComment</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p152529252294"><a name="p152529252294"></a><a name="p152529252294"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p209114502296"><a name="p209114502296"></a><a name="p209114502296"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p8391736163418"><a name="p8391736163418"></a><a name="p8391736163418"></a>Whether to ignore element comments. The default value is <strong id="b12921132182012"><a name="b12921132182012"></a><a name="b12921132182012"></a>false</strong>.</p>
</td>
</tr>
<tr id="row147582020279"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p12476720122715"><a name="p12476720122715"></a><a name="p12476720122715"></a>ignoreCDATA</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p11264112552918"><a name="p11264112552918"></a><a name="p11264112552918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p11102115013297"><a name="p11102115013297"></a><a name="p11102115013297"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p28461623102316"><a name="p28461623102316"></a><a name="p28461623102316"></a>Whether to ignore the element's CDATA information. The default value is <strong id="b8400141332617"><a name="b8400141332617"></a><a name="b8400141332617"></a>false</strong>.</p>
</td>
</tr>
<tr id="row36451623142711"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p464642310271"><a name="p464642310271"></a><a name="p464642310271"></a>ignoreDoctype</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p19275172515291"><a name="p19275172515291"></a><a name="p19275172515291"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p811405092919"><a name="p811405092919"></a><a name="p811405092919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p462436183414"><a name="p462436183414"></a><a name="p462436183414"></a>Whether to ignore the element's <strong id="b1644365410213"><a name="b1644365410213"></a><a name="b1644365410213"></a>Doctype</strong> information. The default value is <strong id="b38201991221"><a name="b38201991221"></a><a name="b38201991221"></a>false</strong>.</p>
</td>
</tr>
<tr id="row156014265276"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p760132618270"><a name="p760132618270"></a><a name="p760132618270"></a>ignoreText</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p12286925122914"><a name="p12286925122914"></a><a name="p12286925122914"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p812517503295"><a name="p812517503295"></a><a name="p812517503295"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p67643663417"><a name="p67643663417"></a><a name="p67643663417"></a>Whether to ignore the element's text information. The default value is <strong id="b21731940182214"><a name="b21731940182214"></a><a name="b21731940182214"></a>false</strong>.</p>
</td>
</tr>
<tr id="row19613162818273"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p1361314282278"><a name="p1361314282278"></a><a name="p1361314282278"></a>declarationKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p9757637182919"><a name="p9757637182919"></a><a name="p9757637182919"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p1414014508297"><a name="p1414014508297"></a><a name="p1414014508297"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p1461412852710"><a name="p1461412852710"></a><a name="p1461412852710"></a>Name of the attribute key for <strong id="b7197102842416"><a name="b7197102842416"></a><a name="b7197102842416"></a>declaration</strong> in the output object. The default value is <strong id="b92387720242"><a name="b92387720242"></a><a name="b92387720242"></a>_declaration</strong>.</p>
</td>
</tr>
<tr id="row14361103817276"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p1736123832715"><a name="p1736123832715"></a><a name="p1736123832715"></a>instructionKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p11770173719299"><a name="p11770173719299"></a><a name="p11770173719299"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p41521150152912"><a name="p41521150152912"></a><a name="p41521150152912"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p336283815279"><a name="p336283815279"></a><a name="p336283815279"></a>Name of the attribute key for <strong id="b978125313248"><a name="b978125313248"></a><a name="b978125313248"></a>instruction</strong> in the output object. The default value is <strong id="b2459142611"><a name="b2459142611"></a><a name="b2459142611"></a>_instruction</strong>.</p>
</td>
</tr>
<tr id="row154132912288"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p7414898284"><a name="p7414898284"></a><a name="p7414898284"></a>attributesKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p8780133711290"><a name="p8780133711290"></a><a name="p8780133711290"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p121661150172920"><a name="p121661150172920"></a><a name="p121661150172920"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p7608142813588"><a name="p7608142813588"></a><a name="p7608142813588"></a>Name of the attribute key for <strong id="b9204185112618"><a name="b9204185112618"></a><a name="b9204185112618"></a>attributes</strong> in the output object. The default value is <strong id="b392414585262"><a name="b392414585262"></a><a name="b392414585262"></a>_attributes</strong>.</p>
</td>
</tr>
<tr id="row376713618283"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p1676846172816"><a name="p1676846172816"></a><a name="p1676846172816"></a>textKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p117908373291"><a name="p117908373291"></a><a name="p117908373291"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p217819501294"><a name="p217819501294"></a><a name="p217819501294"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p0344122145814"><a name="p0344122145814"></a><a name="p0344122145814"></a>Name of the attribute key for <strong id="b851743532718"><a name="b851743532718"></a><a name="b851743532718"></a>text</strong> in the output object. The default value is <strong id="b350917477273"><a name="b350917477273"></a><a name="b350917477273"></a>_text</strong>.</p>
</td>
</tr>
<tr id="row15340164284"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p353512166284"><a name="p353512166284"></a><a name="p353512166284"></a>cdataKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1879923716291"><a name="p1879923716291"></a><a name="p1879923716291"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p20192150122911"><a name="p20192150122911"></a><a name="p20192150122911"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p475618155581"><a name="p475618155581"></a><a name="p475618155581"></a>Name of the attribute key for <strong id="b26841859132720"><a name="b26841859132720"></a><a name="b26841859132720"></a>CDATA</strong> in the output object. The default value is <strong id="b1586013185285"><a name="b1586013185285"></a><a name="b1586013185285"></a>_cdata</strong>.</p>
</td>
</tr>
<tr id="row15657131913280"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p0657619172820"><a name="p0657619172820"></a><a name="p0657619172820"></a>doctypeKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1981023772916"><a name="p1981023772916"></a><a name="p1981023772916"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p820416508292"><a name="p820416508292"></a><a name="p820416508292"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p0979042154918"><a name="p0979042154918"></a><a name="p0979042154918"></a>Name of the attribute key for <strong id="b34439596306"><a name="b34439596306"></a><a name="b34439596306"></a>Doctype</strong> in the output object. The default value is <strong id="b022043913329"><a name="b022043913329"></a><a name="b022043913329"></a>_doctype</strong>.</p>
</td>
</tr>
<tr id="row1537652212285"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p53761822172816"><a name="p53761822172816"></a><a name="p53761822172816"></a>commentKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p14821103792913"><a name="p14821103792913"></a><a name="p14821103792913"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p1621525019292"><a name="p1621525019292"></a><a name="p1621525019292"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p748535519570"><a name="p748535519570"></a><a name="p748535519570"></a>Name of the attribute key for <strong id="b12533205423211"><a name="b12533205423211"></a><a name="b12533205423211"></a>comment</strong> in the output object. The default value is <strong id="b105967633313"><a name="b105967633313"></a><a name="b105967633313"></a>_comment</strong>.</p>
</td>
</tr>
<tr id="row1477410253283"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p577414255288"><a name="p577414255288"></a><a name="p577414255288"></a>parentKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p188311537202915"><a name="p188311537202915"></a><a name="p188311537202915"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p22272050172916"><a name="p22272050172916"></a><a name="p22272050172916"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p1599716428492"><a name="p1599716428492"></a><a name="p1599716428492"></a>Name of the attribute key for <strong id="b18469936103317"><a name="b18469936103317"></a><a name="b18469936103317"></a>parent</strong> in the output object. The default value is <strong id="b5277443163312"><a name="b5277443163312"></a><a name="b5277443163312"></a>_parent</strong>.</p>
</td>
</tr>
<tr id="row149011555192811"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p49016556281"><a name="p49016556281"></a><a name="p49016556281"></a>typeKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p483913752918"><a name="p483913752918"></a><a name="p483913752918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p1723965042916"><a name="p1723965042916"></a><a name="p1723965042916"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p1568738115715"><a name="p1568738115715"></a><a name="p1568738115715"></a>Name of the attribute key for <strong id="b562120374361"><a name="b562120374361"></a><a name="b562120374361"></a>type</strong> in the output object. The default value is <strong id="b1182815436368"><a name="b1182815436368"></a><a name="b1182815436368"></a>_type</strong>.</p>
</td>
</tr>
<tr id="row8724165922815"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p7724459112819"><a name="p7724459112819"></a><a name="p7724459112819"></a>nameKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p584703718296"><a name="p584703718296"></a><a name="p584703718296"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p3664145120292"><a name="p3664145120292"></a><a name="p3664145120292"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p159295216567"><a name="p159295216567"></a><a name="p159295216567"></a>Name of the attribute key for <strong id="b959742613717"><a name="b959742613717"></a><a name="b959742613717"></a>name</strong> in the output object. The default value is <strong id="b2605034203717"><a name="b2605034203717"></a><a name="b2605034203717"></a>_name</strong>.</p>
</td>
</tr>
<tr id="row939021212917"><td class="cellrowborder" valign="top" width="17.549999999999997%" headers="mcps1.1.5.1.1 "><p id="p17390161272918"><a name="p17390161272918"></a><a name="p17390161272918"></a>elementsKey</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p168568373295"><a name="p168568373295"></a><a name="p168568373295"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.16%" headers="mcps1.1.5.1.3 "><p id="p36771451152914"><a name="p36771451152914"></a><a name="p36771451152914"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.1.5.1.4 "><p id="p62794384910"><a name="p62794384910"></a><a name="p62794384910"></a>Name of the attribute key for <strong id="b116698498376"><a name="b116698498376"></a><a name="b116698498376"></a>elements</strong> in the output object. The default value is <strong id="b1054145814374"><a name="b1054145814374"></a><a name="b1054145814374"></a>_elements</strong>.</p>
</td>
</tr>
</tbody>
</table>

