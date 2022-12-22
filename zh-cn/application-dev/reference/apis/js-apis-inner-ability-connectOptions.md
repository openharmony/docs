# ConnectOptions

在连接指定的后台服务时作为入参，用于接收连接过程中的状态变化，如作为[connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)的入参，连接指定的ServiceExtensionAbility。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 参数名           | 类型       | 必填   | 说明                        |
| ------------ | -------- | ---- | ------------------------- |
| onConnect<sup>7+</sup>    | function | 是    | 建立连接时的回调函数。      |
| onDisconnect<sup>7+</sup> | function | 是    | 断开连接时的回调函数。           |
| onFailed<sup>7+</sup>     | function | 是    | 连接失败时的回调函数。 |

