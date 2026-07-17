# AccessibilityExtensionContext (辅助功能扩展上下文)(系统接口)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

辅助功能扩展上下文模块提供上下文环境，支持辅助应用配置关注的信息类型、查询节点信息、手势注入等。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口请参见[AccessibilityExtensionContext (辅助功能扩展上下文)](js-apis-inner-application-accessibilityExtensionContext.md)。

## 使用说明

在使用AccessibilityExtensionContext功能前，需要先通过AccessibilityExtensionAbility子类实例获取一个AccessibilityExtensionContext的实例。

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## Parameter<sup>20+</sup>

无障碍节点元素执行特定操作时，为操作提供具体设置的参数值。不同操作类型需设置不同的参数字段，各操作类型与参数字段的对应关系，详见[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction)（无障碍节点元素可执行的操作）。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| setText             | string | 否   |是 |执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SET_TEXT时配置，设置组件文本时的文本内容。                 |
| selectTextBegin     | string | 否  | 是|执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SET_SELECTION时配置，选定组件内文本时的起始坐标，如：'2'。需与selectTextEnd和selectTextInForWard同时设置。        |
| selectTextEnd       | string | 否   | 是|执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SET_SELECTION时配置，选定组件内文本时的结束坐标，如：'8'。需与selectTextBegin和selectTextInForWard同时设置。      |
| selectTextInForWard | boolean   | 否    | 是|执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SET_SELECTION时配置，表示选定组件内文本时是否向前选择。true表示向前选择，false表示向后选择。需与selectTextBegin和selectTextEnd同时设置。 |
| offset              | string | 否   | 是|执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SET_CURSOR_POSITION时配置，设置光标的字符偏移量，如：'1'。    |
| spanId              | string | 否   |是 |执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SPAN_CLICK时配置，对超链接文本进行点击操作时的文本编号。                |
| scrollType | string | 否 | 是|执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).SCROLL_FORWARD或SCROLL_BACKWARD时配置，组件滚动类型。'fullScreen'表示全屏滚动；'halfScreen'表示半屏滚动。 |
| injectActionType | [InjectActionType](./js-apis-accessibility-sys.md#injectactiontype) | 否   | 是|设置注入的动作类型，执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).INJECT_ACTION时配置。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| customAction          | string | 否   | 是| 执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).EXECUTE_CUSTOM_ACTION时配置，表示自定义操作的名称。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| accessibilityFocusScene          | [AccessibilityFocusScene](./js-apis-accessibility-sys.md#accessibilityfocusscene) | 否   | 是| 执行[AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction).ACCESSIBILITY_FOCUS时配置，用于设置无障碍聚焦的场景。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

**示例：**

选中文本输入框中index从0到7的字符时，executeAction(AccessibilityAction.SET_SELECTION, parameter)方法设置的参数如下：

```ts
import { Parameter } from '@kit.AccessibilityKit';

let parameter : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true };
```

## AccessibilityGrid<sup>20+</sup>

辅助功能网格信息。详见[AccessibilityElement](#accessibilityelement)中的属性currentItem。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| rowIndex             | number | 否   |否 |网格行索引。                 |
| columnIndex          | number | 否  | 否|网格列索引。        |


## AccessibilitySpan<sup>20+</sup>

辅助功能超链接文本信息。详见[AccessibilityElement](#accessibilityelement)中的属性spans。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| spanId             | number | 否   |否 |超链接文本编号。                 |
| spanText          | string | 否 | 否|超链接文本的文本内容。        |
| accessibilityText          | string | 否  | 否|超链接文本的辅助功能文本。        |
| accessibilityDescription          | string | 否  | 否|超链接文本的辅助功能描述。        |
| accessibilityLevel          | string | 否  | 否|超链接文本的辅助功能级别。'auto'：由系统综合判断是否可被辅助功能识别；'yes'：可被辅助功能识别；'no'：不可被辅助功能识别；'no-hide-descendants'：当前文本及其子内容不可被辅助功能识别。        |

## FocusRule<sup>23+</sup>

type FocusRule = 'bypassSelf' | 'bypassSelfDescendants' | 'checkSelf' | 'checkSelfBypassDescendants'

表示查找可聚焦节点时，如何判断起始节点及其子节点的聚焦能力。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型            | 说明          |
| -------- | ------- |
| 'bypassSelf'       | 表示跳过对起始节点的检查，只检查其子节点。值固定为'bypassSelf'字符串。|
| 'bypassSelfDescendants'     | 表示跳过对起始节点及其所有子节点的检查。值固定为'bypassSelfDescendants'字符串。|
| 'checkSelf'     | 表示先检查起始节点是否可以聚焦，如果可以则直接使用；如果不能聚焦，则继续检查其子节点。值固定为'checkSelf'字符串。|
| 'checkSelfBypassDescendants' | 表示先检查起始节点是否可以聚焦，如果可以则使用；如果不能聚焦，则跳过所有子节点的检查。值固定为'checkSelfBypassDescendants'字符串。|

## FocusCondition<sup>23+</sup>

type FocusCondition = 'forward' | 'backward' | 'findLast' | 'getForwardScrollAncestor' | 'getBackwardScrollAncestor' | 'getScrollableAncestor'

表示查询可聚焦节点方式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型       | 说明      |
| -------- | ------- |
| 'forward'       | 表示当前节点下一个可聚焦节点，值固定为'forward' 字符串。|
| 'backward'     | 表示当前节点上一个可聚焦节点，值固定为'backward'字符串。|
| 'findLast'     | 表示查找起始节点的子节点中的最后一个节点，值固定为'findLast'字符串。|
| 'getForwardScrollAncestor' | 表示查找支持前向滚动父组件，值固定为'getForwardScrollAncestor'字符串。|
| 'getBackwardScrollAncestor'| 表示查找支持后向滚动父组件，值固定为'getBackwardScrollAncestor'字符串。|
| 'getScrollableAncestor' | 表示查找支持任意滚动父组件，值固定为'getScrollableAncestor'字符串。|

## FocusMoveResult<sup>23+</sup>

查询无障碍节点返回值类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称                  | 类型     | 只读  |可选| 说明                                |
| ------------------- | ------ | ---- | ----|--------------------------------- |
| target | Array<[AccessibilityElement](#accessibilityelement)> | 否 | 否 | 查询返回的无障碍节点列表。|
| result | [FocusMoveResultCode](./js-apis-accessibility-sys.md#focusmoveresultcode23)  | 否 | 否 | 查询无障碍节点返回结果类型。|


## AccessibilityExtensionContext

辅助功能扩展的上下文环境，提供拉起前台页面、查询节点、获取焦点元素、屏幕常亮控制、预关闭回调管理等能力，适用于无障碍辅助应用与系统界面交互的场景。需要通过AccessibilityExtensionAbility子类实例获取AccessibilityExtensionContext的实例。

### startAbility<sup>12+</sup>

startAbility(want: Want): Promise\<void>

拉起前台页面。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的Ability的信息，如Ability名称、Bundle名称等。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

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

    let want: Want = {
      bundleName: 'com.huawei.hmos.photos',
      abilityName: 'com.huawei.hmos.photos.MainAbility'
    };

    this.context.startAbility(want).then(() => {
      console.info(`succeeded in starting ability`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to start ability. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### getElements<sup>18+</sup>

getElements(windowId: number, elementId?: number): Promise<Array&lt;AccessibilityElement&gt;>

批量查询指定窗口或指定节点下的所有后代无障碍节点。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 表示查询的窗口ID。 |
| elementId | number | 否 | 表示查询的节点ID。传入此参数表示查询该节点下的所有子节点列表（不包含该节点本身）；不传或传-1表示查询指定窗口下的完整节点树（包含根节点）。默认值为-1。 |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise<Array&lt;[AccessibilityElement](#accessibilityelement)&gt;> | Promise对象，返回当前窗口或者当前节点下的所有子节点列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
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

    let windowId: number = 10;
    let elementId: number = 10;

    this.context.getElements(windowId, elementId).then((data:AccessibilityElement[]) => {
      console.info(`succeeded in finding element, ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to find element. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### getDefaultFocusedElementIds<sup>18+</sup>

getDefaultFocusedElementIds(windowId: number): Promise<Array&lt;number&gt;>

查询应用自定义设置的默认焦点元素ID列表。使用Promise异步回调。

默认焦点是指窗口打开时无障碍服务优先聚焦的元素。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 表示查询的窗口ID。 |

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
import {
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

    let windowId: number = 10;

    this.context.getDefaultFocusedElementIds(windowId).then((data: number[]) => {
      console.info(`succeeded in getting default focus, ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get default focus. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### holdRunningLockSync<sup>20+</sup>

holdRunningLockSync(): void

持有RunningLock锁，持锁后，屏幕不会自动灭屏。调用此方法后，在不需要保持屏幕常亮时调用[unholdRunningLockSync](#unholdrunninglocksync20)释放锁，恢复自动灭屏机制。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      this.context.holdRunningLockSync();
    } catch (err) {
      console.error(`Failed to hold RunningLock. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### unholdRunningLockSync<sup>20+</sup>

unholdRunningLockSync(): void

释放RunningLock锁，恢复自动灭屏。与[holdRunningLockSync](#holdrunninglocksync20)配对使用。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      this.context.unholdRunningLockSync();
    } catch (err) {
      console.error(`Failed to unhold RunningLock. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### on('preDisconnect')<sup>20+</sup>

on(type: 'preDisconnect', callback: Callback&lt;void&gt;): void

向无障碍服务注册回调函数，在无障碍服务关闭该辅助功能扩展服务前会执行该回调函数。使用callback异步回调。

此注册函数需要与[notifyDisconnect](#notifydisconnect20)配合使用，如果不调用[notifyDisconnect](#notifydisconnect20)，则默认等待30秒后，辅助功能扩展服务会自动关闭。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件名，固定为‘preDisconnect’，即辅助功能扩展服务即将关闭的事件。 |
| callback | Callback&lt;void&gt; | 是 |回调函数，在辅助功能扩展服务即将关闭时回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      this.context.on('preDisconnect', () => {
        console.info(`To do something before accessibilityExtension disconnect.`);
      });
    } catch (err) {
      console.error(`Failed to register. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### off('preDisconnect')<sup>20+</sup>

off(type: 'preDisconnect', callback?: Callback&lt;void&gt;): void

取消已经向无障碍服务注册的预关闭回调函数，需先通过on('preDisconnect')注册后才能取消。取消后，无障碍服务关闭该扩展服务前不再执行该回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件名，固定为‘preDisconnect’，即辅助功能扩展服务即将关闭的事件。 |
| callback | Callback&lt;void&gt; | 否 |回调函数，取消指定辅助功能扩展服务即将关闭时的回调。需与[on('preDisconnect')](#onpredisconnect20)的callback一致。缺省时，表示注销所有已注册事件。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      this.context.off('preDisconnect');
    } catch (err) {
      console.error(`Failed to unRegister. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### notifyDisconnect<sup>20+</sup>

notifyDisconnect(): void

通知无障碍服务可以关闭该辅助功能扩展服务。

此函数需要与注册预关闭接口[on('preDisconnect')](#onpredisconnect20)配合使用，如果没有调用过注册预关闭函数，直接调用此函数不生效。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      this.context.notifyDisconnect();
    } catch (err) {
      console.error(`Failed to notify accessibility. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### getAccessibilityFocusedElement<sup>20+</sup>

getAccessibilityFocusedElement(): Promise\<AccessibilityElement>

获取当前获得无障碍焦点的元素。使用Promise异步回调。

无障碍焦点是指无障碍服务当前聚焦的节点，与输入焦点不同。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                 | 说明                    |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)>| Promise对象，返回当前获得焦点的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 |  The target application failed to connect to accessibility service. |

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

    this.context.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
      console.info(`succeeded in getting accessibility focused element, ${element.bundleName}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### getRootInActiveWindow<sup>20+</sup>

getRootInActiveWindow(windowId ?: number): Promise\<AccessibilityElement>

获取当前活动窗口的无障碍节点树根元素。使用Promise异步回调。

活动窗口是指当前获得焦点的前台应用窗口。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 否 | 表示查询的窗口ID。如果未提供此参数，则默认查询当前活动窗口的根元素。 |

**返回值：**

| 类型                                 | 说明                    |
| ----------------------------------- | ---------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)>| Promise对象，返回活动窗口的根元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。
| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |
| 9300006 | The target application failed to connect to accessibility service. |

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

    let windowId: number = 0;

    this.context.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
      console.info(`succeeded in getting root in active window element, ${element.bundleName}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get root in active window element. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### getAccessibilityWindowsSync<sup>20+</sup>

getAccessibilityWindowsSync(displayId?: number): Array\<AccessibilityElement>

获取当前显示设备上所有无障碍可访问的窗口列表。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| displayId | number | 否 | 显示ID。如果未提供此参数，则表示默认displayId。 |

**返回值：**

| 类型                                 | 说明                    |
| ----------------------------------- | ---------------------- |
| Array\<[AccessibilityElement](#accessibilityelement)> | 窗口列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。
| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import {
  AccessibilityEvent, 
  AccessibilityExtensionContext
} from '@kit.AccessibilityKit';

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

    try {
      let displayId: number = 0;
      let windowList = this.context.getAccessibilityWindowsSync(displayId);
      if (windowList) {
        for (let window of windowList) {
          console.info(`getAccessibilityWindowsSync: windowId: ${window.windowId}`);
        }
      }
    } catch (err) {
     console.error(`Failed to get accessibility windows sync. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

## AccessibilityElement

无障碍节点元素，提供查询父/子元素、按内容或焦点方向查找元素、执行无障碍操作等能力，适用于无障碍辅助应用需要与界面节点交互和操作的场景。

在调用AccessibilityElement的接口之前，应该调用[AccessibilityExtensionContext.getAccessibilityFocusedElement](#getaccessibilityfocusedelement20)或[AccessibilityExtensionContext.getRootInActiveWindow](#getrootinactivewindow20)来获取一个AccessibilityElement实例。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称                  | 类型                                                             | 只读 | 可选 | 说明             |
|----------------------|--------------------------------------------------------------------|------|------|-------------------|
| accessibilityFocused<sup>20+</sup> | boolean | 否 | 是 | 表示元素是否因无障碍目的获得焦点。true表示已获得焦点，false表示未获得焦点。<br>默认值：false。|
| bundleName<sup>20+</sup> | string                                                             | 否  | 是  | 包名。|
| checkable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可勾选。true表示可勾选，false表示不可勾选。<br>默认值：false。|
| checked<sup>20+</sup> | boolean | 否 | 是 | 元素是否已勾选。true表示已勾选，false表示未勾选。<br>默认值：false。|
| clickable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可点击。true表示可点击，false表示不可点击。<br>默认值：false。|
| componentId<sup>20+</sup> | number | 否 | 是 | 元素所属组件的ID。<br>默认值：-1。|
| componentType<sup>20+</sup> | string                                                             | 否  | 是  | 元素所属组件的类型。|
| contents<sup>20+</sup> | Array&lt;string&gt;                                                | 否  | 是  | 元素显示内容。默认值：空数组。|
| currentIndex<sup>20+</sup> | number                                                             | 否  | 是  | 当前项的索引。<br>默认值：0。|
| description<sup>20+</sup> | string                                                             | 否  | 是  | 元素的描述信息。|
| editable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可编辑。true表示可编辑，false表示不可编辑。<br>默认值：false。|
| endIndex<sup>20+</sup> | number                                                             | 否  | 是  | 屏幕上显示的最后一个列表项的索引。<br>默认值：0。|
| error<sup>20+</sup> | string                                                             | 否  | 是  | 元素的错误状态。|
| focusable<sup>20+</sup> | boolean | 否 | 是 | 元素是否可获得焦点（此处指无障碍焦点，与输入焦点不同）。true表示可获得焦点，false表示不可获得焦点。<br>默认值：false。|
| hintText<sup>20+</sup> | string                                                             | 否  | 是  | 提示文本。|
| inputType<sup>20+</sup> | number                                                             | 否  | 是  | 输入文本的类型，不同数值对应不同的输入模式：0表示无特定类型；1表示文本；2表示邮箱；3表示日期；4表示时间；5表示数字；6表示密码；7表示电话号码；8表示用户名；9表示新密码。<br>默认值：0。|
| inspectorKey<sup>20+</sup> | string                                                             | 否  | 是  | 检查器键。|
| isActive<sup>20+</sup> | boolean | 否 | 是 | 元素是否处于活动状态。true表示活动状态，false表示非活动状态。<br>默认值：true。|
| isEnable<sup>20+</sup> | boolean | 否 | 是 | 元素是否启用。true表示启用，false表示未启用。<br>默认值：false。|
| isHint<sup>20+</sup> | boolean | 否 | 是 | 元素是否为提示信息。true表示元素是提示信息，false表示非提示信息。<br>默认值：false。|
| isFocused<sup>20+</sup> | boolean | 否 | 是 | 表示元素是否已获得焦点（此处指无障碍焦点，与输入焦点不同）。true表示已获得焦点，false表示未获得焦点。<br>默认值：false。|
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
| scrollable<sup>20+</sup>           | boolean                                                            | 否  | 是  | 元素是否可滚动。true表示元素可滚动，false表示不可滚动。当与accessibilityScrollable取值冲突时，以accessibilityScrollable为准。<br>默认值：false。|
| selected<sup>20+</sup>             | boolean                                                            | 否  | 是  | 元素是否已选中。true表示已选中，false表示未选中。<br>默认值：false。|
| startIndex<sup>20+</sup>           | number                                                             | 否  | 是  | 屏幕上第一个列表项的索引。<br>默认值：0。|
| text<sup>20+</sup>                 | string                                                             | 否  | 是  | 元素的文本内容。|
| textLengthLimit<sup>20+</sup>      | number                                                             | 否  | 是  | 元素的最大文本长度。默认值：0。|
| textMoveUnit<sup>20+</sup>         | [accessibility.TextMoveUnit](js-apis-accessibility.md#textmoveunit)| 否  | 是  | 文本朗读时的移动单位。<br>默认值：char。|
| triggerAction<sup>20+</sup>        | [accessibility.Action](js-apis-accessibility.md#action)            | 否  | 是  | 触发元素事件的操作。|
| type<sup>20+</sup>                 | [WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)                                          | 否  | 是  | 元素的窗口类型。|
| valueMax<sup>20+</sup>             | number                                                             | 否  | 是  | 最大值。<br>默认值：0。|
| valueMin<sup>20+</sup>             | number                                                             | 否  | 是  | 最小值。<br>默认值：0。|
| valueNow<sup>20+</sup>             | number                                                             | 否  | 是  | 当前值。<br>默认值：0。|
| windowId<sup>20+</sup>             | number                                                             | 否  | 是  | 窗口ID。<br>默认值：-1。|
| offset<sup>20+</sup>             | number              | 否  | 是  | 内容区域相对于可滚动组件（如List和Grid）顶部坐标的像素偏移量，单位为像素（px）。<br>默认值：0。|
| textType<sup>20+</sup>             | string                                                             | 否  | 是  | 元素的无障碍文本类型，由组件的accessibilityTextHint属性配置。|
| accessibilityText<sup>20+</sup> | string                                                  | 否  | 是  | 元素的无障碍文本信息。|
| accessibilityStateDescription<sup>23+</sup> | string                                      | 否  | 是  | 元素的自定义无障碍状态播报文本信息。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| hotArea<sup>20+</sup>             | [Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)                                                              | 否  | 是  | 元素的可触摸区域。|
| customComponentType<sup>20+</sup>             | string                                                             | 否  | 是  | 自定义组件类型。与元素的[AccessibilityRoleType](../apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilityroletype18枚举说明)类型所对应。|
| accessibilityNextFocusId<sup>20+</sup>             | number                | 否  | 是  | 下一个要获得焦点的组件的ID。<br>默认值：-1。|
| accessibilityPreviousFocusId<sup>20+</sup>             | number                | 否  | 是  | 上一个要获得焦点的组件的ID。<br>默认值：-1。|
| extraInfo<sup>20+</sup>             | string     | 否  | 是  | 元素的额外信息。值为JSON字符串。|
| accessibilityScrollable<sup>20+</sup>             | boolean                 | 否  | 是  | 元素是否因无障碍目的而可滚动。优先级高于scrollable，即当accessibilityScrollable与scrollable取值冲突时以accessibilityScrollable为准。<br>true表示元素可滚动，false表示元素不可滚动。<br>默认值：false。|
| supportedActionNames<sup>20+</sup> | Array&lt;string&gt;                                                | 否  | 是  | 支持的操作名称。默认值：空数组。|
| accessibilityGroup<sup>20+</sup>  | boolean                                                            | 否  | 是  | 元素是否为无障碍组。true表示元素是无障碍组，false表示元素不是无障碍组。<br>默认值：false。|
| accessibilityLevel<sup>20+</sup>             | string                                                             | 否  | 是  | 组件的无障碍级别。<br>'auto'：当前组件由无障碍分组服务和ArkUI进行综合判断组件是否可被辅助功能识别。<br>'yes'：当前组件可被辅助功能识别。<br>'no'：当前组件不可被辅助功能识别。<br>'no-hide-descendants'：当前组件及其所有子组件不可被辅助功能识别。默认值：'auto'。|
| navDestinationId<sup>20+</sup>             | number                                                             | 否  | 是  | 组件的导航目标ID。默认值：-1。|
| currentItem<sup>20+</sup>             | [AccessibilityGrid](#accessibilitygrid20)                                                             | 否  | 是  | 组件网格中的当前项。|
| spans<sup>20+</sup>             | [AccessibilitySpan](#accessibilityspan20)[]                                                             | 否  | 是  | 组件的辅助功能超链接文本信息数组。默认值：空数组。|
| accessibilityVisible<sup>20+</sup>  | boolean                                                            | 否  | 是  | 组件是否无障碍可见。true表示可见，false表示不可见。默认值：true。|
| mainWindowId<sup>20+</sup>             | number                                                             | 否  | 是  | 组件的主窗口ID。默认值：-1。|
| clip<sup>20+</sup>  | boolean                                                            | 否  | 是  | 组件是否需要裁剪。true表示需要裁剪，false表示不需要裁剪。默认值：false。|
| parentId<sup>20+</sup>             | number                                                             | 否  | 是  | 组件的父元素ID。默认值：-1。|
| childrenIds<sup>20+</sup>             | Array\<number>                                                             | 否  | 是  | 组件的子元素ID列表。默认值：空数组。|
| isEssential             | boolean              | 否   | 是   | 表示元素对用户是否是必需的。true表示元素是必需的，false表示元素不是必需的，默认值为false。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| belongTreeId             | number              | 否   | 是   | 表示元素所属的组件树ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| childrenTreeId             | number              | 否   | 是   | 表示元素的子组件树ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| customActions             | Array\<string>                                                             | 否  | 是  | 元素支持的自定义操作列表。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

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

    let windowId: number = 10;

    this.context.getRootInActiveWindow(windowId).then((element: AccessibilityElement) => {
      console.info('AccessibilityElement.checkable: ' + element.checkable);
      console.info('AccessibilityElement.checked: ' + element.checked);
      console.info('AccessibilityElement.clickable: ' + element.clickable);
      console.info('AccessibilityElement.componentId: ' + element.componentId);
      console.info('AccessibilityElement.componentType: ' + element.componentType);
      console.info('AccessibilityElement.contents: ' + element.contents);
      console.info('AccessibilityElement.currentIndex: ' + element.currentIndex);
      console.info('AccessibilityElement.description: ' + element.description);
      // ...
    }).catch((err: BusinessError) => {
      console.error(`Failed to get root in active window. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### enableScreenCurtain<sup>12+</sup>

enableScreenCurtain(isEnable: boolean): void

开启或关闭幕帘屏。幕帘屏开启后，屏幕显示内容将被隐藏（屏幕变暗），但设备仍可正常响应操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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
    this.context.getRootInActiveWindow().then((rootElement: AccessibilityElement) => {
      console.info(`succeeded in getting root element of the window, ${JSON.stringify(rootElement)}`);
      rootElement.enableScreenCurtain(true);
      console.info(`Succeeded in enabling screen curtain`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to enable screen curtain. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

### findElement('elementId')

findElement(type: 'elementId', condition: number): Promise\<AccessibilityElement>

根据elementId查询当前活动窗口下的节点元素。使用Promise异步回调。

与[findElementById](#findelementbyid20)均根据元素ID查找节点元素，功能等价，推荐优先使用findElementById。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                | 必填   | 说明                                       |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | 是    | 固定为'elementId'，表示根据elementId查询当前活动窗口下的节点元素。 |
| condition | number | 是    | 表示要查询的节点元素的elementId。                           |

**返回值：**

| 类型                                  | 说明                               |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement)&gt; | Promise对象，返回满足指定查询条件的节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// elementId为10。
let condition = 10;

// rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
rootElement.findElement('elementId', condition).then((data: AccessibilityElement) => {
  console.info(`succeeded in finding element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to find element. Code: ${err.code}, message: ${err.message}`);
});
```

### findElement('textType')

findElement(type: 'textType', condition: string): Promise\<Array\<AccessibilityElement>>

根据组件配置的accessibilityTextHint无障碍文本类型查询所有节点元素。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型     | 必填   | 说明                            |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | 是    | 固定为'textType'，表示根据文本类型查找节点元素。 |
| condition | string | 是    | 表示查找的无障碍文本类型条件，将返回accessibilityTextHint属性匹配该文本类型的所有节点元素。 |

**返回值：**

| 类型                                       | 说明                            |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement)&gt;&gt; | Promise对象，返回满足指定无障碍文本类型的所有节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// condition的内容需要与目标组件accessibilityTextHint属性的type字段值保持一致。
let condition = 'location'; 

// rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
rootElement.findElement('textType', condition).then((data: AccessibilityElement[]) => {
  console.info(`succeeded in finding element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to find element. Code: ${err.code}, message: ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(): Promise\<number>

获取文本组件中光标位置。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | Promise对象，返回当前光标所处位置。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
rootElement.getCursorPosition().then((data: number) => {
  console.info(`succeeded in getting cursor position, ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get cursor position. Code: ${err.code}, message: ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(callback: AsyncCallback\<number>): void

获取文本组件中光标位置。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数。当获取光标位置成功，err为undefined，data为光标在文本中的位置索引；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
rootElement.getCursorPosition((err: BusinessError, data: number) => {
  if (err && err.code) {
    console.error(`Failed to get cursor position. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`succeeded in getting cursor position, ${data}`);
});
```


### executeAction<sup>20+</sup>

executeAction(action: AccessibilityAction, parameters?: Parameter): Promise\<void>

根据action指定的操作类型和parameters，对无障碍节点元素执行相应操作。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明                                                       |
| ----------- | ---------------------------------------- | ---- |----------------------------------------------------------|
| action    | [AccessibilityAction](./js-apis-accessibility-sys.md#accessibilityaction)| 是    | 无障碍节点可执行的操作。|
| parameters | [Parameter](#parameter20) | 否    | 执行操作时设置的参数值。当执行需要额外参数配置的操作（如SET_SELECTION、SET_CURSOR_POSITION等）时传入此参数；执行无参数操作（如CLICK等）时不需要传入。不传入时默认为空。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.     |
| 9300005 | This action is not supported.            |

**示例：**

- 无参数Action。

  ```ts
  // 无参数Action示例：
  import { AccessibilityAction } from '@kit.AccessibilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
  // Action描述中无明确要求的，均为无参数Action。
  rootElement.executeAction(AccessibilityAction.CLICK).then(() => {
    console.info(`succeeded in performing action CLICK`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to perform action CLICK. Code: ${err?.code}, message: ${err?.message}`);
  });
  ```

- 有参数Action（setSelection）。

  ```ts
  // 有参数Action示例：
  import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // selectTextBegin：表示选择起始位置。
  // selectTextEnd：表示选择结束位置。
  // selectTextInForWard：true表示为前光标，false表示为后光标。
  let parameter : Parameter = { selectTextBegin: '0', selectTextEnd: '8', selectTextInForWard: true };
  // rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
  // setSelection示例代码。
  rootElement.executeAction(AccessibilityAction.SET_SELECTION, parameter).then(() => {
    console.info(`succeeded in performing action SET_SELECTION`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to perform action SET_SELECTION. Code: ${err?.code}, message: ${err?.message}`);
  });
  ```

- 有参数Action（setCursorPosition）。

  ```ts
  // 有参数Action示例：
  import { AccessibilityAction, Parameter } from '@kit.AccessibilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // offset：表示光标的设置位置。
  let parameter : Parameter = { offset: '1' };
  // rootElement是AccessibilityElement的实例，需通过AccessibilityExtensionContext.getAccessibilityFocusedElement()或getRootInActiveWindow()获取。
  // setCursorPosition示例代码。
  rootElement.executeAction(AccessibilityAction.SET_CURSOR_POSITION, parameter).then(() => {
    console.info(`succeeded in performing action SET_CURSOR_POSITION`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to perform action SET_CURSOR_POSITION. Code: ${err?.code}, message: ${err?.message}`);
  });
  ```

### getParent<sup>20+</sup>

getParent(): Promise\<AccessibilityElement>

获取无障碍节点元素的父元素。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)> | Promise对象，返回当前元素的父元素。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.info(`element parent id: ${element.parentId}`);
  element.getParent().then((parent: AccessibilityElement) => {
    console.info(`parent element's parent id: ${parent.parentId}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get parent. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
});
```

### getChildren<sup>20+</sup>

getChildren(): Promise\<Array\<AccessibilityElement>>

获取元素的子元素列表。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement)>> | Promise对象，返回当前元素的子元素列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getAccessibilityFocusedElement().then((element: AccessibilityElement) => {
  console.info(`element childrenIds: ${element.childrenIds}`);
  element.getChildren().then((children: AccessibilityElement[]) => {
    console.info(`children element's size: ${children.length}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get children. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
});
```

### getRoot<sup>20+</sup>

getRoot(): Promise\<AccessibilityElement>

获取活动窗口中的根元素。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)> | Promise对象，返回活动窗口中的根元素。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
let windows: AccessibilityElement[] = axContext.getAccessibilityWindowsSync();
for (let window of windows) {
  console.info(`window id: ${window.windowId}`);
  window.getRoot().then((root: AccessibilityElement) => {
    console.info(`root element's componentId: ${root.componentId}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get root. Code: ${err.code}, message: ${err.message}`);
  });
}
```

### findElementByContent<sup>20+</sup>

findElementByContent(condition: string): Promise\<Array\<AccessibilityElement>>

根据元素的内容文本查找节点元素，将返回包含指定文本的所有节点元素。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | 是 | 要查找的元素内容文本，设置后将返回包含该文本内容的所有节点元素。 |

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement)>> | Promise对象，返回包含指定内容的元素列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
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

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementByContent('connect').then((elements: AccessibilityElement[]) => {
        console.info('findElementByContent size=' + elements.length);
    }).catch((err: BusinessError) => {
        console.error(`Failed to find element by content. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to get root in active window. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementByFocusDirection<sup>20+</sup>

findElementByFocusDirection(condition: FocusDirection): Promise\<AccessibilityElement>

根据焦点方向查找元素。使用Promise异步回调。

与[findElementsByCondition](#findelementsbycondition23)相比，本方法主要用于查找Web组件；findElementsByCondition主要用于查找UI组件。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | [FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection) | 是 | 焦点方向，用于指定查找元素的搜索方向，如'forward'表示向前查找、'backward'表示向后查找等。 |

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)> | Promise对象，返回指定焦点方向的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
// 点击TextInput使其成为无障碍焦点元素，向上方向的下一个焦点元素是Text#connect。
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

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementByFocusDirection('up').then((element: AccessibilityElement) => {
        console.info('findElementByFocusDirection UP componentId: ' + element.componentId);
    }).catch((err: BusinessError) => {
        console.error(`Failed to find element by focus direction. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementByFocusDirection

findElementByFocusDirection(condition: FocusDirection, type: FocusRuleType): Promise\<AccessibilityElement>

根据焦点方向和聚焦类型查找元素。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | [FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection) | 是 | 焦点方向。 |
| type | [FocusRuleType](js-apis-accessibility-sys.md#focusruletype) | 是 | 聚焦类型。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)> | Promise对象，返回指定焦点方向上符合聚焦类型的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
// 点击“二级标题1”，使其成为无障碍焦点元素。下一个聚焦类型为标题焦点元素，是“二级标题2”。
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        
    SubHeader({
      secondaryTitle: '二级标题1',
      operationType: OperationType.BUTTON,
      operationItem: [{
        value: '操作',
        action: () => {
          Prompt.showToast({ message: 'demo' });
        }
      }]
    })

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))

    SubHeader({
      secondaryTitle: '二级标题2',
      operationType: OperationType.BUTTON,
      operationItem: [{
        value: '操作',
        action: () => {
          Prompt.showToast({ message: 'demo' });
        }
      }]
    })
  }

// AccessibilityExtAbility.ets
import { AccessibilityElement, FocusRuleType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementByFocusDirection('forward', FocusRuleType.FOCUS_BY_TITLE).then((element: AccessibilityElement) => {
        console.info(`findElementByFocusDirection forward componentId: ${element.componentId}`);
    }).catch((err: BusinessError) => {
        console.error(`Failed to findElementByFocusDirection forward. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to getAccessibilityFocusedElement. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementsByAccessibilityHintText<sup>20+</sup>

findElementsByAccessibilityHintText(condition: string): Promise\<Array\<AccessibilityElement>>

根据提示文本查找元素，将返回accessibilityTextHint属性匹配该文本的所有节点元素。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | string | 是 | 要查找的元素提示文本。 |

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<Array\<[AccessibilityElement](#accessibilityelement)>> | Promise对象，返回包含指定提示文本的元素列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
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

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getRootInActiveWindow(windowId).then((root: AccessibilityElement) => {
    root.findElementsByAccessibilityHintText('location').then((elements: AccessibilityElement[]) => {
        console.info('findElementsByAccessibilityHintText size=' + elements.length);
    }).catch((err: BusinessError) => {
        console.error(`Failed to find elements by accessibility hint text. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to get root in active window. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementById<sup>20+</sup>

findElementById(condition: number): Promise\<AccessibilityElement>

根据元素ID查找当前活动窗口下的节点元素。使用Promise异步回调。

与[findElement('elementId')](#findelementelementid)功能等价，推荐优先使用本方法。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| condition | number | 是 | 表示要查询的节点元素的ID。 |

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<[AccessibilityElement](#accessibilityelement)> | Promise对象，返回指定ID的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.|
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300006 | The target application failed to connect to accessibility service. |

**示例：**

```ts
// Page.ets
// 点击TextInput使其成为无障碍焦点元素。
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

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementById(0).then((element: AccessibilityElement) => {
        console.info('findElementById componentId: ' + element.componentId);
    }).catch((err: BusinessError) => {
        console.error(`Failed to find element by id. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementsByCondition<sup>23+</sup>

findElementsByCondition(rule: FocusRule, condition: FocusCondition): Promise\<FocusMoveResult>

查询满足条件的可聚焦节点。使用Promise异步回调。

与[findElementByFocusDirection](#findelementbyfocusdirection20)相比，本方法主要用于查找UI组件；findElementByFocusDirection主要用于查找Web组件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| rule | [FocusRule](#focusrule23) | 是| 检查当前节点及其子节点的规则。 |
| condition | [FocusCondition](#focuscondition23) | 是| 表示查询可聚焦节点方式。 |

**返回值：**

| 类型                                      | 说明                   |
| ---------------------------------------- | --------------------- |
| Promise\<[FocusMoveResult](#focusmoveresult23)> | Promise对象，返回包含查询到的无障碍节点列表及查询结果状态码的FocusMoveResult对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts

import { AccessibilityElement, FocusMoveResult } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// axContext是AccessibilityExtensionContext的实例，需通过AccessibilityExtensionAbility子类实例的context属性获取，详见使用说明。
axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementsByCondition('bypassSelf', 'forward').then((res: FocusMoveResult) => {
        console.info('findElementsByCondition result: ' + res.result);
    }).catch((err: BusinessError) => {
        console.error(`Failed to find elements by condition. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to get accessibility focused element. Code: ${err.code}, message: ${err.message}`);
});
```

### findElementsByCondition

findElementsByCondition(rule: FocusRule, condition: FocusCondition, type: FocusRuleType): Promise\<FocusMoveResult>

根据规则和查询条件查找目标类型的可聚焦节点。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 名称 | 类型 | 必填 | 描述 |
| -------- | ---- | -------- | ------------------------------------------------------------ |
| rule | [FocusRule](#focusrule23) | 是 | 检查当前节点及其子节点的规则。 |
| condition | [FocusCondition](#focuscondition23) | 是 | 表示查询可聚焦节点方式。 |
| type | [FocusRuleType](js-apis-accessibility-sys.md#focusruletype) | 是 | 聚焦类型。 |

**返回值：**

| 类型                                      | 描述                   |
| ---------------------------------------- | --------------------- |
| Promise\<[FocusMoveResult](#focusmoveresult23)> | Promise对象，返回查询结果对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                                    |
| ------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
// Page.ets
  build() {
    Text('Connect')
        .id('connect')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        
    SubHeader({
      secondaryTitle: '二级标题1',
      operationType: OperationType.BUTTON,
      operationItem: [{
        value: '操作',
        action: () => {
          Prompt.showToast({ message: 'demo' });
        }
      }]
    })

    TextInput({ placeholder: 'please input...' })
        .id('text_input')
        .fontSize($r('app.float.page_text_font_size'))

    SubHeader({
      secondaryTitle: '二级标题2',
      operationType: OperationType.BUTTON,
      operationItem: [{
        value: '操作',
        action: () => {
          Prompt.showToast({ message: 'demo' });
        }
      }]
    })
  }

// AccessibilityExtAbility.ets

import { AccessibilityElement, FocusRuleType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getAccessibilityFocusedElement().then((focus: AccessibilityElement) => {
    focus.findElementsByCondition("bypassSelf", "forward", FocusRuleType.FOCUS_BY_TITLE).then((res: FocusMoveResult) => {
        console.info(`findElementsByCondition result: ${res.result}`);
    }).catch((err: BusinessError) => {
        console.error(`Failed to findElementsByCondition. Code: ${err.code}, message: ${err.message}`);
    });
}).catch((err: BusinessError) => {
  console.error(`Failed to getAccessibilityFocusedElement. Code: ${err.code}, message: ${err.message}`);
});
```

## ElementAttributeValues

节点元素具备的属性名称及属性值类型信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称                   | 类型                                                              | 只读 | 可选 | 说明              |
|----------------------|--------------------------------------------------------------------|------|------|-------------------|
| accessibilityStateDescription<sup>23+</sup> | string                                      | 否   | 是   | 元素的自定义无障碍状态播报文本信息。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| isEssential             | boolean              | 否   | 是   | 表示元素对用户是否是必需的。true表示元素是必需的，false表示元素不是必需的，默认值为false。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| belongTreeId             | number              | 否   | 是   | 表示元素所属的组件树ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| childrenTreeId             | number              | 否   | 是   | 表示元素的子组件树ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| currentItem             | [AccessibilityGrid](#accessibilitygrid20)              | 否   | 是   | 表示组件网格中的当前项。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| span             | [AccessibilitySpan](#accessibilityspan20)[]              | 否   | 是   | 表示元素的超链接文本信息数组。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| childrenIds             |      Array&lt;number&gt;         | 否   | 是   | 表示元素的子组件ID列表。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| parentId             | number              | 否   | 是   | 表示元素的父组件ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| mainWindowId             | number              | 否   | 是   | 表示元素的主窗口ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| accessibilityVisible             | boolean              | 否   | 是   | 表示元素是否是无障碍可见的。true表示元素是无障碍可见的，false表示元素是无障碍不可见的，默认值为true。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| navDestinationId             | number              | 否   | 是   | 表示元素所关联的导航目标ID。默认值为-1。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| customActions | Array\<string>                     | 否   | 是   | 元素支持的自定义操作列表。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。|
