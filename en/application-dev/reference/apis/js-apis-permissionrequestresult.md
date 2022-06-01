# PermissionRequestResult

> **NOTE**<br>
> The initial APIs of this module are supported since API 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides the permission request result.

## Modules to Import

```js
import Ability from '@ohos.application.Ability'
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| No| Permissions requested.| 
| authResults | Array&lt;number&gt; | Yes| No| Whether the requested permissions are granted or denied. The value **0** means that the requests permissions are granted, and **-1** means the opposite. | 
