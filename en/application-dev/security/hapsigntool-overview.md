# hapsigner Overview

OpenHarmony applications and debugging tools must be signed to ensure their integrity and trusted source. Only signed applications and debugging tools can be installed, run, and debugged on real devices. [developtools_hapsigner](https://gitee.com/openharmony/developtools_hapsigner) provides the source code of the signing tool hapsigner, including the code for generating a key pair, a certificate signing request (CSR), and a certificate, and signing a profile, a Harmony Ability Package (HAP), and a debugging tool.

Moreover, the hapsigner tool provides code signing, which provides validity check and integrity protection for applications in runtime. It can eliminate execution of malicious code on devices and malicious tampering of application code by attackers. By default, code signing is enabled for the hapsigner tool. You can disable it as required. 

Currently, the hapsigner tool can sign only the applications in .hap format and executable code of debugging tools.

> **NOTE**
>
> For applications that do not need to apply for permissions using the ACL, DevEco Studio provides an auto signing solution to implement one-click signing of applications or services. For details, see [Having Your App Automatically Signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465).

## Basic Concepts

The hapsigner tool is implemented based on the Public Key Infrastructure (PKI). Before using this tool, you need to understand the following concepts:

 - Asymmetric key pair

   A key pair used for signing and signature verification. The hapsigner tool can generate standard asymmetric key pairs, including ECC P384/256 and RSA 2048/3072/4096.

 - CSR

   A file that contains information used to apply for a digital certificate. Before applying for a certificate, you must generate a CSR based on the key pair and submit the CSR to the Certificate Authority (CA).

 - Certificate

   OpenHarmony uses the RFC5280 standard to build the X.509 certificate trust system. The OpenHarmony certificates used for application signatures are classified into the root CA certificate, intermediate CA certificate, and end-entity certificate (application or profile signing certificate). The application signing certificate indicates the identity of the application developer, which ensures the traceability of the source of the applications. The profile signing certificate is used to verify the signature of the profile, which ensures the integrity of the profile.

 - HAP

   A package used to deploy an ability, which is the basic unit for OpenHarmony application development. An OpenHarmony application consists of one or more abilities.

 - Debugging tool

   A toolchain that provides C++ debugging for developers, for example, [LLDB](https://gitee.com/openharmony/docs/blob/master/en/application-dev/tools/lldb-tool.md).

 - Profile

   A [HarmonyAppProvision configuration file](app-provision-structure.md) that provides information such as the authorized application permissions and device ID.

## Constraints

 - hapsigner is developed in Java and must run on JRE 8.0 or later.

 - The scripts, such as the one-click signature script, are developed in Python, and must run on Python 3.5 or later.

