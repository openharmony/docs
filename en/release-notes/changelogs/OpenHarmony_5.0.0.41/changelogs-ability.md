# Ability Framework Changelog

## cl.ability.1 Unauthorized URIs Are Blocked When want Is Used to Share File URIs

**Access Level**

Public API

**Reason for Change**


If the authorization flag is enabled in the **flags** field of **want**, it is forbidden to pass unauthorized [file URIs](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md#fileuri10) into the **URI** field of **want** or into the **wantConstant.Params.PARAMS_STREAM** field.

> **NOTE**
>
> An authorized URI is the URI converted from the application sandbox path through [getUriFromPath](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath) or a persistent file URI.

**Change Impact**

This change is a non-compatible change.

Before change:

During file sharing using **want**, if the authorization flag is enabled in the **flags** field of **want**, the URIs set in the **URI** field of **want** and the **wantConstant.Params.PARAMS_STREAM** field are always transparently transmitted.

After change:

During file sharing using **want**, if the authorization flag is enabled in the **flags** field of **want**, unauthorized URIs set in the **URI** field of **want** and the **wantConstant.Params.PARAMS_STREAM** field are not passed. 

The file URI interception rules are as follows:

1. If the **URI** field in **want** is a file URI and the authorizing party does not have the permission to use the URI, the URI field is erased.
2. In the **WantConstant.Params.PARAMS_STREAM** field, the file URIs that the authorizing party does not have permission to access will be erased.
3. After the URI field in **want** is combined with the file URI field in **WantConstant.Params.PARAMS_STREAM**, the part that exceeds 500 will be truncated.


**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.41

**Key API/Component Changes**

N/A

**Adaptation Guide**

No adaptation is required.
