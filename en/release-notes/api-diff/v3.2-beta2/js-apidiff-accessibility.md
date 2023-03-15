# JS API Changes of the Accessibility Subsystem

The table below lists the APIs changes of the accessibility subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| AccessibilityExtensionContext | Rect | height: number; | Added|
| AccessibilityExtensionContext | Rect | width: number; | Added|
| AccessibilityExtensionContext | Rect | top: number; | Added|
| AccessibilityExtensionContext | Rect | left: number; | Added|
| AccessibilityExtensionContext | AccessibilityElement | findElement(type: 'content', condition: string): Promise\<Array\<AccessibilityElement>>;<br>findElement(type: 'content', condition: string, callback: AsyncCallback\<Array\<AccessibilityElement>>): void<br>findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>;<br>findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void<br>findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>;<br>findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void | Added|
| AccessibilityExtensionContext | AccessibilityElement | performAction(actionName: string, parameters?: object): Promise\<boolean>;<br>performAction(actionName: string, callback: AsyncCallback\<boolean>): void;<br>performAction(actionName: string, parameters: object, callback: AsyncCallback\<boolean>): void; | Added|
| AccessibilityExtensionContext | AccessibilityElement | actionNames(): Promise\<Array\<string>>;<br>actionNames(callback: AsyncCallback\<Array\<string>>): void; | Added|
| AccessibilityExtensionContext | AccessibilityElement | "attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise\<ElementAttributeValues[T]>;<br>attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, callback: AsyncCallback\<ElementAttributeValues[T]>): void;" | Added|
| AccessibilityExtensionContext | AccessibilityElement | attributeNames\<T extends keyof ElementAttributeValues>(): Promise\<Array\<T>>;<br>attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback\<Array\<T>>): void; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | gestureInject(gesturePath: GesturePath, listener: Callback\<boolean>): Promise\<boolean>;<br>gestureInject(gesturePath: GesturePath, listener: Callback\<boolean>, callback: AsyncCallback\<boolean>): void; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | getWindows(displayId?: number): Promise\<Array\<AccessibilityElement>>;<br>getWindows(callback: AsyncCallback\<Array\<AccessibilityElement>>): void;<br>getWindows(displayId: number, callback: AsyncCallback\<Array\<AccessibilityElement>>): void; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;<br>getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void;<br>getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;<br>getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;<br>getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | setTargetBundleName(targetNames: Array\<string>): Promise\<boolean>;<br>setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<boolean>): boolean; | Added|
| AccessibilityExtensionContext | AccessibilityExtensionContext | setEventTypeFilter(type: Array\<accessibility.EventType>): Promise\<boolean>;<br>setEventTypeFilter(type: Array\<accessibility.EventType>, callback: AsyncCallback\<boolean>): boolean; | Added|
| ohos.accessibility | AccessibilityAbilityInfo | readonly targetBundleNames: Array\<string>; | Added|
| ohos.application.AccessibilityExtensionAbility | GesturePoint | positionY: number; | Added|
| ohos.application.AccessibilityExtensionAbility | GesturePoint | positionX: number; | Added|
| ohos.application.AccessibilityExtensionAbility | GesturePath | durationTime: number; | Added|
| ohos.application.AccessibilityExtensionAbility | GesturePath | points: Array\<GesturePoint>; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | timeStamp?: number; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | target?: AccessibilityElement; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityEvent | eventType: accessibility.EventType \| accessibility.WindowUpdateType \| TouchGuideType \| GestureType \| PageUpdateType; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onKeyEvent(keyEvent: inputEventClient.KeyEvent): boolean; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onAccessibilityEvent(event: AccessibilityEvent): void; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onDisconnect(): void; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | onConnect(): void; | Added|
| ohos.application.AccessibilityExtensionAbility | AccessibilityExtensionAbility | context: AccessibilityExtensionContext; | Added|
