# Want

Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of [startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When ability A needs to start ability B and transfer some data to ability B, it can use Want a carrier to transfer the data.

> **NOTE**
> 
> The APIs of this module are supported since API version 6 and deprecated since API version 9. You are advised to use [@ohos.app.ability.Want](js-apis-app-ability-want.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import Want from '@ohos.app.ability.Want';
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | string               | No  | ID of the device running the ability.                               |
| bundleName   | string               | No  | Bundle name.|
| abilityName  | string               | No  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability. The value of **abilityName** must be unique in an application.|
| uri          | string               | No  | URI. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type         | string               | No  | MIME type, that is, the type of the file to open, for example, **'text/xml'** and **'image/*'**. For details about the MIME type definition, see https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com.  |
| flags        | number               | No  | How the **Want** object will be handled. By default, numbers are passed in. For details, see [flags](js-apis-app-ability-wantConstant.md#wantconstantflags).|
| action      | string               | No  | Action to take, such as viewing and sharing application details. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data.                           |
| parameters   | {[key: string]: Object} | No  | Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>- **ohos.aafwk.callerPid**: PID of the caller.<br>- **ohos.aafwk.param.callerToken**: token of the caller.<br>- **ohos.aafwk.param.callerUid**: UID in [bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo-1), that is, the application UID in the bundle information.<br>- **component.startup.newRules**: whether to enable the new control rule.<br>- **moduleName**: module name of the caller. No matter what this field is set to, the correct module name will be sent to the peer.<br>- **ohos.dlp.params.sandbox**: available only for DLP files.                                  |
| entities    | Array\<string>       | No  | Additional category information (such as browser and video player) of the target ability. It is a supplement to **action** in implicit Want and is used to filter ability types.                                    |
| moduleName<sup>9+</sup> | string | No   | Module to which the ability belongs.|

**Example**

- Basic usage (called in a UIAbility object, where context in the example is the context object of the UIAbility).

  ```ts
  let want = {
      'deviceId': '', // An empty deviceId indicates the local device.
      'bundleName': 'com.extreme.test',
      'abilityName': 'MainAbility',
      'moduleName': 'entry' // moduleName is optional.
  };
  this.context.startAbility(want, (error) => {
      // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
      console.log('error.code = ' + error.code)
  });
  ```

- Passing a file descriptor (FD) (called in the UIAbility object, where context in the example is the context object of the UIAbility):

  ```ts
  import fs from '@ohos.file.fs';
  
  // ...
  let fd;
  try {
      fd = fs.openSync('/data/storage/el2/base/haps/pic.png').fd;
  } catch(e) {
      console.log('openSync fail:' + JSON.stringify(e));
  }
  let want = {
      'deviceId': '', // An empty deviceId indicates the local device.
      'bundleName': 'com.extreme.test',
      'abilityName': 'MainAbility',
      'moduleName': 'entry', // moduleName is optional.
      'parameters': {
          'keyFd':{'type':'FD', 'value':fd}
      }
  };
  this.context.startAbility(want, (error) => {
      // Start an ability explicitly. The bundleName, abilityName, and moduleName parameters work together to uniquely identify an ability.
      console.log('error.code = ' + error.code)
  });
  // ...
  ```
  
- For more details and examples, see [Want](../../application-models/want-overview.md).

