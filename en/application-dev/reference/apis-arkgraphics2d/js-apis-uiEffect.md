# @ohos.graphics.uiEffect (Cascading Effect)

The uiEffect module provides basic capabilities to apply an effect, for example, blur, pixel stretch, and brightness, to a component. Effects are classified into filters and visual effects. Effects of the same category can be cascaded in an effect instance of the corresponding category. In actual development, the blur effect can be used for background blurring, and the brightness effect can be used for screen-on display.

- [Filter](#filter): applies a filter to a component.
- [VisualEffect](#visualeffect): applies a visual effect to a component.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
```

## uiEffect.createFilter
createFilter(): Filter

Creates a **Filter** instance, which can be used to apply multiple filters to a component.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type             | Description                |
| ------------------| ------------------- |
| [Filter](#filter) | Head node of the filter.|

**Example**

```ts
let filter : uiEffect.Filter = uiEffect.createFilter()
```

## uiEffect.createEffect
createEffect(): VisualEffect

Creates a **VisualEffect** instance, which can be used to apply multiple visual effects to a component.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                         | Description                      |
| ----------------------------- | ------------------------- |
| [VisualEffect](#visualeffect) | Head node of the visual effect.|

**Example**

```ts
let visualEffect : uiEffect.VisualEffect = uiEffect.createEffect()
```

## Filter
A class that can apply a filter to a component. Before calling any API in **Filter**, you must use [createFilter](#uieffectcreatefilter) to create a **Filter** instance.

### blur
blur(blurRadius: number): Filter

Applies the blur effect to the component.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**
| Name      | Type  | Mandatory| Description      |
| ----------- | -------| ---- | --------- |
| blurRadius  | number | Yes  | Blur radius.<br>The value must be greater than or equal to 0. The larger the radius is, the more blurred the content is.<br>If the value is 0, the content is not blurred.|

**Return value**

| Type              | Description                      |
| ----------------- | -------------------------- |
| [Filter](#filter) | **Filter** instance with the blur effect.|

**Example**

```ts
filter.blur(20)
```

## VisualEffect
A class that can apply a visual effect to a component. Before calling any API in **VisualEffect**, you must use [createEffect](#uieffectcreateeffect) to create a **VisualEffect** instance.
