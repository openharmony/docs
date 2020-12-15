# IPublishCallback<a name="ZH-CN_TOPIC_0000001055078141"></a>

-   [Overview](#section273163417165632)
-   [Summary](#section1771518677165632)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section273163417165632"></a>

**Related Modules:**

[Softbus](Softbus.md)

**Description:**

Defines the callbacks for successful and failed service publishing. 

## **Summary**<a name="section1771518677165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table675150387165632"></a>
<table><thead align="left"><tr id="row1331539238165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1228993057165632"><a name="p1228993057165632"></a><a name="p1228993057165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2118483693165632"><a name="p2118483693165632"></a><a name="p2118483693165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row656399954165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p269965121165632"><a name="p269965121165632"></a><a name="p269965121165632"></a><a href="Softbus.md#gade0a74f5ae9b16a1fa7f03df5d9fbdf1">onPublishSuccess</a> )(int publishId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1443067667165632"><a name="p1443067667165632"></a><a name="p1443067667165632"></a>void(* </p>
</td>
</tr>
<tr id="row976192885165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1733731393165632"><a name="p1733731393165632"></a><a name="p1733731393165632"></a><a href="Softbus.md#ga0f84feec4640c176938bbce26b8f25c8">onPublishFail</a> )(int publishId, <a href="Softbus.md#ga6632fcae1db4a3a13370e3fb49e5e620">PublishFailReason</a> reason)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250514809165632"><a name="p250514809165632"></a><a name="p250514809165632"></a>void(* </p>
</td>
</tr>
</tbody>
</table>

