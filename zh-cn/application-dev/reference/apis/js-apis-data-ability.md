# DataAbility 谓词<a name="ZH-CN_TOPIC_0000001201117411"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="section68088407422"></a>

```
import dataAbility from '@ohos.data.dataAbility'
```

## 权限<a name="section11257113618419"></a>

无

## dataAbility.createRdbPredicates<a name="section039731125514"></a>

createRdbPredicates\(name: string, dataAbilityPredicates: DataAbilityPredicates\): rdb.RdbPredicates

从DataAabilityPredicates对象创建RdbPredicates对象。

-   参数：

    <a name="table616003193611"></a>
    <table><thead align="left"><tr id="row1316020312365"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p616063133616"><a name="p616063133616"></a><a name="p616063133616"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1416118313611"><a name="p1416118313611"></a><a name="p1416118313611"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p516113318361"><a name="p516113318361"></a><a name="p516113318361"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p131616353614"><a name="p131616353614"></a><a name="p131616353614"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row816113313611"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13161938361"><a name="p13161938361"></a><a name="p13161938361"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p5162123173618"><a name="p5162123173618"></a><a name="p5162123173618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10162163203617"><a name="p10162163203617"></a><a name="p10162163203617"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1816220320362"><a name="p1816220320362"></a><a name="p1816220320362"></a>数据库表中表名。</p>
    </td>
    </tr>
    <tr id="row51631638365"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1516323143611"><a name="p1516323143611"></a><a name="p1516323143611"></a>dataAbilityPredicates</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p616313383615"><a name="p616313383615"></a><a name="p616313383615"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p41638363611"><a name="p41638363611"></a><a name="p41638363611"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1616315393610"><a name="p1616315393610"></a><a name="p1616315393610"></a>dataAbility谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table4192203119407"></a>
    <table><thead align="left"><tr id="row151921531124013"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p111928310403"><a name="p111928310403"></a><a name="p111928310403"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p21931331194016"><a name="p21931331194016"></a><a name="p21931331194016"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11935314406"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p14805164434011"><a name="p14805164434011"></a><a name="p14805164434011"></a>rdb.<a href="js-apis-data-rdb.md#section3101161234310">RdbPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p152193512554"><a name="p152193512554"></a><a name="p152193512554"></a>返回RdbPredicates对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let dataAbilityPredicates = new dataAbility.DataAbilityPredicates()
    dataAbilityPredicates.equalTo("NAME", "Rose").between("AGE", 16, 30)
    let predicates = dataAbility.createRdbPredicates("EMPLOYEE", dataAbilityPredicates)
    ```


## DataAbilityPredicates<a name="section55051094515"></a>

提供用于实现不同查询方法的谓词。

### equalTo<a name="section2198018183"></a>

equalTo\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且值等于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1454575075612"><a name="p1454575075612"></a><a name="p1454575075612"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row1151918245578"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p2017012187205"><a name="p2017012187205"></a><a name="p2017012187205"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1551922465710"><a name="p1551922465710"></a><a name="p1551922465710"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
    ```


### notEqualTo<a name="section2090013451815"></a>

notEqualTo\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且值不等于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15323381156"><a name="p15323381156"></a><a name="p15323381156"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row108111563614"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p5812667615"><a name="p5812667615"></a><a name="p5812667615"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p138121962619"><a name="p138121962619"></a><a name="p138121962619"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.notEqualTo("NAME", "lisi")
    ```


### beginWrap<a name="section15372052110"></a>

beginWrap\(\): DataAbilityPredicates

向谓词添加左括号。

-   返回值：

    <a name="table8798182141219"></a>
    <table><thead align="left"><tr id="row1879811211210"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1879972111212"><a name="p1879972111212"></a><a name="p1879972111212"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p1779932121212"><a name="p1779932121212"></a><a name="p1779932121212"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row157994291219"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p8799202171212"><a name="p8799202171212"></a><a name="p8799202171212"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p177999216128"><a name="p177999216128"></a><a name="p177999216128"></a>返回带有左括号的DataAbility谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbilitylity.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
        .beginWrap()
        .equalTo("AGE", 18)
        .or()
        .equalTo("SALARY", 200.5)
        .endWrap()
    ```


### endWrap<a name="section830315118589"></a>

endWrap\(\): DataAbilityPredicates

向谓词添加右括号。

