# HdfIoDispatcher<a name="EN-US_TOPIC_0000001055078139"></a>

-   [Overview](#section513341924165631)
-   [Summary](#section1483060063165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1004134595165631)
-   [Field](#section1815270027165631)
-   [Dispatch](#ab87eb61c3bea95bc41c9e8dcc6e2f865)

## **Overview**<a name="section513341924165631"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Defines a driver service call dispatcher. 

**Since:**

1.0

## **Summary**<a name="section1483060063165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2059683372165631"></a>
<table><thead align="left"><tr id="row364277406165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1804367195165631"><a name="p1804367195165631"></a><a name="p1804367195165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1788945974165631"><a name="p1788945974165631"></a><a name="p1788945974165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1716745248165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448034154165631"><a name="p448034154165631"></a><a name="p448034154165631"></a><a href="hdfiodispatcher.md#ab87eb61c3bea95bc41c9e8dcc6e2f865">Dispatch</a> )(struct <a href="hdfobject.md">HdfObject</a> *service, int cmdId, struct <a href="hdfsbuf.md">HdfSBuf</a> *data, struct <a href="hdfsbuf.md">HdfSBuf</a> *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1167260609165631"><a name="p1167260609165631"></a><a name="p1167260609165631"></a>int(* </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1004134595165631"></a>

## **Field **<a name="section1815270027165631"></a>

## Dispatch<a name="ab87eb61c3bea95bc41c9e8dcc6e2f865"></a>

```
int(* HdfIoDispatcher::Dispatch) (struct [HdfObject](hdfobject.md) *service, int cmdId, struct [HdfSBuf](hdfsbuf.md) *data, struct [HdfSBuf](hdfsbuf.md) *reply)
```

 **Description:**

Dispatches a driver service call.  **service**  indicates the pointer to the driver service object,  **id**  indicates the command word of the function,  **data**  indicates the pointer to the data you want to pass to the driver, and  **reply**  indicates the pointer to the data returned by the driver. 

