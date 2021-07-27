#include <iostream> 
#include <sqlite3.h>
#include <string> 

static int callback(void* data, int argc, char** argv, char** azColName){               
    int i; 
   
        for (i = 0; i < argc; i++) 
        { 
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
        } 
  
        printf("\n"); 
        
        return 0; 
    }


/*
--------------------------------------------------------------------------------------------------
EDIT TABLE FUNCTION:
ARGUMENTS: pointer to database, sql command passed as a string, target table passed as a string
Description: editTable() function will take in a database and edit the database based off the command
             that was passed through. Ensure the command is correct syntax.
--------------------------------------------------------------------------------------------------
*/

/*
void editTable(sqlite3 * db, string command, string target)
{
    int exit = 0;
    char * messageError;
    string sql(command);
        exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError); 
        if (exit != SQLITE_OK) 
        { 
            cout << "--------------------------------------------------------- \n";
            cout << "Error Editing " + target << std::endl; 
            sqlite3_free(messageError); 
        } 
        else
        {
            cout << "--------------------------------------------------------- \n";            
            cout << target +" Edited Successfully" << std::endl; 
        }
}
*/

int main(){
	
	sqlite3* DB;

	int exit = 0;
    char * messageError;
		
    exit = sqlite3_open("casinodata.db", &DB); //open the database
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;

    
    // code creates a Player table if one does not already exist
    std::string PLAYERS = "CREATE TABLE PLAYERS(" 
                        "ID INTEGER PRIMARY KEY,"
                        "FIRSTNAME TEXT NOT NULL,"
                        "LASTNAME TEXT NOT NULL,"
                        "BALANCE REAL NOT NULL,"
                        "DEPOSIT REAL NOT NULL,"
                        "WITHDRAW REAL,"
                        "GAMESPLAYED INTEGER,"
                        "WINS INTEGER,"
                        "LOSSES INTEGER,"
                        "CHEATER INTEGER);";

    std::string GAMES = "CREATE TABLE GAMES("
                         "ID INTEGER PRIMARY KEY,"
                         "NAME TEXT NOT NULL,"
                         "WINS INTEGER,"
                         "LOSSES INTEGER,"
                         "GAMESPLAYED INTEGER,"
                         "AMOUNT_WON INTEGER,"
                         "AMOUNT_LOST INTEGER);";
    
    std::string DEALERS = "CREATE TABLE DEALERS("
                          "ID INTEGER PRIMARY KEY,"
                          "FIRSTNAME TEXT NOT NULL,"
                          "LASTNAME TEXT NOT NULL,"
                          "GAMESDEALT INTEGER);";

                                              
    // execute the create table command
    //sqlite3_exec( pointer to database file, string for sql command, callback function (used to respond to queries, not used here), input to callback, error message address)
    
    
     
    
    exit = sqlite3_exec(DB, PLAYERS.c_str(), NULL, 0, &messageError);  
    if (exit != SQLITE_OK) 
        { 
            std::cout << "--------------------------------------------------------- \n";
            std::cout << "Error Editing " << std::endl; 
            sqlite3_free(messageError); 
        } 
        else
        {
            std::cout << "--------------------------------------------------------- \n";            
            std::cout << " Edited Successfully" << std::endl; 
        }

    
    exit = sqlite3_exec(DB, GAMES.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) 
        { 
            std::cout << "--------------------------------------------------------- \n";
            std::cout << "Error Editing " << std::endl; 
            sqlite3_free(messageError); 
        } 
    else
    {
        std::cout << "--------------------------------------------------------- \n";            
        std::cout << " Edited Successfully" << std::endl; 
    }

    exit = sqlite3_exec(DB, DEALERS.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) 
        { 
            std::cout << "--------------------------------------------------------- \n";
            std::cout << "Error Editing " << std::endl; 
            sqlite3_free(messageError); 
        } 
    else
    {
        std::cout << "--------------------------------------------------------- \n";            
        std::cout << " Edited Successfully" << std::endl; 
    }

    std::string Player("INSERT INTO PLAYERS VALUES(0000,'test','tester',1000.0,0.0,0.0,0,0,0,0);");
    exit = sqlite3_exec(DB, Player.c_str(), NULL, 0, &messageError); //inserts a test user with an id of 0

    std::string BlackJack("INSERT INTO GAMES VALUES(1,'BlackJack',0,0,0,0,0);");
    exit = sqlite3_exec(DB, BlackJack.c_str(), NULL, 0, &messageError);//adds Black Jack to the table with ID 1

    std::string Keno("INSERT INTO GAMES VALUES(2,'Keno',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Keno.c_str(), NULL, 0, &messageError);

    std::string Poker("INSERT INTO GAMES VALUES(3,'Poker',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Poker.c_str(), NULL, 0, &messageError);

    std::string Roulette("INSERT INTO GAMES VALUES(4,'Roulette',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Roulette.c_str(), NULL, 0, &messageError);

    std::string Slots("INSERT INTO GAMES VALUES(5,'Slots',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Slots.c_str(), NULL, 0, &messageError);


    std::string Bingo("INSERT INTO GAMES VALUES(6,'Bingo',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Bingo.c_str(), NULL, 0, &messageError);

    std::string Craps("INSERT INTO GAMES VALUES(7,'Craps',0,0,0,0,0);");
    exit = sqlite3_exec(DB, Craps.c_str(), NULL, 0, &messageError);




    sqlite3_close(DB);//closes the database
        
        
     

    return 0;
}