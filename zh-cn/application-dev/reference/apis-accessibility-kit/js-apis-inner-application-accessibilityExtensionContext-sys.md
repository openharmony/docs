# AccessibilityExtensionContext (辅助功能扩展上下文)(系统接口)

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口请参[AccessibilityExtensionContext (辅助功能扩展上下文)](js-apis-inner-application-accessibilityExtensionContext.md)。

## 使用说明

在使用AccessibilityExtensionContext的功能前，需要通过AccessibilityExtensionAbility子类实例获取AccessibilityExtensionContex的实例。

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

### enableScreenCurtain<sup>12+</sup>

enableScreenCurtain(isEnable: boolean): void;

提供开启/关闭幕帘屏的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| isEnable | boolean | 是    | true表示打开幕帘屏功能，false表示关闭幕帘屏功能。|

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
  await rootElement.enableScreenCurtain(true);
  console.log(`Succeeded in enableScreenCurtain}`);
}).catch((err: BusinessError) => {
  console.error(`failed to enableScreenCurtain, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('elementId')<sup>12+</sup>

findElement(type: 'elementId', condition: number): Promise\<AccessibilityElement>;

根据elementId查询当前活动窗口下的节点元素，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                | 必填   | 说明                                       |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | 是    | 固定为'elementId', 表示根据elementId查询当前活动窗口下的节点元素。 |
| condition | number | 是    | 表示要查询的节点元素的elementId。                           |

**返回值：**

| 类型                                  | 说明                               |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt; | Promise对象，返回满足指定查询条件的节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

//elementId为10
let condition = 10;

// rootElement是AccessibilityElement的实例
rootElement.findElement('elementId', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('textType')<sup>12+</sup>

findElement(type: 'textType', condition: string): Promise\<Array\<AccessibilityElement>>;

根据节点配置的accessibilityTextHint无障碍文本类型查询所有节点元素，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型     | 必填   | 说明                            |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | 是    | 固定为'textType', 表示根据文本类型查找节点元素。 |
| condition | string | 是    | 表示查找的条件。                      |

**返回值：**

| 类型                                       | 说明                            |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt;&gt; | Promise对象，返回满足指定查询关键字的所有节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// condition的内容需要与目标组件accessibilityTextHint属性的type字段值保持一致
let condition = 'location'; 

// rootElement是AccessibilityElement的实例
rootElement.findElement('textType', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(): Promise\<number>;

获取文本组件中光标位置，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | Promise对象，返回当前光标所处位置。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
rootElement.getCursorPosition().then((data: number) => {
  console.info(`Succeeded in getCursorPosition, ${data}`);
}).catch((err: BusinessError) => {
  console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(callback: AsyncCallback\<number>): void;

获取文本组件中光标位置，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数，表示文本组件中光标位置。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
rootElement.getCursorPosition((err: BusinessError, data: number) => {
  if (err && err.code) {
    console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getCursorPosition, ${data}`);
});
```

### startAbility<sup>12+</sup>

startAbility(want: Want): void;

提供拉起前台页面的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.huawei.hmos.photos'
  abilityName: 'com.huawei.hmos.photos.MainAbility'
}

axContext.startAbility(want).then(() => {
  console.info(`startAbility Succeeded enable ability`);
}).catch((err: BusinessError) => {
  console.error(`startAbility failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```

### getElements<sup>16+</sup>

getElements(windowId: number, elementId?: number): Promise<Array&lt;AccessibilityElement&gt;>;

提供批量查询节点的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 表示查询的窗口id。 |
| elementId | number | 否 | 表示查询的节点id。传入此参数表示查询当前节点下的所有子节点列表，不传则查询窗口下所有节点。 |

**返回值：**
| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;AccessibilityElement&gt;> | Promise对象，返回当前窗口或者当前节点下的所有子节点列表。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;
let elementId: number = 10;

axContext.getElements(windowId, elementId).then((data:AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### getDefaultFocusedElementIds<sup>16+</sup>

getDefaultFocusedElementIds(windowId: number): Promise<Array&lt;number&gt;>;

提供查询应用自定义默认焦点的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 表示查询的窗口id。 |

**返回值：**
| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;number&gt;> | Promise对象，返回当前窗口下的自定义默认焦点列表。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getDefaultFocusedElementIds(windowId).then((data: number[]) => {
  console.log(`Succeeded in get default focus, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get default focus, Code is ${err.code}, message is ${err.message}`);
});
```