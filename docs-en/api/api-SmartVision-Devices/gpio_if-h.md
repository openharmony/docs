# gpio\_if.h<a name="EN-US_TOPIC_0000001055518056"></a>

-   [Overview](#section597261440165627)
-   [Summary](#section730195322165627)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section597261440165627"></a>

**Related Modules:**

[GPIO](gpio.md)

**Description:**

Declares the standard GPIO interface functions. 

**Since:**

1.0

## **Summary**<a name="section730195322165627"></a>

## Typedefs<a name="typedef-members"></a>

<a name="table1761909882165627"></a>
<table><thead align="left"><tr id="row1453436489165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1981564135165627"><a name="p1981564135165627"></a><a name="p1981564135165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p653632365165627"><a name="p653632365165627"></a><a name="p653632365165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row671745757165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1179765151165627"><a name="p1179765151165627"></a><a name="p1179765151165627"></a><a href="gpio.md#ga8f3b7d0f0aaa1da8117781efe4b1670e">GpioIrqFunc</a>) (uint16_t gpio, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1547436729165627"><a name="p1547436729165627"></a><a name="p1547436729165627"></a>typedef int32_t(* </p>
<p id="p926292812165627"><a name="p926292812165627"></a><a name="p926292812165627"></a>Defines the function type of a GPIO interrupt service routine (ISR). </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1634060585165627"></a>
<table><thead align="left"><tr id="row1739184713165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p501398085165627"><a name="p501398085165627"></a><a name="p501398085165627"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1846407080165627"><a name="p1846407080165627"></a><a name="p1846407080165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1492964704165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368118343165627"><a name="p368118343165627"></a><a name="p368118343165627"></a><a href="gpio.md#ga6a25a3efddf2301c7b01a7f0af44fb11">GpioValue</a> { <a href="gpio.md#gga6a25a3efddf2301c7b01a7f0af44fb11aff32e096d7022208ae0dc00c95bd8e08">GPIO_VAL_LOW</a> = 0, <a href="gpio.md#gga6a25a3efddf2301c7b01a7f0af44fb11a9b9c172b01ce33bb20764c8dd5c7835f">GPIO_VAL_HIGH</a> = 1, <a href="gpio.md#gga6a25a3efddf2301c7b01a7f0af44fb11a6f009070245b6c7d3b48e990b2cc133a">GPIO_VAL_ERR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1333265906165627"><a name="p1333265906165627"></a><a name="p1333265906165627"></a>Enumerates GPIO level values. </p>
</td>
</tr>
<tr id="row937571809165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107359730165627"><a name="p107359730165627"></a><a name="p107359730165627"></a><a href="gpio.md#ga71f27d3ba7ca04d9448199fca38ae19d">GpioDirType</a> { <a href="gpio.md#gga71f27d3ba7ca04d9448199fca38ae19da3881053acb92aad7798425cdbb565fff">GPIO_DIR_IN</a> = 0, <a href="gpio.md#gga71f27d3ba7ca04d9448199fca38ae19da73c68266253638e2246dda97a0d65d91">GPIO_DIR_OUT</a> = 1, <a href="gpio.md#gga71f27d3ba7ca04d9448199fca38ae19da13b9029a753d3c4a2fad6f863f5161bd">GPIO_DIR_ERR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090080047165627"><a name="p1090080047165627"></a><a name="p1090080047165627"></a>Enumerates GPIO directions. </p>
</td>
</tr>
<tr id="row36782057165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949851548165627"><a name="p1949851548165627"></a><a name="p1949851548165627"></a><a href="gpio.md#ga55c74906cd839809c65a2291ce19e71a">GpioIrqType</a> {   <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aa40ed077c119ad44296a7ac1225fc972f">GPIO_IRQ_TRIGGER_NONE</a> = OSAL_IRQF_TRIGGER_NONE, <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aa5a430b37575029938aef1c7dbd6f250f">GPIO_IRQ_TRIGGER_RISING</a> = OSAL_IRQF_TRIGGER_RISING, <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aae7f7ea98de573e579df8b8285d9f702b">GPIO_IRQ_TRIGGER_FALLING</a> = OSAL_IRQF_TRIGGER_FALLING, <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aaa4c97595a61dd70d0ffa897ad8360a2c">GPIO_IRQ_TRIGGER_HIGH</a> = OSAL_IRQF_TRIGGER_HIGH,   <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aa6ef14795012fbe7f49dbe4632fe27f13">GPIO_IRQ_TRIGGER_LOW</a> = OSAL_IRQF_TRIGGER_LOW, <a href="gpio.md#gga55c74906cd839809c65a2291ce19e71aa61e24a0c48897272a7feaf5ffb8888aa">GPIO_IRQ_USING_THREAD</a> = (0x1 &lt;&lt; 8) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514673092165627"><a name="p1514673092165627"></a><a name="p1514673092165627"></a>Enumerates GPIO irq types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table438441346165627"></a>
<table><thead align="left"><tr id="row1699578311165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1245983615165627"><a name="p1245983615165627"></a><a name="p1245983615165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1280609058165627"><a name="p1280609058165627"></a><a name="p1280609058165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2032839281165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p851183550165627"><a name="p851183550165627"></a><a name="p851183550165627"></a><a href="gpio.md#ga267cb09db1f12ac3f08f847e4141f3c5">GpioRead</a> (uint16_t gpio, uint16_t *val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118065701165627"><a name="p2118065701165627"></a><a name="p2118065701165627"></a>int32_t </p>
<p id="p1383677726165627"><a name="p1383677726165627"></a><a name="p1383677726165627"></a>Reads the level value of a GPIO pin. </p>
</td>
</tr>
<tr id="row2092888972165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p461656783165627"><a name="p461656783165627"></a><a name="p461656783165627"></a><a href="gpio.md#ga7dee8242ba9335b3217635ba64764bc4">GpioWrite</a> (uint16_t gpio, uint16_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p910352462165627"><a name="p910352462165627"></a><a name="p910352462165627"></a>int32_t </p>
<p id="p910263908165627"><a name="p910263908165627"></a><a name="p910263908165627"></a>Writes the level value for a GPIO pin. </p>
</td>
</tr>
<tr id="row342037523165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1591150357165627"><a name="p1591150357165627"></a><a name="p1591150357165627"></a><a href="gpio.md#ga5c628216d209fa76c69eca69856bc0ae">GpioSetDir</a> (uint16_t gpio, uint16_t dir)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573979553165627"><a name="p1573979553165627"></a><a name="p1573979553165627"></a>int32_t </p>
<p id="p1005107869165627"><a name="p1005107869165627"></a><a name="p1005107869165627"></a>Sets the input/output direction for a GPIO pin. </p>
</td>
</tr>
<tr id="row42396618165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653173781165627"><a name="p653173781165627"></a><a name="p653173781165627"></a><a href="gpio.md#ga6eb1536930b7ec5e263667ba30dfc6fb">GpioGetDir</a> (uint16_t gpio, uint16_t *dir)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145706587165627"><a name="p145706587165627"></a><a name="p145706587165627"></a>int32_t </p>
<p id="p1443798384165627"><a name="p1443798384165627"></a><a name="p1443798384165627"></a>Obtains the input/output direction of a GPIO pin. </p>
</td>
</tr>
<tr id="row1077543610165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461787821165627"><a name="p1461787821165627"></a><a name="p1461787821165627"></a><a href="gpio.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e">GpioSetIrq</a> (uint16_t gpio, uint16_t mode, <a href="gpio.md#ga8f3b7d0f0aaa1da8117781efe4b1670e">GpioIrqFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795893900165627"><a name="p795893900165627"></a><a name="p795893900165627"></a>int32_t </p>
<p id="p1394270521165627"><a name="p1394270521165627"></a><a name="p1394270521165627"></a>Sets the ISR function for a GPIO pin. </p>
</td>
</tr>
<tr id="row74047040165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408516826165627"><a name="p408516826165627"></a><a name="p408516826165627"></a><a href="gpio.md#ga0e417971d72956f64a3160525c2be19f">GpioUnSetIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1842323518165627"><a name="p1842323518165627"></a><a name="p1842323518165627"></a>int32_t </p>
<p id="p1463855634165627"><a name="p1463855634165627"></a><a name="p1463855634165627"></a>Cancels the setting of the ISR function for a GPIO pin. </p>
</td>
</tr>
<tr id="row671508552165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395453591165627"><a name="p1395453591165627"></a><a name="p1395453591165627"></a><a href="gpio.md#gafcf00796a949245d665e672ae0294aee">GpioEnableIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230055709165627"><a name="p1230055709165627"></a><a name="p1230055709165627"></a>int32_t </p>
<p id="p1387704037165627"><a name="p1387704037165627"></a><a name="p1387704037165627"></a>Enables a GPIO pin interrupt. </p>
</td>
</tr>
<tr id="row2836940165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313479786165627"><a name="p313479786165627"></a><a name="p313479786165627"></a><a href="gpio.md#gafa01dc510f26d5aff102d72679920929">GpioDisableIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131265760165627"><a name="p131265760165627"></a><a name="p131265760165627"></a>int32_t </p>
<p id="p1923717925165627"><a name="p1923717925165627"></a><a name="p1923717925165627"></a>Disables a GPIO pin interrupt. </p>
</td>
</tr>
</tbody>
</table>

