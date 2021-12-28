#  	应用帐号管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager;

应用帐号管理：获取应用帐号模块对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | AppAccountManager | 获取应用帐号模块的实例。 |

- 示例：
  ```
  var appAccountManager = account.createAppAccountManager();
  ```

## AppAccountManager

管理应用帐号模块的实例。

### addAccount

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

将此应用的帐号名添加到帐号管理服务中，使用callback回调异步返回结果。

需要权限：无。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                                       |
  | -------- | ------------------- | ---- | ------------------------------------------ |
  | name     | string              | 是   | 要添加的应用帐户的名称。                   |
  | callback | AsyncCallback&lt;void&gt; | 是   | 将此应用的帐号名添加到帐号管理服务的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void;

将此应用程序的帐号名和额外信息添加到帐号管理服务中，使用callback回调异步返回结果。

需要权限：无。

- 参数：

  | 参数名    | 类型                | 必填 | 说明                                                         |
  | --------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name      | string              | 是   | 要添加的应用帐户的名称。                                     |
  | extraInfo | string              | 是   | 要添加的应用帐户的额外信息(例如token等)，额外的信息不能是应用帐号的敏感信息。 |
  | callback  | AsyncCallback&lt;void&gt; | 是   | 将此应用程序的帐号名和额外信息添加到帐号管理服务中的回调。   |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```



### addAccount

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;;

将此应用的帐号名或额外信息添加到帐号管理服务中，使用Promise方式异步返回结果。

需要权限：无。

- 参数：

  | 参数名    | 类型   | 必填 | 说明                                                         |
  | --------- | ------ | ---- | ------------------------------------------------------------ |
  | name      | string | 是   | 要添加的应用帐户的名称。                                     |
  | extraInfo | string | 是   | 要添加的应用帐户的额外信息，额外的信息不能是应用帐号的敏感信息。 |

- 返回值：

  | 类型          | 说明                               |
  | ------------- | ---------------------------------- |
  | Promise&lt;void&gt; | romise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101").then(()=> { 
      console.log('addAccount Success');
  }).catch((err) => {
      console.log("addAccount err: "  + JSON.stringify(err));
  });
  ```

### deleteAccount

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

