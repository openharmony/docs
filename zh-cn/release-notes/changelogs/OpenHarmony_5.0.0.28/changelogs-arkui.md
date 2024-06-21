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

## cl.arkui.3 bindPopup在窗口失焦后不消失

**访问级别**

公开接口

**变更原因**

开发者不希望popup所在的窗口失去焦点后，popup会自动消失

**变更影响**

该变更为非兼容性变更。

变更前：
popup所在窗口失焦时，popup会自动消失。

变更后：
popup所在窗口失焦时，popup不会自动消失。


**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

气泡的关闭需要用户自行决定。如果出现之前版本某一操作后popup消失，现版本不消失的现象时，用户可以检查现象前后窗口焦点是否发生了变化，如果发生变化，现版本需要用户自行将isShow属性设置为false来关闭popup。

## cl.arkui.4 TextInput/TextArea组件设置宽度为auto时，最小值为16vp

**访问级别**

公开接口

**变更原因**

TextInput/TextArea组件设置宽度为auto并且内容为空时，组件消失。

**变更影响**

该变更为兼容性变更。

变更前：
TextInput/TextArea组件设置宽度为auto并且内容为空时，组件消失。

变更后：
TextInput/TextArea组件设置宽度为auto并且内容为空时，组件最小宽度为16vp。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.5 TextInput/TextArea组件设置为内联模式时，最小值为16vp

**访问级别**

公开接口

**变更原因**

TextInput/TextArea组件设置为内联模式并且内容为空时，组件消失。

**变更影响**

该变更为兼容性变更。

变更前：
TextInput/TextArea组件设置为内联模式并且内容为空时，组件消失。

变更后：
TextInput/TextArea组件设置为内联模式并且内容为空时，组件最小宽度为16vp。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.6 TextInput/TextArea组件在2in1设备上通过双击弹出菜单时，点击全选，菜单消失

**访问级别**

公开接口

**变更原因**

TextInput/TextArea组件在2in1上通过双击弹出菜单时，点击全选，此时无需菜单弹出。

**变更影响**

该变更为兼容性变更。

变更前：
TextInput/TextArea组件在2in1上通过双击弹出菜单时，点击全选，此时菜单弹出。

变更后：
TextInput/TextArea组件在2in1上通过双击弹出菜单时，点击全选，此时菜单消失。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.7 Menu组件默认样式变更

**访问级别**

公开接口

**变更原因**

优化menu组件的视觉体验。

**变更影响**

该变更为非兼容性变更。

变更前：
菜单列表的左右padding默认为

菜单项文本字重默认为regular

菜单组件圆角大小默认为16vp

对于带标题的菜单列表，标题文本大小默认为16fp

对于带标题的菜单列表，标题文本颜色默认为#89000000

对于带标题的菜单列表，标题文本字重默认为normal

变更后：
菜单列表的左右padding默认为16vp

菜单项文本字重默认为medium

菜单组件圆角大小默认为20vp

对于带标题的菜单列表，标题文本大小默认为18fp

对于带标题的菜单列表，标题文本颜色默认为#FF000000

对于带标题的菜单列表，标题文本字重默认为bold


**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.28开始。

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。