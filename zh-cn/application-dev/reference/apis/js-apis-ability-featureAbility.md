# @ohos.ability.featureAbility (FeatureAbility模块)

FeatureAbility模块提供与用户进行交互的Ability的能力，包括启动新的Ability、停止Ability、获取dataAbilityHelper对象、获取当前Ability对应的窗口，连接断连Service等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在FA模型下使用，Stage模型下需使用[UIAbility模块](js-apis-app-ability-uiAbility.md)和[UIAbilityContext模块](js-apis-inner-application-uiAbilityContext.md)。

## 使用限制

FeatureAbility模块的接口只能在Page类型的Ability中调用

## 导入模块

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void

启动新的Ability（callback形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)。

**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<number>                   | 是    | 回调函数。当启动Ability成功，err为undefined，data为0表示启动成功，data为其他表示启动失败；否则为错误对象。      |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: '',
            entities: [''],
            type: '',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri: ''
        },
    },
    (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);
        }
    }
);
```



## featureAbility.startAbility

startAbility(parameter: StartAbilityParameter): Promise\<number>

启动新的Ability（Promise形式）。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-2)。

**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise对象。返回0表示启动成功，返回其他表示启动失败。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.startAbility(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri: ''
        },
    }
).then((data) => {
    console.info(`startAbility data: ${JSON.stringify(data)}`);
});
```

## featureAbility.acquireDataAbilityHelper<sup>7+</sup>

acquireDataAbilityHelper(uri: string): DataAbilityHelper

获取dataAbilityHelper对象。

使用规则：
 - 跨应用访问dataAbility，对端应用需配置关联启动
 - 调用方应用位于后台时，使用该接口访问dataAbility需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限（基于API 8或更早版本SDK开发的应用在启动DataAbility组件时不受此限制的约束）
 - 跨应用场景下，目标dataAbility的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[dataShare.createDataShareHelper](js-apis-data-dataShare.md#datasharecreatedatasharehelper)。

**参数：**

| 参数名   | 类型     | 必填   | 说明           |
| ---- | ------ | ---- | ------------ |
| uri  | string | 是    | 表示要打开的文件的路径。 |

**返回值：**

| 类型                | 说明                              |
| ----------------- | ------------------------------- |
| [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | 用来协助其他Ability访问DataAbility的工具类。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void

启动一个Ability。Ability被启动后，有如下情况(callback形式):
 - 正常情况下可通过调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult)。


**参数：**

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability。 |
| callback  | AsyncCallback\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | 是    | 回调函数。当启动Ability成功，err为undefined，data为ability的启动结果；否则为错误对象。      |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)


**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.startAbilityForResult(
   {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri:''
        },
    },
    (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbilityForResult fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbilityForResult success, data: ${JSON.stringify(data)}`);
        }
    }
);
```

## featureAbility.startAbilityForResult<sup>7+</sup>

startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>

启动一个Ability。Ability被启动后，有如下情况(Promise形式):
 - 正常情况下可通过调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止并且返回结果给调用方。
 - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。
 - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。

使用规则：
 - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限
 - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult-2)。

**参数：**

| 参数名        | 类型                                       | 必填   | 说明            |
| --------- | ---------------------------------------- | ---- | ------------- |
| parameter | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | 是    | 表示被启动的Ability |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<[AbilityResult](js-apis-inner-ability-abilityResult.md)> | Promise对象，返回启动Ability的结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 1 | Get ability error. |
| 202 | Parameter is invalid. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.startAbilityForResult(
    {
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri:'',
            parameters:
            {
                mykey0: 1111,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'xxxxxxxxxxxxxxxxxxxxxx',
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ['aaaaaa', 'bbbbb', 'ccccccccccc'],
                mykey7: true,
            },
        },
    },
).then((data) => {
    console.info(`startAbilityForResult data: ${JSON.stringify(data)}`);
});
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)。

**参数：**

