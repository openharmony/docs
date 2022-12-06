# DataAbilityOperation

定义dataAbility数据操作方式。

> **说明：**
> 
> 本接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本接口仅可在FA模型下使用

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.FAModel

| 名称       | 类型     | 可读    |   可写    |     必填|       说明      |
| --------  | --------    | -------- | -------- | --------| --------        |
| uri   | string | 是      |     否    |      是    | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"。  | 
| type   | featureAbility.DataAbilityOperationType | 是      |     否    |      是    | 指示操作类型。  | 
| valuesBucket?   |  rdb.ValuesBucket | 是      |     否    |      否    | 指示要设置的数据值。  | 
| valueBackReferences?   | rdb.ValuesBucket | 是      |     否    |      否    | 指示包含一组键值对的valuesBucket对象。  | 
| predicates?   | dataAbility.DataAbilityPredicates | 是      |     否    |      否    | 指示要设置的筛选条件。如果此参数为空，则所有数据记录。  | 
| predicatesBackReferences?   | Map\<number, number> | 是      |     否    |      否    | 指示用作谓词中筛选条件的反向引用。  | 
| interrupted?   | boolean | 是      |     否    |      否    | 指定是否可以中断批处理操作。  | 
| expectedCount?   | number | 是      |     否    |      否    | 指示要更新或删除的预期行数。  | 

**示例：**
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