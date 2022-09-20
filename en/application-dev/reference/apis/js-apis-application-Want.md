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
| abilityName  | Read only    | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability.|
| uri          | Read only    | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type         | Read only    | string               | No  | MIME type, for example, **text/plain** or **image/***. |
| flags        | Read only    | number               | No  | How the **Want** object will be handled. For details, see [flags](js-apis-featureAbility.md#flags).|
| action      | Read only    | string               | No  | Action option.                          |
| parameters   | Read only    | {[key: string]: any} | No  | List of parameters in the **Want** object. |
| entities    | Read only    | Array\<string>       | No  | List of entities.                                   |
| extensionAbilityType<sup>9+</sup> |  Read only   | bundle.ExtensionAbilityType | No  | Type of the Extension ability.                |
| extensionAbilityName<sup>9+<sup> | Read only     | string               | No   | Description of the Extension ability name in the **Want** object.                                   |

**Example**

- Basic usage

  ```js
  var want = {
        "deviceId": "", // An empty deviceId indicates the local device.
        "bundleName": "com.extreme.test",
        "abilityName": "MainAbility",
        "uri": "pages/second" // uri is optional and can be used to pass the destination URI.
    };
    this.context.startAbility(want, (error) => {
        // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
        console.log("error.code = " + error.code)
    })
  ```

- Passing a file descriptor (FD)

  ```js
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
        "parameters": {
          "keyFd":{"type":"FD", "value":fd}
        }
    };
    this.context.startAbility(want, (error) => {
        // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
        console.log("error.code = " + error.code)
    })
  ```

  