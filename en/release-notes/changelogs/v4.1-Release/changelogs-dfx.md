# DFX Subsystem Changelog

## cl.dfx.1 Change in Graphics Memory Size Measurement for HiDumper

**Access Level**

Other

**Reason for Change**

The original **graph** value in **hidumper --mem pid**, obtained by calling the API provided by RenderService, does not include the ION/DMA memory size.

**Change Impact**

When you run the **hidumper --mem pid** command to view the PSS memory of a specified process, the **graph** value is larger than that before the change.

**Change Since**

OpenHarmony SDK 4.1.6.7

**Key API/Component Changes**

HiDumper
Before change: The **graph** value returned from the **hidumper --mem pid** command is obtained by calling the API provided by RenderService.
After change: The **graph** value returned from the **hidumper --mem pid** command is obtained by reading the **/proc/process_dmabuf_info** node.

**Adaptation Guide**

No adaptation is required.
