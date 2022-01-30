# Environment Setup<a name="EN-US_TOPIC_0000001215650793"></a>

## Mini and Small Systems<a name="section1742119306399"></a>

### What should I do if garbled characters and segmentation faults occur during hb installation?<a name="section36351051193919"></a>

-   **Symptom**

    Garbled characters and segmentation faults occur during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    pip is of an early version.

-   **Solutions**

    Upgrade pip.

    ```
    python3 -m pip install -U pip
    ```


### What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?<a name="section48221013144011"></a>

-   **Symptom**

    The message "cannot import 'sysconfig' from 'distutils'" is displayed during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    The  **distutils**  module is unavailable.

-   **Solutions**

    Install  **distutils**.

    ```
    sudo apt-get install python3.8-distutils
    ```


### What should I do if the message "module 'platform' has no attribute 'linux\_distribution'" is displayed during hb installation?<a name="section10307193044111"></a>

-   **Symptom**

    The message "module 'platform' has no attribute 'linux\_distribution'" is displayed during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    There is a compatibility issue of python3-pip.

-   **Solutions**

    Reinstall pip.

    ```
    sudo apt remove python3-pip
    curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
    python get-pip.py
    ```


### What should I do if the message "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation?<a name="section8692735427"></a>

-   **Symptom**

    The message "Could not find a version that satisfies the requirement ohos-build" is displayed during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    The installation fails due to poor network connectivity.

-   **Solutions**
    1.  Ensure that your computer has a good network connection. If the network connection is unstable, rectify the network fault and reinstall hb.
    2.  If the network is functional, run the following commands to install hb by specifying a temporary PyPI source:

        ```
        python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
        ```



### What should I do when the message  **configure: error: no acceptable C compiler found in $PATH**  is displayed during Python 3 installation?<a name="section870082884217"></a>

-   **Symptom**

    The following error occurs during Python 3 installation:

    ```
    configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
    ```

-   **Possible Causes**

    **GCC**  is not installed.

-   **Solutions**

    1. Run the  **apt-get install gcc**  command to install  **GCC**  online.

    2. After the installation, reinstall Python 3.


### What should I do when the message  **-bash: make: command not found**  is displayed during Python 3 installation?<a name="section198707170455"></a>

-   **Symptom**

    The following error occurs during Python 3 installation:

    ```
    -bash: make: command not found
    ```

-   **Possible Causes**

    **Make**  is not installed.

-   **Solutions**

    1. Run the  **apt-get install make**  command to install  **Make**  online.

    2. After the installation, reinstall Python 3.


### What should I do when the message  **zlib not available**  is displayed during Python 3 installation?<a name="section85401445204518"></a>

-   **Symptom**

    The following error occurs during Python 3 installation:

    ```
    zipimport.ZipImportError: can't decompress data; zlib not available
    ```

-   **Possible Causes**

    **zlib**  is not installed.

-   **Solutions**

    Solution 1: Run the  **apt-get install zlib**  command to install  **zlib**  online.

    Solution 2: If the software source does not contain  **zlib**, download the source code from  https://www.zlib.net/.

    ![](figures/download-zlib.png)

    Then run the following commands to install  **zlib**  offline:

    ```
    # tar xvf zlib-1.2.11.tar.gz
    # cd zlib-1.2.11
    # ./configure
    # make && make install
    ```

    After the installation, reinstall Python 3.


### What should I do when the message  **No module named '\_ctypes'**  is displayed during Python 3 installation?<a name="section12202694460"></a>

-   **Symptom**

    The following error occurs during Python 3 installation:

    ```
    ModuleNotFoundError: No module named '_ctypes'
    ```


-   **Possible Causes**

    **libffi**  and  **libffi-devel**  are not installed.


-   **Solutions**

    1. Run the  **apt-get install libffi\* -y**  command to install  **libffi**  and  **libffi-devel**  online.

    2. After the installation, reinstall Python 3.


### What should I do when an error with  **lsb\_release**  occurs during  **kconfiglib**  installation?<a name="section5803174135115"></a>

-   **Symptom**

    The following error occurs during  **kconfiglib**  installation:

    ```
    subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
    ```

-   **Possible Causes**

    The Python version matched with the  **lsb\_release**  module is different from the current Python version.

-   **Solutions**

    Run the  **find / -name lsb\_release**  command, for example,  **sudo rm -rf /usr/bin/lsb\_release**  to locate and delete  **lsb\_release**.


### What should I do if the message "ImportError: No module named apt\_pkg" is displayed during the execution of an unidentifiable command?<a name="section510820516515"></a>

-   **Symptom**

    The message "ImportError: No module named apt\_pkg" is displayed when an unidentifiable command is executed on the Linux server.


-   **Possible Causes**

    There is a compatibility issue of python3-apt.

-   **Solutions**

    Reinstall python3-apt.

    ```
    sudo apt-get remove  python3-apt
    sudo apt-get install python3-apt
    ```


