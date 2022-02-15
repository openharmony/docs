# RDB Development<a name="EN-US_TOPIC_0000001185510898"></a>

## When to Use<a name="section3905444123020"></a>

On the basis of the SQLite database, the RDB allows you to operate data with or without native SQL statements. An RDB is also called RDB store.

## Available APIs<a name="section5504175713016"></a>

**Creating and Deleting an RDB Store**

The following table describes APIs available for creating and deleting an RDB store.

**Table  1**  APIs for creating and deleting an RDB store

<a name="table191861518153620"></a>
<table><thead align="left"><tr id="row14232318163610"><th class="cellrowborder" valign="top" width="16.650000000000002%" id="mcps1.2.4.1.1"><p id="p17444101665110"><a name="p17444101665110"></a><a name="p17444101665110"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="30.61%" id="mcps1.2.4.1.2"><p id="p182321618163611"><a name="p182321618163611"></a><a name="p182321618163611"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="52.739999999999995%" id="mcps1.2.4.1.3"><p id="p1623211815366"><a name="p1623211815366"></a><a name="p1623211815366"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16783162014173"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.4.1.1 "><p id="p17783122019176"><a name="p17783122019176"></a><a name="p17783122019176"></a>dataRdb</p>
</td>
<td class="cellrowborder" valign="top" width="30.61%" headers="mcps1.2.4.1.2 "><p id="p231111599237"><a name="p231111599237"></a><a name="p231111599237"></a>getRdbStore(config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.739999999999995%" headers="mcps1.2.4.1.3 "><p id="p9186112481614"><a name="p9186112481614"></a><a name="p9186112481614"></a>Obtains an RDB store. You can set parameters for the RDB store based on service requirements, call APIs to perform data operations, and use a callback to return the result.</p>
<a name="ul20498114912320"></a><a name="ul20498114912320"></a><ul id="ul20498114912320"><li><strong id="b4112115595818"><a name="b4112115595818"></a><a name="b4112115595818"></a>config</strong>: configuration of the RDB store.</li><li><strong id="b11397121135919"><a name="b11397121135919"></a><a name="b11397121135919"></a>version</strong>: version of the RDB store.</li><li><strong id="b43570718591"><a name="b43570718591"></a><a name="b43570718591"></a>callback</strong>: callback invoked to return the RDB store.</li></ul>
</td>
</tr>
<tr id="row32321018143616"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.4.1.1 "><p id="p12399202916814"><a name="p12399202916814"></a><a name="p12399202916814"></a>dataRdb</p>
</td>
<td class="cellrowborder" valign="top" width="30.61%" headers="mcps1.2.4.1.2 "><p id="p3501131011457"><a name="p3501131011457"></a><a name="p3501131011457"></a>getRdbStore(config: StoreConfig, version: number): Promise&lt;RdbStore&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.739999999999995%" headers="mcps1.2.4.1.3 "><p id="p17526162133220"><a name="p17526162133220"></a><a name="p17526162133220"></a>Obtains an RDB store. You can set parameters for the RDB store based on service requirements, call APIs to perform data operations, and use a promise to return the result.</p>
<a name="ul19719610863"></a><a name="ul19719610863"></a><ul id="ul19719610863"><li><strong id="b153861822027"><a name="b153861822027"></a><a name="b153861822027"></a>config</strong>: configuration of the RDB store.</li><li><strong id="b175492306216"><a name="b175492306216"></a><a name="b175492306216"></a>version</strong>: version of the RDB store.</li></ul>
</td>
</tr>
<tr id="row1423210186365"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.4.1.1 "><p id="p94441216175111"><a name="p94441216175111"></a><a name="p94441216175111"></a>dataRdb</p>
</td>
<td class="cellrowborder" valign="top" width="30.61%" headers="mcps1.2.4.1.2 "><p id="p1056516197468"><a name="p1056516197468"></a><a name="p1056516197468"></a>deleteRdbStore(name: string, callback: AsyncCallback&lt;void&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.739999999999995%" headers="mcps1.2.4.1.3 "><p id="p761845132510"><a name="p761845132510"></a><a name="p761845132510"></a>Deletes an RDB store. This method uses a callback to return the result.</p>
<a name="ul11527402717"></a><a name="ul11527402717"></a><ul id="ul11527402717"><li><strong id="b152695571624"><a name="b152695571624"></a><a name="b152695571624"></a>name</strong>: name of the RDB store to delete.</li><li><strong id="b11959131911316"><a name="b11959131911316"></a><a name="b11959131911316"></a>callback</strong>: callback invoked to return the result. If the RDB store is deleted, <strong id="b717583515112554"><a name="b717583515112554"></a><a name="b717583515112554"></a>true</strong> will be returned. Otherwise, <strong id="b1492094045112554"><a name="b1492094045112554"></a><a name="b1492094045112554"></a>false</strong> will be returned.</li></ul>
</td>
</tr>
<tr id="row923319186367"><td class="cellrowborder" valign="top" width="16.650000000000002%" headers="mcps1.2.4.1.1 "><p id="p66511731173510"><a name="p66511731173510"></a><a name="p66511731173510"></a>dataRdb</p>
</td>
<td class="cellrowborder" valign="top" width="30.61%" headers="mcps1.2.4.1.2 "><p id="p29801620134717"><a name="p29801620134717"></a><a name="p29801620134717"></a>deleteRdbStore(name: string): Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.739999999999995%" headers="mcps1.2.4.1.3 "><p id="p1112512307296"><a name="p1112512307296"></a><a name="p1112512307296"></a>Deletes an RDB store. This method uses a promise to return the result.</p>
<a name="ul114112033"></a><a name="ul114112033"></a><ul id="ul114112033"><li><strong id="b8147125819315"><a name="b8147125819315"></a><a name="b8147125819315"></a>name</strong>: name of the RDB store to delete.</li></ul>
</td>
</tr>
</tbody>
</table>

**Managing Data in an RDB Store**

The RDB provides APIs for inserting, deleting, modifying, and querying data in the local RDB store.

-   **Inserting data**

    The RDB provides methods for inserting data through  **ValuesBucket**  in a data table. If the data is inserted successfully, the row number of the data inserted is returned; otherwise,  **-1**  is returned.

    **Table  2**  APIs for inserting data to a data table

    <a name="table96811457164612"></a>
    <table><thead align="left"><tr id="row1971245734616"><th class="cellrowborder" valign="top" width="11.53%" id="mcps1.2.4.1.1"><p id="p102415083812"><a name="p102415083812"></a><a name="p102415083812"></a>Class</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.230000000000004%" id="mcps1.2.4.1.2"><p id="p371235717461"><a name="p371235717461"></a><a name="p371235717461"></a>API</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.239999999999995%" id="mcps1.2.4.1.3"><p id="p471215713468"><a name="p471215713468"></a><a name="p471215713468"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14918412104220"><td class="cellrowborder" valign="top" width="11.53%" headers="mcps1.2.4.1.1 "><p id="p691914127421"><a name="p691914127421"></a><a name="p691914127421"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.230000000000004%" headers="mcps1.2.4.1.2 "><p id="p12888149165312"><a name="p12888149165312"></a><a name="p12888149165312"></a>insert(name: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p891981214423"><a name="p891981214423"></a><a name="p891981214423"></a>Inserts a row of data into a table. This method uses a callback to return the result.</p>
    <a name="ul929362324319"></a><a name="ul929362324319"></a><ul id="ul929362324319"><li><strong id="b791810215118"><a name="b791810215118"></a><a name="b791810215118"></a>name</strong>: name of the target table.</li><li><strong id="b1168133481113"><a name="b1168133481113"></a><a name="b1168133481113"></a>values</strong>: data to be inserted into the table.</li><li><strong id="b153601828111218"><a name="b153601828111218"></a><a name="b153601828111218"></a>callback</strong>: callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, <strong id="b1062976631112554"><a name="b1062976631112554"></a><a name="b1062976631112554"></a>-1</strong> will be returned.</li></ul>
    </td>
    </tr>
    <tr id="row17129579467"><td class="cellrowborder" valign="top" width="11.53%" headers="mcps1.2.4.1.1 "><p id="p6240010381"><a name="p6240010381"></a><a name="p6240010381"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.230000000000004%" headers="mcps1.2.4.1.2 "><p id="p18352838115114"><a name="p18352838115114"></a><a name="p18352838115114"></a>insert(name: string, values: ValuesBucket): Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p579311300812"><a name="p579311300812"></a><a name="p579311300812"></a>Inserts a row of data into a table. This method uses a promise to return the result.</p>
    <a name="ul121533410439"></a><a name="ul121533410439"></a><ul id="ul121533410439"><li><strong id="b928413422120"><a name="b928413422120"></a><a name="b928413422120"></a>name</strong>: name of the target table.</li><li><strong id="b17334499123"><a name="b17334499123"></a><a name="b17334499123"></a>values</strong>: data to be inserted into the table.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   **Updating data**

    Call the  **update\(\)**  method to pass the new data and specify the update conditions by using  **RdbPredicates**. If the data is successfully updated, the row number of the updated data is returned; otherwise,  **0**  is returned.

    **Table  3**  APIs for updating data

    <a name="table183714445119"></a>
    <table><thead align="left"><tr id="row766194475113"><th class="cellrowborder" valign="top" width="8.92%" id="mcps1.2.4.1.1"><p id="p987519262464"><a name="p987519262464"></a><a name="p987519262464"></a>Class</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.050000000000004%" id="mcps1.2.4.1.2"><p id="p1766144165119"><a name="p1766144165119"></a><a name="p1766144165119"></a>API</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.03%" id="mcps1.2.4.1.3"><p id="p16663445516"><a name="p16663445516"></a><a name="p16663445516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1597713174814"><td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.2.4.1.1 "><p id="p14978183124810"><a name="p14978183124810"></a><a name="p14978183124810"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.4.1.2 "><p id="p17502226105513"><a name="p17502226105513"></a><a name="p17502226105513"></a>update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.03%" headers="mcps1.2.4.1.3 "><p id="p173581429117"><a name="p173581429117"></a><a name="p173581429117"></a>Updates the data that meets the conditions specified by the <strong id="b656572122112554"><a name="b656572122112554"></a><a name="b656572122112554"></a>RdbPredicates</strong> object. This method uses a callback to return the result.</p>
    <a name="ul192831157114818"></a><a name="ul192831157114818"></a><ul id="ul192831157114818"><li><strong id="b174257709112554"><a name="b174257709112554"></a><a name="b174257709112554"></a>values</strong>: data to update, which is stored in <strong id="b721764115206"><a name="b721764115206"></a><a name="b721764115206"></a>ValuesBucket</strong>.</li><li><strong id="b09125491559"><a name="b09125491559"></a><a name="b09125491559"></a>rdbPredicates</strong>: conditions for updating data.</li><li><strong id="b10866112471917"><a name="b10866112471917"></a><a name="b10866112471917"></a>callback</strong>: callback invoked to return the number of rows updated.</li></ul>
    </td>
    </tr>
    <tr id="row9207612172712"><td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.2.4.1.1 "><p id="p287617260466"><a name="p287617260466"></a><a name="p287617260466"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.4.1.2 "><p id="p19559457195711"><a name="p19559457195711"></a><a name="p19559457195711"></a>update(values: ValuesBucket, rdbPredicates: RdbPredicates): Promise</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.03%" headers="mcps1.2.4.1.3 "><p id="p102077125277"><a name="p102077125277"></a><a name="p102077125277"></a>Updates the data that meets the conditions specified by the <strong id="b11262847102416"><a name="b11262847102416"></a><a name="b11262847102416"></a>RdbPredicates</strong> object. This method uses a promise to return the result.</p>
    <a name="ul3397556155017"></a><a name="ul3397556155017"></a><ul id="ul3397556155017"><li><strong id="b694170152510"><a name="b694170152510"></a><a name="b694170152510"></a>values</strong>: data to update, which is stored in <strong id="b3949012512"><a name="b3949012512"></a><a name="b3949012512"></a>ValuesBucket</strong>.</li><li><strong id="b1992219615"><a name="b1992219615"></a><a name="b1992219615"></a>rdbPredicates</strong>: conditions for updating data.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   **Deleting data**

    Call the  **delete\(\)**  method to delete data meeting the conditions specified by  **RdbPredicates**. If the data is deleted, the row number of the deleted data is returned; otherwise,  **0**  is returned.

    **Table  4**  APIs for deleting data

    <a name="table12163622913"></a>
    <table><thead align="left"><tr id="row111891027912"><th class="cellrowborder" valign="top" width="10.02%" id="mcps1.2.4.1.1"><p id="p3130348174917"><a name="p3130348174917"></a><a name="p3130348174917"></a>Class</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.440000000000005%" id="mcps1.2.4.1.2"><p id="p16189172593"><a name="p16189172593"></a><a name="p16189172593"></a>API</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.54%" id="mcps1.2.4.1.3"><p id="p191899219916"><a name="p191899219916"></a><a name="p191899219916"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row23075814814"><td class="cellrowborder" valign="top" width="10.02%" headers="mcps1.2.4.1.1 "><p id="p181301484494"><a name="p181301484494"></a><a name="p181301484494"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.440000000000005%" headers="mcps1.2.4.1.2 "><p id="p8308781086"><a name="p8308781086"></a><a name="p8308781086"></a>delete(rdbPredicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.54%" headers="mcps1.2.4.1.3 "><p id="p1746563812810"><a name="p1746563812810"></a><a name="p1746563812810"></a>Deletes data based on the conditions specified by <strong id="b25823275112554"><a name="b25823275112554"></a><a name="b25823275112554"></a>RdbPredicates</strong>. This method uses a callback to return the result.</p>
    <a name="ul199371937131312"></a><a name="ul199371937131312"></a><ul id="ul199371937131312"><li><strong id="b9647017192914"><a name="b9647017192914"></a><a name="b9647017192914"></a>rdbPredicates</strong>: conditions for deleting data.</li><li><strong id="b99708313304"><a name="b99708313304"></a><a name="b99708313304"></a>callback</strong>: callback invoked to return the number of rows deleted.</li></ul>
    </td>
    </tr>
    <tr id="row124255515487"><td class="cellrowborder" valign="top" width="10.02%" headers="mcps1.2.4.1.1 "><p id="p1642575144818"><a name="p1642575144818"></a><a name="p1642575144818"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.440000000000005%" headers="mcps1.2.4.1.2 "><p id="p194252051194818"><a name="p194252051194818"></a><a name="p194252051194818"></a>delete(rdbPredicates: RdbPredicates): Promise</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.54%" headers="mcps1.2.4.1.3 "><p id="p124258512483"><a name="p124258512483"></a><a name="p124258512483"></a>Deletes data based on the conditions specified by <strong id="b801327406112554"><a name="b801327406112554"></a><a name="b801327406112554"></a>RdbPredicates</strong>. This method uses a promise to return the result.</p>
    <a name="ul0605102031416"></a><a name="ul0605102031416"></a><ul id="ul0605102031416"><li><strong id="b220745383116"><a name="b220745383116"></a><a name="b220745383116"></a>rdbPredicates</strong>: conditions for deleting data.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   **Querying data**

    You can query data in the RDB in either of the following ways:

    -   Call the  **query**  method to query data based on the predicates, without passing any SQL statement.
    -   Run the native SQL statement.

    **Table  5**  APIs for querying data

    <a name="table1431902161617"></a>
    <table><thead align="left"><tr id="row2350122161613"><th class="cellrowborder" valign="top" width="12.46%" id="mcps1.2.4.1.1"><p id="p114619172530"><a name="p114619172530"></a><a name="p114619172530"></a>Class</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.97%" id="mcps1.2.4.1.2"><p id="p163501211165"><a name="p163501211165"></a><a name="p163501211165"></a>API</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.57%" id="mcps1.2.4.1.3"><p id="p1635118221618"><a name="p1635118221618"></a><a name="p1635118221618"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1351629160"><td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.4.1.1 "><p id="p314691719532"><a name="p314691719532"></a><a name="p314691719532"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.97%" headers="mcps1.2.4.1.2 "><p id="p1365120526456"><a name="p1365120526456"></a><a name="p1365120526456"></a>query(rdbPredicates: RdbPredicates, columns: Array, callback: AsyncCallback&lt;ResultSet&gt;): void;</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.57%" headers="mcps1.2.4.1.3 "><p id="p854321661212"><a name="p854321661212"></a><a name="p854321661212"></a>Queries data in the database based on specified conditions. This method uses a callback to return the result.</p>
    <a name="ul8744621511"></a><a name="ul8744621511"></a><ul id="ul8744621511"><li><strong id="b10609165211337"><a name="b10609165211337"></a><a name="b10609165211337"></a>rdbPredicates</strong>: conditions for querying data.</li></ul>
    <a name="ul976011905112"></a><a name="ul976011905112"></a><ul id="ul976011905112"><li><strong id="b017915301348"><a name="b017915301348"></a><a name="b017915301348"></a>columns</strong>: columns to query. If this parameter is not specified, the query applies to all columns.</li><li><strong id="b45789585356"><a name="b45789585356"></a><a name="b45789585356"></a>callback</strong>: callback invoked to return the result. If the operation is successful, a <strong id="b575560452112554"><a name="b575560452112554"></a><a name="b575560452112554"></a>ResultSet</strong> object will be returned.</li></ul>
    </td>
    </tr>
    <tr id="row156116124816"><td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.4.1.1 "><p id="p66112124816"><a name="p66112124816"></a><a name="p66112124816"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.97%" headers="mcps1.2.4.1.2 "><p id="p194111833115618"><a name="p194111833115618"></a><a name="p194111833115618"></a>query(rdbPredicates: RdbPredicates, columns: Array): Promise&lt;ResultSet&gt;;</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.57%" headers="mcps1.2.4.1.3 "><p id="p3681422175117"><a name="p3681422175117"></a><a name="p3681422175117"></a>Queries data in the database based on specified conditions. This method uses a promise to return the result.</p>
    <a name="ul882719171553"></a><a name="ul882719171553"></a><ul id="ul882719171553"><li><strong id="b42961422123414"><a name="b42961422123414"></a><a name="b42961422123414"></a>rdbPredicates</strong>: conditions for querying data.</li></ul>
    <a name="ul982714175553"></a><a name="ul982714175553"></a><ul id="ul982714175553"><li><strong id="b1556413233711"><a name="b1556413233711"></a><a name="b1556413233711"></a>columns</strong>: columns to query. If this parameter is not specified, the query applies to all columns.</li></ul>
    </td>
    </tr>
    <tr id="row196741256281"><td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.4.1.1 "><p id="p567445132814"><a name="p567445132814"></a><a name="p567445132814"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.97%" headers="mcps1.2.4.1.2 "><p id="p66741959283"><a name="p66741959283"></a><a name="p66741959283"></a>querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.57%" headers="mcps1.2.4.1.3 "><p id="p767418510287"><a name="p767418510287"></a><a name="p767418510287"></a>Queries data in the RDB store using the specified SQL statement. This method uses a callback to return the result.</p>
    <a name="ul98232063110"></a><a name="ul98232063110"></a><ul id="ul98232063110"><li><strong id="b161631620174220"><a name="b161631620174220"></a><a name="b161631620174220"></a>sql</strong>: SQL statement.</li></ul>
    <a name="ul982192010316"></a><a name="ul982192010316"></a><ul id="ul982192010316"><li><strong id="b125394844210"><a name="b125394844210"></a><a name="b125394844210"></a>bindArgs</strong>: arguments in the SQL statement.</li><li><strong id="b126351142164316"><a name="b126351142164316"></a><a name="b126351142164316"></a>callback</strong>: callback invoked to return the result. If the operation is successful, a <strong id="b1798798407112554"><a name="b1798798407112554"></a><a name="b1798798407112554"></a>ResultSet</strong> object will be returned.</li></ul>
    </td>
    </tr>
    <tr id="row14262191015289"><td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.4.1.1 "><p id="p132621010122817"><a name="p132621010122817"></a><a name="p132621010122817"></a>RdbStore</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.97%" headers="mcps1.2.4.1.2 "><p id="p5262510122817"><a name="p5262510122817"></a><a name="p5262510122817"></a>querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.57%" headers="mcps1.2.4.1.3 "><p id="p15262131018288"><a name="p15262131018288"></a><a name="p15262131018288"></a>Queries data in the RDB store using the specified SQL statement. This method uses a promise to return the result.</p>
    <a name="ul265516228313"></a><a name="ul265516228313"></a><ul id="ul265516228313"><li><strong id="b17420163394412"><a name="b17420163394412"></a><a name="b17420163394412"></a>sql</strong>: SQL statement.</li></ul>
    <a name="ul36551222123116"></a><a name="ul36551222123116"></a><ul id="ul36551222123116"><li><strong id="b19751173811446"><a name="b19751173811446"></a><a name="b19751173811446"></a>bindArgs</strong>: arguments in the SQL statement.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


**Using Predicates**

The RDB provides  **RdbPredicates**  for you to set database operation conditions.

**Table  6**  APIs for RDB predicates

<a name="table1431052112351"></a>
<table><thead align="left"><tr id="row1345821123514"><th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.2.4.1.1"><p id="p142295625511"><a name="p142295625511"></a><a name="p142295625511"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="39.910000000000004%" id="mcps1.2.4.1.2"><p id="p1034572111355"><a name="p1034572111355"></a><a name="p1034572111355"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="46.239999999999995%" id="mcps1.2.4.1.3"><p id="p193451621113517"><a name="p193451621113517"></a><a name="p193451621113517"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row434562114350"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p164375497585"><a name="p164375497585"></a><a name="p164375497585"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p1984411183347"><a name="p1984411183347"></a><a name="p1984411183347"></a>equalTo(field: string, value: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p10345221143519"><a name="p10345221143519"></a><a name="p10345221143519"></a>Sets the <strong id="b438950696112554"><a name="b438950696112554"></a><a name="b438950696112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b749976932112554"><a name="b749976932112554"></a><a name="b749976932112554"></a>ValueType</strong> and value equal to the specified value.</p>
<a name="ul39107814371"></a><a name="ul39107814371"></a><ul id="ul39107814371"><li><strong id="b15195122118513"><a name="b15195122118513"></a><a name="b15195122118513"></a>field</strong>: column name in the database table.</li><li><strong id="b18580195411521"><a name="b18580195411521"></a><a name="b18580195411521"></a>value</strong>: value to match the <strong id="b119217321114"><a name="b119217321114"></a><a name="b119217321114"></a>RdbPredicates</strong>.</li><li><strong id="b82912449110"><a name="b82912449110"></a><a name="b82912449110"></a>RdbPredicates</strong>: <strong id="b20646112018129"><a name="b20646112018129"></a><a name="b20646112018129"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row734514211353"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1221568552"><a name="p1221568552"></a><a name="p1221568552"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p7639121743518"><a name="p7639121743518"></a><a name="p7639121743518"></a>notEqualTo(field: string, value: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1634522183511"><a name="p1634522183511"></a><a name="p1634522183511"></a>Sets the <strong id="b1712658660112554"><a name="b1712658660112554"></a><a name="b1712658660112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b726568859112554"><a name="b726568859112554"></a><a name="b726568859112554"></a>ValueType</strong> and value not equal to the specified value.</p>
<a name="ul415220710398"></a><a name="ul415220710398"></a><ul id="ul415220710398"><li><strong id="b066019819910"><a name="b066019819910"></a><a name="b066019819910"></a>field</strong>: column name in the database table.</li><li><strong id="b1810912616128"><a name="b1810912616128"></a><a name="b1810912616128"></a>value</strong>: value to match the <strong id="b1010920661216"><a name="b1010920661216"></a><a name="b1010920661216"></a>RdbPredicates</strong>.</li><li><strong id="b63152431127"><a name="b63152431127"></a><a name="b63152431127"></a>RdbPredicates</strong>: <strong id="b133155430127"><a name="b133155430127"></a><a name="b133155430127"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row634552123510"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1523656185515"><a name="p1523656185515"></a><a name="p1523656185515"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p1629732110412"><a name="p1629732110412"></a><a name="p1629732110412"></a>beginWrap(): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1334652112353"><a name="p1334652112353"></a><a name="p1334652112353"></a>Adds a left parenthesis to the <strong id="b183257951112554"><a name="b183257951112554"></a><a name="b183257951112554"></a>RdbPredicates</strong>.</p>
<a name="ul3808195613915"></a><a name="ul3808195613915"></a><ul id="ul3808195613915"><li><strong id="b1146415308136"><a name="b1146415308136"></a><a name="b1146415308136"></a>RdbPredicates</strong>: <strong id="b145191852171313"><a name="b145191852171313"></a><a name="b145191852171313"></a>RdbPredicates</strong> with a left parenthesis.</li></ul>
</td>
</tr>
<tr id="row1034662163515"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1223456145516"><a name="p1223456145516"></a><a name="p1223456145516"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p4253185154216"><a name="p4253185154216"></a><a name="p4253185154216"></a>endWrap(): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1634620216353"><a name="p1634620216353"></a><a name="p1634620216353"></a>Adds a right parenthesis to the <strong id="b717084362112554"><a name="b717084362112554"></a><a name="b717084362112554"></a>RdbPredicates</strong>.</p>
<a name="ul952384823816"></a><a name="ul952384823816"></a><ul id="ul952384823816"><li><strong id="b622114010147"><a name="b622114010147"></a><a name="b622114010147"></a>RdbPredicates</strong>: <strong id="b92234051419"><a name="b92234051419"></a><a name="b92234051419"></a>RdbPredicates</strong> with a right parenthesis.</li></ul>
</td>
</tr>
<tr id="row193467215353"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1223856175513"><a name="p1223856175513"></a><a name="p1223856175513"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p782515201423"><a name="p782515201423"></a><a name="p782515201423"></a>or(): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p934672153514"><a name="p934672153514"></a><a name="p934672153514"></a>Adds the OR condition to the <strong id="b1180485437112554"><a name="b1180485437112554"></a><a name="b1180485437112554"></a>RdbPredicates</strong>.</p>
<a name="ul1431681603915"></a><a name="ul1431681603915"></a><ul id="ul1431681603915"><li><strong id="b439496101515"><a name="b439496101515"></a><a name="b439496101515"></a>RdbPredicates</strong>: <strong id="b1839456191515"><a name="b1839456191515"></a><a name="b1839456191515"></a>RdbPredicates</strong> with the OR condition.</li></ul>
</td>
</tr>
<tr id="row158263516300"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1282615143010"><a name="p1282615143010"></a><a name="p1282615143010"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p9222442144210"><a name="p9222442144210"></a><a name="p9222442144210"></a>and(): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1388710815510"><a name="p1388710815510"></a><a name="p1388710815510"></a>Adds the AND condition to the <strong id="b257471589112554"><a name="b257471589112554"></a><a name="b257471589112554"></a>RdbPredicates</strong>.</p>
<a name="ul1727699185710"></a><a name="ul1727699185710"></a><ul id="ul1727699185710"><li><strong id="b18566227141510"><a name="b18566227141510"></a><a name="b18566227141510"></a>RdbPredicates</strong>: <strong id="b185661227171511"><a name="b185661227171511"></a><a name="b185661227171511"></a>RdbPredicates</strong> with the AND condition.</li></ul>
</td>
</tr>
<tr id="row243103215346"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p114393263410"><a name="p114393263410"></a><a name="p114393263410"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p691261154313"><a name="p691261154313"></a><a name="p691261154313"></a>contains(field: string, value: string): RdbPredicats</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p138987821811"><a name="p138987821811"></a><a name="p138987821811"></a>Sets the <strong id="b1636898418112554"><a name="b1636898418112554"></a><a name="b1636898418112554"></a>RdbPredicates</strong> to match a string containing the specified value.</p>
<a name="ul187302357573"></a><a name="ul187302357573"></a><ul id="ul187302357573"><li><strong id="b0662138791"><a name="b0662138791"></a><a name="b0662138791"></a>field</strong>: column name in the database table.</li><li><strong id="b7114767121"><a name="b7114767121"></a><a name="b7114767121"></a>value</strong>: value to match the <strong id="b611466151215"><a name="b611466151215"></a><a name="b611466151215"></a>RdbPredicates</strong>.</li><li>RdbPredicates: <strong id="b14967161332010"><a name="b14967161332010"></a><a name="b14967161332010"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row1823275015527"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p172327507529"><a name="p172327507529"></a><a name="p172327507529"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p111451435154314"><a name="p111451435154314"></a><a name="p111451435154314"></a>beginsWith(field: string, value: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p102321950135210"><a name="p102321950135210"></a><a name="p102321950135210"></a>Sets the <strong id="b895587112554"><a name="b895587112554"></a><a name="b895587112554"></a>RdbPredicates</strong> to match a string that starts with the specified value.</p>
<a name="ul3643102216597"></a><a name="ul3643102216597"></a><ul id="ul3643102216597"><li><strong id="b176634812918"><a name="b176634812918"></a><a name="b176634812918"></a>field</strong>: column name in the database table.</li><li><strong id="b91196671210"><a name="b91196671210"></a><a name="b91196671210"></a>value</strong>: value to match the <strong id="b12119865128"><a name="b12119865128"></a><a name="b12119865128"></a>RdbPredicates</strong>.</li><li><strong id="b163192043181211"><a name="b163192043181211"></a><a name="b163192043181211"></a>RdbPredicates</strong>: <strong id="b13191043101217"><a name="b13191043101217"></a><a name="b13191043101217"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row86756195213"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p566562527"><a name="p566562527"></a><a name="p566562527"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p46356185216"><a name="p46356185216"></a><a name="p46356185216"></a>endsWith(field: string, value: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1063562529"><a name="p1063562529"></a><a name="p1063562529"></a>Sets the <strong id="b1056875172112554"><a name="b1056875172112554"></a><a name="b1056875172112554"></a>RdbPredicates</strong> to match a string that ends with the specified value.</p>
<a name="ul6905132213012"></a><a name="ul6905132213012"></a><ul id="ul6905132213012"><li><strong id="b46643820919"><a name="b46643820919"></a><a name="b46643820919"></a>field</strong>: column name in the database table.</li><li><strong id="b121239671216"><a name="b121239671216"></a><a name="b121239671216"></a>value</strong>: value to match the <strong id="b912317619121"><a name="b912317619121"></a><a name="b912317619121"></a>RdbPredicates</strong>.</li><li><strong id="b103211043131213"><a name="b103211043131213"></a><a name="b103211043131213"></a>RdbPredicates</strong>: <strong id="b20321104319124"><a name="b20321104319124"></a><a name="b20321104319124"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row58214297537"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p3822152917531"><a name="p3822152917531"></a><a name="p3822152917531"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p696112904411"><a name="p696112904411"></a><a name="p696112904411"></a>isNull(field: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p2822172913538"><a name="p2822172913538"></a><a name="p2822172913538"></a>Sets the <strong id="b1194045299112554"><a name="b1194045299112554"></a><a name="b1194045299112554"></a>RdbPredicates</strong> to match the field whose value is <strong id="b1890023078112554"><a name="b1890023078112554"></a><a name="b1890023078112554"></a>null</strong>.</p>
<a name="ul152823233592"></a><a name="ul152823233592"></a><ul id="ul152823233592"><li><strong id="b206641881994"><a name="b206641881994"></a><a name="b206641881994"></a>field</strong>: column name in the database table.</li><li><strong id="b1774115571093"><a name="b1774115571093"></a><a name="b1774115571093"></a>RdbPredicates</strong>: <strong id="b18741165710911"><a name="b18741165710911"></a><a name="b18741165710911"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row9134111680"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1513421388"><a name="p1513421388"></a><a name="p1513421388"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p08046261449"><a name="p08046261449"></a><a name="p08046261449"></a>isNotNull(field: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p7520112182316"><a name="p7520112182316"></a><a name="p7520112182316"></a>Sets the <strong id="b1059930094112554"><a name="b1059930094112554"></a><a name="b1059930094112554"></a>RdbPredicates</strong> to match the field whose value is not <strong id="b172403177112554"><a name="b172403177112554"></a><a name="b172403177112554"></a>null</strong>.</p>
<a name="ul5646142816017"></a><a name="ul5646142816017"></a><ul id="ul5646142816017"><li><strong id="b1366598494"><a name="b1366598494"></a><a name="b1366598494"></a>field</strong>: column name in the database table.</li><li><strong id="b355418851019"><a name="b355418851019"></a><a name="b355418851019"></a>RdbPredicates</strong>: <strong id="b15541983103"><a name="b15541983103"></a><a name="b15541983103"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row1543514416811"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p643516419810"><a name="p643516419810"></a><a name="p643516419810"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p15758134720442"><a name="p15758134720442"></a><a name="p15758134720442"></a>like(field: string, value: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p753485217231"><a name="p753485217231"></a><a name="p753485217231"></a>Sets the <strong id="b964300928112554"><a name="b964300928112554"></a><a name="b964300928112554"></a>RdbPredicates</strong> to match a string that is similar to the specified value.</p>
<a name="ul15439141112"></a><a name="ul15439141112"></a><ul id="ul15439141112"><li><strong id="b1366618991"><a name="b1366618991"></a><a name="b1366618991"></a>field</strong>: column name in the database table.</li><li><strong id="b11277641210"><a name="b11277641210"></a><a name="b11277641210"></a>value</strong>: value to match the <strong id="b121272065124"><a name="b121272065124"></a><a name="b121272065124"></a>RdbPredicates</strong>.</li><li><strong id="b19556158101012"><a name="b19556158101012"></a><a name="b19556158101012"></a>RdbPredicates</strong>: <strong id="b1556484106"><a name="b1556484106"></a><a name="b1556484106"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row1596914712820"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p169691871785"><a name="p169691871785"></a><a name="p169691871785"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p372713974512"><a name="p372713974512"></a><a name="p372713974512"></a>glob(field: string, value: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p14252854172320"><a name="p14252854172320"></a><a name="p14252854172320"></a>Sets the <strong id="b644369182112554"><a name="b644369182112554"></a><a name="b644369182112554"></a>RdbPredicates</strong> to match the specified string.</p>
<a name="ul18503142413115"></a><a name="ul18503142413115"></a><ul id="ul18503142413115"><li><strong id="b5667581899"><a name="b5667581899"></a><a name="b5667581899"></a>field</strong>: column name in the database table.</li><li><strong id="b10131460122"><a name="b10131460122"></a><a name="b10131460122"></a>value</strong>: value to match the <strong id="b1313176191214"><a name="b1313176191214"></a><a name="b1313176191214"></a>RdbPredicates</strong>.</li><li><strong id="b125581984106"><a name="b125581984106"></a><a name="b125581984106"></a>RdbPredicates</strong>: <strong id="b955819810103"><a name="b955819810103"></a><a name="b955819810103"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row142751730101"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p192751938103"><a name="p192751938103"></a><a name="p192751938103"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p36191533114513"><a name="p36191533114513"></a><a name="p36191533114513"></a>between(field: string, low: ValueType, high: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1827513201020"><a name="p1827513201020"></a><a name="p1827513201020"></a>Sets the <strong id="b625856712112554"><a name="b625856712112554"></a><a name="b625856712112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b489101076112554"><a name="b489101076112554"></a><a name="b489101076112554"></a>ValueType</strong> and value within the specified range.</p>
<a name="ul3448133612117"></a><a name="ul3448133612117"></a><ul id="ul3448133612117"><li><strong id="b46682814917"><a name="b46682814917"></a><a name="b46682814917"></a>field</strong>: column name in the database table.</li><li><strong id="b062216817256"><a name="b062216817256"></a><a name="b062216817256"></a>low</strong>: minimum value that matches the <strong id="b4408649182510"><a name="b4408649182510"></a><a name="b4408649182510"></a>RdbPredicates</strong>.</li><li><strong id="b1336881318253"><a name="b1336881318253"></a><a name="b1336881318253"></a>high</strong>: maximum value that matches the <strong id="b05634512611"><a name="b05634512611"></a><a name="b05634512611"></a>RdbPredicates</strong>.</li><li><strong id="b135596841010"><a name="b135596841010"></a><a name="b135596841010"></a>RdbPredicates</strong>: <strong id="b1555913891013"><a name="b1555913891013"></a><a name="b1555913891013"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row18738551100"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p57388541019"><a name="p57388541019"></a><a name="p57388541019"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p102541595465"><a name="p102541595465"></a><a name="p102541595465"></a>notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1073914511013"><a name="p1073914511013"></a><a name="p1073914511013"></a>Sets the <strong id="b480030174112554"><a name="b480030174112554"></a><a name="b480030174112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b591370903112554"><a name="b591370903112554"></a><a name="b591370903112554"></a>ValueType</strong> and value out of the specified range.</p>
<a name="ul697416399210"></a><a name="ul697416399210"></a><ul id="ul697416399210"><li><strong id="b136681086914"><a name="b136681086914"></a><a name="b136681086914"></a>field</strong>: column name in the database table.</li><li><strong id="b4395132016267"><a name="b4395132016267"></a><a name="b4395132016267"></a>low</strong>: minimum value that matches the <strong id="b0396182092615"><a name="b0396182092615"></a><a name="b0396182092615"></a>RdbPredicates</strong>.</li><li><strong id="b16568182820262"><a name="b16568182820262"></a><a name="b16568182820262"></a>high</strong>: maximum value that matches the <strong id="b12568128132611"><a name="b12568128132611"></a><a name="b12568128132611"></a>RdbPredicates</strong>.</li><li><strong id="b25607881011"><a name="b25607881011"></a><a name="b25607881011"></a>RdbPredicates</strong>: <strong id="b256013819104"><a name="b256013819104"></a><a name="b256013819104"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row2946551141115"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p17946195191118"><a name="p17946195191118"></a><a name="p17946195191118"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p86191537184610"><a name="p86191537184610"></a><a name="p86191537184610"></a>greaterThan(field: string, value: ValueType): RdbPredicatesgr</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p129461514117"><a name="p129461514117"></a><a name="p129461514117"></a>Sets the <strong id="b299934469112554"><a name="b299934469112554"></a><a name="b299934469112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b297820682112554"><a name="b297820682112554"></a><a name="b297820682112554"></a>ValueType</strong> and value greater than the specified value.</p>
<a name="ul11811341539"></a><a name="ul11811341539"></a><ul id="ul11811341539"><li><strong id="b116691285910"><a name="b116691285910"></a><a name="b116691285910"></a>field</strong>: column name in the database table.</li><li><strong id="b7135166141214"><a name="b7135166141214"></a><a name="b7135166141214"></a>value</strong>: value to match the <strong id="b71351460123"><a name="b71351460123"></a><a name="b71351460123"></a>RdbPredicates</strong>.</li><li><strong id="b9561138131015"><a name="b9561138131015"></a><a name="b9561138131015"></a>RdbPredicates</strong>: <strong id="b1561584103"><a name="b1561584103"></a><a name="b1561584103"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row4947195461118"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p149481654191110"><a name="p149481654191110"></a><a name="p149481654191110"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p3948205414117"><a name="p3948205414117"></a><a name="p3948205414117"></a>lessThan(field: string, value: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1150510191493"><a name="p1150510191493"></a><a name="p1150510191493"></a>Sets the <strong id="b998950278112554"><a name="b998950278112554"></a><a name="b998950278112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b1745313530112554"><a name="b1745313530112554"></a><a name="b1745313530112554"></a>ValueType</strong> and value less than the specified value.</p>
<a name="ul1641512392313"></a><a name="ul1641512392313"></a><ul id="ul1641512392313"><li><strong id="b367014815919"><a name="b367014815919"></a><a name="b367014815919"></a>field</strong>: column name in the database table.</li><li><strong id="b213966181219"><a name="b213966181219"></a><a name="b213966181219"></a>value</strong>: value to match the <strong id="b161391269123"><a name="b161391269123"></a><a name="b161391269123"></a>RdbPredicates</strong>.</li><li><strong id="b17562183104"><a name="b17562183104"></a><a name="b17562183104"></a>RdbPredicates</strong>: <strong id="b156228141013"><a name="b156228141013"></a><a name="b156228141013"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row10618151417129"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p26189149128"><a name="p26189149128"></a><a name="p26189149128"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p16430131913473"><a name="p16430131913473"></a><a name="p16430131913473"></a>greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p1496111155113"><a name="p1496111155113"></a><a name="p1496111155113"></a>Sets the <strong id="b349869843112554"><a name="b349869843112554"></a><a name="b349869843112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b634300709112554"><a name="b634300709112554"></a><a name="b634300709112554"></a>ValueType</strong> and value greater than or equal to the specified value.</p>
<a name="ul1169911541738"></a><a name="ul1169911541738"></a><ul id="ul1169911541738"><li><strong id="b86711689917"><a name="b86711689917"></a><a name="b86711689917"></a>field</strong>: column name in the database table.</li><li><strong id="b71443641215"><a name="b71443641215"></a><a name="b71443641215"></a>value</strong>: value to match the <strong id="b414420621215"><a name="b414420621215"></a><a name="b414420621215"></a>RdbPredicates</strong>.</li><li><strong id="b3563189109"><a name="b3563189109"></a><a name="b3563189109"></a>RdbPredicates</strong>: <strong id="b6563168171010"><a name="b6563168171010"></a><a name="b6563168171010"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row7691627151211"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1969427131213"><a name="p1969427131213"></a><a name="p1969427131213"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p34348284483"><a name="p34348284483"></a><a name="p34348284483"></a>lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p12181611535"><a name="p12181611535"></a><a name="p12181611535"></a>Sets the <strong id="b312137118112554"><a name="b312137118112554"></a><a name="b312137118112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b304585139112554"><a name="b304585139112554"></a><a name="b304585139112554"></a>ValueType</strong> and value less than or equal to the specified value.</p>
<a name="ul954651146"></a><a name="ul954651146"></a><ul id="ul954651146"><li><strong id="b3672785911"><a name="b3672785911"></a><a name="b3672785911"></a>field</strong>: column name in the database table.</li><li><strong id="b14148146141213"><a name="b14148146141213"></a><a name="b14148146141213"></a>value</strong>: value to match the <strong id="b21481362121"><a name="b21481362121"></a><a name="b21481362121"></a>RdbPredicates</strong>.</li><li><strong id="b1056414811010"><a name="b1056414811010"></a><a name="b1056414811010"></a>RdbPredicates</strong>: <strong id="b20564128141016"><a name="b20564128141016"></a><a name="b20564128141016"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row131173871211"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p15110384126"><a name="p15110384126"></a><a name="p15110384126"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p12573121712492"><a name="p12573121712492"></a><a name="p12573121712492"></a>orderByAsc(field: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p31119384125"><a name="p31119384125"></a><a name="p31119384125"></a>Sets the <strong id="b688515142112554"><a name="b688515142112554"></a><a name="b688515142112554"></a>RdbPredicates</strong> to match the column with values sorted in ascending order.</p>
<a name="ul12611201211416"></a><a name="ul12611201211416"></a><ul id="ul12611201211416"><li><strong id="b20672881395"><a name="b20672881395"></a><a name="b20672881395"></a>field</strong>: column name in the database table.</li><li><strong id="b4565481101"><a name="b4565481101"></a><a name="b4565481101"></a>RdbPredicates</strong>: <strong id="b1956515816107"><a name="b1956515816107"></a><a name="b1956515816107"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row112261741171218"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p422611417127"><a name="p422611417127"></a><a name="p422611417127"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p622664161218"><a name="p622664161218"></a><a name="p622664161218"></a>orderByDesc(field: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p152261741201214"><a name="p152261741201214"></a><a name="p152261741201214"></a>Sets the <strong id="b1784358755112554"><a name="b1784358755112554"></a><a name="b1784358755112554"></a>RdbPredicates</strong> to match the column with values sorted in descending order.</p>
<a name="ul17931024747"></a><a name="ul17931024747"></a><ul id="ul17931024747"><li><strong id="b106731081197"><a name="b106731081197"></a><a name="b106731081197"></a>field</strong>: column name in the database table.</li><li><strong id="b15661871013"><a name="b15661871013"></a><a name="b15661871013"></a>RdbPredicates</strong>: <strong id="b55664821014"><a name="b55664821014"></a><a name="b55664821014"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row9961113773315"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p29616370334"><a name="p29616370334"></a><a name="p29616370334"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p9260141911516"><a name="p9260141911516"></a><a name="p9260141911516"></a>distinct(): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p79613373335"><a name="p79613373335"></a><a name="p79613373335"></a>Sets the <strong id="b1849038781112554"><a name="b1849038781112554"></a><a name="b1849038781112554"></a>RdbPredicates</strong> to filter out duplicate records.</p>
<a name="ul9247643548"></a><a name="ul9247643548"></a><ul id="ul9247643548"><li><strong id="b8216555102712"><a name="b8216555102712"></a><a name="b8216555102712"></a>RdbPredicates</strong>: <strong id="b154056214288"><a name="b154056214288"></a><a name="b154056214288"></a>RdbPredicates</strong> that can filter out duplicate records.</li></ul>
</td>
</tr>
<tr id="row117447163520"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p167444123514"><a name="p167444123514"></a><a name="p167444123514"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p1744191163517"><a name="p1744191163517"></a><a name="p1744191163517"></a>limitAs(value: number): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p167441813355"><a name="p167441813355"></a><a name="p167441813355"></a>Sets the <strong id="b1852235509112554"><a name="b1852235509112554"></a><a name="b1852235509112554"></a>RdbPredicates</strong> to specify the maximum number of records to match in a column.</p>
<a name="ul99331016519"></a><a name="ul99331016519"></a><ul id="ul99331016519"><li><strong id="b1066132843113"><a name="b1066132843113"></a><a name="b1066132843113"></a>value</strong>: maximum number of records in a column.</li><li><strong id="b2596134933112"><a name="b2596134933112"></a><a name="b2596134933112"></a>RdbPredicates</strong>: <strong id="b17201911321"><a name="b17201911321"></a><a name="b17201911321"></a>RdbPredicates</strong> that can be used to set the maximum number of records to match in a column.</li></ul>
</td>
</tr>
<tr id="row13215105816343"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p192151858183419"><a name="p192151858183419"></a><a name="p192151858183419"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p9259827135217"><a name="p9259827135217"></a><a name="p9259827135217"></a>offsetAs(rowOffset: number): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p621595810347"><a name="p621595810347"></a><a name="p621595810347"></a>Sets the <strong id="b330697748112554"><a name="b330697748112554"></a><a name="b330697748112554"></a>RdbPredicates</strong> to specify the start position of the returned result.</p>
<a name="ul16890144017919"></a><a name="ul16890144017919"></a><ul id="ul16890144017919"><li><strong id="b4801398332"><a name="b4801398332"></a><a name="b4801398332"></a>rowOffset</strong>: start position of the returned result. The value is a positive integer.</li><li><strong id="b15974182419334"><a name="b15974182419334"></a><a name="b15974182419334"></a>RdbPredicates</strong>: <strong id="b117772378336"><a name="b117772378336"></a><a name="b117772378336"></a>RdbPredicates</strong> object that specifies the start position of the returned result.</li></ul>
</td>
</tr>
<tr id="row149737835713"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p119730835711"><a name="p119730835711"></a><a name="p119730835711"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p1132724295212"><a name="p1132724295212"></a><a name="p1132724295212"></a>groupBy(fields: Array&lt;string&gt;): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p315610216119"><a name="p315610216119"></a><a name="p315610216119"></a>Sets the <strong id="b922906078112554"><a name="b922906078112554"></a><a name="b922906078112554"></a>RdbPredicates</strong> to group rows that have the same value into summary rows.</p>
<a name="ul048292611102"></a><a name="ul048292611102"></a><ul id="ul048292611102"><li><strong id="b12152152614219"><a name="b12152152614219"></a><a name="b12152152614219"></a>fields</strong>: names of the columns grouped for querying data.</li><li><strong id="b107111444315"><a name="b107111444315"></a><a name="b107111444315"></a>RdbPredicates</strong>: <strong id="b1693008184315"><a name="b1693008184315"></a><a name="b1693008184315"></a>RdbPredicates</strong> that groups rows that have the same value.</li></ul>
</td>
</tr>
<tr id="row1938314155717"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p23836465712"><a name="p23836465712"></a><a name="p23836465712"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p14827457175217"><a name="p14827457175217"></a><a name="p14827457175217"></a>indexedBy(indexName: string): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p784844513588"><a name="p784844513588"></a><a name="p784844513588"></a>Sets the <strong id="b1547335609112554"><a name="b1547335609112554"></a><a name="b1547335609112554"></a>RdbPredicates</strong> object to specify the index column.</p>
<a name="ul14142173351011"></a><a name="ul14142173351011"></a><ul id="ul14142173351011"><li><strong id="b74784474315"><a name="b74784474315"></a><a name="b74784474315"></a>indexName</strong>: name of the index column.</li><li><strong id="b8808413154415"><a name="b8808413154415"></a><a name="b8808413154415"></a>RdbPredicates</strong>: <strong id="b3808141812449"><a name="b3808141812449"></a><a name="b3808141812449"></a>RdbPredicates</strong> object that specifies the index column.</li></ul>
</td>
</tr>
<tr id="row147916365529"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p157922036145218"><a name="p157922036145218"></a><a name="p157922036145218"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p17428713185312"><a name="p17428713185312"></a><a name="p17428713185312"></a>in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p12468144012181"><a name="p12468144012181"></a><a name="p12468144012181"></a>Sets the <strong id="b1089824940112554"><a name="b1089824940112554"></a><a name="b1089824940112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b1982339248112554"><a name="b1982339248112554"></a><a name="b1982339248112554"></a>Array&lt;ValueType&gt;</strong> and value within the specified range.</p>
<a name="ul1261343010160"></a><a name="ul1261343010160"></a><ul id="ul1261343010160"><li><strong id="b2674281693"><a name="b2674281693"></a><a name="b2674281693"></a>field</strong>: column name in the database table.</li></ul>
<a name="ul12498383105"></a><a name="ul12498383105"></a><ul id="ul12498383105"><li><strong id="b495499154512"><a name="b495499154512"></a><a name="b495499154512"></a>value</strong>: array of <strong id="b161531382454"><a name="b161531382454"></a><a name="b161531382454"></a>ValueType</strong> to match.</li><li><strong id="b145677817100"><a name="b145677817100"></a><a name="b145677817100"></a>RdbPredicates</strong>: <strong id="b8567178151019"><a name="b8567178151019"></a><a name="b8567178151019"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
<tr id="row16668112817533"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p146689283532"><a name="p146689283532"></a><a name="p146689283532"></a>RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="39.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p74983294532"><a name="p74983294532"></a><a name="p74983294532"></a>notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates</p>
</td>
<td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.2.4.1.3 "><p id="p2066842875317"><a name="p2066842875317"></a><a name="p2066842875317"></a>Sets the <strong id="b2092907677112554"><a name="b2092907677112554"></a><a name="b2092907677112554"></a>RdbPredicates</strong> to match the field with data type <strong id="b30969258112554"><a name="b30969258112554"></a><a name="b30969258112554"></a>Array&lt;ValueType&gt;</strong> and value out of the specified range.</p>
<a name="ul2699143755811"></a><a name="ul2699143755811"></a><ul id="ul2699143755811"><li><strong id="b56756812910"><a name="b56756812910"></a><a name="b56756812910"></a>field</strong>: column name in the database table.</li></ul>
<a name="ul93771585122"></a><a name="ul93771585122"></a><ul id="ul93771585122"><li><strong id="b447917884619"><a name="b447917884619"></a><a name="b447917884619"></a>value</strong>: array of <strong id="b144791884611"><a name="b144791884611"></a><a name="b144791884611"></a>ValueType</strong> to match.</li><li><strong id="b155684813104"><a name="b155684813104"></a><a name="b155684813104"></a>RdbPredicates</strong>: <strong id="b115680813101"><a name="b115680813101"></a><a name="b115680813101"></a>RdbPredicates</strong> object that matches the specified field.</li></ul>
</td>
</tr>
</tbody>
</table>

**Using the Result Set**

A result set can be regarded as rows of data in the queried results. It allows you to traverse and access the data you have queried. The following table describes the external APIs of  **ResultSet**.

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>After a result set is used, you must call the  **close\(\)**  method to close it explicitly.

**Table  7**  APIs for using the result set

<a name="table20837141217325"></a>
<table><thead align="left"><tr id="row100121314329"><th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.4.1.1"><p id="p775412912565"><a name="p775412912565"></a><a name="p775412912565"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="43.46%" id="mcps1.2.4.1.2"><p id="p191913173219"><a name="p191913173219"></a><a name="p191913173219"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="46.300000000000004%" id="mcps1.2.4.1.3"><p id="p12171318326"><a name="p12171318326"></a><a name="p12171318326"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row520911313181"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p75383261001"><a name="p75383261001"></a><a name="p75383261001"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p19210173118180"><a name="p19210173118180"></a><a name="p19210173118180"></a>goTo(offset:number): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p9210183113187"><a name="p9210183113187"></a><a name="p9210183113187"></a>Moves the result set forwards or backwards by an offset relative to its current position.</p>
</td>
</tr>
<tr id="row71141310323"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p175442935616"><a name="p175442935616"></a><a name="p175442935616"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p1233611818317"><a name="p1233611818317"></a><a name="p1233611818317"></a>goToRow(position: number): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p141113153210"><a name="p141113153210"></a><a name="p141113153210"></a>Moves the result set to a specified row.</p>
</td>
</tr>
<tr id="row1923137323"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p1875442945615"><a name="p1875442945615"></a><a name="p1875442945615"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p19769183218312"><a name="p19769183218312"></a><a name="p19769183218312"></a>goToNextRow(): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p627132327"><a name="p627132327"></a><a name="p627132327"></a>Moves the result set to the next row.</p>
</td>
</tr>
<tr id="row1281316329"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p275462918568"><a name="p275462918568"></a><a name="p275462918568"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p142131311326"><a name="p142131311326"></a><a name="p142131311326"></a>goToPreviousRow(): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p1321813143210"><a name="p1321813143210"></a><a name="p1321813143210"></a>Moves the result set to the previous row.</p>
</td>
</tr>
<tr id="row1527137326"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p137542291560"><a name="p137542291560"></a><a name="p137542291560"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p191361958746"><a name="p191361958746"></a><a name="p191361958746"></a>getColumnIndex(columnName: string): number</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p0315135329"><a name="p0315135329"></a><a name="p0315135329"></a>Obtains the column index based on the specified column name.</p>
</td>
</tr>
<tr id="row53181383215"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p3754329125618"><a name="p3754329125618"></a><a name="p3754329125618"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p119675317520"><a name="p119675317520"></a><a name="p119675317520"></a>getColumnName(columnIndex: number): string</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p4341363212"><a name="p4341363212"></a><a name="p4341363212"></a>Obtains the column name based on the specified column index.</p>
</td>
</tr>
<tr id="row153013153216"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p19754172985613"><a name="p19754172985613"></a><a name="p19754172985613"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p14878197175"><a name="p14878197175"></a><a name="p14878197175"></a>goToFirstRow(): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p153513123219"><a name="p153513123219"></a><a name="p153513123219"></a>Checks whether the result set is located in the first row.</p>
</td>
</tr>
<tr id="row153413123212"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p137544291567"><a name="p137544291567"></a><a name="p137544291567"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p73121318325"><a name="p73121318325"></a><a name="p73121318325"></a>goToLastRow(): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p13381311321"><a name="p13381311321"></a><a name="p13381311321"></a>Checks whether the result set is located in the last row.</p>
</td>
</tr>
<tr id="row64313153214"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p14755629205616"><a name="p14755629205616"></a><a name="p14755629205616"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p6428451185"><a name="p6428451185"></a><a name="p6428451185"></a>getString(columnIndex: number): string</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p1651713173216"><a name="p1651713173216"></a><a name="p1651713173216"></a>Obtains the values in the specified column of the current row, in strings.</p>
</td>
</tr>
<tr id="row1052133323"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p77551529175612"><a name="p77551529175612"></a><a name="p77551529175612"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p95561131987"><a name="p95561131987"></a><a name="p95561131987"></a>getBlob(columnIndex: number): Uint8Array</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p1553134322"><a name="p1553134322"></a><a name="p1553134322"></a>Obtains the values in the specified column of the current row, in a byte array.</p>
</td>
</tr>
<tr id="row95113123215"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p5755112965619"><a name="p5755112965619"></a><a name="p5755112965619"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p1426859998"><a name="p1426859998"></a><a name="p1426859998"></a>getDouble(columnIndex: number): number</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p1854135329"><a name="p1854135329"></a><a name="p1854135329"></a>Obtains the values in the specified column of the current row, in double.</p>
</td>
</tr>
<tr id="row0297182413110"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p029811248111"><a name="p029811248111"></a><a name="p029811248111"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p529822420110"><a name="p529822420110"></a><a name="p529822420110"></a>isColumnNull(columnIndex: number): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p929814244115"><a name="p929814244115"></a><a name="p929814244115"></a>Checks whether the values in the specified column of the current row are <strong id="b1342751713112554"><a name="b1342751713112554"></a><a name="b1342751713112554"></a>null</strong>.</p>
</td>
</tr>
<tr id="row142400459115"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.4.1.1 "><p id="p12401445191113"><a name="p12401445191113"></a><a name="p12401445191113"></a>ResultSet</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p132401145151118"><a name="p132401145151118"></a><a name="p132401145151118"></a>close(): void</p>
</td>
<td class="cellrowborder" valign="top" width="46.300000000000004%" headers="mcps1.2.4.1.3 "><p id="p16240104519118"><a name="p16240104519118"></a><a name="p16240104519118"></a>Closes the result set.</p>
</td>
</tr>
</tbody>
</table>

**Encrypting an RDB Store**

You can encrypt an RDB store.

When creating an RDB store, you can add a key for security purposes. After that, the RDB store can be accessed only with the correct key. You can change the key but cannot delete it.

Once an RDB store is created without a key, you cannot add a key any longer.

**Table  8**  APIs for changing the key

<a name="table1162415825016"></a>
<table><thead align="left"><tr id="row1262417589509"><th class="cellrowborder" valign="top" width="12.11%" id="mcps1.2.4.1.1"><p id="p15624135816506"><a name="p15624135816506"></a><a name="p15624135816506"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="44.34%" id="mcps1.2.4.1.2"><p id="p1662465812509"><a name="p1662465812509"></a><a name="p1662465812509"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43.55%" id="mcps1.2.4.1.3"><p id="p136246584502"><a name="p136246584502"></a><a name="p136246584502"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row96251058195012"><td class="cellrowborder" valign="top" width="12.11%" headers="mcps1.2.4.1.1 "><p id="p062515819502"><a name="p062515819502"></a><a name="p062515819502"></a>RdbStore</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.4.1.2 "><p id="p99182034195712"><a name="p99182034195712"></a><a name="p99182034195712"></a>changeEncryptKey(newEncryptKey:Uint8Array, callback: AsyncCallback&lt;number&gt;):void;</p>
</td>
<td class="cellrowborder" valign="top" width="43.55%" headers="mcps1.2.4.1.3 "><p id="p4625115845012"><a name="p4625115845012"></a><a name="p4625115845012"></a>Changes the encryption key for an RDB store. This method uses a callback to return the result. If the key is changed, <strong id="b17911183611517"><a name="b17911183611517"></a><a name="b17911183611517"></a>0</strong> is returned. Otherwise, a non-zero value is returned.</p>
</td>
</tr>
<tr id="row1662575805017"><td class="cellrowborder" valign="top" width="12.11%" headers="mcps1.2.4.1.1 "><p id="p76252058165015"><a name="p76252058165015"></a><a name="p76252058165015"></a>RdbStore</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.4.1.2 "><p id="p1025394519554"><a name="p1025394519554"></a><a name="p1025394519554"></a>changeEncryptKey(newEncryptKey:Uint8Array): Promise&lt;number&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="43.55%" headers="mcps1.2.4.1.3 "><p id="p186252058175012"><a name="p186252058175012"></a><a name="p186252058175012"></a>Changes the encryption key for an RDB store. This method uses a promise to return the result. If the key is changed, <strong id="b4886609720"><a name="b4886609720"></a><a name="b4886609720"></a>0</strong> is returned. Otherwise, a non-zero value is returned.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section116922712311"></a>

1.  Create an RDB store.

    1.  Configure the RDB attributes, including the name and storage mode of the database and whether it is read-only.
    2.  Initialize the table structure and related data in the database.
    3.  Create an RDB store.

    The sample code is as follows:

    ```
    import dataRdb from '@ohos.data.rdb';
    
    const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
    const STORE_CONFIG = {name: "rdbstore.db",}
    
    let rdbStore = await dataRdb.getRdbStore(STORE_CONFIG, 1);
    await rdbStore.executeSql(CREATE_TABLE_TEST);
    ```

2.  Insert data.

    1.  Create a  **ValuesBucket**  object to store the data you need to insert.
    2.  Call the  **insert\(\)**  method to insert data into the RDB store.

    The sample code is as follows:

    ```
    var u8 = new Uint8Array([1, 2, 3])
    const valueBucket = {"name": "Tom", "age": 18, "salary": 100.5, "blobType": u8,}
    let insertPromise = rdbStore.insert("test", valueBucket)
    ```

3.  Query data.

    1.  Create an  **RdbPredicates**  object to specify query conditions.
    2.  Call the  **query \(\)**  method to query data in the RDB store.
    3.  Call the  **ResultSet\(\)**  method to obtain the query result.

    The sample code is as follows:

    ```
    let predicates = new dataRdb.RdbPredicates("test");
    predicates.equalTo("name", "Tom")
    let resultSet = await rdbStore.query(predicates)
    
    resultSet.goToFirstRow()
    const id = await resultSet.getLong(resultSet.getColumnIndex("id"))
    const name = await resultSet.getString(resultSet.getColumnIndex("name"))
    const age = await resultSet.getLong(resultSet.getColumnIndex("age"))
    const salary = await resultSet.getDouble(resultSet.getColumnIndex("salary"))
    const blobType = await resultSet.getBlob(resultSet.getColumnIndex("blobType"))
    
    resultSet.close()
    ```


