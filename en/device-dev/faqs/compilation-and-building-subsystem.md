# Compilation and Building Subsystem<a name="EN-US_TOPIC_0000001215530845"></a>

-   [Mini and Small Systems](#section78686441462)
    -   [Invalid -- w Option](#section67961431372)
    -   [Library ncurses Not Found](#section199631617371)
    -   [mcopy not Found](#section937435175)
    -   [No riscv File or Directory](#section1115535018713)
    -   [No Crypto](#section17982573813)
    -   [Unexpected Operator](#section53663205819)
    -   [What should I do when the message Could not find a version that satisfies the requirement six\>=1.9.0 is displayed during compilation and building?](#section1917790845)
    -   [What should I do when the message cannot find -lgcc is displayed during compilation and building?](#section141771701647)
    -   [What should I do when the message indicating Python cannot be found is displayed during compilation and building?](#section51781202415)
    -   [What should I do when the message indicating Python 3 cannot be found is displayed during compilation and building?](#section1917950148)


## Mini and Small Systems<a name="section78686441462"></a>

### Invalid -- w Option<a name="section67961431372"></a>

-   **Symptom**

    The build fails, and "usr/sbin/ninja: invalid option -- w" is displayed.

-   **Cause**

    The Ninja version in the build environment is outdated and does not support the  **--w**  option.

-   **Solution**

    Uninstall Ninja and GN and follow the instructions provided in  [IDE](../get-code/gettools-ide.md)  to install Ninja and GN of the required version.


### Library ncurses Not Found<a name="section199631617371"></a>

-   **Symptom**

    The build fails, and "/usr/bin/ld: cannot find -lncurses" is displayed.

-   **Cause**

    The ncurses library is not installed.

-   **Solution**

    ```
    sudo apt-get install lib32ncurses5-dev
    ```


### mcopy not Found<a name="section937435175"></a>

-   **Symptom**

    The build fails, and "line 77: mcopy: command not found" is displayed.

-   **Cause**

    mcopy is not installed.

-   **Solution**

    ```
    ​sudo apt-get install dosfstools mtools
    ```


### No riscv File or Directory<a name="section1115535018713"></a>

-   **Symptom**

    The build fails, and the following information is displayed:

    riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory.

-   **Cause**

    Permission is required to access files in the  **riscv**  compiler directory.

-   **Solution**

    Run the following command to query the directory where  **gcc\_riscv32**  is located:

    ```
    which riscv32-unknown-elf-gcc
    ```

    Run the  **chmod**  command to change the directory permission to  **755**.


### No Crypto<a name="section17982573813"></a>

-   **Symptom**

    The build fails, and "No module named 'Crypto'" is displayed.

-   **Cause**

    Crypto is not installed in Python 3.

-   **Solution**
    1.  Run the following command to query the Python version:

        ```
        python3 --version
        ```

    2.  Ensure that Python 3.7 or later is installed, and then run the following command to install pycryptodome:

        ```
        sudo pip3 install pycryptodome
        ```



### Unexpected Operator<a name="section53663205819"></a>

-   **Symptom**

    The build fails, and "xx.sh \[: xx unexpected operator" is displayed.

-   **Cause**

    The build environment is shell, not bash.

-   **Solution**

    ```
    sudo rm -rf /bin/sh
    sudo ln -s /bin/bash /bin/sh
    ```


### What should I do when the message  **Could not find a version that satisfies the requirement six\>=1.9.0**  is displayed during compilation and building?<a name="section1917790845"></a>

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


### What should I do when the message  **cannot find -lgcc**  is displayed during compilation and building?<a name="section141771701647"></a>

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


### What should I do when the message indicating Python cannot be found is displayed during compilation and building?<a name="section51781202415"></a>

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


### What should I do when the message indicating Python 3 cannot be found is displayed during compilation and building?<a name="section1917950148"></a>

-   **Symptom**

    ![](figures/11.png)


-   **Possible Causes**

    Python 3 is not installed.

-   **Solutions**

    [Install Python](../quick-start/quickstart-lite-env-setup-linux.md).


