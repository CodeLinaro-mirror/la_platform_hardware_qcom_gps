/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#define LOG_TAG "GnssPowerIndicationAidl"

#include "GnssPowerIndication.h"
#include <android/binder_auto_utils.h>
#include <inttypes.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

GnssPowerIndication::GnssPowerIndication() :
    mDeathRecipient(AIBinder_DeathRecipient_new(GnssPowerIndication::gnssPowerIndicationDied)) {
}

GnssPowerIndication::~GnssPowerIndication() {
}

ScopedAStatus GnssPowerIndication::setCallback(
        const shared_ptr<IGnssPowerIndicationCallback>& callback) {
    return ScopedAStatus::ok();
}

void GnssPowerIndication::cleanup() {
    if (nullptr != mGnssPowerIndicationCb) {
        AIBinder_unlinkToDeath(mGnssPowerIndicationCb->asBinder().get(), mDeathRecipient, this);
        mGnssPowerIndicationCb = nullptr;
    }
}

void GnssPowerIndication::gnssPowerIndicationDied(void* cookie) {
    GnssPowerIndication* iface = static_cast<GnssPowerIndication*>(cookie);
    if (iface != nullptr) {
        iface->cleanup();
    }
}

ScopedAStatus GnssPowerIndication::requestGnssPowerStats() {
    return ScopedAStatus::ok();
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
