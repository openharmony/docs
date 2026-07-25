# 使用Picker选择媒体库资源
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

当用户需要分享图片、视频等文件时，开发者可以通过特定接口拉起系统图库，让用户自行选择待分享的资源，完成分享。此接口本身无需申请权限，目前适用于界面UIAbility，使用窗口组件触发。具体使用方式如下：

> **注意：**
> Media Library Kit提供图片和视频的管理能力，当需要读取和保存音频文件时，请使用[AudioViewPicker（音频选择器对象）](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)。

1. 导入选择器模块和文件管理模块。
   <!-- @[PickerMediaLibrary_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  
   
   ``` TypeScript
   import { fileIo } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   ```

2. 创建图片-视频类型文件选择选项实例。

   <!-- @[PickerMediaLibrary_createOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. 配置可选的媒体文件类型和媒体文件的最大数目。

    以下示例以图片选择为例，媒体文件类型请参见[PhotoViewMIMETypes](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)。

    <!-- @[PickerMediaLibrary_configOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   photoSelectOptions.maxSelectNumber = 5;
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
   photoSelectOptions.isPhotoTakingSupported = true;
   ```

4. 创建图库选择器实例，调用[PhotoViewPicker.select](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select)接口拉起图库界面进行文件选择。文件选择成功后，返回[PhotoSelectResult](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectresult)结果集。

   <!-- @[PickerMediaLibrary_select](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->  
   
   ``` TypeScript
   const result = await photoViewPicker.select(photoSelectOptions);
               
   // 文件选择成功后，返回PhotoSelectResult结果集
   console.info('选择成功，返回结果: ' + JSON.stringify(result));
   console.info('选择的文件数量: ' + result.photoUris.length);
         
   // 更新选中的URI列表
   this.selectedUris = result.photoUris;
   // 设置默认选中第一个URI用于读取操作
   if (this.selectedUris.length > 0) {
     this.selectedUriForRead = this.selectedUris[0];
   }
         
   // 调用工具类处理结果
   this.processedItems = MediaLibraryPickerUtils.handleSelectResult(this.selectedUris);
   console.info('处理后的结果数量: ' + this.processedItems.length);
   ```

   select返回的uri权限是只读权限，可以根据结果集中uri进行读取文件数据操作。注意不能在picker的回调里直接使用此uri进行打开文件操作，需要定义一个全局变量保存uri，类似使用一个按钮去触发打开文件。可参考[指定URI读取文件数据](#指定uri读取文件数据)。

   也可以通过返回的uri[获取图片或视频资源](#指定uri获取图片或视频资源)。

   如有获取元数据需求，可以通过[@ohos.file.fs (文件管理)](../../reference/apis-core-file-kit/js-apis-file-fs.md)和[文件URI](../../reference/apis-core-file-kit/js-apis-file-fileuri.md)根据URI获取部分文件属性信息，比如文件大小、访问时间、修改时间、文件名、文件路径等。

## 指定URI读取文件数据

1. 待界面从图库返回后，再通过一个类似按钮的组件去调用其他函数，使用[fileIo.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync)接口，通过[媒体文件uri](../../file-management/user-file-uri-intro.md#媒体文件uri)打开这个文件得到fd。这里需要注意接口权限参数是fileIo.OpenMode.READ_ONLY。

   <!-- @[PickerMediaLibrary_openFile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->
   
   ``` TypeScript
   try {
     const file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
     console.info('file fd: ' + file.fd);
     return { fd: file.fd, file: file };
   } catch (error) {
     console.error('openSync failed with err: ' + error);
     return null;
   }
   ```

2. 通过fd使用[fileIo.readSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#readsync)接口读取这个文件内的数据，读取完成后关闭fd。

   <!-- @[PickerMediaLibrary_readFileData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->
   
   ``` TypeScript
   try {
     const buffer = new ArrayBuffer(bufferSize);
     const readLen = fileIo.readSync(fileObj.fd, buffer);
     console.info('readSync data to file succeed and buffer size is:' + readLen);
     return { data: buffer, length: readLen };
   } catch (error) {
     console.error('readSync failed with err: ' + error);
     return null;
   }
   ```

## 指定URI获取图片或视频资源

媒体库支持Picker选择[媒体文件](../../file-management/user-file-uri-intro.md#媒体文件uri)URI后，根据指定URI获取图片或视频资源，下面以查询指定URI为'file://media/Photo/1/IMG_datetime_0001/displayName.jpg'为例。

1. 定义媒体资源处理器[MediaAssetDataHandler](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)，系统在资源准备就绪时向应用回调onDataPrepared。

   <!-- @[PickerMediaLibrary_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  
   
   ``` TypeScript
   export class MediaAssetDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
     private callback?: MediaDataHandlerCallback;
     
     constructor(callback?: MediaDataHandlerCallback) {
       this.callback = callback;
     }
   
     // 使用箭头函数确保this引用不会丢失
     onDataPrepared = (data: ArrayBuffer, map?: Map<string, string>) => {
       if (data === undefined) {
         console.error('Error occurred when preparing data');
         return;
       }
       console.info('on image data prepared, photo quality is ' + map?.get('quality'));
       // 现在this始终指向MediaAssetDataHandler实例
       if (this.callback) {
         this.callback(data);
       }
     };
   }
   ```

2. 使用[getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1)接口获取要访问的资产，并通过[requestImageData](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#requestimagedata11)获取对应资源。

   > **注意：**
   > 出于对用户隐私安全的保护，对媒体资源EXIF中的地理位置和拍摄参数信息做了去隐私化处理。如果需要获取被去隐私化的EXIF信息，需要[申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.MEDIA_LOCATION'。

   <!-- @[PickerMediaLibrary_getMediaResource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  
   
   ``` TypeScript
   static async getMediaResourceByUri(uri: string, context: common.Context, callback?: MediaDataHandlerCallback)
   : Promise<void> {
     let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> | null = null;
     try {
       // 创建PhotoAccessHelper实例
       const phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
         
       // 创建查询条件
       const predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
       predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uri);
         
       // 设置查询选项
       const fetchOptions: photoAccessHelper.FetchOptions = {
         fetchColumns: [photoAccessHelper.PhotoKeys.TITLE],
         predicates: predicates
       };
   
       // 查询资产
       fetchResult = await phAccessHelper.getAssets(fetchOptions);
         
       const photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
       if (photoAsset) {
         console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
         // 获取标题属性
         console.info('title : ' + photoAsset.get(photoAccessHelper.PhotoKeys.TITLE));
           
         // 设置请求选项
         const requestOptions: photoAccessHelper.RequestOptions = {
           deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
         };
           
         // 请求图片数据
         await photoAccessHelper.MediaAssetManager.requestImageData(
           context, photoAsset, requestOptions, new MediaAssetDataHandler(callback));
           
         console.info('requestImageData successfully');
       } else {
         console.error('No asset found for URI: ' + uri);
       }
         
     } catch (err) {
       console.error('getMediaResourceByUri failed with err: ' + err);
     } finally {
        // 关闭查询结果。
        if (fetchResult !== null) {
          fetchResult.close();
        }
     }
   }
   ```
