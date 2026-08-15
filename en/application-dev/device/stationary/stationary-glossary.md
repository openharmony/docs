# Glossary

<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=65888785f8f628e8f5056f5b8268fadd3dfeb466 translatedAt=2026-08-15T01:46:58.733Z pushedAt=2026-08-15T06:59:42.265Z -->

## H

### Holding Hand

The hand currently holding the device. You can subscribe to holding hand state change events through the motion awareness module to obtain this information. This capability identifies how the user holds the device (for example, with the left hand or the right hand), and the recognition result is affected by factors such as the holding posture, contact area, and whether gloves are worn.

## M

### Metadata Binding

The memory link (metadata binding) feature is used to associate and save the content the user is currently browsing (such as a page screenshot) with the HarmonyOS App Linking link provided by a third-party app. When the user browses the same content again, the system parses the bound metadata and prompts the user to jump to the corresponding third-party app to view details.

### Motion Awareness

The motion awareness module provided by the system for apps. It identifies how users operate the device through sensors and provides motion awareness capabilities such as the operating hand and holding hand, used to perceive device states, recognize user behaviors, and optimize the interaction experience. To use this module, an app must apply for the corresponding permissions.

### Multimodal Awareness

One of the basic service capabilities provided by the system for apps. This capability comprehensively uses multiple types of sensor data on the device (such as accelerometer and gyroscope data), performs fusion computation on multi-source awareness data, identifies the user's motion state (such as stationary, walking, running, and riding in a vehicle) and device posture (such as lying flat and held upright), and reports the awareness results to the app.

## O

### Operating Hand

The hand currently operating the device screen. You can subscribe to operating hand state change events through the motion awareness module to obtain this information. This feature identifies whether the user operates the screen with the left or right hand.

## S

### Stationary Awareness

A device stationary awareness module provided by the system for apps. This module supports subscribing to entry and exit events of device stationary states such as absolute stationary and relative stationary, and reports the results to apps when the state changes.

### steadyStanding

A device state in which the device is stationary and the angle between the screen and the horizontal plane is between 45 and 135 degrees. For a foldable phone, this state requires the device to be folded or fully unfolded. This state is commonly used in scenarios such as landscape placement for viewing. You can obtain it by subscribing to device stationary posture awareness events.