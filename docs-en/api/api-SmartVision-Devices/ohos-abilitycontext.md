# OHOS::AbilityContext<a name="EN-US_TOPIC_0000001054879544"></a>

-   [Overview](#section1121371199165632)
-   [Summary](#section1151626780165632)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1121371199165632"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Provides functions for starting and stopping an ability. 

The  [Ability](ohos-ability.md)  and  [AbilitySlice](ohos-abilityslice.md)  classes are inherited from the  **[AbilityContext](ohos-abilitycontext.md)**  class for you to call functions in this class for application development.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1151626780165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table2056669821165632"></a>
<table><thead align="left"><tr id="row136206013165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p398063038165632"><a name="p398063038165632"></a><a name="p398063038165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p557567191165632"><a name="p557567191165632"></a><a name="p557567191165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188135132165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862895169165632"><a name="p862895169165632"></a><a name="p862895169165632"></a><a href="abilitykit.md#gab11d708d5eaa1eca54828fa88625681a">StartAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072984447165632"><a name="p2072984447165632"></a><a name="p2072984447165632"></a>int </p>
<p id="p1611052058165632"><a name="p1611052058165632"></a><a name="p1611052058165632"></a>Starts an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row1660570312165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574364103165632"><a name="p1574364103165632"></a><a name="p1574364103165632"></a><a href="abilitykit.md#gadc670d5f6df0d485ee3062b70b3ffe99">StopAbility</a> (const <a href="want.md">Want</a> &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634895917165632"><a name="p1634895917165632"></a><a name="p1634895917165632"></a>int </p>
<p id="p2116443184165632"><a name="p2116443184165632"></a><a name="p2116443184165632"></a>Stops an <a href="ohos-ability.md">Ability</a> based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row2123531463165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664794884165632"><a name="p1664794884165632"></a><a name="p1664794884165632"></a><a href="abilitykit.md#gac4a36f03c60fcbeca3b47192ccab1d24">TerminateAbility</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378946686165632"><a name="p1378946686165632"></a><a name="p1378946686165632"></a>int </p>
<p id="p1583175602165632"><a name="p1583175602165632"></a><a name="p1583175602165632"></a>Destroys this <a href="ohos-ability.md">Ability</a>. </p>
</td>
</tr>
<tr id="row968651441165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p776384473165632"><a name="p776384473165632"></a><a name="p776384473165632"></a><a href="abilitykit.md#ga4da460ac085a8da1c665f317fcde2ba1">ConnectAbility</a> (const <a href="want.md">Want</a> &amp;want, const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555862856165632"><a name="p555862856165632"></a><a name="p555862856165632"></a>int </p>
<p id="p454352201165632"><a name="p454352201165632"></a><a name="p454352201165632"></a>Connects to a <a href="service.md">Service</a> ability based on the specified <a href="want.md">Want</a> information. </p>
</td>
</tr>
<tr id="row269893962165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091739115165632"><a name="p2091739115165632"></a><a name="p2091739115165632"></a><a href="abilitykit.md#ga1d9023597a9889dbb4015565a10f3470">DisconnectAbility</a> (const <a href="iabilityconnection.md">IAbilityConnection</a> &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556958610165632"><a name="p1556958610165632"></a><a name="p1556958610165632"></a>int </p>
<p id="p172956318165632"><a name="p172956318165632"></a><a name="p172956318165632"></a>Disconnects from a <a href="service.md">Service</a> ability. </p>
</td>
</tr>
</tbody>
</table>

