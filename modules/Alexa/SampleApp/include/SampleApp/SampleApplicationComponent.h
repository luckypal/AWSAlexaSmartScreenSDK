/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_SMART_SCREEN_SDK_SAMPLEAPP_INCLUDE_SAMPLEAPP_SAMPLEAPPLICATIONCOMPONENT_H_
#define ALEXA_SMART_SCREEN_SDK_SAMPLEAPP_INCLUDE_SAMPLEAPP_SAMPLEAPPLICATIONCOMPONENT_H_

#include <istream>
#include <memory>
#include <vector>

#include <acsdkManufactory/Component.h>
#include <AVSCommon/SDKInterfaces/AuthDelegateInterface.h>
#include <AVSCommon/SDKInterfaces/ContextManagerInterface.h>
#include <AVSCommon/SDKInterfaces/LocaleAssetsManagerInterface.h>
#include <AVSCommon/AVS/Initialization/AlexaClientSDKInit.h>
#include <AVSCommon/AVS/Attachment/AttachmentManagerInterface.h>
#include <AVSCommon/Utils/Configuration/ConfigurationNode.h>
#include <AVSCommon/Utils/DeviceInfo.h>
#include <AVSCommon/Utils/LibcurlUtils/HttpPostInterface.h>
#include <AVSCommon/Utils/Metrics/MetricRecorderInterface.h>
#include <CBLAuthDelegate/CBLAuthDelegateStorageInterface.h>
#include <CBLAuthDelegate/CBLAuthRequesterInterface.h>
#include <RegistrationManager/CustomerDataManager.h>

namespace alexaSmartScreenSDK {
namespace sampleApp {

/**
 * Get the @c Manufactory @c Component for the default @c SampleApplication options
 * @return The @c Manufactory @c Component for the default @c SampleApplication options
 */
alexaClientSDK::acsdkManufactory::Component<
    alexaClientSDK::acsdkManufactory::Import<
        std::unique_ptr<alexaClientSDK::avsCommon::utils::libcurlUtils::HttpPostInterface>>,
    alexaClientSDK::acsdkManufactory::Import<std::shared_ptr<alexaClientSDK::avsCommon::utils::DeviceInfo>>,
    alexaClientSDK::acsdkManufactory::Import<std::shared_ptr<alexaClientSDK::registrationManager::CustomerDataManager>>,
    std::shared_ptr<alexaClientSDK::avsCommon::utils::logger::Logger>,
    std::shared_ptr<alexaClientSDK::avsCommon::utils::metrics::MetricRecorderInterface>>
getSampleApplicationOptionsComponent();

/**
 * Get the manufactory @c Component for SampleApp.
 *
 * @return The manufactory @c Component for SampleApp.
 */
alexaClientSDK::acsdkManufactory::Component<
    std::shared_ptr<alexaClientSDK::avsCommon::avs::initialization::AlexaClientSDKInit>,
    std::shared_ptr<alexaClientSDK::avsCommon::sdkInterfaces::ContextManagerInterface>,
    std::shared_ptr<alexaClientSDK::avsCommon::sdkInterfaces::LocaleAssetsManagerInterface>,
    std::shared_ptr<alexaClientSDK::avsCommon::utils::configuration::ConfigurationNode>,
    std::shared_ptr<alexaClientSDK::avsCommon::utils::DeviceInfo>,
    std::shared_ptr<alexaClientSDK::registrationManager::CustomerDataManager>,
    std::shared_ptr<alexaClientSDK::avsCommon::utils::metrics::MetricRecorderInterface>>
getComponent(
    std::unique_ptr<alexaClientSDK::avsCommon::avs::initialization::InitializationParameters> initParams,
    std::vector<std::shared_ptr<alexaClientSDK::avsCommon::utils::RequiresShutdown>>& requiresShutdownList);

}  // namespace sampleApp
}  // namespace alexaSmartScreenSDK

#endif  // ALEXA_SMART_SCREEN_SDK_SAMPLEAPP_INCLUDE_SAMPLEAPP_SAMPLEAPPLICATIONCOMPONENT_H_
