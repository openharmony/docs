# CodecComponentManager


## **概述**

Codec组件管理类接口定义。

主要提供以下功能:

- 获取Codec编解码组件数量以及编解码能力集表。

- 创建/销毁Codec组件。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([GetComponentNum](#getcomponentnum)&nbsp;)() | 获取Codec编解码组件数量。 | 
| ([GetComponentCapabilityList](#getcomponentcapabilitylist)&nbsp;)(CodecCompCapability&nbsp;\*capList,&nbsp;int32_t&nbsp;count) | 获取编解码能力集表。 | 
| ([CreateComponent](#createcomponent)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*\*component,&nbsp;char&nbsp;\*compName,&nbsp;void&nbsp;\*appData,&nbsp;int32_t&nbsp;appDataSize,&nbsp;struct&nbsp;CodecCallbackType&nbsp;\*callbacks) | 创建Codec组件实例。 | 
| ([DestroyComponent](#destroycomponent)&nbsp;)(struct&nbsp;CodecComponentType&nbsp;\*component) | 销毁组件实例。 | 


## **类成员变量说明**


### CreateComponent

  
```
int32_t(* CodecComponentManager::CreateComponent) (struct CodecComponentType **component, char *compName, void *appData, int32_t appDataSize, struct CodecCallbackType *callbacks)
```

**描述：**

创建Codec组件实例。

根据组件名称创建Codec组件实例。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| component | 输出参数，指向Codec组件的指针。 | 
| compName | 输入参数，组件名称。 | 
| appData | 输入参数，指向应用程序定义的值的指针，该值将在回调期间返回。 | 
| appDataSize | 输入参数，appData字节数。 | 
| callbacks | 输入参数，回调接口，指向OMX_CALLBACKTYPE结构的指针，详见[CodecCallbackType](_codec_callback_type.md)。 | 

**返回:**

HDF_SUCCESS 表示创建组件成功。

HDF_ERR_INVALID_PARAM 表示参数无效，创建组件失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，创建组件失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，创建组件失败。


### DestroyComponent

  
```
int32_t(* CodecComponentManager::DestroyComponent) (struct CodecComponentType *component)
```

**描述：**

销毁组件实例。

销毁指定的Codec组件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| component | 输入参数，需要销毁的Codec组件。 | 

**返回:**

HDF_SUCCESS 表示销毁组件成功。

HDF_ERR_INVALID_PARAM 表示参数无效，销毁组件失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，销毁组件失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，销毁组件失败。


### GetComponentCapabilityList

  
```
int32_t(* CodecComponentManager::GetComponentCapabilityList) (CodecCompCapability *capList, int32_t count)
```

**描述：**

获取编解码能力集表。

用户可通过此接口了解Codec模块提供了哪些编解码能力，对应的能力体现在[CodecCompCapability](_codec_comp_capability.md)结构体。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| capList | 输出参数，返回全部组件的能力集表[CodecCompCapability](_codec_comp_capability.md)。 | 
| count | 输入参数，编解码组件数量，由[GetComponentNum](#getcomponentnum)获得。 | 

**返回:**

HDF_SUCCESS 表示获取能力集表成功。

HDF_ERR_INVALID_PARAM 表示参数无效，获取能力集表失败。

HDF_ERR_INVALID_OBJECT 表示对象无效，获取能力集表失败。

HDF_ERR_MALLOC_FAIL 表示申请内存失败，获取能力集表失败。


### GetComponentNum

  
```
int32_t(* CodecComponentManager::GetComponentNum) ()
```

**描述：**

获取Codec编解码组件数量。

通过此接口获取Codec编解码组件数量，用来获取全部编解码能力集。

**返回:**

Codec编解码组件数量。
