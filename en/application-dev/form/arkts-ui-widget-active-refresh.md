# Active Update of ArkTS Widgets
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

This section provides the development guidelines for active update. For details about the update process, see [Active Update](./arkts-ui-widget-interaction-overview.md#active-update).

## Active Update by Widget Provider
The widget provider can call [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) to actively update the widget. It is recommended that this API be used with the widget lifecycle callbacks [onFormEvent](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent), [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform), and [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform).

### How to Develop
The following demonstrates how to add a widget to the home screen and update the widget by tapping the update button on the widget.
1. [Create a widget](./arkts-ui-widget-creation.md).

2. Implement the widget layout, add an update button to the widget, and call the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction-1) API to trigger the **onFormEvent** callback.

   <!-- @[update_by_message_card](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/updatebymessage/pages/UpdateByMessageCard.ets) --> 
    
    ``` TypeScript
    // entry/src/main/ets/updatebymessage/pages/UpdateByMessageCard.ets
    let storageUpdateByMsg = new LocalStorage();
    
    @Entry(storageUpdateByMsg)
    @Component
    struct UpdateByMessageCard {
      // Replace $r('app.string.default_title') and $r('app.string.DescriptionDefault') with the resource files you use.
      @LocalStorageProp('title') title: ResourceStr = $r('app.string.default_title');
      @LocalStorageProp('detail') detail: ResourceStr = $r('app.string.DescriptionDefault');
    
      build() {
        Column() {
          Column() {
            Text(this.title)
              .fontColor('#FFFFFF')
              .opacity(0.9)
              .fontSize(14)
              .margin({ top: '8%', left: '10%' })
            Text(this.detail)
              .fontColor('#FFFFFF')
              .opacity(0.6)
              .fontSize(12)
              .margin({ top: '5%', left: '10%' })
          }.width('100%').height('50%')
          .alignItems(HorizontalAlign.Start)
    
          Row() {
            // ...
            Button() {
              // Replace $r('app.string.update') with the resource file you use.
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
                params: { msgTest: 'messageEvent' }
              });
            })
          }.width('100%').height('40%')
          .justifyContent(FlexAlign.Center)
        }
        .width('100%')
        .height('100%')
        .alignItems(HorizontalAlign.Start)
        // Replace $r('app.media.CardEvent') with the resource file you use.
        .backgroundImage($r('app.media.CardEvent'))
        .backgroundImageSize(ImageSize.Cover)
      }
    }
    ```

