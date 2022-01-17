# AlphabetIndexer<a name="ZH-CN_TOPIC_0000001192915108"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

字母索引条。

## 支持设备<a name="section151761552181217"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.223613595706617%" id="mcps1.1.5.1.1"><p>手机</p>
</th>
<th class="cellrowborder" valign="top" width="21.451997614788315%" id="mcps1.1.5.1.2"><p>平板</p>
</th>
<th class="cellrowborder" valign="top" width="26.25223613595707%" id="mcps1.1.5.1.3"><p>智慧屏</p>
</th>
<th class="cellrowborder" valign="top" width="27.072152653548002%" id="mcps1.1.5.1.4"><p>智能穿戴</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="25.223613595706617%" headers="mcps1.1.5.1.1 "><p>支持</p>
</td>
<td class="cellrowborder" valign="top" width="21.451997614788315%" headers="mcps1.1.5.1.2 "><p>支持</p>
</td>
<td class="cellrowborder" valign="top" width="26.25223613595707%" headers="mcps1.1.5.1.3 "><p>不支持</p>
</td>
<td class="cellrowborder" valign="top" width="27.072152653548002%" headers="mcps1.1.5.1.4 "><p>不支持</p>
</td>
</tr>
</tbody>
</table>

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section1437452132415"></a>

无

## 接口<a name="section6883949112416"></a>

AlphabetIndexer\(value: \{arrayValue : Array<string\>, selected : number\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.75%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.75%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>arrayValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.75%" headers="mcps1.1.6.1.2 "><p>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.75%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>字母索引字符串数组。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>selected</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.75%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.75%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>选中项编号。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section3345133819557"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.29332933293329%" id="mcps1.1.4.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.373337333733375%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>selectedColor</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>选中文本文字颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>popupColor</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>弹出提示文本字体颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>selectedBackgroundColor</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>选中文本背景颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>popupBackground</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>弹窗索引背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>usingPopup</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>是否使用弹出索引提示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>selectedFont</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>{</p>
<p>size?: number,</p>
<p>weight?: FontWeight,</p>
<p>family?: string,</p>
<p>style?: FontStyle</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>选中文本文字样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>popupFont</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>{</p>
<p>size?: number,</p>
<p>weight?: FontWeight,</p>
<p>family?: string,</p>
<p>style?: FontStyle</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>弹出提示文本字体样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>font</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>{</p>
<p>size?: number,</p>
<p>weight?: FontWeight,</p>
<p>family?: string,</p>
<p>style?: FontStyle</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>字母索引条默认文本字体样式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>itemSize</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>字母索引条字母区域大小，字母区域为正方形，设置正方形边长。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.1.4.1.1 "><p>alignStyle</p>
</td>
<td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.2 "><p>IndexerAlign</p>
</td>
<td class="cellrowborder" valign="top" width="33.373337333733375%" headers="mcps1.1.4.1.3 "><p>字母索引条对齐样式，支持左侧对齐样式与右侧对齐样式，影响弹窗弹出位置。</p>
</td>
</tr>
</tbody>
</table>

-   IndexerAlign枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>弹框显示在索引条右侧。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>弹框显示在索引条左侧。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section12808326678"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="40.6%" id="mcps1.1.3.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="59.4%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="40.6%" headers="mcps1.1.3.1.1 "><p>onSelected(index: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="59.4%" headers="mcps1.1.3.1.2 "><p>字母索引条选中回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="40.6%" headers="mcps1.1.3.1.1 "><p>onRequestPopupData(callback: (index: number) =&gt; Array&lt;string&gt;)<sup><span>8+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="59.4%" headers="mcps1.1.3.1.2 "><p>选中字母索引后，请求索引提示窗口显示内容回调。</p>
<p>返回值：索引对应的字符串数组，此字符串数组在弹出窗口中竖排显示，字符串列表最多显示5个，超出部分可以滑动显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="40.6%" headers="mcps1.1.3.1.1 "><p>onPopupSelected(callback: (index: number) =&gt; void)<sup><span>8+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="59.4%" headers="mcps1.1.3.1.2 "><p>字母索引提示窗口选中回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section11665132318294"></a>

```
@Entry
@Component
struct AlphabetIndexerComponent {
  private value: string[] = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

  build() {
    AlphabetIndexer({ arrayValue: this.value, selected: 0 })
      .selectedColor(0xffffff) // 选中颜色
      .popupColor(0xFFFAF0) // 弹出框颜色
      .selectedBackgroundColor(0xCCCCCC) // 选中背景颜色
      .popupBackground(0xD2B48C) // 弹出框背景颜色
      .usingPopup(true) // 是否显示弹出框
      .selectedFont({ size: 16, weight: FontWeight.Bolder }) // 选中的样式
      .popupFont({ size: 30, weight: FontWeight.Bolder }) // 弹出框的演示
      .itemSize(28) // 每一项的大小正方形
      .alignStyle(IndexerAlign.Left) // 左对齐
      .onSelected((index: number) => {
        console.info(this.value[index] + '被选中了') // 选中的事件
      })
      .margin({ left: 50 })
  }
}
```

![](figures/alphabetindexer.gif)

