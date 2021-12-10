# svg<a name="EN-US_TOPIC_0000001173164705"></a>

**<svg\>**  is a basic container, which is used as the root node of the SVG and can be nested in the SVG.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The APIs of this module are supported since API version 7.
>Constraints: The width and height must be defined for the  **<svg\>**  parent component or  **<svg\>**  component. Otherwise, the component is not drawn.

## Permission List<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

**svg**,  **rect**,  **circle**,  **ellipse**,  **path**,  **line**,  **polygon**,  **polyline**,  **text**,  **animate**, and  **animateTransform**  are supported.

## Attributes<a name="section2907183951110"></a>

The universal attributes as well as the attributes listed below are supported. The configured universal attributes are passed to the child components.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aaf1247770b244944bbcc9f28d9a6f00b"><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="a6efc3502761f4faf9630e484280f75b6"><a name="a6efc3502761f4faf9630e484280f75b6"></a><a name="a6efc3502761f4faf9630e484280f75b6"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="a27a37273d9ad47569ddbcb8db985d302"><a name="a27a37273d9ad47569ddbcb8db985d302"></a><a name="a27a37273d9ad47569ddbcb8db985d302"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a2ff3361bfd3b420ba4967452d2ddd098"><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a83b6dd280109466fb015e64de1ef4df3"><a name="a83b6dd280109466fb015e64de1ef4df3"></a><a name="a83b6dd280109466fb015e64de1ef4df3"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="abc38fa2b85854bc687af75eb17a00a4d"><a name="abc38fa2b85854bc687af75eb17a00a4d"></a><a name="abc38fa2b85854bc687af75eb17a00a4d"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a8d12e4af905d4743a5ec9cd6018d2972"><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p42461736102118"><a name="p42461736102118"></a><a name="p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="a1a1731af05554f119fa365748f276bb2"><a name="a1a1731af05554f119fa365748f276bb2"></a><a name="a1a1731af05554f119fa365748f276bb2"></a>Unique ID of the component.</p>
</td>
</tr>
<tr id="row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a97f90720f6ef448fb3afbb3b1c13ae25"><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="a165d9cd14ccf4127b2e22cc6397680ac"><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a836c513375114f6dac7693e0b4f33230"><a name="a836c513375114f6dac7693e0b4f33230"></a><a name="a836c513375114f6dac7693e0b4f33230"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p17246836142119"><a name="p17246836142119"></a><a name="p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="adbe7ecbee96b4f938b04a4b8d62791bf"><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a>Component width.</p>
</td>
</tr>
<tr id="row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a4a0bae0e1bb946d6bc7bf30e0a535343"><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1346327134215"><a name="p1346327134215"></a><a name="p1346327134215"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p14463117184214"><a name="p14463117184214"></a><a name="p14463117184214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1646316754213"><a name="p1646316754213"></a><a name="p1646316754213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p64638784216"><a name="p64638784216"></a><a name="p64638784216"></a>Component height.</p>
</td>
</tr>
<tr id="row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a3cf785e2a2a043268d168f58d59207c8"><a name="a3cf785e2a2a043268d168f58d59207c8"></a><a name="a3cf785e2a2a043268d168f58d59207c8"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="aa9b258d23e1e425dbc2ffe8edbc91a42"><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="ac312df4f14444c98955ed055456848a7"><a name="ac312df4f14444c98955ed055456848a7"></a><a name="ac312df4f14444c98955ed055456848a7"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1624612362219"><a name="p1624612362219"></a><a name="p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p62121758111517"><a name="p62121758111517"></a><a name="p62121758111517"></a>X-coordinate of the current <strong id="b2724124631610"><a name="b2724124631610"></a><a name="b2724124631610"></a>&lt;svg&gt;</strong> component. The settings do not work for the root <strong id="b172085410165"><a name="b172085410165"></a><a name="b172085410165"></a>&lt;svg&gt;</strong> node.</p>
</td>
</tr>
<tr id="row1259531661611"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1359601671613"><a name="p1359601671613"></a><a name="p1359601671613"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p65967163165"><a name="p65967163165"></a><a name="p65967163165"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1059610169169"><a name="p1059610169169"></a><a name="p1059610169169"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p125961416161611"><a name="p125961416161611"></a><a name="p125961416161611"></a>Y-coordinate of the current <strong id="b122841519181716"><a name="b122841519181716"></a><a name="b122841519181716"></a>&lt;svg&gt;</strong> component. The settings do not work for the root <strong id="b4285131991713"><a name="b4285131991713"></a><a name="b4285131991713"></a>&lt;svg&gt;</strong> node.</p>
</td>
</tr>
<tr id="row11404114510176"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11404124541714"><a name="p11404124541714"></a><a name="p11404124541714"></a>viewBox</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1640474511172"><a name="p1640474511172"></a><a name="p1640474511172"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p740494521712"><a name="p740494521712"></a><a name="p740494521712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p04046452179"><a name="p04046452179"></a><a name="p04046452179"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p740434541717"><a name="p740434541717"></a><a name="p740434541717"></a>View box of the current <strong id="b1055718459177"><a name="b1055718459177"></a><a name="b1055718459177"></a>&lt;svg&gt;</strong> component. The supported format is <strong id="b166865102189"><a name="b166865102189"></a><a name="b166865102189"></a>&lt;number number number number&gt;</strong>. The four parameters indicate the <strong id="b2507112919184"><a name="b2507112919184"></a><a name="b2507112919184"></a>min-x</strong>, <strong id="b11665531141816"><a name="b11665531141816"></a><a name="b11665531141816"></a>min-y</strong>, <strong id="b6237133461814"><a name="b6237133461814"></a><a name="b6237133461814"></a>width</strong>, and <strong id="b1424418412185"><a name="b1424418412185"></a><a name="b1424418412185"></a>height</strong>. The width and height of the view box are different from those of the <strong id="b53631556121813"><a name="b53631556121813"></a><a name="b53631556121813"></a>&lt;svg&gt;</strong> component. The view box is scaled in center-aligned mode.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section360556124815"></a>

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

![](figures/en-us_image_0000001173164789.png)

