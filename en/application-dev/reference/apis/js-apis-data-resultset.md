# Result Set<a name="EN-US_TOPIC_0000001159793150"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## System Capabilities
SystemCapability.DistributedDataManager.RelationalStore.Core

## Usage<a name="section42211227142416"></a>

The  **resultSet**  object is obtained by using  [**RdbStore.query\(\)**](js-apis-data-rdb.md#section6231155031814).

```
import dataRdb from '@ohos.data.rdb';
let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("AGE", 18)
let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
promise.then((resultSet) => {
    await console.log(TAG + "resultSet columnNames:" + resultSet.columnNames);
    await console.log(TAG + "resultSet columnCount:" + resultSet.columnCount);})
```

## Required Permissions<a name="section11257113618419"></a>

None

## ResultSet<a name="section12882825611"></a>

Provides methods to access the result set, which is obtained by querying the relational database \(RDB\) store.

### Attributes<a name="section33371914134316"></a>

<a name="table184922044316"></a>
<table><thead align="left"><tr id="row1649212018436"><th class="cellrowborder" valign="top" width="17.911791179117913%" id="mcps1.1.5.1.1"><p id="p9493140124311"><a name="p9493140124311"></a><a name="p9493140124311"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.291229122912291%" id="mcps1.1.5.1.2"><p id="p11493190144319"><a name="p11493190144319"></a><a name="p11493190144319"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="p124942015436"><a name="p124942015436"></a><a name="p124942015436"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="p19494800433"><a name="p19494800433"></a><a name="p19494800433"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6494500437"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p1349412074317"><a name="p1349412074317"></a><a name="p1349412074317"></a>columnNames</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p114948074319"><a name="p114948074319"></a><a name="p114948074319"></a>Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p16495803434"><a name="p16495803434"></a><a name="p16495803434"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1149515020434"><a name="p1149515020434"></a><a name="p1149515020434"></a>Names of all columns in the result set.</p>
</td>
</tr>
<tr id="row249530144319"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p64951908431"><a name="p64951908431"></a><a name="p64951908431"></a>columnCount</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p14495701434"><a name="p14495701434"></a><a name="p14495701434"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p164954074314"><a name="p164954074314"></a><a name="p164954074314"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p114957010437"><a name="p114957010437"></a><a name="p114957010437"></a>Number of columns in the result set.</p>
</td>
</tr>
<tr id="row2497204431"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p154973074312"><a name="p154973074312"></a><a name="p154973074312"></a>rowCount</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p134972004438"><a name="p134972004438"></a><a name="p134972004438"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p849720094317"><a name="p849720094317"></a><a name="p849720094317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p849720184311"><a name="p849720184311"></a><a name="p849720184311"></a>Number of rows in the result set.</p>
</td>
</tr>
<tr id="row149711094313"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p6498408432"><a name="p6498408432"></a><a name="p6498408432"></a>rowIndex</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p104984004313"><a name="p104984004313"></a><a name="p104984004313"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p17498190154315"><a name="p17498190154315"></a><a name="p17498190154315"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1149840134313"><a name="p1149840134313"></a><a name="p1149840134313"></a>Index of the current row in the result set.</p>
</td>
</tr>
<tr id="row15498140174314"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p1249814011437"><a name="p1249814011437"></a><a name="p1249814011437"></a>isAtFirstRow</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p174996019439"><a name="p174996019439"></a><a name="p174996019439"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p16499140134318"><a name="p16499140134318"></a><a name="p16499140134318"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p54998044315"><a name="p54998044315"></a><a name="p54998044315"></a>Specifies whether the cursor is in the first row of the result set.</p>
</td>
</tr>
<tr id="row154995015437"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p2499105436"><a name="p2499105436"></a><a name="p2499105436"></a>isAtLastRow</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p749910014314"><a name="p749910014314"></a><a name="p749910014314"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p154993020433"><a name="p154993020433"></a><a name="p154993020433"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1950010017432"><a name="p1950010017432"></a><a name="p1950010017432"></a>Whether the cursor is in the last row of the result set.</p>
</td>
</tr>
<tr id="row250016064319"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p75008017436"><a name="p75008017436"></a><a name="p75008017436"></a>isEnded</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p050017016431"><a name="p050017016431"></a><a name="p050017016431"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p1850018010431"><a name="p1850018010431"></a><a name="p1850018010431"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1650013017433"><a name="p1650013017433"></a><a name="p1650013017433"></a>Whether the cursor is after the last row of the result set.</p>
</td>
</tr>
<tr id="row125001014315"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p18501140164316"><a name="p18501140164316"></a><a name="p18501140164316"></a>isStarted</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p16501100184315"><a name="p16501100184315"></a><a name="p16501100184315"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p175019011436"><a name="p175019011436"></a><a name="p175019011436"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1834523310411"><a name="p1834523310411"></a><a name="p1834523310411"></a>Whether the cursor has been moved.</p>
</td>
</tr>
<tr id="row9501509438"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p1502200124310"><a name="p1502200124310"></a><a name="p1502200124310"></a>isClosed</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p2503705432"><a name="p2503705432"></a><a name="p2503705432"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p1350316017434"><a name="p1350316017434"></a><a name="p1350316017434"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p35031016433"><a name="p35031016433"></a><a name="p35031016433"></a>Whether the result set is closed.</p>
</td>
</tr>
</tbody>
</table>

### getColumnIndex<a name="section1157339392"></a>

getColumnIndex\(columnName: string\): number

Obtains the column index based on the specified column name.

-   Parameters

    <a name="table61855294472"></a>
    <table><thead align="left"><tr id="row1918613293479"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2186132919477"><a name="p2186132919477"></a><a name="p2186132919477"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p718722912476"><a name="p718722912476"></a><a name="p718722912476"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p618792944710"><a name="p618792944710"></a><a name="p618792944710"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p718862924711"><a name="p718862924711"></a><a name="p718862924711"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row918872914715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p718817293472"><a name="p718817293472"></a><a name="p718817293472"></a>columnName</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1189629144710"><a name="p1189629144710"></a><a name="p1189629144710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1318942916474"><a name="p1318942916474"></a><a name="p1318942916474"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p151891829124715"><a name="p151891829124715"></a><a name="p151891829124715"></a>Name of the column.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table20961651020"></a>
    <table><thead align="left"><tr id="row169621556217"><th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.3.1.1"><p id="p12962451327"><a name="p12962451327"></a><a name="p12962451327"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="84.85000000000001%" id="mcps1.1.3.1.2"><p id="p1196210517216"><a name="p1196210517216"></a><a name="p1196210517216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1696211520212"><td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.3.1.1 "><p id="p149621851328"><a name="p149621851328"></a><a name="p149621851328"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="84.85000000000001%" headers="mcps1.1.3.1.2 "><p id="p149631953213"><a name="p149631953213"></a><a name="p149631953213"></a>Index of the column.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    resultSet.goToFirstRow()
    const id = resultSet.getLong(resultSet.getColumnIndex("ID"))
    const name = resultSet.getString(resultSet.getColumnIndex("NAME"))
    const age = resultSet.getLong(resultSet.getColumnIndex("AGE"))
    const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"))
    ```


### getColumnName<a name="section17443163225511"></a>

getColumnName\(columnIndex: number\): string

Obtains the column name based on the specified column index.

-   Parameters

    <a name="table44884315584"></a>
    <table><thead align="left"><tr id="row1449204375812"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p149174310589"><a name="p149174310589"></a><a name="p149174310589"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1249643135817"><a name="p1249643135817"></a><a name="p1249643135817"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p8503435582"><a name="p8503435582"></a><a name="p8503435582"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1650104325819"><a name="p1650104325819"></a><a name="p1650104325819"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row115034345817"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p573310187592"><a name="p573310187592"></a><a name="p573310187592"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p2073318189597"><a name="p2073318189597"></a><a name="p2073318189597"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1573417187599"><a name="p1573417187599"></a><a name="p1573417187599"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p773411814590"><a name="p773411814590"></a><a name="p773411814590"></a>Index of the column.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table55311436588"></a>
    <table><thead align="left"><tr id="row165424395811"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.3.1.1"><p id="p16541943185810"><a name="p16541943185810"></a><a name="p16541943185810"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="85.18%" id="mcps1.1.3.1.2"><p id="p1254174318583"><a name="p1254174318583"></a><a name="p1254174318583"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20547439582"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.3.1.1 "><p id="p14837301096"><a name="p14837301096"></a><a name="p14837301096"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="85.18%" headers="mcps1.1.3.1.2 "><p id="p65510438580"><a name="p65510438580"></a><a name="p65510438580"></a>Name of the column.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const id = resultSet.getColumnName(0)
    const name = resultSet.getColumnName(1)
    const age = resultSet.getColumnName(2)
    ```


### goTo<a name="section495110570014"></a>

goTo\(offset:number\): boolean

Moves the cursor to the row based on the specified offset.

-   Parameters

    <a name="table82202318612"></a>
    <table><thead align="left"><tr id="row1722117320618"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p922123068"><a name="p922123068"></a><a name="p922123068"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p722110316612"><a name="p722110316612"></a><a name="p722110316612"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p0222173662"><a name="p0222173662"></a><a name="p0222173662"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p92228310614"><a name="p92228310614"></a><a name="p92228310614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0223634620"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p522412314614"><a name="p522412314614"></a><a name="p522412314614"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1122423760"><a name="p1122423760"></a><a name="p1122423760"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p62241733616"><a name="p62241733616"></a><a name="p62241733616"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p154152015121913"><a name="p154152015121913"></a><a name="p154152015121913"></a>Offset relative to the current position.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table7733112152018"></a>
    <table><thead align="left"><tr id="row5734182152014"><th class="cellrowborder" valign="top" width="14.92%" id="mcps1.1.3.1.1"><p id="p973417213203"><a name="p973417213203"></a><a name="p973417213203"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="85.08%" id="mcps1.1.3.1.2"><p id="p3734721152012"><a name="p3734721152012"></a><a name="p3734721152012"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row573416215206"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.3.1.1 "><p id="p273515212203"><a name="p273515212203"></a><a name="p273515212203"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="85.08%" headers="mcps1.1.3.1.2 "><p id="p12204124792912"><a name="p12204124792912"></a><a name="p12204124792912"></a>Returns <strong id="b16588123663312"><a name="b16588123663312"></a><a name="b16588123663312"></a>true</strong> if the operation is successful; returns <strong id="b734714415343"><a name="b734714415343"></a><a name="b734714415343"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goTo(1)
    resultSet.close()
    resultSet = null
    ```


### goToRow<a name="section1162235119"></a>

goToRow\(position: number\): boolean

Moves the cursor to the specified row in the result set.

-   Parameters

    <a name="table1990643911123"></a>
    <table><thead align="left"><tr id="row390715391128"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13907239181212"><a name="p13907239181212"></a><a name="p13907239181212"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p4907113971210"><a name="p4907113971210"></a><a name="p4907113971210"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13907139111212"><a name="p13907139111212"></a><a name="p13907139111212"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p190853910127"><a name="p190853910127"></a><a name="p190853910127"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11908139101217"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1190883981219"><a name="p1190883981219"></a><a name="p1190883981219"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16908133921214"><a name="p16908133921214"></a><a name="p16908133921214"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p199085397128"><a name="p199085397128"></a><a name="p199085397128"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1690919394126"><a name="p1690919394126"></a><a name="p1690919394126"></a>Position to which the cursor is to be moved.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table252182410125"></a>
    <table><thead align="left"><tr id="row352192441218"><th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.3.1.1"><p id="p8522172471215"><a name="p8522172471215"></a><a name="p8522172471215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="85.5%" id="mcps1.1.3.1.2"><p id="p19522424121213"><a name="p19522424121213"></a><a name="p19522424121213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11522112418127"><td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.3.1.1 "><p id="p820215291665"><a name="p820215291665"></a><a name="p820215291665"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="85.5%" headers="mcps1.1.3.1.2 "><p id="p1752322401217"><a name="p1752322401217"></a><a name="p1752322401217"></a>Returns <strong id="b1099443431"><a name="b1099443431"></a><a name="b1099443431"></a>true</strong> if the operation is successful; returns <strong id="b578907770"><a name="b578907770"></a><a name="b578907770"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goToRow(1)
    resultSet.close()
    resultSet = null
    ```


### goToFirstRow<a name="section1458053411419"></a>

goToFirstRow\(\): boolean

Moves the cursor to the first row of the result set.

-   Return values

    <a name="table581620571583"></a>
    <table><thead align="left"><tr id="row8817357582"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p581720571487"><a name="p581720571487"></a><a name="p581720571487"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p28177571812"><a name="p28177571812"></a><a name="p28177571812"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1581819571083"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p2818757583"><a name="p2818757583"></a><a name="p2818757583"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p981814572814"><a name="p981814572814"></a><a name="p981814572814"></a>Returns <strong id="b1993345723418"><a name="b1993345723418"></a><a name="b1993345723418"></a>true</strong> if the operation is successful; returns <strong id="b18933195712348"><a name="b18933195712348"></a><a name="b18933195712348"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goToFirstRow()
    resultSet.close()
    resultSet = null;
    ```


### goToLastRow<a name="section131488532183"></a>

goToLastRow\(\): boolean

Moves the cursor to the last row of the result set.

-   Return values

    <a name="table111835692010"></a>
    <table><thead align="left"><tr id="row1218486192019"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p14184156122019"><a name="p14184156122019"></a><a name="p14184156122019"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p31851267207"><a name="p31851267207"></a><a name="p31851267207"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row918596122015"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p24019212106"><a name="p24019212106"></a><a name="p24019212106"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p18463621131018"><a name="p18463621131018"></a><a name="p18463621131018"></a>Returns <strong id="b1193716576345"><a name="b1193716576345"></a><a name="b1193716576345"></a>true</strong> if the operation is successful; returns <strong id="b1793795713418"><a name="b1793795713418"></a><a name="b1793795713418"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goToLastRow()
    resultSet.close()
    resultSet = null;
    ```


### goToNextRow<a name="section6231155031814"></a>

goToNextRow\(\): boolean

Moves the cursor to the next row in the result set.

-   Return values

    <a name="table1725123651220"></a>
    <table><thead align="left"><tr id="row18251136141218"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1625536181217"><a name="p1625536181217"></a><a name="p1625536181217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p152573616122"><a name="p152573616122"></a><a name="p152573616122"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1225436121214"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p32543691211"><a name="p32543691211"></a><a name="p32543691211"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p16261236141219"><a name="p16261236141219"></a><a name="p16261236141219"></a>Returns <strong id="b12940175783420"><a name="b12940175783420"></a><a name="b12940175783420"></a>true</strong> if the operation is successful; returns <strong id="b209401657153411"><a name="b209401657153411"></a><a name="b209401657153411"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goToNextRow()
    resultSet.close()
    resultSet = null;
    ```


### goToPreviousRow<a name="section12293161972016"></a>

goToPreviousRow\(\): boolean

Moves the cursor to the previous row in the result set.

-   Return values

    <a name="table0760161855311"></a>
    <table><thead align="left"><tr id="row1076121845318"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p076111187531"><a name="p076111187531"></a><a name="p076111187531"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p127611180532"><a name="p127611180532"></a><a name="p127611180532"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row117611187532"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1954894412136"><a name="p1954894412136"></a><a name="p1954894412136"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p893394712136"><a name="p893394712136"></a><a name="p893394712136"></a>Returns <strong id="b2942857113414"><a name="b2942857113414"></a><a name="b2942857113414"></a>true</strong> if the operation is successful; returns <strong id="b2942257113415"><a name="b2942257113415"></a><a name="b2942257113415"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.goToPreviousRow()
    resultSet.close()
    resultSet = null
    ```


### getBlob<a name="section18984643152118"></a>

getBlob\(columnIndex: number\): Uint8Array

Obtains the value in the specified column in the current row as a byte array.

-   Parameters

    <a name="table5897205885518"></a>
    <table><thead align="left"><tr id="row18971558165517"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p7898165810553"><a name="p7898165810553"></a><a name="p7898165810553"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p11898175812552"><a name="p11898175812552"></a><a name="p11898175812552"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p2898115818556"><a name="p2898115818556"></a><a name="p2898115818556"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p2089835825511"><a name="p2089835825511"></a><a name="p2089835825511"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5898558135514"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p168981658105519"><a name="p168981658105519"></a><a name="p168981658105519"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p63621801571"><a name="p63621801571"></a><a name="p63621801571"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p7899358115516"><a name="p7899358115516"></a><a name="p7899358115516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p128999581556"><a name="p128999581556"></a><a name="p128999581556"></a>Index of the specified column, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table154018346168"></a>
    <table><thead align="left"><tr id="row155411634181610"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p254183491612"><a name="p254183491612"></a><a name="p254183491612"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p3541113415163"><a name="p3541113415163"></a><a name="p3541113415163"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1454193410163"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p554118342165"><a name="p554118342165"></a><a name="p554118342165"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p155414347169"><a name="p155414347169"></a><a name="p155414347169"></a>Value in the specified column as a byte array.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"))
    ```


### getString<a name="section2042914810266"></a>

getString\(columnIndex: number\): string

Obtains the value in the specified column in the current row as a string.

-   Parameters

    <a name="table18627821182614"></a>
    <table><thead align="left"><tr id="row162782182615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p36278211263"><a name="p36278211263"></a><a name="p36278211263"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1662732192616"><a name="p1662732192616"></a><a name="p1662732192616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1362762182616"><a name="p1362762182616"></a><a name="p1362762182616"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p186282218261"><a name="p186282218261"></a><a name="p186282218261"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1262810215268"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p196284210266"><a name="p196284210266"></a><a name="p196284210266"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1462802113268"><a name="p1462802113268"></a><a name="p1462802113268"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1628192192612"><a name="p1628192192612"></a><a name="p1628192192612"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13257659141819"><a name="p13257659141819"></a><a name="p13257659141819"></a>Index of the specified column, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5861925510"></a>
    <table><thead align="left"><tr id="row8878250115"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p20871425718"><a name="p20871425718"></a><a name="p20871425718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1787625112"><a name="p1787625112"></a><a name="p1787625112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3878254119"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1734183581915"><a name="p1734183581915"></a><a name="p1734183581915"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p3871251119"><a name="p3871251119"></a><a name="p3871251119"></a>Value in the specified column as a string.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const name = resultSet.getString(resultSet.getColumnIndex("NAME"))
    ```


