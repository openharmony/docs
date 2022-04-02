# partition


## 命令功能

partition命令用来查看flash分区信息。


## 命令格式

partition [_nand / spinor_]


## 参数说明

  **表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| nand | 显示NAND&nbsp;Flash分区信息。 | N/A | 
| spinor | 显示SPI&nbsp;NOR&nbsp;Flash分区信息。 | N/A | 


## 使用指南

- partition命令用来查看flash分区信息。

- 仅当使能yaffs文件系统时才可以查看nand flash分区信息，使能jffs或romfs文件系统时可以查看spinor flash分区信息。


## 使用实例

举例：partition spinor


## 输出说明

查看spinor flash分区信息

  
```
OHOS # partition spinor
spinor partition num:0,  blkdev name:/dev/spinorblk0, mountpt:/, startaddr:0x00500000, length:0x00a00000
```
