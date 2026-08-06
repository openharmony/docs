# 状态管理错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)。

## 130000 addMonitor/clearMonitor非法目标对象

**错误信息**

The target is not a custom component instance or V2 class instance.

**错误描述**

[addMonitor](./js-apis-stateManagement.md#addmonitor20)/[clearMonitor](./js-apis-stateManagement.md#clearmonitor20)的目标对象参数不合法。

**可能原因**

目标对象不满足以下情况：
- [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的类（至少有一个[\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的变量）。
- [\@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2)装饰的自定义组件的实例。

**处理步骤**

确保addMonitor/clearMonitor的目标对象合法，详情请参见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。

## 130001 addMonitor/clearMonitor非法路径

**错误信息**

The path is invalid.

**错误描述**

addMonitor/clearMonitor的路径参数不合法。

**可能原因**

路径既不是string类型，也不是数组类型。

**处理步骤**

确保addMonitor/clearMonitor的路径合法，详情请参见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。

## 130002 addMonitor/clearMonitor非法回调方法

**错误信息**

addMonitor/clearMonitor failed because the monitorFunc is illegal, monitorFunc must be function or but cannot be an anonymous function.

**错误描述**

addMonitor/clearMonitor的回调方法参数不合法。

**可能原因**

回调方法不是function类型，或者是匿名function类型。

**处理步骤**

确保addMonitor/clearMonitor的回调方法合法，详情请参见[addMonitor/clearMonitor开发指南](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#限制条件)。

## 140001 applySync/flushUpdates/flushUIUpdates非法调用

**错误信息**

The function is not allowed to be called in @Computed.

**错误描述**

applySync/flushUpdates/flushUIUpdates接口在[\@Computed](../../ui/state-management/arkts-new-computed.md)装饰的getter方法内调用是不合法的。

**可能原因**

applySync/flushUpdates/flushUIUpdates接口在@Computed装饰的getter方法内被调用。@Computed装饰的getter方法用于派生值的计算，在其中调用这些接口会触发额外的状态刷新，破坏计算属性的求值逻辑，具体限制请参见[applySync/flushUpdates/flushUIUpdates接口限制条件](../../ui/state-management/arkts-new-applySync-flushUpdates-flushUIUpdates.md#限制条件)。

**处理步骤**

确保在@Computed装饰的getter方法内没有调用applySync/flushUpdates/flushUIUpdates接口。

## 140002 flushUpdates/flushUIUpdates非法调用

**错误信息**

The function is not allowed to be called in @Monitor.

**错误描述**

flushUpdates/flushUIUpdates接口在[\@Monitor](../../ui/state-management/arkts-new-monitor.md)回调方法内调用是不合法的。

**可能原因**

flushUpdates/flushUIUpdates接口在@Monitor回调方法内被调用。@Monitor的回调方法在状态变化时被触发，在其中调用这些接口会导致重复的状态刷新，可能引发循环更新，具体限制请参见[applySync/flushUpdates/flushUIUpdates接口限制条件](../../ui/state-management/arkts-new-applySync-flushUpdates-flushUIUpdates.md#限制条件)。

**处理步骤**

确保在@Monitor回调方法内没有调用flushUpdates/flushUIUpdates接口。

## 140103 AppStorageV2和PersistenceV2使用不支持的数据类型

**错误信息**

Not supported type! The type should have function constructor signature.

**错误描述**

使用[AppStorageV2](./js-apis-stateManagement.md#appstoragev2)的[connect](./js-apis-stateManagement.md#connect)或[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[connect](./js-apis-stateManagement.md#connect)和[globalConnect](./js-apis-stateManagement.md#globalconnect18)时，type参数类型不合法。

**可能原因**

使用AppStorageV2的connect或PersistenceV2的connect和globalConnect时，type参数类型不是[TypeConstructorWithArgs\<T\>](./js-apis-stateManagement.md#typeconstructorwithargst)类型。

**处理步骤**

确保connect/globalConnect传入的type为TypeConstructorWithArgs\<T\>类型，具体支持类型见[PersistenceV2使用限制](../../ui/state-management/arkts-new-persistencev2.md#使用限制)和[AppStorageV2使用限制](../../ui/state-management/arkts-new-appstoragev2.md#使用限制)。

## 140104 AppStorageV2和PersistenceV2使用非法的默认值创建函数

**错误信息**

The default creator should be function when first connect.

**错误描述**

首次使用[AppStorageV2](./js-apis-stateManagement.md#appstoragev2)的[connect](./js-apis-stateManagement.md#connect)或[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[connect](./js-apis-stateManagement.md#connect)和[globalConnect](./js-apis-stateManagement.md#globalconnect18)时，defaultCreator默认数据的构造器不是[StorageDefaultCreator\<T\>](./js-apis-stateManagement.md#storagedefaultcreatort)。

**可能原因**

defaultCreator不是StorageDefaultCreator\<T\>类型。

**处理步骤**

确保connect/globalConnect传入的defaultCreator为StorageDefaultCreator\<T\>类型。以globalConnect为例，示例请参考[globalConnect](./js-apis-stateManagement.md#globalconnect18)。

## 140105 PersistenceV2混用connect和globalConnect并使用相同的key

**错误信息**

ERROR, Duplicate key used when connect

**错误描述**

[connect](./js-apis-stateManagement.md#connect)和[globalConnect](./js-apis-stateManagement.md#globalconnect18)使用相同的key。

**可能原因**

connect和globalConnect使用了相同的key。

**处理步骤**

不建议混用connect和globalConnect；如确需混用，请确保这两个接口不使用相同的key。详情请参见[PersistenceV2使用限制](../../ui/state-management/arkts-new-persistencev2.md#使用限制)。

## 140106 使用PersistenceV2存储数据到不支持的加密级别

**错误信息**

AreaMode Value Error! value range can only in EL1-EL5

**错误描述**

使用[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[globalConnect](./js-apis-stateManagement.md#globalconnect18)存储数据设置的加密级别不在EL1-EL5范围内。

**可能原因**

设置globalConnect参数[ConnectOptions](./js-apis-stateManagement.md#connectoptionst18)的[areaMode](./js-apis-stateManagement.md#connectoptionst18)属性范围不在EL1-EL5内。

**处理步骤**

设置加密级别范围为EL1-EL5，示例请参考[使用globalConnect存储数据](../../ui/state-management/arkts-new-persistencev2.md#使用globalconnect存储数据)。

## 140107 AppStorageV2和PersistenceV2数据类型不匹配

**错误信息**

The type of target mismatches the type of source.

**错误描述**

使用[AppStorageV2](./js-apis-stateManagement.md#appstoragev2)的[connect](./js-apis-stateManagement.md#connect)或[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[connect](./js-apis-stateManagement.md#connect)和[globalConnect](./js-apis-stateManagement.md#globalconnect18)时，发生类型不匹配错误。

**可能原因**

- type类型和defaultCreator返回类型不一致。
- 开发者修改了持久化的数据结构，导致重新从磁盘里读取数据到内存中时，发生类型不匹配。该情况仅通过日志上报错误码，不会抛出运行时异常。

**处理步骤**

- 确保type类型和defaultCreator返回类型一致。
- 需要保证数据持久化前后类型不变。如果要改变类型，需要手动卸载应用，清空当前应用持久化的数据，并再次安装。

## 140108 PersistenceV2缺少@Type装饰器

**错误信息**

Miss @Type.

**错误描述**

[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[globalConnect](./js-apis-stateManagement.md#globalconnect18)时，缺少[\@Type](../../ui/state-management/arkts-new-type.md)装饰器。

**可能原因**

使用globalConnect接口持久化数据时，持久化的数据类型缺少\@Type装饰器。该错误码通过日志上报，不会抛出运行时异常。

**处理步骤**

确保globalConnect持久化复杂类型时，用\@Type装饰类名。

## 140109 @Builder非法触发参数属性赋值

**错误信息**

@Builder: Invalid attempt to set(write to) parameter error!

**错误描述**

在[\@Builder](../../ui/state-management/arkts-builder.md)装饰的函数内部修改入参属性。

**可能原因**

在\@Builder装饰的函数内部修改入参属性，详情见[\@Builder限制条件](../../ui/state-management/arkts-builder.md#限制条件)。

**处理步骤**

不在\@Builder装饰的函数内部修改入参属性，可使用[MutableBinding](./js-apis-stateManagement.md#mutablebindingt20)代替，示例请参考[在@Builder装饰的函数内部修改入参内容](../../ui/state-management/arkts-builder.md#在builder装饰的函数内部修改入参内容)。

## 140110 在UI中使用非@Track装饰的属性发生运行时报错

**错误信息**

Illegal usage of not @Track'ed property on UI!

**错误描述**

如果类中有一个[\@Track](../../ui/state-management/arkts-track.md)装饰的属性，则禁止在UI中使用该类中未被@Track装饰的属性。

**可能原因**

将有\@Track装饰类中的未被\@Track装饰的属性绑定在UI上，详情见[\@Track限制条件](../../ui/state-management/arkts-track.md#限制条件)。

**处理步骤**

为报错信息中提示的属性添加\@Track装饰，示例请参考[在UI中使用非@Track装饰的属性发生运行时报错](../../ui/state-management/arkts-track.md#在ui中使用非track装饰的属性发生运行时报错)。

## 140112 @Consume缺失对应的@Provide

**错误信息**

@Consume missing @Provide property with name or default value. Fail to resolve @Consume.

**错误描述**

[\@Consume](../../ui/state-management/arkts-provide-and-consume.md)初始化失败，\@Consume没有找到匹配的[\@Provide](../../ui/state-management/arkts-provide-and-consume.md)数据源，且开发者没有提供\@Consume默认值。

**可能原因**

\@Consume寻找\@Provide失败，一般有以下两种原因：
1. \@Consume所在组件的父组件没有定义相同key的\@Provide，且\@Consume没有设置默认值，导致\@Consume初始化失败。
2. \@Consume向上查找定义\@Provide所在组件时，\@Consume所在组件的父组件或祖先节点已被销毁，导致\@Consume查找失败。

**处理步骤**

1. 确保初始化\@Consume时，其父组件上存在相同key的\@Provide变量，或设置默认值，示例见[\@Consume限制条件](../../ui/state-management/arkts-provide-and-consume.md#限制条件)。
2. 确保创建\@Consume所在组件时，父组件及其祖先节点生命周期未结束，即[aboutToDisappear](./arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear)未调用。

## 140113 复用\@ComponentV2自定义组件但工具链版本过低

**错误信息**

Old toolchain detected. Please upgrade to the latest.

**错误描述**

从API version 18开始，支持[\@Reusable](../../ui/state-management/arkts-reusable.md)（父组件）中创建[\@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2)（子组件），但需要开发者使用API version 18及以上SDK，否则会有运行时报错。从API version 23开始，将返回此错误码，详情见[\@ReusableV2使用限制](../../ui/state-management/arkts-new-reusableV2.md#使用限制)。

**可能原因**

从API version 18开始，支持\@Reusable（父组件）和\@ComponentV2（子组件）混用，开发者使用了API version 18及以上的设备，但没有使用API version 18及以上的SDK版本编译，所以运行时报错，提醒开发者SDK版本过低。

**处理步骤**

使用API version 18及以上的SDK编译应用。

## 140114 声明重复key的\@Provide

**错误信息**

duplicate @Provide property. Property with this name is provided by one of the ancestor Views already.

**错误描述**

在同一个组件、父组件或其祖先节点中，存在声明了相同的key的\@Provide，详情见[\@Provide限制条件](../../ui/state-management/arkts-provide-and-consume.md#限制条件)。

**可能原因**

在同一个组件、父组件或其祖先节点中，存在声明了相同的key的\@Provide。

**处理步骤**

保证在同一个组件，包括其父组件和其祖先节点中，\@Provide的key不同。或将相同key设置为可重写，即设置[ProvideOptions](./arkui-ts/ts-state-management-provide.md#provideoptions11)中的allowOverride参数，示例见[\@Provide支持allowOverride参数](../../ui/state-management/arkts-provide-and-consume.md#provide支持allowoverride参数)。

## 140115 状态管理V1状态变量使用了非法的类型

**错误信息**

Illegal variable value error with decorated variable

**错误描述**

创建状态管理V1状态变量时，使用了不支持的类型。

**可能原因**

使用V1状态变量装饰器（如@State、@Prop、@Link等）装饰了不支持的类型。

**处理步骤**

使用状态管理V1的状态变量支持的类型，以\@State为例，详情见[\@State装饰器使用规则说明](../../ui/state-management/arkts-state.md#装饰器使用规则说明)。

## 140116 AppStorageV2或PersistenceV2使用非法的key

**错误信息**

The key is invalid, key must be string or TypeConstructorWithArgs type.

**错误描述**

使用[AppStorageV2](./js-apis-stateManagement.md#appstoragev2)、[PersistenceV2](./js-apis-stateManagement.md#persistencev2)的[remove](./js-apis-stateManagement.md#remove)接口和PersistenceV2的[save](./js-apis-stateManagement.md#save)接口传入key不合法。

**可能原因**

key不是string或[TypeConstructorWithArgs\<T\>](./js-apis-stateManagement.md#typeconstructorwithargst)类型。

**处理步骤**

确保调用AppStorageV2、PersistenceV2的remove接口和PersistenceV2的save接口时传入的key参数为string或TypeConstructorWithArgs\<T\>类型。
