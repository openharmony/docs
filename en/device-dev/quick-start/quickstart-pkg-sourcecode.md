# Obtaining Source Code


In the Ubuntu environment, perform the following steps to obtain the OpenHarmony source code:


## Preparations

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. (Skip this step if the tools have been installed.) Install the git client and git-lfs.
   
   Update the software source:
   
   ```
   sudo apt-get update
   ```

   Run the following command to install the tools:
   
   ```
   sudo apt-get install git git-lfs
   ```

4. Configure user information.
   
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

5. Run the following commands to install the **repo** tool:
   
   In this example, **~/bin** is used as an example installation directory. You can change the directory as needed.
   
   ```
   mkdir ~/bin
   curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 -o ~/bin/repo 
   chmod a+x ~/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```

6. Add the path of the **repo** tool to environment variables.
   
   ```
   vim ~/.bashrc               # Edit environment variables.
   export PATH=~/bin:$PATH     # Add the path of the **repo** tool to the end of environment variables.
   source ~/.bashrc            # Apply environment variables.
   ```


## How to Obtain

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> Download the release code, which is more stable, if you want to develop commercial functionalities. Download the master code if you want to get quick access to the latest features for your development.

- **Obtaining OpenHarmony release code**
  
   For details about how to obtain the source code of an OpenHarmony release, see [OpenHarmony Release Notes](../../release-notes/Readme.md).


- **Obtaining OpenHarmony master code**

  > It is recommended that you create a new directory in the root directory and then download the source code.
  
  ```
  cd ~
  mkdir ohos_master       # Create a new directory named ohos_master in the root directory.
  cd ohos_master          # Access the ohos_master directory to download the code.
  ```
  

   Method 1 (recommended): Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)
   
  ```
  repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```

  Method 2 (recommended for cloud servers): Use the **repo** tool to download the source code over HTTPS.

  
  ```
  repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
  repo sync -c
  repo forall -c 'git lfs pull'
  ```


## Running prebuilts

Go to the root directory of the source code and run the following script to install the compiler and binary tool:

```
bash build/prebuilts_download.sh
```
