# Accessibility Framework Subsystem Changelog

## cl.accessibility.1 Access Permission Change in the Listener APIs

Since API version 11, the **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission verification is added to the listener APIs, and error code 201 is returned for lack of permission. This is a compatible change. You need to declare the required permission for your application to pass the verification.

**Access Level**

System

**Reason for Change**

In previous versions, the accessibility application could use the listener APIs without the **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission. This is not secure and needs to be rectified.

**Change Impact**

This change is a compatible change and involves a new error code. An accessibility application must declare the **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission to pass the permission verification.

**Change Since**

OpenHarmony SDK 4.1.5.2

**Key API/Component Changes**

The **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission verification is added to the following APIs. Error code 201 is returned for lack of permission.

- Involved APIs

| File                           | API                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| @ohos.accessibility.config.d.ts | function on(type: 'enabledAccessibilityExtensionListChange', callback: Callback<void>): void; |
| @ohos.accessibility.config.d.ts | function off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback<void>): void; |
| @ohos.accessibility.config.d.ts | on(callback: Callback<T>): void;                             |
| @ohos.accessibility.config.d.ts | off(callback?: Callback<T>): void;                           |

- Before change: 

An accessibility application is not checked for its **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission when it calls a listener API.

```js
 /**
   * Register the listener that watches for changes in the enabled status of accessibility extensions.
   *
   * @param { 'enabledAccessibilityExtensionListChange' } type Indicates the type of event.
   * @param { Callback<void> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  function on(type: 'enabledAccessibilityExtensionListChange', callback: Callback<void>): void;
  
 /**
   * Unregister listener that watches for changes in the enabled status of accessibility extensions.
   *
   * @param { 'enabledAccessibilityExtensionListChange' } type Indicates the type of event.
   * @param { Callback<void> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  function off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback<void>): void;

 /**
   * Register the listener to listen for configuration changes.
   *
   * @param { Callback<T> } callback Indicates the listener.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  on(callback: Callback<T>): void;
 
 /**
   * Unregister the listener to listen for configuration changes.
   *
   * @param { Callback<T> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  off(callback?: Callback<T>): void;
```

- After change:

An accessibility application is checked for its **ohos.permission.READ_ACCESSIBILITY_CONFIG** permission when it calls a listener API. Error code 201 is returned for lack of permission.

```js
   /**
   * Register the listener that watches for changes in the enabled status of accessibility extensions.
   *
   * @permission ohos.permission.READ_ACCESSIBILITY_CONFIG
   * @param { 'enabledAccessibilityExtensionListChange' } type Indicates the type of event.
   * @param { Callback<void> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  function on(type: 'enabledAccessibilityExtensionListChange', callback: Callback<void>): void;
  
 /**
   * Unregister listener that watches for changes in the enabled status of accessibility extensions.
   *
   * @permission ohos.permission.READ_ACCESSIBILITY_CONFIG
   * @param { 'enabledAccessibilityExtensionListChange' } type Indicates the type of event.
   * @param { Callback<void> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  function off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback<void>): void;

 /**
   * Register the listener to listen for configuration changes.
   *
   * @permission ohos.permission.READ_ACCESSIBILITY_CONFIG
   * @param { Callback<T> } callback Indicates the listener.
   * @throws { BusinessError } 201 - Permission denied.
   * @throws { BusinessError } 202 - Not system App.
   * @throws { BusinessError } 401 - Input parameter error.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  on(callback: Callback<T>): void;
 
 /**
   * Unregister the listener to listen for configuration changes.
   *
   * @permission ohos.permission.READ_ACCESSIBILITY_CONFIG
   * @param { Callback<T> } callback Indicates the listener.
   * @throws { BusinessError } 202 - Not system App.
   * @syscap SystemCapability.BarrierFree.Accessibility.Core
   * @systemapi
   * @since 9
   */
  off(callback?: Callback<T>): void;
```


**Adaptation Guide**

Declare the required permission for calling a listener API.
