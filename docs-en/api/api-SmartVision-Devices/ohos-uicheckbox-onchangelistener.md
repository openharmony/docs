# OHOS::UICheckBox::OnChangeListener<a name="EN-US_TOPIC_0000001055039540"></a>

-   [Overview](#section130697803165634)
-   [Summary](#section1890884532165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section130697803165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a listener for changes of a check box. 

This is an inner class of  **[UICheckBox](ohos-uicheckbox.md)**. It contains a callback function to be invoked when the check box state changes.

See also
:   [UICheckBox](ohos-uicheckbox.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1890884532165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1793616352165634"></a>
<table><thead align="left"><tr id="row2024494103165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p344322251165634"><a name="p344322251165634"></a><a name="p344322251165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p754635683165634"><a name="p754635683165634"></a><a name="p754635683165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2057690462165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76825535165634"><a name="p76825535165634"></a><a name="p76825535165634"></a><a href="graphic.md#ga373b76d4ce1aea6380f42ce78ecd59c3">OnChange</a> (<a href="graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> state)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368054971165634"><a name="p1368054971165634"></a><a name="p1368054971165634"></a>virtual bool </p>
<p id="p1903281907165634"><a name="p1903281907165634"></a><a name="p1903281907165634"></a>Called when the state of this check box is switched. This is a virtual function, which needs your implementation. </p>
</td>
</tr>
<tr id="row547728232165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854510458165634"><a name="p1854510458165634"></a><a name="p1854510458165634"></a><a href="graphic.md#gab2e7f64e07e70975baa571660687f6a1">~OnChangeListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491668588165634"><a name="p1491668588165634"></a><a name="p1491668588165634"></a>virtual </p>
<p id="p521733748165634"><a name="p521733748165634"></a><a name="p521733748165634"></a>A destructor used to delete the <strong id="b969232589165634"><a name="b969232589165634"></a><a name="b969232589165634"></a><a href="ohos-uicheckbox-onchangelistener.md">OnChangeListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1689724476165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608733664165634"><a name="p1608733664165634"></a><a name="p1608733664165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p164409858165634"><a name="p164409858165634"></a><a name="p164409858165634"></a>void * </p>
<p id="p1029904932165634"><a name="p1029904932165634"></a><a name="p1029904932165634"></a>Overrides the <strong id="b2047827076165634"><a name="b2047827076165634"></a><a name="b2047827076165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1348664984165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2039858712165634"><a name="p2039858712165634"></a><a name="p2039858712165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1082786775165634"><a name="p1082786775165634"></a><a name="p1082786775165634"></a>void </p>
<p id="p332756612165634"><a name="p332756612165634"></a><a name="p332756612165634"></a>Overrides the <strong id="b1516071910165634"><a name="b1516071910165634"></a><a name="b1516071910165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

