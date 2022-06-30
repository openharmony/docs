# Setting Up the Environment

## Basic Test Framework Environment

| Environment | Operating System | Linux Extended Component | Python | Python Plug-ins | NFS Server | HDC | 
| ------------ | ------------ | ------------ | ------------ | ------------ | ------------ | ------------ | 
| Version | Ubuntu 18.04 or later | libreadline-dev | 3.7.5 or later | - pySerial 3.3 or later<br>- Paramiko 2.7.1 or later<br>- Setuptools 40.8.0 or later<br>- rsa4.0 or later | haneWIN NFS Server 1.2.50 or later, or NFS v4 or later |  1.1.0 or later | 
| Description | Provides code build environment. | Plug-in used to read commands. | Language used by the test framework. | - pySerial: supports Python serial port communication. <br>- Paramiko: allows Python to use SSH. <br>- Setuptools: allows Python packages to be created and distributed easily. <br>- rsa: implements RSA encryption in Python. | Enables devices to be connected through the serial port. | A tool that enables devices to be connected through the HarmonyOS Device Connector (HDC). | 

## Installation Process
1. Run the following command to install the Linux extended component libreadline:
    ```
    sudo apt-get install libreadline-dev
    ```
    The installation is successful if the following information is displayed:
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    libreadline-dev is already the newest version (7.0-3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```
2. Run the following command to install the Setuptools plug-in:
    ```
    pip3 install setuptools
    ```
    The installation is successful if the following information is displayed:
    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```
3. Run the following command to install the Paramiko plug-in:
    ```
    pip3 install paramiko
    ```
    The installation is successful if the following information is displayed:
    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```
4. Run the following command to install the ras plug-in:
    ```
    pip3 install rsa
    ```
    The installation is successful if the following information is displayed:
    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```
5. Run the following command to install the pySerial plug-in:
    ```
    pip3 install pyserial
    ```
    The installation is successful if the following information is displayed:
    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```
6. Install the NFS server if the device outputs results only through the serial port.
    - In Windows, install, for example, haneWIN NFS Server 1.2.50.
    - In Linux, run the following command to install the NFS server:
    ```
    sudo apt install nfs-kernel-server
    ```
    The installation is successful if the following information is displayed:
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    nfs-kernel-server is already the newest version (1:1.3.4-2.1ubuntu5.3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```
7. Install the HDC tool if the device supports HDC connections. For details about the installation process, see [Readme](https://gitee.com/openharmony/developtools_hdc_standard/blob/master/README.md).
    

## Checking the Environment

 | Check Item | Operation | Expected Result | 
 | --- | --- | --- | 
 | Whether Python is successfully installed | Run the **python --version** command. | The Python version is 3.7.5 or later. | 
 | Whether Python plug-ins are successfully installed | Go to the **test/developertest** directory and run **start.bat** or **start.sh**. | The **>>>** prompt is displayed. | 
 | NFS server status (for the devices that support only serial port output) | Log in to the development board through the serial port and run the **mount** command to mount the NFS. | The file directory can be mounted. | 
 | Whether HDC tool is successfully installed | Run the **hdc_std -v** command. | The HDC version is 1.1.0 or later. | 
