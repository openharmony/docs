# osal\_irq.h<a name="ZH-CN_TOPIC_0000001055518064"></a>

-   [Overview](#section1833893572165628)
-   [Summary](#section2023091480165628)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1833893572165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares interrupt request \(IRQ\) interfaces and common IRQ trigger modes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2023091480165628"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table996218787165628"></a>
<table><thead align="left"><tr id="row1548146077165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1354923595165628"><a name="p1354923595165628"></a><a name="p1354923595165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p871039953165628"><a name="p871039953165628"></a><a name="p871039953165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row483676208165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1199357635165628"><a name="p1199357635165628"></a><a name="p1199357635165628"></a><a href="OSAL.md#gab671a9e177f622a98af9ca1bd93198eb">OsalIRQHandle</a>) (uint32_t irqId, void *dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11063800165628"><a name="p11063800165628"></a><a name="p11063800165628"></a> typedef uint32_t(* </p>
<p id="p1048575022165628"><a name="p1048575022165628"></a><a name="p1048575022165628"></a>Defines an IRQ type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1394547510165628"></a>
<table><thead align="left"><tr id="row1119103158165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p429990434165628"><a name="p429990434165628"></a><a name="p429990434165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1056601940165628"><a name="p1056601940165628"></a><a name="p1056601940165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1580658759165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252826816165628"><a name="p1252826816165628"></a><a name="p1252826816165628"></a><a href="OSAL.md#ga78cd126b10424753db6f39f9b72ea124">OSAL_IRQ_TRIGGER_MODE</a> {   <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124aa0252cbf1f560b1d9951da4dfe896a1d">OSAL_IRQF_TRIGGER_NONE</a> = 0, <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c">OSAL_IRQF_TRIGGER_RISING</a> = 1, <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124a3088c6875fb44d05fd3a64a3d158295b">OSAL_IRQF_TRIGGER_FALLING</a> = 2, <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124a9a997189554c568f66dd994a9f9e203d">OSAL_IRQF_TRIGGER_HIGH</a> = 4,   <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124a7768ec0b5be5e88cfeb07dea96cd5865">OSAL_IRQF_TRIGGER_LOW</a> = 8 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959729734165628"><a name="p1959729734165628"></a><a name="p1959729734165628"></a>Enumerates interrupt trigger modes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1709438602165628"></a>
<table><thead align="left"><tr id="row1333125573165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p986829582165628"><a name="p986829582165628"></a><a name="p986829582165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1995833046165628"><a name="p1995833046165628"></a><a name="p1995833046165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2139373459165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604079783165628"><a name="p604079783165628"></a><a name="p604079783165628"></a><a href="OSAL.md#gade084a1942c1672f2148ccf8f6c06331">OsalRegisterIrq</a> (uint32_t irqId, uint32_t config, <a href="OSAL.md#gab671a9e177f622a98af9ca1bd93198eb">OsalIRQHandle</a> handle, const char *name, void *dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249981368165628"><a name="p1249981368165628"></a><a name="p1249981368165628"></a>int32_t </p>
<p id="p659680401165628"><a name="p659680401165628"></a><a name="p659680401165628"></a>Registers an IRQ. </p>
</td>
</tr>
<tr id="row1663447668165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p79344359165628"><a name="p79344359165628"></a><a name="p79344359165628"></a><a href="OSAL.md#gade4ec4496eb07f1ff0610b53ba419dba">OsalUnregisterIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906994107165628"><a name="p906994107165628"></a><a name="p906994107165628"></a>int32_t </p>
<p id="p654864732165628"><a name="p654864732165628"></a><a name="p654864732165628"></a>Unregisters an IRQ. </p>
</td>
</tr>
<tr id="row1857494879165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p701594498165628"><a name="p701594498165628"></a><a name="p701594498165628"></a><a href="OSAL.md#ga7f27c6171678ab8cf925660068ac38ff">OsalEnableIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170829494165628"><a name="p1170829494165628"></a><a name="p1170829494165628"></a>int32_t </p>
<p id="p1134718800165628"><a name="p1134718800165628"></a><a name="p1134718800165628"></a>Enables an IRQ. </p>
</td>
</tr>
<tr id="row560223022165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1204952110165628"><a name="p1204952110165628"></a><a name="p1204952110165628"></a><a href="OSAL.md#gaf6ae039d209e46d45c683aeda3e7cd28">OsalDisableIrq</a> (uint32_t irqId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413456258165628"><a name="p1413456258165628"></a><a name="p1413456258165628"></a>int32_t </p>
<p id="p688442671165628"><a name="p688442671165628"></a><a name="p688442671165628"></a>Disables an IRQ. </p>
</td>
</tr>
</tbody>
</table>

