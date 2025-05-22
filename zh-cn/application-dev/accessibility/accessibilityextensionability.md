# AccessibilityExtensionAbility

Accessibility Kit（无障碍开发服务）通过基于ExtensionAbility框架的AccessibilityExtensionAbility提供无障碍扩展服务，开发者可以基于AccessibilityExtensionAbility模板开发自己的扩展服务，协助用户完成一些快捷的交互过程。

## 如何创建一个无障碍扩展服务

开发者在创建一个无障碍扩展服务时，如工程满足环境要求，开发者可自主选择是否跳过创建工程步骤，在已有工程中新增无障碍扩展服务。一个工程仅支持创建一个无障碍扩展服务。
本指南以实现以下功能为案例，讲述如何创建无障碍扩展服务，如何调用API接口实现该功能：
启动辅助功能后，在设备屏幕上绘画“右划后再下划”（rightThenDown）的手势，获取当前界面的全部节点；之后再绘画“左划后再下划”（leftThenDown）的手势，打印所有节点。

### 创建工程

如需新增独立的无障碍扩展服务应用，在DevEco Studio中新建一个API 9以上的Stage工程。

### 新建无障碍扩展服务ets文件

在已创建工程的ets文件夹下创建AccessibilityExtAbility文件夹，在该文件夹下创建AccessibilityExtAbility.ets文件，可在该文件中实现一些回调函数，并加入业务处理逻辑的调用：

```ts
import { AccessibilityExtensionAbility, AccessibilityEvent } from '@kit.AccessibilityKit';
import AccessibilityManager from './AccessibilityManager';

class AccessibilityExtAbility extends AccessibilityExtensionAbility {
    onConnect() {
        console.info(`AccessibilityExtAbility onConnect`);
        // 执行初始化业务逻辑的操作
        AccessibilityManager.getInstance().onStart(this.context);
    }

    onDisconnect() {
        console.info(`AccessibilityExtAbility onDisconnect`);
        // 执行资源回收退出业务逻辑的操作
        AccessibilityManager.getInstance().onStop();
    }

    onAccessibilityEvent(accessibilityEvent: AccessibilityEvent) {
        console.info(`AccessibilityExtAbility onAccessibilityEvent: ${JSON.stringify(accessibilityEvent)}`);
        // 根据事件信息进行业务逻辑处理
        AccessibilityManager.getInstance().onEvent(accessibilityEvent);
    }
}

export default AccessibilityExtAbility;
```

其中，主要定义了以下接口：

| 接口 | 描述 |
| ---- | ---- |
| onConnect(): void | 当扩展服务连接时回调。 |
| onDisconnect(): void | 当扩展服务断开时回调。 |
| onAccessibilityEvent(event: AccessibilityEvent): void | 当无障碍事件发生时回调。 |

创建AccessibilityManager.ets文件，用于存放业务逻辑代码：
```ts
import {
  AccessibilityElement,
  AccessibilityEvent,
  AccessibilityExtensionContext,
  ElementAttributeKeys
} from '@kit.AccessibilityKit';

interface Rect {
  left: number,
  top: number,
  width: number,
  height: number,
}

// 想要查询的属性信息
let wantedAttribute: ElementAttributeKeys[] = ['bundleName', 'text', 'description', 'windowId'];
type attributeValues = string | number | boolean | AccessibilityElement | AccessibilityElement[] | string[] | Rect;

export default class AccessibilityManager {
  private static instance: AccessibilityManager;
  accessibleContext?: AccessibilityExtensionContext;
  currentPageElementArray: Array<AccessibilityElement> | null = null;

  static getInstance(): AccessibilityManager {
    if (!AccessibilityManager.instance) {
      AccessibilityManager.instance = new AccessibilityManager();
    }
    return AccessibilityManager.instance;
  }

  onStart(context: AccessibilityExtensionContext) {
    console.info(`AccessibilityManager onStart`);
    this.accessibleContext = context;
  }

  onStop() {
    console.info(`AccessibilityManager onStop`);
    this.accessibleContext = undefined;
  }

  onEvent(accessibilityEvent: AccessibilityEvent): void {
    console.info(`AccessibilityManager onEvent`);
    switch (accessibilityEvent.eventType) {
      case 'rightThenDown':
      // 获取当前页面的所有节点
        this.getCurrentPageAllElement();
        break;
      case 'leftThenDown':
      // 打印所有节点
        this.printAllElementInfo();
        break;
      default:
        break;
    }
  }

  async getCurrentPageAllElement(): Promise<void> {
    console.info(`AccessibilityManager getCurrentPageAllElement`);
    let rootElement: AccessibilityElement;
    if(!this.accessibleContext){
      console.error(`AccessibilityManager accessibleContext undefined`);
      return;
    }
    try {
      rootElement = await this.accessibleContext?.getWindowRootElement();
      this.currentPageElementArray = await this.getAttributeValue(rootElement, 'children') as AccessibilityElement[];
    } catch (error) {
      console.error(`AccessibilityExtAbility Failed to getWindowRootElement. Cause:${JSON.stringify(error)}`);
    }
  }

  async getElementWantedInfo(accessibilityElement: AccessibilityElement, wantedAttribute: ElementAttributeKeys[]):
    Promise<string | null> {
    console.info(`AccessibilityUtils getElementAllInfo`);
    if (accessibilityElement === null) {
      console.error(`AccessibilityUtils accessibilityElement is null`);
      return null;
    }

    let info = '';
    let value: attributeValues | null;
    for (let name of wantedAttribute) {
      value = await this.getAttributeValue(accessibilityElement, name);
      info = info.concat(name + ': ' + value + ' ');
    }
    return info;
  }

  async getAttributeValue(accessibilityElement: AccessibilityElement, key: ElementAttributeKeys):
    Promise<attributeValues | null> {
    console.info(`AccessibilityUtils getAttributeValue`);
    let value: attributeValues;
    let keys = await accessibilityElement.attributeNames();
    let isExit = false;
    for (let keyString of keys) {
      if (key == keyString) {
        isExit = true;
      }
    }
    if (isExit) {
      try {
        value = await accessibilityElement.attributeValue(key);
        return value;
      } catch (error) {
        console.error(`AccessibilityUtils Failed to get attributeValue of ${key} . Cause:  ${JSON.stringify(error)}`);
      }
    }
    return null;
  }

  async printAllElementInfo(): Promise<void> {
    console.info(`AccessibilityManager printAllElementInfo`);
    if (this.currentPageElementArray === null || this.currentPageElementArray.length === 0) {
      console.error(`AccessibilityManager currentPageElementArray is null`);
      return;
    }
    let info: string | null = null;
    for (let index = 0; index < this.currentPageElementArray.length; index++) {
      info = await this.getElementWantedInfo(this.currentPageElementArray[index], wantedAttribute);
      console.info(`AccessibilityManager element information: ${info}`);
    }
  }
}
```

