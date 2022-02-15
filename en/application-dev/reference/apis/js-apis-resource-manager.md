# Resource Manager<a name="EN-US_TOPIC_0000001192428610"></a>


>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import resourceManager from '@ohos.resourceManager';
```

## Required Permissions<a name="section11257113618419"></a>

None

## resourceManager.getResourceManager<a name="section192192415554"></a>

getResourceManager\(callback: AsyncCallback<ResourceManager\>\): void

Obtains the  **ResourceManager**  object of the current application. This method uses a callback to return the result.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="8.81%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.11%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.710000000000001%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.37%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="8.81%" headers="mcps1.1.5.1.1 "><p id="p13838351705"><a name="p13838351705"></a><a name="p13838351705"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.11%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>AsyncCallback&lt;<a href="#section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.710000000000001%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.37%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Asynchronous callback used to return the <strong id="b1661432813912"><a name="b1661432813912"></a><a name="b1661432813912"></a>ResourceManager</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        if (error != null) {
            console.log("error occurs" + error);
            return; 
        }
        mgr.getString(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


## resourceManager.getResourceManager<a name="section46989284018"></a>

getResourceManager\(bundleName: string, callback: AsyncCallback<ResourceManager\>\): void

Obtains the  **ResourceManager**  object of the specified application. This method uses a callback to return the result.

-   Parameters

    <a name="table146992288015"></a>
    <table><thead align="left"><tr id="row16994286017"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p196991328500"><a name="p196991328500"></a><a name="p196991328500"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p156991028607"><a name="p156991028607"></a><a name="p156991028607"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.762631629794225%" id="mcps1.1.5.1.3"><p id="p569920281005"><a name="p569920281005"></a><a name="p569920281005"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.211670370012556%" id="mcps1.1.5.1.4"><p id="p5699428800"><a name="p5699428800"></a><a name="p5699428800"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row469912281801"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p46991028909"><a name="p46991028909"></a><a name="p46991028909"></a>bundleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p469919282017"><a name="p469919282017"></a><a name="p469919282017"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="p169982812013"><a name="p169982812013"></a><a name="p169982812013"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="p569972818014"><a name="p569972818014"></a><a name="p569972818014"></a>Bundle name of the specified application.</p>
    </td>
    </tr>
    <tr id="row769982815012"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p10188114718716"><a name="p10188114718716"></a><a name="p10188114718716"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1518810471873"><a name="p1518810471873"></a><a name="p1518810471873"></a>AsyncCallback&lt;<a href="#section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.762631629794225%" headers="mcps1.1.5.1.3 "><p id="p718813478713"><a name="p718813478713"></a><a name="p718813478713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.211670370012556%" headers="mcps1.1.5.1.4 "><p id="p1618844718710"><a name="p1618844718710"></a><a name="p1618844718710"></a>Asynchronous callback used to return the <strong id="b44311356171313"><a name="b44311356171313"></a><a name="b44311356171313"></a>ResourceManager</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {
    });
    ```


## resourceManager.getResourceManager<a name="section0543541673"></a>

getResourceManager\(\): Promise<ResourceManager\>

Obtains the  **ResourceManager**  object of the current application. This method uses a promise to return the result.

