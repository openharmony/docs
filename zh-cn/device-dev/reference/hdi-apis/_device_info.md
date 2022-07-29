# InputDeviceInfo


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [devIndex](#devindex) | 设备索引 |      
| [devType](#devtype) | 设备类型 |                       
| [chipInfo](#chipinfo)&nbsp;[CHIP_INFO_LEN] | 驱动芯片编码信息 | 
| [vendorName](#vendorname)&nbsp;[VENDOR_NAME_LEN] | 模组厂商名 |  
| [chipName](#chipname)&nbsp;[CHIP_NAME_LEN] | 驱动芯片型号 | 
| [attrSet](#attrset)| 设备属性。 |
| [abilitySet](#abilityset)| 设备能力属性。|



## **详细描述**

Input设备基础设备信息。


## **类成员变量说明**


### chipInfo

  
```
char InputDeviceInfo::chipInfo[CHIP_INFO_LEN]
```

**描述：**

驱动芯片编码信息。


### chipName

  
```
char InputDeviceInfo::chipName[CHIP_NAME_LEN]
```

**描述：**

驱动芯片型号。


### devIndex

  
```
uint32_t InputDeviceInfo::devIndex
```

**描述：**

设备索引。



### devType

  
```
uint32_t InputDeviceInfo::devType
```

**描述：**

设备类型。


### vendorName

  
```
char InputDeviceInfo::vendorName[VENDOR_NAME_LEN]
```

**描述：**

模组厂商名。


### attrSet

  
```
InputDevAttr InputDeviceInfo::attrSet
```

**描述：**

设备属性。


### abilitySet

  
```
InputDevAbility InputDeviceInfo::abilitySet
```

**描述：**

设备能力属性。