# @ohos.app.ability.Want (Want)

Want is a carrier for information transfer between objects (application components).

A typical scenario is when a UIAbility (for example, UIAbility A) needs to launch another UIAbility (for example, UIAbility B) and pass some data along. In this case, a Want can be used as the medium. For example, in the **want** parameter of the **startAbility** API, you can specify the target ability using the **abilityName** field or include additional data via the **parameters** field.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { Want } from '@kit.AbilityKit';
```

## Want

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Type                | Read-Only| Optional| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| deviceId    | string               | No| Yes| Device ID. It indicates the device ID of the target application in the application launch scenario. If not specified, it defaults to the current device.              |
| bundleName   | string               | No| Yes | Bundle name of the application. It represents the bundle name of the target application in the application launch scenario.|
| moduleName | string | No| Yes| Module name of the application. It represents the module name of the target application in the application launch scenario.<br>**NOTE**<br> If the ability belongs to a [HAR](../../quick-start/har-package.md) module, **moduleName** must be set to the name of the [HAP](../../quick-start/hap-package.md) or [HSP](../../quick-start/in-app-hsp.md) module that depends on this HAR.|
| abilityName  | string               | No| Yes | Ability name of the application. It represents the ability name of the target application in the application launch scenario. If both **bundleName** and **abilityName** are specified in a Want object, the Want object can match a specific ability. The value of **abilityName** must be unique in an application.|
| action | string               | No| Yes | Action to take, such as viewing and sharing application details. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data. For details about the definition and matching rules of implicit Want, see [Matching Rules of Explicit Want and Implicit Want](../../application-models/explicit-implicit-want-mappings.md).     |
| entities | Array\<string> | No| Yes| Additional category information (such as browser and video player) of the ability. It is a supplement to the **action** field for implicit Want. and is used to filter ability types.|
| uri | string | No| Yes| URI, which is used with **type** to specify the data type to be processed in the application launch scenario. If **uri** is specified in a Want, the Want will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type | string | No| Yes| MIME type, that is, the type of the file to open, for example, **'text/xml'** and **'image/*'**. For details about the MIME type definition, see [Media Types](https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com).|
| parameters   | Record\<string, Object> | No| Yes | List of parameters in the Want object.<br>1. The values of the following keys are assigned by the system. Manual settings do not take effect, since the system automatically changes the values to the actual values during data transfer.<br>- **ohos.aafwk.param.callerPid**: PID of the caller. The value is a string.<br>- **ohos.aafwk.param.callerBundleName**: bundle name of the caller. The value is a string.<br>- **ohos.aafwk.param.callerAbilityName**: ability name of the caller. The value is a string.<br>- **ohos.aafwk.param.callerNativeName**: process name of the caller when the native method is called. The value is a string.<br>- **ohos.aafwk.param.callerAppId**: appId of the caller. The value is a string.<br>- **ohos.aafwk.param.callerAppIdentifier**: appIdentifier of the caller. The value is a string.<br>- **ohos.aafwk.param.callerToken**: token of the caller. The value is a string.<br>- **ohos.aafwk.param.callerUid**: UID in [BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1), that is, the application's UID in the bundle information. The value is a number.<br>- **ohos.param.callerAppCloneIndex**: clone index of the caller. The value is of the numeric type.<br>- **component.startup.newRules**: enabled status of the new control rule. The value is of the Boolean type.<br>- **moduleName**: module name of the caller. The value is a string.<br>- **ohos.ability.params.abilityRecoveryRestart**: support for ability restart upon fault recovery. The value is of the Boolean type.<br>- **ohos.extra.param.key.showMode**: mode to show the atomic service startup. The value is an enumerated value of [wantConstant.ShowMode](js-apis-app-ability-wantConstant.md#showmode12).<br><br>2. Certain keys are defined by the system, and their values need to be manually assigned. For details about the keys and their values, see [wantConstant.Params](js-apis-app-ability-wantConstant.md#params)<!--Del--> and [wantConstant.Params (for System Applications Only)](js-apis-app-ability-wantConstant-sys.md#params)<!--DelEnd-->.<br><br>3. In addition to the foregoing cases, applications may further agree on the key-value pairs to transfer.<br><br>**NOTE**<br>For details about the constants of **Params** in **want**, see [wantConstant](js-apis-app-ability-wantConstant.md).<br>Note that a maximum of 100 KB data that can be transferred by using **WantParams**. If the data volume exceeds 100 KB, transfer data in [WriteRawDataBuffer](../apis-ipc-kit/js-apis-rpc.md#writerawdatabuffer11) or [uri](../apis-arkts/js-apis-uri.md) mode.<br>The values of **parameters** must be of the following basic data types: String, Number, Boolean, Object, undefined, and null. Functions in an object cannot be transferred.|
| [flags](js-apis-app-ability-wantConstant.md#flags) | number | No| Yes| How the Want object will be handled. By default, a number is passed in.<br>For example, if the value is 0x00000001 (**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**), the receiver is temporarily granted the permission to read the data pointed to by the URI.|
| fds<sup>15+</sup> | Record\<string, number> | Yes| Yes| File descriptor (FD). The FD written by the launcher in the application launch scenario is set to this parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|

**Example**

- Basic usage: called in a UIAbility object, as shown in the example below. For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  ```ts
  import { UIAbility, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
      let want: Want = {
        deviceId: '', // An empty deviceId indicates the local device.
        bundleName: 'com.example.myapplication',
        abilityName: 'FuncAbility',
        moduleName: 'entry' // moduleName is optional.
      };

      this.context.startAbility(want, (err: BusinessError) => {
        if (err.code) {
          // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        }
      });
    }
  }
  ```

- Currently, the following data types are supported: string, number, Boolean, object, array, and file descriptor (FD).

    * String
        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                keyForString: 'str',
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```
    * Number
        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                keyForInt: 100,
                keyForDouble: 99.99,
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```
    * Boolean
        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                keyForBool: true,
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```
    * Object
        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                keyForObject: {
                  keyForObjectString: 'str',
                  keyForObjectInt: -200,
                  keyForObjectDouble: 35.5,
                  keyForObjectBool: false,
                },
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```
    * Array

        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                keyForArrayString: ['str1', 'str2', 'str3'],
                keyForArrayInt: [100, 200, 300, 400],
                keyForArrayDouble: [0.1, 0.2],
                keyForArrayObject: [{ obj1: 'aaa' }, { obj2: 100 }],
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```

    * FD

        ```ts
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';
        import { fileIo } from '@kit.CoreFileKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let fd: number = 0;

            try {
              fd = fileIo.openSync('/data/storage/el2/base/haps/pic.png').fd;
            } catch (err) {
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              console.error(`Failed to openSync. Code: ${code}, message: ${message}`);
            }
            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              moduleName: 'entry', // moduleName is optional.
              parameters: {
                'keyFd': { 'type': 'FD', 'value': fd } // {'type':'FD', 'value':fd} is a fixed usage, indicating that the data is a file descriptor.
              }
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```

    * **parameters** usage: **parameters** carries custom parameters. It is transferred by UIAbilityA to UIAbilityB and obtained from UIAbilityB.

        ```ts
        // (1) UIAbilityA calls startAbility to start UIAbilityB.
        import { UIAbility, Want } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'UIAbilityB',
              parameters: {
                developerParameters: 'parameters',
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```

        ```ts
        // (2) If the UIAbilityB instance is started for the first time, it enters the onCreate lifecycle.
        import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

        class UIAbilityB extends UIAbility {
          onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
            console.log(`onCreate, want parameters: ${want.parameters?.developerParameters}`);
          }
        }
        ```
    * Usage of the keys of [wantConstant](js-apis-app-ability-wantConstant.md) in **parameters**.

        ```ts
        import { UIAbility, Want, wantConstant } from '@kit.AbilityKit';
        import { window } from '@kit.ArkUI';
        import { BusinessError } from '@kit.BasicServicesKit';

        export default class EntryAbility extends UIAbility {
          onWindowStageCreate(windowStage: window.WindowStage): void {
            let want: Want = {
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              parameters: {
                [wantConstant.Params.CONTENT_TITLE_KEY]: 'contentTitle',
              },
            };

            this.context.startAbility(want, (err: BusinessError) => {
              if (err.code) {
                console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
              }
            });
          }
        }
        ```
    * Obtain the information about the party that starts the UIAbility from **parameters**.

      For details, see [Obtaining Information About the UIAbility Launcher](../../application-models/uiability-usage.md#obtaining-information-about-the-uiability-launcher).
