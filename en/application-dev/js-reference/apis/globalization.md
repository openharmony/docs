# Globalization<a name="EN-US_TOPIC_0000001115814852"></a>


## Imported Modules<a name="en-us_topic_0000001103315838_s56d19203690d4782bfc74069abb6bd71"></a>

```
import Intl from '@ohos.intl';
```

## Permissions<a name="en-us_topic_0000001103315838_section11257113618419"></a>

None.

## Class<a name="en-us_topic_0000001103315838_section1956131218111"></a>

## Locale<a name="en-us_topic_0000001103315838_section189341937163212"></a>

Provides APIs for obtaining locale information.

### Attributes<a name="en-us_topic_0000001103315838_section23751576140"></a>

<a name="en-us_topic_0000001103315838_table728861911417"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103315838_row62887198149"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001103315838_p928811911410"><a name="en-us_topic_0000001103315838_p928811911410"></a><a name="en-us_topic_0000001103315838_p928811911410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001103315838_p8288191916149"><a name="en-us_topic_0000001103315838_p8288191916149"></a><a name="en-us_topic_0000001103315838_p8288191916149"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001103315838_p14288131911418"><a name="en-us_topic_0000001103315838_p14288131911418"></a><a name="en-us_topic_0000001103315838_p14288131911418"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001103315838_p1928861921411"><a name="en-us_topic_0000001103315838_p1928861921411"></a><a name="en-us_topic_0000001103315838_p1928861921411"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001103315838_p728815191149"><a name="en-us_topic_0000001103315838_p728815191149"></a><a name="en-us_topic_0000001103315838_p728815191149"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103315838_row528891919142"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103315838_p3288191991414"><a name="en-us_topic_0000001103315838_p3288191991414"></a><a name="en-us_topic_0000001103315838_p3288191991414"></a>language</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103315838_p3288121901418"><a name="en-us_topic_0000001103315838_p3288121901418"></a><a name="en-us_topic_0000001103315838_p3288121901418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103315838_p182881319191414"><a name="en-us_topic_0000001103315838_p182881319191414"></a><a name="en-us_topic_0000001103315838_p182881319191414"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103315838_p1928801914148"><a name="en-us_topic_0000001103315838_p1928801914148"></a><a name="en-us_topic_0000001103315838_p1928801914148"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103315838_p1428811192144"><a name="en-us_topic_0000001103315838_p1428811192144"></a><a name="en-us_topic_0000001103315838_p1428811192144"></a>Indicates the language of the locale.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103315838_row11288719111417"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103315838_p10288419131415"><a name="en-us_topic_0000001103315838_p10288419131415"></a><a name="en-us_topic_0000001103315838_p10288419131415"></a>script</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103315838_p91710563611"><a name="en-us_topic_0000001103315838_p91710563611"></a><a name="en-us_topic_0000001103315838_p91710563611"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103315838_p14171165163611"><a name="en-us_topic_0000001103315838_p14171165163611"></a><a name="en-us_topic_0000001103315838_p14171165163611"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103315838_p1017115543612"><a name="en-us_topic_0000001103315838_p1017115543612"></a><a name="en-us_topic_0000001103315838_p1017115543612"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103315838_p3171125183610"><a name="en-us_topic_0000001103315838_p3171125183610"></a><a name="en-us_topic_0000001103315838_p3171125183610"></a>Indicates the script of the locale.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103315838_row19687050183612"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103315838_p32281883406"><a name="en-us_topic_0000001103315838_p32281883406"></a><a name="en-us_topic_0000001103315838_p32281883406"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103315838_p1522810854016"><a name="en-us_topic_0000001103315838_p1522810854016"></a><a name="en-us_topic_0000001103315838_p1522810854016"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103315838_p1422858124014"><a name="en-us_topic_0000001103315838_p1422858124014"></a><a name="en-us_topic_0000001103315838_p1422858124014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103315838_p1922817874013"><a name="en-us_topic_0000001103315838_p1922817874013"></a><a name="en-us_topic_0000001103315838_p1922817874013"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103315838_p1722818834016"><a name="en-us_topic_0000001103315838_p1722818834016"></a><a name="en-us_topic_0000001103315838_p1722818834016"></a>Indicates the region of the locale.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103315838_row115871535369"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103315838_p15801188114019"><a name="en-us_topic_0000001103315838_p15801188114019"></a><a name="en-us_topic_0000001103315838_p15801188114019"></a>baseName</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103315838_p108011082401"><a name="en-us_topic_0000001103315838_p108011082401"></a><a name="en-us_topic_0000001103315838_p108011082401"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103315838_p138011980407"><a name="en-us_topic_0000001103315838_p138011980407"></a><a name="en-us_topic_0000001103315838_p138011980407"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103315838_p1980128134011"><a name="en-us_topic_0000001103315838_p1980128134011"></a><a name="en-us_topic_0000001103315838_p1980128134011"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103315838_p1801208144012"><a name="en-us_topic_0000001103315838_p1801208144012"></a><a name="en-us_topic_0000001103315838_p1801208144012"></a>Indicates the basic locale information, which is returned as a substring of a complete locale string.</p>
</td>
</tr>
</tbody>
</table>

