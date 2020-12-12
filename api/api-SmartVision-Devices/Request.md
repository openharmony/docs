# Request<a name="ZH-CN_TOPIC_0000001055358144"></a>

-   [Overview](#section1389605876165635)
-   [Summary](#section2143216301165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section1637798787165635)
-   [Field](#section459350412165635)
-   [data](#a04b0cc187654cc20a1d036917bcad878)
-   [len](#a4fd475107279d3cc090d7a383719ab3d)
-   [msgId](#a3449d55dccf5271f417df1450bac652e)
-   [msgValue](#ae26e2e2c6d456140217167550372a5bd)

## **Overview**<a name="section1389605876165635"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Defines a request. 

You can use this structure to define the request that will be sent to a feature through the asynchronous function of  [IUnknown](IUnknown.md).  [Request](Request.md), which is data that is packed to send to a feature. If the data is not empty and the length is not 0, the system automatically releases the data. 

## **Summary**<a name="section2143216301165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table984721231165635"></a>
<table><thead align="left"><tr id="row1024503312165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1753802047165635"><a name="p1753802047165635"></a><a name="p1753802047165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1665389122165635"><a name="p1665389122165635"></a><a name="p1665389122165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row914634846165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817369409165635"><a name="p1817369409165635"></a><a name="p1817369409165635"></a><a href="Request.md#a3449d55dccf5271f417df1450bac652e">msgId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1584184571165635"><a name="p1584184571165635"></a><a name="p1584184571165635"></a>int16 </p>
</td>
</tr>
<tr id="row1164679972165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764009496165635"><a name="p764009496165635"></a><a name="p764009496165635"></a><a href="Request.md#a4fd475107279d3cc090d7a383719ab3d">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p257885027165635"><a name="p257885027165635"></a><a name="p257885027165635"></a>int16 </p>
</td>
</tr>
<tr id="row1314078204165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116903811165635"><a name="p2116903811165635"></a><a name="p2116903811165635"></a><a href="Request.md#a04b0cc187654cc20a1d036917bcad878">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1017662777165635"><a name="p1017662777165635"></a><a name="p1017662777165635"></a>void * </p>
</td>
</tr>
<tr id="row817899506165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120451862165635"><a name="p120451862165635"></a><a name="p120451862165635"></a><a href="Request.md#ae26e2e2c6d456140217167550372a5bd">msgValue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583421713165635"><a name="p583421713165635"></a><a name="p583421713165635"></a>uint32 </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1637798787165635"></a>

## **Field **<a name="section459350412165635"></a>

## data<a name="a04b0cc187654cc20a1d036917bcad878"></a>

```
void* Request::data
```

 **Description:**

Data content 

## len<a name="a4fd475107279d3cc090d7a383719ab3d"></a>

```
int16 Request::len
```

 **Description:**

Data length 

## msgId<a name="a3449d55dccf5271f417df1450bac652e"></a>

```
int16 Request::msgId
```

 **Description:**

Message ID 

## msgValue<a name="ae26e2e2c6d456140217167550372a5bd"></a>

```
uint32 Request::msgValue
```

 **Description:**

Message value, which is defined by developers 

