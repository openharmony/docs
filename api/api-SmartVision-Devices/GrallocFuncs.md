# GrallocFuncs<a name="ZH-CN_TOPIC_0000001054918153"></a>

-   [Overview](#section859227232165631)
-   [Summary](#section1937256718165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section386149568165631)
-   [Field](#section419891595165631)
-   [AllocMem](#a48c1f21c086ead11bcb1a53bbec2d285)
-   [FlushCache](#ad56665aa0ff48995b5ec72a8095416d8)
-   [FlushMCache](#aceac1511a490c2ade1e33723d0e20960)
-   [FreeMem](#af80e6c92c5ba7e2419da27cafe19bcff)
-   [Mmap](#ab64438d785bc59050cd4f0a759bd531b)
-   [MmapCache](#a25005370b14ff2a0c860b2272b354e3f)
-   [Unmap](#a55864e4912348f40dd77584e96ad4647)

## **Overview**<a name="section859227232165631"></a>

**Related Modules:**

[Display](Display.md)

**Description:**

Defines pointers to the memory driver functions. 

## **Summary**<a name="section1937256718165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2121244019165631"></a>
<table><thead align="left"><tr id="row556565270165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p455549487165631"><a name="p455549487165631"></a><a name="p455549487165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1344154811165631"><a name="p1344154811165631"></a><a name="p1344154811165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1064583449165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045570690165631"><a name="p1045570690165631"></a><a name="p1045570690165631"></a><a href="GrallocFuncs.md#a48c1f21c086ead11bcb1a53bbec2d285">AllocMem</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p627157068165631"><a name="p627157068165631"></a><a name="p627157068165631"></a>int32_t(* </p>
<p id="p997111251165631"><a name="p997111251165631"></a><a name="p997111251165631"></a>Allocates memory based on the parameters passed by the GUI. </p>
</td>
</tr>
<tr id="row271833281165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283432730165631"><a name="p283432730165631"></a><a name="p283432730165631"></a><a href="GrallocFuncs.md#af80e6c92c5ba7e2419da27cafe19bcff">FreeMem</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831463626165631"><a name="p1831463626165631"></a><a name="p1831463626165631"></a>void(* </p>
<p id="p1368547554165631"><a name="p1368547554165631"></a><a name="p1368547554165631"></a>Releases memory. </p>
</td>
</tr>
<tr id="row77092860165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764226395165631"><a name="p1764226395165631"></a><a name="p1764226395165631"></a><a href="GrallocFuncs.md#ab64438d785bc59050cd4f0a759bd531b">Mmap</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p419555765165631"><a name="p419555765165631"></a><a name="p419555765165631"></a>void *(* </p>
<p id="p936439700165631"><a name="p936439700165631"></a><a name="p936439700165631"></a>Maps memory to memory without cache in the process's address space. </p>
</td>
</tr>
<tr id="row942164489165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393929824165631"><a name="p393929824165631"></a><a name="p393929824165631"></a><a href="GrallocFuncs.md#a25005370b14ff2a0c860b2272b354e3f">MmapCache</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660673263165631"><a name="p1660673263165631"></a><a name="p1660673263165631"></a>void *(* </p>
<p id="p1423580838165631"><a name="p1423580838165631"></a><a name="p1423580838165631"></a>Maps memory to memory with cache in the process's address space. </p>
</td>
</tr>
<tr id="row293986225165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579508311165631"><a name="p1579508311165631"></a><a name="p1579508311165631"></a><a href="GrallocFuncs.md#a55864e4912348f40dd77584e96ad4647">Unmap</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603726515165631"><a name="p1603726515165631"></a><a name="p1603726515165631"></a>int32_t(* </p>
<p id="p1386531635165631"><a name="p1386531635165631"></a><a name="p1386531635165631"></a>Unmaps memory, that is, removes any mappings in the process's address space. </p>
</td>
</tr>
<tr id="row634336986165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899113969165631"><a name="p899113969165631"></a><a name="p899113969165631"></a><a href="GrallocFuncs.md#ad56665aa0ff48995b5ec72a8095416d8">FlushCache</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1974314945165631"><a name="p1974314945165631"></a><a name="p1974314945165631"></a>int32_t(* </p>
<p id="p457604299165631"><a name="p457604299165631"></a><a name="p457604299165631"></a>Flushes data from the cache to memory and invalidates the data in the cache. </p>
</td>
</tr>
<tr id="row1200838767165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p973377643165631"><a name="p973377643165631"></a><a name="p973377643165631"></a><a href="GrallocFuncs.md#aceac1511a490c2ade1e33723d0e20960">FlushMCache</a> )(<a href="GrallocBuffer.md">GrallocBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971712062165631"><a name="p1971712062165631"></a><a name="p1971712062165631"></a>int32_t(* </p>
<p id="p643532329165631"><a name="p643532329165631"></a><a name="p643532329165631"></a>Flushes data from the cache mapped via <a href="GrallocFuncs.md#ab64438d785bc59050cd4f0a759bd531b">Mmap</a> to memory and invalidates the data in the cache. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section386149568165631"></a>

## **Field **<a name="section419891595165631"></a>

## AllocMem<a name="a48c1f21c086ead11bcb1a53bbec2d285"></a>

```
int32_t(* GrallocFuncs::AllocMem) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Allocates memory based on the parameters passed by the GUI. 

The allocated memory can be classified into shared memory, memory with cache, and memory without cache.

**Parameters:**

<a name="table1101777179165631"></a>
<table><thead align="left"><tr id="row482280986165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1353010811165631"><a name="p1353010811165631"></a><a name="p1353010811165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p628425244165631"><a name="p628425244165631"></a><a name="p628425244165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1641944075165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the memory to allocate.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## FlushCache<a name="ad56665aa0ff48995b5ec72a8095416d8"></a>

```
int32_t(* GrallocFuncs::FlushCache) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Flushes data from the cache to memory and invalidates the data in the cache. 

**Parameters:**

<a name="table120054678165631"></a>
<table><thead align="left"><tr id="row985480269165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2059365527165631"><a name="p2059365527165631"></a><a name="p2059365527165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1975987152165631"><a name="p1975987152165631"></a><a name="p1975987152165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1191285056165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the cache to flush.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## FlushMCache<a name="aceac1511a490c2ade1e33723d0e20960"></a>

```
int32_t(* GrallocFuncs::FlushMCache) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Flushes data from the cache mapped via  [Mmap](GrallocFuncs.md#ab64438d785bc59050cd4f0a759bd531b)  to memory and invalidates the data in the cache. 

**Parameters:**

<a name="table1701054931165631"></a>
<table><thead align="left"><tr id="row1773383486165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2022302880165631"><a name="p2022302880165631"></a><a name="p2022302880165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p3476556165631"><a name="p3476556165631"></a><a name="p3476556165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row925564110165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the cache to flush.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## FreeMem<a name="af80e6c92c5ba7e2419da27cafe19bcff"></a>

```
void(* GrallocFuncs::FreeMem) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Releases memory. 

**Parameters:**

<a name="table1216971623165631"></a>
<table><thead align="left"><tr id="row516082350165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1628890119165631"><a name="p1628890119165631"></a><a name="p1628890119165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p97701835165631"><a name="p97701835165631"></a><a name="p97701835165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row570751055165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the memory to release.</td>
</tr>
</tbody>
</table>

## Mmap<a name="ab64438d785bc59050cd4f0a759bd531b"></a>

```
void*(* GrallocFuncs::Mmap) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Maps memory to memory without cache in the process's address space. 

**Parameters:**

<a name="table1695810267165631"></a>
<table><thead align="left"><tr id="row277949810165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p368052547165631"><a name="p368052547165631"></a><a name="p368052547165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p264263137165631"><a name="p264263137165631"></a><a name="p264263137165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row424967841165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the memory to map.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to a valid address if the operation is successful; returns  **NULL**  otherwise. 

## MmapCache<a name="a25005370b14ff2a0c860b2272b354e3f"></a>

```
void*(* GrallocFuncs::MmapCache) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Maps memory to memory with cache in the process's address space. 

**Parameters:**

<a name="table1977898769165631"></a>
<table><thead align="left"><tr id="row375931036165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1933697965165631"><a name="p1933697965165631"></a><a name="p1933697965165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1251159317165631"><a name="p1251159317165631"></a><a name="p1251159317165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row604586297165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the memory to map.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to a valid address if the operation is successful; returns  **NULL**  otherwise. 

## Unmap<a name="a55864e4912348f40dd77584e96ad4647"></a>

```
int32_t(* GrallocFuncs::Unmap) ([GrallocBuffer](GrallocBuffer.md) *buffer)
```

 **Description:**

Unmaps memory, that is, removes any mappings in the process's address space. 

**Parameters:**

<a name="table412365469165631"></a>
<table><thead align="left"><tr id="row147745565165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2028105956165631"><a name="p2028105956165631"></a><a name="p2028105956165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p963911673165631"><a name="p963911673165631"></a><a name="p963911673165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1100075082165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer of the memory to unmap.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](Display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

