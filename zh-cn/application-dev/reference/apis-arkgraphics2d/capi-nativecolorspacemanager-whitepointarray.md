# WhitePointArray
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @xiaojianfeng_jeffery-->
<!--Designer: @dizuo1-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

```c
typedef struct {...} WhitePointArray
```

## 概述

提供白点数组结构体，白点是在当前色域中表示白色的坐标。

**起始版本：** 13

**相关模块：** [NativeColorSpaceManager](capi-nativecolorspacemanager.md)

**所在头文件：** [native_color_space_manager.h](capi-native-color-space-manager-h.md)

## 汇总

### 成员变量

| 名称         | 描述               |
| ------------ | ------------------ |
| float arr[2] | 表示白点坐标数组。arr[0]表示x坐标，arr[1]表示y坐标，用于在色域空间中精确定义白色基准点，影响色域的显示效果和颜色准确性。 |

