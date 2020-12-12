# I2cMsg<a name="ZH-CN_TOPIC_0000001054918161"></a>

-   [Overview](#section1938170583165632)
-   [Summary](#section208689179165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1058882627165632)
-   [Field](#section1489406453165632)
-   [addr](#a8f9fae2a615957552b2c409b868e91cd)
-   [buf](#a7b32a5e6322edb302cea3faf698953a0)
-   [flags](#adfecd4720506fef0a87d0abd45d1f201)
-   [len](#aa3951709930c577af6f5ee4cf53b6dad)

## **Overview**<a name="section1938170583165632"></a>

**Related Modules:**

[I2C](I2C.md)

**Description:**

Defines the I2C transfer message used during custom transfers. 

Attention
:   This structure does not limit the data transfer length specified by  **len**. The specific I2C controller determines the maximum length allowed. The device address  **addr**  indicates the original device address and does not need to contain the read/write flag bit.

**Since:**

1.0

## **Summary**<a name="section208689179165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1458877587165632"></a>
<table><thead align="left"><tr id="row2057743372165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p95045078165632"><a name="p95045078165632"></a><a name="p95045078165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1248472528165632"><a name="p1248472528165632"></a><a name="p1248472528165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row447359425165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450586820165632"><a name="p1450586820165632"></a><a name="p1450586820165632"></a><a href="I2cMsg.md#a8f9fae2a615957552b2c409b868e91cd">addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090500892165632"><a name="p1090500892165632"></a><a name="p1090500892165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1963720075165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770009504165632"><a name="p770009504165632"></a><a name="p770009504165632"></a><a href="I2cMsg.md#a7b32a5e6322edb302cea3faf698953a0">buf</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665199170165632"><a name="p665199170165632"></a><a name="p665199170165632"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1733904926165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396903097165632"><a name="p396903097165632"></a><a name="p396903097165632"></a><a href="I2cMsg.md#aa3951709930c577af6f5ee4cf53b6dad">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126495860165632"><a name="p1126495860165632"></a><a name="p1126495860165632"></a>uint16_t </p>
</td>
</tr>
<tr id="row1266233869165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596595734165632"><a name="p1596595734165632"></a><a name="p1596595734165632"></a><a href="I2cMsg.md#adfecd4720506fef0a87d0abd45d1f201">flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621837128165632"><a name="p1621837128165632"></a><a name="p1621837128165632"></a>uint16_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1058882627165632"></a>

## **Field **<a name="section1489406453165632"></a>

## addr<a name="a8f9fae2a615957552b2c409b868e91cd"></a>

```
uint16_t I2cMsg::addr
```

 **Description:**

Address of the I2C device 

## buf<a name="a7b32a5e6322edb302cea3faf698953a0"></a>

```
uint8_t* I2cMsg::buf
```

 **Description:**

Address of the buffer for storing transferred data 

## flags<a name="adfecd4720506fef0a87d0abd45d1f201"></a>

```
uint16_t I2cMsg::flags
```

## len<a name="aa3951709930c577af6f5ee4cf53b6dad"></a>

```
uint16_t I2cMsg::len
```

 **Description:**

Length of the transferred data 

