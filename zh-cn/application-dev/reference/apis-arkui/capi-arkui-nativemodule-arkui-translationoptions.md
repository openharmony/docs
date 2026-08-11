# ArkUI_TranslationOptions
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_TranslationOptions
```

## 概述

定义组件转场时平移效果的配置选项，用于设置组件在转场过程中横向、纵向和深度方向的平移距离。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type_visual.h](capi-native-type-visual-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float x | 横向的平移距离，单位为vp。取值原则：正值表示向右平移，负值表示向左平移，0表示不平移。默认值：0 |
| float y | 纵向的平移距离，单位为vp。取值原则：正值表示向下平移，负值表示向上平移，0表示不平移。默认值：0 |
| float z | 深度方向的平移距离，单位为vp。取值原则：正值表示向靠近观察者方向平移，负值表示向远离观察者方向平移，0表示不平移。z轴方向移动时由于观察点位置不变，z的值接近观察点组件会有放大效果，远离则缩小。默认值：0 |
