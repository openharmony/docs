# DataAbilityResult
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module defines the operation result on DataAbilities. When you call [executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch) to operate the database, the operation result is returned through the DataAbilityResult object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name     | Type | Read Only | Optional   |       Description  |
| -------- | -------- | -------- | -------- | -------- |
| uri      | string    | No | Yes   | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'. |
| count     | number   | No | Yes   | Number of rows affected by the operation. |

**Example**

<!--code_no_check_fa-->
```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';
import { BusinessError } from '@ohos.base';

// Perform database operations in batches.
function executeBatchOperation() {
    let dataAbilityUri = ('dataability:///com.example.myapplication.TestDataAbility');
    let DAHelper: ability.DataAbilityHelper;
    DAHelper = featureAbility.acquireDataAbilityHelper(dataAbilityUri);

    let valueBucket: rdb.ValuesBucket = {
        'name': 'DataAbilityHelperTest',
        'age': 24,
        'salary': 2024.20,
    };
    let predicateBackReferences = new Map<number, number>()
    predicateBackReferences.set(1, 1)

    let operations: Array<ability.DataAbilityOperation> = [
        {
            uri: dataAbilityUri,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket: valueBucket,
            expectedCount: 1,
            predicatesBackReferences: predicateBackReferences,
            interrupted: true,
        },
        {
            uri: dataAbilityUri,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket: valueBucket,
            expectedCount: 1,
            predicatesBackReferences: predicateBackReferences,
            interrupted: true,
        }
    ];
    try {
        DAHelper.executeBatch(dataAbilityUri, operations).then((data) => {
            for (let i = 0; i < data.length; i++) {
                let dataAbilityResult: ability.DataAbilityResult = data[i];
                console.log(`dataAbilityResult.uri: ${dataAbilityResult.uri}`);
                console.log(`dataAbilityResult.count: ${dataAbilityResult.count}`);
            }
        }).catch((err: BusinessError) => {
            console.error(`executeBatch error: ${JSON.stringify(err)}`);
        });
    } catch (err) {
        console.error(`executeBatch error: ${JSON.stringify(err as BusinessError)}`);
    }
}
```
