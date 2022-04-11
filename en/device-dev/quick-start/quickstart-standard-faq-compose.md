# Fixing Compilation Issues


## What should I do if the message "ImportError: No module named apt_pkg" is displayed during the execution of an unidentifiable command?

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


## What should I do when the message indicating Python cannot be found is displayed during compilation and building?

- **Symptom**

  The following error occurs during compilation and building:

    
  ```
  -bash: /usr/bin/python: No such file or directory
  ```

- **Possible Cause 1**

  Python is not installed.

- **Solution**

  Run the following command to install Python. The following uses Python 3.8 as an example.

    
  ```
  sudo apt-get install python3.8
  ```

- **Possible Cause 2**

  The soft link that points to the Python does not exist in the **usr/bin** directory.

  ![en-us_image_0000001226922322](figures/en-us_image_0000001226922322.png)

- **Solution**

  Run the following commands to add a soft link:

    
  ```
  # cd /usr/bin/ 
  # which python3
  # ln -s /usr/local/bin/python3 python
  # python --version
  ```

  Example:

  ![en-us_image_0000001271562453](figures/en-us_image_0000001271562453.png)


## What should I do when the message indicating Python 3 cannot be found is displayed during compilation and building?

- **Symptom**

  ![en-us_image_0000001226602414](figures/en-us_image_0000001226602414.png)

- **Possible Causes**

  Python 3 is not installed.

- **Solution**

  Run the following command to install Python 3:

    
  ```
  sudo apt-get install python3.8
  ```


## What should I do when the message configure: error: no acceptable C compiler found in $PATH is displayed during Python 3 installation?

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


## What should I do when the message -bash: make: command not found is displayed during Python 3 installation?

- **Symptom**

  The following error occurs during Python 3 installation:

    
  ```
  -bash: make: command not found
  ```

- **Possible Causes**

  Make is not installed.

- **Solution**

  1. Run the **apt-get install make** command to install Make online.
  2. After the installation, reinstall Python 3.


## What should I do when the message No module named '_ctypes' is displayed during Python 3 installation?

- **Symptom**

  The following error occurs during Python 3 installation:

    
  ```
  ModuleNotFoundError: No module named '_ctypes'
  ```

- **Possible Causes**

  **libffi** and **libffi-devel** are not installed.

- **Solution**

  1. Run the **apt-get install libffi* -y** command to install **libffi** and **libffi-devel** online.
  2. After the installation, reinstall Python 3.


## "No module named 'Crypto'" Displayed During the Build Process

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

  ![en-us_image_0000001227082334](figures/en-us_image_0000001227082334.png)

  Save the source package to the Linux server, decompress the package, and run the **python3 setup.py install** command to install Crypto.

  After the preceding installation is complete, rebuild an environment.
