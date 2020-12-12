# InputInfo<a name="EN-US_TOPIC_0000001054879536"></a>

-   [Overview](#section705319385165632)
-   [Summary](#section2056514315165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1477004799165632)
-   [Field](#section1236352740165632)
-   [bufferCnt](#adf0831b639d3e7e3b99c5cb2de16fad5)
-   [buffers](#ad759a3e9cef5806ffbf9dbff601d3897)
-   [flag](#a80d14d367be6484c1487d4fd2cef7e5f)
-   [pts](#acc69e5b615cd5fbe52626fb52cb1b90e)

## **Overview**<a name="section705319385165632"></a>

**Related Modules:**

[Codec](codec.md)

**Description:**

Describes input information. 

## **Summary**<a name="section2056514315165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1321510282165632"></a>
<table><thead align="left"><tr id="row796898384165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p677440466165632"><a name="p677440466165632"></a><a name="p677440466165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1406371959165632"><a name="p1406371959165632"></a><a name="p1406371959165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1373452754165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947703357165632"><a name="p1947703357165632"></a><a name="p1947703357165632"></a><a href="inputinfo.md#adf0831b639d3e7e3b99c5cb2de16fad5">bufferCnt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1191470003165632"><a name="p1191470003165632"></a><a name="p1191470003165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row581230747165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532287326165632"><a name="p532287326165632"></a><a name="p532287326165632"></a><a href="inputinfo.md#ad759a3e9cef5806ffbf9dbff601d3897">buffers</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272361651165632"><a name="p1272361651165632"></a><a name="p1272361651165632"></a><a href="codecbufferinfo.md">CodecBufferInfo</a> * </p>
</td>
</tr>
<tr id="row1411019629165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961365682165632"><a name="p961365682165632"></a><a name="p961365682165632"></a><a href="inputinfo.md#acc69e5b615cd5fbe52626fb52cb1b90e">pts</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765413706165632"><a name="p765413706165632"></a><a name="p765413706165632"></a>int64_t </p>
</td>
</tr>
<tr id="row508696583165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284857521165632"><a name="p284857521165632"></a><a name="p284857521165632"></a><a href="inputinfo.md#a80d14d367be6484c1487d4fd2cef7e5f">flag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p865326922165632"><a name="p865326922165632"></a><a name="p865326922165632"></a>int32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1477004799165632"></a>

## **Field **<a name="section1236352740165632"></a>

## bufferCnt<a name="adf0831b639d3e7e3b99c5cb2de16fad5"></a>

```
uint32_t InputInfo::bufferCnt
```

 **Description:**

Number of buffers 

## buffers<a name="ad759a3e9cef5806ffbf9dbff601d3897"></a>

```
[CodecBufferInfo](codecbufferinfo.md)* InputInfo::buffers
```

 **Description:**

Pointer to the buffer description. For details, see  [CodecBufferInfo](codecbufferinfo.md). 

## flag<a name="a80d14d367be6484c1487d4fd2cef7e5f"></a>

```
int32_t InputInfo::flag
```

 **Description:**

Input flag. For details, see  [StreamFlagType](codec.md#ga8a15793172118d64d8adeba0c8544e84). 

## pts<a name="acc69e5b615cd5fbe52626fb52cb1b90e"></a>

```
int64_t InputInfo::pts
```

 **Description:**

Input timestamp 

