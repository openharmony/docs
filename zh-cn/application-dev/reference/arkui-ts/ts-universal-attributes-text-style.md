# 文本样式设置<a name="ZH-CN_TOPIC_0000001237475065"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

针对包含文本元素的组件，设置文本样式。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.15%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.3%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.28%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="57.269999999999996%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.5.1.1 "><p>fontColor</p>
</td>
<td class="cellrowborder" valign="top" width="18.3%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="57.269999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.5.1.1 "><p>fontSize</p>
</td>
<td class="cellrowborder" valign="top" width="18.3%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="57.269999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本尺寸，Length为number类型时，使用fp单位。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.5.1.1 "><p>fontStyle</p>
</td>
<td class="cellrowborder" valign="top" width="18.3%" headers="mcps1.1.5.1.2 "><p><a href="#li6906111945316">FontStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.3 "><p>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="57.269999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本的字体样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.5.1.1 "><p>fontWeight</p>
</td>
<td class="cellrowborder" valign="top" width="18.3%" headers="mcps1.1.5.1.2 "><p>number | <a href="#li24391125115311">FontWeight</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.3 "><p>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="57.269999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</p>
<p>提供常用枚举值，参考：<a href="#li24391125115311">FontWeight</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.5.1.1 "><p>fontFamily</p>
</td>
<td class="cellrowborder" valign="top" width="18.3%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="57.269999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li6906111945316"></a>FontStyle枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>标准的字体样式。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Italic</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>斜体的字体样式。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li24391125115311"></a>FontWeight枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Lighter</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体较细。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体粗细正常。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Regular</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体粗细正常。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Medium</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体粗细适中。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Bold</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体较粗。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Bolder</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>字体非常粗。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section17655814153017"></a>

```
@Entry
@Component
struct TextStyleExample {
  build() {
    Column({ space: 5 }) {
      Text('default text')

      Text('text font color red')
        .fontColor(Color.Red)

      Text('text font size 20')
        .fontSize(20)

      Text('text font style Italic')
        .fontStyle(FontStyle.Italic)

      Text('text fontWeight bold')
        .fontWeight(700)

      Text('text fontFamily sans-serif')
        .fontFamily('sans-serif')

      Text('red 20 Italic bold cursive text')
        .fontColor(Color.Red)
        .fontSize(20)
        .fontStyle(FontStyle.Italic)
        .fontWeight(700)
        .fontFamily('cursive')
        .textAlign(TextAlign.Center)
        .width('90%')

      Text('Orange 18 Normal source-sans-pro text')
        .fontColor(Color.Orange)
        .fontSize(18)
        .fontStyle(FontStyle.Normal)
        .fontWeight(400)
        .fontFamily('source-sans-pro,cursive,sans-serif')
    }.width('100%')
  }
}
```

![](figures/textstyle.png)

