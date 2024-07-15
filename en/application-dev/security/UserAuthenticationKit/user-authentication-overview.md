# Introduction to User Authentication Kit

User Authentication Kit provides the user authentication capabilities based on the lock screen password, facial characteristics, and fingerprint registered with a device.

User Authentication Kit provides system-level identity authentication and a system-level user authentication widget, which provides unified user authentication across devices with diversified authentication modes (facial, fingerprint, and PIN authentication).

Before accessing personal data or performing sensitive operations upon a user request, the application or system service invokes the user authentication widget to authenticate the user identity. The data can be accessed or the sensitive operation can be performed only when the authentication is successful.

User identity authentication can be used in authentication scenarios, such as in-app login and payment.

<!--RP1-->
![en_image_0000001742639520](figures/user_authentication.png)
<!--RP1End-->

## Features

- Unified authentication interface

    Unified APIs are provided to perform user authentication based on the lock screen password, facial characteristics, and fingerprint.

    The same set of APIs provides a combination of facial, fingerprint, and lock screen password authentication modes.

    The same set of APIs provides a combination of facial authentication, fingerprint authentication, and custom authentication.

- Awareness of different authentication trust levels

    The expected authentication trust level can be specified to prevent the use of the lower-security authentication capability (such as the 2D facial authentication) in user authentication scenarios with higher risks (such as payment).

- Support for custom authentication modes

    The authentication page with a navigation button is provided for the user to switch to a page for custom authentication.

- Reuse of the device unlock authentication result within a short period of time

    The system supports reuse of the authentication result within the specified duration (max. 5 minutes) regardless of the authentication mode. This feature eliminates repeated authentication within a given period of time after a successful authentication.

    The system also supports reuse of the authentication result for a specific authentication mode within the specified duration. This feature eliminates repeated authentication of a specific mode within a given period of time after a successful authentication.

- System-level user authentication UX

    The caller can customize the title of the authentication page and the text on the navigation button.

    The user authentication widget automatically adjusts the display mode based on the device screen status.

- Awareness of the change in credential status

    The status of the credentials enrolled by a user can be directly queried or obtained from the authentication and saved. To check whether a user credential is changed, the caller can query the current credential status or obtain the credential status from the current authentication, and compare the credential status obtained with the credential status saved.

## Working Mechanism

The following figure shows the architecture of the unified user authentication framework.

![](figures/unified_auth_architecture.png)

The unified user authentication framework consists of the following:

1. Unified user authentication APIs: provide unified APIs for implementing user authentication capabilities. The APIs shield the differences between authentication modes to simplify your app experience.

2. Unified user authentication framework: consists of authentication SAs and drivers. The framework schedules various identity authentication capabilities and the user authentication widget to complete user authentication requests initiated by services through the unified user authentication APIs.

3. User authentication widget: provides the interaction interfaces for different authentication modes to ensure consistent user authentication experience regardless of the authentication mode.

4. Authentication capabilities: provides capabilities of PIN (password) authentication, facial authentication, and fingerprint authentication for the unified user authentication framework to schedule.

If the user authentication is successful, the unified user authentication framework issues an AuthToken in the trusted execution environment (TEE) of the device.

User authentication can also be used to control the access to the keys in HUKS. For the keys that can be accessed only with user authentication, the application needs to provide a key invocation request with the obtained AuthToken to the [HUKS](../UniversalKeystoreKit/huks-overview.md). After verifying the validity and validity of the AuthToken in the TEE, the HUKS service responds to the service request and performs the related key operation.

### AuthToken Struct

Plaintext

| Name| Content| Type| Description|
| -------- | -------- | -------- | -------- |
| version | Token version| uint32_t | Currently, the token version is 2.0.|
| challenge | Random challenge for authentication| uint8_t[32] | One-off random challenge generated by the service that needs to verify the authentication result.|
| time | Authentication timestamp| uint64_t | Timestamp when the authentication is successful.|
| authTrustLevel | Authentication trust level| uint32_t | See [Authentication Trust Levels](#authentication-trust-levels).|
| authType | Authentication type| uint32_t | Authentication type, which can be facial authentication, fingerprint authentication, or PIN authentication (lock screen password authentication). |
| authMode | Operation type| uint32_t | Identification/authentication. |
| securityLevel | Security level of the token issuing environment | uint32_t | Security level of the environment where the token is issued. |

Ciphertext

| Name| Content| Type| Description|
| -------- | -------- | -------- | -------- |
| userId | User ID| int32_t | ID allocated by the system to a user when the user is created.|
| secureUid | Secure user ID| uint64_t | ID randomly allocated to a user when the user registers the system password. The ID will be deleted when the password is deleted. It remains unchanged when the password is changed.|
| enrolledId | Credential enrollment ID| uint64_t | ID generated each time a credential of this type is enrolled. The ID remains unchanged if the credential is deleted. |
| credentialId | Credential ID| uint64_t | ID of a credential (such as the face or fingerprint) enrolled by the user.|

Tag

| Name| Content| Type| Description|
| -------- | -------- | -------- | -------- |
| tag | Tag of the ciphertext| uint8_t[16] | Tag generated after the ciphertext is encrypted using AES-GCM.|
| iv | Initialization vector (IV) used to encrypt the ciphertext.| uint8_t[12] | Random IV used for AES-GCM encryption.|
| sign | Signature of the AuthToken| uint8_t[32] | Signature used to protect the integrity of the AuthToken.|

### Authentication Trust Levels

The system uses the following metrics to measure the authentication trust level (**AuthTrustLevel**). The following table lists the authentication trust levels supported by the system.

- False Rejection Rate (FRR): percentage of the times that a user is incorrectly rejected by a system.

- False Acceptance Rate (FAR): percentage of times that an imposter is incorrectly accepted by a system.

- Spoof Acceptance Rate (SAR): percentage of times that a non-lived, previously recorded sample is accepted by a system.

The lower the FAR, the higher the FRR. In other words, the more secure the authentication, the lower the ease of the use.

| AuthTrustLevel| Metrics| Description and Example| Application Scenario|
| -------- | -------- | -------- | -------- |
| ATL4 | When FRR = 10%, FAR ≤ 0.001%, SAR ≤ 3%| The authentication can accurately identify individual users and provides powerful liveness detection capabilities. For example, PIN (min. 6 digits) authentication with a secure keyboard and fingerprint or 3D facial authentication with special security hardening.| Small-amount payment|
| ATL3 | When FRR = 10%, FAR ≤ 0.002%, SAR ≤ 7%| The authentication can accurately identify individual users and provides strong liveness detection capabilities. For example, 2D facial authentication with special security hardening.| Device unlocking|
| ATL2 | When FRR = 10%, FAR ≤ 0.002%, 7% < SAR ≤ 20%| The authentication can accurately identify individual users and provides regular liveness detection capabilities. For example, 2D facial authentication using common a camera to collect images.| Maintaining the unlocked state of a device|
| ATL1 | When FRR = 10%, FAR ≤ 1%, 7% < SAR ≤ 20%| The authentication can identify individual users and provides limited liveness detection capabilities. For example, voiceprint authentication.| Service risk control, targeted recommendations, and personalized services|

## Constraints

When a third-party application needs to use the local authentication capability of the system, the built-in user authentication widget must be used.
