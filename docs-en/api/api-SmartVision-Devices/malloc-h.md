# malloc.h<a name="EN-US_TOPIC_0000001054948035"></a>

-   [Overview](#section1352232287165628)
-   [Summary](#section1287219182165628)
-   [Functions](#func-members)

## **Overview**<a name="section1352232287165628"></a>

**Related Modules:**

[MEM](mem.md)

**Description:**

Declares APIs for allocating and releasing memory. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1287219182165628"></a>

## Functions<a name="func-members"></a>

<a name="table1185964988165628"></a>
<table><thead align="left"><tr id="row1663039740165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p261415809165628"><a name="p261415809165628"></a><a name="p261415809165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p915582141165628"><a name="p915582141165628"></a><a name="p915582141165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row614668251165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p260418476165628"><a name="p260418476165628"></a><a name="p260418476165628"></a><a href="mem.md#ga7ac38fce3243a7dcf448301ee9ffd392">malloc</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453503247165628"><a name="p453503247165628"></a><a name="p453503247165628"></a>void * </p>
<p id="p1723787594165628"><a name="p1723787594165628"></a><a name="p1723787594165628"></a>Dynamically allocates a block of uninitialized memory with the specified size. </p>
</td>
</tr>
<tr id="row1707702576165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402699971165628"><a name="p1402699971165628"></a><a name="p1402699971165628"></a><a href="mem.md#ga62b7798461bd461da64c5f9d35feddf7">calloc</a> (size_t nmemb, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403563508165628"><a name="p403563508165628"></a><a name="p403563508165628"></a>void * </p>
<p id="p599269931165628"><a name="p599269931165628"></a><a name="p599269931165628"></a>Dynamically allocates multiple blocks of memory with the specified size. </p>
</td>
</tr>
<tr id="row590191480165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490562109165628"><a name="p490562109165628"></a><a name="p490562109165628"></a><a href="mem.md#ga1a6b5e8d2f1c37e5b43e4345586075be">realloc</a> (void *ptr, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574434863165628"><a name="p1574434863165628"></a><a name="p1574434863165628"></a>void * </p>
<p id="p1446092268165628"><a name="p1446092268165628"></a><a name="p1446092268165628"></a>Changes the size of a previously allocated memory block pointed to by <strong id="b1059166578165628"><a name="b1059166578165628"></a><a name="b1059166578165628"></a>ptr</strong> to the specified size. </p>
</td>
</tr>
<tr id="row1896349862165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735027096165628"><a name="p1735027096165628"></a><a name="p1735027096165628"></a><a href="mem.md#gafbedc913aa4651b3c3b4b3aecd9b4711">free</a> (void *ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138013928165628"><a name="p138013928165628"></a><a name="p138013928165628"></a>void </p>
<p id="p1544157151165628"><a name="p1544157151165628"></a><a name="p1544157151165628"></a>Frees the memory space pointed to by <strong id="b1176204384165628"><a name="b1176204384165628"></a><a name="b1176204384165628"></a>ptr</strong>. </p>
</td>
</tr>
<tr id="row85059283165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p225511766165628"><a name="p225511766165628"></a><a name="p225511766165628"></a><a href="mem.md#ga6a1c0668b7069bb45fd6e69f301ed5b9">memalign</a> (size_t alignment, size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771156510165628"><a name="p771156510165628"></a><a name="p771156510165628"></a>void * </p>
<p id="p1743597663165628"><a name="p1743597663165628"></a><a name="p1743597663165628"></a>Allocates a block of memory with the specified size based on the given alignment mode. </p>
</td>
</tr>
<tr id="row335131390165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668188981165628"><a name="p1668188981165628"></a><a name="p1668188981165628"></a><a href="mem.md#gaa011d7b7bfeba45c8c32e04204a0f565">malloc_usable_size</a> (void *ptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2029833001165628"><a name="p2029833001165628"></a><a name="p2029833001165628"></a>size_t </p>
<p id="p1963925310165628"><a name="p1963925310165628"></a><a name="p1963925310165628"></a>Obtains the size of the memory block pointed to by <strong id="b1234917359165628"><a name="b1234917359165628"></a><a name="b1234917359165628"></a>ptr</strong>. </p>
</td>
</tr>
</tbody>
</table>

