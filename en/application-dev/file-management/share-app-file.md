# Sharing an Application File

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @gzhuangzhuang-->
<!--Designer: @wang_zhangjun; @chenxi0605-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=db7022f0cb4327ce8c3bb45927411e792eeb9d9a translatedAt=2026-08-01T07:28:36.460Z pushedAt=2026-08-01T11:24:30.790Z -->

An application can share a file with another application based on the uniform resource identifier (URI) of the file.

## Using startAbility to Start a File Application

Based on the sharing method of [file picker (startAbility)](../application-models/file-processing-apps-startup.md), an app can share a single file and grant read-only or read/write permissions to other apps through the [wantConstant.Flags API of ohos.app.ability.wantConstant](../reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags). The receiving app can open the URI through [fileIo.open](../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopen) and perform read/write operations.

## Shareable Application Directories

| Application Sandbox Path                            | Description &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;|
| -------                              |  ---- |
| /data/storage/el1/base               |  Encrypted database directory under **/el1**.|
| /data/storage/el2/base               |  Encrypted database directory under **/el2**.|
| /data/storage/el2/distributedfiles   |  Distributed data directory with an account under **el2/**.|

## File URI Specifications

The file URIs are in the following format:

  file://&lt;bundleName&gt;/&lt;path&gt;

- **file**: indicates a file URI.

- *bundleName*: specifies the owner of the file, that is, the application that shares the file.

- *path*: specifies the application sandbox path of the file.

> **NOTE**
>
> - URI processing involves encoding and decoding. The system cannot guarantee the availability of the URI address that an application combines by itself.
> - You are advised to use the APIs provided by the system to obtain URIs, for example, [getUriFromPath](../reference/apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath).

## Samples

The following sample is available:

- [SandboxShare (ArkTS) (API9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileShare/SandboxShare)