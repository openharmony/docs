# BufferStream<a name="EN-US_TOPIC_0000001055518082"></a>

-   [Overview](#section939158420165630)
-   [Summary](#section1466875558165630)
-   [Data Fields](#pub-attribs)
-   [Details](#section498541529165630)
-   [Field](#section151440637165630)
-   [GetReadableSize](#a24e47ffeb7e9c2a8e01f83ffb3a16407)
-   [handle](#ae2019a77aba73fa96d5a716155c7fb7f)
-   [ReadData](#af0c4387f21bba2c1f02a5310daa95a00)

## **Overview**<a name="section939158420165630"></a>

**Related Modules:**

[Format](format.md)

**Description:**

Defines the function for reading stream data. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1466875558165630"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table976936501165630"></a>
<table><thead align="left"><tr id="row1046523566165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2008007869165630"><a name="p2008007869165630"></a><a name="p2008007869165630"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1023077644165630"><a name="p1023077644165630"></a><a name="p1023077644165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2029404786165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818822082165630"><a name="p1818822082165630"></a><a name="p1818822082165630"></a><a href="bufferstream.md#af0c4387f21bba2c1f02a5310daa95a00">ReadData</a> )(void *<a href="bufferstream.md#ae2019a77aba73fa96d5a716155c7fb7f">handle</a>, uint8_t *data, int32_t size, int32_t timeOutMs, <a href="format.md#gacff079fdf8427c743f9197ea5be33a7f">DataFlags</a> *flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39435269165630"><a name="p39435269165630"></a><a name="p39435269165630"></a>int32_t(* </p>
<p id="p1988458567165630"><a name="p1988458567165630"></a><a name="p1988458567165630"></a>Reads data from streams, save the data to the buffer pointed by <strong id="b1059295911165630"><a name="b1059295911165630"></a><a name="b1059295911165630"></a>data</strong> with the specified <strong id="b1497910262165630"><a name="b1497910262165630"></a><a name="b1497910262165630"></a>size</strong>, and returns the size of the read data and type. </p>
</td>
</tr>
<tr id="row1999330275165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089599889165630"><a name="p2089599889165630"></a><a name="p2089599889165630"></a><a href="bufferstream.md#a24e47ffeb7e9c2a8e01f83ffb3a16407">GetReadableSize</a> )(const void *<a href="bufferstream.md#ae2019a77aba73fa96d5a716155c7fb7f">handle</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1281082419165630"><a name="p1281082419165630"></a><a name="p1281082419165630"></a>int32_t(* </p>
<p id="p1392032620165630"><a name="p1392032620165630"></a><a name="p1392032620165630"></a>Obtains the size of data that can be read. </p>
</td>
</tr>
<tr id="row138442628165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1211382201165630"><a name="p1211382201165630"></a><a name="p1211382201165630"></a><a href="bufferstream.md#ae2019a77aba73fa96d5a716155c7fb7f">handle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733505623165630"><a name="p733505623165630"></a><a name="p733505623165630"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section498541529165630"></a>

## **Field **<a name="section151440637165630"></a>

## GetReadableSize<a name="a24e47ffeb7e9c2a8e01f83ffb3a16407"></a>

```
int32_t(* BufferStream::GetReadableSize) (const void *[handle](bufferstream.md#ae2019a77aba73fa96d5a716155c7fb7f))
```

 **Description:**

Obtains the size of data that can be read. 

Before reading data, you should call this function to check whether there is data to read.

**Parameters:**

<a name="table1772193989165630"></a>
<table><thead align="left"><tr id="row832346728165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p346323288165630"><a name="p346323288165630"></a><a name="p346323288165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1100700483165630"><a name="p1100700483165630"></a><a name="p1100700483165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2000575421165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the context handle. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the read data. 

## handle<a name="ae2019a77aba73fa96d5a716155c7fb7f"></a>

```
void* BufferStream::handle
```

 **Description:**

Context handle 

## ReadData<a name="af0c4387f21bba2c1f02a5310daa95a00"></a>

```
int32_t(* BufferStream::ReadData) (void *[handle](bufferstream.md#ae2019a77aba73fa96d5a716155c7fb7f), uint8_t *data, int32_t size, int32_t timeOutMs, [DataFlags](format.md#gacff079fdf8427c743f9197ea5be33a7f) *flags)
```

 **Description:**

Reads data from streams, save the data to the buffer pointed by  **data**  with the specified  **size**, and returns the size of the read data and type. 

**Parameters:**

<a name="table545953811165630"></a>
<table><thead align="left"><tr id="row547699613165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p152632416165630"><a name="p152632416165630"></a><a name="p152632416165630"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p712347806165630"><a name="p712347806165630"></a><a name="p712347806165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1757451952165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the context handle. </td>
</tr>
<tr id="row939730681165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer to store the read data. The memory is allocated by the caller. </td>
</tr>
<tr id="row1612575276165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the available buffer memory. </td>
</tr>
<tr id="row1437058988165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOutMs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates read operation wait time. The value <strong id="b40029899165630"><a name="b40029899165630"></a><a name="b40029899165630"></a>0</strong> means no wait time. </td>
</tr>
<tr id="row1797389910165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the type of the read data, see <a href="format.md#gacff079fdf8427c743f9197ea5be33a7f">DataFlags</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the size of the read data. 

