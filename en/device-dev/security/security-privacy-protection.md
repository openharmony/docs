# Privacy Protection

## Overview

Personal data plays an increasingly important role in social economy and daily life along with the development of the Internet and informatization. Meanwhile, personal data leakage risks are increasing. As consumer product developers, you shall take more effective measures to protect users' personal data and improve their trust in your products. To protect consumers' privacy and improve their experience on privacy, you should set high-level privacy protection policies for your product.

**Basic Concepts**

-   **Personal data**

    Any information relating to an identified or identifiable natural person \("Data Subject"\) who can be identified, directly or indirectly, in particular by reference to an identifier such as a name, an identification number, location data, an online identifier or to one or more factors specific to the physical, physiological, genetic, mental, commercial, cultural, or social identity of that natural person. Personal data includes a natural person's email address, phone number, biometric information \(such as a fingerprint\), location data, IP address, healthcare information, religious belief, social security number, marital status, and so on.

-   **Sensitive personal data**

    Sensitive personal data, a critical subset of personal data, refers to the most private information of a data subject or information that may cause severe adverse impacts on a data subject once disclosed. Sensitive personal data defined in laws and regulations of EU and its members includes personal data revealing racial or ethnic origin, political opinions, religious or philosophical beliefs, trade-union membership, genetic data, biometric information, and data concerning health or sex life and sexual orientation.

    With reference to industry best practices, we also define the following data related to a natural person's identity as sensitive: bank card number, identification number, passport number, and passwords. More strict protection measures are usually required for processing sensitive personal data.

-   **Public available personal data**

    Personal data that is proactively disclosed by a data subject or that can be accessed on public web pages or applications, including posts and comments made on forums.

-   **User profile**

    Any form of automated processing of personal data to assess a natural person in specific aspects, and in particular to analyze and predict the natural person's work performance, financial situation, health, personal preference, interest, creditability, behavior, and location or trace.

-   **Data controller**

    A natural or legal person, public authority, agency, or any other body that, alone or jointly with others, determines the purposes and means of personal data processing.

-   **Data processor**

    A natural or legal person, public authority, agency, or any other body that processes personal data on behalf of a data controller. A data processor must provide adequate protection following the data controller's requirements.

-   **Explicit consent**

    Explicit consent applies to the following scenarios where the General Data Protection Regulation \(GDPR\) allows the legitimate processing of personal data based on data subjects' explicit consent:

    -   Processing of sensitive personal data
    -   Automated decision-making, including user profiles
    -   Transfer of personal data to countries without an adequate level of protection, which uses consent as the legal basis

    Explicit consent can be implemented as follows:

    -   In the collection of specific data, display a privacy statement to notify data subjects of matters related to the processing of personal data, provide a check box which is deselected by default, and prompt data subjects to proactively select the option indicating that "I agree to process my personal data in the above manner" or click the "I agree" button.
    -   Expressly present consent in writing and request data subjects to sign it.
    -   Ask data subjects to upload an electronic form with their signature in the system.
    -   Adopt the double verification method by requesting data subjects to consent via an email and then re-click the email link for verification or enter the SMS verification code.
    -   Users provide information proactively, such as scenarios where a user enters their identification number and bank card number to bind the bank card.


## Data Classification

Data is classified into five levels: very high, high, moderate, low, and public based on the data protection objectives and consequences \(the impact of legal risks caused by data leakage or damage on individuals, organizations, or the public\).

**Table 1**  Standards for data classification

