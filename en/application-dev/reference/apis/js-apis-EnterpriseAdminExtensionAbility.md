# EnterpriseAdminExtentionAbility

The **EnterpriseAdminExtentionAbility** module provides APIs for Extension abilities of enterprise administrators.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.
## Modules to Import

```ts
import EnterpriseAdminExtentionAbility from '@ohos.EnterpriseAdminExtentionAbility'
```

## EnterpriseAdminExtentionAbility.onAdminEnabled

onAdminEnabled(): void

Called when an enterprise administrator is enabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Example**

  ```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
    onAdminEnabled() {
    }
};
  ```

## EnterpriseAdminExtentionAbility.onAdminDisabled

onAdminDisabled(): void

Called when an enterprise administrator is disabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Example**
    

  ```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
    onAdminDisabled() {
    }
};
  ```
