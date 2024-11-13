# InputDevAbility


## 概述

Input设备的能力属性，存储支持事件的位图。

用位的方式来表示该Input设备能够上报的事件类型。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [devProp](#devprop) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(INPUT_PROP_CNT)] | 设备属性  | 
| uint64_t [eventType](#eventtype) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(EV_CNT)] | 用于记录支持的事件类型的位图  | 
| uint64_t [absCode](#abscode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(ABS_CNT)] | 记录支持的绝对坐标的位图  | 
| uint64_t [relCode](#relcode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(REL_CNT)] | 记录支持的相对坐标的位图  | 
| uint64_t [keyCode](#keycode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(KEY_CNT)] | 记录支持的按键值的位图  | 
| uint64_t [ledCode](#ledcode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(LED_CNT)] | 记录设备支持的指示灯的位图  | 
| uint64_t [miscCode](#misccode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(MSC_CNT)] | 记录设备支持的其他功能的位图  | 
| uint64_t [soundCode](#soundcode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(SND_CNT)] | 记录设备支持的声音或警报的位图  | 
| uint64_t [forceCode](#forcecode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)([HDF_FF_CNT](_input.md#hdf_ff_cnt))] | 记录设备支持的作用力功能的位图  | 
| uint64_t [switchCode](#switchcode) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(SW_CNT)] | 记录设备支持的开关功能的位图  | 
| uint64_t [keyType](#keytype) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(KEY_CNT)] | 按键状态的位图  | 
| uint64_t [ledType](#ledtype) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(LED_CNT)] | led状态的位图  | 
| uint64_t [soundType](#soundtype) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(SND_CNT)] | 声音状态的位图  | 
| uint64_t [switchType](#switchtype) [[BITS_TO_UINT64](_input.md#bits_to_uint64)(SW_CNT)] | 开关状态的位图  | 


## 类成员变量说明


### absCode

```
uint64_t InputDevAbility::absCode[BITS_TO_UINT64(ABS_CNT)]
```
**描述**

记录支持的绝对坐标的位图


### devProp

```
uint64_t InputDevAbility::devProp[BITS_TO_UINT64(INPUT_PROP_CNT)]
```
**描述**

设备属性


### eventType

```
uint64_t InputDevAbility::eventType[BITS_TO_UINT64(EV_CNT)]
```
**描述**

用于记录支持的事件类型的位图


### forceCode

```
uint64_t InputDevAbility::forceCode[BITS_TO_UINT64(HDF_FF_CNT)]
```
**描述**

记录设备支持的作用力功能的位图


### keyCode

```
uint64_t InputDevAbility::keyCode[BITS_TO_UINT64(KEY_CNT)]
```
**描述**

记录支持的按键值的位图


### keyType

```
uint64_t InputDevAbility::keyType[BITS_TO_UINT64(KEY_CNT)]
```
**描述**

按键状态的位图


### ledCode

```
uint64_t InputDevAbility::ledCode[BITS_TO_UINT64(LED_CNT)]
```
**描述**

记录设备支持的指示灯的位图


### ledType

```
uint64_t InputDevAbility::ledType[BITS_TO_UINT64(LED_CNT)]
```
**描述**

led状态的位图


### miscCode

```
uint64_t InputDevAbility::miscCode[BITS_TO_UINT64(MSC_CNT)]
```
**描述**

记录设备支持的其他功能的位图


### relCode

```
uint64_t InputDevAbility::relCode[BITS_TO_UINT64(REL_CNT)]
```
**描述**

记录支持的相对坐标的位图


### soundCode

```
uint64_t InputDevAbility::soundCode[BITS_TO_UINT64(SND_CNT)]
```
**描述**

记录设备支持的声音或警报的位图


### soundType

```
uint64_t InputDevAbility::soundType[BITS_TO_UINT64(SND_CNT)]
```
**描述**

声音状态的位图


### switchCode

```
uint64_t InputDevAbility::switchCode[BITS_TO_UINT64(SW_CNT)]
```
**描述**

记录设备支持的开关功能的位图


### switchType

```
uint64_t InputDevAbility::switchType[BITS_TO_UINT64(SW_CNT)]
```
**描述**

开关状态的位图
