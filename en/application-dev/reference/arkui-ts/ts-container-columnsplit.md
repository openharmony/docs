# ColumnSplit<a name="EN-US_TOPIC_0000001237475057"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<ColumnSplit\>**  lays out child components vertically and inserts a horizontal divider between every two child components.

## Required Permissions<a name="section53281531154915"></a>

None

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section1643325819470"></a>

ColumnSplit\(\)

## Attributes<a name="section945991855410"></a>

<a name="table252174055416"></a>
<table><thead align="left"><tr id="row353940135411"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p id="p175318403545"><a name="p175318403545"></a><a name="p175318403545"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.29332933293329%" id="mcps1.1.4.1.2"><p id="p453194014548"><a name="p453194014548"></a><a name="p453194014548"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.373337333733375%" id="mcps1.1.4.1.3"><p id="p19531240145412"><a name="p19531240145412"></a><a name="p19531240145412"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row125384035411"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p id="p1753134065413"><a name="p1753134065413"></a><a name="p1753134065413"></a>resizeable</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p id="p85364012541"><a name="p85364012541"></a><a name="p85364012541"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p id="p85314400547"><a name="p85314400547"></a><a name="p85314400547"></a>Whether the divider can be dragged. The default value is <strong id="b77317111362"><a name="b77317111362"></a><a name="b77317111362"></a>false</strong>.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Similar to  **<RowSplit\>**, the divider of  **<ColumnSplit\>**  can be dragged to a position that just fully holds a component.

## Example<a name="section1078035104913"></a>

```
@Entry
@Component
struct ColumnSplitExample {
  build() {
    Column(){
      Text('The secant line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      ColumnSplit() {
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .resizeable(true)
      .width('90%').height('60%')
    }.width('100%')
  }
}
```

![](figures/columnsplit.gif)

