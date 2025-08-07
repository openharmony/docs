# V1->V2迁移指导
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @katabanga-->
<!--SE: @s10021109-->
<!--TSE: @TerryTsao-->

## 概述
ArkUI状态管理的主要职责是：负责将可观察数据的变化自动同步到UI界面，实现数据驱动的UI刷新，使开发者能更加够专注于UI界面的实现和设计。

在状态管理框架的演进过程中，先后推出了状态管理V1和V2两个版本。V1强调组件层级的状态管理，而V2则增强了对数据对象的深度观察与管理能力，不再局限于组件层级。通过V2，开发者能够更灵活地控制数据和状态，实现更高效的UI刷新。具体V1和V2的区别可以参见[状态管理概述](./arkts-state-management-overview.md)。

## V1V2使用指引
1. V2是V1的增强版本，正在持续迭代优化来为开发者提供更多功能和灵活性。
2. 对于新开发的应用，建议直接使用V2版本范式来进行开发。
3. 对于已经使用V1的应用，如果V1的功能和性能已能满足需求，则不必立即切换到V2。
4. 对于需要在现阶段混用V1和V2的场景，请参阅[混用文档](./arkts-custom-component-mixed-scenarios.md)。编译器、工具链、DevEco Studio对某些不推荐的误用和混用场景会进行校验，虽然开发者可能可以通过特殊手段绕过这些校验，但还是强烈建议开发者遵循[混用文档](./arkts-custom-component-mixed-scenarios.md)的指导，避免因双重代理等问题给应用带来不确定性。

## 迁移指南的目的
1. 对希望将现有V1应用迁移到V2的开发者，提供系统化的模板和指导，帮助完成V1到V2的迁移。
2. 对希望逐步将V1应用过渡到V2的开发者，提供参考，结合本迁移文档与[混用文档](./arkts-custom-component-mixed-scenarios.md)，可以帮助开发者实现逐步改造。
3. 尚未开始开发应用但已熟悉V1状态管理规则的开发者，可以参考本迁移文档及V2各个装饰器和接口的文档，开始使用V2进行应用开发。

