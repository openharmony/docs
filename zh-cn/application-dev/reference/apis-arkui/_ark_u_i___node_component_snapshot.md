# OH_ComponentSnapshot


## 概述

本模块提供获取组件截图的能力。

**起始版本：** 16

## 汇总

### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [ArkUI_SnapshotOptions](native__type_8h.md#ArkUI_SnapshotOptions) | 截图选项。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_GetNodeSnapshot](native__node_8h#OH_ArkUI_GetNodeSnapshot) () | 获取给定组件的截图，若节点不在组件树上或尚未渲染，截图操作将会失败。当pixelmap不再使用时，应通过调用OH_PixelmapNative_Release来释放。 | 
| ArkUI_SnapshotOptions [OH_ArkUI_CreateSnapshotOptions](native__type_8h#OH_ArkUI_CreateSnapshotOptions) () | 创建一个截图选项，当返回值不再使用时必须通过`OH_ArkUI_SnapshotOptions_Dispose`释放。 | 
| void [OH_ArkUI_DestroySnapshotOptions](native__type_8h#OH_ArkUI_DestroySnapshotOptions) () | 销毁截图选项指针。 | 
| int32_t [OH_ArkUI_SnapshotOptions_SetScale](native__type_8h#OH_ArkUI_SnapshotOptions_SetScale) () | 配置截图选项中的缩放属性。 | 

### 创建快照选项

## 类型定义说明

### ArkUI_SnapshotOptions

```
typedef struct ArkUI_SnapshotOptions ArkUI_SnapshotOptions;
```

**描述**

定义截图的可选项。

**起始版本：** 16

## 函数说明

### OH_ArkUI_GetNodeSnapshot()

```
int32_t OH_ArkUI_GetNodeSnapshot(ArkUI_NodeHandle node, ArkUI_SnapshotOptions* snapshotOptions,
    OH_PixelmapNative** pixelMap)
```

**描述**

获取节点的快照像素图。

**起始版本：** 16

**参数:**

| 名称          |  参数                                                     |
| --------------- | ------------------------------------------------------------ |
| node            | 截图的目标节点。                                             |
| snapshotOptions | 给定的截图配置，为空时表示默认配置。              |
| pixelmap        | 通过系统创建的Pixelmap指针。 |

**返回：**

| 返回值                                        | 描述           |
| --------------------------------------------- | -------------- |
| `ARKUI_ERROR_CODE_NO_ERROR`                   | 成功。     |
| `ARKUI_ERROR_CODE_PARAM_INVALID`              | 函数参数异常。    |
| `ARKUI_ERROR_CODE_INTERNAL_ERROR`             | 截图失败，将返回空指针。     |
| `ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT` | 截图超时。 |


### OH_ArkUI_CreateSnapshotOptions()

```
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()
```

**描述**

创建一个截图选项，当返回值不再使用时必须通过`OH_ArkUI_SnapshotOptions_Dispose`释放。

**起始版本：** 16

**返回：**

| 返回值                   | 描述                                                         |
| ------------------------ | ------------------------------------------------------------ |
| `ArkUI_SnapshotOptions*` | 返回指向创建的截图选项对象的指针。如果对象返回空指针，则表示创建失败，失败的原因可能是地址空间已满。 |


### OH_ArkUI_DestroySnapshotOptions()

```
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
```

**描述**

销毁截图选项指针。

**起始版本：** 16

**参数:**

| 名称         | 描述         |
| --------------- | ---- |
| snapshotOptions | 截图选项。 |

### OH_ArkUI_SnapshotOptions_SetScale()

```
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
```

**描述**

配置截图选项中的缩放属性

**起始版本：** 16

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| snapshotOptions | 截图选项。 |
| scale           | 缩放值。 |

**返回：**

| 返回值                           | 描述       |
| -------------------------------- | ---------- |
| `ARKUI_ERROR_CODE_NO_ERROR`      | 成功。 |
| `ARKUI_ERROR_CODE_PARAM_INVALID` | 函数参数异常。<br> 异常原因：传入参数验证失败，参数不能为空。 |