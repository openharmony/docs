# shortcutInfo (System API)

The module defines shortcut information configured in the configuration file. For the FA model, the shortcut information is configured in the [config.json](../../quick-start/application-configuration-file-overview-fa.md) file. For the stage model, the information is configured in the configuration file under **resources/base/profile** in the development view.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-ShortcutWant](js-apis-bundleManager-shortcutInfo.md) instead.
> 
> The APIs provided by this module are system APIs.

## ShortcutWant<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-ShortcutWant](js-apis-bundleManager-shortcutInfo.md#shortcutwant) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

| Name                     | Type  | Read-Only| Optional| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | Yes  | No  | Target bundle of the shortcut.|
| targetClass               | string | Yes  | No  | Target class required by the shortcut.|
