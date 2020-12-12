# Response<a name="ZH-CN_TOPIC_0000001055078175"></a>

-   [Overview](#section1975332424165636)
-   [Summary](#section11301928165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1445460175165636)
-   [Field](#section2144347466165636)
-   [data](#a771bd5a2dd1f2d8be9928af7c0fe37a0)
-   [len](#a7a20e7a28a2be1427111d8f03828bb7e)

## **Overview**<a name="section1975332424165636"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Defines a response. 

This structure is used to send a response after the message processing function of a service or feature processes a request. If the data is not empty and the length is not 0, the system automatically releases the data. 

## **Summary**<a name="section11301928165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2059074853165636"></a>
<table><thead align="left"><tr id="row455034582165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1556258782165636"><a name="p1556258782165636"></a><a name="p1556258782165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1789589780165636"><a name="p1789589780165636"></a><a name="p1789589780165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row86859485165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875125484165636"><a name="p1875125484165636"></a><a name="p1875125484165636"></a><a href="Response.md#a771bd5a2dd1f2d8be9928af7c0fe37a0">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1864898829165636"><a name="p1864898829165636"></a><a name="p1864898829165636"></a>void * </p>
</td>
</tr>
<tr id="row601806670165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13403182165636"><a name="p13403182165636"></a><a name="p13403182165636"></a><a href="Response.md#a7a20e7a28a2be1427111d8f03828bb7e">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223975088165636"><a name="p223975088165636"></a><a name="p223975088165636"></a>int16 </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1445460175165636"></a>

## **Field **<a name="section2144347466165636"></a>

## data<a name="a771bd5a2dd1f2d8be9928af7c0fe37a0"></a>

```
void* Response::data
```

 **Description:**

Data content 

## len<a name="a7a20e7a28a2be1427111d8f03828bb7e"></a>

```
int16 Response::len
```

 **Description:**

Data length 

