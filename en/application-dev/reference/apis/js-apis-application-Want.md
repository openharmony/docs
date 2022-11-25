# Want

The **Want** module provides the basic communication component of the system.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import Want from '@ohos.application.Want';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read only    | string               | No  | ID of the device running the ability.                               |
| bundleName   | Read only    | string               | No  | Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability.|
| abilityName  | Read only    | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. The value of **abilityName** must be unique in an application.|
| uri          | Read only    | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type         | Read only    | string               | No  | MIME type, that is, the type of the file to open, for example, **text/xml** and **image/***. For details about the MIME type definition, see https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com.  |
| flags        | Read only    | number               | No  | How the **Want** object will be handled. For details, see [flags](js-apis-featureAbility.md#flags).|
| action      | Read only    | string               | No  | Action to take, such as viewing and sharing application details. In implicit **Want**, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data.                          |
| parameters   | Read only    | {[key: string]: any} | No  | Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>**ohos.aafwk.callerPid**: PID of the caller.<br>**ohos.aafwk.param.callerToken**: token of the caller.<br>**ohos.aafwk.param.callerUid**: UID in [bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo-1), that is, the application UID in the bundle information.                                      |
| entities    | Read only    | Array\<string>       | No  | Additional category information (such as browser and video player) of the target ability. It is a supplement to **action** in implicit **Want** and is used to filter ability types.                                   |
| moduleName<sup>9+</sup> | Read only  | string | No   | Module to which the ability belongs.|

**Example**

- Basic usage

  ```  js
    var want = {
        "deviceId": "", // An empty deviceId indicates the local device.
        "bundleName": "com.extreme.test",
        "abilityName": "MainAbility",
        "moduleName": "entry" // moduleName is optional.
    };
    this.context.startAbility(want, (error) => {
        // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
        console.log("error.code = " + error.code)
    })
  ```

- Data is transferred through user-defined fields. The following data types are supported:

    * String
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForString: "str",
            },
        }
        ```
    * Number
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForInt: 100,
                keyForDouble: 99.99,
            },
        }
        ```
    * Boolean
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForBool: true,
            },
        }
        ```
    * Object
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForObject: {
                    keyForObjectString: "str",
                    keyForObjectInt: -200,
                    keyForObjectDouble: 35.5,
                    keyForObjectBool: false,
                },
            },
        }
        ```
    * Array
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForArrayString: ["str1", "str2", "str3"],
                keyForArrayInt: [100, 200, 300, 400],
                keyForArrayDouble: [0.1, 0.2],
                keyForArrayObject: [{obj1: "aaa"}, {obj2: 100}],
            },
        }
        ```
    * File descriptor (FD)
        ```ts
            import fileio from '@ohos.fileio';
            var fd;
            try {
                fd = fileio.openSync("/data/storage/el2/base/haps/pic.png");
            } catch(e) {
                console.log("openSync fail:" + JSON.stringify(e));
            }
            var want = {
                "deviceId": "", // An empty deviceId indicates the local device.
                "bundleName": "com.extreme.test",
                "abilityName": "MainAbility",
                "moduleName": "entry", // moduleName is optional.
                "parameters": {
                    "keyFd":{"type":"FD", "value":fd}
                }
            };
            this.context.startAbility(want, (error) => {
                // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
                console.log("error.code = " + error.code)
            })
        ```

  <!--no_check-->
