# animateMotion<a name="ZH-CN_TOPIC_0000001173324621"></a>

路径动效。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

支持animate属性\(values不生效\)和以下表格中的属性。

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aaf1247770b244944bbcc9f28d9a6f00b"><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="a6efc3502761f4faf9630e484280f75b6"><a name="a6efc3502761f4faf9630e484280f75b6"></a><a name="a6efc3502761f4faf9630e484280f75b6"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="a27a37273d9ad47569ddbcb8db985d302"><a name="a27a37273d9ad47569ddbcb8db985d302"></a><a name="a27a37273d9ad47569ddbcb8db985d302"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a2ff3361bfd3b420ba4967452d2ddd098"><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p19122124719532"><a name="p19122124719532"></a><a name="p19122124719532"></a>keyPoints</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p3121547175310"><a name="p3121547175310"></a><a name="p3121547175310"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p201211474539"><a name="p201211474539"></a><a name="p201211474539"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p151201747195314"><a name="p151201747195314"></a><a name="p151201747195314"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1211954714533"><a name="p1211954714533"></a><a name="p1211954714533"></a>一组关键帧的点位置，每帧的值为对象沿路径的距离比例。功能与animate属性中的values相同。</p>
</td>
</tr>
<tr id="row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p311854717535"><a name="p311854717535"></a><a name="p311854717535"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1911864710533"><a name="p1911864710533"></a><a name="p1911864710533"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p31171947115310"><a name="p31171947115310"></a><a name="p31171947115310"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1911624795319"><a name="p1911624795319"></a><a name="p1911624795319"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p21152477539"><a name="p21152477539"></a><a name="p21152477539"></a>定义运动的路径，使用与path组件d属性相同的语法。</p>
</td>
</tr>
<tr id="row88054245713"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p198115428579"><a name="p198115428579"></a><a name="p198115428579"></a>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p13811242205710"><a name="p13811242205710"></a><a name="p13811242205710"></a>[auto | auto-reverse | &lt;number&gt;]</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1181042175712"><a name="p1181042175712"></a><a name="p1181042175712"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p168174211576"><a name="p168174211576"></a><a name="p168174211576"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p981164295716"><a name="p981164295716"></a><a name="p981164295716"></a>设置动画对象的旋转方向</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section360556124815"></a>

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" width="400" height="400">
    <path fill="none" stroke="blue" stroke-width="3" d="m40,60 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,130 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="none" stroke="blue" stroke-width="3" d="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto" keyPoints="0;0.2;0.4;0.6;0.8;1" path="m40,60 c0,-100 160,160,100 160,0 c0,-100,-160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="auto-reverse"path="m40,130 c0,-100 160,100 160,0 c0,-100,-160,100 -160,0 z">
      </animateMotion>
    </path>
    <path fill="red" d="M-5,-5 L10,0 L-5,5 L0,0 Z">
      <animateMotion dur="2000" repeatCount="indefinite" rotate="45"path="m40,200 c0,-100 160,100 160,0 c0,-100 -160,100 -160,0 z"></animateMotion>
    </path>
  </svg>
</div>
```

![](figures/2-2.gif)

