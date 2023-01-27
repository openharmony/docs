# User Authentication Overview

## UserAuth Module

The **UserAuth** module provides user authentication capabilities. You can use the APIs provided by this module to authenticate users in scenarios, such as device unlocking, payment, and application logins.

Currently, user authentication comes with facial recognition and fingerprint recognition capabilities. The specific capabilities supported by a device vary depending on the hardware and technology implementation.

## Basic Concepts

- Facial recognition is a biometric recognition technology that identifies individuals based on their facial characteristics. A camera is used to collect images or video streams that contain human faces, and automatically detect, track, and recognize the human faces.

- Fingerprint recognition is a biometric recognition technology that identifies individuals based on fingerprint ridge patterns. When the user places their finger against the fingerprint sensor, the sensor captures the fingerprint image of the user, and transmits it to the fingerprint recognition module for processing, which then compares the fingerprint image with the fingerprint information pre-registered by the user to identify the user identity.

## Working Principles

During facial or fingerprint recognition, the feature collecting device transmits the collected biometrics information to the Trusted Execution Environment (TEE) directly through a secure channel. This security mechanism prevents malware from attacking the Rich Execution Environment (REE). Processing of the biometrics information, from alive human body detection to characteristic extraction, storage, and comparison, is all done in the TEE, where security isolation is implemented based on the trust zone. The service framework that provides APIs only deals with authentication requests and authentication results. It does not process the biometrics information.

Biometrics information is stored in trust zones in a TEE, which uses strong cryptographic algorithms to encrypt and protect the integrity of the information. The collected and stored biometrics information will not be transferred out of the TEE without user authorization. That is, no application can obtain the biometrics information or send it to any external storage medium without user authorization.

## Constraints

- Only facial and fingerprint recognition is currently available and can only be executed on a local device. Moreover, no authentication UI is provided.
- To implement user authentication, a device must have a component for collecting the biometrics information, and the face image must be greater than 100 x 100 pixels.
- The device must have a TEE, where encrypted biometrics information is stored.
- Facial recognition may not work for people with similar looks and children whose facial characteristics keep changing. If you are concerned about this, consider using other authentication modes.
