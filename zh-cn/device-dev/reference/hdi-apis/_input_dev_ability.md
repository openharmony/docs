# InputDevAbility


## 概述

Input设备的能力属性，存储支持事件的位图。

用位的方式来表示该Input设备能够上报的事件类型。

**相关模块:**

[Input](_input.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [devProp](#devprop)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(INPUT_PROP_CNT)] | uint64_t<br/>设备属性&nbsp; | 
| [eventType](#eventtype)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(EV_CNT)] | uint64_t<br/>用于记录支持的事件类型的位图&nbsp; | 
| [absCode](#abscode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(ABS_CNT)] | uint64_t<br/>记录支持的绝对坐标的位图&nbsp; | 
| [relCode](#relcode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(REL_CNT)] | uint64_t<br/>记录支持的相对坐标的位图&nbsp; | 
| [keyCode](#keycode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(KEY_CNT)] | uint64_t<br/>记录支持的按键值的位图&nbsp; | 
| [ledCode](#ledcode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(LED_CNT)] | uint64_t<br/>记录设备支持的指示灯的位图&nbsp; | 
| [miscCode](#misccode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(MSC_CNT)] | uint64_t<br/>记录设备支持的其他功能的位图&nbsp; | 
| [soundCode](#soundcode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(SND_CNT)] | uint64_t<br/>记录设备支持的声音或警报的位图&nbsp; | 
| [forceCode](#forcecode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)([HDF_FF_CNT](_input.md#hdf_ff_cnt))] | uint64_t<br/>记录设备支持的作用力功能的位图&nbsp; | 
| [switchCode](#switchcode)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(SW_CNT)] | uint64_t<br/>记录设备支持的开关功能的位图&nbsp; | 
| [keyType](#keytype)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(KEY_CNT)] | uint64_t<br/>按键状态的位图&nbsp; | 
| [ledType](#ledtype)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(LED_CNT)] | uint64_t<br/>led状态的位图&nbsp; | 
| [soundType](#soundtype)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(SND_CNT)] | uint64_t<br/>声音状态的位图&nbsp; | 
| [switchType](#switchtype)&nbsp;[[BITS_TO_UINT64](_input.md#bits_to_uint64)(SW_CNT)] | uint64_t<br/>开关状态的位图&nbsp; | 


## 类成员变量说明


### absCode

  
```
uint64_t InputDevAbility::absCode[BITS_TO_UINT64(ABS_CNT)]
```
**描述:**
记录支持的绝对坐标的位图


### devProp

  
```
uint64_t InputDevAbility::devProp[BITS_TO_UINT64(INPUT_PROP_CNT)]
```
**描述:**
设备属性


### eventType

  
```
uint64_t InputDevAbility::eventType[BITS_TO_UINT64(EV_CNT)]
```
**描述:**
用于记录支持的事件类型的位图


### forceCode

  
```
uint64_t InputDevAbility::forceCode[BITS_TO_UINT64(HDF_FF_CNT)]
```
**描述:**
记录设备支持的作用力功能的位图


### keyCode

  
```
uint64_t InputDevAbility::keyCode[BITS_TO_UINT64(KEY_CNT)]
```
**描述:**
记录支持的按键值的位图


### keyType

  
```
uint64_t InputDevAbility::keyType[BITS_TO_UINT64(KEY_CNT)]
```
**描述:**
按键状态的位图


### ledCode

  
```
uint64_t InputDevAbility::ledCode[BITS_TO_UINT64(LED_CNT)]
```
**描述:**
记录设备支持的指示灯的位图


### ledType

  
```
uint64_t InputDevAbility::ledType[BITS_TO_UINT64(LED_CNT)]
```
**描述:**
led状态的位图


### miscCode

  
```
uint64_t InputDevAbility::miscCode[BITS_TO_UINT64(MSC_CNT)]
```
**描述:**
记录设备支持的其他功能的位图


### relCode

  
```
uint64_t InputDevAbility::relCode[BITS_TO_UINT64(REL_CNT)]
```
**描述:**
记录支持的相对坐标的位图


### soundCode

  
```
uint64_t InputDevAbility::soundCode[BITS_TO_UINT64(SND_CNT)]
```
**描述:**
记录设备支持的声音或警报的位图


### soundType

  
```
uint64_t InputDevAbility::soundType[BITS_TO_UINT64(SND_CNT)]
```
**描述:**
声音状态的位图


### switchCode

  
```
uint64_t InputDevAbility::switchCode[BITS_TO_UINT64(SW_CNT)]
```
**描述:**
记录设备支持的开关功能的位图


### switchType

  
```
uint64_t InputDevAbility::switchType[BITS_TO_UINT64(SW_CNT)]
```
**描述:**
开关状态的位图
