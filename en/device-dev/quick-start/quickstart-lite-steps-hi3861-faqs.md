# FAQs<a name="EN-US_TOPIC_0000001128311054"></a>

## What should I do when the message  **configure: error: no acceptable C compiler found in $PATH**  is displayed during Python 3 installation?<a name="section1221016541119"></a>

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


## What should I do when the message  **-bash: make: command not found**  is displayed during Python 3 installation?<a name="section1913477181213"></a>

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


## What should I do when the message  **zlib not available**  is displayed during Python 3 installation?<a name="section108211415131210"></a>

-   **Symptom**

    The following error occurs during Python 3 installation:

    ```
    zipimport.ZipImportError: can't decompress data; zlib not available
    ```

-   **Possible Causes**

    **zlib**  is not installed.

-   **Solutions**

    Solution 1: Run the  **apt-get install zlib**  command to install  **zlib**  online.

    Solution 2: If the software source does not contain  **zlib**, download the source code from  [http://www.zlib.net/](http://www.zlib.net/).

    ![](figures/download-zlib.png)

    Then run the following commands to install  **zlib**  offline:

    ```
    # tar xvf zlib-1.2.11.tar.gz
    # cd zlib-1.2.11
    # ./configure
    # make && make install
    ```

    After the installation, reinstall Python 3.


## What should I do when the message  **No module named '\_ctypes'**  is displayed during Python 3 installation?<a name="section2062268124"></a>

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


## What should I do when the message  **No module named 'Crypto'**  is displayed during compilation and building?<a name="section982315398121"></a>

-   **Symptom**

    The following error occurs during compilation and building:

    ```
    ModuleNotFoundError: No module named 'Crypto'
    ```


-   **Possible Causes**

    **Crypto**  is not installed.


-   **Solutions**

    Solution 1: Run the  **pip3 install Crypto**  command to install  **Crypto**  online.

    Solution 2: Install  **Crypto**  offline.

    -   Download the source code from  [https://pypi.org/project/pycrypto/\#files](https://pypi.org/project/pycrypto/#files).

    ![](figures/download-the-source-code.png)

    -   Save the source code package to the Linux server, decompress the package, and run the  **python3 setup.py install**  command to install  **Crypto**.
    -   Rebuild an environment.


## What should I do when the message  **No module named 'ecdsa'**  is displayed during compilation and building?<a name="section102035451216"></a>

-   **Symptom**

    The following error occurs during compilation and building:

    ```
    ModuleNotFoundError: No module named 'ecdsa'
    ```


-   **Possible Causes**

    **ecdsa**  is not installed.


-   **Solutions**

    Solution 1: Run the  **pip3 install ecdsa**  command to install  **ecdsa**  online.

    Solution 2: Install  **ecdsa**  offline.

    -   Download the installation package from  [https://pypi.org/project/ecdsa/\#files](https://pypi.org/project/ecdsa/#files).

    ![](figures/download-ecdsa.png)

    -   Save the installation package to the Linux server and run the  **pip3 install ecdsa-0.15-py2.py3-none-any.whl**  command to install  **ecdsa**.
    -   Rebuild an environment.


## What should I do when the message  **Could not find a version that satisfies the requirement six\>=1.9.0**  is displayed during compilation and building?<a name="section4498158162320"></a>

-   **Symptom**

    The following error occurs during compilation and building:

    ```
    Could not find a version that satisfies the requirement six>=1.9.0
    ```


-   **Possible Causes**

    **six**  is not installed.


-   **Solutions**

    Solution 1: Run the  **pip3 install six**  command to install  **six**  online.

    Solution 2: Install  **six**  offline.

    -   Download the installation package from  [https://pypi.org/project/six/\#files](https://pypi.org/project/six/#files).

    ![](figures/download-six.png)

    -   Save the source code to the Linux server and run the  **pip3 install six-1.14.0-py2.py3-none-any.whl**  command to install  **six**.
    -   Rebuild an environment.


## What should I do when the message  **cannot find -lgcc**  is displayed during compilation and building?<a name="section11181036112615"></a>

-   **Symptom**

    The following error occurs during compilation and building:

    ```
    riscv32-unknown-elf-ld: cannot find -lgcc
    ```


-   **Possible Causes**

    The PATH is incorrectly written by  **gcc\_riscv32**. There is an extra slash \(/\).

    ```
    ~/gcc_riscv32/bin/:/data/toolchain/
    ```


-   **Solutions**

    Modify the PATH by deleting the slash \(/\).

    ```
    ~/gcc_riscv32/bin:/data/toolchain/
    ```


## What should I do when the message indicating Python cannot be found is displayed during compilation and building?<a name="section1571810194619"></a>

-   **Symptom**

    The following error occurs during compilation and building:

    ```
    -bash: /usr/bin/python: No such file or directory
    ```


-   **Possible Cause 1:**  Python is not installed.
-   **Solutions**

    [Install Python](../quick-start/quickstart-lite-env-setup-linux.md).

-   **Possible Cause 2:**  The soft link that points to the Python does not exist in the  **usr/bin**  directory.

    ![](figures/reason-no-python-soft-link.png)

-   **Solutions**

    Run the following commands to add a soft link:

    ```
    # cd /usr/bin/
    # which python3
    # ln -s /usr/local/bin/python3 python
    # python --version
    ```

    Example:

    ![](figures/solution-add-soft-link.png)


## What should I do when the message indicating Python3 cannot be found is displayed during compilation and building?<a name="section108385316482"></a>

-   **Symptom**

    ![](figures/11.png)


-   **Possible Causes**

    Python 3 is not installed.

-   **Solutions**

    [Install Python](../quick-start/quickstart-lite-env-setup-linux.md).


## What should I do when an error with  **lsb\_release**  occurs during  **kconfiglib**  installation?<a name="section691681635814"></a>

-   **Symptom**

    The following error occurs during  **kconfiglib**  installation:

    ```
    subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
    ```

-   **Possible Causes**

    The Python version matched with the  **lsb\_release**  module is different from the current Python version.

-   **Solutions**

    Run the  **find / -name lsb\_release**  command, for example,  **sudo rm -rf /usr/bin/lsb\_release**  to locate and delete  **lsb\_release**.


