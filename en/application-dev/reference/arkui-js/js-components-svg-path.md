# path<a name="EN-US_TOPIC_0000001173164771"></a>

The  **<path\>**  component is used to draw a path.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

**animate**,  **animateMotion**, and  **animateTransform**  are supported.

## Attributes<a name="section2907183951110"></a>

The  [universal attributes](js-components-svg-common-attributes.md)  and the attributes listed below are supported. The configured universal attributes are passed to the child components.

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
<tr id="row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a97f90720f6ef448fb3afbb3b1c13ae25"><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a><a name="a97f90720f6ef448fb3afbb3b1c13ae25"></a>d</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="a165d9cd14ccf4127b2e22cc6397680ac"><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a><a name="a165d9cd14ccf4127b2e22cc6397680ac"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a836c513375114f6dac7693e0b4f33230"><a name="a836c513375114f6dac7693e0b4f33230"></a><a name="a836c513375114f6dac7693e0b4f33230"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p17246836142119"><a name="p17246836142119"></a><a name="p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="adbe7ecbee96b4f938b04a4b8d62791bf"><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a><a name="adbe7ecbee96b4f938b04a4b8d62791bf"></a>Shape of the path. The value contains a group of character instructions. Uppercase letters are absolute paths, and lowercase letters are relative paths.</p>
<p id="p46751932620"><a name="p46751932620"></a><a name="p46751932620"></a>The meanings of the letters are as follows:</p>
<a name="ul146753321226"></a><a name="ul146753321226"></a><ul id="ul146753321226"><li>M/m = moveto</li><li>L/l = lineto</li><li>H/h = horizontal lineto</li><li>V/v = vertical lineto</li><li>C/c = curveto</li><li>S/s = smooth curveto</li><li>Q/q = quadratic Belzier curve</li><li>T/t = smooth quadratic Belzier curveto</li><li>A/a = elliptical Arc</li><li>Z/z = closepath</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="section360556124815"></a>

```
<!-- xxx.hml -->
<div class="container">
    <svg width="400" height="400">
        <path d="M 10,30 A 20,20 0,0,1 50,30 A 20,20 0,0,1 90,30 Q 90,60 50,90 Q 10,60 10,30 z"
          stroke="blue" stroke-width="3" fill="red">
        </path>
    </svg>
</div>
```

![](figures/en-us_image_0000001173164891.png)

