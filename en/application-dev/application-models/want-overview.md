# Want Overview


## Definition and Usage of Want

[Want](../reference/apis/js-apis-app-ability-want.md) is used as the carrier to transfer information between application components. It is used as a parameter of **startAbility()** to specify the startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. For example, when UIAbilityA starts UIAbilityB and needs to transfer some data to UIAbilityB, it can use Want to transfer the data.

**Figure 1** Want usage

![usage-of-want](figures/usage-of-want.png) 


## Types of Want

- **Explicit Want**: A type of Want with **abilityName** and **bundleName** specified when starting a UIAbility.
    When there is an explicit object to process the request, the target ability can be started by specifying the bundle name and ability name in Want. Explicit Want is usually used to start a known ability. For details, see [Want Parameter](want-overview.md#want-parameter).
    
  ```ts
  let wantInfo = {
      deviceId: '', // An empty deviceId indicates the local device.
      bundleName: 'com.example.myapplication',
      abilityName: 'FuncAbility',
  }
  ```

- **Implicit Want**: A type of Want with **abilityName** unspecified when starting the ability.
  Implicit Want can be used when the object used to process the request is unclear and the current application wants to use a capability (defined by the [skills tag](../quick-start/module-configuration-file.md#skills)) provided by another application. For example, you can use implicit Want to describe a request for opening a link, since you do not care which application is used to open the link. The system matches all applications that support the request.

  
  ```ts
  let wantInfo = {
      // Uncomment the line below if you want to implicitly query data only in the specific bundle.
      // bundleName: 'com.example.myapplication',
      action: 'ohos.want.action.search',
      // entities can be omitted.
      entities: [ 'entity.system.browsable' ],
      uri: 'https://www.test.com:8080/query/student',
      type: 'text/plain',
  };
  ```

  > **NOTE**
  > - Depending on the ability matching result, the following cases may be possible when you attempt to use implicit Want to start the ability.
  >   - No ability is matched. The startup fails.
  >   - An ability that meets the conditions is matched. That ability is started.
  >   - Multiple abilities that meet the conditions are matched. A dialog box is displayed for users to select one of them.
  > 
  > - If the **want** parameter passed does not contain **abilityName** or **bundleName**, the ServiceExtensionAbility components of all applications cannot be started through implicit Want.
  > 
  > - If the **want** parameter passed contains **bundleName**, the **startServiceExtensionAbility()** method can be used to implicitly start ServiceExtensionAbility. By default, ServiceExtensionAbility with the highest priority is returned. If all the matching ServiceExtensionAbility components have the same priority, the first ServiceExtensionAbility is returned.

## Want Parameter

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceId | Read Only| string | No| ID of the device where the target ability is located. If this field is unspecified, the local device is used.|
| bundleName | Read Only| string | No| Name of the application to which the target ability belongs.|
| moduleName | Read Only| string | No| Name of the module to which the target ability belongs.|
| abilityName | Read Only| string | No| Name of the target ability. If this field is unspecified, implicit Want is used. If both **bundleName**, **moduleName**, and **abilityName** are specified in Want, the Want can match a specific ability.|
| uri | Read Only| string | No| Data carried. This field is used together with **type** to specify the data type. If **uri** is specified in Want, the Want will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type | Read Only| string | No| Type of the data carried. The [MIME type](https://www.iana.org/assignments/media-types/media-types.xhtml) specification is used. Example: **"text/plain"** and **"image/\*"**.|
| [action](../reference/apis/js-apis-ability-wantConstant.md) | Read Only| string | No| Action to take, such as viewing, sharing, and application details. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data, for example, viewing URI data. For example, if the URI is a website and the action is **ohos.want.action.viewData**, the ability that supports website viewing is matched.|
| [entities](../reference/apis/js-apis-ability-wantConstant.md) | Read Only| Array&lt;string&gt; | No| Additional category information (such as browser and video player) of the target ability. It is a supplement to **action** in implicit Want. You can define this field to filter UIAbility categories, for example, browser. For example, for the value of the **action** field, multiple applications declare that they support website viewing. Some are social applications, and some are browser applications. You can use **entity.system.browsable** to filter out non-browser applications.|
| [flags](../reference/apis/js-apis-ability-wantConstant.md#wantconstantflags) | Read Only| number | No| How the Want will be handled. For example, **wantConstant.Flags.FLAG_ABILITY_CONTINUATION** specifies whether to start the ability in cross-device migration scenarios.|
| parameters | Read Only| {[key:&nbsp;string]:&nbsp;any} | No| Custom data. Data is filled using custom key-value pairs. For details about the supported data types, see [Want API](../reference/apis/js-apis-app-ability-want.md).|
