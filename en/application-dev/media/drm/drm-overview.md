# Introduction to DRM Kit

You can call the APIs provided by Digital Rights Management Kit (DRM Kit) to decrypt DRM-protected audio and video content and manage DRM certificates and media keys on devices.

## Available Capabilities
- Decryption and playback: provides unified audio and video decryption capabilities, which enable audio and video applications to play DRM-protected content after integrating with DRM.

- DRM scheme support: supports various DRM schemes.

- Online certificate download: supports device certificate requests and settings.

- Online/Offline media key authorization: supports online media key requests and settings, and offline media key requests, loading, updates, deletion, and status query.

## Features

- Media key and decryption session management

  DRM Kit supports multiple sessions, allows users to request and set media keys in sessions, and binds decryption sessions to media keys.

- Secure and non-secure video channels

  DRM Kit supports secure video channels with encrypted memory calls and decoding. It also supports non-secure channels with non-encrypted memory calls and decoding.

## Basic Concepts
Be familiar with the following basic concepts before development:

- DRM scheme (DRM plugin)

  Below the DRM framework layer, there are drivers that implement the DRM Hardware Device Interface (HDI) layer. Content decryption is implemented in the drivers.

- DRM session (MediaKeySession)

  DRM sessions are used for media key management and media decryption. Their lifecycle are managed by DRM instances (MediaKeySystem).

## Development Model

Specific DRM implementation manners and technical details vary according to the types of the content, protection requirements, and use scenarios.

The DRM working process can be summarized into three parts: device certificate management, media key management, and decryption management.

- After creating a DRM instance, the client creates a DRM decryption session. If the client detects that the device does not have a device DRM certificate or the certificate is abnormal, it starts the online certificate download process.

- After the certificate is downloaded, the client creates a DRM decryption session and generates a media key request. The client obtains the response to the media key request from the server and sets it on the device. There are online and offline media keys. You can obtain the IDs of media keys, check their status, and clear them.

- The client sets the decryption configuration to decrypt the content.

The figure below illustrates the DRM development model for you to better develop applications with digital rights protection.

**Figure 1** DRM development model

![Drm Development Model](figures/drm-development-model.png)

The player application calls DRM APIs to implement basic operations such as device certificate management, media key management, and decryption management. To implement these basic operations, you need to create a DRM instance and request and set a device certificate. Then, you need to create a session instance and request and set a media key. When an encrypted stream arrives, the player application sends it to a specific DRM plugin for decryption through the bottom-layer HDI.
