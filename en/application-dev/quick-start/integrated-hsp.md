# Integrated HSP

The integrated HSP is an intermediate build product of the intra-app HSP. It aims to solve the strong coupling between the bundle name and signature of the user.
> **NOTE**
> The HSP can be used only by projects with the same bundle name, but the integrated HSP can be used by projects with different bundle names.

## Development Instructions
1. Project configuration for creators: Normalized OHMUrl format should be used in the integrated HSP. Creator needs to modify the project-level build configuration file **build-profile.json5** and set **useNormalizedOHMUrl** to **true** to enable the normalized OHMUrl format.

    ```json
    // created_party_project/build-profile.json5
    {
      "app": {
        "products": {
          "name": "default",
          "signingConfig": "default",
          "compatibleSdkVersion": "5.0.0(12)",
          "runtimeOS": "HarmonyOS",
          "buildOption": {
            "strictMode": {
              "useNormalizedOHMUrl": true
            }
          }
        }
      }
    }
    ```
2. Module configuration for creators: Modify the module-level build configuration file **build-profile.json5** and set **integratedHsp** to **true** to specify the HSP module to be built as the integrated HSP module.

    ```json
    // created_party_project/library/build-profile.json5
    {
      "apiType": "stageMode",
      "buildOption": {
        "arkOptions": {
          "integratedHsp": true
        }
      }
    }
    ```

3. Packing configuration for creators (.tgz Package)

    3.1 Configure project signature information. For details, see [Application/Service Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-signing-0000001587684945-V5).

    3.2 Configure the release mode.

    ![](./figures/ide-release-setting.png)

    3.3 Select the **library** directory in **Build** -> **Make Module 'library'**.

4. Project dependency configuration for users: Add dependencies to the **oh-package.json5** configuration file in the main module.

    ```json
    // user_project/entry/oh-package.json5
      "dependencies": {
        "hsp": "./lib/library-default.tgz"
      }
    ```

5. Project configuration for users: Normalized OHMUrl format should be used in the integrated HSP. User needs to modify the project-level build configuration file **build-profile.json5** and set **useNormalizedOHMUrl** to **true** to enable the normalized OHMUrl format.

    ```json
    // user_project/build-profile.json5
    {
      "app": {
        "products": {
          "name": "default",
          "signingConfig": "default",
          "compatibleSdkVersion": "5.0.0(12)",
          "runtimeOS": "HarmonyOS",
          "buildOption": {
            "strictMode": {
              "useNormalizedOHMUrl": true
            }
          }
        }
      }
    }
    ```
    > **NOTE**
    > Before installing and running an application, the user must configure the project signature information. For details, see [App/Service Signature](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-0000001587684945-V5).