### getLong<a name="section270062312014"></a>

getLong\(columnIndex: number\): number

Obtains the value in the specified column in the current row as a  **Long**.

-   Parameters

    <a name="table670242372014"></a>
    <table><thead align="left"><tr id="row6703182362015"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1670322382019"><a name="p1670322382019"></a><a name="p1670322382019"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1770482311208"><a name="p1770482311208"></a><a name="p1770482311208"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18704523122013"><a name="p18704523122013"></a><a name="p18704523122013"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p18704123172013"><a name="p18704123172013"></a><a name="p18704123172013"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row970402311204"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3704182313202"><a name="p3704182313202"></a><a name="p3704182313202"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p3704223172012"><a name="p3704223172012"></a><a name="p3704223172012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p20704122302013"><a name="p20704122302013"></a><a name="p20704122302013"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p207055233203"><a name="p207055233203"></a><a name="p207055233203"></a>Index of the specified column, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table87051223112014"></a>
    <table><thead align="left"><tr id="row1370682362020"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p2706142302015"><a name="p2706142302015"></a><a name="p2706142302015"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p16706112382019"><a name="p16706112382019"></a><a name="p16706112382019"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16706102310207"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p127068235203"><a name="p127068235203"></a><a name="p127068235203"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1870622302018"><a name="p1870622302018"></a><a name="p1870622302018"></a>Value in the specified column as a <strong id="b15869112345117"><a name="b15869112345117"></a><a name="b15869112345117"></a>Long</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const age = resultSet.getLong(resultSet.getColumnIndex("AGE"))
    ```


### getDouble<a name="section3820153618207"></a>

getDouble\(columnIndex: number\): number

Obtains the value in the specified column in the current row as a  **double**.

-   Parameters

    <a name="table12820163616205"></a>
    <table><thead align="left"><tr id="row68215367207"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p98211936182014"><a name="p98211936182014"></a><a name="p98211936182014"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p4821336152015"><a name="p4821336152015"></a><a name="p4821336152015"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p182243652017"><a name="p182243652017"></a><a name="p182243652017"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p20822183611203"><a name="p20822183611203"></a><a name="p20822183611203"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17822436132012"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p10822103662015"><a name="p10822103662015"></a><a name="p10822103662015"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p178221836102020"><a name="p178221836102020"></a><a name="p178221836102020"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6822336152011"><a name="p6822336152011"></a><a name="p6822336152011"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p582312362202"><a name="p582312362202"></a><a name="p582312362202"></a>Index of the specified column, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1582316364202"></a>
    <table><thead align="left"><tr id="row148249369203"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p10824736122011"><a name="p10824736122011"></a><a name="p10824736122011"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p108241236162015"><a name="p108241236162015"></a><a name="p108241236162015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8824436132014"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p158241836132017"><a name="p158241836132017"></a><a name="p158241836132017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p982423642015"><a name="p982423642015"></a><a name="p982423642015"></a>Value in the specified column as a <strong id="b1396205911447"><a name="b1396205911447"></a><a name="b1396205911447"></a>double</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"))
    ```


