# LifecycleForm Switching


  | API in the FA Model| Corresponding d.ts File in the Stage Model| Corresponding API in the Stage Model| 
| -------- | -------- | -------- |
| onCreate?(want: Want): formBindingData.FormBindingData; | \@ohos.app.form.FormExtensionAbility.d.ts | [onAddForm(want: Want): formBindingData.FormBindingData;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onaddform) |
| onCastToNormal?(formId: string): void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onCastToNormalForm(formId: string): void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#oncasttonormalform) |
| onUpdate?(formId: string): void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onUpdateForm(formId: string): void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onupdateform) |
| onVisibilityChange?(newStatus: { [key: string]: number }): void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onChangeFormVisibility(newStatus: { [key: string]: number }): void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onchangeformvisibility) |
| onEvent?(formId: string, message: string): void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onFormEvent(formId: string, message: string): void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onformevent) |
| onDestroy?(formId: string): void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onRemoveForm(formId: string): void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onremoveform) |
| onAcquireFormState?(want: Want): formInfo.FormState; | \@ohos.app.form.FormExtensionAbility.d.ts | [onAcquireFormState?(want: Want): formInfo.FormState;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onacquireformstate) |
| onShare?(formId: string): {[key: string]: any}; | \@ohos.app.form.FormExtensionAbility.d.ts | [onShareForm?(formId: string): { [key: string]: any };](../reference/apis/js-apis-app-form-formExtensionAbility.md#onshareform) |
