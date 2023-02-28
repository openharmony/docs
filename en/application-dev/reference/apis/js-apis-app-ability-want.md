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
| deviceId    | string               | No  | ID of the device running the ability.                               |
| bundleName   | string               | No  | Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. |
| abilityName  | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. The value of **abilityName** must be unique in an application.|
| uri | string | No| If **uri** is specified in a **Want**, the **Want** will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path** components.|
| type | string | No| MIME type, that is, the type of the file to open, for example, **'text/xml'** and **'image/*'**. For details about the MIME type definition, see https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com.|
| flags | number | No| How the **Want** object will be handled. By default, a number is passed in. For details, see [flags](js-apis-ability-wantConstant.md#wantConstant.Flags). |
| action | string               | No  | Action to take, such as viewing and sharing application details. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data.               |
| parameters   | {[key: string]: any} | No  | Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>- **ohos.aafwk.callerPid**: PID of the caller.<br>- **ohos.aafwk.param.callerToken**: token of the caller.<br>- **ohos.aafwk.param.callerUid**: UID in [BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1), that is, the application UID in the bundle information.<br>- **component.startup.newRules**: whether to enable the new control rule.<br/>- **moduleName**: module name of the caller. No matter what this field is set to, the correct module name will be sent to the peer.<br/>- **ohos.dlp.params.sandbox**: available only for DLP files. |
| entities | Array\<string> | No| Additional category information (such as browser and video player) of the ability. It is a supplement to the **action** field for implicit Want. and is used to filter ability types.|
| moduleName | string | ·ñ    | Module to which the ability belongs. |

**Example**

- Basic usage

  ```ts
    let want = {
        'deviceId': '', // An empty deviceId indicates the local device.
        'bundleName': 'com.extreme.test',
        'abilityName': 'MainAbility',
        'moduleName': 'entry' // moduleName is optional
    };
    this.context.startAbility(want, (error) => {
        // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
        console.log('error.code = ' + error.code);
    })
  ```

- Data is transferred through user-defined fields. The following data types are supported:

    * String
        ```ts
        let want = {
            bundleName: 'com.example.demo',
            abilityName: 'com.example.demo.MainAbility',
            parameters: {
                keyForString: 'str',
            },
        };
        ```
    * Number
        ```ts
        let want = {
            bundleName: 'com.example.demo',
            abilityName: 'com.example.demo.MainAbility',
            parameters: {
                keyForInt: 100,
                keyForDouble: 99.99,
            },
        };
        ```
    * Boolean
        ```ts
        let want = {
            bundleName: 'com.example.demo',
            abilityName: 'com.example.demo.MainAbility',
            parameters: {
                keyForBool: true,
            },
        };
        ```
    * Object
        ```ts
        let want = {
            bundleName: 'com.example.demo',
            abilityName: 'com.example.demo.MainAbility',
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
        let want = {
            bundleName: 'com.example.demo',
            abilityName: 'com.example.demo.MainAbility',
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
            import fileio from '@ohos.fileio';
            let fd;
            try {
                fd = fileio.openSync('/data/storage/el2/base/haps/pic.png');
            } catch(e) {
                console.log('openSync fail:' + JSON.stringify(e));
            }
            let want = {
                'deviceId': '', // An empty deviceId indicates the local device.
                'bundleName': 'com.extreme.test',
                'abilityName': 'MainAbility',
                'moduleName': 'entry', // moduleName is optional.
                'parameters': {
                    'keyFd':{'type':'FD', 'value':fd} // {'type':'FD', 'value':fd} is a fixed usage, indicating that the data is a file descriptor.
                }
            };
            this.context.startAbility(want, (error) => {
            // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
                console.log('error.code = ' + error.code);
            });
        ```



