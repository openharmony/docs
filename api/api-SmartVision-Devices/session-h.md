# session.h<a name="ZH-CN_TOPIC_0000001054598139"></a>

-   [Overview](#section946648268165629)
-   [Summary](#section1520242253165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section946648268165629"></a>

**Related Modules:**

[Softbus](Softbus.md)

**Description:**

Declares unified data transmission interfaces. 

This file provides data transmission capabilities, including creating and removing a session server, opening and closing sessions, receiving data, and querying basic session information. After multiple nearby devices are discovered and networked, these interfaces can be used to transmit data across devices. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1520242253165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1437557246165629"></a>
<table><thead align="left"><tr id="row1716968694165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1398509021165629"><a name="p1398509021165629"></a><a name="p1398509021165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1284083706165629"><a name="p1284083706165629"></a><a name="p1284083706165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row497772934165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074072480165629"><a name="p1074072480165629"></a><a name="p1074072480165629"></a><a href="ISessionListener.md">ISessionListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1941148099165629"><a name="p1941148099165629"></a><a name="p1941148099165629"></a>Defines session callbacks. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1514034961165629"></a>
<table><thead align="left"><tr id="row1269453660165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1082169796165629"><a name="p1082169796165629"></a><a name="p1082169796165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p83205532165629"><a name="p83205532165629"></a><a name="p83205532165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row355230068165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101330542165629"><a name="p101330542165629"></a><a name="p101330542165629"></a><a href="Softbus.md#gad7e95cced3378e8f489553d70b121392">CreateSessionServer</a> (const char *mouduleName, const char *sessionName, struct <a href="ISessionListener.md">ISessionListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1859385281165629"><a name="p1859385281165629"></a><a name="p1859385281165629"></a>int </p>
<p id="p36728053165629"><a name="p36728053165629"></a><a name="p36728053165629"></a>Creates a session server based on a module name and session name. </p>
</td>
</tr>
<tr id="row392248302165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2006804132165629"><a name="p2006804132165629"></a><a name="p2006804132165629"></a><a href="Softbus.md#ga225a1e178544457263d94078e638b7b5">RemoveSessionServer</a> (const char *mouduleName, const char *sessionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885784090165629"><a name="p885784090165629"></a><a name="p885784090165629"></a>int </p>
<p id="p1571436422165629"><a name="p1571436422165629"></a><a name="p1571436422165629"></a>Removes a session server based on a module name and session name. </p>
</td>
</tr>
<tr id="row509880880165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1621630214165629"><a name="p1621630214165629"></a><a name="p1621630214165629"></a><a href="Softbus.md#ga0333c76724dbef71bca48fb2a82e6980">SendBytes</a> (int sessionId, const void *data, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341705165165629"><a name="p1341705165165629"></a><a name="p1341705165165629"></a>int </p>
<p id="p40152673165629"><a name="p40152673165629"></a><a name="p40152673165629"></a>Sends data based on a session ID. </p>
</td>
</tr>
<tr id="row372393232165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162755576165629"><a name="p162755576165629"></a><a name="p162755576165629"></a><a href="Softbus.md#ga00611f717919f4156c74b7919b28c7d8">GetMySessionName</a> (int sessionId, char *sessionName, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413992338165629"><a name="p413992338165629"></a><a name="p413992338165629"></a>int </p>
<p id="p1209215256165629"><a name="p1209215256165629"></a><a name="p1209215256165629"></a>Obtains the session name registered by the local device based on the session ID. </p>
</td>
</tr>
<tr id="row1042197781165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1793114342165629"><a name="p1793114342165629"></a><a name="p1793114342165629"></a><a href="Softbus.md#ga92d5a47fcdf97a0e01797c77e644033e">GetPeerSessionName</a> (int sessionId, char *sessionName, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p410297275165629"><a name="p410297275165629"></a><a name="p410297275165629"></a>int </p>
<p id="p1003103723165629"><a name="p1003103723165629"></a><a name="p1003103723165629"></a>Obtains the session name registered by the peer device based on the session ID. </p>
</td>
</tr>
<tr id="row1070599454165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702894971165629"><a name="p702894971165629"></a><a name="p702894971165629"></a><a href="Softbus.md#ga21b9a889069eea6e7fe653820e601c04">GetPeerDeviceId</a> (int sessionId, char *devId, unsigned int len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1466274862165629"><a name="p1466274862165629"></a><a name="p1466274862165629"></a>int </p>
<p id="p1528099941165629"><a name="p1528099941165629"></a><a name="p1528099941165629"></a>Obtains the peer device ID based on a session ID. </p>
</td>
</tr>
<tr id="row815821356165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807440940165629"><a name="p1807440940165629"></a><a name="p1807440940165629"></a><a href="Softbus.md#ga5b0c0b334f387f9c2753146ee0890780">CloseSession</a> (int sessionId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1530711916165629"><a name="p1530711916165629"></a><a name="p1530711916165629"></a>void </p>
<p id="p617847398165629"><a name="p617847398165629"></a><a name="p617847398165629"></a>Closes a connected session based on a session ID. </p>
</td>
</tr>
</tbody>
</table>

