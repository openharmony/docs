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

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name     | Template    | Read Only| Optional | Description      |
| --------- | -------- |-----| ------| ---------- |
| uri   | string | No |  No  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'. |
| type   | [featureAbility.DataAbilityOperationType](js-apis-ability-featureAbility.md#dataabilityoperationtype7) | No | No  | Operation type. |
| valuesBucket   |  [rdb.ValuesBucket](../apis-arkdata/js-apis-data-relationalStore.md#valuesbucket) | No | Yes   | Data value to set. |
| valueBackReferences   | [rdb.ValuesBucket](../apis-arkdata/js-apis-data-relationalStore.md#valuesbucket) | No | Yes   | **ValuesBucket** object that contains a set of key-value pairs. |
| predicates   | [dataAbility.DataAbilityPredicates](../apis-arkdata/js-apis-data-ability.md#dataabilitypredicates) | No | Yes  | Predicates to set. If no predicate is set, all data records are displayed. |
| predicatesBackReferences   | Map\<number, number> | No | Yes   | Back references of the predicates. |
| interrupted   | boolean | No | Yes   | Whether batch operations can be interrupted. |
| expectedCount   | number | No | Yes   | Expected number of rows to be updated or deleted. |
