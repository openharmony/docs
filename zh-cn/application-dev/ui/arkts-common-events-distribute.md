# 事件分发

## 概述

ArkUI触控事件，根据输入源不同，主要划分为touch类与mouse类。

touch类的输入源包含：finger、pen

mouse类的输入源包含：mouse、touchpad、joystick

由这两类输入源可以触发如下事件：

| touch | mouse |
|:-----:| ----- |
| 触摸事件  | 触摸事件  |
| 点击事件  | 鼠标事件  |
| 拖拽事件  | 点击事件  |
| 手势事件  | 拖拽事件  |
|       | 手势事件  |

无论是touch类事件还是mouse类事件，在ArkUI框架上均由触摸测试发起，触摸测试直接决定了ArkUI事件响应链的生成及事件的分发。

## 触摸测试

触摸测试指手指或者鼠标光标按下时，基于当前触点所在位置测试命中了哪些组件，并收集整个事件响应链的过程。

如下是对触摸测试结果影响较大的几个因素：

- TouchTest：触摸测试入口方法，此方法无外部接口

- hitTestBehavior：触摸测试控制

- interceptTouch：事件自定义拦截

- responseRegion：触摸热区设置

- enabled：禁用控制

- 安全组件

- 其他属性设置：透明度/组件下线

### TouchTest

- TouchTest的触发时机由每次点按的按下动作发起，默认由组件树的根节点TouchTest方法作为入口。

- hitTestBehavior可以由InterceptTouch事件变更。

- 触摸热区/禁用控制等不满足组件事件交互诉求，会导致立即返回父节点。

  ![TouchTest](figures/TouchTest.png)

### 触摸测试控制

具体用法参考[触摸测试控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-hit-test-behavior.md)

- 命中：触摸测试成功收集到当前组件/子组件的事件。

- 子组件对父组件触摸测试的影响，取决于最后一个没有被阻塞触摸测试的子组件。

- HitTestMode.Default：默认不配hitTestBehavior属性的效果，自身如果命中会阻塞兄弟组件，但是不阻塞子组件。

  ![hitTestModeDefault](figures/hitTestModeDefault.png)

- HitTestMode.None：自身不接收事件，但不会阻塞兄弟组件/子组件继续做触摸测试。

  ![hitTestModeNone](figures/hitTestModeNone.png)

- HitTestMode.Block：阻塞子组件的触摸测试，如果自身触摸测试命中，会阻塞兄弟组件及父组件的触摸测试。

  ![hitTestModeBlock](figures/hitTestModeBlock.png)

- HitTestMode.Transparent：自身进行触摸测试，同时不阻塞兄弟组件及父组件。

  ![hitTestModeTransparent](figures/hitTestModeTransparent.png)

### 自定义事件拦截

[自定义事件拦截](../reference/apis-arkui/arkui-ts/ts-universal-attributes-on-touch-intercept.md)在按下触发时，可以根据业务状态动态改变组件的hitTestBehavior属性。

### 禁用控制

设置[禁用控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-enable.md)的组件，包括其子组件不会发起触摸测试过程，会直接返回父节点继续触摸测试。

### 触摸热区设置

[触摸热区设置](../reference/apis-arkui/arkui-ts/ts-universal-attributes-touch-target.md)会影响触屏/鼠标类的触摸测试，如果设置为0，或不可触控区域，则事件直接返回父节点继续触摸测试。

### 安全组件

ArkUI包含的安全组件有：[使用位置组件](../security/AccessToken/locationbutton.md)、[使用粘贴组件](../security/AccessToken/pastebutton.md)、[使用保存组件](../security/AccessToken/savebutton.md)等。

安全组件当前对触摸测试影响：如果有组件的[z序](../reference/apis-arkui/arkui-ts/ts-universal-attributes-z-order.md)比安全组件的z序靠前，且遮盖安全组件，则安全组件事件直接返回到父节点继续触摸测试。

## 事件响应链的收集

ArkUI事件响应链收集，根据右子树（按组件布局的先后层级）优先的后序遍历流程，流程为：

```
foreach(item=>(node.rbegin(),node.rend(){
    item.TouchTest()
}
node.collectEvent()
```

响应链收集举例，按下图的组件树，hitTestBehavior属性均为默认，用户点按的动作如果发生在组件5上，则最终收集到的响应链，以及先后关系是5，3，1。

因为组件3的hitTestBehavior属性为Default，收集到事件后会阻塞兄弟节点，所以没有收集组件1的左子树。

  ![EventResponseChain](figures/EventResponseChain.png)
