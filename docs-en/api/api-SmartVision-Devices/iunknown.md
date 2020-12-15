# IUnknown<a name="EN-US_TOPIC_0000001055078143"></a>

-   [Overview](#section1286749898165632)
-   [Summary](#section172348923165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1203810746165632)
-   [Field](#section217204763165632)
-   [AddRef](#a4d778cd58b81b5f35f7704cbfc5fb3ef)
-   [QueryInterface](#ab1eebb31d61b815123d65764134de2bc)
-   [Release](#a5b8e564aec30767170a2c27380277715)

## **Overview**<a name="section1286749898165632"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Defines the  **[IUnknown](iunknown.md)**  class. 

You need to inherit this structure when developing a subclass of the  **[IUnknown](iunknown.md)**  interface. 

## **Summary**<a name="section172348923165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1917721599165632"></a>
<table><thead align="left"><tr id="row2033528515165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1715055661165632"><a name="p1715055661165632"></a><a name="p1715055661165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p123933938165632"><a name="p123933938165632"></a><a name="p123933938165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1728692973165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345152679165632"><a name="p1345152679165632"></a><a name="p1345152679165632"></a><a href="iunknown.md#ab1eebb31d61b815123d65764134de2bc">QueryInterface</a> )(<a href="iunknown.md">IUnknown</a> *iUnknown, int version, void **target)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1031589752165632"><a name="p1031589752165632"></a><a name="p1031589752165632"></a>int(* </p>
</td>
</tr>
<tr id="row569297177165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302547539165632"><a name="p1302547539165632"></a><a name="p1302547539165632"></a><a href="iunknown.md#a4d778cd58b81b5f35f7704cbfc5fb3ef">AddRef</a> )(<a href="iunknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p77997086165632"><a name="p77997086165632"></a><a name="p77997086165632"></a>int(* </p>
</td>
</tr>
<tr id="row515355802165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276180020165632"><a name="p1276180020165632"></a><a name="p1276180020165632"></a><a href="iunknown.md#a5b8e564aec30767170a2c27380277715">Release</a> )(<a href="iunknown.md">IUnknown</a> *iUnknown)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088191109165632"><a name="p1088191109165632"></a><a name="p1088191109165632"></a>int(* </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1203810746165632"></a>

## **Field **<a name="section217204763165632"></a>

## AddRef<a name="a4d778cd58b81b5f35f7704cbfc5fb3ef"></a>

```
int(* IUnknown::AddRef) ([IUnknown](iunknown.md) *iUnknown)
```

 **Description:**

Adds the reference count. 

## QueryInterface<a name="ab1eebb31d61b815123d65764134de2bc"></a>

```
int(* IUnknown::QueryInterface) ([IUnknown](iunknown.md) *iUnknown, int version, void **target)
```

 **Description:**

Queries the subclass object of the  **[IUnknown](iunknown.md)**  interface of a specified version \(downcasting\). 

## Release<a name="a5b8e564aec30767170a2c27380277715"></a>

```
int(* IUnknown::Release) ([IUnknown](iunknown.md) *iUnknown)
```

 **Description:**

Release the reference to an  **[IUnknown](iunknown.md)**  interface. 

