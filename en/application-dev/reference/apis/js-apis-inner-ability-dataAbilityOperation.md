# DataAbilityOperation

The **DataAbilityOperation** module defines the operation on Data abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name      | Template    |     Mandatory|       Description     |
| --------  | --------    | --------| --------        |
| uri   | string |      Yes   | URI of the Data ability. Example: "dataability:///com.example.xxx.xxxx". | 
| type   | featureAbility.DataAbilityOperationType |      Yes   | Operation type. | 
| valuesBucket?   |  rdb.ValuesBucket |      No   | Data value to set. | 
| valueBackReferences?   | rdb.ValuesBucket |      No   | **ValuesBucket** object that contains a set of key-value pairs. | 
| predicates?   | dataAbility.DataAbilityPredicates |      No   | Predicates to set. If no predicate is set, all data records are displayed. | 
| predicatesBackReferences?   | Map\<number, number> |      No   | Back references of the predicates. | 
| interrupted?   | boolean |      No   | Whether batch operations can be interrupted. | 
| expectedCount?   | number |      No   | Expected number of rows to be updated or deleted. | 

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
let dataAbilityOperation = {
    uri: dataAbilityUri,
    type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
    valuesBucket: valueBucket,
    predicates: null,
    expectedCount: 1,
    PredicatesBackReferences: {},
    interrupted: true
}
let operations = [
    dataAbilityOperation
];
try {
    DAHelper.executeBatch(dataAbilityUri, operations,
        (err, data) => {
            console.log("executeBatch, data: " + JSON.stringify(data));
        }
    );
} catch (err) {
    console.error('executeBatch fail: ' + JSON.stringify(err));
}
```
