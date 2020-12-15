# Feature<a name="EN-US_TOPIC_0000001055518086"></a>

-   [Overview](#section416481894165631)
-   [Summary](#section1825669683165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section2084409850165631)
-   [Field](#section589332272165631)
-   [GetName](#ab30dc9677abd4aaa18ec88254e90b139)
-   [OnInitialize](#adb3f9401f41e2309006568ef6e78fd43)
-   [OnMessage](#adf249c7a1b07eb47d51f046c5c8a5f6b)
-   [OnStop](#ab0a4b92d867106b10f3fd3c4761338ba)

## **Overview**<a name="section416481894165631"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Defines the base class of a feature. 

You need to implement the pointer to the feature. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1825669683165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1937197149165631"></a>
<table><thead align="left"><tr id="row1942019000165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p879146928165631"><a name="p879146928165631"></a><a name="p879146928165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p661053041165631"><a name="p661053041165631"></a><a name="p661053041165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row332502951165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167998028165631"><a name="p1167998028165631"></a><a name="p1167998028165631"></a><a href="feature.md#ab30dc9677abd4aaa18ec88254e90b139">GetName</a> )(<a href="feature.md">Feature</a> *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002481467165631"><a name="p2002481467165631"></a><a name="p2002481467165631"></a>const char *(* </p>
<p id="p1613108763165631"><a name="p1613108763165631"></a><a name="p1613108763165631"></a>Obtains a feature name. </p>
</td>
</tr>
<tr id="row1108482273165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1804269092165631"><a name="p1804269092165631"></a><a name="p1804269092165631"></a><a href="feature.md#adb3f9401f41e2309006568ef6e78fd43">OnInitialize</a> )(<a href="feature.md">Feature</a> *feature, <a href="service.md">Service</a> *parent, <a href="identity.md">Identity</a> identity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822850993165631"><a name="p1822850993165631"></a><a name="p1822850993165631"></a>void(* </p>
<p id="p695388815165631"><a name="p695388815165631"></a><a name="p695388815165631"></a>Initializes a feature. </p>
</td>
</tr>
<tr id="row9839150165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219936188165631"><a name="p1219936188165631"></a><a name="p1219936188165631"></a><a href="feature.md#ab0a4b92d867106b10f3fd3c4761338ba">OnStop</a> )(<a href="feature.md">Feature</a> *feature, <a href="identity.md">Identity</a> identity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047296109165631"><a name="p2047296109165631"></a><a name="p2047296109165631"></a>void(* </p>
<p id="p826382864165631"><a name="p826382864165631"></a><a name="p826382864165631"></a>Stops a feature. </p>
</td>
</tr>
<tr id="row1087426016165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065112058165631"><a name="p2065112058165631"></a><a name="p2065112058165631"></a><a href="feature.md#adf249c7a1b07eb47d51f046c5c8a5f6b">OnMessage</a> )(<a href="feature.md">Feature</a> *feature, <a href="request.md">Request</a> *request)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611960672165631"><a name="p611960672165631"></a><a name="p611960672165631"></a>BOOL(* </p>
<p id="p1832331162165631"><a name="p1832331162165631"></a><a name="p1832331162165631"></a>Processes a feature message. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2084409850165631"></a>

## **Field **<a name="section589332272165631"></a>

## GetName<a name="ab30dc9677abd4aaa18ec88254e90b139"></a>

```
const char*(* Feature::GetName) ([Feature](feature.md) *feature)
```

 **Description:**

Obtains a feature name. 

This function is implemented by developers and called by Samgr during feature registration and startup. 

**Parameters:**

<a name="table711360432165631"></a>
<table><thead align="left"><tr id="row1329603654165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1973257118165631"><a name="p1973257118165631"></a><a name="p1973257118165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p957714957165631"><a name="p957714957165631"></a><a name="p957714957165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row224180492165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a constant character string less than 16 bytes if the operation is successful; returns  **NULL**  if the operation fails.

## OnInitialize<a name="adb3f9401f41e2309006568ef6e78fd43"></a>

```
void(* Feature::OnInitialize) ([Feature](feature.md) *feature, [Service](service.md) *parent, [Identity](identity.md) identity)
```

 **Description:**

Initializes a feature. 

This function is implemented by developers. After Samgr dispatches tasks to a service, the service calls this function in its own tasks. 

**Parameters:**

<a name="table449775449165631"></a>
<table><thead align="left"><tr id="row933615880165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p645818123165631"><a name="p645818123165631"></a><a name="p645818123165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1639645214165631"><a name="p1639645214165631"></a><a name="p1639645214165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row169854711165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature. </td>
</tr>
<tr id="row1372659902165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">parent</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the <a href="service.md">Service</a> to which the feature belongs. </td>
</tr>
<tr id="row615580258165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the identity of a feature dispatched by the system.</td>
</tr>
</tbody>
</table>

## OnMessage<a name="adf249c7a1b07eb47d51f046c5c8a5f6b"></a>

```
BOOL(* Feature::OnMessage) ([Feature](feature.md) *feature, [Request](request.md) *request)
```

 **Description:**

Processes a feature message. 

This function is implemented by developers to process requests sent by callers through  [IUnknown](iunknown.md). 

**Parameters:**

<a name="table277916757165631"></a>
<table><thead align="left"><tr id="row550515633165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p958837042165631"><a name="p958837042165631"></a><a name="p958837042165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p544853448165631"><a name="p544853448165631"></a><a name="p544853448165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1781844582165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature. </td>
</tr>
<tr id="row1227777758165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the request message. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the processing is successful; returns  **FALSE**  if the processing fails.

## OnStop<a name="ab0a4b92d867106b10f3fd3c4761338ba"></a>

```
void(* Feature::OnStop) ([Feature](feature.md) *feature, [Identity](identity.md) identity)
```

 **Description:**

Stops a feature. 

This function is implemented by developers and is called by Samgr when a feature is deregistered to stop running services. 

**Parameters:**

<a name="table189406589165631"></a>
<table><thead align="left"><tr id="row2115921194165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p34644278165631"><a name="p34644278165631"></a><a name="p34644278165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p861910447165631"><a name="p861910447165631"></a><a name="p861910447165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1777650037165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature. </td>
</tr>
<tr id="row886232707165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <a href="identity.md">Identity</a> of the feature to be stopped. </td>
</tr>
</tbody>
</table>

