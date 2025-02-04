# 跨设备文件访问

分布式文件系统为应用提供了跨设备文件访问的能力，开发者在两个设备安装同一应用时，通过[基础文件接口](app-file-access.md)，可跨设备读写另一个设备该应用[分布式文件路径](app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)（/data/storage/el2/distributedfiles/）下的文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可访问设备B同应用分布式路径下的文件，当期望应用文件被其他设备访问时，只需将文件移动到分布式文件路径即可。

## 开发步骤

1. 完成分布式组网。
   将需要跨设备访问的两个设备登录同一账号，保证设备蓝牙和Wi-Fi功能开启，蓝牙无需互连，Wi-Fi无需接入同一个局域网。

2. 访问跨设备文件。
   同一应用不同设备之间实现跨设备文件访问，只需要将对应的文件放在应用沙箱的分布式文件路径即可。

   设备A上在分布式路径下创建测试文件，并写入内容。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
 
   let context = getContext(this) as common.UIAbilityContext; // 获取设备A的UIAbilityContext信息
   let pathDir: string = context.distributedFilesDir;
   // 获取分布式目录的文件路径
   let filePath: string = pathDir + '/test.txt';
   
   try {
     // 在分布式目录下创建文件
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in createing.');
     // 向文件中写入内容
     fs.writeSync(file.fd, 'content');
     // 关闭文件
     fs.closeSync(file.fd);
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   } 
   ```

   设备B主动向设备A发起建链，建链成功后设备B可在分布式路径下读取测试文件。
   > **说明：**
   >
   > 这里通过分布式设备管理的接口获取设备networkId，详见[设备管理接口](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md)。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { buffer } from '@kit.ArkTS';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'
 
   // 通过分布式设备管理的接口获取设备A的networkId信息
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   let networkId = deviceInfoList[0].networkId;
 
   // 定义访问公共文件目录的回调
   let listeners : fs.DfsListeners = {
     onStatus: (networkId: string, status: number): void => {
       console.info('Failed to access public directory');
     }
   }
 
   // 访问并挂载公共文件目录
   fs.connectDfs(networkId, listeners).then(() => {
     console.info("Success to connectDfs");
     let context = getContext(); // 获取设备B的UIAbilityContext信息
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
       }
       let option = new Option();
       option.length = arrayBuffer.byteLength;
       let num = fs.readSync(file.fd, arrayBuffer, option);
       // 打印读取到的文件数据
       let buf = buffer.from(arrayBuffer, 0, num);
       console.info('read result: ' + buf.toString());
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
     }
   }).catch((error: BusinessError) => {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to connectDfs Code: ${err.code}, message: ${err.message}`);
   });
   ```

3. B设备访问跨设备文件完成，断开链路。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'
   import { fileIo as fs } from '@kit.CoreFileKit';
   
   // 获取设备A的networkId
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   let networkId = deviceInfoList[0].networkId;
 
   // 取消公共文件目录挂载
   fs.disconnectDfs(networkId).then(() => {
     console.info("Success to disconnectDfs");
   }).catch((error: BusinessError) => {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to disconnectDfs Code: ${err.code}, message: ${err.message}`)
   })
   ```