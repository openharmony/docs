### FeatureAbility模块(JS端SDK接口)

#### 支持设备

| API                                                          | 手机 | 平板 | 智慧屏 | 智能穿戴 | 轻量级智能穿戴 | 智慧视觉设备 |
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- | -------------- | ------------ |
| FeatureAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.startAbility(parameter: StartAbilityParameter) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.acquireDataAbilityHelper(uri: string)         | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.terminateSelfWithResult(parameter: AbilityResult) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.hasWindowFocus(callback: AsyncCallback\<boolean>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.hasWindowFocus()                              | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.getWant(callback: AsyncCallback\<Want>)       | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.getWant()                                     | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.getContext()                                  | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.terminateSelf(callback: AsyncCallback\<void>) | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |
| FeatureAbility.terminateSelf()                               | 支持 | 支持 | 支持   | 支持     | 不支持         | 不支持       |

#### 权限列表

ohos.permission.RUNNING_LOCK permission

#### 使用限制

FeatureAbility模块的接口只能在Page类型的Ability调用

#### 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```

#### FeatureAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>)

* 接口说明

  启动新的ability(callback形式)

* startAbility参数描述

| 名称      | 读写属性 | 类型                  | 必填 | 描述                |
| --------- | -------- | --------------------- | ---- | ------------------- |
| parameter | 只读     | StartAbilityParameter | 是   | 表示被启动的Ability |
| callback  | 只读     | AsyncCallback         | 是   | 被指定的回调方法    |

- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility(
        {
        want:
        {
            action: "",
            entities: [""],
            type: "",
           	flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    },
  );
)
```



#### FeatureAbility.startAbility(parameter: StartAbilityParameter)

* 接口说明

  启动新的ability(Promise形式)

* startAbility参数描述

| 名称      | 读写属性 | 类型                  | 必填 | 描述                |
| --------- | -------- | --------------------- | ---- | ------------------- |
| parameter | 只读     | StartAbilityParameter | 是   | 表示被启动的Ability |

- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
			flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.startability",
            abilityName: "com.example.startability.MainAbility",
            uri: ""
        },
    }
   ).then((void) => {
	console.info("==========================>startAbility=======================>");
});
```



#### FeatureAbility.acquireDataAbilityHelper(uri: string)

* 接口说明

  获取dataAbilityHelper

* 参数描述

  | 名称 | 读写属性 | 类型   | 必填 | 描述                   |
  | ---- | -------- | ------ | ---- | ---------------------- |
  | uri  | 只读     | string | 是   | 指示要打开的文件的路径 |

* 返回值

  返回dataAbilityHelper

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.acquireDataAbilityHelper(
    "dataability:///com.exmaple.DataAbility"
)
```



#### FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>)  

* 接口说明

  启动一个ability，并在该ability被销毁时返回执行结果(callback形式)

* startAbility参数描述

| 名称      | 读写属性 | 类型                   | 必填 | 描述                |
| --------- | -------- | ---------------------- | ---- | ------------------- |
| parameter | 只读     | StartAbilityParameter  | 是   | 表示被启动的Ability |
| callback  | 只读     | AsyncCallback\<number> | 是   | 被指定的回调方法    |

- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  返回{@link AbilityResult}

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.startabilityforresulttest1.MainAbility",
            uri:""
        },
    },
)
```



#### FeatureAbility.startAbilityForResult(parameter: StartAbilityParameter)  

* 接口说明

  启动一个ability，并在该ability被销毁时返回执行结果(Promise形式)

* startAbility参数描述

| 名称      | 读写属性 | 类型                  | 必填 | 描述                |
| --------- | -------- | --------------------- | ---- | ------------------- |
| parameter | 只读     | StartAbilityParameter | 是   | 表示被启动的Ability |

- StartAbilityParameter类型说明

| 名称                | 读写属性 | 类型   | 必填 | 描述                               |
| ------------------- | -------- | ------ | ---- | ---------------------------------- |
| want                | 只读     | want   | 是   | 表示需要包含有关目标启动能力的信息 |
| abilityStartSetting | 只读     | string | 否   | 指示启动能力中使用的特殊启动设置   |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  返回{@link AbilityResult}

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.startabilityforresulttest2.MainAbility",
            uri:"",
            parameters:
            {
                mykey0: 1111,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "xxxxxxxxxxxxxxxxxxxxxx",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["aaaaaa", "bbbbb", "ccccccccccc"],
                mykey7: true,
            },
        },
        requestCode: 2,
    },
).then((void) => {
    console.info("==========================>startAbilityForResult=======================>");
});
```



#### FeatureAbility.terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>)  

* 接口说明

  设置此page ability将返回给调用者的结果代码和数据并破坏此page ability(callback形式)


* startAbility参数描述

| 名称      | 读写属性 | 类型          | 必填 | 描述                |
| --------- | -------- | ------------- | ---- | ------------------- |
| parameter | 只读     | AbilityResult | 是   | 表示被启动的Ability |
| callback  | 只读     | AsyncCallback | 是   | 被指定的回调方法    |


* AbilityResult类型说明

| 名称       | 读写属性 | 类型   | 必填 | 描述                                                         |
| ---------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| resultCode | 只读     | number | 是   | 指示销毁该能力后返回的结果代码。您可以定义结果代码来识别错误（暂不支持） |
| want       | 只读     | Want   | 否   | 指示销毁该能力后返回的数据。您可以定义返回的数据。此参数可以为null。 |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.finishwithresulttest1.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    },
);
```



