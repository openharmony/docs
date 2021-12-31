# Text<a name="ZH-CN_TOPIC_0000001192915102"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

文本，用于呈现一段信息。

## 权限列表<a name="section1895361713156"></a>

无

## 子组件<a name="section1444658131617"></a>

可以包含[Span](ts-basic-components-span.md)子组件。

## 接口<a name="section1383178131719"></a>

Text\(content?: string\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>content</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>''</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>文本内容，包含子组件Span时不生效，显示Span内容。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section175320400172"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.35%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="26.51%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>textAlign</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p><a href="#li16164333289">TextAlign</a></p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>Start</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置多行文本的文本对齐方式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>textOverflow</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p>{overflow: <a href="#li3837144314284">TextOverflow</a>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>{overflow: TextOverflow.Clip}</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本超长时的显示方式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>maxLines</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>Infinity</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本的最大行数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>lineHeight</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本的文本行高，设置值不大于0时，不限制文本行高，自适应字体大小，Length为number类型时单位为fp。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>decoration</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>type: <a href="#li182215492284">TextDecorationType</a>,</p>
<p>color?: Color</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>type: TextDecorationType.None,</p>
<p>color：Color.Black</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本装饰线样式及其颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>baselineOffset</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本基线的偏移量。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>textCase</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.5.1.2 "><p><a href="#li6551155619287">TextCase</a></p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.1.5.1.3 "><p>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="26.51%" headers="mcps1.1.5.1.4 "><p>设置文本大小写。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li16164333289"></a>TextAlign枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本居中对齐。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>根据文字书写相同的方向对齐。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>根据文字书写相反的方向对齐。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li3837144314284"></a>TextOverflow枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Clip</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本超长时进行裁剪显示。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Ellipsis</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本超长时显示不下的文本用省略号代替。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本超长时不进行裁剪。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li182215492284"></a>TextDecorationType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Underline</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文字下划线修饰。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>LineThrough</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>穿过文本的修饰线。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Overline</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文字上划线修饰。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>不使用文本装饰线。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li6551155619287"></a>TextCase枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>保持文本原有大小写。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>LowerCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本采用全小写。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>UpperCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>文本采用全大写。</p>
    </td>
    </tr>
    </tbody>
    </table>


>![](../../public_sys-resources/icon-note.gif) **说明：** 
>不支持Text内同时存在文本内容和Span子组件。（如果同时存在，只显示Span内的内容\)。

## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct TextExample1 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text with the line height set This is the text with the line height set This is the text with the line height set.')
        .lineHeight(25).fontSize(12).border({ width: 1 }).padding(10)

      Text('TextOverflow').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the setting of textOverflow to none text content This is the setting of textOverflow to none text content.')
        .textOverflow({ overflow: TextOverflow.None })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to Clip text content.')
        .textOverflow({ overflow: TextOverflow.Clip })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)
      Text('This is set textOverflow to Ellipsis text content This is set textOverflow to Ellipsis text content.')
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)

      Text('decoration').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with the decoration set to Underline and the color set to Red.')
        .decoration({ type: TextDecorationType.Underline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to LineThrough and the color set to Red.')
        .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to Overline and the color set to Red.')
        .decoration({ type: TextDecorationType.Overline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
    }.height(600).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/Text1.gif)

```
@Entry
@Component
struct TextExample2 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('textCase').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textCase set to Normal.')
        .textCase(TextCase.Normal)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to LowerCase.')
        .textCase(TextCase.LowerCase)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to UpperCase.')
        .textCase(TextCase.UpperCase)
        .fontSize(12).border({ width: 1 }).padding(10)

      Text('textAlign').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textAlign set to Center.')
        .textAlign(TextAlign.Center)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to Start.')
        .textAlign(TextAlign.Start)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to End.')
        .textAlign(TextAlign.End)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')

      Text('baselineOffset').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with baselineOffset set to 10.')
        .baselineOffset(10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to 30.')
        .baselineOffset(30).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to -10.')
        .baselineOffset(-10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
    }.height(700).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/Text2.gif)

