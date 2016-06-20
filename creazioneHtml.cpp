#include "librerie.h"

void creazioneCitta(){
    ofstream file;
    file.open("fileHTML/citta.html");
    
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

void creazionePuntiInteresse(){
    ofstream file;
    
    file.open("fileHTML/puntiInteresse.html");
    
    file<<"<html>"<<endl;
    file<<"\t<head>"<<endl;
    file<<"\t\t<title>Punti di interesse</title>"<<endl;
    file<<"\t</head>"<<endl;
    file<<"\t<body bgcolor=\"orange\">"<<endl;
    file<<"\t\t<h1>Punti di Interesse</h1>"<<endl;
    file<<"\t\t<table align=\"center\" bgcolor=\"lightblue\" border=1 width=100%>"<<endl;
    file<<"\t\t\t<tr>"<<endl;
    file<<"\t\t\t\t<td><h3>Citt&agrave</h3></td>"<<endl;
    
    int i;
    for(i=0; i<MAX_HOTEL; i++){
        file<<"\t\t\t\t<td><h3>Hotel</h3></td>"<<endl;
        file<<"\t\t\t\t<td><h3>Indirizzo</h3></td>"<<endl;
    }
    
    for(i=0; i<MAX_RISTORANTI ;i++){
        file<<"\t\t\t\t<td><h3>Ristorante</h3></td>"<<endl;
        file<<"\t\t\t\t<td><h3>Indirizzo</h3></td>"<<endl;
    }
    
    file<<"\t\t\t\t</tr>"<<endl;
    
    sqlite3_stmt *stmt = NULL;
    sqlite3 *db;
    int rc;
    
    rc = sqlite3_open("database.db",&db);
    if(rc == SQLITE_OK){
        rc = sqlite3_prepare_v2(db, "select * from puntiInteresse;", -1, &stmt, NULL);
        
        if (rc == SQLITE_OK){
            rc = sqlite3_step(stmt);
            
            while (rc != SQLITE_DONE && rc != SQLITE_OK){
                int j;
                int indCol=0;
                
                file<<"\t\t\t<tr>"<<endl;
                
                file<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                indCol++;
                
                for(j=0; j<MAX_HOTEL*2 ; j++){
                    file<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                    indCol++;
                }
                
                for(j=0; j<MAX_RISTORANTI*2 ; j++){
                    file<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                    indCol++;
                }
                
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