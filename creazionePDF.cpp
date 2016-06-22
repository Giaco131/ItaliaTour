#include "librerie.h"

void creazionePdf(const config &configurazione){
	char comandoPdf_Citta[MAX_PERCORSO], comandoPdf_PuntiInteresse[MAX_PERCORSO];
    
    cout<<"Creazione Pdf delle citta'"<<endl<<endl;
    strcpy(comandoPdf_Citta, "wkhtmltopdf.exe ");
    strcat(comandoPdf_Citta, configurazione.percorsoHtml);
    strcat(comandoPdf_Citta,"Citta.html ");
    strcat(comandoPdf_Citta, configurazione.percorsoPdf);
    strcat(comandoPdf_Citta, "Citta.pdf");
    
    system(comandoPdf_Citta);
    
    cout<<endl<<endl<<endl;
    
    cout<<"Creazione Pdf dei punti di interesse delle citta'"<<endl<<endl;
    strcpy(comandoPdf_PuntiInteresse, "wkhtmltopdf.exe ");
    strcat(comandoPdf_PuntiInteresse, configurazione.percorsoHtml);
    strcat(comandoPdf_PuntiInteresse,"Punti_Di_Interesse.html ");
    strcat(comandoPdf_PuntiInteresse, configurazione.percorsoPdf);
    strcat(comandoPdf_PuntiInteresse, "Punti_Di_Interesse.pdf");
	
    system(comandoPdf_PuntiInteresse);
    system("PAUSE");
    system("cls");
}