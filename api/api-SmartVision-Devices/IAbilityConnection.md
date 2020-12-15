# IAbilityConnection<a name="ZH-CN_TOPIC_0000001054479567"></a>

-   [Overview](#section1831135900165631)
-   [Summary](#section1540980390165631)
-   [Data Fields](#pub-attribs)

## **Overview**<a name="section1831135900165631"></a>

**Related Modules:**

[AbilityKit](AbilityKit.md)

**Description:**

Provides callbacks to be invoked when a remote  [Service](Service.md)  ability is connected or disconnected. 

## **Summary**<a name="section1540980390165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table989694410165631"></a>
<table><thead align="left"><tr id="row1213064226165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p225743872165631"><a name="p225743872165631"></a><a name="p225743872165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1420673164165631"><a name="p1420673164165631"></a><a name="p1420673164165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row108814336165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167230993165631"><a name="p1167230993165631"></a><a name="p1167230993165631"></a><a href="AbilityKit.md#ga3b9bfacbcf1564c83cffbfff7889998a">OnAbilityConnectDone</a> )(<a href="ElementName.md">ElementName</a> *elementName, SvcIdentity *serviceSid, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903338102165631"><a name="p1903338102165631"></a><a name="p1903338102165631"></a>void(* </p>
<p id="p798332460165631"><a name="p798332460165631"></a><a name="p798332460165631"></a>Called when a client is connected to a <a href="Service.md">Service</a> ability. </p>
</td>
</tr>
<tr id="row928781257165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457566603165631"><a name="p457566603165631"></a><a name="p457566603165631"></a><a href="AbilityKit.md#gaba7cf0abb517890ef1a3949e398aaf1d">OnAbilityDisconnectDone</a> )(<a href="ElementName.md">ElementName</a> *elementName, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962129111165631"><a name="p1962129111165631"></a><a name="p1962129111165631"></a>void(* </p>
<p id="p1232143269165631"><a name="p1232143269165631"></a><a name="p1232143269165631"></a>Called after all connections to a <a href="Service.md">Service</a> ability are disconnected. </p>
</td>
</tr>
</tbody>
</table>

