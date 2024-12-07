# IEffectModel


## 概述

音效模型接口。

提供音效模型支持的驱动能力，包括获取描述符列表、创建音效控制器、销毁音效控制器、获取指定描述符等

**起始版本：** 4.0

**相关模块：**[HdiEffect](_hdi_effect.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [IsSupplyEffectLibs](#issupplyeffectlibs) ([out] boolean supply) | 查询供应商/OEM是否提供效果库。 | 
| [GetAllEffectDescriptors](#getalleffectdescriptors) ([out] struct [EffectControllerDescriptor](_effect_controller_descriptor.md)[] descs) | 获取所有支持的音效的描述符。 | 
| [CreateEffectController](#createeffectcontroller) ([in]struct [EffectInfo](_effect_info.md) info, [out] [IEffectControl](interface_i_effect_control.md) contoller, [out] struct [ControllerId](_controller_id.md) id) | 创建一个用于操作音效实例的音效控制器。 | 
| [DestroyEffectController](#destroyeffectcontroller) ([in] struct [ControllerId](_controller_id.md) id) | 销毁控制器ID指定的音效控制器。 | 
| [GetEffectDescriptor](#geteffectdescriptor) ([in] String effectId, [out] struct [EffectControllerDescriptor](_effect_controller_descriptor.md) desc) | 获取指定音效的描述符。 | 


## 成员函数说明


### CreateEffectController()

```
IEffectModel::CreateEffectController ([in] struct EffectInfo info, [out] IEffectControl contoller, [out] struct ControllerId id )
```

**描述**

创建一个用于操作音效实例的音效控制器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| info | 音效信息。 | 
| contoller | 音效控制器对象。 | 
| contollerId | 音效控制器ID。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### DestroyEffectController()

```
IEffectModel::DestroyEffectController ([in] struct ControllerId id)
```

**描述**

销毁控制器ID指定的音效控制器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| contollerId | 音效控制器ID | 

**返回：**

执行成功返回0，执行失败返回其他值。


### GetAllEffectDescriptors()

```
IEffectModel::GetAllEffectDescriptors ([out] struct EffectControllerDescriptor[] descs)
```

**描述**

获取所有支持的音效的描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| descs | 音效描述符列表。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### GetEffectDescriptor()

```
IEffectModel::GetEffectDescriptor ([in] String effectId, [out] struct EffectControllerDescriptor desc )
```

**描述**

获取指定音效的描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| effectId | 音效ID。 | 
| desc | 指定音效的描述符。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### IsSupplyEffectLibs()

```
IEffectModel::IsSupplyEffectLibs ([out] boolean supply)
```

**描述**

查询供应商/OEM是否提供效果库。

如果提供，请使用提供的效果库。如果没有，请使用系统服务软件效果。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| supply | 供应商/OEM是否提供效果库的状态。 | 

**返回：**

执行成功返回0，执行失败返回其他值。
