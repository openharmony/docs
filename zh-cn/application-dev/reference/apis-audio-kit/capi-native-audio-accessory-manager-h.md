# native_audio_accessory_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明音频配件管理相关的接口。

该文件接口用于管理音频配件的创建、连接、断开和销毁等功能。

**引用文件：** <ohaudio/native_audio_accessory_manager.h>

**库：** libohaudio.so

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 26.0.0

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef bool (\*OH_AudioAccessory_SetNoiseReductionCallback)(OH_AudioAccessory *accessory, OH_AudioNoiseReductionMode mode)](#oh_audioaccessory_setnoisereductioncallback) | OH_AudioAccessory_SetNoiseReductionCallback | 音频配件降噪模式变更回调函数。 |
| [OH_AudioCommon_Result OH_AudioManager_GetAccessoryManager(OH_AudioAccessoryManager **outManager)](#oh_audiomanager_getaccessorymanager) | - | 获取音频配件管理器实例。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_CreateInput(OH_AudioAccessoryManager *manager, const OH_AudioAccessoryInfo *info, const OH_AudioAccessoryCapabilities *capabilities, OH_AudioAccessory_OpenInputStreamCallback openInputStream, OH_AudioAccessory **outOwnedAccessory)](#oh_audioaccessorymanager_createinput) | - | 创建音频配件实例，并设置其支持的音频流能力。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_SetAssociatedMacAddresses(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, const char **macAddresses, uint32_t count)](#oh_audioaccessorymanager_setassociatedmacaddresses) | - | 设置与主音频配件组合使用的副配件MAC地址列表。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_RegisterNoiseReductionCapability(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, const OH_AudioAccessoryNoiseReductionCapability *capability, OH_AudioAccessory_SetNoiseReductionCallback onNoiseReduction)](#oh_audioaccessorymanager_registernoisereductioncapability) | - | 注册音频配件的降噪能力。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_SetNoiseReductionMode(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, OH_AudioNoiseReductionMode mode)](#oh_audioaccessorymanager_setnoisereductionmode) | - | 设置音频配件的降噪模式。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_Connected(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)](#oh_audioaccessorymanager_connected) | - | 将音频配件连接到音频系统。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_Disconnected(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)](#oh_audioaccessorymanager_disconnected) | - | 断开音频配件连接。 |
| [OH_AudioCommon_Result OH_AudioAccessoryManager_Destroy(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)](#oh_audioaccessorymanager_destroy) | - | 销毁音频配件实例。 |

## 函数说明

### OH_AudioAccessory_SetNoiseReductionCallback()

```c
typedef bool (*OH_AudioAccessory_SetNoiseReductionCallback)(OH_AudioAccessory *accessory, OH_AudioNoiseReductionMode mode)
```

**描述**

音频配件降噪模式变更回调函数。

触发时机：当配件的降噪模式发生变更时触发，此回调可以在配件连接后的任意时间触发。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 音频配件。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) mode | 配件当前的降噪模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true：请求的降噪模式处理成功。<br>false：请求的降噪模式处理失败。 |

### OH_AudioManager_GetAccessoryManager()

```c
OH_AudioCommon_Result OH_AudioManager_GetAccessoryManager(OH_AudioAccessoryManager **outManager)
```

**描述**

获取音频配件管理器实例。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) **outManager | 指向OH_AudioAccessoryManager指针的地址。该指针地址由系统管理，调用方不得释放，否则可能导致使用异常。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数outManager为NULL。 |

### OH_AudioAccessoryManager_CreateInput()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_CreateInput(OH_AudioAccessoryManager *manager, const OH_AudioAccessoryInfo *info, const OH_AudioAccessoryCapabilities *capabilities, OH_AudioAccessory_OpenInputStreamCallback openInputStream, OH_AudioAccessory **outOwnedAccessory)
```

**描述**

创建音频配件实例，并设置其支持的音频流能力。

> **说明：**
>
> - 此函数仅用于创建音频配件实例，不会创建任何输入流。
> - 函数执行成功时，系统通过outOwnedAccessory指针返回创建好的OH_AudioAccessory句柄。
> - 该音频配件实例需在不再使用时调用OH_AudioAccessoryManager_Destroy释放。
> - 当应用请求从该音频配件采集音频时，系统会触发openInputStream回调函数。
> - 在一个音频配件的生命周期内，输入流可能被创建和释放多次。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| const [OH_AudioAccessoryInfo](capi-ohaudio-oh-audioaccessoryinfo.md) *info | 指向配件基本信息的指针，不可为NULL。 |
| const [OH_AudioAccessoryCapabilities](capi-ohaudio-oh-audioaccessorycapabilities.md) *capabilities | 指向配件能力的指针，不可为NULL。 |
| OH_AudioAccessory_OpenInputStreamCallback openInputStream | 音频配件打开输入流的回调函数，不可为NULL。<br>此回调仅在应用请求从该音频配件采集音频时调用，而非在调用此函数时调用。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) **outOwnedAccessory | 指向OH_AudioAccessory指针的地址，用于接收创建好的音频配件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数无效，包括info为NULL、capabilities为NULL、openInputStream为NULL、outOwnedAccessory为NULL、info信息未全部填写、capabilities信息未全部填写，或outOwnedAccessory已通过OH_AudioAccessoryManager_CreateInput创建。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数manager未通过OH_AudioManager_GetAccessoryManager进行初始化。 |

### OH_AudioAccessoryManager_SetAssociatedMacAddresses()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_SetAssociatedMacAddresses(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, const char **macAddresses, uint32_t count)
```

**描述**

设置与主音频配件组合使用的副配件MAC地址列表。

> **说明：**
>
> - 此函数适用于多配件组合场景（如二合一、四合一），支持动态管理配件组合。
> - 初始化：配件创建后，调用此函数设置初始副配件列表。
> - 动态更新：副配件替换或断开连接时，调用此函数覆盖旧的MAC列表。
> - 线程安全：录音期间可安全调用。
> - 限制：此函数仅用于更新副配件MAC地址列表，不用于更新主配件MAC地址。主配件断开连接或主配件MAC地址变化时，应先断开并销毁原有配件句柄，再使用新的主配件信息重新创建配件实例。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向主配件句柄的指针。 |
| const char **macAddresses | 副配件MAC地址数组。<br>当count为0时可以为空，表示清除副配件MAC列表，适用于所有副配件断开连接的场景。<br>每个元素需符合以下规则：<br>- 格式为以冒号分隔的十六进制表示的NUL终止ASCII字符串。<br>  接受大写和小写十六进制数字（A-F / a-f）。<br>- 需为非空、非零长度字符串。<br>- 同一数组中的重复地址将被忽略，仅每个唯一地址的首次出现生效。 |
| uint32_t count | MAC地址数组中的元素数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数无效，包括manager为NULL、manager未通过OH_AudioManager_GetAccessoryManager进行初始化、accessory为NULL，或macAddresses传入的个数与count不一致。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_CreateInput创建。 |

### OH_AudioAccessoryManager_RegisterNoiseReductionCapability()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_RegisterNoiseReductionCapability(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, const OH_AudioAccessoryNoiseReductionCapability *capability, OH_AudioAccessory_SetNoiseReductionCallback onNoiseReduction)
```

**描述**

注册音频配件的降噪能力。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向通过OH_AudioAccessoryManager_CreateInput获取的音频配件实例。 |
| const [OH_AudioAccessoryNoiseReductionCapability](capi-ohaudio-oh-audioaccessorynoisereductioncapability.md) *capability | 指向降噪能力的指针，不可为NULL。 |
| OH_AudioAccessory_SetNoiseReductionCallback onNoiseReduction | 音频配件的降噪模式发生变更时调用的回调函数。<br>如果配件不支持动态模式切换，可以为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数无效，包括manager为NULL、manager未通过OH_AudioManager_GetAccessoryManager进行初始化、accessory为NULL、capability为NULL，或capability中的supportedModes为NULL或supportedModeCount为0。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_CreateInput创建。 |

### OH_AudioAccessoryManager_SetNoiseReductionMode()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_SetNoiseReductionMode(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory, OH_AudioNoiseReductionMode mode)
```

**描述**

设置音频配件的降噪模式。

> **说明：**
>
> - 此函数由配件关联的服务或应用来调用，用于将配件当前降噪模式同步到系统。
> - 通常在通过其他方式（如硬件按钮或配套应用）更改降噪模式时使用，以确保系统侧的降噪模式与配件实际降噪模式保持一致。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向通过OH_AudioAccessoryManager_CreateInput获取的音频配件实例。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) mode | 要设置的降噪模式。应为通过RegisterNoiseReductionCapability注册的模式之一。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数accessory为NULL。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_CreateInput创建，或未通过OH_AudioAccessoryManager_Connected连接。<br>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED：设置的降噪模式未通过OH_AudioAccessoryManager_RegisterNoiseReductionCapability注册。 |

