# Accessing the Security & Privacy Framework

The Security & Privacy framework allows access via a UIAbility or an ExtensionAbility.

In the Security & Privacy Center, the accessed applications are displayed by **bundleName** in alphabetical order.

The corresponding **action** and **metadata** fields need to be configured in the **module.json5** file of the application module for the Security & Privacy Center menu access framework to scan and parse.

This topic describes how to implement the access to the Security & Privacy framework.

## Adding a Metadata Configuration File

Add a metadata configuration file (.json) containing the following parameters for the service.

| Key (Attribute Name)| Value                                                     | Mandatory| Description                                             |
| ----------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------- |
| displayedMode     | - **list**: indicates the list view.<br>- **card**: indicates the widget view, which is not supported currently.| Yes      | Currently, only the list view is available no matter whether you set this parameter to **list** or **card**.|
| mainTitleResource | Name of the main title string displayed on the entry menu.                           | Yes      | -                                                 |
| dstAbilityMode    | - **0**: A UIAbility is to be started.<br>- **1**: A UIExtensionAbility is to be started. | Yes      | -                                                 |
| dstAbilityName    | Name of the target ability to start.<br>- If **dstAbilityMode** is **0**, a UIAbility will be started.<br>- if **dstAbilityMode** is **1**, the ability inherits from a UIExtensionAbility and the caller loads its own page in this ability. | Yes      | -                                                 |
| dstBundleName     | Bundle name of the application.                                        | Yes      | -                                                 |
| displayUserConfig | - **ONLY_PRIMARY_USER**: display the content only to the primary user.<br>- **ONLY_SUB_USER**: display the content only to sub-users.| No      | If this parameter is left blank, the content is displayed to all users.                 |

For example, create a **security_privacy.json** file in **resource/rawfile/** directory of the module. You can customize the file name.

The following shows the configuration of the **security_privacy.json** file.

```json
{
  "displayedMode": "list",
  "mainTitleResource": "$string:main_title",
  "dstAbilityMode": 0,
  "dstAbilityName": "EntryAbility",
  "dstBundleName": "com.example.test"
}
```

## Modifying the Application Configuration File

The **module.json5** file of each module contains the configuration of the UIAbility and ExtensionAbility components of the module and the permissions required for application running. To access the Security & Privacy framework, you need to configure the following fields in **module.json5**.

### Setting actions

In the **module.json5** file, set the **actions** field under **skills** to **action.access.privacy.center**.

```typescript
"skills": [
  {
    "actions": [
      "action.access.privacy.center"
    ]
  }
]
```

### Setting Metadata

In the **module.json5** file, add an entry with **name** and **value** under **metadata**, and set **name** to **metadata.access.privacy.center** and **value** to the metadata configuration file name.

The metadata configuration file is the **resource/rawfile/*xxx*.json** file (**security_privacy.json** in this example) added above.

> **NOTE**
>
> Set **actions** and **metadata** based on the **dstAbilityMode** value set in the metadata configuration file.
>
> - If **dstAbilityMode** is **0** (UIAbility), configure **metadata** under **abilities**.
>
> - If **dstAbilityMode** is **1** (UIExtensionAbility), configure **metadata** under **extensionAbilities**. When configuring **extensionAbilities**, set **type** to **sys/commonUI**.
>

The following example provides only the settings for accessing the Security & Privacy framework. You need to set the other fields in the **module.json5** file to match your case.

```typescript
// Set this field if dstAbilityMode is 0 (UIAbility).
"abilities": [
  {
    "skills": [
      {
        "actions": [
          "action.access.privacy.center"
        ]
      }
    ],
    "metadata": [
      {
        "name": 'metadata.access.privacy.center',
        "value": 'security_privacy.json'
      }
    ]
  }
]
```

```typescript
// Set this field if dstAbilityMode is 1 (UIExtensionAbility).
"extensionAbilities": [
      {
        "type": "sys/commonUI",
        "skills": [
          {
            "actions": [
              "action.access.privacy.center"
            ]
          }
        ],
        "metadata": [
          {
            "name": 'metadata.access.privacy.center',
            "value": 'security_privacy.json'
          }
        ]
      }
    ]
```

### Requesting Permissions

The caller must have the [ohos.permission.ACCESS_SECURITY_PRIVACY_CENTER](../AccessToken/permissions-for-system-apps.md#ohospermissionaccess_security_privacy_center) permission.

For details about how to request the permission, see [Workflow for Requesting Permissions](../AccessToken/determine-application-mode.md).

## Accessing the Security & Privacy Framework via a UIAbility

To access the Security & Privacy framework via a UIAbility, use the default access mode generated.

Example:

```typescript
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
}
```

## Accessing the Security & Privacy Framework via an ExtensionAbility

To access the Security & Privacy Framework via an ExtensionAbility, the Ability page needs to inherit from the ExtensionAbility. You need to modify the configuration and create a session to start the main page of the application.

Example:

```typescript
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import ExtensionAbility from '@ohos.app.ability.ExtensionAbility';
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';

export default class EntryAbility extends ExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onSessionCreate');
    let param: Record<string, Object> = {
      'session': session
    }
    let storage: LocalStorage = new LocalStorage(param)
    session.loadContent('pages/Index', storage)
  }
}
```

## Exiting the Security & Privacy Framework (UIAbility)

If the caller (which accessed the Security & Privacy Framework via a UIAbility) needs to exit actively, for example, there is a return button on the page, call **router.back()** or **terminateSelf()** to destroy the page.

Example:

```typescript
import router from '@ohos.router';

@Entry()
@Component
struct Index {
 
  build() {
    Row() {
      Column() {
        Button("click to back")
          .onClick(() => {
            router.back()
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Exiting the Security & Privacy Framework (ExtensionAbility)

If the caller (which accessed the Security & Privacy Framework via a UIExtensionAbility) needs to exit actively, for example, there is a return button on the page, call **sendData** of UIExtensionContentSession to send {"action": "exit"}. Upon receiving the data, the receiver exits the page.

Example:

```typescript
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'

let storage = LocalStorage.getShared()

@Entry(storage)
@Component
struct Index {
  private session: UIExtensionContentSession = storage.get<UIExtensionContentSession>('session') as UIExtensionContentSession
  build() {
    Row() {
      Column() {
        Button("click to back")
          .onClick(() => {
            this.session.sendData({ 'action': "exit" })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
