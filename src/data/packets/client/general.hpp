#pragma once
#include <data/packets/packet.hpp>
#include <data/types/gd.hpp>
#include <data/types/room.hpp>

// 11000 - SyncIconsPacket
class SyncIconsPacket : public Packet {
    GLOBED_PACKET(11000, SyncIconsPacket, false, false)

    SyncIconsPacket() {}
    SyncIconsPacket(const PlayerIconData& icons) : icons(icons) {}

    PlayerIconData icons;
};

GLOBED_SERIALIZABLE_STRUCT(SyncIconsPacket, (icons));

// 11001 - RequestGlobalPlayerListPacket
class RequestGlobalPlayerListPacket : public Packet {
    GLOBED_PACKET(11001, RequestGlobalPlayerListPacket, false, false)

    RequestGlobalPlayerListPacket() {}
};

GLOBED_SERIALIZABLE_STRUCT(RequestGlobalPlayerListPacket, ());

// 11002 - RequestLevelListPacket
class RequestLevelListPacket : public Packet {
    GLOBED_PACKET(11002, RequestLevelListPacket, false, false)

    RequestLevelListPacket() {}
};

GLOBED_SERIALIZABLE_STRUCT(RequestLevelListPacket, ());

// 11003 - RequestPlayerCountPacket
class RequestPlayerCountPacket : public Packet {
    GLOBED_PACKET(11003, RequestPlayerCountPacket, false, false)

    RequestPlayerCountPacket() {}
    RequestPlayerCountPacket(std::vector<LevelId>&& levelIds) : levelIds(std::move(levelIds)) {}

    std::vector<LevelId> levelIds;
};

GLOBED_SERIALIZABLE_STRUCT(RequestPlayerCountPacket, (levelIds));

class SetPlayerToInvisiblePacket : public Packet{
    GLOBED_PACKET(11004, SetPlayerToInvisiblePacket, false, false);

    SetPlayerToInvisiblePacket() {}
    SetPlayerToInvisiblePacket(bool is_invisible) : is_invisible(is_invisible) {}

    bool is_invisible;
};

GLOBED_SERIALIZABLE_STRUCT(SetPlayerToInvisiblePacket, (is_invisible));