# DataAbilityOperation

The **DataAbilityOperation** module defines the operation on DataAbilities. It can be used as an input parameter of [executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch) to specify the database operation information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name      | Template    |     Mandatory|       Description     |
| --------  | --------    | --------| --------        |
| uri   | string |      Yes   | URI of the DataAbility. Example: dataability:///com.example.xxx.xxxx. |
| type   | featureAbility.DataAbilityOperationType |      Yes   | Operation type. |
| valuesBucket?   |  rdb.ValuesBucket |      No   | Data value to set. |
| valueBackReferences?   | rdb.ValuesBucket |      No   | **ValuesBucket** object that contains a set of key-value pairs. |
| predicates?   | dataAbility.DataAbilityPredicates |      No   | Predicates to set. If no predicate is set, all data records are displayed. |
| predicatesBackReferences?   | Map\<number, number> |      No   | Back references of the predicates. |
| interrupted?   | boolean |      No   | Whether batch operations can be interrupted. |
| expectedCount?   | number |      No   | Expected number of rows to be updated or deleted. |
