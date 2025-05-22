# OH_ComponentSnapshot


## Overview

Provides APIs for obtaining component snapshots.

**Since**: 15

## Summary

### Structs

| Name| Description| 
| -------- | -------- |
| struct  [ArkUI_SnapshotOptions](native__type_8h.md#ArkUI_SnapshotOptions) | Defines a struct for snapshot options.| 

### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ArkUI_GetNodeSnapshot](native__node_8h.md#OH_ArkUI_GetNodeSnapshot) () | Obtains a snapshot of a given component. If the node is not in the component tree or has not been rendered, the snapshot operation will fail. When the **Pixelmap** object created is no longer in use, it should be released by calling **OH_PixelmapNative_Release**.| 
| ArkUI_SnapshotOptions [OH_ArkUI_CreateSnapshotOptions](native__type_8h.md#OH_ArkUI_CreateSnapshotOptions) () | Creates a snapshot options object, which must be released using **OH_ArkUI_SnapshotOptions_Dispose** when no longer in use.| 
| void [OH_ArkUI_DestroySnapshotOptions](native__type_8h.md#OH_ArkUI_DestroySnapshotOptions) () | Destroys a snapshot options object.| 
| int32_t [OH_ArkUI_SnapshotOptions_SetScale](native__type_8h.md#OH_ArkUI_SnapshotOptions_SetScale) () | Sets the scale property in the snapshot options.| 

### Creates a snapshot options object.

## Type Description

### ArkUI_SnapshotOptions

```
typedef struct ArkUI_SnapshotOptions ArkUI_SnapshotOptions;
```

**Description**

Defines a struct for snapshot options.

**Since**: 15

## Function Description

### OH_ArkUI_GetNodeSnapshot()

```
int32_t OH_ArkUI_GetNodeSnapshot(ArkUI_NodeHandle node, ArkUI_SnapshotOptions* snapshotOptions,
    OH_PixelmapNative** pixelMap)
```

**Description**

Obtains a snapshot of the specified node.

**Since**: 15

**Parameters**

| Name         |  Description                                                    |
| --------------- | ------------------------------------------------------------ |
| node            | Target node to capture a snapshot.                                            |
| snapshotOptions | Snapshot settings. If the value is null, the default settings are used.             |
| pixelmap        | Pointer to the Pixelmap created by the system.|

**Returns**

| Return Value                                       | Description          |
| --------------------------------------------- | -------------- |
| `ARKUI_ERROR_CODE_NO_ERROR`                   | Success.    |
| `ARKUI_ERROR_CODE_PARAM_INVALID`              | Parameter error.   |
| `ARKUI_ERROR_CODE_INTERNAL_ERROR`             | Snapshot failed. A null pointer is returned.    |
| `ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT` | Snapshot timed out.|


### OH_ArkUI_CreateSnapshotOptions()

```
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()
```

**Description**

Creates a snapshot options object, which must be released using **OH_ArkUI_SnapshotOptions_Dispose** when no longer in use.

**Since**: 15

**Returns**

| Return Value                  | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| `ArkUI_SnapshotOptions*` | Pointer to the created snapshot options object. If a null pointer is returned, creation failed, possibly due to insufficient memory.|


### OH_ArkUI_DestroySnapshotOptions()

```
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
```

**Description**

Destroys a snapshot options object.

**Since**: 15

**Parameters**

| Name        | Description        |
| --------------- | ---- |
| snapshotOptions | Screenshot options.|

### OH_ArkUI_SnapshotOptions_SetScale()

```
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
```

**Description**

Sets the scale property in the snapshot options.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| snapshotOptions | Screenshot options.|
| scale           | Scale factor.|

**Returns**

| Return Value                          | Description      |
| -------------------------------- | ---------- |
| `ARKUI_ERROR_CODE_NO_ERROR`      | Success.|
| `ARKUI_ERROR_CODE_PARAM_INVALID` | Parameter error.<br> A possible cause is that mandatory parameters are left unspecified.|
