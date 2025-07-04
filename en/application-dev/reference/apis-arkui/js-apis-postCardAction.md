# postCardAction

Provides information for interaction between the widget and widget provider. Currently, router, message, and call events are supported. This API can only be called within the widget.

> **NOTE** 
>
> This API is supported since API version 9.

## postCardAction

postCardAction(component: Object, action: Object): void

Performs internal interactions within a function and processes operations related to the **component** and **action** objects. This API does not return any value.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**


| **Name** | **Type** | **Mandatory** | **Description** |
| -------- | -------- | -------- | -------- |
| component | Object | Yes | Instance of the current custom component. Generally, **this** is passed in. |
| action | Object | Yes | Action description. For details, see the following table. |


**Description of the action parameter**


| **Name** | **Type** |  **Mandatory** | **Description** |
| -------- | -------- | -------- | -------- |
| action | string | Yes|Action type.<br>- **"router"**: redirection to the specified UIAbility of the widget provider. This type of action can be triggered only in a click event.<br>- **"message"**: custom message. If this type of action is triggered, the [onFormEvent()](../apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent) lifecycle callback of the provider FormExtensionAbility is called.<br>- **"call"**: launch of the widget provider in the background. If this type of action is triggered, the specified UIAbility (whose [launch type](../../application-models/uiability-launch-type.md) must be singleton) of the widget provider is started in the background, but not displayed in the foreground. This action type requires that the widget provider should have the [ohos.permission.KEEP_BACKGROUND_RUNNING](../../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running) permission.|
| bundleName | string | No | Name of the target bundle when **action** is **"router"** or **"call"**. |
| moduleName | string | No | Name of the target module when **action** is **"router"** or **"call"**. |
| abilityName | string | No | Name of the target UIAbility when **action** is **"router"** or **"call"**. |
| uri<sup>11+</sup> | string   | No  | URI of the target UIAbility when **action** is **"router"**. If both **uri** and **abilityName** are set, **abilityName** takes precedence. |
| params | Object | No | Additional parameters carried in the current action. The value is a key-value pair in JSON format. |

>**NOTE**
>
>When **action** is **"call"**, a string value of **'method'** must be passed to **params** to trigger the corresponding method in the UIAbility.

**Example** 

<!--code_no_check-->

```ts
Button('Redirect')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'router',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        message: 'testForRouter' // Customize the message to send.
      }
    });
  })

Button('Start in Background')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'call',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        method: 'fun', // Set the name of the method to call. It is mandatory.
        message: 'testForCall' // Customize the message to send.
      }
    });
  })

Button('Redirect URI')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'router',
      uri: 'example://uri.ohos.com/link_page',
      params: {
        message: 'router msg for dynamic uri deeplink' // Customize the message to send.
      }
    });
  })

```

The following is an example of **uris** configuration in the [module.json5](../../quick-start/module-configuration-file.md#skills) file of the target application:

```json
"abilities": [
  {
    "skills": [
      {
        "uris": [
          {
            "scheme": "example",
            "host": "uri.ohos.com",
            "path": "link_page"
          },
        ]
      }
    ],
  }
]
```
