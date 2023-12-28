# 刷新本地图片和网络图片


在卡片上通常需要展示本地图片或从网络上下载的图片，获取本地图片和网络图片需要通过FormExtensionAbility来实现，如下示例代码介绍了如何在卡片上显示本地图片和网络图片。


1. 下载网络图片需要使用到网络能力，需要申请ohos.permission.INTERNET权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 在EntryFormAbility中的onAddForm生命周期回调中实现本地文件的刷新。

   ```ts
   import type Base from '@ohos.base';
   import type fileFs from '@ohos.file.fs';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formInfo from '@ohos.app.form.formInfo';
   import formProvider from '@ohos.app.form.formProvider';
   import fs from '@ohos.file.fs';
   import hilog from '@ohos.hilog';
   import request from '@ohos.request';
   import type Want from '@ohos.app.ability.Want';
   
   const TAG: string = 'WgtImgUpdateEntryFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
     // 在添加卡片时，打开一个本地图片并将图片内容传递给卡片页面显示
     onAddForm(want: Want): formBindingData.FormBindingData {
       // 假设在当前卡片应用的tmp目录下有一个本地图片：head.PNG
       let tempDir = this.context.getApplicationContext().tempDir;
       // 打开本地图片并获取其打开后的fd
       let file: fileFs.File;
       let imgBear: Record<string, number>;
       try {
         file = fs.openSync(tempDir + '/' + 'head.PNG');
         imgBear = {
           'imgBear': file.fd
         };
       } catch (e) {
         console.error(`openSync failed: ${JSON.stringify(e as Base.BusinessError)}`);
       };
   
       class FormDataClass {
         text: string = 'Image: Bear';
         imgName: string = 'imgBear';
         loaded: boolean = true;
         formImages: Record<string, number> = imgBear;
       }
   
       let formData = new FormDataClass();
   
       // 将fd封装在formData中并返回至卡片页面
       return formBindingData.createFormBindingData(formData);
     }
   
     ...
   }
   ```

3. 在EntryFormAbility中的onFormEvent生命周期回调中实现网络文件的刷新。

   ```ts
   import type Base from '@ohos.base';
   import type fileFs from '@ohos.file.fs';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formInfo from '@ohos.app.form.formInfo';
   import formProvider from '@ohos.app.form.formProvider';
   import fs from '@ohos.file.fs';
   import hilog from '@ohos.hilog';
   import request from '@ohos.request';
   import type Want from '@ohos.app.ability.Want';
   
   const TAG: string = 'WgtImgUpdateEntryFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
     onFormEvent(formId: string, message: string): void {
       let param: Record<string, string> = {
         'text': '刷新中...'
       };
       let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
       formProvider.updateForm(formId, formInfo);
       // 注意：FormExtensionAbility在触发生命周期回调时被拉起，仅能在后台存在5秒
       // 建议下载能快速下载完成的小文件，如在5秒内未下载完成，则此次网络图片无法刷新至卡片页面上
       let netFile = 'https://cn-assets.gitee.com/assets/mini_app-e5eee5a21c552b69ae6bf2cf87406b59.jpg'; // 需要在此处使用真实的网络图片下载链接
       let tempDir = this.context.getApplicationContext().tempDir;
       let fileName = 'file' + Date.now();
       let tmpFile = tempDir + '/' + fileName;
       request.downloadFile(this.context, {
         url: netFile, filePath: tmpFile, enableMetered: true, enableRoaming: true
       }).then((task) => {
         task.on('complete', () => {
           hilog.info(DOMAIN_NUMBER, TAG, 'ArkTSCard download complete: %{public}s', tmpFile);
           let file: fileFs.File;
           let fileInfo: Record<string, string | number> = {};
           try {
             file = fs.openSync(tmpFile);
             fileInfo[fileName] = file.fd;
           } catch (e) {
             console.error(`openSync failed: ${JSON.stringify(e as Base.BusinessError)}`);
           };
   
           class FormDataClass {
             text: string = 'Image: Bear' + fileName;
             imgName: string = fileName;
             loaded: boolean = true;
             formImages: object = fileInfo;
           }
   
           let formData = new FormDataClass();
           let formInfo = formBindingData.createFormBindingData(formData);
           formProvider.updateForm(formId, formInfo).then(() => {
             hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'FormAbility updateForm success.');
           }).catch((error: Base.BusinessError) => {
             hilog.error(DOMAIN_NUMBER, TAG, `FormAbility updateForm failed: ${JSON.stringify(error)}`);
           });
         });
         task.on('fail', (err: number) => {
           hilog.info(DOMAIN_NUMBER, TAG, `ArkTSCard download task failed. Cause: ${JSON.stringify(err)}`);
           let param: Record<string, string> = {
             'text': '刷新失败'
           };
           let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
           formProvider.updateForm(formId, formInfo);
         });
       }).catch((err: Base.BusinessError) => {
         hilog.error(DOMAIN_NUMBER, TAG, `Failed to request the download. Cause: ${JSON.stringify(err)}`);
       });
     }
     ...
   }
   ```