| 参数名        | 类型                              | 必填   | 说明             |
| --------- | ------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是    | 表示停止Ability之后返回的结果。 |
| callback  | AsyncCallback\<void>            | 是    | 回调函数。当停止当前Ability成功，err为undefined，否则为错误对象。      |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri:'',
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey7: true,
            }
        },
    },
    (error) => {
        console.error(`error: ${JSON.stringify(error)}`);
    }
);
```

## featureAbility.terminateSelfWithResult<sup>7+</sup>

terminateSelfWithResult(parameter: AbilityResult): Promise\<void>

停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult-1)。

**参数：**

| 参数名        | 类型                              | 必填   | 说明            |
| --------- | ------------------------------- | ---- | ------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是    | 表示停止Ability之后返回的结果 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import wantConstant from '@ohos.app.ability.wantConstant';
featureAbility.terminateSelfWithResult(
    {
        resultCode: 1,
        want:
        {
            action: 'ohos.want.action.home',
            entities: ['entity.system.home'],
            type: 'MIMETYPE',
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
            deviceId: '',
            bundleName: 'com.example.myapplication',
            /* FA模型中abilityName由package + Ability name组成 */
            abilityName: 'com.example.myapplication.secondAbility',
            uri:'',
            parameters: {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: '[1, 2, 3]',
                mykey3: 'ssssssssssssssssssssssssss',
                mykey4: [1, 15],
                mykey5: [false, true, false],
                mykey6: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],
                mykey7: true,
            }
        },
    }
).then(() => {
    console.info('==========================>terminateSelfWithResult=======================>');
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(callback: AsyncCallback\<boolean>): void

检查Ability的主窗口是否具有窗口焦点（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[on('windowEvent')](js-apis-window.md#onwindowevent10)。

**参数：**

| 参数名       | 类型                      | 必填   | 说明                                       |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback\<boolean> | 是    | 以callback的形式返回结果。<br>如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus((error, data) => {
    if (error && error.code !== 0) {
        console.error(`hasWindowFocus fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`hasWindowFocus success, data: ${JSON.stringify(data)}`);
    }
});
```

## featureAbility.hasWindowFocus<sup>7+<sup>

hasWindowFocus(): Promise\<boolean>

检查Ability的主窗口是否具有窗口焦点（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**返回值：**

| 类型                | 说明                                    |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise形式返回结果，如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.hasWindowFocus().then((data) => {
    console.info(`hasWindowFocus data: ${JSON.stringify(data)}`);
});
```

## featureAbility.getWant

getWant(callback: AsyncCallback\<Want>): void

获取要拉起的Ability对应的Want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbility.launchWant](js-apis-app-ability-uiAbility.md#属性)。

**参数：**

| 参数名       | 类型                            | 必填   | 说明        |
| -------- | ----------------------------- | ---- | --------- |
| callback | AsyncCallback\<[Want](js-apis-application-want.md)> | 是    | 以callback的形式返回want。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -106 | Call the ability interface, the return value is wrong. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getWant fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getWant success, data: ${JSON.stringify(data)}`);
    }
});
```

## featureAbility.getWant

getWant(): Promise\<Want>

获取要拉起的Ability对应的Want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbility.launchWant](js-apis-app-ability-uiAbility.md#属性)。

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| Promise\<[Want](js-apis-application-want.md)> | 以Promise的形式返回want。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -106 | Call the ability interface, the return value is wrong. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.getWant().then((data) => {
    console.info(`getWant data: ${JSON.stringify(data)}`);
});
```

## featureAbility.getContext

getContext(): Context

获取应用上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbility.context](js-apis-app-ability-uiAbility.md#属性)。

**返回值：**

| 类型      | 说明         |
| ------- | ---------- |
| Context | 返回应用程序上下文。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
context.getBundleName((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getBundleName fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getBundleName success, data: ${JSON.stringify(data)}`);
    }
});
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(callback: AsyncCallback\<void>): void

停止当前的Ability（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)。

**参数：**

