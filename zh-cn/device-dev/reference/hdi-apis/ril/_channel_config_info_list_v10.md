# ChannelConfigInfoList


## 概述

通道配置信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [itemNum](#itemnum) | 编号  | 
| List&lt; struct [PhysicalChannelConfig](_physical_channel_config_v10.md) &gt; [channelConfigInfos](#channelconfiginfos) | 物理通道配置  | 
| int [flag](#flag) | 通道配置标识  | 


## 类成员变量说明


### channelConfigInfos

```
List<struct PhysicalChannelConfig> ChannelConfigInfoList::channelConfigInfos
```
**描述**

物理通道配置


### flag

```
int ChannelConfigInfoList::flag
```
**描述**

通道配置标识


### itemNum

```
int ChannelConfigInfoList::itemNum
```
**描述**

编号