## 如何处理一个无障碍事件

相关无障碍事件可以在`onAccessibilityEvent()`方法中进行业务逻辑处理，具体事件可参考[AccessibilityEvent](../reference/apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md#accessibilityevent)。此处以手势事件`rightThenDown`为例：

```ts
onAccessibilityEvent(accessibilityEvent: AccessibilityEvent) {
    console.info('AccessibilityExtAbility onAccessibilityEvent: ' + JSON.stringify(accessibilityEvent));
    if (accessibilityEvent.eventType === 'rightThenDown') {
        console.info('AccessibilityExtAbility onAccessibilityEvent: rightThenDown');
        // TODO: 自定义相关逻辑开发
    }
}
```
在相应的无障碍事件中，可以使用[辅助功能扩展上下文（AccessibilityExtensionContext）](../reference/apis-accessibility-kit/js-apis-inner-application-accessibilityExtensionContext.md)提供的接口进行扩展开发，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

此外，还可在无障碍扩展服务中对物理按键事件进行处理，具体可参考[onKeyEvent](../reference/apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md#accessibilityextensionabilityonkeyevent)。

## 如何声明无障碍扩展服务具备的能力

在完成自定义无障碍扩展服务的逻辑开发后，还需要在工程中Module对应的module.json5文件中加入新增扩展服务的配置信息。

`srcEntry`标签为`extensionAbility`对应的路径。
`label`标签为`extensionAbility`在已安装扩展服务列表中显示的名称。
`description`标签为`extensionAbility`在已安装扩展服务详情页的帮助信息。
`type`标签要按照与无障碍子系统的约定进行配置，需要注意的是该值固定为`accessibility`，否则将无法正常连接。

```json
"extensionAbilities": [
  {
    "name": "AccessibilityExtAbility",
    "srcEntry": "./ets/AccessibilityExtAbility/AccessibilityExtAbility.ets",
    "label": "$string:MainAbility_label",
    "description": "$string:MainAbility_desc",
    "type": "accessibility",
    "metadata": [
      {
        "name": "ohos.accessibleability",
        "resource": "$profile:accessibility_config"
      }
    ]
  }
]
```
另外，配置信息中的`accessibility_config`为无障碍扩展服务的具体配置，需要在`resources/base/profile/`下新建`accessibility_config.json`文件，在该文件中声明此无障碍扩展服务具备的[能力类型](../reference/apis-accessibility-kit/js-apis-accessibility.md#capability)，根据业务功能合理声明能力类型，本案例中，需要如下声明:
```json
{
  "accessibilityCapabilities": [
    "retrieve",
    "gesture",
    "touchGuide"
  ]
}
```
## 如何开启自定义的无障碍扩展服务

当前提供设备-设置中的扩展服务管理页的开关按钮来开启/关闭选择的无障碍扩展服务：  

1、打开设备设置页面，进入“辅助功能”，“扩展服务”小标题下的“已安装的服务”显示当前安装的扩展服务个数，点击进入，展示安装的扩展服务列表；未安装扩展服务时，“已安装的扩展服务”不可点击，并显示“无服务”。

2、选择需要开启/关闭的扩展服务，通过开关按钮进行扩展服务的开启/关闭。

3、开启时，弹出安全提醒，在倒计时结束后，勾选“我已知晓如上风险，并自愿承担可能导致的后果。”后，可选择“开启”/“不开启”按钮；  关闭时，将开启的开关关闭，即可关闭已开启的扩展服务。

## 相关实例

针对AccessibilityExtensionAbility开发，有以下相关实例可供参考：

- [AccessibilityExtensionAbility示例](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/AccessibilityExtAbility)
