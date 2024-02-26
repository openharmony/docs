# arkcompiler子系统变更说明

## cl.arkcompiler.1 arkcompiler 热点函数中Sendable Class赋值检查修复

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