4. 在卡片页面通过Image组件展示EntryFormAbility传递过来的卡片内容。

   ```ts
   let storageWidgetImageUpdate = new LocalStorage();
   
   @Entry(storageWidgetImageUpdate)
   @Component
   struct WidgetImageUpdateCard {
     @LocalStorageProp('text') text: ResourceStr = $r('app.string.loading');
     @LocalStorageProp('loaded') loaded: boolean = false;
     @LocalStorageProp('imgName') imgName: ResourceStr = $r('app.string.imgName');
   
     build() {
       if (this.loaded) {
         Column() {
           Column() {
             Text(this.text)
               .fontColor('#FFFFFF')
               .opacity(0.9)
               .fontSize(12)
               .textOverflow({ overflow: TextOverflow.Ellipsis })
               .maxLines(1)
               .margin({ top: '8%', left: '10%' })
           }.width('100%').height('50%')
           .alignItems(HorizontalAlign.Start)
   
           Row() {
             Button() {
               Text($r('app.string.update'))
                 .fontColor('#45A6F4')
                 .fontSize(12)
             }
             .width(120)
             .height(32)
             .margin({ top: '30%', bottom: '10%' })
             .backgroundColor('#FFFFFF')
             .borderRadius(16)
             .onClick(() => {
               postCardAction(this, {
                 action: 'message',
                 params: {
                   info: 'refreshImage'
                 }
               });
             })
           }.width('100%').height('40%')
           .justifyContent(FlexAlign.Center)
         }.width('100%').height('100%')
         .backgroundImage('memory://' + this.imgName)
         .backgroundImageSize(ImageSize.Cover)
       } else {
         Column() {
           Column() {
             Text(this.text)
               .fontColor('#FFFFFF')
               .opacity(0.9)
               .fontSize(12)
               .textOverflow({ overflow: TextOverflow.Ellipsis })
               .maxLines(1)
               .margin({ top: '8%', left: '10%' })
           }.width('100%').height('50%')
           .alignItems(HorizontalAlign.Start)
   
           Row() {
             Button() {
               Text($r('app.string.update'))
                 .fontColor('#45A6F4')
                 .fontSize(12)
             }
             .width(120)
             .height(32)
             .margin({ top: '30%', bottom: '10%' })
             .backgroundColor('#FFFFFF')
             .borderRadius(16)
             .onClick(() => {
               postCardAction(this, {
                 action: 'message',
                 params: {
                   info: 'refreshImage'
                 }
               });
             })
           }.width('100%').height('40%')
           .justifyContent(FlexAlign.Center)
         }.width('100%').height('100%')
         .backgroundImage($r('app.media.ImageDisp'))
         .backgroundImageSize(ImageSize.Cover)
       }
     }
   }
   ```

> **说明：**
>
> - Image组件通过入参(**memory://fileName**)中的**memory://**标识来进行远端内存图片显示，其中**fileName**需要和EntryFormAbility传递对象(**'formImages': {key: fd})**中的**key**相对应。
>
> - Image组件通过传入的参数是否有变化来决定是否刷新图片，因此EntryFormAbility每次传递过来的**imgName**都需要不同，连续传递两个相同的**imgName**时，图片不会刷新。
>
> - 文件使用完成后必须关闭，否则会出现内存泄漏问题。系统不会自动关闭文件，开发者可以使用[fs.closeSync](../reference/apis/js-apis-file-fs.md#fsclosesync)来关闭文件。
