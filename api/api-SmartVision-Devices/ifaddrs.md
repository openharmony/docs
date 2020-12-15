# ifaddrs<a name="ZH-CN_TOPIC_0000001054479609"></a>

-   [Overview](#section730545667165637)
-   [Summary](#section480032498165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section77610978165637)
-   [Field](#section1332576686165637)
-   [ifa\_addr](#a12d148f51adf48cee024fc6204f42c94)
-   [ifa\_data](#a7298836283614a0a469c8da1eabdabb9)
-   [ifa\_flags](#a7a68b76a064a1b2474f73aac492780da)
-   [ifa\_name](#a15b0944beb947aaef5e8532635889f6f)
-   [ifa\_netmask](#acac3a8d7d40841c497bb55b9e42c41d5)
-   [ifa\_next](#a56ad9ba85e2c8f8634b8f15fc53b6447)
-   [ifu\_broadaddr](#add59b160fa5ec481f1f650158cc746ab)
-   [ifu\_dstaddr](#a67a6b7d90d3648e32752c8251cfce98a)

## **Overview**<a name="section730545667165637"></a>

**Related Modules:**

[NET](NET.md)

**Description:**

Defines the network interface information. 

## **Summary**<a name="section480032498165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1607635070165637"></a>
<table><thead align="left"><tr id="row1732217811165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1332286440165637"><a name="p1332286440165637"></a><a name="p1332286440165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1880401286165637"><a name="p1880401286165637"></a><a name="p1880401286165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1061434467165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895672580165637"><a name="p895672580165637"></a><a name="p895672580165637"></a><a href="ifaddrs.md#a56ad9ba85e2c8f8634b8f15fc53b6447">ifa_next</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435727168165637"><a name="p1435727168165637"></a><a name="p1435727168165637"></a>struct <a href="ifaddrs.md">ifaddrs</a> * </p>
</td>
</tr>
<tr id="row300867291165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p863912913165637"><a name="p863912913165637"></a><a name="p863912913165637"></a><a href="ifaddrs.md#a15b0944beb947aaef5e8532635889f6f">ifa_name</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1902556555165637"><a name="p1902556555165637"></a><a name="p1902556555165637"></a>char * </p>
</td>
</tr>
<tr id="row1852831613165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577405507165637"><a name="p577405507165637"></a><a name="p577405507165637"></a><a href="ifaddrs.md#a7a68b76a064a1b2474f73aac492780da">ifa_flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220467116165637"><a name="p1220467116165637"></a><a name="p1220467116165637"></a>unsigned </p>
</td>
</tr>
<tr id="row2012476863165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985272256165637"><a name="p1985272256165637"></a><a name="p1985272256165637"></a><a href="ifaddrs.md#a12d148f51adf48cee024fc6204f42c94">ifa_addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804633012165637"><a name="p1804633012165637"></a><a name="p1804633012165637"></a>struct <a href="sockaddr.md">sockaddr</a> * </p>
</td>
</tr>
<tr id="row1320541651165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1798395328165637"><a name="p1798395328165637"></a><a name="p1798395328165637"></a><a href="ifaddrs.md#acac3a8d7d40841c497bb55b9e42c41d5">ifa_netmask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p751300318165637"><a name="p751300318165637"></a><a name="p751300318165637"></a>struct <a href="sockaddr.md">sockaddr</a> * </p>
</td>
</tr>
<tr id="row312223831165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43455896165637"><a name="p43455896165637"></a><a name="p43455896165637"></a><a href="ifaddrs.md#a7298836283614a0a469c8da1eabdabb9">ifa_data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1575876013165637"><a name="p1575876013165637"></a><a name="p1575876013165637"></a>void * </p>
</td>
</tr>
<tr id="row1140946638165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906344038165637"><a name="p1906344038165637"></a><a name="p1906344038165637"></a><a href="ifaddrs.md#add59b160fa5ec481f1f650158cc746ab">ifu_broadaddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493690754165637"><a name="p1493690754165637"></a><a name="p1493690754165637"></a>struct <a href="sockaddr.md">sockaddr</a> * </p>
</td>
</tr>
<tr id="row1282015107165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183914468165637"><a name="p183914468165637"></a><a name="p183914468165637"></a><a href="ifaddrs.md#a67a6b7d90d3648e32752c8251cfce98a">ifu_dstaddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884502396165637"><a name="p884502396165637"></a><a name="p884502396165637"></a>struct <a href="sockaddr.md">sockaddr</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section77610978165637"></a>

## **Field **<a name="section1332576686165637"></a>

## ifa\_addr<a name="a12d148f51adf48cee024fc6204f42c94"></a>

```
struct [sockaddr](sockaddr.md)* ifaddrs::ifa_addr
```

 **Description:**

Interface address 

## ifa\_data<a name="a7298836283614a0a469c8da1eabdabb9"></a>

```
void* ifaddrs::ifa_data
```

 **Description:**

Address-specific data 

## ifa\_flags<a name="a7a68b76a064a1b2474f73aac492780da"></a>

```
unsigned ifaddrs::ifa_flags
```

 **Description:**

Interface flag 

## ifa\_name<a name="a15b0944beb947aaef5e8532635889f6f"></a>

```
char* ifaddrs::ifa_name
```

 **Description:**

Interface name 

## ifa\_netmask<a name="acac3a8d7d40841c497bb55b9e42c41d5"></a>

```
struct [sockaddr](sockaddr.md)* ifaddrs::ifa_netmask
```

 **Description:**

Interface netmask 

## ifa\_next<a name="a56ad9ba85e2c8f8634b8f15fc53b6447"></a>

```
struct [ifaddrs](ifaddrs.md)* ifaddrs::ifa_next
```

 **Description:**

Next item in the linked list 

## ifu\_broadaddr<a name="add59b160fa5ec481f1f650158cc746ab"></a>

```
struct [sockaddr](sockaddr.md)* ifaddrs::ifu_broadaddr
```

 **Description:**

Broadcast address associated with  **ifa\_addr** 

## ifu\_dstaddr<a name="a67a6b7d90d3648e32752c8251cfce98a"></a>

```
struct [sockaddr](sockaddr.md)* ifaddrs::ifu_dstaddr
```

 **Description:**

Destination address of the point-to-point interface 

