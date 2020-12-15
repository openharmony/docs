# CodecBufferInfo<a name="ZH-CN_TOPIC_0000001054879526"></a>

-   [Overview](#section299982411165630)
-   [Summary](#section1801142375165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section1041610524165630)
-   [Field](#section1222816335165630)
-   [addr](#ac41289afc743bdc85b266166d612e244)
-   [fd](#a8cad2128f76788aed9de86e69e78dd15)
-   [handle](#a11122e64c16864ce1d8129102905982a)
-   [length](#ac179611206a69c89d7c638e221ea159d)
-   [offset](#a6c0b23a5f242d80924f2e8689c83b3ae)
-   [size](#a9f02e97d2724dd93324d8e70793357b4)
-   [type](#a9b30909c247d03dfc94e4cfdcb69b13a)

## **Overview**<a name="section299982411165630"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Describes buffer information. 

## **Summary**<a name="section1801142375165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table769327844165630"></a>
<table><thead align="left"><tr id="row278611737165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p327129267165630"><a name="p327129267165630"></a><a name="p327129267165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p30097855165630"><a name="p30097855165630"></a><a name="p30097855165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1844689371165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800086472165630"><a name="p800086472165630"></a><a name="p800086472165630"></a><a href="CodecBufferInfo.md#a9b30909c247d03dfc94e4cfdcb69b13a">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2129907763165630"><a name="p2129907763165630"></a><a name="p2129907763165630"></a><a href="Codec.md#gadf8e136713c0691010d2bec6ba63e9cf">BufferType</a> </p>
</td>
</tr>
<tr id="row1386899135165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795641113165630"><a name="p795641113165630"></a><a name="p795641113165630"></a><strong id="ada7293f0c9daba22ad1e2a5c5e9be014"><a name="ada7293f0c9daba22ad1e2a5c5e9be014"></a><a name="ada7293f0c9daba22ad1e2a5c5e9be014"></a></strong> union {</p>
</td>
</tr>
<tr id="row312993344165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242034242165630"><a name="p1242034242165630"></a><a name="p1242034242165630"></a>   uint8_t *   <a href="CodecBufferInfo.md#ac41289afc743bdc85b266166d612e244">addr</a></p>
</td>
</tr>
<tr id="row118334558165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442791287165630"><a name="p442791287165630"></a><a name="p442791287165630"></a>   int32_t   <a href="CodecBufferInfo.md#a8cad2128f76788aed9de86e69e78dd15">fd</a></p>
</td>
</tr>
<tr id="row998879512165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1328775087165630"><a name="p1328775087165630"></a><a name="p1328775087165630"></a>   <a href="BufferHandle.md">BufferHandle</a>   <a href="CodecBufferInfo.md#a11122e64c16864ce1d8129102905982a">handle</a></p>
</td>
</tr>
<tr id="row1531893626165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1785762565165630"><a name="p1785762565165630"></a><a name="p1785762565165630"></a>}; </p>
<p id="p1937126278165630"><a name="p1937126278165630"></a><a name="p1937126278165630"></a>Describes the buffer address. </p>
</td>
</tr>
<tr id="row420480440165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171384613165630"><a name="p1171384613165630"></a><a name="p1171384613165630"></a><a href="CodecBufferInfo.md#a6c0b23a5f242d80924f2e8689c83b3ae">offset</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p478634835165630"><a name="p478634835165630"></a><a name="p478634835165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row576606627165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2060265035165630"><a name="p2060265035165630"></a><a name="p2060265035165630"></a><a href="CodecBufferInfo.md#ac179611206a69c89d7c638e221ea159d">length</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p698024008165630"><a name="p698024008165630"></a><a name="p698024008165630"></a>uint32_t </p>
</td>
</tr>
<tr id="row1695462870165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p312878251165630"><a name="p312878251165630"></a><a name="p312878251165630"></a><a href="CodecBufferInfo.md#a9f02e97d2724dd93324d8e70793357b4">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731012802165630"><a name="p731012802165630"></a><a name="p731012802165630"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1041610524165630"></a>

## **Field **<a name="section1222816335165630"></a>

## addr<a name="ac41289afc743bdc85b266166d612e244"></a>

```
uint8_t* CodecBufferInfo::addr
```

 **Description:**

Virtual address 

## fd<a name="a8cad2128f76788aed9de86e69e78dd15"></a>

```
int32_t CodecBufferInfo::fd
```

 **Description:**

File descriptor 

## handle<a name="a11122e64c16864ce1d8129102905982a"></a>

```
[BufferHandle](BufferHandle.md) CodecBufferInfo::handle
```

 **Description:**

Data handle. For details, see  [BufferHandle](BufferHandle.md) 

## length<a name="ac179611206a69c89d7c638e221ea159d"></a>

```
uint32_t CodecBufferInfo::length
```

 **Description:**

Length of valid data 

## offset<a name="a6c0b23a5f242d80924f2e8689c83b3ae"></a>

```
uint32_t CodecBufferInfo::offset
```

 **Description:**

Buffer offset 

## size<a name="a9f02e97d2724dd93324d8e70793357b4"></a>

```
uint32_t CodecBufferInfo::size
```

 **Description:**

Total size of buffer blocks 

## type<a name="a9b30909c247d03dfc94e4cfdcb69b13a"></a>

```
[BufferType](Codec.md#gadf8e136713c0691010d2bec6ba63e9cf) CodecBufferInfo::type
```

 **Description:**

Buffer type 

