# pollfd<a name="EN-US_TOPIC_0000001055678140"></a>

-   [Overview](#section810147763165637)
-   [Summary](#section1549798616165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section916150739165637)
-   [Field](#section1379130010165637)
-   [events](#ac9b2f2c5b1f9a7487eb57e67cd4960ef)
-   [fd](#a57e1c316fb063e468d680b6246147861)
-   [revents](#aafb457d11cac415faf0e1e2b825118c2)

## **Overview**<a name="section810147763165637"></a>

**Related Modules:**

[IO](io.md)

**Description:**

Defines I/O multiplexing. 

This structure is used to describe the content during I/O multiplexing, including the file descriptor, event mask, and returned event mask. 

## **Summary**<a name="section1549798616165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1710611845165637"></a>
<table><thead align="left"><tr id="row1971714895165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p799168723165637"><a name="p799168723165637"></a><a name="p799168723165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p533480775165637"><a name="p533480775165637"></a><a name="p533480775165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1457132788165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p650906202165637"><a name="p650906202165637"></a><a name="p650906202165637"></a><a href="pollfd.md#a57e1c316fb063e468d680b6246147861">fd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011018426165637"><a name="p1011018426165637"></a><a name="p1011018426165637"></a>int </p>
</td>
</tr>
<tr id="row1685122616165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626484303165637"><a name="p1626484303165637"></a><a name="p1626484303165637"></a><a href="pollfd.md#ac9b2f2c5b1f9a7487eb57e67cd4960ef">events</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953745235165637"><a name="p953745235165637"></a><a name="p953745235165637"></a>short </p>
</td>
</tr>
<tr id="row1243711499165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903266189165637"><a name="p903266189165637"></a><a name="p903266189165637"></a><a href="pollfd.md#aafb457d11cac415faf0e1e2b825118c2">revents</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297564684165637"><a name="p1297564684165637"></a><a name="p1297564684165637"></a>short </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section916150739165637"></a>

## **Field **<a name="section1379130010165637"></a>

## events<a name="ac9b2f2c5b1f9a7487eb57e67cd4960ef"></a>

```
short pollfd::events
```

 **Description:**

Event mask to be queried 

## fd<a name="a57e1c316fb063e468d680b6246147861"></a>

```
int pollfd::fd
```

 **Description:**

File descriptor 

## revents<a name="aafb457d11cac415faf0e1e2b825118c2"></a>

```
short pollfd::revents
```

 **Description:**

Returned event mask 

