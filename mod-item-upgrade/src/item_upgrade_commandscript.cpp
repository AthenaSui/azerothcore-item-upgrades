/*
 * Credits: silviu20092
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "CommandScript.h"
#include "item_upgrade.h"

using namespace Acore::ChatCommands;

class item_upgrade_commandscript : public CommandScript
{
public:
    item_upgrade_commandscript() : CommandScript("item_upgrade_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable itemUpgradeSubcommandTable =
        {
            { "reload", HandleReloadModItemUpgrade, SEC_ADMINISTRATOR, Console::Yes },
            { "lock",   HandleLockItemUpgrade,      SEC_ADMINISTRATOR, Console::Yes }
        };

        static ChatCommandTable itemUpgradeCommandTable =
        {
            { "item_upgrade", itemUpgradeSubcommandTable }
        };

        return itemUpgradeCommandTable;
    }
private:
    static bool HandleReloadModItemUpgrade(ChatHandler* handler)
    {
        ItemUpgrade::PagedDataMap& pagedData = sItemUpgrade->GetPagedDataMap();
        for (auto& itr : pagedData)
            itr.second.reloaded = true;

        sItemUpgrade->SetReloading(true);
        sItemUpgrade->HandleDataReload(false);

        sItemUpgrade->LoadFromDB(true);

        sItemUpgrade->HandleDataReload(true);
        sItemUpgrade->SetReloading(false);

        handler->SendGlobalGMSysMessage("物品升级模块数据重载成功。");
        return true;
    }

    static bool HandleLockItemUpgrade(ChatHandler* handler)
    {
        sItemUpgrade->SetReloading(true);
        handler->SendSysMessage("物品升级NPC已锁定，现在可以安全编辑数据库表了。使用.item_upgrade reload命令解除锁定。");
        return true;
    }
};

void AddSC_item_upgrade_commandscript()
{
    new item_upgrade_commandscript();
}
