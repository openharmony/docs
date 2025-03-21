# avimage_generator_base.h


## 概述

定义AVImageGenerator的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**库：** libavimage_generator.so

**起始版本：** 18

**相关模块：**[AVImageGenerator](_a_v_image_generator.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AVImageGenerator_QueryOptions](_a_v_image_generator.md#oh_avimagegenerator_queryoptions) [OH_AVImageGenerator_QueryOptions](_a_v_image_generator.md#oh_avimagegenerator_queryoptions) | 指定时间点与视频帧对应关系的枚举。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVImageGenerator_QueryOptions](_a_v_image_generator.md#oh_avimagegenerator_queryoptions-1) {<br> OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC = 0,<br>  OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC = 1, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC = 2, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST = 3 } | 指定时间点与视频帧对应关系的枚举。  | 
