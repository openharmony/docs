# qelem<a name="ZH-CN_TOPIC_0000001055518136"></a>

-   [Overview](#section1390316689165637)
-   [Summary](#section1557628487165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section2056875648165637)
-   [Field](#section1321585773165637)
-   [q\_back](#a4a64afa420bf271831f625e269d8f904)
-   [q\_data](#a6c6345d36147063410f8a50d01dc6d63)
-   [q\_forw](#acde6ec14ed8d080765c2f58dc1343c6b)

## **Overview**<a name="section1390316689165637"></a>

**Related Modules:**

[UTILS](UTILS.md)

**Description:**

Creates a queue from the doubly linked list for  [insque](UTILS.md#ga7dc680d5d6d07984f96737c220058d64)  and  [remque](UTILS.md#ga1d2e353620a8dc3bb2702831607a3fc1). 

## **Summary**<a name="section1557628487165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2030197004165637"></a>
<table><thead align="left"><tr id="row770140778165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2086901988165637"><a name="p2086901988165637"></a><a name="p2086901988165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1964288753165637"><a name="p1964288753165637"></a><a name="p1964288753165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row390247468165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1473355554165637"><a name="p1473355554165637"></a><a name="p1473355554165637"></a><a href="qelem.md#acde6ec14ed8d080765c2f58dc1343c6b">q_forw</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1599032883165637"><a name="p1599032883165637"></a><a name="p1599032883165637"></a>struct <a href="qelem.md">qelem</a> * </p>
</td>
</tr>
<tr id="row1143847676165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496894041165637"><a name="p496894041165637"></a><a name="p496894041165637"></a><a href="qelem.md#a4a64afa420bf271831f625e269d8f904">q_back</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208679281165637"><a name="p1208679281165637"></a><a name="p1208679281165637"></a>struct <a href="qelem.md">qelem</a> * </p>
</td>
</tr>
<tr id="row1487677958165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865296290165637"><a name="p1865296290165637"></a><a name="p1865296290165637"></a><a href="qelem.md#a6c6345d36147063410f8a50d01dc6d63">q_data</a> [1]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733499631165637"><a name="p1733499631165637"></a><a name="p1733499631165637"></a>char </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2056875648165637"></a>

## **Field **<a name="section1321585773165637"></a>

## q\_back<a name="a4a64afa420bf271831f625e269d8f904"></a>

```
struct [qelem](qelem.md)* qelem::q_back
```

 **Description:**

Pointer to the next  **qelem**  type 

## q\_data<a name="a6c6345d36147063410f8a50d01dc6d63"></a>

```
char qelem::q_data[1]
```

 **Description:**

Data saved in the queue 

## q\_forw<a name="acde6ec14ed8d080765c2f58dc1343c6b"></a>

```
struct [qelem](qelem.md)* qelem::q_forw
```

 **Description:**

Pointer to the previous  **qelem**  type 

