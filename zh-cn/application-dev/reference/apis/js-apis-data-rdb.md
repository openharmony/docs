# 关系型数据库<a name="ZH-CN_TOPIC_0000001200552329"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import dataRdb from '@ohos.data.rdb'
```

## 权限<a name="section11257113618419"></a>

无

## dataRdb.getRdbStore<a name="section82751028152316"></a>

getRdbStore\(config: StoreConfig, version: number, callback: AsyncCallback<RdbStore\>\): void

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，结果以callback形式返回。

-   参数：

    <a name="table653684215178"></a>
    <table><thead align="left"><tr id="row45374426171"><th class="cellrowborder" valign="top" width="9.683081423695757%" id="mcps1.1.5.1.1"><p id="p17537742181710"><a name="p17537742181710"></a><a name="p17537742181710"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.19015114578254%" id="mcps1.1.5.1.2"><p id="p1153744217173"><a name="p1153744217173"></a><a name="p1153744217173"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.511945392491468%" id="mcps1.1.5.1.3"><p id="p853710422172"><a name="p853710422172"></a><a name="p853710422172"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.614822038030226%" id="mcps1.1.5.1.4"><p id="p14537124220176"><a name="p14537124220176"></a><a name="p14537124220176"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row175381421178"><td class="cellrowborder" valign="top" width="9.683081423695757%" headers="mcps1.1.5.1.1 "><p id="p1453824231712"><a name="p1453824231712"></a><a name="p1453824231712"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.19015114578254%" headers="mcps1.1.5.1.2 "><p id="p1453811421177"><a name="p1453811421177"></a><a name="p1453811421177"></a><a href="#section957124521217">StoreConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p4538642151718"><a name="p4538642151718"></a><a name="p4538642151718"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p617319414272"><a name="p617319414272"></a><a name="p617319414272"></a>与此RDB存储相关的数据库配置。</p>
    </td>
    </tr>
    <tr id="row9983554191710"><td class="cellrowborder" valign="top" width="9.683081423695757%" headers="mcps1.1.5.1.1 "><p id="p19984454131717"><a name="p19984454131717"></a><a name="p19984454131717"></a>version</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.19015114578254%" headers="mcps1.1.5.1.2 "><p id="p19841654101713"><a name="p19841654101713"></a><a name="p19841654101713"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p18984054191711"><a name="p18984054191711"></a><a name="p18984054191711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p137741846122912"><a name="p137741846122912"></a><a name="p137741846122912"></a>数据库版本。</p>
    </td>
    </tr>
    <tr id="row653884220176"><td class="cellrowborder" valign="top" width="9.683081423695757%" headers="mcps1.1.5.1.1 "><p id="p4538154261718"><a name="p4538154261718"></a><a name="p4538154261718"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.19015114578254%" headers="mcps1.1.5.1.2 "><p id="p568519206182"><a name="p568519206182"></a><a name="p568519206182"></a>AsyncCallback&lt;<a href="#section12882825611">RdbStore</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p653934231718"><a name="p653934231718"></a><a name="p653934231718"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p9351151163112"><a name="p9351151163112"></a><a name="p9351151163112"></a>指定callback回调函数。返回一个RdbStore。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import dataRdb from '@ohos.data.rdb'
    const STORE_CONFIG = { name: "RdbTest.db" }
    const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
    dataRdb.getRdbStore(STORE_CONFIG, 1, function (err, rdbStore) {
        rdbStore.executeSql(SQL_CREATE_TABLE)
        console.info(TAG + 'create table done.')
    })
    ```


## dataRdb.getRdbStore<a name="section192192415554"></a>

getRdbStore\(config: StoreConfig, version: number\): Promise<RdbStore\>

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，结果以Promise形式返回。

-   参数：

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.42174549000487%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.511945392491468%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.614822038030226%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row128961021101812"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p2090415317487"><a name="p2090415317487"></a><a name="p2090415317487"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p17904153117480"><a name="p17904153117480"></a><a name="p17904153117480"></a><a href="#section957124521217">StoreConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p5905133144817"><a name="p5905133144817"></a><a name="p5905133144817"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p1490513144814"><a name="p1490513144814"></a><a name="p1490513144814"></a>与此RDB存储相关的数据库配置。</p>
    </td>
    </tr>
    <tr id="row12616141914811"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1685515371486"><a name="p1685515371486"></a><a name="p1685515371486"></a>version</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p16855193784819"><a name="p16855193784819"></a><a name="p16855193784819"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p6856237154816"><a name="p6856237154816"></a><a name="p6856237154816"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p38563374484"><a name="p38563374484"></a><a name="p38563374484"></a>数据库版本。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table10367840172411"></a>
    <table><thead align="left"><tr id="row9367340162416"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p03671240162419"><a name="p03671240162419"></a><a name="p03671240162419"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p2367104002411"><a name="p2367104002411"></a><a name="p2367104002411"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row436714014242"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1897255913242"><a name="p1897255913242"></a><a name="p1897255913242"></a>Promise&lt;<a href="#section12882825611">RdbStore</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p9368840152411"><a name="p9368840152411"></a><a name="p9368840152411"></a>指定Promise回调函数。返回一个RdbStore。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import dataRdb from '@ohos.data.rdb'
    const STORE_CONFIG = { name: "RdbTest.db" }
    const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
    let promise = dataRdb.getRdbStore(STORE_CONFIG, 1);
    promise.then(async (rdbStore) => {
        await rdbStore.executeSql(SQL_CREATE_TABLE, null)
    }).catch((err) => {
        expect(null).assertFail();
    })
    ```


## dataRdb.deleteRdbStore<a name="section761705115251"></a>

deleteRdbStore\(name: string, callback: AsyncCallback<void\>\): void

删除数据库，结果以callback形式返回。

-   参数：

    <a name="table206180511253"></a>
    <table><thead align="left"><tr id="row126181951152513"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p20618155112513"><a name="p20618155112513"></a><a name="p20618155112513"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.349585568015602%" id="mcps1.1.5.1.2"><p id="p561885114256"><a name="p561885114256"></a><a name="p561885114256"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.838127742564602%" id="mcps1.1.5.1.3"><p id="p561814519259"><a name="p561814519259"></a><a name="p561814519259"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.360799609946355%" id="mcps1.1.5.1.4"><p id="p1861845120252"><a name="p1861845120252"></a><a name="p1861845120252"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18274185435020"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p196192514253"><a name="p196192514253"></a><a name="p196192514253"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.349585568015602%" headers="mcps1.1.5.1.2 "><p id="p36191951162515"><a name="p36191951162515"></a><a name="p36191951162515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.838127742564602%" headers="mcps1.1.5.1.3 "><p id="p16191051162511"><a name="p16191051162511"></a><a name="p16191051162511"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.360799609946355%" headers="mcps1.1.5.1.4 "><p id="p7722105418272"><a name="p7722105418272"></a><a name="p7722105418272"></a>数据库名称。</p>
    </td>
    </tr>
    <tr id="row13472173272720"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14473193219278"><a name="p14473193219278"></a><a name="p14473193219278"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.349585568015602%" headers="mcps1.1.5.1.2 "><p id="p2473113272718"><a name="p2473113272718"></a><a name="p2473113272718"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.838127742564602%" headers="mcps1.1.5.1.3 "><p id="p164731732182719"><a name="p164731732182719"></a><a name="p164731732182719"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.360799609946355%" headers="mcps1.1.5.1.4 "><p id="p3473123212716"><a name="p3473123212716"></a><a name="p3473123212716"></a>指定callback回调函数。如果数据库已删除，则为true；否则返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import dataRdb from '@ohos.data.rdb'
    dataRdb.deleteRdbStore("RdbTest.db", function (err, rdbStore) {
        console.info(TAG + 'delete store done.')})
    ```


## dataRdb.deleteRdbStore<a name="section1396463815379"></a>

deleteRdbStore\(name: string\): Promise<void\>

使用指定的数据库文件配置删除数据库，结果以Promise形式返回。

-   参数：

    <a name="table99651538193711"></a>
    <table><thead align="left"><tr id="row1296553843712"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19965183833714"><a name="p19965183833714"></a><a name="p19965183833714"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p9965153863713"><a name="p9965153863713"></a><a name="p9965153863713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15965133819375"><a name="p15965133819375"></a><a name="p15965133819375"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p496518383377"><a name="p496518383377"></a><a name="p496518383377"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6965238143718"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p18965163816378"><a name="p18965163816378"></a><a name="p18965163816378"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10965193816372"><a name="p10965193816372"></a><a name="p10965193816372"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p896623833719"><a name="p896623833719"></a><a name="p896623833719"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p157012058162714"><a name="p157012058162714"></a><a name="p157012058162714"></a>数据库名称。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table2917135992918"></a>
    <table><thead align="left"><tr id="row3917165913293"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p59172595299"><a name="p59172595299"></a><a name="p59172595299"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1791795932915"><a name="p1791795932915"></a><a name="p1791795932915"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row891715914297"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p199181659172914"><a name="p199181659172914"></a><a name="p199181659172914"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p11918175962910"><a name="p11918175962910"></a><a name="p11918175962910"></a>指定Promise回调函数。如果数据库已删除，则为true；否则返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import dataRdb from '@ohos.data.rdb'
    let promise = dataRdb.deleteRdbStore("RdbTest.db")
    promise.then(()=>{
        console.info(TAG + 'delete store done.')
    })
    ```


## RdbPredicates<a name="section3101161234310"></a>

表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。

### constructor<a name="section984214450519"></a>

constructor\(name: string\)

构造函数。

-   参数：

    <a name="table294919502505"></a>
    <table><thead align="left"><tr id="row1795065017500"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p295025085011"><a name="p295025085011"></a><a name="p295025085011"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p895010503503"><a name="p895010503503"></a><a name="p895010503503"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p995011508505"><a name="p995011508505"></a><a name="p995011508505"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p17953155005010"><a name="p17953155005010"></a><a name="p17953155005010"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0953125025017"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14953175025014"><a name="p14953175025014"></a><a name="p14953175025014"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p39531450175018"><a name="p39531450175018"></a><a name="p39531450175018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19953145045014"><a name="p19953145045014"></a><a name="p19953145045014"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p795335045012"><a name="p795335045012"></a><a name="p795335045012"></a>数据库表名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import dataRdb from '@ohos.data.rdb'
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    ```