-   返回值：

    <a name="table1345521812144"></a>
    <table><thead align="left"><tr id="row2455201812143"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1045631810147"><a name="p1045631810147"></a><a name="p1045631810147"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p245631813147"><a name="p245631813147"></a><a name="p245631813147"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1045610186147"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p144569181148"><a name="p144569181148"></a><a name="p144569181148"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p12457141812149"><a name="p12457141812149"></a><a name="p12457141812149"></a>返回带有右括号的DataAbility谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "lisi")
        .beginWrap()
        .equalTo("AGE", 18)
        .or()
        .equalTo("SALARY", 200.5)
        .endWrap()
    ```


### or<a name="section12206854306"></a>

or\(\): DataAbilityPredicates

将或条件添加到谓词中。

-   返回值：

    <a name="table6746132913152"></a>
    <table><thead align="left"><tr id="row1374711292154"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p574715292152"><a name="p574715292152"></a><a name="p574715292152"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p17481429111515"><a name="p17481429111515"></a><a name="p17481429111515"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12748202911154"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p6748102911513"><a name="p6748102911513"></a><a name="p6748102911513"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1574882991512"><a name="p1574882991512"></a><a name="p1574882991512"></a>返回带有或条件的DataAbility谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
        .or()
        .equalTo("NAME", "Rose")
    ```


### and<a name="section33535342114"></a>

and\(\): DataAbilityPredicates

向谓词添加和条件。

-   返回值：

    <a name="table11147145951616"></a>
    <table><thead align="left"><tr id="row1914785918165"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p21471559101610"><a name="p21471559101610"></a><a name="p21471559101610"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p8147175918161"><a name="p8147175918161"></a><a name="p8147175918161"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111479594161"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p18147175915168"><a name="p18147175915168"></a><a name="p18147175915168"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p13148165911612"><a name="p13148165911612"></a><a name="p13148165911612"></a>返回带有和条件的DataAbility谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Lisa")
        .and()
        .equalTo("SALARY", 200.5)
    ```


### contains<a name="section18316219823"></a>

contains\(field: string, value: string\): DataAbilityPredicates

配置谓词以匹配数据类型为String且value包含指定值的字段。

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
    <tbody><tr id="row187372229192"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17737162216194"><a name="p17737162216194"></a><a name="p17737162216194"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p773782281911"><a name="p773782281911"></a><a name="p773782281911"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.contains("NAME", "os")
    ```


### beginsWith<a name="section1976125011217"></a>

beginsWith\(field: string, value: string\): DataAbilityPredicates

配置谓词以匹配数据类型为String且值以指定字符串开头的字段。

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
    <tbody><tr id="row13593655102212"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p9593135542210"><a name="p9593135542210"></a><a name="p9593135542210"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p19594135515224"><a name="p19594135515224"></a><a name="p19594135515224"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.beginsWith("NAME", "os")
    ```


### endsWith<a name="section202091222412"></a>

endsWith\(field: string, value: string\): DataAbilityPredicates

配置谓词以匹配数据类型为String且值以指定字符串结尾的字段。

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
    <tbody><tr id="row2595242172511"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1959684214259"><a name="p1959684214259"></a><a name="p1959684214259"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p759664212259"><a name="p759664212259"></a><a name="p759664212259"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.endsWith("NAME", "se")
    ```


### isNull<a name="section208566591645"></a>

isNull\(field: string\): DataAbilityPredicates

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
    <tbody><tr id="row129671724102719"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p49671324162710"><a name="p49671324162710"></a><a name="p49671324162710"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p796713249277"><a name="p796713249277"></a><a name="p796713249277"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.isNull("NAME")
    ```


### isNotNull<a name="section108675461514"></a>

isNotNull\(field: string\): DataAbilityPredicates

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
    <tbody><tr id="row029281323011"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17292713173018"><a name="p17292713173018"></a><a name="p17292713173018"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p15292171319302"><a name="p15292171319302"></a><a name="p15292171319302"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.isNotNull("NAME")
    ```


### like<a name="section11923221863"></a>

like\(field: string, value: string\): DataAbilityPredicates

配置谓词以匹配数据类型为string且值类似于指定字符串的字段。

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
    <tbody><tr id="row03333178323"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p183338171329"><a name="p183338171329"></a><a name="p183338171329"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p5333917133219"><a name="p5333917133219"></a><a name="p5333917133219"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.like("NAME", "%os%")
    ```


### glob<a name="section8668135612617"></a>

glob\(field: string, value: string\): DataAbilityPredicates

配置谓词匹配数据类型为string的指定字段。

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
    <tbody><tr id="row2825104633512"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p982611460351"><a name="p982611460351"></a><a name="p982611460351"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p62241647143112"><a name="p62241647143112"></a><a name="p62241647143112"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.glob("NAME", "?h*g")
    ```


