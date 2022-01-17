# Display<a name="EN-US_TOPIC_0000001163727614"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import display from '@ohos.display';
```

## Required Permissions<a name="section11257113618419"></a>

None

## DisplayState<a name="section099619567453"></a>

Provides the state of a display.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p52851329122117"><a name="p52851329122117"></a><a name="p52851329122117"></a>STATE_UNKNOWN</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>Unknown.</p>
</td>
</tr>
<tr id="row9573466526"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1657317665219"><a name="p1657317665219"></a><a name="p1657317665219"></a>STATE_OFF</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p457396175219"><a name="p457396175219"></a><a name="p457396175219"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p195734655215"><a name="p195734655215"></a><a name="p195734655215"></a>The display is shut down.</p>
</td>
</tr>
<tr id="row594210615212"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1194218685216"><a name="p1194218685216"></a><a name="p1194218685216"></a>STATE_ON</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p99429655216"><a name="p99429655216"></a><a name="p99429655216"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p994212610529"><a name="p994212610529"></a><a name="p994212610529"></a>The display is powered on.</p>
</td>
</tr>
<tr id="row1126914795219"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p526907135217"><a name="p526907135217"></a><a name="p526907135217"></a>STATE_DOZE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p172697710521"><a name="p172697710521"></a><a name="p172697710521"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p2269207135212"><a name="p2269207135212"></a><a name="p2269207135212"></a>The display is in sleep mode.</p>
</td>
</tr>
<tr id="row9269113311527"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p13269133315527"><a name="p13269133315527"></a><a name="p13269133315527"></a>STATE_DOZE_SUSPEND</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p3269133315527"><a name="p3269133315527"></a><a name="p3269133315527"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p18269153355217"><a name="p18269153355217"></a><a name="p18269153355217"></a>The display is in sleep mode, and the CPU is suspended.</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p12106173918219"><a name="p12106173918219"></a><a name="p12106173918219"></a>STATE_VR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15865395215"><a name="p15865395215"></a><a name="p15865395215"></a>The display is in VR mode.</p>
</td>
</tr>
<tr id="row119663437528"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p119671435520"><a name="p119671435520"></a><a name="p119671435520"></a>STATE_ON_SUSPEND</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p0967144325219"><a name="p0967144325219"></a><a name="p0967144325219"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p396720433521"><a name="p396720433521"></a><a name="p396720433521"></a>The display is powered on, and the CPU is suspended.</p>
</td>
</tr>
</tbody>
</table>

## Display<a name="section12882825611"></a>

Describes the attributes of a display.

### Attributes<a name="section1059684317312"></a>

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="17.73%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.6%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.549999999999999%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="37.78%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row95971943839"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p85976431431"><a name="p85976431431"></a><a name="p85976431431"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p2059710431030"><a name="p2059710431030"></a><a name="p2059710431030"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1059711439317"><a name="p1059711439317"></a><a name="p1059711439317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p659715430317"><a name="p659715430317"></a><a name="p659715430317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p2059719436313"><a name="p2059719436313"></a><a name="p2059719436313"></a>ID of the display.</p>
</td>
</tr>
<tr id="row457515412419"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p185751494115"><a name="p185751494115"></a><a name="p185751494115"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p1575174134114"><a name="p1575174134114"></a><a name="p1575174134114"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p85757417416"><a name="p85757417416"></a><a name="p85757417416"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p115751144412"><a name="p115751144412"></a><a name="p115751144412"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p165751447416"><a name="p165751447416"></a><a name="p165751447416"></a>Name of the display.</p>
</td>
</tr>
<tr id="row179143454114"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p19144416411"><a name="p19144416411"></a><a name="p19144416411"></a>alive</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p7914541418"><a name="p7914541418"></a><a name="p7914541418"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1991420434110"><a name="p1991420434110"></a><a name="p1991420434110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p791411411418"><a name="p791411411418"></a><a name="p791411411418"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p99144412415"><a name="p99144412415"></a><a name="p99144412415"></a>Whether the display is alive.</p>
</td>
</tr>
<tr id="row102142520415"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p52142514414"><a name="p52142514414"></a><a name="p52142514414"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p142142564116"><a name="p142142564116"></a><a name="p142142564116"></a><a href="#section099619567453">DisplayState</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p7215195164110"><a name="p7215195164110"></a><a name="p7215195164110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p821510515418"><a name="p821510515418"></a><a name="p821510515418"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p102153564110"><a name="p102153564110"></a><a name="p102153564110"></a>State of the display.</p>
</td>
</tr>
<tr id="row5472125204114"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p184722514117"><a name="p184722514117"></a><a name="p184722514117"></a>refreshRate</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p1547215544112"><a name="p1547215544112"></a><a name="p1547215544112"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p74726515410"><a name="p74726515410"></a><a name="p74726515410"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p1947355194112"><a name="p1947355194112"></a><a name="p1947355194112"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p647315520412"><a name="p647315520412"></a><a name="p647315520412"></a>Refresh rate of the display.</p>
</td>
</tr>
<tr id="row1968020524118"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p1968005184118"><a name="p1968005184118"></a><a name="p1968005184118"></a>rotation</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p116804584113"><a name="p116804584113"></a><a name="p116804584113"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p668013504119"><a name="p668013504119"></a><a name="p668013504119"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p10680156412"><a name="p10680156412"></a><a name="p10680156412"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p16808514113"><a name="p16808514113"></a><a name="p16808514113"></a>Screen rotation angle of the display.</p>
</td>
</tr>
<tr id="row164425664116"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p1744216134115"><a name="p1744216134115"></a><a name="p1744216134115"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p0442126194115"><a name="p0442126194115"></a><a name="p0442126194115"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1444212614110"><a name="p1444212614110"></a><a name="p1444212614110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p2044286124115"><a name="p2044286124115"></a><a name="p2044286124115"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p1544266184119"><a name="p1544266184119"></a><a name="p1544266184119"></a>Width of the display, in pixels.</p>
</td>
</tr>
<tr id="row1764911684115"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p164916610417"><a name="p164916610417"></a><a name="p164916610417"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p164906174116"><a name="p164906174116"></a><a name="p164906174116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p136492624113"><a name="p136492624113"></a><a name="p136492624113"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p12649660417"><a name="p12649660417"></a><a name="p12649660417"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p126490694117"><a name="p126490694117"></a><a name="p126490694117"></a>Height of the display, in pixels.</p>
</td>
</tr>
<tr id="row0814166164118"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p1081413694118"><a name="p1081413694118"></a><a name="p1081413694118"></a>densityDPI</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p88142654116"><a name="p88142654116"></a><a name="p88142654116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1081415654114"><a name="p1081415654114"></a><a name="p1081415654114"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p481466164119"><a name="p481466164119"></a><a name="p481466164119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p29318812312"><a name="p29318812312"></a><a name="p29318812312"></a>Screen density of the display, in DPI.</p>
</td>
</tr>
<tr id="row1022157124119"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p422576414"><a name="p422576414"></a><a name="p422576414"></a>densityPixels</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p72220724116"><a name="p72220724116"></a><a name="p72220724116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1822677418"><a name="p1822677418"></a><a name="p1822677418"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p13221371412"><a name="p13221371412"></a><a name="p13221371412"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p422127164110"><a name="p422127164110"></a><a name="p422127164110"></a>Screen density of the display, in pixels.</p>
</td>
</tr>
<tr id="row420113911425"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p220117954217"><a name="p220117954217"></a><a name="p220117954217"></a>scaledDensity</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p15201994420"><a name="p15201994420"></a><a name="p15201994420"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p162025915423"><a name="p162025915423"></a><a name="p162025915423"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p182027916423"><a name="p182027916423"></a><a name="p182027916423"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p132021793429"><a name="p132021793429"></a><a name="p132021793429"></a>Scaling factor for fonts displayed on the display.</p>
</td>
</tr>
<tr id="row185973435316"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p1559710432310"><a name="p1559710432310"></a><a name="p1559710432310"></a>xDPI</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p16597144318312"><a name="p16597144318312"></a><a name="p16597144318312"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p12597194313317"><a name="p12597194313317"></a><a name="p12597194313317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p1259710431236"><a name="p1259710431236"></a><a name="p1259710431236"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p10597843034"><a name="p10597843034"></a><a name="p10597843034"></a>Exact physical dots per inch of the screen in the horizontal direction.</p>
</td>
</tr>
<tr id="row138296171429"><td class="cellrowborder" valign="top" width="17.73%" headers="mcps1.1.6.1.1 "><p id="p183016179421"><a name="p183016179421"></a><a name="p183016179421"></a>yDPI</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.6.1.2 "><p id="p15830101715429"><a name="p15830101715429"></a><a name="p15830101715429"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p198301917164219"><a name="p198301917164219"></a><a name="p198301917164219"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.4 "><p id="p18301174421"><a name="p18301174421"></a><a name="p18301174421"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.78%" headers="mcps1.1.6.1.5 "><p id="p2083001718427"><a name="p2083001718427"></a><a name="p2083001718427"></a>Exact physical dots per inch of the screen in the vertical direction.</p>
</td>
</tr>
</tbody>
</table>

## display.getDefaultDisplay<a name="section39061940191"></a>

getDefaultDisplay\(callback: AsyncCallback<Display\>\): void;

Obtains the default display object.

-   Parameters

    <a name="table1889910298214"></a>
    <table><thead align="left"><tr id="row38991829162119"><th class="cellrowborder" valign="top" width="14.95%" id="mcps1.1.5.1.1"><p id="p17899192918217"><a name="p17899192918217"></a><a name="p17899192918217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.839999999999996%" id="mcps1.1.5.1.2"><p id="p1389972922116"><a name="p1389972922116"></a><a name="p1389972922116"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.829999999999999%" id="mcps1.1.5.1.3"><p id="p089952919215"><a name="p089952919215"></a><a name="p089952919215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.38%" id="mcps1.1.5.1.4"><p id="p178998291215"><a name="p178998291215"></a><a name="p178998291215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18900102982117"><td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.5.1.1 "><p id="p1590019292215"><a name="p1590019292215"></a><a name="p1590019292215"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.839999999999996%" headers="mcps1.1.5.1.2 "><p id="p1290017293214"><a name="p1290017293214"></a><a name="p1290017293214"></a>AsyncCallback&lt;<a href="#section12882825611">Display</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.829999999999999%" headers="mcps1.1.5.1.3 "><p id="p990042932115"><a name="p990042932115"></a><a name="p990042932115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.38%" headers="mcps1.1.5.1.4 "><p id="p1790072917218"><a name="p1790072917218"></a><a name="p1790072917218"></a>Callback used to return the attributes of the default display.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var displayClass = null;
    display.getDefaultDisplay((err, data) => {
        if (err) {
            console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
        displayClass = data;
    });
    ```