#### FeatureAbility.terminateSelfWithResult(parameter: AbilityResult)

* 接口说明

  设置此page ability将返回给调用者的结果代码和数据并破坏此page ability(Promise形式)

* startAbility参数描述

| 名称      | 读写属性 | 类型          | 必填 | 描述                |
| --------- | -------- | ------------- | ---- | ------------------- |
| parameter | 只读     | AbilityResult | 是   | 表示被启动的Ability |


* AbilityResult类型说明

| 名称       | 读写属性 | 类型   | 必填 | 描述                                                         |
| ---------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| resultCode | 只读     | number | 是   | 指示销毁该能力后返回的结果代码。您可以定义结果代码来识别错误（暂不支持） |
| want       | 只读     | Want   | 否   | 指示销毁该能力后返回的数据。您可以定义返回的数据。此参数可以为null。 |

- want类型说明

| 名称        | 读写属性 | 类型   | 必填 | 描述                       |
| ----------- | -------- | ------ | ---- | -------------------------- |
| deviceId    | 只读     | string | 否   | 设备id                     |
| bundleName  | 只读     | string | 否   | 捆绑包名称                 |
| abilityName | 只读     | string | 否   | ability 名字               |
| uri         | 只读     | string | 否   | 请求中URI的描述            |
| type        | 只读     | string | 否   | 此文件中类型的说明         |
| flags       | 只读     | number | 否   | 此文件中标志的选项是必需的 |
| action      | 只读     | string | 否   | 需求中对操作的描述         |
| parameters  | 只读     | string | 否   | Want中WantParams对象的描述 |
| entities    | 只读     | string | 否   | 对象中实体的描述           |

* flags类型说明

  | 名称                                 | 参数       | 描述                                                         |
  | ------------------------------------ | ---------- | ------------------------------------------------------------ |
  | FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权                                  |
  | FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权                                  |
  | FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给源异能                                           |
  | FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备                 |
  | FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否不属于OHOS                                       |
  | FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力                                         |
  | FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权                                    |
  | FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 将结果返回到源能力片                                         |
  | FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动                             |
  | FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能   |
  | FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示延续是可逆的。                                           |
  | FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能                           |
  | FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，请使用后台模式安装指定的DI功能。                 |
  | FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给{@link ohos.app.Context#startAbility}的{@code Intent}设置此标志，并且必须与{@link flag_ABILITY_NEW_MISSION}一起使用 |
  | FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                         |
  | FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: "action.system.home",
            entities: ["entity.system.home"],
            type: "MIMETYPE",
            flags: FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: "",
            bundleName: "com.example.featureabilitytest",
            abilityName: "com.example.finishwithresulttest1.MainAbility",
            uri:"",
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey7: true,
            }
        },
    }
).then((void) => {
		console.info("==========================>terminateSelfWithResult=======================>");
});
```



#### FeatureAbility.hasWindowFocus(callback: AsyncCallback\<boolean>)  

* 接口说明

  检查ability的主窗口是否具有窗口焦点(callback形式)

* 参数描述

| 名称     | 读写属性 | 类型                    | 必填 | 描述             |
| -------- | -------- | ----------------------- | ---- | ---------------- |
| callback | 只读     | AsyncCallback\<boolean> | 是   | 被指定的回调方法 |

* 返回值

  如果此异能当前具有视窗焦点，则返回{@code true}；否则返回{@code false}

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus()
```



#### FeatureAbility.hasWindowFocus()  

* 接口说明

  检查ability的主窗口是否具有窗口焦点(Promise形式)

* 参数描述

  Null

