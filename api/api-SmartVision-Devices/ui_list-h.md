# ui\_list.h<a name="ZH-CN_TOPIC_0000001054718111"></a>

-   [Overview](#section871306462165630)
-   [Summary](#section49646208165630)
-   [Data Structures](#nested-classes)

## **Overview**<a name="section871306462165630"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Declares a scrollable list in the vertical or horizontal direction. \* This scrollable list can be used with the adapter  **AbstractAdapter**  to implement scrolling, inertial scrolling, automatic alignment, and invoking of a callback when a child view at the preset position is selected as this list scrolls. It is used when there is a large number of child views with a fixed format. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section49646208165630"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1282642207165630"></a>
<table><thead align="left"><tr id="row1582751737165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1487482572165630"><a name="p1487482572165630"></a><a name="p1487482572165630"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p54889912165630"><a name="p54889912165630"></a><a name="p54889912165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1998752697165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p310808178165630"><a name="p310808178165630"></a><a name="p310808178165630"></a><a href="OHOS-ListScrollListener.md">OHOS::ListScrollListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441558431165630"><a name="p441558431165630"></a><a name="p441558431165630"></a>Represents a listener that contains a callback to be invoked when the scroll state changes or when a new child view is selected at the preset position as this list scrolls. The scroll state can be {<strong id="b402676513165630"><a name="b402676513165630"></a><a name="b402676513165630"></a>} or SCROLL_STATE_MOVE}. </strong> </p>
</td>
</tr>
<tr id="row2116596171165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744836522165630"><a name="p1744836522165630"></a><a name="p1744836522165630"></a><a href="OHOS-UIList.md">OHOS::UIList</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288344494165630"><a name="p1288344494165630"></a><a name="p1288344494165630"></a>Represents a scrollable list which is used with the adapter <a href="OHOS-AbstractAdapter.md">AbstractAdapter</a> to implement scrolling, inertial scrolling, automatic alignment, and invoking of a callback when a child view is selected at the preset position as this list scrolls. </p>
</td>
</tr>
</tbody>
</table>