### Locale<a name="en-us_topic_0000001103315838_section1410593619146"></a>

A constructor used to create a  **Locale**  object.

**Parameters**

<a name="en-us_topic_0000001103315838_table114831131512"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103315838_row914851141517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103315838_p214819113159"><a name="en-us_topic_0000001103315838_p214819113159"></a><a name="en-us_topic_0000001103315838_p214819113159"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103315838_p1214921121519"><a name="en-us_topic_0000001103315838_p1214921121519"></a><a name="en-us_topic_0000001103315838_p1214921121519"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001103315838_p11491711141512"><a name="en-us_topic_0000001103315838_p11491711141512"></a><a name="en-us_topic_0000001103315838_p11491711141512"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103315838_p171491011171512"><a name="en-us_topic_0000001103315838_p171491011171512"></a><a name="en-us_topic_0000001103315838_p171491011171512"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103315838_row91491211131519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103315838_p45271354164919"><a name="en-us_topic_0000001103315838_p45271354164919"></a><a name="en-us_topic_0000001103315838_p45271354164919"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103315838_p1252795444917"><a name="en-us_topic_0000001103315838_p1252795444917"></a><a name="en-us_topic_0000001103315838_p1252795444917"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001103315838_p314916118154"><a name="en-us_topic_0000001103315838_p314916118154"></a><a name="en-us_topic_0000001103315838_p314916118154"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103315838_p814951171516"><a name="en-us_topic_0000001103315838_p814951171516"></a><a name="en-us_topic_0000001103315838_p814951171516"></a>Indicates a character string containing the locale information, including the language and optionally the script and region.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
var enLatnGB = new Intl.Locale("en-Latn-GB");
var enGB = new Intl.Locale("en-GB");
var en = new Intl.Locale("en");
```

## DateTimeFormat<a name="en-us_topic_0000001103315838_section88061769522"></a>

Provides the API for formatting date strings.

### DateTimeFormat<a name="en-us_topic_0000001103315838_section28081362523"></a>

A constructor used to create a  **DateTimeFormat**  object.

**Parameters**

<a name="en-us_topic_0000001103315838_table1680806175216"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103315838_row10808868524"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103315838_p108080625215"><a name="en-us_topic_0000001103315838_p108080625215"></a><a name="en-us_topic_0000001103315838_p108080625215"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103315838_p78089645215"><a name="en-us_topic_0000001103315838_p78089645215"></a><a name="en-us_topic_0000001103315838_p78089645215"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001103315838_p17808126175217"><a name="en-us_topic_0000001103315838_p17808126175217"></a><a name="en-us_topic_0000001103315838_p17808126175217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103315838_p15808106185212"><a name="en-us_topic_0000001103315838_p15808106185212"></a><a name="en-us_topic_0000001103315838_p15808106185212"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103315838_row19808116205213"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103315838_p880815616525"><a name="en-us_topic_0000001103315838_p880815616525"></a><a name="en-us_topic_0000001103315838_p880815616525"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103315838_p18091655211"><a name="en-us_topic_0000001103315838_p18091655211"></a><a name="en-us_topic_0000001103315838_p18091655211"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001103315838_p19809196105217"><a name="en-us_topic_0000001103315838_p19809196105217"></a><a name="en-us_topic_0000001103315838_p19809196105217"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103315838_p28095613525"><a name="en-us_topic_0000001103315838_p28095613525"></a><a name="en-us_topic_0000001103315838_p28095613525"></a>Indicates a character string containing the locale information, including the language and optionally the script and region, for the <strong id="en-us_topic_0000001103315838_b06014570014"><a name="en-us_topic_0000001103315838_b06014570014"></a><a name="en-us_topic_0000001103315838_b06014570014"></a>DateTimeFormat</strong> object.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
var dateFmt = new Intl.DateTimeFormat("en-Latn-GB");
```

