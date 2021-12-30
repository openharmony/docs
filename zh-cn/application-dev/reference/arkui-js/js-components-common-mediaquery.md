# 媒体查询<a name="ZH-CN_TOPIC_0000001173164721"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   media属性值默认为设备的真实尺寸大小、物理像素和真实的屏幕分辨率。请勿与以720px为基准的项目配置宽度px混淆。

媒体查询（Media Query）在移动设备上应用十分广泛，开发者经常需要根据设备的大致类型或者特定的特征和设备参数（例如屏幕分辨率）来修改应用的样式。为此媒体查询提供了如下功能：

1.  针对设备和应用的属性信息，可以设计出相匹配的布局样式。
2.  当屏幕发生动态改变时（比如分屏、横竖屏切换），应用页面布局同步更新。

## CSS语法规则<a name="section168919480313"></a>

使用@media来引入查询语句，具体规则如下：

```
@media [media-type] [and|not|only] [(media-feature)] {
  CSS-Code;
}
```

例子：

@media screen and \(round-screen: true\) \{ … \} // 当设备屏幕是圆形时条件成立

@media \(max-height: 800\) \{ … \} // 范围查询，CSS level 3 写法

@media \(height <= 800\) \{ … \} // 范围查询，CSS level 4 写法，与CSS level3写法等价

@media screen and \(device-type: tv\) or \(resolution < 2\) \{ … \} // 同时包含媒体类型和多个媒体特征的多条件复杂语句查询

## 页面中引用资源<a name="section1993557745"></a>

通过@import方式引入媒体查询，具体使用方法如下：

```
@import url [media-type] [and|not|only] [(media-feature)];
```

例如：

```
@import '../common/style.css' screen and (min-width: 600) and (max-width: 1200);
```

## 媒体类型<a name="section17366633144"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p>screen</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p>按屏幕相关参数进行媒体查询。</p>
</td>
</tr>
</tbody>
</table>

## 媒体逻辑操作<a name="section9949248948"></a>

媒体逻辑操作符：and、or、not、only用于构成复杂媒体查询，也可以通过comma（,）将其组合起来，详细解释说明如下表。

**表 1**  媒体逻辑操作符

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.02%" id="mcps1.2.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="79.97999999999999%" id="mcps1.2.3.1.2"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p>and</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p>将多个媒体特征（Media Feature）以“与”的方式连接成一个媒体查询，只有当所有媒体特征都为true，查询条件成立。另外，它还可以将媒体类型和媒体功能结合起来。</p>
<p>例如：screen and (device-type: wearable) and (max-height: 600) 表示当设备类型是智能穿戴同时应用的最大高度小于等于600个像素单位时成立。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p>not</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p>取反媒体查询结果，媒体查询结果不成立时返回true，否则返回false。在媒体查询列表中应用not，则not仅取反应用它的媒体查询。</p>
<p>例如：not screen and (min-height: 50) and (max-height: 600) 表示当应用高度小于50个像素单位或者大于600个像素单位时成立。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用not运算符时必须指定媒体类型。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p>only</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p>当整个表达式都匹配时，才会应用选择的样式，可以应用在防止某些较早的版本的浏览器上产生歧义的场景。一些较早版本的浏览器对于同时包含了媒体类型和媒体特征的语句会产生歧义，比如：</p>
<p>screen and (min-height: 50)</p>
<p>老版本浏览器会将这句话理解成screen，从而导致仅仅匹配到媒体类型（screen），就应用了指定样式，使用only可以很好地规避这种情况。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用only时必须指定媒体类型。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p>,(comma)</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p>将多个媒体特征以“或”的方式连接成一个媒体查询，如果存在结果为true的媒体特征，则查询条件成立。其效果等同于or运算符。</p>
<p>例如：screen and (min-height: 1000),  （round-screen：true） 表示当应用高度大于等于1000个像素单位或者设备屏幕是圆形时，条件成立。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.3.1.1 "><p>or</p>
</td>
<td class="cellrowborder" valign="top" width="79.97999999999999%" headers="mcps1.2.3.1.2 "><p>将多个媒体特征以“或”的方式连接成一个媒体查询，如果存在结果为true的媒体特征，则查询条件成立。</p>
<p>例如：screen and (max-height: 1000) or  （round-screen：true）表示当应用高度小于等于1000个像素单位或者设备屏幕是圆形时，条件成立。</p>
</td>
</tr>
</tbody>
</table>

在MediaQuery Level 4中引入了范围查询，使其能够使用max-，min-的同时，也支持了<=，\>=，<，\>操作符。

**表 2**  媒体逻辑范围操作符

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p>&lt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p>小于等于，例如：screen and (height &lt;= 50)。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p>&gt;=</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p>大于等于，例如：screen and (height &gt;= 600)。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p>&lt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p>小于，例如：screen and (height &lt; 50)。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p>大于，例如：screen and (height &gt; 600)。</p>
</td>
</tr>
</tbody>
</table>

## 媒体特征<a name="section192341841653"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="34.11%" id="mcps1.1.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="65.89%" id="mcps1.1.3.1.2"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的最小高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的最大高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的最小宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的最大宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的分辨率，支持dpi，dppx和dpcm单位。其中：</p>
<ul><li>dpi表示每英寸中物理像素个数，1dpi≈0.39dpcm；</li><li>dpcm表示每厘米上的物理像素个数，1dpcm ≈ 2.54dpi；</li><li>dppx表示每个px中的物理像素数（此单位按96px=1英寸为基准，与页面中的px单位计算方式不同），1dppx = 96dpi。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最小分辨率。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-resolution</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最大分辨率。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>orientation</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>屏幕的方向。</p>
<p>可选值：</p>
<ul><li>orientation: portrait（设备竖屏）</li><li>orientation: landscape（设备横屏）</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的宽度与高度的比值。</p>
<p>例如：aspect-ratio:1/2</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的宽度与高度的最小比值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>应用页面显示区域的宽度与高度的最大比值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最小高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-device-height</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最大高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>min-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最小宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>max-device-width</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>设备的最大宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>round-screen</p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>屏幕类型，圆形屏幕为true， 非圆形屏幕为 false。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="34.11%" headers="mcps1.1.3.1.1 "><p>dark-mode<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="65.89%" headers="mcps1.1.3.1.2 "><p>系统为深色模式时为true，否则为false。</p>
</td>
</tr>
</tbody>
</table>

## 示例代码<a name="section1018513818615"></a>

-   通用媒体特征示例代码：

```
<!-- xxx.hml -->
<div>
  <div class="container">
    <text class="title">Hello World</text>
  </div>
</div>
```

```
/* xxx.css */
.container {
  width: 300px;
  height: 600px;
  background-color: #008000;
}
@media (device-type: tv) {
  .container {
    width: 500px;
    height: 500px;
    background-color: #fa8072;
  }
} 
@media (device-type: wearable) {
  .container {
    width: 300px;
    height: 300px;
    background-color: #008b8b;
  }
} 
```

