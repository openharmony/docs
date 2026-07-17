# ArkWeb_JavaScriptObject
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_JavaScriptObject
```

## 概述

**ArkWeb_JavaScriptObject** 结构体用于向Web页面注入JavaScript代码并获取执行结果。适用于需要从原生应用主动调用Web页面中的JavaScript函数、读取Web页面状态或调用Web页面API的场景，可简化Web与原生应用间的数据交互流程。开发者可通过该结构体指定待注入的JavaScript脚本内容及长度，注册执行完成回调，并通过userData传递自定义上下文数据，实现Web与原生应用之间的数据交互。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                        | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| const uint8_t* buffer                                                                     | 注入的JavaScript代码。该缓冲区长度需与size参数一致。 |
| size_t size                                                                               | JavaScript代码长度。单位：字节。需与buffer的实际长度一致，否则可能导致越界或截断。 |
| [ArkWeb_OnJavaScriptCallback](capi-arkweb-type-h.md#arkweb_onjavascriptcallback) callback | JavaScript执行完成的回调。回调函数指针，可以传入NULL表示不需要回调。 |
| void* userData                                                                            | 需要在回调中携带的自定义数据。 |

