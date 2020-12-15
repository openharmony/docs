# OHOS::Style<a name="EN-US_TOPIC_0000001055518122"></a>

-   [Overview](#section1036123221165635)
-   [Summary](#section2120768408165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1036123221165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the basic attributes and functions of a style. You can use this class to set different styles. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2120768408165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table441089452165635"></a>
<table><thead align="left"><tr id="row83336546165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p765213114165635"><a name="p765213114165635"></a><a name="p765213114165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p573759297165635"><a name="p573759297165635"></a><a name="p573759297165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1913870531165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406084941165635"><a name="p1406084941165635"></a><a name="p1406084941165635"></a><a href="graphic.md#ga592b31b43819c40563c52fe7b45d9358">Style</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990611430165635"><a name="p990611430165635"></a><a name="p990611430165635"></a> </p>
<p id="p1509173504165635"><a name="p1509173504165635"></a><a name="p1509173504165635"></a>A constructor used to create a <strong id="b324738571165635"><a name="b324738571165635"></a><a name="b324738571165635"></a><a href="ohos-style.md">Style</a></strong> instance. </p>
</td>
</tr>
<tr id="row1487326831165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72122697165635"><a name="p72122697165635"></a><a name="p72122697165635"></a><a href="graphic.md#ga6356d56766de8fe37d4888ef70f521ec">~Style</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420739660165635"><a name="p1420739660165635"></a><a name="p1420739660165635"></a>virtual </p>
<p id="p114708228165635"><a name="p114708228165635"></a><a name="p114708228165635"></a>A destructor used to delete the <strong id="b617447295165635"><a name="b617447295165635"></a><a name="b617447295165635"></a><a href="ohos-style.md">Style</a></strong> instance. </p>
</td>
</tr>
<tr id="row1119542537165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544011283165635"><a name="p544011283165635"></a><a name="p544011283165635"></a><a href="graphic.md#ga31941bb1abbb6744ee832d4b0fe6e080">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2009644959165635"><a name="p2009644959165635"></a><a name="p2009644959165635"></a>void </p>
<p id="p332557940165635"><a name="p332557940165635"></a><a name="p332557940165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1345496315165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1913146981165635"><a name="p1913146981165635"></a><a name="p1913146981165635"></a><a href="graphic.md#ga2b4b818f26822ad6a020473e6a5e5214">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421608590165635"><a name="p1421608590165635"></a><a name="p1421608590165635"></a>int64_t </p>
<p id="p515422633165635"><a name="p515422633165635"></a><a name="p515422633165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1652901112165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1428651553165635"><a name="p1428651553165635"></a><a name="p1428651553165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2030904545165635"><a name="p2030904545165635"></a><a name="p2030904545165635"></a>void * </p>
<p id="p386686216165635"><a name="p386686216165635"></a><a name="p386686216165635"></a>Overrides the <strong id="b195460588165635"><a name="b195460588165635"></a><a name="b195460588165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1710690646165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p858396794165635"><a name="p858396794165635"></a><a name="p858396794165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973688345165635"><a name="p973688345165635"></a><a name="p973688345165635"></a>void </p>
<p id="p1531904970165635"><a name="p1531904970165635"></a><a name="p1531904970165635"></a>Overrides the <strong id="b1876199664165635"><a name="b1876199664165635"></a><a name="b1876199664165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

