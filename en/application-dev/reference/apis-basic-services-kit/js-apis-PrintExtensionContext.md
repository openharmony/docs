# PrintExtensionContext

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @baozewei-->
<!--Tester: @baozewei-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=a75caff82c94546c33a0453b490236ece761a353 translatedAt=2026-08-05T12:18:28.469Z pushedAt=2026-08-06T02:22:24.500Z -->

**PrintExtensionContext** represents the context of **PrintExtensionAbility** and inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

It can be directly used as the context of **PrintExtension** and provides APIs to access specific **PrintExtensionAbility** resources.

> **NOTE**
>
> - The APIs of this module can be used only in the stage model.
> - The initial APIs of this module are supported since API version 26. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
```

## How to Use

Obtain it through a **PrintExtensionAbility** child class instance.

```ts
import { PrintExtensionAbility } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

export default class printExtension extends PrintExtensionAbility {

  onCreate(want: Want) {
    let context = this.context;
  }
}
```