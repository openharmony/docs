# 数据防泄漏服务开发指导

DLP是系统提供的系统级的数据防泄漏解决方案，提供一种称为DLP的文件格式。后缀格式为“原始文件名（包含原始文件后缀）.dlp”，例如“test.docx.dlp”，文件由授权凭证和原始文件密文组成。

通过端云协同认证（需要联网）来获取文件的访问授权，授权类型包含只读、编辑、文件拥有者三种。

- 只读：能读取文件内容但不能修改。
- 编辑：能够读写文件内容，但不能修改文件权限配置。
- 文件拥有者：可读写文件、修改权限配置、恢复原始原始文件等。

应用需要访问DLP文件时，系统会自动安装应用的DLP沙箱分身应用，相当于完全独立的应用，数据和配置会继承原应用，但相互之间并不共享。分身应用在运行时会处于DLP沙箱环境中，访问外部的权限会被限制，以防止数据的泄漏。每当打开一个新的DLP文件会生成一个应用沙箱分身，沙箱应用之间也是相互隔离的，当应用关闭后应用分身会自动卸载，沙箱期间产生的临时数据也会丢弃。

正常情况下，应用不会感知到沙箱的存在，访问的也是解密后的明文，和访问普通文件没有区别，但由于DLP沙箱会限制其访问外部的权限（例如网络、剪切板、截屏、录屏、蓝牙等）。为了更好的用户体验，需要应用进行适配，例如文件只读的情况下，不应显示“保存”按钮，不应主动联网等。

## 沙箱限制

当应用进入DLP沙箱状态时，可以申请的权限将受到限制，根据DLP文件授权类型不同，限制也不相同，如下表：

| 权限名 | 说明 | 授权类型：只读 | 授权类型：编辑/文件拥有者 |
| -------- | -------- | -------- | -------- |
| ohos.permission.USE_BLUETOOTH | 允许应用使用蓝牙。 | 禁止 | 禁止 |
| ohos.permission.INTERNET |允许应用访问网络。 |  禁止 | 禁止 |
| ohos.permission.DISTRIBUTED_DATASYNC | 允许应用与远程设备交换用户数据（如图片、音乐、视频、及应用数据等）。 | 禁止 | 禁止 |
| ohos.permission.WRITE_MEDIA | 应用读写用户媒体文件，如视频、音频、图片等，需要申请此权限。 | 禁止 | 允许 |
| ohos.permission.NFC_TAG | 允许应用使用NFC。 | 禁止 | 允许 |

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| isDLPFile(fd: number): Promise&lt;boolean&gt; <br> isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void| 判断是否是dlp文件 |
| getDLPPermissionInfo(): Promise&lt;DLPPermissionInfo&gt; <br>getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void  | 获取当前沙箱应用的权限类型 |
| getOriginalFileName(fileName: string): string | 获取dlp文件原始文件名 |
| getDLPSuffix(): string | 获取dlp文件dlp后缀名 |
| on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void | 注册dlp文件打开事件监听，用于原始应用获取dlp文件打开事件 |
| off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void | 取消dlp文件打开事件监听 |
| isInSandbox(): Promise&lt;boolean&gt; <br>isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void | 判断当前是否是dlp沙箱应用 |
| getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;<br>getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void | 获取当前系统支持添加权限保护的文件格式类型 |
| setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt; <br> setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | 设置dlp分身应用保留状态 |
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | 取消dlp分身应用保留状态 |
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| 获取当前保留沙箱列表 |
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | 获取dlp文件访问记录 |
|setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;|设置沙箱应用配置信息|
|getSandboxAppConfig(): Promise&lt;string&gt;|查询沙箱应用配置信息|
|cleanSandboxAppConfig(): Promise&lt;void&gt;|清理沙箱应用配置信息|
| startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt; <br> | 在当前UIAbility界面以无边框形式打开DLP权限管理应用（只支持Stage模式） |

## 开发步骤

1. 引入[dlpPermission](../../reference/apis-data-protection-kit/js-apis-dlppermission.md)模块。

   ```ts
   import { dlpPermission } from '@kit.DataProtectionKit';
   ```

2. 打开DLP文件，系统会自动安装应用的DLP沙箱分身应用。以下代码应在应用页Ability中使用。

    ```ts
    import { common, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    function OpenDlpFile(dlpUri: string, fileName: string, fd: number) {
      let want:Want = {
        "action": "ohos.want.action.viewData",
        "bundleName": "com.example.example_bundle_name",
        "abilityName": "exampleAbility",
        "uri": dlpUri,
        "parameters": {
          "fileName": {
            "name": fileName
          },
          "keyFd": {
            "type": "FD",
            "value": fd
          }
        }
      }

      let context = getContext() as common.UIAbilityContext; // 获取当前UIAbilityContext

      try {
        console.log('openDLPFile:' + JSON.stringify(want));
        console.log('openDLPFile: delegator:' + JSON.stringify(context));
        context.startAbility(want);
      } catch (err) {
        console.error('openDLPFile startAbility failed', (err as BusinessError).code, (err as BusinessError).message);
        return;
      }
    }
    ```

    以上代码需要在module.json5文件中增加ohos.want.action.viewData：

    ```json
    "skills":[
      {
        "entities":[
          ...
        ],
        "actions":[
          ...
          "ohos.want.action.viewData"
        ]
      }
    ]
    ```