### between<a name="section18415928472"></a>

between\(field: string, low: ValueType, high: ValueType\): DataAbilityPredicates

将谓词配置为匹配数据类型为ValueType且value在指定范围内的指定字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p20845184112371"><a name="p20845184112371"></a><a name="p20845184112371"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19586162911379"><a name="p19586162911379"></a><a name="p19586162911379"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p65868296372"><a name="p65868296372"></a><a name="p65868296372"></a>指示与谓词匹配的最小值。</p>
    </td>
    </tr>
    <tr id="row72261046133720"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p122754616371"><a name="p122754616371"></a><a name="p122754616371"></a>high</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p202275464372"><a name="p202275464372"></a><a name="p202275464372"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12228194611372"><a name="p12228194611372"></a><a name="p12228194611372"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p2022844615374"><a name="p2022844615374"></a><a name="p2022844615374"></a>指示与谓词匹配的最大值。</p>
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
    <tbody><tr id="row169012017164010"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p15901201714019"><a name="p15901201714019"></a><a name="p15901201714019"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p19901517174018"><a name="p19901517174018"></a><a name="p19901517174018"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.between("AGE", 10, 50)
    ```


### notBetween<a name="section093519135818"></a>

notBetween\(field: string, low: ValueType, high: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value超出给定范围的指定字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2811244194314"><a name="p2811244194314"></a><a name="p2811244194314"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1981844104316"><a name="p1981844104316"></a><a name="p1981844104316"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1381844194316"><a name="p1381844194316"></a><a name="p1381844194316"></a>指示与谓词匹配的最小值。</p>
    </td>
    </tr>
    <tr id="row1682184415434"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p178234418435"><a name="p178234418435"></a><a name="p178234418435"></a>high</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p118215442438"><a name="p118215442438"></a><a name="p118215442438"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p48274416436"><a name="p48274416436"></a><a name="p48274416436"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p88354494313"><a name="p88354494313"></a><a name="p88354494313"></a>指示与谓词匹配的最大值。</p>
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
    <tbody><tr id="row9859447436"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p4851244194314"><a name="p4851244194314"></a><a name="p4851244194314"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1886194414437"><a name="p1886194414437"></a><a name="p1886194414437"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.notBetween("AGE", 10, 50)
    ```


### greaterThan<a name="section9224192116910"></a>

greaterThan\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且值大于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1291284312465"><a name="p1291284312465"></a><a name="p1291284312465"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row15395124684715"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p10396154614715"><a name="p10396154614715"></a><a name="p10396154614715"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p9396104604719"><a name="p9396104604719"></a><a name="p9396104604719"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.greaterThan("AGE", 18)
    ```


### lessThan<a name="section1731334619915"></a>

lessThan\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为valueType且value小于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9363145014910"><a name="p9363145014910"></a><a name="p9363145014910"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row193657502491"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1636515074918"><a name="p1636515074918"></a><a name="p1636515074918"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p436516508490"><a name="p436516508490"></a><a name="p436516508490"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.lessThan("AGE", 20)
    ```


### greaterThanOrEqualTo<a name="section19411192241013"></a>

greaterThanOrEqualTo\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value大于或等于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1114234612517"><a name="p1114234612517"></a><a name="p1114234612517"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row1686457135114"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p668710576514"><a name="p668710576514"></a><a name="p668710576514"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p116871157135117"><a name="p116871157135117"></a><a name="p116871157135117"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.greaterThanOrEqualTo("AGE", 18)
    ```


### lessThanOrEqualTo<a name="section855697131115"></a>

lessThanOrEqualTo\(field: string, value: ValueType\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType且value小于或等于指定值的字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p833594265316"><a name="p833594265316"></a><a name="p833594265316"></a><a href="js-apis-data-rdb.md#section56419143718">ValueType</a></p>
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
    <tbody><tr id="row10336154295319"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p18337164225318"><a name="p18337164225318"></a><a name="p18337164225318"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p173371242165319"><a name="p173371242165319"></a><a name="p173371242165319"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.lessThanOrEqualTo("AGE", 20)
    ```


### orderByAsc<a name="section10613839161111"></a>

orderByAsc\(field: string\): DataAbilityPredicates

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
    <tbody><tr id="row14795123211566"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p17796532125612"><a name="p17796532125612"></a><a name="p17796532125612"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p77969322566"><a name="p77969322566"></a><a name="p77969322566"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.orderByAsc("NAME")
    ```


### orderByDesc<a name="section1277751220124"></a>

orderByDesc\(field: string\): DataAbilityPredicates

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
    <tbody><tr id="row1287418335817"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p28749355816"><a name="p28749355816"></a><a name="p28749355816"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1987416318588"><a name="p1987416318588"></a><a name="p1987416318588"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.orderByDesc("AGE")
    ```


