/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#include <unistd.h>
#include <aidl/android/hardware/gnss/IGnss.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include "Gnss.h"
#include <utils/Log.h>
#include <cutils/properties.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "android.hardware.gnss-aidl-impl-qti-stub"

using ::android::sp;

using GnssAidl = ::android::hardware::gnss::aidl::implementation::Gnss;

static void sleepIfInShutdown() {
    char shutdownProp[PROPERTY_VALUE_MAX] = {};
    const char propName[] = "sys.shutdown.requested";
    const char propDefault[] = "N/A";
    property_get(propName, shutdownProp, propDefault);
    if (strncmp(shutdownProp, propDefault, sizeof(propDefault)-1) != 0) {
        ALOGW("%s, %s was set %s, SLEEP!!!", __FUNCTION__, propName, shutdownProp);
        sleep(UINT_MAX);
    }
}

int main() {
    ALOGI("%s, start Gnss HAL stub process", __FUNCTION__);
    sleepIfInShutdown();
    ABinderProcess_setThreadPoolMaxThreadCount(0);

    std::shared_ptr<GnssAidl> gnssAidl = ndk::SharedRefBase::make<GnssAidl>();
    const std::string instance = std::string() + GnssAidl::descriptor + "/default";
    if (gnssAidl != nullptr) {
        binder_status_t status =
            AServiceManager_addService(gnssAidl->asBinder().get(), instance.c_str());
        if (STATUS_OK == status) {
            ALOGD("register IGnss AIDL service success");
        } else {
            ALOGE("Error while register IGnss AIDL service, status: %d", status);
        }
    }
    // Loc AIDL service end
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;  // should not reach
}
