# AudioMmapBufferDescripter<a name="ZH-CN_TOPIC_0000001290561152"></a>

## **概述**<a name="section522969628083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section1169147286083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table226034974083931"></a>
<table><thead align="left"><tr id="row1932155414083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1575883444083931"><a name="p1575883444083931"></a><a name="p1575883444083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p276337455083931"><a name="p276337455083931"></a><a name="p276337455083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1154874067083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606446559083931"><a name="p1606446559083931"></a><a name="p1606446559083931"></a><a href="_audio.md#ga38892498b9e3d4ca9bdbb41e47fbeff2">memoryAddress</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry753811063083931p0"><a name="entry753811063083931p0"></a><a name="entry753811063083931p0"></a>指向mmap缓冲区的指针。</p>
</td>
</tr>
<tr id="row1889271968083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476491563083931"><a name="p1476491563083931"></a><a name="p1476491563083931"></a><a href="_audio.md#gac084a700674ef590de8363069d5c7995">memoryFd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry16254840083931p0"><a name="entry16254840083931p0"></a><a name="entry16254840083931p0"></a>mmap缓冲区的文件描述符。</p>
</td>
</tr>
<tr id="row1407446637083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p259979244083931"><a name="p259979244083931"></a><a name="p259979244083931"></a><a href="_audio.md#gad12b5c342220fab8baea8607ca362fb9">totalBufferFrames</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1748754044083931p0"><a name="entry1748754044083931p0"></a><a name="entry1748754044083931p0"></a>缓冲区总大小，单位：帧。</p>
</td>
</tr>
<tr id="row276993280083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1007295010083931"><a name="p1007295010083931"></a><a name="p1007295010083931"></a><a href="_audio.md#gaf86c7c4794f9db29c5237c1e623c3790">transferFrameSize</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1763372754083931p0"><a name="entry1763372754083931p0"></a><a name="entry1763372754083931p0"></a>传输大小，单位：帧。</p>
</td>
</tr>
<tr id="row86848217083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946425668083931"><a name="p1946425668083931"></a><a name="p1946425668083931"></a><a href="_audio.md#ga9eef06a3e4938a8965041699d9bc4e5b">isShareable</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606174766083931"><a name="p1606174766083931"></a><a name="p1606174766083931"></a>mmap缓冲区是否可以在进程间共享。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1353032735083931"></a>

mmap缓冲区描述符。

