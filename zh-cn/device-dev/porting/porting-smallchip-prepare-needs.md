# 移植须知


本文详细介绍如何将OpenHarmony小型系统的linux和LiteOS-A内核移植到新的开发板上，要求读者具有一定的嵌入式系统开发经验。建议先查看[入门指导](../../OpenHarmony-Overview_zh.md)，以了解OpenHarmony软件架构、目录结构、内核子系统和驱动子系统相关知识。当前小型系统已适配的开发板如下表所示：


  **表1** OpenHarmony小型系统已适配的开发板

| 开发板 | 内核 | arch | ROM | RAM | 文件系统 | Flash&nbsp;类型 |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| hispark_taurus | LiteOS-A和linux-4.19 | ARM&nbsp;cortex-a7 | 8G | 1GB | VFAT、EXT4 | eMMC4.5 |
| hispark_aries | LiteOS-A | ARM&nbsp;cortex-a7 | 16M | 512M | JFFS2 | SPI&nbsp;NOR |


表1中的开发板可作为待移植开发板的参考，当前LiteOS-A和linux-4.19支持的arch、ROM占用、支持的文件系统和支持的Flash类型如下表所示：


  **表2** OpenHarmony小型系统内核移植信息表

| 内核 | 支持的arch | ROM | 文件系统 | Flash类型 |
| -------- | -------- | -------- | -------- | -------- |
| LiteOS-A | ARMv7 | &gt;&nbsp;2M | VFAT、JFFS2、YAFFS2 | SPI&nbsp;NOR、NAND、EMMC |
| linux-4.19 | ARM，&nbsp;ARM64、&nbsp;MIPS、&nbsp;X86等 | &gt;&nbsp;5M | VFAT、JFFS2、YAFFS、EXT/2/3/4、NFS等等 | NOR、NAND、EMMC等 |
