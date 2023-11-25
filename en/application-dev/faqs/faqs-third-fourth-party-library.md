# Usage of Third- and Fourth-Party Libraries

## Which third-party libraries can be used to implement bridge between ArkTS and C/C++ code during native development? (API version 10)

**Solution**

The Alpha Kernel Interacting (AKI) framework can be used.

**References**

[AKI Project Introduction](https://gitee.com/openharmony-sig/aki)


## How do I obtain available third-party libraries? (API version 9)

The three-party and four-party libraries that can be obtained through ohpm are summarized in the [OpenHarmony-TPC/tpc_resource repository](https://gitee.com/openharmony-tpc/tpc_resource). You can access this repository, and find the desired component based on the directory index.

## Which third-party libraries are related to network requests?

Applicable to: OpenHarmony 3.1 Beta5 (API version 9)

The following third-party libraries are related to network requests: [Axios](https://gitee.com/openharmony-sig/axios), httpclient, and okdownload. For details, see the [OpenHarmony-TPC/tpc_resource repository](https://gitee.com/openharmony-tpc/tpc_resource).

## How do I use ohpm to import third- and fourth-party libraries? (API version 9)

**Solution**

-   Method 1:
    1.  Open the **Terminal** window and run the following command to go to the **entry** directory:

        ```
        cd entry
        ```

    2.  Run the following command to install a third-party library, for example, **dayjs**:

        ```
        ohpm install dayjs
        ```

    3.  Add the following statement in the .js file to import the third-party library:

        ```
        import dayjs from 'dayjs'; 
        ```


-   Method 2:
    1.  Enter the **entry** directory of the project and open the **oh-package.json5** file.
    2.  Write the third-party library to be installed (for example, **dayjs**) in the **oh-package.json5** file.

        ```
        {
          "dependencies": {
            "dayjs": "^1.10.4",
          }
        }
        ```

    3.  Open the **Terminal** window and run the following command to go to the **entry** directory:

        ```
        cd entry
        ```

    4.  Run the following command to install the third-party library:

        ```
        ohpm install
        ```

    5.  Add the following statement in the .js file to import the third-party library:

        ```
        import dayjs from 'dayjs'; 
        ```
