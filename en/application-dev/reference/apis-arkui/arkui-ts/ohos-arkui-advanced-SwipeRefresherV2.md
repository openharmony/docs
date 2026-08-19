# SwipeRefresherV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangrunsen-->
<!--Designer: @YanSanzo-->
<!--Tester: @ybhou1993-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=509c629682129872c95431baa7fdea382080692f translatedAt=2026-08-10T02:21:11.015Z pushedAt=2026-08-10T03:42:31.986Z -->

The **SwipeRefresherV2** component is used for content loading, which refers to obtaining and loading content. It is commonly used to display pull-to-refresh content.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can more flexibly control the data and state of content loading through this component, achieving more efficient UI refresh.

> **NOTE**
>
> - This component can only be used in the stage model.
>
> - If [universal attributes](ts-component-general-attributes.md) and [universal events](ts-component-general-events.md) are set for **SwipeRefresherV2**, the compilation toolchain will generate an additional node **__Common__** and mount the universal attributes or universal events on **__Common__**, rather than directly applying them to **SwipeRefresherV2** itself. This may cause the set universal attributes or universal events to not take effect or behave unexpectedly. Therefore, it is not recommended to set universal attributes and universal events on **SwipeRefresherV2**.

**Since:** 26.0.0

## Modules to Import

```ts
import { SwipeRefresherV2 } from '@kit.ArkUI';
```

## Child Components

Not supported

## SwipeRefresherV2

SwipeRefresherV2({content?: string, isLoading: boolean})

Implements the pull-to-refresh feature. When the user pulls down the page, a content loading operation is triggered, that is, new content is obtained from the data source and dynamically displayed on the UI.

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Mandatory | Decorator | Description |
| -------- | -------- | -------- | -------- |----------|
| content | string | No | @Param | Text displayed during content loading.<br/>Default value: empty string.<br/>**Note:** If the text exceeds the column width, it is truncated. |
| isLoading | boolean | Yes | @Require<br/>@Param | Whether the content is currently being loaded.<br> **true**: The content is being loaded.<br> **false**: The content is not being loaded. |

## Events

The [universal events](ts-component-general-events.md) are not supported.

## Examples

The **SwipeRefresherV2** component is supported since API version 26.0.0. The following example demonstrates different loading effects when the **content** attribute is set to an empty string or a non-empty string, and **isLoading** is set to **true** or **false**.

```ts
import { SwipeRefresherV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  build(): void {
    Column() {
      SwipeRefresherV2({
        content: 'Loading...',
        isLoading: true
      })
      SwipeRefresherV2({
        content: '',
        isLoading: true
      })
      SwipeRefresherV2({
        content: 'Loading...',
        isLoading: false
      })
    }
  }
}
```

<!--Del--> <!--DelEnd-->