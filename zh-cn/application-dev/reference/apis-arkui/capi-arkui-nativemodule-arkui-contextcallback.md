# ArkUI_ContextCallback

## 概述

事件回调类型。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type.h](capi-native-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| void* userData | 自定义类型。 |


### 成员函数

| 名称 | 描述 |
| -- | -- |
| [void (\*callback)(void* userData)](#callback) | 事件回调。 |

## 成员函数说明

### callback()

```
void (*callback)(void* userData)
```

**描述：**


事件回调。


