# StartAbilityParameter

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义启动Ability参数，可以作为入参，调用[startAbility](js-apis-ability-featureAbility.md#featureabilitystartability)启动指定的Ability。

> **说明：**
> 
> 本接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 此接口仅可在FA模型下使用。

## 导入模块

```ts
import ability from '@ohos.ability.ability';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

| 名称               |   类型   | 必填   | 说明                                    |
| ------------------- | -------- | ---- | -------------------------------------- |
| want                | [Want](js-apis-app-ability-want.md)|   是   | 启动Ability的want信息。                     |
| abilityStartSetting | { [key: string]: any } | 否    | 启动Ability的特殊属性，当开发者启动Ability时，该属性可以作为调用中的输入参数传递。 |
| abilityStartSettings<sup>11+<sup> | Record\<string, Object> | 否    | 启动Ability的特殊属性，当开发者启动Ability时，该属性可以作为调用中的输入参数传递。推荐使用该属性替代abilityStartSetting，设置该属性后，abilityStartSetting不再生效。 |

**示例：**

<!--code_no_check_fa-->
```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';

let want: Want = {
    bundleName: 'com.example.abilityStartSettingApp2',
    abilityName: 'com.example.abilityStartSettingApp.EntryAbility',
};

let startAbilityParameter: ability.StartAbilityParameter = {
    want : want,
    abilityStartSettings : {
        abilityBounds : [100,200,300,400],
        windowMode :
        featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED,
        displayId : 1,
    }
};

try {
    featureAbility.startAbility(startAbilityParameter, (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);
        }
    });
} catch(error) {
    console.error(`startAbility error: ${JSON.stringify(error)}`);
}
```