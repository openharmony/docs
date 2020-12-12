# ability\_manager.h<a name="ZH-CN_TOPIC_0000001055518048"></a>

-   [Overview](#section355447599165626)
-   [Summary](#section2051047041165626)
-   [Functions](#func-members)

## **Overview**<a name="section355447599165626"></a>

**Related Modules:**

[AbilityKit](AbilityKit.md)

**Description:**

Declares ability-related functions, including functions for starting, stopping, connecting to, and disconnecting from an ability, registering a callback, and unregistering a callback. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2051047041165626"></a>

## Functions<a name="func-members"></a>

<a name="table604970664165626"></a>
<table><thead align="left"><tr id="row254103658165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p209615722165626"><a name="p209615722165626"></a><a name="p209615722165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p108478935165626"><a name="p108478935165626"></a><a name="p108478935165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1107138187165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794693482165626"><a name="p1794693482165626"></a><a name="p1794693482165626"></a><a href="AbilityKit.md#gae79800c4077afdc2851d5a74d8964111">StartAbility</a> (const <a href="Want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738180257165626"><a name="p1738180257165626"></a><a name="p1738180257165626"></a>int </p>
<p id="p1956762360165626"><a name="p1956762360165626"></a><a name="p1956762360165626"></a>Starts an ability based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1982471448165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564194474165626"><a name="p564194474165626"></a><a name="p564194474165626"></a><a href="AbilityKit.md#gaba99bbd4ff6da4fb072338f5ce95e6ae">StopAbility</a> (const <a href="Want.md">Want</a> *want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1313442919165626"><a name="p1313442919165626"></a><a name="p1313442919165626"></a>int </p>
<p id="p287885750165626"><a name="p287885750165626"></a><a name="p287885750165626"></a>Stops an ability based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1028237317165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p25418927165626"><a name="p25418927165626"></a><a name="p25418927165626"></a><a href="AbilityKit.md#gaae6c2bbb6ab0df92e39c1daad2bd901f">ConnectAbility</a> (const <a href="Want.md">Want</a> *want, const <a href="IAbilityConnection.md">IAbilityConnection</a> *conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p69484502165626"><a name="p69484502165626"></a><a name="p69484502165626"></a>int </p>
<p id="p1271518754165626"><a name="p1271518754165626"></a><a name="p1271518754165626"></a>Connects to a <a href="Service.md">Service</a> ability based on the specified <a href="Want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row383386329165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1498370461165626"><a name="p1498370461165626"></a><a name="p1498370461165626"></a><a href="AbilityKit.md#ga2769216a4c2654d3297a2fdb4011ea7a">DisconnectAbility</a> (const <a href="IAbilityConnection.md">IAbilityConnection</a> *conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1164520615165626"><a name="p1164520615165626"></a><a name="p1164520615165626"></a>int </p>
<p id="p1644325974165626"><a name="p1644325974165626"></a><a name="p1644325974165626"></a>Disconnects from a <a href="Service.md">Service</a> ability. </p>
</td>
</tr>
</tbody>
</table>

