# arkui子系统ChangeLog

## cl.arkui.1 xcomponent组件接口变更

arkui子系统xcomponent组件接口存在变更：

 - 去除getXComponentSurfaceId和setXComponentSurfaceSize接口的@systemapi标签
 - 指定getXComponentSurfaceId，getXComponentContext和setXComponentSurfaceSize接口的返回值类型

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响已发布的JS接口，应用需要进行适配才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

 - getXComponentSurfaceId：改为public接口，指定返回值类型为string
 - setXComponentSurfaceSize：改为public接口，指定返回值类型为void
 - getXComponentContext：指定返回值类型为Object

**适配指导**

不同场景下的启动规则说明如下：
开发者适配内容：

  - **getXComponentSurfaceId**
    - OpenHarmony 3.2-beta3 版本规则：
      - 系统接口systemapi。
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 公共接口。
      - 指定返回值类型为string
      - 开发者需要按照string类型处理返回值
  - **setXComponentSurfaceSize**
    - OpenHarmony 3.2-beta3 版本规则：
      - 系统接口systemapi。
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 公共接口。
      - 指定返回值类型为void
      - 开发者需要按照void类型处理返回值
  - **getXComponentContext**
    - OpenHarmony 3.2-beta3 版本规则：
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 指定返回值类型为Object
      - 开发者需要按照Object类型处理返回值
        
## cl.arkui.2 弹窗类组件接口样式变更

ArkUI子系统alertDialog, actionSheet, customDialog组件及prompt, promptAction接口存在样式变更：

 - promptAction.showDialog, promptAction.showActionMenu, alertDialog, actionSheet, customDialog更新弹窗底板模糊效果

**变更影响**

默认弹窗底板模糊效果

**关键的接口/组件变更**

涉及接口: promptAction.showDialog, promptAction.showActionMenu;
涉及组件: alertDialog, actionSheet, customDialog

**适配指导**

无需适配

## cl.arkui.3 自定义组件成员变量初始化的方式与约束校验场景补全

自定义组件成员变量初始化规则此版本修复了某些遗漏场景的校验。


**变更影响**

如果未按照文档规范，进行自定义组件成员变量初始化赋值，编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

按文档提示修改。

## cl.arkui.4 自定义父子组件成员变量赋值约束校验场景补全

自定义父子组件成员变量赋值规则此版本修复了某些遗漏场景的校验。


**变更影响**

如果自定义父子组件成员变量初始化未按照文档规范，编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

按文档提示修改，使用其它装饰器变量或常规变量赋值。

## cl.arkui.5 单一子组件校验补全

对 'Button', 'FlowItem'，'GridItem'，'GridCol'，'ListItem'，'Navigator'，'Refresh'，'RichText'，'ScrollBar'，'StepperItem'，'TabContent'等只支持一个子组件的开启校验。


**变更影响**

如果上述组件内有超过一个子组件，编译报错。

**关键的接口/组件变更**

```js
RichText('RichText') {
    Text('Text1')
    Text('Text2')
}
/* ArkTS:ERROR File: /root/newOH/developtools/ace-ets2bundle/compiler/sample/pages/home.ets:25:7
 The component 'RichText' can only have a single child component. */
```

**适配指导**

按报错提示修改，指定组件内只能有一个子组件。