-   Return values

    <a name="table125442040718"></a>
    <table><thead align="left"><tr id="row11545745715"><th class="cellrowborder" valign="top" width="21.19%" id="mcps1.1.3.1.1"><p id="p115451947716"><a name="p115451947716"></a><a name="p115451947716"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.81%" id="mcps1.1.3.1.2"><p id="p15451043716"><a name="p15451043716"></a><a name="p15451043716"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row55451841670"><td class="cellrowborder" valign="top" width="21.19%" headers="mcps1.1.3.1.1 "><p id="p135451841712"><a name="p135451841712"></a><a name="p135451841712"></a>Promise&lt;<a href="#section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.81%" headers="mcps1.1.3.1.2 "><p id="p954512419714"><a name="p954512419714"></a><a name="p954512419714"></a>Promise used to return the <strong id="b7370162314145"><a name="b7370162314145"></a><a name="b7370162314145"></a>ResourceManager</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager().then(mgr => {
        mgr.getString(0x1000000, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    }).catch(error => {
        console.log(error);
    });
    ```


## resourceManager.getResourceManager<a name="section1816951410716"></a>

getResourceManager\(bundleName: string\): Promise<ResourceManager\>

Obtains the  **ResourceManager**  object of the specified application. This method uses a promise to return the result.

-   Parameters

    <a name="table6169161415710"></a>
    <table><thead align="left"><tr id="row141691914878"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p191691114172"><a name="p191691114172"></a><a name="p191691114172"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p91690141774"><a name="p91690141774"></a><a name="p91690141774"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1417013141074"><a name="p1417013141074"></a><a name="p1417013141074"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1117051418716"><a name="p1117051418716"></a><a name="p1117051418716"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1917061417717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16466037131616"><a name="p16466037131616"></a><a name="p16466037131616"></a>bundleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p8466637101620"><a name="p8466637101620"></a><a name="p8466637101620"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p446633713162"><a name="p446633713162"></a><a name="p446633713162"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1446633701612"><a name="p1446633701612"></a><a name="p1446633701612"></a>Bundle name of the specified application.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table51715149717"></a>
    <table><thead align="left"><tr id="row717151413717"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p917117141075"><a name="p917117141075"></a><a name="p917117141075"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p131716141778"><a name="p131716141778"></a><a name="p131716141778"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1417116141579"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1940551651713"><a name="p1940551651713"></a><a name="p1940551651713"></a>Promise&lt;<a href="#section137771134135415">ResourceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p140517164171"><a name="p140517164171"></a><a name="p140517164171"></a>Promise used to return the <strong id="b19744123815167"><a name="b19744123815167"></a><a name="b19744123815167"></a>ResourceManager</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager("com.example.myapplication").then(mgr => {
    
    }).catch(error => {
    
    });
    ```


## Direction<a name="section099619567453"></a>

Enumerates screen directions.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p26821854218"><a name="p26821854218"></a><a name="p26821854218"></a>DIRECTION_VERTICAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>Portrait</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p12106173918219"><a name="p12106173918219"></a><a name="p12106173918219"></a>DIRECTION_HORIZONTAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15865395215"><a name="p15865395215"></a><a name="p15865395215"></a>Landscape</p>
</td>
</tr>
</tbody>
</table>

## DeviceType<a name="section4734636131914"></a>

Enumerates device types.

<a name="table873411360193"></a>
<table><thead align="left"><tr id="row187341036191911"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p19735163661915"><a name="p19735163661915"></a><a name="p19735163661915"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p12735173661913"><a name="p12735173661913"></a><a name="p12735173661913"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p12735163611913"><a name="p12735163611913"></a><a name="p12735163611913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row19735113619194"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p27351736111919"><a name="p27351736111919"></a><a name="p27351736111919"></a>DEVICE_TYPE_PHONE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p137351636131917"><a name="p137351636131917"></a><a name="p137351636131917"></a>0x00</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1873543614192"><a name="p1873543614192"></a><a name="p1873543614192"></a>Phone</p>
</td>
</tr>
<tr id="row1956619491229"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1456634917225"><a name="p1456634917225"></a><a name="p1456634917225"></a>DEVICE_TYPE_TABLET</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1256634982217"><a name="p1256634982217"></a><a name="p1256634982217"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p598213916331"><a name="p598213916331"></a><a name="p598213916331"></a>Tablet</p>
</td>
</tr>
<tr id="row57811744162211"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p47820449225"><a name="p47820449225"></a><a name="p47820449225"></a>DEVICE_TYPE_CAR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1878244417224"><a name="p1878244417224"></a><a name="p1878244417224"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p378213446229"><a name="p378213446229"></a><a name="p378213446229"></a>Head unit</p>
</td>
</tr>
<tr id="row578284442218"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p117821445229"><a name="p117821445229"></a><a name="p117821445229"></a>DEVICE_TYPE_PC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p137821044172214"><a name="p137821044172214"></a><a name="p137821044172214"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p18782124422219"><a name="p18782124422219"></a><a name="p18782124422219"></a>PC</p>
</td>
</tr>
<tr id="row84751140142210"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p0475184014225"><a name="p0475184014225"></a><a name="p0475184014225"></a>DEVICE_TYPE_TV</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1847519407228"><a name="p1847519407228"></a><a name="p1847519407228"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p44757409225"><a name="p44757409225"></a><a name="p44757409225"></a>Smart TV</p>
</td>
</tr>
<tr id="row9735736161917"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p2073520364190"><a name="p2073520364190"></a><a name="p2073520364190"></a>DEVICE_TYPE_WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1273683612191"><a name="p1273683612191"></a><a name="p1273683612191"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1873653617198"><a name="p1873653617198"></a><a name="p1873653617198"></a>Wearable</p>
</td>
</tr>
</tbody>
</table>

## ScreenDensity<a name="section7331173812197"></a>

Enumerates screen density types.

<a name="table203311638181919"></a>
<table><thead align="left"><tr id="row33311338101917"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p733183811195"><a name="p733183811195"></a><a name="p733183811195"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.42%" id="mcps1.1.4.1.2"><p id="p1331163810197"><a name="p1331163810197"></a><a name="p1331163810197"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.68%" id="mcps1.1.4.1.3"><p id="p10331238191920"><a name="p10331238191920"></a><a name="p10331238191920"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row19331163821912"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p133311538131919"><a name="p133311538131919"></a><a name="p133311538131919"></a>SCREEN_SDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p833113385195"><a name="p833113385195"></a><a name="p833113385195"></a>120</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p1133133881918"><a name="p1133133881918"></a><a name="p1133133881918"></a>Screen density with small-scale dots per inch (SDPI).</p>
</td>
</tr>
<tr id="row1399293473011"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p599213418300"><a name="p599213418300"></a><a name="p599213418300"></a>SCREEN_MDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p1099210349304"><a name="p1099210349304"></a><a name="p1099210349304"></a>160</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p139921534173016"><a name="p139921534173016"></a><a name="p139921534173016"></a>Screen density with medium-scale dots per inch (MDPI)</p>
</td>
</tr>
<tr id="row4841123016304"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p188417305309"><a name="p188417305309"></a><a name="p188417305309"></a>SCREEN_LDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p10841193014308"><a name="p10841193014308"></a><a name="p10841193014308"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p1084116309304"><a name="p1084116309304"></a><a name="p1084116309304"></a>Screen density with large-scale dots per inch (LDPI).</p>
</td>
</tr>
<tr id="row1784163013302"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p48413309304"><a name="p48413309304"></a><a name="p48413309304"></a>SCREEN_XLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p128411930183011"><a name="p128411930183011"></a><a name="p128411930183011"></a>320</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p084110301309"><a name="p084110301309"></a><a name="p084110301309"></a>Screen density with extra-large-scale dots per inch (XLDPI).</p>
</td>
</tr>
<tr id="row1084092610308"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p128411926173012"><a name="p128411926173012"></a><a name="p128411926173012"></a>SCREEN_XXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p884192693019"><a name="p884192693019"></a><a name="p884192693019"></a>480</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p6841226163015"><a name="p6841226163015"></a><a name="p6841226163015"></a>Screen density with extra-extra-large-scale dots per inch (XXLDPI).</p>
</td>
</tr>
<tr id="row11331163891916"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p14331163861914"><a name="p14331163861914"></a><a name="p14331163861914"></a>SCREEN_XXXLDPI</p>
</td>
<td class="cellrowborder" valign="top" width="12.42%" headers="mcps1.1.4.1.2 "><p id="p933115383192"><a name="p933115383192"></a><a name="p933115383192"></a>640</p>
</td>
<td class="cellrowborder" valign="top" width="59.68%" headers="mcps1.1.4.1.3 "><p id="p199356496257"><a name="p199356496257"></a><a name="p199356496257"></a>Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI).</p>
</td>
</tr>
</tbody>
</table>