### isColumnNull<a name="section167981954112118"></a>

isColumnNull\(columnIndex: number\): boolean

Checks whether the value in the specified column in the current row is  **null**.

-   Parameters

    <a name="table12799254192110"></a>
    <table><thead align="left"><tr id="row279915413216"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p279975417215"><a name="p279975417215"></a><a name="p279975417215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p18799155413217"><a name="p18799155413217"></a><a name="p18799155413217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18799195410213"><a name="p18799195410213"></a><a name="p18799195410213"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1580095411211"><a name="p1580095411211"></a><a name="p1580095411211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row580018543213"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p48001854162115"><a name="p48001854162115"></a><a name="p48001854162115"></a>columnIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p0800115442114"><a name="p0800115442114"></a><a name="p0800115442114"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p128001954182115"><a name="p128001954182115"></a><a name="p128001954182115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p13800115414215"><a name="p13800115414215"></a><a name="p13800115414215"></a>Index of the specified column, starting from 0.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table18800165402111"></a>
    <table><thead align="left"><tr id="row380155452114"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1680115540219"><a name="p1680115540219"></a><a name="p1680115540219"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1801165412113"><a name="p1801165412113"></a><a name="p1801165412113"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6802165442111"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p10802115416214"><a name="p10802115416214"></a><a name="p10802115416214"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p16802754172116"><a name="p16802754172116"></a><a name="p16802754172116"></a>Returns <strong id="b3173740204516"><a name="b3173740204516"></a><a name="b3173740204516"></a>true</strong> if the value is null; returns <strong id="b8900151614466"><a name="b8900151614466"></a><a name="b8900151614466"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"))
    ```


### close<a name="section675093133215"></a>

close\(\): void

Closes the result set.

-   Example

    ```
    let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
    let resultSet = await rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
    resultSet.close()
    resultSet = null
    ```


