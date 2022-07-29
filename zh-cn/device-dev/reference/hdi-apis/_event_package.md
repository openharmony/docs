# InputEventPackage


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [type](#type) | 输入事件的属性 | 
| [code](#code) | 输入事件的特定编码项 | 
| [value](#value) | 输入事件编码项对应的值 | 
| [timestamp](#timestamp) | 输入事件对应的时间戳 | 


## **详细描述**

Input事件数据包结构。


## **类成员变量说明**


### code

  
```
uint32_t EventPackage::code
```

**描述：**

输入事件的特定编码项


### timestamp

  
```
uint64_t EventPackage::timestamp
```

**描述：**

输入事件对应的时间戳


### type

  
```
uint32_t EventPackage::type
```

**描述：**

输入事件的属性


### value

  
```
int32_t EventPackage::value
```

**描述：**

输入事件编码项对应的值
