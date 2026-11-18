/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/BnAGnss.h>
#include <aidl/android/hardware/gnss/IAGnssCallback.h>
#include "AGnss.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

void agnssServiceDied(void* cookie) {
    AGnss* iface = static_cast<AGnss*>(cookie);
    if (iface != nullptr) {
        iface->setCallback(nullptr);
        iface = nullptr;
    }
}
AGnss::AGnss()
    : mDeathRecipient(AIBinder_DeathRecipient_new(&agnssServiceDied)) {
}

AGnss::~AGnss() {
}

ScopedAStatus AGnss::setCallback(const shared_ptr<IAGnssCallback>& callback) {
    return ScopedAStatus::ok();
}
ScopedAStatus AGnss::dataConnClosed() {
    return ScopedAStatus::ok();
}
ScopedAStatus AGnss::dataConnFailed() {
    return ScopedAStatus::ok();
}
ScopedAStatus AGnss::dataConnOpen(int64_t networkHandle, const std::string& apn,
        ::aidl::android::hardware::gnss::IAGnss::ApnIpType apnIpType) {
    return ScopedAStatus::ok();
}
ScopedAStatus AGnss::setServer(::aidl::android::hardware::gnss::IAGnssCallback::AGnssType type,
        const std::string& hostname, int32_t port) {
    return ScopedAStatus::ok();
}
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
