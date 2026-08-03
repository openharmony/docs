# EnterpriseAdminExtensionContext（企业设备管理扩展能力上下文环境）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

EnterpriseAdminExtensionContext是[EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md)的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

每个EnterpriseAdminExtensionAbility组件实例化时，系统都会自动创建对应的EnterpriseAdminExtensionContext。开发者可以通过EnterpriseAdminExtensionContext获取应用的沙箱路径、启动其他的组件。该上下文环境只能在当前EnterpriseAdminExtensionAbility中使用，不能传递到其他组件中使用。

> **说明：**
>
> 本模块首批接口从API version 23 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { common } from '@kit.MDMKit';
```

## EnterpriseAdminExtensionContext

[EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md)的上下文，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

### startAbilityByAdmin

startAbilityByAdmin(admin: Want, want: Want): Promise\<void>

在[EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md)组件中直接启动另外一个组件（页面没有弹窗提醒），目前支持[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)，[AppServiceExtensionAbility](../apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)。调用成功后，目标组件将被启动并进入运行状态。使用Promise异步回调。

> **说明：**
>
> 仅支持启动三方应用组件，不支持系统应用组件。
> 
> 被启动的组件需要对外可见，即module.json5中的exported字段需要为true。
> 
> 不支持[隐式Want启动](../../application-models/ability-terminology.md#隐式want启动)。
> 
> 如果被启动的UIAbility有权限保护，需要额外申请对应的权限。

**需要权限**：ohos.permission.ENTERPRISE_START_ABILITIES

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。设置后系统将以此参数验证调用方的设备管理员身份和权限。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 启动组件的必要信息，Want中必须包含被启动组件的abilityName和所在应用的bundleName。设置后系统将根据bundleName定位目标应用，根据abilityName定位并启动目标组件。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当启动组件失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200014  | Failed to start the ability. |
| 9200015  | The ability does not exist. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**
需要在module.json5中配置被启动组件的信息。permissions为可选字段，需根据实际情况进行替换或者不填。

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

调用方应用需要在module.json5中申请对应的权限。启动其他应用中的组件时，调用方应用必须获取该组件所要求的权限。

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
 * 企业设备管理扩展能力组件
 */
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
    // 需根据实际情况进行替换
    let admin: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'EnterpriseAdminAbility',
    };
    // 需根据实际情况进行替换
    let want: Want = {
      bundleName: 'com.example.myotherapplication',
      abilityName: 'MainAbility'
    };
    this.context.startAbilityByAdmin(admin, want).catch((err: BusinessError) => {
      console.error(`Failed to start an ability. Code: ${err.code}, message: ${err.message}`);
    });
    
    // 通过context获取到应用文件路径
    let preferencesDir = this.context.preferencesDir;
    console.info(`preferencesDir: ` + preferencesDir);
    
    // 通过context获取到preferences数据
    let options: preferences.Options = {
      // 需根据实际情况进行替换
      name: "key",
    };
    try {
      let preference = preferences.getPreferencesSync(this.context, options);
      // 需根据实际情况进行替换
      preference.putSync("key", "value");
      preference.flushSync();
    
      // 需根据实际情况进行替换
      let value: string = preference.getSync('key', 'default') as string;
      console.info(`get preferences value: ${value}`);
    } catch (error) {
      console.error('get preference fail');
    }
  }
}
```