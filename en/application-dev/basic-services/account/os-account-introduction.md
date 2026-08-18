# System Account Introduction

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @pan9f-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=9c3c647d072b0519c6b6cf42cca216bb556b9e0f translatedAt=2026-08-18T01:33:40.097Z pushedAt=2026-08-18T08:47:51.072Z -->

## System Account ID System

In OpenHarmony, each system account is assigned a unique integer identifier upon creation, called the **system account ID**, which corresponds to the `localId` field in [OsAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo). System account IDs are classified into the following categories by purpose:

| Range | Category | Purpose |
|------|------|------|
| ID=0 | System-level public service account | System-level services and apps are installed and run under this account. |
| ID=1 | Enterprise-level public service account | Enterprise-level services and apps are installed and run under this account. |
| ID=2~99 | Reserved system accounts | Reserved by the system and not yet defined. |
| ID=100+ | Natural person user accounts | Accounts used by natural persons, with IDs starting from 100. |

> **NOTE**
> 
> For the installation specifications of apps under each type of system account, see [App Installation Instructions](../../tools/bm-tool.md#userid).

## Related Documents

- [OsAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)