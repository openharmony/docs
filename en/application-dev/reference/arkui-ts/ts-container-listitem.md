# ListItem<a name="EN-US_TOPIC_0000001192595148"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<ListItem\>**  component displays specific items in the list. Its width occupies the  **<List\>**  component by default and must be used together with  **<List\>**.

## Required Permissions<a name="section19446161017538"></a>

None

## Child Components<a name="section3767111810531"></a>

This component can contain a single child component.

## APIs<a name="section36922294535"></a>

ListItem\(\)

## Attributes<a name="section83861522436"></a>

<a name="table1474mcpsimp"></a>
<table><thead align="left"><tr id="row1481mcpsimp"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.5.1.1"><p id="p1483mcpsimp"><a name="p1483mcpsimp"></a><a name="p1483mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.32%" id="mcps1.1.5.1.2"><p id="p1485mcpsimp"><a name="p1485mcpsimp"></a><a name="p1485mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.3"><p id="p1487mcpsimp"><a name="p1487mcpsimp"></a><a name="p1487mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.41%" id="mcps1.1.5.1.4"><p id="p1489mcpsimp"><a name="p1489mcpsimp"></a><a name="p1489mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1490mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p id="p1492mcpsimp"><a name="p1492mcpsimp"></a><a name="p1492mcpsimp"></a>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1494mcpsimp"><a name="p1494mcpsimp"></a><a name="p1494mcpsimp"></a><a href="#li66453411182">Sticky</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p id="p1496mcpsimp"><a name="p1496mcpsimp"></a><a name="p1496mcpsimp"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p id="p1644391915392"><a name="p1644391915392"></a><a name="p1644391915392"></a>Sticky effect of the list item. For details, see <a href="#table3452114216394">Sticky enums</a>.</p>
</td>
</tr>
<tr id="row1501mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p id="p16779164274313"><a name="p16779164274313"></a><a name="p16779164274313"></a>editable</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1219317506433"><a name="p1219317506433"></a><a name="p1219317506433"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p id="p1507mcpsimp"><a name="p1507mcpsimp"></a><a name="p1507mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p id="p1299917596433"><a name="p1299917596433"></a><a name="p1299917596433"></a>Whether the list item is editable. A list item can be deleted in editing mode.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li66453411182"></a>Sticky enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>No sticky.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>The list item is sticky and disappears when you slide it.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section559995265311"></a>

```
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Text('sticky:Normal , click me edit list')
            .width('100%').height(40).fontSize(12).fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center).backgroundColor(0x696969)
            .onClick(() => {
              this.editFlag = !this.editFlag
            })
        }.sticky(Sticky.Normal)

        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }.editable(this.editFlag)
        }, item => item)
      }
      .editMode(true)
      .onItemDelete((index: number) => {
        console.info(this.arr[index - 1] + 'Delete')
        this.arr.splice(index - 1,1)
        this.editFlag = false
        return true
      }).width('90%')
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![](figures/listitem.gif)