## display.getAllDisplay<a name="section129251146697"></a>

getAllDisplay\(callback: AsyncCallback<Array<Display\>\>\): void;

Obtains all the display objects.

-   Parameters

    <a name="table1098161318234"></a>
    <table><thead align="left"><tr id="row18981913132317"><th class="cellrowborder" valign="top" width="14.95%" id="mcps1.1.5.1.1"><p id="p898201322314"><a name="p898201322314"></a><a name="p898201322314"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.949999999999996%" id="mcps1.1.5.1.2"><p id="p8981013162319"><a name="p8981013162319"></a><a name="p8981013162319"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.5.1.3"><p id="p298161362320"><a name="p298161362320"></a><a name="p298161362320"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.18%" id="mcps1.1.5.1.4"><p id="p398101318235"><a name="p398101318235"></a><a name="p398101318235"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1798413152317"><td class="cellrowborder" valign="top" width="14.95%" headers="mcps1.1.5.1.1 "><p id="p1798161319239"><a name="p1798161319239"></a><a name="p1798161319239"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.5.1.2 "><p id="p7981213122317"><a name="p7981213122317"></a><a name="p7981213122317"></a>AsyncCallback&lt;Array&lt;<a href="#section12882825611">Display</a>&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="p189861392314"><a name="p189861392314"></a><a name="p189861392314"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.18%" headers="mcps1.1.5.1.4 "><p id="p29812131235"><a name="p29812131235"></a><a name="p29812131235"></a>Callback used to return the attributes of all displays.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    display.getAllDisplay((err, data) => {
        if (err) {
            console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data))
    });
    ```


## display.on\('add'|'remove'|'change'\)<a name="section5851341125"></a>

on\(type: 'add'|'remove'|'change', callback: Callback<number\>\): void;

Enables listening.

-   Parameters

    <a name="table1185133418121"></a>
    <table><thead align="left"><tr id="row10857341125"><th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.1"><p id="p88503412128"><a name="p88503412128"></a><a name="p88503412128"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.130000000000003%" id="mcps1.1.5.1.2"><p id="p98513411125"><a name="p98513411125"></a><a name="p98513411125"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.91%" id="mcps1.1.5.1.3"><p id="p585163481213"><a name="p585163481213"></a><a name="p585163481213"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.99%" id="mcps1.1.5.1.4"><p id="p086183411124"><a name="p086183411124"></a><a name="p086183411124"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row286153419127"><td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.1 "><p id="p108693415126"><a name="p108693415126"></a><a name="p108693415126"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.130000000000003%" headers="mcps1.1.5.1.2 "><p id="p18867344125"><a name="p18867344125"></a><a name="p18867344125"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.91%" headers="mcps1.1.5.1.3 "><p id="p7863341127"><a name="p7863341127"></a><a name="p7863341127"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.99%" headers="mcps1.1.5.1.4 "><p id="p12576162873620"><a name="p12576162873620"></a><a name="p12576162873620"></a>Listening type.</p>
    <a name="ul5610203018367"></a><a name="ul5610203018367"></a><ul id="ul5610203018367"><li><strong id="b1574838195610"><a name="b1574838195610"></a><a name="b1574838195610"></a>add</strong>: listening for whether a display is added</li><li><strong id="b51261741175616"><a name="b51261741175616"></a><a name="b51261741175616"></a>remove</strong>: listening for whether a display is removed</li><li><strong id="b18418142145615"><a name="b18418142145615"></a><a name="b18418142145615"></a>change</strong>: listening for whether a display is changed</li></ul>
    </td>
    </tr>
    <tr id="row926414772311"><td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.1 "><p id="p8654354112313"><a name="p8654354112313"></a><a name="p8654354112313"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.130000000000003%" headers="mcps1.1.5.1.2 "><p id="p2654854112310"><a name="p2654854112310"></a><a name="p2654854112310"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.91%" headers="mcps1.1.5.1.3 "><p id="p15654185417236"><a name="p15654185417236"></a><a name="p15654185417236"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.99%" headers="mcps1.1.5.1.4 "><p id="p965485411233"><a name="p965485411233"></a><a name="p965485411233"></a>Callback used to return the ID of the display.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var type = "add";
    var callback = (data) => {
        console.info('Listening enabled. Data: ' + JSON.stringify(data))
    }
    display.on(type, callback);
    ```


