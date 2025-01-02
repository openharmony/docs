# @ohos.application.Want (Want)

Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of **startAbility()** to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When ability A needs to start ability B and transfer some data to ability B, it can use Want a carrier to transfer the data.

> **NOTE**
>
> The APIs of this module are supported since API version 8 and deprecated since API version 9. You are advised to use [@ohos.app.ability.Want](js-apis-app-ability-want.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import Want from '@ohos.application.Want';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | string               | No  | ID of the device running the ability. If this field is unspecified, the local device is used.                               |
| bundleName   | string               | No  | Bundle name.|
| abilityName  | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. The value of **abilityName** must be unique in an application.|
| uri          | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type         | string               | No  | MIME type, that is, the type of the file to open, for example, **'text/xml'** and **'image/*'**. For details about the MIME type definition, see https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com.  |
| flags        | number               | No  | How the **Want** object will be handled. By default, numbers are passed in. For details, see [flags](js-apis-ability-wantConstant.md#flags).|
| action      | string               | No  | Action to take, such as viewing and sharing application details. In implicit **Want**, you can define this property and use it together with **uri** or **parameters** to specify the operation to be performed on the data. For details, see [action](js-apis-ability-wantConstant.md#action). For details about the definition and matching rules of implicit Want, see [Matching Rules of Explicit Want and Implicit Want](../../application-models/explicit-implicit-want-mappings.md).                          |
| parameters   | { [key: string]: any } | No  | Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>- **ohos.aafwk.param.callerPid**: PID of the caller.<br>- **ohos.aafwk.param.callerToken**: token of the caller.<br>- **ohos.aafwk.param.callerUid**: UID in [bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo), that is, the application UID in the bundle information.<br>- **component.startup.newRules**: whether to enable the new control rule.<br>- **moduleName**: module name of the caller. No matter what this field is set to, the correct module name will be sent to the peer.<br>- **ohos.dlp.params.sandbox**: available only for DLP files.                                      |
| entities    | Array\<string>       | No  | Additional category information (such as browser and video player) of the ability. It is a supplement to the **action** field for implicit Want. and is used to filter ability types. For details, see [entity](js-apis-ability-wantConstant.md#entity).                                   |

**Example**

- Basic usage (called in a UIAbility object, where context in the example is the context object of the UIAbility).

    ```ts
    import Want from '@ohos.application.Want';
    import { BusinessError } from '@ohos.base';
    import UIAbility from '@ohos.app.ability.UIAbility';
    import AbilityConstant from '@ohos.app.ability.AbilityConstant';

    let want: Want = {
    'deviceId': '', // An empty deviceId indicates the local device.
    'bundleName': 'com.example.myapplication',
    'abilityName': 'EntryAbility',
    };
    class MyAbility extends UIAbility{
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam){
        this.context.startAbility(want, (error: BusinessError) => {
        // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
        console.error(`error.code = ${error.code}`);
        });
    }
    }
    ```

- Data is transferred through user-defined fields. The following data types are supported (called in a UIAbility object, where context in the example is the context object of the UIAbility):

    * String
        ```ts
        import Want from '@ohos.application.Want';

        let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
                keyForString: 'str',
            },
        };
        ```
    * Number
        ```ts
        import Want from '@ohos.application.Want';

        let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
                keyForInt: 100,
                keyForDouble: 99.99,
            },
        };
        ```
    * Boolean
        ```ts
        import Want from '@ohos.application.Want';

        let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
                keyForBool: true,
            },
        };
        ```
    * Object
        ```ts
        import Want from '@ohos.application.Want';

        let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
                keyForObject: {
                    keyForObjectString: 'str',
                    keyForObjectInt: -200,
                    keyForObjectDouble: 35.5,
                    keyForObjectBool: false,
                },
            },
        };
        ```
    * Array
        ```ts
        import Want from '@ohos.application.Want';

        let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
                keyForArrayString: ['str1', 'str2', 'str3'],
                keyForArrayInt: [100, 200, 300, 400],
                keyForArrayDouble: [0.1, 0.2],
                keyForArrayObject: [{obj1: 'aaa'}, {obj2: 100}],
            },
        };
        ```
    * File descriptor (FD)
        ```ts
        import fs from '@ohos.file.fs';
        import Want from '@ohos.application.Want';
        import { BusinessError } from '@ohos.base';
        import AbilityConstant from '@ohos.app.ability.AbilityConstant';
        import UIAbility from '@ohos.app.ability.UIAbility';


        let fd: number = 0;
        try {
        fd = fs.openSync('/data/storage/el2/base/haps/pic.png').fd;
        } catch(e) {
        console.error(`openSync fail: ${JSON.stringify(e)}`);
        }
        let want: Want = {
        deviceId: '', // An empty deviceId indicates the local device.
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility',
        parameters: {
            'keyFd':{'type':'FD', 'value':fd}
        }
        };

        class MyAbility extends UIAbility{
        onCreate(want: Want, launchParam: AbilityConstant.LaunchParam){
            this.context.startAbility(want, (error: BusinessError) => {
            // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
            console.error(`error.code = ${error.code}`);
            });
        }
        }
        ```
