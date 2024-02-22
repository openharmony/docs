# Introduction to DRM Kit

Digital Rights Management Kit (DRM Kit) provides APIs for you to implement basic digital rights protection, such as device certificate management, media key management, and decryption, in your player applications. It also enables you to perform more operations such as software security decryption and hardware security decryption.

## Development Model

DRM is a way to protect copyrights for digital content. It contains the following key steps:

- Content encryption: encrypts digital content to prevent unauthorized access and replication.
- Key management: manages and allocates keys to ensure that only authorized users can access and decrypt content.
- Identity authentication: verifies the identity of a user to ensure that the user has the permission to access and use content.
- Content verification: verifies the integrity and source of the content to ensure that it is not modified or copied without authorization.
- Scheme management: manages and implements DRM schemes, including license agreements, terms of use, and liabilities for breach of contract.

Specific DRM implementation manners and technical details vary according to the types of the content, protection requirements, and use scenarios.

The DRM working process can be summarized into three parts: device certificate management, media key management, and decryption management.

- Device certificate management: Device certificates and private keys are released to the provisioning server. Before the device obtains a media key to play DRM-protected content, the DRM plug-in checks the device certificate locally. If no device certificate exists or the certificate is abnormal, the DRM plug-in throws an exception and starts online certificate download.

- Media key management: After processing the response to a provision request, the player application creates a media key request. The license server returns a response to the player application, which sends the response to the DRM plug-in for parsing. There are online and offline media keys. You can obtain the IDs of media keys, check their status, and clear them.

- Decryption management: The player application creates a DRM session, sets the session object to the decoder, and obtains a decryption object. The decryption object supports basic content decryption operations, including creating and destroying a decrypter, querying whether a secure decoder is required to decode data of a specified MIME type, and decrypting the content.

The figure below illustrates the DRM development model for you to better develop applications with digital rights protection.

**Figure 1** DRM development model 
![Drm Development Model](figures/drm-development-model.png)

The player application calls DRM APIs to implement basic operations such as device certificate management, media key management, and decryption management. To implement these basic operations, you need to create a **MediaKeySystem** instance and request and set a device certificate. Then, you need to create a **MediaKeySession** instance and request and set a media key. When an encrypted stream arrives, the player application sends it to a specific DRM plug-in for decryption through the bottom-layer Hardware Device Interface (HDI).