### format<a name="en-us_topic_0000001103315838_section917151185514"></a>

Obtains the formatted date strings.

**Parameters**

<a name="en-us_topic_0000001103315838_table61711165519"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103315838_row1176115554"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103315838_p017312552"><a name="en-us_topic_0000001103315838_p017312552"></a><a name="en-us_topic_0000001103315838_p017312552"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103315838_p217112554"><a name="en-us_topic_0000001103315838_p217112554"></a><a name="en-us_topic_0000001103315838_p217112554"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001103315838_p61771165517"><a name="en-us_topic_0000001103315838_p61771165517"></a><a name="en-us_topic_0000001103315838_p61771165517"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103315838_p418515559"><a name="en-us_topic_0000001103315838_p418515559"></a><a name="en-us_topic_0000001103315838_p418515559"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103315838_row121811118556"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103315838_p13181419559"><a name="en-us_topic_0000001103315838_p13181419559"></a><a name="en-us_topic_0000001103315838_p13181419559"></a>date</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103315838_p918171185515"><a name="en-us_topic_0000001103315838_p918171185515"></a><a name="en-us_topic_0000001103315838_p918171185515"></a>Date</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001103315838_p161819114551"><a name="en-us_topic_0000001103315838_p161819114551"></a><a name="en-us_topic_0000001103315838_p161819114551"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103315838_p718316555"><a name="en-us_topic_0000001103315838_p718316555"></a><a name="en-us_topic_0000001103315838_p718316555"></a>Indicates the <strong id="en-us_topic_0000001103315838_b89491740312"><a name="en-us_topic_0000001103315838_b89491740312"></a><a name="en-us_topic_0000001103315838_b89491740312"></a>Date</strong> object to be formatted.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001103315838_table2187195518"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103315838_row618171115511"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001103315838_p12186185510"><a name="en-us_topic_0000001103315838_p12186185510"></a><a name="en-us_topic_0000001103315838_p12186185510"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001103315838_p218171115514"><a name="en-us_topic_0000001103315838_p218171115514"></a><a name="en-us_topic_0000001103315838_p218171115514"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103315838_row13181115555"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001103315838_p3195145512"><a name="en-us_topic_0000001103315838_p3195145512"></a><a name="en-us_topic_0000001103315838_p3195145512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001103315838_p3196119551"><a name="en-us_topic_0000001103315838_p3196119551"></a><a name="en-us_topic_0000001103315838_p3196119551"></a>Indicates a date string formatted based on the specified locale.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
var date = new Date(1995, 11, 25, 3, 14, 0);
var datefmt = new Intl.DateTimeFormat("en-Latn-GB");
var result = datefmt.format(date); // The formatted date string is Dec 25, 1995.
```

