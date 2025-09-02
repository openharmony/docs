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

| Name        | Type    | Read-Only  | Optional |Description         |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | No   | No| Bundle name of the application.|
| moduleName | string | No   | No| Module name of the application.|
| id         | number | No   | No| Resource ID.     |
| params     | any[] | No  | Yes| Other resource parameters, including the resource name, substitution value for the formatting API, and quantifier for the singular-plural formatting API.     |
| type       | number | No   | Yes| Resource type.     |
