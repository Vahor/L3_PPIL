//
// Created by Nathan David on 26/01/2022.
//

#include "scene/SceneDao.h"

SceneDao *SceneDao::instance_ = {nullptr};

SceneDao *SceneDao::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new SceneDao();
    }
    return instance_;
}
