# Distributed Account Management<a name="EN-US_TOPIC_0000001160355878"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE** 
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import account_distributedAccount from '@ohos.account.distributedAccount';
```


## System Capabilities

SystemCapability.Account.OsAccount


## account\_distributedAccount.getDistributedAccountAbility<a name="section192192415554"></a>

getDistributedAccountAbility\(\): DistributedAccountAbility

Obtains a  **DistributedAccountAbility**  instance.

-   Return values

    <a name="table16391145317913"></a>
    <table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p6835165294410"><a name="p6835165294410"></a><a name="p6835165294410"></a><a href="#section189341937163212">DistributedAccountAbility</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p108356521449"><a name="p108356521449"></a><a name="p108356521449"></a>Instance that provides methods for querying and updating the login state of a distributed account.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    ```


## DistributedAccountAbility<a name="section189341937163212"></a>

Provides methods for querying and updating the login state of a distributed account. \(You must obtain a  **DistributedAccountAbility**  instance first.\)

### queryOsAccountDistributedInfo<a name="section7209156183516"></a>

queryOsAccountDistributedInfo\(callback: AsyncCallback<DistributedInfo\>\): void

Obtains distributed account information. This method uses an asynchronous callback to return the result.

The  **ohos.permission.MANAGE\_LOCAL\_ACCOUNTS or ohos.permission.DISTRIBUTED\_DATASYNC**  permission is required. This permission is intended for system applications only.

-   Parameters

    <a name="table114831131512"></a>
    <table><thead align="left"><tr id="row914851141517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p214819113159"><a name="p214819113159"></a><a name="p214819113159"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1214921121519"><a name="p1214921121519"></a><a name="p1214921121519"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p11491711141512"><a name="p11491711141512"></a><a name="p11491711141512"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p171491011171512"><a name="p171491011171512"></a><a name="p171491011171512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row91491211131519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1238213593910"><a name="p1238213593910"></a><a name="p1238213593910"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p173828593913"><a name="p173828593913"></a><a name="p173828593913"></a>AsyncCallback&lt;<a href="#section720518449379">DistributedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p138216591899"><a name="p138216591899"></a><a name="p138216591899"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1238218595918"><a name="p1238218595918"></a><a name="p1238218595918"></a>Callback invoked to return the distributed account information.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    accountAbility.queryOsAccountDistributedInfo((err, data) => { 
        console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
        console.log('Query account info name: ' + data.name);
        console.log('Query account info id: ' + data.id);
    });
    ```


### queryOsAccountDistributedInfo<a name="section186285471210"></a>

queryOsAccountDistributedInfo\(\): Promise<DistributedInfo\>

Obtains distributed account information. This method uses a promise to return the result asynchronously.

The  **ohos.permission.MANAGE\_LOCAL\_ACCOUNTS or ohos.permission.DISTRIBUTED\_DATASYNC**  permission is required. This permission is intended for system applications only.

-   Return values

    <a name="table1527413113225"></a>
    <table><thead align="left"><tr id="row827519116223"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="p827512192212"><a name="p827512192212"></a><a name="p827512192212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="p127515142218"><a name="p127515142218"></a><a name="p127515142218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22758142211"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="p171934599141"><a name="p171934599141"></a><a name="p171934599141"></a>Promise&lt;<a href="#section720518449379">DistributedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="p1819375961417"><a name="p1819375961417"></a><a name="p1819375961417"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    accountAbility.queryOsAccountDistributedInfo().then((data) => { 
        console.log('Query account info name: ' + data.name);
        console.log('Query account info id: ' + data.id);
    }).catch((err) => {
        console.log("queryOsAccountDistributedInfoerr: "  + JSON.stringify(err));
    });
    ```


### updateOsAccountDistributedInfo<a name="section52221846181514"></a>

updateOsAccountDistributedInfo\(accountInfo: DistributedInfo, callback: AsyncCallback<void\>\): void

Updates distributed account information. This method uses an asynchronous callback to return the result.

The  **ohos.permission.MANAGE\_LOCAL\_ACCOUNTS**  permission is required. This permission is intended for system applications only.

