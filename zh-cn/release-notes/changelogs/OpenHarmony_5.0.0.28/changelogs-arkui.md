# ArkUI子系统Changelog

## cl.arkui.1 自定义组件struct装饰器校验信息优化

**访问级别**

公开接口

**变更原因**

之前的报错信息存在冗余，不易理解。

**变更影响**

该变更为兼容性变更。

变更前：
输出一个警告(WARN)和一个错误(ERROR)日志信息。
```
WARN: ArkTS:WARN File: xx
A struct should use decorator '@Component' or '@ComponentV2'.
ERROR: ArkTS:ERROR File:xx
'TestComponent()' does not meet UI component syntax.
```

变更后：
如果struct没有被(@Entry/@Preview/@ComponentV2/@Component/@CustomDialog/@Reusable)其中一个装饰器装饰，编译报错，只有一个错误(ERROR)日志信息。
```
ERROR: ArkTS:ERROR File:xx
Decorator '@Component', '@ComponentV2', or '@CustomDialog' is missing for struct 'TestComponent'.
```
错误示例如下：
```ts
struct Child {
  build() {
    Column() {
      Text("hello Child")
    }
  }
}

@Entry
@Component
struct Child {
  build() {
    Column() {
      Child()
    }
  }
}
```

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

如果应用代码未发生变化，则不需要适配。
## cl.arkui.2 增加方法装饰器的校验

**访问级别**

公开接口

**变更原因**

当开发者错误的使用多个方法装饰器装饰在同一个方法上时，会导致运行时异常，需要在编译阶段提前拦截。

**变更影响**

该变更为非兼容性变更。

变更前：
当不同的方法装饰器装饰在同一个方法时，编译无日志提示信息。

变更后：
当不同的方法装饰器装饰在同一个方法时，编译输出报错提示信息。
```
ERROR: ArkTS:ERROR File:xx
A function can only be decorated by one of the 'AnimatableExtend, Builder, Extend, Styles and Concurrent'.
ERROR: ArkTS:ERROR File:xx
The member property or method can not be decorated by multiple built-in decorators.
```

错误示例如下：
```ts
@Builder
@Styles
function testFunc() {
  Text("hello testFunc")
}

@Component
struct TestComponent {

  @Builder
  @Styles
  testMethod() {
    Text("hello testMethod")
  }

  build() {
    Column() {
      Text("hello TestComponent")
    }
  }
}
```

变更前：
当相同的内置方法装饰器(@AnimatableExtend/@Builder/@Extend/@Styles/@Concurrent)装饰在同一个方法时，编译无日志提示信息。

变更后：
当相同的内置方法装饰器(@AnimatableExtend/@Builder/@Extend/@Styles/@Concurrent)装饰在同一个方法时，编译输出警告日志提示信息。
```
WARN: ArkTS:WARN File: xx
Duplicate decorators for function are not allowed.
```

错误示例如下：
```ts
@Builder
@Builder
function testFunc() {
  Text("hello testFunc")
}
```

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

如果开发者不按规范使用对应范式，则需按日志提示信息进行修改。
