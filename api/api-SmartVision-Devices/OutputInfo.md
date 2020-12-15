# OutputInfo<a name="ZH-CN_TOPIC_0000001054918167"></a>

-   [Overview](#section357683563165632)
-   [Summary](#section1394105377165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section748509999165632)
-   [Field](#section1953417827165632)
-   [bufferCnt](#ac131b4abc43415f000a0750e82bb881d)
-   [buffers](#a5a8cc2acb5f2918dde6fa60562e54d00)
-   [flag](#a56f914be981dd3a2f0ee8c65e501d8f1)
-   [sequence](#a6ad161decc8e676690c66d2a6dbde468)
-   [timeStamp](#ac160a64994059683a0fc0547ab734a87)
-   [type](#ad3d70960789585a3b2014d83dddc448b)
-   [vendorPrivate](#a751ecb0c55401f130bf1a5b6492e1f38)

## **Overview**<a name="section357683563165632"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Describes output information. 

## **Summary**<a name="section1394105377165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1263289119165632"></a>
<table><thead align="left"><tr id="row907026576165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1916859393165632"><a name="p1916859393165632"></a><a name="p1916859393165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1972379047165632"><a name="p1972379047165632"></a><a name="p1972379047165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row714208237165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2009825401165632"><a name="p2009825401165632"></a><a name="p2009825401165632"></a><a href="OutputInfo.md#ac131b4abc43415f000a0750e82bb881d">bufferCnt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2118322618165632"><a name="p2118322618165632"></a><a name="p2118322618165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row131608356165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p811085886165632"><a name="p811085886165632"></a><a name="p811085886165632"></a><a href="OutputInfo.md#a5a8cc2acb5f2918dde6fa60562e54d00">buffers</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189100593165632"><a name="p189100593165632"></a><a name="p189100593165632"></a><a href="CodecBufferInfo.md">CodecBufferInfo</a> * </p>
</td>
</tr>
<tr id="row1105848774165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p128702445165632"><a name="p128702445165632"></a><a name="p128702445165632"></a><a href="OutputInfo.md#ac160a64994059683a0fc0547ab734a87">timeStamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p982312653165632"><a name="p982312653165632"></a><a name="p982312653165632"></a>int64_t </p>
</td>
</tr>
<tr id="row2132332956165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264082805165632"><a name="p1264082805165632"></a><a name="p1264082805165632"></a><a href="OutputInfo.md#a6ad161decc8e676690c66d2a6dbde468">sequence</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158504775165632"><a name="p158504775165632"></a><a name="p158504775165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row1576201767165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111633634165632"><a name="p111633634165632"></a><a name="p111633634165632"></a><a href="OutputInfo.md#a56f914be981dd3a2f0ee8c65e501d8f1">flag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1025906160165632"><a name="p1025906160165632"></a><a name="p1025906160165632"></a>uint32_t </p>
</td>
</tr>
<tr id="row1023528704165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867157920165632"><a name="p1867157920165632"></a><a name="p1867157920165632"></a><a href="OutputInfo.md#ad3d70960789585a3b2014d83dddc448b">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762012206165632"><a name="p762012206165632"></a><a name="p762012206165632"></a><a href="Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79">CodecType</a> </p>
</td>
</tr>
<tr id="row306208981165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456354056165632"><a name="p456354056165632"></a><a name="p456354056165632"></a><a href="OutputInfo.md#a751ecb0c55401f130bf1a5b6492e1f38">vendorPrivate</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17319317165632"><a name="p17319317165632"></a><a name="p17319317165632"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section748509999165632"></a>

## **Field **<a name="section1953417827165632"></a>

## bufferCnt<a name="ac131b4abc43415f000a0750e82bb881d"></a>

```
uint32_t OutputInfo::bufferCnt
```

 **Description:**

Number of buffers 

## buffers<a name="a5a8cc2acb5f2918dde6fa60562e54d00"></a>

```
[CodecBufferInfo](CodecBufferInfo.md)* OutputInfo::buffers
```

 **Description:**

Pointer to the buffer description. For details, see  [CodecBufferInfo](CodecBufferInfo.md). 

## flag<a name="a56f914be981dd3a2f0ee8c65e501d8f1"></a>

```
uint32_t OutputInfo::flag
```

 **Description:**

Output flag 

## sequence<a name="a6ad161decc8e676690c66d2a6dbde468"></a>

```
uint32_t OutputInfo::sequence
```

 **Description:**

Corresponding input sequence number 

## timeStamp<a name="ac160a64994059683a0fc0547ab734a87"></a>

```
int64_t OutputInfo::timeStamp
```

 **Description:**

Output timestamp 

## type<a name="ad3d70960789585a3b2014d83dddc448b"></a>

```
[CodecType](Codec.md#ga03b4b6ae5fb82af68d46aaea3d3e4d79) OutputInfo::type
```

 **Description:**

Codec type 

## vendorPrivate<a name="a751ecb0c55401f130bf1a5b6492e1f38"></a>

```
void* OutputInfo::vendorPrivate
```

 **Description:**

Private information about a device vendor 

