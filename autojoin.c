/*
 * purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include "purple.h"

PurplePlugin *plugin_handle = NULL;

static gint chat_invited_cb(PurpleAccount *account, const char *inviter,
                     const char *chat, const char *invite_message,
                     const GHashTable *components)
{
	return 1;
}

static gboolean
plugin_load(PurplePlugin *plugin)
{
	void *conv_handle = purple_conversations_get_handle();
	plugin_handle = plugin;
	purple_signal_connect(conv_handle, "chat-invited", plugin, PURPLE_CALLBACK(chat_invited_cb), NULL);
	
	return TRUE;
}

static gboolean
plugin_unload(PurplePlugin *plugin)
{
	plugin_handle = NULL;
    return TRUE;
}


static PurplePluginInfo info =
{
     PURPLE_PLUGIN_MAGIC,
     2,
     1,
     PURPLE_PLUGIN_STANDARD,
     NULL,
     0,
     NULL,
     PURPLE_PRIORITY_DEFAULT,
     "core-eionrobb-autojoin",
     "AutoJoin Chats",
     "1.0",
     "Auto accepts any chat invite",
     "Joins any chat request without displaying the 'do you want to join this chat' popup.",
     "Eion Robb <eion@gmail.com>",
     "",
     plugin_load,
     plugin_unload,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
	 /* padding */
     NULL,
     NULL,
     NULL,
     NULL
};

 static void
 init_plugin(PurplePlugin *plugin)
 {
 }

PURPLE_INIT_PLUGIN(autojoin, init_plugin, info)
