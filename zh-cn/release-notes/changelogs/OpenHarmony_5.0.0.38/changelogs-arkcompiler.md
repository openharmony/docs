# ArkCompiler子系统Changelog

## cl.arkcompiler.1 ArkTS napi_create_type_error result返回Error类型变更

**访问级别**

公开接口

**变更原因**

napi_create_type_error调用后result为Error，而不是预期的TypeError。表现与预期及ECMA规范不一致

**变更影响**

该变更为不兼容变更。


变更前：napi_create_type_error调用后result为Error

变更后：napi_create_type_error调用后result为TypeError


**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.38 开始。

**变更的接口/组件**

不涉及。

**适配指导**

使用napi_create_type_error得到的值类型由Error变更为TypeError，TypeError为Error的子类型。如果开发者对返回值类型做了判断，需要保证程序可以执行正确分支。

## cl.arkcompiler.2 ArkTS napi_create_range_error result返回Error类型变更

**访问级别**

公开接口

**变更原因**

napi_create_range_error调用后result为Error，而不是预期的RangeError。表现与预期及ECMA规范不一致

**变更影响**

该变更为不兼容变更。


变更前：napi_create_range_error调用后result为Error

变更后：napi_create_range_error调用后result为RangeError


**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.38 开始。

**变更的接口/组件**

不涉及。

**适配指导**

使用napi_create_type_error得到的值类型由Error变更为RangeError，RangeError为Error的子类型。如果开发者对返回值类型做了判断，需要保证程序可以执行正确分支。
