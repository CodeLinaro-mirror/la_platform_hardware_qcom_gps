/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_AGNSS_H
#define ANDROID_HARDWARE_GNSS_AIDL_AGNSS_H
#include <aidl/android/hardware/gnss/BnAGnss.h>
#include <aidl/android/hardware/gnss/IAGnssCallback.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::BnAGnss;
using ::aidl::android::hardware::gnss::IAGnssCallback;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
class AGnss : public BnAGnss {
public:
    AGnss();
    virtual ~AGnss();

    ScopedAStatus setCallback(const shared_ptr<IAGnssCallback>& callback) override;
    ScopedAStatus dataConnClosed() override;
    ScopedAStatus dataConnFailed() override;
    ScopedAStatus setServer(IAGnssCallback::AGnssType type, const std::string& hostname,
            int32_t port) override;
    ScopedAStatus dataConnOpen(int64_t networkHandle, const std::string& apn,
            ApnIpType apnIpType) override;
private:
    shared_ptr<IAGnssCallback> mAGnssCbIface = nullptr;
    AIBinder_DeathRecipient *mDeathRecipient = nullptr;
};
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_AGNSS_H
