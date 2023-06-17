# Shared Package Overview

OpenHarmony provides two types of shared packages: [Harmony Archive (HAR)](har-package.md) static shared package and Harmony Shared Package (HSP) dynamic shared package.

Both the HAR and HSP are used to share code and resources and can contain code, C++ libraries, resources, and configuration files. The biggest differences between them are as follows: The code and resources in the HAR are compiled with the invoking module, and if there are multiple invoking modules, the build product contains multiple copies of the same code and resources; the code and resources in the HSP can be compiled independently, and the build product contains only one copy of the code and resources.

**Figure 1** HAR and HSP in the App Pack

![in-app-hsp-har](figures/in-app-hsp-har.png)

The HSP aims to resolve the App Pack bloat resulting from multiple HAP files referencing the same HAR.

Restrictions on the HSP:
- The HSP and its invoking modules must be in the stage model.
- The HSP and its invoking modules must use the **esmodule** compilation mode.
- The HSP does not support the declaration of **abilities** and **extensionAbilities** in its configuration file.

The HSP can be classified as [in-application HSP](in-app-hsp.md) or inter-application HSP, which will be supported in later versions.
