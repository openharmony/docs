# sockaddr<a name="ZH-CN_TOPIC_0000001055518138"></a>

-   [Overview](#section126117207165637)
-   [Summary](#section1728531772165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1529563928165637)
-   [Field](#section1878305071165637)
-   [sa\_data](#afd5d95d56d0f8959f5b56458b3b3c714)
-   [sa\_family](#ac6ef02e9a2e90a30218132ffd7b5a5c5)

## **Overview**<a name="section126117207165637"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Describes the socket address information. 

## **Summary**<a name="section1728531772165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table82705939165637"></a>
<table><thead align="left"><tr id="row788902418165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1715452844165637"><a name="p1715452844165637"></a><a name="p1715452844165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p986319059165637"><a name="p986319059165637"></a><a name="p986319059165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row509538584165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283734052165637"><a name="p1283734052165637"></a><a name="p1283734052165637"></a><a href="sockaddr.md#ac6ef02e9a2e90a30218132ffd7b5a5c5">sa_family</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1841480769165637"><a name="p1841480769165637"></a><a name="p1841480769165637"></a><a href="UTILS.md#ga92e2efe4f4a4f461f5e405cc957a0570">sa_family_t</a> </p>
</td>
</tr>
<tr id="row1415973214165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1869741210165637"><a name="p1869741210165637"></a><a name="p1869741210165637"></a><a href="sockaddr.md#afd5d95d56d0f8959f5b56458b3b3c714">sa_data</a> [14]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978839629165637"><a name="p1978839629165637"></a><a name="p1978839629165637"></a>char </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1529563928165637"></a>

## **Field **<a name="section1878305071165637"></a>

## sa\_data<a name="afd5d95d56d0f8959f5b56458b3b3c714"></a>

```
char sockaddr::sa_data[14]
```

 **Description:**

Protocol address 

## sa\_family<a name="ac6ef02e9a2e90a30218132ffd7b5a5c5"></a>

```
[sa_family_t](UTILS.md#ga92e2efe4f4a4f461f5e405cc957a0570) sockaddr::sa_family
```

 **Description:**

Address family 

