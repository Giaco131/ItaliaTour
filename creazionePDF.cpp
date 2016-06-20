#include "librerie.h"

void creazionePdf(){
	
	system("wkhtmltopdf.exe fileHTML/citta.html filePDF/citta.pdf");
	system("wkhtmltopdf.exe fileHTML/puntiInteresse.html filePDF/puntiInteresse.pdf");
	
}