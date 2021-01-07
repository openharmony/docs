# Reference<a name="EN-US_TOPIC_0000001063223654"></a>

-   [Directory Structure](#section5487173174316)

## Directory Structure<a name="section5487173174316"></a>

**Table  1**  Directory structure of the source code for DFX

<a name="table66755210373"></a>
<table><thead align="left"><tr id="row56777233718"><th class="cellrowborder" valign="top" width="36.09%" id="mcps1.2.3.1.1"><p id="p1367713214377"><a name="p1367713214377"></a><a name="p1367713214377"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="63.91%" id="mcps1.2.3.1.2"><p id="p36771228375"><a name="p36771228375"></a><a name="p36771228375"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row66782283710"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p1167811273717"><a name="p1167811273717"></a><a name="p1167811273717"></a>hiviewdfx/interface</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p1467912223712"><a name="p1467912223712"></a><a name="p1467912223712"></a>Stores all header files for open APIs.</p>
</td>
</tr>
<tr id="row1167910233715"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p106801023374"><a name="p106801023374"></a><a name="p106801023374"></a>hiviewdfx/interfaces/kits/hilog</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p668013223716"><a name="p668013223716"></a><a name="p668013223716"></a>Defines open APIs available for logs in the featured framework.</p>
</td>
</tr>
<tr id="row166801626377"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p9681162123713"><a name="p9681162123713"></a><a name="p9681162123713"></a>hiviewdfx/interfaces/kits/hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p16814213713"><a name="p16814213713"></a><a name="p16814213713"></a>Defines open APIs available for logs in the mini framework.</p>
</td>
</tr>
<tr id="row1568116218371"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p868115223710"><a name="p868115223710"></a><a name="p868115223710"></a>hiviewdfx/interfaces/innerkits/hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p66823263717"><a name="p66823263717"></a><a name="p66823263717"></a>Defines open APIs available for event printing in the mini framework.</p>
</td>
</tr>
<tr id="row11682112203711"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p96825213719"><a name="p96825213719"></a><a name="p96825213719"></a>hiviewdfx/services/hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p36821528373"><a name="p36821528373"></a><a name="p36821528373"></a>Stores services and commands related to logs.</p>
</td>
</tr>
<tr id="row1768314213719"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p156830213710"><a name="p156830213710"></a><a name="p156830213710"></a>hiviewdfx/services/hilogcat_lite/apphilogcat</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p176847283719"><a name="p176847283719"></a><a name="p176847283719"></a>Provides the log flushing-to-disk service in the featured framework.</p>
</td>
</tr>
<tr id="row16841212371"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p2068419220378"><a name="p2068419220378"></a><a name="p2068419220378"></a>hiviewdfx/services/hilogcat_lite/command</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p7684627377"><a name="p7684627377"></a><a name="p7684627377"></a>Provides DFX commands specific to the mini framework.</p>
</td>
</tr>
<tr id="row1068414210373"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p18685127370"><a name="p18685127370"></a><a name="p18685127370"></a>hiviewdfx/services/hilogcat_lite/hilogcat</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p1868515233717"><a name="p1868515233717"></a><a name="p1868515233717"></a>Provides commands to output logs in the featured framework.</p>
</td>
</tr>
<tr id="row568610243714"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p6686720376"><a name="p6686720376"></a><a name="p6686720376"></a>hiviewdfx/services/hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p196875293712"><a name="p196875293712"></a><a name="p196875293712"></a>Registers the DFX service specific to the mini framework.</p>
</td>
</tr>
<tr id="row56871215376"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p468710214371"><a name="p468710214371"></a><a name="p468710214371"></a>hiviewdfx/frameworks/ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p2687152153717"><a name="p2687152153717"></a><a name="p2687152153717"></a>Dumps Double Data Rate (DDR) memory in the mini framework.</p>
</td>
</tr>
<tr id="row669011223710"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p15690029377"><a name="p15690029377"></a><a name="p15690029377"></a>hiviewdfx/frameworks/hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p56911927374"><a name="p56911927374"></a><a name="p56911927374"></a>Records event printing in the mini framework.</p>
</td>
</tr>
<tr id="row196911922371"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p1969222203712"><a name="p1969222203712"></a><a name="p1969222203712"></a>hiviewdfx/frameworks/hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p1669213210373"><a name="p1669213210373"></a><a name="p1669213210373"></a>Defines APIs for logging.</p>
</td>
</tr>
<tr id="row166921927372"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p76931217377"><a name="p76931217377"></a><a name="p76931217377"></a>hiviewdfx/frameworks/hilog_lite/featured</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p1069311212377"><a name="p1069311212377"></a><a name="p1069311212377"></a>Defines APIs for logging in the featured framework.</p>
</td>
</tr>
<tr id="row1669315213379"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p7693152143719"><a name="p7693152143719"></a><a name="p7693152143719"></a>hiviewdfx/frameworks/hilog_lite/mini</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p116931223711"><a name="p116931223711"></a><a name="p116931223711"></a>Defines APIs for logging in the mini framework.</p>
</td>
</tr>
<tr id="row769413216372"><td class="cellrowborder" valign="top" width="36.09%" headers="mcps1.2.3.1.1 "><p id="p769542113710"><a name="p769542113710"></a><a name="p769542113710"></a>hiviewdfx/utils/lite</p>
</td>
<td class="cellrowborder" valign="top" width="63.91%" headers="mcps1.2.3.1.2 "><p id="p16951524379"><a name="p16951524379"></a><a name="p16951524379"></a>Stores utils, including the configuration items of the mini framework.</p>
</td>
</tr>
</tbody>
</table>

