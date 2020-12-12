# Service<a name="ZH-CN_TOPIC_0000001055198168"></a>

-   [Overview](#section1287791382165636)
-   [Summary](#section65587967165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1393409351165636)
-   [Field](#section702608981165636)
-   [GetName](#a7d6fe59023a0e6ad2ad7c625c0d117d6)
-   [GetTaskConfig](#abc4b1868a77fafe434fe63c8a4685aeb)
-   [Initialize](#a80b0715ef9129631d5f622cb199ff8ae)
-   [MessageHandle](#aa2b7015639906efbadd36aa87eea269b)

## **Overview**<a name="section1287791382165636"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Indicates the basic type of a service. 

You need to implement the function pointers of  **[Service](Service.md)**. 

## **Summary**<a name="section65587967165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1002203845165636"></a>
<table><thead align="left"><tr id="row152441476165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p447133499165636"><a name="p447133499165636"></a><a name="p447133499165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p308455829165636"><a name="p308455829165636"></a><a name="p308455829165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1507937953165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1978490094165636"><a name="p1978490094165636"></a><a name="p1978490094165636"></a><a href="Service.md#a7d6fe59023a0e6ad2ad7c625c0d117d6">GetName</a> )(<a href="Service.md">Service</a> *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1325825453165636"><a name="p1325825453165636"></a><a name="p1325825453165636"></a>const char *(* </p>
<p id="p358378595165636"><a name="p358378595165636"></a><a name="p358378595165636"></a>Obtains the name of a service. </p>
</td>
</tr>
<tr id="row208757320165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158098769165636"><a name="p158098769165636"></a><a name="p158098769165636"></a><a href="Service.md#a80b0715ef9129631d5f622cb199ff8ae">Initialize</a> )(<a href="Service.md">Service</a> *service, <a href="Identity.md">Identity</a> identity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009798661165636"><a name="p1009798661165636"></a><a name="p1009798661165636"></a>BOOL(* </p>
<p id="p222317071165636"><a name="p222317071165636"></a><a name="p222317071165636"></a>Initializes the service. </p>
</td>
</tr>
<tr id="row418777547165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p874635050165636"><a name="p874635050165636"></a><a name="p874635050165636"></a><a href="Service.md#aa2b7015639906efbadd36aa87eea269b">MessageHandle</a> )(<a href="Service.md">Service</a> *service, <a href="Request.md">Request</a> *request)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1252361172165636"><a name="p1252361172165636"></a><a name="p1252361172165636"></a>BOOL(* </p>
<p id="p1299694704165636"><a name="p1299694704165636"></a><a name="p1299694704165636"></a>Processes service messages. </p>
</td>
</tr>
<tr id="row936952119165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472628051165636"><a name="p472628051165636"></a><a name="p472628051165636"></a><a href="Service.md#abc4b1868a77fafe434fe63c8a4685aeb">GetTaskConfig</a> )(<a href="Service.md">Service</a> *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1851890378165636"><a name="p1851890378165636"></a><a name="p1851890378165636"></a><a href="TaskConfig.md">TaskConfig</a>(* </p>
<p id="p790600708165636"><a name="p790600708165636"></a><a name="p790600708165636"></a>Obtains task configurations of a service. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1393409351165636"></a>

## **Field **<a name="section702608981165636"></a>

## GetName<a name="a7d6fe59023a0e6ad2ad7c625c0d117d6"></a>

```
const char*(* Service::GetName) ([Service](Service.md) *service)
```

 **Description:**

Obtains the name of a service. 

This function is called by Samgr during service registration and startup. You need to implement this function. 

**Parameters:**

<a name="table1601667528165636"></a>
<table><thead align="left"><tr id="row1977265753165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2071038078165636"><a name="p2071038078165636"></a><a name="p2071038078165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p698606071165636"><a name="p698606071165636"></a><a name="p698606071165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row949100093165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a constant string no more than 16 bytes if the service name is obtained successfully; returns  **NULL**  if the service name fails to be obtained. 

## GetTaskConfig<a name="abc4b1868a77fafe434fe63c8a4685aeb"></a>

```
[TaskConfig](TaskConfig.md)(* Service::GetTaskConfig) ([Service](Service.md) *service)
```

 **Description:**

Obtains task configurations of a service. 

This function is used to return task configurations. You need to implement this function. 

**Parameters:**

<a name="table1044203256165636"></a>
<table><thead align="left"><tr id="row397171697165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p389223829165636"><a name="p389223829165636"></a><a name="p389223829165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1962347101165636"><a name="p1962347101165636"></a><a name="p1962347101165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row992269154165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  [TaskConfig](TaskConfig.md).

## Initialize<a name="a80b0715ef9129631d5f622cb199ff8ae"></a>

```
BOOL(* Service::Initialize) ([Service](Service.md) *service, [Identity](Identity.md) identity)
```

 **Description:**

Initializes the service. 

After Samgr assigns tasks to a service, the service calls the function in its own tasks. You need to implement this function. 

**Parameters:**

<a name="table459681254165636"></a>
<table><thead align="left"><tr id="row664932932165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1653547033165636"><a name="p1653547033165636"></a><a name="p1653547033165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p407646744165636"><a name="p407646744165636"></a><a name="p407646744165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row216466689165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service. </td>
</tr>
<tr id="row2026462224165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identity</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID allocated by the system to the service. For details, see <a href="Identity.md">Identity</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the initialization is successful; returns  **FALSE**  otherwise. 

## MessageHandle<a name="aa2b7015639906efbadd36aa87eea269b"></a>

```
BOOL(* Service::MessageHandle) ([Service](Service.md) *service, [Request](Request.md) *request)
```

 **Description:**

Processes service messages. 

This function is used to process requests sent by the caller through  [IUnknown](IUnknown.md). You need to implement this function. 

**Parameters:**

<a name="table283201392165636"></a>
<table><thead align="left"><tr id="row775314962165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1113450990165636"><a name="p1113450990165636"></a><a name="p1113450990165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p696730011165636"><a name="p696730011165636"></a><a name="p696730011165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1213050152165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service. </td>
</tr>
<tr id="row21235977165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the request data. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the message processing is successful; returns  **FALSE**  if the processing fails. 

