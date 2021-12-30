# toolbar-item<a name="ZH-CN_TOPIC_0000001127125080"></a>

工具栏子组件。作为工具栏组件的子组件，用于展示工具栏上的一个操作选项。

## 子组件<a name="section9288143101012"></a>

无

## 属性<a name="section19217161499"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>该操作项文本内容。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>icon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>该操作项图标资源路径，该图标展示在选项文本上，支持本地路径，格式为png，jpg和svg。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section184493015533"></a>

仅支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.82%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.379999999999999%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="46.300000000000004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本字体样式，可选值为：</p>
<ol><li>normal: 标准的字体样式；</li><li>italic: 斜体的字体样式。</li></ol>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>number|string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本字体粗细，number类型取值[100, 900]的整数（被100整除），默认为400，取值越大，字体越粗。string类型取值为：lighter、normal、bold、bolder。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>文本修饰，可选值为：</p>
<ol><li>underline: 文本下划线修饰；</li><li>line-through: 穿过文本的修饰线；</li><li>none: 标准文本。</li></ol>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>仅支持设置<a href="js-components-common-gradient.md">渐变样式</a>，与background-color、background-image不兼容。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>设置背景颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>设置背景图片。与background-color、background不兼容；支持网络图片资源和本地图片资源地址。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><ul><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>设置背景图片的大小。</p>
<ul><li>string可选值：<ul><li>contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。</li><li>cover：把背景图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。</li><li>auto：保持原图的比例不变。</li></ul>
</li><li>length值参数方式：<p>设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li><li>百分比参数方式：<p>以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 "auto"。</p>
</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>针对重复背景图像样式进行设置，背景图像默认在水平和垂直方向上重复。</p>
<ul><li>repeat：在水平轴和竖直轴上同时重复绘制图片。</li><li>repeat-x：只在水平轴上重复绘制图片。</li><li>repeat-y：只在竖直轴上重复绘制图片。</li><li>no-repeat：不会重复绘制图片。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><ul><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><ul><li>关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<ul><li>left：水平方向上最左侧。</li><li>right：水平方向上最右侧。</li><li>top：竖直方向上最顶部。</li><li>bottom：竖直方向上最底部。</li><li>center：水平方向或竖直方向上中间位置。</li></ul>
</li></ul>
<ul><li>length值参数方式：第一个值是水平位置，第二个值是垂直位置。 左上角是 0 0。单位是像素 (0px 0px)  。如果仅规定了一个值，另外一个值将是50%。</li><li>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另外一个值为50%。</li><li>可以混合使用&lt;percentage&gt;和&lt;length&gt;。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>display</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>确定一个元素所产生的框的类型，可选值为：</p>
<ul><li>flex：弹性布局。</li><li>none：不渲染此元素。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.6.1.1 "><p>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.6.1.2 "><p>string</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.6.1.3 "><p>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.1.6.1.5 "><p>是否显示元素所产生的框。不可见的框会占用布局（将'display'属性设置为'none'来完全去除框），可选值为：</p>
<ul><li>visible：元素正常显示。</li><li>hidden：隐藏元素，但是其他元素的布局不改变，相当于此元素变成透明。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>visibility和display样式都设置时，仅display生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section571865310552"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section568225514199"></a>

不支持。

## 示例<a name="section1240714821316"></a>

```
<!-- xxx.hml -->
<toolbar style="position: fixed; bottom: 0px; ">    
   <toolbar-item icon='common/Icon/location.png' value='Option 1' >   </toolbar-item>
   <toolbar-item icon='common/Icon/heart.png' value='Option 2'>   </toolbar-item>    
   <toolbar-item icon='common/Icon/diamond.png' value='Option 3'  >   </toolbar-item>    
   <toolbar-item icon='common/Icon/heart.png' value='Option 4' >   </toolbar-item>    
   <toolbar-item icon='common/Icon/heart.png' value='Option 5' >   </toolbar-item>
   <toolbar-item icon='common/Icon/heart.png' value='Option 6'>   </toolbar-item> 
</toolbar>
```

![](figures/000000.jpg)