### equalTo<a name="section81306545314"></a>

equalTo\(field: string, value: ValueType\): RdbPredicates

配置谓词以匹配数据字段为ValueType且值等于指定值的字段。

-   参数：

    <a name="table199461128125613"></a>
    <table><thead align="left"><tr id="row1794762812569"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8947128125618"><a name="p8947128125618"></a><a name="p8947128125618"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p199472028175610"><a name="p199472028175610"></a><a name="p199472028175610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p69475284563"><a name="p69475284563"></a><a name="p69475284563"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p7948152819564"><a name="p7948152819564"></a><a name="p7948152819564"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row159484286561"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9613184065619"><a name="p9613184065619"></a><a name="p9613184065619"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p19481828115617"><a name="p19481828115617"></a><a name="p19481828115617"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p39481528165612"><a name="p39481528165612"></a><a name="p39481528165612"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13948172810562"><a name="p13948172810562"></a><a name="p13948172810562"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row35449501565"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p5545155065620"><a name="p5545155065620"></a><a name="p5545155065620"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1454575075612"><a name="p1454575075612"></a><a name="p1454575075612"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p165455508567"><a name="p165455508567"></a><a name="p165455508567"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p354665035618"><a name="p354665035618"></a><a name="p354665035618"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table051813246573"></a>
    <table><thead align="left"><tr id="row8518724125714"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p65186247578"><a name="p65186247578"></a><a name="p65186247578"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p65181324105720"><a name="p65181324105720"></a><a name="p65181324105720"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1151918245578"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p195244383572"><a name="p195244383572"></a><a name="p195244383572"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1551922465710"><a name="p1551922465710"></a><a name="p1551922465710"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
    ```


### notEqualTo<a name="section05401557145215"></a>

notEqualTo\(field: string, value: ValueType\): RdbPredicates

配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。

-   参数：

    <a name="table17531173816514"></a>
    <table><thead align="left"><tr id="row953113819510"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8531838659"><a name="p8531838659"></a><a name="p8531838659"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p553112388513"><a name="p553112388513"></a><a name="p553112388513"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p6531133810511"><a name="p6531133810511"></a><a name="p6531133810511"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1853293814512"><a name="p1853293814512"></a><a name="p1853293814512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1053213388510"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14532153810516"><a name="p14532153810516"></a><a name="p14532153810516"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p195322380510"><a name="p195322380510"></a><a name="p195322380510"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p3532103816512"><a name="p3532103816512"></a><a name="p3532103816512"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p16532133810511"><a name="p16532133810511"></a><a name="p16532133810511"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row2532103810512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p105321238052"><a name="p105321238052"></a><a name="p105321238052"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15323381156"><a name="p15323381156"></a><a name="p15323381156"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p15331386514"><a name="p15331386514"></a><a name="p15331386514"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5533103820515"><a name="p5533103820515"></a><a name="p5533103820515"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table9811361768"></a>
    <table><thead align="left"><tr id="row15811961668"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p88111567612"><a name="p88111567612"></a><a name="p88111567612"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p68111661263"><a name="p68111661263"></a><a name="p68111661263"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row108111563614"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p5812667615"><a name="p5812667615"></a><a name="p5812667615"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p138121962619"><a name="p138121962619"></a><a name="p138121962619"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.notEqualTo("NAME", "lisi")
    ```


### beginWrap<a name="section568118617579"></a>

beginWrap\(\): RdbPredicates

向谓词添加左括号。

-   返回值：

    <a name="table8798182141219"></a>
    <table><thead align="left"><tr id="row1879811211210"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1879972111212"><a name="p1879972111212"></a><a name="p1879972111212"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1779932121212"><a name="p1779932121212"></a><a name="p1779932121212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row157994291219"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p8799202171212"><a name="p8799202171212"></a><a name="p8799202171212"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p177999216128"><a name="p177999216128"></a><a name="p177999216128"></a>返回带有左括号的Rdb谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
        .beginWrap()
        .equalTo("AGE", 18)
        .or()
        .equalTo("SALARY", 200.5)
        .endWrap()
    ```


### endWrap<a name="section5853135275719"></a>

endWrap\(\): RdbPredicates

向谓词添加右括号。

-   返回值：

    <a name="table1345521812144"></a>
    <table><thead align="left"><tr id="row2455201812143"><th class="cellrowborder" valign="top" width="31.19%" id="mcps1.1.3.1.1"><p id="p1045631810147"><a name="p1045631810147"></a><a name="p1045631810147"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="68.81%" id="mcps1.1.3.1.2"><p id="p245631813147"><a name="p245631813147"></a><a name="p245631813147"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1045610186147"><td class="cellrowborder" valign="top" width="31.19%" headers="mcps1.1.3.1.1 "><p id="p144569181148"><a name="p144569181148"></a><a name="p144569181148"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="68.81%" headers="mcps1.1.3.1.2 "><p id="p12457141812149"><a name="p12457141812149"></a><a name="p12457141812149"></a>返回带有右括号的Rdb谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
        .beginWrap()
        .equalTo("AGE", 18)
        .or()
        .equalTo("SALARY", 200.5)
        .endWrap()
    ```


### or<a name="section1961719301588"></a>

or\(\): RdbPredicates

将或条件添加到谓词中。

-   返回值：

    <a name="table6746132913152"></a>
    <table><thead align="left"><tr id="row1374711292154"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p574715292152"><a name="p574715292152"></a><a name="p574715292152"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p17481429111515"><a name="p17481429111515"></a><a name="p17481429111515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12748202911154"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p6748102911513"><a name="p6748102911513"></a><a name="p6748102911513"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1574882991512"><a name="p1574882991512"></a><a name="p1574882991512"></a>返回带有或条件的Rdb谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
        .or()
        .equalTo("NAME", "Rose")
    ```


### and<a name="section3715362143"></a>

and\(\): RdbPredicates

向谓词添加和条件。

-   返回值：

    <a name="table11147145951616"></a>
    <table><thead align="left"><tr id="row1914785918165"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p21471559101610"><a name="p21471559101610"></a><a name="p21471559101610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p8147175918161"><a name="p8147175918161"></a><a name="p8147175918161"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111479594161"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p18147175915168"><a name="p18147175915168"></a><a name="p18147175915168"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p13148165911612"><a name="p13148165911612"></a><a name="p13148165911612"></a>返回带有和条件的Rdb谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
        .and()
        .equalTo("SALARY", 200.5)
    ```


### contains<a name="section14363480594"></a>

contains\(field: string, value: string\): RdbPredicat

配置谓词以匹配数据字段为String且value包含指定值的字段。

-   参数：

    <a name="table99541451811"></a>
    <table><thead align="left"><tr id="row1695514191816"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p79554416187"><a name="p79554416187"></a><a name="p79554416187"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1295511491810"><a name="p1295511491810"></a><a name="p1295511491810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p119555414180"><a name="p119555414180"></a><a name="p119555414180"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p109554410181"><a name="p109554410181"></a><a name="p109554410181"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1295511416188"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p20955174111810"><a name="p20955174111810"></a><a name="p20955174111810"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1956164101819"><a name="p1956164101819"></a><a name="p1956164101819"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p199560411183"><a name="p199560411183"></a><a name="p199560411183"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1595612471811"><a name="p1595612471811"></a><a name="p1595612471811"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row7956114121815"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p695615451819"><a name="p695615451819"></a><a name="p695615451819"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p129801018122018"><a name="p129801018122018"></a><a name="p129801018122018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1957445181"><a name="p1957445181"></a><a name="p1957445181"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p595711461816"><a name="p595711461816"></a><a name="p595711461816"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table17360223196"></a>
    <table><thead align="left"><tr id="row167361522161912"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p197362022111910"><a name="p197362022111910"></a><a name="p197362022111910"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p7736722151913"><a name="p7736722151913"></a><a name="p7736722151913"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row187372229192"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17737162216194"><a name="p17737162216194"></a><a name="p17737162216194"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p773782281911"><a name="p773782281911"></a><a name="p773782281911"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.contains("NAME", "os")
    ```


### beginsWith<a name="section320518431911"></a>

beginsWith\(field: string, value: string\): RdbPredicates

配置谓词以匹配数据字段为String且值以指定字符串开头的字段。

-   参数：

    <a name="table13588185517222"></a>
    <table><thead align="left"><tr id="row858985542212"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18589555122218"><a name="p18589555122218"></a><a name="p18589555122218"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p19589255122217"><a name="p19589255122217"></a><a name="p19589255122217"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1258925512214"><a name="p1258925512214"></a><a name="p1258925512214"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1658919555225"><a name="p1658919555225"></a><a name="p1658919555225"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row959014558220"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p155906556229"><a name="p155906556229"></a><a name="p155906556229"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1659015542216"><a name="p1659015542216"></a><a name="p1659015542216"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p135905552227"><a name="p135905552227"></a><a name="p135905552227"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p35911455102217"><a name="p35911455102217"></a><a name="p35911455102217"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row459115518229"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11591175562211"><a name="p11591175562211"></a><a name="p11591175562211"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16591115514221"><a name="p16591115514221"></a><a name="p16591115514221"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p059135519222"><a name="p059135519222"></a><a name="p059135519222"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1059215555223"><a name="p1059215555223"></a><a name="p1059215555223"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table35926554222"></a>
    <table><thead align="left"><tr id="row959216553223"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1659235592214"><a name="p1659235592214"></a><a name="p1659235592214"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p3593855192215"><a name="p3593855192215"></a><a name="p3593855192215"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13593655102212"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p9593135542210"><a name="p9593135542210"></a><a name="p9593135542210"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p19594135515224"><a name="p19594135515224"></a><a name="p19594135515224"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.beginsWith("NAME", "os")
    ```


