# 边框设置<a name="ZH-CN_TOPIC_0000001237555101"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

设置组件边框样式。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.79%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.57%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="43.64%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>border</p>
</td>
<td class="cellrowborder" valign="top" width="27.79%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>width?: Length,</p>
<p>color?: Color,</p>
<p>radius?: Length,</p>
<p>style?: <a href="#li5617903594">BorderStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.64%" headers="mcps1.1.5.1.4 "><p>统一边框样式设置接口。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>borderStyle</p>
</td>
<td class="cellrowborder" valign="top" width="27.79%" headers="mcps1.1.5.1.2 "><p><a href="#li5617903594">BorderStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.1.5.1.3 "><p>Solid</p>
</td>
<td class="cellrowborder" valign="top" width="43.64%" headers="mcps1.1.5.1.4 "><p>设置元素的边框样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>borderWidth</p>
</td>
<td class="cellrowborder" valign="top" width="27.79%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="43.64%" headers="mcps1.1.5.1.4 "><p>设置元素的边框宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>borderColor</p>
</td>
<td class="cellrowborder" valign="top" width="27.79%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.64%" headers="mcps1.1.5.1.4 "><p>设置元素的边框颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>borderRadius</p>
</td>
<td class="cellrowborder" valign="top" width="27.79%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="43.64%" headers="mcps1.1.5.1.4 "><p>设置元素的边框圆角半径。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li5617903594"></a>BorderStyle枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Dotted</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>显示为一系列圆点，圆点半径为borderWidth的一半。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Dashed</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>显示为一系列短的方形虚线。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Solid</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>显示为一条实线。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1976245813394"></a>

```
@Entry
@Component
struct BorderExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
      // 线段
      Text('dashed')
        .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      // 点线
      Text('dotted')
        .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
    }.width('100%').height(150)
  }
}
```

![](figures/border.gif)

