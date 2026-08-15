# Editing ArkTS Widgets

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=7eb91d6df8b4aeed3953bbb4aaef8a6f065801e4 translatedAt=2026-08-15T01:50:43.919Z pushedAt=2026-08-15T08:15:20.716Z -->

ArkTS widgets provide widget page editing capabilities, allowing users to customize widget content, for example, editing a contact widget, modifying the contacts displayed in a widget, and editing a weather widget.

Widget page editing is available in two modes: half-modal widget editing and full-screen widget editing. Starting from API version 18, half-modal widget editing is supported.

## Semi-Modal Widget Editing

The following example describes how to use semi-modal widget editing.

### Implementation Principle

![WidgetProject](figures/semi-modal-edit-page-process.png)

1. Long press on the widget to bring up the menu. At this point, the home screen determines whether to display the **Edit** button based on whether the widget supports the widget editing capability, which is indicated by the [formConfigAbility](./arkts-ui-widget-configuration.md#fields-in-configuration-file) field.

2. Tap the **Edit** menu item. The home screen uses the fields in `formConfigAbility` to launch the corresponding page and enter the first-level editing page. The first-level editing page has a limited editing area and is intended for relatively simple editing layouts.

    - Preview area: The gray area is the preview area, which shows the effect after widget editing. The layout of the preview area is determined by the home screen.

    - Editing area: The white area is the editing area, which is a custom layout area of the app and is used to implement the widget editing layout. The layout of the widget editing area is drawn by the app after inheriting [FormEditExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md), and can be used for simple editing layouts.

    - FormEditDemo: This field is the app name of the widget host app, configured through the `label` field in the [app.json5](../quick-start/app-configuration-file.md#configuration-file-tags) configuration file.

    - widget: This field is the widget name, configured through the [name](./arkts-ui-widget-configuration.md#fields-in-configuration-file) field in the widget `form_config.json` configuration file.

    - **Done** button: After editing is complete, tap the button to exit the half-modal widget editing page.

3. In the widget editing area, after you tap the **Switch to: Shanghai** button, the widget provider can update the widget information through the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API, and the update is displayed in the preview area.

4. In the widget editing area, tap the **Enter Secondary Editing Page** button. The widget then passes the widget provider's secondary editing page information to the home screen through the [startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage) method provided by FormEditExtensionContext. The home screen launches the corresponding page, that is, the secondary editing page. The secondary editing page is mainly used to implement complex editing layouts. Add a secondary editing page based on your actual requirements.

5. Exit the editing page after editing is complete.

### How to Develop

1. [Create a widget](./arkts-ui-widget-creation.md).

2. Create the EntryFormEditAbility file to implement the semi-modal editing component of [FormEditExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md), and configure the [formConfigAbility](./arkts-ui-widget-configuration.md#fields-in-configuration-file) field in the form_config.json file.

   - Implementation of the Ability for the semi-modal primary editing page.

   <!-- @[FormEditDemo_EntryFormEditAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/entryformeditability/EntryFormEditAbility.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/entryformeditability/EntryFormEditAbility.ets
   import { FormEditExtensionAbility } from '@kit.FormKit';
   import { UIExtensionContentSession, Want } from '@kit.AbilityKit';
   import { ExtensionEvent } from '../model/ExtensionEvent';
   
   const TAG: string = 'FormEditDemo[EntryFormEditAbility] -->';
   let storage: LocalStorage = ExtensionEvent.getStorage();
   
   export default class EntryFormEditAbility extends FormEditExtensionAbility {
     onCreate() {
       console.info(`${TAG} onCreate`);
     }
   
     onForeground(): void {
       console.info(`${TAG} EntryFormEditAbility onForeground.....`);
     }
   
     onBackground(): void {
       console.info(`${TAG} EntryFormEditAbility onBackground......`);
     }
   
     onDestroy(): void {
       console.info(`${TAG} EntryFormEditAbility onDestroy......`);
     }
   
     onSessionCreate(want: Want, session: UIExtensionContentSession) {
       // Obtain the widget ID of the widget being edited and the widget ID of the preview widget, and synchronize them to the first-level editing page through storage.
       const formId: string | undefined = want.parameters?.cardId as string;
       const previewFormId: string | undefined = want.parameters?.previewCardId as string;
   
       if (formId) {
         console.info(`${TAG} form id is ${formId}`);
         storage.setOrCreate('formId', formId);
       }
       if (previewFormId) {
         console.info(`${TAG} preview form id is ${previewFormId}`);
         storage.setOrCreate('previewFormId', previewFormId);
       }
       let extensionEvent: ExtensionEvent = new ExtensionEvent();
       extensionEvent.setStartSecondPage((): void => this.startSecondPage());
       storage.setOrCreate('extensionEvent', extensionEvent);
       storage.setOrCreate('context', this.context);
       try {
         // Load the first-level editing page.
         session.loadContent('pages/FormEditExtension', storage);
       } catch (e) {
         console.error(`${TAG} EntryFormEditAbility loadContent err, Code: ${e.code}, Message: ${e.message}`);
       }
     }
   
     onSessionDestroy(session: UIExtensionContentSession) {
       console.info(`${TAG} onSessionDestroy`);
     }
   
     private startSecondPage() {
       const bundleName: string = this.context.extensionAbilityInfo.bundleName;
       const secPageAbilityName: string = 'FormEditSecPageAbility';
       console.info(`${TAG} startSecondPage. bundleName: ${bundleName}, secPageAbilityName: ${secPageAbilityName}.`);
       try {
         // Load the second-level editing page.
         this.context.startSecondPage({
           bundleName: bundleName,
           parameters: {
             'secPageAbilityName': secPageAbilityName
           }
         });
         console.info(`${TAG} startSecondPage success!`);
       } catch (err) {
         console.error(`${TAG} startSecondPage failed, Code: ${err.code}, Message: ${err.message}`);
       }
     }
   };
   ```

   - Implementation of the semi-modal second-level editing page Ability.

   <!-- @[FormEditDemo_FormEditSecPageAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/entryformeditability/FormEditSecPageAbility.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/entryformeditability/FormEditSecPageAbility.ets
   import { FormEditExtensionAbility } from '@kit.FormKit';
   import { UIExtensionContentSession, Want } from '@kit.AbilityKit';
   import { ExtensionEvent } from '../model/ExtensionEvent';
   
   const TAG = 'FormEditExtensionAbility';
   
   export default class FormEditSecPageAbility extends FormEditExtensionAbility {
     public storage: LocalStorage = new LocalStorage();
   
     onCreate() {
       console.info(TAG, `Ability onCreate`);
     }
   
     onForeground(): void {
       console.info(TAG, `Ability onForeground`);
     }
   
     onBackground(): void {
       console.info(TAG, `Ability onBackground`);
     }
   
     onDestroy(): void {
       console.info(TAG, `Ability onDestroy`);
     }
   
     onSessionCreate(want: Want, session: UIExtensionContentSession) {
       let extensionEvent: ExtensionEvent = new ExtensionEvent();
       this.storage.setOrCreate('extensionEvent', extensionEvent);
       this.storage.setOrCreate('session', session);
   
       try {
         session.loadContent('pages/FormEditSecPage', this.storage);
         console.info(TAG, `loadContent first edit page success`);
       } catch (e) {
         console.error(TAG, `EntryFormEditAbility loadContent err, want: ${e?.message}`);
       }
     }
   
     onSessionDestroy(session: UIExtensionContentSession) {
       console.info(TAG, `onSessionDestroy`);
     }
   }
   ```

   - The newly added EntryFormEditAbility must be configured in module.json5 as follows.

   ```json5
   // entry/src/main/module.json5
   {
       "module": {
           // ...
           "extensionAbilities": [
               {
                   // First-level editing page
                   "name": "EntryFormEditAbility",
                   "srcEntry": "./ets/entryformeditability/EntryFormEditAbility.ets",
                   "type": "formEdit"
               },
               {
                   // Second-level editing page
                   "name": "FormEditSecPageAbility",
                   "srcEntry": "./ets/entryformeditability/FormEditSecPageAbility.ets",
                   "type": "formEdit"
               }
           ]
       }
   }
   ```

   - Implement the widget `form_config.json` file.

   ```json5
   // entry/src/main/resources/base/profile/form_config.json
   {
       "forms": [
           {
               "name": "widget",
               "displayName": "$string:widget_display_name",
               "description": "$string:widget_desc",
               "src": "./ets/widget/pages/WidgetCard.ets",
               "uiSyntax": "arkts",
               "formConfigAbility": "ability://EntryFormEditAbility",
               "isDynamic": true,
               "isDefault": true,
               "updateEnabled": false,
               "scheduledUpdateTime": "10:30",
               "multiScheduledUpdateTime": "11:30,16:30",
               "updateDuration": 1,
               "defaultDimension": "1*2",
               "supportDimensions": [
                   "1*2",
                   "2*2",
                   "2*4",
                   "4*4",
                   "6*4"
               ]
           }
       ]
   }
   ```

3. Implement the first-level editing page layout. Use the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API to refresh the information of the widget being edited and the preview widget information, and use the [startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage) method to launch the second-level editing page.

   - The first-level editing page layout is implemented as follows.

   <!-- @[FormEditDemo_FormEditExtension](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/pages/FormEditExtension.ets) -->

   ``` TypeScript
   // entry/src/main/ets/pages/FormEditExtension.ets
   import { common, UIExtensionContentSession } from '@kit.AbilityKit';
   import { preferences } from '@kit.ArkData';
   import { formBindingData, formProvider } from '@kit.FormKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { ExtensionEvent } from '../model/ExtensionEvent';
   import { PreferencesUtil } from '../common/PreferencesUtil';
   import { FormData } from '../common/CommonData';
   
   const TAG: string = 'FormEditDemo[Extension] -->';
   let storage: LocalStorage = ExtensionEvent.getStorage();
   
   @Entry(storage)
   @Component
   struct FormEditExtension {
     @State message1: string = 'Beijing';
     @State message2: string = 'Shanghai';
     private formId: string = storage.get('formId') as string;
     private previewFormId: string = storage.get('previewFormId') as string;
     private session: UIExtensionContentSession =
       storage.get<UIExtensionContentSession>('session') as UIExtensionContentSession;
     private extensionEvent: ExtensionEvent = storage.get<ExtensionEvent>('extensionEvent') as ExtensionEvent;
     // Before API version 22, import LiveFormExtensionContext from 'application/LiveFormExtensionContext';
     // Import LiveFormExtensionContext. This import method is marked in red in DevEco Studio, but it does not affect compilation or running.
     // You can use LiveFormExtensionContext directly. In API version 22 and later, import { common } from '@kit.AbilityKit';
     // Import LiveFormExtensionContext and use it as common.LiveFormExtensionContext.
     private context: common.FormEditExtensionContext | undefined =
       storage.get<common.FormEditExtensionContext>('context');
   
     updateForm(message: string) {
       if (!this.formId && !this.previewFormId) {
         return;
       }
       if (this.context) {
         let util = PreferencesUtil.getInstance();
         let preferences = util.getPreferences(this.context) as preferences.Preferences;
         util.preferencesPut(preferences, this.formId, new FormData(this.formId, message));
       }
       let param: Record<string, string> = {
         'message': message
       }
       let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
       try {
         // Refresh the information of the widget being edited.
         formProvider.updateForm(this.formId, obj, (error: BusinessError) => {
           if (error) {
             console.error(TAG, `callback error, code: ${error.code}, message: ${error.message})`);
             return;
           }
           console.info(TAG, `formProvider updateForm success`);
         });
       } catch (error) {
         console.error(TAG, `catch error, Code: ${error.code}, Message: ${error.message}`);
       }
       if (!this.previewFormId) {
         console.error(TAG, 'previewFormId is empty');
         return;
       }
       try {
         // Refresh the information of the preview widget.
         formProvider.updateForm(this.previewFormId, obj, (error: BusinessError) => {
           if (error) {
             console.error(TAG, `callback error, code: ${error.code}, message: ${error.message})`);
             return;
           }
           console.info(TAG, `formProvider updateForm success`);
         });
       } catch (error) {
         console.error(TAG, `catch error, Code: ${error.code}, Message: ${error.message}`);
       }
     }
   
     onPageShow() {
       console.info(`${TAG} onPageShow. extensionEvent`);
     }
   
     build() {
       Row() {
         Column() {
           Button($r('app.string.button_one'))
             .width('80%')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .onClick(() => {
               console.info(`${TAG} Button1 onClick ${storage.get('message')}`);
               this.updateForm(this.message1);
               storage.setOrCreate('message', this.message1);
             })
           Button($r('app.string.button_two'))
             .width('80%')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .onClick(() => {
               console.info(`${TAG} Button2 onClick`);
               this.updateForm(this.message2);
               storage.setOrCreate('message', this.message2);
             })
           Button($r('app.string.button_three'))
             .width('80%')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .onClick(async () => {
               console.info(`${TAG} Button onClick`);
               // Launch the second-level editing page.
               this.extensionEvent?.startFormEditSecondPage();
             })
         }
       }
       .justifyContent(FlexAlign.Center)
       .width('100%')
     }
   }
   ```

   - Add the FormEditSecPage.ets file to implement the second-level editing page layout.

   <!-- @[FormEditDemo_FormEditSecPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/pages/FormEditSecPage.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/pages/FormEditSecPage.ets
   @Entry
   @Component
   struct FormEditSecPage {
     @State message: string | ResourceStr = $r('app.string.button_three');
   
     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize($r('app.float.page_text_font_size'))
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(() => {
             this.message = 'Welcome';
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

   - Load the layout file.

       ```json5
       // entry/src/main/resources/base/profile/main_pages.json
       {
           "src": [
               "pages/Index",
               "pages/FormEditExtension",
               "pages/FormEditSecPage"
           ]
       } 
       ```

   - Create an ExtensionEvent file to encapsulate the [startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage) method into `startFormEditSecondPage` for business use.

   <!-- @[FormEditDemo_ExtensionEvent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/model/ExtensionEvent.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/model/ExtensionEvent.ets
   const TAG: string = 'FormEditDemo[ExtensionEvent] -->';
   const LOCAL: Record<string, string> = { 'formId': '', 'previewFormId': '', 'message': '' };
   
   export class ExtensionEvent {
     private static storage = new LocalStorage(LOCAL);
   
     public static getStorage(): LocalStorage {
       return ExtensionEvent.storage;
     }
   
     public setStartSecondPage(startSecondPage: () => void) {
       console.info(`${TAG} setStartSecondPage`);
       this.startSecondPage = startSecondPage;
     }
   
     public async startFormEditSecondPage() {
       console.info(`${TAG} startFormEditSecondPage call`);
       this.startSecondPage();
     }
   
     private startSecondPage: () => void = (): void => {
       console.info(`${TAG} startSecondPage is empty!`);
     };
   }
   ```

4. Persist widget information. Each time you enter the widget editing page, the preview widget must stay consistent with the widget being edited, so the widget information needs to be persisted.

   - Create a PreferencesUtil file to encapsulate the [Preferences](../database/data-persistence-by-preferences.md) preferences for persistent data use by the business.

   <!-- @[FormEditDemo_PreferencesUtil](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/common/PreferencesUtil.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/common/PreferencesUtil.ets
   import { preferences } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { FormData } from './CommonData';
   
   const TAG: string = 'PreferencesUtil';
   const MY_STORE: string = 'myStore';
   
   export class PreferencesUtil {
     private static preferencesUtil: PreferencesUtil;
   
     public static getInstance(): PreferencesUtil {
       if (!PreferencesUtil.preferencesUtil) {
         PreferencesUtil.preferencesUtil = new PreferencesUtil();
       }
       return PreferencesUtil.preferencesUtil;
     }
   
     getPreferences(context: Context): preferences.Preferences | undefined {
       try {
         preferences.removePreferencesFromCacheSync(context, MY_STORE);
         return preferences.getPreferencesSync(context, { name: MY_STORE });
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `getPreferences failed, error code=${err.code}, message=${err.message}`);
         return undefined;
       }
     }
   
     preferencesFlush(preferences: preferences.Preferences) {
       preferences.flush((err) => {
         if (err) {
           console.error(TAG, `Failed to flush. Code:${err.code}, message:${err.message}`);
         }
       })
     }
   
     preferencesPut(preferences: preferences.Preferences, formID: string, value: FormData): void {
       try {
         preferences.putSync(formID, value);
         this.preferencesFlush(preferences);
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `preferencesPut failed, error code=${err.code}, message=${err.message}`);
       }
     }
   
     removePreferencesFromCache(context: Context): void {
       preferences.removePreferencesFromCache(context, MY_STORE).catch((err: BusinessError) => {
         console.error(TAG, `removePreferencesFromCache failed, error code=${err.code}, message=${err.message}`);
       });
     }
   
     getValue(preferences: preferences.Preferences, formID: string): FormData | undefined {
       if (preferences === null) {
         console.error(TAG, `preferences is null`);
         return undefined;
       }
       try {
         return preferences.getSync(formID, new FormData('')) as FormData;
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `getSync failed, error code=${err.code}, message=${err.message}`);
         return undefined;
       }
     }
   
     removeFormId(context: Context, formId: string) {
       try {
         let preferences = this.getPreferences(context);
         if (!preferences) {
           console.error(TAG, `preferences is null`);
           return;
         }
         if (preferences.hasSync(formId)) {
           preferences.deleteSync(formId);
           this.preferencesFlush(preferences);
         }
       } catch (error) {
         console.error(TAG, `Failed to get preferences. Code:${error.code}, message:${error.message}`);
       }
     }
   }
   ```

   - To keep the preview widget and the widget being edited synchronized, when creating a widget, check in the `onAddForm` callback whether the `ohos.extra.param.key.edit_form_id` field carries a widget ID. If it does, the widget is a preview widget, and the information of the widget being edited must be obtained from the database.

   <!-- @[FormEditDemo_EntryFormAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/entryformability/EntryFormAbility.ets) -->

   ``` TypeScript
   // entry/src/main/ets/entryformability/WidgetCard.ets
   import { formBindingData, FormExtensionAbility, formInfo } from '@kit.FormKit';
   import { Want } from '@kit.AbilityKit';
   import { PreferencesUtil } from '../common/PreferencesUtil';
   import { FormData } from '../common/CommonData';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want: Want) {
       let editFormId: string = '';
       let formId: string = '';
       // Initialize the preferences database.
       let util = PreferencesUtil.getInstance();
       let preferences = util.getPreferences(this.context);
       if (want.parameters) {
         formId = want.parameters[formInfo.FormParam.IDENTITY_KEY] as string;
         editFormId = want.parameters['ohos.extra.param.key.edit_form_id'] as string;
       }
       // If the widget is a preview widget on the editing page, update the edited widget information to the preview widget when it is created.
       if (editFormId && preferences) {
         let formData: FormData = util.getValue(preferences, editFormId) as FormData;
         return formBindingData.createFormBindingData({
           'message': formData.text
         });
       }
   
       return formBindingData.createFormBindingData('');
     }
   
     onCastToNormalForm(formId: string) {
     }
   
     onUpdateForm(formId: string) {
     }
   
     onFormEvent(formId: string, message: string) {
     }
   
     onRemoveForm(formId: string) {
     }
   
     onAcquireFormState(want: Want) {
       return formInfo.FormState.READY;
     }
   }
   ```

   - The widget layout file is as follows.

   <!-- @[FormEditDemo_WidgetCard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/widget/pages/WidgetCard.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/widget/pages/WidgetCard.ets
   let storage: LocalStorage = new LocalStorage();
   
   @Entry(storage)
   @Component
   struct WidgetCard {
     @LocalStorageProp('message') title: string = 'Hello World';
     readonly actionType: string = 'router';
     readonly abilityName: string = 'EntryAbility';
     readonly message: string = 'add detail';
     readonly fullWidthPercent: string = '100%';
     readonly fullHeightPercent: string = '100%';
   
     build() {
       Row() {
         Column() {
           Text(this.title)
             .fontSize($r('app.float.font_size'))
             .fontWeight(FontWeight.Medium)
             .fontColor($r('sys.color.font'))
         }
         .width(this.fullWidthPercent)
       }
       .height(this.fullHeightPercent)
       .backgroundColor($r('sys.color.comp_background_primary'))
       .onClick(() => {
         postCardAction(this, {
           action: this.actionType,
           abilityName: this.abilityName,
           params: {
             message: this.message
           }
         });
       })
     }
   }
   ```

   - Add the CommonData.ets file to define the widget data structure.

   <!-- @[FormEditDemo_CommonData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditDemo/entry/src/main/ets/common/CommonData.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/common/CommonData.ets
   export class FormData {
     public formId: string = '';
     public text: string = 'Hello World';
   
     constructor(formId: string, text?: string) {
       this.formId = formId;
       this.text = text ? text : 'Hello World';
     }
   }
   ```

5. The resource file is as follows.

   ```json5
   // entry/src/main/resources/base/element/string.json
   {
      "string": [
         // ...
         {
            "name": "button_one",
            "value": "Switch to: Beijing"
         },
         {
            "name": "button_two",
            "value": "Switch to: Shanghai"
         },
         {
            "name": "button_three",
            "value": "Enter the editing secondary page"
         }
      ]
    }
    ```

<!--Del-->6. The running effect is as follows:<br>

![WidgetProject] (figures/half-modal-running-result.gif)<!--DelEnd-->

## Full-Screen Widget Editing

### Implementation Principle

![WidgetProject](figures/full-screen-edit-page-process.png)

1. Long press on the widget to display a menu. The home screen determines whether to display the **Edit** button based on the [formConfigAbility](./arkts-ui-widget-configuration.md#fields-in-configuration-file) field, which indicates whether the widget supports the widget editing capability.

2. Tap the **Edit** menu item to enter the full-screen editing page. The home screen launches the widget editing page based on the information in the `formConfigAbility` field.

3. Tap the **Switch to: Shanghai** button to edit the widget content. The provider updates the information of the widget being edited through the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) API.

### How to Develop

The following example implements the following functions: long press on a widget to display the editing menu, tap the **Edit** menu item to enter the full-screen editing page, and modify the widget content.

1. [Create a widget](./arkts-ui-widget-creation.md).

2. Create an `EntryEditAbility.ets` file that inherits from the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component and implements the [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate) and [onNewWant](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onnewwant) callback functions. The widget user passes the ID of the widget being edited through the `parameters` field of [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md). In addition, configure the [formConfigAbility](./arkts-ui-widget-configuration.md#fields-in-configuration-file) field in the `form_config.json` file.

   - Implement the Ability for the editing page.

   <!-- @[FormEditUIAbility_EntryEditAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditUIAbility/entry/src/main/ets/entryability/EntryEditAbility.ets) -->

   ``` TypeScript
   // entry/src/main/ets/entryability/EntryEditAbility.ets
   import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { window } from '@kit.ArkUI';
   import { PreferencesUtil } from '../common/PreferencesUtil';
   import { preferences } from '@kit.ArkData';
   
   const DOMAIN: number = 0x0000;
   
   export default class EntryEditAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       const formId: string = want.parameters?.formId as string;
       hilog.info(DOMAIN, 'testTag', 'onCreate form id is' + formId)
       if (formId) {
         // Store the ID of the widget being edited for later use.
         let util = PreferencesUtil.getInstance();
         let preferences = util.getPreferences(this.context) as preferences.Preferences;
         util.preferencesPut(preferences, formId);
       }
       try {
         this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
       } catch (err) {
         hilog.error(DOMAIN, 'testTag', 'Failed to set colorMode. Code:${err.code}, message:${err.message}');
       }
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
     }
   
     onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // Refresh the ID of the widget being edited when the editing page is hot-started.
       const formId: string = want.parameters?.formId as string;
       hilog.info(DOMAIN, 'testTag', 'onNewWant form id is' + formId)
       if (formId) {
         // Initialize the preferences database.
         let util = PreferencesUtil.getInstance();
         let preferences = util.getPreferences(this.context) as preferences.Preferences;
         util.preferencesPut(preferences, formId);
       }
     }
   
     onDestroy(): void {
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
     }
   
     onWindowStageCreate(windowStage: window.WindowStage): void {
       // Main window is created, set main page for this ability
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
   
       windowStage.loadContent('pages/FormEditIndex', (err) => {
         if (err.code) {
           hilog.error(DOMAIN, 'testTag', `Failed to load the content. Code:${err.code}, message:${err.message}`);
           return;
         }
         hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
       });
       AppStorage.setOrCreate('windowStage', this.context);
     }
   
     onWindowStageDestroy(): void {
       // Main window is destroyed, release UI related resources
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
     }
   
     onForeground(): void {
       // Ability has brought to foreground
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
     }
   
     onBackground(): void {
       // Ability has back to background
       hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
     }
   }
   ```

   - Configure the newly added EntryEditAbility in module.json5 as follows.

   <!-- @[FormEditUIAbility_modulejson5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditUIAbility/entry/src/main/module.json5) --> 

   ``` JSON5
   "abilities": [
     // ...
     {
       "name": "FormEditAbility",
       "srcEntry": "./ets/entryability/EntryEditAbility.ets",
       "description": "$string:EntryAbility_desc",
       "icon": "$media:layered_image",
       "label": "$string:EntryAbility_label",
       "startWindowIcon": "$media:startIcon",
       "startWindowBackground": "$color:start_window_background",
       "exported": true,
     }
   ],
   ```

   - Implement the widget form_config.json file.

   ```json5
   // entry/src/main/resources/base/profile/form_config.json
   {
     "forms": [
       {
         "name": "widget",
         "displayName": "$string:widget_display_name",
         "description": "$string:widget_desc",
         "src": "./ets/widget/pages/WidgetCard.ets",
         "uiSyntax": "arkts",
         "isDynamic": true,
         "isDefault": true,
         "updateEnabled": false,
         "formConfigAbility": "ability://FormEditAbility",
         "scheduledUpdateTime": "10:30",
         "updateDuration": 1,
         "defaultDimension": "2*2",
         "supportDimensions": [
           "2*2"
         ]
       }
     ]
   }
   ```

3. Add the FormEditIndex.ets file to implement the full-screen editing page layout, and call [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) to refresh the information of the widget being edited.

   <!-- @[FormEditUIAbility_FormEditIndex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditUIAbility/entry/src/main/ets/pages/FormEditIndex.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/pages/FormEditIndex.ets
   import { formBindingData, formProvider } from '@kit.FormKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { PreferencesUtil } from '../common/PreferencesUtil';
   import { preferences } from '@kit.ArkData';
   
   const TAG: string = 'FormEdit -->';
   
   @Entry
   @Component
   struct FormEditIndex {
     @State message: string = 'Hello World';
     @State message1: string = 'Beijing';
     @State message2: string = 'Shanghai';
   
     updateForm(message: string) {
       // Obtain the ID of the widget being edited from the database.
       let util = PreferencesUtil.getInstance();
       let preferences = util.getPreferences(this.getUIContext().getHostContext() as Context) as preferences.Preferences;
       let formId: string = util.getValue(preferences) as string;
       if (!formId) {
         return;
       }
       console.info(TAG, `doy: formId: ${formId}, message: ${message}`)
       let param: Record<string, string> = {
         'message': message
       }
       let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
       try {
         formProvider.updateForm(formId, obj, (error: BusinessError) => {
           if (error) {
             console.error(TAG, `callback error, code: ${error.code}, message: ${error.message})`);
             return;
           }
           console.info(TAG, `formProvider updateForm success`);
         });
       } catch (error) {
         console.error(TAG, `catch error, Code:${error.code}, message:${error.message}`);
       }
     }
   
     build() {
       Row() {
         Column() {
           Button($r('app.string.button_one'))
             .width('80%')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .onClick(() => {
               this.updateForm(this.message1);
             })
           Button($r('app.string.button_two'))
             .width('80%')
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .onClick(() => {
               this.updateForm(this.message2);
             })
         }
       }
       .justifyContent(FlexAlign.Center)
       .width('100%')
     }
   }
   ```

   - Load the full-screen editing page layout file.

   ```json5
   // entry/src/main/resources/base/profile/main_pages.json
   {
     "src": [
       "pages/Index",
       "pages/FormEditIndex"
     ]
   }
   ```

   - The widget layout file is as follows.

   <!-- @[FormEditUIAbility_WidgetCard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditUIAbility/entry/src/main/ets/widget/pages/WidgetCard.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/widget/pages/WidgetCard.ets
   @Entry
   @Component
   struct WidgetCard {
     @LocalStorageProp('message') title: string = 'Hello World';
     readonly actionType: string = 'router';
     readonly abilityName: string = 'EntryAbility';
     readonly message: string = 'add detail';
     readonly fullWidthPercent: string = '100%';
     readonly fullHeightPercent: string = '100%';
   
     build() {
       Row() {
         Column() {
           Text(this.title)
             .fontSize($r('app.float.font_size'))
             .fontWeight(FontWeight.Medium)
             .fontColor($r('sys.color.font'))
         }
         .width(this.fullWidthPercent)
       }
       .height(this.fullHeightPercent)
       .backgroundColor($r('sys.color.comp_background_primary'))
       .onClick(() => {
         postCardAction(this, {
           action: this.actionType,
           abilityName: this.abilityName,
           params: {
             message: this.message
           }
         });
       })
     }
   }
   ```

4. Add the PreferencesUtil file, which mainly encapsulates [Preferences](../database/data-persistence-by-preferences.md) for persistent data storage in services.

   <!-- @[FormEditUIAbility_PreferencesUtil](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormEditUIAbility/entry/src/main/ets/common/PreferencesUtil.ets) --> 

   ``` TypeScript
   // entry/src/main/ets/common/PreferencesUtil.ets
   import { preferences } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   const TAG: string = 'PreferencesUtil';
   const MY_STORE: string = 'myStore';
   const key: string = 'formID';
   
   export class PreferencesUtil {
     private static preferencesUtil: PreferencesUtil;
   
     public static getInstance(): PreferencesUtil {
       if (!PreferencesUtil.preferencesUtil) {
         PreferencesUtil.preferencesUtil = new PreferencesUtil();
       }
       return PreferencesUtil.preferencesUtil;
     }
   
     getPreferences(context: Context): preferences.Preferences | undefined {
       try {
         preferences.removePreferencesFromCacheSync(context, MY_STORE);
         return preferences.getPreferencesSync(context, { name: MY_STORE });
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `getPreferences failed, error code=${err.code}, message=${err.message}`);
         return undefined;
       }
     }
   
     preferencesFlush(preferences: preferences.Preferences) {
       preferences.flushSync();
     }
   
     preferencesPut(preferences: preferences.Preferences, formID: string): void {
       try {
         preferences.putSync(key, formID);
         preferences.flushSync();
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `preferencesPut failed, error code=${err.code}, message=${err.message}`);
       }
     }
   
     removePreferencesFromCache(context: Context): void {
       preferences.removePreferencesFromCache(context, MY_STORE).catch((err: BusinessError) => {
         console.error(TAG, `removePreferencesFromCache failed, error code=${err.code}, message=${err.message}`);
       });
     }
   
     getValue(preferences: preferences.Preferences): string | undefined {
       if (preferences === null) {
         console.error(TAG, `preferences is null`);
         return undefined;
       }
       try {
         return preferences.getSync(key, '') as string
       } catch (error) {
         let err = error as BusinessError;
         console.error(TAG, `getSync failed, error code=${err.code}, message=${err.message}`);
         return undefined;
       }
     }
   
     removeFormId(context: Context) {
       try {
         let preferences = this.getPreferences(context);
         if (!preferences) {
           console.error(TAG, `preferences is null`);
           return;
         }
         if (preferences.hasSync(key)) {
           preferences.deleteSync(key);
           preferences.flushSync();
           console.info(TAG, `deleteSync done.`)
         }
       } catch (error) {
         console.error(TAG, `Failed to get preferences. Code:${error.code}, message:${error.message}`);
       }
     }
   }
   ```

5. The resource file is as follows.

   ```json5
   // entry/src/main/resources/base/element/string.json
   {
     "string": [
       // ...
       {
         "name": "button_one",
         "value": "Switch to: Beijing"
       },
       {
         "name": "button_two",
         "value": "Switch to: Shanghai"
       }
     ]
   }
   ```

<!--Del-->6. The running effect is as follows:<br>

![WidgetProject] (figures/full-screen-editing-page-running-result.gif)<!--DelEnd-->