# AccessibilityExtensionContext (辅助功能扩展上下文)

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

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

## ElementAttributeValues

节点元素具备的属性名称及属性值类型信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称                   | 类型                                                                 | 可读  | 可写  | 说明                  |
|----------------------|--------------------------------------------------------------------|-----|-----| ------------------- |
| accessibilityFocused | boolean                                                            | 是   | 否   |   accessibility焦点状态。   |
| accessibilityText<sup>12+</sup> | string                                                  | 是   | 否   | 元素的无障碍文本信息。 |
| bundleName           | string                                                             | 是   | 否   | 应用包名。 |
| checkable            | boolean                                                            | 是   | 否   | 元素是否可查。 |
| checked              | boolean                                                            | 是   | 否   | 元素是否被检查。 |
| children             | Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;        | 是   | 否   | 所有子元素。 |
| clickable            | boolean                                                            | 是   | 否   | 是否可点击。 |
| componentId          | number                                                             | 是   | 否   | 元素所属的组件ID。 |
| componentType        | string                                                             | 是   | 否   | 元素所属的组件类型。 |
| contents             | Array&lt;string&gt;                                                | 是   | 否   | 内容。 |
| currentIndex         | number                                                             | 是   | 否   | 当前项的索引。 |
| description          | string                                                             | 是   | 否   | 元素的描述信息。 |
| editable             | boolean                                                            | 是   | 否   | 元素是否可编辑。 |
| endIndex             | number                                                             | 是   | 否   | 屏幕最后显示项的列表索引。 |
| error                | string                                                             | 是   | 否   | 错误状态字符串。 |
| focusable            | boolean                                                            | 是   | 否   | 元素是否可聚焦。 |
| hintText             | string                                                             | 是   | 否   | 提示文本。 |
| inputType            | number                                                             | 是   | 否   | 输入文本的类型。 |
| inspectorKey         | string                                                             | 是   | 否   | 检查键。 |
| isActive             | boolean                                                            | 是   | 否   | 元素是否处于活动状态。 |
| isEnable             | boolean                                                            | 是   | 否   | 元素是否启用。 |
| isHint               | boolean                                                            | 是   | 否   | 元素是否为提示状态。 |
| isFocused            | boolean                                                            | 是   | 否   | 元素是否聚焦。 |
| isPassword           | boolean                                                            | 是   | 否   | 元素是否为密码。 |
| isVisible            | boolean                                                            | 是   | 否   | 元素是否可见。 |
| itemCount            | number                                                             | 是   | 否   | 项目的总数。 |
| lastContent          | string                                                             | 是   | 否   | 最后的内容。 |
| layer                | number                                                             | 是   | 否   | 该元素的显示层。 |
| longClickable        | boolean                                                            | 是   | 否   | 元素是否可长单击。 |
| pageId               | number                                                             | 是   | 否   | 页码id。 |
| parent               | [AccessibilityElement](#accessibilityelement9)                     | 是   | 否   | 元素的父元素。 |
| pluralLineSupported  | boolean                                                            | 是   | 否   | 元素是否支持多行文本。 |
| rect                 | [Rect](#rect)                                                      | 是   | 否   | 元素的面积。 |
| resourceName         | string                                                             | 是   | 否   | 元素的资源名称。 |
| rootElement          | [AccessibilityElement](#accessibilityelement9)                     | 是   | 否   | 窗口元素的根元素。 |
| screenRect           | [Rect](#rect)                                                      | 是   | 否   | 元素的显示区域。 |
| scrollable           | boolean                                                            | 是   | 否   | 元素是否可滚动。 |
| selected             | boolean                                                            | 是   | 否   | 元素是否被选中。 |
| startIndex           | number                                                             | 是   | 否   | 在屏幕上的第一个项目的列表索引。 |
| text                 | string                                                             | 是   | 否   | 元素的文本。 |
| textLengthLimit      | number                                                             | 是   | 否   | 元素文本的最大长度限制。 |
| textMoveUnit         | [accessibility.TextMoveUnit](js-apis-accessibility.md#textmoveunit) | 是   | 否   | 文本被读取时的移动单位。 |
| triggerAction        | [accessibility.Action](js-apis-accessibility.md#action)         | 是   | 否   | 触发元素事件的动作。 |
| type                 | [WindowType](#windowtype)                                          | 是   | 否   | 元素的窗口类型。 |
| valueMax             | number                                                             | 是   | 否   | 最大值。 |
| valueMin             | number                                                             | 是   | 否   | 最小值。|
| valueNow             | number                                                             | 是   | 否   | 当前值。 |
| windowId             | number                                                             | 是   | 否   | 窗口id。 |
| textType<sup>12+</sup>             | string                                                             | 是   | 否   | 元素的无障碍文本类型，由组件accessibilityTextHint属性配置。 |
| offset<sup>12+</sup>             | number                                                             | 是   | 否   | 对于可滚动类控件，如List、Grid，内容区相对控件的顶部坐标滚动的像素偏移量。 |
| hotArea<sup>12+</sup>             | [Rect](#rect)                                                              | 是   | 否   | 元素的可触摸区域。 |

## FocusDirection

type FocusDirection = 'up' | 'down' | 'left' | 'right' | 'forward' | 'backward'

表示查询下一焦点元素的方向。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型       | 说明      |
| -------- | ------- |
| 'up'       | 表示向上查询。 |
| 'down'     | 表示向下查询。 |
| 'left'     | 表示向左查询。 |
| 'right'    | 表示向右查询。 |
| 'forward'  | 表示向前查询。 |
| 'backward' | 表示向后查询。 |

## FocusType

type FocusType = 'accessibility' | 'normal'

表示查询焦点元素的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型            | 说明          |
| ------------- | ----------- |
| 'accessibility' | 表示无障碍的焦点类型。 |
| 'normal'        | 表示普通的焦点类型。  |

## Rect

表示矩形区域。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称     | 类型     | 可读   | 可写   | 说明        |
| ------ | ------ | ---- | ---- | --------- |
| left   | number | 是    | 否    | 矩形区域的左边界。 |
| top    | number | 是    | 否    | 矩形区域的上边界。 |
| width  | number | 是    | 否    | 矩形区域的宽度。  |
| height | number | 是    | 否    | 矩形区域的高度。  |

## WindowType

type WindowType = 'application' | 'system'

表示窗口的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型          | 说明        |
| ----------- | --------- |
| 'application' | 表示应用窗口类型。 |
| 'system'      | 表示系统窗口类型。 |

## AccessibilityExtensionContext.setTargetBundleName<sup>(deprecated)</sup>

setTargetBundleName(targetNames: Array\<string>): Promise\<void>;

设置关注的目标包名，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                  | 必填   | 说明       |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | 是    | 设置关注应用的包名，服务接收关注应用的无障碍事件，默认接收所有应用的无障碍事件，取消关注应用则传空数组。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNames = ['com.ohos.xyz'];
axContext.setTargetBundleName(targetNames).then(() => {
  console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
}).catch((err: BusinessError) => {
  console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.setTargetBundleName<sup>(deprecated)</sup>

setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void;

设置关注的目标包名，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                        | 必填   | 说明                                       |
| ----------- | ------------------------- | ---- | ---------------------------------------- |
| targetNames | Array&lt;string&gt;       | 是    | 设置关注应用的包名，服务接收关注应用的无障碍事件，默认接收所有应用的无障碍事件，取消关注应用则传空数组。                                 |
| callback    | AsyncCallback&lt;void&gt; | 是    | 回调函数，如果设置关注的目标包名失败，则AsyncCallback中err有数据返回。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNames = ['com.ohos.xyz'];
try {
  axContext.setTargetBundleName(targetNames, (err: BusinessError) => {
    if (err && err.code) {
      console.error(`failed to set target bundle names, Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in set target bundle names, targetNames is ${targetNames}`);
  });
} catch (error) {
  console.error(`failed to set target bundle names, Because ${JSON.stringify(error)}`);
}
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

获取焦点元素, 使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型      | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | 否    | 获取的是否是无障碍焦点元素，True表示是，False表示否，默认为否。 |

**返回值：**
| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise对象，返回当前对应的焦点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getFocusElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get focus element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
})
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;

获取焦点元素, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回当前对应的焦点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getFocusElement((err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getFocusElement<sup>(deprecated)</sup>

getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;

获取焦点元素, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                |
| -------------------- | ---------------------------------------- | ---- | ----------------- |
| isAccessibilityFocus | boolean                                  | 是    | 获取的是否是无障碍焦点元素，True表示是，False表示否。    |
| callback             | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回当前对应的焦点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let isAccessibilityFocus = true;
let rootElement: AccessibilityElement;

axContext.getFocusElement(isAccessibilityFocus, (err: BusinessError, data: AccessibilityElement)=> {
  if (err && err.code) {
    console.error(`failed to get focus element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get focus element, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

获取指定窗口的根节点元素, 使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                     |
| -------- | ------ | ---- | ---------------------- |
| windowId | number | 否    | 指定窗口的编号，未指定则从当前活跃窗口获取。 |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise对象，返回指定窗口的根节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;

获取指定窗口的根节点元素, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                 |
| -------- | ---------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回指定窗口的根节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement((err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindowRootElement<sup>(deprecated)</sup>

getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void;

获取指定窗口的根节点元素, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                     |
| -------- | ---------------------------------------- | ---- | ---------------------- |
| windowId | number                                   | 是    | 指定窗口的编号，未指定则从当前活跃窗口获取。 |
| callback | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回指定窗口的根节点元素。     |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowId = 10;
let rootElement: AccessibilityElement;

axContext.getWindowRootElement(windowId, (err: BusinessError, data: AccessibilityElement) => {
  if (err && err.code) {
    console.error(`failed to get root element of the window, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  rootElement = data;
  console.info(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;

获取指定屏幕中的所有窗口, 使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型     | 必填   | 说明                    |
| --------- | ------ | ---- | --------------------- |
| displayId | number | 否    | 指定的屏幕编号，未指定则从默认主屏幕获取。 |

**返回值：**

| 类型                                       | 说明                     |
| ---------------------------------------- | ---------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Promise对象，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getWindows().then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in get windows, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

获取指定屏幕中的所有窗口, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | 是    | 回调函数，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

axContext.getWindows((err: BusinessError, data: AccessibilityElement[]) => {
  if (err && err.code) {
    console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get windows, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.getWindows<sup>(deprecated)</sup>

getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

获取指定屏幕中的所有窗口, 使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                    |
| --------- | ---------------------------------------- | ---- | --------------------- |
| displayId | number                                   | 是    | 指定的屏幕编号，未指定则从默认主屏幕获取。 |
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | 是    | 回调函数，返回指定屏幕的所有窗口。     |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let displayId = 10;
axContext.getWindows(displayId, (err: BusinessError, data: AccessibilityElement[]) => {
  if (err && err.code) {
    console.error(`failed to get windows, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get windows, ${JSON.stringify(data)}`);
});
```

## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath): Promise\<void>;

> **说明：**
>
> 从API version 10开始废弃。

注入手势，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                                                 | 必填   | 说明         |
| ----------- |--------------------------------------------------------------------| ---- | ---------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | 是    | 表示手势的路径信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let gesturePath: GesturePath = new GesturePath(100);

for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGesture(gesturePath).then(() => {
  console.info(`Succeeded in inject gesture,gesturePath is ${gesturePath}`);
}).catch((err: BusinessError) => {
  console.error(`failed to inject gesture, Code is ${err.code}, message is ${err.message}`);
});
```
## AccessibilityExtensionContext.injectGesture<sup>(deprecated)</sup>

injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void

> **说明：**
>
> 从API version 10开始废弃。

注入手势，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                                                 | 必填   | 说明                  |
| ----------- |--------------------------------------------------------------------| ---- | ------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | 是    | 表示手势的路径信息。          |
| callback    | AsyncCallback&lt;void&gt;                                          | 是    | 回调函数，表示注入手势执行结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                                     |
| ------- | ---------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

**示例：**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let gesturePath: GesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGesture(gesturePath, (err: BusinessError) => {
  if (err) {
    console.error(`failed to inject gesture, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in inject gesture,gesturePath is ${gesturePath}`);
});
```
## AccessibilityExtensionContext.injectGestureSync<sup>(deprecated)</sup>

injectGestureSync(gesturePath: GesturePath): void

注入手势。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                                                 | 必填 | 说明                 |
| ----------- |--------------------------------------------------------------------| ---- | -------------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | 是   | 表示手势的路径信息。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003  | No accessibility permission to perform the operation. |

**示例：**

```ts
import { GesturePath, GesturePoint } from '@kit.AccessibilityKit';

let gesturePath: GesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
  let gesturePoint = new GesturePoint(100, i * 200);
  gesturePath.points.push(gesturePoint);
}
axContext.injectGestureSync(gesturePath);
```

## AccessibilityElement<sup>9+</sup>

无障碍节点元素, 在调用AccessibilityElement的方法前，需要先通过[AccessibilityExtensionContext.getFocusElement() ](#accessibilityextensioncontextgetfocuselementdeprecated)或者[AccessibilityExtensionContext.getWindowRootElement() ](#accessibilityextensioncontextgetwindowrootelementdeprecated)获取AccessibilityElement实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.BarrierFree.Accessibility.Core

### attributeNames<sup>(deprecated)</sup>

attributeNames\<T extends keyof ElementAttributeValues>() : Promise\<Array\<T>>;

获取节点元素的所有属性名称，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                            | 说明                       |
| ----------------------------- | ------------------------ |
| Promise&lt;Array&lt;T&gt;&gt; | Promise对象，返回节点元素的所有属性名称。 |

**示例：**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
rootElement.attributeNames().then((data: ElementAttributeKeys[]) => {
  console.log(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.log(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeNames<sup>(deprecated)</sup>

attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void;

获取节点元素的所有属性名称，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                  |
| -------- | ----------------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | 是    | 回调函数，返回节点元素的所有属性名称。 |

**示例：**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
rootElement.attributeNames((err: BusinessError, data: ElementAttributeKeys[]) => {
  if (err && err.code) {
    console.error(`failed to get attribute names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute names, ${JSON.stringify(data)}`);
});
```

### attributeValue<sup>(deprecated)</sup>

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;

根据属性名称获取属性值，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core


**参数：**

| 参数名           | 类型   | 必填   | 说明       |
| ------------- | ---- | ---- | -------- |
| attributeName | ElementAttributeKeys  | 是    | 表示属性的名称。 |

**返回值：**

| 类型                                       | 说明                          |
| ---------------------------------------- | --------------------------- |
| Promise&lt;ElementAttributeValues[T]&gt; | Promise对象，返回根据节点属性名称获取的属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300004 | This property does not exist. |


**示例：**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let attributeName: ElementAttributeKeys = 'bundleName';

// rootElement是AccessibilityElement的实例
rootElement.attributeValue(attributeName).then((data: string) => {
  console.log(`Succeeded in get attribute value by name, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
});
```

### attributeValue<sup>(deprecated)</sup>

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, 
    callback: AsyncCallback\<ElementAttributeValues[T]>): void;

根据属性名称获取属性值，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名           | 类型                                       | 必填   | 说明                     |
| ------------- | ---------------------------------------- | ---- | ---------------------- |
| attributeName | ElementAttributeKeys                         | 是    | 表示属性的名称。               |
| callback      | AsyncCallback&lt;ElementAttributeValues[T]&gt; | 是    | 回调函数，返回根据节点属性名称获取的属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300004 | This property does not exist. |

**示例：**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let attributeName: ElementAttributeKeys = 'bundleName';

// rootElement是AccessibilityElement的实例
rootElement.attributeValue(attributeName, (err: BusinessError, data: string) => {
  if (err && err.code) {
    console.error(`failed to get attribute value, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get attribute value, ${JSON.stringify(data)}`);
});
```

### actionNames<sup>(deprecated)</sup>

actionNames(): Promise\<Array\<string>>;

获取节点元素支持的所有操作名称，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                 | 说明                         |
| ---------------------------------- | -------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回节点元素支持的所有操作名称。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
rootElement.actionNames().then((data: string[]) => {
  console.log(`Succeeded in get action names, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
})
```

### actionNames<sup>(deprecated)</sup>

actionNames(callback: AsyncCallback\<Array\<string>>): void;

获取节点元素支持的所有操作名称，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                    |
| -------- | ---------------------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 回调函数，返回节点元素支持的所有操作名称。 |

**示例：**

```ts
// rootElement是AccessibilityElement的实例
rootElement.actionNames((err: BusinessError, data: string[]) => {
  if (err && err.code) {
    console.error(`failed to get action names, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get action names, ${JSON.stringify(data)}`);
})
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, parameters?: object): Promise\<void>;

根据操作名称执行某个操作，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明                                                       |
| ----------- | ---------------------------------------- | ---- |----------------------------------------------------------|
| actionName | string | 是    | 表示属性的名称，取值参考[Action](./js-apis-accessibility.md#action)。 
| parameters | object | 否    | 表示执行操作时所需要的参数；默认为空。                             |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';

// rootElement是AccessibilityElement的实例
rootElement.performAction(actionName).then(() => {
  console.info(`Succeeded in perform action,actionName is ${actionName}`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

**无参数Action示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
// Action描述中无明确要求的，均为无参数Action
rootElement.performAction('click').then(() => {
  console.info(`Succeeded in perform action.`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

**有参数Action示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
// setSelection示例代码
rootElement.performAction('setSelection', {
  selectTextBegin: '0', // 表示选择起始位置
  selectTextEnd: '8',   // 表示选择结束位置
  selectTextInForWard: true   // true表示为前光标，false表示为后光标
}).then(() => {
  console.info(`Succeeded in perform action`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement是AccessibilityElement的实例
// setCursorPosition示例代码
rootElement.performAction('setCursorPosition', {
  offset: '1'   // 表示光标的设置位置
}).then(() => {
  console.info(`Succeeded in perform action`);
}).catch((err: BusinessError) => {
  console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
});
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, callback: AsyncCallback\<void>): void;

根据操作名称执行某个操作，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | 是    | 表示属性的名称，取值参考[Action](./js-apis-accessibility.md#action)。 
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，表示执行指定操作的回调。|

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';

// rootElement是AccessibilityElement的实例
rootElement.performAction(actionName, (err: BusinessError) => {
  if (err && err.code) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action, actionName is ${actionName}`);
});
```

### performAction<sup>(deprecated)</sup>

performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void;

根据操作名称执行某个操作，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                                          |
| ---------- | ------------------------- | ---- |-------------------------------------------------------------|
| actionName | string                    | 是    | 表示属性的名称，取值参考[Action](./js-apis-accessibility.md#action)。 |
| parameters | object                    | 是    | 表示执行操作时所需要的参数；默认为空。                                |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数，表示执行指定操作的回调。                                           |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300005 | This action is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let actionName = 'action';
let parameters: object = [];

// rootElement是AccessibilityElement的实例
rootElement.performAction(actionName, parameters, (err: BusinessError) => {
  if (err && err.code) {
    console.error(`failed to perform action, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in perform action,actionName is ${actionName}, parameters is ${parameters}`);
});
```

### findElement('content')<sup>(deprecated)</sup>

findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;

根据节点内容查询所有节点元素，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型     | 必填   | 说明                            |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | 是    | 固定为'content', 表示查找的类型为节点元素内容。 |
| condition | string | 是    | 表示查找的条件。                      |

**返回值：**

| 类型                                       | 说明                            |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | Promise对象，返回满足指定查询关键字的所有节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let condition = 'keyword';

// rootElement是AccessibilityElement的实例
rootElement.findElement('content', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('content')<sup>(deprecated)</sup>

findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

根据节点内容查询所有节点元素。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                           |
| --------- | ---------------------------------------- | ---- | ---------------------------- |
| type      | string                                   | 是    | 固定为'content',表示查找的类型为节点元素内容。 |
| condition | string                                   | 是    | 表示查找的条件。                     |
| callback  | AsyncCallback&lt;Array&lt;[AccessibilityElement](#accessibilityelement9)&gt;&gt; | 是    | 回调函数，返回满足指定查询关键字的所有节点元素。     |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let condition = 'keyword';

// rootElement是AccessibilityElement的实例
rootElement.findElement('content', condition, (err: BusinessError, data: AccessibilityElement[])=>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusType')<sup>(deprecated)</sup>

findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;

根据焦点元素类型查询节点元素，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                      | 必填   | 说明                                 |
| --------- | ----------------------- | ---- | ---------------------------------- |
| type      | string                  | 是    | 固定为'focusType', 表示查询的类型为节点的焦点元素类型。 |
| condition | [FocusType](#focustype) | 是    | 表示查询焦点元素的类型。                       |

**返回值：**

| 类型                                  | 说明                             |
| ----------------------------------- | ------------------------------ |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise对象，返回满足指定查询焦点元素类型的节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { FocusType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusType = 'normal';

// rootElement是AccessibilityElement的实例
rootElement.findElement('focusType', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element,${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusType')<sup>(deprecated)</sup>

findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void;

根据焦点元素类型查询节点元素，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                 |
| --------- | ---------------------------------------- | ---- | ---------------------------------- |
| type      | string                                   | 是    | 固定为'focusType', 表示查询的类型为节点的焦点元素类型。 |
| condition | [FocusType](#focustype)                  | 是    | 表示查询焦点元素的类型。                       |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回满足指定查询焦点元素类型的节点元素。          |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { FocusType } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusType = 'normal';

// rootElement是AccessibilityElement的实例
rootElement.findElement('focusType', condition, (err: BusinessError, data: AccessibilityElement)=>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```

### findElement('focusDirection')<sup>(deprecated)</sup>

findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;

根据下一焦点元素方向查询节点元素，使用Promise异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                | 必填   | 说明                                       |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | 是    | 固定为'focusDirection', 表示查询的类型为节点的下一焦点元素方向。 |
| condition | [FocusDirection](#focusdirection) | 是    | 表示查询下一焦点元素的方向。                           |

**返回值：**

| 类型                                  | 说明                               |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](#accessibilityelement9)&gt; | Promise对象，返回满足指定查询下一焦点元素方向的节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusDirection = 'up';

// rootElement是AccessibilityElement的实例
rootElement.findElement('focusDirection', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('focusDirection')<sup>(deprecated)</sup>

findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void;

根据下一焦点元素方向查询节点元素，使用callback异步回调。

> **说明：**
>
> 从API version 12开始废弃。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                                       |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type      | string                                   | 是    | 固定为'focusDirection', 表示查询的类型为节点的下一焦点元素方向。 |
| condition | [FocusDirection](#focusdirection)        | 是    | 表示下一查询焦点元素的方向。                           |
| callback  | AsyncCallback&lt;[AccessibilityElement](#accessibilityelement9)&gt; | 是    | 回调函数，返回满足指定查询下一焦点元素方向的节点元素。              |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID   | 错误信息                          |
| ------- | ----------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let condition: FocusDirection = 'up';

// rootElement是AccessibilityElement的实例
rootElement.findElement('focusDirection', condition, (err: BusinessError, data: AccessibilityElement) =>{
  if (err && err.code) {
    console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in find element, ${JSON.stringify(data)}`);
});
```