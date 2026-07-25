# V1 to V2 Migration Overview

<!--Kit: ArkUI--> 
<!--Subsystem: ArkUI-->
<!--Owner: @katabanga-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=c6d2a51ae0d4d741fa9801df0b2e84e58290f6c1 translatedAt=2026-07-24T01:23:02.269Z pushedAt=2026-07-24T03:23:16.369Z -->

## Overview

<!--RP1-->

In the iterative evolution of the state management framework, [State Management V1](./arkts-state.md) (V1 for short) and [State Management V2](./arkts-new-local.md) (V2 for short) are launched. V1 focuses on state management at the component level. For example, it requires developers to unwrap nested classes layer by layer via [\@ObjectLink](./arkts-observed-and-objectlink.md) to enable observation capabilities for deep-level data. V2 achieves a capability upgrade and enhances the capabilities of deep observation and management for data objects. For example, [\@Monitor](./arkts-new-monitor.md) in V2 cannot only perceive the data after changes, but also obtain the data before changes. With V2, you can manipulate data and states more flexibly, achieve more efficient UI refresh, and improve development experience as well as application performance.

<!--RP1End-->

<!--RP2-->

To help developers smoothly migrate applications developed based on V1 to V2, this document provides [Migration for Component State Variables](./arkts-v1-v2-migration-inner-component.md), covering common scenarios during the migration. Developers can adapt the migration guide based on their services. In addition, for the [mixed use of state management V1 and V2](./arkts-v1-v2-mixusage-before-api-version.md) that may occur during the migration transition phase, this document elaborates on the rules and practical methods for using V2 components in V1. Based on the differences before and after API version 19, it also provides targeted solutions respectively to help developers implement gradual reconstruction.

<!--RP2End-->

## How to Use

You are advised to select V1 or V2 based on application requirements. V2 is an enhanced version of V1 and is continuously iterated and optimized. Therefore, V2 is recommended for new development. The reference policies are as follows:

1. For new applications, you are advised to use V2 for development.

2. For applications that have used V1, if the features and performance of V1 meet the requirements, you do not need to switch to V2 immediately.

3. For scenarios where mixed usage of V1 and V2 is required at the current stage, <!--RP3-->please refer to [Mixed Use of State Management V1 and V2](./arkts-v1-v2-mixusage-before-api-version.md)<!--RP3End-->. The compiler, toolchain, and DevEco Studio perform checks on certain misuse and mixed-use scenarios. You are advised to follow this document to avoid uncertainties in applications caused by issues such as dual proxying (data being proxied and monitored by both V1 and V2 simultaneously).

## V1 and V2 Differences

For details about the differences between V1 and V2, see [State Management Overview](./arkts-state-management-overview.md) and [Differences Between State Management V1 and V2 Update Mechanisms](./arkts-v1-v2-update-difference.md). This section helps you understand the differences between V1 and V2 and improve the adaptation efficiency.

## V1 and V2 Capability Comparison and Migration Table

