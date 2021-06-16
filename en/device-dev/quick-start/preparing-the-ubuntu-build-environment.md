# Preparing the Ubuntu Build Environment<a name="EN-US_TOPIC_0000001161257591"></a>

-   [Setting up an Ubuntu Build Environment Using a Docker Environment](#section1643363843714)
    -   [Obtaining System Source Code](#section58448331029)
    -   [Installing and Using the Docker Environment](#section22916211916)

-   [Setting up an Ubuntu Build Environment Using an Installation Package](#section25961010189)
    -   [Installing Dependent Tools](#section109262032104819)
    -   [Obtaining Standard-System Source Code](#section6325556113718)
    -   [Obtaining prebuilts](#section16453104219209)
    -   [Configuring the Node.js Environment and Obtaining the Node\_modules Dependency Package](#section133741330192119)
    -   [Installing the hc-gen Tool](#section149281248182116)


You can use either the Docker environment or installation package provided by OpenHarmony to set up an Ubuntu build environment. This section describes the two methods.

## Setting up an Ubuntu Build Environment Using a Docker Environment<a name="section1643363843714"></a>

The standard OpenHarmony system provides a Docker environment which encapsulates build tools. To use the Docker environment, perform the following steps:

1.  Obtain the system source code.
2.  Install and use the Docker environment.

### Obtaining System Source Code<a name="section58448331029"></a>

For details, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

### Installing and Using the Docker Environment<a name="section22916211916"></a>

For details, see  [Installing and Using Docker](../get-code/tool-acquisition.md).

## Setting up an Ubuntu Build Environment Using an Installation Package<a name="section25961010189"></a>

The procedure is as follows:

1.  Install dependent tools.
2.  Obtain the system source code.
3.  Obtain prebuilts.
4.  Configure the Node.js environment and obtain the Node\_modules dependency package.
5.  Install the hc-gen tool.

### Installing Dependent Tools<a name="section109262032104819"></a>

The installation command is as follows:

```
sudo apt-get install binutils git-core git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 
```

>![](public_sys-resources/icon-caution.gif) **CAUTION:** 
>The preceding command is applicable to Ubuntu 18.04. For other Ubuntu versions, use the corresponding installation commands based on the installation package name. If the Ubuntu version is later than 18.04, Python 2.7 and python-minimal must be installed.

### Obtaining Standard-System Source Code<a name="section6325556113718"></a>

For details, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

### Obtaining prebuilts<a name="section16453104219209"></a>

1.  Go to the OpenHarmony working directory.

    ```
    cd OpenHarmony
    ```

2.  Download the script.

    ```
    curl https://gitee.com/landwind/script-tools/raw/master/Shell/OpenHarmony/OpenHarmony_2.0_canary_prebuilts_download.sh >./prebuilts_download.sh
    ```

3.  Download and decompress the prebuilts package in a specified directory.

    ```
    bash ./prebuilts_download.sh
    ```

    By default, binary files are stored in the  **OpenHarmony\_2.0\_canary\_prebuilts**  directory, which is in the same directory as  **OpenHarmony**. To change the storage path, change the value of  **bin\_dir**  in  **prebuilts\_download.sh**.

4.  Return to the previous directory.

    ```
    cd -
    ```


### Configuring the Node.js Environment and Obtaining the Node\_modules Dependency Package<a name="section133741330192119"></a>

To build the JS framework, you need to download and configure Node.js on a Linux server. The procedure is as follows \(the  **OpenHarmony**  directory in the following steps is the root directory of the current project and is configurable\):

1.  Download Node.js on a Linux server.

    ```
    mkdir -p OpenHarmony/prebuilts/build-tools/common/nodejs                                # Create the nodejs directory.
    cd OpenHarmony/prebuilts/build-tools/common/nodejs                                      # Go to the nodejs directory.
    wget --no-check-certificate https://nodejs.org/download/release/v12.18.4/node-v12.18.4-linux-x64.tar.gz # Download the Node.js package.
    tar -zxvf node-v12.18.4-linux-x64.tar.gz                                                # Decompress the Node.js package.
    cd -                                                                                    # Return to the previous directory.
    ```

2.  Configure the Node.js variable and download the  **node\_modules**  package.

    ```
    cd OpenHarmony/third_party/jsframework                  # Go to the jsframework directory.
    export PATH=../../prebuilts/build-tools/common/nodejs/node-v12.18.4-linux-x64/bin:${PATH} # Configure the Node.js variable.
    npm install                                             # Download the node_modules package.
    cd -                                                    # Return to the previous directory.
    ```

3.  Store the  **node\_modules**  package in the  **prebuilts/build-tools/common/js-framework**  directory of the OpenHarmony code.

    ```
    mkdir -p OpenHarmony/prebuilts/build-tools/common/js-framework          # Create the js-framework directory.
    cp -rp OpenHarmony/third_party/jsframework/node_modules OpenHarmony/prebuilts/build-tools/common/js-framework/
    ```


### Installing the hc-gen Tool<a name="section149281248182116"></a>

hc-gen is used to compile the driver. To install hc-gen, perform the following steps:

1.  Start a Linux server.
2.  Download  [hc-gen](https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar).
3.  Decompress the hc-gen installation package to  **\~/hc-gen**  on the Linux server.

    ```
    tar -xvf hc-gen-0.65-linux.tar -C ~/
    ```

4.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/hc-gen:$PATH
    ```

5.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


