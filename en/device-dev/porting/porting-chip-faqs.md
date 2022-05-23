# FAQs<a name="EN-US_TOPIC_0000001153683024"></a>

## How Do I Mount the Heap Memory to the Kernel?<a name="section965418378552"></a>

-   The following table describes the macros for configuring the kernel heap memory. You can configure them as required in the  **target\_config.h**  file.

**Table  1**  Macros for configuring the kernel heap memory

<a name="table04172020563"></a>
<table><thead align="left"><tr id="row5462035616"><th class="cellrowborder" valign="top" width="39.12%" id="mcps1.2.3.1.1"><p id="p1456204569"><a name="p1456204569"></a><a name="p1456204569"></a>Macro</p>
</th>
<th class="cellrowborder" valign="top" width="60.88%" id="mcps1.2.3.1.2"><p id="p19502005618"><a name="p19502005618"></a><a name="p19502005618"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14522018560"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p35112025620"><a name="p35112025620"></a><a name="p35112025620"></a>LOSCFG_SYS_EXTERNAL_HEAP</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p5127138175710"><a name="p5127138175710"></a><a name="p5127138175710"></a>Specifies whether the internal kernel heap memory or the user heap memory will be used. The default value is <strong id="b161891157141719"><a name="b161891157141719"></a><a name="b161891157141719"></a>0</strong> and indicates that the internal heap memory whose size is <strong id="b116218121820"><a name="b116218121820"></a><a name="b116218121820"></a>0x10000</strong> will be used. If you want to use the external heap memory, set this macro to <strong id="b2744657141814"><a name="b2744657141814"></a><a name="b2744657141814"></a>1</strong>.</p>
</td>
</tr>
<tr id="row20514209567"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p5532017563"><a name="p5532017563"></a><a name="p5532017563"></a>LOSCFG_SYS_HEAP_ADDR</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p65520125619"><a name="p65520125619"></a><a name="p65520125619"></a>Specifies the start address of the kernel heap memory.</p>
</td>
</tr>
<tr id="row15302929115615"><td class="cellrowborder" valign="top" width="39.12%" headers="mcps1.2.3.1.1 "><p id="p113021529145612"><a name="p113021529145612"></a><a name="p113021529145612"></a>LOSCFG_SYS_HEAP_SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="60.88%" headers="mcps1.2.3.1.2 "><p id="p1030252965619"><a name="p1030252965619"></a><a name="p1030252965619"></a>Specifies the size of the kernel heap memory, that is, size of the memory block specified by <strong id="b1611815991419"><a name="b1611815991419"></a><a name="b1611815991419"></a>LOSCFG_SYS_HEAP_ADDR</strong>.</p>
</td>
</tr>
</tbody>
</table>

-   Note:

Ensure that the specified heap memory range is not used by other modules. Otherwise, functions of the heap memory will be damaged due to the heap memory corruption.

