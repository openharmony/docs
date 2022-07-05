# FormError

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides widget-related error codes.

## Modules to Import

```
import formError from '@ohos.application.formError';
```

## Required Permissions

None.

## enum FormError

Enumerates the available error codes.

**System capability**

SystemCapability.Ability.Form

| Name       | Value  | Description        |
| ----------- | ---- | ------------ |
| ERR_COMMON       | 1    | Default error code.  |
| ERR_PERMISSION_DENY       | 2    | No permission to perform the operation.  |
| ERR_GET_INFO_FAILED      | 4    | Failed to query widget information.  |
| ERR_GET_BUNDLE_FAILED    | 5    | Failed to query the bundle information.  |
| ERR_GET_LAYOUT_FAILED    | 6    | Failed to query the layout information.  |
| ERR_ADD_INVALID_PARAM     | 7    | Invalid parameter.  |
| ERR_CFG_NOT_MATCH_ID     | 8    | The widget ID does not match.  |
| ERR_NOT_EXIST_ID       | 9    | The widget ID does not exist.  |
| ERR_BIND_PROVIDER_FAILED       | 10    | Failed to bind to the widget provider.  |
| ERR_MAX_SYSTEM_FORMS      | 11    | The number of system widgets exceeds the upper limit.  |
| ERR_MAX_INSTANCES_PER_FORM     | 12    | The number of instances per widget exceeds the upper limit.  |
| ERR_OPERATION_FORM_NOT_SELF     | 13    | The application is not allowed to operate widgets applied by other applications.  |
| ERR_PROVIDER_DEL_FAIL       | 14    | The widget provider failed to delete the widget.  |
| ERR_MAX_FORMS_PER_CLIENT       | 15    | The number of widgets applied for by the widget host exceeds the upper limit.  |
| ERR_MAX_SYSTEM_TEMP_FORMS       | 16    | The number of temporary widgets exceeds the upper limit.  |
| ERR_FORM_NO_SUCH_MODULE       | 17    | The module does not exist.  |
| ERR_FORM_NO_SUCH_ABILITY       | 18    | The ability component does not exist.  |
| ERR_FORM_NO_SUCH_DIMENSION      | 19    | The widget dimension does not exist.  |
| ERR_FORM_FA_NOT_INSTALLED      | 20    | The FA where the widget is located is not installed.  |
| ERR_SYSTEM_RESPONSES_FAILED        | 30    | The system service failed to respond.  |
| ERR_FORM_DUPLICATE_ADDED        | 31    | The widget has been added.  |
| ERR_IN_RECOVERY    | 36    | Failed to overwrite the widget data.  |
