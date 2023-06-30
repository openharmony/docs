# Updating Local and Online Images in the Widget


Typically, a widget includes local images or online images downloaded from the network. To obtain local and online images, use the FormExtensionAbility. The following exemplifies how to show local and online images on a widget.


1. For the widget to download online images, declare the **ohos.permission.INTERNET** permission for the widget. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md).

2. Update local files in the **onAddForm** lifecycle callback of the EntryFormAbility.
   
   ```ts
   import formBindingData from '@ohos.app.form.formBindingData';
   import formProvider from '@ohos.app.form.formProvider';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import request from '@ohos.request';
   import fs from '@ohos.file.fs';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     ...
     // When the widget is added, a local image is opened and transferred to the widget page for display.
     onAddForm(want) {
       // Assume that the local image head.PNG is in the tmp directory of the current widget.
       let tempDir = this.context.getApplicationContext().tempDir;
       // Open the local image and obtain the FD after the image is opened.
       let file;
       try {
         file = fs.openSync(tempDir + '/' + 'head.PNG');
       } catch (e) {
         console.error(`openSync failed: ${JSON.stringify(e)}`);
       }
       let formData = {
         'text': 'Image: Bear',
         'imgName': 'imgBear',
         'formImages': {
           'imgBear': file.fd
         },
         'loaded': true
       }
       // Encapsulate the FD in formData and return it to the widget page.
       return formBindingData.createFormBindingData(formData);
     }
   
     ...
   }
   ```

3. Update online images in the **onFormEvent** lifecycle callback of the EntryFormAbility.
   
   ```ts
   import formBindingData from '@ohos.app.form.formBindingData';
   import formProvider from '@ohos.app.form.formProvider';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import request from '@ohos.request';
   import fs from '@ohos.file.fs';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     // When the message event is triggered on the widget page, an online image is downloaded and transferred to the widget page for display.
     onFormEvent(formId, message) {
       let formInfo = formBindingData.createFormBindingData({
         'text': 'Updating...'
       })
       formProvider.updateForm(formId, formInfo)
       // Note: After being started with the triggering of the lifecycle callback, the FormExtensionAbility can run in the background for only 5 seconds.
       // When possible, limit the size of the image to download. If an image cannot be downloaded within 5 seconds, it will not be updated to the widget page.
       let netFile = 'https://xxxx/xxxx.png'; // Specify the URL of the image to download.
       let tempDir = this.context.getApplicationContext().tempDir;
       let fileName = 'file' + Date.now();
       let tmpFile = tempDir + '/' + fileName;
       request.downloadFile(this.context, {
         url: netFile, filePath: tmpFile, enableMetered: true, enableRoaming: true
       }).then((task) => {
         task.on('complete', function callback() {
           console.info('ArkTSCard download complete:' + tmpFile);
           let file;
           try {
             file = fs.openSync(tmpFile);
           } catch (e) {
             console.error(`openSync failed: ${JSON.stringify(e)}`);
           }
           let fileInfo = {};
           fileInfo[fileName] = file.fd;
           let formData = {
             'text': 'Image:' + fileName,
             'imgName': fileName,
             'formImages': fileInfo,
             'loaded': true
           };
           let formInfo = formBindingData.createFormBindingData(formData)
           formProvider.updateForm(formId, formInfo).then((data) => {
             console.info('FormAbility updateForm success.' + JSON.stringify(data));
           }).catch((error) => {
             console.error('FormAbility updateForm failed: ' + JSON.stringify(error));
           })
         })
         task.on('fail', function callBack(err) {
           console.info('ArkTSCard download task failed. Cause:' + err);
           let formInfo = formBindingData.createFormBindingData({
             'text':'Update failed.'
           })
           formProvider.updateForm(formId, formInfo)
         });
       }).catch((err) => {
         console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
       });
     }
   
     ...
   };
   ```

4. On the widget page, use the **\<Image>** component to display the widget content transferred from the EntryFormAbility.

   ```ts
   let storage = new LocalStorage();
   @Entry(storage)
   @Component
   struct WidgetCard {
     @LocalStorageProp('text') text: string = 'Loading...';
     @LocalStorageProp('loaded') loaded: boolean = false;
     @LocalStorageProp('imgName') imgName: string = 'name';
   
     build() {
       Column() {
         Text(this.text)
           .fontSize('12vp')
           .textAlign(TextAlign.Center)
           .width('100%')
           .height('15%')
   
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
               .margin('5%')
           }
         }.alignItems(VerticalAlign.Center)
         .justifyContent(FlexAlign.Center)
   
         Button ('Update')
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

> **NOTE**
> - The **\<Image>** component displays images in the remote memory based on the **memory://** identifier in the input parameter (**memory://fileName**). The value of **fileName** must be consistent with the key in the object (**'formImages': {key: fd}**) passed by the EntryFormAbility.
> 
> - The **\<Image>** component determines whether to update the image by comparing the values of **imgName** consecutively passed by the EntryFormAbility. It updates the image only when the values are different.