| V1 Decorator/Scenario| V2 Decorator/API| Description|
| -------- | -------- | -------- |
| [\@Component](./arkts-create-custom-components.md#component) | [\@ComponentV2](./arkts-create-custom-components.md#componentv2) | \@Component is the decorator for custom components in V1.<br>\@ComponentV2 is the decorator for custom components in V2.|
| [\@State](./arkts-state.md) | No external initialization: [\@Local](./arkts-new-local.md)<br>One-time external initialization: [\@Param](./arkts-new-param.md) or [\@Once](./arkts-new-once.md)| Similar to \@Local, \@State decorated variables can work as the data source which can be directly migrated without external initialization. If the initialization needs to be transferred from an external system, it can be migrated to \@Param \@Once. For details, see [\@State->\@Local](./arkts-v1-v2-migration-inner-component.md#state---local). If using [WaterFlowSections](../../reference/apis-arkui/arkui-ts/ts-container-waterflow.md#waterflowsections12)/[ChildrenMainSize](../../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#childrenmainsize12) associated with the scroll component, you need to use [makeObserved](./arkts-new-makeObserved.md). For details, see Scrollable Component.|
| [\@Prop](./arkts-prop.md) | [\@Param](./arkts-new-param.md) | \@Prop and \@Param both represent parameters for custom components. For complex input types, \@Prop uses deep copying, while \@Param uses references. For details, see [@Prop -> @Param](./arkts-v1-v2-migration-inner-component.md#prop---param).|
| [\@Link](./arkts-link.md) | [\@Param](./arkts-new-param.md), [@Event](./arkts-new-event.md)| \@Link is a framework-encapsulated implementation of two-way synchronization. In V2, you can implement two-way synchronization manually using \@Param and \@Event. For details, see [\@Link -> \@Param/\@Event](./arkts-v1-v2-migration-inner-component.md#link---paramevent)|
| [\@Observed](./arkts-observed-and-objectlink.md) | [\@ObservedV2](./arkts-new-observedV2-and-trace.md) | Both mark an object as observable, but with key differences:<br>\@Observed is used to observe the top-level properties and requires [\@ObjectLink](./arkts-observed-and-objectlink.md) to take effect.<br>\@ObservedV2 does not have the observation capability. It only marks a class as observable. To observe the class properties, use it together with \@Trace. For details, see [@ObjectLink/@Observed/@Track -> @ObservedV2/@Trace](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace).|
| [\@ObjectLink](./arkts-observed-and-objectlink.md) | [\@ObservedV2](./arkts-new-observedV2-and-trace.md), [\@Trace](./arkts-new-observedV2-and-trace.md)| Direct compatibility. \@ObjectLink needs to be initialized by the instance of the class decorated by @Observed. It is mainly used to observe nested classes. \@ObservedV2\@Trace can be used in state management V2. For details, see [@ObjectLink/@Observed/@Track -> @ObservedV2/@Trace](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace).|
| [@Track](./arkts-track.md) | [@Trace](./arkts-new-observedV2-and-trace.md) | \@Track is used for accurate observation. If it is not used, class properties cannot be accurately observed.<br>\@Trace decorated properties can be accurately traced and observed. For details, see [@ObjectLink/@Observed/@Track -> @ObservedV2/@Trace](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace).|
| [@Provide](./arkts-provide-and-consume.md), [@Consume](./arkts-provide-and-consume.md)| [@Provider](./arkts-new-provider-and-consumer.md), [@Consumer](./arkts-new-provider-and-consumer.md)| Compatible. For details, see [@Provide/@Consume -> @Provider/@Consumer](./arkts-v1-v2-migration-inner-component.md#provideconsume---providerconsumer).|
| [@Watch](./arkts-watch.md) | [@Monitor](./arkts-new-monitor.md) | @Watch is used to monitor changes in V1 state variables. It can monitor changes to the state variable itself and its first-level properties. Observable changes to the state variable trigger its @Watch monitoring event. For details, see the migration scenario [@Watch -> @Monitor](./arkts-v1-v2-migration-inner-component.md#watch---monitor).<br/>@Monitor is used to monitor changes in V2 state variables. When used together with @ObservedV2 and @Trace, it provides deep monitoring capabilities. When a state variable changes multiple times in a single event, whether the @Monitor monitoring event is triggered is determined solely by the final result. |
| No computing capability| [@Computed](./arkts-new-computed.md) | State management V1 does not have the capability of calculating attributes. State management V2 can use \@Computed to avoid repeated calculation. For details, see [Repeated Calculation -> @Computed Property](./arkts-v1-v2-migration-inner-component.md#repeated-calculation---computed-property).|
| [LocalStorage](./arkts-localstorage.md) | [@ObservedV2](./arkts-new-observedV2-and-trace.md), [@Trace](./arkts-new-observedV2-and-trace.md)| Compatible. For details, see [LocalStorage->@ObservedV2/@Trace](./arkts-v1-v2-migration-application.md#localstorage-observedv2trace).|
| [AppStorage](./arkts-appstorage.md) | [AppStorageV2](./arkts-new-appstoragev2.md) | Compatible. For details, see [AppStorage->AppStorageV2](./arkts-v1-v2-migration-application.md#appstorage-appstoragev2).|
| [Environment](./arkts-environment.md) | Direct ability API calls to obtain system environment variables| **Environment** for obtaining environment variables is coupled with AppStorage. V2 removes AppStorage dependency, enabling direct ability API calls for obtaining environment variables. For details, see Environment->Direct API Calls to Obtain System Environment Variables.|
| [PersistentStorage](./arkts-persiststorage.md) | [PersistenceV2](./arkts-new-persistencev2.md) | PersistentStorage's persistence capability is coupled with AppStorage, while PersistenceV2 can be used independently. For details, see [PersistentStorage->PersistenceV2](./arkts-v1-v2-migration-application.md#persistentstorage-persistencev2).|

## Gradual Migration from State Management V1 to V2

For large-scale applications already developed with V1, it is generally difficult to migrate from V1 to V2 all at once. Instead, a gradual migration in batches and by components is required. First, migrate V1 components to V2 components. <!--RP5-->For details, see [State Management V1 to V2 Migration](./arkts-v1-v2-migration-inner-component.md)<!--RP5End-->.

During the migration, V1 and V2 coexist, which inevitably leads to the mixed use of V1 and V2. For the mixed use scenario, <!--RP4-->see [Mixed Use of State Management V1 and V2](./arkts-v1-v2-mixusage-before-api-version.md), and finally complete the full migration from V1 to V2<!--RP4End-->.