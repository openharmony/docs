# User IAM Subsystem

- [Introduction](#Introduction)
- [Directory Structure](#Directory-Structure)
- [Constraints](#Constraints)
- [Usage](#Usage)
    - [How to Use](#How-to-Use)
- [Repositories Involved](#Repositories-Involved)


## Introduction

The user identity and access management (IAM) subsystem provides a unified framework for user credential management and user identity authentication in OpenHarmony. It allows multiple users to set their own authentication credential information and authenticates their identities based on the information set. This subsystem is widely used in security-sensitive scenarios such as screen lock. The subsystem also provides APIs for third-party developers to call the identity authentication capabilities to control user access.

**Figure 1** Subsystem architecture

<img src="figures/User-IAM-subsystem-architecture.png" alt="User IAM subsystem architecture" style="zoom:80%;" />

The user IAM subsystem consists of the unified user authentication framework and authentication executor. The unified user authentication framework consists of the following parts:

- Unified user authentication: provides unified user identity authentication externally and provides open biometric authentication capabilities for third-party applications to invoke.
- User credential management: provides a unified user credential information management interface for the upper layer and invokes authentication resources in the system through the authentication executor management part to implement lifecycle management and secure storage of user credentials.
- Authentication executor management: provides authentication resource management and authentication session management, and supports unified management, scheduling, and connection of various authentication executors in the system.

Based on the unified user authentication framework, the system can be extended to support multiple authentication capabilities. Currently, the authentication executors supported by OpenHarmony are password and facial authentication. To implement a new authentication executor, you only need to implement authentication capabilities in a new part and connect the new part to the unified user authentication framework based on the interfaces defined by the authentication executor management part.

*Note: In the user IAM subsystem, an authentication executor is the minimum execution unit of a user identity authentication operation. For example, a password authentication module is responsible for password collection, password processing and comparison, and secure storage, and therefore it can be abstracted as a password authentication executor.*

## Directory Structure


```undefined
//base/user_iam
├── auth_executor_mgr	# Authentication executor management part, which supports unified authentication resource management and scheduling
├── face_auth			# Facial authentication module, which connects to the authentication executor management part and supports facial information recording, deletion, and verification
├── pin_auth 			# Password authentication module, which connects to the authentication executor management part and supports password recording, deletion, and verification
├── user_auth			# Unified user authentication part
└── user_idm 			# User credential management part

```

## Constraints

1. User credential management is a key operation in the system, and interfaces used for user credential management can be invoked only by basic system applications.
2. The authentication executors process user authentication credentials and their capabilities can only be implemented by system services for interconnection with the authentication executor management part.

## Usage

### How to Use

1. The unified user authentication framework must work with an authentication executor.
2. The first default authentication executor in the system must be password authentication.

## Repositories Involved

[useriam_auth_executor_mgr](https://gitee.com/openharmony-sig/useriam_coauth)

[useriam_user_idm](https://gitee.com/openharmony-sig/useriam_useridm)

[useriam_user_auth](https://gitee.com/openharmony-sig/useriam_userauth)

[useriam_pin_auth](https://gitee.com/openharmony-sig/useriam_pinauth)

[useriam_faceauth](https://gitee.com/openharmony/useriam_faceauth)
