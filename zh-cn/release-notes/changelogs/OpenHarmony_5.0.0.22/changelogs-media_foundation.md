# 媒体引擎组件 media_foundation 变更说明

## OH_AVFormat Set 接口行为变更

**访问级别**

公开接口

**变更原因**

OH_AVFormat 可传入多种类型的参数（int、long、float、double、string、buffer），开发者可能会使用错误的 Set 接口传值，而不会报错，相关的功能模块也因此获取不到相应的参数，导致效果问题发生，故在 OH_AVFormat Set 接口中添加参数类型校验逻辑，确保开发者正确的设置相关的参数。

**变更影响**

该变更为兼容性变更，影响仅为错误调用 Set 接口时，接口返回 false。

**起始 API Level**

API9

**变更发生版本**

API12

**变更的接口/组件**

| 名称                       | 描述                                    |
| -------------------------- | --------------------------------------- |
| OH_AVFormat_SetIntValue    | 使用此接口设置非 int 类型参数将会报错    |
| OH_AVFormat_SetLongValue   | 使用此接口设置非 long 类型参数将会报错   |
| OH_AVFormat_SetFloatValue  | 使用此接口设置非 float 类型参数将会报错  |
| OH_AVFormat_SetDoubleValue | 使用此接口设置非 double 类型参数将会报错 |
| OH_AVFormat_SetStringValue | 使用此接口设置非 string 类型参数将会报错 |
| OH_AVFormat_SetBuffer      | 使用此接口设置非 buffer 类型参数将会报错 |

**适配指导**

参考各参数的类型定义，正确的使用 OH_AVFormat 的 Set 接口传入参数。
