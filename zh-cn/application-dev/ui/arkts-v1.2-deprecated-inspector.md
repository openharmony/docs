# 布局回调

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## createComponentObserver

ArkTS1.1接口声明：[createComponentObserver(id: string): ComponentObserver](../reference/apis-arkui/js-apis-arkui-inspector.md#inspectorcreatecomponentobserverdeprecated)

替代的ArkTS1.2接口声明：[createComponentObserver(id: string): inspector.ComponentObserver](../reference/apis-arkui/js-apis-arkui-UIContext.md#createcomponentobserver)

适配方法如下：

ArkTS1.1

```ts
// 监听id为COMPONENT_ID的组件回调事件
let listener:inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID');
```

ArkTS1.2
<!--code_no_check-->
```ts
import { UIInspector } from '@kit.ArkUI';

let inspector: UIInspector = uiContext.getUIInspector();
// 监听id为COMPONENT_ID的组件回调事件
let listener = inspector.createComponentObserver('COMPONENT_ID');
```