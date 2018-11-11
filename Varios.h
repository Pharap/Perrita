#pragma once

#include "FlashString.h"

//FUNCIONES VARIAS.
//**************************************************************************************************
const char PROGMEM TextoFracasarA0[]="YOU FAILED";
const char PROGMEM TextoFracasarA1[]="FRACASASTE";

const char* const PROGMEM TextoFracasarTabla[]={
TextoFracasarA0,TextoFracasarA1};
//**************************************************************************************************
void EsperarBotonA()
//Funcion que se asegura que pulses y sueltes el boton A.
{
	arduboy.display();
	arduboy.waitNoButtons();
	while(!arduboy.pressed(A_BUTTON));
	arduboy.waitNoButtons();
}
//**************************************************************************************************
void PintaPerritaTriste()
//Dibuja la pantalla de finalizacion de juego por perdida de vidas.
{
	arduboy.clear();
	arduboy.drawCompressed(64,0,PerritaTriste);
	font3x5.setCursor(0,30);
	font3x5.println(AsFlashString(pgm_read_ptr(&TextoFracasarTabla[bIdioma])));

	EsperarBotonA();
}
//**************************************************************************************************
//Gestiona la vida y los huesos que se muestran en pantalla.
void PintaVida()
{
	arduboy.fillRect(0,0,49,9,BLACK);
	arduboy.drawCompressed(0,0,CorazonHueso);

	font3x5.setCursor(10, 0);
	font3x5.print(bVidas);
	font3x5.setCursor(22, 0);
	font3x5.print(bHuesos);
	font3x5.setCursor(44, 0);
	font3x5.print(bLlaves);
  
} 
//**************************************************************************************************
void Pita(int iB1, byte bTiempo1, int iB2, byte bTiempo2)
//iB1-Frecuencia del canal 1.
//iB2-Frecuencia del canal 2.
//bTiempo1-Tiempo de ejecucion canal 1.
//bTiempo2-Tiempo de ejecucion canal 2.
{
	beep1.tone(beep1.freq(iB1), bTiempo1); // 1000Hz for 2 seconds
	beep2.tone(beep2.freq(iB2), bTiempo2); // 1000Hz for 2 seconds
}
//**************************************************************************************************
void TocaSonido()
//Mira si hay que tocar algo y lo toca.
//Usa la variable global:  bSonido; //0-Parar, 1-254 Toca un sonido, 255-No hace nada.
{
	switch (bSonido){
		case 0: //Para lo que este sonando.
			beep1.noTone();
			beep2.noTone();
			break;
		case cSonidoA:
			Pita(950,30,900,30);
			break;
		case 255: //No hace nada.
			break;
		default:
			break;
	} //End switch
	bSonido=255;
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************