## V1V2能力对比及迁移简表
| V1装饰器名\场景                | V2装饰器名\API                  | 说明 |
|------------------------|--------------------------|--------------------------|
| [\@Observed](./arkts-observed-and-objectlink.md)              | [\@ObservedV2](./arkts-new-observedV2-and-trace.md)              | 表明当前对象为可观察对象。但两者能力并不相同。 <br/>\@Observed可观察第一层的属性，需要搭配[\@ObjectLink](./arkts-observed-and-objectlink.md)使用才能生效。 <br/>\@ObservedV2本身无观察能力，仅代表当前class可被观察，如果要观察其属性，需要搭配\@Trace使用。详情见[\@ObjectLink/\@Observed/\@Track迁移场景](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace)。  |
| [\@Track](./arkts-track.md)                 | [\@Trace](./arkts-new-observedV2-and-trace.md)               | V1装饰器\@Track为精确观察，不使用则无法做到类属性的精准观察。 <br/>V2\@Trace装饰的属性可以被精确跟踪观察。详情见[\@ObjectLink/\@Observed/\@Track迁移场景](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace)。|
| [\@Component](./arkts-create-custom-components.md#component)             | [\@ComponentV2](./arkts-new-componentV2.md)             | \@Component为搭配V1状态变量使用的自定义组件装饰器。<br/>@ComponentV2为搭配V2状态变量使用的自定义组件装饰器。 |
|[\@State](./arkts-state.md)                 | 无外部初始化：[\@Local](./arkts-new-local.md)<br/>外部初始化一次：[\@Param](./arkts-new-param.md)[\@Once](./arkts-new-once.md) | \@State和\@Local类似都是数据源的概念，在不需要外部传入初始化时，可直接迁移。如果需要外部传入初始化，则可以迁移为\@Param\@Once。详情见[@State迁移场景](./arkts-v1-v2-migration-inner-component.md#state-local)。 |
| [\@Prop](./arkts-prop.md)                  | [\@Param](./arkts-new-param.md)                   | \@Prop和\@Param类似都是自定义组件参数的概念。当输入参数为复杂类型时，\@Prop为深拷贝，\@Param为引用。详情见[@Prop迁移场景](./arkts-v1-v2-migration-inner-component.md#prop---param)。 |
| [\@Link](./arkts-link.md)                  | [\@Param](./arkts-new-param.md)[\@Event](./arkts-new-event.md)    | \@Link是框架自己封装实现的双向同步，对于V2开发者可以通过@Param@Event自己实现双向同步。详情见[@Link迁移场景](./arkts-v1-v2-migration-inner-component.md#link---paramevent)。 |
| [\@ObjectLink](./arkts-observed-and-objectlink.md)           | [\@ObservedV2](./arkts-new-observedV2-and-trace.md)[\@Trace](./arkts-new-observedV2-and-trace.md)                   | 直接兼容，\@ObjectLink需要被@Observed装饰的class的实例初始化，主要应用于观察嵌套类场景。在状态管理V2中可以使用\@ObservedV2\@Trace。详情见[\@ObjectLink/\@Observed/\@Track迁移场景](./arkts-v1-v2-migration-inner-class.md#objectlinkobservedtrack---observedv2trace)。  |
| [\@Provide](./arkts-provide-and-consume.md)               | [\@Provider](./arkts-new-Provider-and-Consumer.md)                | 兼容。详情见[\@Provide\@Consume迁移场景](./arkts-v1-v2-migration-inner-component.md#provideconsume---providerconsumer)。 |
| [\@Consume](./arkts-provide-and-consume.md)               | [\@Consumer](./arkts-new-Provider-and-Consumer.md)                | 兼容。详情见[\@Provide\@Consume迁移场景](./arkts-v1-v2-migration-inner-component.md#provideconsume---providerconsumer)。 |
| [\@Watch](./arkts-watch.md)               | [\@Monitor](./arkts-new-monitor.md)                | \@Watch用于监听V1状态变量的变化，具有监听状态变量本身和其第一层属性变化的能力。状态变量可观察到的变化会触发其\@Watch监听事件。<br/>\@Monitor用于监听V2状态变量的变化，搭配\@Trace使用，可有深层监听的能力。状态变量在一次事件中多次变化时，仅会以最终的结果判断是否触发\@Monitor监听事件。详情见[\@Watch迁移场景](./arkts-v1-v2-migration-inner-component.md#watch---monitor)。 |
| 重复计算               | [\@Computed](./arkts-new-Computed.md)               |状态管理V1无计算属性相关能力，状态管理V2可使用\@Computed避免重复计算。详情见[@Computed使用场景](./arkts-v1-v2-migration-inner-component.md#computed)。|
| [LocalStorage](./arkts-localstorage.md)               | \@ObservedV2\@Trace   | 兼容。详情见[LocalStorage迁移场景](./arkts-v1-v2-migration-application-and-others.md#localstorage-observedv2trace)。 |
| [AppStorage](./arkts-appstorage.md)               | [AppStorageV2](./arkts-new-appstoragev2.md)   | 兼容。详情见[AppStorage迁移场景](./arkts-v1-v2-migration-application-and-others.md#appstorage-appstoragev2)。 |
| [Environment](./arkts-environment.md)       | 调用Ability接口获取系统环境变量   | Environment获取环境变量能力和AppStorage耦合。在V2中可直接调用Ability接口获取系统环境变量。详情见[Environment迁移场景](./arkts-v1-v2-migration-application-and-others.md#environment-调用ability接口直接获取系统环境变量)。 |
| [PersistentStorage](./arkts-persiststorage.md)     | [PersistenceV2](./arkts-new-persistencev2.md)   | PersistentStorage持久化能力和AppStorage耦合，PersistenceV2持久化能力可独立使用。详情见[PersistentStorage迁移场景](./arkts-v1-v2-migration-application-and-others.md#persistentstorage-persistencev2)。 |


## V1V2迁移场景
| 场景                | 涉及V2装饰器和API                  | 说明 |
|------------------------|--------------------------|--------------------------|
| V1现有功能向V2的逐步迁移场景      | \@ObservedV2、\@Trace和\@Monitor |对于已经使用V1开发的应用，逐步迁移V2的示例，详情见[V1现有功能向V2的逐步迁移场景](./arkts-v1-v2-migration-application-and-others.md#v1现有功能向v2的逐步迁移场景)。|
| 滑动组件场景      | [makeObserved](./arkts-new-makeObserved.md)|详情见[滑动组件迁移场景](./arkts-v1-v2-migration-application-and-others.md#滑动组件)。|
| [Modifier](../arkts-user-defined-modifier.md)场景     | makeObserved、\@ObservedV2、\@Trace|详情见[Modifier迁移场景](./arkts-v1-v2-migration-application-and-others.md#modifier)。|
