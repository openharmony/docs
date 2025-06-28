# @ohos.identifier.oaid (OAID) (System API)

The **OAID** module provides APIs for obtaining and resetting Open Anonymous Device Identifiers (OAIDs).

> **NOTE**
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - To use the APIs for obtaining OAIDs, you must [request the ohos.permission.APP_TRACKING_CONSENT permission](../../security/AccessToken/request-user-authorization.md).
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.identifier.oaid (OAID)](js-apis-oaid.md).

## Modules to Import

```ts
import { identifier } from '@kit.AdsKit';
```

## identifier.resetOAID

resetOAID(): void

Resets an OAID.

**System API**: This is a system API.

**System capability**: SystemCapability.Advertising.OAID

**Error codes**

For details about the following error codes, see [OAID Error Codes](errorcode-oaid.md).

| ID| Error Message                                                                    |
|----------|------------------------------------------------------------------------------|
| 202      | Permission verification failed. A non-system application calls a system API. |
| 17300001 | System internal error.                                                       |
| 17300002 | Not in the trust list.                                                       |

**Example**

```ts
import { identifier } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  identifier.resetOAID();
} catch (err) {
  hilog.error(0x0000, 'testTag', `Fail to reset OAID. Code is ${err.code}, message is ${err.message}`);
}
```
