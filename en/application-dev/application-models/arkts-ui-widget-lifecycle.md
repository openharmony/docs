# Widget Lifecycle Management


When creating an ArkTS widget, you need to implement the [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md) lifecycle APIs.


1. Import related modules to **EntryFormAbility.ts**.
   
   ```ts
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   ```

2. In **EntryFormAbility.ts**, implement the [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md) lifecycle APIs, including **onAddForm**, whose **want** parameter can be used to obtain the widget information through [FormParam](../reference/apis/js-apis-app-form-formInfo.md#formparam).
   
   ```typescript
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   
   export default class EntryFormAbility extends FormExtensionAbility {
     onAddForm(want) {
       console.info('[EntryFormAbility] onAddForm');
       // Obtain the unique widget ID formId from the want parameter.
       let formId: string = want.parameters[formInfo.FormParam.IDENTITY_KEY];
       // Called when the widget is created. The widget provider should return the widget data binding class.
       let obj = {
         'title': 'titleOnAddForm',
         'detail': 'detailOnAddForm'
       };
       let formData = formBindingData.createFormBindingData(obj);
       return formData;
     }
   
     onCastToNormalForm(formId) {
       // Called when the form provider is notified that a temporary form is successfully
       // converted to a normal form.
       // Called when the widget host converts the temporary widget into a normal one. The widget provider should do something to respond to the conversion.
       console.info(`[EntryFormAbility] onCastToNormalForm, formId: ${formId}`);
     }
   
     onUpdateForm(formId) {
       // Override this method to support scheduled updates, periodic updates, or updates requested by the widget host.
       console.info('[EntryFormAbility] onUpdateForm');
       let obj = {
         'title': 'titleOnUpdateForm',
         'detail': 'detailOnUpdateForm'
       };
       let formData = formBindingData.createFormBindingData(obj);
       formProvider.updateForm(formId, formData).catch((err) => {
         if (err) {
           // Print errors.
           console.error(`[EntryFormAbility] Failed to updateForm. Code: ${err.code}, message: ${err.message}`);
           return;
         }
       });
     }
   
     onChangeFormVisibility(newStatus) {
       // Called when the form provider receives form events from the system.
       // The callback is performed only when formVisibleNotify is set to true and the application is a system application.
       console.info('[EntryFormAbility] onChangeFormVisibility');
     }
   
     onFormEvent(formId, message) {
       // Called when a specified message event defined by the form provider is triggered.
       // If the widget supports event triggering, override this method and implement the trigger.
       console.info('[EntryFormAbility] onFormEvent');
     }
   
     onRemoveForm(formId) {
       // Called to notify the form provider that a specified form has been destroyed.
       // Called when the corresponding widget is deleted. The input parameter is the ID of the deleted card.
       console.info('[EntryFormAbility] onRemoveForm');
     }
   
     onConfigurationUpdate(config) {
       // Called when the system configuration is updated.
       console.info('[EntryFormAbility] configurationUpdate:' + JSON.stringify(config));
     }
   
     onAcquireFormState(want) {
       // Called to return a {@link FormState} object.
       // Called when the widget provider receives the status query result of a widget. By default, the initial state of the widget is returned.
       return formInfo.FormState.READY;
     }
   }
   ```


> **NOTE**
>
> The FormExtensionAbility cannot reside in the background. It persists for 5 seconds after the lifecycle callback is completed and exist if no new lifecycle callback is invoked during this time frame. This means that continuous tasks cannot be processed in the widget lifecycle callbacks. For the service logic that may take more than 5 seconds to complete, it is recommended that you [start the application](arkts-ui-widget-event-uiability.md) for processing. After the processing is complete, use [updateForm()](../reference/apis/js-apis-app-form-formProvider.md#updateform) to notify the widget of the update.
