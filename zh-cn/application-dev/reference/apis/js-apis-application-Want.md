# Want

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。

Want是系统的基本通信组件。


## 导入模块


```
import Want from '@ohos.application.Want';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string               | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName   | 只读     | string               | 否   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName  | 只读     | string               | 否   | 表示待启动的Ability名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| uri          | 只读     | string               | 否   | 表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |
| type         | 只读     | string               | 否   | 表示MIME type类型描述，比如："text/plain" 、 "image/*"等。   |
| flags        | 只读     | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](js-apis-featureAbility.md#flags说明)。 |
| action      | 只读     | string               | 否   | 表示action选项描述。                           |
| parameters   | 只读     | {[key: string]: any} | 否   | 表示WantParams描述。                                       |
| entities    | 只读     | Array\<string>       | 否   | 表示entities相关描述。                                    |                              |
| extensionAbilityType<sup>9+</sup> |  只读   | bundle.ExtensionAbilityType | 否  | ExtensionAbility类型                |
| extensionAbilityName<sup>9+<sup> | 只读     | string               | 否   | Want中扩展能力名称的描述。                                   |

**示例：**

- 基础用法

  ```js
  var want = {
        "deviceId": "", // deviceId为空表示本设备
        "bundleName": "com.extreme.test",
        "abilityName": "MainAbility",
        "uri": "pages/second" // uri非必选，可以传递路由地址
    };
    this.context.startAbility(want, (error) => {
        // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
        console.log("error.code = " + error.code)
    })
  ```

- 传递FD数据，FD表示文件描述符(FileDescriptor)

  ```js
  var fd;
    try {
        fd = fileio.openSync("/data/storage/el2/base/haps/pic.png");
    } catch(e) {
        console.log("openSync fail:" + JSON.stringify(e));
    }
    var want = {
        "deviceId": "", // deviceId为空表示本设备
        "bundleName": "com.extreme.test",
        "abilityName": "MainAbility",
        "parameters": {
          "keyFd":{"type":"FD", "value":fd}
        }
    };
    this.context.startAbility(want, (error) => {
        // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
        console.log("error.code = " + error.code)
    })
  ```

  