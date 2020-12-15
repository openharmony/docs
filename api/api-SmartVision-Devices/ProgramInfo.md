# ProgramInfo<a name="ZH-CN_TOPIC_0000001055518124"></a>

-   [Overview](#section1946451835165635)
-   [Summary](#section255717250165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section400338988165635)
-   [Field](#section781250091165635)
-   [durationMs](#a652dc8e396a6c8337f24ef19a60ff8d5)
-   [programId](#a37665885745484c665fd7c3f7c4e0257)
-   [track](#a7464c64a9cdbd91debb2e0dc3ae494bd)
-   [trackNum](#a63ffbb3059e57c139cb3801c8188c662)

## **Overview**<a name="section1946451835165635"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines program information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section255717250165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1088376170165635"></a>
<table><thead align="left"><tr id="row1528553664165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p631475077165635"><a name="p631475077165635"></a><a name="p631475077165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p735479019165635"><a name="p735479019165635"></a><a name="p735479019165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1501546392165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1383653776165635"><a name="p1383653776165635"></a><a name="p1383653776165635"></a><a href="ProgramInfo.md#a37665885745484c665fd7c3f7c4e0257">programId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129305532165635"><a name="p1129305532165635"></a><a name="p1129305532165635"></a>int32_t </p>
</td>
</tr>
<tr id="row1186076671165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1530344703165635"><a name="p1530344703165635"></a><a name="p1530344703165635"></a><a href="ProgramInfo.md#a652dc8e396a6c8337f24ef19a60ff8d5">durationMs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282431321165635"><a name="p282431321165635"></a><a name="p282431321165635"></a>int64_t </p>
</td>
</tr>
<tr id="row429056876165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1761829345165635"><a name="p1761829345165635"></a><a name="p1761829345165635"></a><a href="ProgramInfo.md#a63ffbb3059e57c139cb3801c8188c662">trackNum</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p749018599165635"><a name="p749018599165635"></a><a name="p749018599165635"></a>uint32_t </p>
</td>
</tr>
<tr id="row440580596165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466572265165635"><a name="p466572265165635"></a><a name="p466572265165635"></a><a href="ProgramInfo.md#a7464c64a9cdbd91debb2e0dc3ae494bd">track</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744741994165635"><a name="p1744741994165635"></a><a name="p1744741994165635"></a><a href="TrackInfo.md">TrackInfo</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section400338988165635"></a>

## **Field **<a name="section781250091165635"></a>

## durationMs<a name="a652dc8e396a6c8337f24ef19a60ff8d5"></a>

```
int64_t ProgramInfo::durationMs
```

 **Description:**

Program duration 

## programId<a name="a37665885745484c665fd7c3f7c4e0257"></a>

```
int32_t ProgramInfo::programId
```

 **Description:**

Program index 

## track<a name="a7464c64a9cdbd91debb2e0dc3ae494bd"></a>

```
[TrackInfo](TrackInfo.md)* ProgramInfo::track
```

 **Description:**

Pointer to the array of current program information 

## trackNum<a name="a63ffbb3059e57c139cb3801c8188c662"></a>

```
uint32_t ProgramInfo::trackNum
```

 **Description:**

Number of tracks of the current program 

