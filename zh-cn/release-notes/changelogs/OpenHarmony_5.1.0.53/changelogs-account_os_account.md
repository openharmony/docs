# 系统账号子系统Changelog

## cl.accountaccount_os_account.1 域账号服务器配置添加、删除、查询接口权限变更

**访问级别**

公开接口。

**变更原因**

系统接口变更为公开接口，接口管控权限跟随变更，新权限允许系统应用和企业应用申请。

**变更影响**

此变更需要应用适配。

| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
|addServerConfig(parameters: Record\<string, Object>): Promise\<DomainServerConfig>|接口权限为ohos.permission.MANAGE_LOCAL_ACCOUNTS|接口权限为ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS|
|removeServerConfig(configId: string): Promise\<void>|接口权限为ohos.permission.MANAGE_LOCAL_ACCOUNTS|接口权限为ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS|
|getAccountServerConfig(domainAccountInfo: DomainAccountInfo): Promise\<DomainServerConfig>|接口权限为ohos.permission.MANAGE_LOCAL_ACCOUNTS|接口权限为ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS|

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

[@ohos.account.osAccount.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.account.osAccount.d.ts)中如下接口。

- addServerConfig(parameters: Record\<string, Object>): Promise\<DomainServerConfig>

- removeServerConfig(configId: string): Promise\<void>

- getAccountServerConfig(domainAccountInfo: DomainAccountInfo): Promise\<DomainServerConfig>

**适配指导**

应用开发者需申请变更后的新权限：ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS

## cl.accountaccount_os_account.2 addServerConfig接口错误码变更

**访问级别**

公开接口。

**变更原因**

接口新增“重复添加”，“添加配置已达上限”异常。

**变更影响**

此变更需要应用适配。

- 变更前。
  - addServerConfig 传入的配置信息已添加，返回OK。

- 变更后。
  - addServerConfig 传入的配置信息已添加，返回12300213 - Server config already exists。
  - addServerConfig 配置信息已达上限，返回12300215 - The number of server config reaches the upper limit。


**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

[@ohos.account.osAccount.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.account.osAccount.d.ts)中如下接口。

- addServerConfig(parameters: Record\<string, Object>): Promise\<DomainServerConfig>


**适配指导**

调用addServerConfig接口新增12300213、123000215错误码，示例如下。

```ts
import { BusinessError, osAccount } from '@kit.BasicServicesKit';
let configParams: Record<string, Object> = {
  'uri': 'test.example.com',
  'port': 100
};
osAccount.DomainServerConfigManager.addServerConfig(configParams).then((
  serverConfig: osAccount.DomainServerConfig) => {
  console.log('add server configuration successfully, the return config: ' + JSON.stringify(serverConfig));
}).catch((err: BusinessError) => {
  console.log('add server configuration failed, error: ' + JSON.stringify(err));
  if (err.code === 12300213) {
    // 提示配置项已存在。
  }
  if (err.code === 12300215) {
    // 配置器添加数量已达上限。
  }
});
```

## cl.accountaccount_os_account.3 removeServerConfig接口错误码变更

**访问级别**

公开接口。

**变更原因**

接口新增“服务器配置已绑定账号，无法删除”异常。

**变更影响**

此变更需要应用适配。

- 变更前。
  - removeServerConfig传入的配置信息已和本地账号绑定，返回OK。

- 变更后。
  - removeServerConfig传入的配置信息已和本地账号绑定，返回12300214 - Server config has been associated with an account。


**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.53 版本开始。

**变更的接口/组件**

[@ohos.account.osAccount.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.account.osAccount.d.ts)中如下接口。

- removeServerConfig(configId: string): Promise\<void>


**适配指导**

调用removeServerConfig接口新增12300214错误码，示例如下。

```ts
import { BusinessError, osAccount } from '@kit.BasicServicesKit';
let configParams: Record<string, Object> = {
  'uri': 'test.example.com',
  'port': 100
};
osAccount.DomainServerConfigManager.addServerConfig(configParams).then((
  serverConfig: osAccount.DomainServerConfig) => {
  console.log('add domain server configuration successfully, the added config: ' + JSON.stringify(serverConfig));
  osAccount.DomainServerConfigManager.removeServerConfig(serverConfig.id).catch((err: BusinessError) => {
    console.log('remove server configuration failed, error: ' + JSON.stringify(err));
    if (err.code === 12300214) {
      // 提示配置项已绑定无法删除。
    }
  });
}).catch((err: BusinessError) => {
  console.log('add server configuration failed, error: ' + JSON.stringify(err));
});
```
