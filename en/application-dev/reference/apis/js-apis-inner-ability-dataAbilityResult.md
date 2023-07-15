# DataAbilityResult

The **DataAbilityResult** module defines the operation result on DataAbilities. When you call [executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch) to operate the database, the operation result is returned through the **DataAbilityResult** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name      | Type |     Mandatory   |       Description  |
| --------  | --------  | --------    | --------    |
| uri?      | string    |      No   | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'. |
| count?     | number    |      No   | Number of rows affected by the operation. |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

// Perform database operations in batches.
function executeBatchOperation() {
    let dataAbilityUri = ('dataability:///com.example.myapplication.TestDataAbility');
    let DAHelper: ability.DataAbilityHelper;
    try {
        DAHelper = featureAbility.acquireDataAbilityHelper(dataAbilityUri);
        if (DAHelper === null) {
            console.error('DAHelper is null');
        }
    } catch (err) {
        console.error('acquireDataAbilityHelper fail, error: ${JSON.stringify(err)}');
    }

    let valueBucket = {
        'name': 'DataAbilityHelperTest',
        'age': 24,
        'salary': 2024.20,
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
                let dataAbilityResult: ability.DataAbilityResult = data[i];
                console.log('dataAbilityResult.uri: ${dataAbilityResult.uri}');
                console.log('dataAbilityResult.count: ${dataAbilityResult.count}');
            }
        }).catch(err => {
            console.error('executeBatch error: ${JSON.stringify(err)}');
        });
    } catch (err) {
        console.error('executeBatch error: ${JSON.stringify(err)}');
    }
}
```
