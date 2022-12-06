# Want

Want是对象间信息传递的载体, 可以用于应用组件间的信息传递。 Want的使用场景之一是作为startAbility的参数, 其包含了指定的启动目标, 以及启动时需携带的相关数据, 如bundleName和abilityName字段分别指明目标Ability所在应用的包名以及对应包内的Ability名称。当Ability A需要启动Ability B并传入一些数据时, 可使用Want作为载体将这些数据传递给Ability B。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入类

```ts
import Want from '@ohos.app.ability.Want';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string               | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName   | 只读     | string               | 否   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName  | 只读     | string               | 否   | 表示待启动的Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |
| uri          | 只读     | string               | 否   | 表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |
| type         | 只读     | string               | 否   | 表示MIME type类型描述，打开文件的类型，主要用于文管打开文件。比如："text/xml" 、 "image/*"等，MIME定义参考：https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。   |
| flags        | 只读     | number               | 否   | 表示处理Want的方式。默认传数字，具体参考：[flags说明](js-apis-ability-wantConstant.md#wantConstant.Flags)。 |
| action      | 只读     | string               | 否   | 表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。                           |
| parameters   | 只读     | {[key: string]: any} | 否   | 表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br>ohos.aafwk.callerPid 表示拉起方的pid。<br>ohos.aafwk.param.callerToken 表示拉起方的token。<br>ohos.aafwk.param.callerUid 表示[bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。                                       |
| entities    | 只读     | Array\<string>       | 否   | 表示目标Ability额外的类别信息（如：浏览器、视频播放器），在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。                                    |
| moduleName | 只读   | string | 否    | 表示待启动的Ability所属的模块（module）。 |

**示例：**

- 基础用法

  ```ts
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


