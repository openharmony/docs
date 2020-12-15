# GPIO<a name="ZH-CN_TOPIC_0000001054918103"></a>

-   [Overview](#section1158330629165623)
-   [Summary](#section1514023225165623)
-   [Files](#files)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section600064076165623)
-   [Typedef](#section550945231165623)
-   [GpioIrqFunc](#ga8f3b7d0f0aaa1da8117781efe4b1670e)
-   [Enumeration Type](#section1554549735165623)
-   [GpioDirType](#ga71f27d3ba7ca04d9448199fca38ae19d)
-   [GpioIrqType](#ga55c74906cd839809c65a2291ce19e71a)
-   [GpioValue](#ga6a25a3efddf2301c7b01a7f0af44fb11)
-   [Function](#section821997884165623)
-   [GpioDisableIrq\(\)](#gafa01dc510f26d5aff102d72679920929)
-   [GpioEnableIrq\(\)](#gafcf00796a949245d665e672ae0294aee)
-   [GpioGetDir\(\)](#ga6eb1536930b7ec5e263667ba30dfc6fb)
-   [GpioRead\(\)](#ga267cb09db1f12ac3f08f847e4141f3c5)
-   [GpioSetDir\(\)](#ga5c628216d209fa76c69eca69856bc0ae)
-   [GpioSetIrq\(\)](#ga6ea5d16b8d73cb74e36d367f05cb7f6e)
-   [GpioUnSetIrq\(\)](#ga0e417971d72956f64a3160525c2be19f)
-   [GpioWrite\(\)](#ga7dee8242ba9335b3217635ba64764bc4)

## **Overview**<a name="section1158330629165623"></a>

**Description:**

Provides standard general-purpose input/output \(GPIO\) interfaces for driver development. 

You can use this module to perform operations on a GPIO pin, including setting the input/output direction, reading/writing the level value, and setting the interrupt service routine \(ISR\) function.

**Since:**

1.0

## **Summary**<a name="section1514023225165623"></a>

## Files<a name="files"></a>

<a name="table1604519262165623"></a>
<table><thead align="left"><tr id="row1949206811165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1404010496165623"><a name="p1404010496165623"></a><a name="p1404010496165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1439800207165623"><a name="p1439800207165623"></a><a name="p1439800207165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1259238319165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703490650165623"><a name="p1703490650165623"></a><a name="p1703490650165623"></a><a href="gpio_if-h.md">gpio_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p534480037165623"><a name="p534480037165623"></a><a name="p534480037165623"></a>Declares the standard GPIO interface functions. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table480359531165623"></a>
<table><thead align="left"><tr id="row615367633165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1927950152165623"><a name="p1927950152165623"></a><a name="p1927950152165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1045265003165623"><a name="p1045265003165623"></a><a name="p1045265003165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row404767026165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610809837165623"><a name="p610809837165623"></a><a name="p610809837165623"></a><a href="GPIO.md#ga8f3b7d0f0aaa1da8117781efe4b1670e">GpioIrqFunc</a>) (uint16_t gpio, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2099138959165623"><a name="p2099138959165623"></a><a name="p2099138959165623"></a>typedef int32_t(* </p>
<p id="p1002748649165623"><a name="p1002748649165623"></a><a name="p1002748649165623"></a>Defines the function type of a GPIO interrupt service routine (ISR). </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table310846131165623"></a>
<table><thead align="left"><tr id="row701973704165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1165659542165623"><a name="p1165659542165623"></a><a name="p1165659542165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p215624955165623"><a name="p215624955165623"></a><a name="p215624955165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row429067196165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p829254794165623"><a name="p829254794165623"></a><a name="p829254794165623"></a><a href="GPIO.md#ga6a25a3efddf2301c7b01a7f0af44fb11">GpioValue</a> { <a href="GPIO.md#gga6a25a3efddf2301c7b01a7f0af44fb11aff32e096d7022208ae0dc00c95bd8e08">GPIO_VAL_LOW</a> = 0, <a href="GPIO.md#gga6a25a3efddf2301c7b01a7f0af44fb11a9b9c172b01ce33bb20764c8dd5c7835f">GPIO_VAL_HIGH</a> = 1, <a href="GPIO.md#gga6a25a3efddf2301c7b01a7f0af44fb11a6f009070245b6c7d3b48e990b2cc133a">GPIO_VAL_ERR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608647973165623"><a name="p608647973165623"></a><a name="p608647973165623"></a>Enumerates GPIO level values. </p>
</td>
</tr>
<tr id="row1283868497165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p452232923165623"><a name="p452232923165623"></a><a name="p452232923165623"></a><a href="GPIO.md#ga71f27d3ba7ca04d9448199fca38ae19d">GpioDirType</a> { <a href="GPIO.md#gga71f27d3ba7ca04d9448199fca38ae19da3881053acb92aad7798425cdbb565fff">GPIO_DIR_IN</a> = 0, <a href="GPIO.md#gga71f27d3ba7ca04d9448199fca38ae19da73c68266253638e2246dda97a0d65d91">GPIO_DIR_OUT</a> = 1, <a href="GPIO.md#gga71f27d3ba7ca04d9448199fca38ae19da13b9029a753d3c4a2fad6f863f5161bd">GPIO_DIR_ERR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779937046165623"><a name="p1779937046165623"></a><a name="p1779937046165623"></a>Enumerates GPIO directions. </p>
</td>
</tr>
<tr id="row294765129165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1673971268165623"><a name="p1673971268165623"></a><a name="p1673971268165623"></a><a href="GPIO.md#ga55c74906cd839809c65a2291ce19e71a">GpioIrqType</a> {   <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aa40ed077c119ad44296a7ac1225fc972f">GPIO_IRQ_TRIGGER_NONE</a> = OSAL_IRQF_TRIGGER_NONE, <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aa5a430b37575029938aef1c7dbd6f250f">GPIO_IRQ_TRIGGER_RISING</a> = OSAL_IRQF_TRIGGER_RISING, <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aae7f7ea98de573e579df8b8285d9f702b">GPIO_IRQ_TRIGGER_FALLING</a> = OSAL_IRQF_TRIGGER_FALLING, <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aaa4c97595a61dd70d0ffa897ad8360a2c">GPIO_IRQ_TRIGGER_HIGH</a> = OSAL_IRQF_TRIGGER_HIGH,   <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aa6ef14795012fbe7f49dbe4632fe27f13">GPIO_IRQ_TRIGGER_LOW</a> = OSAL_IRQF_TRIGGER_LOW, <a href="GPIO.md#gga55c74906cd839809c65a2291ce19e71aa61e24a0c48897272a7feaf5ffb8888aa">GPIO_IRQ_USING_THREAD</a> = (0x1 &lt;&lt; 8) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911303333165623"><a name="p911303333165623"></a><a name="p911303333165623"></a>Enumerates GPIO irq types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table512786091165623"></a>
<table><thead align="left"><tr id="row953640091165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2091763721165623"><a name="p2091763721165623"></a><a name="p2091763721165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1526218936165623"><a name="p1526218936165623"></a><a name="p1526218936165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1233935211165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p548165479165623"><a name="p548165479165623"></a><a name="p548165479165623"></a><a href="GPIO.md#ga267cb09db1f12ac3f08f847e4141f3c5">GpioRead</a> (uint16_t gpio, uint16_t *val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847797235165623"><a name="p847797235165623"></a><a name="p847797235165623"></a>int32_t </p>
<p id="p2134476326165623"><a name="p2134476326165623"></a><a name="p2134476326165623"></a>Reads the level value of a GPIO pin. </p>
</td>
</tr>
<tr id="row373642245165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116171013165623"><a name="p2116171013165623"></a><a name="p2116171013165623"></a><a href="GPIO.md#ga7dee8242ba9335b3217635ba64764bc4">GpioWrite</a> (uint16_t gpio, uint16_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876673753165623"><a name="p1876673753165623"></a><a name="p1876673753165623"></a>int32_t </p>
<p id="p670873586165623"><a name="p670873586165623"></a><a name="p670873586165623"></a>Writes the level value for a GPIO pin. </p>
</td>
</tr>
<tr id="row1592776320165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1083941897165623"><a name="p1083941897165623"></a><a name="p1083941897165623"></a><a href="GPIO.md#ga5c628216d209fa76c69eca69856bc0ae">GpioSetDir</a> (uint16_t gpio, uint16_t dir)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851077279165623"><a name="p851077279165623"></a><a name="p851077279165623"></a>int32_t </p>
<p id="p869461813165623"><a name="p869461813165623"></a><a name="p869461813165623"></a>Sets the input/output direction for a GPIO pin. </p>
</td>
</tr>
<tr id="row1841068211165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458923463165623"><a name="p1458923463165623"></a><a name="p1458923463165623"></a><a href="GPIO.md#ga6eb1536930b7ec5e263667ba30dfc6fb">GpioGetDir</a> (uint16_t gpio, uint16_t *dir)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137255836165623"><a name="p137255836165623"></a><a name="p137255836165623"></a>int32_t </p>
<p id="p841615726165623"><a name="p841615726165623"></a><a name="p841615726165623"></a>Obtains the input/output direction of a GPIO pin. </p>
</td>
</tr>
<tr id="row373142432165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885233925165623"><a name="p1885233925165623"></a><a name="p1885233925165623"></a><a href="GPIO.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e">GpioSetIrq</a> (uint16_t gpio, uint16_t mode, <a href="GPIO.md#ga8f3b7d0f0aaa1da8117781efe4b1670e">GpioIrqFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973509438165623"><a name="p973509438165623"></a><a name="p973509438165623"></a>int32_t </p>
<p id="p1923892432165623"><a name="p1923892432165623"></a><a name="p1923892432165623"></a>Sets the ISR function for a GPIO pin. </p>
</td>
</tr>
<tr id="row1524496051165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1949248632165623"><a name="p1949248632165623"></a><a name="p1949248632165623"></a><a href="GPIO.md#ga0e417971d72956f64a3160525c2be19f">GpioUnSetIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440621659165623"><a name="p1440621659165623"></a><a name="p1440621659165623"></a>int32_t </p>
<p id="p1902175129165623"><a name="p1902175129165623"></a><a name="p1902175129165623"></a>Cancels the setting of the ISR function for a GPIO pin. </p>
</td>
</tr>
<tr id="row1318349217165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319126813165623"><a name="p1319126813165623"></a><a name="p1319126813165623"></a><a href="GPIO.md#gafcf00796a949245d665e672ae0294aee">GpioEnableIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1887811791165623"><a name="p1887811791165623"></a><a name="p1887811791165623"></a>int32_t </p>
<p id="p1656825317165623"><a name="p1656825317165623"></a><a name="p1656825317165623"></a>Enables a GPIO pin interrupt. </p>
</td>
</tr>
<tr id="row1987912394165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993452050165623"><a name="p1993452050165623"></a><a name="p1993452050165623"></a><a href="GPIO.md#gafa01dc510f26d5aff102d72679920929">GpioDisableIrq</a> (uint16_t gpio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393515501165623"><a name="p1393515501165623"></a><a name="p1393515501165623"></a>int32_t </p>
<p id="p645665825165623"><a name="p645665825165623"></a><a name="p645665825165623"></a>Disables a GPIO pin interrupt. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section600064076165623"></a>

## **Typedef **<a name="section550945231165623"></a>

## GpioIrqFunc<a name="ga8f3b7d0f0aaa1da8117781efe4b1670e"></a>

```
typedef int32_t(* GpioIrqFunc) (uint16_t gpio, void *data)
```

 **Description:**

Defines the function type of a GPIO interrupt service routine \(ISR\). 

This function is used when you call  [GpioSetIrq](GPIO.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e)  to register the ISR for a GPIO pin.

**Parameters:**

<a name="table919699839165623"></a>
<table><thead align="left"><tr id="row464169926165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1554179559165623"><a name="p1554179559165623"></a><a name="p1554179559165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p151146168165623"><a name="p151146168165623"></a><a name="p151146168165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1596154256165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO number of the ISR. </td>
</tr>
<tr id="row1839370497165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the private data passed to this ISR (The data is specified when the ISR is registered).</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the ISR function type is successfully defined; returns a negative value otherwise. 

**See also:**

[GpioSetIrq](GPIO.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e) 

## **Enumeration Type **<a name="section1554549735165623"></a>

## GpioDirType<a name="ga71f27d3ba7ca04d9448199fca38ae19d"></a>

```
enum [GpioDirType](GPIO.md#ga71f27d3ba7ca04d9448199fca38ae19d)
```

 **Description:**

Enumerates GPIO directions. 

<a name="table789832173165623"></a>
<table><thead align="left"><tr id="row1789214218165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1017891118165623"><a name="p1017891118165623"></a><a name="p1017891118165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p661357261165623"><a name="p661357261165623"></a><a name="p661357261165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row936370499165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga71f27d3ba7ca04d9448199fca38ae19da3881053acb92aad7798425cdbb565fff"><a name="gga71f27d3ba7ca04d9448199fca38ae19da3881053acb92aad7798425cdbb565fff"></a><a name="gga71f27d3ba7ca04d9448199fca38ae19da3881053acb92aad7798425cdbb565fff"></a></strong>GPIO_DIR_IN </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p207348823165623"><a name="p207348823165623"></a><a name="p207348823165623"></a>Input direction </p>
 </td>
</tr>
<tr id="row1587551862165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga71f27d3ba7ca04d9448199fca38ae19da73c68266253638e2246dda97a0d65d91"><a name="gga71f27d3ba7ca04d9448199fca38ae19da73c68266253638e2246dda97a0d65d91"></a><a name="gga71f27d3ba7ca04d9448199fca38ae19da73c68266253638e2246dda97a0d65d91"></a></strong>GPIO_DIR_OUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1802408692165623"><a name="p1802408692165623"></a><a name="p1802408692165623"></a>Output direction </p>
 </td>
</tr>
<tr id="row1531645997165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga71f27d3ba7ca04d9448199fca38ae19da13b9029a753d3c4a2fad6f863f5161bd"><a name="gga71f27d3ba7ca04d9448199fca38ae19da13b9029a753d3c4a2fad6f863f5161bd"></a><a name="gga71f27d3ba7ca04d9448199fca38ae19da13b9029a753d3c4a2fad6f863f5161bd"></a></strong>GPIO_DIR_ERR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108045670165623"><a name="p108045670165623"></a><a name="p108045670165623"></a>Invalid direction </p>
 </td>
</tr>
</tbody>
</table>

## GpioIrqType<a name="ga55c74906cd839809c65a2291ce19e71a"></a>

```
enum [GpioIrqType](GPIO.md#ga55c74906cd839809c65a2291ce19e71a)
```

 **Description:**

Enumerates GPIO irq types. 

<a name="table978142608165623"></a>
<table><thead align="left"><tr id="row60372241165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1009419042165623"><a name="p1009419042165623"></a><a name="p1009419042165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1542392922165623"><a name="p1542392922165623"></a><a name="p1542392922165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row634382043165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aa40ed077c119ad44296a7ac1225fc972f"><a name="gga55c74906cd839809c65a2291ce19e71aa40ed077c119ad44296a7ac1225fc972f"></a><a name="gga55c74906cd839809c65a2291ce19e71aa40ed077c119ad44296a7ac1225fc972f"></a></strong>GPIO_IRQ_TRIGGER_NONE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108722025165623"><a name="p1108722025165623"></a><a name="p1108722025165623"></a>Trigger is not set </p>
 </td>
</tr>
<tr id="row1873609935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aa5a430b37575029938aef1c7dbd6f250f"><a name="gga55c74906cd839809c65a2291ce19e71aa5a430b37575029938aef1c7dbd6f250f"></a><a name="gga55c74906cd839809c65a2291ce19e71aa5a430b37575029938aef1c7dbd6f250f"></a></strong>GPIO_IRQ_TRIGGER_RISING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625675932165623"><a name="p625675932165623"></a><a name="p625675932165623"></a>Rising edge triggered </p>
 </td>
</tr>
<tr id="row511891190165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aae7f7ea98de573e579df8b8285d9f702b"><a name="gga55c74906cd839809c65a2291ce19e71aae7f7ea98de573e579df8b8285d9f702b"></a><a name="gga55c74906cd839809c65a2291ce19e71aae7f7ea98de573e579df8b8285d9f702b"></a></strong>GPIO_IRQ_TRIGGER_FALLING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824013160165623"><a name="p1824013160165623"></a><a name="p1824013160165623"></a>Falling edge triggered </p>
 </td>
</tr>
<tr id="row2140257285165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aaa4c97595a61dd70d0ffa897ad8360a2c"><a name="gga55c74906cd839809c65a2291ce19e71aaa4c97595a61dd70d0ffa897ad8360a2c"></a><a name="gga55c74906cd839809c65a2291ce19e71aaa4c97595a61dd70d0ffa897ad8360a2c"></a></strong>GPIO_IRQ_TRIGGER_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488582897165623"><a name="p1488582897165623"></a><a name="p1488582897165623"></a>High-level triggered </p>
 </td>
</tr>
<tr id="row1160713830165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aa6ef14795012fbe7f49dbe4632fe27f13"><a name="gga55c74906cd839809c65a2291ce19e71aa6ef14795012fbe7f49dbe4632fe27f13"></a><a name="gga55c74906cd839809c65a2291ce19e71aa6ef14795012fbe7f49dbe4632fe27f13"></a></strong>GPIO_IRQ_TRIGGER_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901210032165623"><a name="p1901210032165623"></a><a name="p1901210032165623"></a>Low-level triggered </p>
 </td>
</tr>
<tr id="row2014687282165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga55c74906cd839809c65a2291ce19e71aa61e24a0c48897272a7feaf5ffb8888aa"><a name="gga55c74906cd839809c65a2291ce19e71aa61e24a0c48897272a7feaf5ffb8888aa"></a><a name="gga55c74906cd839809c65a2291ce19e71aa61e24a0c48897272a7feaf5ffb8888aa"></a></strong>GPIO_IRQ_USING_THREAD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p685740778165623"><a name="p685740778165623"></a><a name="p685740778165623"></a>execute interrupt service routine in thread context </p>
 </td>
</tr>
</tbody>
</table>

## GpioValue<a name="ga6a25a3efddf2301c7b01a7f0af44fb11"></a>

```
enum [GpioValue](GPIO.md#ga6a25a3efddf2301c7b01a7f0af44fb11)
```

 **Description:**

Enumerates GPIO level values. 

<a name="table305844337165623"></a>
<table><thead align="left"><tr id="row1959337406165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1691455859165623"><a name="p1691455859165623"></a><a name="p1691455859165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p461756381165623"><a name="p461756381165623"></a><a name="p461756381165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row158303531165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6a25a3efddf2301c7b01a7f0af44fb11aff32e096d7022208ae0dc00c95bd8e08"><a name="gga6a25a3efddf2301c7b01a7f0af44fb11aff32e096d7022208ae0dc00c95bd8e08"></a><a name="gga6a25a3efddf2301c7b01a7f0af44fb11aff32e096d7022208ae0dc00c95bd8e08"></a></strong>GPIO_VAL_LOW </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p877003504165623"><a name="p877003504165623"></a><a name="p877003504165623"></a>Low GPIO level </p>
 </td>
</tr>
<tr id="row324475750165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6a25a3efddf2301c7b01a7f0af44fb11a9b9c172b01ce33bb20764c8dd5c7835f"><a name="gga6a25a3efddf2301c7b01a7f0af44fb11a9b9c172b01ce33bb20764c8dd5c7835f"></a><a name="gga6a25a3efddf2301c7b01a7f0af44fb11a9b9c172b01ce33bb20764c8dd5c7835f"></a></strong>GPIO_VAL_HIGH </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819641054165623"><a name="p1819641054165623"></a><a name="p1819641054165623"></a>High GPIO level </p>
 </td>
</tr>
<tr id="row565056843165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga6a25a3efddf2301c7b01a7f0af44fb11a6f009070245b6c7d3b48e990b2cc133a"><a name="gga6a25a3efddf2301c7b01a7f0af44fb11a6f009070245b6c7d3b48e990b2cc133a"></a><a name="gga6a25a3efddf2301c7b01a7f0af44fb11a6f009070245b6c7d3b48e990b2cc133a"></a></strong>GPIO_VAL_ERR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826101302165623"><a name="p826101302165623"></a><a name="p826101302165623"></a>Invalid GPIO level </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section821997884165623"></a>

## GpioDisableIrq\(\)<a name="gafa01dc510f26d5aff102d72679920929"></a>

```
int32_t GpioDisableIrq (uint16_t gpio)
```

 **Description:**

Disables a GPIO pin interrupt. 

You can call this function when you need to temporarily mask a GPIO pin interrupt or cancel an ISR function.

**Parameters:**

<a name="table2094585787165623"></a>
<table><thead align="left"><tr id="row322756561165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p75633648165623"><a name="p75633648165623"></a><a name="p75633648165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1932587886165623"><a name="p1932587886165623"></a><a name="p1932587886165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row786119690165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin interrupt is successfully disabled; returns a negative value otherwise. 

## GpioEnableIrq\(\)<a name="gafcf00796a949245d665e672ae0294aee"></a>

```
int32_t GpioEnableIrq (uint16_t gpio)
```

 **Description:**

Enables a GPIO pin interrupt. 

Before enabling the interrupt, you must call  [GpioSetIrq](GPIO.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e)  to set the ISR function for the GPIO pin.

**Parameters:**

<a name="table744449451165623"></a>
<table><thead align="left"><tr id="row1266105638165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p117863930165623"><a name="p117863930165623"></a><a name="p117863930165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1447064163165623"><a name="p1447064163165623"></a><a name="p1447064163165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1946678047165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin interrupt is successfully enabled; returns a negative value otherwise. 

## GpioGetDir\(\)<a name="ga6eb1536930b7ec5e263667ba30dfc6fb"></a>

```
int32_t GpioGetDir (uint16_t gpio, uint16_t * dir )
```

 **Description:**

Obtains the input/output direction of a GPIO pin. 

**Parameters:**

<a name="table1615608974165623"></a>
<table><thead align="left"><tr id="row410750254165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p365552969165623"><a name="p365552969165623"></a><a name="p365552969165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p82358904165623"><a name="p82358904165623"></a><a name="p82358904165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row768263554165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number. </td>
</tr>
<tr id="row1292874845165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dir</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained input/output direction. For details, see <a href="GPIO.md#ga71f27d3ba7ca04d9448199fca38ae19d">GpioDirType</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin direction is successfully obtained; returns a negative value otherwise. 

## GpioRead\(\)<a name="ga267cb09db1f12ac3f08f847e4141f3c5"></a>

```
int32_t GpioRead (uint16_t gpio, uint16_t * val )
```

 **Description:**

Reads the level value of a GPIO pin. 

Before using this function, you need to call  [GpioSetDir](GPIO.md#ga5c628216d209fa76c69eca69856bc0ae)  to set the GPIO pin direction to input.

**Parameters:**

<a name="table1130563677165623"></a>
<table><thead align="left"><tr id="row654977014165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1139860132165623"><a name="p1139860132165623"></a><a name="p1139860132165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p613251053165623"><a name="p613251053165623"></a><a name="p613251053165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row195112107165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number. </td>
</tr>
<tr id="row1220359176165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the read level value. For details, see <a href="GPIO.md#ga6a25a3efddf2301c7b01a7f0af44fb11">GpioValue</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin level value is successfully read; returns a negative value otherwise. 

## GpioSetDir\(\)<a name="ga5c628216d209fa76c69eca69856bc0ae"></a>

```
int32_t GpioSetDir (uint16_t gpio, uint16_t dir )
```

 **Description:**

Sets the input/output direction for a GPIO pin. 

Generally, you can set the direction to input when external level signals need to be read, and set the direction to output when the level signals need to be sent externally.

**Parameters:**

<a name="table1959192129165623"></a>
<table><thead align="left"><tr id="row1473340134165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1615534088165623"><a name="p1615534088165623"></a><a name="p1615534088165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p648304434165623"><a name="p648304434165623"></a><a name="p648304434165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row384842911165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number. </td>
</tr>
<tr id="row2087365909165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dir</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the direction to set. For details, see <a href="GPIO.md#ga71f27d3ba7ca04d9448199fca38ae19d">GpioDirType</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin direction is successfully set; returns a negative value otherwise. 

## GpioSetIrq\(\)<a name="ga6ea5d16b8d73cb74e36d367f05cb7f6e"></a>

```
int32_t GpioSetIrq (uint16_t gpio, uint16_t mode, [GpioIrqFunc](GPIO.md#ga8f3b7d0f0aaa1da8117781efe4b1670e) func, void * arg )
```

 **Description:**

Sets the ISR function for a GPIO pin. 

Before using a GPIO pin as an interrupt, you must call this function to set an ISR function for this GPIO pin, including the ISR parameters and the interrupt trigger mode. After the setting is successful, you also need to call  [GpioEnableIrq](GPIO.md#gafcf00796a949245d665e672ae0294aee)  to enable the interrupt, so that the ISR function can respond correctly.

**Parameters:**

<a name="table477453093165623"></a>
<table><thead align="left"><tr id="row1387239059165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p642594077165623"><a name="p642594077165623"></a><a name="p642594077165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p822234596165623"><a name="p822234596165623"></a><a name="p822234596165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2013701945165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number. </td>
</tr>
<tr id="row1983206860165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">mode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the interrupt trigger mode. For details, see <a href="OSAL.md#gga78cd126b10424753db6f39f9b72ea124ab98297946a624d99a3fad6adac899f2c">OSAL_IRQF_TRIGGER_RISING</a>. </td>
</tr>
<tr id="row839614529165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ISR function to set, which is specified by <a href="GPIO.md#ga8f3b7d0f0aaa1da8117781efe4b1670e">GpioIrqFunc</a>. </td>
</tr>
<tr id="row865777513165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the parameters passed to the ISR function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the ISR function of the GPIO pin is successfully set; returns a negative value otherwise. 

## GpioUnSetIrq\(\)<a name="ga0e417971d72956f64a3160525c2be19f"></a>

```
int32_t GpioUnSetIrq (uint16_t gpio)
```

 **Description:**

Cancels the setting of the ISR function for a GPIO pin. 

If you do not need the GPIO pin as an interrupt, call this function to cancel the ISR function set via  [GpioSetIrq](GPIO.md#ga6ea5d16b8d73cb74e36d367f05cb7f6e). Since this ISR function is no longer valid, you are advised to use  [GpioDisableIrq](GPIO.md#gafa01dc510f26d5aff102d72679920929)  to disable the GPIO pin interrupt.

**Parameters:**

<a name="table2124248926165623"></a>
<table><thead align="left"><tr id="row527146461165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p636189098165623"><a name="p636189098165623"></a><a name="p636189098165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1137427225165623"><a name="p1137427225165623"></a><a name="p1137427225165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1231932680165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the ISR function of the GPIO pin is successfully cancelled; returns a negative value otherwise. 

## GpioWrite\(\)<a name="ga7dee8242ba9335b3217635ba64764bc4"></a>

```
int32_t GpioWrite (uint16_t gpio, uint16_t val )
```

 **Description:**

Writes the level value for a GPIO pin. 

Before using this function, you need to call  [GpioSetDir](GPIO.md#ga5c628216d209fa76c69eca69856bc0ae)  to set the GPIO pin direction to output.

**Parameters:**

<a name="table766686514165623"></a>
<table><thead align="left"><tr id="row748520524165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1852219146165623"><a name="p1852219146165623"></a><a name="p1852219146165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1655305406165623"><a name="p1655305406165623"></a><a name="p1655305406165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row46313667165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">gpio</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the GPIO pin number. </td>
</tr>
<tr id="row488716490165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">val</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the level value to be written. For details, see <a href="GPIO.md#ga6a25a3efddf2301c7b01a7f0af44fb11">GpioValue</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the GPIO pin level value is successfully written; returns a negative value otherwise. 

