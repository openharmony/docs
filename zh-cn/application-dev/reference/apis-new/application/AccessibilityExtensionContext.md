# AccessibilityExtensionContext    
辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AccessibilityExtensionContext    
辅助功能扩展上下文模块提供辅助功能扩展的上下文环境的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### setTargetBundleName    
设置关注的目标包名，使用Promise异步回调。  
 **调用形式：**     
    
- setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setTargetBundleName(targetNames: Array\<string>): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| targetNames | Array<string> | true | 关注的目标包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果设置关注的目标包名失败，则AsyncCallback中err有数据返回。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```null    
import { BusinessError } from '@ohos.base';  
  
let targetNames = ['com.ohos.xyz'];  
try {  
  axContext.setTargetBundleName(targetNames, (err: BusinessError<void>) => {  
    if (err) {  
      console.error(`failed to set target bundle names, because ${JSON.stringify(err)}`);  
      return;  
    }  
    console.info('set target bundle names success');  
  });  
} catch (exception) {  
  console.error(`failed to set target bundle names, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(promise):  
```ts    
let targetNames = ['com.ohos.xyz'];  
  
try {  
  axContext.setTargetBundleName(targetNames).then(() => {  
    console.info('set target bundle names success');  
  }).catch((err: object) => {  
    console.error(`failed to set target bundle names, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to set target bundle names, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### getFocusElement    
获取焦点元素, 使用Promise异步回调。  
 **调用形式：**     
    
- getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9    
- getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>    
起始版本： 9    
- getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isAccessibilityFocus | boolean | true | 获取的是否是无障碍焦点元素，默认为否。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前对应的焦点元素。 |  
| Promise<AccessibilityElement> | Promise对象，返回当前对应的焦点元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | Do not have accessibility right for this operation. |  
    
 **示例代码1：**   
示例(promise):  
```ts    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
  
let focusElement: AccessibilityElement;  
try {  
  axContext.getFocusElement().then((data: AccessibilityElement) => {  
    focusElement = data;  
    console.log('get focus element success');  
  }).catch((err: object) => {  
    console.error(`failed to get focus element, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to get focus element, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let focusElement: AccessibilityElement;  
