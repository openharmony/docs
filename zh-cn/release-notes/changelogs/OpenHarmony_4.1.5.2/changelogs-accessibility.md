# 无障碍框架子系统变更说明

## cl.accessibility.1  监听器接口访问权限变更

从API11开始，监听器接口增加ohos.permission.READ_ACCESSIBILITY_CONFIG权限校验，错误码返回201，此次属于兼容性变更，开发者需要增加应用权限。

**访问级别**

系统api

**变更原因**

当前使用监听器接口时未检查辅助应用是否具有ohos.permission.READ_ACCESSIBILITY_CONFIG权限，现增加该权限校验，辅助应用无权限时，返回错误码201。

**变更影响**

此次变更为兼容性变更，涉及新增错误码，对开发者而言，应用需要增加ohos.permission.READ_ACCESSIBILITY_CONFIG权限。

**变更发生版本**

从OpenHarmony SDK 4.1.5.2 开始。

**变更的接口**

相较于之前，当辅助应用调用监听器接口时，系统增加ohos.permission.READ_ACCESSIBILITY_CONFIG权限校验，如果不具备该权限，则返回错误码201。

- 涉及接口

| 文件                            | 接口                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| @ohos.accessibility.config.d.ts | function on(type: 'enabledAccessibilityExtensionListChange', callback: Callback<void>): void; |
| @ohos.accessibility.config.d.ts | function off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback<void>): void; |
| @ohos.accessibility.config.d.ts | on(callback: Callback<T>): void;                             |
| @ohos.accessibility.config.d.ts | off(callback?: Callback<T>): void;                           |

- 变更前：

监听器接口不检查辅助应用是否具备ohos.permission.READ_ACCESSIBILITY_CONFIG权限。

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

- 变更后：

监听器接口检查辅助应用是否具备ohos.permission.READ_ACCESSIBILITY_CONFIG权限，如果不具备该权限则返回错误码201。

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


**适配指导**

本次修改仅涉及增加监听器接口访问权限，其余行为不变。
