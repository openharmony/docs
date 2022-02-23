# richtext<a name="ZH-CN_TOPIC_0000001173164701"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

富文本组件，用于展示富文本信息，内容需要写在元素标签内。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section877361219116"></a>

不包含子组件。

## 属性<a name="section2907183951110"></a>

仅支持[通用属性](js-components-common-attributes.md)中的id、style和class属性。

## 样式<a name="section5775351116"></a>

仅支持[通用样式](js-components-common-styles.md)中的display和visibility样式。

## 事件<a name="section17878123517511"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>开始加载时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>complete</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>加载完成时触发。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focus、blur、key事件。
>-   不支持无障碍事件。
>-   包含richtext的页面返回时richtext显示区域不会跟随页面的转场动效。
>-   richtext内容不建议超过一个屏幕高度，超出部分不会显示。
>-   不支持设置宽度，默认撑开全屏。

## 示例<a name="section581819591666"></a>

```
<!-- xxx.hml -->
<div style="flex-direction: column;width: 100%;">
  <richtext @start="onLoadStart" @complete="onLoadEnd">{{content}}</richtext>
</div>
```

```
// xxx.js
export default {
  data: {
    content: `
     <h1 style='text-align: center;'>h1标题</h1>
     <h1 style='text-align: center;'><i>h1斜体</i></h1>
     <h1 style='text-align: center;'><u>h1下划线</u></h1>
     <h2 style='text-align: center;'>h2标题</h2>
     <h3 style='text-align: center;'>h3标题</h3>
     <p style='text-align: center;'>p常规</p><hr/>
     <div style='width: 500px;height: 500px;border: 1px solid;margin: 0auto;'>
         <p style='font-size: 35px;text-align: center;font-weight: bold; color: rgb(24,78,228)'>字体大小35px,行高45px</p>
         <p style='background-color: #e5e5e5;line-height: 45px;font-size: 35px;text-indent: 2em;'>
            这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字
            这是一段文字</p>
     </div>
    `,
  },
  onLoadStart() {
    console.error("start load rich text.")
  },
  onLoadEnd() {
    console.error("end load rich text.")
  }
}
```

