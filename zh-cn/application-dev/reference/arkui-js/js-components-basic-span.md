# span<a name="ZH-CN_TOPIC_0000001127284860"></a>

作为<[text](js-components-basic-text.md)\>子组件提供文本修饰能力。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持子组件<span\>。

## 属性<a name="section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md)。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>不支持focusable和disabled属性。

## 样式<a name="section5775351116"></a>

仅支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.21212121212121%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.8015801580158%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.231423142314231%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.400940094009401%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="39.35393539353936%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>30px</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的文本尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的字体样式，见<a href="js-components-basic-text.md#section5775351116">text组件font-style的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的字体粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的文本修饰，见<a href="js-components-basic-text.md#section5775351116">text组件text-decoration样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p>设置文本段落的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1319514265813"></a>

仅支持[通用事件](js-components-common-events.md)中的click事件。

## 方法<a name="section2291124515582"></a>

不支持。

## 示例<a name="section1841815550582"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text class="title">
    <span class="spanTxt">span</span>
  </text>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.title {
  font-size: 30px;
  text-align: center;
  width: 100%;
  height: 100px;
}
.spanTxt{
  color: chartreuse;
  font-size: 100px;
}
```

![](figures/zh-cn_image_0000001152588626.png)

