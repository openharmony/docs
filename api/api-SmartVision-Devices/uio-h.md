# uio.h<a name="ZH-CN_TOPIC_0000001054909436"></a>

-   [Overview](#section1032301602165629)
-   [Summary](#section1240370983165629)
-   [Functions](#func-members)

## **Overview**<a name="section1032301602165629"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Provides functions and structures related to input/output \(I/O\) to a file or buffer. 

You can use the functions provided in this file to read files to the buffer or read information from the buffer to files.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1240370983165629"></a>

## Functions<a name="func-members"></a>

<a name="table123607200165629"></a>
<table><thead align="left"><tr id="row555294276165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1065755733165629"><a name="p1065755733165629"></a><a name="p1065755733165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p692208000165629"><a name="p692208000165629"></a><a name="p692208000165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1478070397165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117667655165629"><a name="p117667655165629"></a><a name="p117667655165629"></a><a href="IO.md#gaa1952d693ed3c43292566e643ceb9858">readv</a> (int fd, const struct iovec *iov, int iovcnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p493582529165629"><a name="p493582529165629"></a><a name="p493582529165629"></a>ssize_t </p>
<p id="p1868802826165629"><a name="p1868802826165629"></a><a name="p1868802826165629"></a>Reads the data of <strong id="b390336860165629"><a name="b390336860165629"></a><a name="b390336860165629"></a>fd</strong> to <strong id="b154771923165629"><a name="b154771923165629"></a><a name="b154771923165629"></a>iov</strong>. </p>
</td>
</tr>
<tr id="row48630726165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2081812668165629"><a name="p2081812668165629"></a><a name="p2081812668165629"></a><a href="IO.md#gad57f362a0aef72b52ea59288f74dd1ea">writev</a> (int fd, const struct iovec *iov, int iovcnt)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p286991094165629"><a name="p286991094165629"></a><a name="p286991094165629"></a>ssize_t </p>
<p id="p2051812593165629"><a name="p2051812593165629"></a><a name="p2051812593165629"></a>Writes a given length of data into a file. </p>
</td>
</tr>
<tr id="row1867000398165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1507417798165629"><a name="p1507417798165629"></a><a name="p1507417798165629"></a><a href="IO.md#ga94adc8dd94a6bdaaa9cf4d9f388418b3">preadv</a> (int fd, const struct iovec *iov, int iovcnt, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948650941165629"><a name="p948650941165629"></a><a name="p948650941165629"></a>ssize_t </p>
<p id="p1823910189165629"><a name="p1823910189165629"></a><a name="p1823910189165629"></a>Reads the data in a file whose <strong id="b899472408165629"><a name="b899472408165629"></a><a name="b899472408165629"></a>fd</strong> offset is <strong id="b1426123703165629"><a name="b1426123703165629"></a><a name="b1426123703165629"></a>offset</strong> to the multi-group buffer space pointed to by <strong id="b1854575530165629"><a name="b1854575530165629"></a><a name="b1854575530165629"></a>iov</strong>. </p>
</td>
</tr>
<tr id="row1027882860165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393774519165629"><a name="p393774519165629"></a><a name="p393774519165629"></a><a href="IO.md#ga3de6f9331d6bb930e748bb61860edbd6">pwritev</a> (int fd, const struct iovec *iov, int iovcnt, off_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1528771586165629"><a name="p1528771586165629"></a><a name="p1528771586165629"></a>ssize_t </p>
<p id="p872065487165629"><a name="p872065487165629"></a><a name="p872065487165629"></a>Writes the data of a multi-group buffer space pointed to by <strong id="b1388354449165629"><a name="b1388354449165629"></a><a name="b1388354449165629"></a>iov</strong> to the offset of <strong id="b1173850672165629"><a name="b1173850672165629"></a><a name="b1173850672165629"></a>fd</strong>. </p>
</td>
</tr>
</tbody>
</table>

