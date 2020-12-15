# timeb<a name="ZH-CN_TOPIC_0000001054879582"></a>

-   [Overview](#section347936828165637)
-   [Summary](#section2008416906165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1973851083165637)
-   [Field](#section1374389041165637)
-   [dstflag](#a951ede614d33eed486224c381df15f4e)
-   [millitm](#aa459454ab48c84566d6b1fa72bafebe7)
-   [time](#a6f298f9fb1327aba639d457f2989b859)
-   [timezone](#aa1c6a12ca2a9150c5002bdfb0331bf0b)

## **Overview**<a name="section347936828165637"></a>

**Related Modules:**

[TIME](TIME.md)

**Description:**

Describes the time, accurate to millisecond. 

## **Summary**<a name="section2008416906165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table99836259165637"></a>
<table><thead align="left"><tr id="row1317241347165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1777341097165637"><a name="p1777341097165637"></a><a name="p1777341097165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p302180713165637"><a name="p302180713165637"></a><a name="p302180713165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row565281716165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702039819165637"><a name="p702039819165637"></a><a name="p702039819165637"></a><a href="timeb.md#a6f298f9fb1327aba639d457f2989b859">time</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030292301165637"><a name="p1030292301165637"></a><a name="p1030292301165637"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
</td>
</tr>
<tr id="row672187973165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443789495165637"><a name="p443789495165637"></a><a name="p443789495165637"></a><a href="timeb.md#aa459454ab48c84566d6b1fa72bafebe7">millitm</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914095739165637"><a name="p1914095739165637"></a><a name="p1914095739165637"></a>unsigned short </p>
</td>
</tr>
<tr id="row977724578165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843052244165637"><a name="p843052244165637"></a><a name="p843052244165637"></a><a href="timeb.md#aa1c6a12ca2a9150c5002bdfb0331bf0b">timezone</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1164452471165637"><a name="p1164452471165637"></a><a name="p1164452471165637"></a>short </p>
</td>
</tr>
<tr id="row1011045200165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461226071165637"><a name="p1461226071165637"></a><a name="p1461226071165637"></a><a href="timeb.md#a951ede614d33eed486224c381df15f4e">dstflag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723869407165637"><a name="p723869407165637"></a><a name="p723869407165637"></a>short </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1973851083165637"></a>

## **Field **<a name="section1374389041165637"></a>

## dstflag<a name="a951ede614d33eed486224c381df15f4e"></a>

```
short timeb::dstflag
```

 **Description:**

Whether DST is observed 

## millitm<a name="aa459454ab48c84566d6b1fa72bafebe7"></a>

```
unsigned short timeb::millitm
```

 **Description:**

Number of milliseconds in the current time 

## time<a name="a6f298f9fb1327aba639d457f2989b859"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) timeb::time
```

 **Description:**

Total number of seconds elapsed since January 1, 1970 00:00:00 \(UTC\) 

## timezone<a name="aa1c6a12ca2a9150c5002bdfb0331bf0b"></a>

```
short timeb::timezone
```

 **Description:**

Time zone 

