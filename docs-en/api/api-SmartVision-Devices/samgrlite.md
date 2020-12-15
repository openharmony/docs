# SamgrLite<a name="EN-US_TOPIC_0000001054918193"></a>

-   [Overview](#section1479211129165636)
-   [Summary](#section1482277520165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section1810909222165636)
-   [Field](#section1636874996165636)
-   [GetDefaultFeatureApi](#ac9d054e649b089ce256128ea4731cf57)
-   [GetFeatureApi](#aad5c8419acea291e00059f79f8e6c8d1)
-   [RegisterDefaultFeatureApi](#aafa34cfe11f389b208e90ba451000c1d)
-   [RegisterFeature](#a05153cf073a1373bac53a0a1c2030ba0)
-   [RegisterFeatureApi](#a9c1a5452e501478a984a1220f550efba)
-   [RegisterService](#a9adf6d526e11688ad318229487cfc0b4)
-   [UnregisterDefaultFeatureApi](#a46f630c5a037c569a5b7806b4f8804ad)
-   [UnregisterFeature](#a03c53143dae167f685d796f3a806a574)
-   [UnregisterFeatureApi](#a2e33f34b97159b6673dff37e675ed844)
-   [UnregisterService](#a3cebb3773860e67de745ac24021e63b0)

## **Overview**<a name="section1479211129165636"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Represents the system ability management class. 

This class is used for registering and discovering services, features, and functions. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1482277520165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table419971652165636"></a>
<table><thead align="left"><tr id="row1697707126165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1961234192165636"><a name="p1961234192165636"></a><a name="p1961234192165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2032270311165636"><a name="p2032270311165636"></a><a name="p2032270311165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1360233423165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1168696419165636"><a name="p1168696419165636"></a><a name="p1168696419165636"></a><a href="samgrlite.md#a9adf6d526e11688ad318229487cfc0b4">RegisterService</a> )(<a href="service.md">Service</a> *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65822490165636"><a name="p65822490165636"></a><a name="p65822490165636"></a>BOOL(* </p>
<p id="p1133401723165636"><a name="p1133401723165636"></a><a name="p1133401723165636"></a>Registers a service. </p>
</td>
</tr>
<tr id="row1336825674165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1808410166165636"><a name="p1808410166165636"></a><a name="p1808410166165636"></a><a href="samgrlite.md#a3cebb3773860e67de745ac24021e63b0">UnregisterService</a> )(const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661170844165636"><a name="p661170844165636"></a><a name="p661170844165636"></a><a href="service.md">Service</a> *(* </p>
<p id="p1414208198165636"><a name="p1414208198165636"></a><a name="p1414208198165636"></a>Unregisters a service. </p>
</td>
</tr>
<tr id="row865781126165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576018537165636"><a name="p576018537165636"></a><a name="p576018537165636"></a><a href="samgrlite.md#a05153cf073a1373bac53a0a1c2030ba0">RegisterFeature</a> )(const char *serviceName, <a href="feature.md">Feature</a> *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p597406743165636"><a name="p597406743165636"></a><a name="p597406743165636"></a>BOOL(* </p>
<p id="p1977702225165636"><a name="p1977702225165636"></a><a name="p1977702225165636"></a>Registers a feature. </p>
</td>
</tr>
<tr id="row264729470165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p601479371165636"><a name="p601479371165636"></a><a name="p601479371165636"></a><a href="samgrlite.md#a03c53143dae167f685d796f3a806a574">UnregisterFeature</a> )(const char *serviceName, const char *featureName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015593358165636"><a name="p1015593358165636"></a><a name="p1015593358165636"></a><a href="feature.md">Feature</a> *(* </p>
<p id="p1571718436165636"><a name="p1571718436165636"></a><a name="p1571718436165636"></a>Unregisters a feature. </p>
</td>
</tr>
<tr id="row451883626165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p260699911165636"><a name="p260699911165636"></a><a name="p260699911165636"></a><a href="samgrlite.md#aafa34cfe11f389b208e90ba451000c1d">RegisterDefaultFeatureApi</a> )(const char *service, <a href="iunknown.md">IUnknown</a> *publicApi)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1526128819165636"><a name="p1526128819165636"></a><a name="p1526128819165636"></a>BOOL(* </p>
<p id="p1930862249165636"><a name="p1930862249165636"></a><a name="p1930862249165636"></a>Registers the API for the default feature of a service. </p>
</td>
</tr>
<tr id="row922996530165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221417999165636"><a name="p1221417999165636"></a><a name="p1221417999165636"></a><a href="samgrlite.md#a46f630c5a037c569a5b7806b4f8804ad">UnregisterDefaultFeatureApi</a> )(const char *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653612034165636"><a name="p653612034165636"></a><a name="p653612034165636"></a><a href="iunknown.md">IUnknown</a> *(* </p>
<p id="p1372085111165636"><a name="p1372085111165636"></a><a name="p1372085111165636"></a>Unregisters the API from the default feature of a service. </p>
</td>
</tr>
<tr id="row2060199750165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040615921165636"><a name="p1040615921165636"></a><a name="p1040615921165636"></a><a href="samgrlite.md#a9c1a5452e501478a984a1220f550efba">RegisterFeatureApi</a> )(const char *service, const char *feature, <a href="iunknown.md">IUnknown</a> *publicApi)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2052914107165636"><a name="p2052914107165636"></a><a name="p2052914107165636"></a>BOOL(* </p>
<p id="p1732671543165636"><a name="p1732671543165636"></a><a name="p1732671543165636"></a>Registers the API for a feature. </p>
</td>
</tr>
<tr id="row2068877925165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985974019165636"><a name="p1985974019165636"></a><a name="p1985974019165636"></a><a href="samgrlite.md#a2e33f34b97159b6673dff37e675ed844">UnregisterFeatureApi</a> )(const char *service, const char *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p484654216165636"><a name="p484654216165636"></a><a name="p484654216165636"></a><a href="iunknown.md">IUnknown</a> *(* </p>
<p id="p1053884159165636"><a name="p1053884159165636"></a><a name="p1053884159165636"></a>Unregisters the API from a feature. </p>
</td>
</tr>
<tr id="row2009929565165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631447218165636"><a name="p1631447218165636"></a><a name="p1631447218165636"></a><a href="samgrlite.md#ac9d054e649b089ce256128ea4731cf57">GetDefaultFeatureApi</a> )(const char *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p907312359165636"><a name="p907312359165636"></a><a name="p907312359165636"></a><a href="iunknown.md">IUnknown</a> *(* </p>
<p id="p845299881165636"><a name="p845299881165636"></a><a name="p845299881165636"></a>Obtains the API specific to the default feature. </p>
</td>
</tr>
<tr id="row931153881165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391942194165636"><a name="p391942194165636"></a><a name="p391942194165636"></a><a href="samgrlite.md#aad5c8419acea291e00059f79f8e6c8d1">GetFeatureApi</a> )(const char *serviceName, const char *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246999459165636"><a name="p246999459165636"></a><a name="p246999459165636"></a><a href="iunknown.md">IUnknown</a> *(* </p>
<p id="p1538767552165636"><a name="p1538767552165636"></a><a name="p1538767552165636"></a>Obtains the API specific to the feature. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1810909222165636"></a>

## **Field **<a name="section1636874996165636"></a>

## GetDefaultFeatureApi<a name="ac9d054e649b089ce256128ea4731cf57"></a>

```
[IUnknown](iunknown.md)*(* SamgrLite::GetDefaultFeatureApi) (const char *service)
```

 **Description:**

Obtains the API specific to the default feature. 

You need to call this function before using the system capabilities of the service involved. 

**Parameters:**

<a name="table494987071165636"></a>
<table><thead align="left"><tr id="row2135013783165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p350563314165636"><a name="p350563314165636"></a><a name="p350563314165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p242533256165636"><a name="p242533256165636"></a><a name="p242533256165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1024378989165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service to which the default feature belongs. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **[IUnknown](iunknown.md)  \***  object that can be called if the operation is successful; returns  **NULL**  if the operation fails. 

## GetFeatureApi<a name="aad5c8419acea291e00059f79f8e6c8d1"></a>

```
[IUnknown](iunknown.md)*(* SamgrLite::GetFeatureApi) (const char *serviceName, const char *feature)
```

 **Description:**

Obtains the API specific to the feature. 

You need to call this function before using the system capabilities of the service involved. 

**Parameters:**

<a name="table353847165636"></a>
<table><thead align="left"><tr id="row1614948380165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1322184685165636"><a name="p1322184685165636"></a><a name="p1322184685165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2073172876165636"><a name="p2073172876165636"></a><a name="p2073172876165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row761719778165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service to which the feature belongs. </td>
</tr>
<tr id="row648783118165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the feature whose API will be obtained. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the  **[IUnknown](iunknown.md)  \***  object that can be called if the operation is successful; returns  **NULL**  if the operation fails. 

## RegisterDefaultFeatureApi<a name="aafa34cfe11f389b208e90ba451000c1d"></a>

```
BOOL(* SamgrLite::RegisterDefaultFeatureApi) (const char *service, [IUnknown](iunknown.md) *publicApi)
```

 **Description:**

Registers the API for the default feature of a service. 

You need to call this function after the service is registered. The pointers to the  [IUnknown](iunknown.md)  and  [IUnknown](iunknown.md)  members to be registered cannot be empty. 

**Parameters:**

<a name="table2113995376165636"></a>
<table><thead align="left"><tr id="row81187548165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1342448105165636"><a name="p1342448105165636"></a><a name="p1342448105165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1685598796165636"><a name="p1685598796165636"></a><a name="p1685598796165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row874346272165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service whose default feature's API will be registered. </td>
</tr>
<tr id="row34161855165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">publicApi</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the API to be registered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the registration is successful; returns  **FALSE**  if the registration fails. 

## RegisterFeature<a name="a05153cf073a1373bac53a0a1c2030ba0"></a>

```
BOOL(* SamgrLite::RegisterFeature) (const char *serviceName, [Feature](feature.md) *feature)
```

 **Description:**

Registers a feature. 

You need to call this function in the startup entry of each feature.  [Feature](feature.md)  and  [Feature](feature.md)  structure members to be registered cannot be empty. 

**Parameters:**

<a name="table842316237165636"></a>
<table><thead align="left"><tr id="row1676007668165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1666875598165636"><a name="p1666875598165636"></a><a name="p1666875598165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p673143135165636"><a name="p673143135165636"></a><a name="p673143135165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row677392330165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the feature to be registered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the registration is successful; returns  **FALSE**  if the registration fails. 

## RegisterFeatureApi<a name="a9c1a5452e501478a984a1220f550efba"></a>

```
BOOL(* SamgrLite::RegisterFeatureApi) (const char *service, const char *feature, [IUnknown](iunknown.md) *publicApi)
```

 **Description:**

Registers the API for a feature. 

You can call this function only if the feature has been registered. The pointers to the  [IUnknown](iunknown.md)  and  [IUnknown](iunknown.md)  members to be registered cannot be empty. 

**Parameters:**

<a name="table1747522903165636"></a>
<table><thead align="left"><tr id="row1474551277165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p834289510165636"><a name="p834289510165636"></a><a name="p834289510165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p455803966165636"><a name="p455803966165636"></a><a name="p455803966165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row526094650165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service whose API will be registered. </td>
</tr>
<tr id="row2131394587165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the feature whose API will be registered. </td>
</tr>
<tr id="row523161509165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">publicApi</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the API to be registered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the registration is successful; returns  **FALSE**  if the registration fails. 

## RegisterService<a name="a9adf6d526e11688ad318229487cfc0b4"></a>

```
BOOL(* SamgrLite::RegisterService) ([Service](service.md) *service)
```

 **Description:**

Registers a service. 

You need to call this function in the startup entry of each service.  [Service](service.md)  and  [Service](service.md)  structure members to be registered cannot be empty. 

**Parameters:**

<a name="table614652900165636"></a>
<table><thead align="left"><tr id="row680328584165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1987710019165636"><a name="p1987710019165636"></a><a name="p1987710019165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p272754008165636"><a name="p272754008165636"></a><a name="p272754008165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row129947866165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the service to be registered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **TRUE**  if the registration is successful; returns  **FALSE**  if the registration fails. 

## UnregisterDefaultFeatureApi<a name="a46f630c5a037c569a5b7806b4f8804ad"></a>

```
[IUnknown](iunknown.md)*(* SamgrLite::UnregisterDefaultFeatureApi) (const char *service)
```

 **Description:**

Unregisters the API from the default feature of a service. 

You need to call this function to unregister  [IUnknown](iunknown.md)  if the service to which the default feature belongs is no longer required. 

**Parameters:**

<a name="table224454139165636"></a>
<table><thead align="left"><tr id="row860407165165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1546309216165636"><a name="p1546309216165636"></a><a name="p1546309216165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1653247250165636"><a name="p1653247250165636"></a><a name="p1653247250165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row798797638165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service whose default feature's API will be unregistered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the unregistered function object if the unregistration is successful. The memory is released by the caller. Returns  **NULL**  if the unregistration fails. 

## UnregisterFeature<a name="a03c53143dae167f685d796f3a806a574"></a>

```
[Feature](feature.md)*(* SamgrLite::UnregisterFeature) (const char *serviceName, const char *featureName)
```

 **Description:**

Unregisters a feature. 

You need to call this function when the feature is no longer required. 

**Parameters:**

<a name="table1357025487165636"></a>
<table><thead align="left"><tr id="row5216095165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1295952920165636"><a name="p1295952920165636"></a><a name="p1295952920165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p439000952165636"><a name="p439000952165636"></a><a name="p439000952165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row303479106165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">serviceName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service whose feature will be unregistered. </td>
</tr>
<tr id="row467984036165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">featureName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the feature to be unregistered. </td>
</tr>
</tbody>
</table>

**Attention:**

Before unregistering the feature, you must unregister its functions. Otherwise, the unregistration fails. 

**Returns:**

Returns the unregistered feature object if the unregistration is successful. The memory is released by the caller. Returns  **NULL**  if the unregistration fails. 

## UnregisterFeatureApi<a name="a2e33f34b97159b6673dff37e675ed844"></a>

```
[IUnknown](iunknown.md)*(* SamgrLite::UnregisterFeatureApi) (const char *service, const char *feature)
```

 **Description:**

Unregisters the API from a feature. 

You must call this function before unregistering the feature no longer required. 

**Parameters:**

<a name="table572863035165636"></a>
<table><thead align="left"><tr id="row709185707165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p49487169165636"><a name="p49487169165636"></a><a name="p49487169165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2049792076165636"><a name="p2049792076165636"></a><a name="p2049792076165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1727328931165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service whose API will be unregistered. </td>
</tr>
<tr id="row2126844024165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the feature whose API will be unregistered. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the unregistered function object if the unregistration is successful. The memory is released by the caller. Returns  **NULL**  if the unregistration fails. 

## UnregisterService<a name="a3cebb3773860e67de745ac24021e63b0"></a>

```
[Service](service.md)*(* SamgrLite::UnregisterService) (const char *name)
```

 **Description:**

Unregisters a service. 

You need to call this function when the service is no longer required. 

**Parameters:**

<a name="table1541554607165636"></a>
<table><thead align="left"><tr id="row1525420894165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1923871376165636"><a name="p1923871376165636"></a><a name="p1923871376165636"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p722709839165636"><a name="p722709839165636"></a><a name="p722709839165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1488854214165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the name of the service to be unregistered. </td>
</tr>
</tbody>
</table>

**Attention:**

Before unregistering the service, you must unregister its features and functions. 

**Returns:**

Returns the unregistered service object if the unregistration is successful. The memory is released by the caller. Returns  **NULL**  if the unregistration fails. 

