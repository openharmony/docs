# JSVM_PropertyHandler
<!--Kit: Common Basic Capability-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## 概述

包含将class作为函数进行调用时所触发的回调函数的函数指针，以及访问实例对象属性时触发的回调函数的函数指针集。

**起始版本：** 18

**相关模块：** [JSVM](capi-jsvm.md)

**所在头文件：** [jsvm_types.h](capi-jsvm-types-h.md)

## 汇总

### 成员变量

| 名称                                                                                                  | 描述 |
|-----------------------------------------------------------------------------------------------------| -- |
| [JSVM_PropertyHandlerCfg](capi-jsvm-jsvm-propertyhandlerconfigurationstruct8h.md) propertyHandlerCfg | 访问实例对象属性触发相应的回调函数。 |
| [JSVM_Callback](capi-jsvm-jsvm-callbackstruct8h.md) callAsFunctionCallback                                                            | 实例对象作为函数调用将触发此回调。 |


