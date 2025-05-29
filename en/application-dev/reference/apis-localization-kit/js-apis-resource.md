# Resource

Provides resource information, such as the application bundle name, application module name, and resource ID.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Import a module.

```js
import { resourceManager } from '@kit.LocalizationKit'
```

## Resource

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Global.ResourceManager

| Name        | Type    | Readable  | Writable |Description         |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | Yes   | No| Bundle name of the application.|
| moduleName | string | Yes   | No| Module name of the application.|
| id         | number | Yes   | No| Resource ID.     |
| params     | any[] | Yes   | No| Other resource parameters, which are optional.     |
| type       | number | Yes   | No| Resource type, which is optional.     |
