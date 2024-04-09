# Special Effect Drawing Combination (System API)

The **useEffect** attribute is used to combine the drawing of special effects, such as background blur.

> **NOTE**
>
> This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## useEffect

useEffect(value: boolean)

Specifies whether to combine the drawing of special effects, such as background blur.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | boolean | Yes| Whether the component inherits the special effect settings of the **\<EffectComponent>** component.<br>The value **true** means that the component inherits the special effect settings of the **\<EffectComponent>** component, and **false** means the opposite.<br>Default value: **false**|

## Example

For details, see [EffectComponent](ts-container-effectcomponent-sys.md).
