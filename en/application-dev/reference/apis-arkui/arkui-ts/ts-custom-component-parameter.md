# Custom Component Parameters

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=a9c7224e91e63e46df3e2d778f9b21001bb35f6c translatedAt=2026-08-14T08:55:52.743Z pushedAt=2026-08-15T03:37:13.270Z -->

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## ComponentOptions

Defines parameters of a custom component, which is used to configure whether to support component freezing and the global reuse pool. They apply to scenarios where the performance of custom components needs to be optimized and the component reuse efficiency needs to be improved.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ------ | ---- | ---- | ------------ | ------------ |
|freezeWhenInactive|boolean| No | No |Whether to enable component freezing for the custom component. The value **true** means to enable component freezing, and **false** means not to enable it. When the developer does not specify **ComponentOptions**, **false** is used as the default value of **freezeWhenInactive**.<br>Since API version 11, this parameter can be used to configure component freezing for [@Component](../../../ui/state-management/arkts-create-custom-components.md#component). For an example, see [Freezing a Custom Component (V1)](../../../ui/state-management/arkts-custom-components-freeze.md).<br>Since API version 12, this parameter can be used to configure component freezing for [@ComponentV2](../../../ui/state-management/arkts-create-custom-components.md#componentv2). For an example, see [Freezing a Custom Component (V2)](../../../ui/state-management/arkts-custom-components-freezeV2.md).<br>**Widget capability:** This API can be used in ArkTS widgets since API version 11.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| reusePool | [ReusePoolOwnership](#reusepoolownership) | No | Yes | Type of the global reuse pool configured on the custom component. It applies to scenarios where multiple reusable custom components of the same type exist in an app and reuse resources need to be shared or isolated between component instances to improve reuse efficiency. If this parameter is not passed, the global reuse pool does not take effect. **reusePool** must be used together with **poolAccepts**. When **reusePool** is set, **poolAccepts** must be a non-empty array; otherwise, global reuse does not take effect.<br>**Since:** 26.0.0<br>**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0. |
| poolAccepts | Function[] | No | Yes | List of custom component names that the global reuse pool can accept (that is, allow to be reused). When **reusePool** is set, the system caches the matching reusable components into the global reuse pool based on the component names listed in **poolAccepts** for subsequent reuse. When **reusePool** is set, **poolAccepts** must be a non-empty array. Setting **poolAccepts** alone does not make global reuse take effect. When neither **poolAccepts** nor **reusePool** is assigned, global reuse does not take effect.<br>**Since:** 26.0.0<br>**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0. |

## ReusableOptions

Defines the parameters of a reusable custom component, which are used to configure the memory optimization strategy. They apply to scenarios where the memory usage of reusable custom components needs to be reduced.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ------ | ---- | ---- | ------------ | ------------ |
| memoryOptimizationStrategy | [ReusableMemOptStrategy](#reusablememoptstrategy) | No | Yes | Memory optimization strategy of the reusable custom component. This parameter is set when the reusable custom component is created and does not support dynamic modification. When [ENABLE_AUTO_CACHE_OPTIMIZATION](#reusablememoptstrategy) is passed, automatic memory optimization is enabled, and the components in the reuse pool are automatically released in scenarios such as the app going to the background, the component becoming invisible, or the device running low on memory. When this parameter is not passed, the default value [DEFAULT](#reusablememoptstrategy) (no memory optimization strategy) is used. |

## ReusableMemOptStrategy

Enumerates the memory optimization strategies of reusable custom components.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value | Description |
| --- | --- | --- |
| DEFAULT | 0 | No memory optimization strategy. |
| ENABLE_AUTO_CACHE_OPTIMIZATION | 1 << 0 | Automatic memory optimization strategy. It is recommended to use this strategy in scenarios where the memory usage of reusable custom components needs to be reduced.<br>All custom components of this type in the reuse pool are released when any of the following conditions is met:<br>- The app goes to the background.<br>- The component that owns the reuse pool becomes invisible (the [visibility](./ts-universal-attributes-visibility.md#visibility) attribute is set to a value other than [Visible](./ts-appendix-enums.md#visibility), or the component area is 0, regardless of occlusion).<br>- The device runs low on memory ([MemoryLevel](../../apis-ability-kit/js-apis-app-ability-abilityConstant.md#memorylevel) reaches **MEMORY_LEVEL_LOW** or **MEMORY_LEVEL_CRITICAL**).<br>When the number of custom components of this type with the same **ReuseId** in the reuse pool exceeds the reuse pool capacity limit and does not increase within 5 seconds, the components within the limit are retained and the rest are released. The reuse pool capacity limit is set as follows:<br>- When the device memory is greater than 8 GB, the limit is 48.<br>- When the device memory is greater than 6 GB and less than or equal to 8 GB, the limit is 4.<br>- When the device memory is less than or equal to 6 GB, the limit is 2.<br>When a node is released, the [custom component lifecycle](../../../ui/state-management/arkts-page-custom-components-lifecycle.md) is triggered. |

## Examples

### Example 1: Using the Automatic Memory Optimization Strategy

In the following example, the reusable custom component **ReusableComponent** uses the automatic memory optimization strategy through the **memoryOptimizationStrategy** attribute of [ReusableOptions](#reusableoptions). Click the **Recycle** button to trigger the recycling of the **ReusableComponent** component. Then, when the app goes to the background, the reuse pool cache is released.

The **ReusableOptions** API is added since API version 26.0.0.

```ts
@Reusable({ memoryOptimizationStrategy: ReusableMemOptStrategy.ENABLE_AUTO_CACHE_OPTIMIZATION }) // Use the automatic memory optimization strategy.
@Component
struct ReusableComponent {
  aboutToRecycle() {
    console.info('ReusableComponent aboutToRecycle');
  }
  aboutToDisappear() {
    console.info('ReusableComponent aboutToDisappear');
  }
  build() {
    Text('ReusableComponent')
  }
}

@Entry
@Component
struct MemoryOptimizeDemo {
  @State showReusableComponent: boolean = true;
  build() {
    Column() {
      Button('Recycle').onClick(() => { // Tap the button to trigger component recycling.
        this.showReusableComponent = false;
      })
      if (this.showReusableComponent) {
        ReusableComponent()
      }
    }
  }
}
```

## ReusePoolOwnership

type ReusePoolOwnership = 'shared' | 'perInstance'

Defines the ownership type of the global reuse pool.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Type | Description |
|-------------    | ------------------- |
| 'shared' | All instances of the **@Component**/**@ComponentV2** class share the same reuse pool instance. It applies to scenarios where multiple component instances of the same type need to reuse the same resources, maximizing the reuse pool utilization and reducing memory usage. |
| 'perInstance' | Each instance of **@Component**/**@ComponentV2** has an independent reuse pool instance. It applies to scenarios where the reuse resources of each component instance need to be isolated, preventing the reuse resources of different instances from affecting each other. |