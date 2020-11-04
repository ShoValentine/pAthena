// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef LOG_HPP
#define LOG_HPP

#include <string>

#include "../common/cbasetypes.hpp"
#include "../common/mmo.hpp"

struct block_list;
struct map_session_data;
struct mob_data;
struct item;

enum e_log_chat_type : uint8
{
	LOG_CHAT_NONE        = 0,
	LOG_CHAT_GLOBAL      = 0x01,
	LOG_CHAT_WHISPER     = 0x02,
	LOG_CHAT_PARTY       = 0x04,
	LOG_CHAT_GUILD       = 0x08,
	LOG_CHAT_MAINCHAT    = 0x10,
	LOG_CHAT_CLAN        = 0x20,
	// all
	LOG_CHAT_ALL         = 0xFF,
};

enum e_log_pick_type : uint32
{
	LOG_TYPE_NONE             = 0,
	LOG_TYPE_TRADE            = 0x000001,
	LOG_TYPE_VENDING          = 0x000002,
	LOG_TYPE_PICKDROP_PLAYER  = 0x000004,
	LOG_TYPE_PICKDROP_MONSTER = 0x000008,
	LOG_TYPE_NPC              = 0x000010,
	LOG_TYPE_SCRIPT           = 0x000020,
	LOG_TYPE_STEAL            = 0x000040,
	LOG_TYPE_CONSUME          = 0x000080,
	LOG_TYPE_PRODUCE          = 0x000100,
	LOG_TYPE_MVP              = 0x000200,
	LOG_TYPE_COMMAND          = 0x000400,
	LOG_TYPE_STORAGE          = 0x000800,
	LOG_TYPE_GSTORAGE         = 0x001000,
	LOG_TYPE_MAIL             = 0x002000,
	LOG_TYPE_AUCTION          = 0x004000,
	LOG_TYPE_BUYING_STORE     = 0x008000,
	LOG_TYPE_OTHER            = 0x010000,
	LOG_TYPE_CASH             = 0x020000,
	LOG_TYPE_BANK             = 0x040000,
	LOG_TYPE_BOUND_REMOVAL    = 0x080000,
	LOG_TYPE_ROULETTE         = 0x100000,
	LOG_TYPE_MERGE_ITEM       = 0x200000,
	LOG_TYPE_QUEST            = 0x400000,
	LOG_TYPE_PRIVATE_AIRSHIP  = 0x800000,
	// combinations
	LOG_TYPE_LOOT             = LOG_TYPE_PICKDROP_MONSTER|LOG_TYPE_CONSUME,
	// all
	LOG_TYPE_ALL              = 0xFFFFFF,
};

enum e_log_cash_type : uint8
{
	LOG_CASH_TYPE_CASH = 0x1,
	LOG_CASH_TYPE_KAFRA = 0x2
};

enum e_log_feeding_type : uint8 
{
	LOG_FEED_HOMUNCULUS = 0x1,
	LOG_FEED_PET        = 0x2,
};

/// new logs
void log_pick_pc(struct map_session_data* sd, e_log_pick_type type, int amount, struct item* itm);
void log_pick_mob(struct mob_data* md, e_log_pick_type type, int amount, struct item* itm);
void log_zeny(struct map_session_data* sd, e_log_pick_type type, struct map_session_data* src_sd, int amount);
void log_cash( struct map_session_data* sd, e_log_pick_type type, e_log_cash_type cash_type, int amount );
void log_npc( struct npc_data* nd, const char* message );
void log_npc(struct map_session_data* sd, const char *message);
void log_chat(e_log_chat_type type, int type_id, int src_charid, int src_accid, const char* map, int x, int y, const char* dst_charname, const char* message);
void log_atcommand(struct map_session_data* sd, const char* message);
void log_feeding(struct map_session_data *sd, e_log_feeding_type type, t_itemid nameid);

/// old, but useful logs
void log_branch(struct map_session_data* sd);
void log_mvpdrop(struct map_session_data* sd, int monster_id, t_itemid nameid, t_exp exp);

int log_config_read(const char* cfgName);

/// Log Config structure
struct Log_Config {
	uint32 enable_logs;				///< Values @see e_log_pick_type
	uint16 filter;					///< Values @see e_log_filter
	bool sql_logs;					///< Enable SQL log instead of file log
	bool log_chat_woe_disable;		///< Disable chat logging on WOE

	bool cash;						///< Log cash usage
	bool branch;					///< Log item branch usage
	bool mvpdrop;					///< Log MVP Drop
	uint32 zeny;					///< Log Zeny usage if zeny spent is more than 'zeny'
	bool commands;					///< Log Comman usage
	bool npc;						///< Log NPC 'logmes' command
	uint8 chat;						///< Log Chat @see e_log_chat_type
	uint8 feeding;					///< Log Feeding usage

	// Filter
	uint16 rare_items_log;			///< Log if droprate is less than 'rare_items_log'
	uint8 refine_items_log;			///< Log if refine value is more than 'refine_items_log'
	uint32 price_items_log;			///< Log if item buy price is more than 'price_items_log'
	uint16 amount_items_log;		///< Log if single item amount is more than 'amount_items_log'

	std::string log_path;			///< Path to log file (Used if 'sql_logs' is no)
	std::string log_ext;			///< Log file extension (Used if 'sql_logs' is no)
	std::string log_timestamp;		///< Time Stamp format for logs

	struct s_log_schema_config {
		std::string branch_table;	///< Branch log table/file with path
		std::string cash_table;		///< Cash log table/file with path
		std::string chat_table;		///< Chat log table/file with path
		std::string command_table;	///< Command log table/file with path
		std::string mvpdrop_table;	///< MVP Drop log table/file with path
		std::string npc_table;		///< NPC log table/file with path
		std::string pick_table;		///< Pick log table/file with path
		std::string zeny_table;		///< Zeny log table/file with path
		std::string feeding_table;	///< Feeding log table/file with path
	} schema;						///< Log filepathes or tables
};
/// Log Config used values
extern struct Log_Config log_config;

void log_config_init(void);
void log_config_final(void);
void log_config_read_done(void);
bool log_check_tables(void);

#endif /* LOG_HPP */
