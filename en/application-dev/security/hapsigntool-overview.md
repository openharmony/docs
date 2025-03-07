# hapsigner Overview

The OpenHarmony apps and debug tools must be signed to ensure their integrity and trusted source. Only signed apps and debug tools can be installed, run, debugged, and used on devices. [developtools_hapsigner](https://gitee.com/openharmony/developtools_hapsigner) provides the source code of the signing tool hapsigner, including the code for generating a key pair, a certificate signing request (CSR), a certificate, and signing a profile, an app package, and a debug tool.

The mandatory code signing mechanism provides validity check and integrity protection for apps in runtime, eliminating execution of malicious code on devices and tampering of app code by attackers.

Code signing is enabled by default for hapsigner. If you do not need the mandatory code signing feature, you can disable it as required. Currently, hapsigner can be used to sign binary tools and app packages in .hap, .hsp, and .hqf formats only.

> **NOTE** 
>
> For the apps that do not need to apply for permissions via the ACL, DevEco Studio provides an auto signing solution to implement one-click signing of apps/services. For details, see [Having Your App Automatically Signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465).

## Basic Concepts

The hapsigner tool is implemented based on the Public Key Infrastructure (PKI). Before using this tool, you need to understand the following concepts:

 - Asymmetric key pair

   The asymmetric key algorithm is the basis of data signing and signature verification. The hapsigner tool can generate standard asymmetric key pairs, including ECC P384/256 and RSA 2048/3072/4096.

 - CSR

   The CSR contains the public key, subject, and private key signature of a certificate. Before applying for a certificate, you must generate a CSR based on the key pair and submit the CSR to the Certificate Authority (CA).

 - Certificate

   OpenHarmony uses the RFC5280 standard to build the X.509 certificate trust system. The OpenHarmony certificates used for app signing are classified into the root CA certificate, intermediate CA certificate, and entity certificate (app or profile signing certificate). The app signing certificate indicates the identity of the app developer, which ensures the traceability of the source of the apps. The profile signing certificate is used to verify the signature of the profile, which ensures the integrity of the profile.

 - HAP

   A Harmony Ability Package (HAP) is used to deploy an ability, which is the basic unit for OpenHarmony app development. An OpenHarmony app consists of one or more abilities.

 - HSP

   A Harmony Shared Package (HSP) is a dynamic shared package. HSPs can be classified as intra-app HSPs and inter-app HSPs.

 - HQF

   A Harmony Ability Package Quick Fix (HQF), installed on a device, is used to quickly fix HAP problems.

 - Debug tool

   A toolchain that provides C++ debugging, for example, [LLDB](https://gitee.com/openharmony/docs/blob/master/en/application-dev/tools/lldb-tool.md).

 - Profile

   A [HarmonyAppProvision configuration file](app-provision-structure.md) in an app package provides information such as the authorized app permissions and device ID.

## Constraints

 - The hapsigner tool is developed in Java and C++. The tool in Java must run on JRE 8 or later. The tool in C++ must run on an OpenHarmony standard system with C++ 17 or later.

 - The scripts for one-click signing (available only for the tool in Java) are written in Python and must run on Python 3.5 or later.
