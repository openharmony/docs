# Updating Local and Online Images in the Widget


Typically, a widget includes local images or online images downloaded from the network. To obtain local and online images, use the FormExtensionAbility. The following exemplifies how to show local and online images on a widget.


1. For the widget to download online images, declare the **ohos.permission.INTERNET** permission for the widget. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Update local files in the **onAddForm** lifecycle callback of the EntryFormAbility.

    ```ts
    import { Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo } from '@kit.CoreFileKit';
    import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    
    const TAG: string = 'WgtImgUpdateEntryFormAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    
    export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
      // When the widget is added, a local image is opened and transferred to the widget page for display.
      onAddForm(want: Want): formBindingData.FormBindingData {
        // Assume that the local image head.PNG is in the tmp directory of the current widget.
        let tempDir = this.context.getApplicationContext().tempDir;
        hilog.info(DOMAIN_NUMBER, TAG, `tempDir: ${tempDir}`);
        let imgMap: Record<string, number> = {};
        try {
          // Open the local image and obtain the FD after the image is opened.
          let file = fileIo.openSync(tempDir + '/' + 'head.PNG');
          imgMap['imgBear'] = file.fd;
        } catch (e) {
          hilog.error(DOMAIN_NUMBER, TAG, `openSync failed: ${JSON.stringify(e as BusinessError)}`);
        }
    
        class FormDataClass {
          text: string = 'Image: Bear';
          loaded: boolean = true;
          // If an image needs to be displayed in the widget, the value of imgName must be the same as the key 'imgBear' in formImages.
          imgName: string = 'imgBear';
          // If an image needs to be displayed in the widget, the formImages field is mandatory (formImages cannot be left blank or renamed), and 'imgBear' corresponds to the FD.
          formImages: Record<string, number> = imgMap;
        }

        let formData = new FormDataClass();
        // Encapsulate the FD in formData and return it to the widget page.
        return formBindingData.createFormBindingData(formData);
      }
      //...
    }
    ```

3. Update online files in the **onFormEvent** lifecycle callback of the EntryFormAbility.

      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { fileIo } from '@kit.CoreFileKit';
      import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
      import { http } from '@kit.NetworkKit';
      import { hilog } from '@kit.PerformanceAnalysisKit';

      const TAG: string = 'WgtImgUpdateEntryFormAbility';
      const DOMAIN_NUMBER: number = 0xFF00;

      export default class WgtImgUpdateEntryFormAbility extends FormExtensionAbility {
        onFormEvent(formId: string, message: string): void {
          let param: Record<string, string> = {
            'text': 'Updating...'
          };
          let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
          formProvider.updateForm(formId, formInfo);

          // Note: After being started with the triggering of the lifecycle callback, the FormExtensionAbility can run in the background for only 5 seconds.
          // When possible, limit the size of the image to download. If an image cannot be downloaded within 5 seconds, it will not be updated to the widget page.
          let netFile = 'https://cn-assets.gitee.com/assets/mini_app-e5eee5a21c552b69ae6bf2cf87406b59.jpg'; // Specify the URL of the image to download.
          let tempDir = this.context.getApplicationContext().tempDir;
          let fileName = 'file' + Date.now();
          let tmpFile = tempDir + '/' + fileName;

          let httpRequest = http.createHttp()
          httpRequest.request(netFile).then((data) => {
            if (data?.responseCode == http.ResponseCode.OK) {
              let imgFile = fileIo.openSync(tmpFile, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
              fileIo.write(imgFile.fd, data.result as ArrayBuffer).then((writeLen: number) => {
                hilog.info(DOMAIN_NUMBER, TAG, "write data to file succeed and size is:" + writeLen);
              }).catch((err: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG, "write data to file failed with error message: " + err.message + ", error code: " + err.code);
              }).finally(() => {
                fileIo.closeSync(imgFile);
              });

              hilog.info(DOMAIN_NUMBER, TAG, 'ArkTSCard download complete: %{public}s', tmpFile);
              let imgMap: Record<string, number> = {};
              try {
                let file = fileIo.openSync(tmpFile);
                imgMap[fileName] = file.fd;
              } catch (e) {
                hilog.error(DOMAIN_NUMBER, TAG, `openSync failed: ${JSON.stringify(e as BusinessError)}`);
              }

              class FormDataClass {
                text: string = 'Image: Bear' + fileName;
                loaded: boolean = true;
                // If an image needs to be displayed in the widget, the value of imgName must be the same as the key fileName in formImages.
                imgName: string = fileName;
                // If an image needs to be displayed in the widget, the formImages field is mandatory (formImages cannot be left blank or renamed), and fileName corresponds to the FD.
                formImages: Record<string, number> = imgMap;
              }

              let formData = new FormDataClass();
              let formInfo = formBindingData.createFormBindingData(formData);
              formProvider.updateForm(formId, formInfo).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'FormAbility updateForm success.');
              }).catch((error: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG, `FormAbility updateForm failed: ${JSON.stringify(error)}`);
              });
            } else {
              hilog.error(DOMAIN_NUMBER, TAG, `ArkTSCard download task failed`);
              let param: Record<string, string> = {
                'text': 'Update failed.'
              };
              let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
              formProvider.updateForm(formId, formInfo);
            }
            httpRequest.destroy();
          })
        }
        //...
      }
      ```

4. On the widget page, use the **backgroundImage** attribute to display the widget content passed from the EntryFormAbility.

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

> **NOTE**
>
> - The **\<Image>** component displays images in the remote memory based on the **memory://** identifier in the input parameter (**memory://fileName**). The value of **fileName** must be consistent with the key in the object (**'formImages': {key: fd}**) passed by the EntryFormAbility.
>
> - The **\<Image>** component determines whether to update the image by comparing the values of **imgName** consecutively passed by the EntryFormAbility. It updates the image only when the values are different.
