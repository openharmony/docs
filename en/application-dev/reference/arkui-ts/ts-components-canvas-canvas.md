# Canvas<a name="EN-US_TOPIC_0000001237355065"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Canvas\>**  component can be used to customize drawings.

## Required Permissions<a name="section53281531154915"></a>

None

## Child Components<a name="section9288143101012"></a>

None

## APIs<a name="section15647101282420"></a>

Canvas\(context: CanvasRenderingContext2D\)

-   Parameters

    <a name="table193606194544"></a>
    <table><thead align="left"><tr id="row536071910541"><th class="cellrowborder" valign="top" width="12.540000000000001%" id="mcps1.1.6.1.1"><p id="p436112199544"><a name="p436112199544"></a><a name="p436112199544"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.150000000000002%" id="mcps1.1.6.1.2"><p id="p19361319115410"><a name="p19361319115410"></a><a name="p19361319115410"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.49%" id="mcps1.1.6.1.3"><p id="p9361201975417"><a name="p9361201975417"></a><a name="p9361201975417"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p id="p43611199542"><a name="p43611199542"></a><a name="p43611199542"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1136141975419"><a name="p1136141975419"></a><a name="p1136141975419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10361101915545"><td class="cellrowborder" valign="top" width="12.540000000000001%" headers="mcps1.1.6.1.1 "><p id="p1361119155417"><a name="p1361119155417"></a><a name="p1361119155417"></a>context</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.150000000000002%" headers="mcps1.1.6.1.2 "><p id="p115573011512"><a name="p115573011512"></a><a name="p115573011512"></a><a href="ts-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.49%" headers="mcps1.1.6.1.3 "><p id="p153611119195411"><a name="p153611119195411"></a><a name="p153611119195411"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1436114193546"><a name="p1436114193546"></a><a name="p1436114193546"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p328155017218"><a name="p328155017218"></a><a name="p328155017218"></a>For details, see <a href="ts-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section2907183951110"></a>

[Universal attributes](ts-universal-attributes-size.md)  are supported.

## Events<a name="section47669296127"></a>

In addition to  [universal events](ts-universal-events-click.md), the following events are supported.

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="34.2%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.470000000000002%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="49.33%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="34.2%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>onReady(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="16.470000000000002%" headers="mcps1.1.4.1.2 "><p id="p685785963319"><a name="p685785963319"></a><a name="p685785963319"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="49.33%" headers="mcps1.1.4.1.3 "><p id="p14183154363412"><a name="p14183154363412"></a><a name="p14183154363412"></a>Triggered when .</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section42931433142318"></a>

```
@Entry
@Component
struct CanvasExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.fillRect(0,30,100,100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

