# JSVM_PropertyHandler


## 概述

包含将class作为函数进行调用时所触发的回调函数的函数指针和访问实例对象属性时触发的回调函数的函数指针集。

**起始版本：** 18

**相关模块：** [JSVM](_j_s_v_m.md)

**所在头文件：** [jsvm_types.h](jsvm__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_PropertyHandlerCfg](_j_s_v_m.md#jsvm_propertyhandlercfg) [propertyHandlerCfg](#propertyhandlercfg) | 访问实例对象属性触发相应的回调函数。  | 
| [JSVM_Callback ](_j_s_v_m.md#jsvm_callback) [callAsFunctionCallback](#callasfunctioncallback) | 将实例对象作为函数调用将触发此回调。  | 


## 结构体成员变量说明


### propertyHandlerCfg

```
JSVM_PropertyHandlerCfg JSVM_PropertyHandler::propertyHandlerCfg
```
**描述**
访问实例对象属性触发相应的回调函数。


### callAsFunctionCallback

```
JSVM_Callback JSVM_PropertyHandler::callAsFunctionCallback
```
**描述**
将实例对象作为函数调用将触发此回调。
