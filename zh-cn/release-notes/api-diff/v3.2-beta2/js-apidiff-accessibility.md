# 无障碍子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，无障碍子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| AccessibilityExtensionContext | Rect | height: number; | 新增 |
| AccessibilityExtensionContext | Rect | width: number; | 新增 |
| AccessibilityExtensionContext | Rect | top: number; | 新增 |
| AccessibilityExtensionContext | Rect | left: number; | 新增 |
| AccessibilityExtensionContext | AccessibilityElement | findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;<br>findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void<br>findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;<br>findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void<br>findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;<br>findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void | 新增 |
| AccessibilityExtensionContext | AccessibilityElement | performAction(actionName: string, parameters?: object): Promise\<boolean>;<br>performAction(actionName: string, callback: AsyncCallback\<boolean>): void;<br>performAction(actionName: string, parameters: object, callback: AsyncCallback\<boolean>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityElement | actionNames(): Promise\<Array\<string>>;<br>actionNames(callback: AsyncCallback\<Array\<string>>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityElement | "attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;<br>attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, callback: AsyncCallback\<ElementAttributeValues[T]>): void;" | 新增 |
| AccessibilityExtensionContext | AccessibilityElement | attributeNames\<T extends keyof ElementAttributeValues>(): Promise\<Array\<T>>;<br>attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | gestureInject(gesturePath: GesturePath, listener: Callback\<boolean>): Promise\<boolean>;<br>gestureInject(gesturePath: GesturePath, listener: Callback\<boolean>, callback: AsyncCallback\<boolean>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;<br>getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;<br>getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;<br>getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;<br>getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;<br>getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;<br>getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | setTargetBundleName(targetNames: Array\<string>): Promise\<boolean>;<br>setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<boolean>): boolean; | 新增 |
| AccessibilityExtensionContext | AccessibilityExtensionContext | setEventTypeFilter(type: Array\<accessibility.EventType>): Promise\<boolean>;<br>setEventTypeFilter(type: Array\<accessibility.EventType>, callback: AsyncCallback\<boolean>): boolean; | 新增 |
| ohos.accessibility | AccessibilityAbilityInfo | readonly targetBundleNames: Array\<string>; | 新增 |
| ohos.application.AccessibilityExtensionAbility | GesturePoint | positionY: number; | 新增 |
| ohos.application.AccessibilityExtensionAbility | GesturePoint | positionX: number; | 新增 |
| ohos.application.AccessibilityExtensionAbility | GesturePath | durationTime: number; | 新增 |
| ohos.application.AccessibilityExtensionAbility | GesturePath | points: Array\<GesturePoint>; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | timeStamp?: number; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | target?: AccessibilityElement; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | eventType: accessibility.EventType \| accessibility.WindowUpdateType \| TouchGuideType \| GestureType \| PageUpdateType; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onKeyEvent(keyEvent: inputEventClient.KeyEvent): boolean; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onAccessibilityEvent(event: AccessibilityEvent): void; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onDisconnect(): void; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onConnect(): void; | 新增 |
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | context: AccessibilityExtensionContext; | 新增 |