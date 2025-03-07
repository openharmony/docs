# 系统账号子系统Changelog

## cl.accountaccount_os_account.1 setAppAccess错误码变更
**访问级别**

公开接口

**变更原因**

为防止资源浪费，禁止应用无限制地通过调用该接口授予三方应用权限，当授权应用数量超过1024个时，返回新增的错误码（12400005）。

**变更影响**

该变更为不兼容变更。

变更前：setAppAccess传入的第三方应用包名未安装时，返回错误码12400001提示应用未找到。

变更后：setAppAccess传入的第三方应用包名未安装时，当已授权的应用列表未超过限制数量时返回成功，当已授权的应用列表超过了限制数量，返回错误码12400005提示授权应用数量超过了上限。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.2.1 版本开始。

**变更的接口/组件**

[@ohos.account.appAccount.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.account.appAccount.d.ts)中如下接口：

- setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback\<void>): void

- setAppAccess(name: string, bundleName: string, isAccessible: boolean): Promise\<void>

**适配指导**

调用setAppAccess接口新增12400005错误码,示例如下:
```ts
import { BusinessError } from '@ohos.base';
import account_appAccount from '@ohos.account.appAccount';

let appAccountManager: account_appAccount.AppAccountManager = account_appAccount.createAppAccountManager();

try {
  appAccountManager.setAppAccess('ZhangSan', 'com.example.accountjsdemo', true, (err: BusinessError) => {
	if (err.code === 12400005) {
	  //处理授权应用数量超过上限异常，比如对之前已授权的应用取消授权
	} else if (err) {
	  console.log('setAppAccess failed: ' + JSON.stringify(err));
	} else {
	  console.log('setAppAccess successfully');
	}
  });
} catch (err) {
  console.log('setAppAccess exception: ' + JSON.stringify(err));
}
```