## Configuration<a name="section12882825611"></a>

Provides the device configuration.

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p85976431431"><a name="p85976431431"></a><a name="p85976431431"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p2059710431030"><a name="p2059710431030"></a><a name="p2059710431030"></a><a href="#section099619567453">Direction</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1059711439317"><a name="p1059711439317"></a><a name="p1059711439317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p659715430317"><a name="p659715430317"></a><a name="p659715430317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2059719436313"><a name="p2059719436313"></a><a name="p2059719436313"></a>Screen direction of the current device.</p>
</td>
</tr>
<tr id="row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1559710432310"><a name="p1559710432310"></a><a name="p1559710432310"></a>locale</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p16597144318312"><a name="p16597144318312"></a><a name="p16597144318312"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p12597194313317"><a name="p12597194313317"></a><a name="p12597194313317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1259710431236"><a name="p1259710431236"></a><a name="p1259710431236"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10597843034"><a name="p10597843034"></a><a name="p10597843034"></a>Current system language.</p>
</td>
</tr>
</tbody>
</table>

## DeviceCapability<a name="section7200123494410"></a>

Provides the device capability.

<a name="table16201103444414"></a>
<table><thead align="left"><tr id="row620123444415"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p1620163494418"><a name="p1620163494418"></a><a name="p1620163494418"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p15201434124418"><a name="p15201434124418"></a><a name="p15201434124418"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p13201123484412"><a name="p13201123484412"></a><a name="p13201123484412"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1320123412448"><a name="p1320123412448"></a><a name="p1320123412448"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p9201934134419"><a name="p9201934134419"></a><a name="p9201934134419"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3201103494415"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p20826502499"><a name="p20826502499"></a><a name="p20826502499"></a>screenDensity</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p120143413448"><a name="p120143413448"></a><a name="p120143413448"></a><a href="#section7331173812197">ScreenDensity</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p18201334114417"><a name="p18201334114417"></a><a name="p18201334114417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p420113347441"><a name="p420113347441"></a><a name="p420113347441"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p202021934134412"><a name="p202021934134412"></a><a name="p202021934134412"></a>Screen density of the current device.</p>
</td>
</tr>
<tr id="row19202113413445"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p82028341442"><a name="p82028341442"></a><a name="p82028341442"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p62021434104413"><a name="p62021434104413"></a><a name="p62021434104413"></a><a href="#section4734636131914">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p142021134164413"><a name="p142021134164413"></a><a name="p142021134164413"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p22021834104417"><a name="p22021834104417"></a><a name="p22021834104417"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p112021341446"><a name="p112021341446"></a><a name="p112021341446"></a>Type of the current device.</p>
</td>
</tr>
</tbody>
</table>

## ResourceManager<a name="section137771134135415"></a>

