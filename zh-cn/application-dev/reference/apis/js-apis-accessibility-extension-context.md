# 辅助功能扩展上下文

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用AccessibilityExtensionContext的功能前，需要通过AccessibilityExtensionAbility子类实例获取AccessibilityExtensionContex的实例。

```js
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility'
let axContext;
class MainAbility extends AccessibilityExtensionAbility {
    onConnect(): void {
        console.log('AxExtensionAbility onConnect');
        axContext = this.context;
    }
}
```

## FocusDirection

表示查询下一焦点元素的方向。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称       | 描述      |
| -------- | ------- |
| up       | 表示向上查询。 |
| down     | 表示向上查询。 |
| left     | 表示向左查询。 |
| right    | 表示向右查询。 |
| forward  | 表示向前查询。 |
| backward | 表示向后查询。 |

## FocusType

表示查询焦点元素的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称            | 描述          |
| ------------- | ----------- |
| accessibility | 表示无障碍的焦点类型。 |
| normal        | 表示普通的焦点类型。  |

## Rect

表示矩形区域。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称     | 类型   | 可读   | 可写   | 说明        |
| ------ | ------ | ---- | ---- | --------- |
| left   | number | 是    | 否    | 矩形区域的左边界。 |
| top    | number | 是    | 否    | 矩形区域的上边界。 |
| width  | number | 是    | 否    | 矩形区域的宽度。  |
| height | number | 是    | 否    | 矩形区域的高度。  |

## WindowType

表示窗口的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称          | 描述        |
| ----------- | --------- |
| application | 表示应用窗口类型。 |
| system      | 表示系统窗口类型。 |

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>): Promise\<void>;

设置关注的目标包名，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                | 必填   | 说明       |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | 是    | 关注的目标包名。 |

**返回值：**