### endsWith<a name="section10321300318"></a>

endsWith\(field: string, value: string\): RdbPredicates

配置谓词以匹配数据字段为String且值以指定字符串结尾的字段。

-   参数：

    <a name="table959074252519"></a>
    <table><thead align="left"><tr id="row85911342122517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1859194292517"><a name="p1859194292517"></a><a name="p1859194292517"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1959154272515"><a name="p1959154272515"></a><a name="p1959154272515"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p359119428254"><a name="p359119428254"></a><a name="p359119428254"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p559217421253"><a name="p559217421253"></a><a name="p559217421253"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row155921242102515"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p859254222516"><a name="p859254222516"></a><a name="p859254222516"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p175921242132511"><a name="p175921242132511"></a><a name="p175921242132511"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p259244262510"><a name="p259244262510"></a><a name="p259244262510"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17593942142517"><a name="p17593942142517"></a><a name="p17593942142517"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row155936421254"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8593342102517"><a name="p8593342102517"></a><a name="p8593342102517"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4593124216259"><a name="p4593124216259"></a><a name="p4593124216259"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1594194215256"><a name="p1594194215256"></a><a name="p1594194215256"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p059434232511"><a name="p059434232511"></a><a name="p059434232511"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1659594211251"></a>
    <table><thead align="left"><tr id="row1359574213251"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p13595042142511"><a name="p13595042142511"></a><a name="p13595042142511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p7595184215257"><a name="p7595184215257"></a><a name="p7595184215257"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2595242172511"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1959684214259"><a name="p1959684214259"></a><a name="p1959684214259"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p759664212259"><a name="p759664212259"></a><a name="p759664212259"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.endsWith("NAME", "se")
    ```


### isNull<a name="section2036415371410"></a>

isNull\(field: string\): RdbPredicates

配置谓词以匹配值为null的字段。

-   参数：

    <a name="table11961102414270"></a>
    <table><thead align="left"><tr id="row8962124162717"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11962724132712"><a name="p11962724132712"></a><a name="p11962724132712"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1896392492719"><a name="p1896392492719"></a><a name="p1896392492719"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p14963424192720"><a name="p14963424192720"></a><a name="p14963424192720"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1296320244279"><a name="p1296320244279"></a><a name="p1296320244279"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11963024142713"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14964172432718"><a name="p14964172432718"></a><a name="p14964172432718"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p119642248272"><a name="p119642248272"></a><a name="p119642248272"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1996452416274"><a name="p1996452416274"></a><a name="p1996452416274"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1996411246271"><a name="p1996411246271"></a><a name="p1996411246271"></a>数据库表中的列名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1496672416277"></a>
    <table><thead align="left"><tr id="row796615244274"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p199662242279"><a name="p199662242279"></a><a name="p199662242279"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p10966172416274"><a name="p10966172416274"></a><a name="p10966172416274"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row129671724102719"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p49671324162710"><a name="p49671324162710"></a><a name="p49671324162710"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p796713249277"><a name="p796713249277"></a><a name="p796713249277"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.isNull("NAME")
    ```


### isNotNull<a name="section166151026181518"></a>

isNotNull\(field: string\): RdbPredicates

配置谓词以匹配值不为null的指定字段。

-   参数：

    <a name="table328791393015"></a>
    <table><thead align="left"><tr id="row162888138309"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1528811316306"><a name="p1528811316306"></a><a name="p1528811316306"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1428861319309"><a name="p1428861319309"></a><a name="p1428861319309"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p19288151303015"><a name="p19288151303015"></a><a name="p19288151303015"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p828913133307"><a name="p828913133307"></a><a name="p828913133307"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14289713193020"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11289131319304"><a name="p11289131319304"></a><a name="p11289131319304"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p728991363013"><a name="p728991363013"></a><a name="p728991363013"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p82902135309"><a name="p82902135309"></a><a name="p82902135309"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1529081319307"><a name="p1529081319307"></a><a name="p1529081319307"></a>数据库表中的列名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table18290101383017"></a>
    <table><thead align="left"><tr id="row1129141353017"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1629191310307"><a name="p1629191310307"></a><a name="p1629191310307"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1829131310305"><a name="p1829131310305"></a><a name="p1829131310305"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row029281323011"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17292713173018"><a name="p17292713173018"></a><a name="p17292713173018"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p15292171319302"><a name="p15292171319302"></a><a name="p15292171319302"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.isNotNull("NAME")
    ```


### like<a name="section19934205801519"></a>

like\(field: string, value: string\): RdbPredicates

配置谓词以匹配数据字段为String且值类似于指定字符串的字段。

-   参数：

    <a name="table119162123217"></a>
    <table><thead align="left"><tr id="row4101628327"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p9109211320"><a name="p9109211320"></a><a name="p9109211320"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p31014220322"><a name="p31014220322"></a><a name="p31014220322"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p191142163214"><a name="p191142163214"></a><a name="p191142163214"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p31192163210"><a name="p31192163210"></a><a name="p31192163210"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row011526322"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2011192143214"><a name="p2011192143214"></a><a name="p2011192143214"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p31211283214"><a name="p31211283214"></a><a name="p31211283214"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6127243213"><a name="p6127243213"></a><a name="p6127243213"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p201222193217"><a name="p201222193217"></a><a name="p201222193217"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row21318293214"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9134216327"><a name="p9134216327"></a><a name="p9134216327"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p131312218326"><a name="p131312218326"></a><a name="p131312218326"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7131211326"><a name="p7131211326"></a><a name="p7131211326"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1013121325"><a name="p1013121325"></a><a name="p1013121325"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table173321317173213"></a>
    <table><thead align="left"><tr id="row6333141711327"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1033351710325"><a name="p1033351710325"></a><a name="p1033351710325"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p5333161763212"><a name="p5333161763212"></a><a name="p5333161763212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row03333178323"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p183338171329"><a name="p183338171329"></a><a name="p183338171329"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p5333917133219"><a name="p5333917133219"></a><a name="p5333917133219"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.like("NAME", "%os%")
    ```


### glob<a name="section36551633121616"></a>

glob\(field: string, value: string\): RdbPredicates

配置RdbPredicates匹配数据字段为String的指定字段。

-   参数：

    <a name="table382114613515"></a>
    <table><thead align="left"><tr id="row14821134612359"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p582214613356"><a name="p582214613356"></a><a name="p582214613356"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1582212467352"><a name="p1582212467352"></a><a name="p1582212467352"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13822144683510"><a name="p13822144683510"></a><a name="p13822144683510"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p168224469351"><a name="p168224469351"></a><a name="p168224469351"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1282204613350"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1782314464352"><a name="p1782314464352"></a><a name="p1782314464352"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p182319461356"><a name="p182319461356"></a><a name="p182319461356"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p11823134643511"><a name="p11823134643511"></a><a name="p11823134643511"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p12823846193519"><a name="p12823846193519"></a><a name="p12823846193519"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row178235463355"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1082311466356"><a name="p1082311466356"></a><a name="p1082311466356"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p98241546123512"><a name="p98241546123512"></a><a name="p98241546123512"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1682444643518"><a name="p1682444643518"></a><a name="p1682444643518"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4824134683515"><a name="p4824134683515"></a><a name="p4824134683515"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table17824346153511"></a>
    <table><thead align="left"><tr id="row782554613353"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p182514610359"><a name="p182514610359"></a><a name="p182514610359"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1382519467358"><a name="p1382519467358"></a><a name="p1382519467358"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2825104633512"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p982611460351"><a name="p982611460351"></a><a name="p982611460351"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p0826164693513"><a name="p0826164693513"></a><a name="p0826164693513"></a>返回指定的Rdb谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.glob("NAME", "?h*g")
    ```


### between<a name="section157909401815"></a>

between\(field: string, low: ValueType, high: ValueType\): RdbPredicates

将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。

-   参数：

    <a name="table20583429113712"></a>
    <table><thead align="left"><tr id="row85847296375"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p6584172933719"><a name="p6584172933719"></a><a name="p6584172933719"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1584529193716"><a name="p1584529193716"></a><a name="p1584529193716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15841029193720"><a name="p15841029193720"></a><a name="p15841029193720"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p858512299371"><a name="p858512299371"></a><a name="p858512299371"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17585162983717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p165857297377"><a name="p165857297377"></a><a name="p165857297377"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15585329173718"><a name="p15585329173718"></a><a name="p15585329173718"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6585102963711"><a name="p6585102963711"></a><a name="p6585102963711"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p11585122912376"><a name="p11585122912376"></a><a name="p11585122912376"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row1058692983714"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1074493513718"><a name="p1074493513718"></a><a name="p1074493513718"></a>low</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p20845184112371"><a name="p20845184112371"></a><a name="p20845184112371"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19586162911379"><a name="p19586162911379"></a><a name="p19586162911379"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p65868296372"><a name="p65868296372"></a><a name="p65868296372"></a>指示与谓词匹配的最小值。</p>
    </td>
    </tr>
    <tr id="row72261046133720"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p122754616371"><a name="p122754616371"></a><a name="p122754616371"></a>high</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p202275464372"><a name="p202275464372"></a><a name="p202275464372"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12228194611372"><a name="p12228194611372"></a><a name="p12228194611372"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2022844615374"><a name="p2022844615374"></a><a name="p2022844615374"></a>指示要与谓词匹配的最大值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1990071724017"></a>
    <table><thead align="left"><tr id="row1890051715402"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p11900617204016"><a name="p11900617204016"></a><a name="p11900617204016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p14901131715400"><a name="p14901131715400"></a><a name="p14901131715400"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row169012017164010"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p15901201714019"><a name="p15901201714019"></a><a name="p15901201714019"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p19901517174018"><a name="p19901517174018"></a><a name="p19901517174018"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.between("AGE", 10, 50)
    ```


