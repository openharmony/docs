# User Authentication Overview

OpenHarmony provides biometric recognition that can be used for identity authentication in device unlocking, application login, and payment.

OpenHarmony provides both 2D and 3D facial recognition. You can provide either or both of them on your device based on the hardware and technology applied on the device. 3D facial recognition is superior to 2D facial recognition in terms of recognition rate and anti-counterfeiting capability. However, you can use 3D facial recognition only if your device supports capabilities such as 3D structured light and 3D Time of Flight \(TOF\).

## Basic Concepts

Biometric recognition \(also known as biometric authentication\) uses optical, acoustical, and biological sensors, as well as the biological statistics mechanism to identify individuals.

Facial recognition is a biometric recognition technology that identifies individuals based on facial characteristics. A camera is used to collect images or video streams that contain human faces, and automatically detect, track, and recognize the human faces.

## Working Principles

Facial recognition establishes a secure channel between a camera and a trusted execution environment \(TEE\). Through this channel, face image data is transmitted to the TEE. This protects against any attack from the rich execution environment \(REE\) as the face image data cannot be obtained from the REE. The face image collection, characteristic extraction, alive human body detection, and characteristic comparison are all completed in the TEE. The TEE implements security isolation based on the trust zone. The external face framework only initiates face authentication and processes authentication results. It does not process the human face data.

Facial characteristics are stored in the TEE, which uses strong cryptographic algorithms to encrypt and protect the integrity of facial characteristics. The collected and stored facial characteristics will not be transferred out of the TEE without user authorization. This ensures that system or third-party applications cannot obtain facial characteristics, or send or back them up to any external storage medium.

## Constraints

-   OpenHarmony only supports facial recognition and local authentication, and does not support an authentication UI.
-   To use biometric recognition, a device must have a camera with a face image pixel greater than 100x100.
-   The device must have a TEE, where encrypted facial characteristics are stored.
-   Facial recognition may not work for people with similar looks and children whose facial features keep changing. If you are concerned about this, consider using other authentication modes.

