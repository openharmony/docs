# ArkUI子系统ChangeLog

OpenHarmony 4.0.6.1 版本相较于OpenHarmony 之前的版本，Navigation、NavDestination 组件默认行为变更如下。

## Navigation、NavDestination组件默认扩展到非安全区

满足安全区可拓展的条件下，Navigation、NavDestination组件默认扩展到非安全区。

**访问级别**

公开接口

**变更影响**

变更前：Navigation、NavDestination组件的expandSafeArea属性默认为[SafeAreaExpandType.NONE, SafeAreaExpandEdges.NONE]。

变更后：Navigation、NavDestination组件的expandSafeArea属性默认为[SafeAreaExpandType.SYSTEM, SafeAreaExpandEdges.BOTTOM, SafeAreaEdge.TOP]，背景色延伸到顶部状态栏和底部导航栏。

**API Level**

11

**变更发生版本**

OpenHarmony SDK 4.0.6.1

**变更的接口/组件**

受影响组件有：Navigation与NavDestination

**适配指导**

默认行为变更，如果应用原先使用margin设置了Navigation或NavDestination的外边距，使其无法与顶部状态栏或底部导航栏贴边，会导致组件无法扩展到非安全区。若应用仍想生效沉浸式效果，则需要将margin改成padding，使导航组件与顶部状态栏或底部导航栏贴边，代码示例如下：

适配前：

```ts
@Entry
@Component
struct NavigationExample {
  build() {
    NavDestination() {
        ...
    }.margin({...})
  }
}
```

适配后：

```ts
@Entry
@Component
struct NavigationExample {
  build() {
    NavDestination() {
        ...
    }.padding({...})
  }
}
```