# Accessibility Subsystem Changelog

## cl.accessibility.1 APIs Related to the Accessibility Extension Service Deprecated

**Access Level**

Public API

**Reason for Change**

To improve system security.

**Change Impact**

1. This change is a non-compatible change.

2. The extended service API of the Accessibility module is deprecated.

3. In **Settings** > **Accessibility**, the features of querying and managing installed services are no longer provided.

**Change Since**

OpenHarmony SDK 5.0.0.35

**Key API/Component Changes**

1. The following APIs are deprecated.

    | Bundle Name        | Method Declaration                       |Start API Level|
    | ----------- | ------------------------- |------------------------- |
    | AccessibilityExtensionContext | setTargetBundleName(targetNames: Array\<string>, callback: AsyncCallback\<void>): void; |9   |
    | AccessibilityExtensionContext | setTargetBundleName(targetNames: Array\<string>): Promise\<void>; |9   |
    | AccessibilityExtensionContext | getFocusElement(isAccessibilityFocus: boolean, callback: AsyncCallback\<AccessibilityElement>): void;  |9   |
    | AccessibilityExtensionContext | getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;  |9   |
    | AccessibilityExtensionContext | getFocusElement(callback: AsyncCallback\<AccessibilityElement>): void;  |9   |
    | AccessibilityExtensionContext | getWindowRootElement(windowId: number, callback: AsyncCallback\<AccessibilityElement>): void; |9   |
    | AccessibilityExtensionContext | getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>; |9   |
    | AccessibilityExtensionContext | getWindowRootElement(callback: AsyncCallback\<AccessibilityElement>): void; |9   |
    | AccessibilityExtensionContext | getWindows(displayId: number, callback: AsyncCallback<Array\<AccessibilityElement>>): void; |9   |
    | AccessibilityExtensionContext |  getWindows(displayId?: number): Promise<Array\<AccessibilityElement>>; |9   |
    | AccessibilityExtensionContext | getWindows(callback: AsyncCallback<Array\<AccessibilityElement>>): void; |9   |
    | AccessibilityExtensionContext |  injectGestureSync(gesturePath: GesturePath): void; |10   |
    | AccessibilityExtensionContext | attributeNames\<T extends keyof ElementAttributeValues>(callback: AsyncCallback<Array\<T>>): void; |9   |
    | AccessibilityExtensionContext | attributeNames\<T extends keyof ElementAttributeValues>(): Promise<Array\<T>>; |9   |
    | AccessibilityExtensionContext |  attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T, callback: AsyncCallback<ElementAttributeValues[T]>): void; |9   |
    | AccessibilityExtensionContext | attributeValue\<T extends keyof ElementAttributeValues>(attributeName: T): Promise<ElementAttributeValues[T]>; |9   |
    | AccessibilityExtensionContext |  actionNames(callback: AsyncCallback<Array\<string>>): void; |9   |
    | AccessibilityExtensionContext |  actionNames(): Promise<Array\<string>>; |9   |
    | AccessibilityExtensionContext | performAction(actionName: string, parameters: object, callback: AsyncCallback\<void>): void; |9   |
    | AccessibilityExtensionContext |  performAction(actionName: string, parameters?: object): Promise\<void>; |9   |
    | AccessibilityExtensionContext |  performAction(actionName: string, callback: AsyncCallback\<void>): void; |9   |
    | AccessibilityExtensionContext | findElement(type: 'content', condition: string, callback: AsyncCallback<Array\<AccessibilityElement>>): void; |9   |
    | AccessibilityExtensionContext | findElement(type: 'content', condition: string): Promise<Array\<AccessibilityElement>>; |9   |
    | AccessibilityExtensionContext | findElement(type: 'focusType', condition: FocusType, callback: AsyncCallback\<AccessibilityElement>): void; |9   |
    | AccessibilityExtensionContext | findElement(type: 'focusType', condition: FocusType): Promise\<AccessibilityElement>; |9   |
    | AccessibilityExtensionContext | findElement(type: 'focusDirection', condition: FocusDirection, callback: AsyncCallback\<AccessibilityElement>): void; |9   |
    | AccessibilityExtensionContext |  findElement(type: 'focusDirection', condition: FocusDirection): Promise\<AccessibilityElement>; |9   |
    | ohos.accessibility | function on(type: 'accessibilityStateChange', callback: Callback\<boolean>): void; |7   |
    | ohos.accessibility | function on(type: 'touchGuideStateChange', callback: Callback\<boolean>): void; |7   |
    | ohos.accessibility | function off(type: 'accessibilityStateChange', callback?: Callback\<boolean>): void; |7   |
    | ohos.accessibility | function off(type: 'touchGuideStateChange', callback?: Callback\<boolean>): void; |7   |
    | ohos.accessibility |   function getCaptionsManager(): CaptionsManager; |8   |
    | ohos.application.AccessibilityExtensionAbility |   onConnect(): void; |9   |
    | ohos.application.AccessibilityExtensionAbility |   onDisconnect(): void; |9   |
    | ohos.application.AccessibilityExtensionAbility |   onAccessibilityEvent(event: AccessibilityEvent): void; |9   |
    | ohos.application.AccessibilityExtensionAbility |   onKeyEvent(keyEvent: KeyEvent): boolean; |9   |
    | ohos.accessibility.GesturePath |   constructor(durationTime: number); |9   |
    | ohos.accessibility.GesturePoint |  constructor(positionX: number, positionY: number); |9   |


2. The following APIs are deleted.

    | Bundle Name        | Method Declaration                       |Start API Level|
    | ----------- | ------------------------- |------------------------- |
    | AccessibilityExtensionContext | getCursorPosition(callback: AsyncCallback\<number>): void;  |12   |
    | AccessibilityExtensionContext | getCursorPosition(): Promise\<number>;  |12   |
    | AccessibilityExtensionContext | findElement(type: 'textType', condition: string): Promise<Array\<AccessibilityElement>>;  |12   |
    | AccessibilityExtensionContext | findElement(type: 'elementId', condition: number): Promise\<AccessibilityElement>;  |12   |


3. In **Settings** > **Accessibility**, the features of querying and managing installed services are no longer provided.

**Adaptation Guide**

No adaptation is required.