### notBetween<a name="section17122464189"></a>

notBetween\(field: string, low: ValueType, high: ValueType\): RdbPredicates

配置RdbPredicates以匹配数据字段为ValueType且value超出给定范围的指定字段。

-   参数：

    <a name="table197584411436"></a>
    <table><thead align="left"><tr id="row17613449431"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1376184414430"><a name="p1376184414430"></a><a name="p1376184414430"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p776184417436"><a name="p776184417436"></a><a name="p776184417436"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13771744144316"><a name="p13771744144316"></a><a name="p13771744144316"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p877044174311"><a name="p877044174311"></a><a name="p877044174311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row07717446438"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1077544134317"><a name="p1077544134317"></a><a name="p1077544134317"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p157814417434"><a name="p157814417434"></a><a name="p157814417434"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p67854474311"><a name="p67854474311"></a><a name="p67854474311"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1981444134313"><a name="p1981444134313"></a><a name="p1981444134313"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row881844174312"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1881154414435"><a name="p1881154414435"></a><a name="p1881154414435"></a>low</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2811244194314"><a name="p2811244194314"></a><a name="p2811244194314"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1981844104316"><a name="p1981844104316"></a><a name="p1981844104316"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1381844194316"><a name="p1381844194316"></a><a name="p1381844194316"></a>指示与谓词匹配的最小值。</p>
    </td>
    </tr>
    <tr id="row1682184415434"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p178234418435"><a name="p178234418435"></a><a name="p178234418435"></a>high</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p118215442438"><a name="p118215442438"></a><a name="p118215442438"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p48274416436"><a name="p48274416436"></a><a name="p48274416436"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p88354494313"><a name="p88354494313"></a><a name="p88354494313"></a>指示要与谓词匹配的最大值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table128484410435"></a>
    <table><thead align="left"><tr id="row1984104418433"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p28534419438"><a name="p28534419438"></a><a name="p28534419438"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p178534434311"><a name="p178534434311"></a><a name="p178534434311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9859447436"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p4851244194314"><a name="p4851244194314"></a><a name="p4851244194314"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1886194414437"><a name="p1886194414437"></a><a name="p1886194414437"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.notBetween("AGE", 10, 50)
    ```


### greaterThan<a name="section4792221122016"></a>

greaterThan\(field: string, value: ValueType\): RdbPredicatesgr

配置谓词以匹配数据字段为ValueType且值大于指定值的字段。

-   参数：

    <a name="table15907134334611"></a>
    <table><thead align="left"><tr id="row590934316468"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p390984354620"><a name="p390984354620"></a><a name="p390984354620"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1490918438469"><a name="p1490918438469"></a><a name="p1490918438469"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p59105436468"><a name="p59105436468"></a><a name="p59105436468"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1991064316465"><a name="p1991064316465"></a><a name="p1991064316465"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row199109433462"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p191114435467"><a name="p191114435467"></a><a name="p191114435467"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p39111043144610"><a name="p39111043144610"></a><a name="p39111043144610"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p391113433460"><a name="p391113433460"></a><a name="p391113433460"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1691124318464"><a name="p1691124318464"></a><a name="p1691124318464"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row199112433466"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11911643134614"><a name="p11911643134614"></a><a name="p11911643134614"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1291284312465"><a name="p1291284312465"></a><a name="p1291284312465"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7912943184616"><a name="p7912943184616"></a><a name="p7912943184616"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p29123434463"><a name="p29123434463"></a><a name="p29123434463"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table113949464474"></a>
    <table><thead align="left"><tr id="row739524617479"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p43951446184714"><a name="p43951446184714"></a><a name="p43951446184714"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1539584614473"><a name="p1539584614473"></a><a name="p1539584614473"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15395124684715"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p10396154614715"><a name="p10396154614715"></a><a name="p10396154614715"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p9396104604719"><a name="p9396104604719"></a><a name="p9396104604719"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.greaterThan("AGE", 18)
    ```


### lessThan<a name="section12451245162011"></a>

lessThan\(field: string, value: ValueType\): RdbPredicates

配置谓词以匹配数据字段为valueType且value小于指定值的字段。

-   参数：

    <a name="table2036015013499"></a>
    <table><thead align="left"><tr id="row53612050184920"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1436125013493"><a name="p1436125013493"></a><a name="p1436125013493"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p3362550174918"><a name="p3362550174918"></a><a name="p3362550174918"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p2036245015499"><a name="p2036245015499"></a><a name="p2036245015499"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1536265017492"><a name="p1536265017492"></a><a name="p1536265017492"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12362950164910"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p4362115011494"><a name="p4362115011494"></a><a name="p4362115011494"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13631250114915"><a name="p13631250114915"></a><a name="p13631250114915"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p17363145011499"><a name="p17363145011499"></a><a name="p17363145011499"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p113631950154917"><a name="p113631950154917"></a><a name="p113631950154917"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row1636311504494"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11363150154917"><a name="p11363150154917"></a><a name="p11363150154917"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9363145014910"><a name="p9363145014910"></a><a name="p9363145014910"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7364150194915"><a name="p7364150194915"></a><a name="p7364150194915"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17364195020494"><a name="p17364195020494"></a><a name="p17364195020494"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table736405034910"></a>
    <table><thead align="left"><tr id="row193644507493"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p17365135014910"><a name="p17365135014910"></a><a name="p17365135014910"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p203657504496"><a name="p203657504496"></a><a name="p203657504496"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row193657502491"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1636515074918"><a name="p1636515074918"></a><a name="p1636515074918"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p436516508490"><a name="p436516508490"></a><a name="p436516508490"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.lessThan("AGE", 20)
    ```


### greaterThanOrEqualTo<a name="section3159182124819"></a>

greaterThanOrEqualTo\(field: string, value: ValueType\): RdbPredicates

配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。

-   参数：

    <a name="table1413816460511"></a>
    <table><thead align="left"><tr id="row12139184613511"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2139134612515"><a name="p2139134612515"></a><a name="p2139134612515"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p913974635120"><a name="p913974635120"></a><a name="p913974635120"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p16140746115115"><a name="p16140746115115"></a><a name="p16140746115115"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p13140144675114"><a name="p13140144675114"></a><a name="p13140144675114"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13140124635115"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p171407461519"><a name="p171407461519"></a><a name="p171407461519"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1414116467518"><a name="p1414116467518"></a><a name="p1414116467518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19141174675113"><a name="p19141174675113"></a><a name="p19141174675113"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p514164619518"><a name="p514164619518"></a><a name="p514164619518"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row17141134635114"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11141124619518"><a name="p11141124619518"></a><a name="p11141124619518"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1114234612517"><a name="p1114234612517"></a><a name="p1114234612517"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p16142646175117"><a name="p16142646175117"></a><a name="p16142646175117"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p3142164615120"><a name="p3142164615120"></a><a name="p3142164615120"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table176851057155119"></a>
    <table><thead align="left"><tr id="row168635755117"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p8686657125118"><a name="p8686657125118"></a><a name="p8686657125118"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p12686195717515"><a name="p12686195717515"></a><a name="p12686195717515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1686457135114"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p668710576514"><a name="p668710576514"></a><a name="p668710576514"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p116871157135117"><a name="p116871157135117"></a><a name="p116871157135117"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.greaterThanOrEqualTo("AGE", 18)
    ```


### lessThanOrEqualTo<a name="section12679514484"></a>

lessThanOrEqualTo\(field: string, value: ValueType\): RdbPredicates

配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。

