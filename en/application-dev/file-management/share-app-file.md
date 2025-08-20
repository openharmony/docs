# Sharing an Application File

An application can share a file with another application based on the uniform resource identifier (URI) of the file.

## Using startAbility to Start a File Application

[startAbility](../application-models/file-processing-apps-startup.md)-based file sharing: You can use [wantConstant.Flags](../reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) to specify the read or read/write permission on the file for the target application (application with which the file is shared). The target application can call [fs.open](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopen) to open the file based on the URI and perform read and write operations.

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

