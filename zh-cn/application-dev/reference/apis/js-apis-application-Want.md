# Want

Want模块提供系统的基本通信组件的能力。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import Want from '@ohos.application.Want';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 可读     | 可写     | 类型                 | 必填 | 说明                                                         |
| ----------- | -------- | ------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | 是     | 否    | string               | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName   | 是     | 否    | string               | 否   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName  | 是     | 否    | string               | 否   | 表示待启动的Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |
| uri          | 是     | 否    | string               | 否   | 表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |
| type         | 是     | 否    | string               | 否   | 表示MIME type类型描述，打开文件的类型，主要用于文管打开文件。比如："text/xml" 、 "image/*"等，MIME定义参考：https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。   |
| flags        | 是     | 否     | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](js-apis-featureAbility.md#flags说明)。 |
| action      | 是     | 否     | string               | 否   | 表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。                           |
| parameters   | 是     | 否    | {[key: string]: any} | 否   | 表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br>ohos.aafwk.callerPid 表示拉起方的pid。<br>ohos.aafwk.param.callerToken 表示拉起方的token。<br>ohos.aafwk.param.callerUid 表示[bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。                                       |
| entities    | 是     | 否    | Array\<string>       | 否   | 表示目标Ability额外的类别信息（如：浏览器、视频播放器），在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。                                    |
| moduleName<sup>9+</sup> | 是   | 否    | string | 否    | 表示待启动的Ability所属的模块（module）。 |

**示例：**

- 基础用法

  ```  js
    var want = {
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

- 通过自定字段传递数据, 以下为当前支持类型。

    * 字符串（String）
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForString: "str",
            },
        }
        ```
    * 数字（Number）
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
    * 布尔（Boolean）
        ```ts
        let want = {
            bundleName: "com.example.demo",
            abilityName: "com.example.demo.MainAbility",
            parameters: {
                keyForBool: true,
            },
        }
        ```
    * 对象（Object）
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
    * 数组（Array）
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
    * 文件描述符（FD）
        ```ts
            import fileio from '@ohos.fileio';
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
                "moduleName": "entry", // moduleName非必选
                "parameters": {
                    "keyFd":{"type":"FD", "value":fd}
                }
            };
            this.context.startAbility(want, (error) => {
                // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
                console.log("error.code = " + error.code)
            })
        ```

  <!--no_check-->


