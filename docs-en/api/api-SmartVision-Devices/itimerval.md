# itimerval<a name="EN-US_TOPIC_0000001054799645"></a>

-   [Overview](#section1814071933165636)
-   [Summary](#section478725931165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section163530793165636)
-   [Field](#section37001115165636)
-   [it\_interval](#ae37e5edff9a3efa2841f5e614e2c2efb)
-   [it\_value](#a2dc8aae1b0b2e57a7ec8f7d33834495d)

## **Overview**<a name="section1814071933165636"></a>

**Related Modules:**

[TIME](time.md)

**Description:**

Describes a timer. 

## **Summary**<a name="section478725931165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1781826074165636"></a>
<table><thead align="left"><tr id="row2042578940165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1207925412165636"><a name="p1207925412165636"></a><a name="p1207925412165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1765930847165636"><a name="p1765930847165636"></a><a name="p1765930847165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1335449430165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081011870165636"><a name="p1081011870165636"></a><a name="p1081011870165636"></a><a href="itimerval.md#ae37e5edff9a3efa2841f5e614e2c2efb">it_interval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578569120165636"><a name="p1578569120165636"></a><a name="p1578569120165636"></a>struct <a href="timeval.md">timeval</a> </p>
</td>
</tr>
<tr id="row259722463165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p799035052165636"><a name="p799035052165636"></a><a name="p799035052165636"></a><a href="itimerval.md#a2dc8aae1b0b2e57a7ec8f7d33834495d">it_value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307837878165636"><a name="p1307837878165636"></a><a name="p1307837878165636"></a>struct <a href="timeval.md">timeval</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section163530793165636"></a>

## **Field **<a name="section37001115165636"></a>

## it\_interval<a name="ae37e5edff9a3efa2841f5e614e2c2efb"></a>

```
struct [timeval](timeval.md) itimerval::it_interval
```

 **Description:**

Timer interval. The value  **0**  indicates a one-shot timer. 

## it\_value<a name="a2dc8aae1b0b2e57a7ec8f7d33834495d"></a>

```
struct [timeval](timeval.md) itimerval::it_value
```

 **Description:**

Timer value 

