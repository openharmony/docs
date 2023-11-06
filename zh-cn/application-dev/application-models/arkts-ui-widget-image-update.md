# 刷新本地图片和网络图片


在卡片上通常需要展示本地图片或从网络上下载的图片，获取本地图片和网络图片需要通过FormExtensionAbility来实现，如下示例代码介绍了如何在卡片上显示本地图片和网络图片。


1. 下载网络图片需要使用到网络能力，需要申请ohos.permission.INTERNET权限，配置方式请参见[配置文件权限声明](../security/accesstoken-guidelines.md)。

2. 在EntryFormAbility中的onAddForm生命周期回调中实现本地文件的刷新。

   ```ts
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import fs from '@ohos.file.fs';
   import Want from '@ohos.app.ability.Want';
   import Base from '@ohos.base';
   import fileFs from '@ohos.file.fs';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     ...
    // 在添加卡片时，打开一个本地图片并将图片内容传递给卡片页面显示
    onAddForm(want: Want) {
      // 假设在当前卡片应用的tmp目录下有一个本地图片：head.PNG
      let tempDir = this.context.getApplicationContext().tempDir;
      // 打开本地图片并获取其打开后的fd
      let file: fileFs.File;
      let imgBear: Record<string, number>;
      try {
        file = fs.openSync(tempDir + '/' + 'head.PNG');
        imgBear = {
          'imgBear': file.fd
        }
      } catch (e) {
        console.error(`openSync failed: ${JSON.stringify(e as Base.BusinessError)}`);
      }
      class FormDataClass{
        text: string = 'Image: Bear'
        imgName: string = 'imgBear'
        loaded: boolean = true
        formImages: Record<string, number> = imgBear
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
    import formBindingData from '@ohos.app.form.formBindingData';
    import formProvider from '@ohos.app.form.formProvider';
    import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
    import request from '@ohos.request';
    import fs from '@ohos.file.fs';
    import Base from '@ohos.base';
    import fileFs from '@ohos.file.fs';

    export default class EntryFormAbility extends FormExtensionAbility {
      // 在卡片页面触发message事件时，下载一个网络图片，并将网络图片内容传递给卡片页面显示
      onFormEvent(formId: string, message: string) {
        let param: Record<string, string> = {
          'text': '刷新中...'
        };
        let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
        formProvider.updateForm(formId, formInfo);
        // 注意：FormExtensionAbility在触发生命周期回调时被拉起，仅能在后台存在5秒
        // 建议下载能快速下载完成的小文件，如在5秒内未下载完成，则此次网络图片无法刷新至卡片页面上
        let netFile = 'https://xxxx/xxxx.png'; // 需要在此处使用真实的网络图片下载链接
        let tempDir = this.context.getApplicationContext().tempDir;
        let fileName = 'file' + Date.now();
        let tmpFile = tempDir + '/' + fileName;
        request.downloadFile(this.context, {
          url: netFile, filePath: tmpFile, enableMetered: true, enableRoaming: true
        }).then((task) => {
          task.on('complete', () => {
            console.info('ArkTSCard download complete:' + tmpFile);
            let file: fileFs.File;
            let fileInfo: Record<string, string | number> ={};
            try {
              file = fs.openSync(tmpFile);
              fileInfo[fileName] = file.fd;
            } catch (e) {
              console.error(`openSync failed: ${JSON.stringify(e as Base.BusinessError)}`);
            }
            class FormDataClass{
              text: string = 'Image: Bear' + fileName
              imgName: string = fileName
              loaded: boolean = true
              formImages: object = fileInfo
            }
            let formData = new FormDataClass();

            let formInfo = formBindingData.createFormBindingData(formData);
            formProvider.updateForm(formId, formInfo).then(() => {
              console.info('FormAbility updateForm success.');
            }).catch((error: Base.BusinessError) => {
              console.error('FormAbility updateForm failed: ' + JSON.stringify(error));
            });
          })
          task.on('fail', (err: number) => {
            console.info('ArkTSCard download task failed. Cause:' + err);
            let param: Record<string, string> = {
              'text': '刷新失败'
            };
            let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
            formProvider.updateForm(formId, formInfo);
          });
        }).catch((err: Base.BusinessError) => {
          console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
        });
      }
    };
   ```

4. 在卡片页面通过Image组件展示EntryFormAbility传递过来的卡片内容。

    ```ts
    let storage = new LocalStorage();
    @Entry(storage)
    @Component
    struct WidgetCard {
      @LocalStorageProp('text') text: string = '加载中...';
      @LocalStorageProp('loaded') loaded: boolean = false;
      @LocalStorageProp('imgName') imgName: string = 'name';

      build() {
        Column() {
          Text(this.text)
            .fontSize('12vp')
            .textAlign(TextAlign.Center)
            .width('100%')
            .height('20%')

          Row() {
            if (this.loaded) {
              Image('memory://' + this.imgName)
                .width('50%')
                .height('50%')
                .margin('5%')
            } else {
              Image('common/start.PNG')
                .width('50%')
                .height('50%')
                .margin('1%')
            }
          }.alignItems(VerticalAlign.Center)
          .justifyContent(FlexAlign.Center)

          Button('刷新')
            .height('15%')
            .onClick(() => {
              postCardAction(this, {
                'action': 'message',
                'params': {
                  'info': 'refreshImage'
                }
              });
            })
        }
        .width('100%').height('100%')
        .alignItems(HorizontalAlign.Center)
        .padding('5%')
      }
    }
   ```

> **说明：**
> - Image组件通过入参(**memory://fileName**)中的**memory://**标识来进行远端内存图片显示，其中**fileName**需要和EntryFormAbility传递对象(**'formImages': {key: fd})**中的**key**相对应。
>
> - Image组件通过传入的参数是否有变化来决定是否刷新图片，因此EntryFormAbility每次传递过来的**imgName**都需要不同，连续传递两个相同的**imgName**时，图片不会刷新。
