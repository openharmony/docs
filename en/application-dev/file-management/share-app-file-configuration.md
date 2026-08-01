# Configuring the Application Shared Directory

<!--Kit: Core File Kit-->
<!--Subsystem: Security-->
<!--Owner: @renzehua-->
<!--Designer: @renzehua; @huangjieliang; @zhanganxiang-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=eea7130fde34aad89d99ea1779662114cbb1a92c translatedAt=2026-08-01T07:29:31.152Z pushedAt=2026-08-01T11:21:39.191Z -->

From API version 23, the system supports shared directory configuration. In the [app file sharing](share-app-file.md) scenario, you can [configure the shared directory](#configuring-the-shared-directory). After configuration, only files in the shared directory can be shared by users with other apps for viewing, preventing sensitive app data from being leaked. This configuration takes effect only on phones and tablets.

> **NOTE**
>
> Starting from API version 26.0.0, the configurable shared directory scope is expanded. Configure the shared directory based on the latest scope. The following configuration guide applies to version 26.0.0.

Starting from API version 26.0.0, the system supports configuring app-donated sandbox directories. When a shared directory is configured, you can [configure the donated sandbox directory](#configuring-the-donated-sandbox-directory). The donated directory is a subdirectory of the shared directory. After the app configures the donated directory, system apps such as file manager can access and operate on the file data in it.

Take the interaction experience on file manager as an example. After the app configures the donated directory, users can view and modify files in the donated directory through file manager on phones and tablets. This configuration takes effect only on phones and tablets.

## How to Develop

1. Add the **shareFiles** tag to the **module** tag in the application module-level configuration file [src/main/module.json5](../quick-start/module-configuration-file.md) to restrict permissions for sandbox shared directories. If no shared directory is configured, the application is allowed to share files in its own sandbox by default.

   **shareFiles tag**

   ``` JSON5
   {
     "module": {
       // ...
       "shareFiles": "$profile:share_files", // Resource configuration, which points to the configuration file share_files.json defined in the profile.
       // ...
     }
   }
   ```

2. Define the configuration file `share_files.json` in the `resources/base/profile` directory in the development view to specify the permission information of all shared paths in the current module.

   The file name can be changed to one that complies with system naming rules, but it must be consistent with the file name configured in the `shareFiles` tag.

   **Description of the share_files tag**

   | Property| Description| Data Type| Mandatory|
   | -------- | -------- | -------- | -------- |
   | scopes | Scope allowed for sharing. For details, see [Configuring the Shared Directory](#configuring-the-shared-directory). | Array of objects | No |
   | sharingOSPath | Sandbox directory donated by the app to the operating system. For details, see [Configuring the Donated Sandbox Directory](#configuring-the-donated-sandbox-directory). | String | No |
   | sharingOSSubpath | Subdirectory of the sandbox directory donated by the app to the operating system. For details, see [Configuring the Donated Sandbox Directory](#configuring-the-donated-sandbox-directory). | String | No |
   | sharingOSPermission | Access permission for the sandbox directory donated by the app to the operating system. For details, see [Configuring the Donated Sandbox Directory](#configuring-the-donated-sandbox-directory). | String | No |

   > **NOTE**
   >
   > If the configuration is modified during an app update, the new configuration takes effect for management, and temporary shared file permissions remain unaffected.

### Configuring the Shared Directory

   | Name | Description | Type | Mandatory |
   | -------- | -------- | -------- | -------- |
   | path | Shared path configuration. The first level of the path supports el1 to el5 encryption directories, and the second level supports only the following directories:<br/>- `base`<br/>- `distributedfiles`<br/>- `cloud`<br/>For detailed restrictions, see [Path Restrictions](#path-restrictions).<br/>**Since:** 26.0.0 | string | Mandatory when `scopes` is present |
   | permission | Shared path permission. The following values are supported:<br/>- `r`: read-only.<br/>- `r+w`: read-write.<br/>**Since:** 23 | string | Mandatory when `scopes` is present |

### Path Restrictions

1. Path depth restrictions:

   - A single path must be configured with at least 2 levels, for example, `/el2/base`.

   - A single path can be configured with up to 10 levels, for example, `/el2/base/files/level4/level5/level6/level7/level8/level9/level10`.

2. Path quantity restrictions:

   - Configured paths must not be duplicated, and a maximum of 20 paths can be configured.

3. Path format restrictions:

   - The path must start with `/`. The characters `.`, `..`, and `\0` are not allowed, and the path must not end with `/`.

4. Parent-child directory restrictions:

   - When a parent directory is configured, child directories must not be configured.

   - For example, if `/el2/base/parentsA` is configured, `/el2/base/parentsA/childrenA` must not be configured, but `/el2/base/parentsB/childrenB` is allowed.

5. Verification method and locating:

   - To maintain compatibility with earlier system versions, if any path configuration of an app does not comply with the path restrictions, all configured paths of the app are automatically cleared. You can search the system log for related errors using the keyword: "TransAndSetToMapInner failed for bundle".

### Configuring the Donated Sandbox Directory

   When an app needs to donate a sandbox directory to the operating system, fill in the three fields `sharingOSPath`, `sharingOSSubpath`, and `sharingOSPermission` in the configuration file `share_files.json`.

   | Name | Description | Type |
   | -------- | -------- | -------- |
   | sharingOSPath | Sandbox directory donated by the app to the operating system. The value must be a `path` value already configured in the `scopes` list. If this field is not configured, no directory is donated to the operating system, and system apps such as File Manager and FilePicker cannot view the sandbox directory donated by the app.<br/>**Since:** 26.0.0 | String |
   | sharingOSSubpath | Subdirectory of the sandbox directory donated by the app to the operating system. Mandatory only when `sharingOSPath` is configured. The length must not exceed 32 characters. The path formed by concatenating `sharingOSPath` + `sharingOSSubpath` is used as the directory donated to the operating system. An empty string `""` means that `sharingOSPath` is donated directly. If the value contains characters, it must start with `/`. The characters `.`, `..`, and `\0` are not allowed.<br/>**Since:** 26.0.0 | String |
   | sharingOSPermission | Access permission for the sandbox directory donated by the app to the operating system. Mandatory only when `sharingOSPath` is configured. The permission must be a subset of the `permission` of the corresponding path in `scopes` and must not exceed the originally configured permission.<br/>**Since:** 26.0.0 | String |

   Example of **share_files.json**:

   ``` json
   {
     "share_files": {
       "scopes": [
         {
           "path": "/el2/base/files",
           "permission": "r+w"
         },
         {
           "path": "/el3/distributedfiles/files/tmp",
           "permission": "r+w"
         }
       ],
       "sharingOSPath" : "/el2/base/files",
       "sharingOSSubpath" : "/subdir",
       "sharingOSPermission": "r"
     }
   }
   ```