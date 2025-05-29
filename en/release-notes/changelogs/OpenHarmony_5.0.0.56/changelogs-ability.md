# Ability Framework Changelog

## cl.ability.1 Error Code 16000082 Is Returned When the startAbility API Is Called to Start a UIAbility That Is Configured in Singleton Mode and Is Currently Being Launched

**Access Level**

Public API

**Reason for Change**

When the **startAbility** API is called to start a UIAbility that is configured in singleton mode and is currently being launched, the original logic does not execute the call request and returns OK.

To enable the caller to detect request exceptions, an error code is introduced in this case.

**Change Impact**

This change is a non-compatible change.

Before change: When the **startAbility** API is called to start a UIAbility in singleton mode, the system does not respond to the call request and returns OK if the UIAbility is currently being launched. The caller is unaware of the exception.

After change: When the **startAbility** API is called to start a UIAbility in singleton mode, the system does not respond to the call request and returns an error code if the UIAbility is currently being launched. The API call fails.


**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.56

**Key API/Component Changes**

startAbility/openLink

The following APIs are involved:

UIAbilityContext:

- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options?: StartOptions)
- startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)

ServiceExtensionContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options?: StartOptions)
- startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- openLink(link:string, options?: OpenLinkOptions)

UIExtensionContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityForResultAsCaller(want: Want, options?: StartOptions)
- openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)

UIExtensionContentSession
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)

AbilityDelegator:
- startAbility(want: Want)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

InsightIntentContext:
- startAbility(want: Want)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

**Adaptation Guide**

When an application calls an API to start a UIAbility in singleton mode, if the error code 16000082 is reported, the UIAbility is currently being launched. Wait until the UIAbility finishes launching and try again.
