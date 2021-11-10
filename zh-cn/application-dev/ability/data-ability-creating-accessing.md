# 基于Native的Data Ability创建与访问

## Data Ability基本概念
通过Ability派生出的DataAbility类（以下简称“Data”）,有助于应用管理其自身和其他应用存储数据的访问，并提供与其他应用共享数据的方法。Data既可用于同设备不同应用的数据共享，也支持跨设备不同应用的数据共享。

## 创建Data
### 1. Data子系统实现
1. 基于Native的Data子系统,需要继承Ability类,成为Ability的派生类来实现功能
2. 需要实现父类中Insert,Query,Update,Delete接口的业务内容.保证能够满足数据库存储业务的基本需求.BatchInsert与ExecuteBatch接口已经在系统中实现遍历逻辑,依赖Insert,Query,Update,Delete接口逻辑,来实现数据的批量处理.
3. 使用REGISTER_AA宏将Data的类名注册到系统服务中


### 2. 子系统配置

| Json重要字段  | 备注说明                                                     |
| ------------- | ------------------------------------------------------------ |
| "name"        | Ability名子,对应Ability派生的Data类名                        |
| "type"        | Ability类型,Data对应的Ability类型未"data"                    |
| "uri"         | 通信使用的URI                                                |
| "srcLanguage" | Data实现语言,c++实现的Data填写c++, js实现的Data填写js        |
| "visible"     | 对其他应用是否可见, 设置为true时, Data才能与其他应用进行通信传输数据 |

**config.json配置样例**

```json
"abilities":[{
    "name": ".DataAbility",
    "icon": "$media:snowball",
    "label": "Data Firs Ability",
    "launchType": "standard",
    "orientation": "unspecified",
    "type": "data",
    "uri": "dataability://com.ix.DataAbility",
    "srcLanguage": "c++",
    "visible": true
}]
```

## 访问Data
### 1 JS应用开发前准备
基础依赖包:
    1. @ohos.ability.featureAbility
    2. @ohos.data.dataability
    3. @ohos.data.rdb
与Data子系统通信的Uri字符串

### 2 JS应用开发接口
工具接口类对象创建
```js
// 作为参数传递的Uri,与config中定义的Uri的区别是多了一个"/",是因为作为参数传递的uri中,在第二个与第三个"/"中间,存在一个DeviceID的参数
var urivar = "dataability:///com.ix.DataAbility"
var DAHelper = featureAbility.acquireDataAbilityHelper(
    urivar
);
```
数据库相关的rdb数据构建
```js
var valuesBucket = {"name": "gaolu"}
var da = new ohos_data_ability.DataAbilityPredicates()
var valArray =new Array("value1");
var cars = new Array({"batchInsert1" : "value1",});
```
向指定的Data子系统插入数据,inster调用
```js
// callbacke方式调用:
DAHelper.insert(
    urivar,
    valuesBucket,
    (error, data) => {
        expect(typeof(data)).assertEqual("number")
    }
);
// promise方式调用:
var datainsert = await DAHelper.insert(
    urivar,
    valuesBucket
);
```
删除Data子系统中指定的数据, delete调用
```js
// callbacke方式调用:
DAHelper.delete(
    urivar,
    da,
    (error, data) => {
        expect(typeof(data)).assertEqual("number")
    }
);
// promise方式调用:
var datadelete = await DAHelper.delete(
    urivar,
    da,
);
```
更新指定Data子系统中的数据, update调用
```js
// callbacke方式调用:
DAHelper.update(
    urivar
    valuesBucket,
    da,
    (error, data) => {
        expect(typeof(data)).assertEqual("number")
    }
);
// promise方式调用:
var dataupdate = await DAHelper.update(
    urivar,
    valuesBucket,
    da,
);
```
在指定的Data子系统中查找数据,query调用
```js
// callbacke方式调用:
DAHelper.query(
    urivar,
    valArray,
    da,
    (error, data) => {
        expect(typeof(data)).assertEqual("object")
    }
);
// promise方式调用:
var dataquery = await DAHelper.query(
    urivar,
    valArray,
    da
);
```
向指定的数据子系统批量插入数据,batchInsert调用
```js
// callbacke方式调用:
DAHelper.batchInsert(
    urivar,
    cars,
    (error, data) => {
        expect(typeof(data)).assertEqual("number")
    }
);
// promise方式调用:
var databatchInsert = await DAHelper.batchInsert(
    urivar,
    cars
);
```
向指定的Data子系统进行数据的批量处理,executeBatch调用
```js
// callbacke方式调用:
DAHelper.executeBatch(
    urivar,
    [
        {
            uri: urivar,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket: {"executeBatch" : "value1",},
            predicates: da,
            expectedCount:0,
            PredicatesBackReferences: {},
            interrupted:true,
        }
    ],
    (error, data) => {
        expect(typeof(data)).assertEqual("object")
    }
);
// promise方式调用:
var dataexecuteBatch = await DAHelper.executeBatch(
    urivar,
    [
        {
            uri: urivar,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket:
            {
                "executeBatch" : "value1",
            },
            predicates: da,
            expectedCount:0,
            PredicatesBackReferences: {},
            interrupted:true,
        }
    ]
);
```

