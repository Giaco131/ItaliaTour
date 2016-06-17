#include "librerie.h"

void creazioneCitta(){
    ofstream file;
    file.open("citta.html");
    
    file<<"<html>"<<endl;
    file<<"\t<head>"<<endl;
    file<<"\t\t<title>Citta</title>"<<endl;
    file<<"\t</head>"<<endl;
    file<<"\t<body bgcolor=\"orange\">"<<endl;
    file<<"\t\t<h1>Citt&agrave</h1>"<<endl;
    file<<"\t\t<table align=\"center\" bgcolor=\"lightblue\" border=1 width=100%>"<<endl;
    file<<"\t\t\t<tr>"<<endl;
    file<<"\t\t\t\t<td><h3>Citt&agrave</h3></td>"<<endl;
    file<<"\t\t\t\t<td><h3>Regione</h3></td>"<<endl;
    file<<"\t\t\t\t<td><h3>Abitanti</h3></td>"<<endl;
    file<<"\t\t\t\t<td><h3>Superficie</h3></td>"<<endl;
    file<<"\t\t\t\t<td><h3>Longitudine</h3></td>"<<endl;
    file<<"\t\t\t\t<td><h3>Latitudine</h3></td>"<<endl;
    file<<"\t\t\t\t</tr>"<<endl;
    
    sqlite3_stmt *stmt = NULL;
    sqlite3 *db;
    int rc;
    
    rc = sqlite3_open("database.db",&db);
    if(rc == SQLITE_OK){
        rc = sqlite3_prepare_v2(db, "select * from citta;", -1, &stmt, NULL);
        
        if (rc == SQLITE_OK){
            rc = sqlite3_step(stmt);
            
            while (rc != SQLITE_DONE && rc != SQLITE_OK){
                file<<"\t\t\t<tr>"<<endl;
                
                file<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, 0)<<"</td>"<<endl;
                file<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, 1)<<"</td>"<<endl;
                file<<"\t\t\t\t<td>"<<sqlite3_column_int(stmt, 2)<<"</td>"<<endl;
                file<<"\t\t\t\t<td>"<<sqlite3_column_double(stmt, 3)<<"</td>"<<endl;
                file<<"\t\t\t\t<td>"<<sqlite3_column_double(stmt, 4)<<"</td>"<<endl;
                file<<"\t\t\t\t<td>"<<sqlite3_column_double(stmt, 5)<<"</td>"<<endl;
                
                file<<"\t\t\t</tr>"<<endl;
                
                rc = sqlite3_step(stmt);
            }
        }
    }
    
    file<<"\t\t</table>"<<endl;
    file<<"\t</body>"<<endl;
    file<<"</head>"<<endl;
    
    file.close();
    sqlite3_close(db);
}

/*void creazionePuntiInteresse(){
    ofstream file;
    
    sqlite3_stmt *stmt = NULL;
    sqlite3 *db;
    int rc, i, j;
    
    rc = sqlite3_open("database.db",&db);
    if(rc != SQLITE_OK)
        return 1;
    
    rc = sqlite3_prepare_v2(db, "select * from citta;", -1, &stmt, NULL);
    if (rc != SQLITE_OK)
        return 1;

    italia.numCitta=0;
    
    rc = sqlite3_step(stmt);
    
    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        for(i=0; i<MAX_COL_CITTA ;i++){
            switch( i ){
                case 0:{
                    const unsigned char* nomeCitta = sqlite3_column_text(stmt, i);
                    
                    for(j=0; nomeCitta[j] ; j++)
                        italia.citta[italia.numCitta].nomeCitta[j]=nomeCitta[j];
                    italia.citta[italia.numCitta].nomeCitta[j]=nomeCitta[j];
                    
                    break;
                }
                case 1:{
                    const unsigned char* nomeRegione = sqlite3_column_text(stmt, i);
                    
                    for(j=0; nomeRegione[j] ; j++)
                        italia.citta[italia.numCitta].nomeRegione[j]=nomeRegione[j];
                    italia.citta[italia.numCitta].nomeRegione[j]=nomeRegione[j];
                    
                    break;
                }
                case 2:{
                    italia.citta[italia.numCitta].abitanti=sqlite3_column_int(stmt, i);
                        
                    break;
                }
                case 3:{
                    italia.citta[italia.numCitta].superficie=sqlite3_column_double(stmt, i);
                        
                    break;
                }
                case 4:{
                    italia.citta[italia.numCitta].coord.x=sqlite3_column_double(stmt, i);
                        
                    break;
                }
                case 5:{
                    italia.citta[italia.numCitta].coord.y=sqlite3_column_double(stmt, i);
                        
                    break;
                }
                default:{
                    break;
                }
                
            }
        }
        
        rc = sqlite3_step(stmt);
        italia.numCitta++;
    }

    sqlite3_close(db);
}*/