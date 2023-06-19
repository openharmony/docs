# @ohos.app.ability.Want (Want)

Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of **startAbility** to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When UIAbility A needs to start UIAbility B and transfer some data to UIAbility B, it can use Want a carrier to transfer the data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import Want from '@ohos.app.ability.Want';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | string               | No  | ID of the device running the ability. If this field is unspecified, the local device is used.                               |
| bundleName   | string               | No  | Bundle name of the ability.|
| moduleName | string | No| Name of the module to which the ability belongs.|
| abilityName  | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. The value of **abilityName** must be unique in an application.|
| action | string               | No  | Action to take, such as viewing and sharing application details. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data. For details about the definition and matching rules of implicit Want, see [Matching Rules of Explicit Want and Implicit Want](../../application-models/explicit-implicit-want-mappings.md).            |
| entities | Array\<string> | No| Additional category information (such as browser and video player) of the ability. It is a supplement to the **action** field for implicit Want. and is used to filter ability types.|
| uri | string | No| Data carried. This field is used together with **type** to specify the data type. If **uri** is specified in a Want, the Want will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type | string | No| MIME type, that is, the type of the file to open, for example, **'text/xml'** and **'image/*'**. For details about the MIME type definition, see https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com.|
| parameters   | {[key: string]: any} | No  | Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>- **ohos.aafwk.callerPid**: PID of the caller.<br>- **ohos.aafwk.param.callerBundleName**: bundle name of the caller.<br>- **ohos.aafwk.param.callerToken**: token of the caller.<br>- **ohos.aafwk.param.callerUid**: UID in [BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1), that is, the application UID in the bundle information.<br>- **component.startup.newRules**: whether to enable the new control rule.<br>- **moduleName**: module name of the caller. No matter what this field is set to, the correct module name will be sent to the peer.<br>- **ohos.dlp.params.sandbox**: available only for DLP files.<br>- **ability.params.backToOtherMissionStack**: whether to support redirection back across mission stacks.|
| [flags](js-apis-ability-wantConstant.md#wantconstantflags) | number | No| How the **Want** object will be handled. By default, a number is passed in.<br>For example, **wantConstant.Flags.FLAG_ABILITY_CONTINUATION** specifies whether to start the ability in cross-device migration scenarios.|

**Example**

- Basic usage: called in a UIAbility object, as shown in the example below. For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  let want = {
    'deviceId': '', // An empty deviceId indicates the local device.
    'bundleName': 'com.example.myapplication',
    'abilityName': 'FuncAbility',
    'moduleName': 'entry' // moduleName is optional.
  };
  
  context.startAbility(want, (err) => {
    // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
    console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
  });
  ```

- Currently, the following data types are supported: string, number, Boolean, object, array, and file descriptor (FD).

    * String
        ```ts
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication',
          abilityName: 'FuncAbility',
          parameters: {
            keyForString: 'str',
          },
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    * Number
        ```ts
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication',
          abilityName: 'FuncAbility',
          parameters: {
            keyForInt: 100,
            keyForDouble: 99.99,
          },
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    * Boolean
        ```ts
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication',
          abilityName: 'FuncAbility',
          parameters: {
            keyForBool: true,
          },
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    * Object
        ```ts
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
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
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    * Array
        ```ts
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication',
          abilityName: 'FuncAbility',
          parameters: {
            keyForArrayString: ['str1', 'str2', 'str3'],
            keyForArrayInt: [100, 200, 300, 400],
            keyForArrayDouble: [0.1, 0.2],
            keyForArrayObject: [{ obj1: 'aaa' }, { obj2: 100 }],
          },
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    * FD
        ```ts
        import fs from '@ohos.file.fs';
        
        import common from '@ohos.app.ability.common';
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        
        let fd;
        try {
          fd = fs.openSync('/data/storage/el2/base/haps/pic.png').fd;
        } catch(err) {
          console.error(`Failed to openSync. Code: ${err.code}, message: ${err.message}`);
        }
        let want = {
          'deviceId': '', // An empty deviceId indicates the local device.
          'bundleName': 'com.example.myapplication',
          'abilityName': 'FuncAbility',
          'moduleName': 'entry', // moduleName is optional.
          'parameters': {
            'keyFd': { 'type': 'FD', 'value': fd } // {'type':'FD', 'value':fd} is a fixed usage, indicating that the data is a file descriptor.
          }
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    - Usage of **parameters**: The following uses **ability.params.backToOtherMissionStack** as an example. When a ServiceExtensionAbility starts a UIAbility, redirection back across mission stacks is supported.

    ```ts
        // (1) UIAbility1 starts a ServiceExtensionAbility.
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication1',
          abilityName: 'ServiceExtensionAbility',
        };

        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });

        // (2) The ServiceExtensionAbility starts UIAbility2, carrying **"ability.params.backToOtherMissionStack": true** during the startup.
        let context = ...; // ServiceExtensionContext
        let want = {
          bundleName: 'com.example.myapplication2',
          abilityName: 'MainAbility',
          parameters: {
            "ability.params.backToOtherMissionStack": true,
          },
        };

        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
    ```

    Note: In the preceding example, when the ServiceExtensionAbility starts UIAbility2, **"ability.params.backToOtherMissionStack": true** is carried, indicating that redirection back across mission stacks is supported. Therefore, when you press **Back** on the page of UIAbility 2, the page of UIAbility1 page is displayed. However, if **ability.params.backToOtherMissionStack** is not carried or if **"ability.params.backToOtherMissionStack": false** is carried, the page of UIAbility1 is not displayed when you press **Back** on the page of UIAbility 2.
