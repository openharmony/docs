# Application File Overview

Application files are files of an application, including the application's installation files, resource files, and cache files.

- The data used and saved by an application is stored in files, key-value (KV) pairs, and databases in a dedicated directory on a device. This directory is called application file directory, and the files in the directory are application files.

- The directories visible to an application consist of the application file directory and a directory containing the minimum system files required for the running of the application. These two directories constitute an [application sandbox directory](app-sandbox-directory.md). That is, the application file directory is a subset of the application sandbox directory.

- The system files and directories are read-only for the application. The application can only save files to sub-directories in the [application file directory](app-sandbox-directory.md#application-file-directory-and-application-file-path) based on certain rules.

The following topics describe the application sandbox, application file directories, and how to access, manage, and share application files.
