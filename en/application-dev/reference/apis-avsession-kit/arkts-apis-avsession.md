# Module Description

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=3bb4c97ba607c5353ac0e05f41ee04555a22e644 translatedAt=2026-08-19T10:02:23.809Z pushedAt=2026-08-19T12:01:32.627Z -->

The AVSession module provides APIs for media playback control so that applications can access the system's Media Controller.

This module provides the following typical features related to media sessions:

- [AVSession](arkts-apis-avsession-AVSession.md): used to set session metadata, playback state information, and more.

- [AVSessionController](arkts-apis-avsession-AVSessionController.md): used to obtain session IDs, send commands and events to sessions, and obtain the session metadata and playback state information.

- [AVCastController](arkts-apis-avsession-AVCastController.md): used to control playback, listen for remote playback state changes, and obtain the remote playback state in casting scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { avSession } from '@kit.AVSessionKit';
```