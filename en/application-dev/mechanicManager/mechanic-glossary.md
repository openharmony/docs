# Glossary

<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @qxqxqxqxqx-->
<!--Designer: @peter__1024-->
<!--Tester: @Aullar-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=953ab2487fbf59eda3ae970f50e53e1f5b96792d translatedAt=2026-08-15T11:13:12.404Z pushedAt=2026-08-15T11:40:39.077Z -->

## C

### Camera Tracking

A feature that uses a camera to identify a target and automatically controls the rotation of a mechanical body device to keep the target in the frame. It supports enabling or disabling control and layout settings, and is used to implement intelligent tracking scenarios.

## G

### Gimbal Device

A portable three-axis stabilized rotating platform mechanic device that can carry a camera to achieve stable shooting and intelligent tracking.

## M

### Mechanic Device

An intelligent hardware device (such as a gimbal) that connects to a host over Bluetooth and receives rotation control commands, used with a camera to achieve stable shooting and target tracking.

### Mechanic Kit

A Kit that provides the capability to interact with mechanical body devices, including device connection management, camera tracking control, rotation control, and status listening, for developing apps related to mechanical body devices.

### Mechanic Kit Protocol

A compatibility specification standard between Mechanic Device and Mechanic Kit. A device must comply with this protocol to be recognized and controlled by Mechanic Kit, distinguishing it from Mechanic Kit (the software that implements the specification) and Mechanic Device (the hardware that complies with the specification).

## R

### Rotation Axis

The degrees of freedom of the rotational motion of Mechanical Body Settings, including the yaw, roll, and pitch axes. Each axis can be independently enabled or disabled and has its own limit state, for describing and controlling the spatial rotation capability of the device.

### Rotation Axis Limit

The runtime state in which a rotation axis has reached its maximum rotation angle in a certain direction, including three cases: unlimited, limited in the negative direction, and limited in the positive direction. It is used to determine whether the device can continue rotating in that direction. Distinguished from the rotation angle limit (a static constraint specification), it emphasizes the current limited state of the axis.