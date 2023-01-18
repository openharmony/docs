# hapsigner Overview

To ensure the integrity and secure source of OpenHarmony applications, the applications must be signed during the build process. Only signed applications can be installed, run, and debugged on real devices. [developtools_hapsigner](https://gitee.com/openharmony/developtools_hapsigner) provides the source code of the OpenHarmony Ability Package (HAP) signing tool - hapsigner. This tool can be used to generate key pairs, certificate signing requests (CSRs), certificates, profile signatures, and HAP signatures.

> **NOTE**<br>For applications that do not need to apply for permissions using the ACL, DevEco Studio provides an auto signing solution to implement one-click signing of applications or services. For details, see [Having Your App Automatically Signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465).

## Basic Concepts

The hapsigner tool is implemented based on the Public Key Infrastructure (PKI). Before using this tool, you should understand the following concepts:

 - Asymmetric key pair

   The asymmetric key algorithm is the basis of data signature and signature verification. The hapsigner tool can generate standard asymmetric key pairs, including ECC P384/256 and RSA 2048/3072/4096.

 - CSR

   The CSR contains the public key, subject, and private key signature of a certificate. Before applying for a certificate, you must generate a CSR based on the key pair and submit the CSR to the Certificate Authority (CA).

 - Certificate

   OpenHarmony uses the RFC5280 standard to build the X.509 certificate trust system. The OpenHarmony certificates used for application signatures are classified into the root CA certificate, intermediate CA certificate, and end-entity certificate (application or profile signing certificate). The application signing certificate indicates the identity of the application developer, which ensures the traceability of the source of the applications. The profile signing certificate is used to verify the signature of the profile, which ensures the integrity of the profile.

 - HAP

   HAP is a package used to deploy an ability, which is the basic unit for OpenHarmony application development. An OpenHarmony application consists of one or more abilities.

 - Profile

   [HarmonyAppProvision configuration file](app-provision-structure.md) provides information such as the authorized application permissions and device ID.

## Constraints

 - hapsigner is developed in Java and must run in JRE 8.0 or later.

 - The scripts, such as the one-click signature script, are developed in Python, and must run on Python 3.5 or later.
