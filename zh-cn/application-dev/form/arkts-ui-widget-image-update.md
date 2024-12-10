# 刷新本地图片和网络图片


在卡片上通常需要展示本地图片或从网络上下载的图片，获取本地图片和网络图片需要通过FormExtensionAbility来实现，如下示例代码介绍了如何在卡片上显示本地图片和网络图片。


1. 下载网络图片需要使用到网络能力，需要申请ohos.permission.INTERNET权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 在EntryFormAbility中的onAddForm生命周期回调中实现本地文件的刷新。

    ```ts
    import { Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo } from '@kit.CoreFileKit';
    import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    
    const TAG: string = 'WgtImgUpdateEntryFormAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    
    export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
      // 在添加卡片时，打开一个本地图片并将图片内容传递给卡片页面显示
      onAddForm(want: Want): formBindingData.FormBindingData {
        // 假设在当前卡片应用的tmp目录下有一个本地图片：head.PNG
        let tempDir = this.context.getApplicationContext().tempDir;
        hilog.info(DOMAIN_NUMBER, TAG, `tempDir: ${tempDir}`);
        let imgMap: Record<string, number> = {};
        try {
          // 打开本地图片并获取其打开后的fd
          let file = fileIo.openSync(tempDir + '/' + 'head.PNG');
          imgMap['imgBear'] = file.fd;
        } catch (e) {
          hilog.error(DOMAIN_NUMBER, TAG, `openSync failed: ${JSON.stringify(e as BusinessError)}`);
        }
    
        class FormDataClass {
          text: string = 'Image: Bear';
          loaded: boolean = true;
          // 卡片需要显示图片场景, 必须和下列字段formImages 中的key 'imgBear' 相同。
          imgName: string = 'imgBear';
          // 卡片需要显示图片场景, 必填字段(formImages 不可缺省或改名), 'imgBear' 对应 fd
          formImages: Record<string, number> = imgMap;
        }

        let formData = new FormDataClass();
        // 将fd封装在formData中并返回至卡片页面
        return formBindingData.createFormBindingData(formData);
      }
      //...
    }
    ```

3. 在EntryFormAbility中的onFormEvent生命周期回调中实现网络文件的刷新。

      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { fileIo } from '@kit.CoreFileKit';
      import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
      import { http } from '@kit.NetworkKit';
      import { hilog } from '@kit.PerformanceAnalysisKit';

      const TAG: string = 'WgtImgUpdateEntryFormAbility';
      const DOMAIN_NUMBER: number = 0xFF00;

      export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
        async onFormEvent(formId: string, message: string): Promise<void> {
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
          let imgMap: Record<string, number> = {};

          class FormDataClass {
            text: string = 'Image: Bear' + fileName;
            loaded: boolean = true;
            // 卡片需要显示图片场景, 必须和下列字段formImages 中的key fileName 相同。
            imgName: string = fileName;
            // 卡片需要显示图片场景, 必填字段(formImages 不可缺省或改名), fileName 对应 fd
            formImages: Record<string, number> = imgMap;
          }

          let httpRequest = http.createHttp()
          let data = await httpRequest.request(netFile);
          if (data?.responseCode == http.ResponseCode.OK) {
            try {
              let imgFile = fileIo.openSync(tmpFile, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
              imgMap[fileName] = imgFile.fd;
              try{
                let writeLen: number = await fileIo.write(imgFile.fd, data.result as ArrayBuffer);
                hilog.info(DOMAIN_NUMBER, TAG, "write data to file succeed and size is:" + writeLen);
                hilog.info(DOMAIN_NUMBER, TAG, 'ArkTSCard download complete: %{public}s', tmpFile);
                try {
                  let formData = new FormDataClass();
                  let formInfo = formBindingData.createFormBindingData(formData);
                  await formProvider.updateForm(formId, formInfo);
                  hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'FormAbility updateForm success.');
                } catch (error) {
                  hilog.error(DOMAIN_NUMBER, TAG, `FormAbility updateForm failed: ${JSON.stringify(error)}`);
                }
              } catch (err) {
                hilog.error(DOMAIN_NUMBER, TAG, "write data to file failed with error message: " + err.message + ", error code: " + err.code);
              } finally {
                fileIo.closeSync(imgFile);
              };
            } catch (e) {
              hilog.error(DOMAIN_NUMBER, TAG, `openSync failed: ${JSON.stringify(e as BusinessError)}`);
            }

          } else {
            hilog.error(DOMAIN_NUMBER, TAG, `ArkTSCard download task failed`);
            let param: Record<string, string> = {
              'text': '刷新失败'
            };
            let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
            formProvider.updateForm(formId, formInfo);
          }
          httpRequest.destroy();
        }
      }
      ```

4. 在卡片页面通过backgroundImage属性展示EntryFormAbility传递过来的卡片内容。

    ```ts
    let storageWidgetImageUpdate = new LocalStorage();
    
    @Entry(storageWidgetImageUpdate)
    @Component
    struct WidgetImageUpdateCard {
      @LocalStorageProp('text') text: ResourceStr = $r('app.string.loading');
      @LocalStorageProp('loaded') loaded: boolean = false;
      @LocalStorageProp('imgName') imgName: ResourceStr = $r('app.string.imgName');
    
      build() {
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
        }
        .width('100%').height('100%')
        .backgroundImage(this.loaded ? 'memory://' + this.imgName : $r('app.media.ImageDisp'))
        .backgroundImageSize(ImageSize.Cover)
      }
    }
    ```

> **说明：**
>
> - Image组件通过入参(memory://fileName)中的(memory://)标识来进行远端内存图片显示，其中fileName需要和EntryFormAbility传递对象('formImages': {key: fd})中的key相对应。
>
> - Image组件通过传入的参数是否有变化来决定是否刷新图片，因此EntryFormAbility每次传递过来的imgName都需要不同，连续传递两个相同的imgName时，图片不会刷新。
>
> - 在卡片上展示的图片，大小需要控制在2MB以内。
