# ListItem<a name="ZH-CN_TOPIC_0000001158141287"></a>

用来展示列表具体item，宽度默认充满List组件，必须配合List来使用。

## 权限列表<a name="section19446161017538"></a>

无

## 子组件<a name="section3767111810531"></a>

可以包含单个子组件。

## 接口<a name="section36922294535"></a>

ListItem\(\)

## 属性<a name="section83861522436"></a>

<a name="table1474mcpsimp"></a>
<table><thead align="left"><tr id="row1481mcpsimp"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.5.1.1"><p id="p1483mcpsimp"><a name="p1483mcpsimp"></a><a name="p1483mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.32%" id="mcps1.1.5.1.2"><p id="p1485mcpsimp"><a name="p1485mcpsimp"></a><a name="p1485mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.3"><p id="p1487mcpsimp"><a name="p1487mcpsimp"></a><a name="p1487mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.41%" id="mcps1.1.5.1.4"><p id="p1489mcpsimp"><a name="p1489mcpsimp"></a><a name="p1489mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1490mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p id="p1492mcpsimp"><a name="p1492mcpsimp"></a><a name="p1492mcpsimp"></a>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1494mcpsimp"><a name="p1494mcpsimp"></a><a name="p1494mcpsimp"></a><a href="#li66453411182">Sticky</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p id="p1496mcpsimp"><a name="p1496mcpsimp"></a><a name="p1496mcpsimp"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p id="p1644391915392"><a name="p1644391915392"></a><a name="p1644391915392"></a>设置ListItem吸顶效果，参见Sticky枚举描述。</p>
</td>
</tr>
<tr id="row1501mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p id="p16779164274313"><a name="p16779164274313"></a><a name="p16779164274313"></a>editable</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1219317506433"><a name="p1219317506433"></a><a name="p1219317506433"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p id="p1507mcpsimp"><a name="p1507mcpsimp"></a><a name="p1507mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p id="p1299917596433"><a name="p1299917596433"></a><a name="p1299917596433"></a>声明当前ListItem元素是否可编辑，进入编辑模式后可删除。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li66453411182"></a>Sticky枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>无吸顶效果。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>当前item吸顶，滑动消失。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section559995265311"></a>

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

![](figures/ListItem.gif)

