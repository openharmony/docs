# 语言编译器运行时变更说明

## cl.ArkCompiler.1 ArkTS语法规则变更

从OpenHarmony SDK版本4.1.5.5起，以下ArkTS语法规则发生变更。

**移除规则**

规则`arkts-no-decorators-except-arkui`、`arkts-no-side-effects-imports`和`arkts-no-regexp-literals`被移除。

**降级规则**

规则`arkts-no-globalthis`和`arkts-no-classes-as-obj`等级降为警告，不再阻塞工程编译。

规则`arkts-no-func-apply-bind-call`被拆分成以下两条：
1. `arkts-no-func-apply-call`，等级：错误
2. `arkts-no-func-bind`，等级：警告

相比于之前版本，报错代码和报错总数不变。

**放宽规则**

规则`arkts-identifiers-as-prop-names`放宽，支持属性名为字符串字面量或枚举中的字符串值。

以下代码不再报错。

```
enum Test {
  A = 'aaa',
  B = 'bbb'
}

let obj: Record<string, number> = {
  [Test.A]: 1,   // 枚举中的字符串值
  [Test.B]: 2,   // 枚举中的字符串值
  ['value']: 3   // 字符串字面量
}
```

**变更影响**

开发者无需适配代码，无兼容性影响。

## cl.ArkCompiler.2 三方包ts检查变更

**访问级别**

其它

**变更原因**

oh_modules目录下的三方包中的代码应符合ts语法规范。以前oh_modules目录下不符合ts语法规范的代码会报错，但由于代码实现的原因，从4.0.10.3版本开始未报错。目前该问题已修复，oh_modules目录下不符合ts语法规范的代码现在会报错。

**变更发生版本**

OpenHarmony SDK 4.1.5.5

**变更影响**

需要使用ts语法正确的三方包，若在三方包内添加了不符合ts语法规范的代码则编译会报错。

如在三方包代码中加入如下代码：
```
let a: string = 1;
```

编译时会报错：

```
Type 'number' is not assignable to type 'string'.
```

**适配指导**

使用符合ts语法规范的三方包，不能往三方包中添加不符合ts语法规范的代码。

## cl.arkcompiler.3 arkcompiler内部实现变更

arkcompiler内部实现变更

**引入版本**

OpenHarmony_4.1.6.1

**变更原因**

为实现ECMA2022 class新特性和sendable class特性，需新增字节码

**变更说明**

class 特性新增字节码：
1. `definefieldbyname`
2. `callruntime.definefieldbyvalue`
3. `callruntime.definefieldbyindex`
4. `callruntime.defineprivateproperty`
5. `callruntime.callinit`
6. `callruntime.createprivateproperty`
7. `callruntime.topropertykey`
8. `ldprivateproperty`
9. `stprivateproperty`
10. `testin`

sendable class新增字节码：
1. `callruntime.definesendableclass`
2. `callruntime.ldsendableclass`

**变更影响**

OpenHarmony SDK版本4.1.6.1增加新字节码，相关字节码实现需要对应版本ROM来支持。如果使用API11版本的ROM，4.1.6.1版本之前的ROM无法运行4.1.6.1版本SDK编译出的应用。

如果使用API 10版本的ROM以及4.1.6.1版本的SDK，开发者仍然可以通过IDE界面配置`compatiableSdkVersion: 10`选项，编译生成可以运行在API10 ROM上的应用。

**现象**

如未配套使用SDK和ROM，可能导致下列错误之一：

1. jsCrash: `Load file with filename '/data/storage/el1/bundle/entry/ets/module.abc' failed, recordName 'com.example.myapplication/entry/ets/entryability/EntryAbility' not exists` 伴随着hilog: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 9.0.0.0. Please upgrade the runtime to supported version or generate byte code with former SDK tools`

2. cppCrash: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 11.0.1.0. Please upgrade the system image or use former version of SDK tools to generate abc files`

**如何解决**

如遇到API11 SDK和ROM版本不匹配导致应用无法运行问题，请升级ROM版本至OpenHarmony_4.1.6.1及以上。

## cl.arkcompiler.4 arkcompiler AOT使能方式变更
**引入版本**

OpenHarmony_4.1.6.2

**变更原因**

AOT使能方式适配user版本

**变更影响**

该变更不属于非兼容性变更，新增对user版本使能AOT的方法

- 变更前：仅对root版本的ROM镜像支持AOT功能
- 变更后：新增对user版本的ROM镜像支持AOT功能

**API Level**

不涉及

**变更发生版本**

OpenHarmony_4.1.6.2

**变更的接口/组件**

arkcompiler AOT使能方式

**适配指导**

参见[AOT编译使用指南](https://gitee.com/openharmony/arkcompiler_ets_runtime/blob/master/docs/aot-guide_zh.md)

## cl.arkcompiler.5 arkcompiler 热点函数中Sendable Class赋值检查修复

**变更原因**

热点函数中Sendable Class赋值检查修复

**变更影响**

该变更为非兼容性变更。

- Sendable数据用于解决跨线程数据传递的性能问题。其使用介绍参见[@Sendable装饰器：声明并校验Sendable类](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/arkts-utils/arkts-sendable.md)。
- 部分约束在热点函数中未做检查，导致开发者能够绕过该约束
- 下面是本次变更涉及绕过的约束

    | \@Sendable类装饰器         | 说明                                                                   |
    | ------------------------- | ---------------------------------------------------------------------- |
    | 装饰的对象内的属性类型限制  | <b>支持string、number、boolean、SendableClass。</b>禁止使用闭包变量。不支持#定义私有属性，需用private。不支持计算属性。           |
  

- 对于违反**属性类型限制**的情况。
    - 变更前：程序正常运行，无错误
    - 变更后：程序在违反约束的点抛出异常，提醒开发者此处赋值类型不匹配，需要按照：[@Sendable装饰器：声明并校验Sendable类](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/arkts-utils/arkts-sendable.md) 中**装饰的对象内的属性类型限制**的要求进行适配

**API Level**

API11

**变更发生版本**

OpenHarmony_4.1.6.5

**变更的接口/组件**

@Sendable装饰器

**适配指导**

本次变更后，如在运行时发生类型不匹配异常，可能违反了本次修改涉及的使用约束，需要对赋值类型进行检查。详细说明，参见[@Sendable装饰器：声明并校验Sendable类](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/arkts-utils/arkts-sendable.md)

## cl.arkcompiler.6 sdk中ark_asm下线

**访问级别**

其他

**变更原因**

ark_asm工具最初设计是为了配合ts2abc编译生成abc文件。但随着技术演进，一方面该方案由于效率原因已经被其他方案替代；另一方面，ts2abc也已经被es2abc替代下线，因此ark_asm工具一直没有参与到应用编译或开发流程中。ark_asm工具下线后，开发者可以在sdk的toolchains目录下发现如下图所示的变更。

![stack](figures/api11_sdk_toolchains_component_change.png)

**变更影响**

该变更为兼容性变更。由于ark_asm并不参与应用编译或开发流程，升级该版本的sdk后，对开发者不会有任何影响。

**API Level**

11

**变更发生版本**

从Openharmony SDK 4.1.5.5 开始

**变更的接口/组件**

arkcompiler前端编译器中的ark_asm工具下线。

**适配指导**

不会造成任何影响，不需要做适配。