<a name="table1536524010291"></a>
<table><thead align="left"><tr id="row444844052917"><th class="cellrowborder" valign="top" width="13.239999999999998%" id="mcps1.1.5.1.1"><p id="p2448740182911"><a name="p2448740182911"></a><a name="p2448740182911"></a><strong id="b2079915010139"><a name="b2079915010139"></a><a name="b2079915010139"></a>Level</strong></p>
</th>
<th class="cellrowborder" valign="top" width="26.05%" id="mcps1.1.5.1.2"><p id="p58515187465"><a name="p58515187465"></a><a name="p58515187465"></a><strong id="b52571858131320"><a name="b52571858131320"></a><a name="b52571858131320"></a>Privacy Risk</strong></p>
</th>
<th class="cellrowborder" valign="top" width="11.91%" id="mcps1.1.5.1.3"><p id="p2920544155210"><a name="p2920544155210"></a><a name="p2920544155210"></a><strong id="b104071711171410"><a name="b104071711171410"></a><a name="b104071711171410"></a>Privacy Attribute</strong></p>
</th>
<th class="cellrowborder" valign="top" width="48.8%" id="mcps1.1.5.1.4"><p id="p174482040112912"><a name="p174482040112912"></a><a name="p174482040112912"></a><strong id="b192611421412"><a name="b192611421412"></a><a name="b192611421412"></a>Typical Example</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1844904062919"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="p1444934002910"><a name="p1444934002910"></a><a name="p1444934002910"></a>Very high</p>
</td>
<td class="cellrowborder" valign="top" width="26.05%" headers="mcps1.1.5.1.2 "><p id="p1013011148467"><a name="p1013011148467"></a><a name="p1013011148467"></a>Once data is identified or associated with an individual or group of individuals, its disclosure or improper use may have a catastrophic negative impact on that individual or group of individuals.</p>
</td>
<td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.3 "><p id="p1992019442526"><a name="p1992019442526"></a><a name="p1992019442526"></a>Sensitive personal data</p>
</td>
<td class="cellrowborder" valign="top" width="48.8%" headers="mcps1.1.5.1.4 "><p id="p544974014295"><a name="p544974014295"></a><a name="p544974014295"></a>DNA, race, religious belief, and sexual orientation; biometric information; original communication content; bank account password and magnetic track data</p>
</td>
</tr>
<tr id="row8449164062911"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="p24491040192916"><a name="p24491040192916"></a><a name="p24491040192916"></a>High</p>
</td>
<td class="cellrowborder" valign="top" width="26.05%" headers="mcps1.1.5.1.2 "><p id="p101301214144615"><a name="p101301214144615"></a><a name="p101301214144615"></a>Once data is identified or associated with an individual or group of individuals, its disclosure or improper use may have a severe negative impact on that individual or group of individuals.</p>
</td>
<td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.3 "><p id="p1592084417525"><a name="p1592084417525"></a><a name="p1592084417525"></a>Sensitive personal data</p>
</td>
<td class="cellrowborder" valign="top" width="48.8%" headers="mcps1.1.5.1.4 "><p id="p74501400297"><a name="p74501400297"></a><a name="p74501400297"></a>Social identity (such as ID card and passport number); web browsing history; tracks; content (such as images, audio, and video) uploaded to the cloud</p>
</td>
</tr>
<tr id="row1745074020293"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="p1145074072915"><a name="p1145074072915"></a><a name="p1145074072915"></a>Moderate</p>
</td>
<td class="cellrowborder" valign="top" width="26.05%" headers="mcps1.1.5.1.2 "><p id="p31311514124618"><a name="p31311514124618"></a><a name="p31311514124618"></a>Once data is identified or associated with an individual or group of individuals, its disclosure or improper use may have a significant negative impact on that individual or group of individuals.</p>
</td>
<td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.3 "><p id="p1092116445529"><a name="p1092116445529"></a><a name="p1092116445529"></a>General personal data</p>
</td>
<td class="cellrowborder" valign="top" width="48.8%" headers="mcps1.1.5.1.4 "><p id="p945144022910"><a name="p945144022910"></a><a name="p945144022910"></a>Device ID (such as IMEI, SN, and OAID) and user ID; basic personal information (name and address); mobile number and email address</p>
</td>
</tr>
<tr id="row144512407291"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="p145110408294"><a name="p145110408294"></a><a name="p145110408294"></a>Low</p>
</td>
<td class="cellrowborder" valign="top" width="26.05%" headers="mcps1.1.5.1.2 "><p id="p61311514154618"><a name="p61311514154618"></a><a name="p61311514154618"></a>Once data is identified or associated with an individual or group of individuals, its disclosure or improper use may have a limited negative impact on that individual or group of individuals.</p>
</td>
<td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.3 "><p id="p29212442526"><a name="p29212442526"></a><a name="p29212442526"></a>General personal data</p>
</td>
<td class="cellrowborder" valign="top" width="48.8%" headers="mcps1.1.5.1.4 "><p id="p945217401298"><a name="p945217401298"></a><a name="p945217401298"></a>OS settings (including the OS version and country/region); device hardware information (device model, screen size, and screen resolution); network information (network connection status and access network information); device status (login time/duration)</p>
</td>
</tr>
<tr id="row135851553268"><td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.1 "><p id="p55864518261"><a name="p55864518261"></a><a name="p55864518261"></a>Public</p>
</td>
<td class="cellrowborder" valign="top" width="26.05%" headers="mcps1.1.5.1.2 "><p id="p135861254267"><a name="p135861254267"></a><a name="p135861254267"></a>Public data has no adverse impact on individuals or organizations.</p>
</td>
<td class="cellrowborder" valign="top" width="11.91%" headers="mcps1.1.5.1.3 "><p id="p1921144115218"><a name="p1921144115218"></a><a name="p1921144115218"></a>Non-personal data</p>
</td>
<td class="cellrowborder" valign="top" width="48.8%" headers="mcps1.1.5.1.4 "><p id="p1058612512613"><a name="p1058612512613"></a><a name="p1058612512613"></a>Publicly released product introduction, public meeting information, and external open-source code</p>
</td>
</tr>
</tbody>
</table>

