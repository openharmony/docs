# Environment Setup


## Mini and Small Systems


### What should I do if garbled characters and segmentation faults occur during hb installation?

- **Symptom**
  Garbled characters and segmentation faults occur during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  pip is of an early version.

- **Solution**
  Upgrade pip.

    
  ```
  python3 -m pip install -U pip
  ```


### What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?

- **Symptom**
  The message "cannot import 'sysconfig' from 'distutils'" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  The **distutils** module is unavailable.

- **Solution**
  Install **distutils**.

    
  ```
  sudo apt-get install python3.8-distutils
  ```


### What should I do if the message "module 'platform' has no attribute 'linux_distribution'" is displayed during hb installation?

- **Symptom**
  The message "module 'platform' has no attribute 'linux_distribution'" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  There is a compatibility issue of python3-pip.

- **Solution**
  Reinstall pip.

    
  ```
  sudo apt remove python3-pip
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  ```


### What should I do if the message "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation?

- **Symptom**
  The message "Could not find a version that satisfies the requirement ohos-build" is displayed during the execution of the **python3 -m pip install --user ohos-build** command.

- **Possible Causes**
  The installation fails due to poor network connectivity.

- **Solution**
  1. Ensure that your computer has a good network connection. If the network connection is unstable, rectify the network fault and reinstall hb.
  2. If the network is functional, run the following commands to install hb by specifying a temporary PyPI source:
        
      ```
      python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple ohos-build
      ```


### What should I do if the message "configure: error: no acceptable C compiler found in $PATH" is displayed during Python 3 installation?

- **Symptom**
  The following error occurs during Python 3 installation:

    
  ```
  configure: error: no acceptable C compiler found in $PATH. See 'config.log' for more details
  ```

- **Possible Causes**
  **gcc** is not installed.

- **Solution**
  1. Run the **apt-get install gcc** command to install **gcc** online.
  2. After the installation, reinstall Python 3.


### What should I do if the message "-bash: make: command not found is displayed" during Python 3 installation?

- **Symptom**
  The following error occurs during Python 3 installation:

    
  ```
  -bash: make: command not found
  ```

- **Possible Causes**
  **Make** is not installed.

- **Solution**
  1. Run the **apt-get install make** command to install Make online.
  2. After the installation, reinstall Python 3.


### What should I do if the message **zlib not available** is displayed during Python 3 installation?

- **Symptom**
  The following error occurs during Python 3 installation:

    
  ```
  zipimport.ZipImportError: can't decompress data; zlib not available
  ```

- **Possible Causes**
  **zlib** is not installed.

- **Solution**
  Solution 1: Run the **apt-get install zlib** command to install **zlib** online.

  Solution 2: If the software source does not contain **zlib**, download the source code from <xref href="http://www.zlib.net/" scope="external" class="- topic/xref " id="xref17252104445818">http://www.zlib.net/</xref>.

  ![en-us_image_0000001198001086](figures/en-us_image_0000001198001086.png)

  Then run the following commands to install **zlib** offline:

    
  ```
  # tar xvf zlib-1.2.11.tar.gz
  # cd zlib-1.2.11
  # ./configure
  # make && make install
  ```

  After the installation, reinstall Python 3.


### What should I do if the message "No module named 'Crypto'" is displayed during the build process?

- **Symptom**
  The following error occurs during compilation and building:

    
  ```
  ModuleNotFoundError: No module named 'Crypto'
  ```

- **Possible Causes**
  **Crypto** is not installed.

- **Solution**
  Solution 1: Run the **pip3 install Crypto** command to install **Crypto** online.

  Method 2: Offline installation

  Download the source code from [PyPI](https://pypi.org/project/pycrypto/#files).

  ![en-us_image_0000001251196005](figures/en-us_image_0000001251196005.png)

  Save the source package to the Linux server, decompress the package, and run the **python3 setup.py install** command to install Crypto.

  After the preceding installation is complete, rebuild an environment.


### What should I do when an error with **lsb_release** occurs during **kconfiglib** installation?

- **Symptom**
  The following error occurs during **kconfiglib** installation:

    
  ```
  subprocess.CalledProcessError: Command '('lsb_release', '-a')' returned non-zero exit status 1.
  ```

- **Possible Causes**
  The Python version matched with the **lsb_release** module is different from the current Python version.

- **Solution**
  Run the **find / -name lsb_release** command, for example, **sudo rm -rf /usr/bin/lsb_release** to locate and delete **lsb_release**.


### What should I do if the message "ImportError: No module named apt_pkg" is displayed during the execution of an unidentifiable command?

- **Symptom**
  The message "ImportError: No module named apt_pkg" is displayed when an unidentifiable command is executed on the Linux server.

- **Possible Causes**
  There is a compatibility issue of python3-apt.

- **Solution**
  Reinstall python3-apt.

    
  ```
  sudo apt-get remove  python3-apt
  sudo apt-get install python3-apt
  ```
