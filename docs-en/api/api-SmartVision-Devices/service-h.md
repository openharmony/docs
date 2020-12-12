# service.h<a name="EN-US_TOPIC_0000001054799579"></a>

-   [Overview](#section1370060007165629)
-   [Summary](#section350083987165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)

## **Overview**<a name="section1370060007165629"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Provides basic types and constants of services. 

This file is mainly used for service development. This file provides basic capabilities such as lifecycle functions of services, inherited macros, and task configuration. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section350083987165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1771255521165629"></a>
<table><thead align="left"><tr id="row405320320165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p795866680165629"><a name="p795866680165629"></a><a name="p795866680165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p898967415165629"><a name="p898967415165629"></a><a name="p898967415165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row809452028165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400795592165629"><a name="p400795592165629"></a><a name="p400795592165629"></a><a href="taskconfig.md">TaskConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428932464165629"><a name="p428932464165629"></a><a name="p428932464165629"></a>Defines task configurations for a service. </p>
</td>
</tr>
<tr id="row132164877165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p877051234165629"><a name="p877051234165629"></a><a name="p877051234165629"></a><a href="service.md">Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665844436165629"><a name="p665844436165629"></a><a name="p665844436165629"></a>Indicates the basic type of a service. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1527698782165629"></a>
<table><thead align="left"><tr id="row11275225165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1319787505165629"><a name="p1319787505165629"></a><a name="p1319787505165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1243844456165629"><a name="p1243844456165629"></a><a name="p1243844456165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row656937838165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1986761814165629"><a name="p1986761814165629"></a><a name="p1986761814165629"></a><a href="samgr.md#gae9253a7fc1d0acbab91414b4cacc1d84">INHERIT_SERVICE</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1209547216165629"><a name="p1209547216165629"></a><a name="p1209547216165629"></a>Indicates the macro used to inherit the members from the <strong id="b156094579165629"><a name="b156094579165629"></a><a name="b156094579165629"></a>service</strong> class. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1756466347165629"></a>
<table><thead align="left"><tr id="row1290686520165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p562064423165629"><a name="p562064423165629"></a><a name="p562064423165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1376402559165629"><a name="p1376402559165629"></a><a name="p1376402559165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1096049331165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127656915165629"><a name="p2127656915165629"></a><a name="p2127656915165629"></a><a href="samgr.md#gab265648f2dbef93878ad8c383712b43a">TaskType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16990705165629"><a name="p16990705165629"></a><a name="p16990705165629"></a>typedef enum <a href="samgr.md#ga026844c14ab62f42a2e19b54d622609b">TaskType</a> </p>
<p id="p294436763165629"><a name="p294436763165629"></a><a name="p294436763165629"></a>Enumerates task types. </p>
</td>
</tr>
<tr id="row1698171125165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559022518165629"><a name="p559022518165629"></a><a name="p559022518165629"></a><a href="samgr.md#gae9c7eed07272a46851d61e646b6e86d5">SpecifyTag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1821324800165629"><a name="p1821324800165629"></a><a name="p1821324800165629"></a>typedef enum <a href="samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0">SpecifyTag</a> </p>
<p id="p957310806165629"><a name="p957310806165629"></a><a name="p957310806165629"></a>Specifies the tag for the task shared by multiple services. </p>
</td>
</tr>
<tr id="row288282843165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p689662582165629"><a name="p689662582165629"></a><a name="p689662582165629"></a><a href="samgr.md#gaef69bbb3353ea484414c3bbaf8ec362b">TaskPriority</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p718711816165629"><a name="p718711816165629"></a><a name="p718711816165629"></a>typedef enum <a href="samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa">TaskPriority</a> </p>
<p id="p1012753129165629"><a name="p1012753129165629"></a><a name="p1012753129165629"></a>Enumerates task priority. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1785550655165629"></a>
<table><thead align="left"><tr id="row940184662165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1388477628165629"><a name="p1388477628165629"></a><a name="p1388477628165629"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2030343541165629"><a name="p2030343541165629"></a><a name="p2030343541165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1352396204165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606704806165629"><a name="p606704806165629"></a><a name="p606704806165629"></a><a href="samgr.md#ga026844c14ab62f42a2e19b54d622609b">TaskType</a> { <a href="samgr.md#gga026844c14ab62f42a2e19b54d622609ba5e16ebf94e3d37c775ce51bbe4468e99">SHARED_TASK</a> = 0, <a href="samgr.md#gga026844c14ab62f42a2e19b54d622609baa1dcd6759a5b023d945ae8c955e48315">SINGLE_TASK</a> = 1, <a href="samgr.md#gga026844c14ab62f42a2e19b54d622609ba84f51cfcf3f659a99aabbd85924c5376">SPECIFIED_TASK</a> = 2, <a href="samgr.md#gga026844c14ab62f42a2e19b54d622609baf1a2b164c6a01dd1290f3e79171a8f11">NO_TASK</a> = 0xFF }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p553253160165629"><a name="p553253160165629"></a><a name="p553253160165629"></a>Enumerates task types. </p>
</td>
</tr>
<tr id="row195003104165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1473988751165629"><a name="p1473988751165629"></a><a name="p1473988751165629"></a><a href="samgr.md#ga704a59a45a705ef7a15d16e3cab8c1b0">SpecifyTag</a> { <a href="samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a5cf3038af9f9528363577dd32e4eb955">LEVEL_HIGH</a> = 0, <a href="samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a889647ca5662082ace422e57b1da6647">LEVEL_MIDDLE</a> = 1, <a href="samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0a1541ce26187ac34e3e99559669751cf5">LEVEL_LOW</a> = 2, <a href="samgr.md#gga704a59a45a705ef7a15d16e3cab8c1b0afc8d0aa33bc1d911f92931fa5e287263">LEVEL_CUSTOM_BEGIN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205483456165629"><a name="p1205483456165629"></a><a name="p1205483456165629"></a>Specifies the tag for the task shared by multiple services. </p>
</td>
</tr>
<tr id="row1479630641165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779816706165629"><a name="p779816706165629"></a><a name="p779816706165629"></a><a href="samgr.md#gaee057e5f06a7b2533e6f58bde34d15fa">TaskPriority</a> {   <a href="samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faaf8a2513dc9a78bb09c0520af65a3f402">PRI_LOW</a> = 9, <a href="samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faa6f05a14315026dd5f3e5bc87cf745258">PRI_BELOW_NORMAL</a> = 16, <a href="samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faa8ffe612e81f7db9099f774b853533063">PRI_NORMAL</a> = 24, <a href="samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faacb1f8848eb9a8c56779869b418ef9cb6">PRI_ABOVE_NORMAL</a> = 32,   <a href="samgr.md#ggaee057e5f06a7b2533e6f58bde34d15faab9766c2f87357a5cc6e3b14ccbc2c54b">PRI_BUTT</a> = 39 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1529049674165629"><a name="p1529049674165629"></a><a name="p1529049674165629"></a>Enumerates task priority. </p>
</td>
</tr>
</tbody>
</table>

