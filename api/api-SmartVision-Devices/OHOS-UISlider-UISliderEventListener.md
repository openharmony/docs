# OHOS::UISlider::UISliderEventListener<a name="ZH-CN_TOPIC_0000001054598187"></a>

-   [Overview](#section1283742170165634)
-   [Summary](#section232933391165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1283742170165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents the listener for a slider change. 

This is an inner class of  **[UISlider](OHOS-UISlider.md)**  used to listen for slider events and invoke the callback function.

See also
:   [UISlider](OHOS-UISlider.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section232933391165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table98790044165634"></a>
<table><thead align="left"><tr id="row1998510719165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p36056926165634"><a name="p36056926165634"></a><a name="p36056926165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1001087372165634"><a name="p1001087372165634"></a><a name="p1001087372165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1857041110165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p565695006165634"><a name="p565695006165634"></a><a name="p565695006165634"></a><a href="Graphic.md#gaf7923989ab1a8cb8a0b643ef65d02134">~UISliderEventListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285157013165634"><a name="p285157013165634"></a><a name="p285157013165634"></a>virtual </p>
<p id="p1822074510165634"><a name="p1822074510165634"></a><a name="p1822074510165634"></a>A destructor used to delete the <strong id="b2062186042165634"><a name="b2062186042165634"></a><a name="b2062186042165634"></a> <a href="OHOS-UISlider-UISliderEventListener.md">UISliderEventListener</a> </strong> instance. </p>
</td>
</tr>
<tr id="row1257332631165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949367240165634"><a name="p1949367240165634"></a><a name="p1949367240165634"></a><a href="Graphic.md#ga6044e7ac9a27c7a85cc855dd32e4df5e">OnChange</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016267382165634"><a name="p2016267382165634"></a><a name="p2016267382165634"></a>virtual void </p>
<p id="p1812133705165634"><a name="p1812133705165634"></a><a name="p1812133705165634"></a>Called when the slider is dragged or clicked. This is a virtual function, which needs your implementation. </p>
</td>
</tr>
<tr id="row1544909958165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501938119165634"><a name="p501938119165634"></a><a name="p501938119165634"></a><a href="Graphic.md#gaf8982c429bfa52c1a8a01d1115b596e6">OnRelease</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565377721165634"><a name="p1565377721165634"></a><a name="p1565377721165634"></a>virtual void </p>
<p id="p1281661238165634"><a name="p1281661238165634"></a><a name="p1281661238165634"></a>Called when the slider is released. This is a virtual function, which needs your implementation. </p>
</td>
</tr>
<tr id="row1679023961165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097848149165634"><a name="p2097848149165634"></a><a name="p2097848149165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025940286165634"><a name="p2025940286165634"></a><a name="p2025940286165634"></a>void * </p>
<p id="p2041824420165634"><a name="p2041824420165634"></a><a name="p2041824420165634"></a>Overrides the <strong id="b552742357165634"><a name="b552742357165634"></a><a name="b552742357165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1328274532165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p433583259165634"><a name="p433583259165634"></a><a name="p433583259165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p998557461165634"><a name="p998557461165634"></a><a name="p998557461165634"></a>void </p>
<p id="p847427013165634"><a name="p847427013165634"></a><a name="p847427013165634"></a>Overrides the <strong id="b619045053165634"><a name="b619045053165634"></a><a name="b619045053165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

