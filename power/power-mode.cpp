/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <aidl/android/hardware/power/BnPower.h>
#include <android-base/file.h>
#include <android-base/logging.h>
#include <linux/input.h>

namespace aidl {
namespace android {
namespace hardware {
namespace power {
namespace impl {

using ::aidl::android::hardware::power::Mode;

bool isDeviceSpecificModeSupported(Mode type, bool* _aidl_return) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE:
            *_aidl_return = true;
            return true;
        default:
            return false;
    }
}

bool setDeviceSpecificMode(Mode type, bool enabled) {
    switch (type) {
        case Mode::DOUBLE_TAP_TO_WAKE:
            ::android::base::WriteStringToFile(enabled ? "1" : "0", "/sys/devices/virtual/input/lge_touch/tap2wake", true);
            return true;
        default:
            return false;
    }
}

}  // namespace impl
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl