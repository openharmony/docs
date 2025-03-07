# 跨设备文件拷贝

分布式文件系统为应用提供了跨设备文件拷贝的能力，开发者在跨设备跨应用进行文件拷贝时，通过[基础文件接口](../reference/apis-core-file-kit/js-apis-file-fs.md)，可跨设备跨应用拷贝文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可在复制时，将A设备的沙箱文件，拷贝到A设备的分布式路径下，设备B在粘贴的时候，从设备B的分布式路径下，将文件拷贝到对应的沙箱文件中。

## 开发步骤

1. 完成分布式组网。
   首先将需要进行跨设备访问的设备连接到同一局域网中，同账号认证完成组网。

2. 拷贝跨设备文件。 同一应用不同设备之间实现跨设备文件拷贝，只需要将对应的文件放在应用沙箱的分布式文件路径即可。

   将A设备的待拷贝沙箱文件，拷贝到A设备的分布式路径下。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   let context = getContext(this) as common.UIAbilityContext; // 获取设备A的UIAbilityContext信息
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // 待拷贝文件沙箱路径
   let filePath: string = pathDir + '/src.txt';
   
   try {
    // 文件不存在时，需要创建文件并写入内容
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    fs.writeSync(file.fd, 'Create file success');
    fs.closeSync(file);
   } catch (error) {
    console.error(`Failed to createFile. Code: ${error.code}, message: ${error.message}`);
   }

   // 获取待拷贝文件uri
   let srcUri = fileUri.getUriFromPath(filePath);
   
   // 将待拷贝的沙箱文件，拷贝到分布式目录下
   let destUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');

   try {
    // 将沙箱路径下的文件拷贝到分布式路径下
    fs.copy(srcUri, destUri).then(()=>{
      console.info("Succeeded in copying---. ");
      console.info("src: " + srcUri + "dest: " + destUri);
    }).catch((error: BusinessError)=>{
      let err: BusinessError = error as BusinessError;
      console.info(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
    })
   } catch (error) {
    console.error(`Failed to getData. Code: ${error.code}, message: ${error.message}`);
   }
   ```

   B设备在获取A端沙箱文件时，从B设备的分布式路径下将对应的文件拷贝走，以此完成跨设备拷贝。

   ```ts
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileUri } from '@kit.CoreFileKit';

   let context = getContext(this) as common.UIAbilityContext; // 获取设备B的UIAbilityContext信息
   let pathDir: string = context.filesDir;
   let distributedPathDir: string = context.distributedFilesDir;
   // 待拷贝文件的目标沙箱路径
   let filePath: string = pathDir + '/dest.txt';

   // 获取目标路径uri
   let destUri = fileUri.getUriFromPath(filePath);

   // 获取分布式路径下的源文件
   let srcUri: string = fileUri.getUriFromPath(distributedPathDir + '/src.txt');

   // 定义拷贝回调
   let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
     console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
   };
   let options: fs.CopyOptions = {
     "progressListener" : progressListener
   }

   try {
    // 将分布式路径下的文件拷贝到其他沙箱路径下
    fs.copy(srcUri, destUri, options).then(()=>{
      console.info("Succeeded in copying of paste. ");
      console.info("src: " + srcUri + "dest: " + destUri); // file://com.example.myapplication/data/storage/el2/distributedfiles/src.txt
    }).catch((error: BusinessError)=>{
      let err: BusinessError = error as BusinessError;
      console.info(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
    })
   } catch (error) {
    console.error(`Failed to copy. Code: ${error.code}, message: ${error.message}`);
   }
   ```