# Want

Want是对象间信息传递的载体, 可以用于应用组件间的信息传递。 Want的使用场景之一是作为[startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)的参数, 其包含了指定的启动目标, 以及启动时需携带的相关数据, 如bundleName和abilityName字段分别指明目标Ability所在应用的Bundle名称以及对应包内的Ability名称。当Ability A需要启动Ability B并传入一些数据时, 可使用Want作为载体将这些数据传递给Ability B。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | string               | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName   | string               | 否   | 表示Bundle名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName  | string               | 否   | 表示待启动的Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |
| uri          | string               | 否   | 表示Uri。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |
| type         | string               | 否   | 表示MIME type类型，打开文件的类型，主要用于文管打开文件。比如："text/xml" 、 "image/*"等，MIME定义参考：https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。   |
| flags        | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](js-apis-ability-wantConstant.md#wantConstant.Flags)。 |
| action      | string               | 否   | 表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。                           |
| parameters   | {[key: string]: any} | 否   | 表示WantParams，由开发者自行决定传入的键值对。默认会携带以下key值：<br>ohos.aafwk.callerPid 表示拉起方的pid。<br>ohos.aafwk.param.callerToken 表示拉起方的token。<br>ohos.aafwk.param.callerUid 表示[bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。                                       |
| entities    | Array\<string>       | 否   | 表示目标Ability额外的类别信息（如：浏览器、视频播放器），在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。                                    |
| moduleName<sup>9+</sup> | string | 否    | 表示待启动的Ability所属的模块（module）。 |

**示例：**

- 基础用法(在UIAbility对象中调用，其中示例中的context为UIAbility的上下文对象)

  ```ts
  let want = {
      "deviceId": "", // deviceId为空表示本设备
      "bundleName": "com.extreme.test",
      "abilityName": "MainAbility",
      "moduleName": "entry" // moduleName非必选
  };
  this.context.startAbility(want, (error) => {
      // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
      console.log("error.code = " + error.code)
  })
  ```

- 传递FD(文件描述符)数据(在UIAbility对象中调用，其中示例中的context为UIAbility的上下文对象)

  ```ts
  import fileio from '@ohos.fileio';
  
  // ...
  let fd;
  try {
      fd = fileio.openSync("/data/storage/el2/base/haps/pic.png");
  } catch(e) {
      console.log("openSync fail:" + JSON.stringify(e));
  }
  let want = {
      "deviceId": "", // deviceId为空表示本设备
      "bundleName": "com.extreme.test",
      "abilityName": "MainAbility",
      "moduleName": "entry", // moduleName非必选
      "parameters": {
          "keyFd":{"type":"FD", "value":fd}
      }
  };
  this.context.startAbility(want, (error) => {
      // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
      console.log("error.code = " + error.code)
  })
  // ...
  ```
  
- 更多详细说明和示例请参见： [应用模型](../../application-models/Readme-CN.md)的信息传递载体Want

  <!--no_check-->