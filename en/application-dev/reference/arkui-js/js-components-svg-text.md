# text<a name="EN-US_TOPIC_0000001173164689"></a>

The  **<text\>**  component is used to display a piece of textual information.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>-   The text content must be written in the content area. The  **tspan**  sub-element label can be nested to segment the text content. The  **textPath**  sub-element label can be nested to draw the text content based on the specified path.
>-   **<text\>**  can be nested only by the parent element label  **svg**.
>-   Only the default font  **sans-serif**  is supported.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

**Tspan**,  **textpath**,  **animate**, and  **animateTransform are**  supported.

## Attributes<a name="section2907183951110"></a>

The attributes in the following table are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="16.84%" id="mcps1.1.6.1.1"><p id="aaf1247770b244944bbcc9f28d9a6f00b"><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a><a name="aaf1247770b244944bbcc9f28d9a6f00b"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.4%" id="mcps1.1.6.1.2"><p id="a6efc3502761f4faf9630e484280f75b6"><a name="a6efc3502761f4faf9630e484280f75b6"></a><a name="a6efc3502761f4faf9630e484280f75b6"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.4%" id="mcps1.1.6.1.3"><p id="a27a37273d9ad47569ddbcb8db985d302"><a name="a27a37273d9ad47569ddbcb8db985d302"></a><a name="a27a37273d9ad47569ddbcb8db985d302"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.6%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a2ff3361bfd3b420ba4967452d2ddd098"><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a><a name="a2ff3361bfd3b420ba4967452d2ddd098"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row36332165231"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="a83b6dd280109466fb015e64de1ef4df3"><a name="a83b6dd280109466fb015e64de1ef4df3"></a><a name="a83b6dd280109466fb015e64de1ef4df3"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="abc38fa2b85854bc687af75eb17a00a4d"><a name="abc38fa2b85854bc687af75eb17a00a4d"></a><a name="abc38fa2b85854bc687af75eb17a00a4d"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="a8d12e4af905d4743a5ec9cd6018d2972"><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a><a name="a8d12e4af905d4743a5ec9cd6018d2972"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p42461736102118"><a name="p42461736102118"></a><a name="p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="a1a1731af05554f119fa365748f276bb2"><a name="a1a1731af05554f119fa365748f276bb2"></a><a name="a1a1731af05554f119fa365748f276bb2"></a>Unique ID of the component.</p>
</td>
</tr>
<tr id="row1634171618236"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="a3cf785e2a2a043268d168f58d59207c8"><a name="a3cf785e2a2a043268d168f58d59207c8"></a><a name="a3cf785e2a2a043268d168f58d59207c8"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="aa9b258d23e1e425dbc2ffe8edbc91a42"><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a><a name="aa9b258d23e1e425dbc2ffe8edbc91a42"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="ac312df4f14444c98955ed055456848a7"><a name="ac312df4f14444c98955ed055456848a7"></a><a name="ac312df4f14444c98955ed055456848a7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p1624612362219"><a name="p1624612362219"></a><a name="p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p62121758111517"><a name="p62121758111517"></a><a name="p62121758111517"></a>X-coordinate of the upper left corner of the component.</p>
</td>
</tr>
<tr id="row1259531661611"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p1359601671613"><a name="p1359601671613"></a><a name="p1359601671613"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p65967163165"><a name="p65967163165"></a><a name="p65967163165"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p10596151671610"><a name="p10596151671610"></a><a name="p10596151671610"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p1059610169169"><a name="p1059610169169"></a><a name="p1059610169169"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p125961416161611"><a name="p125961416161611"></a><a name="p125961416161611"></a>Y-coordinate of the upper left corner of the component.</p>
</td>
</tr>
<tr id="row11404114510176"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p11404124541714"><a name="p11404124541714"></a><a name="p11404124541714"></a>dx</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p108919015549"><a name="p108919015549"></a><a name="p108919015549"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p20892019541"><a name="p20892019541"></a><a name="p20892019541"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p7893010540"><a name="p7893010540"></a><a name="p7893010540"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p78950185420"><a name="p78950185420"></a><a name="p78950185420"></a>Offset of the text on the x-axis.</p>
</td>
</tr>
<tr id="row75241175410"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p117241850155416"><a name="p117241850155416"></a><a name="p117241850155416"></a>dy</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p4724125035416"><a name="p4724125035416"></a><a name="p4724125035416"></a>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p117241350155416"><a name="p117241350155416"></a><a name="p117241350155416"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p4724145065420"><a name="p4724145065420"></a><a name="p4724145065420"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p107241750205414"><a name="p107241750205414"></a><a name="p107241750205414"></a>Offset of the text on the y-axis.</p>
</td>
</tr>
<tr id="row346915743314"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p1546917783314"><a name="p1546917783314"></a><a name="p1546917783314"></a>rotate</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p846910713319"><a name="p846910713319"></a><a name="p846910713319"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p14469271337"><a name="p14469271337"></a><a name="p14469271337"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p79541222103311"><a name="p79541222103311"></a><a name="p79541222103311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p34692079335"><a name="p34692079335"></a><a name="p34692079335"></a>Rotates the lower left corner of the font based on the circle center. A positive number indicates clockwise rotation, and a negative number indicates counterclockwise rotation.</p>
</td>
</tr>
<tr id="row19322182910543"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p150223885411"><a name="p150223885411"></a><a name="p150223885411"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p3502113811542"><a name="p3502113811542"></a><a name="p3502113811542"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p16502238125414"><a name="p16502238125414"></a><a name="p16502238125414"></a>30px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p1250273816549"><a name="p1250273816549"></a><a name="p1250273816549"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p10502203815413"><a name="p10502203815413"></a><a name="p10502203815413"></a>Font size.</p>
</td>
</tr>
<tr id="row19645239145513"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p1254235895511"><a name="p1254235895511"></a><a name="p1254235895511"></a>fill</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p17542115815553"><a name="p17542115815553"></a><a name="p17542115815553"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p5542135835517"><a name="p5542135835517"></a><a name="p5542135835517"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p65421458105510"><a name="p65421458105510"></a><a name="p65421458105510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p354275835511"><a name="p354275835511"></a><a name="p354275835511"></a>Font fill color.</p>
</td>
</tr>
<tr id="row94649463555"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p1254217581557"><a name="p1254217581557"></a><a name="p1254217581557"></a>fill-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p1754215875514"><a name="p1754215875514"></a><a name="p1754215875514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p15542115814558"><a name="p15542115814558"></a><a name="p15542115814558"></a>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p115433589554"><a name="p115433589554"></a><a name="p115433589554"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p19543058195511"><a name="p19543058195511"></a><a name="p19543058195511"></a>Font fill opacity.</p>
</td>
</tr>
<tr id="row14858838113210"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="a4a0bae0e1bb946d6bc7bf30e0a535343"><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a><a name="a4a0bae0e1bb946d6bc7bf30e0a535343"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="a2679e4565dbc4370b40d1be831a6148d"><a name="a2679e4565dbc4370b40d1be831a6148d"></a><a name="a2679e4565dbc4370b40d1be831a6148d"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="a0b0d56a245e14779a5561f99cd1ce9f6"><a name="a0b0d56a245e14779a5561f99cd1ce9f6"></a><a name="a0b0d56a245e14779a5561f99cd1ce9f6"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p324614367213"><a name="p324614367213"></a><a name="p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="aa0471c31e05e465aa9c42312b9ab9f6f"><a name="aa0471c31e05e465aa9c42312b9ab9f6f"></a><a name="aa0471c31e05e465aa9c42312b9ab9f6f"></a>Opacity of an element. The value ranges from <strong id="b20788312163913"><a name="b20788312163913"></a><a name="b20788312163913"></a>0</strong> to <strong id="b2789412193917"><a name="b2789412193917"></a><a name="b2789412193917"></a>1</strong>. The value <strong id="b1978901216398"><a name="b1978901216398"></a><a name="b1978901216398"></a>1</strong> means opaque, and <strong id="b18790171213917"><a name="b18790171213917"></a><a name="b18790171213917"></a>0</strong> means completely transparent. Attribute animations are supported.</p>
</td>
</tr>
<tr id="row55924498556"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p17543185895520"><a name="p17543185895520"></a><a name="p17543185895520"></a>stroke</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p195431258175515"><a name="p195431258175515"></a><a name="p195431258175515"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p18543658205512"><a name="p18543658205512"></a><a name="p18543658205512"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p16543165855517"><a name="p16543165855517"></a><a name="p16543165855517"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1543145845514"><a name="p1543145845514"></a><a name="p1543145845514"></a>Stroke and stroke color.</p>
</td>
</tr>
<tr id="row175295385512"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p16543115835516"><a name="p16543115835516"></a><a name="p16543115835516"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p15543958165515"><a name="p15543958165515"></a><a name="p15543958165515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p654416580553"><a name="p654416580553"></a><a name="p654416580553"></a>1px</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p25440586552"><a name="p25440586552"></a><a name="p25440586552"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1954415895512"><a name="p1954415895512"></a><a name="p1954415895512"></a>Stroke width.</p>
</td>
</tr>
<tr id="row192241431553"><td class="cellrowborder" valign="top" width="16.84%" headers="mcps1.1.6.1.1 "><p id="p454412587553"><a name="p454412587553"></a><a name="p454412587553"></a>stroke-opacity</p>
</td>
<td class="cellrowborder" valign="top" width="29.4%" headers="mcps1.1.6.1.2 "><p id="p3544358195516"><a name="p3544358195516"></a><a name="p3544358195516"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.4%" headers="mcps1.1.6.1.3 "><p id="p7544165855514"><a name="p7544165855514"></a><a name="p7544165855514"></a>1.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.6.1.4 "><p id="p13544258195517"><a name="p13544258195517"></a><a name="p13544258195517"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p14544185816559"><a name="p14544185816559"></a><a name="p14544185816559"></a>Stroke opacity.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section360556124815"></a>

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
    <text x="20" y="250" fill="red" font-size="40" fill-opacity="0.2">Test Chinese</text>
    <text x="20" y="300" rotate="30" fill="red" font-size="40">test rotate</text>
    <text x="20" y="350" fill="blue" font-size="40" stroke="red" stroke-width="2">test stroke</text>
    <text x="20" y="400" fill="white" font-size="40" stroke="red" stroke-width="2" stroke-opacity="0.5">test stroke-opacity</text>
  </svg>
</div>
```

![](figures/text-part1.png)

Attribute animation example

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

