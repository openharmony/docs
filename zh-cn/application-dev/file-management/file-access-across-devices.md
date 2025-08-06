# 跨设备文件访问
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--SE: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

分布式文件系统为应用提供了跨设备文件访问的能力，开发者在两个设备上安装同一应用时，通过[基础文件接口](app-file-access.md)，可跨设备读写另一个设备上该应用[分布式目录](app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)（/data/storage/el2/distributedfiles/）下的文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可访问设备B上的同应用分布式目录下的文件，当期望应用文件被其他设备访问时，只需将文件移动到分布式目录即可。

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
       console.info(`request permission result: ${JSON.stringify(result)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
     })
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Catch err. Failed to request permissions from user. Code: ${err.code}, message: ${err.message}`);
   }
   ```

3. 访问跨设备文件。
   同一应用不同设备之间实现跨设备文件访问，只需要将对应的文件放在应用沙箱的分布式目录即可。

   设备A上在分布式目录下创建测试文件，并写入内容。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
 
   // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
   let pathDir: string = context.distributedFilesDir;
   // 获取分布式目录的文件路径
   let filePath: string = pathDir + '/test.txt';
   
   try {
     // 在分布式目录下创建文件
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in creating.');
     // 向文件中写入内容
     fs.writeSync(file.fd, 'content');
     // 关闭文件
     fs.closeSync(file.fd);
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   } 
   ```

   设备B主动向设备A发起建链，建链成功后设备B可在分布式目录下读取测试文件。
   > **说明：**
   >
   > 这里通过分布式设备管理的接口获取设备networkId，详见[设备管理接口](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md)。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { buffer } from '@kit.ArkTS';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
 
   // 通过分布式设备管理的接口获取设备A的networkId信息
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
     console.info(`Success to get available device list`);
     let networkId = deviceInfoList[0].networkId;
     // 定义访问公共文件目录的回调
     let listeners : fs.DfsListeners = {
       onStatus: (networkId: string, status: number): void => {
         console.info('Failed to access public directory');
       }
     };
     // 开始跨设备文件访问
     fs.connectDfs(networkId, listeners).then(() => {
       console.info("Success to connect dfs");
       // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
       let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
       let pathDir: string = context.distributedFilesDir;
       // 获取分布式目录的文件路径
       let filePath: string = pathDir + '/test.txt';
       try {
         // 打开分布式目录下的文件
         let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
         // 定义接收读取数据的缓存
         let arrayBuffer = new ArrayBuffer(4096);
         // 读取文件的内容，返回值是读取到的字节个数
         class Option {
             public offset: number = 0;
             public length: number = 0;
         };
         let option = new Option();
         option.length = arrayBuffer.byteLength;
         let num = fs.readSync(file.fd, arrayBuffer, option);
         // 打印读取到的文件数据
         let buf = buffer.from(arrayBuffer, 0, num);
         console.info('read result: ' + buf.toString());
         fs.closeSync(file);
       } catch (error) {
         let err: BusinessError = error as BusinessError;
         console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
       }
     }).catch((error: BusinessError) => {
       let err: BusinessError = error as BusinessError;
       console.error(`Failed to connect dfs. Code: ${err.code}, message: ${err.message}`);
     });
   }
   ```

3. B设备访问跨设备文件完成，断开链路。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   // 获取设备A的networkId
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   if (deviceInfoList && deviceInfoList.length > 0) {
     console.info(`Success to get available device list`);
     let networkId = deviceInfoList[0].networkId;
    // 关闭跨设备文件访问
     fs.disconnectDfs(networkId).then(() => {
       console.info("Success to disconnect dfs");
     }).catch((err: BusinessError) => {
       console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
     })
   }
   ```