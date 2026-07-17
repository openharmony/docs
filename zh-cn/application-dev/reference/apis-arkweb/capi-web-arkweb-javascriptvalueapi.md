# ArkWeb_JavaScriptValueAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_JavaScriptValueAPI
```

## 概述

ArkWeb_JavaScriptValueAPI是JavaScript相关Native API结构体。该结构体提供了创建JavaScript值的函数，支持将Native数据转换为JavaScript可识别的格式并返回给HTML。该转换机制根据指定的JavaScript值类型对Native数据缓冲区进行解析和封装，生成对应的JavaScript值对象。适用于需要从Native层向Web层传递数据的应用场景，能够实现Native与Web之间的双向数据交互，提升应用开发灵活性。

在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取JavaScript相关接口。调用前建议通过[ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#宏定义)校验函数指针的可用性，避免SDK与设备ROM不匹配导致崩溃。

**起始版本：** 18

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体的大小。 |

### 成员函数

| 名称                                                                                                                      | 描述 |
|-------------------------------------------------------------------------------------------------------------------------|----|
| [ArkWeb_JavaScriptValuePtr (\*createJavaScriptValue)(ArkWeb_JavaScriptValueType type, void* data, size_t dataLength)](#createjavascriptvalue) | 创建一个JavaScript值，用于返回给HTML。   |

## 成员函数说明

### createJavaScriptValue()

```c
ArkWeb_JavaScriptValuePtr (*createJavaScriptValue)(ArkWeb_JavaScriptValueType type, void* data, size_t dataLength)
```

**描述：**

创建一个JavaScript值，用于返回给HTML。该函数根据指定的type参数对data缓冲区中的数据进行类型转换和封装，生成对应的JavaScript值对象，转换失败时返回NULL。使用前需通过OH_ArkWeb_GetNativeAPI获取JavaScript接口，并建议校验函数指针可用性。

**起始版本：** 18

**参数：**

| 参数项                             | 描述                                                                      |
|---------------------------------|-------------------------------------------------------------------------|
| ArkWeb_JavaScriptValueType type | JavaScript值的类型。                                                         |
| void* data                                | JavaScript值的数据缓冲区。应按type对应的类型提供数据，内存由调用方管理并确保在返回前有效，对于无需数据的类型可传nullptr。 |
| size_t dataLength                         | JavaScript值的数据缓冲区所指向的字节数。应与data所指向缓冲区长度一致，当data为nullptr时，该值应设为0。         |

**返回：**

| 类型                            | 说明 |
|-------------------------------|----|
| [ArkWeb_JavaScriptValuePtr](capi-web-arkweb-javascriptvalue8h.md) | 创建出来的JavaScript值。当输入参数无效或内存分配失败时，返回NULL。 |

