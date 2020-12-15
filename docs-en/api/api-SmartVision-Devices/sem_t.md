# sem\_t<a name="EN-US_TOPIC_0000001055198178"></a>

-   [Overview](#section243002162165637)
-   [Summary](#section2087719119165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section512372025165637)
-   [Field](#section1016476050165637)
-   [\_\_val](#a79fdf291ed1877958bc756d78fc16cf3)

## **Overview**<a name="section243002162165637"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Defines semaphores. 

This structure is used to store semaphores. 

## **Summary**<a name="section2087719119165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table805408919165637"></a>
<table><thead align="left"><tr id="row211625320165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1449914364165637"><a name="p1449914364165637"></a><a name="p1449914364165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1485704808165637"><a name="p1485704808165637"></a><a name="p1485704808165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row709522021165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269919133165637"><a name="p1269919133165637"></a><a name="p1269919133165637"></a><a href="sem_t.md#a79fdf291ed1877958bc756d78fc16cf3">__val</a> [4 *sizeof(long)/sizeof(int)]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2071949759165637"><a name="p2071949759165637"></a><a name="p2071949759165637"></a>volatile int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section512372025165637"></a>

## **Field **<a name="section1016476050165637"></a>

## \_\_val<a name="a79fdf291ed1877958bc756d78fc16cf3"></a>

```
volatile int sem_t::__val[4 *sizeof(long)/sizeof(int)]
```

 **Description:**

Number of semaphores 

