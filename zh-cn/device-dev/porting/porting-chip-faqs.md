# 常见问题<a name="ZH-CN_TOPIC_0000001063192853"></a>

-   [如何将用户的堆内存挂载进内核](#section965418378552)

## 如何将用户的堆内存挂载进内核<a name="section965418378552"></a>

-   内核堆内存配置的相关宏如下，用户可根据实际情况，在target\_config.h中配置：

**表 1**  内核堆内存配置相关宏

<a name="table04172020563"></a>
<table><thead align="left"><tr id="row5462035616"><th class="cellrowborder" valign="top" width="39.12%" id="mcps1.2.3.1.1"><p id="p1456204569"><a name="p1456204569"></a><a name="p1456204569"></a>宏名称</p>
</th>
<th class="cellrowborder" valign="top" width="60.88%" id="mcps1.2.3.1.2"><p id="p19502005618"><a name="p19502005618"></a><a name="p19502005618"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row14522018560"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p35112025620"><a name="p35112025620"></a><a name="p35112025620"></a>LOSCFG_SYS_EXTERNAL_HEAP</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p5127138175710"><a name="p5127138175710"></a><a name="p5127138175710"></a>这个宏决定系统是使用内核的内部堆内存还是用户的堆内存，默认为0（即使用内部的堆内存），大小为0x10000；如果用户需要基于外部的堆内存，那么可以将该宏设置为1。</p>
</td>
</tr>
<tr id="row20514209567"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p5532017563"><a name="p5532017563"></a><a name="p5532017563"></a>LOSCFG_SYS_HEAP_ADDR</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p65520125619"><a name="p65520125619"></a><a name="p65520125619"></a>内核堆内存的起始地址。</p>
</td>
</tr>
<tr id="row15302929115615"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p113021529145612"><a name="p113021529145612"></a><a name="p113021529145612"></a>LOSCFG_SYS_HEAP_SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p1030252965619"><a name="p1030252965619"></a><a name="p1030252965619"></a>内核堆内存的大小，即LOSCFG_SYS_HEAP_ADDR指定的内存块大小。</p>
</td>
</tr>
</tbody>
</table>

-   注意事项：

指定的堆内存范围务必保证没有其他模块使用，避免踩内存，破坏堆内存功能。

