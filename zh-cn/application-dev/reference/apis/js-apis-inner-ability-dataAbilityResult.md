# DataAbilityResult

定义DataAbility数据操作结果，通过[executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch)操作数据库时，操作结果使用DataAbilityResult对象返回。

> **说明：**
> 
> 本接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本接口仅可在FA模型下使用

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称       | 类型  |     必填    |       说明   |
| --------  | --------  | --------    | --------    |
| uri?      | string    |      否    | 指示待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"。  |
| count?     | number    |      否    | 指示受操作影响的数据数量。  |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'

// 批量执行数据库操作
function executeBatchOperation() {
    let dataAbilityUri = ("dataability:///com.example.myapplication.TestDataAbility");
    let DAHelper;
    try {
        DAHelper = featureAbility.acquireDataAbilityHelper(dataAbilityUri);
        if (DAHelper == null) {
            console.error('DAHelper is null');
            return;
        }
    } catch (err) {
        console.error('acquireDataAbilityHelper fail, error:' + JSON.stringify(err));
        return;
    }

    let valueBucket = {
        "name": "DataAbilityHelperTest",
        "age": 24,
        "salary": 2024.20,
    };
    let operations = [
    {
        uri: dataAbilityUri,
        type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
        valuesBucket: valueBucket,
        predicates: null,
        expectedCount: 1,
        PredicatesBackReferences: {},
        interrupted: true,
    },
    {
        uri: dataAbilityUri,
        type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
        valuesBucket: valueBucket,
        predicates: null,
        expectedCount: 1,
        PredicatesBackReferences: {},
        interrupted: true,
    }
    ];

    try {
        DAHelper.executeBatch(dataAbilityUri, operations).then((data) => {
            for (let i = 0; i < data.length; i++) {
                let dataAbilityResult = data[i];
                console.log('dataAbilityResult.uri: ' + dataAbilityResult.uri);
                console.log('dataAbilityResult.count: ' + dataAbilityResult.count);
            }
        }).catch(err => {
            console.error('executeBatch error: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.error('executeBatch error: ' + JSON.stringify(err));
    }
}
```