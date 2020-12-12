# timespec<a name="ZH-CN_TOPIC_0000001055039566"></a>

-   [Overview](#section1020984232165637)
-   [Summary](#section97703895165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section575627431165637)
-   [Field](#section1557898625165637)
-   [tv\_nsec](#ae3c7510dafa8cbcaede866ed13c99683)
-   [tv\_sec](#afc3302668d7cb5952f590da69fdd4955)

## **Overview**<a name="section1020984232165637"></a>

**Related Modules:**

[TIME](TIME.md)

**Description:**

Describes a period of time, accurate to nanoseconds. 

## **Summary**<a name="section97703895165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1431639852165637"></a>
<table><thead align="left"><tr id="row751243888165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p625960134165637"><a name="p625960134165637"></a><a name="p625960134165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1151117769165637"><a name="p1151117769165637"></a><a name="p1151117769165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row134730782165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1870651916165637"><a name="p1870651916165637"></a><a name="p1870651916165637"></a><a href="timespec.md#afc3302668d7cb5952f590da69fdd4955">tv_sec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75636290165637"><a name="p75636290165637"></a><a name="p75636290165637"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row1366569324165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079852536165637"><a name="p2079852536165637"></a><a name="p2079852536165637"></a><a href="timespec.md#ae3c7510dafa8cbcaede866ed13c99683">tv_nsec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796977084165637"><a name="p796977084165637"></a><a name="p796977084165637"></a>long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section575627431165637"></a>

## **Field **<a name="section1557898625165637"></a>

## tv\_nsec<a name="ae3c7510dafa8cbcaede866ed13c99683"></a>

```
long timespec::tv_nsec
```

 **Description:**

Nanosecond 

## tv\_sec<a name="afc3302668d7cb5952f590da69fdd4955"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) timespec::tv_sec
```

 **Description:**

Second 