3. In the implementation of **onFormEvent**, call the **updateForm** API to update the widget data.

   <!-- @[update_by_message_form_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/entryformability/EntryFormAbility.ts) -->
   
   ``` TypeScript
   // entry/src/main/ets/entryformability/EntryFormAbility.ts
   import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
   import { Configuration, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   
   // entry/src/main/ets/entryformability/EntryFormAbility.ts
   const TAG: string = 'EntryFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want: Want): formBindingData.FormBindingData {
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onAddForm');
       hilog.info(DOMAIN_NUMBER, TAG, want.parameters?.[formInfo.FormParam.NAME_KEY] as string);
       // Called when the widget host creates a widget. The widget provider should return the widget data binding class.
       let obj: Record<string, string> = {
         'title': 'titleOnAddForm',
         'detail': 'detailOnAddForm'
       };
       let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
       return formData;
     }
   
     onCastToNormalForm(formId: string): void {
       // ...
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
     }
   
     onUpdateForm(formId: string): void {
       // If the widget supports interval-based updates, scheduled updates, or active update requests from the widget host, the widget provider needs to override this method to support data updates.
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onUpdateForm');
       let obj: Record<string, string> = {
         'title': 'titleOnUpdateForm',
         'detail': 'detailOnUpdateForm'
       };
       let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
       formProvider.updateForm(formId, formData).catch((error: BusinessError) => {
         hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] updateForm, error:' + JSON.stringify(error));
       });
     }
   
     onChangeFormVisibility(newStatus: Record<string, number>): void {
       // ...
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onChangeFormVisibility');
     }
   
     onFormEvent(formId: string, message: string): void {
       // ...
       hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${message}`);
       class FormDataClass {
         title: string = 'Title Update.'; // It matches the widget layout.
         detail: string = 'Description update success.'; // It matches the widget layout.
       }
   
       // Replace the following with the actual widget data to be updated.
       let formData = new FormDataClass();
       let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
       formProvider.updateForm(formId, formInfo).then(() => {
         hilog.info(DOMAIN_NUMBER, TAG, 'FormAbility updateForm success.');
       }).catch((error: BusinessError) => {
         hilog.error(DOMAIN_NUMBER, TAG, `Operation updateForm failed. Cause: ${JSON.stringify(error)}`);
       });
     }
   
     onRemoveForm(formId: string): void {
       // ...
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
       // ...
     }
   
     onConfigurationUpdate(config: Configuration) {
       // ...
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
     }
   
   
     onAcquireFormState(want: Want): formInfo.FormState {
       // ...
       return formInfo.FormState.READY;
     }
   
   }
   
   ```

4. The resource file is as follows:
   ```ts
   // entry/src/main/resources/zh_CN/element/string.json
   {
      "string": [
      // ...
        {
          "name": "default_title",
          "value": "Title default."
        },
        {
          "name": "DescriptionDefault",
          "value": "Description default."
        },
        {
          "name": "update",
          "value": "Update."
        }
      ]
   }
   ```
### Running Result
![WidgetPrinciple](figures/active-update-result.gif)

## Batch Update By Widget Provider
Starting from API version 22, widget providers can batch update widget content. They can call the [reloadForms](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderreloadforms22) and [reloadAllForms](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderreloadallforms22) APIs in the main process of the application to notify the FormExtension process of batch updates. These APIs can be called only in [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md).

### How to Develop
The following demonstrates how to add multiple widgets of an application to the home screen and update the widgets in batches by tapping the update button within the UIAbility.
1. [Create a widget](./arkts-ui-widget-creation.md).

2. Implement the widget layout and add two **Text** components that can be updated to the widget.

   <!-- @[ReloadByUIAbilityCard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/ReloadFormsDoc/entry/src/main/ets/reloadbyuiability/pages/ReloadByUIAbilityCard.ets) --> 
   
   ``` TypeScript
   // entry/src/main/ets/reloadbyuiability/pages/ReloadByUIAbilityCard.ets
   let storageReloadForm = new LocalStorage();
   
   @Entry(storageReloadForm)
   @Component
   struct ReloadByUIAbilityCard {
     // Create two Text components to be updated. The initial content of the first Text is 'Title default' and that of the second Text is 'Description default'. For details about the resource file definition, see step 5.
     @LocalStorageProp('title') title: ResourceStr = $r('app.string.default_title');
     @LocalStorageProp('detail') detail: ResourceStr = $r('app.string.DescriptionDefault');
   
     build() {
       Column() {
         Column() {
           Text(this.title)
             .fontSize(14)
             .margin({ top: '8%', left: '10%' })
           Text(this.detail)
             .fontSize(12)
             .margin({ top: '5%', left: '10%' })
         }.width('100%').height('50%')
         .alignItems(HorizontalAlign.Start)
       }
       .width('100%')
       .height('100%')
       .alignItems(HorizontalAlign.Start)
     }
   }
   ```

3. Implement the **onUpdateForm** callback in FormExtensionAbility and use the **updateForm** API to define the widget update logic.

   <!-- @[EntryFormAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/ReloadFormsDoc/entry/src/main/ets/entryformability/EntryFormAbility.ets) --> 
   
   ``` TypeScript
   // entry/src/main/ets/entryformability/EntryFormAbility.ets
   import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
   import { Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = 'EntryFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want: Want) {
       const formData = '';
       return formBindingData.createFormBindingData(formData);
     }
   
     onCastToNormalForm(formId: string): void {
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
     }
   
     onUpdateForm(formId: string) {
   
       class FormDataClass {
         title: string = 'Title: ' + Math.random();
         detail: string = 'Description: ' + Math.random();
       }
   
       let formData = new FormDataClass();
       let formInfo: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
       // Update the widget data.
       formProvider.updateForm(formId, formInfo).then(() => {
         hilog.info(DOMAIN_NUMBER, TAG, 'FormAbility updateForm success.');
       }).catch((error: BusinessError) => {
         hilog.error(DOMAIN_NUMBER, TAG, `Operation updateForm failed. code: ${error.code}, message: ${error.message}`);
       });
     }
   
     onFormEvent(formId: string, message: string) {
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
     }
   
     onRemoveForm(formId: string) {
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
     }
   
     onAcquireFormState(want: Want) {
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onAcquireFormState');
       return formInfo.FormState.READY;
     }
   }
   ```

4. Add two batch update buttons to the UIAbility. After the buttons are tapped, the **reloadForms** or **reloadAllForms** API is called to trigger the **onUpdateForm** callback for batch updates.

   <!-- @[index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/ReloadFormsDoc/entry/src/main/ets/pages/Index.ets) --> 
   
   ``` TypeScript
   // entry/src/main/ets/pages/index.ets
   import { common } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { formProvider } from '@kit.FormKit';
   
   @Entry
   @Component
   struct Index {
     build() {
       Column({ space: 20 }) {
         Button('reloadForms')
           .onClick(() => {
             try {
               let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
               let moduleName: string = 'entry';
               let abilityName: string = 'EntryFormAbility';
               let formName: string = 'ReloadByUIAbility';
               formProvider.reloadForms(context, moduleName, abilityName, formName).then((reloadNum: number) => {
                 console.info(`reloadForms success, reload number: ${reloadNum}`);
               }).catch((error: BusinessError) => {
                 console.error(`promise error, code: ${error.code}, message: ${error.message}`);
               });
             } catch (error) {
               console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
             }
           })
         Button('reloadAllForms')
           .onClick(() => {
             try {
               let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
               formProvider.reloadAllForms(context).then((reloadNum: number) => {
                 console.info(`reloadAllForms success, reload number: ${reloadNum}`);
               }).catch((error: BusinessError) => {
                 console.error(`promise error, code: ${error.code}, message: ${error.message})`);
               });
             } catch (error) {
               console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
             }
           })
       }
       .height('100%')
       .width('100%')
       .justifyContent(FlexAlign.Center)
     }
   }
   ```

5. The resource file is as follows:

   ```json5
   // entry/src/main/resources/base/element/string.json
   {
      "string": [
      // ...
        {
          "name": "default_title",
          "value": "Title default."
        },
        {
          "name": "DescriptionDefault",
          "value": "Description default."
        }
      ]
   }
   ```

### Running Result
![WidgetPrinciple](figures/batch-update-result.gif)

<!--Del-->
## Active Update by Widget Host (for System Applications Only)

Due to the time limit of interval-based and time-specific updates, the widget host can call [requestForm](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md#requestform) to request the Widget Manager to actively update the widget. The Widget Manager calls the [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) lifecycle callback in the FormExtensionAbility of the widget provider. In the callback, the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API can be called to update the widget content.

   <!-- @[FormUpdate_page](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormUpdateDemo/entry/src/main/ets/pages/Index.ets) --> 
   
   ``` TypeScript
   import { formHost } from '@kit.FormKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = 'EntryFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   let storage = new LocalStorage();
   
   @Entry(storage)
   @Component
   struct Index {
     @State formId: string = '0';
   
     build() {
       Column() {
         Column() {
           FormComponent({
             id: 0,
             name: 'widget',
             bundle: 'com.samples.formupdatedemo', // Replace it with the actual bundle name.
             ability: 'EntryFormAbility',
             module: 'entry',
             dimension: 2,
             temporary: false,
           })
             .size({
               width: 200,
               height: 200,
             })
             .borderColor(Color.Black)
             .borderRadius(10)
             .borderWidth(1)
             .onAcquired((form: FormCallbackInfo) => {
               hilog.info(DOMAIN_NUMBER, TAG, `onAcquired: ${form.id}`)
               this.formId = form.id.toString();
             })
             .onRouter(() => {
               hilog.info(DOMAIN_NUMBER, TAG, `onRouter`)
             })
             .onError((error) => {
               hilog.error(DOMAIN_NUMBER, TAG, `onError: code: ${error?.errcode}, message: ${error?.msg}`)
             })
           // ...
           Button($r('app.string.button_update'))
             .onClick(() => {
               hilog.info(DOMAIN_NUMBER, TAG, `click to check requestForm, formId: ${this.formId}`);
               // formId is the ID of the widget to be updated.
               if (this.formId != null) {
                 formHost.requestForm(this.formId).then(() => {
                   hilog.info(DOMAIN_NUMBER, TAG, 'EntryFormAbility requestForm success.');
                 }).catch((error: BusinessError) => {
                   hilog.error(DOMAIN_NUMBER, TAG,
                     `EntryFormAbility requestForm fail, code: ${error?.code}, message: ${error?.message}`);
                   hilog.error(DOMAIN_NUMBER, TAG, `EntryFormAbility requestForm fail, code: ${this.formId}`);
                 })
               }
             })
             .margin(5)
             .width('50%')
         }
         .width('100%')
         .height('100%')
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

<!--DelEnd-->
