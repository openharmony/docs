# fd\_set<a name="ZH-CN_TOPIC_0000001054598205"></a>

-   [Overview](#section1038682519165636)
-   [Summary](#section1126534124165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section518354676165636)
-   [Field](#section1185365104165636)
-   [fds\_bits](#af3253fd40c49cf37181639e903f16aba)

## **Overview**<a name="section1038682519165636"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Defines a file descriptor set. 

This structure is used to specify whether the file descriptor set exists. 

## **Summary**<a name="section1126534124165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1756642082165636"></a>
<table><thead align="left"><tr id="row2075120044165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1419960609165636"><a name="p1419960609165636"></a><a name="p1419960609165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1135088315165636"><a name="p1135088315165636"></a><a name="p1135088315165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row961508369165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955476841165636"><a name="p955476841165636"></a><a name="p955476841165636"></a><a href="fd_set.md#af3253fd40c49cf37181639e903f16aba">fds_bits</a> [<a href="IO.md#ga86c5dbf5a99358e288f573d6a1e0873f">FD_SETSIZE</a>/8/sizeof(long)]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381330619165636"><a name="p381330619165636"></a><a name="p381330619165636"></a>unsigned long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section518354676165636"></a>

## **Field **<a name="section1185365104165636"></a>

## fds\_bits<a name="af3253fd40c49cf37181639e903f16aba"></a>

```
unsigned long fd_set::fds_bits[[FD_SETSIZE](IO.md#ga86c5dbf5a99358e288f573d6a1e0873f)/8/sizeof(long)]
```

 **Description:**

Whether the descriptor exists is indicated by each bit. 

