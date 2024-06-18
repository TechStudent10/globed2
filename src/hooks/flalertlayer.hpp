#pragma once
#include <defs/geode.hpp>
#include <Geode/modify/FLAlertLayer.hpp>

#include <util/time.hpp>

class $modify(HookedFLAlertLayer, FLAlertLayer) {
    struct Fields {
        bool blockClosing = false;
        util::time::time_point blockClosingUntil;
    };

    $override
    void keyBackClicked() override;

    template <typename Rep, typename Period>
    void blockClosingFor(util::time::duration<Rep, Period> duration) {
        m_fields->blockClosing = true;
        m_fields->blockClosingUntil = util::time::now() + duration;
    }
};
