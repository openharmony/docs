# polygon<a name="ZH-CN_TOPIC_0000001127284872"></a>

绘制多边形。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持animate、animateMotion、animateTransform。

## 属性<a name="section2907183951110"></a>

支持所列的Svg组件通用属性和以下表格的属性。

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
<tr id="row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a97f90720f6ef448fb3afbb3b1c13ae25"><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a>points</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="a165d9cd14ccf4127b2e22cc6397680ac"><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a836c513375114f6dac7693e0b4f33230"><a name="a836c513375114f6dac7693e0b4f33230"></a><a name="a836c513375114f6dac7693e0b4f33230"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p17246836142119"><a name="p17246836142119"></a><a name="p17246836142119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="adbe7ecbee96b4f938b04a4b8d62791bf"><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a>设置多边形的多个坐标点</p>
<p id="p158933814449"><a name="p158933814449"></a><a name="p158933814449"></a>格式为[x1,y1 x2,y2 x3,y3]。</p>
<p id="p78913383449"><a name="p78913383449"></a><a name="p78913383449"></a>支持属性动画，如果属性动画里设置的动效变化值的坐标个数与原始points的格式不一样，则无效</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section360556124815"></a>

```
<!-- xxx.hml -->
<div class="container">
  <svg fill="white" stroke="blue" width="400" height="400">
    <polygon points="10,110 60,35 60,85 110,10" fill="red"></polygon>
    <polygon points="10,200 60,125 60,175 110,100" stroke-dasharray="10 5" stroke-dashoffset="3"></polygon>
  </svg>
</div>
```

![](figures/zh-cn_image_0000001173324721.png)

