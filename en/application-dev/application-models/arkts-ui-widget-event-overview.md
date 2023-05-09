# Widget Event Capability Overview


The ArkTS widget provides the **postCardAction()** API for interaction between the widget internal and the provider application. Currently, this API supports the router, message, and call events and can be called only in the widget.


![WidgetPostCardAction](figures/WidgetPostCardAction.png)


Definition: postCardAction(component: Object, action: Object): void


Parameters:


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| component | Object | Yes| Instance of the current custom component. Generally, **this** is transferred.|
| action | Object | Yes| Action description. For details, see the following table.|


Description of the action parameter


| **Key** | **Value** | Description|
| -------- | -------- | -------- |
| "action" | string | Action type.<br>- **"router"**: application redirection. If this type of action is triggered, the corresponding UIAbility is displayed. Only the UIAbility of the current application can be displayed.<br>- **"message"**: custom message. If this type of action is triggered, the [onFormEvent()](../reference/apis/js-apis-app-form-formExtensionAbility.md#onformevent) lifecycle callback of the provider FormExtensionAbility is called.<br>- **"call"**: application startup in the background. If this type of action is triggered, the corresponding UIAbility is started but does not run in the foreground. The target application must have the permission to run in the background ([ohos.permission.KEEP_BACKGROUND_RUNNING](../security/permission-list.md#ohospermissionkeep_background_running)).|
| "bundleName" | string | Name of the target bundle when **action** is **"router"** or **"call"**. This parameter is optional.|
| "moduleName" | string | Name of the target module when **action** is **"router"** or **"call"**. This parameter is optional.|
| "abilityName" | string | Name of the target UIAbility when **action** is **"router"** or **"call"**. This parameter is mandatory.|
| "params" | Object | Additional parameters carried in the current action. The value is a key-value pair in JSON format.|


Sample code of the **postCardAction()** API:



```typescript
Button ('Jump')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      'action': 'router',
      'bundleName': 'com.example.myapplication',
      'abilityName': 'EntryAbility',
      'params': {
        'message': 'testForRouter' // Customize the message to be sent.
      }
    });
  })
```


The following are typical widget development scenarios that can be implemented through widget events:


- [Updating Widget Content Through FormExtensionAbility](arkts-ui-widget-event-formextensionability.md)

- [Updating Widget Content Through UIAbility](arkts-ui-widget-event-uiability.md)

- [Redirecting to a Specified Page Through the Router Event](arkts-ui-widget-event-router.md)