-   Parameters

    <a name="table822216466150"></a>
    <table><thead align="left"><tr id="row1522324617153"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p922314611514"><a name="p922314611514"></a><a name="p922314611514"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p822313469154"><a name="p822313469154"></a><a name="p822313469154"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p722394661517"><a name="p722394661517"></a><a name="p722394661517"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p422374614153"><a name="p422374614153"></a><a name="p422374614153"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15223846111519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p19136121717206"><a name="p19136121717206"></a><a name="p19136121717206"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p161361717122014"><a name="p161361717122014"></a><a name="p161361717122014"></a><a href="#section720518449379">DistributedInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7136317112017"><a name="p7136317112017"></a><a name="p7136317112017"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4376343191617"><a name="p4376343191617"></a><a name="p4376343191617"></a>Distributed account information.</p>
    </td>
    </tr>
    <tr id="row16769105315198"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p181660132015"><a name="p181660132015"></a><a name="p181660132015"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p15166015201"><a name="p15166015201"></a><a name="p15166015201"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p116681142016"><a name="p116681142016"></a><a name="p116681142016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p21661112204"><a name="p21661112204"></a><a name="p21661112204"></a>Callback invoked when the distributed account information is updated.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
    accountAbility.updateOsAccountDistributedInfo(accountInfo, (err) => { 
        console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
    });
    ```


### updateOsAccountDistributedInfo<a name="section122504611155"></a>

updateOsAccountDistributedInfo\(accountInfo: DistributedInfo\): Promise<void\>

Updates distributed account information. This method uses a promise to return the result asynchronously.

The  **ohos.permission.MANAGE\_LOCAL\_ACCOUNTS**  permission is required. This permission is intended for system applications only.

-   Parameters

    <a name="table183757341918"></a>
    <table><thead align="left"><tr id="row23761234190"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p837673171914"><a name="p837673171914"></a><a name="p837673171914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1837618371914"><a name="p1837618371914"></a><a name="p1837618371914"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p173761391912"><a name="p173761391912"></a><a name="p173761391912"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1737633141914"><a name="p1737633141914"></a><a name="p1737633141914"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13761931195"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14444202014199"><a name="p14444202014199"></a><a name="p14444202014199"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1244402010195"><a name="p1244402010195"></a><a name="p1244402010195"></a><a href="#section720518449379">DistributedInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p8444112013195"><a name="p8444112013195"></a><a name="p8444112013195"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p744452014197"><a name="p744452014197"></a><a name="p744452014197"></a>Distributed account information.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table20225174621513"></a>
    <table><thead align="left"><tr id="row18225134671517"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="p82251246171515"><a name="p82251246171515"></a><a name="p82251246171515"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="p13225546161518"><a name="p13225546161518"></a><a name="p13225546161518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16225646121517"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="p4576349151812"><a name="p4576349151812"></a><a name="p4576349151812"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="p5576134941817"><a name="p5576134941817"></a><a name="p5576134941817"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
    accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
        console.log('updateOsAccountDistributedInfo Success');
     }).catch((err) => {
        console.log("updateOsAccountDistributedInfo err: "  + JSON.stringify(err));
    });
    ```


## DistributedInfo<a name="section720518449379"></a>

Defines distributed OS account information.

<a name="t1e7d4d4f9078490d8dcdbb56465b8ab3"></a>
<table><thead align="left"><tr id="r85a1aa805727476a8e768b658530fc49"><th class="cellrowborder" valign="top" width="13.08%" id="mcps1.1.5.1.1"><p id="a58cac6e212134a42a245df58d7b6f3a3"><a name="a58cac6e212134a42a245df58d7b6f3a3"></a><a name="a58cac6e212134a42a245df58d7b6f3a3"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="8.9%" id="mcps1.1.5.1.2"><p id="ae520989fe4be4482acdfdf2c26d6517d"><a name="ae520989fe4be4482acdfdf2c26d6517d"></a><a name="ae520989fe4be4482acdfdf2c26d6517d"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.5%" id="mcps1.1.5.1.3"><p id="a6b396dd84a564272a6f3d4732b4e12fe"><a name="a6b396dd84a564272a6f3d4732b4e12fe"></a><a name="a6b396dd84a564272a6f3d4732b4e12fe"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="67.52%" id="mcps1.1.5.1.4"><p id="ae728420f819e42d1b31424ac9747665b"><a name="ae728420f819e42d1b31424ac9747665b"></a><a name="ae728420f819e42d1b31424ac9747665b"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r3e8e2a236aee4030b7f7878cf5bc7537"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="p622724611205"><a name="p622724611205"></a><a name="p622724611205"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="p9227114615203"><a name="p9227114615203"></a><a name="p9227114615203"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="p172273462204"><a name="p172273462204"></a><a name="p172273462204"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="p1773051213414"><a name="p1773051213414"></a><a name="p1773051213414"></a>Name of a distributed account. It must be a non-null string.</p>
</td>
</tr>
<tr id="row144831617482"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="p10228184662019"><a name="p10228184662019"></a><a name="p10228184662019"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="p122844612207"><a name="p122844612207"></a><a name="p122844612207"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="p1722874602015"><a name="p1722874602015"></a><a name="p1722874602015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="p171141242153717"><a name="p171141242153717"></a><a name="p171141242153717"></a>UID of a distributed account. It must be a non-null string.</p>
</td>
</tr>
<tr id="row197156101511"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="p62281846172013"><a name="p62281846172013"></a><a name="p62281846172013"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="p1722810460203"><a name="p1722810460203"></a><a name="p1722810460203"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="p4228846182017"><a name="p4228846182017"></a><a name="p4228846182017"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="p1951165714370"><a name="p1951165714370"></a><a name="p1951165714370"></a>Login state of a distributed account. The state can be login, logout, token invalid, or logoff, which correspond to the following strings respectively:</p>
<a name="ul098673061720"></a><a name="ul098673061720"></a><ul id="ul098673061720"><li>Ohos.account.event.LOGIN</li><li>Ohos.account.event.LOGOUT</li><li>Ohos.account.event.TOKEN_INVALID</li><li>Ohos.account.event.LOGOFF</li></ul>
</td>
</tr>
<tr id="row227311811513"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="p1422815463200"><a name="p1422815463200"></a><a name="p1422815463200"></a>scalableData</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="p1022834619208"><a name="p1022834619208"></a><a name="p1022834619208"></a>object</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="p17228204619208"><a name="p17228204619208"></a><a name="p17228204619208"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="p111151126143816"><a name="p111151126143816"></a><a name="p111151126143816"></a>Extended information about a distributed account. Customized information is passed in key-value pairs.</p>
<p id="p11123717144012"><a name="p11123717144012"></a><a name="p11123717144012"></a>Note: This parameter is reserved and not used in query and update methods.</p>
</td>
</tr>
</tbody>
</table>
