/*********************************************************
 *  updates match status in database
 * 
 * @param  Database			timer handle
 * @param  Status			  string message
 * @noreturn
 *********************************************************/
stock UpdateMatchStatus(Handle:database, char[] status)
{
  char query[256];
  Format(query,sizeof(query), "UPDATE `matches` SET `status` = '%s' WHERE `id` = '%i'", status, MatchID);
  SQL_Query(database, query);
}

/*********************************************************
 *  updates player status in database
 * 
 * @param  Database			timer handle
 * @param  MatchID			integer
 * @param  SteamID			string
 * @param  Status			  string message
 * @noreturn
 *********************************************************/
stock UpdatePlayerStatus(Handle:database, int match, const char[] steam_id, char[] status)
{
  char query[256];
  
  Format(query,sizeof(query), "UPDATE `teams` SET `status` = '%s' WHERE `match_id` = '%i' AND `player_id` = (SELECT `id` FROM `players` WHERE `steamId` = '%s')",status, match, steam_id);
  SQL_Query(database, query);
}

stock Handle:MySQL_Connect()
{
  char error[256];

  db = SQL_Connect("gleague", true, error, sizeof(error));
  if(db == INVALID_HANDLE){
    SetFailState("Can't connect to database");
  }

  return db;
}