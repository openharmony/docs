# Widget Event Capability Overview

The ArkTS widget provides the **postCardAction()** API for interaction between the widget internal and the widget provider. Currently, this API supports the router, message, and call events and can be called only in the widget.

![WidgetPostCardAction](figures/WidgetPostCardAction.png)

**Definition**: postCardAction(component: Object, action: Object): void

**Parameters**


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| component | Object | Yes| Instance of the current custom component. Generally, **this** is passed in.|
| action | Object | Yes| Action description. For details, see the following table.|

**Description of the action parameter**


| Key | Value | Description|
| -------- | -------- | -------- |
| "action" | string | Action type.<br>- **"router"**: redirection to the specified UIAbility of the widget provider.<br>- **"message"**: custom message. If this type of action is triggered, the [onFormEvent()](../reference/apis/js-apis-app-form-formExtensionAbility.md#onformevent) lifecycle callback of the provider FormExtensionAbility is called.<br>- **"call"**: launch of the widget provider in the background. If this type of action is triggered, the specified UIAbility (whose [launch type](uiability-launch-type.md) must be singleton) of the widget provider is started in the background, but not displayed in the foreground. This action type requires that the widget provider should have the [ohos.permission.KEEP_BACKGROUND_RUNNING](../security/permission-list.md#ohospermissionkeep_background_running) permission.|
| "bundleName" | string | Name of the target bundle when **action** is **"router"** or **"call"**. This parameter is optional.|
| "moduleName" | string | Name of the target module when **action** is **"router"** or **"call"**. This parameter is optional.|
| "abilityName" | string | Name of the target UIAbility when **action** is **"router"** or **"call"**. This parameter is mandatory.|
| "params" | Object | Additional parameters carried in the current action. The value is a key-value pair in JSON format. For the **"call"** action type, the **method** parameter (mandatory) must be set and its value type must be string.|


Sample code of the **postCardAction()** API:

```typescript
Button ('Redirect')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      'action': 'router',
      'bundleName': 'com.example.myapplication',
      'abilityName': 'EntryAbility',
      'params': {
        'message': 'testForRouter' // Customize the message to send.
      }
    });
  })

Button ('Start in Background')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      'action': 'call',
      'bundleName': 'com.example.myapplication',
      'abilityName': 'EntryAbility',
      'params': {
        'method': 'fun', // Set the name of the method to call. It is mandatory.
        'message': 'testForCall' // Customize the message to send.
      }
    });
  })
```


Read on to learn the typical widget development scenarios that can be implemented through widget events.
