# 开发用户文件管理器（仅对系统应用开放）

OpenHarmony预置了FileManager文件管理器。系统应用开发者也可以根据需要，按以下指导自行开发文件管理器。

## 接口说明

开发用户文件管理器的相关API详细介绍请参见[API参考](../reference/apis/js-apis-fileAccess.md)。

## 开发步骤

1. 权限配置和导入模块。
   申请ohos.permission.FILE_ACCESS_MANAGER和ohos.permission.GET_BUNDLE_INFO_PRIVILEGED权限，配置方式请参见[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。

   > **说明：**
   >
   > ohos.permission.FILE_ACCESS_MANAGER是使用文件访问框架接口的基础权限。
   >
   > ohos.permission.GET_BUNDLE_INFO_PRIVILEGED权限可以用于查询系统内当前支持的文件管理服务端应用信息。

2. 导入依赖模块。

   ```ts
   import fileAccess from '@ohos.file.fileAccess';
   import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
   ```

   其中fileAccess提供了文件基础操作的API，fileExtensionInfo提供了应用开发的关键结构体。

3. 查询设备列表。
   开发者可以获取当前系统所有文件管理服务端管理的设备属性，也可以获取某个文件管理服务端管理的设备属性。应用开发者可以按需过滤设备。

   在文件访问框架中，使用RootInfo用于表示设备的属性信息。以下示例可以获取所有设备的RootInfo。

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   import { Filter } from '@ohos.file.fs';

   // 获取应用上下文
   let context = getContext(this) as common.UIAbilityContext;

   // 创建连接系统内所有文件管理服务端的helper对象
   let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
   function createFileAccessHelper(): void {
     try {    // this.context是EntryAbility传过来的Context
       fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);
       if (!fileAccessHelperAllServer) {
         console.error("createFileAccessHelper interface returns an undefined object");
       }
     } catch (err) {
         let error: BusinessError = err as BusinessError;
         console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   let rootInfos: Array<fileAccess.RootInfo> = [];
   async function getRoots(): Promise<void>{
     let rootIterator: fileAccess.RootIterator;
     let isDone: boolean = false;
     try {
       rootIterator = await fileAccessHelperAllServer.getRoots();
       if (!rootIterator) {
         console.error("getRoots interface returns an undefined object");
         return;
       }
       while (!isDone) {
         let result = rootIterator.next();
         console.info("next result = " + JSON.stringify(result));
         isDone = result.done;
         if (!isDone)
           rootInfos.push(result.value);
       }
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
     }
   }
   ```

4. 浏览目录。
   在文件访问框架中，使用FileInfo表示一个文件（目录）的基础信息。开发者可以使用listfile接口遍历下一级所有文件（目录）的迭代器对象；也可以通过scanfile过滤指定目录，获取满足条件的迭代器对象。

    listfile和scanfile接口当前支持RootInfo对象调用，可用于支撑遍历下一级文件或过滤整个目录树。同时，接口也支持FileInfo对象调用，用于支撑遍历下一级文件或过滤指定目录。

   ```ts
   import { BusinessError } from '@ohos.base';
   import { Filter } from '@ohos.file.fs';

   // 从根目录开始
   let rootInfo: Array<fileAccess.RootInfo> = rootInfos[0];
   let fileInfos: Array<fileAccess.FileInfo> = [];
   let isDone: boolean = false;
   let filter: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // 设定过滤条件
   try {  
     let fileIterator: string = rootInfo.listFile();          // 遍历设备rootinfos[0]的根目录，返回迭代器对象
     // let fileIterator = rootInfo.scanFile(filter); // 过滤设备rootinfos[0]满足指定条件的文件信息，返回迭代对象
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone) {
       let result: boolean = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone = result.done;
       if (!isDone)
         fileInfos.push(result.value);
     }
   } catch (err) {
    let error: BusinessError = err as BusinessError;
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   
   // 从指定的目录开始
   let fileInfoDir: Array<fileAccess.FileInfo> = fileInfos[0]; // fileInfoDir 表示某个目录信息
   let subFileInfos: Array<fileAccess.FileInfo> = [];
   let isDone02: boolean = false;
   let filter02: Filter = {suffix : [".txt", ".jpg", ".xlsx"]}; // 设定过滤条件
   try {
     let fileIterator: string = fileInfoDir.listFile(); // 遍历特定的目录fileinfo，返回迭代器对象
     // let fileIterator = rootInfo.scanFile(filter02); // 过滤特定的目录fileinfo，返回迭代器对象
     if (!fileIterator) {
       console.error("listFile interface returns an undefined object");
     }
     while (!isDone02) {
       let result: boolean = fileIterator.next();
       console.info("next result = " + JSON.stringify(result));
       isDone02 = result.done;
       if (!isDone02)
         subFileInfos.push(result.value);
     }
   } catch (err) {
    let error: BusinessError = err as BusinessError;
     console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
   }
   ```

5. 操作文件或目录。
   开发者可以集成文件访问框架的接口，完成一些用户行为，比如删除文件（目录）、重命名文件（目录）、新建文件（目录）、移动文件（目录）等。以下示例展示了如何创建一个文件，其他接口请参见[API参考](../reference/apis/js-apis-fileAccess.md)。

   ```ts
   import { BusinessError } from '@ohos.base';

   // 以本地设备为例
   // 创建文件
   // 示例代码sourceUri是Download目录的fileinfo中的URI
   // 开发者应根据自己实际获取fileinfo的URI进行开发
   async function creatFile(): Promise<void> {
     let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
     let displayName: string = "file1";
     let fileUri: string = '';
     try {
       // fileAccessHelperAllServer 参考 fileAccess.createFileAccessHelper 示例代码获取
       fileUri = await fileAccessHelperAllServer.createFile(sourceUri, displayName);
       if (!fileUri) {
         console.error("createFile return undefined object");
       }
       console.info("createFile sucess, fileUri: " + JSON.stringify(fileUri));
     } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
     };
   }
   ```
