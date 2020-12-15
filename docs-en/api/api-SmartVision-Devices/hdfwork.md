# HdfWork<a name="EN-US_TOPIC_0000001055518088"></a>

-   [Overview](#section351142809165631)
-   [Summary](#section2043918552165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1104441243165631)
-   [Field](#section659285226165631)
-   [realWork](#a8830d89e775646b48db0beae2af4b561)

## **Overview**<a name="section351142809165631"></a>

**Related Modules:**

[DriverUtils](driverutils.md)

**Description:**

Describes a work item and a delayed work item. This structure defines the work and delayed work items, and then calls the initialization function  [HdfWorkInit](driverutils.md#gad171adc8eda320fd01049a2b87ea62fb)  or  [HdfDelayedWorkInit](driverutils.md#ga55bf669dc6740c65e4d45a4f641db2f1)  to perform initialization. The  **[HdfAddWork\(\)](driverutils.md#ga82cc68d656aa17317634b07d49dae160)**  function is to add a work item to a work queue immediately, and the  **[HdfAddDelayedWork\(\)](driverutils.md#gaef781ccc1579db3070745088da47b2c5)**  function is to add a work item to a work queue after the configured delayed time. 

## **Summary**<a name="section2043918552165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1167245409165631"></a>
<table><thead align="left"><tr id="row606093194165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1748378137165631"><a name="p1748378137165631"></a><a name="p1748378137165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p289556143165631"><a name="p289556143165631"></a><a name="p289556143165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row545366609165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120536562165631"><a name="p120536562165631"></a><a name="p120536562165631"></a><a href="hdfwork.md#a8830d89e775646b48db0beae2af4b561">realWork</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423599509165631"><a name="p423599509165631"></a><a name="p423599509165631"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1104441243165631"></a>

## **Field **<a name="section659285226165631"></a>

## realWork<a name="a8830d89e775646b48db0beae2af4b561"></a>

```
void* HdfWork::realWork
```

 **Description:**

Pointer to a work item and a delayed work item 