| 参数名       | 类型                   | 必填   | 说明       |
| -------- | -------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是    | 以callback的形式返回停止当前Ability结果 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf(
    (error) => {
        console.error(`error: ${JSON.stringify(error)}`);
    }
)
```

## featureAbility.terminateSelf<sup>7+</sup>

terminateSelf(): Promise\<void>

停止当前的Ability（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself-1)。

**返回值：**

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
featureAbility.terminateSelf().then(() => {
    console.info('==========================>terminateSelf=======================>');
});
```

## featureAbility.connectAbility<sup>7+</sup>

connectAbility(request: Want, options:ConnectOptions): number

将当前Ability与指定的ServiceAbility进行连接。

使用规则：
 - 跨应用连接serviceAbility，对端应用需配置关联启动
 - 调用方应用位于后台时，使用该接口连接serviceAbility需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限（基于API 8或更早版本SDK开发的应用在启动ServiceAbility组件时不受此限制的约束）
 - 跨应用场景下，目标serviceAbility的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.connectAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)。

**参数：**

| 参数名      | 类型             | 必填   | 说明                    |
| ------- | -------------- | ---- | --------------------- |
| request | [Want](js-apis-application-want.md)  | 是    | 表示被连接的ServiceAbility。 |
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 是    | 表示连接回调函数。             |

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| number | 连接的ServiceAbility的ID(ID从0开始自增，每连接成功一次ID加1)。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -1   | Invalid parameter. |
| -2   | Ability not found.|
| -3   | Permission denied.|
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';

let connectId = featureAbility.connectAbility(
    {
        deviceId: '',
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`)
        },
        onFailed: (code) => {
            console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`)
        },
    },
);
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

断开与指定ServiceAbility的连接（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.disconnectAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability-1)。

**参数：**

| 参数名         | 类型                   | 必填   | 说明                      |
| ---------- | -------------------- | ---- | ----------------------- |
| connection | number               | 是    | 表示断开连接的ServiceAbility的ID。 |
| callback   | AsyncCallback\<void> | 是    | 以callback的形式返回断开连接结果                |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -105 | Type of ability is invalid. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';

let connectId = featureAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`);
        },
    },
);

featureAbility.disconnectAbility(connectId, (error) => {
    if (error && error.code !== 0) {
        console.error(`disconnectAbility fail, connectId: ${connectId}, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`disconnectAbility success， connectId: ${connectId}`);
    }
});
```

## featureAbility.disconnectAbility<sup>7+</sup>

disconnectAbility(connection: number): Promise\<void>

断开与指定ServiceAbility的连接（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[UIAbilityContext.disconnectAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability)。

**参数：**

| 参数名         | 类型     | 必填   | 说明                      |
| ---------- | ------ | ---- | ----------------------- |
| connection | number | 是    | 表示断开连接的ServiceAbility的ID。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |
| -105 | Type of ability is invalid. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)

**示例：**

```ts
import rpc from '@ohos.rpc';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

let connectId = featureAbility.connectAbility(
    {
        bundleName: 'com.ix.ServiceAbility',
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',
    },
    {
        onConnect: (element, remote) => {
            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);
        },
        onDisconnect: (element) => {
            console.log(`ConnectAbility onDisconnect element.deviceId : ${element.deviceId}`);
        },
        onFailed: (code) => {
            console.error(`featureAbilityTest ConnectAbility onFailed errCode : ${code}`);
        },
    },
);

