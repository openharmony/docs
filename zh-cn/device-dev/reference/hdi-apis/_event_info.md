# EventInfo


## **概述**

定义事件上报信息。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [appData](#appdata) | 设置回调时给入的上层实例。 | 
| [appDataLen](#appdatalen) | appData字节数。 | 
| [data1](#data1) | 事件上报携带的数据1。 | 
| [data2](#data2) | 事件上报携带的数据2。 | 
| [eventData](#eventdata) | 事件上报携带的数据信息。 | 
| [eventDataLen](#eventdatalen) | eventData字节数。 | 


## **类成员变量说明**


### appData

  
```
int8_t* EventInfo::appData
```

**描述：**

设置回调时给入的上层实例。


### appDataLen

  
```
uint32_t EventInfo::appDataLen
```

**描述：**

appData字节数。


### data1

  
```
uint32_t EventInfo::data1
```

**描述：**

事件上报携带的数据1。


### data2

  
```
uint32_t EventInfo::data2
```

**描述：**

事件上报携带的数据2。


### eventData

  
```
int8_t* EventInfo::eventData
```

**描述：**

事件上报携带的数据信息。


### eventDataLen

  
```
uint32_t EventInfo::eventDataLen
```

**描述：**

eventData字节数。
