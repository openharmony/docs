# 分布式数据对象变更说明

## cl.distributeddatamgr.1 deleteRdbStore行为变更

**访问级别**

公开接口

**变更原因**

删除数据库后，仍能通过句柄执行增加、删除、查询及恢复操作，且不返回错误码，导致无法感知数据库已被删除。

**变更影响**

创建数据库之后正常使用，删除该数据库之后需要重新创建再使用，不能操作已经删除的数据库。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony 5.1.0.56开始。

**变更的接口/组件**

deleteRdbStore/关系型数据管理（relational_store）

**示例代码**

在调用deleteRdbStore之后，如果使用此数据库进行增删改查备份，则将返回错误码（数据库已关闭），可以按照返回的错误码进行处理，删库之后可以重新建库使用。

```ts
	import { relationalStore } from '@kit.ArkData';
    import { featureAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let store: relationalStore.RdbStore | undefined = undefined;
    let context = featureAbility.getContext();

	const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
		"name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
	const STORE_CONFIG = {
		name: "rdbstore.db",
		securityLevel: relationalStore.SecurityLevel.S3,
	}

	let store = await relationalStore.getRdbStore(context, STORE_CONFIG);
	await store.executeSql(CREATE_TABLE_TEST);
	await relationalStore.deleteRdbStore(context, "rdbstore.db");

    try {
        var u8 = new Uint8Array([1, 2, 3])
        {
            const valueBucket = {
                "name": "zhangsan",
                "age": 18,
                "salary": 100.5,
                "blobType": u8,
            }
            await store.insert("test", valueBucket)
        }
    } catch (err) {
		console.error(`Insert failed, error code: ${err.code}, message: ${err.message}.`)
    }
    store = null;
```