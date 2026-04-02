/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSPOWERINDICATION_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSPOWERINDICATION_H
#include <aidl/android/hardware/gnss/BnGnssPowerIndication.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

using ::aidl::android::hardware::gnss::BnGnssPowerIndication;
using ::aidl::android::hardware::gnss::IGnssPowerIndicationCallback;
using ::aidl::android::hardware::gnss::GnssPowerStats;
using ::aidl::android::hardware::gnss::ElapsedRealtime;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;

struct GnssPowerIndication : public BnGnssPowerIndication {
public:
    GnssPowerIndication();
    ~GnssPowerIndication();
    ScopedAStatus setCallback(
            const shared_ptr<IGnssPowerIndicationCallback>& callback) override;
    ScopedAStatus requestGnssPowerStats() override;

    void cleanup();

private:
    shared_ptr<IGnssPowerIndicationCallback> mGnssPowerIndicationCb = nullptr;
    // Synchronization lock for mGnssPowerIndicationCb
    AIBinder_DeathRecipient* mDeathRecipient;

    static void gnssPowerIndicationDied(void* cookie);
};

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSPOWERINDICATION_H
