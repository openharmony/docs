# DataAbilityOperation

定义dataAbility数据操作方式，可以作为[executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch)的入参查询数据库的信息。

> **说明：**
> 
> 本接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本接口仅可在FA模型下使用

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称       | 类型     |     必填|       说明      |
| --------  | --------    | --------| --------        |
| uri   | string |      是    | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"。  |
| type   | featureAbility.DataAbilityOperationType |      是    | 指示操作类型。  |
| valuesBucket?   |  rdb.ValuesBucket |      否    | 指示要设置的数据值。  |
| valueBackReferences?   | rdb.ValuesBucket |      否    | 指示包含一组键值对的valuesBucket对象。  |
| predicates?   | dataAbility.DataAbilityPredicates |      否    | 指示要设置的筛选条件。如果此参数为空，则所有数据记录。  |
| predicatesBackReferences?   | Map\<number, number> |      否    | 指示用作谓词中筛选条件的反向引用。  |
| interrupted?   | boolean |      否    | 指定是否可以中断批处理操作。  |
| expectedCount?   | number |      否    | 指示要更新或删除的预期行数。  |
