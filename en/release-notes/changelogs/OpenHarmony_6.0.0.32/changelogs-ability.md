# Ability Framework Changelog

## cl.ability.1 AbilityDelegator.startAbility() Error Code Changed

**Access Level**

Public API

**Reason for Change**

All error codes returned by **AbilityDelegator.startAbility()** are inconsistent with the API documentation.

**Impact of the Change**

This change does not require application adaptation.

The change affects all error codes returned by **AbilityDelegator.startAbility()**. The error code mapping is as follows:

| Before Change   | After Change   |
| -------- | --------  |
| 29360128 | 401       |
| 2097199  | 16000001  |
| 2097187  | 16000002  |
| 2097179  | 16000004  |
| 2097208  | 16000005  |
| 2097207  |16000006   |
| 2097203  | 16000008  |
| 11       |  16000009 |
| 2097206  | 16000010  |
| 2097323  | 16000011  |
| 2097204  | 16000012  |
| 2097215  | 16000013  |
| 2097167  | 16000050  |
| 5242881  | 16000053  |
| 29360300 | 16000055  |
| 2097205  | 16200001  |

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

**startAbility()** provided by AbilityDelegator

**Adaptation Guide**

No adaptation is required.

For details about the **startAbility()** API provided by AbilityDelegator, see [startAbility](../../../application-dev/reference/apis-test-kit/js-apis-inner-application-abilityDelegator.md#startability9).

## cl.ability.2 Erasing Invalid URIs When Sharing Files via Want

**Access Level**

Public API

**Reason for Change**

In file sharing scenarios (where the **flags** field of Want is configured with [wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) or [wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)), an application can pass a single URI through the **uri** field of Want, or pass multiple URIs using the **Key** value of [wantConstant.Params.PARAMS_STREAM](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params). To ensure that the parameters passed to the target application are valid, the system proactively erases URIs that do not meet the conditions.

**Impact of the Change**

This change does not require application adaptation.

Before change, in file sharing scenarios, if the scheme of the **uri** field in Want is empty, or the scheme of the URIs in the **wantConstant.Params.PARAMS_STREAM** field is not **file**, the system does not perform any processing.

After change, in file sharing scenarios, if the scheme of the **uri** field in Want is empty, or the scheme of the URIs in the **wantConstant.Params.PARAMS_STREAM** field is not **file**, the system erases the corresponding URI values.

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

The APIs related to starting and exiting applications can trigger this change in file sharing scenarios. The involved interfaces are as follows:

[UIAbilityContext](../../../application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext):
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void
- terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number
- startAbilityByCall(want: Want): Promise&lt;Caller&gt;
- startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;
- connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

[UIExtensionContext](../../../application-dev/reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md#uiextensioncontext):

- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void
- terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;
- startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;
- connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

**Adaptation Guide**

No adaptation is required.