-   参数：

    <a name="table1333124219536"></a>
    <table><thead align="left"><tr id="row13311942175315"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p633244255310"><a name="p633244255310"></a><a name="p633244255310"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p833264245313"><a name="p833264245313"></a><a name="p833264245313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p333210425537"><a name="p333210425537"></a><a name="p333210425537"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2332204210539"><a name="p2332204210539"></a><a name="p2332204210539"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row033311425538"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16333842165315"><a name="p16333842165315"></a><a name="p16333842165315"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p5333104216536"><a name="p5333104216536"></a><a name="p5333104216536"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p4333154218535"><a name="p4333154218535"></a><a name="p4333154218535"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17334204215534"><a name="p17334204215534"></a><a name="p17334204215534"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row1033434212538"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p183346424538"><a name="p183346424538"></a><a name="p183346424538"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p833594265316"><a name="p833594265316"></a><a name="p833594265316"></a><a href="#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p113351342135317"><a name="p113351342135317"></a><a name="p113351342135317"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p16335242135314"><a name="p16335242135314"></a><a name="p16335242135314"></a>指示要与谓词匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1733634213537"></a>
    <table><thead align="left"><tr id="row6336114275316"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1433613421533"><a name="p1433613421533"></a><a name="p1433613421533"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p433634212530"><a name="p433634212530"></a><a name="p433634212530"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10336154295319"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p18337164225318"><a name="p18337164225318"></a><a name="p18337164225318"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p173371242165319"><a name="p173371242165319"></a><a name="p173371242165319"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.lessThanOrEqualTo("AGE", 20)
    ```


### orderByAsc<a name="section203691699509"></a>

orderByAsc\(field: string\): RdbPredicates

配置谓词以匹配其值按升序排序的列。

-   参数：

    <a name="table1988111105513"></a>
    <table><thead align="left"><tr id="row688214112556"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1088211113557"><a name="p1088211113557"></a><a name="p1088211113557"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1988217117551"><a name="p1988217117551"></a><a name="p1988217117551"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p888381115513"><a name="p888381115513"></a><a name="p888381115513"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p588381195519"><a name="p588381195519"></a><a name="p588381195519"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row98831711155517"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13883101125515"><a name="p13883101125515"></a><a name="p13883101125515"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p148845117556"><a name="p148845117556"></a><a name="p148845117556"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p588441185517"><a name="p588441185517"></a><a name="p588441185517"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p68841111195510"><a name="p68841111195510"></a><a name="p68841111195510"></a>数据库表中的列名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table19793932175619"></a>
    <table><thead align="left"><tr id="row379573215620"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1279593216561"><a name="p1279593216561"></a><a name="p1279593216561"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1979553212564"><a name="p1979553212564"></a><a name="p1979553212564"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14795123211566"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17796532125612"><a name="p17796532125612"></a><a name="p17796532125612"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p77969322566"><a name="p77969322566"></a><a name="p77969322566"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.orderByAsc("NAME")
    ```


### orderByDesc<a name="section1757213509506"></a>

orderByDesc\(field: string\): RdbPredicates

配置谓词以匹配其值按降序排序的列。

-   参数：

    <a name="table1187173145817"></a>
    <table><thead align="left"><tr id="row0871113125818"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13871123115816"><a name="p13871123115816"></a><a name="p13871123115816"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p38722039586"><a name="p38722039586"></a><a name="p38722039586"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p2872833583"><a name="p2872833583"></a><a name="p2872833583"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1787212325819"><a name="p1787212325819"></a><a name="p1787212325819"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row28723320585"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p48728365820"><a name="p48728365820"></a><a name="p48728365820"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1687283105820"><a name="p1687283105820"></a><a name="p1687283105820"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p28735316584"><a name="p28735316584"></a><a name="p28735316584"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1387316305811"><a name="p1387316305811"></a><a name="p1387316305811"></a>数据库表中的列名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table9873183105812"></a>
    <table><thead align="left"><tr id="row687310316581"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p3874173145810"><a name="p3874173145810"></a><a name="p3874173145810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1874103145814"><a name="p1874103145814"></a><a name="p1874103145814"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1287418335817"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p28749355816"><a name="p28749355816"></a><a name="p28749355816"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1987416318588"><a name="p1987416318588"></a><a name="p1987416318588"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.orderByDesc("AGE")
    ```


### distinct<a name="section45891667519"></a>

distinct\(\): RdbPredicates

配置谓词以过滤重复记录并仅保留其中一个。

-   返回值：

    <a name="table929218331804"></a>
    <table><thead align="left"><tr id="row1529311337018"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p2293113314012"><a name="p2293113314012"></a><a name="p2293113314012"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p92947336018"><a name="p92947336018"></a><a name="p92947336018"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1229414331705"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p329415336012"><a name="p329415336012"></a><a name="p329415336012"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p2029411332017"><a name="p2029411332017"></a><a name="p2029411332017"></a>返回可用于过滤重复记录的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").distinct("NAME")
    let resultSet = await rdbStore.query(predicates, ["NAME"])
    ```


### limitAs<a name="section1129521411272"></a>

limitAs\(value: number\): RdbPredicates

设置最大数据记录数的谓词。

-   参数：

    <a name="table1817013541934"></a>
    <table><thead align="left"><tr id="row121711354135"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p141711548316"><a name="p141711548316"></a><a name="p141711548316"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p117165412316"><a name="p117165412316"></a><a name="p117165412316"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p117215411316"><a name="p117215411316"></a><a name="p117215411316"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6172105410311"><a name="p6172105410311"></a><a name="p6172105410311"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61739541532"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12173254738"><a name="p12173254738"></a><a name="p12173254738"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p51734544311"><a name="p51734544311"></a><a name="p51734544311"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p18174354137"><a name="p18174354137"></a><a name="p18174354137"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1517417541634"><a name="p1517417541634"></a><a name="p1517417541634"></a>最大数据记录数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table3565171111519"></a>
    <table><thead align="left"><tr id="row195651611953"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p8566181114518"><a name="p8566181114518"></a><a name="p8566181114518"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1856613111857"><a name="p1856613111857"></a><a name="p1856613111857"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row656641112518"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p14566121116510"><a name="p14566121116510"></a><a name="p14566121116510"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1556711111755"><a name="p1556711111755"></a><a name="p1556711111755"></a>返回可用于设置最大数据记录数的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").limitAs(3)
    ```


### offsetAs<a name="section73879413300"></a>

offsetAs\(rowOffset: number\): RdbPredicates

配置RdbPredicates以指定返回结果的起始位置。

-   参数：

    <a name="table174331881171"></a>
    <table><thead align="left"><tr id="row164341282071"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p174341481670"><a name="p174341481670"></a><a name="p174341481670"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p84341686719"><a name="p84341686719"></a><a name="p84341686719"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p043538874"><a name="p043538874"></a><a name="p043538874"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1243568873"><a name="p1243568873"></a><a name="p1243568873"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row54351786714"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11735614472"><a name="p11735614472"></a><a name="p11735614472"></a>rowOffset</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1943520815712"><a name="p1943520815712"></a><a name="p1943520815712"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p8436385715"><a name="p8436385715"></a><a name="p8436385715"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p643616810715"><a name="p643616810715"></a><a name="p643616810715"></a>返回结果的起始位置，取值为正整数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table22586341383"></a>
    <table><thead align="left"><tr id="row9258183415812"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1125819341181"><a name="p1125819341181"></a><a name="p1125819341181"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1425912344814"><a name="p1425912344814"></a><a name="p1425912344814"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row52591234987"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p9259934787"><a name="p9259934787"></a><a name="p9259934787"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1259123415819"><a name="p1259123415819"></a><a name="p1259123415819"></a>返回具有指定返回结果起始位置的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").offsetAs(3)
    ```


### groupBy<a name="section87095506331"></a>

groupBy\(fields: Array<string\>\): RdbPredicates

配置RdbPredicates按指定列分组查询结果。

-   参数：

    <a name="table1633191451119"></a>
    <table><thead align="left"><tr id="row19634171417117"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p863417141117"><a name="p863417141117"></a><a name="p863417141117"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1063519146117"><a name="p1063519146117"></a><a name="p1063519146117"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18635414161119"><a name="p18635414161119"></a><a name="p18635414161119"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1963581417116"><a name="p1963581417116"></a><a name="p1963581417116"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row563521441118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11593122141115"><a name="p11593122141115"></a><a name="p11593122141115"></a>fields</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1663613144111"><a name="p1663613144111"></a><a name="p1663613144111"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p17636101411112"><a name="p17636101411112"></a><a name="p17636101411112"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13636614201116"><a name="p13636614201116"></a><a name="p13636614201116"></a>指定分组依赖的列名。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table1712684521212"></a>
    <table><thead align="left"><tr id="row112615451128"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1912613454129"><a name="p1912613454129"></a><a name="p1912613454129"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1112694513128"><a name="p1112694513128"></a><a name="p1112694513128"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15126164510125"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p6127745111213"><a name="p6127745111213"></a><a name="p6127745111213"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p158461234133315"><a name="p158461234133315"></a><a name="p158461234133315"></a>返回分组查询列的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.groupBy(["AGE", "NAME"])
    ```


### indexedBy<a name="section1874631393616"></a>

indexedBy\(indexName: string\): RdbPredicates

配置RdbPredicates以指定索引列。

-   参数：

    <a name="table554414420111"></a>
    <table><thead align="left"><tr id="row16546194412114"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1654611443116"><a name="p1654611443116"></a><a name="p1654611443116"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p16546344113"><a name="p16546344113"></a><a name="p16546344113"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1054734416118"><a name="p1054734416118"></a><a name="p1054734416118"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p145471447111"><a name="p145471447111"></a><a name="p145471447111"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3547134413117"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14808141141"><a name="p14808141141"></a><a name="p14808141141"></a>indexName</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p195492441015"><a name="p195492441015"></a><a name="p195492441015"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p205491044013"><a name="p205491044013"></a><a name="p205491044013"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p654944414119"><a name="p654944414119"></a><a name="p654944414119"></a>索引列的名称。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table393195010519"></a>
    <table><thead align="left"><tr id="row15945501454"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p194145017515"><a name="p194145017515"></a><a name="p194145017515"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p19941650258"><a name="p19941650258"></a><a name="p19941650258"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row495145015516"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p89575013516"><a name="p89575013516"></a><a name="p89575013516"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p295115013511"><a name="p295115013511"></a><a name="p295115013511"></a>返回具有指定索引列的RdbPredicates。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.indexedBy("SALARY_INDEX")
    ```