Provides the capability of accessing application resources.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The methods involved in  **ResourceManager**  are applicable only to the TypeScript-based declarative development paradigm.
>-   Resource files are defined in the  **resources**  directory of the project. You can obtain the resource ID from  **$r\(resource address\).id**, for example,  **$r\(?app.string.test?\).id**.

### getString<a name="section9779153419548"></a>

getString\(resId: number, callback: AsyncCallback<string\>\): void

Obtains the string corresponding to the specified resource ID. This method uses a callback to return the result.

-   Parameters

    <a name="table15779123455418"></a>
    <table><thead align="left"><tr id="row37791234125419"><th class="cellrowborder" valign="top" width="9.07%" id="mcps1.1.5.1.1"><p id="p1778018347547"><a name="p1778018347547"></a><a name="p1778018347547"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.48%" id="mcps1.1.5.1.2"><p id="p12780113475417"><a name="p12780113475417"></a><a name="p12780113475417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p137801834145410"><a name="p137801834145410"></a><a name="p137801834145410"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1678053465414"><a name="p1678053465414"></a><a name="p1678053465414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row478015349541"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="p1978013410544"><a name="p1978013410544"></a><a name="p1978013410544"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="p13780123410542"><a name="p13780123410542"></a><a name="p13780123410542"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p14780334145419"><a name="p14780334145419"></a><a name="p14780334145419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p97801934185415"><a name="p97801934185415"></a><a name="p97801934185415"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row5780334175417"><td class="cellrowborder" valign="top" width="9.07%" headers="mcps1.1.5.1.1 "><p id="p1780113413548"><a name="p1780113413548"></a><a name="p1780113413548"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.1.5.1.2 "><p id="p5127248143016"><a name="p5127248143016"></a><a name="p5127248143016"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p778003485413"><a name="p778003485413"></a><a name="p778003485413"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p137801834105419"><a name="p137801834105419"></a><a name="p137801834105419"></a>Asynchronous callback used to return the obtained string.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getString($r('app.string.test').id, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getString<a name="section159261924165411"></a>

getString\(resId: number\): Promise<string\>

Obtains the string corresponding to the specified resource ID. This method uses a promise to return the result.

-   Parameters

    <a name="table209261824205420"></a>
    <table><thead align="left"><tr id="row1492722415415"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1692782416547"><a name="p1692782416547"></a><a name="p1692782416547"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p189271240541"><a name="p189271240541"></a><a name="p189271240541"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p199271824205415"><a name="p199271824205415"></a><a name="p199271824205415"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p109270241547"><a name="p109270241547"></a><a name="p109270241547"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2927132413546"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p135781232358"><a name="p135781232358"></a><a name="p135781232358"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p195781383513"><a name="p195781383513"></a><a name="p195781383513"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p16578439358"><a name="p16578439358"></a><a name="p16578439358"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p135783310357"><a name="p135783310357"></a><a name="p135783310357"></a>Resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1492913246542"></a>
    <table><thead align="left"><tr id="row169291824135411"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p15929132485415"><a name="p15929132485415"></a><a name="p15929132485415"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p392918245541"><a name="p392918245541"></a><a name="p392918245541"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1592992455414"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p179291924135420"><a name="p179291924135420"></a><a name="p179291924135420"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p17929142485416"><a name="p17929142485416"></a><a name="p17929142485416"></a>String corresponding to the resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getString($r('app.string.test').id).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getStringArray<a name="section4490132775420"></a>

getStringArray\(resId: number, callback: AsyncCallback<Array<string\>\>\): void

Obtains the array of strings corresponding to the specified resource ID. This method uses a callback to return the result.

