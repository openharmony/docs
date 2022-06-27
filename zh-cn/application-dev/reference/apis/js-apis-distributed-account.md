# 分布式帐号管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import account_distributedAccount from '@ohos.account.distributedAccount';
```


## account_distributedAccount.getDistributedAccountAbility

getDistributedAccountAbility(): DistributedAccountAbility

获取分布式帐号单实例对象。

**系统能力：** SystemCapability.Account.OsAccount

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [DistributedAccountAbility](#distributedaccountability) | 返回一个实例，实例提供查询和更新分布式帐号登录状态方法。 |

- 示例：
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

提供查询和更新分布式帐号登录状态方法(需要先获取分布式帐号的单实例对象)。

### queryOsAccountDistributedInfo

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

获取分布式帐号信息，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.DISTRIBUTED_DATASYNC，该权限仅供系统应用使用。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | 是 | 获取分布式帐号信息的回调。 |

- 示例：
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo((err, data) => { 
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
  });
  ```

### queryOsAccountDistributedInfo

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

获取分布式帐号信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS 或 ohos.permission.DISTRIBUTED_DATASYNC，该权限仅供系统应用使用。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo().then((data) => { 
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
  }).catch((err) => {
      console.log("queryOsAccountDistributedInfoerr: "  + JSON.stringify(err));
  });
  ```

### updateOsAccountDistributedInfo

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

更新分布式帐号信息，使用callback回调异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅供系统应用使用。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式帐号信息。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 更新分布式帐号信息的回调。 |

- 示例：
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err) => { 
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
  });
  ```

### updateOsAccountDistributedInfo

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

更新分布式帐号信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Account.OsAccount

**需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅供系统应用使用。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | 是 | 分布式帐户信息。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
      console.log('updateOsAccountDistributedInfo Success');
   }).catch((err) => {
      console.log("updateOsAccountDistributedInfo err: "  + JSON.stringify(err));
  });
  ```


## DistributedInfo

提供操作系统帐户的分布式信息。

**系统能力：** SystemCapability.Account.OsAccount

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 分布式帐号名称，非空字符串。 |
| id | string | 是 | 分布式帐号UID，非空字符串。 |
| event | string | 是 | 分布式帐号登录状态，包括登录、登出、Token失效和注销，分别对应以下字符串：<br/>-&nbsp;Ohos.account.event.LOGIN<br/>-&nbsp;Ohos.account.event.LOGOUT<br/>-&nbsp;Ohos.account.event.TOKEN_INVALID<br/>-&nbsp;Ohos.account.event.LOGOFF |
| scalableData | object | 否 | 分布式帐号扩展信息，根据业务所需，以k-v形式传递定制化信息。<br/>说明：该参数是预留的可选项，目前查询和更新的方法实现中未使用。 |
