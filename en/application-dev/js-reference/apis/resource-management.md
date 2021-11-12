# Resource Management<a name="EN-US_TOPIC_0000001162414653"></a>

-   [Imported Modules](#en-us_topic_0000001150318493_s56d19203690d4782bfc74069abb6bd71)
-   [Permissions](#en-us_topic_0000001150318493_section11257113618419)
-   [Methods](#en-us_topic_0000001150318493_section125675489541)
-   [getResourceManager](#en-us_topic_0000001150318493_section192192415554)
-   [getResourceManager](#en-us_topic_0000001150318493_section46989284018)
-   [getResourceManager](#en-us_topic_0000001150318493_section0543541673)
-   [getResourceManager](#en-us_topic_0000001150318493_section1816951410716)
-   [Enum](#en-us_topic_0000001150318493_section1978842154715)
-   [Direction](#en-us_topic_0000001150318493_section099619567453)
-   [DeviceType](#en-us_topic_0000001150318493_section4734636131914)
-   [ScreenDensity](#en-us_topic_0000001150318493_section7331173812197)
-   [Appendix](#en-us_topic_0000001150318493_section1933416317165)
-   [AsyncCallback<T\>](#en-us_topic_0000001150318493_section256244135613)
-   [Configuration](#en-us_topic_0000001150318493_section12882825611)
    -   [Attributes](#en-us_topic_0000001150318493_section1059684317312)

-   [DeviceCapability](#en-us_topic_0000001150318493_section7200123494410)
    -   [Attributes](#en-us_topic_0000001150318493_section2201153419440)

-   [ResourceManager](#en-us_topic_0000001150318493_section137771134135415)
    -   [getString](#en-us_topic_0000001150318493_section9779153419548)
    -   [getString](#en-us_topic_0000001150318493_section159261924165411)
    -   [getStringArray](#en-us_topic_0000001150318493_section4490132775420)
    -   [getStringArray](#en-us_topic_0000001150318493_section1992322017541)
    -   [getMedia](#en-us_topic_0000001150318493_section6710152513409)
    -   [getMedia](#en-us_topic_0000001150318493_section6711152517409)
    -   [getMediaBase64](#en-us_topic_0000001150318493_section11402326194315)
    -   [getMediaBase64](#en-us_topic_0000001150318493_section6404726124312)
    -   [getConfiguration](#en-us_topic_0000001150318493_section8123152874015)
    -   [getConfiguration](#en-us_topic_0000001150318493_section312515284406)
    -   [getDeviceCapability](#en-us_topic_0000001150318493_section104951210135017)
    -   [getDeviceCapability](#en-us_topic_0000001150318493_section114961410115013)
    -   [getPluralString](#en-us_topic_0000001150318493_section1549163064013)
    -   [getPluralString](#en-us_topic_0000001150318493_section165183015405)


## Imported Modules<a name="en-us_topic_0000001150318493_s56d19203690d4782bfc74069abb6bd71"></a>

```
import resmgr from '@ohos.resmgr';
```

## Permissions<a name="en-us_topic_0000001150318493_section11257113618419"></a>

None.

## Methods<a name="en-us_topic_0000001150318493_section125675489541"></a>

## getResourceManager<a name="en-us_topic_0000001150318493_section192192415554"></a>

Obtains the  **ResourceManager**  object of the current application.

**Parameters**

<a name="en-us_topic_0000001150318493_table69661135912"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p7966738914"><a name="en-us_topic_0000001150318493_p7966738914"></a><a name="en-us_topic_0000001150318493_p7966738914"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p296713699"><a name="en-us_topic_0000001150318493_p296713699"></a><a name="en-us_topic_0000001150318493_p296713699"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p196718315911"><a name="en-us_topic_0000001150318493_p196718315911"></a><a name="en-us_topic_0000001150318493_p196718315911"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p9967231197"><a name="en-us_topic_0000001150318493_p9967231197"></a><a name="en-us_topic_0000001150318493_p9967231197"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p13838351705"><a name="en-us_topic_0000001150318493_p13838351705"></a><a name="en-us_topic_0000001150318493_p13838351705"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p11967433914"><a name="en-us_topic_0000001150318493_p11967433914"></a><a name="en-us_topic_0000001150318493_p11967433914"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;<a href="#en-us_topic_0000001150318493_section137771134135415">ResourceManager</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p19671336916"><a name="en-us_topic_0000001150318493_p19671336916"></a><a name="en-us_topic_0000001150318493_p19671336916"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p69671631796"><a name="en-us_topic_0000001150318493_p69671631796"></a><a name="en-us_topic_0000001150318493_p69671631796"></a>Indicates the callback containing the <strong id="en-us_topic_0000001150318493_b1744004415714"><a name="en-us_topic_0000001150318493_b1744004415714"></a><a name="en-us_topic_0000001150318493_b1744004415714"></a>ResourceManager</strong> object.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

**Example**

```
resmgr.getResourceManager((error, mgr) => {
    // callback
    mgr.getString(0x1000000, (error, value) => {
        if (error != null) {
            console.log(value);
        } else {
            console.log(value);
        }
    });

    // promise
    mgr.getString(0x1000000).then(value => {
        console.log(value);
    }).catch(error => {
        console.log("getstring promise " + error);
    });
}

```

## getResourceManager<a name="en-us_topic_0000001150318493_section46989284018"></a>

Obtains the  **ResourceManager**  object of the specified application.

**Parameters**

<a name="en-us_topic_0000001150318493_table146992288015"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row16994286017"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p196991328500"><a name="en-us_topic_0000001150318493_p196991328500"></a><a name="en-us_topic_0000001150318493_p196991328500"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p156991028607"><a name="en-us_topic_0000001150318493_p156991028607"></a><a name="en-us_topic_0000001150318493_p156991028607"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.762631629794225%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p569920281005"><a name="en-us_topic_0000001150318493_p569920281005"></a><a name="en-us_topic_0000001150318493_p569920281005"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.211670370012556%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p5699428800"><a name="en-us_topic_0000001150318493_p5699428800"></a><a name="en-us_topic_0000001150318493_p5699428800"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row469912281801"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p46991028909"><a name="en-us_topic_0000001150318493_p46991028909"></a><a name="en-us_topic_0000001150318493_p46991028909"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p469919282017"><a name="en-us_topic_0000001150318493_p469919282017"></a><a name="en-us_topic_0000001150318493_p469919282017"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p169982812013"><a name="en-us_topic_0000001150318493_p169982812013"></a><a name="en-us_topic_0000001150318493_p169982812013"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p569972818014"><a name="en-us_topic_0000001150318493_p569972818014"></a><a name="en-us_topic_0000001150318493_p569972818014"></a>Indicates the bundle name of the specified application.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row769982815012"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p10188114718716"><a name="en-us_topic_0000001150318493_p10188114718716"></a><a name="en-us_topic_0000001150318493_p10188114718716"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1518810471873"><a name="en-us_topic_0000001150318493_p1518810471873"></a><a name="en-us_topic_0000001150318493_p1518810471873"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;<a href="#en-us_topic_0000001150318493_section137771134135415">ResourceManager</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p718813478713"><a name="en-us_topic_0000001150318493_p718813478713"></a><a name="en-us_topic_0000001150318493_p718813478713"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1618844718710"><a name="en-us_topic_0000001150318493_p1618844718710"></a><a name="en-us_topic_0000001150318493_p1618844718710"></a>Indicates the callback containing the <strong id="en-us_topic_0000001150318493_b5121366013"><a name="en-us_topic_0000001150318493_b5121366013"></a><a name="en-us_topic_0000001150318493_b5121366013"></a>ResourceManager</strong> object.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

**Example**

```
resmgr.getResourceManager("com.example.myapplication", (error, mgr) => {
}
```

## getResourceManager<a name="en-us_topic_0000001150318493_section0543541673"></a>

Obtains the  **ResourceManager**  object of the current application.

**Parameters**

None.

**Return Values**

<a name="en-us_topic_0000001150318493_table125442040718"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row11545745715"><th class="cellrowborder" valign="top" width="21.19%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p115451947716"><a name="en-us_topic_0000001150318493_p115451947716"></a><a name="en-us_topic_0000001150318493_p115451947716"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="78.81%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p15451043716"><a name="en-us_topic_0000001150318493_p15451043716"></a><a name="en-us_topic_0000001150318493_p15451043716"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row55451841670"><td class="cellrowborder" valign="top" width="21.19%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p135451841712"><a name="en-us_topic_0000001150318493_p135451841712"></a><a name="en-us_topic_0000001150318493_p135451841712"></a>Promise&lt;<a href="#en-us_topic_0000001150318493_section137771134135415">ResourceManager</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="78.81%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p954512419714"><a name="en-us_topic_0000001150318493_p954512419714"></a><a name="en-us_topic_0000001150318493_p954512419714"></a>Indicates that the <strong id="en-us_topic_0000001150318493_b11718591325"><a name="en-us_topic_0000001150318493_b11718591325"></a><a name="en-us_topic_0000001150318493_b11718591325"></a>ResourceManager</strong> object is returned in Promise mode.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
resmgr.getResourceManager().then(mgr => {
    // callback
    mgr.getString(0x1000000, (error, value) => {
        if (error != null) {
            console.log(value);
        } else {
            console.log(value);
        }
    });

    // promise
    mgr.getString(0x1000000).then(value => {
        console.log(value);
    }).catch(error => {
        console.log("getstring promise " + error);
    });
}).catch(error => {

});
```

## getResourceManager<a name="en-us_topic_0000001150318493_section1816951410716"></a>

Obtains the  **ResourceManager**  object of the specified application.

**Parameters**

<a name="en-us_topic_0000001150318493_table6169161415710"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row141691914878"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p191691114172"><a name="en-us_topic_0000001150318493_p191691114172"></a><a name="en-us_topic_0000001150318493_p191691114172"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p91690141774"><a name="en-us_topic_0000001150318493_p91690141774"></a><a name="en-us_topic_0000001150318493_p91690141774"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p1417013141074"><a name="en-us_topic_0000001150318493_p1417013141074"></a><a name="en-us_topic_0000001150318493_p1417013141074"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p1117051418716"><a name="en-us_topic_0000001150318493_p1117051418716"></a><a name="en-us_topic_0000001150318493_p1117051418716"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row1917061417717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p16466037131616"><a name="en-us_topic_0000001150318493_p16466037131616"></a><a name="en-us_topic_0000001150318493_p16466037131616"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p8466637101620"><a name="en-us_topic_0000001150318493_p8466637101620"></a><a name="en-us_topic_0000001150318493_p8466637101620"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p446633713162"><a name="en-us_topic_0000001150318493_p446633713162"></a><a name="en-us_topic_0000001150318493_p446633713162"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1446633701612"><a name="en-us_topic_0000001150318493_p1446633701612"></a><a name="en-us_topic_0000001150318493_p1446633701612"></a>Indicates the bundle name of the specified application.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table51715149717"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row717151413717"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p917117141075"><a name="en-us_topic_0000001150318493_p917117141075"></a><a name="en-us_topic_0000001150318493_p917117141075"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p131716141778"><a name="en-us_topic_0000001150318493_p131716141778"></a><a name="en-us_topic_0000001150318493_p131716141778"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row1417116141579"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p1940551651713"><a name="en-us_topic_0000001150318493_p1940551651713"></a><a name="en-us_topic_0000001150318493_p1940551651713"></a>Promise&lt;<a href="#en-us_topic_0000001150318493_section137771134135415">ResourceManager</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p140517164171"><a name="en-us_topic_0000001150318493_p140517164171"></a><a name="en-us_topic_0000001150318493_p140517164171"></a>Indicates that the <strong id="en-us_topic_0000001150318493_b866143712213"><a name="en-us_topic_0000001150318493_b866143712213"></a><a name="en-us_topic_0000001150318493_b866143712213"></a>ResourceManager</strong> object is returned in Promise mode.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
resmgr.getResourceManager("com.example.myapplication").then(mgr => {

}).catch(error => {

});
```

## Enum<a name="en-us_topic_0000001150318493_section1978842154715"></a>

## Direction<a name="en-us_topic_0000001150318493_section099619567453"></a>

Enumerates screen directions

<a name="en-us_topic_0000001150318493_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001150318493_a3d0fc780cc904c1cbab7991251622f65"><a name="en-us_topic_0000001150318493_a3d0fc780cc904c1cbab7991251622f65"></a><a name="en-us_topic_0000001150318493_a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001150318493_aace9cae4ba0d4939bfa048460f61c3c7"><a name="en-us_topic_0000001150318493_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="en-us_topic_0000001150318493_aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001150318493_afec895de33f94e3c87ee7acc20190a17"><a name="en-us_topic_0000001150318493_afec895de33f94e3c87ee7acc20190a17"></a><a name="en-us_topic_0000001150318493_afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p26821854218"><a name="en-us_topic_0000001150318493_p26821854218"></a><a name="en-us_topic_0000001150318493_p26821854218"></a>DIRECTION_VERTICAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p2282152962115"><a name="en-us_topic_0000001150318493_p2282152962115"></a><a name="en-us_topic_0000001150318493_p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p328012293211"><a name="en-us_topic_0000001150318493_p328012293211"></a><a name="en-us_topic_0000001150318493_p328012293211"></a>Indicates the vertical direction.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p12106173918219"><a name="en-us_topic_0000001150318493_p12106173918219"></a><a name="en-us_topic_0000001150318493_p12106173918219"></a>DIRECTION_HORIZONTAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1310553911218"><a name="en-us_topic_0000001150318493_p1310553911218"></a><a name="en-us_topic_0000001150318493_p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p15865395215"><a name="en-us_topic_0000001150318493_p15865395215"></a><a name="en-us_topic_0000001150318493_p15865395215"></a>Indicates the horizontal direction.</p>
</td>
</tr>
</tbody>
</table>

## DeviceType<a name="en-us_topic_0000001150318493_section4734636131914"></a>

Enumerates device types.

<a name="en-us_topic_0000001150318493_table873411360193"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row187341036191911"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001150318493_p19735163661915"><a name="en-us_topic_0000001150318493_p19735163661915"></a><a name="en-us_topic_0000001150318493_p19735163661915"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001150318493_p12735173661913"><a name="en-us_topic_0000001150318493_p12735173661913"></a><a name="en-us_topic_0000001150318493_p12735173661913"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001150318493_p12735163611913"><a name="en-us_topic_0000001150318493_p12735163611913"></a><a name="en-us_topic_0000001150318493_p12735163611913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row19735113619194"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p27351736111919"><a name="en-us_topic_0000001150318493_p27351736111919"></a><a name="en-us_topic_0000001150318493_p27351736111919"></a>DEVICE_TYPE_PHONE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p137351636131917"><a name="en-us_topic_0000001150318493_p137351636131917"></a><a name="en-us_topic_0000001150318493_p137351636131917"></a>0x00</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p1873543614192"><a name="en-us_topic_0000001150318493_p1873543614192"></a><a name="en-us_topic_0000001150318493_p1873543614192"></a>Indicates a phone.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row1956619491229"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p1456634917225"><a name="en-us_topic_0000001150318493_p1456634917225"></a><a name="en-us_topic_0000001150318493_p1456634917225"></a>DEVICE_TYPE_TABLET</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1256634982217"><a name="en-us_topic_0000001150318493_p1256634982217"></a><a name="en-us_topic_0000001150318493_p1256634982217"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p598213916331"><a name="en-us_topic_0000001150318493_p598213916331"></a><a name="en-us_topic_0000001150318493_p598213916331"></a>Indicates a tablet.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row57811744162211"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p47820449225"><a name="en-us_topic_0000001150318493_p47820449225"></a><a name="en-us_topic_0000001150318493_p47820449225"></a>DEVICE_TYPE_CAR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1878244417224"><a name="en-us_topic_0000001150318493_p1878244417224"></a><a name="en-us_topic_0000001150318493_p1878244417224"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p378213446229"><a name="en-us_topic_0000001150318493_p378213446229"></a><a name="en-us_topic_0000001150318493_p378213446229"></a>Indicates a head unit.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row578284442218"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p117821445229"><a name="en-us_topic_0000001150318493_p117821445229"></a><a name="en-us_topic_0000001150318493_p117821445229"></a>DEVICE_TYPE_PC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p137821044172214"><a name="en-us_topic_0000001150318493_p137821044172214"></a><a name="en-us_topic_0000001150318493_p137821044172214"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p18782124422219"><a name="en-us_topic_0000001150318493_p18782124422219"></a><a name="en-us_topic_0000001150318493_p18782124422219"></a>Indicates a PC.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row84751140142210"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p0475184014225"><a name="en-us_topic_0000001150318493_p0475184014225"></a><a name="en-us_topic_0000001150318493_p0475184014225"></a>DEVICE_TYPE_TV</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1847519407228"><a name="en-us_topic_0000001150318493_p1847519407228"></a><a name="en-us_topic_0000001150318493_p1847519407228"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p44757409225"><a name="en-us_topic_0000001150318493_p44757409225"></a><a name="en-us_topic_0000001150318493_p44757409225"></a>Indicates a smart TV.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row9735736161917"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p2073520364190"><a name="en-us_topic_0000001150318493_p2073520364190"></a><a name="en-us_topic_0000001150318493_p2073520364190"></a>DEVICE_TYPE_WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1273683612191"><a name="en-us_topic_0000001150318493_p1273683612191"></a><a name="en-us_topic_0000001150318493_p1273683612191"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p1873653617198"><a name="en-us_topic_0000001150318493_p1873653617198"></a><a name="en-us_topic_0000001150318493_p1873653617198"></a>Indicates a wearable.</p>
</td>
</tr>
</tbody>
</table>

## ScreenDensity<a name="en-us_topic_0000001150318493_section7331173812197"></a>

Enumerates screen density types.

<a name="en-us_topic_0000001150318493_table203311638181919"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row33311338101917"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001150318493_p733183811195"><a name="en-us_topic_0000001150318493_p733183811195"></a><a name="en-us_topic_0000001150318493_p733183811195"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001150318493_p1331163810197"><a name="en-us_topic_0000001150318493_p1331163810197"></a><a name="en-us_topic_0000001150318493_p1331163810197"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001150318493_p10331238191920"><a name="en-us_topic_0000001150318493_p10331238191920"></a><a name="en-us_topic_0000001150318493_p10331238191920"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row19331163821912"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p133311538131919"><a name="en-us_topic_0000001150318493_p133311538131919"></a><a name="en-us_topic_0000001150318493_p133311538131919"></a>SCREEN_SDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p833113385195"><a name="en-us_topic_0000001150318493_p833113385195"></a><a name="en-us_topic_0000001150318493_p833113385195"></a>120</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p1133133881918"><a name="en-us_topic_0000001150318493_p1133133881918"></a><a name="en-us_topic_0000001150318493_p1133133881918"></a>Indicates small screen density.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row1399293473011"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p599213418300"><a name="en-us_topic_0000001150318493_p599213418300"></a><a name="en-us_topic_0000001150318493_p599213418300"></a>SCREEN_MDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p1099210349304"><a name="en-us_topic_0000001150318493_p1099210349304"></a><a name="en-us_topic_0000001150318493_p1099210349304"></a>160</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p139921534173016"><a name="en-us_topic_0000001150318493_p139921534173016"></a><a name="en-us_topic_0000001150318493_p139921534173016"></a>Indicates medium screen density.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row4841123016304"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p188417305309"><a name="en-us_topic_0000001150318493_p188417305309"></a><a name="en-us_topic_0000001150318493_p188417305309"></a>SCREEN_LDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p10841193014308"><a name="en-us_topic_0000001150318493_p10841193014308"></a><a name="en-us_topic_0000001150318493_p10841193014308"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p1084116309304"><a name="en-us_topic_0000001150318493_p1084116309304"></a><a name="en-us_topic_0000001150318493_p1084116309304"></a>Indicates large screen density.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row1784163013302"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p48413309304"><a name="en-us_topic_0000001150318493_p48413309304"></a><a name="en-us_topic_0000001150318493_p48413309304"></a>SCREEN_XLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p128411930183011"><a name="en-us_topic_0000001150318493_p128411930183011"></a><a name="en-us_topic_0000001150318493_p128411930183011"></a>320</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p084110301309"><a name="en-us_topic_0000001150318493_p084110301309"></a><a name="en-us_topic_0000001150318493_p084110301309"></a>Indicates extra-large screen density.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row1084092610308"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p128411926173012"><a name="en-us_topic_0000001150318493_p128411926173012"></a><a name="en-us_topic_0000001150318493_p128411926173012"></a>SCREEN_XXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p884192693019"><a name="en-us_topic_0000001150318493_p884192693019"></a><a name="en-us_topic_0000001150318493_p884192693019"></a>480</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p6841226163015"><a name="en-us_topic_0000001150318493_p6841226163015"></a><a name="en-us_topic_0000001150318493_p6841226163015"></a>Indicates extra-extra-large screen density.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row11331163891916"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150318493_p14331163861914"><a name="en-us_topic_0000001150318493_p14331163861914"></a><a name="en-us_topic_0000001150318493_p14331163861914"></a>SCREEN_XXXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150318493_p933115383192"><a name="en-us_topic_0000001150318493_p933115383192"></a><a name="en-us_topic_0000001150318493_p933115383192"></a>640</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150318493_p23321138141912"><a name="en-us_topic_0000001150318493_p23321138141912"></a><a name="en-us_topic_0000001150318493_p23321138141912"></a>Indicates extra-extra-extra-large screen density.</p>
</td>
</tr>
</tbody>
</table>

## Appendix<a name="en-us_topic_0000001150318493_section1933416317165"></a>

## AsyncCallback<T\><a name="en-us_topic_0000001150318493_section256244135613"></a>

<a name="en-us_topic_0000001150318493_table0103172561814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row12103152513185"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1610322561817"><a name="en-us_topic_0000001150318493_p1610322561817"></a><a name="en-us_topic_0000001150318493_p1610322561817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.271227122712272%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p20103132551816"><a name="en-us_topic_0000001150318493_p20103132551816"></a><a name="en-us_topic_0000001150318493_p20103132551816"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p1103172518188"><a name="en-us_topic_0000001150318493_p1103172518188"></a><a name="en-us_topic_0000001150318493_p1103172518188"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p19103125141812"><a name="en-us_topic_0000001150318493_p19103125141812"></a><a name="en-us_topic_0000001150318493_p19103125141812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row201031125101812"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p293518218251"><a name="en-us_topic_0000001150318493_p293518218251"></a><a name="en-us_topic_0000001150318493_p293518218251"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p39351925253"><a name="en-us_topic_0000001150318493_p39351925253"></a><a name="en-us_topic_0000001150318493_p39351925253"></a>Error</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p8935162182512"><a name="en-us_topic_0000001150318493_p8935162182512"></a><a name="en-us_topic_0000001150318493_p8935162182512"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p109351224253"><a name="en-us_topic_0000001150318493_p109351224253"></a><a name="en-us_topic_0000001150318493_p109351224253"></a>Returns an error if an exception is thrown during execution; returns an empty value otherwise.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row750201314232"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p5501413112313"><a name="en-us_topic_0000001150318493_p5501413112313"></a><a name="en-us_topic_0000001150318493_p5501413112313"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p7501313142310"><a name="en-us_topic_0000001150318493_p7501313142310"></a><a name="en-us_topic_0000001150318493_p7501313142310"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p550141313239"><a name="en-us_topic_0000001150318493_p550141313239"></a><a name="en-us_topic_0000001150318493_p550141313239"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p750191318235"><a name="en-us_topic_0000001150318493_p750191318235"></a><a name="en-us_topic_0000001150318493_p750191318235"></a>Returns a T object if the execution is successful; returns an empty value otherwise.</p>
</td>
</tr>
</tbody>
</table>

## Configuration<a name="en-us_topic_0000001150318493_section12882825611"></a>

Provides the device configuration.

### Attributes<a name="en-us_topic_0000001150318493_section1059684317312"></a>

<a name="en-us_topic_0000001150318493_table1459620431636"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001150318493_p1559716434320"><a name="en-us_topic_0000001150318493_p1559716434320"></a><a name="en-us_topic_0000001150318493_p1559716434320"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001150318493_p3597743539"><a name="en-us_topic_0000001150318493_p3597743539"></a><a name="en-us_topic_0000001150318493_p3597743539"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001150318493_p15971343131"><a name="en-us_topic_0000001150318493_p15971343131"></a><a name="en-us_topic_0000001150318493_p15971343131"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001150318493_p1459715436311"><a name="en-us_topic_0000001150318493_p1459715436311"></a><a name="en-us_topic_0000001150318493_p1459715436311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001150318493_p75975439316"><a name="en-us_topic_0000001150318493_p75975439316"></a><a name="en-us_topic_0000001150318493_p75975439316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001150318493_p85976431431"><a name="en-us_topic_0000001150318493_p85976431431"></a><a name="en-us_topic_0000001150318493_p85976431431"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001150318493_p2059710431030"><a name="en-us_topic_0000001150318493_p2059710431030"></a><a name="en-us_topic_0000001150318493_p2059710431030"></a><a href="#en-us_topic_0000001150318493_section099619567453">Direction</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001150318493_p1059711439317"><a name="en-us_topic_0000001150318493_p1059711439317"></a><a name="en-us_topic_0000001150318493_p1059711439317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001150318493_p659715430317"><a name="en-us_topic_0000001150318493_p659715430317"></a><a name="en-us_topic_0000001150318493_p659715430317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001150318493_p2059719436313"><a name="en-us_topic_0000001150318493_p2059719436313"></a><a name="en-us_topic_0000001150318493_p2059719436313"></a>Indicates the screen direction of the current device.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001150318493_p1559710432310"><a name="en-us_topic_0000001150318493_p1559710432310"></a><a name="en-us_topic_0000001150318493_p1559710432310"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001150318493_p16597144318312"><a name="en-us_topic_0000001150318493_p16597144318312"></a><a name="en-us_topic_0000001150318493_p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001150318493_p12597194313317"><a name="en-us_topic_0000001150318493_p12597194313317"></a><a name="en-us_topic_0000001150318493_p12597194313317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001150318493_p1259710431236"><a name="en-us_topic_0000001150318493_p1259710431236"></a><a name="en-us_topic_0000001150318493_p1259710431236"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001150318493_p10597843034"><a name="en-us_topic_0000001150318493_p10597843034"></a><a name="en-us_topic_0000001150318493_p10597843034"></a>Indicates the current system language, for example, zh-Hans-CN.</p>
</td>
</tr>
</tbody>
</table>

## DeviceCapability<a name="en-us_topic_0000001150318493_section7200123494410"></a>

Provides the device capability.

### Attributes<a name="en-us_topic_0000001150318493_section2201153419440"></a>

<a name="en-us_topic_0000001150318493_table16201103444414"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row620123444415"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001150318493_p1620163494418"><a name="en-us_topic_0000001150318493_p1620163494418"></a><a name="en-us_topic_0000001150318493_p1620163494418"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001150318493_p15201434124418"><a name="en-us_topic_0000001150318493_p15201434124418"></a><a name="en-us_topic_0000001150318493_p15201434124418"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001150318493_p13201123484412"><a name="en-us_topic_0000001150318493_p13201123484412"></a><a name="en-us_topic_0000001150318493_p13201123484412"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001150318493_p1320123412448"><a name="en-us_topic_0000001150318493_p1320123412448"></a><a name="en-us_topic_0000001150318493_p1320123412448"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001150318493_p9201934134419"><a name="en-us_topic_0000001150318493_p9201934134419"></a><a name="en-us_topic_0000001150318493_p9201934134419"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row3201103494415"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001150318493_p20826502499"><a name="en-us_topic_0000001150318493_p20826502499"></a><a name="en-us_topic_0000001150318493_p20826502499"></a>screenDensity</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001150318493_p120143413448"><a name="en-us_topic_0000001150318493_p120143413448"></a><a name="en-us_topic_0000001150318493_p120143413448"></a><a href="#en-us_topic_0000001150318493_section7331173812197">ScreenDensity</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001150318493_p18201334114417"><a name="en-us_topic_0000001150318493_p18201334114417"></a><a name="en-us_topic_0000001150318493_p18201334114417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001150318493_p420113347441"><a name="en-us_topic_0000001150318493_p420113347441"></a><a name="en-us_topic_0000001150318493_p420113347441"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001150318493_p202021934134412"><a name="en-us_topic_0000001150318493_p202021934134412"></a><a name="en-us_topic_0000001150318493_p202021934134412"></a>Indicates the screen density of the current device.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row19202113413445"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001150318493_p82028341442"><a name="en-us_topic_0000001150318493_p82028341442"></a><a name="en-us_topic_0000001150318493_p82028341442"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001150318493_p62021434104413"><a name="en-us_topic_0000001150318493_p62021434104413"></a><a name="en-us_topic_0000001150318493_p62021434104413"></a><a href="#en-us_topic_0000001150318493_section4734636131914">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001150318493_p142021134164413"><a name="en-us_topic_0000001150318493_p142021134164413"></a><a name="en-us_topic_0000001150318493_p142021134164413"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001150318493_p22021834104417"><a name="en-us_topic_0000001150318493_p22021834104417"></a><a name="en-us_topic_0000001150318493_p22021834104417"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001150318493_p112021341446"><a name="en-us_topic_0000001150318493_p112021341446"></a><a name="en-us_topic_0000001150318493_p112021341446"></a>Indicates the type of the current device.</p>
</td>
</tr>
</tbody>
</table>

## ResourceManager<a name="en-us_topic_0000001150318493_section137771134135415"></a>

Provides the capability of accessing application resources.

### getString<a name="en-us_topic_0000001150318493_section9779153419548"></a>

Obtains the character string corresponding to a specified resource ID in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table15779123455418"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row37791234125419"><th class="cellrowborder" valign="top" width="9.07%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1778018347547"><a name="en-us_topic_0000001150318493_p1778018347547"></a><a name="en-us_topic_0000001150318493_p1778018347547"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.48%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p12780113475417"><a name="en-us_topic_0000001150318493_p12780113475417"></a><a name="en-us_topic_0000001150318493_p12780113475417"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p137801834145410"><a name="en-us_topic_0000001150318493_p137801834145410"></a><a name="en-us_topic_0000001150318493_p137801834145410"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p1678053465414"><a name="en-us_topic_0000001150318493_p1678053465414"></a><a name="en-us_topic_0000001150318493_p1678053465414"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row478015349541"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1978013410544"><a name="en-us_topic_0000001150318493_p1978013410544"></a><a name="en-us_topic_0000001150318493_p1978013410544"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p13780123410542"><a name="en-us_topic_0000001150318493_p13780123410542"></a><a name="en-us_topic_0000001150318493_p13780123410542"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p14780334145419"><a name="en-us_topic_0000001150318493_p14780334145419"></a><a name="en-us_topic_0000001150318493_p14780334145419"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p97801934185415"><a name="en-us_topic_0000001150318493_p97801934185415"></a><a name="en-us_topic_0000001150318493_p97801934185415"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row5780334175417"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1780113413548"><a name="en-us_topic_0000001150318493_p1780113413548"></a><a name="en-us_topic_0000001150318493_p1780113413548"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p5127248143016"><a name="en-us_topic_0000001150318493_p5127248143016"></a><a name="en-us_topic_0000001150318493_p5127248143016"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p778003485413"><a name="en-us_topic_0000001150318493_p778003485413"></a><a name="en-us_topic_0000001150318493_p778003485413"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p137801834105419"><a name="en-us_topic_0000001150318493_p137801834105419"></a><a name="en-us_topic_0000001150318493_p137801834105419"></a>Indicates the asynchronous callback used to return the obtained character string.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getString<a name="en-us_topic_0000001150318493_section159261924165411"></a>

Obtains string resources associated with a specified resource ID in Promise mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table209261824205420"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row1492722415415"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1692782416547"><a name="en-us_topic_0000001150318493_p1692782416547"></a><a name="en-us_topic_0000001150318493_p1692782416547"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p189271240541"><a name="en-us_topic_0000001150318493_p189271240541"></a><a name="en-us_topic_0000001150318493_p189271240541"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p199271824205415"><a name="en-us_topic_0000001150318493_p199271824205415"></a><a name="en-us_topic_0000001150318493_p199271824205415"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p109270241547"><a name="en-us_topic_0000001150318493_p109270241547"></a><a name="en-us_topic_0000001150318493_p109270241547"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row2927132413546"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p135781232358"><a name="en-us_topic_0000001150318493_p135781232358"></a><a name="en-us_topic_0000001150318493_p135781232358"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p195781383513"><a name="en-us_topic_0000001150318493_p195781383513"></a><a name="en-us_topic_0000001150318493_p195781383513"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p16578439358"><a name="en-us_topic_0000001150318493_p16578439358"></a><a name="en-us_topic_0000001150318493_p16578439358"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p135783310357"><a name="en-us_topic_0000001150318493_p135783310357"></a><a name="en-us_topic_0000001150318493_p135783310357"></a>Indicates the resource ID.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table1492913246542"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row169291824135411"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p15929132485415"><a name="en-us_topic_0000001150318493_p15929132485415"></a><a name="en-us_topic_0000001150318493_p15929132485415"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p392918245541"><a name="en-us_topic_0000001150318493_p392918245541"></a><a name="en-us_topic_0000001150318493_p392918245541"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row1592992455414"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p179291924135420"><a name="en-us_topic_0000001150318493_p179291924135420"></a><a name="en-us_topic_0000001150318493_p179291924135420"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p17929142485416"><a name="en-us_topic_0000001150318493_p17929142485416"></a><a name="en-us_topic_0000001150318493_p17929142485416"></a>Indicates the character string corresponding to the resource ID.</p>
</td>
</tr>
</tbody>
</table>

### getStringArray<a name="en-us_topic_0000001150318493_section4490132775420"></a>

Obtains the array of character strings corresponding to a specified resource ID in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table104901227185415"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row1849042719548"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p2491727195416"><a name="en-us_topic_0000001150318493_p2491727195416"></a><a name="en-us_topic_0000001150318493_p2491727195416"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p449122775413"><a name="en-us_topic_0000001150318493_p449122775413"></a><a name="en-us_topic_0000001150318493_p449122775413"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p549117275549"><a name="en-us_topic_0000001150318493_p549117275549"></a><a name="en-us_topic_0000001150318493_p549117275549"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p4491152716543"><a name="en-us_topic_0000001150318493_p4491152716543"></a><a name="en-us_topic_0000001150318493_p4491152716543"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row84911027155414"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1738472410372"><a name="en-us_topic_0000001150318493_p1738472410372"></a><a name="en-us_topic_0000001150318493_p1738472410372"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1438462419379"><a name="en-us_topic_0000001150318493_p1438462419379"></a><a name="en-us_topic_0000001150318493_p1438462419379"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p13841524203711"><a name="en-us_topic_0000001150318493_p13841524203711"></a><a name="en-us_topic_0000001150318493_p13841524203711"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p8384142493715"><a name="en-us_topic_0000001150318493_p8384142493715"></a><a name="en-us_topic_0000001150318493_p8384142493715"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row4491142717542"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p11384142443715"><a name="en-us_topic_0000001150318493_p11384142443715"></a><a name="en-us_topic_0000001150318493_p11384142443715"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1538472473719"><a name="en-us_topic_0000001150318493_p1538472473719"></a><a name="en-us_topic_0000001150318493_p1538472473719"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;Array&lt;string&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p18384132473713"><a name="en-us_topic_0000001150318493_p18384132473713"></a><a name="en-us_topic_0000001150318493_p18384132473713"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p8384132411379"><a name="en-us_topic_0000001150318493_p8384132411379"></a><a name="en-us_topic_0000001150318493_p8384132411379"></a>Indicates the asynchronous callback used to return the obtained array of character strings.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getStringArray<a name="en-us_topic_0000001150318493_section1992322017541"></a>

Obtains the array of character strings corresponding to a specified resource ID in Promise mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table11924132005411"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row13924172017543"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1392442016541"><a name="en-us_topic_0000001150318493_p1392442016541"></a><a name="en-us_topic_0000001150318493_p1392442016541"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p0924920145417"><a name="en-us_topic_0000001150318493_p0924920145417"></a><a name="en-us_topic_0000001150318493_p0924920145417"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p392452011549"><a name="en-us_topic_0000001150318493_p392452011549"></a><a name="en-us_topic_0000001150318493_p392452011549"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p1992492065414"><a name="en-us_topic_0000001150318493_p1992492065414"></a><a name="en-us_topic_0000001150318493_p1992492065414"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row15924220135414"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1451111743917"><a name="en-us_topic_0000001150318493_p1451111743917"></a><a name="en-us_topic_0000001150318493_p1451111743917"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p9511157113911"><a name="en-us_topic_0000001150318493_p9511157113911"></a><a name="en-us_topic_0000001150318493_p9511157113911"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p195117718397"><a name="en-us_topic_0000001150318493_p195117718397"></a><a name="en-us_topic_0000001150318493_p195117718397"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p151119713915"><a name="en-us_topic_0000001150318493_p151119713915"></a><a name="en-us_topic_0000001150318493_p151119713915"></a>Indicates the resource ID.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table1492552055418"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row20925132035420"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p10925202010544"><a name="en-us_topic_0000001150318493_p10925202010544"></a><a name="en-us_topic_0000001150318493_p10925202010544"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p129269201544"><a name="en-us_topic_0000001150318493_p129269201544"></a><a name="en-us_topic_0000001150318493_p129269201544"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row119261820145419"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p179309445393"><a name="en-us_topic_0000001150318493_p179309445393"></a><a name="en-us_topic_0000001150318493_p179309445393"></a>Promise&lt;Array&lt;string&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p139301144153915"><a name="en-us_topic_0000001150318493_p139301144153915"></a><a name="en-us_topic_0000001150318493_p139301144153915"></a>Indicates the array of character strings corresponding to the specified resource ID.</p>
</td>
</tr>
</tbody>
</table>

### getMedia<a name="en-us_topic_0000001150318493_section6710152513409"></a>

Obtains the content of the media file corresponding to a specified resource ID in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table13710192554016"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row3710152534017"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p47108259406"><a name="en-us_topic_0000001150318493_p47108259406"></a><a name="en-us_topic_0000001150318493_p47108259406"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p2710102564013"><a name="en-us_topic_0000001150318493_p2710102564013"></a><a name="en-us_topic_0000001150318493_p2710102564013"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p17710525154014"><a name="en-us_topic_0000001150318493_p17710525154014"></a><a name="en-us_topic_0000001150318493_p17710525154014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p771022517402"><a name="en-us_topic_0000001150318493_p771022517402"></a><a name="en-us_topic_0000001150318493_p771022517402"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row871062544010"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1871016257407"><a name="en-us_topic_0000001150318493_p1871016257407"></a><a name="en-us_topic_0000001150318493_p1871016257407"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1371002534015"><a name="en-us_topic_0000001150318493_p1371002534015"></a><a name="en-us_topic_0000001150318493_p1371002534015"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p16711122515403"><a name="en-us_topic_0000001150318493_p16711122515403"></a><a name="en-us_topic_0000001150318493_p16711122515403"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1271119257400"><a name="en-us_topic_0000001150318493_p1271119257400"></a><a name="en-us_topic_0000001150318493_p1271119257400"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row1971112524019"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p27111125204017"><a name="en-us_topic_0000001150318493_p27111125204017"></a><a name="en-us_topic_0000001150318493_p27111125204017"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1371152514409"><a name="en-us_topic_0000001150318493_p1371152514409"></a><a name="en-us_topic_0000001150318493_p1371152514409"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;Array&lt;Uint8Array&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p13711625124019"><a name="en-us_topic_0000001150318493_p13711625124019"></a><a name="en-us_topic_0000001150318493_p13711625124019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p8711172511406"><a name="en-us_topic_0000001150318493_p8711172511406"></a><a name="en-us_topic_0000001150318493_p8711172511406"></a>Indicates the asynchronous callback used to return the obtained media file content.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getMedia<a name="en-us_topic_0000001150318493_section6711152517409"></a>

Obtains the content of the media file corresponding to a specified resource ID in Promise mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table10711725154015"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row8712225154016"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p371210253407"><a name="en-us_topic_0000001150318493_p371210253407"></a><a name="en-us_topic_0000001150318493_p371210253407"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p771214253404"><a name="en-us_topic_0000001150318493_p771214253404"></a><a name="en-us_topic_0000001150318493_p771214253404"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p171242574017"><a name="en-us_topic_0000001150318493_p171242574017"></a><a name="en-us_topic_0000001150318493_p171242574017"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p6712725114013"><a name="en-us_topic_0000001150318493_p6712725114013"></a><a name="en-us_topic_0000001150318493_p6712725114013"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row971232544013"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p67126252406"><a name="en-us_topic_0000001150318493_p67126252406"></a><a name="en-us_topic_0000001150318493_p67126252406"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p12712425114012"><a name="en-us_topic_0000001150318493_p12712425114012"></a><a name="en-us_topic_0000001150318493_p12712425114012"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p19712152511403"><a name="en-us_topic_0000001150318493_p19712152511403"></a><a name="en-us_topic_0000001150318493_p19712152511403"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p8712162564019"><a name="en-us_topic_0000001150318493_p8712162564019"></a><a name="en-us_topic_0000001150318493_p8712162564019"></a>Indicates the resource ID.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table271292534018"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row1971352524020"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p9713925104011"><a name="en-us_topic_0000001150318493_p9713925104011"></a><a name="en-us_topic_0000001150318493_p9713925104011"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p471352574010"><a name="en-us_topic_0000001150318493_p471352574010"></a><a name="en-us_topic_0000001150318493_p471352574010"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row9713142554012"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p1071352554019"><a name="en-us_topic_0000001150318493_p1071352554019"></a><a name="en-us_topic_0000001150318493_p1071352554019"></a>Promise&lt;Array&lt;Uint8Array&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p8713192517405"><a name="en-us_topic_0000001150318493_p8713192517405"></a><a name="en-us_topic_0000001150318493_p8713192517405"></a>Indicates the content of the media file corresponding to the specified resource ID.</p>
</td>
</tr>
</tbody>
</table>

### getMediaBase64<a name="en-us_topic_0000001150318493_section11402326194315"></a>

Obtains the Base64 code of the image resource corresponding to the specified resource ID in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table1740272614430"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row540272684311"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1340272624311"><a name="en-us_topic_0000001150318493_p1340272624311"></a><a name="en-us_topic_0000001150318493_p1340272624311"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p8402192617438"><a name="en-us_topic_0000001150318493_p8402192617438"></a><a name="en-us_topic_0000001150318493_p8402192617438"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p1440222674312"><a name="en-us_topic_0000001150318493_p1440222674312"></a><a name="en-us_topic_0000001150318493_p1440222674312"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p11403926164312"><a name="en-us_topic_0000001150318493_p11403926164312"></a><a name="en-us_topic_0000001150318493_p11403926164312"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row54031726114310"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p114031326154312"><a name="en-us_topic_0000001150318493_p114031326154312"></a><a name="en-us_topic_0000001150318493_p114031326154312"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1040382604313"><a name="en-us_topic_0000001150318493_p1040382604313"></a><a name="en-us_topic_0000001150318493_p1040382604313"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p94035265431"><a name="en-us_topic_0000001150318493_p94035265431"></a><a name="en-us_topic_0000001150318493_p94035265431"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1140392612434"><a name="en-us_topic_0000001150318493_p1140392612434"></a><a name="en-us_topic_0000001150318493_p1140392612434"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row12403192615432"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p14031226144319"><a name="en-us_topic_0000001150318493_p14031226144319"></a><a name="en-us_topic_0000001150318493_p14031226144319"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1740382618433"><a name="en-us_topic_0000001150318493_p1740382618433"></a><a name="en-us_topic_0000001150318493_p1740382618433"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p144032026104313"><a name="en-us_topic_0000001150318493_p144032026104313"></a><a name="en-us_topic_0000001150318493_p144032026104313"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p18403142618437"><a name="en-us_topic_0000001150318493_p18403142618437"></a><a name="en-us_topic_0000001150318493_p18403142618437"></a>Indicates the asynchronous callback used to return the obtained Base64 code of the image resource.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getMediaBase64<a name="en-us_topic_0000001150318493_section6404726124312"></a>

Obtains the Base64 code of the image resource corresponding to the specified resource ID in Promise mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table1840452674318"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row84041226184317"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p5404926154316"><a name="en-us_topic_0000001150318493_p5404926154316"></a><a name="en-us_topic_0000001150318493_p5404926154316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p194048268435"><a name="en-us_topic_0000001150318493_p194048268435"></a><a name="en-us_topic_0000001150318493_p194048268435"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p184041226104320"><a name="en-us_topic_0000001150318493_p184041226104320"></a><a name="en-us_topic_0000001150318493_p184041226104320"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p12404726184315"><a name="en-us_topic_0000001150318493_p12404726184315"></a><a name="en-us_topic_0000001150318493_p12404726184315"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row8404126124314"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p104051426104313"><a name="en-us_topic_0000001150318493_p104051426104313"></a><a name="en-us_topic_0000001150318493_p104051426104313"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p15405172610430"><a name="en-us_topic_0000001150318493_p15405172610430"></a><a name="en-us_topic_0000001150318493_p15405172610430"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p240582616430"><a name="en-us_topic_0000001150318493_p240582616430"></a><a name="en-us_topic_0000001150318493_p240582616430"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p124051726104318"><a name="en-us_topic_0000001150318493_p124051726104318"></a><a name="en-us_topic_0000001150318493_p124051726104318"></a>Indicates the resource ID.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table1240514269437"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row1240532620433"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p1406202614313"><a name="en-us_topic_0000001150318493_p1406202614313"></a><a name="en-us_topic_0000001150318493_p1406202614313"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p8406226124316"><a name="en-us_topic_0000001150318493_p8406226124316"></a><a name="en-us_topic_0000001150318493_p8406226124316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row164065261435"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p5406182612436"><a name="en-us_topic_0000001150318493_p5406182612436"></a><a name="en-us_topic_0000001150318493_p5406182612436"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p3406182612434"><a name="en-us_topic_0000001150318493_p3406182612434"></a><a name="en-us_topic_0000001150318493_p3406182612434"></a>Indicates the Base64 code of the image resource corresponding to the specified resource ID.</p>
</td>
</tr>
</tbody>
</table>

### getConfiguration<a name="en-us_topic_0000001150318493_section8123152874015"></a>

Obtains the device configuration in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table15123112811401"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row13123102844013"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1812311285406"><a name="en-us_topic_0000001150318493_p1812311285406"></a><a name="en-us_topic_0000001150318493_p1812311285406"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p101239284409"><a name="en-us_topic_0000001150318493_p101239284409"></a><a name="en-us_topic_0000001150318493_p101239284409"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p41236289403"><a name="en-us_topic_0000001150318493_p41236289403"></a><a name="en-us_topic_0000001150318493_p41236289403"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p201231228164019"><a name="en-us_topic_0000001150318493_p201231228164019"></a><a name="en-us_topic_0000001150318493_p201231228164019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row141241285400"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p812452814012"><a name="en-us_topic_0000001150318493_p812452814012"></a><a name="en-us_topic_0000001150318493_p812452814012"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p1412420284405"><a name="en-us_topic_0000001150318493_p1412420284405"></a><a name="en-us_topic_0000001150318493_p1412420284405"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;<a href="#en-us_topic_0000001150318493_section12882825611">Configuration</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p10124122817403"><a name="en-us_topic_0000001150318493_p10124122817403"></a><a name="en-us_topic_0000001150318493_p10124122817403"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p161241028184011"><a name="en-us_topic_0000001150318493_p161241028184011"></a><a name="en-us_topic_0000001150318493_p161241028184011"></a>Indicates the asynchronous callback used to return the obtained device configuration.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getConfiguration<a name="en-us_topic_0000001150318493_section312515284406"></a>

Obtains the device configuration in Promise mode.

**Parameters**

None.

**Return Values**

<a name="en-us_topic_0000001150318493_table12126228134013"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row11126728184016"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p191261028174019"><a name="en-us_topic_0000001150318493_p191261028174019"></a><a name="en-us_topic_0000001150318493_p191261028174019"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p6126202894018"><a name="en-us_topic_0000001150318493_p6126202894018"></a><a name="en-us_topic_0000001150318493_p6126202894018"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row8126728174017"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p112718283409"><a name="en-us_topic_0000001150318493_p112718283409"></a><a name="en-us_topic_0000001150318493_p112718283409"></a>Promise&lt;<a href="#en-us_topic_0000001150318493_section12882825611">Configuration</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p1412792864011"><a name="en-us_topic_0000001150318493_p1412792864011"></a><a name="en-us_topic_0000001150318493_p1412792864011"></a>Indicates the device configuration.</p>
</td>
</tr>
</tbody>
</table>

### getDeviceCapability<a name="en-us_topic_0000001150318493_section104951210135017"></a>

Obtains the device capability in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table1495410115014"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row649514108507"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p54957102501"><a name="en-us_topic_0000001150318493_p54957102501"></a><a name="en-us_topic_0000001150318493_p54957102501"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.28%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p649531011504"><a name="en-us_topic_0000001150318493_p649531011504"></a><a name="en-us_topic_0000001150318493_p649531011504"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="5.319999999999999%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p74954109501"><a name="en-us_topic_0000001150318493_p74954109501"></a><a name="en-us_topic_0000001150318493_p74954109501"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p174951910155019"><a name="en-us_topic_0000001150318493_p174951910155019"></a><a name="en-us_topic_0000001150318493_p174951910155019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row11495710115015"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p154951510185014"><a name="en-us_topic_0000001150318493_p154951510185014"></a><a name="en-us_topic_0000001150318493_p154951510185014"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.28%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p174955105509"><a name="en-us_topic_0000001150318493_p174955105509"></a><a name="en-us_topic_0000001150318493_p174955105509"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;<a href="#en-us_topic_0000001150318493_section7200123494410">DeviceCapability</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="5.319999999999999%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p1495121012501"><a name="en-us_topic_0000001150318493_p1495121012501"></a><a name="en-us_topic_0000001150318493_p1495121012501"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p54969103507"><a name="en-us_topic_0000001150318493_p54969103507"></a><a name="en-us_topic_0000001150318493_p54969103507"></a>Indicates the asynchronous callback used to return the obtained device capability.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getDeviceCapability<a name="en-us_topic_0000001150318493_section114961410115013"></a>

Obtains the device capability in Promise mode.

**Parameters**

None.

**Return Values**

<a name="en-us_topic_0000001150318493_table17496111015019"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row12496111095010"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p1496101015503"><a name="en-us_topic_0000001150318493_p1496101015503"></a><a name="en-us_topic_0000001150318493_p1496101015503"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p1496110155013"><a name="en-us_topic_0000001150318493_p1496110155013"></a><a name="en-us_topic_0000001150318493_p1496110155013"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row10496181065014"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p19497151095012"><a name="en-us_topic_0000001150318493_p19497151095012"></a><a name="en-us_topic_0000001150318493_p19497151095012"></a>Promise&lt;<a href="#en-us_topic_0000001150318493_section7200123494410">DeviceCapability</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p18497141011504"><a name="en-us_topic_0000001150318493_p18497141011504"></a><a name="en-us_topic_0000001150318493_p18497141011504"></a>Indicates the device capability.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getPluralString<a name="en-us_topic_0000001150318493_section1549163064013"></a>

Obtains the singular-plural character string represented by the ID string corresponding to the specified number in callback mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table649330164020"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row6491302400"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1749123034017"><a name="en-us_topic_0000001150318493_p1749123034017"></a><a name="en-us_topic_0000001150318493_p1749123034017"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p449143064012"><a name="en-us_topic_0000001150318493_p449143064012"></a><a name="en-us_topic_0000001150318493_p449143064012"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p1349123044017"><a name="en-us_topic_0000001150318493_p1349123044017"></a><a name="en-us_topic_0000001150318493_p1349123044017"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p11491302408"><a name="en-us_topic_0000001150318493_p11491302408"></a><a name="en-us_topic_0000001150318493_p11491302408"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row145013054010"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p65073012401"><a name="en-us_topic_0000001150318493_p65073012401"></a><a name="en-us_topic_0000001150318493_p65073012401"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p11502030124016"><a name="en-us_topic_0000001150318493_p11502030124016"></a><a name="en-us_topic_0000001150318493_p11502030124016"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p1650330174019"><a name="en-us_topic_0000001150318493_p1650330174019"></a><a name="en-us_topic_0000001150318493_p1650330174019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1650163034013"><a name="en-us_topic_0000001150318493_p1650163034013"></a><a name="en-us_topic_0000001150318493_p1650163034013"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row18497201611531"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1949711615318"><a name="en-us_topic_0000001150318493_p1949711615318"></a><a name="en-us_topic_0000001150318493_p1949711615318"></a>num:</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p13497191615532"><a name="en-us_topic_0000001150318493_p13497191615532"></a><a name="en-us_topic_0000001150318493_p13497191615532"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p9497716125311"><a name="en-us_topic_0000001150318493_p9497716125311"></a><a name="en-us_topic_0000001150318493_p9497716125311"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p249771619536"><a name="en-us_topic_0000001150318493_p249771619536"></a><a name="en-us_topic_0000001150318493_p249771619536"></a>Indicates the number.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row45053011403"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p1650230204016"><a name="en-us_topic_0000001150318493_p1650230204016"></a><a name="en-us_topic_0000001150318493_p1650230204016"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p165010302401"><a name="en-us_topic_0000001150318493_p165010302401"></a><a name="en-us_topic_0000001150318493_p165010302401"></a><a href="#en-us_topic_0000001150318493_section256244135613">AsyncCallback</a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p7501530164018"><a name="en-us_topic_0000001150318493_p7501530164018"></a><a name="en-us_topic_0000001150318493_p7501530164018"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p17501330104012"><a name="en-us_topic_0000001150318493_p17501330104012"></a><a name="en-us_topic_0000001150318493_p17501330104012"></a>Indicates the asynchronous callback used to return the singular-plural character string represented by the ID string corresponding to the specified number.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

None.

### getPluralString<a name="en-us_topic_0000001150318493_section165183015405"></a>

Obtains the singular-plural character string represented by the ID string corresponding to the specified number in Promise mode.

**Parameters**

<a name="en-us_topic_0000001150318493_table105173016408"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row195223064018"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150318493_p1752183064013"><a name="en-us_topic_0000001150318493_p1752183064013"></a><a name="en-us_topic_0000001150318493_p1752183064013"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150318493_p175273064016"><a name="en-us_topic_0000001150318493_p175273064016"></a><a name="en-us_topic_0000001150318493_p175273064016"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150318493_p1452430124014"><a name="en-us_topic_0000001150318493_p1452430124014"></a><a name="en-us_topic_0000001150318493_p1452430124014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150318493_p9525305406"><a name="en-us_topic_0000001150318493_p9525305406"></a><a name="en-us_topic_0000001150318493_p9525305406"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row65233019409"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p125213301405"><a name="en-us_topic_0000001150318493_p125213301405"></a><a name="en-us_topic_0000001150318493_p125213301405"></a>resId</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p55293019409"><a name="en-us_topic_0000001150318493_p55293019409"></a><a name="en-us_topic_0000001150318493_p55293019409"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p553103094019"><a name="en-us_topic_0000001150318493_p553103094019"></a><a name="en-us_topic_0000001150318493_p553103094019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p1453430124015"><a name="en-us_topic_0000001150318493_p1453430124015"></a><a name="en-us_topic_0000001150318493_p1453430124015"></a>Indicates the resource ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150318493_row05323013406"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150318493_p197652617548"><a name="en-us_topic_0000001150318493_p197652617548"></a><a name="en-us_topic_0000001150318493_p197652617548"></a>num:</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150318493_p187651685411"><a name="en-us_topic_0000001150318493_p187651685411"></a><a name="en-us_topic_0000001150318493_p187651685411"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150318493_p776517611543"><a name="en-us_topic_0000001150318493_p776517611543"></a><a name="en-us_topic_0000001150318493_p776517611543"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150318493_p2076646145413"><a name="en-us_topic_0000001150318493_p2076646145413"></a><a name="en-us_topic_0000001150318493_p2076646145413"></a>Indicates the number.</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150318493_table45313011403"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150318493_row554133016401"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150318493_p13549300401"><a name="en-us_topic_0000001150318493_p13549300401"></a><a name="en-us_topic_0000001150318493_p13549300401"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150318493_p75419307408"><a name="en-us_topic_0000001150318493_p75419307408"></a><a name="en-us_topic_0000001150318493_p75419307408"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150318493_row1554143094015"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150318493_p115483064019"><a name="en-us_topic_0000001150318493_p115483064019"></a><a name="en-us_topic_0000001150318493_p115483064019"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150318493_p1965948111118"><a name="en-us_topic_0000001150318493_p1965948111118"></a><a name="en-us_topic_0000001150318493_p1965948111118"></a>Indicates the singular-plural character string represented by the ID string corresponding to the specified number.</p>
</td>
</tr>
</tbody>
</table>