### in<a name="section1932471143817"></a>

in\(field: string, value: Array<ValueType\>\): RdbPredicates

配置RdbPredicates以匹配数据字段为ValueType数组且值在给定范围内的指定字段。

-   参数：

    <a name="table8311622131917"></a>
    <table><thead align="left"><tr id="row8312172231914"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19312142217196"><a name="p19312142217196"></a><a name="p19312142217196"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p331272217196"><a name="p331272217196"></a><a name="p331272217196"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p331332216195"><a name="p331332216195"></a><a name="p331332216195"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1631312281918"><a name="p1631312281918"></a><a name="p1631312281918"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row103139226191"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p131415229191"><a name="p131415229191"></a><a name="p131415229191"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p18314922111916"><a name="p18314922111916"></a><a name="p18314922111916"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7314112231916"><a name="p7314112231916"></a><a name="p7314112231916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p163145220191"><a name="p163145220191"></a><a name="p163145220191"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row8822182915196"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3823152961916"><a name="p3823152961916"></a><a name="p3823152961916"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p582352914191"><a name="p582352914191"></a><a name="p582352914191"></a>Array&lt;<a href="#section56419143718">ValueType</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p148231429171910"><a name="p148231429171910"></a><a name="p148231429171910"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p17824202914199"><a name="p17824202914199"></a><a name="p17824202914199"></a>以ValueType型数组形式指定的要匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table827316323259"></a>
    <table><thead align="left"><tr id="row32741232102511"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p12741932152515"><a name="p12741932152515"></a><a name="p12741932152515"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p192741832102515"><a name="p192741832102515"></a><a name="p192741832102515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14274133222511"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p3275183252515"><a name="p3275183252515"></a><a name="p3275183252515"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p827513325255"><a name="p827513325255"></a><a name="p827513325255"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.in("AGE", [18, 20])
    ```


### notIn<a name="section149241721184219"></a>

notIn\(field: string, value: Array<ValueType\>\): RdbPredicates

将RdbPredicates配置为匹配数据字段为ValueType且值超出给定范围的指定字段。

-   参数：

    <a name="table3136194115358"></a>
    <table><thead align="left"><tr id="row1713754118358"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p121371041113511"><a name="p121371041113511"></a><a name="p121371041113511"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p13138154115359"><a name="p13138154115359"></a><a name="p13138154115359"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p111381941143514"><a name="p111381941143514"></a><a name="p111381941143514"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p7138164123513"><a name="p7138164123513"></a><a name="p7138164123513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6139144120354"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p4139124120352"><a name="p4139124120352"></a><a name="p4139124120352"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p51391241113515"><a name="p51391241113515"></a><a name="p51391241113515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p11140104110358"><a name="p11140104110358"></a><a name="p11140104110358"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4140741183519"><a name="p4140741183519"></a><a name="p4140741183519"></a>数据库表中的列名。</p>
    </td>
    </tr>
    <tr id="row1514016418353"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1114154113353"><a name="p1114154113353"></a><a name="p1114154113353"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1714174118355"><a name="p1714174118355"></a><a name="p1714174118355"></a>Array&lt;<a href="#section56419143718">ValueType</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p141421441133516"><a name="p141421441133516"></a><a name="p141421441133516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p414294116359"><a name="p414294116359"></a><a name="p414294116359"></a>以ValueType数组形式指定的要匹配的值。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table5143541133514"></a>
    <table><thead align="left"><tr id="row1314484143514"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p131441141153511"><a name="p131441141153511"></a><a name="p131441141153511"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1714544115358"><a name="p1714544115358"></a><a name="p1714544115358"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1814544133514"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1814511417359"><a name="p1814511417359"></a><a name="p1814511417359"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p614594118351"><a name="p614594118351"></a><a name="p614594118351"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.notIn("NAME", ["Lisa", "Rose"])
    ```


## RdbStore<a name="section12882825611"></a>

提供管理关系数据库\(RDB\)方法的接口。

### insert<a name="section161726917544"></a>

insert\(name: string, values: ValuesBucket, callback: AsyncCallback<number\>\):void

向目标表中插入一行数据，结果以callback形式返回。

-   参数：

    <a name="table61855294472"></a>
    <table><thead align="left"><tr id="row1918613293479"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2186132919477"><a name="p2186132919477"></a><a name="p2186132919477"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p718722912476"><a name="p718722912476"></a><a name="p718722912476"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p618792944710"><a name="p618792944710"></a><a name="p618792944710"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p718862924711"><a name="p718862924711"></a><a name="p718862924711"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row918872914715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p718817293472"><a name="p718817293472"></a><a name="p718817293472"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1189629144710"><a name="p1189629144710"></a><a name="p1189629144710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1318942916474"><a name="p1318942916474"></a><a name="p1318942916474"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p151891829124715"><a name="p151891829124715"></a><a name="p151891829124715"></a>指定的目标表名。</p>
    </td>
    </tr>
    <tr id="row119019297472"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p131901629144718"><a name="p131901629144718"></a><a name="p131901629144718"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p719014291470"><a name="p719014291470"></a><a name="p719014291470"></a><a href="#section11627732124619">ValuesBucket</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p61901529194714"><a name="p61901529194714"></a><a name="p61901529194714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p124921153185019"><a name="p124921153185019"></a><a name="p124921153185019"></a>表示要插入到表中的数据行。</p>
    </td>
    </tr>
    <tr id="row88542533473"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1185617535478"><a name="p1185617535478"></a><a name="p1185617535478"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10856135318474"><a name="p10856135318474"></a><a name="p10856135318474"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p28560534477"><a name="p28560534477"></a><a name="p28560534477"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p742233425213"><a name="p742233425213"></a><a name="p742233425213"></a>指定callback回调函数。如果操作成功，返回行ID；否则返回-1。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const valueBucket = {
        "NAME": "Lisa",
        "AGE": 18,
        "SALARY": 100.5,
        "CODES": new Uint8Array([1, 2, 3, 4, 5]),
    }
    rdbStore.insert("EMPLOYEE", valueBucket, function (err, ret) {
        expect(1).assertEqual(ret)
        console.log(TAG + "insert first done: " + ret)})
    ```


### insert<a name="section17443163225511"></a>

insert\(name: string, values: ValuesBucket\):Promise<number\>

向目标表中插入一行数据，结果以Promise形式返回。

-   参数：

    <a name="table44884315584"></a>
    <table><thead align="left"><tr id="row1449204375812"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p149174310589"><a name="p149174310589"></a><a name="p149174310589"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1249643135817"><a name="p1249643135817"></a><a name="p1249643135817"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p8503435582"><a name="p8503435582"></a><a name="p8503435582"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1650104325819"><a name="p1650104325819"></a><a name="p1650104325819"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row115034345817"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p573310187592"><a name="p573310187592"></a><a name="p573310187592"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2073318189597"><a name="p2073318189597"></a><a name="p2073318189597"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1573417187599"><a name="p1573417187599"></a><a name="p1573417187599"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p773411814590"><a name="p773411814590"></a><a name="p773411814590"></a>指定的目标表名。</p>
    </td>
    </tr>
    <tr id="row55194310581"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p873561855910"><a name="p873561855910"></a><a name="p873561855910"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4735191820597"><a name="p4735191820597"></a><a name="p4735191820597"></a><a href="#section11627732124619">ValuesBucket</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p873551805916"><a name="p873551805916"></a><a name="p873551805916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p673516184593"><a name="p673516184593"></a><a name="p673516184593"></a>表示要插入到表中的数据行。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table55311436588"></a>
    <table><thead align="left"><tr id="row165424395811"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p16541943185810"><a name="p16541943185810"></a><a name="p16541943185810"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1254174318583"><a name="p1254174318583"></a><a name="p1254174318583"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20547439582"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p55524325817"><a name="p55524325817"></a><a name="p55524325817"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p966518169235"><a name="p966518169235"></a><a name="p966518169235"></a>指定Promise回调函数。如果操作成功，返回行ID；否则返回-1。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const valueBucket = {
        "NAME": "Lisa",
        "AGE": 18,
        "SALARY": 100.5,
        "CODES": new Uint8Array([1, 2, 3, 4, 5]),
    }
    let promise = rdbStore.insert("EMPLOYEE", valueBucket)
    promise.then(async (ret) => {
        await console.log(TAG + "insert first done: " + ret)
    }).catch((err) => {})
    ```


### update<a name="section495110570014"></a>

update\(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback<number\>\):void

根据RdbPredicates的指定实例对象更新数据库中的数据，结果以callback形式返回。

