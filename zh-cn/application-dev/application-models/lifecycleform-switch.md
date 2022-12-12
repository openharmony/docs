# LifecycleForm接口切换


  | FA模型接口 | Stage模型接口对应d.ts文件 | Stage模型对应接口 | 
| -------- | -------- | -------- |
| onCreate?(want:&nbsp;Want):&nbsp;formBindingData.FormBindingData; | \@ohos.app.form.FormExtensionAbility.d.ts | [onAddForm(want:&nbsp;Want):&nbsp;formBindingData.FormBindingData;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onaddform) |
| onCastToNormal?(formId:&nbsp;string):&nbsp;void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onCastToNormalForm(formId:&nbsp;string):&nbsp;void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#oncasttonormalform) |
| onUpdate?(formId:&nbsp;string):&nbsp;void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onUpdateForm(formId:&nbsp;string):&nbsp;void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onupdateform) |
| onVisibilityChange?(newStatus:&nbsp;{&nbsp;[key:&nbsp;string]:&nbsp;number&nbsp;}):&nbsp;void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onChangeFormVisibility(newStatus:&nbsp;{&nbsp;[key:&nbsp;string]:&nbsp;number&nbsp;}):&nbsp;void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onchangeformvisibility) |
| onEvent?(formId:&nbsp;string,&nbsp;message:&nbsp;string):&nbsp;void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onFormEvent(formId:&nbsp;string,&nbsp;message:&nbsp;string):&nbsp;void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onformevent) |
| onDestroy?(formId:&nbsp;string):&nbsp;void; | \@ohos.app.form.FormExtensionAbility.d.ts | [onRemoveForm(formId:&nbsp;string):&nbsp;void;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onremoveform) |
| onAcquireFormState?(want:&nbsp;Want):&nbsp;formInfo.FormState; | \@ohos.app.form.FormExtensionAbility.d.ts | [onAcquireFormState?(want:&nbsp;Want):&nbsp;formInfo.FormState;](../reference/apis/js-apis-app-form-formExtensionAbility.md#onacquireformstate) |
| onShare?(formId:&nbsp;string):&nbsp;{[key:&nbsp;string]:&nbsp;any}; | \@ohos.app.form.FormExtensionAbility.d.ts | [onShareForm?(formId:&nbsp;string):&nbsp;{&nbsp;[key:&nbsp;string]:&nbsp;any&nbsp;};](../reference/apis/js-apis-app-form-formExtensionAbility.md#onshareform) |
