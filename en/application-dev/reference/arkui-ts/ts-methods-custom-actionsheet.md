# List Selection Dialog Box<a name="EN-US_TOPIC_0000001192755136"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

List pop-up window.

## Required Permissions<a name="section137491348987"></a>

None

## ActionSheet.show<a name="section91411857161619"></a>

show\(options: \{  [paramObject1](#table816913216616)\}\)

Defines and shows the list popup window.

-   paramObject1 parameters

    <a name="table816913216616"></a>
    <table><thead align="left"><tr id="row016972667"><th class="cellrowborder" valign="top" width="12.31%" id="mcps1.1.6.1.1"><p id="p101691221267"><a name="p101691221267"></a><a name="p101691221267"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.61%" id="mcps1.1.6.1.2"><p id="p616916211613"><a name="p616916211613"></a><a name="p616916211613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.3"><p id="p21691725613"><a name="p21691725613"></a><a name="p21691725613"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.54%" id="mcps1.1.6.1.4"><p id="p4169221969"><a name="p4169221969"></a><a name="p4169221969"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.389999999999997%" id="mcps1.1.6.1.5"><p id="p616922465"><a name="p616922465"></a><a name="p616922465"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row617013216610"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p11170822063"><a name="p11170822063"></a><a name="p11170822063"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p1483117481135"><a name="p1483117481135"></a><a name="p1483117481135"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p19393124211313"><a name="p19393124211313"></a><a name="p19393124211313"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p51702216617"><a name="p51702216617"></a><a name="p51702216617"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p479412426512"><a name="p479412426512"></a><a name="p479412426512"></a>Title of the dialog box.</p>
    </td>
    </tr>
    <tr id="row4170723612"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p171709214610"><a name="p171709214610"></a><a name="p171709214610"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p1517018210613"><a name="p1517018210613"></a><a name="p1517018210613"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p141701022068"><a name="p141701022068"></a><a name="p141701022068"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p20170429614"><a name="p20170429614"></a><a name="p20170429614"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p17931042651"><a name="p17931042651"></a><a name="p17931042651"></a>Content of the dialog box.</p>
    </td>
    </tr>
    <tr id="row7170625613"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p11170627619"><a name="p11170627619"></a><a name="p11170627619"></a>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p71701121661"><a name="p71701121661"></a><a name="p71701121661"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p8170192564"><a name="p8170192564"></a><a name="p8170192564"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p3714415149"><a name="p3714415149"></a><a name="p3714415149"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p2792194217516"><a name="p2792194217516"></a><a name="p2792194217516"></a>Whether to close the dialog box when the overlay is clicked.</p>
    </td>
    </tr>
    <tr id="row4619154917209"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p15281132516419"><a name="p15281132516419"></a><a name="p15281132516419"></a>confirm</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p46868785117"><a name="p46868785117"></a><a name="p46868785117"></a>{</p>
    <p id="p568627135117"><a name="p568627135117"></a><a name="p568627135117"></a>value: string,</p>
    <p id="p1767616508415"><a name="p1767616508415"></a><a name="p1767616508415"></a>action: () =&gt; void</p>
    <p id="p36866718517"><a name="p36866718517"></a><a name="p36866718517"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p1161910499207"><a name="p1161910499207"></a><a name="p1161910499207"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p65590225511"><a name="p65590225511"></a><a name="p65590225511"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p1479224217510"><a name="p1479224217510"></a><a name="p1479224217510"></a>Text content of the confirm button and callback upon button clicking.</p>
    <p id="p1167213156577"><a name="p1167213156577"></a><a name="p1167213156577"></a><strong id="b14905141312349"><a name="b14905141312349"></a><a name="b14905141312349"></a>value</strong>: button text.</p>
    <p id="p9727125155715"><a name="p9727125155715"></a><a name="p9727125155715"></a><strong id="b11601850183717"><a name="b11601850183717"></a><a name="b11601850183717"></a>action</strong>: callback upon button clicking.</p>
    </td>
    </tr>
    <tr id="row1212812822210"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p11128181222"><a name="p11128181222"></a><a name="p11128181222"></a>cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p38813406419"><a name="p38813406419"></a><a name="p38813406419"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p312819882214"><a name="p312819882214"></a><a name="p312819882214"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p1128158112211"><a name="p1128158112211"></a><a name="p1128158112211"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p678919421452"><a name="p678919421452"></a><a name="p678919421452"></a>Callback invoked when the dialog box is closed after the overlay is clicked.</p>
    </td>
    </tr>
    <tr id="row1842942319416"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p11429192314412"><a name="p11429192314412"></a><a name="p11429192314412"></a>alignment</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p1542910231744"><a name="p1542910231744"></a><a name="p1542910231744"></a><a href="ts-methods-custom-dialog-box.md#li46304184186">DialogAlignment</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p842914239415"><a name="p842914239415"></a><a name="p842914239415"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p842916234416"><a name="p842916234416"></a><a name="p842916234416"></a>DialogAlignment.Default</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p1342922318415"><a name="p1342922318415"></a><a name="p1342922318415"></a>Alignment mode of the dialog box in the vertical direction.</p>
    </td>
    </tr>
    <tr id="row164541242866"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p745414424612"><a name="p745414424612"></a><a name="p745414424612"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p334103919529"><a name="p334103919529"></a><a name="p334103919529"></a>{</p>
    <p id="p1491213305918"><a name="p1491213305918"></a><a name="p1491213305918"></a>dx: Length,</p>
    <p id="p534123918528"><a name="p534123918528"></a><a name="p534123918528"></a>dy: Length</p>
    <p id="p1934183925219"><a name="p1934183925219"></a><a name="p1934183925219"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p64540421767"><a name="p64540421767"></a><a name="p64540421767"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p19422212014"><a name="p19422212014"></a><a name="p19422212014"></a>{</p>
    <p id="p2251182219015"><a name="p2251182219015"></a><a name="p2251182219015"></a>dx: 0,</p>
    <p id="p117634271408"><a name="p117634271408"></a><a name="p117634271408"></a>dy: 0</p>
    <p id="p8454124215613"><a name="p8454124215613"></a><a name="p8454124215613"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p44541142362"><a name="p44541142362"></a><a name="p44541142362"></a>Offset of the dialog box relative to the alignment position.</p>
    </td>
    </tr>
    <tr id="row07688549148"><td class="cellrowborder" valign="top" width="12.31%" headers="mcps1.1.6.1.1 "><p id="p8768125419148"><a name="p8768125419148"></a><a name="p8768125419148"></a>sheets</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.61%" headers="mcps1.1.6.1.2 "><p id="p1761716152522"><a name="p1761716152522"></a><a name="p1761716152522"></a>Array&lt;<a href="#table896716596134">SheetInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.3 "><p id="p1176845471411"><a name="p1176845471411"></a><a name="p1176845471411"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.6.1.4 "><p id="p16768954111413"><a name="p16768954111413"></a><a name="p16768954111413"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.389999999999997%" headers="mcps1.1.6.1.5 "><p id="p16768954151416"><a name="p16768954151416"></a><a name="p16768954151416"></a>Options in the dialog box. Each option supports the image, text, and callback.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   SheetInfo parameters

    <a name="table5608164215511"></a>
    <table><thead align="left"><tr id="row137221742754"><th class="cellrowborder" valign="top" width="13.848615138486153%" id="mcps1.1.6.1.1"><p id="p117224429519"><a name="p117224429519"></a><a name="p117224429519"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.85781421857814%" id="mcps1.1.6.1.2"><p id="p972216421255"><a name="p972216421255"></a><a name="p972216421255"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.858614138586143%" id="mcps1.1.6.1.3"><p id="p1472218421751"><a name="p1472218421751"></a><a name="p1472218421751"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.958904109589042%" id="mcps1.1.6.1.4"><p id="p97229421454"><a name="p97229421454"></a><a name="p97229421454"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.47605239476052%" id="mcps1.1.6.1.5"><p id="p1372214217516"><a name="p1372214217516"></a><a name="p1372214217516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9722114218514"><td class="cellrowborder" valign="top" width="13.848615138486153%" headers="mcps1.1.6.1.1 "><p id="p072210425511"><a name="p072210425511"></a><a name="p072210425511"></a>title</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.85781421857814%" headers="mcps1.1.6.1.2 "><p id="p187227421515"><a name="p187227421515"></a><a name="p187227421515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.858614138586143%" headers="mcps1.1.6.1.3 "><p id="p47220421052"><a name="p47220421052"></a><a name="p47220421052"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.958904109589042%" headers="mcps1.1.6.1.4 "><p id="p15722142354"><a name="p15722142354"></a><a name="p15722142354"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.47605239476052%" headers="mcps1.1.6.1.5 "><p id="p15722154216519"><a name="p15722154216519"></a><a name="p15722154216519"></a>Sheet text.</p>
    </td>
    </tr>
    <tr id="row1172213429512"><td class="cellrowborder" valign="top" width="13.848615138486153%" headers="mcps1.1.6.1.1 "><p id="p137232042851"><a name="p137232042851"></a><a name="p137232042851"></a>icon</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.85781421857814%" headers="mcps1.1.6.1.2 "><p id="p147231042359"><a name="p147231042359"></a><a name="p147231042359"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.858614138586143%" headers="mcps1.1.6.1.3 "><p id="p2723642952"><a name="p2723642952"></a><a name="p2723642952"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.958904109589042%" headers="mcps1.1.6.1.4 "><p id="p177238421751"><a name="p177238421751"></a><a name="p177238421751"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.47605239476052%" headers="mcps1.1.6.1.5 "><p id="p572344219515"><a name="p572344219515"></a><a name="p572344219515"></a>Sheet icon.</p>
    </td>
    </tr>
    <tr id="row147236422512"><td class="cellrowborder" valign="top" width="13.848615138486153%" headers="mcps1.1.6.1.1 "><p id="p157237421257"><a name="p157237421257"></a><a name="p157237421257"></a>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.85781421857814%" headers="mcps1.1.6.1.2 "><p id="p1572434220515"><a name="p1572434220515"></a><a name="p1572434220515"></a>()=&gt;void</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.858614138586143%" headers="mcps1.1.6.1.3 "><p id="p5724542650"><a name="p5724542650"></a><a name="p5724542650"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.958904109589042%" headers="mcps1.1.6.1.4 "><p id="p27247421352"><a name="p27247421352"></a><a name="p27247421352"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.47605239476052%" headers="mcps1.1.6.1.5 "><p id="p1172424220513"><a name="p1172424220513"></a><a name="p1172424220513"></a>Callback when the sheet is selected.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section080615383813"></a>

```
@Entry
@Component
struct ActionSheetExapmle {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Click to Show ActionSheet')
        .onClick(() => {
          ActionSheet.show({
            title: 'ActionSheet title',
            message: 'message',
            confirm: {
              value: 'Confirm button',
              action: () => {
                console.log('Get Alert Dialog handled')
              }
            },
            sheets: [
              {
                title: 'apples',
                action: () => {
                  console.error('apples')
                }
              },
              {
                title: 'bananas',
                action: () => {
                  console.error('bananas')
                }
              },
              {
                title: 'pears',
                action: () => {
                  console.error('pears')
                }
              }
            ]
          })
        })
    }.width('100%')
    .height('100%')
  }
}
```

![](figures/en-us_image_0000001201475612.gif)

