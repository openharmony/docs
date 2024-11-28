# Widget Lifecycle Management


When creating an ArkTS widget, you need to implement the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) lifecycle APIs.

1. Import related modules to **EntryFormAbility.ets**.
    ```ts
    import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
    import { Configuration, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. In **EntryFormAbility.ets**, implement the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) lifecycle API, including **onAddForm**, in which [want](../reference/apis-ability-kit/js-apis-app-ability-want.md) can be used to obtain the widget information through [FormParam](../reference/apis-form-kit/js-apis-app-form-formInfo.md#formparam).
   
      ```ts
      const TAG: string = 'EntryFormAbility';
      const DOMAIN_NUMBER: number = 0xFF00;
    
      export default class EntryFormAbility extends FormExtensionAbility {
        onAddForm(want: Want): formBindingData.FormBindingData {
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onAddForm');
          hilog.info(DOMAIN_NUMBER, TAG, want.parameters?.[formInfo.FormParam.NAME_KEY] as string);
    
          // ...
          // Called when the widget is created. The widget provider should return the widget data binding class.
          let obj: Record<string, string> = {
            'title': 'titleOnAddForm',
            'detail': 'detailOnAddForm'
          };
          let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
          return formData;
        }
    
        onCastToNormalForm(formId: string): void {
          // The widget provider should do something to respond to the conversion.
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
        }
    
        onUpdateForm(formId: string): void {
          // Override this method to support scheduled updates, periodic updates, or updates requested by the widget host.
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
          // Called when the widget host initiates an event about visibility changes. The widget provider should do something to respond to the notification. This callback takes effect only for system applications.
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onChangeFormVisibility');
        }
    
        onFormEvent(formId: string, message: string): void {
          // If the widget supports event triggering, override this method and implement the trigger.
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
          // ...
        }
    
        onRemoveForm(formId: string): void {
          // Delete widget data.
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
          // Delete the persistent widget instance data.
          // Implement this API based on project requirements.
        }
    
        onConfigurationUpdate(config: Configuration) {
          // Called when the configuration of the environment where the formExtensionAbility is running is being updated.
          // The formExtensionAbility is cleared after 10 seconds of inactivity.
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
        }
    
        onAcquireFormState(want: Want) {
          // Called upon a status query request from the widget. By default, the initial widget state is returned.
          return formInfo.FormState.READY;
        }
      }
      ```


> **NOTE**
>
> The FormExtensionAbility cannot reside in the background. It persists for 10 seconds after the lifecycle callback is completed and exits if no new lifecycle callback is invoked during this time frame. This means that continuous tasks cannot be processed in the widget lifecycle callbacks. For the service logic that may take more than 10 seconds to complete, it is recommended that you [start the application](arkts-ui-widget-event-uiability.md) for processing. After the processing is complete, use [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) to notify the widget of the update.
