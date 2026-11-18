/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#define LOG_TAG "GnssBatchingAidl"

#include "GnssBatching.h"
#include <android/binder_auto_utils.h>
#include <inttypes.h>
namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
void gnssBatchingDied(void* cookie) {
    GnssBatching* iface = static_cast<GnssBatching*>(cookie);
    if (iface != nullptr) {
        iface->cleanup();
        iface = nullptr;
    }
}
GnssBatching::GnssBatching(): mBatchSize(0),
    mDeathRecipient(AIBinder_DeathRecipient_new(gnssBatchingDied)) {
}

GnssBatching::~GnssBatching() {
}


ScopedAStatus GnssBatching::init(const shared_ptr<IGnssBatchingCallback>& callback) {
    if (mGnssBatchingCbIface != nullptr) {
        AIBinder_unlinkToDeath(mGnssBatchingCbIface->asBinder().get(), mDeathRecipient, this);
    }

    mGnssBatchingCbIface = callback;
    if (mGnssBatchingCbIface != nullptr) {
        AIBinder_DeathRecipient_setOnUnlinked(mDeathRecipient, [](void* cookie) {});
        AIBinder_linkToDeath(mGnssBatchingCbIface->asBinder().get(), mDeathRecipient, this);
    }
    return ScopedAStatus::ok();
}
ScopedAStatus GnssBatching::getBatchSize(int32_t* _aidl_return) {
    *_aidl_return = mBatchSize;
    return ScopedAStatus::ok();
}
ScopedAStatus GnssBatching::start(const IGnssBatching::Options& options) {
    return ScopedAStatus::ok();
}
ScopedAStatus GnssBatching::flush() {
    return ScopedAStatus::ok();
}
ScopedAStatus GnssBatching::stop() {
    return ScopedAStatus::ok();
}
ScopedAStatus GnssBatching::cleanup() {
    if (mGnssBatchingCbIface != nullptr) {
        mGnssBatchingCbIface = nullptr;
    }
    return ScopedAStatus::ok();
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
