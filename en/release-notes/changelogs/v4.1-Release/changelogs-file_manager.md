# File Management Subsystem Changelog

## c1.file_manager.1 Deprecation of File Management Module API and Parameters

**Access Level**

System API

**Reason for Change**

The deprecated API is a new API added in API version 11. Considering the compatibility with the existing APIs in API version 10, the authorization scheme is adjusted and the authorization is implemented by the AMS API **GrantUriPermission**. Therefore, this API is not longer required and is deprecated.

**Change Impact**

This API has never been released with a formal version. No adaptation is required.

**API level**

<11>

**Deprecated Since**

OpenHarmony SDK 4.1.5.1

**Deprecated API/Parameters**

function grantPermission(tokenId: number, policies: Array<PolicyInfo>, policyFlag: number): Promise<void>

export enum policyFlag

FORBID_PERSISTENCE = 0b10

ALLOW_PERSISTENCE = 0b1

**Adaptation Guide**

This API has never been released with a formal version. No adaptation is required.
