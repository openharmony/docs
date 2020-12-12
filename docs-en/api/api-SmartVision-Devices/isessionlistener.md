# ISessionListener<a name="EN-US_TOPIC_0000001054598163"></a>

-   [Overview](#section709738140165632)
-   [Summary](#section1732391709165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section709738140165632"></a>

**Related Modules:**

[Softbus](softbus.md)

**Description:**

Defines session callbacks. 

When a session is opened or closed, or there is data to process, the related callback is invoked.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1732391709165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1059784604165632"></a>
<table><thead align="left"><tr id="row1468650552165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p227338373165632"><a name="p227338373165632"></a><a name="p227338373165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p427132729165632"><a name="p427132729165632"></a><a name="p427132729165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1675545913165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425587134165632"><a name="p425587134165632"></a><a name="p425587134165632"></a><a href="softbus.md#ga2b042b85e03d66f1988c348414b2db6e">onSessionOpened</a> )(int sessionId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910829570165632"><a name="p1910829570165632"></a><a name="p1910829570165632"></a>int(* </p>
<p id="p1806508095165632"><a name="p1806508095165632"></a><a name="p1806508095165632"></a>Called when a session is opened. </p>
</td>
</tr>
<tr id="row655528052165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005114214165632"><a name="p2005114214165632"></a><a name="p2005114214165632"></a><a href="softbus.md#ga2088a4e0e196030d8e428a828298eba0">onSessionClosed</a> )(int sessionId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2045230822165632"><a name="p2045230822165632"></a><a name="p2045230822165632"></a>void(* </p>
<p id="p296477732165632"><a name="p296477732165632"></a><a name="p296477732165632"></a>Called when a session is closed. </p>
</td>
</tr>
<tr id="row1401111168165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2023042477165632"><a name="p2023042477165632"></a><a name="p2023042477165632"></a><a href="softbus.md#ga95243f25fa04ef29f7f8f0b3a440dbd3">onBytesReceived</a> )(int sessionId, const void *data, unsigned int dataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070086445165632"><a name="p2070086445165632"></a><a name="p2070086445165632"></a>void(* </p>
<p id="p1191274566165632"><a name="p1191274566165632"></a><a name="p1191274566165632"></a>Called when data is received. </p>
</td>
</tr>
</tbody>
</table>

