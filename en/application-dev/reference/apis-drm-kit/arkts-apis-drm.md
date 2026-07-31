# Module Description

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:11:46.609Z pushedAt=2026-07-31T03:50:38.261Z -->

The Digital Rights Management (DRM) framework enables you to develop digital rights management features for audio and video services. By calling the DRM plugins provided by the system, you can achieve the following:

- DRM certificate management: Generate certificate requests and handle certificate responses to facilitate certificate provisioning (downloading).

- DRM media key management: Generate media key requests, manage media key responses, and handle offline media keys.

- DRM content authorization: Allow DRM plugins to authorize content based on media key permissions.

- DRM content decryption: Support media playback decryption calls to decrypt DRM content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```