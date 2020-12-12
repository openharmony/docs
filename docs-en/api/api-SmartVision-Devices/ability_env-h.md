# ability\_env.h<a name="EN-US_TOPIC_0000001054598119"></a>

-   [Overview](#section779629548165626)
-   [Summary](#section1423511448165626)
-   [Functions](#func-members)

## **Overview**<a name="section779629548165626"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares functions for obtaining information about the runtime environment of the application to which the ability belongs, including the bundle name, source code path, and data path. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1423511448165626"></a>

## Functions<a name="func-members"></a>

<a name="table2068121123165626"></a>
<table><thead align="left"><tr id="row1500508816165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1042065596165626"><a name="p1042065596165626"></a><a name="p1042065596165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p535684258165626"><a name="p535684258165626"></a><a name="p535684258165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row247050280165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1163982444165626"><a name="p1163982444165626"></a><a name="p1163982444165626"></a><a href="abilitykit.md#gac893d7c01fabee34f80294e3e026c37d">GetBundleName</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100432162165626"><a name="p1100432162165626"></a><a name="p1100432162165626"></a>const char * </p>
<p id="p1176388048165626"><a name="p1176388048165626"></a><a name="p1176388048165626"></a>Obtains the bundle name of the application to which this ability belongs. </p>
</td>
</tr>
<tr id="row1162932398165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425522763165626"><a name="p1425522763165626"></a><a name="p1425522763165626"></a><a href="abilitykit.md#ga7cead123e67bea6db8a34c8ae100e6c5">GetSrcPath</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118746380165626"><a name="p2118746380165626"></a><a name="p2118746380165626"></a>const char * </p>
<p id="p190462367165626"><a name="p190462367165626"></a><a name="p190462367165626"></a>Obtains the source code path of this ability. </p>
</td>
</tr>
<tr id="row1211341393165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894990973165626"><a name="p894990973165626"></a><a name="p894990973165626"></a><a href="abilitykit.md#ga9be6a002714f3fb61b2335dd13ed9787">GetDataPath</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134944162165626"><a name="p134944162165626"></a><a name="p134944162165626"></a>const char * </p>
<p id="p598804260165626"><a name="p598804260165626"></a><a name="p598804260165626"></a>Obtains the data path of this ability. </p>
</td>
</tr>
</tbody>
</table>