从帐号管理服务中删除应用帐号，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                               |
  | -------- | ------------------- | ---- | ---------------------------------- |
  | name     | string              | 是   | 要删除的应用帐户的名称。           |
  | callback | AsyncCallback&lt;void&gt; | 是   | 帐号管理服务中删除应用帐号的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu", (err) => { 
      console.log("deleteAccount err: " + JSON.stringify(err));
   });
  ```

### deleteAccount

deleteAccount(name: string): Promise&lt;void&gt;;

从帐号管理服务中删除应用帐号，使用Promise方式异步返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | name   | string | 是   | 要删除的应用帐户的名称。 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
        console.log('deleteAccount Success');
   }).catch((err) => {
      console.log("deleteAccount err: "  + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

禁止指定第三方应用帐户的名称访问指定包名称的第三方应用，使用callback回调异步返回结果。

- 参数：

  | 参数名     | 类型                | 必填 | 说明                                                         |
  | ---------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name       | string              | 是   | 要禁用访问的第三方应用帐户的名称。                           |
  | bundleName | string              | 是   | 第三方应用的包名。                                           |
  | callback   | AsyncCallback&lt;void&gt; | 是   | 禁止指定第三方应用帐户的名称访问指定包名称的第三方应用的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.huawei.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;;

禁止指定第三方应用帐户的名称访问指定包名称的第三方应用，使用Promise方式异步返回结果。

- 参数：

  | 参数名     | 类型   | 必填 | 说明                               |
  | ---------- | ------ | ---- | ---------------------------------- |
  | name       | string | 是   | 要禁用访问的第三方应用帐户的名称。 |
  | bundleName | string | 是   | 第三方应用的包名。                 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.huawei.ohos.accountjsdemo").then(() => { 
      console.log('disableAppAccess Success');
  }).catch((err) => {
      console.log("disableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

允许指定第三方应用帐户的名称访问指定包名称的第三方应用，使用callback回调异步返回结果。

- 参数：

  | 参数名     | 类型                | 必填 | 说明                                                         |
  | ---------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name       | string              | 是   | 应用帐号名称。                                               |
  | bundleName | string              | 是   | 第三方应用的包名。                                           |
  | callback   | AsyncCallback&lt;void&gt; | 是   | 允许指定第三方应用帐户的名称访问指定包名称的第三方应用的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.huawei.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;;

允许指定第三方应用帐户的名称访问指定包名称的第三方应用，使用Promise方式异步返回结果。

- 参数：

  | 参数名     | 类型   | 必填 | 说明               |
  | ---------- | ------ | ---- | ------------------ |
  | name       | string | 是   | 应用帐号名称。     |
  | bundleName | string | 是   | 第三方应用的包名。 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  app_account_instance.enableAppAccess("ZhangSan", "com.huawei.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void;

检查指定应用帐号是否允许应用数据同步，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                   | 必填 | 说明                                         |
  | -------- | ---------------------- | ---- | -------------------------------------------- |
  | name     | string                 | 是   | 应用帐号名称。                               |
  | callback | AsyncCallback&lt;boolean&gt; | 是   | 检查指定应用帐号是否允许应用数据同步的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan", (err, result) => { 
      console.log("checkAppAccountSyncEnable err: " + JSON.stringify(err));
      console.log('checkAppAccountSyncEnable result: ' + result);
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;;

检查指定应用帐号是否允许应用数据同步，使用Promise方式异步返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明           |
  | ------ | ------ | ---- | -------------- |
  | name   | string | 是   | 应用帐号名称。 |

- 返回值：

  | 类型             | 说明                                |
  | :--------------- | :---------------------------------- |
  | Promise&lt;boolean&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan").then((data) => { 
      console.log('checkAppAccountSyncEnable, result: ' + data);
  }).catch((err) => {
      console.log("checkAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void;

设置此应用程序帐号的凭据，使用callback回调异步返回结果。

- 参数：

  | 参数名         | 类型                | 必填 | 说明                         |
  | -------------- | ------------------- | ---- | ---------------------------- |
  | name           | string              | 是   | 应用程序帐户的名称。         |
  | credentialType | string              | 是   | 要设置的凭据的类型。         |
  | credential     | string              | 是   | 要设置的凭据。               |
  | callback       | AsyncCallback&lt;void&gt; | 是   | 设置此应用帐号的凭据的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;;

设置此应用程序帐号的凭据，使用Promise方式异步返回结果。

- 参数：

  | 参数名         | 类型   | 必填 | 说明                 |
  | -------------- | ------ | ---- | -------------------- |
  | name           | string | 是   | 应用帐户的名称。     |
  | credentialType | string | 是   | 要设置的凭据的类型。 |
  | credential     | string | 是   | 要设置的凭据。       |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
      console.log('setAccountCredential Success');
  }).catch((err) => {
      console.log("setAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void;

设置此应用程序帐号的额外信息，使用callback回调异步返回结果。

- 参数：

  | 参数名    | 类型                | 必填 | 说明                             |
  | --------- | ------------------- | ---- | -------------------------------- |
  | name      | string              | 是   | 应用帐户的名称。                 |
  | extraInfo | string              | 是   | 要设置的额外信息。               |
  | callback  | AsyncCallback&lt;void&gt; | 是   | 设置此应用帐号的额外信息的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;;

设置此应用程序帐号的额外信息，使用Promise方式异步返回结果。

- 参数：

  | 参数名    | 类型   | 必填 | 说明               |
  | --------- | ------ | ---- | ------------------ |
  | name      | string | 是   | 应用帐户的名称。   |
  | extraInfo | string | 是   | 要设置的额外信息。 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002").then(() => { 
      console.log('setAccountExtraInfo Success');
  }).catch((err) => {
      console.log("setAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

设置指定的应用程序帐号是否允许应用程序数据同步，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                                               |
  | -------- | ------------------- | ---- | -------------------------------------------------- |
  | name     | string              | 是   | 应用帐户的名称。                                   |
  | isEnable | boolean             | 是   | 是否允许应用数据同步。                             |
  | callback | AsyncCallback&lt;void&gt; | 是   | 设置指定的应用帐号是否允许应用程序数据同步的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;;

设置指定的应用程序帐号是否允许应用程序数据同步，使用Promise方式异步返回结果。

- 参数：

  | 参数名   | 类型    | 必填 | 说明                   |
  | -------- | ------- | ---- | ---------------------- |
  | name     | string  | 是   | 应用帐户的名称。       |
  | isEnable | boolean | 是   | 是否允许应用数据同步。 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager .setAppAccountSyncEnable("ZhangSan", true).then(() => { 
      console.log('setAppAccountSyncEnable Success');
  }).catch((err) => {
      console.log("setAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;

设置与此应用程序帐号关联的数据，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                               |
  | -------- | ------------------- | ---- | ---------------------------------- |
  | name     | string              | 是   | 应用帐户的名称。                   |
  | key      | string              | 是   | 要设置的数据的键，密钥可以自定义。 |
  | value    | string              | 是   | 要设置的数据的值。                 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 设置与此应用帐号关联的数据的回调。 |

- 示例：

  ```
  app_account_instance.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;;

设置与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明                               |
  | ------ | ------ | ---- | ---------------------------------- |
  | name   | string | 是   | 应用帐户的名称。                   |
  | key    | string | 是   | 要设置的数据的键，密钥可以自定义。 |
  | value  | string | 是   | 要设置的数据的值。                 |

- 返回值：

  | 类型          | 说明                                |
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void;

获取此应用帐号的凭据，使用callback回调异步返回结果。

- 参数：

  | 参数名         | 类型                  | 必填 | 说明                         |
  | -------------- | --------------------- | ---- | ---------------------------- |
  | name           | string                | 是   | 应用帐号名称。               |
  | credentialType | string                | 是   | 要获取的凭据的类型。         |
  | callback       | AsyncCallback&lt;string&gt; | 是   | 获取此应用帐号的凭据的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;;

