# RowSplit<a name="EN-US_TOPIC_0000001168264323"></a>

The  **<RowSplit\>**  lays out child components horizontally and inserts a vertical divider between every two child components.

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section1643325819470"></a>

RowSplit\(\)

## Attributes<a name="section945991855410"></a>

<a name="table252174055416"></a>
<table><thead align="left"><tr id="row353940135411"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p175318403545"><a name="p175318403545"></a><a name="p175318403545"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.532953295329534%" id="mcps1.1.4.1.2"><p id="p453194014548"><a name="p453194014548"></a><a name="p453194014548"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="37.13371337133714%" id="mcps1.1.4.1.3"><p id="p19531240145412"><a name="p19531240145412"></a><a name="p19531240145412"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row125384035411"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1753134065413"><a name="p1753134065413"></a><a name="p1753134065413"></a>resizeable</p>
</td>
<td class="cellrowborder" valign="top" width="29.532953295329534%" headers="mcps1.1.4.1.2 "><p id="p85364012541"><a name="p85364012541"></a><a name="p85364012541"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="37.13371337133714%" headers="mcps1.1.4.1.3 "><p id="p85314400547"><a name="p85314400547"></a><a name="p85314400547"></a>Whether the divider can be dragged. The default value is <strong id="b224464612187"><a name="b224464612187"></a><a name="b224464612187"></a>false</strong>.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Similar to  **<RowSplit\>**, the divider of  **<RowSplit\>**  can be dragged to a position that just fully holds a component.

## Example<a name="section1078035104913"></a>

```
@Entry
@Component
struct RowSplitExample {
  build() {
    Column() {
      Text('The secant line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      RowSplit() {
        Text('1').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('10%').height(100).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('10%').height(100).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .resizeable(true) // The divider can be dragged.
      .width('90%').height(100)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/rowsplit.gif)