Note: For details about the definitions of privacy protection and data classification, see GDPR.

## General Privacy Design Rules

To help you better complete privacy design for OpenHarmony products, we sort out general privacy design requirements.

**Openness and Transparency in Data Collection and Use**

When collecting personal data, clearly and explicitly notify users of the data to collect and how their personal data will be used.

-   Develop specific privacy processing policies for personal data at different levels.
    -   Explicit consent shall be obtained from the data subject before your product attempts to collect sensitive personal data.
    -   Generally, the collection of personal data requires the consent of the data subject or other legal authorizations.
    -   If non-personal data is to be collected in association with personal data at the moderate, high, or very high level, the data subject's consent or other legal authorization is required, and the consent or authorization shall be presented in the privacy statement.

-   Develop and follow appropriate privacy policies. Comply with all applicable laws, policies, and regulations when collecting, using, retaining, and sharing users' personal data with any third parties. For example, prior to data collection, fully inform users of the types, purposes, processing methods, and retention periods of personal data to meet the requirements of data subjects' rights.

    Guided by the preceding principles, we have designed some examples for your reference. The figures below are examples of a privacy notice and a privacy statement, respectively.

    **Figure  1**  Examples of a privacy notice and a privacy statement  
    

    ![](figure/privacy-notice.png)![](figure/privacy-statement.png)

-   Personal data shall be collected for specified, explicit, and legitimate purposes and not further processed in a manner that is incompatible with those purposes. If the purposes are changed or a user withdraws their consent, you shall obtain user consent again before using the data. The figures below are examples of a privacy statement update and content withdrawal, respectively.

    **Figure  2**  Example dialog showing a privacy statement update<a name="fig3591610523"></a>  
    

    ![](figure/privacy-statement-update.png)

    **Figure  3**  Example dialog showing consent withdrawal<a name="fig12802152515583"></a>  
    

    ![](figure/consent-withdrawal-1.png)![](figure/consent-withdrawal-2.png)

-   You shall provide an entry for users to view the privacy statement. For example, you can provide an entry on the  **About**  page of your application to view the privacy statement, as shown in the following figure.

    **Figure  4**  Example of About page providing an entry to the privacy statement<a name="fig11392538162011"></a>  
    

   ![](figure/privacy-statement-entry.png)


**Minimization in Data Collection and Use**

Collect personal data only when they are adequate, relevant, and limited to what is necessary in relation to the purposes for which they are processed. Apply anonymization or pseudonymization to personal data if possible to reduce the risks to the data subjects concerned. Data shall only be collected and processed for a specified purpose, and no further unnecessary operations shall be conducted on them.

