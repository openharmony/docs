# 数据防泄漏（DLP）开发指导

数据防泄漏（Data Loss Prevention, DLP）是OpenHarmony提供的系统级的数据防泄漏解决方案，提供一种称为DLP的文件格式。后缀格式为“原始文件名（包含原始文件后缀）.dlp”，例如: “test.docx.dlp”，文件由授权凭证和原始文件密文组成。

通过端云协同认证（需要联网）来获取文件的访问授权，授权类型包含只读、编辑、文档拥有者三种。

- 只读：能读取文档内容但不能修改。
- 编辑：能够读写文档内容，但不能修改文档权限配置。
- 文档拥有者：可读写文件、修改权限配置、恢复原始原始文件等。

应用需要访问DLP文件时，系统会自动安装应用的DLP沙箱分身应用，相当于完全独立的应用，数据和配置会继承原应用，但相互之间并不共享。分身应用在运行时会处于DLP沙箱环境中，访问外部的权限会被限制，以防止数据的泄漏。每当打开一个新的DLP文档会生成一个应用沙箱分身，沙箱应用之间也是相互隔离的，当应用关闭后应用分身会自动卸载，沙箱期间产生的临时数据也会丢弃。

正常情况下，应用不会感知到沙箱的存在，访问的也是解密后的明文，和访问普通文档没有区别，但由于DLP沙箱会限制其访问外部的权限（例如网络、剪切板、蓝牙等）。为了更好的用户体验，需要应用进行适配，例如文件只读的情况下，不应显示“保存”按钮，不应主动联网等。

## 沙箱限制

当应用进入DLP沙箱状态时，可以申请的权限将受到限制，根据DLP文件授权类型不同，限制也不相同，如下表：

| 权限名 | 说明 | 授权类型：只读 | 授权类型：编辑/文档拥有者 |
| -------- | -------- | -------- | -------- |
| ohos.permission.USE_BLUETOOTH | 允许应用使用蓝牙。 | 禁止 | 禁止 |
| ohos.permission.INTERNET |允许应用访问网络。 |  禁止 | 禁止 |
| ohos.permission.DISTRIBUTED_DATASYNC | 允许应用与远程设备交换用户数据（如图片、音乐、视频、及应用数据等）。 | 禁止 | 禁止 |
| ohos.permission.WRITE_MEDIA | 应用读写用户媒体文件，如视频、音频、图片等，需要申请此权限。 | 禁止 | 允许 |
| ohos.permission.CAPTURE_SCREEN | 允许应用截屏。 | 禁止 | 允许 |
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
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | 取消dlp分享应用保留状态 |
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| 获取当前保留沙箱列表 |
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | 获取dlp文件访问记录 |
|setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;|设置沙箱应用配置信息|
|getSandboxAppConfig(): Promise&lt;string&gt;|查询沙箱应用配置信息|
|cleanSandboxAppConfig(): Promise&lt;void&gt;|清理沙箱应用配置信息|
## 开发步骤

开发步骤

1. 引入[dlpPermission](../reference/apis/js-apis-dlppermission.md)模块。

   ```ts
   import dlpPermission from '@ohos.dlpPermission';
   ```

2. 打开DLP文件，系统会自动安装应用的DLP沙箱分身应用。以下代码应在应用页Ability中使用。

    ```ts
    async OpenDlpFile(dlpUri: string, fileName: string, fd: number) {
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

      try {
        console.log("openDLPFile:" + JSON.stringify(want));
        console.log("openDLPFile: delegator:" + JSON.stringify(this.context));
        this.context.startAbility(want);
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

3. 查询当前应用是否在沙箱中。

   ```ts
   dlpPermission.isInSandbox().then((data)=> {
     console.log('isInSandbox, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log("isInSandbox: "  + JSON.stringify(err));
   });
   ```

4. 查询当前编辑的文档权限，根据文档授权的不同，DLP沙箱被限制的权限有所不同，参考[沙箱限制](#沙箱限制)。

   ```ts
   dlpPermission.getDLPPermissionInfo().then((data)=> {
     console.log('getDLPPermissionInfo, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log("getDLPPermissionInfo: "  + JSON.stringify(err));
   });
   ```

5. 获取当前可支持DLP方案的文件扩展名类型列表，用于应用判断能否生成DLP文档，可用在实现类似文件管理器设置DLP权限的场景。

   ```ts
   dlpPermission.getDLPSupportedFileTypes((err, result) => {
     console.log("getDLPSupportedFileTypes: " + JSON.stringify(err));
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(result));
   });
   ```

6. 判断当前打开文件是否是dlp文件。

   ```ts
   let file = fs.openSync(uri);
   try {
     let res = await dlpPermission.isDLPFile(file.fd); // 是否加密DLP文件
     console.info('res', res);
   } catch (err) {
     console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
   }
   fs.closeSync(file);
   ```

7. 订阅、取消订阅DLP打开事件。

   ```ts
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
   ```

8. 获取DLP文件打开记录。

   ```ts
   async func() {
     try {
       let res:Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // 获取DLP访问列表
       console.info('res', JSON.stringify(res))
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
     }
   }
   ```

9. 获取DLP文件保留沙箱记录。
    ```ts
    async func() {
     try {
       let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // 获取沙箱保留列表
       console.info('res', JSON.stringify(res))
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
     }
    }
    ```

10. 设置沙箱应用配置信息。
    ```ts
    async func() {
      try {
        await dlpPermission.setSandboxAppConfig('configInfo'); // 设置沙箱应用配置信息
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

11. 清理沙箱应用配置信息。
    ```ts
    async func() {
      try {
        await dlpPermission.cleanSandboxAppConfig(); // 清理沙箱应用配置信息
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```

12. 查询沙箱应用配置信息。
    ```ts
    async func() {
      try {
        let res:string = await dlpPermission.getSandboxAppConfig(); // 查询沙箱应用配置信息
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
      }
    }
    ```