获取此应用程序帐号的凭据，使用Promise方式异步返回结果。

- 参数：

  | 参数名         | 类型   | 必填 | 说明                 |
  | -------------- | ------ | ---- | -------------------- |
  | name           | string | 是   | 应用帐号名称。       |
  | credentialType | string | 是   | 要获取的凭据的类型。 |

- 返回值：

  | 类型            | 说明                                |
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void;

获取此应用帐号的额外信息，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                  | 必填 | 说明                             |
  | -------- | --------------------- | ---- | -------------------------------- |
  | name     | string                | 是   | 应用帐号名称。                   |
  | callback | AsyncCallback&lt;string&gt; | 是   | 获取此应用帐号的额外信息的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan", (err, result) => { 
      console.log("getAccountExtraInfo err: " + JSON.stringify(err));
      console.log('getAccountExtraInfo result: ' + result);
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string): Promise&lt;string&gt;;

获取此应用程序帐号的额外信息，使用Promise方式异步返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明           |
  | ------ | ------ | ---- | -------------- |
  | name   | string | 是   | 应用帐号名称。 |

- 返回值：

  | 类型            | 说明                                |
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan").then((data) => { 
      console.log('getAccountExtraInfo, result: ' + data);
  }).catch((err) => {
      console.log("getAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void;

获取与此应用程序帐号关联的数据，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                  | 必填 | 说明                               |
  | -------- | --------------------- | ---- | ---------------------------------- |
  | name     | string                | 是   | 应用帐号名称。                     |
  | key      | string                | 是   | 要获取的数据的key。                |
  | callback | AsyncCallback&lt;string&gt; | 是   | 获取与此应用帐号关联的数据的回调。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string): Promise&lt;string&gt;;

获取与此应用程序帐号关联的数据，使用Promise方式异步返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明                |
  | ------ | ------ | ---- | ------------------- |
  | name   | string | 是   | 应用帐号名称。      |
  | key    | string | 是   | 要获取的数据的key。 |

- 返回值：

  | 类型            | 说明                                |
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

获取全部应用已授权帐号信息。

需要权限：ohos.permission.GET_ACCOUNTS_PRIVILEGED，系统应用可用。

- 参数：

  | 参数名   | 类型                                 | 必填 | 说明             |
  | -------- | ------------------------------------ | ---- | ---------------- |
  | callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是   | 应用帐号信息列表 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

获取全部应用已授权帐号信息。

需要权限：ohos.permission.GET_ACCOUNTS_PRIVILEGED，系统应用可用。

- 参数：

  | 类型                           | 说明                                |
  | ------------------------------ | ----------------------------------- |
  | Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

获取指定应用全部帐号信息。

需要权限：ohos.permission.GET_ACCOUNTS_PRIVILEGED，系统应用可用。

- 参数：

  | 参数名   | 类型                                 | 必填 | 说明             |
  | -------- | ------------------------------------ | ---- | ---------------- |
  | owner    | string                               | 是   | 应用包名称       |
  | callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是   | 应用帐号信息列表 |

- 示例：

  ```
  const appAccountManager = account.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

获取指定应用全部帐号信息。

需要权限：ohos.permission.GET_ACCOUNTS_PRIVILEGED，系统应用可用。

- 参数：

  | 参数名 | 类型   | 必填 | 说明       |
  | ------ | ------ | ---- | ---------- |
  | owner  | string | 是   | 应用包名称 |

- 参数：

  | 类型                           | 说明                                |
  | ------------------------------ | ----------------------------------- |
  | Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle).then((data) => { 
       console.log('getAllAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  });
  ```

### on('change')

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

订阅指定帐号所有者的帐户变更事件，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                            | 必填 | 说明                                                         |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | type     | 'change'                        | 是   | 关于帐户更改事件，当帐户所有者更新帐户时，订阅者将收到通知。 |
  | owners   | Array&lt;string&gt;                   | 是   | 指示帐户的所有者。                                           |
  | callback | Callback&lt;Array&lt;AppAccountInfo&gt;&gt; | 是   | 订阅指定帐号所有者的帐户变更事件的回调。                     |

- 示例：

  ```
  const appAccountManager = account.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### off('change')

off(type: 'change', callback?: Callback&lt;void&gt;): void;

取消订阅帐号事件，使用callback回调异步返回结果。

- 参数：

  | 参数名   | 类型                 | 必填 | 说明                     |
  | -------- | -------------------- | ---- | ------------------------ |
  | type     | 'change'             | 是   | 关于帐户更改事件。       |
  | callback | Callback&lt;void&gt; | 否   | 取消订阅帐号事件的回调。 |

- 示例：

  ```
  const appAccountManager = account.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  	appAccountManager.off('change', function(){
  		console.debug("off finish");
  	}
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

## AppAccountInfo



| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| owner  | string | 是   | 所有者是应用帐户。 |
| name   | string | 是   | 应用帐户的名称。   |

