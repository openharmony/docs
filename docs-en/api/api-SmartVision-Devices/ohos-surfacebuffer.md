# OHOS::SurfaceBuffer<a name="EN-US_TOPIC_0000001054718143"></a>

-   [Overview](#section977729523165633)
-   [Summary](#section1163816034165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section977729523165633"></a>

**Related Modules:**

[Surface](surface.md)

**Description:**

Provides functions such as setting the virtual address, size, and additional attributes of shared memory. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1163816034165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table127227145165633"></a>
<table><thead align="left"><tr id="row266480016165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1981574221165633"><a name="p1981574221165633"></a><a name="p1981574221165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p516805400165633"><a name="p516805400165633"></a><a name="p516805400165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row354815380165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531960825165633"><a name="p1531960825165633"></a><a name="p1531960825165633"></a><a href="surface.md#ga623d6c8ced742a36017bb71f6441b2a7">GetVirAddr</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305051095165633"><a name="p1305051095165633"></a><a name="p1305051095165633"></a>virtual void * </p>
<p id="p404616388165633"><a name="p404616388165633"></a><a name="p404616388165633"></a>Obtains the virtual address of shared memory for producers and consumers. </p>
</td>
</tr>
<tr id="row1735176420165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836862658165633"><a name="p836862658165633"></a><a name="p836862658165633"></a><a href="surface.md#ga5d797958fed83fdea15b3f6ad5ddf97e">GetPhyAddr</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451241145165633"><a name="p451241145165633"></a><a name="p451241145165633"></a>virtual uint64_t </p>
<p id="p1375510060165633"><a name="p1375510060165633"></a><a name="p1375510060165633"></a>Obtains the physical address of shared memory. </p>
</td>
</tr>
<tr id="row988881037165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p270725510165633"><a name="p270725510165633"></a><a name="p270725510165633"></a><a href="surface.md#gaad9d0ca349b3f398b31c38ac9a650138">GetSize</a> () const =0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694572671165633"><a name="p1694572671165633"></a><a name="p1694572671165633"></a>virtual uint32_t </p>
<p id="p1356595520165633"><a name="p1356595520165633"></a><a name="p1356595520165633"></a>Obtains the size of shared memory. </p>
</td>
</tr>
<tr id="row2120936614165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895153226165633"><a name="p895153226165633"></a><a name="p895153226165633"></a><a href="surface.md#ga818ee9015ff03d536b9a73d52f36b4f2">SetSize</a> (uint32_t size)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421909780165633"><a name="p1421909780165633"></a><a name="p1421909780165633"></a>virtual void </p>
<p id="p535989675165633"><a name="p535989675165633"></a><a name="p535989675165633"></a>Sets the size of shared memory. </p>
</td>
</tr>
<tr id="row1451024163165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087506667165633"><a name="p2087506667165633"></a><a name="p2087506667165633"></a><a href="surface.md#gaf4b467cb2d7015d00f4bcf77c5b19875">SetInt32</a> (uint32_t key, int32_t value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832729668165633"><a name="p1832729668165633"></a><a name="p1832729668165633"></a>virtual int32_t </p>
<p id="p448237544165633"><a name="p448237544165633"></a><a name="p448237544165633"></a>Sets an extra attribute value of the int32 type. </p>
</td>
</tr>
<tr id="row1244228581165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34364019165633"><a name="p34364019165633"></a><a name="p34364019165633"></a><a href="surface.md#ga54a916606158a8799fe421eb3842848e">GetInt32</a> (uint32_t key, int32_t &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143187644165633"><a name="p1143187644165633"></a><a name="p1143187644165633"></a>virtual int32_t </p>
<p id="p1212685399165633"><a name="p1212685399165633"></a><a name="p1212685399165633"></a>Obtains an extra attribute value of the int32 type. </p>
</td>
</tr>
<tr id="row451784853165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639459030165633"><a name="p639459030165633"></a><a name="p639459030165633"></a><a href="surface.md#ga479eea3722e4d8448ead051c2f11cec5">SetInt64</a> (uint32_t key, int64_t value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p687455363165633"><a name="p687455363165633"></a><a name="p687455363165633"></a>virtual int32_t </p>
<p id="p1583615078165633"><a name="p1583615078165633"></a><a name="p1583615078165633"></a>Sets an extra attribute value of the int64 type. </p>
</td>
</tr>
<tr id="row191022730165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078995026165633"><a name="p2078995026165633"></a><a name="p2078995026165633"></a><a href="surface.md#ga3a442c71aee865c7b7a9bb6505ce800a">GetInt64</a> (uint32_t key, int64_t &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758171653165633"><a name="p1758171653165633"></a><a name="p1758171653165633"></a>virtual int32_t </p>
<p id="p361912486165633"><a name="p361912486165633"></a><a name="p361912486165633"></a>Obtains an extra attribute value of the int64 type. </p>
</td>
</tr>
</tbody>
</table>