-   Parameters

    <a name="table104901227185415"></a>
    <table><thead align="left"><tr id="row1849042719548"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="p2491727195416"><a name="p2491727195416"></a><a name="p2491727195416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="p449122775413"><a name="p449122775413"></a><a name="p449122775413"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p549117275549"><a name="p549117275549"></a><a name="p549117275549"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p4491152716543"><a name="p4491152716543"></a><a name="p4491152716543"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row84911027155414"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p1738472410372"><a name="p1738472410372"></a><a name="p1738472410372"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p1438462419379"><a name="p1438462419379"></a><a name="p1438462419379"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13841524203711"><a name="p13841524203711"></a><a name="p13841524203711"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8384142493715"><a name="p8384142493715"></a><a name="p8384142493715"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row4491142717542"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p11384142443715"><a name="p11384142443715"></a><a name="p11384142443715"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p1538472473719"><a name="p1538472473719"></a><a name="p1538472473719"></a>AsyncCallback&lt;Array&lt;string&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p18384132473713"><a name="p18384132473713"></a><a name="p18384132473713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8384132411379"><a name="p8384132411379"></a><a name="p8384132411379"></a>Asynchronous callback used to return the obtained array of strings.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getStringArray($r('app.strarray.test').id, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getStringArray<a name="section1992322017541"></a>

getStringArray\(resId: number\): Promise<Array<string\>\>

Obtains the array of strings corresponding to the specified resource ID. This method uses a promise to return the result.

-   Parameters

    <a name="table11924132005411"></a>
    <table><thead align="left"><tr id="row13924172017543"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1392442016541"><a name="p1392442016541"></a><a name="p1392442016541"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p0924920145417"><a name="p0924920145417"></a><a name="p0924920145417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p392452011549"><a name="p392452011549"></a><a name="p392452011549"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1992492065414"><a name="p1992492065414"></a><a name="p1992492065414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15924220135414"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1451111743917"><a name="p1451111743917"></a><a name="p1451111743917"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9511157113911"><a name="p9511157113911"></a><a name="p9511157113911"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p195117718397"><a name="p195117718397"></a><a name="p195117718397"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p151119713915"><a name="p151119713915"></a><a name="p151119713915"></a>Resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1492552055418"></a>
    <table><thead align="left"><tr id="row20925132035420"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p10925202010544"><a name="p10925202010544"></a><a name="p10925202010544"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p129269201544"><a name="p129269201544"></a><a name="p129269201544"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row119261820145419"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p179309445393"><a name="p179309445393"></a><a name="p179309445393"></a>Promise&lt;Array&lt;string&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p139301144153915"><a name="p139301144153915"></a><a name="p139301144153915"></a>Array of strings corresponding to the specified resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
         mgr.getStringArray($r('app.strarray.test').id).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getMedia<a name="section6710152513409"></a>

getMedia\(resId: number, callback: AsyncCallback<Uint8Array\>\): void

Obtains the content of the media file corresponding to the specified resource ID. This method uses a callback to return the result.

-   Parameters

    <a name="table13710192554016"></a>
    <table><thead align="left"><tr id="row3710152534017"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="p47108259406"><a name="p47108259406"></a><a name="p47108259406"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="p2710102564013"><a name="p2710102564013"></a><a name="p2710102564013"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="p17710525154014"><a name="p17710525154014"></a><a name="p17710525154014"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="p771022517402"><a name="p771022517402"></a><a name="p771022517402"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row871062544010"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p1871016257407"><a name="p1871016257407"></a><a name="p1871016257407"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p1371002534015"><a name="p1371002534015"></a><a name="p1371002534015"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p16711122515403"><a name="p16711122515403"></a><a name="p16711122515403"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p1271119257400"><a name="p1271119257400"></a><a name="p1271119257400"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row1971112524019"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p27111125204017"><a name="p27111125204017"></a><a name="p27111125204017"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p1371152514409"><a name="p1371152514409"></a><a name="p1371152514409"></a>AsyncCallback&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p13711625124019"><a name="p13711625124019"></a><a name="p13711625124019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p8711172511406"><a name="p8711172511406"></a><a name="p8711172511406"></a>Asynchronous callback used to return the content of the obtained media file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMedia($r('app.media.test').id, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getMedia<a name="section6711152517409"></a>

getMedia\(resId: number\): Promise<Uint8Array\>

Obtains the content of the media file corresponding to the specified resource ID. This method uses a promise to return the result.

-   Parameters

    <a name="table10711725154015"></a>
    <table><thead align="left"><tr id="row8712225154016"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p371210253407"><a name="p371210253407"></a><a name="p371210253407"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p771214253404"><a name="p771214253404"></a><a name="p771214253404"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p171242574017"><a name="p171242574017"></a><a name="p171242574017"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6712725114013"><a name="p6712725114013"></a><a name="p6712725114013"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row971232544013"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p67126252406"><a name="p67126252406"></a><a name="p67126252406"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p12712425114012"><a name="p12712425114012"></a><a name="p12712425114012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19712152511403"><a name="p19712152511403"></a><a name="p19712152511403"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8712162564019"><a name="p8712162564019"></a><a name="p8712162564019"></a>Resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table271292534018"></a>
    <table><thead align="left"><tr id="row1971352524020"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="p9713925104011"><a name="p9713925104011"></a><a name="p9713925104011"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="p471352574010"><a name="p471352574010"></a><a name="p471352574010"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9713142554012"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="p1071352554019"><a name="p1071352554019"></a><a name="p1071352554019"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="p8713192517405"><a name="p8713192517405"></a><a name="p8713192517405"></a>Promise used to return the content of the obtained media file.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMedia($r('app.media.test').id).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getMediaBase64<a name="section11402326194315"></a>

getMediaBase64\(resId: number, callback: AsyncCallback<string\>\): void

Obtains the Base64 code of the image corresponding to the specified resource ID. This method uses a callback to return the result.

-   Parameters

    <a name="table1740272614430"></a>
    <table><thead align="left"><tr id="row540272684311"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="p1340272624311"><a name="p1340272624311"></a><a name="p1340272624311"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="p8402192617438"><a name="p8402192617438"></a><a name="p8402192617438"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="p1440222674312"><a name="p1440222674312"></a><a name="p1440222674312"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="p11403926164312"><a name="p11403926164312"></a><a name="p11403926164312"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row54031726114310"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p114031326154312"><a name="p114031326154312"></a><a name="p114031326154312"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p1040382604313"><a name="p1040382604313"></a><a name="p1040382604313"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p94035265431"><a name="p94035265431"></a><a name="p94035265431"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p1140392612434"><a name="p1140392612434"></a><a name="p1140392612434"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row12403192615432"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p14031226144319"><a name="p14031226144319"></a><a name="p14031226144319"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p1740382618433"><a name="p1740382618433"></a><a name="p1740382618433"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p144032026104313"><a name="p144032026104313"></a><a name="p144032026104313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p18403142618437"><a name="p18403142618437"></a><a name="p18403142618437"></a>Asynchronous callback used to return the obtained Base64 code of the image.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMediaBase64($r('app.media.test').id, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getMediaBase64<a name="section6404726124312"></a>

getMediaBase64\(resId: number\): Promise<string\>

Obtains the Base64 code of the image corresponding to the specified resource ID. This method uses a promise to return the result.

-   Parameters

    <a name="table1840452674318"></a>
    <table><thead align="left"><tr id="row84041226184317"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p5404926154316"><a name="p5404926154316"></a><a name="p5404926154316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p194048268435"><a name="p194048268435"></a><a name="p194048268435"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p184041226104320"><a name="p184041226104320"></a><a name="p184041226104320"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p12404726184315"><a name="p12404726184315"></a><a name="p12404726184315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8404126124314"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p104051426104313"><a name="p104051426104313"></a><a name="p104051426104313"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15405172610430"><a name="p15405172610430"></a><a name="p15405172610430"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p240582616430"><a name="p240582616430"></a><a name="p240582616430"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p124051726104318"><a name="p124051726104318"></a><a name="p124051726104318"></a>Resource ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1240514269437"></a>
    <table><thead align="left"><tr id="row1240532620433"><th class="cellrowborder" valign="top" width="23.02%" id="mcps1.1.3.1.1"><p id="p1406202614313"><a name="p1406202614313"></a><a name="p1406202614313"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="76.98%" id="mcps1.1.3.1.2"><p id="p8406226124316"><a name="p8406226124316"></a><a name="p8406226124316"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row164065261435"><td class="cellrowborder" valign="top" width="23.02%" headers="mcps1.1.3.1.1 "><p id="p5406182612436"><a name="p5406182612436"></a><a name="p5406182612436"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.98%" headers="mcps1.1.3.1.2 "><p id="p3406182612434"><a name="p3406182612434"></a><a name="p3406182612434"></a>Promise used to return the obtained Base64 code of the image.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getMediaBase64($r('app.media.test').id).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getConfiguration<a name="section8123152874015"></a>

getConfiguration\(callback: AsyncCallback<Configuration\>\): void

Obtains the device configuration. This method uses a callback to return the result.

-   Parameters

    <a name="table15123112811401"></a>
    <table><thead align="left"><tr id="row13123102844013"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="p1812311285406"><a name="p1812311285406"></a><a name="p1812311285406"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="p101239284409"><a name="p101239284409"></a><a name="p101239284409"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p41236289403"><a name="p41236289403"></a><a name="p41236289403"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p201231228164019"><a name="p201231228164019"></a><a name="p201231228164019"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row141241285400"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p812452814012"><a name="p812452814012"></a><a name="p812452814012"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p1412420284405"><a name="p1412420284405"></a><a name="p1412420284405"></a>AsyncCallback&lt;<a href="#section12882825611">Configuration</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10124122817403"><a name="p10124122817403"></a><a name="p10124122817403"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p161241028184011"><a name="p161241028184011"></a><a name="p161241028184011"></a>Asynchronous callback used to return the obtained device configuration.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getConfiguration((error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getConfiguration<a name="section312515284406"></a>

getConfiguration\(\): Promise<Configuration\>

Obtains the device configuration. This method uses a promise to return the result.

-   Return values

    <a name="table12126228134013"></a>
    <table><thead align="left"><tr id="row11126728184016"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p191261028174019"><a name="p191261028174019"></a><a name="p191261028174019"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p6126202894018"><a name="p6126202894018"></a><a name="p6126202894018"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8126728174017"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p112718283409"><a name="p112718283409"></a><a name="p112718283409"></a>Promise&lt;<a href="#section12882825611">Configuration</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1412792864011"><a name="p1412792864011"></a><a name="p1412792864011"></a>Promise used to return the device configuration.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getConfiguration().then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getDeviceCapability<a name="section104951210135017"></a>

getDeviceCapability\(callback: AsyncCallback<DeviceCapability\>\): void

Obtains the device capability. This method uses a callback to return the result.

-   Parameters

    <a name="table1495410115014"></a>
    <table><thead align="left"><tr id="row649514108507"><th class="cellrowborder" valign="top" width="8.7%" id="mcps1.1.5.1.1"><p id="p54957102501"><a name="p54957102501"></a><a name="p54957102501"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.69%" id="mcps1.1.5.1.2"><p id="p649531011504"><a name="p649531011504"></a><a name="p649531011504"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.319999999999999%" id="mcps1.1.5.1.3"><p id="p74954109501"><a name="p74954109501"></a><a name="p74954109501"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p174951910155019"><a name="p174951910155019"></a><a name="p174951910155019"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11495710115015"><td class="cellrowborder" valign="top" width="8.7%" headers="mcps1.1.5.1.1 "><p id="p154951510185014"><a name="p154951510185014"></a><a name="p154951510185014"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.69%" headers="mcps1.1.5.1.2 "><p id="p174955105509"><a name="p174955105509"></a><a name="p174955105509"></a>AsyncCallback&lt;<a href="#section7200123494410">DeviceCapability</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.319999999999999%" headers="mcps1.1.5.1.3 "><p id="p1495121012501"><a name="p1495121012501"></a><a name="p1495121012501"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p54969103507"><a name="p54969103507"></a><a name="p54969103507"></a>Asynchronous callback used to return the obtained device capability.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getDeviceCapability((error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getDeviceCapability<a name="section114961410115013"></a>

getDeviceCapability\(\): Promise<DeviceCapability\>

Obtains the device capability. This method uses a promise to return the result.

-   Return values

    <a name="table17496111015019"></a>
    <table><thead align="left"><tr id="row12496111095010"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1496101015503"><a name="p1496101015503"></a><a name="p1496101015503"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1496110155013"><a name="p1496110155013"></a><a name="p1496110155013"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10496181065014"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p19497151095012"><a name="p19497151095012"></a><a name="p19497151095012"></a>Promise&lt;<a href="#section7200123494410">DeviceCapability</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p18497141011504"><a name="p18497141011504"></a><a name="p18497141011504"></a>Promise used to return the obtained device capability.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getDeviceCapability().then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getPluralString<a name="section1549163064013"></a>

getPluralString\(resId: number, num: number, callback: AsyncCallback<string\>\): void

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This method uses a callback to return the result.

-   Parameters

    <a name="table649330164020"></a>
    <table><thead align="left"><tr id="row6491302400"><th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.1"><p id="p1749123034017"><a name="p1749123034017"></a><a name="p1749123034017"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.5.1.2"><p id="p449143064012"><a name="p449143064012"></a><a name="p449143064012"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1349123044017"><a name="p1349123044017"></a><a name="p1349123044017"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p11491302408"><a name="p11491302408"></a><a name="p11491302408"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row145013054010"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p65073012401"><a name="p65073012401"></a><a name="p65073012401"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p11502030124016"><a name="p11502030124016"></a><a name="p11502030124016"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1650330174019"><a name="p1650330174019"></a><a name="p1650330174019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1650163034013"><a name="p1650163034013"></a><a name="p1650163034013"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row18497201611531"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p1949711615318"><a name="p1949711615318"></a><a name="p1949711615318"></a>num</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p13497191615532"><a name="p13497191615532"></a><a name="p13497191615532"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p9497716125311"><a name="p9497716125311"></a><a name="p9497716125311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p249771619536"><a name="p249771619536"></a><a name="p249771619536"></a>Number that determines the plural or singular form.</p>
    </td>
    </tr>
    <tr id="row45053011403"><td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.1 "><p id="p1650230204016"><a name="p1650230204016"></a><a name="p1650230204016"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.5.1.2 "><p id="p165010302401"><a name="p165010302401"></a><a name="p165010302401"></a>AsyncCallback&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7501530164018"><a name="p7501530164018"></a><a name="p7501530164018"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17501330104012"><a name="p17501330104012"></a><a name="p17501330104012"></a>Asynchronous callback used to return the obtained singular-plural string.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getPluralString($r("app.plural.test").id, 1, (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getPluralString<a name="section165183015405"></a>

getPluralString\(resId: number, num: number\): Promise<string\>

Obtains the specified number of singular-plural strings corresponding to the specified resource ID. This method uses a promise to return the result.

-   Parameters

    <a name="table105173016408"></a>
    <table><thead align="left"><tr id="row195223064018"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1752183064013"><a name="p1752183064013"></a><a name="p1752183064013"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p175273064016"><a name="p175273064016"></a><a name="p175273064016"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1452430124014"><a name="p1452430124014"></a><a name="p1452430124014"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9525305406"><a name="p9525305406"></a><a name="p9525305406"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row65233019409"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p125213301405"><a name="p125213301405"></a><a name="p125213301405"></a>resId</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p55293019409"><a name="p55293019409"></a><a name="p55293019409"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p553103094019"><a name="p553103094019"></a><a name="p553103094019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1453430124015"><a name="p1453430124015"></a><a name="p1453430124015"></a>Resource ID.</p>
    </td>
    </tr>
    <tr id="row05323013406"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p197652617548"><a name="p197652617548"></a><a name="p197652617548"></a>num</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p187651685411"><a name="p187651685411"></a><a name="p187651685411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p776517611543"><a name="p776517611543"></a><a name="p776517611543"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2076646145413"><a name="p2076646145413"></a><a name="p2076646145413"></a>Number that determines the plural or singular form.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table45313011403"></a>
    <table><thead align="left"><tr id="row554133016401"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p13549300401"><a name="p13549300401"></a><a name="p13549300401"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p75419307408"><a name="p75419307408"></a><a name="p75419307408"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1554143094015"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p115483064019"><a name="p115483064019"></a><a name="p115483064019"></a>Promise&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1965948111118"><a name="p1965948111118"></a><a name="p1965948111118"></a>Promise used to return the obtained singular-plural string.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getPluralString($r("app.plural.test").id, 1).then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getstring promise " + error);
        });
    });
    ```


### getRawFile<sup>8+</sup><a name="section95073471466"></a>

getRawFile\(path: string, callback: AsyncCallback<Uint8Array\>\): void

Obtains the content of rawfile in the specified path. This method uses an asynchronous callback to return the result.

-   Parameters

    <a name="table15072471264"></a>
    <table><thead align="left"><tr id="row1550784715616"><th class="cellrowborder" valign="top" width="7.901402961808262%" id="mcps1.1.5.1.1"><p id="p1650720473611"><a name="p1650720473611"></a><a name="p1650720473611"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.565081839438818%" id="mcps1.1.5.1.2"><p id="p1850710478614"><a name="p1850710478614"></a><a name="p1850710478614"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819953234606392%" id="mcps1.1.5.1.3"><p id="p7508247962"><a name="p7508247962"></a><a name="p7508247962"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.713561964146535%" id="mcps1.1.5.1.4"><p id="p1250816471565"><a name="p1250816471565"></a><a name="p1250816471565"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row205084473617"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p12508144716615"><a name="p12508144716615"></a><a name="p12508144716615"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p45085471768"><a name="p45085471768"></a><a name="p45085471768"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p1150834716613"><a name="p1150834716613"></a><a name="p1150834716613"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p950814719617"><a name="p950814719617"></a><a name="p950814719617"></a>Path of the rawfile.</p>
    </td>
    </tr>
    <tr id="row145082471163"><td class="cellrowborder" valign="top" width="7.901402961808262%" headers="mcps1.1.5.1.1 "><p id="p145081347867"><a name="p145081347867"></a><a name="p145081347867"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.565081839438818%" headers="mcps1.1.5.1.2 "><p id="p550814471615"><a name="p550814471615"></a><a name="p550814471615"></a>AsyncCallback&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819953234606392%" headers="mcps1.1.5.1.3 "><p id="p1450884713612"><a name="p1450884713612"></a><a name="p1450884713612"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.713561964146535%" headers="mcps1.1.5.1.4 "><p id="p150864719611"><a name="p150864719611"></a><a name="p150864719611"></a> Asynchronous callback used to return the rawfile content, in byte arrays.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getRawFile("test.xml", (error, value) => {
            if (error != null) {
                console.log(value);
            } else {
                console.log(value);
            }
        });
    });
    ```