* 返回值

  如果此异能当前具有视窗焦点，则返回{@code true}；否则返回{@code false}

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.hasWindowFocus().then((void) => {
		console.info("==========================>hasWindowFocus=======================>");
});
```



#### FeatureAbility.getWant(callback: AsyncCallback\<Want>)  

* 接口说明

  获取从ability发送的want(callback形式)

* 参数描述

| 名称     | 读写属性 | 类型                 | 必填 | 描述             |
| -------- | -------- | -------------------- | ---- | ---------------- |
| callback | 只读     | AsyncCallback\<Want> | 是   | 被指定的回调方法 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant()
```



#### FeatureAbility.getWant()

* 接口说明

  获取从ability发送的want(Promise形式)

* 参数描述

  Null

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.getWant().then((void) => {
		console.info("==========================>getWantCallBack=======================>");
});
```



#### FeatureAbility.getContext()  

* 接口说明

  获取应用程序上下文

* 返回值

  返回应用程序上下文

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
var context = featureAbility.getContext()
context.getBundleName()
```



#### FeatureAbility.terminateSelf(callback: AsyncCallback\<void>)

* 接口说明

  设置page ability返回给被调用方的结果代码和数据，并销毁此page ability(callback形式)

* 参数描述

| 名称     | 读写属性 | 类型                 | 必填 | 描述             |
| -------- | -------- | -------------------- | ---- | ---------------- |
| callback | 只读     | AsyncCallback\<void> | 是   | 被指定的回调方法 |

* 返回值

  void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf()
```



#### FeatureAbility.terminateSelf()

* 接口说明

  设置page ability返回给被调用方的结果代码和数据，并销毁此page ability(Promise形式)

* 参数描述

  Null

* 返回值

* void

* 示例

```javascript
import featureAbility from '@ohos.ability.featureability';
featureAbility.terminateSelf().then((void) => {		    console.info("==========================>terminateSelfCallBack=======================>");
});
```

#### FeatureAbility.connectAbility(*request*: Want, *options*:ConnectOptions): number

* 接口说明

  将当前ability连接到指定ServiceAbility(callback形式)

* connectAbility参数描述

| 名称    | 读写属性 | 类型           | 必填 | 描述                       |
| ------- | -------- | -------------- | ---- | -------------------------- |
| request | 只读     | Want           | 是   | 表示被连接的ServiceAbility |
| options | 只读     | ConnectOptions | 是   | 被指定的回调方法           |

- ConnectOptions类型说明

| 名称         | 读写属性 | 类型     | 必填 | 描述                               |
| ------------ | -------- | -------- | ---- | ---------------------------------- |
| onConnect    | 只读     | function | 是   | 连接成功时的回调函数               |
| onDisconnect | 只读     | function | 是   | 连接失败时的回调函数               |
| onFailed     | 只读     | function | 是   | ConnectAbility调用失败时的回调函数 |

* 返回值

  连接的ServiceAbilityID。

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

#### FeatureAbility.disconnectAbility(connection: number, callback:AsyncCallback<void>): void

* 接口说明

  断开与指定ServiceAbility的连接(callback形式)

* disconnectAbility参数描述

| 名称       | 读写属性 | 类型          | 必填 | 描述                           |
| ---------- | -------- | ------------- | ---- | ------------------------------ |
| connection | 只读     | number        | 是   | 指定断开连接的ServiceAbilityID |
| callback   | 只读     | AsyncCallback | 是   | 被指定的回调方法               |

* 返回值

  无

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = featureAbility.disconnectAbility(connId,
    (error,data) => {
    console.log('featureAbilityTest DisConnectJsSameBundleName result errCode : ' + error.code + " data: " + data)
    },
);
```

#### FeatureAbility.disconnectAbility(connection: number): Promise<void>;

* 接口说明

  断开与指定ServiceAbility的连接(promise形式)

* disconnectAbility参数描述

| 名称       | 读写属性 | 类型   | 必填 | 描述                           |
| ---------- | -------- | ------ | ---- | ------------------------------ |
| connection | 只读     | number | 是   | 指定断开连接的ServiceAbilityID |

* 返回值

  无

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
var mRemote;
var connId;
function onConnectCallback(element, remote){
    mRemote = remote;
    console.log('ConnectAbility onConnect remote is proxy:' + (remote instanceof rpc.RemoteProxy));
}
function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect element.deviceId : ' + element.deviceId)
}
function onFailedCallback(code){
    console.log('featureAbilityTest ConnectAbility onFailed errCode : ' + code)
}
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.ix.ServiceAbility",
        abilityName: "ServiceAbilityA",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
var result = await featureAbility.disconnectAbility(connId);
```