-   参数：

    <a name="table82202318612"></a>
    <table><thead align="left"><tr id="row1722117320618"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p922123068"><a name="p922123068"></a><a name="p922123068"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p722110316612"><a name="p722110316612"></a><a name="p722110316612"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p0222173662"><a name="p0222173662"></a><a name="p0222173662"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p92228310614"><a name="p92228310614"></a><a name="p92228310614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0223634620"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p522412314614"><a name="p522412314614"></a><a name="p522412314614"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1122423760"><a name="p1122423760"></a><a name="p1122423760"></a><a href="#section11627732124619">ValuesBucket</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p62241733616"><a name="p62241733616"></a><a name="p62241733616"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p115701665813"><a name="p115701665813"></a><a name="p115701665813"></a>value指示数据库中要更新的数据行。键值对与数据库表的列名相关联</p>
    </td>
    </tr>
    <tr id="row522515314611"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p22258320612"><a name="p22258320612"></a><a name="p22258320612"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2022612320616"><a name="p2022612320616"></a><a name="p2022612320616"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1322613367"><a name="p1322613367"></a><a name="p1322613367"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p142261739615"><a name="p142261739615"></a><a name="p142261739615"></a>表示要插入到表中的数据行。</p>
    </td>
    </tr>
    <tr id="row1421811266611"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8219826564"><a name="p8219826564"></a><a name="p8219826564"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p221932612616"><a name="p221932612616"></a><a name="p221932612616"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p92193261664"><a name="p92193261664"></a><a name="p92193261664"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4162947172417"><a name="p4162947172417"></a><a name="p4162947172417"></a>指定的callback回调方法。返回受影响的行数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const valueBucket = {
        "NAME": "Rose",
        "AGE": 22,
        "SALARY": 200.5,
        "CODES": new Uint8Array([1, 2, 3, 4, 5]),
    }
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
    rdbStore.update(valueBucket, predicates, function (err, ret) {
        console.log(TAG + "updated row count: " + changedRows)})
    ```


### update<a name="section1162235119"></a>

update\(values: ValuesBucket, rdbPredicates: RdbPredicates\):Promise<number\>

根据RdbPredicates的指定实例对象更新数据库中的数据，结果以Promise形式返回。

-   参数：

    <a name="table1990643911123"></a>
    <table><thead align="left"><tr id="row390715391128"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13907239181212"><a name="p13907239181212"></a><a name="p13907239181212"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p4907113971210"><a name="p4907113971210"></a><a name="p4907113971210"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13907139111212"><a name="p13907139111212"></a><a name="p13907139111212"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p190853910127"><a name="p190853910127"></a><a name="p190853910127"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11908139101217"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1190883981219"><a name="p1190883981219"></a><a name="p1190883981219"></a>values</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16908133921214"><a name="p16908133921214"></a><a name="p16908133921214"></a><a href="#section11627732124619">ValuesBucket</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p199085397128"><a name="p199085397128"></a><a name="p199085397128"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1690919394126"><a name="p1690919394126"></a><a name="p1690919394126"></a>value指示数据库中要更新的数据行。键值对与数据库表的列名相关联</p>
    </td>
    </tr>
    <tr id="row10909143913128"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9909039171219"><a name="p9909039171219"></a><a name="p9909039171219"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9910103910126"><a name="p9910103910126"></a><a name="p9910103910126"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p29105394125"><a name="p29105394125"></a><a name="p29105394125"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p12910739101212"><a name="p12910739101212"></a><a name="p12910739101212"></a>表示要插入到表中的数据行。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   返回值：

    <a name="table252182410125"></a>
    <table><thead align="left"><tr id="row352192441218"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p8522172471215"><a name="p8522172471215"></a><a name="p8522172471215"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p19522424121213"><a name="p19522424121213"></a><a name="p19522424121213"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11522112418127"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p5523424131211"><a name="p5523424131211"></a><a name="p5523424131211"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1752322401217"><a name="p1752322401217"></a><a name="p1752322401217"></a>指定的Promise回调方法。返回受影响的行数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const valueBucket = {
        "NAME": "Rose",
        "AGE": 22,
        "SALARY": 200.5,
        "CODES": new Uint8Array([1, 2, 3, 4, 5]),
    }
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
    let promise = rdbStore.update(valueBucket, predicates)
    promise.then(async (ret) => {
        await console.log(TAG + "updated row count: " + changedRows)
    }).catch((err) => {})
    ```


### delete<a name="section1458053411419"></a>

delete\(rdbPredicates: RdbPredicates, callback: AsyncCallback<number\>\):void

根据rdbPredicates的指定实例对象从数据库中删除数据，结果以callback形式返回。

-   参数：

    <a name="table11883125218158"></a>
    <table><thead align="left"><tr id="row7884952151518"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p208841852191512"><a name="p208841852191512"></a><a name="p208841852191512"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p788565221510"><a name="p788565221510"></a><a name="p788565221510"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p9887125214151"><a name="p9887125214151"></a><a name="p9887125214151"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p78871152121516"><a name="p78871152121516"></a><a name="p78871152121516"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1688814522156"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10888175216155"><a name="p10888175216155"></a><a name="p10888175216155"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9888115214152"><a name="p9888115214152"></a><a name="p9888115214152"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p38891252171512"><a name="p38891252171512"></a><a name="p38891252171512"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19889452111519"><a name="p19889452111519"></a><a name="p19889452111519"></a>RdbPredicates的实例对象指定的删除条件。</p>
    </td>
    </tr>
    <tr id="row2891175220156"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p9891452101519"><a name="p9891452101519"></a><a name="p9891452101519"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p198911525155"><a name="p198911525155"></a><a name="p198911525155"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p58921752151516"><a name="p58921752151516"></a><a name="p58921752151516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5850183112010"><a name="p5850183112010"></a><a name="p5850183112010"></a>指定callback回调函数。返回受影响的行数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
    rdbStore.delete(predicates, function (err, rows) {
        console.log(TAG + "delete rows: " + rows)})
    ```


### delete<a name="section131488532183"></a>

delete\(rdbPredicates: RdbPredicates\):Promise<number\>

根据rdbPredicates的指定实例对象从数据库中删除数据，结果以Promise形式返回。

-   参数：

    <a name="table10718335131912"></a>
    <table><thead align="left"><tr id="row871913359195"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p14719143519195"><a name="p14719143519195"></a><a name="p14719143519195"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p0720103531912"><a name="p0720103531912"></a><a name="p0720103531912"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1472023511920"><a name="p1472023511920"></a><a name="p1472023511920"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p18720635161912"><a name="p18720635161912"></a><a name="p18720635161912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1172073531919"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p4721103516196"><a name="p4721103516196"></a><a name="p4721103516196"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p472183551918"><a name="p472183551918"></a><a name="p472183551918"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p27219357192"><a name="p27219357192"></a><a name="p27219357192"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p7722113501911"><a name="p7722113501911"></a><a name="p7722113501911"></a>RdbPredicates的实例对象指定的删除条件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table111835692010"></a>
    <table><thead align="left"><tr id="row1218486192019"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p14184156122019"><a name="p14184156122019"></a><a name="p14184156122019"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p31851267207"><a name="p31851267207"></a><a name="p31851267207"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row918596122015"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p111855612203"><a name="p111855612203"></a><a name="p111855612203"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p141862692016"><a name="p141862692016"></a><a name="p141862692016"></a>指定Promise回调函数。返回受影响的行数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
    let promise = rdbStore.delete(predicates)
    promise.then((rows) => {
        console.log(TAG + "delete rows: " + rows)
    }).catch((err) => {})
    ```


### query<a name="section6231155031814"></a>

query\(rdbPredicates: RdbPredicates, columns: Array<string\>, callback: AsyncCallback<ResultSet\>\):void

根据指定条件查询数据库中的数据，结果以callback形式返回。

-   参数：

    <a name="table134047259197"></a>
    <table><thead align="left"><tr id="row134041225191915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7404172513199"><a name="p7404172513199"></a><a name="p7404172513199"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1740422518197"><a name="p1740422518197"></a><a name="p1740422518197"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18404122513192"><a name="p18404122513192"></a><a name="p18404122513192"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2404025121912"><a name="p2404025121912"></a><a name="p2404025121912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20404172517195"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3404625101912"><a name="p3404625101912"></a><a name="p3404625101912"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p114047255192"><a name="p114047255192"></a><a name="p114047255192"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10404162571912"><a name="p10404162571912"></a><a name="p10404162571912"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10404192513199"><a name="p10404192513199"></a><a name="p10404192513199"></a>表示rdbPredicates的实例对象指定的查询条件。</p>
    </td>
    </tr>
    <tr id="row1740492512196"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1540432551910"><a name="p1540432551910"></a><a name="p1540432551910"></a>columns</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1668231610505"><a name="p1668231610505"></a><a name="p1668231610505"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6405202516196"><a name="p6405202516196"></a><a name="p6405202516196"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1140502514190"><a name="p1140502514190"></a><a name="p1140502514190"></a>表示要查询的列。如果值为空，则查询应用于所有列。</p>
    </td>
    </tr>
    <tr id="row678445844913"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10784115817492"><a name="p10784115817492"></a><a name="p10784115817492"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p14785558164919"><a name="p14785558164919"></a><a name="p14785558164919"></a>AsyncCallback&lt;<a href="js-apis-data-resultset.md#section12882825611">ResultSet</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1278518587497"><a name="p1278518587497"></a><a name="p1278518587497"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p97851358184916"><a name="p97851358184916"></a><a name="p97851358184916"></a>指定callback回调函数。如果操作成功，则返回ResultSet对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose")
    rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
        console.log(TAG + "resultSet column names:" + resultSet.columnNames)
        console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
    ```


### query<a name="section12293161972016"></a>

query\(rdbPredicates: RdbPredicates, columns: Array<string\>\):Promise<ResultSet\>

根据指定条件查询数据库中的数据，结果以Promise形式返回。

-   参数：

    <a name="table4937172922016"></a>
    <table><thead align="left"><tr id="row3937162917202"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p39377296202"><a name="p39377296202"></a><a name="p39377296202"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p1093712917202"><a name="p1093712917202"></a><a name="p1093712917202"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p5937142915201"><a name="p5937142915201"></a><a name="p5937142915201"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p693722972018"><a name="p693722972018"></a><a name="p693722972018"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0937829202013"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1993718293203"><a name="p1993718293203"></a><a name="p1993718293203"></a>rdbPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p1937122922018"><a name="p1937122922018"></a><a name="p1937122922018"></a><a href="#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p10937152962019"><a name="p10937152962019"></a><a name="p10937152962019"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p1683215379523"><a name="p1683215379523"></a><a name="p1683215379523"></a>表示rdbPredicates的实例对象指定的查询条件。</p>
    </td>
    </tr>
    <tr id="row1293752912012"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1893714292206"><a name="p1893714292206"></a><a name="p1893714292206"></a>columns</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p884912410524"><a name="p884912410524"></a><a name="p884912410524"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p12937429102016"><a name="p12937429102016"></a><a name="p12937429102016"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p129372299204"><a name="p129372299204"></a><a name="p129372299204"></a>表示要查询的列。如果值为空，则查询应用于所有列。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table0760161855311"></a>
    <table><thead align="left"><tr id="row1076121845318"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p076111187531"><a name="p076111187531"></a><a name="p076111187531"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p127611180532"><a name="p127611180532"></a><a name="p127611180532"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row117611187532"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p11762918185319"><a name="p11762918185319"></a><a name="p11762918185319"></a>Promise&lt;<a href="js-apis-data-resultset.md#section12882825611">ResultSet</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p13207156165218"><a name="p13207156165218"></a><a name="p13207156165218"></a>指定Promise回调函数。如果操作成功，则返回ResultSet对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose")
    let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    promise.then((resultSet) => {
        console.log(TAG + "resultSet column names:" + resultSet.columnNames)
        console.log(TAG + "resultSet column count:" + resultSet.columnCount)})
    ```


