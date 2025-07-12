# Class (UIInspector)

提供注册组件布局和组件绘制送显完成回调通知的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 以下API需先使用UIContext中的[getUIInspector()](arkts-apis-uicontext-uicontext.md#getuiinspector)方法获取到UIInspector对象，再通过该对象调用对应方法。

## createComponentObserver

createComponentObserver(id: string): inspector.ComponentObserver

注册组件布局和组件绘制送显完成回调通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明      |
| ---- | ------ | ---- | ------- |
| id   | string | 是    | 指定组件id，该id通过通用属性[id](./arkui-ts/ts-universal-attributes-component-id.md#id)或者[key](./arkui-ts/ts-universal-attributes-component-id.md#key12)设置。 |

**返回值：** 

| 类型                                                         | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [inspector.ComponentObserver](js-apis-arkui-inspector.md#componentobserver) | 组件回调事件监听句柄，用于注册和取消注册监听回调。 |

**示例：**

<!--code_no_check-->
```ts
import { UIInspector } from '@kit.ArkUI';

let inspector: UIInspector = uiContext.getUIInspector();
let listener = inspector.createComponentObserver('COMPONENT_ID');
```
