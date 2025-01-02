# NativeDisplayManager_CutoutInfo


## 概述

挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 12

**相关模块：**[OH_DisplayManager](_o_h___display_manager.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t  **boundingRectsLength** | 挖孔屏、刘海屏不可用屏幕区域长度。 | 
| [NativeDisplayManager_Rect](_native_display_manager___rect.md) \* **boundingRects** | 挖孔屏、刘海屏等区域的边界矩形。 | 
| [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) **waterfallDisplayAreaRects** | 瀑布屏曲面部分显示区域。 | 
