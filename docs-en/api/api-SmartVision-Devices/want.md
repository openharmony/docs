# Want<a name="EN-US_TOPIC_0000001055039558"></a>

-   [Overview](#section2061577705165636)
-   [Summary](#section688560146165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section566798983165636)
-   [Field](#section1651066855165636)
-   [data](#a47c0d5e886bb5cb0b7c9fdb32fa903fa)
-   [dataLength](#a9175a7f7f1c7d84e11042b2d17a2d3f4)
-   [element](#a0ca9d0b3a71d92dec9a14468787afbf8)
-   [sid](#a08a6438e5a2630cbefde052834869b3c)

## **Overview**<a name="section2061577705165636"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Defines the abstract description of an operation, including information about the ability and the extra data to carry. 

## **Summary**<a name="section688560146165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table774563067165636"></a>
<table><thead align="left"><tr id="row186019965165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p716072402165636"><a name="p716072402165636"></a><a name="p716072402165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1796021309165636"><a name="p1796021309165636"></a><a name="p1796021309165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1659882063165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1885739324165636"><a name="p1885739324165636"></a><a name="p1885739324165636"></a><a href="want.md#a0ca9d0b3a71d92dec9a14468787afbf8">element</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474977620165636"><a name="p474977620165636"></a><a name="p474977620165636"></a><a href="elementname.md">ElementName</a> * </p>
</td>
</tr>
<tr id="row849203241165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879064584165636"><a name="p1879064584165636"></a><a name="p1879064584165636"></a><a href="want.md#a08a6438e5a2630cbefde052834869b3c">sid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261602106165636"><a name="p261602106165636"></a><a name="p261602106165636"></a>SvcIdentity * </p>
</td>
</tr>
<tr id="row1464365585165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900061192165636"><a name="p900061192165636"></a><a name="p900061192165636"></a><a href="want.md#a47c0d5e886bb5cb0b7c9fdb32fa903fa">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889275453165636"><a name="p889275453165636"></a><a name="p889275453165636"></a>void * </p>
</td>
</tr>
<tr id="row1079889966165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p739079704165636"><a name="p739079704165636"></a><a name="p739079704165636"></a><a href="want.md#a9175a7f7f1c7d84e11042b2d17a2d3f4">dataLength</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479363656165636"><a name="p479363656165636"></a><a name="p479363656165636"></a>uint16_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section566798983165636"></a>

## **Field **<a name="section1651066855165636"></a>

## data<a name="a47c0d5e886bb5cb0b7c9fdb32fa903fa"></a>

```
void* Want::data
```

 **Description:**

Pointer to the carried data 

## dataLength<a name="a9175a7f7f1c7d84e11042b2d17a2d3f4"></a>

```
uint16_t Want::dataLength
```

 **Description:**

Data length 

## element<a name="a0ca9d0b3a71d92dec9a14468787afbf8"></a>

```
[ElementName](elementname.md)* Want::element
```

 **Description:**

Pointer to the ability information, including the device ID, bundle name, and class name. 

## sid<a name="a08a6438e5a2630cbefde052834869b3c"></a>

```
SvcIdentity* Want::sid
```

 **Description:**

Pointer to the ID of the server that listens for ability startup. After the ability is started, the callback function corresponding to the server will be invoked. 

