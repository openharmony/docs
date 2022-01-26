# Row<a name="ZH-CN_TOPIC_0000001237355047"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：**
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

沿水平方向布局容器。

## 权限列表<a name="section06615514119"></a>

无

## 子组件<a name="section877361219116"></a>

可以包含子组件。

## 接口<a name="section11682122941119"></a>

Row\(value:\{space?: Length\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.580000000000002%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>space</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.580000000000002%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>横向布局元素间距。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section87414715116"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="61%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p>alignItems</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p><a href="#table12144170154116">VerticalAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p>Center</p>
</td>
<td class="cellrowborder" valign="top" width="61%" headers="mcps1.1.5.1.4 "><p>在垂直方向上子组件的对齐格式。</p>
</td>
</tr>
</tbody>
<tbody><tr><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p>justifyContent</p>
</td>
<td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.5.1.2 "><p><a href="#li1540916112452">FlexAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p>Start</p>
</td>
<td class="cellrowborder" valign="top" width="59%" headers="mcps1.1.5.1.4 "><p>设置子组件在水平方向上的对齐格式。</p>
</td>
</tr>
</tbody>
</table>

-   VerticalAlign枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>顶部对齐。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>居中对齐，默认对齐方式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>底部对齐。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section32771595128"></a>

```
@Entry
@Component
struct RowExample {
  build() {
    Column({ space: 5 }) {
      Text('space').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row({ space: 5 }) {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').height(107).border({ width: 1 })

        Text('alignItems(Top)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Top).height('15%').border({ width: 1 })

        Text('alignItems(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Center).height('15%').border({ width: 1 })

        Text('justifyContent(End)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.End)

        Text('justifyContent(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.Center)
    }.width('100%')
  }
}
```

![](figures/Row.png)

