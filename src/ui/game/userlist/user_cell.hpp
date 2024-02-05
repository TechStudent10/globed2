#pragma once
#include <defs.hpp>

#include <data/types/gd.hpp>
#include <game/player_store.hpp>

class GlobedUserCell : public cocos2d::CCLayer {
public:
    static constexpr float CELL_HEIGHT = 45.f;

    void refreshData(const PlayerStore::Entry& entry);

    static GlobedUserCell* create(const PlayerStore::Entry& entry, const PlayerAccountData& data);

    int playerId;

private:
    cocos2d::CCLabelBMFont* percentageLabel;
    uint16_t lastPercentage = static_cast<uint16_t>(-1);
    PlayerStore::Entry _data;

    bool init(const PlayerStore::Entry& entry, const PlayerAccountData& data);
    void onOpenProfile(cocos2d::CCObject*);
};