-   When applying for sensitive permissions, adhere to permission minimization and apply for only the permissions required for obtaining necessary information or resources. For example, if your application can implement its functions without access to the camera, then it shall not request the user for the camera permission.
-   Comply with data collection minimization, and do not collect data irrelevant to services provided by the product. For example, a product that provides location services shall not collect users' web browsing history.
-   The functions that use personal data shall be able to benefit users. The collected data shall not be used for functions irrelevant to users' normal use. No data shall be collected for any functions irrelevant to user operations. For example, sensitive personal data, such as biometric features and health data, shall not be used for non-core service functions like service improvement, advertising, and marketing.
-   Printing sensitive personal data in logs is prohibited. If common personal data needs to be printed in logs, make sure the data is anonymized or pseudonymized.

    Preferentially use identifiers that are resettable. For example, use the NetworkID and DVID as the device identifier in the distributed scenario; use the  [OAID](https://developer.huawei.com/consumer/en/doc/development/HMSCore-Guides/oaid-0000001050783198)  in the advertising scenario; use the  [ODID](https://developer.huawei.com/consumer/en/doc/development/HMSCore-Guides/odid-0000001051063255)  and  [AAID](https://developer.huawei.com/consumer/en/doc/development/HMSCore-Guides/aaid-0000001051142988)  in the application-based analysis scenario; and use the UUID in other scenarios where a unique identifier is required. Use permanent identifiers such as the sequence number and MAC address only when resettable identifiers cannot meet your service requirements.


**Data Processing Selection and Control**

You shall obtain consent from users and comply with applicable laws and regulations for processing personal data and give users full control over their data.

-   When applying for a certain sensitive permission, your product shall display a pop-up dialog to notify the user of the requested permission and the purpose of using the permission. The user shall be able to choose whether to grant the permission and how they would like to grant the permission. This ensures that permission granting and use are transparent, perceivable, and controllable. The following figure is an example dialog for requesting a sensitive permission.

    **Figure  5**  Example dialog for requesting a sensitive permission<a name="fig20776134521514"></a>  
    

    ![](figure/sensitive-permission-request.png)

-   Users shall have the right to modify or withdraw the permissions granted to your product. When a user does not agree to a permission or data collection, the user shall be allowed to use the functions irrelevant to the permission or data collection. For example, the user can refuse to grant the camera permission to social or communication apps on Smart TVs, when using product functions irrelevant to the camera, such as voice calls.
-   In scenarios where personal data is recorded, users shall be provided with the functions of adding, deleting, modifying, and viewing personal data.
-   Your products shall provide a mechanism or method for securely deleting personal data when hardware is recycled or returned to the factory.
-   The download or upgrade of user system software or application software may involve the modification of users' private space. Users shall have the right to know and control such behavior. They shall be informed of such behavior and be given the option to agree or disagree with such behavior.

**Data Security**

Data processing security shall be ensured in technical terms, which include encrypted data storage and secure data transfer. Security mechanisms or measures shall be enabled by default for a system.

-   A protection mechanism shall be available for personal data access, including identity authentication and access control. Identity authentication \(such as username and password\) allows only authenticated users to access data in multi-user scenarios. Access control \(for example, [permission control](../security/security-guidelines-overall.md)\) can be applied to restrict access to applications.
-   Secure storage of personal data on distributed devices must meet Huawei Universal Keystore \(HUKS\) requirements, including secure storage of keys and data.
-   The transfer of personal data between distributed devices must meet the trust binding relationship between devices and security requirements of data transmission channels. For details, see [Device Interconnection Security](../security/security-guidelines-overall.md#device-interconnection-security).
-   Authentication data \(such as passwords and fingerprints\) shall be encrypted before being stored.

**Localization**

User data shall be preferentially processed on the local device. Data that cannot be processed on the local device shall be preferentially processed on Device+ \(super device in the distributed scenario\). If any data cannot be processed on Device+, the data shall be anonymized before being transferred out of Device+ for processing.

**Minors' Data Protection**

If your product is designed for minors or you can identify, based on the collected user age data, that the end user is a minor, you shall particularly analyze issues related to minors' personal data protection based on relevant national laws in the target market. Your product shall obtain explicit consent from the holders of parental responsibility over minors.

## **Privacy Protection Requirements for Special Categories**

In addition to these general privacy requirements, consumer hardware products have the following requirements for special categories. You shall comply with these requirements during product design.

**Table 2**  Privacy protection requirements for special categories

<a name="table17143732123612"></a>
<table><thead align="left"><tr id="row1943617174010"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.3.1.1"><p id="p1194461794016"><a name="p1194461794016"></a><a name="p1194461794016"></a>Product Category</p>
</th>
<th class="cellrowborder" valign="top" width="77%" id="mcps1.1.3.1.2"><p id="p1894481764012"><a name="p1894481764012"></a><a name="p1894481764012"></a>Privacy Protection Requirements</p>
</th>
</tr>
</thead>
<tbody><tr id="row918893210367"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p718853216369"><a name="p718853216369"></a><a name="p718853216369"></a><strong id="b1150122319282"><a name="b1150122319282"></a><a name="b1150122319282"></a>Smart home</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p81884329366"><a name="p81884329366"></a><a name="p81884329366"></a>Biometric information (such as fingerprints, voiceprints, facial recognition, and irises) and user passwords involved in security products are sensitive personal data. They shall be processed using technical measures (for example, extracting the digest of biometric information) before being encrypted and stored in the products.</p>
</td>
</tr>
<tr id="row19189103223618"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p201891632163610"><a name="p201891632163610"></a><a name="p201891632163610"></a><strong id="b16184636153611"><a name="b16184636153611"></a><a name="b16184636153611"></a>Smart home</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p18189173243610"><a name="p18189173243610"></a><a name="p18189173243610"></a>For security products that involve audio, video, and images, their manufacturers, functioning as the data controller, shall provide an independent privacy notification and a brand log on their application UI. Transfer and storage of audio and video data shall be encrypted. Access to audio and video data of security products is permitted only after being authorized by the data subject.</p>
</td>
</tr>
<tr id="row121891432163614"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p121892320363"><a name="p121892320363"></a><a name="p121892320363"></a><strong id="b670294616282"><a name="b670294616282"></a><a name="b670294616282"></a>Smart home/Entertainment</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p51891432183615"><a name="p51891432183615"></a><a name="p51891432183615"></a>Cameras on products should be able to be physically disabled. For example, cameras can be hidden, shuttered, or re-oriented so that consumers can perceive that the cameras are disabled.</p>
</td>
</tr>
<tr id="row1218903210364"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p5189632163616"><a name="p5189632163616"></a><a name="p5189632163616"></a><strong id="b1067022117448"><a name="b1067022117448"></a><a name="b1067022117448"></a>Smart home/Entertainment</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p111891632153617"><a name="p111891632153617"></a><a name="p111891632153617"></a>Products with a microphone should provide an explicit display of the recording status. For example, the products can provide a status indicator that blinks when recording is started and turns off when recording is stopped.</p>
</td>
</tr>
<tr id="row31891932173619"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p11891132163618"><a name="p11891132163618"></a><a name="p11891132163618"></a><strong id="b12223353122815"><a name="b12223353122815"></a><a name="b12223353122815"></a>Mobile office</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p10189632183612"><a name="p10189632183612"></a><a name="p10189632183612"></a>In scenarios such as cross-device display and transfer of user data, your products shall obtain explicit consent from users and give them full control over their personal data.</p>
</td>
</tr>
<tr id="row1189232103617"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.3.1.1 "><p id="p16189632183619"><a name="p16189632183619"></a><a name="p16189632183619"></a><strong id="b1225245962810"><a name="b1225245962810"></a><a name="b1225245962810"></a>In-vehicle infotainment (IVI)</strong></p>
</td>
<td class="cellrowborder" valign="top" width="77%" headers="mcps1.1.3.1.2 "><p id="p1018983263615"><a name="p1018983263615"></a><a name="p1018983263615"></a>1. Privacy notice and permission settings</p>
<p id="p1618914325366"><a name="p1618914325366"></a><a name="p1618914325366"></a>Do not let users read privacy policies and permission settings in the driving state.</p>
<p id="p1818973263617"><a name="p1818973263617"></a><a name="p1818973263617"></a>IVI applications shall consider the safety of vehicle use. The applications shall not require complex permission settings or reading of privacy policies when users are driving. For example, HiCar is usable only after users have set basic permissions and read privacy policies on their mobile phone.</p>
<p id="p518973210368"><a name="p518973210368"></a><a name="p518973210368"></a>The privacy statement shall be notified after the user identity is confirmed.</p>
<p id="p6189132113615"><a name="p6189132113615"></a><a name="p6189132113615"></a>Vehicle data involves vehicle owners, drivers, and passengers. The data subject shall be notified of the privacy statement. The recommended practice is to make a privacy statement after confirming the user identity. For an application that requires login, the privacy statement should be displayed after, instead of before, a user is logged in.</p>
<p id="p1818914329368"><a name="p1818914329368"></a><a name="p1818914329368"></a>2. Personal data protection for sharing applications</p>
<p id="p191892032103620"><a name="p191892032103620"></a><a name="p191892032103620"></a>Shared applications shall exit after the IVI is restarted, and the personal data of the current user shall be cleared or encrypted. The applications shall also provide the function to permanently delete historical data.</p>
<p id="p4189153213611"><a name="p4189153213611"></a><a name="p4189153213611"></a>3. Notifications</p>
<p id="p2189432103613"><a name="p2189432103613"></a><a name="p2189432103613"></a>As the IVI is used in an open environment, applications shall not directly display the message content on the IVI. Instead, the applications shall only notify users that there is an incoming message.</p>
</td>
</tr>
</tbody>
</table>

