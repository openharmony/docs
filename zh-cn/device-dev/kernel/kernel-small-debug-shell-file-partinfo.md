# partinfo


## 命令功能

partinfo命令用于查看系统识别的硬盘，SD卡多分区信息。


## 命令格式

partinfo &lt;_dev_inodename_&gt;


## 参数说明

  **表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| dev_inodename | 要查看的分区名字。 | 合法的分区名。 | 


## 使用指南

无


## 使用实例

举例：partinfo /dev/mmcblk0p0


## 输出说明

**示例** 查看系统分区信息


```
OHOS # partinfo /dev/mmcblk0p0
part info :
disk id          : 0
part_id in system: 1
part no in disk  : 0
part no in mbr   : 0
part filesystem  : 00
part sec start   : 20480
part sec count   : 102400
```
