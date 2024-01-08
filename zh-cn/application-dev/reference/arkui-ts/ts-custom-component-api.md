# 自定义组件内置方法

自定义组件内置方法是由ArkUI开发框架提供给应用开发者的，定义在自定义组件基类上的API。应用开发者可以在自定义组件的实例上调用对应的API以获取当前自定义组件实例相关的信息。例如，查询当前自定组件上下文的UIContext信息。

> **说明：**
>
> 本模块首批接口从API version 11开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## getUIContext

getUIContext?(): UIContext

获取UIContext对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                      | 说明                    |
| --------------------------------------------------------- | ----------------------- |
| [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext) | 返回UIContext实例对象。 |

**示例：**

```ts
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    if (typeof this.getUIContext === 'function') {
        let uiContext: UIContext = this.getUIContext();
    }
  }

  build() {
    // ...
  }
}
```

## queryNavDestinationInfo

queryNavDestinationInfo?(): NavDestinationInfo | undefined;

获取NavDestinationInfo实例对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                                       | 说明      |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../apis/js-apis-arkui-observer.md#navdestinationinfo) \| undefined | 返回NavDestinationInfo实例对象。 |

**示例：**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    if (typeof this.queryNavDestinationInfo === 'function') {
        let info: observer.NavDestinationInfo | undefined = this.queryNavDestinationInfo();
    }
  }

  build() {
    // ...
  }
}
```
