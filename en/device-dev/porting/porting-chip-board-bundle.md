# Third-party Module Adaptation<a name="EN-US_TOPIC_0000001153842842"></a>

To use third-party modules in the  **third\_party**  directory, you may need to adapt the modules. This section uses mbedTLS as an example to describe how to integrate the adaptation code with the OpenHarmony compilation framework. For the principles of mbedTLS and the specific logic of the adaptation code, see the adaptation guide on the mbedTLS official website.

1.  <a name="li12446195633211"></a>Write the adaptation layer code.

    Write the required adaptation layer code based on the mbedTLS adaptation guide. In this example, adaptation of the hardware random number is used for illustration, and the paths are relative to  **third\_party/mbedtls**:

    1.  Copy the  **include/mbedtls/config.h**  file to the  **ports**  directory, and enable  **MBEDTLS\_ENTROPY\_HARDWARE\_ALT**  in the file.
    2.  In the  **ports**  directory, create the  **entropy\_poll\_alt.c**  file under  **include**  and implement the hardware random number API in  **entropy\_poll.h**.
    3.  Add the path of the adapted  **entropy\_poll\_alt.c**  file to  **mbedtls\_sources**  in the  **BUILD.gn**  file.
    4.  Add the line  **MBEDTLS\_CONFIG\_FILE**  to  **lite\_library\("mbedtls\_static"\)**  in the  **BUILD.gn**  file to specify the path of the new configuration file.

        ```
        lite_library("mbedtks_static") {
          ...  
          defines += ["MBEDTLS_CONFIG_FILE=<../port/config.h>"]
          ...
        }
        ```

    You are advised to make the preceding modifications in a new  **config.h**  file or  **_xxx_\_alt.c**  file. Do not directly edit the code in the original file. Intrusive modifications may cause a large number of scattered conflicts during subsequent version updates, increasing the update maintenance costs.

2.  Create a patch.

    The preceding adaptation is hardware-specific. Therefore, when uploading code to the library, you cannot directly store the code in the  **third\_party/mbedtls**  directory. Instead, you need to integrate the preceding modifications into a patch and inject the patch into the code for a build.

    1.  Add the patch configuration file  **device/<_company_\>/<_board_\>/patch.yml**.
    2.  In the  **device/<_company_\>/<_board_\>/patch.yml**  file, add the information about the patch to apply.

        ```
        # Path of the patch to apply. This path is relative to the code root directory.
        third_party/mbedtls:
          # Directory in which the patch is stored.
          - device/<company>/<board>/third_party/mbedtls/adapter.patch
        third_party/wpa_supplicant:
          # When there are multiple patches in a path, the patches are executed in sequence.
          - device/<company>/<board>/third_party/wpa_supplicant/xxxxx.patch
          - device/<company>/<board>/third_party/wpa_supplicant/yyyyy.patch
        ...
        ```

    3.  Create a patch file as described in step  [1](#li12446195633211)  and save it to the corresponding directory.

3.  Start a build with the patch.

    Add  **--patch**  when triggering a build. The following is the command for executing a full build with a patch:

    ```
    hb build -f --patch
    ```

    >![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
    >The information about the product to which the patch is most recently applied will be recorded. Next time the build is performed, the previous patch is rolled back \(that is,  **\`patch -p1 -R < xxx\`**  is executed\). If the patch fails to be rolled back or a patch fails to be added, the build process is terminated. In this case, resolve the patch conflict and try again.


