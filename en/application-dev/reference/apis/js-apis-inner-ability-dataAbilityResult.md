# DataAbilityResult

The **DataAbilityResult** module defines the operation result on Data abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name      | Type |     Mandatory   |       Description  |
| --------  | --------  | --------    | --------    |
| uri?      | string    |      No   | URI of the Data ability. Example: "dataability:///com.example.xxx.xxxx". | 
| count?     | number    |      No   | Number of rows affected by the operation. | 

**Example**
```ts
import featureAbility from '@ohos.ability.featureAbility'

let dataAbilityUri = ("dataability:///com.example.myapplication.TestDataAbility");
let DAHelper;
try {
    DAHelper = featureAbility.acquireDataAbilityHelper(dataAbilityUri);
    if(DAHelper == null){
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
    let promise = DAHelper.executeBatch(dataAbilityUri, operations).then((data) => {
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
```
