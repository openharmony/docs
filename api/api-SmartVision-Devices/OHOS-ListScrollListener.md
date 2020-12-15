# OHOS::ListScrollListener<a name="ZH-CN_TOPIC_0000001055518114"></a>

-   [Overview](#section669334094165634)
-   [Summary](#section1535020238165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section669334094165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a listener that contains a callback to be invoked when the scroll state changes or when a new child view is selected at the preset position as this list scrolls. The scroll state can be \{**\} or SCROLL\_STATE\_MOVE\}. **

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1535020238165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table287432143165634"></a>
<table><thead align="left"><tr id="row1621007783165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p12422413165634"><a name="p12422413165634"></a><a name="p12422413165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1936441146165634"><a name="p1936441146165634"></a><a name="p1936441146165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row897789631165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283898107165634"><a name="p283898107165634"></a><a name="p283898107165634"></a><a href="Graphic.md#gabed0d1b84d44874c94487796be82748f">ListScrollListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041317057165634"><a name="p2041317057165634"></a><a name="p2041317057165634"></a> </p>
<p id="p483686072165634"><a name="p483686072165634"></a><a name="p483686072165634"></a>A constructor used to create a <strong id="b1952979438165634"><a name="b1952979438165634"></a><a name="b1952979438165634"></a><a href="OHOS-ListScrollListener.md">ListScrollListener</a></strong> instance with the default state <strong id="b2077112720165634"><a name="b2077112720165634"></a><a name="b2077112720165634"></a>SCROLL_STATE_STOP</strong>. </p>
</td>
</tr>
<tr id="row304762475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745808707165634"><a name="p1745808707165634"></a><a name="p1745808707165634"></a><a href="Graphic.md#gace5864b41e1f07feecb33b3f897fe02d">~ListScrollListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p963871105165634"><a name="p963871105165634"></a><a name="p963871105165634"></a>virtual </p>
<p id="p410042970165634"><a name="p410042970165634"></a><a name="p410042970165634"></a>A destructor used to delete the <strong id="b1698861205165634"><a name="b1698861205165634"></a><a name="b1698861205165634"></a><a href="OHOS-ListScrollListener.md">ListScrollListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1416790221165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p692695192165634"><a name="p692695192165634"></a><a name="p692695192165634"></a><a href="Graphic.md#gae802e8b4c48f7d416d6809ba8fa89428">OnScrollStart</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245575087165634"><a name="p1245575087165634"></a><a name="p1245575087165634"></a>virtual void </p>
<p id="p1315588858165634"><a name="p1315588858165634"></a><a name="p1315588858165634"></a>Called when a scroll starts. </p>
</td>
</tr>
<tr id="row813349141165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114468605165634"><a name="p2114468605165634"></a><a name="p2114468605165634"></a><a href="Graphic.md#ga74cc55be27bfd4c21f10d859bc1fbd3d">OnScrollEnd</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p61220954165634"><a name="p61220954165634"></a><a name="p61220954165634"></a>virtual void </p>
<p id="p1938795642165634"><a name="p1938795642165634"></a><a name="p1938795642165634"></a>Called when a scroll ends. </p>
</td>
</tr>
<tr id="row902263361165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565497747165634"><a name="p1565497747165634"></a><a name="p1565497747165634"></a><a href="Graphic.md#gab6b77fec222bb03439d2d0a37538f1f0">OnItemSelected</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249054668165634"><a name="p249054668165634"></a><a name="p249054668165634"></a>virtual void </p>
<p id="p666627802165634"><a name="p666627802165634"></a><a name="p666627802165634"></a>Called when a new child view is selected at the preset position as this list scrolls. For details about how to set the position, see <strong id="b1312779848165634"><a name="b1312779848165634"></a><a name="b1312779848165634"></a>SetSelectPosition</strong>. </p>
</td>
</tr>
<tr id="row987158366165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374750683165634"><a name="p1374750683165634"></a><a name="p1374750683165634"></a><a href="Graphic.md#ga3710c81b7fe02708da391d23cf08ddad">GetScrollState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1536806331165634"><a name="p1536806331165634"></a><a name="p1536806331165634"></a>uint8_t </p>
<p id="p1563572467165634"><a name="p1563572467165634"></a><a name="p1563572467165634"></a>Obtains the scroll state of this list. </p>
</td>
</tr>
<tr id="row89814121165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683317114165634"><a name="p1683317114165634"></a><a name="p1683317114165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p857735371165634"><a name="p857735371165634"></a><a name="p857735371165634"></a>void * </p>
<p id="p502892734165634"><a name="p502892734165634"></a><a name="p502892734165634"></a>Overrides the <strong id="b587623895165634"><a name="b587623895165634"></a><a name="b587623895165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1974598259165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p623349605165634"><a name="p623349605165634"></a><a name="p623349605165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155177953165634"><a name="p1155177953165634"></a><a name="p1155177953165634"></a>void </p>
<p id="p671868692165634"><a name="p671868692165634"></a><a name="p671868692165634"></a>Overrides the <strong id="b169556644165634"><a name="b169556644165634"></a><a name="b169556644165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