### executeSql<a name="section18984643152118"></a>

executeSql\(sql: string, bindArgs: Array<ValueType\>, callback: AsyncCallback<void\>\):void

执行包含指定参数但不返回值的SQL语句，结果以callbck形式返回。

-   参数：

    <a name="table5897205885518"></a>
    <table><thead align="left"><tr id="row18971558165517"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p7898165810553"><a name="p7898165810553"></a><a name="p7898165810553"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p11898175812552"><a name="p11898175812552"></a><a name="p11898175812552"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p2898115818556"><a name="p2898115818556"></a><a name="p2898115818556"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p2089835825511"><a name="p2089835825511"></a><a name="p2089835825511"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5898558135514"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p168981658105519"><a name="p168981658105519"></a><a name="p168981658105519"></a>sql</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p63621801571"><a name="p63621801571"></a><a name="p63621801571"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p7899358115516"><a name="p7899358115516"></a><a name="p7899358115516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p128999581556"><a name="p128999581556"></a><a name="p128999581556"></a>指定要执行的SQL语句。</p>
    </td>
    </tr>
    <tr id="row18991587554"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p6899105845510"><a name="p6899105845510"></a><a name="p6899105845510"></a>bindArgs</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p1478720615576"><a name="p1478720615576"></a><a name="p1478720615576"></a>Array&lt;<a href="#section56419143718">ValueType</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p889995816556"><a name="p889995816556"></a><a name="p889995816556"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p1890095820554"><a name="p1890095820554"></a><a name="p1890095820554"></a>SQL语句中参数的值。</p>
    </td>
    </tr>
    <tr id="row1365434915561"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p166551949175617"><a name="p166551949175617"></a><a name="p166551949175617"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p36557495567"><a name="p36557495567"></a><a name="p36557495567"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p4655134919565"><a name="p4655134919565"></a><a name="p4655134919565"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p26551149115616"><a name="p26551149115616"></a><a name="p26551149115616"></a>指定callback回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   示例：

    ```
    rdbStore.executeSql("DELETE FROM EMPLOYEE", function () {
        console.info(TAG + 'delete done.')})
    ```


### executeSql<a name="section2042914810266"></a>

executeSql\(sql: string, bindArgs: Array<ValueType\>\):Promise<void\>

执行包含指定参数但不返回值的SQL语句，结果以Promise形式返回。

-   参数：

    <a name="table18627821182614"></a>
    <table><thead align="left"><tr id="row162782182615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p36278211263"><a name="p36278211263"></a><a name="p36278211263"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1662732192616"><a name="p1662732192616"></a><a name="p1662732192616"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1362762182616"><a name="p1362762182616"></a><a name="p1362762182616"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p186282218261"><a name="p186282218261"></a><a name="p186282218261"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1262810215268"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p196284210266"><a name="p196284210266"></a><a name="p196284210266"></a>sql</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1462802113268"><a name="p1462802113268"></a><a name="p1462802113268"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1628192192612"><a name="p1628192192612"></a><a name="p1628192192612"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18356154119293"><a name="p18356154119293"></a><a name="p18356154119293"></a>指定要执行的SQL语句。</p>
    </td>
    </tr>
    <tr id="row5628202152619"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8628102192617"><a name="p8628102192617"></a><a name="p8628102192617"></a>bindArgs</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1629619574583"><a name="p1629619574583"></a><a name="p1629619574583"></a>Array&lt;<a href="#section56419143718">ValueType</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p96281217267"><a name="p96281217267"></a><a name="p96281217267"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15628721142612"><a name="p15628721142612"></a><a name="p15628721142612"></a>SQL语句中参数的值。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table5861925510"></a>
    <table><thead align="left"><tr id="row8878250115"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p20871425718"><a name="p20871425718"></a><a name="p20871425718"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1787625112"><a name="p1787625112"></a><a name="p1787625112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3878254119"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p387142517119"><a name="p387142517119"></a><a name="p387142517119"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p3871251119"><a name="p3871251119"></a><a name="p3871251119"></a>指定Promise回调函数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let promise = rdbStore.executeSql("DELETE FROM EMPLOYEE")
    promise.then(() => {
        console.info(TAG + 'delete done.')})
    ```


## StoreConfig<a name="section957124521217"></a>

管理关系数据库配置。

<a name="table18105191011146"></a>
<table><thead align="left"><tr id="row21065107143"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17107171041416"><a name="p17107171041416"></a><a name="p17107171041416"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p10107210191414"><a name="p10107210191414"></a><a name="p10107210191414"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18108910171416"><a name="p18108910171416"></a><a name="p18108910171416"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1310831001411"><a name="p1310831001411"></a><a name="p1310831001411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14108510111417"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3332192420141"><a name="p3332192420141"></a><a name="p3332192420141"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1310910106146"><a name="p1310910106146"></a><a name="p1310910106146"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p11110510121413"><a name="p11110510121413"></a><a name="p11110510121413"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13110110181418"><a name="p13110110181418"></a><a name="p13110110181418"></a>数据库文件名。</p>
</td>
</tr>
</tbody>
</table>

## ValueType<a name="section56419143718"></a>

用于表示允许的数据字段类型。

<a name="table1923665410559"></a>
<table><thead align="left"><tr id="row2236185411552"><th class="cellrowborder" valign="top" width="23.630000000000003%" id="mcps1.1.3.1.1"><p id="p1723755417554"><a name="p1723755417554"></a><a name="p1723755417554"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="76.37%" id="mcps1.1.3.1.2"><p id="p10237454125510"><a name="p10237454125510"></a><a name="p10237454125510"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13237165420553"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.1.3.1.1 "><p id="p623715475519"><a name="p623715475519"></a><a name="p623715475519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="76.37%" headers="mcps1.1.3.1.2 "><p id="p3237175419556"><a name="p3237175419556"></a><a name="p3237175419556"></a>表示值类型为数字。</p>
</td>
</tr>
<tr id="row16237185419559"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.1.3.1.1 "><p id="p202378547551"><a name="p202378547551"></a><a name="p202378547551"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="76.37%" headers="mcps1.1.3.1.2 "><p id="p2023820548551"><a name="p2023820548551"></a><a name="p2023820548551"></a>表示值类型为字符。</p>
</td>
</tr>
<tr id="row28813815919"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.1.3.1.1 "><p id="p1389123814598"><a name="p1389123814598"></a><a name="p1389123814598"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="76.37%" headers="mcps1.1.3.1.2 "><p id="p589538175910"><a name="p589538175910"></a><a name="p589538175910"></a>表示值类型为布尔值。</p>
</td>
</tr>
</tbody>
</table>

## ValuesBucket<a name="section11627732124619"></a>

用于存储键值对。

<a name="table0103172561814"></a>
<table><thead align="left"><tr id="row12103152513185"><th class="cellrowborder" valign="top" width="13.87138713871387%" id="mcps1.1.5.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.373037303730378%" id="mcps1.1.5.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.141014101410141%" id="mcps1.1.5.1.3"><p id="p1103172518188"><a name="p1103172518188"></a><a name="p1103172518188"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.614561456145616%" id="mcps1.1.5.1.4"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row201031125101812"><td class="cellrowborder" valign="top" width="13.87138713871387%" headers="mcps1.1.5.1.1 "><p id="p155807341179"><a name="p155807341179"></a><a name="p155807341179"></a>[key: string]</p>
</td>
<td class="cellrowborder" valign="top" width="30.373037303730378%" headers="mcps1.1.5.1.2 "><p id="p18278259281"><a name="p18278259281"></a><a name="p18278259281"></a><a href="#section56419143718">ValueType</a>| Uint8Array | null</p>
</td>
<td class="cellrowborder" valign="top" width="10.141014101410141%" headers="mcps1.1.5.1.3 "><p id="p8935162182512"><a name="p8935162182512"></a><a name="p8935162182512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.614561456145616%" headers="mcps1.1.5.1.4 "><p id="p4111161091810"><a name="p4111161091810"></a><a name="p4111161091810"></a>用于存储键值对。</p>
</td>
</tr>
</tbody>
</table>

