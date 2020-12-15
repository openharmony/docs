# DeviceResourceAttr<a name="ZH-CN_TOPIC_0000001055078135"></a>

-   [Overview](#section986637668165631)
-   [Summary](#section81282211165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1600458448165631)
-   [Field](#section819926947165631)
-   [name](#aadf17a5e450feda1a2ccb043fc94f907)
-   [next](#ac806f1957696cfecba92937d8b25409f)
-   [value](#a2a9e9a433e8197aaf4863efe468ffdd2)

## **Overview**<a name="section986637668165631"></a>

**Related Modules:**

[DriverConfig](DriverConfig.md)

**Description:**

Defines the attributes of a tree node in the configuration tree. 

The tree node attributes are saved in a linked list. The information about each node in the linked list contains the attribute name, attribute value, and pointer that points to the next attribute. 

## **Summary**<a name="section81282211165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1031450593165631"></a>
<table><thead align="left"><tr id="row708529797165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p547851370165631"><a name="p547851370165631"></a><a name="p547851370165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p441400511165631"><a name="p441400511165631"></a><a name="p441400511165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row257277104165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401869525165631"><a name="p1401869525165631"></a><a name="p1401869525165631"></a><a href="DeviceResourceAttr.md#aadf17a5e450feda1a2ccb043fc94f907">name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145258461165631"><a name="p145258461165631"></a><a name="p145258461165631"></a>const char * </p>
</td>
</tr>
<tr id="row1047349485165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1898443979165631"><a name="p1898443979165631"></a><a name="p1898443979165631"></a><a href="DeviceResourceAttr.md#a2a9e9a433e8197aaf4863efe468ffdd2">value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141593867165631"><a name="p1141593867165631"></a><a name="p1141593867165631"></a>const char * </p>
</td>
</tr>
<tr id="row1613778270165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462350339165631"><a name="p1462350339165631"></a><a name="p1462350339165631"></a><a href="DeviceResourceAttr.md#ac806f1957696cfecba92937d8b25409f">next</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764513601165631"><a name="p1764513601165631"></a><a name="p1764513601165631"></a>struct <a href="DeviceResourceAttr.md">DeviceResourceAttr</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1600458448165631"></a>

## **Field **<a name="section819926947165631"></a>

## name<a name="aadf17a5e450feda1a2ccb043fc94f907"></a>

```
const char* DeviceResourceAttr::name
```

 **Description:**

Pointer to the attribute name 

## next<a name="ac806f1957696cfecba92937d8b25409f"></a>

```
struct [DeviceResourceAttr](DeviceResourceAttr.md)* DeviceResourceAttr::next
```

 **Description:**

Pointer to the next attribute of the node in the configuration tree. 

## value<a name="a2a9e9a433e8197aaf4863efe468ffdd2"></a>

```
const char* DeviceResourceAttr::value
```

 **Description:**

Pointer to the attribute value 