### OH_AudioAccessoryManager_Connected()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_Connected(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)
```

**描述**

将音频配件连接到音频系统。

> **说明：**
>
> - 调用此函数前，需通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例，并通过OH_AudioAccessoryManager_CreateInput创建accessory实例。
> - 建议音频配件管理程序优先接入智慧生活应用，为用户提供设备发现与连接体验的一致性。
> - 若以独立音频配件管理应用方式，需要申请ACL权限ohos.permission.MANAGE_AUDIO_ACCESSORY。

**需要权限：** ohos.permission.MANAGE_AUDIO_ACCESSORY

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向通过OH_AudioAccessoryManager_CreateInput获取的音频配件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_PERMISSION_DENIED：调用方没有ohos.permission.MANAGE_AUDIO_ACCESSORY权限。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数无效，包括manager为NULL、manager未通过OH_AudioManager_GetAccessoryManager进行初始化，或accessory为NULL。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_CreateInput创建，或accessory已通过OH_AudioAccessoryManager_Connected连接。<br>AUDIOCOMMON_RESULT_ERROR_SYSTEM：音频服务进程死亡。 |

### OH_AudioAccessoryManager_Disconnected()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_Disconnected(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)
```

**描述**

断开音频配件连接。

**需要权限：** ohos.permission.MANAGE_AUDIO_ACCESSORY

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向通过OH_AudioAccessoryManager_CreateInput获取的音频配件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_PERMISSION_DENIED：调用方没有ohos.permission.MANAGE_AUDIO_ACCESSORY权限。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数accessory为NULL。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_Connected连接。<br>AUDIOCOMMON_RESULT_ERROR_SYSTEM：音频服务进程死亡。 |

### OH_AudioAccessoryManager_Destroy()

```c
OH_AudioCommon_Result OH_AudioAccessoryManager_Destroy(OH_AudioAccessoryManager *manager, OH_AudioAccessory *accessory)
```

**描述**

销毁音频配件实例。

> **说明：**
>
> 销毁前需先断开配件连接。

**起始版本：** 26.0.0

**参数：**

| 名称 | 描述 |
| -- | -- |
| [OH_AudioAccessoryManager](capi-ohaudio-oh-audioaccessorymanager.md) *manager | 指向通过OH_AudioManager_GetAccessoryManager获取的音频配件管理器实例。 |
| [OH_AudioAccessory](capi-ohaudio-oh-audioaccessory.md) *accessory | 指向通过OH_AudioAccessoryManager_CreateInput获取的音频配件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数无效，包括manager为NULL、manager未通过OH_AudioManager_GetAccessoryManager进行初始化，或accessory为NULL。<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：参数accessory未通过OH_AudioAccessoryManager_Disconnected断开连接。 |
