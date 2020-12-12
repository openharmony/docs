# ability\_state.h<a name="EN-US_TOPIC_0000001055039476"></a>

-   [Overview](#section1491960134165626)
-   [Summary](#section1963130563165626)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1491960134165626"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares ability-related functions, including ability lifecycle callbacks and functions for connecting to or disconnecting from Particle Abilities. As the fundamental unit of OpenHarmony applications, abilities are classified into  [Feature](feature.md)  Abilities and Particle Abilities.  [Feature](feature.md)  Abilities support the Page template, and Particle Abilities support the  [Service](service.md)  template. An ability using the Page template is called a Page ability for short and that using the  [Service](service.md)  template is called a  [Service](service.md)  ability. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1963130563165626"></a>

## Enumerations<a name="enum-members"></a>

<a name="table958975629165626"></a>
<table><thead align="left"><tr id="row1267508256165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2103787749165626"><a name="p2103787749165626"></a><a name="p2103787749165626"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1934901997165626"><a name="p1934901997165626"></a><a name="p1934901997165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row307020458165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830942275165626"><a name="p1830942275165626"></a><a name="p1830942275165626"></a><a href="abilitykit.md#ga5d74787dedbc4e11c1ab15bf487e61f8">State</a> {   <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a36e8e2958c7f6a4505cb8e8782717530">STATE_UNINITIALIZED</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a24ac4e25affdf1bcda765d59e6cabcfd">STATE_INITIAL</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a39e9fc11b119db5acccb179004077657">STATE_INACTIVE</a>, <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a5f1f347a14f3373f19eb61973636f1a6">STATE_ACTIVE</a>,   <a href="abilitykit.md#gga5d74787dedbc4e11c1ab15bf487e61f8a701f6c0d2f4df7e2e37b07dacd0f514c">STATE_BACKGROUND</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628060959165626"><a name="p628060959165626"></a><a name="p628060959165626"></a>Enumerates all lifecycle states that an ability will go through over the course of its lifetime. </p>
</td>
</tr>
</tbody>
</table>