try {  
  axContext.getFocusElement((err: BusinessError<void>, data: AccessibilityElement) => {  
    if (err) {  
      console.error(`failed to get focus element, because ${JSON.stringify(err)}`);  
      return;  
    }  
    focusElement = data;  
    console.info('get focus element success');  
  });  
} catch (exception) {  
  console.error(`failed to get focus element, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### getWindowRootElement    
获取指定窗口的根节点元素, 使用Promise异步回调。  
 **调用形式：**     
    
- getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9    
- getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>    
起始版本： 9    
- getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowId | number | true | 指定窗口的编号，未指定则从当前活跃窗口获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<AccessibilityElement> | Promise对象，返回指定窗口的根节点元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | 回调函数，返回指定窗口的根节点元素。 |  
    
 **示例代码1：**   
示例(promise):  
```null    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
  
let rootElement: AccessibilityElement;  
try {  
  axContext.getWindowRootElement().then((data: AccessibilityElement) => {  
    rootElement = data;  
    console.log('get root element of the window success');  
  }).catch((err: object) => {  
    console.error(`failed to get root element of the window, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to get root element of the window, ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```null    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let rootElement: AccessibilityElement;  
try {  
  axContext.getWindowRootElement((err: BusinessError<void>  
                                  , data: AccessibilityElement) => {  
    if (err) {  
      console.error(`failed to get root element of the window, because ${JSON.stringify(err)}`);  
      return;  
    }  
    rootElement = data;  
    console.info('get root element of the window success');  
  });  
} catch (exception) {  
  console.error(`failed to get root element of the window, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### getWindows    
获取指定屏幕中的所有窗口, 使用Promise异步回调。  
 **调用形式：**     
    
- getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void    
起始版本： 9    
- getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>    
起始版本： 9    
- getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| displayId | number | true | 指定的屏幕编号，未指定则从默认主屏幕获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定屏幕的所有窗口。 |  
| Promise<Array<AccessibilityElement>> | Promise对象，返回指定屏幕的所有窗口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | Do not have accessibility right for this operation. |  
    
 **示例代码1：**   
示例 (callback) :  
```ts    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let windows: AccessibilityElement[];  
try {  
  axContext.getWindows((err: BusinessError<void>, data: AccessibilityElement[]) => {  
    if (err) {  
      console.error(`failed to get windows, because ${JSON.stringify(err)}`);  
      return;  
    }  
    windows = data;  
    console.info('get windows success');  
  });  
} catch (exception) {  
  console.error(`failed to get windows, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例 （promise）:  
```null    
import { AccessibilityElement } from '@ohos.application.AccessibilityExtensionAbility';  
  
let windows: AccessibilityElement[];  
try {  
  axContext.getWindows().then((data: AccessibilityElement[]) => {  
    windows = data;  
    console.log('get windows success');  
  }).catch((err: object) => {  
    console.error(`failed to get windows, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to get windows, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### injectGesture<sup>(deprecated)</sup>    
注入手势，使用Promise异步回调。  
 **调用形式：**     
- injectGesture(gesturePath: GesturePath, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: AccessibilityExtensionContext/AccessibilityExtensionContext#injectGestureSync。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| gesturePath<sup>(deprecated)</sup> | GesturePath | true | 表示手势的路径信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，表示注入手势执行结果的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | Do not have accessibility right for this operation. |  
    
 **示例代码：**   
示例 （promise）:  
```ts    
import GesturePath from '@ohos.accessibility.GesturePath';  
import GesturePoint from '@ohos.accessibility.GesturePoint';  
  
let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);  
try {  
  for (let i = 0; i < 10; i++) {  
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);  
    gesturePath.points.push(gesturePoint);  
  }  
  axContext.injectGesture(gesturePath).then(() => {  
    console.info('inject gesture success');  
  }).catch((err: object) => {  
    console.error(`failed to inject gesture, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### injectGesture<sup>(deprecated)</sup>    
注入手势，使用Promise异步回调。  
 **调用形式：**     
- injectGesture(gesturePath: GesturePath): Promise\<void>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: AccessibilityExtensionContext/AccessibilityExtensionContext#injectGestureSync。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| gesturePath<sup>(deprecated)</sup> | GesturePath | true | 表示手势的路径信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | Do not have accessibility right for this operation. |  
    
 **示例代码：**   
示例 （promise）:  
  
```null    
import GesturePath from '@ohos.accessibility.GesturePath';  
import GesturePoint from '@ohos.accessibility.GesturePoint';  
  
let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);  
try {  
  for (let i = 0; i < 10; i++) {  
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);  
    gesturePath.points.push(gesturePoint);  
  }  
  axContext.injectGesture(gesturePath).then(() => {  
    console.info('inject gesture success');  
  }).catch((err: object) => {  
    console.error(`failed to inject gesture, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### injectGestureSync<sup>(10+)</sup>    
注入手势。  
 **调用形式：**     
- injectGestureSync(gesturePath: GesturePath): void  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| gesturePath | GesturePath | true | 表示手势的路径信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300003 | Do not have accessibility right for this operation. |  
    
 **示例代码：**   
```ts    
import GesturePath from '@ohos.accessibility.GesturePath';  
import GesturePoint from '@ohos.accessibility.GesturePoint';  
  
let gesturePath: GesturePath.GesturePath = new GesturePath.GesturePath(100);  
try {  
  for (let i = 0; i < 10; i++) {  
    let gesturePoint = new GesturePoint.GesturePoint(100, i * 200);  
    gesturePath.points.push(gesturePoint);  
  }  
  axContext.injectGestureSync(gesturePath);  
} catch (exception) {  
  console.error(`failed to inject gesture, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
## AccessibilityElement    
无障碍节点元素, 在调用AccessibilityElement的方法前，需要先通过[AccessibilityExtensionContext.getFocusElement()](#accessibilityextensioncontextgetfocuselement)或者[AccessibilityExtensionContext.getWindowRootElement()](#accessibilityextensioncontextgetwindowrootelement)获取AccessibilityElement实例。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### attributeNames    
获取节点元素的所有属性名称，使用Promise异步回调。  
 **调用形式：**     
    
- attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void    
起始版本： 9    
- attributeNames\<T extends keyof ElementAttributeValues>(): Promise\<Array\<T>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回节点元素的所有属性名称。 |  
| Promise<Array<T>> | Promise对象，返回节点元素的所有属性名称。 |  
    
 **示例代码1：**   
示例 (callback):  
```ts    
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let attributeNames: ElementAttributeKeys[];  
rootElement.attributeNames((err: BusinessError<void>, data: ElementAttributeKeys[]) => {  
  if (err) {  
    console.error(`failed to get attribute names, because ${JSON.stringify(err)}`);  
    return;  
  }  
  attributeNames = data;  
  console.info('get attribute names success');  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise) :  
```ts    
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';  
  
let attributeName: ElementAttributeKeys = 'bundleName';  
let attributeValue: string;  
try {  
  rootElement.attributeValue(attributeName).then((data: string) => {  
    console.log('get attribute value by name success');  
    attributeValue = data;  
  }).catch((err: object) => {  
    console.error(`failed to get attribute value, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to get attribute value, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### attributeValue    
根据属性名称获取属性值，使用callback异步回调。  
 **调用形式：**     
    
- attributeValue\<T extends keyof ElementAttributeValues>(     attributeName: T,     callback: AsyncCallback\<ElementAttributeValues[T]>   ): void    
起始版本： 9    
- attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| attributeName | T | true | 表示属性的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回根据节点属性名称获取的属性值。 |  
| Promise<ElementAttributeValues[T]> | Promise对象，返回节点元素支持的所有操作名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300004 | This property does not exist. |  
    
 **示例代码1：**   
示例 （callback）:  
```ts    
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let attributeName: ElementAttributeKeys = 'bundleName';  
let attributeValue: string;  
try {  
  rootElement.attributeValue(attributeName, (err: BusinessError<void>, data: string) => {  
    if (err) {  
      console.error(`failed to get attribute value, because ${JSON.stringify(err)}`);  
      return;  
    }  
    attributeValue = data;  
    console.info('get attribute value success');  
  });  
} catch (exception) {  
  console.error(`failed to get attribute value, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import { ElementAttributeKeys } from '@ohos.application.AccessibilityExtensionAbility';  
  
let attributeName: ElementAttributeKeys = 'bundleName';  
let attributeValue: string;  
try {  
  rootElement.attributeValue(attributeName).then((data: string) => {  
    console.log('get attribute value by name success');  
    attributeValue = data;  
  }).catch((err: object) => {  
    console.error(`failed to get attribute value, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to get attribute value, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
### actionNames    
获取节点元素支持的所有操作名称，使用Promise异步回调。  
 **调用形式：**     
    
- actionNames(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- actionNames(): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回节点元素支持的所有操作名称。 |  
| Promise<Array<string>> | Promise对象，返回节点元素支持的所有操作名称。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
let actionNames: string[];rootElement.actionNames((err: BusinessError<void>, data: string[]) => { if (err) {  console.error(`failed to get action names, because ${JSON.stringify(err)}`);  return; } actionNames = data; console.info('get action names success');})    
```    
  
    
 **示例代码2：**   
示例（promise）：  
```ts    
let actionNames: string[];rootElement.actionNames().then((data: string[]) => { console.log('get action names success'); actionNames = data;}).catch((err: object) => { console.error(`failed to get action names because ${JSON.stringify(err)}`);})    
```    
  
    
### performAction    
根据操作名称执行某个操作，使用Promise异步回调。  
 **调用形式：**     
    
- performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void    
起始版本： 9    
- performAction(actionName: string, parameters?: object): Promise\<void>    
起始版本： 9    
- performAction(actionName: string, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| actionName | string | true | 表示属性的名称，取值参考[Action](./js-apis-accessibility.md#action)。 |  
| parameters | object | true | 表示执行操作时所需要的参数；默认为空；当前版本暂不支持。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，表示执行指定操作的回调。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9300005 | This action is not supported. |  
    
 **示例代码1：**   
示例（promise）：  
```ts    
let actionName = 'action';  
try {  
  rootElement.performAction(actionName).then(() => {  
    console.info('perform action success');  
  }).catch((err: object) => {  
    console.error(`failed to perform action, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to perform action, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let actionName = 'action';  
try {  
  rootElement.performAction(actionName, (err:BusinessError) => {  
    if (err) {  
      console.error(`failed to perform action, because ${JSON.stringify(err)}`);  
      return;  
    }  
    console.info('perform action success');  
  });  
} catch (exception) {  
  console.error(`failed to perform action, because ${JSON.stringify(exception)}`);}  
    
```    
  
    
### findElement    
根据节点内容查询所有节点元素，使用Promise异步回调。  
 **调用形式：**     
    
- findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void    
起始版本： 9    
- findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>    
起始版本： 9    
- findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9    
- findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>    
起始版本： 9    
- findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void    
起始版本： 9    
- findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定为'content',表示查找的类型为节点元素内容。 |  
| condition | string | true | 表示查找的条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回满足指定查询关键字的所有节点元素。 |  
| Promise<Array<AccessibilityElement>> | Promise对象，返回满足指定查询焦点元素类型的节点元素。 |  
| Promise<AccessibilityElement> | Promise对象，返回满足指定查询下一焦点元素方向的节点元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
let condition: FocusDirection = 'up';  
let elements: AccessibilityElement;  
try {  
  rootElement.findElement('focusDirection', condition, (err: BusinessError<void>, data: AccessibilityElement) => {  
    if (err) {  
      console.error(`failed to find element, because ${JSON.stringify(err)}`);  
      return;  
    }  
    elements = data;  
    console.info('find element success');  
  });  
} catch (exception) {  
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```null    
import { FocusDirection } from '@ohos.application.AccessibilityExtensionAbility';  
  
let condition: FocusDirection = 'up';  
let element: AccessibilityElement;  
try {  
  rootElement.findElement('focusDirection', condition).then((data: AccessibilityElement) => {  
    element = data;  
    console.log('find element success');  
  }).catch((err: object) => {  
    console.error(`failed to find element, because ${JSON.stringify(err)}`);  
  });  
} catch (exception) {  
  console.error(`failed to find element, because ${JSON.stringify(exception)}`);  
}  
    
```    
  
    
## ElementAttributeValues  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### 属性    
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| 'accessibilityFocused' | boolean | false | true |  |  
| 'bundleName' | string | false | true |  |  
| 'checkable' | boolean | false | true |  |  
| 'checked' | boolean | false | true |  |  
| 'children' | Array<AccessibilityElement> | false | true |  |  
| 'clickable' | boolean | false | true |  |  
| 'componentId' | number | false | true |  |  
| 'componentType' | string | false | true |  |  
| 'contents' | Array<string> | false | true |  |  
| 'currentIndex' | number | false | true |  |  
| 'description' | string | false | true |  |  
| 'editable' | boolean | false | true |  |  
| 'endIndex' | number | false | true |  |  
| 'error' | string | false | true |  |  
| 'focusable' | boolean | false | true |  |  
| 'hintText' | string | false | true |  |  
| 'inputType' | number | false | true |  |  
| 'inspectorKey' | string | false | true |  |  
| 'isActive' | boolean | false | true |  |  
| 'isEnable' | boolean | false | true |  |  
| 'isHint' | boolean | false | true |  |  
| 'isFocused' | boolean | false | true |  |  
| 'isPassword' | boolean | false | true |  |  
| 'isVisible' | boolean | false | true |  |  
| 'itemCount' | number | false | true |  |  
| 'lastContent' | string | false | true |  |  
| 'layer' | number | false | true |  |  
| 'longClickable' | boolean | false | true |  |  
| 'pageId' | number | false | true |  |  
| 'parent' | AccessibilityElement | false | true |  |  
| 'pluralLineSupported' | boolean | false | true |  |  
| 'rect' | Rect | false | true |  |  
| 'resourceName' | string | false | true |  |  
| 'rootElement' | AccessibilityElement | false | true |  |  
| 'screenRect' | Rect | false | true |  |  
| 'scrollable' | boolean | false | true |  |  
| 'selected' | boolean | false | true |  |  
| 'startIndex' | number | false | true |  |  
| 'text' | string | false | true |  |  
| 'textLengthLimit' | number | false | true |  |  
| 'textMoveUnit' | accessibility.TextMoveUnit | false | true |  |  
| 'triggerAction' | accessibility.Action | false | true |  |  
| 'type' | WindowType | false | true |  |  
| 'valueMax' | number | false | true |  |  
| 'valueMin' | number | false | true |  |  
| 'valueNow' | number | false | true |  |  
| 'windowId' | number | false | true |  |  
    
## FocusDirection    
表示查询下一焦点元素的方向。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| up | 表示向上查询。 |  
| down | 表示向下查询。 |  
| left | 表示向左查询。 |  
| right | 表示向右查询。 |  
| forward | 表示向前查询。 |  
| backward | 表示向后查询。 |  
    
## FocusType    
表示查询焦点元素的类型。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| accessibility | 表示无障碍的焦点类型。 |  
| normal | 表示普通的焦点类型。 |  
    
## WindowType    
表示窗口的类型。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| application | 表示应用窗口类型。 |  
| system | 表示系统窗口类型。 |  
    
## Rect    
表示矩形区域。  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left | number | false | true | 矩形区域的左边界。 |  
| top | number | false | true | 矩形区域的上边界。 |  
| width | number | false | true | 矩形区域的宽度。 |  
| height | number | false | true | 矩形区域的高度。 |  
