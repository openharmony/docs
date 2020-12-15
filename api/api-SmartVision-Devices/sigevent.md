# sigevent<a name="ZH-CN_TOPIC_0000001054879580"></a>

-   [Overview](#section2006269069165637)
-   [Summary](#section222431250165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section198648129165637)
-   [Field](#section1170030040165637)
-   [char\_\_pad](#afefb1d2489fc37345bc4923c99d667c8)
-   [sigev\_notify](#aae9a19d879c38e0c4e8a9bf738c5081e)
-   [sigev\_notify\_attributes](#a5a687d2092b237d76eb08e2d46a5115f)
-   [sigev\_notify\_function](#ac3d9f1ee55173d6da3ff2929c7215061)
-   [sigev\_signo](#a5c645ec1d12bb46efc3f4097c52b665d)
-   [sigev\_value](#a757af1e34b87e3f66bbc08c514017a2c)

## **Overview**<a name="section2006269069165637"></a>

**Related Modules:**

[IPC](IPC.md)

**Description:**

Describes asynchronous notifications. 

## **Summary**<a name="section222431250165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table832710157165637"></a>
<table><thead align="left"><tr id="row1757111619165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1299000159165637"><a name="p1299000159165637"></a><a name="p1299000159165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1650180054165637"><a name="p1650180054165637"></a><a name="p1650180054165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1649837995165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1496847711165637"><a name="p1496847711165637"></a><a name="p1496847711165637"></a><a href="sigevent.md#a757af1e34b87e3f66bbc08c514017a2c">sigev_value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983518053165637"><a name="p983518053165637"></a><a name="p983518053165637"></a>union <a href="sigval.md">sigval</a> </p>
</td>
</tr>
<tr id="row489336337165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p124744550165637"><a name="p124744550165637"></a><a name="p124744550165637"></a><a href="sigevent.md#a5c645ec1d12bb46efc3f4097c52b665d">sigev_signo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478802512165637"><a name="p1478802512165637"></a><a name="p1478802512165637"></a>int </p>
</td>
</tr>
<tr id="row57617285165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977470868165637"><a name="p977470868165637"></a><a name="p977470868165637"></a><a href="sigevent.md#aae9a19d879c38e0c4e8a9bf738c5081e">sigev_notify</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301851865165637"><a name="p1301851865165637"></a><a name="p1301851865165637"></a>int </p>
</td>
</tr>
<tr id="row2121511506165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p852280861165637"><a name="p852280861165637"></a><a name="p852280861165637"></a><a href="sigevent.md#ac3d9f1ee55173d6da3ff2929c7215061">sigev_notify_function</a> )(unionsigval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134747513165637"><a name="p1134747513165637"></a><a name="p1134747513165637"></a>void(* </p>
</td>
</tr>
<tr id="row1203679962165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992247257165637"><a name="p992247257165637"></a><a name="p992247257165637"></a><a href="sigevent.md#a5a687d2092b237d76eb08e2d46a5115f">sigev_notify_attributes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879292224165637"><a name="p879292224165637"></a><a name="p879292224165637"></a><a href="UTILS.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> * </p>
</td>
</tr>
<tr id="row1601726302165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098513711165637"><a name="p2098513711165637"></a><a name="p2098513711165637"></a><a href="sigevent.md#afefb1d2489fc37345bc4923c99d667c8">char__pad</a> [56-3 *sizeof(long)]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;&nbsp;</td>
</tr>
</tbody>
</table>

## **Details**<a name="section198648129165637"></a>

## **Field **<a name="section1170030040165637"></a>

## char\_\_pad<a name="afefb1d2489fc37345bc4923c99d667c8"></a>

```
sigevent::char__pad[56-3 *sizeof(long)]
```

 **Description:**

A reserved field 

## sigev\_notify<a name="aae9a19d879c38e0c4e8a9bf738c5081e"></a>

```
int sigevent::sigev_notify
```

 **Description:**

Notification method, which can be set to  [SIGEV\_SIGNAL](IPC.md#ga06d5881eeb84e6ac35f5b801c380dbb6),  [SIGEV\_NONE](IPC.md#gaced9a66610d9d61756999ce4f103740e), or  [SIGEV\_THREAD](IPC.md#ga29ccb6a17fa90a1357b478f62af7fca0) 

## sigev\_notify\_attributes<a name="a5a687d2092b237d76eb08e2d46a5115f"></a>

```
[pthread_attr_t](UTILS.md#gac8ee4471bbc35deb7589ac3615deb486)* sigevent::sigev_notify_attributes
```

 **Description:**

Attributes for notification thread 

## sigev\_notify\_function<a name="ac3d9f1ee55173d6da3ff2929c7215061"></a>

```
void(* sigevent::sigev_notify_function) (unionsigval)
```

 **Description:**

Function used for thread notification 

## sigev\_signo<a name="a5c645ec1d12bb46efc3f4097c52b665d"></a>

```
int sigevent::sigev_signo
```

 **Description:**

Notification signal 

## sigev\_value<a name="a757af1e34b87e3f66bbc08c514017a2c"></a>

```
union [sigval](sigval.md) sigevent::sigev_value
```

 **Description:**

Data passed with notification 

