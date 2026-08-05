# EnterpriseAdminExtensionContext

<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2d9be1fcb1ab0f8ba01422df9fdd5412cd8884b7 translatedAt=2026-07-23T07:09:36.994Z pushedAt=2026-07-23T07:43:18.505Z -->

**EnterpriseAdminExtensionContext** is the context of [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md) and inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

When an **EnterpriseAdminExtensionAbility** component is instantiated, the system automatically creates the corresponding **EnterpriseAdminExtensionContext**. You can use this **EnterpriseAdminExtensionContext** to obtain the sandbox path of the app and start other components. This context can only be used within the current **EnterpriseAdminExtensionAbility** and cannot be transferred to other components.

> **NOTE**
>
> The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are open only to the device administrator application, and the device administrator application must be activated before the APIs are called. For details, see [MDM Kit Development Guide](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { common } from '@kit.MDMKit';
```

## EnterpriseAdminExtensionContext

Context of the [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md) component. It inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

### startAbilityByAdmin

startAbilityByAdmin(admin: Want, want: Want): Promise\<void>

Starts another component directly in the [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md) component (without a dialog box reminder on the page). Currently, [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) and [AppServiceExtensionAbility](../apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) are supported. After the API is called successfully, the target component is started and enters the running state. This API uses a promise to return the result.

> **NOTE**
>
> - Only third-party app components are supported; system app components are not supported.
> 
> - The component to start must be visible to external parties, that is, the **exported** field in the **module.json5** file must be set to **true**.
> 
> - [Implicit Want launch](../../application-models/ability-terminology.md#implicit-want-launch) is not supported.
> 
> - If the **UIAbility** to start has permission protection, you need to apply for the corresponding permission.

**Required permissions**: ohos.permission.ENTERPRISE_START_ABILITIES

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Mandatory | Enterprise device management extension component. `Want` must contain `abilityName` of the enterprise device management extension ability and `bundleName` of the application where it resides. After being set, the system uses this parameter to verify the device administrator identity and permissions of the caller. |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Mandatory | Required information for starting a component. `Want` must contain `abilityName` of the enterprise device management extension ability and `bundleName` of the application where it resides. After being set, the system locates the target application based on `bundleName`, and locates and starts the target component based on `abilityName`. |

**Return values**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. If the component fails to be started, an error object is thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200014  | Failed to start the ability. |
| 9200015  | The ability does not exist. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**
The information about the component to start must be configured in the `module.json5` file. The `permissions` parameter is optional. Set it based on the actual situation or leave it empty.

```json5
"abilities": [
  {
    "name": "MainAbility",
    "srcEntry": "./ets/MainAbility/MainAbility.ts",
    "description": "$string:MainAbility_desc",
    "icon": "$media:icon",
    "label": "$string:MainAbility_label",
    "startWindowIcon": "$media:icon",
    "startWindowBackground": "$color:white",
    "exported": true,
    "permissions": [
      "ohos.permission.START_UI_ABILITY"
    ]
  }
]
```

The caller app must request the corresponding permissions in the `module.json5` file. When starting a component in another application, the caller application must obtain the permissions required by the component.

```json5
"requestPermissions": [
  {
    "name": "ohos.permission.START_UI_ABILITY"
  },
  {
    "name": "ohos.permission.ENTERPRISE_START_ABILITIES"
  }
]
```

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
import { preferences } from '@kit.ArkData';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

/**
 * EnterpriseAdminExtensionAbility
 */
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
    // Replace with the actual value.
    let admin: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EnterpriseAdminAbility',
    };
    // Replace with the actual value.
    let want: Want = {
      bundleName: 'com.example.myotherapplication',
      abilityName: 'MainAbility'
    };
    this.context.startAbilityByAdmin(admin, want).catch((err: BusinessError) => {
      console.error(`Failed to start an ability. Code: ${err.code}, message: ${err.message}`);
    });
    
    // Obtain the application file path through context.
    let preferencesDir = this.context.preferencesDir;
    console.info(`preferencesDir: ` + preferencesDir);
    
    // Obtain the preferences data through context.
    let options: preferences.Options = {
      // Replace with the actual value.
      name: "key",
    };
    try {
      let preference = preferences.getPreferencesSync(this.context, options);
      // Replace with the actual value.
      preference.putSync("key", "value");
      preference.flushSync();
    
      // Replace with the actual value.
      let value: string = preference.getSync('key', 'default') as string;
      console.info(`get preferences value: ${value}`);
    } catch (error) {
      console.error('get preference fail');
    }
  }
}
```