### getRawFile<sup>8+</sup><a name="section53115315102"></a>

getRawFile\(path: string\): Promise<Uint8Array\>

Obtains the content of the rawfile in the specified path. This method uses a promise to return the result.

-   Parameters

    <a name="table73111831141015"></a>
    <table><thead align="left"><tr id="row1311143131013"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1631163171011"><a name="p1631163171011"></a><a name="p1631163171011"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p431193191013"><a name="p431193191013"></a><a name="p431193191013"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p131114317106"><a name="p131114317106"></a><a name="p131114317106"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1531211312104"><a name="p1531211312104"></a><a name="p1531211312104"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1331263131011"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1531223111011"><a name="p1531223111011"></a><a name="p1531223111011"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p173121931151016"><a name="p173121931151016"></a><a name="p173121931151016"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12312173118102"><a name="p12312173118102"></a><a name="p12312173118102"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13312163141013"><a name="p13312163141013"></a><a name="p13312163141013"></a>Path of the rawfile.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table6312113112103"></a>
    <table><thead align="left"><tr id="row12312231101015"><th class="cellrowborder" valign="top" width="34.339999999999996%" id="mcps1.1.3.1.1"><p id="p19312173112109"><a name="p19312173112109"></a><a name="p19312173112109"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.66%" id="mcps1.1.3.1.2"><p id="p1431223161016"><a name="p1431223161016"></a><a name="p1431223161016"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12312431151011"><td class="cellrowborder" valign="top" width="34.339999999999996%" headers="mcps1.1.3.1.1 "><p id="p14312113119102"><a name="p14312113119102"></a><a name="p14312113119102"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.66%" headers="mcps1.1.3.1.2 "><p id="p43128317109"><a name="p43128317109"></a><a name="p43128317109"></a> Promise used to return the rawfile content, in byte arrays.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resourceManager.getResourceManager((error, mgr) => {
        mgr.getRawFile("test.xml").then(value => {
            console.log(value);
        }).catch(error => {
            console.log("getrawfile promise " + error);
        });
    });
    ```

