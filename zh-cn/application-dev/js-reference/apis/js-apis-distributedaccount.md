# 分布式帐号管理<a name="ZH-CN_TOPIC_0000001164755754"></a>

-   [导入模块](#zh-cn_topic_0000001209412247_section818153115716)
-   [account\_distributedAccount.getDistributedAccountAbility](#zh-cn_topic_0000001209412247_section192192415554)
-   [DistributedAccountAbility](#zh-cn_topic_0000001209412247_section189341937163212)
    -   [queryOsAccountDistributedInfo](#zh-cn_topic_0000001209412247_section7209156183516)
    -   [queryOsAccountDistributedInfo](#zh-cn_topic_0000001209412247_section186285471210)
    -   [updateOsAccountDistributedInfo](#zh-cn_topic_0000001209412247_section52221846181514)
    -   [updateOsAccountDistributedInfo](#zh-cn_topic_0000001209412247_section122504611155)

-   [DistributedInfo](#zh-cn_topic_0000001209412247_section720518449379)

## 导入模块<a name="zh-cn_topic_0000001209412247_section818153115716"></a>

```
import account_distributedAccount from '@ohos.account.distributedAccount';
```

## account\_distributedAccount.getDistributedAccountAbility<a name="zh-cn_topic_0000001209412247_section192192415554"></a>

getDistributedAccountAbility\(\): DistributedAccountAbility

获取分布式帐号单实例对象。

-   返回值：

    <a name="zh-cn_topic_0000001209412247_table16391145317913"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row2391145319910"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209412247_p13911353991"><a name="zh-cn_topic_0000001209412247_p13911353991"></a><a name="zh-cn_topic_0000001209412247_p13911353991"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209412247_p193911531395"><a name="zh-cn_topic_0000001209412247_p193911531395"></a><a name="zh-cn_topic_0000001209412247_p193911531395"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row1339114531391"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209412247_p6835165294410"><a name="zh-cn_topic_0000001209412247_p6835165294410"></a><a name="zh-cn_topic_0000001209412247_p6835165294410"></a><a href="#zh-cn_topic_0000001209412247_section189341937163212">DistributedAccountAbility</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209412247_p108356521449"><a name="zh-cn_topic_0000001209412247_p108356521449"></a><a name="zh-cn_topic_0000001209412247_p108356521449"></a>返回一个实例，实例提供查询和更新分布式帐号登录状态方法。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    const accountAbility = account_distributedAccount.getDistributedAccountAbility();
    ```


## DistributedAccountAbility<a name="zh-cn_topic_0000001209412247_section189341937163212"></a>

提供查询和更新分布式帐号登录状态方法\(需要先获取分布式帐号的单实例对象\)。

### queryOsAccountDistributedInfo<a name="zh-cn_topic_0000001209412247_section7209156183516"></a>

queryOsAccountDistributedInfo\(callback: AsyncCallback<DistributedInfo\>\): void

获取分布式帐号信息，使用callback回调异步返回结果。

需要权限：ohos.permission.MANAGE\_LOCAL\_ACCOUNTS，该权限仅供系统应用使用。

-   参数：

    <a name="zh-cn_topic_0000001209412247_table114831131512"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row914851141517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209412247_p214819113159"><a name="zh-cn_topic_0000001209412247_p214819113159"></a><a name="zh-cn_topic_0000001209412247_p214819113159"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209412247_p1214921121519"><a name="zh-cn_topic_0000001209412247_p1214921121519"></a><a name="zh-cn_topic_0000001209412247_p1214921121519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209412247_p11491711141512"><a name="zh-cn_topic_0000001209412247_p11491711141512"></a><a name="zh-cn_topic_0000001209412247_p11491711141512"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209412247_p171491011171512"><a name="zh-cn_topic_0000001209412247_p171491011171512"></a><a name="zh-cn_topic_0000001209412247_p171491011171512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row91491211131519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p1238213593910"><a name="zh-cn_topic_0000001209412247_p1238213593910"></a><a name="zh-cn_topic_0000001209412247_p1238213593910"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p173828593913"><a name="zh-cn_topic_0000001209412247_p173828593913"></a><a name="zh-cn_topic_0000001209412247_p173828593913"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001209412247_section720518449379">DistributedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p138216591899"><a name="zh-cn_topic_0000001209412247_p138216591899"></a><a name="zh-cn_topic_0000001209412247_p138216591899"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p1238218595918"><a name="zh-cn_topic_0000001209412247_p1238218595918"></a><a name="zh-cn_topic_0000001209412247_p1238218595918"></a>获取分布式帐号信息的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    accountAbility.queryOsAccountDistributedInfo((err, data) => { 
        console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
        console.log('Query account info name: ' + data.name);
        console.log('Query account info id: ' + data.id);
    });
    ```


### queryOsAccountDistributedInfo<a name="zh-cn_topic_0000001209412247_section186285471210"></a>

queryOsAccountDistributedInfo\(\): Promise<DistributedInfo\>

获取分布式帐号信息，使用Promise方式异步返回结果。

需要权限：ohos.permission.MANAGE\_LOCAL\_ACCOUNTS，该权限仅供系统应用使用。

-   返回值：

    <a name="zh-cn_topic_0000001209412247_table1527413113225"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row827519116223"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209412247_p827512192212"><a name="zh-cn_topic_0000001209412247_p827512192212"></a><a name="zh-cn_topic_0000001209412247_p827512192212"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209412247_p127515142218"><a name="zh-cn_topic_0000001209412247_p127515142218"></a><a name="zh-cn_topic_0000001209412247_p127515142218"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row22758142211"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209412247_p171934599141"><a name="zh-cn_topic_0000001209412247_p171934599141"></a><a name="zh-cn_topic_0000001209412247_p171934599141"></a>Promise&lt;<a href="#zh-cn_topic_0000001209412247_section720518449379">DistributedInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209412247_p1819375961417"><a name="zh-cn_topic_0000001209412247_p1819375961417"></a><a name="zh-cn_topic_0000001209412247_p1819375961417"></a>Promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    accountAbility.queryOsAccountDistributedInfo().then((data) => { 
        console.log('Query account info name: ' + data.name);
        console.log('Query account info id: ' + data.id);
    }).catch((err) => {
        console.log("queryOsAccountDistributedInfoerr: "  + JSON.stringify(err));
    });
    ```


### updateOsAccountDistributedInfo<a name="zh-cn_topic_0000001209412247_section52221846181514"></a>

updateOsAccountDistributedInfo\(accountInfo: DistributedInfo, callback: AsyncCallback<void\>\): void

更新分布式帐号信息，使用callback回调异步返回结果。

需要权限：ohos.permission.MANAGE\_LOCAL\_ACCOUNTS，该权限仅供系统应用使用。

-   参数：

    <a name="zh-cn_topic_0000001209412247_table822216466150"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row1522324617153"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209412247_p922314611514"><a name="zh-cn_topic_0000001209412247_p922314611514"></a><a name="zh-cn_topic_0000001209412247_p922314611514"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209412247_p822313469154"><a name="zh-cn_topic_0000001209412247_p822313469154"></a><a name="zh-cn_topic_0000001209412247_p822313469154"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209412247_p722394661517"><a name="zh-cn_topic_0000001209412247_p722394661517"></a><a name="zh-cn_topic_0000001209412247_p722394661517"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209412247_p422374614153"><a name="zh-cn_topic_0000001209412247_p422374614153"></a><a name="zh-cn_topic_0000001209412247_p422374614153"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row15223846111519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p19136121717206"><a name="zh-cn_topic_0000001209412247_p19136121717206"></a><a name="zh-cn_topic_0000001209412247_p19136121717206"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p161361717122014"><a name="zh-cn_topic_0000001209412247_p161361717122014"></a><a name="zh-cn_topic_0000001209412247_p161361717122014"></a><a href="#zh-cn_topic_0000001209412247_section720518449379">DistributedInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p7136317112017"><a name="zh-cn_topic_0000001209412247_p7136317112017"></a><a name="zh-cn_topic_0000001209412247_p7136317112017"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p4376343191617"><a name="zh-cn_topic_0000001209412247_p4376343191617"></a><a name="zh-cn_topic_0000001209412247_p4376343191617"></a>用于更新的分布式帐号信息。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209412247_row16769105315198"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p181660132015"><a name="zh-cn_topic_0000001209412247_p181660132015"></a><a name="zh-cn_topic_0000001209412247_p181660132015"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p15166015201"><a name="zh-cn_topic_0000001209412247_p15166015201"></a><a name="zh-cn_topic_0000001209412247_p15166015201"></a>AsyncCallback<span>&lt;</span><span>void</span><span>&gt;</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p116681142016"><a name="zh-cn_topic_0000001209412247_p116681142016"></a><a name="zh-cn_topic_0000001209412247_p116681142016"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p21661112204"><a name="zh-cn_topic_0000001209412247_p21661112204"></a><a name="zh-cn_topic_0000001209412247_p21661112204"></a>更新分布式帐号信息的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
    accountAbility.updateOsAccountDistributedInfo(accountInfo, (err) => { 
        console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
    });
    ```


### updateOsAccountDistributedInfo<a name="zh-cn_topic_0000001209412247_section122504611155"></a>

updateOsAccountDistributedInfo\(accountInfo: DistributedInfo\): Promise<void\>

更新分布式帐号信息，使用Promise方式异步返回结果。

需要权限：ohos.permission.MANAGE\_LOCAL\_ACCOUNTS，该权限仅供系统应用使用。

-   参数：

    <a name="zh-cn_topic_0000001209412247_table183757341918"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row23761234190"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209412247_p837673171914"><a name="zh-cn_topic_0000001209412247_p837673171914"></a><a name="zh-cn_topic_0000001209412247_p837673171914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209412247_p1837618371914"><a name="zh-cn_topic_0000001209412247_p1837618371914"></a><a name="zh-cn_topic_0000001209412247_p1837618371914"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209412247_p173761391912"><a name="zh-cn_topic_0000001209412247_p173761391912"></a><a name="zh-cn_topic_0000001209412247_p173761391912"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209412247_p1737633141914"><a name="zh-cn_topic_0000001209412247_p1737633141914"></a><a name="zh-cn_topic_0000001209412247_p1737633141914"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row13761931195"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p14444202014199"><a name="zh-cn_topic_0000001209412247_p14444202014199"></a><a name="zh-cn_topic_0000001209412247_p14444202014199"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p1244402010195"><a name="zh-cn_topic_0000001209412247_p1244402010195"></a><a name="zh-cn_topic_0000001209412247_p1244402010195"></a><a href="#zh-cn_topic_0000001209412247_section720518449379">DistributedInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p8444112013195"><a name="zh-cn_topic_0000001209412247_p8444112013195"></a><a name="zh-cn_topic_0000001209412247_p8444112013195"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p744452014197"><a name="zh-cn_topic_0000001209412247_p744452014197"></a><a name="zh-cn_topic_0000001209412247_p744452014197"></a>分布式系统使用的操作系统帐户信息。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001209412247_table20225174621513"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209412247_row18225134671517"><th class="cellrowborder" valign="top" width="17.83%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209412247_p82251246171515"><a name="zh-cn_topic_0000001209412247_p82251246171515"></a><a name="zh-cn_topic_0000001209412247_p82251246171515"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.17%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209412247_p13225546161518"><a name="zh-cn_topic_0000001209412247_p13225546161518"></a><a name="zh-cn_topic_0000001209412247_p13225546161518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209412247_row16225646121517"><td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209412247_p4576349151812"><a name="zh-cn_topic_0000001209412247_p4576349151812"></a><a name="zh-cn_topic_0000001209412247_p4576349151812"></a>Promise<span>&lt;</span><span>void</span><span>&gt;</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="82.17%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209412247_p5576134941817"><a name="zh-cn_topic_0000001209412247_p5576134941817"></a><a name="zh-cn_topic_0000001209412247_p5576134941817"></a>Promise实例，用于获取异步返回结果。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
    accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
        console.log('updateOsAccountDistributedInfo Success');
     }).catch((err) => {
        console.log("updateOsAccountDistributedInfo err: "  + JSON.stringify(err));
    });
    ```


## DistributedInfo<a name="zh-cn_topic_0000001209412247_section720518449379"></a>

提供操作系统帐户的分布式信息。

<a name="zh-cn_topic_0000001209412247_t1e7d4d4f9078490d8dcdbb56465b8ab3"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001209412247_r85a1aa805727476a8e768b658530fc49"><th class="cellrowborder" valign="top" width="13.08%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209412247_a58cac6e212134a42a245df58d7b6f3a3"><a name="zh-cn_topic_0000001209412247_a58cac6e212134a42a245df58d7b6f3a3"></a><a name="zh-cn_topic_0000001209412247_a58cac6e212134a42a245df58d7b6f3a3"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="8.9%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209412247_ae520989fe4be4482acdfdf2c26d6517d"><a name="zh-cn_topic_0000001209412247_ae520989fe4be4482acdfdf2c26d6517d"></a><a name="zh-cn_topic_0000001209412247_ae520989fe4be4482acdfdf2c26d6517d"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.5%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209412247_a6b396dd84a564272a6f3d4732b4e12fe"><a name="zh-cn_topic_0000001209412247_a6b396dd84a564272a6f3d4732b4e12fe"></a><a name="zh-cn_topic_0000001209412247_a6b396dd84a564272a6f3d4732b4e12fe"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="67.52%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209412247_ae728420f819e42d1b31424ac9747665b"><a name="zh-cn_topic_0000001209412247_ae728420f819e42d1b31424ac9747665b"></a><a name="zh-cn_topic_0000001209412247_ae728420f819e42d1b31424ac9747665b"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001209412247_r3e8e2a236aee4030b7f7878cf5bc7537"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p622724611205"><a name="zh-cn_topic_0000001209412247_p622724611205"></a><a name="zh-cn_topic_0000001209412247_p622724611205"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p9227114615203"><a name="zh-cn_topic_0000001209412247_p9227114615203"></a><a name="zh-cn_topic_0000001209412247_p9227114615203"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p172273462204"><a name="zh-cn_topic_0000001209412247_p172273462204"></a><a name="zh-cn_topic_0000001209412247_p172273462204"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p1773051213414"><a name="zh-cn_topic_0000001209412247_p1773051213414"></a><a name="zh-cn_topic_0000001209412247_p1773051213414"></a>分布式帐号名称，非空字符串。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001209412247_row144831617482"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p10228184662019"><a name="zh-cn_topic_0000001209412247_p10228184662019"></a><a name="zh-cn_topic_0000001209412247_p10228184662019"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p122844612207"><a name="zh-cn_topic_0000001209412247_p122844612207"></a><a name="zh-cn_topic_0000001209412247_p122844612207"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p1722874602015"><a name="zh-cn_topic_0000001209412247_p1722874602015"></a><a name="zh-cn_topic_0000001209412247_p1722874602015"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p171141242153717"><a name="zh-cn_topic_0000001209412247_p171141242153717"></a><a name="zh-cn_topic_0000001209412247_p171141242153717"></a>分布式帐号UID，非空字符串。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001209412247_row197156101511"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p62281846172013"><a name="zh-cn_topic_0000001209412247_p62281846172013"></a><a name="zh-cn_topic_0000001209412247_p62281846172013"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p1722810460203"><a name="zh-cn_topic_0000001209412247_p1722810460203"></a><a name="zh-cn_topic_0000001209412247_p1722810460203"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p4228846182017"><a name="zh-cn_topic_0000001209412247_p4228846182017"></a><a name="zh-cn_topic_0000001209412247_p4228846182017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p1951165714370"><a name="zh-cn_topic_0000001209412247_p1951165714370"></a><a name="zh-cn_topic_0000001209412247_p1951165714370"></a>分布式帐号登录状态，包括登录、登出、Token失效和注销，分别对应以下字符串：</p>
<a name="zh-cn_topic_0000001209412247_ul3390191017109"></a><a name="zh-cn_topic_0000001209412247_ul3390191017109"></a><ul id="zh-cn_topic_0000001209412247_ul3390191017109"><li>Ohos.account.event.LOGIN</li><li>Ohos.account.event.LOGOUT</li><li>Ohos.account.event.TOKEN_INVALID</li><li>Ohos.account.event.LOGOFF</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001209412247_row227311811513"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209412247_p1422815463200"><a name="zh-cn_topic_0000001209412247_p1422815463200"></a><a name="zh-cn_topic_0000001209412247_p1422815463200"></a>scalableData</p>
</td>
<td class="cellrowborder" valign="top" width="8.9%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209412247_p1022834619208"><a name="zh-cn_topic_0000001209412247_p1022834619208"></a><a name="zh-cn_topic_0000001209412247_p1022834619208"></a>object</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209412247_p17228204619208"><a name="zh-cn_topic_0000001209412247_p17228204619208"></a><a name="zh-cn_topic_0000001209412247_p17228204619208"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="67.52%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209412247_p111151126143816"><a name="zh-cn_topic_0000001209412247_p111151126143816"></a><a name="zh-cn_topic_0000001209412247_p111151126143816"></a>分布式帐号扩展信息，根据业务所需，以k-v形式传递定制化信息。</p>
<p id="zh-cn_topic_0000001209412247_p11123717144012"><a name="zh-cn_topic_0000001209412247_p11123717144012"></a><a name="zh-cn_topic_0000001209412247_p11123717144012"></a>说明：该参数是预留的可选项，目前查询和更新的方法实现中未使用。</p>
</td>
</tr>
</tbody>
</table>

