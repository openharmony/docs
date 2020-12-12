# IUnknownEntry<a name="EN-US_TOPIC_0000001054598165"></a>

-   [Overview](#section1603272145165632)
-   [Summary](#section2118773644165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section251707806165632)
-   [Field](#section17328325165632)
-   [iUnknown](#adb0c9a5863f934471bb2edf853690bb9)
-   [ref](#afdf52f5e2c624790ab558ffb0c8aa9a9)
-   [ver](#a5d0fd097aeef2c3a9766a47cf148d8b9)

## **Overview**<a name="section1603272145165632"></a>

**Related Modules:**

[Samgr](samgr.md)

**Description:**

Defines the  **[IUnknown](iunknown.md)**  implementation class. 

You need to inherit this structure when developing a subclass of the  **[IUnknown](iunknown.md)**  implementation class. Each  **[IUnknown](iunknown.md)**  interface must correspond to one or more  **[IUnknown](iunknown.md)**  implementation classes. 

## **Summary**<a name="section2118773644165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table626555520165632"></a>
<table><thead align="left"><tr id="row1322017664165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p942829794165632"><a name="p942829794165632"></a><a name="p942829794165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p474258155165632"><a name="p474258155165632"></a><a name="p474258155165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1998036875165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711241746165632"><a name="p711241746165632"></a><a name="p711241746165632"></a><a href="iunknownentry.md#a5d0fd097aeef2c3a9766a47cf148d8b9">ver</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560226797165632"><a name="p560226797165632"></a><a name="p560226797165632"></a>uint16 </p>
</td>
</tr>
<tr id="row1797260070165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p982856807165632"><a name="p982856807165632"></a><a name="p982856807165632"></a><a href="iunknownentry.md#afdf52f5e2c624790ab558ffb0c8aa9a9">ref</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684225395165632"><a name="p1684225395165632"></a><a name="p1684225395165632"></a>int16 </p>
</td>
</tr>
<tr id="row534576445165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635951339165632"><a name="p635951339165632"></a><a name="p635951339165632"></a><a href="iunknownentry.md#adb0c9a5863f934471bb2edf853690bb9">iUnknown</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1477770222165632"><a name="p1477770222165632"></a><a name="p1477770222165632"></a><a href="iunknown.md">IUnknown</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section251707806165632"></a>

## **Field **<a name="section17328325165632"></a>

## iUnknown<a name="adb0c9a5863f934471bb2edf853690bb9"></a>

```
[IUnknown](iunknown.md) IUnknownEntry::iUnknown
```

 **Description:**

Implementation of  **[IUnknown](iunknown.md)**  interface, which is related to the specific definition implementation. 

## ref<a name="afdf52f5e2c624790ab558ffb0c8aa9a9"></a>

```
int16 IUnknownEntry::ref
```

 **Description:**

Reference count of  **[IUnknown](iunknown.md)**  interface. 

## ver<a name="a5d0fd097aeef2c3a9766a47cf148d8b9"></a>

```
uint16 IUnknownEntry::ver
```

 **Description:**

Version information of  **[IUnknown](iunknown.md)**  interface. 

