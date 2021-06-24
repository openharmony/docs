# Preparing the Ubuntu Build Environment<a name="EN-US_TOPIC_0000001161257591"></a>

-   [Method 1: Setting up an Ubuntu Build Environment Using a Docker Environment](#section1643363843714)
    -   [Obtaining Standard-System Source Code](#section58448331029)
    -   [Installing and Using the Docker Environment](#section22916211916)

-   [Method 2: Setting up an Ubuntu Build Environment Using an Installation Package](#section25961010189)
    -   [Installing Dependent Tools](#section109262032104819)
    -   [Obtaining Standard-System Source Code](#section6325556113718)
    -   [Obtaining prebuilts](#section16453104219209)


You can use either the Docker environment or installation package provided by OpenHarmony to set up an Ubuntu build environment. This section describes the two methods.

## Method 1: Setting up an Ubuntu Build Environment Using a Docker Environment<a name="section1643363843714"></a>

The standard OpenHarmony system provides a Docker environment which encapsulates build tools. To use the Docker environment, perform the following steps:

1.  Obtain the standard-system source code.
2.  Install and use the Docker environment.

### Obtaining Standard-System Source Code<a name="section58448331029"></a>

Obtain the  [standard-system source code](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary.tar.gz). The obtained source code is the static code. If you want to obtain the latest source code from Gitee, use  [repo](../get-code/source-code-acquisition.md).

### Installing and Using the Docker Environment<a name="section22916211916"></a>

For details, see  [Installing and Using Docker](../get-code/tool-acquisition.md).

## Method 2: Setting up an Ubuntu Build Environment Using an Installation Package<a name="section25961010189"></a>

The procedure is as follows:

1.  Install dependent tools.
2.  Obtain the standard-system source code.
3.  Obtain prebuilts.

### Installing Dependent Tools<a name="section109262032104819"></a>

The installation command is as follows:

```
sudo apt-get install binutils git-core git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 
```

>![](public_sys-resources/icon-caution.gif) **CAUTION:** 
>The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, use the corresponding installation commands based on the installation package name. If the Ubuntu version is later than 18.04, Python 2.7 and python-minimal must be installed.

### Obtaining Standard-System Source Code<a name="section6325556113718"></a>

Obtain the  [standard-system source code](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary.tar.gz). The obtained source code is the static code. If you want to obtain the latest source code from Gitee, use  [repo](../get-code/source-code-acquisition.md).

### Obtaining prebuilts<a name="section16453104219209"></a>

1.  Go to the OpenHarmony working directory.

    ```
    cd OpenHarmony
    ```

2.  Execute the following script:

    ```
    build/prebuilts_download.sh
    ```

    By default, the downloaded prebuilts binary file is stored in  **OpenHarmony\_2.0\_canary\_prebuilts**  \(which is in the same directory as  **OpenHarmony**\).


