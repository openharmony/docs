# Widget Lifecycle Management


When creating an ArkTS widget, you need to implement the [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md) lifecycle APIs.


1. Import related modules to **EntryFormAbility.ets**.
   
   ```ts
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   ```

2. In **EntryFormAbility.ets**, implement the [[FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md) lifecycle APIs, including **onAddForm**, whose **want** parameter can be used to obtain the widget information through [FormParam](../reference/apis/js-apis-app-form-formInfo.md#formparam).
   
   ```typescript
   import formInfo from '@ohos.app.form.formInfo';
   import formBindingData from '@ohos.app.form.formBindingData';
   import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
   import formProvider from '@ohos.app.form.formProvider';
   import { Configuration } from '@ohos.app.ability.Configuration';
   import Want from '@ohos.app.ability.Want';
   import Base from '@ohos.base';
   
   export default class EntryFormAbility extends FormExtensionAbility {
    onAddForm(want: Want) {
      console.info('[EntryFormAbility] onAddForm');
      // Called when the widget is created. The widget provider should return the widget data binding class.
      let obj: Record<string, string> = {
        'title': 'titleOnAddForm',
        'detail': 'detailOnAddForm'
      };
      let formData = formBindingData.createFormBindingData(obj);
      return formData;
    }

    onCastToNormalForm(formId: string) {
      // Called when the widget host converts the temporary widget into a normal one.
       
      // The widget provider should do something to respond to the conversion.
      console.info(`[EntryFormAbility] onCastToNormalForm, formId: ${formId}`);
    }

    onUpdateForm(formId: string) {
      // Override this method to support scheduled updates, periodic updates, or updates requested by the widget host.
      console.info('[EntryFormAbility] onUpdateForm');
      let obj: Record<string, string> = {
        'title': 'titleOnUpdateForm',
        'detail': 'detailOnUpdateForm'
      };
      let formData = formBindingData.createFormBindingData(obj);
      formProvider.updateForm(formId, formData).catch((err: Base.BusinessError) => {
        console.error(`[EntryFormAbility] Failed to updateForm. Code: ${err.code}, message: ${err.message}`);
      });
    }

    onChangeFormVisibility(newStatus: Record<string, number>) {
      // Called when the widget provider receives form events from the system.
      // The callback is triggered only when formVisibleNotify is set to true and the application is a system application.
      console.info('[EntryFormAbility] onChangeFormVisibility');
    }

    onFormEvent(formId: string, message: string) {
      // Called when a specified message event defined by the widget provider is triggered.
      // If the widget supports event triggering, override this method and implement the trigger.
      console.info('[EntryFormAbility] onFormEvent');
    }

    onRemoveForm(formId: string) {
      // Called to notify the widget provider that a specified widget has been destroyed.
      // The input parameter is the ID of the deleted card.
      console.info('[EntryFormAbility] onRemoveForm');
    }

    onConfigurationUpdate(config: Configuration) {
      // Called when the system configuration is updated.
      console.info('[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
    }

    onAcquireFormState(want: Want) {
      // Called to return a FormState object
      // upon a status query request from the widget. By default, the initial widget state is returned.
      return formInfo.FormState.READY;
    }
   }
   ```


> **NOTE**
>
> The FormExtensionAbility cannot reside in the background. It persists for 5 seconds after the lifecycle callback is completed and exist if no new lifecycle callback is invoked during this time frame. This means that continuous tasks cannot be processed in the widget lifecycle callbacks. For the service logic that may take more than 5 seconds to complete, it is recommended that you [start the application](arkts-ui-widget-event-uiability.md) for processing. After the processing is complete, use [updateForm()](../reference/apis/js-apis-app-form-formProvider.md#updateform) to notify the widget of the update.
