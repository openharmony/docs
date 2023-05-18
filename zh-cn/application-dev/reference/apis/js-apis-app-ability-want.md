# @ohos.app.ability.Want (Want)

Want是对象间信息传递的载体，可以用于应用组件间的信息传递。Want的使用场景之一是作为startAbility的参数，其包含了指定的启动目标，以及启动时需携带的相关数据，例如bundleName和abilityName字段分别指明目标Ability所在应用的包名以及对应包内的Ability名称。当UIAbilityA需要启动UIAbilityB并传入一些数据时，可使用Want作为载体将这些数据传递给UIAbilityB。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import Want from '@ohos.app.ability.Want';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | string               | 否   | 表示运行指定Ability的设备ID。如果未设置该字段，则表明指定本设备。                                |
| bundleName   | string               | 否   | 表示待启动Ability所在的应用Bundle名称。 |
| moduleName | string | 否 | 表示待启动的Ability所属的模块名称。 |
| abilityName  | string               | 否   | 表示待启动Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |
| action | string               | 否   | 表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。隐式Want定义及匹配规则请参见[显式Want与隐式Want匹配规则](../../application-models/explicit-implicit-want-mappings.md)。             |
| entities | Array\<string> | 否 | 表示目标Ability额外的类别信息（如：浏览器、视频播放器）。在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。 |
| uri | string | 否 | 表示携带的数据，一般配合type使用，指明待处理的数据类型。如果在Want中指定了uri，则Want将匹配指定的Uri信息，包括`scheme`、`schemeSpecificPart`、`authority`和`path`信息。 |
| type | string | 否 | 表示MIME type类型描述，打开文件的类型，主要用于文管打开文件。比如：'text/xml' 、 'image/*'等，MIME定义请参见https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。 |
| parameters   | {[key: string]: any} | 否   | 表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br />- ohos.aafwk.callerPid：表示拉起方的pid。<br />- ohos.aafwk.param.callerBundleName：表示拉起方的Bundle Name。<br />- ohos.aafwk.param.callerToken：表示拉起方的token。<br />- ohos.aafwk.param.callerUid：表示[BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。<br />- component.startup.newRules：表示是否启用新的管控规则。<br />- moduleName：表示拉起方的模块名，该字段的值即使定义成其他字符串，在传递到另一端时会被修改为正确的值。<br />- ohos.dlp.params.sandbox：表示dlp文件才会有。<br />- ability.params.backToOtherMissionStack：表示是否支持跨任务链返回。 |
| [flags](js-apis-ability-wantConstant.md#wantconstantflags) | number | 否 | 表示处理Want的方式。默认传数字。<br />例如通过wantConstant.Flags.FLAG_ABILITY_CONTINUATION表示是否以设备间迁移方式启动Ability。 |

**示例：**

- 基础用法：在UIAbility对象中调用，示例中的context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  let want = {
    'deviceId': '', // deviceId为空表示本设备
    'bundleName': 'com.example.myapplication',
    'abilityName': 'FuncAbility',
    'moduleName': 'entry' // moduleName非必选
  };
  
  context.startAbility(want, (err) => {
    // 显式拉起Ability，通过bundleName、abilityName和moduleName可以唯一确定一个Ability
    console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
  });
  ```

- 目前支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等。

    * 字符串（String）
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
    * 数字（Number）
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
    * 布尔（Boolean）
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
    * 对象（Object）
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
    * 数组（Array）
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
    * 文件描述符（FD）
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
          'deviceId': '', // deviceId为空表示本设备
          'bundleName': 'com.example.myapplication',
          'abilityName': 'FuncAbility',
          'moduleName': 'entry', // moduleName非必选
          'parameters': {
            'keyFd': { 'type': 'FD', 'value': fd } // {'type':'FD', 'value':fd}是固定用法，用于表示该数据是FD
          }
        };
        
        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });
        ```
    - parameter参数用法：以ability.params.backToOtherMissionStack为例，ServiceExtension在拉起UIAbility的时候，可以支持跨任务链返回。

    ```ts
        // (1) UIAbility1启动一个ServiceExtension
        let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want = {
          bundleName: 'com.example.myapplication1',
          abilityName: 'ServiceExtensionAbility',
        };

        context.startAbility(want, (err) => {
          console.error(`Failed to startAbility. Code: ${err.code}, message: ${err.message}`);
        });

        // (2) 该ServiceExtension去启动另一个UIAbility2，并在启动的时候携带参数ability.params.backToOtherMissionStack为true
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

    说明：上例中，如果ServiceExtension启动UIAbility2时不携带ability.params.backToOtherMissionStack参数，或者携带的ability.params.backToOtherMissionStack参数为false，则UIAbility1和UIAbility2不在同一个任务栈里面，在UIAbility2的界面点back键，不会回到UIAbility1的界面。如果携带的ability.params.backToOtherMissionStack参数为true，则表示支持跨任务链返回，此时在UIAbility2的界面点back键，会回到UIAbility1的界面。