### distinct<a name="section1525512399124"></a>

distinct\(\): DataAbilityPredicates

配置谓词以过滤重复记录并仅保留其中一个。

-   返回值：

    <a name="table929218331804"></a>
    <table><thead align="left"><tr id="row1529311337018"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p2293113314012"><a name="p2293113314012"></a><a name="p2293113314012"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p92947336018"><a name="p92947336018"></a><a name="p92947336018"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1229414331705"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p329415336012"><a name="p329415336012"></a><a name="p329415336012"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p2029411332017"><a name="p2029411332017"></a><a name="p2029411332017"></a>返回可用于过滤重复记录的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").distinct("NAME")
    let resultSet = await rdbStore.query(predicates, ["NAME"])
    ```


### limitAs<a name="section183021921138"></a>

limitAs\(value: number\): DataAbilityPredicates

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
    <tbody><tr id="row656641112518"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p14566121116510"><a name="p14566121116510"></a><a name="p14566121116510"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1556711111755"><a name="p1556711111755"></a><a name="p1556711111755"></a>返回可用于设置最大数据记录数的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").limitAs(3)
    ```


### offsetAs<a name="section140411296135"></a>

offsetAs\(rowOffset: number\): DataAbilityPredicates

配置谓词以指定返回结果的起始位置。

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
    <tbody><tr id="row52591234987"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p9259934787"><a name="p9259934787"></a><a name="p9259934787"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1259123415819"><a name="p1259123415819"></a><a name="p1259123415819"></a>返回具有指定返回结果起始位置的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.equalTo("NAME", "Rose").offsetAs(3)
    ```


### groupBy<a name="section1512514535133"></a>

groupBy\(fields: Array<string\>\): DataAbilityPredicates

配置谓词按指定列分组查询结果。

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
    <tbody><tr id="row15126164510125"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p6127745111213"><a name="p6127745111213"></a><a name="p6127745111213"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p158461234133315"><a name="p158461234133315"></a><a name="p158461234133315"></a>返回分组查询列的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.groupBy(["AGE", "NAME"])
    ```


### indexedBy<a name="section6724191991418"></a>

indexedBy\(indexName: string\): DataAbilityPredicates

配置谓词以指定索引列。

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
    <tbody><tr id="row3547134413117"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13494109104218"><a name="p13494109104218"></a><a name="p13494109104218"></a>indexName</p>
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
    <tbody><tr id="row495145015516"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p89575013516"><a name="p89575013516"></a><a name="p89575013516"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p295115013511"><a name="p295115013511"></a><a name="p295115013511"></a>返回具有指定索引列的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.indexedBy("SALARY_INDEX")
    ```


### in<a name="section8947145381415"></a>

in\(field: string, value: Array<ValueType\>\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType数组且值在给定范围内的指定字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p582352914191"><a name="p582352914191"></a><a name="p582352914191"></a>Array&lt;<a href="js-apis-data-rdb.md#section56419143718">ValueType</a>&gt;</p>
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
    <tbody><tr id="row14274133222511"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p3275183252515"><a name="p3275183252515"></a><a name="p3275183252515"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p827513325255"><a name="p827513325255"></a><a name="p827513325255"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.in("AGE", [18, 20])
    ```


### notIn<a name="section1294132119155"></a>

notIn\(field: string, value: Array<ValueType\>\): DataAbilityPredicates

配置谓词以匹配数据类型为ValueType数组且值不在给定范围内的指定字段。

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
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1714174118355"><a name="p1714174118355"></a><a name="p1714174118355"></a>Array&lt;<a href="js-apis-data-rdb.md#section56419143718">ValueType</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p141421441133516"><a name="p141421441133516"></a><a name="p141421441133516"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p414294116359"><a name="p414294116359"></a><a name="p414294116359"></a>以ValueType型数组形式指定的要匹配的值。</p>
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
    <tbody><tr id="row1814544133514"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p1814511417359"><a name="p1814511417359"></a><a name="p1814511417359"></a><a href="#section55051094515">DataAbilityPredicates</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p614594118351"><a name="p614594118351"></a><a name="p614594118351"></a>返回与指定字段匹配的谓词。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let predicates = new dataAbility.DataAbilityPredicates("EMPLOYEE")
    predicates.notIn("NAME", ["Lisa", "Rose"])
    ```


