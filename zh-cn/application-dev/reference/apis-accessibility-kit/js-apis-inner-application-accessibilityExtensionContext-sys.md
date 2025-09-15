# AccessibilityExtensionContext (辅助功能扩展上下文)(系统接口)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

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

## Parameter<sup>20+</sup>

无障碍节点元素执行特定操作时，为操作提供具体设置的参数值。
详见[无障碍节点元素可执行的操作](./js-apis-accessibility-sys.md#accessibilityaction)。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| setText             | string | 否   |是 |设置组件文本时文本内容。                 |
| selectTextBegin     | string | 否  | 是|选定组件内文本时的起始坐标，如：'2'。        |
| selectTextEnd       | string | 否   | 是|选定组件内文本时的结束坐标，如：'8'。      |
| selectTextInForWard | bool   | 否    | 是|选定组件内文本时是否向前选择，如：true。      |
| offset              | string | 否   | 是|设置光标的偏移量，如：'1'。    |
| spanId              | string | 否   |是 |对超链接文本进行点击操作时文本编号。                |
| scrollType          | string | 否   | 是|组件滚动类型，包括'fullScreen'（全屏）和'halfScreen'（半屏）。 |

例如：选中文本输入框中index从0到7的字符时，executeAction(AccessibilityAction.SET_SELECTION, parameter)方法设置的参数如下:
```ts
let p : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true }
```

## AccessibilityGrid<sup>20+</sup>

辅助功能网格信息。
详见[AccessibilityElement.currentItem](#accessibilityelement12)。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| rowIndex             | number | 否   |否 |网格行索引。                 |
| columnIndex          | number | 否  | 否|网格列索引。        |


## AccessibilitySpan<sup>20+</sup>

辅助功能超链接文本信息。
详见[AccessibilityElement.spans](#accessibilityelement12)。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| spanId             | number | 否   |否 |超链接文本编号。                 |
| spanText          | string | 否 | 否|超链接文本的文本内容。        |
| accessibilityText          | string | 否  | 否|超链接文本的辅助功能文本。        |
| accessibilityDescription          | string | 否  | 否|超链接文本的辅助功能描述。        |
| accessibilityLevel          | string | 否  | 否|超链接文本的辅助功能级别。        |


## startAbility<sup>12+</sup>

startAbility(want: Want): Promise\<void>;

提供拉起前台页面的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.huawei.hmos.photos',
  abilityName: 'com.huawei.hmos.photos.MainAbility'
}

axContext.startAbility(want).then(() => {
  console.info(`startAbility Succeeded enable ability`);
}).catch((err: BusinessError) => {
  console.error(`startAbility failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getElements<sup>18+</sup>

getElements(windowId: number, elementId?: number): Promise<Array&lt;AccessibilityElement&gt;>;

提供批量查询节点的能力。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 表示查询的窗口id。 |
| elementId | number | 否 | 表示查询的节点id。传入此参数表示查询当前节点下的所有子节点列表，不传则查询窗口下所有节点。默认值为-1。 |

**返回值：**
| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;AccessibilityElement&gt;> | Promise对象，返回当前窗口或者当前节点下的所有子节点列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

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
let elementId: number = 10;

axContext.getElements(windowId, elementId).then((data:AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getDefaultFocusedElementIds<sup>18+</sup>

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

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

## AccessibilityExtensionContext.holdRunningLockSync<sup>20+</sup>

holdRunningLockSync(): void

持有RunningLock锁，持锁后，屏幕不会自动灭屏。

**需要权限**：ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.holdRunningLockSync();
} catch (err) {
  console.error(`Failed to hold RunningLock, Code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.unholdRunningLockSync<sup>20+</sup>

unholdRunningLockSync(): void

释放RunningLock锁，恢复自动灭屏。

**需要权限**：ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.unholdRunningLockSync();
} catch (err) {
  console.error(`Failed to unhold RunningLock, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.on('preDisconnect')<sup>20+</sup>

on(type: 'preDisconnect', callback: Callback&lt;void&gt;): void

向无障碍服务注册回调函数，在无障碍服务关闭该无障碍扩展服务前会执行该回调函数。

此注册函数需要与[notifyDisconnect](#accessibilityextensioncontextnotifydisconnect20)配合使用，如果不调用[notifyDisconnect](#accessibilityextensioncontextnotifydisconnect20)，则默认等待30秒后，无障碍扩展服务会自动关闭。

**需要权限**：ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件名，固定为‘preDisconnect’，即无障碍扩展服务即将关闭事件。 |
| callback | Callback&lt;void&gt; | 是 |回调函数，在无障碍扩展服务即将关闭时回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.on('preDisconnect', () => {
    console.info(`To do something before accessibilityExtension disconnect.`);
  });
} catch (err) {
  console.error(`Failed to register, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.off('preDisconnect')<sup>20+</sup>

off(type: 'preDisconnect', callback?: Callback&lt;void&gt;): void

取消已经向无障碍服务注册的预关闭回调函数，无障碍服务关闭该扩展服务前不再执行该回调。

**需要权限**：ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件名，固定为‘preDisconnect’，即无障碍扩展服务即将关闭事件。 |
| callback | Callback&lt;void&gt; | 否 |回调函数，取消指定无障碍扩展服务即将关闭时的回调。需与[on('preDisconnect')](#accessibilityextensioncontextonpredisconnect20)的callback一致。缺省时，表示注销所有已注册事件。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.off('preDisconnect', () => {
    console.info(`To do something before accessibilityExtension disconnect.`);
  });
} catch (err) {
  console.error(`Failed to unRegister, code is ${err.code}, message is ${err.message}`);
}
```

## AccessibilityExtensionContext.notifyDisconnect<sup>20+</sup>

notifyDisconnect(): void

通知无障碍服务可以关闭该无障碍扩展服务。

此函数需要与注册预关闭接口[on('preDisconnect')](#accessibilityextensioncontextonpredisconnect20)配合使用，如果没有调用过注册预关闭函数，直接调用此函数不生效。

**需要权限**：ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  axContext.notifyDisconnect();
} catch (err) {
  console.error(`Failed to notify accessibility, code is ${err.code}, message is ${err.message}`);
}
```

## getAccessibilityFocusedElement<sup>20+</sup>

getAccessibilityFocusedElement(): Promise\<AccessibilityElement>;

获取当前获得焦点的元素。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值:**
| 类型                                 | 描述                    |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)>| 异步返回函数结果.|

**错误码:**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 |  The target application failed to connect to accessibility service. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`Succeeded in get accessibility focused element, ${element.bundleName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get accessibility focused element, Code is ${err.code}, message is ${err.message}`);
});
```

## getRootInActiveWindow<sup>20+</sup>

getRootInActiveWindow(windowId ?: number): Promise\<[AccessibilityElement](#accessibilityelement12)>;

获取活动窗口根元素。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | No | Window ID to be obtained.|

**返回值:**
| 类型                                 | 描述                    |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)>| Promise used to return the result.|

**错误码:**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。
| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 0;

axContext.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
  console.log(`Succeeded in get root inactive window element, ${element.bundleName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get root inactive window element, Code is ${err.code}, message is ${err.message}`);
});
```

## getAccessibilityWindowsSync<sup>20+</sup>

getAccessibilityWindowsSync(displayId?: number): Array\<[AccessibilityElement](#accessibilityelement12)>

获取窗口列表。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| displayId | number | No | 显示ID。如果未提供此参数，则表示默认displayId。 |

**返回值:**

| 类型                                 | 描述                    |
| ----------------------------------- | ---------------------- |
| Array\<[AccessibilityElement](#accessibilityelement12)> | 窗口列表。|

**错误码:**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。
| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId: number = 0;
  let windowList = context?.getAccessibilityWindowsSync(displayId);
  if (windowList) {
    for (let window of windowList) {
      console.log(`getAccessibilityWindowsSync: windowId: ${window.windowId}`);
    }
  }
} catch (err) {
  console.log(`[FAILED] getAccessibilityWindowsSync: ${err.code} ${err.message}`)
}
```

## AccessibilityElement<sup>12+</sup>

无障碍节点元素。在调用 **AccessibilityElement** 的 API 之前，应该调用 [AccessibilityExtensionContext.getAccessibilityFocusedElement()](#getaccessibilityfocusedelement20) 或 [AccessibilityExtensionContext.getRootInActiveWindow()](#getrootinactivewindow20) 来获取一个 **AccessibilityElement** 实例。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称                  | 类型                                                             | 只读 | 可选 | 描述             |
|----------------------|--------------------------------------------------------------------|------|------|-------------------|
| accessibilityFocused<sup>20+</sup> | boolean | 否 | 是 | 表示元素是否因无障碍目的获得焦点。true表示已获得焦点，false表示未获得焦点。<br>默认值：false。|
| bundleName<sup>20+</sup> | string                                                             | 否  | 是  | 包名。|
| checkable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可勾选。true表示可勾选，false表示不可勾选。<br>默认值：false。|
| checked<sup>20+</sup> | boolean | 否 | 是 | 元素是否已勾选。true表示已勾选，false表示未勾选。<br>默认值：false。|
| clickable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可点击。true表示可点击，false表示不可点击。<br>默认值：false。|
| componentId<sup>20+</sup> | number | 否 | 是 | 元素所属组件的ID。<br>默认值：-1。|
| componentType<sup>20+</sup> | string                                                             | 否  | 是  | 元素所属组件的类型。|
| contents<sup>20+</sup> | Array&lt;string&gt;                                                | 否  | 是  | 元素显示内容。|
| currentIndex<sup>20+</sup> | number                                                             | 否  | 是  | 当前项的索引。<br>默认值：0。|
| description<sup>20+</sup> | string                                                             | 否  | 是  | 元素的描述信息。|
| editable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可编辑。true表示可编辑，false表示不可编辑。<br>默认值：false。|
| endIndex<sup>20+</sup> | number                                                             | 否  | 是  | 屏幕上显示的最后一个列表项的索引。<br>默认值：0。|
| error<sup>20+</sup> | string                                                             | 否  | 是  | 元素的错误状态。|
| focusable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可获得焦点。true表示可获得焦点，false表示不可获得焦点。<br/>默认值：false。|
| hintText<sup>20+</sup> | string                                                             | 否  | 是  | 提示文本。|
| inputType<sup>20+</sup> | number                                                             | 否  | 是  | 输入文本的类型。<br>默认值：0。|
| inspectorKey<sup>20+</sup> | string                                                             | 否  | 是  | 检查器键。|
| isActive<sup>20+</sup> | boolean | 否 | 是 | 元素是否处于活动状态。true表示活动状态，false表示非活动状态。<br>默认值：true。|
| isEnable<sup>20+</sup> | boolean | 否 | 是 | 元素是否启用。true表示启用，false表示未启用。<br>默认值：false。|
| isHint<sup>20+</sup> | boolean | 否 | 是 | 元素是否为提示信息。true表示元素是提示信息，false表示非提示信息。<br>默认值：false。|
| isFocused<sup>20+</sup> | boolean | 否 | 是 | 表示元素是否已获得焦点。true表示已获得焦点，false表示未获得焦点。<br>默认值：false。|
| isPassword<sup>20+</sup> | boolean                                                            | 否  | 是  | 元素是否为密码。true表示元素是密码，false表示不是密码。<br>默认值：false。|
| isVisible<sup>20+</sup> | boolean | 否 | 是 | 元素是否可见。true表示元素可见，false表示元素不可见。<br>默认值：false。|
| itemCount<sup>20+</sup> | number                                                             | 否  | 是  | 项目总数。<br>默认值：0。|
| lastContent<sup>20+</sup> | string                                                             | 否  | 是  | 最后一项内容。|
| layer<sup>20+</sup> | number                                                             | 否  | 是  | 元素的显示层级。|
| longClickable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可长按。true表示可长按，false表示不可长按。<br>默认值：false。|
| pageId<sup>20+</sup> | number | 否 | 是 | 页面ID。<br>默认值：-1。|
| pluralLineSupported<sup>20+</sup> | boolean | 否 | 是 | 表示元素是否支持多行文本。true表示支持，false表示不支持。<br>默认值：false。|
| rect<sup>20+</sup>                 | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                      | 否  | 是  | 元素的区域。|
| resourceName<sup>20+</sup>         | string                                                             | 否  | 是  | 元素的资源名称。|
| screenRect<sup>20+</sup>           | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                      | 否  | 是  | 元素的显示区域。|
| scrollable<sup>20+</sup>           | boolean                                                            | 否  | 是  | 元素是否可滚动。true表示元素可滚动，false表示不可滚动。<br>默认值：false。|
| selected<sup>20+</sup>             | boolean                                                            | 否  | 是  | 元素是否已选中。true表示已选中，false表示未选中。<br>默认值：false。|
| startIndex<sup>20+</sup>           | number                                                             | 否  | 是  | 屏幕上第一个列表项的索引。<br>默认值：0。|
| text<sup>20+</sup>                 | string                                                             | 否  | 是  | 元素的文本内容。|
| textLengthLimit<sup>20+</sup>      | number                                                             | 否  | 是  | 元素的最大文本长度。|
| textMoveUnit<sup>20+</sup>         | [accessibility.TextMoveUnit](js-apis-accessibility.md#textmoveunit)| 否  | 是  | 文本朗读时的移动单位。<br>默认值：0。|
| triggerAction<sup>20+</sup>        | [accessibility.Action](js-apis-accessibility.md#action)            | 否  | 是  | 触发元素事件的操作。|
| type<sup>20+</sup>                 | [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)                                          | 否  | 是  | 元素的窗口类型。|
| valueMax<sup>20+</sup>             | number                                                             | 否  | 是  | 最大值。<br>默认值：0。|
| valueMin<sup>20+</sup>             | number                                                             | 否  | 是  | 最小值。<br>默认值：0。|
| valueNow<sup>20+</sup>             | number                                                             | 否  | 是  | 当前值。<br>默认值：0。|
| windowId<sup>20+</sup>             | number                                                             | 否  | 是  | 窗口ID。<br>默认值：-1。|
| offset<sup>20+</sup>             | number              | 否  | 是  | 内容区域相对于可滚动组件（如List和Grid）顶部坐标的像素偏移量。<br>默认值：0。|
| textType<sup>20+</sup>             | string                                                             | 否  | 是  | 元素的无障碍文本类型，由组件的accessibilityTextHint属性配置。|
| accessibilityText<sup>20+</sup> | string                                                  | 否  | 是  | 元素的无障碍文本信息。|
| hotArea<sup>20+</sup>             | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                              | 否  | 是  | 元素的可触摸区域。|
| customComponentType<sup>20+</sup>             | string                                                             | 否  | 是  | 自定义组件类型。|
| accessibilityNextFocusId<sup>20+</sup>             | number                | 否  | 是  | 下一个要获得焦点的组件的ID。<br>默认值：-1。|
| accessibilityPreviousFocusId<sup>20+</sup>             | number                | 否  | 是  | 上一个要获得焦点的组件的ID。<br>默认值：-1。|
| extraInfo<sup>20+</sup>             | string     | 否  | 是  | 元素的额外信息。值为JSON字符串。|
| accessibilityScrollable<sup>20+</sup>             | boolean                 | 否  | 是  | 元素是否因无障碍目的而可滚动。此属性优先级高于scrollable。<br>true表示元素可滚动，false表示元素不可滚动。<br>默认值：true。|
| supportedActionNames<sup>20+</sup> | Array&lt;string&gt;                                                | 否  | 是  | 支持的操作名称。|
| accessibilityGroup<sup>20+</sup>  | boolean                                                            | 否  | 是  | 元素是否为无障碍组。true表示元素是无障碍组，false表示元素不是无障碍组。<br>默认值：false。|
| accessibilityLevel<sup>20+</sup>             | string                                                             | 否  | 是  | 组件的无障碍级别。<br>'auto'：当前组件由无障碍分组服务和ArkUI进行综合判断组件是否可被辅助功能识别。<br>'yes'：当前组件可被辅助功能识别。<br>'no'：当前组件不可被辅助功能识别。<br>'no-hide-descendants'：当前组件及其所有子组件不可被辅助功能识别。|
| navDestinationId<sup>20+</sup>             | number                                                             | 否  | 是  | 组件的导航目标ID。|
| currentItem<sup>20+</sup>             | [AccessibilityGrid](#accessibilitygrid20)                                                             | 否  | 是  | 组件网格中的当前项。|
| spans<sup>20+</sup>             | [AccessibilitySpan](#accessibilityspan20)[]                                                             | 否  | 是  | 组件的跨度数组。|
| accessibilityVisible<sup>20+</sup>  | boolean                                                            | 否  | 是  | 组件是否无障碍可见。true表示可见，false表示不可见。|
| mainWindowId<sup>20+</sup>             | number                                                             | 否  | 是 | 组件的主窗口ID。|
| clip<sup>20+</sup>  | boolean                                                            | 否  | 是  | 组件是否需要裁剪。true表示需要裁剪，false表示不需要裁剪。|
| parentId<sup>20+</sup>             | number                                                             | 否  | 是  | 组件的父元素ID。|
| childrenIds<sup>20+</sup>             | Array\<number>                                                             | 否  | 是  | 组件的子元素ID列表。|

**示例：**
```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
  console.info("AccessibilityElement.checkable: " + element.checkable)
  console.info("AccessibilityElement.checked: " + element.checked)
  console.info("AccessibilityElement.clickable: " + element.clickable)
  console.info("AccessibilityElement.componentId: " + element.componentId)
  console.info("AccessibilityElement.componentType: " + element.componentType)
  console.info("AccessibilityElement.contents: " + element.contents)
  console.info("AccessibilityElement.currentIndex: " + element.currentIndex)
  console.info("AccessibilityElement.description: " + element.description)
  // ....
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import {
  AccessibilityElement,
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class AccessibilityManager {
  private static instance: AccessibilityManager;
  context?: AccessibilityExtensionContext;

  static getInstance(): AccessibilityManager {
    if (!AccessibilityManager.instance) {
      AccessibilityManager.instance = new AccessibilityManager();
    }
    return AccessibilityManager.instance;
  }

  onStart(context: AccessibilityExtensionContext) {
    this.context = context;
  }

  onStop() {
    this.context = undefined;
  }

  onEvent(accessibilityEvent: AccessibilityEvent): void {
    if (!this.context) {
      console.error('context is not available!');
      return;
    }
    this.context.getWindowRootElement().then((rootElement: AccessibilityElement) => {
      console.log(`Succeeded in get root element of the window, ${JSON.stringify(rootElement)}`);
      rootElement.enableScreenCurtain(true);
      console.log(`Succeeded in enableScreenCurtain`);
    }).catch((err: BusinessError) => {
      console.error(`failed to enableScreenCurtain, Code is ${err.code}, message is ${err.message}`);
    });
  }
}
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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


### executeAction<sup>20+</sup>

executeAction(action: AccessibilityAction, parameters?: Parameter): Promise\<void>;

根据action指定的操作类型和parameters传入的参数，执行特定操作。使用Promise异步回调。

**权限:** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明                                                       |
| ----------- | ---------------------------------------- | ---- |----------------------------------------------------------|
| action    | [AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction)| 是    | 无障碍节点可执行的操作。
| parameters | [Parameter](#parameter20) | 否    | 执行操作时设置的参数值，默认为空。                            |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201     | Permission verification failed.The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.     |
| 9300005 | This action is not supported.            |

**示例：**
```ts
//无参数Action示例：
import { BusinessError } from '@kit.BasicServicesKit';
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

// rootElement是AccessibilityElement的实例
// Action描述中无明确要求的，均为无参数Action
try {
  rootElement.executeAction(AccessibilityAction.CLICK);
  console.info(`Succeeded in perform action CLICK`);
}catch (error){
  console.error(`failed to perform action CLICK, Code is ${error?.code}, message is ${error?.message}`);
}
```



```ts
//有参数Action示例：
import { BusinessError } from '@kit.BasicServicesKit'; 
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

try {
  // selectTextBegin: 表示选择起始位置
  // selectTextEnd: 表示选择结束位置
  // selectTextInForWard: true表示为前光标，false表示为后光标
  let p : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true }
  // rootElement是AccessibilityElement的实例
  // setSelection示例代码
  rootElement.executeAction(AccessibilityAction.SET_SELECTION, p);
  console.info(`Succeeded in perform action SET_SELECTION`);
}catch (error){
  console.error(`failed to perform action SET_SELECTION, Code is ${error?.code}, message is ${error?.message}`);
}
```

```ts
//有参数Action示例：
import { BusinessError } from '@kit.BasicServicesKit';
import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';

try {
  // offset: 表示光标的设置位置
  let p : Parameter = { offset: '1' }
  // rootElement是AccessibilityElement的实例
  // setCursorPosition示例代码
  rootElement.executeAction(AccessibilityAction.SET_CURSOR_POSITION, p);
  console.info(`Succeeded in perform action SET_CURSOR_POSITION`);
}catch (error){
  console.error(`failed to perform action SET_CURSOR_POSITION, Code is ${error?.code}, message is ${error?.message}`);
}
```

### getParent<sup>20+</sup>

getParent(): Promise\<AccessibilityElement>;

获取无障碍节点元素的父元素。

**权限:** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | 父元素。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`element parent id: ${element.parentId}`);
  element.getParent().then((parent: AccessibilityElement) => {
    console.log(`parent element's parent id: ${parent.parentId}`);
  }).catch((err) => {
    console.log(`getParent failed, code: ${err.code}, message: ${err.message}`);
  })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### getChildren<sup>20+</sup>

getChildren(): Promise\<Array\<AccessibilityElement>>;

获取元素的子元素列表。

**权限:** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | 子元素数组。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.log(`element childrenIds: ${element.childrenIds}`);
  element.getChildren().then((children: AccessibilityElement[]) => {
    console.log(`children element's size: ${children.length}`);
  }).catch((err) => {
    console.log(`getChildren failed, code: ${err.code}, message: ${err.message}`);
  })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### getRoot<sup>20+</sup>

getRoot(): Promise\<AccessibilityElement>;

获取活动窗口中的根元素。

**权限:** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | 根元素。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windows: AccessibilityWindow[] = axContext.getAccessibilityWindowsSync()
for (let window of windows) {
  console.log(`window id: ${window.windowId}`);
  window.getRoot().then((root: AccessibilityElement) => {
    console.log(`root element's componentId: ${root.componentId}`);
  }).catch((err) => {
    console.log(`getRoot failed, code: ${err.code}, message: ${err.message}`);
  })
}
```

### findElementByContent<sup>20+</sup>

findElementByContent(condition: string): Promise\<Array\<AccessibilityElement>>;

根据内容查找元素。

**权限:** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | 是 | 内容。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | 元素数组。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementByContent('connect').then((elements: AccessibilityElement[]) => {
        console.log("findElementByContent size=" + elements.length)
    }).catch((err) => {
        console.log(`findElementByContent failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementByFocusDirection<sup>20+</sup>

findElementByFocusDirection(condition: FocusDirection): Promise\<AccessibilityElement>;

根据焦点方向查找元素。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | FocusDirection | 是 | 焦点方向。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | AccessibilityElement.|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
// Click TextInput and then it is the accessibility focus element, up direction element is Text#connect
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementByFocusDirection('up').then((element: AccessibilityElement) => {
        console.log("findElementByFocusDirection UP componentId: " + element.componentId);
    }).catch((err) => {
        console.log(`findElementByFocusDirection UP failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementsByAccessibilityHintText<sup>20+</sup>

findElementsByAccessibilityHintText(condition: string): Promise\<Array\<AccessibilityElement>>;

根据性提示文本查找元素。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | 是 | 提示文本。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement12)>> | 元素数组。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
        .accessibilityTextHint('location')
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId: number = 10;

axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementsByAccessibilityHintText('location').then((elements: AccessibilityElement[]) => {
        console.log("findElementsByAccessibilityHintText size=" + elements.length)
    }).catch((err) => {
        console.log(`findElementsByAccessibilityHintText failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getRootInActiveWindow failed, code: ${err.code}, message: ${err.message}`);
})
```

### findElementById<sup>20+</sup>

findElementById(condition: number): Promise\<AccessibilityElement>;

根据元素 ID 查找元素。

**权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力:** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | number | 是 | 元素 ID。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement12)> | AccessibilityElement.|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed.The application does not have the permission required to call the API.|
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
// Click TextInput and then it is the accessibility focus element
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))
// ...

// AccessibilityExtAbility.ets
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementById(0).then((element: AccessibilityElement) => {
        console.log("findElementById componentId: " + element.componentId);
    }).catch((err) => {
        console.log(`findElementById failed, code: ${err.code}, message: ${err.message}`);
    })
}).catch((err) => {
  console.log(`getAccessibilityFocusedElement failed, code: ${err.code}, message: ${err.message}`);
})
```
