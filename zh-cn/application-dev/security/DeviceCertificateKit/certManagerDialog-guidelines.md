# 证书管理对话框开发指导

> **说明**
>
> 本开发指导需使用API version 13及以上版本SDK。

证书管理对话框，可用于拉起证书管理页面并管理证书，如安装、存储、使用、销毁证书。


## 接口说明

详细接口说明可参考[API参考](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md)。

以上场景涉及的常用接口如下表所示：

| 实例名          | 接口名                                                       | 描述                                         |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| certificateManagerDialog        | openCertificateManagerDialog(context: common.Context, pageType: CertificateDialogPageType): Promise\<void> | 拉起证书管理对话框，显示相应的页面，使用Promise方式异步返回结果 |

## 开发步骤

1. 申请ohos.permission.ACCESS_CERT_MANAGER权限。可参考[申请应用权限-声明权限](../AccessToken/declare-permissions.md)。

2. 导入相关模块

   ```ts
   import certificateManagerDialog from '@ohos.security.certManagerDialog';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```
3. 拉起证书管理界面。

   ```ts
   async function certificateManagerDialogSample() {
	/* context为应用的上下文信息，由调用方自行获取，此处仅为示例 */
	let context: common.Context = getContext(this);
	/* pageType为页面类型，此处赋值PAGE_MAIN，即拉起证书管理主界面 */
	let pageType: certificateManagerDialog.CertificateDialogPageType = certificateManagerDialog.CertificateDialogPageType.PAGE_MAIN;
	try {
	  certificateManagerDialog.openCertificateManagerDialog(context, pageType).then(() => {
		console.info('Succeeded in opening certificate manager dialog.');
	  }).catch((err: BusinessError) => {
		console.error(`Failed to open certificate manager dialog. Code: ${err.code}, message: ${err.message}`);
	  })
	} catch (error) {
	  console.error(`Failed to open certificate manager dialog. Code: ${error.code}, message: ${error.message}`);
	}
   }
   ```
