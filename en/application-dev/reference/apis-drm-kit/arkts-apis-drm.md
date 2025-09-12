# Module Description

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Digital Rights Management (DRM) framework provides APIs for you to develop digital rights management for your audio and video applications. You can call the DRM solutions (which exist as DRM plugins) provided by the system to implement the following features:

- DRM certificate management: generates provision requests and processes responses to these requests. Such a request/response exchange occurs between an application and a provisioning server to retrieve a DRM certificate.
- DRM media key management: generates media key requests, processes responses to these requests, and manages offline media keys. Such a request/response exchange occurs between an application and a license server to obtain or release a media key, which is used to decrypt DRM-protected content.
- DRM authorization: authorizes access to DRM-protected content based on media keys.
- DRM decryption: decrypts DRM-protected content.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```
