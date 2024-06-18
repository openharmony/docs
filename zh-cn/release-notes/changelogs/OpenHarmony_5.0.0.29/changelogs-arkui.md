# ArkUI子系统Changelog

## cl.arkui.1 自定义弹窗避让软键盘行为优化

**访问级别**

公开接口

**变更原因**

从API version 12开始，将自定义弹窗避让软键盘行为优化为弹窗到达极限位置之后进行高度压缩。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，自定义弹窗避让软键盘时仅抬起软键盘对应高度，横屏等高度不足场景或自定义弹窗高度较大场景下，会出现弹窗超出屏幕显示的情况。

API version 12及以后，将自定义弹窗避让软键盘行为优化为弹窗到达极限位置之后进行高度压缩，而不会使弹窗超出极限位置显示。

**起始API Level**

CustomDialogController: API7
openCustomDialog(options: CustomDialogOptions): API11
openCustomDialog<T extends Object>(dialogContent: ComponentContent<T>, options?: promptAction.BaseDialogOptions): API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 版本开始。

**变更的接口/组件**

自定义弹窗

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.2 Badge组件显隐时增加缩放动效

**访问级别**

公开接口

**变更原因**

给Badge组件显隐时增加缩放动画，代替简单的出现与消失

**变更影响**

该变更为非兼容性变更。

API version 11及以前：Badge组件显隐时没有缩放动效。

API version 12及以后：Badge组件前后状态相同时不缩放，显隐时增加缩放动效。

**起始 API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.29开始。

**适配指导**

默认样式变更调整，无需适配。

## cl.arkui.3 TimePickerDialog、DatePickerDialog支持设置前导零

**访问级别**

公开接口

**变更原因**

开发者给TimePickerDialog、DatePickerDialog设置是否需要前导零。

**变更影响**

该变更为非兼容性变更。

1. 根据开发者的配置动态控制TimePickerDialog中的TimePicker小时选项是否需要前导零：当且仅当TimePickerDialog 是12小时制的且开发者设置需要前导零，TimePickerDialog 的小时选项中小于10的选项数值前才需要补零，否则不补零。24小时制小于10的选项数值默认有前导零，可以单独设置没有前导零。

2. 根据开发者的配置动态控制DatePickerDialog中的TimePicker小时选项是否需要前导零：当且仅当DatePickerDialog中的TimePicker是12小时制的且开发者设置需要前导零，DatePickerDialog中的TimePicker的小时选项中小于10的选项数值前才需要补零，否则不补零。24小时制小于10的选项数值默认有前导零，可以单独设置没有前导零。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.29开始。

**适配指导**

默认行为变更，无需适配，但应注意时间窗口是否按照设置显示前导零。

## cl.arkui.4 构造@ComponentV2修饰的自定义组件时，增加对常规变量的构造赋值校验

**访问级别**

公开接口

**变更原因**

该变更为非兼容性变更。

在@ComponentV2修饰的自定义组件中使用常规变量(没有任何装饰器修饰的，不涉及更新的普通变量)，在构造的时候传参赋值，进行校验并输出错误信息。

**变更影响**

执行下列用例：

```ts
@Entry
@ComponentV2
struct v2DecoratorInitFromParent {
  build() {
    Column() {
      testChild({
        regular_value: "hello"
      })
    }
  }
}

@ComponentV2
struct testChild {
  regular_value: string = "hello";
  build() {}
}
```

变更前无报错

变更后报错信息为：

Property 'regular_value' in the custom component 'testChild' cannot initialize here (forbidden to specify).

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony SDK 5.0.0.29开始。

**适配指导**

如果开发者不按规范使用对应范式，则需按日志提示信息进行修改。