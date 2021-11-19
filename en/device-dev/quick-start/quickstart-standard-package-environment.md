# Setting Up a Ubuntu Development Environment Using the Installation Package<a name="EN-US_TOPIC_0000001119804790"></a>

-   [Installing Dependent Tools](#section18431165519244)
-   [Obtaining Standard-System Source Code](#section113751052102517)
    -   [Prerequisites](#section102871547153314)
    -   [Procedure](#section429012478331)

-   [Running prebuilts](#section0495320152619)
-   [Building Source Code](#section1664835963517)

## Installing Dependent Tools<a name="section18431165519244"></a>

The installation command is as follows:

```
sudo apt-get update && sudo apt-get install binutils git git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 bc gnutls-bin python3.8 python3-pip ruby
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, modify the preceding installation command based on the installation package name. Python 3.7 or later is required. Python 3.8 is used as an example.

## Obtaining Standard-System Source Code<a name="section113751052102517"></a>

### Prerequisites<a name="section102871547153314"></a>

1.  Register your account with Gitee.
2.  Register an SSH public key for access to Gitee.
3.  Install the  [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)  and  [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure basic user information.

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  Run the following commands to install the  **repo**  tool:

    ```
    curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the access permission to this directory, download the tool to any other accessible directory and configure the directory to the environment variable.
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


### Procedure<a name="section429012478331"></a>

Two methods are provided for you to obtain the OpenHarmony master code. You are advised to create a new folder and run the related commands in this folder to download the source code. This folder will then be the root directory of the source code.

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## Running prebuilts<a name="section0495320152619"></a>

Go to the root directory of the source code and run the following script to install the compiler and binary tool:

```
bash build/prebuilts_download.sh
```

By default, the downloaded prebuilts binary file is stored in  **OpenHarmony\_2.0\_canary\_prebuilts**  \(which is in the same directory as  **OpenHarmony**\).

## Building Source Code<a name="section1664835963517"></a>

Perform the following operations in the Linux environment:

1.  Go to the root directory of the source code and run the following command to build the distribution.

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the product supported by the current distribution, for example,  **Hi3516DV300**.

2.  Check the build result. After the build is complete, the following information is displayed in the log:

    ```
     build system image successful.
    =====build Hi3516DV300 successful.
    ```

    Files generated during the build are stored in the  **out/{device_name}/**  directory, and the generated image is stored in the  **out/{device_name}/packages/phone/images/**  directory.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >For details about module-specific build operations, see  [Building Guidelines](../subsystems/subsys-build-standard-large.md).

3.  Burn the image. For details, see  [Burning Images](quickstart-standard-burn.md).

