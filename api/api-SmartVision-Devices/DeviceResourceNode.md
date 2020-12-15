# DeviceResourceNode<a name="ZH-CN_TOPIC_0000001054598157"></a>

-   [Overview](#section165277185165631)
-   [Summary](#section813009472165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1825251284165631)
-   [Field](#section1057845482165631)
-   [attrData](#a7da5b6d00ceb2cd33d881a678bdb262b)
-   [child](#ae6104929f3cd35e811975ada3005fca9)
-   [hashValue](#a133894c208928b8ade08efb53beca314)
-   [name](#a991fdfa13e2af8b63c2506d9ed31fc0b)
-   [parent](#a765c15b3be1bfb1178173e1ed0df4062)
-   [sibling](#a484324bd4df5f2f9998ed0d58222e5ba)

## **Overview**<a name="section165277185165631"></a>

**Related Modules:**

[DriverConfig](DriverConfig.md)

**Description:**

Defines a tree node in the configuration tree. 

The tree node information includes the node name, unique node ID, node attributes, parent node, child nodes, and sibling nodes. 

## **Summary**<a name="section813009472165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2122028449165631"></a>
<table><thead align="left"><tr id="row1391070425165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1557891263165631"><a name="p1557891263165631"></a><a name="p1557891263165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p706303206165631"><a name="p706303206165631"></a><a name="p706303206165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1525208272165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761102812165631"><a name="p761102812165631"></a><a name="p761102812165631"></a><a href="DeviceResourceNode.md#a991fdfa13e2af8b63c2506d9ed31fc0b">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788259059165631"><a name="p1788259059165631"></a><a name="p1788259059165631"></a>const char * </p>
</td>
</tr>
<tr id="row1721887096165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912104342165631"><a name="p912104342165631"></a><a name="p912104342165631"></a><a href="DeviceResourceNode.md#a133894c208928b8ade08efb53beca314">hashValue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318381563165631"><a name="p318381563165631"></a><a name="p318381563165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1707588692165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652955444165631"><a name="p1652955444165631"></a><a name="p1652955444165631"></a><a href="DeviceResourceNode.md#a7da5b6d00ceb2cd33d881a678bdb262b">attrData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535863394165631"><a name="p535863394165631"></a><a name="p535863394165631"></a>struct <a href="DeviceResourceAttr.md">DeviceResourceAttr</a> * </p>
</td>
</tr>
<tr id="row1593778752165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139393402165631"><a name="p2139393402165631"></a><a name="p2139393402165631"></a><a href="DeviceResourceNode.md#a765c15b3be1bfb1178173e1ed0df4062">parent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246106220165631"><a name="p246106220165631"></a><a name="p246106220165631"></a>struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> * </p>
</td>
</tr>
<tr id="row1765923409165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458636910165631"><a name="p1458636910165631"></a><a name="p1458636910165631"></a><a href="DeviceResourceNode.md#ae6104929f3cd35e811975ada3005fca9">child</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466092981165631"><a name="p466092981165631"></a><a name="p466092981165631"></a>struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> * </p>
</td>
</tr>
<tr id="row102512204165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456871295165631"><a name="p456871295165631"></a><a name="p456871295165631"></a><a href="DeviceResourceNode.md#a484324bd4df5f2f9998ed0d58222e5ba">sibling</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858620815165631"><a name="p1858620815165631"></a><a name="p1858620815165631"></a>struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1825251284165631"></a>

## **Field **<a name="section1057845482165631"></a>

## attrData<a name="a7da5b6d00ceb2cd33d881a678bdb262b"></a>

```
struct [DeviceResourceAttr](DeviceResourceAttr.md)* DeviceResourceNode::attrData
```

 **Description:**

Pointer to the node attributes 

## child<a name="ae6104929f3cd35e811975ada3005fca9"></a>

```
struct [DeviceResourceNode](DeviceResourceNode.md)* DeviceResourceNode::child
```

 **Description:**

Pointer to a child node 

## hashValue<a name="a133894c208928b8ade08efb53beca314"></a>

```
uint32_t DeviceResourceNode::hashValue
```

 **Description:**

Unique ID of a node 

## name<a name="a991fdfa13e2af8b63c2506d9ed31fc0b"></a>

```
const char* DeviceResourceNode::name
```

 **Description:**

Pointer to the node name 

## parent<a name="a765c15b3be1bfb1178173e1ed0df4062"></a>

```
struct [DeviceResourceNode](DeviceResourceNode.md)* DeviceResourceNode::parent
```

 **Description:**

Pointer to the parent node 

## sibling<a name="a484324bd4df5f2f9998ed0d58222e5ba"></a>

```
struct [DeviceResourceNode](DeviceResourceNode.md)* DeviceResourceNode::sibling
```

 **Description:**

Pointer to a sibling node 

