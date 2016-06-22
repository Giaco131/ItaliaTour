#include "librerie.h"

void creazioneCitta(const char percorso[]){
    ofstream file;
    char percorsoCitta[MAX_PERCORSO];
    
    strcpy(percorsoCitta, percorso);
    strcat(percorsoCitta, "Citta.html");
    
    file.open(percorsoCitta);
    
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

void creazionePuntiInteresse(const char percorso[]){
    ofstream filePuntiInteresse;
    char percorsoPuntiInteresse[MAX_PERCORSO];
    
    strcpy(percorsoPuntiInteresse, percorso);
    strcat(percorsoPuntiInteresse,"Punti_Di_Interesse.html");
    
    filePuntiInteresse.open(percorsoPuntiInteresse);
    
    filePuntiInteresse<<"<html>"<<endl;
    
    filePuntiInteresse<<"\t<head>"<<endl;
    filePuntiInteresse<<"\t\t<title>Punti di Interesse</title>"<<endl;
    filePuntiInteresse<<"\t</head>"<<endl;
    
    filePuntiInteresse<<"\t<body bgcolor=\"orange\">"<<endl;
    filePuntiInteresse<<"\t\t<h1>Punti di Interesse</h1>"<<endl;
    
    filePuntiInteresse<<"\t\t<table align=\"center\" bgcolor=\"lightblue\" border=1 width=100%>"<<endl;
    
    filePuntiInteresse<<"\t\t\t<tr>"<<endl;
    
     filePuntiInteresse<<"\t\t\t\t<td><h3>Citt&agrave</h3></td>"<<endl;
     filePuntiInteresse<<"\t\t\t\t<td><h3>Tipo</h3></td>"<<endl;
     filePuntiInteresse<<"\t\t\t\t<td><h3>Nome</h3></td>"<<endl;
     filePuntiInteresse<<"\t\t\t\t<td><h3>Indirizzo</h3></td>"<<endl;
    
    filePuntiInteresse<<"\t\t\t</tr>"<<endl;
    
    sqlite3_stmt *stmt = NULL;
    sqlite3 *db;
    int rc;
    
    rc = sqlite3_open("database.db",&db);
    if(rc == SQLITE_OK){
        rc = sqlite3_prepare_v2(db, "select * from puntiInteresse;", -1, &stmt, NULL);
        
        if (rc == SQLITE_OK){
            rc = sqlite3_step(stmt);
            
            while (rc != SQLITE_DONE && rc != SQLITE_OK){
                int i, indCol=0;
                
                filePuntiInteresse<<"\t\t\t<tr>"<<endl;
                
                 filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;//Fase lettura Hotel
                 indCol++;
                 
                 filePuntiInteresse<<"\t\t\t\t<td>Hotel</td>"<<endl;
                
                for(i=0; i<2 ;i++){                                                                   //Leggo il primo con l'indirizzo
                    filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                    indCol++;
                }
                
                for(i=0; i<MAX_HOTEL-1 ; i++){                                                        //Leggo i rimanenti Hotel
                    filePuntiInteresse<<"\t\t\t<tr>"<<endl;
                     
                     filePuntiInteresse<<"\t\t\t\t<td></td>"<<endl;
                     filePuntiInteresse<<"\t\t\t\t<td>Hotel</td>"<<endl;
                     filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                     indCol++;
                     filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                     indCol++;
                     
                    filePuntiInteresse<<"\t\t\t</tr>"<<endl; 
                }
                
                
                for(i=0; i<MAX_RISTORANTI ; i++){                                                     //Leggo i ristoranti
                    filePuntiInteresse<<"\t\t\t<tr>"<<endl;
                     
                     filePuntiInteresse<<"\t\t\t\t<td></td>"<<endl;
                     filePuntiInteresse<<"\t\t\t\t<td>Ristorante</td>"<<endl;
                     filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                     indCol++;
                     filePuntiInteresse<<"\t\t\t\t<td>"<<sqlite3_column_text(stmt, indCol)<<"</td>"<<endl;
                     indCol++;
                     
                    filePuntiInteresse<<"\t\t\t</tr>"<<endl; 
                }
                
                filePuntiInteresse<<"\t\t\t</tr>"<<endl;
                
                rc = sqlite3_step(stmt);
            }
        }
    }
    
    filePuntiInteresse<<"\t\t</table>"<<endl;
    filePuntiInteresse<<"\t</body>"<<endl;
    filePuntiInteresse<<"</head>"<<endl;
    
    filePuntiInteresse.close();
    sqlite3_close(db);
}