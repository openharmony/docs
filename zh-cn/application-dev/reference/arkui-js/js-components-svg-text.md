# text<a name="ZH-CN_TOPIC_0000001173164689"></a>

文本，用于呈现一段信息。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>-   文本的展示内容需要写在元素标签内，可嵌套tspan子元素标签分段，可嵌套textPath子元素标签按指定路径绘制。
>-   只支持被父元素标签svg嵌套。
>-   只支持默认字体sans-serif。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持tspan、textpath、animate、animateTransform。

## 属性<a name="section2907183951110"></a>

支持以下表格中的属性。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.84%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.4%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.4%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.6%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>id</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>组件的唯一标识。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>x</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置组件左上角x轴坐标</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>y</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置组件左上角y轴坐标</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>dx</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置文本x轴偏移</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>dy</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置文本y轴偏移</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>字体以左下角为圆心旋转角度，正数顺时针，负数逆时针</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>30px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置文本的尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>fill</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>字体填充颜色</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>fill-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>字体填充透明度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。支持属性动画。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>stroke</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>绘制字体边框并指定颜色</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>1px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>字体边框宽度</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p>stroke-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>字体边框透明度</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section360556124815"></a>

```
/* xxx.css */
.container {    
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 1000px;
    width: 1080px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20px" y="0px" font-size="30" fill="blue">test x|y</text>
    <text x="150" y="15" font-size="30" fill="blue">test x|y</text>
    <text x="300" y="30" font-size="30" fill="blue" opacity="0.1">test opacity</text>
    <text dx="20" y="30" dy="50" fill="blue" font-size="30">test dx|dy|fill|font-size</text>
    <text x="20" y="150" fill="blue" font-size="30" fill-opacity="0.2">test fill-opacity</text>
    <text x="20" y="200" fill="red" font-size="40">test 0123456789</text>
    <text x="20" y="250" fill="red" font-size="40" fill-opacity="0.2">test 中文</text>
    <text x="20" y="300" rotate="30" fill="red" font-size="40">test rotate</text>
    <text x="20" y="350" fill="blue" font-size="40" stroke="red" stroke-width="2">test stroke</text>
    <text x="20" y="400" fill="white" font-size="40" stroke="red" stroke-width="2" stroke-opacity="0.5">test stroke-opacity</text>
  </svg>
</div>
```

![](figures/text-part1.png)

属性动画示例

```
/* xxx.css  */
.container {
    flex-direction: row;
    justify-content: flex-start;
    align-items: flex-start;
    height: 3000px;
    width: 1080px;
}
```

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text y="50" font-size="30" fill="blue">
      <animate attributeName="x" from="100" by="400" dur="3s" repeatCount="indefinite"></animate>
      <animate attributeName="opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
      <animate attributeName="rotate" from="0" to="360" dur="3s" repeatCount="indefinite"></animate>
      text attribute x|opacity|rotate
    </text>
  </svg>
</div>
```

![](figures/text-animate-part1.gif)

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20" y="200" fill="blue">
      text attribute font-size
      <animate attributeName="font-size" from="10" to="50" dur="3s" repeatCount="indefinite">
      </animate>
    </text>
  </svg>
</div>
```

![](figures/text-animate-part2.gif)

```
<!-- xxx.hml -->
<div class="container">
  <svg>
    <text x="20" y="250" font-size="25" fill="blue" stroke="red">
      text attribute stroke
      <animate attributeName="stroke" from="red" to="#00FF00" dur="3s" repeatCount="indefinite"></animate>
    </text>
    <text x="300" y="250" font-size="25" fill="white" stroke="red">
      text attribute stroke-width-opacity
      <animate attributeName="stroke-width" from="1" to="5" dur="3s" repeatCount="indefinite"></animate>
      <animate attributeName="stroke-opacity" from="0.01" to="0.99" dur="3s" repeatCount="indefinite"></animate>
    </text>
  </svg>
</div>
```

![](figures/text-animate-part3.gif)

