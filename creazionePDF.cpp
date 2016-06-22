#include "librerie.h"

void creazionePdf(){
	
	system("wkhtmltopdf.exe fileHTML/citta.html filePDF/citta.pdf");
	system("wkhtmltopdf.exe fileHTML/\"Punti Di Interesse.html\" filePDF/puntiInteresse.pdf");
	
}