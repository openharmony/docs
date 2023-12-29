# Application Package Overview


A user application, also known as an application or app, runs on the operating system of devices and provides particular services for users. The software package corresponding to an application is called an application package.


The system provides an efficient management mechanism for application packages. With this mechanism, you can easily develop, install, query, update, and uninstall application packages.
- To accelerate application deployment, you can use the integrated development tool provided to integrate executable code, resources, and third-party libraries into an application package.

- To distribute your application package by device type, you can specify the device types for distribution in the application package configuration file.

- An application may provide a wide range of features. It is a good practice to divide and manage application features by module. The system provides a multi-package management mechanism on an application-by-application basis. You can aggregate different application features into different packages to facilitate subsequent maintenance and expansion.

- To allow an application to run across various chipset platforms, such as x86, Arm, and other 32-bit or 64-bit platforms, the system abstracts away the differences between chip platforms for application packages.

- With a myriad of query APIs, you can quickly check the information about applications, including the application versions, names, components, and permissions.

- To facilitate resource search and use, the bundle management service archives resources by type (media, native, string, internationalization, and more) in different directories and integrates resource index files.