## display.off\('add'|'remove'|'change'\)<a name="section13178205443512"></a>

off\(type: 'add'|'remove'|'change', callback?: Callback<number\>\): void;

Disables listening.

-   Parameters

    <a name="table1717865483515"></a>
    <table><thead align="left"><tr id="row91789548359"><th class="cellrowborder" valign="top" width="12.479999999999999%" id="mcps1.1.5.1.1"><p id="p19178185413352"><a name="p19178185413352"></a><a name="p19178185413352"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.32%" id="mcps1.1.5.1.2"><p id="p41780541354"><a name="p41780541354"></a><a name="p41780541354"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.3%" id="mcps1.1.5.1.3"><p id="p917895443512"><a name="p917895443512"></a><a name="p917895443512"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.9%" id="mcps1.1.5.1.4"><p id="p17178205410352"><a name="p17178205410352"></a><a name="p17178205410352"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row151787544353"><td class="cellrowborder" valign="top" width="12.479999999999999%" headers="mcps1.1.5.1.1 "><p id="p1217819543355"><a name="p1217819543355"></a><a name="p1217819543355"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.32%" headers="mcps1.1.5.1.2 "><p id="p417915453516"><a name="p417915453516"></a><a name="p417915453516"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.3%" headers="mcps1.1.5.1.3 "><p id="p81791954203516"><a name="p81791954203516"></a><a name="p81791954203516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.9%" headers="mcps1.1.5.1.4 "><p id="p11366379368"><a name="p11366379368"></a><a name="p11366379368"></a>Listening type.</p>
    <a name="ul20308203893611"></a><a name="ul20308203893611"></a><ul id="ul20308203893611"><li><strong id="b78701755195618"><a name="b78701755195618"></a><a name="b78701755195618"></a>add</strong>: listening for whether a display is added</li><li><strong id="b10430956195611"><a name="b10430956195611"></a><a name="b10430956195611"></a>remove</strong>: listening for whether a display is removed</li><li><strong id="b113699578561"><a name="b113699578561"></a><a name="b113699578561"></a>change</strong>: listening for whether a display is changed</li></ul>
    </td>
    </tr>
    <tr id="row152711425132514"><td class="cellrowborder" valign="top" width="12.479999999999999%" headers="mcps1.1.5.1.1 "><p id="p0986172612510"><a name="p0986172612510"></a><a name="p0986172612510"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.32%" headers="mcps1.1.5.1.2 "><p id="p9987102617255"><a name="p9987102617255"></a><a name="p9987102617255"></a>Callback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.3%" headers="mcps1.1.5.1.3 "><p id="p1798742617259"><a name="p1798742617259"></a><a name="p1798742617259"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.9%" headers="mcps1.1.5.1.4 "><p id="p1698722611251"><a name="p1698722611251"></a><a name="p1698722611251"></a>Callback used to return the ID of the display.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var type = "remove";
    display.off(type);
    ```


