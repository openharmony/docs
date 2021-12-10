# svg<a name="ZH-CN_TOPIC_0000001173164705"></a>

基础容器，主要作为svg的根节点使用，也可以在svg中嵌套使用。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。
>约束条件：svg父组件或者svg组件需要定义宽高值，否则不进行绘制。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持svg、rect、circle、ellipse、path、line、polygon、polyline、text、animate、animateTransform。

## 属性<a name="section2907183951110"></a>

支持所列的Svg组件通用属性和以下表格的属性，设置的通用属性会传递给子组件。

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
<tbody><tr id="row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a83b6dd280109466fb015e64de1ef4df3"><a name="a83b6dd280109466fb015e64de1ef4df3"></a><a name="a83b6dd280109466fb015e64de1ef4df3"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="abc38fa2b85854bc687af75eb17a00a4d"><a name="abc38fa2b85854bc687af75eb17a00a4d"></a><a name="abc38fa2b85854bc687af75eb17a00a4d"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a8d12e4af905d4743a5ec9cd6018d2972"><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p42461736102118"><a name="p42461736102118"></a><a name="p42461736102118"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="a1a1731af05554f119fa365748f276bb2"><a name="a1a1731af05554f119fa365748f276bb2"></a><a name="a1a1731af05554f119fa365748f276bb2"></a>组件的唯一标识。</p>
</td>
</tr>
<tr id="row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a97f90720f6ef448fb3afbb3b1c13ae25"><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="a165d9cd14ccf4127b2e22cc6397680ac"><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a836c513375114f6dac7693e0b4f33230"><a name="a836c513375114f6dac7693e0b4f33230"></a><a name="a836c513375114f6dac7693e0b4f33230"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p17246836142119"><a name="p17246836142119"></a><a name="p17246836142119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="adbe7ecbee96b4f938b04a4b8d62791bf"><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a>设置组件的宽度</p>
</td>
</tr>
<tr id="row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a4a0bae0e1bb946d6bc7bf30e0a535343"><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1346327134215"><a name="p1346327134215"></a><a name="p1346327134215"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p14463117184214"><a name="p14463117184214"></a><a name="p14463117184214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1646316754213"><a name="p1646316754213"></a><a name="p1646316754213"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p64638784216"><a name="p64638784216"></a><a name="p64638784216"></a>设置组件的高度</p>
</td>
</tr>
<tr id="row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a3cf785e2a2a043268d168f58d59207c8"><a name="a3cf785e2a2a043268d168f58d59207c8"></a><a name="a3cf785e2a2a043268d168f58d59207c8"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="aa9b258d23e1e425dbc2ffe8edbc91a42"><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="ac312df4f14444c98955ed055456848a7"><a name="ac312df4f14444c98955ed055456848a7"></a><a name="ac312df4f14444c98955ed055456848a7"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1624612362219"><a name="p1624612362219"></a><a name="p1624612362219"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p62121758111517"><a name="p62121758111517"></a><a name="p62121758111517"></a>设置当前svg的x轴坐标，根svg节点无效</p>
</td>
</tr>
<tr id="row1259531661611"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1359601671613"><a name="p1359601671613"></a><a name="p1359601671613"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p65967163165"><a name="p65967163165"></a><a name="p65967163165"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1059610169169"><a name="p1059610169169"></a><a name="p1059610169169"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p125961416161611"><a name="p125961416161611"></a><a name="p125961416161611"></a>设置当前svg的y轴坐标，根svg节点无效</p>
</td>
</tr>
<tr id="row11404114510176"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11404124541714"><a name="p11404124541714"></a><a name="p11404124541714"></a>viewBox</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1640474511172"><a name="p1640474511172"></a><a name="p1640474511172"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p740494521712"><a name="p740494521712"></a><a name="p740494521712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p04046452179"><a name="p04046452179"></a><a name="p04046452179"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p740434541717"><a name="p740434541717"></a><a name="p740434541717"></a>设置当前svg的视口。支持的格式为&lt;number number number number&gt;，4个参数分别表示min-x, min-y, width and height，viewBox的宽高和svg的宽高不一致，会以中心对齐进行缩放。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section360556124815"></a>

```
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400">
    <svg width="200" height="200" viewBox="0 0 100 100">
      <rect x="10" y="10" width="80" height="80" fill="#00FF00"></rect>
    </svg>
    <rect x="10" y="10" width="80" height="80" fill="red" ></rect>
    <svg x="0" y="0" width="200" height="200" viewBox="0 0 200 200">
      <rect x="10" y="10" width="80" height="80" fill="red"></rect>
    </svg>
    <svg x="0" y="0" width="200" height="200" viewBox="0 0 400 400">
      <rect x="10" y="10" width="80" height="80" fill="blue"></rect>
    </svg>
  </svg>
</div>
```

![](figures/zh-cn_image_0000001173164789.png)

