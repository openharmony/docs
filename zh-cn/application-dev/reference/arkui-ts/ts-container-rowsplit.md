# RowSplit<a name="ZH-CN_TOPIC_0000001168264323"></a>

将子组件横向布局，并在每个子组件之间插入一根纵向的分割线。

## 子组件<a name="section5989144051714"></a>

可以包含子组件

## 接口<a name="section1643325819470"></a>

RowSplit\(\)

## 属性<a name="section945991855410"></a>

<a name="table252174055416"></a>
<table><thead align="left"><tr id="row353940135411"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p175318403545"><a name="p175318403545"></a><a name="p175318403545"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.532953295329534%" id="mcps1.1.4.1.2"><p id="p453194014548"><a name="p453194014548"></a><a name="p453194014548"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="37.13371337133714%" id="mcps1.1.4.1.3"><p id="p19531240145412"><a name="p19531240145412"></a><a name="p19531240145412"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row125384035411"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1753134065413"><a name="p1753134065413"></a><a name="p1753134065413"></a>resizeable</p>
</td>
<td class="cellrowborder" valign="top" width="29.532953295329534%" headers="mcps1.1.4.1.2 "><p id="p85364012541"><a name="p85364012541"></a><a name="p85364012541"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="37.13371337133714%" headers="mcps1.1.4.1.3 "><p id="p85314400547"><a name="p85314400547"></a><a name="p85314400547"></a>分割线是否可拖拽，默认为false。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>RowSplit的分割线最小能拖动到刚好包含子组件。

## 示例<a name="section1078035104913"></a>

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
      .resizeable(true) // 可拖动
      .width('90%').height(100)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/RowSplit.gif)

