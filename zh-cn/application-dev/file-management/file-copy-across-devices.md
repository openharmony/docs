# 跨设备文件拷贝

分布式文件系统为应用提供了跨设备文件拷贝的能力，开发者在跨设备跨应用进行文件拷贝时，通过[基础文件接口](../reference/apis/js-apis-file-fs.md)，可跨设备跨应用拷贝文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可通过剪切板，将设备A上的文件，拷贝到设备B的某个应用中。

## 开发步骤

1. 完成分布式组网。
   首先将需要进行跨设备访问的设备连接到同一局域网中，同帐号认证完成组网。

2. 将待拷贝文件的uri写入剪切板，通过分布式剪切板，将uri转换为分布式uri。跨设备从分布式剪切板获取到分布式uri，调用基础文件接口fs.copy，完成文件的跨端拷贝。

   设备A上将待拷贝文件uri写入分布式剪切板中，完成复制。

   ```ts
   import fs from '@ohos.file.fs';
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   import pasteboard from '@ohos.pasteboard';
   import fileuri from '@ohos.file.fileuri';

   let context = getContext(this) as common.UIAbilityContext; // 获取设备A的UIAbilityContext信息
   let pathDir: string = context.filesDir;
   // 获取待拷贝文件沙箱路径
   let filePath: string = pathDir + '/src.txt';

   // 获取待拷贝文件uri
   let fileUri = fileuri.getUriFromPath(filePath);
   
   try {
     // 在待拷贝文件uri写入剪切板
     let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, fileUri);
     pasteboard.getSystemPasteboard().setData(pasteData, (err: BusinessError) => {
       if (err) {
         console.error(`Failed to set paste data. Code: ${err.code}, message: ${err.message}`);
         return;
       }
       console.info('Succeeded in setting paste data.');
     });
   } catch (error) {
     console.error(`Failed to set paste data: ${JSON.stringify(error)}`);
   }
   ```

   设备B上从剪切板获取到待拷贝文件的分布式uri。

   ```ts
   import fs from '@ohos.file.fs';
   import common from '@ohos.app.ability.common';
   import buffer from '@ohos.buffer';
   import { BusinessError } from '@ohos.base';
   import pasteboard from '@ohos.pasteboard';
   
   let context = getContext(this) as common.UIAbilityContext; // 获取设备B的UIAbilityContext信息
   let pathDir: string = context.filesDir;

   // 定义待拷贝文件的目标拷贝路径
   let destPath: string = pathDir + '/dest.txt';
   // 获取目标路径对应的uri
   let destUri = fileuri.getUriFromPath(destPath);

   try {
     // 从剪切板中获取待拷贝的文件信息
     pasteboard.getSystemPasteboard().getData().then((pasteData) => {
       let pasteDataUri = pasteData.getPrimaryUri();
       console.info(`Succeeded in getting paste data, pasteDataUri = ${pasteDataUri}`);

       // 定义拷贝回调
       let progressListener: fs.ProgressListener = (progress: fs.Progress) => {
	     console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
       };
       let options: fs.CopyOptions = {
         "progressListener" : progressListener
       }

       // 进行拷贝
       fs.copy(pasteDataUri, destUri, options).then(()=>{
         console.info("Succeeded in copying. ");
       }).catch((err: BusinessError)=>{
         console.info(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
       })
     }).catch((err: BusinessError)=>{
       console.error(`Failed to getData. Code: ${err.code}, message: ${err.message}`);
     })
   } catch(err) {
     console.error(`Failed to getData: ${JSON.stringify(err)}`);
   }
   ```
