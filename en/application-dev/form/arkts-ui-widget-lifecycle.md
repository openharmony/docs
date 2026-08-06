# Managing ArkTS Widget Lifecycle

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=a08d450b4f575e3d4749ddeef9dd32275ec0a19e translatedAt=2026-08-03T02:26:09.094Z pushedAt=2026-08-03T06:59:00.208Z -->

When creating an ArkTS widget, you need to implement the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) lifecycle APIs.

1. Import related modules to **EntryFormAbility.ets**.

    <!-- @[import_entry_form_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/entryformability/EntryFormAbility.ts) -->

    ``` TypeScript
    // entry/src/main/ets/entryformability/EntryFormAbility.ts
    import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
    import { Configuration, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. In **EntryFormAbility.ets**, implement the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) lifecycle API, including **onAddForm**, in which [want](../reference/apis-ability-kit/js-apis-app-ability-want.md) can be used to obtain the widget information through [FormParam](../reference/apis-form-kit/js-apis-app-form-formInfo.md#formparam).

    <!-- @[entry_form_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/entryformability/EntryFormAbility.ts) -->

    ``` TypeScript
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
        // This callback function is not required for the widget host.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
      }
    
      onUpdateForm(formId: string): void {
        // Override this method to support interval-based updates, time-specific updates, or updates requested by the widget host.
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
        hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${message}`);
        // ···
      }
    
      onRemoveForm(formId: string): void {
        // Remove widget data.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
        // Remove the persistent widget instance data.
        // Implement this API based on project requirements.
      }
    
      onConfigurationUpdate(config: Configuration) {
        // Called when the configuration of the environment where the formExtensionAbility is running is being updated.
        // The formExtensionAbility is cleared after 10 seconds of inactivity.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
      }
    
      onAcquireFormState(want: Want): formInfo.FormState {
        // Called upon a status query request from the widget. By default, the initial widget state is returned.
        return formInfo.FormState.READY;
      }
    }
    ```

> **NOTE**
>
> The FormExtensionAbility process cannot remain resident in the background. That is, long-running tasks cannot be processed in widget lifecycle callbacks. After lifecycle scheduling is complete, the process persists for 10 seconds. If no new lifecycle callback is received within 10 seconds, the process exits automatically. For business logic that may take more than 10 seconds to complete, you are advised to [launch the main app](arkts-ui-widget-event-overview.md) for processing, and then use [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform) to notify the widget to refresh.