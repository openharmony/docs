# Input Method Framework ChangeLog

## cl.inputmethod_frameworks.1 API Filename Change

The following modules do not comply with the OpenHarmony API file naming rules. Therefore, they are modified in API version 9 and later.

 **Change Impacts**
 
 The SDK after the change is incompatible with the earlier versions. Therefore, adaptation is required for applications developed in earlier versions so that they can be properly built with the SDK in the new version.
 
 **Key API/Component Changes**
 
| Module| File Name Before Change| File Name After Change|
|------|--------------|--------------|
| Input method framework module| @ohos.inputmethod.d.ts |@ohos.inputMethod.d.ts |
| Input method service module|@ohos.inputmethodengine.d.ts | @ohos.inputMethodEngine.d.ts |
| Input method ExtentionAbility module| @ohos.inputmethodextensionability.d.ts | @ohos.InputMethodExtensionAbility.d.ts |
| Input method ExtentionContext module|@ohos.inputmethodextensioncontext.d.ts | @ohos.InputMethodExtensionContext.d.ts |
| Input method subtype module| @ohos.inputMethodSubtype.d.ts | @ohos.InputMethodSubtype.d.ts |
 
 **Adaptation Guide**
 
 In the application code, change the name of the d.ts file following **import** to the new file name, which complies with the UpperCamelCase or lowerCamelCase style.
 Example:
 
```js
import inputMethodEngine from '@ohos.inputMethodEngine';
```
 
 
