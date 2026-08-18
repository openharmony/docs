# Application Package Glossary

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e614db0ed9ef9e65ff9f340640f4a0fd5317e78d translatedAt=2026-08-13T08:49:51.005Z pushedAt=2026-08-13T11:44:37.480Z -->

## A

### APP

When an app is released to an app marketplace, it must be packaged into a file with the .app file extension for release. This .app file is called an App Pack (Application Package), which contains all HAP and HSP files of the app as well as the pack.info description file, and serves as the basic unit for release.

## B

### Bundle

The collection of all HAP and HSP files in an app. Its bundleName is the unique identifier of the app. A Bundle is packaged into an App Pack before being released to an app marketplace.

### Bundle Manager (bm)

A command-line tool for app package management. It supports operations such as installing, uninstalling, and querying apps.

## E

### Entry UIAbility

A UIAbility whose entities under the skills tag contain `"entity.system.home"` and whose actions contain `"ohos.want.action.home"`. It serves as the entry component of an app.

## H

### Harmony Ability Package (HAP)

The basic unit for app installation and running. A HAP file contains all content of an app, including code, resources, third-party libraries, and configuration files, with the .hap file extension. It is classified into entry and feature types and supports independent installation and running.

### Harmony Archive (HAR)

A static shared package used for reuse in the compilation state. It can contain code, C++ libraries, resources, and configuration files, with the .har file extension, and is used to share code and resources. It supports sharing within an app and can also be published to OHPM for use by other apps. However, referencing it from multiple packages causes duplicate copies of code and resources.

### Harmony Shared Package (HSP)

A dynamic shared package reused during runtime. It can contain code, C++ libraries, resources, and configuration files, with the .hsp file extension, and is used to share code and resources. Referencing it from multiple packages does not cause duplicate copies, effectively controlling the app package size.

## I

### Integrated HSP

An intermediate compilation artifact of an in-app HSP, used to resolve the strong coupling between the consumer's `bundleName` and the signature. During build and release, it is not coupled with a specific app bundle name. The toolchain supports automatically replacing the bundle name of the integrated HSP with that of the host app.

## M

### Module

A part of an app. Each module has an independent module.json5 configuration file. In a project, Entry, Feature, HSP, and HAR are all app modules and support independent compilation and feature implementation.

## S

### Static Library

A Library-type module that generates a HAR file after compilation. Its code and resources are compiled along with the consumer and reused in the compilation state.

### Shared Library

A Library-type module that generates an HSP file after compilation. Its code and resources can be compiled independently and reused by multiple modules while the app is running. <!--Del-->

### System-level HSP

An HSP preset in the system by the OEM. As the underlying implementation of Kits, it is indirectly depended on by third-party applications and runs in the third-party process space.

<!--DelEnd-->