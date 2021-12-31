# Span<a name="ZH-CN_TOPIC_0000001237475051"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

文本段落，只能作为Text子组件，呈现一段文本信息。

## 权限列表<a name="section6238143720229"></a>

无

## 子组件<a name="section163926568224"></a>

无

## 接口<a name="section769166122319"></a>

Span\(content: string\)

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
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>文本内容。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section11378635172316"></a>

通用属性方法仅支持通用文本样式，不支持触摸热区设置。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="26.009999999999998%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="21.790000000000003%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="36.199999999999996%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>decoration</p>
</td>
<td class="cellrowborder" valign="top" width="26.009999999999998%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>type: <a href="ts-appendix-enums.md#section81063305178">TextDecorationType</a>,</p>
<p>color?: Color</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="21.790000000000003%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>type: TextDecorationType.None</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="36.199999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本装饰线样式及其颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p>textCase</p>
</td>
<td class="cellrowborder" valign="top" width="26.009999999999998%" headers="mcps1.1.5.1.2 "><p><a href="ts-appendix-enums.md#section1276124151715">TextCase</a></p>
</td>
<td class="cellrowborder" valign="top" width="21.790000000000003%" headers="mcps1.1.5.1.3 "><p>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="36.199999999999996%" headers="mcps1.1.5.1.4 "><p>设置文本大小写。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1093554116361"></a>

通用事件仅支持点击事件。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>由于Span组件无尺寸信息，因此点击事件返回的ClickEvent对象的target属性无效。

## 示例<a name="section21711157202411"></a>

```
@Entry
@Component
struct SpanExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }

      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Underline-span').decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am LineThrough-span').decoration({ type: TextDecorationType.LineThrough, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am Overline-span').decoration({ type: TextDecorationType.Overline, color: Color.Red }).fontSize(12)
      }

      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Lower-span').textCase(TextCase.LowerCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
      Text() {
        Span('I am Upper-span').textCase(TextCase.UpperCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/Span.gif)

