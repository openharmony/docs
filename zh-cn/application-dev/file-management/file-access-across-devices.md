# 跨设备文件访问

分布式文件系统为应用提供了跨设备文件访问的能力，开发者在多个设备安装同一应用时，通过[基础文件接口](app-file-access.md)，可跨设备读写其他设备该应用分布式文件路径（/data/storage/el2/distributedfiles/）下的文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可访问设备B同应用分布式路径下的文件，当期望应用文件被其他设备访问时，只需将文件移动到分布式文件路径即可。

## 开发步骤

1. 完成分布式组网。
   首先将需要进行跨设备访问的设备连接到同一局域网中，同帐号认证完成组网。

2. 访问跨设备文件。
   同一应用不同设备之间实现跨设备文件访问，只需要将对应的文件放在应用沙箱的分布式文件路径即可。

   设备A上在分布式路径下创建测试文件，并写入内容。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

   设备A访问设备B公共文档目录，并挂载目录到沙箱路径下，如果设备B出现异常，业务执行回调DfsListeners内onStatus通知应用。实例中的networkId的获取方式请参见[distributedDeviceManager](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md)接口调用[deviceBasicInfo](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { distributedDeviceManager } from '@kit.DistributedServiceKit'

   let context = getContext(this) as common.UIAbilityContext; // 获取设备A的UIAbilityContext信息
   let pathDir: string = context.distributedFilesDir;
   // 获取分布式目录的文件路径
   let filePath: string = pathDir + '/test.txt';
   // 定义访问公共文件目录的回调
   let dmInstance = distributedDeviceManager.createDeviceManager("com.example.hap");
   let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   let networkId = deviceInfoList[0].networkId;
   let listeners : fs.DfsListeners = {
    onStatus: function (networkId: string, status: number): void {
      console.info('Failed to access public directory');
    }
   }
   
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

   // 访问并挂载公共文件目录
   fs.connectDfs(networkId, listeners).then(() => {
     console.info("Success to connectDfs");
   }).catch((error) => {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to connectDfs Code: ${error.code}, message: ${error.message}`);
   });
   // 取消公共文件目录挂载
   fs.disconnectDfs(networkId).then(() => {
     console.info("Success to disconnectDfs");
   }).catch((error) => {
     let err: BusinessError = error as BusinessError;
     console.error(`Failed to disconnectDfs Code: ${error.code}, message: ${error.message}`)
   })
   ```

   设备B上在分布式路径下读取测试文件。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { buffer } from '@kit.ArkTS';
   
   let context = getContext(this) as common.UIAbilityContext; // 获取设备B的UIAbilityContext信息
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
   ```
