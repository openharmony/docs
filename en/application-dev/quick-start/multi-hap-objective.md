# Multi-HAP Design Objectives

The multi-HAP mechanism is designed for the following purposes:


- Modular management

  A well-designed application is generally managed in a modular manner, where modules are loosely coupled. The multi-HAP mechanism allows you to divide services into multiple modules and store each module in an independent HAP file.

  For example, if you are developing a payment application whose home screen consists of multiple modules, such as the scan, pay, messaging, and finance modules, you can implement the HAP files as follows: (1) In the entry HAP file, implement the home screen logic for managing these modules; (2) in feature HAP files, implement specific modules. The feature HAP files are independent of each other. You can develop and test each of them separately, and then integrate them with the entry HAP file.

- Flexible deployment

  You can flexibly combine HAP files for device-specific deployment.

  Assume that an application contains one entry HAP file (**entry.hap**) and two feature HAP files (**Feature1.hap** and **Feature2.hap**). The **Entry.hap** file can be deployed on device A and device B, the **Feature1.hap** file can be deployed only on device A, and the **Feature2.hap** file can be deployed only on device B. This means that you can combine the **Entry.hap** and **Feature1.hap** files and deploy them on device A, and combine the **Entry.hap** and **Feature2.hap** files and deploy them on device B.

- On-demand loading
  
  You can load modules only when they are needed, reducing the package size. Specifically, you can configure some HAP files of your application to be loaded on demand. For example, if some features are not used during application startup, you can configure them to be loaded only when they are needed, rather than being loaded at startup. This can reduce the size of the application package to some extent.