featureAbility.disconnectAbility(connectId).then(() => {
    console.log('disconnectAbility success')
}).catch((error: BusinessError)=>{
    console.error(`featureAbilityTest result errCode : ${error.code}`);
});
```


## featureAbility.getWindow<sup>7+</sup>

getWindow(callback: AsyncCallback\<window.Window>): void

获取当前Ability对应的窗口（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[window.getLastWindow](js-apis-window.md#windowgetlastwindow9)。

**参数：**

| 参数名     | 类型                          | 必填 | 说明                          |
| -------- | ----------------------------- | ---- | ----------------------------- |
| callback | AsyncCallback\<[window.Window](js-apis-window.md#window)> | 是   | callback形式返回当前Ability对应的窗口。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export default {

  onActive() {
    console.info("onActive");
    featureAbility.getWindow((error: BusinessError, data: window.Window) => {
      if (error && error.code !== 0) {
        console.error(`getWindow fail, error: ${JSON.stringify(error)}`);
      } else {
        console.log(`getWindow success, data: ${typeof(data)}`);
      }
    });
  }
}
```

## featureAbility.getWindow<sup>7+</sup>

getWindow(): Promise\<window.Window>

获取当前Ability对应的窗口（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**说明**：本接口仅可在FA模型下使用，Stage模型下需使用[window.getLastWindow](js-apis-window.md#windowgetlastwindow9-1)。

**返回值：**

| 类型                    | 说明                          |
| ----------------------- | ----------------------------- |
| Promise\<[window.Window](js-apis-window.md#window)> | Promise形式返回当前Ability对应的窗口。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| -102 | Failed to acquire ability object. |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export default {

  onActive() {
    console.info("onActive");
    featureAbility.getWindow().then((data: window.Window) => {
        console.log(`getWindow success, data: ${typeof(data)}`);
    }).catch((error: BusinessError)=>{
        console.error(`getWindow fail, error: ${JSON.stringify(error)}`);
    });
  }
}
```

## AbilityWindowConfiguration

表示当前Ability对应的窗口配置项，使用时通过featureAbility.AbilityWindowConfiguration获取。

**示例：**

```
featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                                     | 值   | 说明                                       |
| ---------------------------------------- | ---- | ---------------------------------------- |
| WINDOW_MODE_UNDEFINED<sup>7+</sup>       | 0    | 未定义。 |
| WINDOW_MODE_FULLSCREEN<sup>7+</sup>      | 1    | 全屏。    |
| WINDOW_MODE_SPLIT_PRIMARY<sup>7+</sup>   | 100  | 屏幕如果是水平方向表示左分屏，屏幕如果是竖直方向表示上分屏。 |
| WINDOW_MODE_SPLIT_SECONDARY<sup>7+</sup> | 101  | 屏幕如果是水平方向表示右分屏，屏幕如果是竖直方向表示下分屏。 |
| WINDOW_MODE_FLOATING<sup>7+</sup>        | 102  | 悬浮窗。 |


## AbilityStartSetting

表示当前Ability对应的窗口属性，abilityStartSetting属性是一个定义为[key: string]: any的对象，key对应设定类型为：AbilityStartSetting枚举类型，value对应设定类型为：AbilityWindowConfiguration枚举类型。

使用时通过featureAbility.AbilityStartSetting获取。

**示例：**

```
featureAbility.AbilityStartSetting.BOUNDS_KEY
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                           | 值              | 说明                                       |
| ---------------------------- | --------------- | ---------------------------------------- |
| BOUNDS_KEY<sup>7+</sup>      | 'abilityBounds' | 窗口显示大小属性的参数名。 |
| WINDOW_MODE_KEY<sup>7+</sup> | 'windowMode'    | 窗口显示模式属性的参数名。|
| DISPLAY_ID_KEY<sup>7+</sup>  | 'displayId'     | 窗口显示设备ID属性的参数名。 |

## DataAbilityOperationType

表示数据的操作类型。DataAbility批量操作数据时可以通过该枚举值指定操作类型

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称                       | 值    | 说明                                       |
| ------------------------ | ---- | ---------------------------------------- |
| TYPE_INSERT<sup>7+</sup> | 1    | 插入类型。 |
| TYPE_UPDATE<sup>7+</sup> | 2    | 修改类型。 |
| TYPE_DELETE<sup>7+</sup> | 3    | 删除类型。 |
| TYPE_ASSERT<sup>7+</sup> | 4    | 声明类型。 |