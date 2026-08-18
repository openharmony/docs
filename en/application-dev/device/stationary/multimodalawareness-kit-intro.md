# About This Kit

<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=21c92f0c1bb5bce8b0b255803845ef148366250d translatedAt=2026-08-18T11:01:35.803Z pushedAt=2026-08-18T11:34:31.465Z -->

Multimodal Awareness Kit allows an application to identify user activities (walking, running, driving, etc.) or postures based on the data collected by sensors including gyroscopes and acceleration sensors built in a HarmonyOS device.

## How Multimodal Awareness Kit Works

Multimodal Awareness Kit is offered by the system as a basic service for applications. Depending on the service scenario, an application needs to initiate a subscription request to the system and cancel the subscription when the service scenario ends. In this process, the system reports the device status information to the application on a real-time basis.

## Constraints

Using multimodal awareness capabilities requires your application to request the relevant permissions from the user. The device must support the sensors required for the intended capabilities.

<!--RP1-->

### Emulator Support

This Kit does not support the Emulator.

<!--RP1End-->