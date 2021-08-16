# Configuring the Compilation Environment<a name="EN-US_TOPIC_0000001071315859"></a>

-   [Linux Server](#section20979554791)
-   [Node.js](#section9954105413153)
-   [Installing hpm-cli Tool](#section15937194904819)
-   [Python Environment](#section1621819180417)
-   [File Packaging Tool](#section77617165913)
-   [SCons](#section20558439191516)

![](figure/3516dv300.png)

## Linux Server<a name="section20979554791"></a>

Prepare a 64-bit Linux server running Ubuntu 16.04 or later. \(Currently, the compilation in the Windows environment is not fully supported.\)

Configure Ubuntu to use bash as the Linux system shell, by performing the following:

```
ls -l $(which sh)
# If the file does not point to bash, modify the file using either of the provided methods.
# Method 1: Run the following command and select no:
dpkg-reconfigure dash
# Method 2: Run the following commands to delete /bin/sh and then create a new symbolic link to bash:
rm -f /bin/sh
ln -s bash /bin/sh
```

## Node.js<a name="section9954105413153"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>If the  **Node.js**  version of the source is outdated, run the following command before running  **apt-get install**:
>```
>curl -L https://deb.nodesource.com/setup_12.x | bash
>```

You are advised to install Node.js 12.x \(including npm 6.14.4\) or a later version \(12.13.0 or later is recommended\).

```
sudo apt-get install nodejs
sudo apt-get install npm
```

Run the following commands to view  **Node.js**  and npm versions:

```
node --version  # Check the Node.js version.
npm --version   # Check the npm version.
```

## Installing hpm-cli Tool<a name="section15937194904819"></a>

Install the  **hpm-cli**  command line tool by using the npm \(default source: https://registry.npmjs.org/\) provided by  **Node.js**.

```
npm install -g @ohos/hpm-cli
```

After  **hpm-cli**  is installed, run the following command to view the default hpm configurations:

```
hpm config
```

You can modify the default configurations as required. The following lists common hpm configurations:

```
registry = https://hpm.harmonyos.com              # Address of the hpm registry. This is mandatory for downloading bundles.
strictSsl = true                                  # Enable strict SSL verification as HTTPS is used for connection.
http_proxy = http://your-proxy-server:port        # Configure the HTTP proxy.
https_proxy = http://your-proxy-server:port       # Configure the HTTPS proxy.
```

For details about  **hpm-cli**  commands, see  [HPM Commands](bundles-standard-rules.md).

## Python Environment<a name="section1621819180417"></a>

Run the following commands to install Python later than 3.7:

```
sudo apt-get install python3.8
sudo apt-get install python3-pip
sudo pip3 install setuptools
sudo pip3 install kconfiglib  # Install kconfiglib 13.2.0 or later.
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The preceding method is applicable to Hi3518 and Hi3516 platforms. For Hi3861, run the following commands to install the Python environment:
>```
>sudo apt-get install python3.8
>sudo apt-get install python3-pip
>sudo pip3 install setuptools
>sudo pip3 install kconfiglib  # Install kconfiglib 13.2.0 or later.
>sudo pip3 install pycryptodome
>sudo pip3 install six --upgrade --ignore-installed six
>sudo pip3 install ecdsa
>```

If both Python2 and Python3 have been installed in the current system, run the following commands to set the default Python to Python3:

```
ll `which python`
rm /usr/bin/python
ln -s python3.8 /usr/bin/python
```

## File Packaging Tool<a name="section77617165913"></a>

Run the following commands to install the tool:

```
which mkfs.vfat  # If mkfs.vfat is not found, run the following command:
sudo apt-get install dosfstools
which mcopy # If mcopy is not found, run the following command:
sudo apt-get install mtools
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Both Hi3518 and Hi3516 platforms require the file packaging tool. For Hi3861, the tool is not required.

## SCons<a name="section20558439191516"></a>

1.  Start a Linux server.
2.  Run the following command to install the SCons installation package:

    ```
    python3 -m pip install scons
    ```

3.  Run the following command to check whether SCons is successfully installed. If the installation is successful, the query result shown in  [Figure 1](#fig235815252492)  is displayed.

    ```
    scons -v
    ```

    **Figure  1**  Successful installation \(SCons version requirement: 3.0.4 or later\)<a name="fig235815252492"></a>  
    ![](figure/successful-installation-(scons-version-requirement-3-0-4-or-later)-28.png "successful-installation-(scons-version-requirement-3-0-4-or-later)-28")


>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>SCons is required for the Hi3861 platform, but not for the Hi3518 or Hi3516 platform.