| 类型                     | 说明                    |
| ---------------------- | --------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
let targetNames = ['com.ohos.xyz'];
try {
    axContext.setTargetBundleName(targetNames).then(() => {
        console.info('set target bundle names success');
    }).catch((err) => {
        console.error('failed to set target bundle names, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to set target bundle names, because ' + JSON.stringify(exception));
};
```

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void;

设置关注的目标包名，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                | 必填   | 说明       |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | 是    | 关注的目标包名。 |
| callback    | AsyncCallback&lt;void&gt; | 是    | 回调函数，如果设置关注的目标包名失败，则AsyncCallback中err有数据返回。 |

**示例：**

```ts
let targetNames = ['com.ohos.xyz'];
try {
    axContext.setTargetBundleName(targetNames, (err, data) => {
        if (err) {
            console.error('failed to set target bundle names, because ' + JSON.stringify(err));
            return;
        }
        console.info('set target bundle names success');
    });
} catch (exception) {
    console.error('failed to set target bundle names, because ' + JSON.stringify(exception));
};
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

获取焦点元素, 使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | 否    | 获取的是否是无障碍焦点元素，默认为否。 |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise对象，返回当前对应的焦点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
let focusElement;
try {
    axContext.getFocusElement().then((data) => {
        focusElement = data;
        console.log('get focus element success');
    }).catch((err) => {
        console.error('failed to get focus element, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get focus element, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;

获取焦点元素, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback    | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回当前对应的焦点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
try {
    axContext.getFocusElement((err, data) => {
        if (err) {
            console.error('failed to get focus element, because ' + JSON.stringify(err));
            return;
        }
        focusElement = data;
        console.info('get focus element success');
    });
} catch (exception) {
    console.error('failed to get focus element, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;

获取焦点元素, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | 是    | 获取的是否是无障碍焦点元素。 |
| callback    | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回当前对应的焦点元素。 |

**示例：**

```ts
try {
    axContext.getFocusElement(isAccessibilityFocus, (err, data) => {
    if (err) {
        console.error('failed to get focus element, because ' + JSON.stringify(err));
        return;
    }
    focusElement = data;
    console.info('get focus element success');
});
} catch (exception) {
    console.error('failed to get focus element, because ' + JSON.stringify(exception));
}
```
## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

获取指定窗口的根节点元素, 使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| windowId | number | 否    | 指定窗口的编号，未指定则从当前活跃窗口获取。 |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise对象，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
let rootElement;
try {
    axContext.getWindowRootElement().then((data) => {
        rootElement = data;
        console.log('get root element of the window success');
    }).catch((err) => {
        console.error('failed to get root element of the window, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get root element of the window, ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;

获取指定窗口的根节点元素, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback    | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回指定窗口的根节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
try {
    axContext.getWindowRootElement((err, data) => {
    if (err) {
        console.error('failed to get root element of the window, because ' + JSON.stringify(err));
        return;
    }
    rootElement = data;
    console.info('get root element of the window success');
});
} catch (exception) {
    console.error('failed to get root element of the window, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void;

获取指定屏幕中的所有窗口, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| windowId | number | 是    | 指定窗口的编号，未指定则从当前活跃窗口获取。 |
| callback    | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回指定窗口的根节点元素。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
try {
    axContext.getWindowRootElement(windowId, (err, data) => {
    if (err) {
        console.error('failed to get root element of the window, because ' + JSON.stringify(err));
        return;
    }
    rootElement = data;
    console.info('get root element of the window success');
});
} catch (exception) {
    console.error('failed to get root element of the window, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;

获取指定屏幕中的所有窗口, 使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| displayId | number | 否    | 指定的屏幕编号，未指定则从默认主屏幕获取。 |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise对象，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
let windows;
try {
    axContext.getWindows().then((data) => {
        windows = data;
        console.log('get windows success');
    }).catch((err) => {
        console.error('failed to get windows, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get windows, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getWindows

getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

获取指定屏幕中的所有窗口, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback    | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | 是    | 回调函数，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
let windows;
try {
    axContext.getWindows((err, data) => {
        if (err) {
            console.error('failed to get windows, because ' + JSON.stringify(err));
            return;
        }
        windows = data;
        console.info('get windows success');
    });
} catch (exception) {
    console.error('failed to get windows, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

获取指定屏幕中的所有窗口, 使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名                  | 类型    | 必填   | 说明                  |
| -------------------- | ------- | ---- | ------------------- |
| displayId | number | 是    | 指定的屏幕编号，未指定则从默认主屏幕获取。 |
| callback    | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | 是    | 回调函数，返回指定屏幕的所有窗口。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
let windows;
let displayId = 10;
try {
    axContext.getWindows(displayId, (err, data) => {
        if (err) {
            console.error('failed to get windows, because ' + JSON.stringify(err));
            return;
        }
        windows = data;
        console.info('get windows success');
    });
} catch (exception) {
    console.error('failed to get windows, because ' + JSON.stringify(exception));
}
```

## AccessibilityExtensionContext.injectGesture

injectGesture(gesturePath: GesturePath): Promise\<void>;

注入手势，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | 是    | 表示手势的路径信息。     |

**返回值：**

| 类型                                  | 说明                     |
| ----------------------------------- | ---------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
import GesturePath from "@ohos.accessibility.GesturePath";
let gesturePath = new GesturePath(100);
try {
    for (let i = 0; i < 10; i++) {
        let gesturePoint = new GesturePoint(100, i * 200);
        gesturePath.points.push(gesturePoint);
    }
    axContext.injectGesture(gesturePath).then(() => {
        console.info('inject gesture success');
    }).catch((err) => {
        console.error('failed to inject gesture, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to inject gesture, because ' + JSON.stringify(exception));
}
```
## AccessibilityExtensionContext.injectGesture

injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void

注入手势，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| gesturePath | [GesturePath](js-apis-accessibility-GesturePath.md#gesturepath) | 是    | 表示手势的路径信息。     |
| callback    | AsyncCallback&lt;void&gt;                  | 是    | 回调函数，表示注入手势执行结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300003 | Do not have accessibility right for this operation. |

**示例：**

```ts
import GesturePath from "@ohos.accessibility.GesturePath";
let gesturePath = new GesturePath(100);
try {
    for (let i = 0; i < 10; i++) {
        let gesturePoint = new GesturePoint(100, i * 200);
        gesturePath.points.push(gesturePoint);
    }
    axContext.injectGesture(gesturePath, (err, data) => {
        if (err) {
            console.error('failed to inject gesture, because ' + JSON.stringify(err));
            return;
        }
        console.info('inject gesture success');
    });
} catch (exception) {
    console.error('failed to inject gesture, because ' + JSON.stringify(exception));
}
```
## AccessibilityElement<sup>9+</sup>

无障碍节点元素, 在调用AccessibilityElement的方法前，需要先通过[AccessibilityExtensionContext.getFocusElement()](#accessibilityextensioncontextgetfocuselement)或者[AccessibilityExtensionContext.getWindowRootElement()](#accessibilityextensioncontextgetwindowrootelement)获取AccessibilityElement实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.BarrierFree.Accessibility.Core

## attributeNames

attributeNames\<T extends keyof ElementAttributeValues>(): Promise\<Array\<T>>;

获取节点元素的所有属性名称，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;Array&lt;T&gt;&gt; | Promise对象，返回节点元素的所有属性名称。 |

**示例：**

```ts
let rootElement;
let attributeNames;
rootElement.attributeNames().then((data) => {
    console.log('get attribute names success');
    attributeNames = data;
}).catch((err) => {
    console.log('failed to get attribute names, because '  + JSON.stringify(err));
});
```
## attributeNames

attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void;

获取节点元素的所有属性名称，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback    | AsyncCallback&lt;Array&lt;T&gt;&gt;                  | 是    | 回调函数，返回节点元素的所有属性名称。 |

**示例：**

```ts
let rootElement;
let attributeNames;
rootElement.attributeNames((err, data) => {
    if (err) {
        console.error('failed to get attribute names, because ' + JSON.stringify(err));
        return;
    }
    attributeNames = data;
    console.info('get attribute names success');
});
```
## AccessibilityElement.attributeValue

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;

根据属性名称获取属性值，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| attributeName | T | 是    | 表示属性的名称。     |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;ElementAttributeValues[T]&gt; | Promise对象，返回根据节点属性名称获取的属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300004 | This property does not exist. |

**示例：**

```ts
let attributeName = 'name';
try {
    rootElement.attributeValue(attributeName).then((data) => {
        console.log('get attribute value by name success');
        attribtueValue = data;
    }).catch((err) => {
        console.log('failed to get attribute value, because '  + JSON.stringify(err));
    });
} catch (exception) {
    console.log('failed to get attribute value, because ' + JSON.stringify(exception));
}
```
## AccessibilityElement.attributeValue

attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, 
    callback: AsyncCallback\<ElementAttributeValues[T]>): void;

根据属性名称获取属性值，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| attributeName | T | 是    | 表示属性的名称。     |
| callback    | AsyncCallback&lt;ElementAttributeValues[T]&gt;   | 是    | 回调函数，返回根据节点属性名称获取的属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300004 | This property does not exist. |

**示例：**

```ts
let rootElement;
let attributeValue;
let attributeName = 'name';
try {
    rootElement.attributeValue(attributeName, (err, data) => {
        if (err) {
            console.error('failed to get attribute value, because ' + JSON.stringify(err));
            return;
        }
        attributeValue = data;
        console.info('get attribute value success');
    });
} catch (exception) {
    console.log('failed to get attribute value, because ' + JSON.stringify(exception));
}
```
## actionNames

actionNames(): Promise\<Array\<string>>;

获取节点元素支持的所有操作名称，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回节点元素支持的所有操作名称。 |

**示例：**

```ts
let rootElement;
let actionNames;
rootElement.actionNames().then((data) => {
    console.log('get action names success');
    actionNames = data;
}).catch((err) => {
    console.log('failed to get action names because '  + JSON.stringify(err));
});
```
## actionNames

actionNames(callback: AsyncCallback\<Array\<string>>): void;

获取节点元素支持的所有操作名称，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback    | AsyncCallback&lt;Array&lt;string&gt;&gt;   | 是    | 回调函数，返回节点元素支持的所有操作名称。 |

**示例：**

```ts
let rootElement;
let actionNames;
rootElement.actionNames((err, data) => {
    if (err) {
        console.error('failed to get action names, because ' + JSON.stringify(err));
        return;
    }
    actionNames = data;
    console.info('get action names success');
});
```
## performAction

performAction(actionName: string, parameters?: object): Promise\<void>;

根据操作名称执行某个操作，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | 是    | 表示属性的名称。     |
| parameters | object | 否    | 表示执行操作时所需要的参数。     |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300005 | This action is not supported. |

**示例：**

```ts
let rootElement;
try {
    rootElement.performAction('action').then((data) => {
        console.info('perform action success');
    }).catch((err) => {
        console.log('failed to perform action, because '  + JSON.stringify(err));
    });
} catch (exception) {
    console.log('failed to perform action, because ' + JSON.stringify(exception));
}
```
## performAction

performAction(actionName: string, callback: AsyncCallback\<void>): void;

根据操作名称执行某个操作，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | 是    | 表示属性的名称。     |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，表示执行指定操作的回调。|

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300005 | This action is not supported. |

**示例：**

```ts
let rootElement;
try {
    rootElement.performAction('action', (err, data) => {
        if (err) {
            console.error('failed to perform action, because ' + JSON.stringify(err));
            return;
        }
        console.info('perform action success');
    });
} catch (exception) {
    console.log('failed to perform action, because ' + JSON.stringify(exception));
}
```
## performAction

performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void;

根据操作名称执行某个操作，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| actionName | string | 是    | 表示属性的名称。     |
| parameters | object | 是    | 表示执行操作时所需要的参数。     |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，表示执行指定操作的回调。|

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300005 | This action is not supported. |

**示例：**

```ts
let rootElement;
let actionName = 'action';
let parameters = {
    'setText': 'test text'
};
try {
    rootElement.performAction(actionName, parameters, (err, data) => {
        if (err) {
            console.error('failed to perform action, because ' + JSON.stringify(err));
            return;
        }
        console.info('perform action success');
    });
} catch (exception) {
    console.log('failed to perform action, because ' + JSON.stringify(exception));
}
```
## findElement('content')

findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;

根据节点内容查询所有节点元素，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'content', 表示查找的类型为节点元素内容。     |
| condition | string | 是    | 表示查找的条件。     |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise对象，返回满足指定查询关键字的所有节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'content';
let condition = 'keyword';
let elements;
try {
    rootElement.findElement(type, condition).then((data) => {
        elements = data;
        console.log('find element success');
    }).catch((err) => {
        console.log('failed to find element, because '  + JSON.stringify(err));
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
## findElement('content')

findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void;

根据节点内容查询所有节点元素。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'content',表示查找的类型为节点元素内容。     |
| condition | string | 是    | 表示查找的条件。     |
| callback | AsyncCallback&lt;Array&lt;AccessibilityElement&gt;&gt; | 是    | 回调函数，返回满足指定查询关键字的所有节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'content';
let condition = 'keyword';
let elements;
try {
    rootElement.findElement(type, condition, (err, data) => {
        if (err) {
            console.error('failed to find element, because ' + JSON.stringify(err));
            return;
        }
        elements = data;
        console.info('find element success');
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
## findElement('focusType')

findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;

根据焦点元素类型查询节点元素，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'focusType', 表示查询的类型为节点的焦点元素类型。     |
| condition | [FocusType](#focustype) | 是    | 表示查询焦点元素的类型。     |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;AccessibilityElement&gt; | Promise对象，返回满足指定查询焦点元素类型的节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'focusType';
let condition = 'normal';
let element;
try {
    rootElement.findElement(type, condition).then((data) => {
        element = data;
        console.log('find element success');
    }).catch((err) => {
        console.log('failed to find element, because '  + JSON.stringify(err));
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
## findElement('focusType')

findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void;

根据焦点元素类型查询节点元素，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'focusType', 表示查询的类型为节点的焦点元素类型。     |
| condition | [FocusType](#focustype) | 是    | 表示查询焦点元素的类型。     |
| callback | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回满足指定查询焦点元素类型的节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'focusType';
let condition = 'normal';
let element;
try {
    rootElement.findElement(type, condition, (err, data) => {
        if (err) {
            console.error('failed to find element, because ' + JSON.stringify(err));
            return;
        }
        element = data;
        console.info('find element success');
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
## findElement('focusDirection')

findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;

根据下一焦点元素方向查询节点元素，使用Promise异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'focusDirection', 表示查询的类型为节点的下一焦点元素方向。     |
| condition | [FocusDirection](#focusdirection) | 是    | 表示查询下一焦点元素的方向。     |

**返回值：**

| 类型                                       | 说明                       |
| ---------------------------------------- | ------------------------ |
| Promise&lt;AccessibilityElement&gt; | Promise对象，返回满足指定查询下一焦点元素方向的节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'focusDirection';
let condition = 'up';
let element;
try {
    rootElement.findElement(type, condition).then((data) => {
        element = data;
        console.log('find element success');
    }).catch((err) => {
        console.log('failed to find element, because '  + JSON.stringify(err));
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
## findElement('focusDirection')

findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void;

根据下一焦点元素方向查询所有节点元素，使用callback异步回调。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名         | 类型                                     | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定为'focusDirection', 表示查询的类型为节点的下一焦点元素方向。     |
| condition | [FocusDirection](#focusdirection) | 是    | 表示下一查询焦点元素的方向。     |
| callback | AsyncCallback&lt;AccessibilityElement&gt; | 是    | 回调函数，返回满足指定查询下一焦点元素方向的节点元素。 |

**示例：**

```ts
let rootElement;
let type = 'focusDirection';
let condition = 'up';
let elements;
try {
    rootElement.findElement(type, condition, (err, data) => {
        if (err) {
            console.error('failed to find element, because ' + JSON.stringify(err));
            return;
        }
        elements = data;
        console.info('find element success');
    });
} catch (exception) {
    console.log('failed to find element, because ' + JSON.stringify(exception));
}
```
