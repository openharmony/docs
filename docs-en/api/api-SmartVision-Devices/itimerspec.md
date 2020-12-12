# itimerspec<a name="EN-US_TOPIC_0000001055039562"></a>

-   [Overview](#section1230982617165636)
-   [Summary](#section598589889165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section838589919165636)
-   [Field](#section394414574165636)
-   [it\_interval](#a27cedae552e2b2fe0993c1b2c4ff1889)
-   [it\_value](#a754dda918053251c24558b07571d6e8f)

## **Overview**<a name="section1230982617165636"></a>

**Related Modules:**

[TIME](time.md)

**Description:**

Sets a timer. 

## **Summary**<a name="section598589889165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1746537531165636"></a>
<table><thead align="left"><tr id="row1860629690165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1804244735165636"><a name="p1804244735165636"></a><a name="p1804244735165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1419280996165636"><a name="p1419280996165636"></a><a name="p1419280996165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1632828131165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278569387165636"><a name="p1278569387165636"></a><a name="p1278569387165636"></a><a href="itimerspec.md#a27cedae552e2b2fe0993c1b2c4ff1889">it_interval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649954043165636"><a name="p649954043165636"></a><a name="p649954043165636"></a>struct <a href="timespec.md">timespec</a> </p>
</td>
</tr>
<tr id="row825789817165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406361614165636"><a name="p406361614165636"></a><a name="p406361614165636"></a><a href="itimerspec.md#a754dda918053251c24558b07571d6e8f">it_value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1716816298165636"><a name="p1716816298165636"></a><a name="p1716816298165636"></a>struct <a href="timespec.md">timespec</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section838589919165636"></a>

## **Field **<a name="section394414574165636"></a>

## it\_interval<a name="a27cedae552e2b2fe0993c1b2c4ff1889"></a>

```
struct [timespec](timespec.md) itimerspec::it_interval
```

 **Description:**

Interval between two consecutive timer triggers 

## it\_value<a name="a754dda918053251c24558b07571d6e8f"></a>

```
struct [timespec](timespec.md) itimerspec::it_value
```

 **Description:**

Initial timeout duration 