3. 生成DLP文件

    [该功能云端对接模块当前需要开发者自行搭建。](../DataProtectionKit/dlp-overview.md)

    3.1 当前支持生成DLP文件的原文件类型: ".doc", ".docm", ".docx", ".dot", ".dotm", ".dotx", ".odp", ".odt", ".pdf", ".pot", ".potm", ".potx", ".ppa", ".ppam", ".pps", ".ppsm", ".ppsx", ".ppt", ".pptm", ".pptx", ".rtf", ".txt", ".wps", ".xla", ".xlam", ".xls", ".xlsb", ".xlsm", ".xlsx", ".xlt", ".xltm", ".xltx", ".xlw", ".xml", ".xps"。

    3.2 首先要有一个DLP权限应用有读写权限的(比如文件管理的文档目录下)并且属于以上文件类型之一的原文件。

    3.3 以无边框形式打开DLP权限管理应用。此方法只能在UIAbility上下文中调用，只支持Stage模式。调用以下代码，拉起DLP管理应用的设置权限页面，输入相关的授权账号信息，点击保存，在拉起的filepicker中选择DLP文件的保存路径，保存DLP文件。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { common, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      let fileUri: string = "file://docs/storage/Users/currentUser/test.txt";
      let fileName: string = "test.txt";
      let context = getContext() as common.UIAbilityContext; // 获取当前UIAbilityContext
      let want: Want = {
        'uri': fileUri,
        'parameters': {
          'displayName': fileName
        }
      }; // 请求参数
      dlpPermission.startDLPManagerForResult(context, want).then((res: dlpPermission.DLPManagerResult) => {
        console.info('startDLPManagerForResult res.resultCode:' + res.resultCode);
        console.info('startDLPManagerForResult res.want:' + JSON.stringify(res.want));
      }); // 拉起DLP权限管理应用 设置权限
    } catch (err) {
      console.error('startDLPManagerForResult error:' + (err as BusinessError).code + (err as BusinessError).message);
    }
    ```

4. 查询当前应用是否在沙箱中。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    dlpPermission.isInSandbox().then((data)=> {
      console.log('isInSandbox, result: ' + JSON.stringify(data));
    }).catch((err:BusinessError) => {
      console.log('isInSandbox: ' + JSON.stringify(err));
    });
    ```

5. 查询当前编辑的文件权限，根据文件授权的不同，DLP沙箱被限制的权限有所不同，参考[沙箱限制](#沙箱限制)。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    dlpPermission.getDLPPermissionInfo().then((data)=> {
      console.log('getDLPPermissionInfo, result: ' + JSON.stringify(data));
    }).catch((err:BusinessError) => {
      console.log('getDLPPermissionInfo: ' + JSON.stringify(err));
    });
    ```

6. 获取当前可支持DLP方案的文件扩展名类型列表，用于应用判断能否生成DLP文件，可用在实现类似文件管理器设置DLP权限的场景。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';

    dlpPermission.getDLPSupportedFileTypes((err, result) => {
      console.log('getDLPSupportedFileTypes: ' + JSON.stringify(err));
      console.log('getDLPSupportedFileTypes: ' + JSON.stringify(result));
    });
    ```

7. 判断当前打开文件是否是DLP文件。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { fileIo } from '@kit.CoreFileKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
    let file = fileIo.openSync(uri);
    try {
      let res = dlpPermission.isDLPFile(file.fd); // 是否加密DLP文件
      console.info('res', res);
    } catch (err) {
      console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
    }
    fileIo.closeSync(file);
    ```

8. 订阅、取消订阅DLP打开事件。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    class SubscribeExample {
      event(info: dlpPermission.AccessedDLPFileInfo) {
        console.info('openDlpFile event', info.uri, info.lastOpenTime)
      }
      unSubscribe() {
        try {
          dlpPermission.off('openDLPFile', this.event); // 取消订阅
        } catch (err) {
          console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
        }
      }
      subscribe() {
        try {
          dlpPermission.on('openDLPFile', this.event); // 订阅
        } catch (err) {
          console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
        }
      }
      onCreate() {
        this.subscribe();
      }
      onDestroy() {
        this.unSubscribe();
      }
    }
    ```

9. 获取DLP文件打开记录。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    async function getDLPFileAccessRecords() {
      try {
        let res:Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // 获取DLP访问列表
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

10. 获取DLP文件保留沙箱记录。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    async function getRetentionSandboxList() {
      try {
        let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // 获取沙箱保留列表
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

11. 设置沙箱应用配置信息。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    async function setSandboxAppConfig() {
      try {
        await dlpPermission.setSandboxAppConfig('configInfo'); // 设置沙箱应用配置信息
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

12. 清理沙箱应用配置信息。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    async function cleanSandboxAppConfig() {
      try {
        await dlpPermission.cleanSandboxAppConfig(); // 清理沙箱应用配置信息
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

13. 查询沙箱应用配置信息。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    async function getSandboxAppConfig() {
      try {
        let res:string = await dlpPermission.getSandboxAppConfig(); // 查询沙箱应用配置信息
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

14. 以无边框形式打开DLP权限管理应用。此方法只能在UIAbility上下文中调用，只支持Stage模式。

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { common, UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      let context = getContext() as common.UIAbilityContext; // 获取当前UIAbilityContext
      let want: Want = {
        "uri": "file://docs/storage/Users/currentUser/Desktop/1.txt",
        "parameters": {
          "displayName": "1.txt"
        }
      }; // 请求参数
      dlpPermission.startDLPManagerForResult(context, want).then((res) => {
        console.info('res.resultCode', res.resultCode);
        console.info('res.want', JSON.stringify(res.want));
      }); // 打开DLP权限管理应用
    } catch (err) {
      console.error('error', err.code, err.message); // 失败报错
    }
    ```

15. 查询当前系统是否提供DLP特性。
    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    dlpPermission.isDLPFeatureProvided().then((res) => {
      console.info('res', JSON.stringify(res));
    }).catch((err: BusinessError) => {
      console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
    });
    ```
