# richtext<a name="ZH-CN_TOPIC_0000001173164701"></a>

富文本组件，用于展示富文本信息。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   从 API Version 6 开始支持。
>-   富文本内容需要写在元素标签内。

## 权限列表<a name="section11257113618419"></a>

无

## 属性<a name="section2907183951110"></a>

仅支持[通用属性](js-components-common-attributes.md)中的id、style和class属性。

## 样式<a name="section5775351116"></a>

仅支持[通用样式](js-components-common-styles.md)中的display和visibility样式。

## 事件<a name="section17878123517511"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<a name="table13878203565113"></a>
<table><thead align="left"><tr id="row18789355519"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p08781335165113"><a name="p08781335165113"></a><a name="p08781335165113"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p6878123595117"><a name="p6878123595117"></a><a name="p6878123595117"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p28783359518"><a name="p28783359518"></a><a name="p28783359518"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2087803565116"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p3878113518516"><a name="p3878113518516"></a><a name="p3878113518516"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p187813511516"><a name="p187813511516"></a><a name="p187813511516"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1269067752"><a name="p1269067752"></a><a name="p1269067752"></a>开始加载时触发。</p>
</td>
</tr>
<tr id="row28781235145111"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p118810157518"><a name="p118810157518"></a><a name="p118810157518"></a>complete</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19878535135111"><a name="p19878535135111"></a><a name="p19878535135111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p13878335145119"><a name="p13878335145119"></a><a name="p13878335145119"></a>加载完成时触发。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focus、blur、key事件。
>-   不支持无障碍事件。
>-   包含richtext的页面返回时richtext显示区域不会跟随页面的转场动效。
>-   richtext内容不建议超过一个屏幕高度，超出部分不会显示。

## 方法<a name="section14703165113610"></a>

不支持。

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
    <div class="flex-direction: column; background-color: #ffffff; padding: 30px; margin-bottom: 30px;"  style="background-color: #FFFFFF">
      <style>h1{color: yellow;}</style>
      <p class="item-title">h1</p>
      <h1>文本测试(h1测试)</h1>
      <p class="item-title">h2</p>
      <h2>文本测试(h2测试)</h2>
    </div>
    `,
  },
  onLoadStart() {
    console.error("start load rich text:" + JSON.stringify())
  },
  onLoadEnd() {
    console.error("end load rich text:" + JSON.stringify())
  }
}
```

