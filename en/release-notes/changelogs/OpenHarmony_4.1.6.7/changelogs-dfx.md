# DFX Subsystem Changelog

## Change in the Graphic Memory Statistics Method of HiDumper Component

**Access Level**

Other

**Reason for Change**

The Graph value in the **hidumper --mem pid** command was obtained by calling the API provided by RenderService, which could not access the corresponding ION/DMA memory.

**Change Impact**

After **hidumper --mem pid** is executed to view the Pss memory of a specified process, there will be an additional Graph value.

**Change Since**

OpenHarmony SDK 4.1.6.7

**Key API/Component Changes**

Affected Component: HiDumper

Before the change: After **hidumper --mem pid** is executed, the memory information's graph statistics were obtained by calling the API provided by RenderService.

After the change: After **hidumper --mem pid** is executed, the graph statistics in the memory information is obtained by reading from the **/proc/process_dmabuf_info** node.

**Adaptation Guide**

No adaptation is needed.
