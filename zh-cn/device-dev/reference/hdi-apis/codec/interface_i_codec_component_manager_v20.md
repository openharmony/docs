# ICodecComponentManager


## 概述

Codec组件管理类接口定义。

主要提供以下功能:

- 获取Codec编解码组件数量以及编解码能力集表。

- 创建/销毁Codec组件。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetComponentNum](#getcomponentnum) ([out] int count) | 获取Codec编解码组件数量。  | 
| [GetComponentCapabilityList](#getcomponentcapabilitylist) ([out] struct [CodecCompCapability](_codec_comp_capability_v20.md)[] capList, [in] int count) | 获取编解码能力集表。  | 
| [CreateComponent](#createcomponent) ([out] [ICodecComponent](interface_i_codec_component_v20.md) component, [out] unsigned int componentId, [in] String compName, [in] long appData, [in] [ICodecCallback](interface_i_codec_callback_v20.md) callbacks) | 创建Codec组件实例。  | 
| [DestoryComponent](#destorycomponent) ([in] unsigned int componentId) | 销毁组件实例。  | 


## 成员函数说明


### CreateComponent()

```
ICodecComponentManager::CreateComponent ([out] ICodecComponent component, [out] unsigned int componentId, [in] String compName, [in] long appData, [in] ICodecCallback callbacks )
```
**描述**

创建Codec组件实例。

根据组件名称创建Codec组件实例。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| component | 指向Codec组件的指针。  | 
| componentId | 创建组件的Id。  | 
| compName | 组件名称。  | 
| appData | 指向应用程序定义的值的指针，该值将在回调期间返回。  | 
| callbacks | 回调接口，指向OMX_CALLBACKTYPE结构的指针，详见[ICodecCallback](interface_i_codec_callback_v20.md)。 | 

**返回：**

HDF_SUCCESS 表示创建组件成功。

HDF_ERR_INVALID_PARAM 表示参数无效，创建组件失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的[OMX_ERRORTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。


### DestoryComponent()

```
ICodecComponentManager::DestoryComponent ([in] unsigned int componentId)
```
**描述**

销毁组件实例。

销毁指定的Codec组件。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| componentId | 需要销毁的Codec组件。 | 

**返回：**

HDF_SUCCESS 表示销毁组件成功。

HDF_ERR_INVALID_PARAM 表示参数无效，销毁组件失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败，具体错误码详见OpenMAX IL定义的[OMX_ERRORTYPE](https://gitee.com/openharmony/third_party_openmax/blob/master/api/1.1.2/OMX_Core.h)。


### GetComponentCapabilityList()

```
ICodecComponentManager::GetComponentCapabilityList ([out] struct CodecCompCapability[] capList, [in] int count )
```
**描述**

获取编解码能力集表。

用户可通过此接口了解Codec模块提供了哪些编解码能力，对应的能力体现在[CodecCompCapability](_codec_comp_capability_v20.md)结构体。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capList | 返回全部组件的能力集表[CodecCompCapability](_codec_comp_capability_v20.md)。  | 
| count | 编解码组件数量，由[GetComponentNum](#getcomponentnum)获得。 | 

**返回：**

HDF_SUCCESS 表示获取能力集表成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取能力集表失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败。


### GetComponentNum()

```
ICodecComponentManager::GetComponentNum ([out] int count)
```
**描述**

获取Codec编解码组件数量。

通过此接口获取Codec编解码组件数量，用来获取全部编解码能力集。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| count | 编解码组件数量。 | 

**返回：**

HDF_SUCCESS 表示获取编解码组件数量成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取编解码组件数量失败。

HDF_FAILURE 表示执行失败。

其他值表示底层返回失败。
