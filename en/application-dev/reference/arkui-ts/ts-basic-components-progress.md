# Progress<a name="EN-US_TOPIC_0000001193075086"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Progress\>**  component is used to provide a progress bar that displays the progress of content loading or an operation.

## Required Permissions<a name="section781125411508"></a>

None

## Child Components<a name="section53281531154915"></a>

None

## APIs<a name="section1989913519718"></a>

Progress\(value: \{value: number, total?: number, style?: ProgressStyle\}\)

Creates a progress bar with a specified progress value.

-   Parameters

    <a name="table11384430418"></a>
    <table><thead align="left"><tr id="row103841930216"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p038517301118"><a name="p038517301118"></a><a name="p038517301118"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.3%" id="mcps1.1.6.1.2"><p id="p17385530915"><a name="p17385530915"></a><a name="p17385530915"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.71%" id="mcps1.1.6.1.3"><p id="p03857305117"><a name="p03857305117"></a><a name="p03857305117"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p id="p93855306110"><a name="p93855306110"></a><a name="p93855306110"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p103852301819"><a name="p103852301819"></a><a name="p103852301819"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row103858301018"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p23851230613"><a name="p23851230613"></a><a name="p23851230613"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p id="p1738512301610"><a name="p1738512301610"></a><a name="p1738512301610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p id="p113851302115"><a name="p113851302115"></a><a name="p113851302115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p5385163016119"><a name="p5385163016119"></a><a name="p5385163016119"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p73857301211"><a name="p73857301211"></a><a name="p73857301211"></a>Current progress.</p>
    </td>
    </tr>
    <tr id="row538517301316"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p638510301813"><a name="p638510301813"></a><a name="p638510301813"></a>total</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p id="p838511307111"><a name="p838511307111"></a><a name="p838511307111"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p id="p1338517309117"><a name="p1338517309117"></a><a name="p1338517309117"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p238583011119"><a name="p238583011119"></a><a name="p238583011119"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p13853301411"><a name="p13853301411"></a><a name="p13853301411"></a>Total progress.</p>
    </td>
    </tr>
    <tr id="row1838563011114"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p43853301117"><a name="p43853301117"></a><a name="p43853301117"></a>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.3%" headers="mcps1.1.6.1.2 "><p id="p43851130511"><a name="p43851130511"></a><a name="p43851130511"></a><a href="#table12144170154116">ProgressStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.71%" headers="mcps1.1.6.1.3 "><p id="p113851630312"><a name="p113851630312"></a><a name="p113851630312"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p17385183010110"><a name="p17385183010110"></a><a name="p17385183010110"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p15385430418"><a name="p15385430418"></a><a name="p15385430418"></a>Style of the progress bar.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   ProgressStyle enums

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="24.69%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="75.31%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="24.69%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.31%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>Linear progress bar.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section18430105671014"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p id="p961mcpsimp"><a name="p961mcpsimp"></a><a name="p961mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.5.1.2"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.82%" id="mcps1.1.5.1.3"><p id="p965mcpsimp"><a name="p965mcpsimp"></a><a name="p965mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="42.67%" id="mcps1.1.5.1.4"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1352619001912"><a name="p1352619001912"></a><a name="p1352619001912"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.5.1.2 "><p id="p9247199201913"><a name="p9247199201913"></a><a name="p9247199201913"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.5.1.3 "><p id="p23053910513"><a name="p23053910513"></a><a name="p23053910513"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.67%" headers="mcps1.1.5.1.4 "><p id="p18583122017217"><a name="p18583122017217"></a><a name="p18583122017217"></a>Current progress.</p>
</td>
</tr>
<tr id="row14401548131820"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p10401174801810"><a name="p10401174801810"></a><a name="p10401174801810"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.5.1.2 "><p id="p3401104810185"><a name="p3401104810185"></a><a name="p3401104810185"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.5.1.3 "><p id="p10401048181818"><a name="p10401048181818"></a><a name="p10401048181818"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.67%" headers="mcps1.1.5.1.4 "><p id="p1153317296299"><a name="p1153317296299"></a><a name="p1153317296299"></a>Background color of the progress bar.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13800193662114"></a>

```
@Entry
@Component
struct ProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Linear Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 10, style: ProgressStyle.Linear }).width(200)

      Text('Linear Progress Color').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 20, total: 150, style: ProgressStyle.Linear }).color(Color.Red).value(50).width(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/progress.png)

