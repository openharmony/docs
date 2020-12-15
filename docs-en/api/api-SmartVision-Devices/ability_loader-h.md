# ability\_loader.h<a name="EN-US_TOPIC_0000001055678052"></a>

-   [Overview](#section201263320165626)
-   [Summary](#section494032089165626)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)

## **Overview**<a name="section201263320165626"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares functions for registering the class names of  **Ability**  and  **AbilitySlice**  with the ability management framework. 

After creating your own  **Ability**  and  **AbilitySlice**  child classes, you should register their class names with the ability management framework so that the application can start  **Ability**  instances created in the background.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section494032089165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table596415794165626"></a>
<table><thead align="left"><tr id="row1302688273165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p350842803165626"><a name="p350842803165626"></a><a name="p350842803165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1986608073165626"><a name="p1986608073165626"></a><a name="p1986608073165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1369155089165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429742412165626"><a name="p1429742412165626"></a><a name="p1429742412165626"></a><a href="ohos-abilityloader.md">OHOS::AbilityLoader</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931273190165626"><a name="p1931273190165626"></a><a name="p1931273190165626"></a>Declares functions for registering the class names of <a href="ohos-ability.md">Ability</a> and <a href="ohos-abilityslice.md">AbilitySlice</a> with the ability management framework. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1059987052165626"></a>
<table><thead align="left"><tr id="row1888110482165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p883426820165626"><a name="p883426820165626"></a><a name="p883426820165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p847118650165626"><a name="p847118650165626"></a><a name="p847118650165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1200594315165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446115936165626"><a name="p1446115936165626"></a><a name="p1446115936165626"></a><a href="abilitykit.md#ga2c5bd891b502a92f937ae4bff3f80cad">REGISTER_AA</a>(className)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p595182845165626"><a name="p595182845165626"></a><a name="p595182845165626"></a>Registers the class name of an <strong id="b1729732385165626"><a name="b1729732385165626"></a><a name="b1729732385165626"></a>Ability</strong> child class. </p>
</td>
</tr>
<tr id="row1980815506165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584464571165626"><a name="p584464571165626"></a><a name="p584464571165626"></a><a href="abilitykit.md#ga8e811999b2b7780e67cb746d045ab5b8">REGISTER_AS</a>(className)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1306431519165626"><a name="p1306431519165626"></a><a name="p1306431519165626"></a>Registers the class name of an <strong id="b1876473912165626"><a name="b1876473912165626"></a><a name="b1876473912165626"></a>AbilitySlice</strong> child class. </p>
</td>
</tr>
</tbody>
</table>

