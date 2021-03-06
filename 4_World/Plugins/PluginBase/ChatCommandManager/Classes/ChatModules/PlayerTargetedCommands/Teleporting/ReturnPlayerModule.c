class ReturnPlayerChatModule : ChatCommand
{
	override void ExecuteCommand(PlayerBase caller, array<Man> targets, array<string> args)
    {
        PlayerIdentity identity = caller.GetIdentity();

        if(identity == null) return;

        string callerID;
        string callerName;

        if(identity != null)
        {
            callerID = identity.GetPlainId();           
            callerName = identity.GetName();
        }

        foreach(Man target : targets)
        {
            PlayerBase playerTarget = PlayerBase.Cast(target);
            PlayerIdentity targetIdentity = playerTarget.GetIdentity();

            if(playerTarget != null && targetIdentity != null)
            {
                string targetName = targetIdentity.GetName();
                string targetID = targetIdentity.GetPlainId();

				GetTeleportManager().ReturnPlayer(target, callerID);
				GetWebHooksManager().PostData(AdminActivityMessage, new AdminActivityMessage(callerID, callerName, "Chat Command Manager: /return command used on: " + targetName + " ID: " + targetID));
            }
        }
    }
}