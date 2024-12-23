# ArkUI子系统Changelog

## cl.arkui.1 当使用自定义组件名和内置属性重名时编译报错变更

**访问级别**

公开接口

**变更原因**

当使用自定义组件名和内置属性重名时，编译会根据指定的白名单进行拦截报错，如果白名单中不存在，编译就拦截不到，导致编译转换后的产物出现问题。

**变更影响**

该变更为不兼容变更。

举例说明，执行以下用例：

```ts
@Entry
@Component
struct enableAnalyzer {
  build() {
    Canvas()
      .enableAnalyzer((true))
  }
}
```

变更前：
不在白名单的内置组件属性与自定义组件重名时，编译没有拦截报错，导致运行时crash。

变更后：
在白名单的内置组件属性与自定义组件重名时，编译拦截报错。

![arkui_pg1](figures/arkui_pg1.PNG)

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.0.2.52开始。

**变更的接口/组件**

ArkUI 内置组件属性API。

**适配指导**

自定义组件名和内置组件属性重名时，编译报错，修改自定义组件名为其他非内置组件属性名即可解决。

修改前：

自定义组件enableAnalyzer和Canvas的enableAnalyzer重名。

```ts
@Entry
@Component
struct enableAnalyzer {
  build() {
    Canvas()
      .enableAnalyzer()
  }
}
```

修改后：

将自定义组件名改为任意不和内置组件重名的名称，如EnableAnalyzerComp。

```ts
@Entry
@Component
struct EnableAnalyzerComp {
  build() {
    Canvas()
      .enableAnalyzer()
  }
}
```

## cl.arkui.2 Toast和Popup/Menu同时存在时，点击Toast子窗不再关闭Popup/Menu

**访问级别**

公开接口

**变更原因**

子窗口中显示Popup/Menu，弹出与其有相同父窗口的Toast时，Toast窗口上的点击事件会关闭Popup/Menu。

**变更影响**

该变更为不兼容变更。

变更前：点击Toast窗口时，会主动关闭与其有相同父窗口的Popup/Menu。

变更后：点击Toast窗口时，不再主动关闭与其有相同父窗口的Popup/Menu。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.2.52开始。

**变更的接口/组件**

不涉及。

**适配指导**
默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
