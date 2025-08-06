# 跨设备文件拷贝
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--SE: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

分布式文件系统为应用提供了跨设备文件拷贝的能力，开发者可以通过[基础文件接口](../reference/apis-core-file-kit/js-apis-file-fs.md)进行跨设备拷贝文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可将沙箱文件拷贝到设备A的分布式目录下。设备B在粘贴时，从B设备的分布式目录下将文件拷贝到对应的沙箱文件中。

## 开发步骤

1. 完成分布式组网。
   将需要跨设备访问的两个设备登录同一账号，保证设备蓝牙和Wi-Fi功能开启，蓝牙无需互连，Wi-Fi无需接入同一个局域网。

2. 授权分布式数据同步权限。
   分布式数据同步权限的授权方式为user_grant，因此需要调用requestPermissionsFromUser接口，以动态弹窗的方式向用户申请授权。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   import { common, abilityAccessCtrl } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let atManager = abilityAccessCtrl.createAtManager();
   try {
     //以动态弹窗的方式向用户申请授权
     atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC']).then((result) => {
       console.info(`Request permission result: ${JSON.stringify(result)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Catch err. Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
   }
   ```

3. 执行跨设备文件拷贝操作。
   同一应用在不同设备之间实现跨设备文件拷贝，只需要将对应的文件放在应用沙箱的分布式目录即可。

   将A设备的待拷贝沙箱文件拷贝到A设备的分布式目录下。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // 待拷贝文件沙箱路径
   let filePath: string = pathDir + '/src.txt';
   try {
    // 准备待拷贝沙箱文件
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    fs.writeSync(file.fd, 'Create file success');
    fs.closeSync(file);
   } catch (error) {
    console.error(`Failed to createFile. Code: ${error.code}, message: ${error.message}`);
   }

   // 获取待拷贝源文件uri
   let srcUri = fileUri.getUriFromPath(filePath);
   // 获取目标路径(分布式目录)的uri
   let destUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');
   try {
     // 将沙箱路径下的源文件拷贝到目标分布式目录下
     fs.copy(srcUri, destUri).then(()=>{
       console.info(`Succeeded in copying---. `);
       console.info(`src: ${srcUri} dest: ${destUri}`);
     }).catch((error: BusinessError)=>{
       let err: BusinessError = error as BusinessError;
       console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     console.error(`Catch err. Failed to copy. Code: ${error.code}, message: ${error.message}`);
   }
   ```

   B设备在获取A设备沙箱文件时，从B设备的分布式目录下将对应的文件拷贝走，以此完成跨设备拷贝。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';

   // context是EntryAbility传过来的context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // 待拷贝文件的目标路径(沙箱路径)
   let destPath: string = pathDir + '/dest.txt';
   // 获取目标路径uri
   let destUri = fileUri.getUriFromPath(destPath);

   // 拷贝源文件路径(分布式目录)
   let srcPath = distributedPathDir + '/src.txt';
   // 获取源路径uri
   let srcUri: string = fileUri.getUriFromPath(srcPath);

   // 定义拷贝回调
   let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
     console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
   };
   let options: fs.CopyOptions = {
     "progressListener" : progressListener
   };
   // 通过分布式设备管理的接口获取设备A的networkId信息
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`success to get available device list`);
    let networkId = deviceInfoList[0].networkId; // 这里只是两个设备连接，列表中首个即为A设备的networkId
    // 定义访问分布式目录的回调
    let listeners : fs.DfsListeners = {
      onStatus: (networkId: string, status: number): void => {
        console.error(`Failed to access public directory，${status}`);
      }
    };
    // 开始跨设备文件拷贝
    fs.connectDfs(networkId, listeners).then(()=>{
      try {
        // 将分布式目录下的文件拷贝到其他沙箱路径下
        fs.copy(srcUri, destUri, options).then(()=>{
          console.info(`Succeeded in copying from distribted path`);
          console.info(`src: ${srcUri} dest: ${destUri}`);
          fs.unlinkSync(srcPath); // 拷贝完成后清理分布式目录下的临时文件
        }).catch((error: BusinessError)=>{
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
        })
      } catch (error) {
        console.error(`Catch err. Failed to copy. Code: ${error.code}, message: ${error.message}`);
      }
    }).catch((error: BusinessError) => {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to connect dfs. Code: ${err.code}, message: ${err.message}`);
    });
   }
   ```

4. 跨设备文件拷贝完成，断开链路。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'
   import { fileIo as fs } from '@kit.CoreFileKit';

   // 获取设备A的networkId
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Success to get available device list`);
    let networkId = deviceInfoList[0].networkId; // 这里只是两个设备连接，列表中首个即为A设备的networkId
    // 关闭跨设备文件拷贝
    fs.disconnectDfs(networkId).then(() => {
      console.info(`Success to disconnect dfs`);
    }).catch((error: BusinessError) => {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
    })
   }
   ```