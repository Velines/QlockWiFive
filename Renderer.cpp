/******************************************************************************
   Renderer.cpp
******************************************************************************/

#include "Renderer.h"

Renderer::Renderer() {
}

// Zeit in den Screenbuffer schreiben
void Renderer::setTime(uint8_t hours, uint8_t minutes, uint8_t language, word matrix[16]) {
	switch (language) {
	case LANGUAGE_DE_DE:
	case LANGUAGE_DE_SW:
	case LANGUAGE_DE_BA:
	case LANGUAGE_DE_SA:
		DE_ESIST;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 nach
			DE_FUENF;
			DE_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			DE_ZEHN;
			DE_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel nach
			if ((language == LANGUAGE_DE_SW) || (language == LANGUAGE_DE_SA)) {
				DE_VIERTEL;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_VIERTEL;
				DE_NACH;
				setHours(hours, false, language, matrix);
			}
			break;
		case 4:
			// 20 nach
			if (language == LANGUAGE_DE_SA) {
				DE_ZEHN;
				DE_VOR;
				DE_HALB;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_ZWANZIG;
				DE_NACH;
				setHours(hours, false, language, matrix);
			}
			break;
		case 5:
			// 5 vor halb
			DE_FUENF;
			DE_VOR;
			DE_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 6:
			// halb
			DE_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			DE_FUENF;
			DE_NACH;
			DE_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			if (language == LANGUAGE_DE_SA) {
				DE_ZEHN;
				DE_NACH;
				DE_HALB;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_ZWANZIG;
				DE_VOR;
				setHours(hours + 1, false, language, matrix);
			}
			break;
		case 9:
			// viertel vor
			if ((language == LANGUAGE_DE_SW) || (language == LANGUAGE_DE_BA) || (language == LANGUAGE_DE_SA)) {
				DE_DREIVIERTEL;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_VIERTEL;
				DE_VOR;
				setHours(hours + 1, false, language, matrix);
			}
			break;
		case 10:
			// 10 vor
			DE_ZEHN;
			DE_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			DE_FUENF;
			DE_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		default:
			;
		}
		break;
	case LANGUAGE_DE_MKF_DE:
	case LANGUAGE_DE_MKF_SW:
	case LANGUAGE_DE_MKF_BA:
	case LANGUAGE_DE_MKF_SA:
		DE_MKF_ESIST;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 nach
			DE_MKF_FUENF;
			DE_MKF_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			DE_MKF_ZEHN;
			DE_MKF_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel nach
			if ((language == LANGUAGE_DE_MKF_SW) || (language == LANGUAGE_DE_MKF_SA)) {
				DE_MKF_VIERTEL;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_MKF_VIERTEL;
				DE_MKF_NACH;
				setHours(hours, false, language, matrix);
			}
			break;
		case 4:
			// 20 nach
			if (language == LANGUAGE_DE_MKF_SA) {
				DE_MKF_ZEHN;
				DE_MKF_VOR;
				DE_MKF_HALB;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_MKF_ZWANZIG;
				DE_MKF_NACH;
				setHours(hours, false, language, matrix);
			}
			break;
		case 5:
			// 5 vor halb
			DE_MKF_FUENF;
			DE_MKF_VOR;
			DE_MKF_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 6:
			// halb
			DE_MKF_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			DE_MKF_FUENF;
			DE_MKF_NACH;
			DE_MKF_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			if (language == LANGUAGE_DE_MKF_SA) {
				DE_MKF_ZEHN;
				DE_MKF_NACH;
				DE_MKF_HALB;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_MKF_ZWANZIG;
				DE_MKF_VOR;
				setHours(hours + 1, false, language, matrix);
			}
			break;
		case 9:
			// viertel vor
			if ((language == LANGUAGE_DE_MKF_SW) || (language == LANGUAGE_DE_MKF_BA) || (language == LANGUAGE_DE_MKF_SA)) {
				DE_MKF_DREIVIERTEL;
				setHours(hours + 1, false, language, matrix);
			}
			else {
				DE_MKF_VIERTEL;
				DE_MKF_VOR;
				setHours(hours + 1, false, language, matrix);
			}
			break;
		case 10:
			// 10 vor
			DE_MKF_ZEHN;
			DE_MKF_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			DE_MKF_FUENF;
			DE_MKF_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		default:
			;
		}
		break;
	case LANGUAGE_D3:
		D3_ESISCH;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 nach
			D3_FUENF;
			D3_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			D3_ZEHN;
			D3_NACH;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertl nach
			D3_VIERTL;
			setHours(hours + 1, false, language, matrix);
			break;
		case 4:
			// 10 vor halb
			D3_ZEHN;
			D3_VOR;
			D3_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 5:
			// 5 vor halb
			D3_FUENF;
			D3_VOR;
			D3_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 6:
			// halb
			D3_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			D3_FUENF;
			D3_NACH;
			D3_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 10 nach halb
			D3_ZEHN;
			D3_NACH;
			D3_HALB;
			setHours(hours + 1, false, language, matrix);
			break;
		case 9:
			// viertel vor
			D3_DREIVIERTL;
			setHours(hours + 1, false, language, matrix);
			break;
		case 10:
			// 10 vor
			D3_ZEHN;
			D3_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			D3_FUENF;
			D3_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		}
		break;
	case LANGUAGE_CH_GS:
		if (minutes % 5) CH_GSI;
	case LANGUAGE_CH:
		CH_ESISCH;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 ab
			CH_FUEF;
			CH_AB;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 ab
			CH_ZAEAE;
			CH_AB;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel ab
			CH_VIERTU;
			CH_AB;
			setHours(hours, false, language, matrix);
			break;
		case 4:
			// 20 ab
			CH_ZWAENZG;
			CH_AB;
			setHours(hours, false, language, matrix);
			break;
		case 5:
			// 5 vor halb
			CH_FUEF;
			CH_VOR;
			CH_HAUBI;
			setHours(hours + 1, false, language, matrix);
			break;
		case 6:
			// halb
			CH_HAUBI;
			setHours(hours + 1, false, language, matrix);
			break;
		case 7:
			// 5 ab halb
			CH_FUEF;
			CH_AB;
			CH_HAUBI;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			CH_ZWAENZG;
			CH_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 9:
			// viertel vor
			CH_VIERTU;
			CH_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 10:
			// 10 vor
			CH_ZAEAE;
			CH_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			CH_FUEF;
			CH_VOR;
			setHours(hours + 1, false, language, matrix);
			break;
		default:
			;
		}
		break;
	case LANGUAGE_EN:
		EN_ITIS;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 nach
			EN_FIVE;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			EN_TEN;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel nach
			EN_A;
			EN_QUATER;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 4:
			// 20 nach
			EN_TWENTY;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 5:
			// 5 vor halb
			EN_TWENTY;
			EN_FIVE;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 6:
			// halb
			EN_HALF;
			EN_PAST;
			setHours(hours, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			EN_TWENTY;
			EN_FIVE;
			EN_TO;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			EN_TWENTY;
			EN_TO;
			setHours(hours + 1, false, language, matrix);
			break;
		case 9:
			// viertel vor
			EN_A;
			EN_QUATER;
			EN_TO;
			setHours(hours + 1, false, language, matrix);
			break;
		case 10:
			// 10 vor
			EN_TEN;
			EN_TO;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			EN_FIVE;
			EN_TO;
			setHours(hours + 1, false, language, matrix);
			break;
		}
		break;
	case LANGUAGE_ES:
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 1:
			// 5 nach
			ES_Y;
			ES_CINCO;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			ES_Y;
			ES_DIEZ;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel nach
			ES_Y;
			ES_CUARTO;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 4:
			// 20 nach
			ES_Y;
			ES_VEINTE;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 5:
			// 5 vor halb
			ES_Y;
			ES_VEINTICINCO;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 6:
			// halb
			ES_Y;
			ES_MEDIA;
			ES_hours(hours, matrix);
			setHours(hours, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			ES_MENOS;
			ES_VEINTICINCO;
			ES_hours(hours + 1, matrix);
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			ES_MENOS;
			ES_VEINTE;
			ES_hours(hours + 1, matrix);
			setHours(hours + 1, false, language, matrix);
			break;
		case 9:
			// viertel vor
			ES_MENOS;
			ES_CUARTO;
			ES_hours(hours + 1, matrix);
			setHours(hours + 1, false, language, matrix);
			break;
		case 10:
			// 10 vor
			ES_MENOS;
			ES_DIEZ;
			ES_hours(hours + 1, matrix);
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			ES_MENOS;
			ES_CINCO;
			ES_hours(hours + 1, matrix);
			setHours(hours + 1, false, language, matrix);
			break;
		}
		break;
	case LANGUAGE_FR:
		FR_ILEST;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			FR_hours(hours, matrix);
			break;
		case 1:
			// 5 nach
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_CINQ;
			break;
		case 2:
			// 10 nach
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_DIX;
			break;
		case 3:
			// viertel nach
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_ET;
			FR_QUART;
			break;
		case 4:
			// 20 nach
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_VINGT;
			break;
		case 5:
			// 5 vor halb
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_VINGT;
			FR_TRAIT;
			FR_CINQ;
			break;
		case 6:
			// halb
			setHours(hours, false, language, matrix);
			FR_hours(hours, matrix);
			FR_ET;
			FR_DEMIE;
			break;
		case 7:
			// 5 nach halb
			setHours(hours + 1, false, language, matrix);
			FR_hours(hours + 1, matrix);
			FR_MOINS;
			FR_VINGT;
			FR_TRAIT;
			FR_CINQ;
			break;
		case 8:
			// 20 vor
			setHours(hours + 1, false, language, matrix);
			FR_hours(hours + 1, matrix);
			FR_MOINS;
			FR_VINGT;
			break;
		case 9:
			// viertel vor
			setHours(hours + 1, false, language, matrix);
			FR_hours(hours + 1, matrix);
			FR_MOINS;
			FR_LE;
			FR_QUART;
			break;
		case 10:
			// 10 vor
			setHours(hours + 1, false, language, matrix);
			FR_hours(hours + 1, matrix);
			FR_MOINS;
			FR_DIX;
			break;
		case 11:
			// 5 vor
			setHours(hours + 1, false, language, matrix);
			FR_hours(hours + 1, matrix);
			FR_MOINS;
			FR_CINQ;
			break;
		}
		break;
	case LANGUAGE_IT:
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 1:
			// 5 nach
			IT_E2;
			IT_CINQUE;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 2:
			// 10 nach
			IT_E2;
			IT_DIECI;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 3:
			// viertel nach
			IT_E2;
			IT_UN;
			IT_QUARTO;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 4:
			// 20 nach
			IT_E2;
			IT_VENTI;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 5:
			// 5 vor halb
			IT_E2;
			IT_VENTI;
			IT_CINQUE;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 6:
			// halb
			IT_E2;
			IT_MEZZA;
			setHours(hours, false, language, matrix);
			IT_hours(hours, matrix);
			break;
		case 7:
			// 5 nach halb
			IT_MENO;
			IT_VENTI;
			IT_CINQUE;
			setHours(hours + 1, false, language, matrix);
			IT_hours(hours + 1, matrix);
			break;
		case 8:
			// 20 vor
			IT_MENO;
			IT_VENTI;
			setHours(hours + 1, false, language, matrix);
			IT_hours(hours + 1, matrix);
			break;
		case 9:
			// viertel vor
			IT_MENO;
			IT_UN;
			IT_QUARTO;
			setHours(hours + 1, false, language, matrix);
			IT_hours(hours + 1, matrix);
			break;
		case 10:
			// 10 vor
			IT_MENO;
			IT_DIECI;
			setHours(hours + 1, false, language, matrix);
			IT_hours(hours + 1, matrix);
			break;
		case 11:
			// 5 vor
			IT_MENO;
			IT_CINQUE;
			setHours(hours + 1, false, language, matrix);
			IT_hours(hours + 1, matrix);
			break;
		}
		break;
	case LANGUAGE_NL:
		NL_HETIS;
		switch (minutes / 5) {
		case 0:
			// glatte Stunde
			setHours(hours, true, language, matrix);
			break;
		case 1:
			// 5 nach
			NL_VIJF;
			NL_OVER;
			setHours(hours, false, language, matrix);
			break;
		case 2:
			// 10 nach
			NL_TIEN;
			NL_OVER;
			setHours(hours, false, language, matrix);
			break;
		case 3:
			// viertel nach
			NL_KWART;
			NL_OVER2;
			setHours(hours, false, language, matrix);
			break;
		case 4:
			// 10 vor halb
			NL_TIEN;
			NL_VOOR;
			NL_HALF;
			setHours(hours + 1, false, language, matrix);
			break;
		case 5:
			// 5 vor halb
			NL_VIJF;
			NL_VOOR;
			NL_HALF;
			setHours(hours + 1, false, language, matrix);
			break;
		case 6:
			// halb
			NL_HALF;
			setHours(hours + 1, false, language, matrix);
			break;
		case 7:
			// 5 nach halb
			NL_VIJF;
			NL_OVER;
			NL_HALF;
			setHours(hours + 1, false, language, matrix);
			break;
		case 8:
			// 20 vor
			NL_TIEN;
			NL_OVER;
			NL_HALF;
			setHours(hours + 1, false, language, matrix);
			break;
		case 9:
			// viertel vor
			NL_KWART;
			NL_VOOR2;
			setHours(hours + 1, false, language, matrix);
			break;
		case 10:
			// 10 vor
			NL_TIEN;
			NL_VOOR;
			setHours(hours + 1, false, language, matrix);
			break;
		case 11:
			// 5 vor
			NL_VIJF;
			NL_VOOR;
			setHours(hours + 1, false, language, matrix);
			break;
		}
		break;
	default:
		;
	}
}

// Stunden in den Screenbuffer schreiben
void Renderer::setHours(uint8_t hours, boolean glatt, uint8_t language, word matrix[16]) {
	switch (language) {
	case LANGUAGE_DE_DE:
	case LANGUAGE_DE_SW:
	case LANGUAGE_DE_BA:
	case LANGUAGE_DE_SA:
		if (glatt) {
			DE_UHR;
		}
		switch (hours) {
		case 0:
		case 12:
		case 24:
			DE_H_ZWOELF;
			break;
		case 1:
		case 13:
			if (glatt) {
				DE_H_EIN;
			}
			else {
				DE_H_EINS;
			}
			break;
		case 2:
		case 14:
			DE_H_ZWEI;
			break;
		case 3:
		case 15:
			DE_H_DREI;
			break;
		case 4:
		case 16:
			DE_H_VIER;
			break;
		case 5:
		case 17:
			DE_H_FUENF;
			break;
		case 6:
		case 18:
			DE_H_SECHS;
			break;
		case 7:
		case 19:
			DE_H_SIEBEN;
			break;
		case 8:
		case 20:
			DE_H_ACHT;
			break;
		case 9:
		case 21:
			DE_H_NEUN;
			break;
		case 10:
		case 22:
			DE_H_ZEHN;
			break;
		case 11:
		case 23:
			DE_H_ELF;
			break;
		default:
			;
		}
		break;
	case LANGUAGE_DE_MKF_DE:
	case LANGUAGE_DE_MKF_SW:
	case LANGUAGE_DE_MKF_BA:
	case LANGUAGE_DE_MKF_SA:
		if (glatt) {
			DE_MKF_UHR;
		}
		switch (hours) {
		case 0:
		case 12:
		case 24:
			DE_MKF_H_ZWOELF;
			break;
		case 1:
		case 13:
			if (glatt) {
				DE_MKF_H_EIN;
			}
			else {
				DE_MKF_H_EINS;
			}
			break;
		case 2:
		case 14:
			DE_MKF_H_ZWEI;
			break;
		case 3:
		case 15:
			DE_MKF_H_DREI;
			break;
		case 4:
		case 16:
			DE_MKF_H_VIER;
			break;
		case 5:
		case 17:
			DE_MKF_H_FUENF;
			break;
		case 6:
		case 18:
			DE_MKF_H_SECHS;
			break;
		case 7:
		case 19:
			DE_MKF_H_SIEBEN;
			break;
		case 8:
		case 20:
			DE_MKF_H_ACHT;
			break;
		case 9:
		case 21:
			DE_MKF_H_NEUN;
			break;
		case 10:
		case 22:
			DE_MKF_H_ZEHN;
			break;
		case 11:
		case 23:
			DE_MKF_H_ELF;
			break;
		default:
			;
		}
		break;
	case LANGUAGE_D3:
		switch (hours) {
		case 0:
		case 12:
		case 24:
			D3_H_ZWOELFE;
			break;
		case 1:
		case 13:
			D3_H_OISE;
			break;
		case 2:
		case 14:
			D3_H_ZWOIE;
			break;
		case 3:
		case 15:
			D3_H_DREIE;
			break;
		case 4:
		case 16:
			D3_H_VIERE;
			break;
		case 5:
		case 17:
			D3_H_FUENFE;
			break;
		case 6:
		case 18:
			D3_H_SECHSE;
			break;
		case 7:
		case 19:
			D3_H_SIEBNE;
			break;
		case 8:
		case 20:
			D3_H_ACHTE;
			break;
		case 9:
		case 21:
			D3_H_NEUNE;
			break;
		case 10:
		case 22:
			D3_H_ZEHNE;
			break;
		case 11:
		case 23:
			D3_H_ELFE;
			break;
		}
		break;
	case LANGUAGE_CH:
	case LANGUAGE_CH_GS:
		switch (hours) {
		case 0:
		case 12:
		case 24:
			CH_H_ZWOEUFI;
			break;
		case 1:
		case 13:
			CH_H_EIS;
			break;
		case 2:
		case 14:
			CH_H_ZWOEI;
			break;
		case 3:
		case 15:
			CH_H_DRUE;
			break;
		case 4:
		case 16:
			CH_H_VIER;
			break;
		case 5:
		case 17:
			CH_H_FUEFI;
			break;
		case 6:
		case 18:
			CH_H_SAECHSI;
			break;
		case 7:
		case 19:
			CH_H_SIEBNI;
			break;
		case 8:
		case 20:
			CH_H_ACHTI;
			break;
		case 9:
		case 21:
			CH_H_NUENI;
			break;
		case 10:
		case 22:
			CH_H_ZAENI;
			break;
		case 11:
		case 23:
			CH_H_EUFI;
			break;
		default:
			;
		}
		break;
	case LANGUAGE_EN:
		if (glatt) EN_OCLOCK;
		switch (hours) {
		case 0:
		case 12:
		case 24:
			EN_H_TWELVE;
			break;
		case 1:
		case 13:
			EN_H_ONE;
			break;
		case 2:
		case 14:
			EN_H_TWO;
			break;
		case 3:
		case 15:
			EN_H_THREE;
			break;
		case 4:
		case 16:
			EN_H_FOUR;
			break;
		case 5:
		case 17:
			EN_H_FIVE;
			break;
		case 6:
		case 18:
			EN_H_SIX;
			break;
		case 7:
		case 19:
			EN_H_SEVEN;
			break;
		case 8:
		case 20:
			EN_H_EIGHT;
			break;
		case 9:
		case 21:
			EN_H_NINE;
			break;
		case 10:
		case 22:
			EN_H_TEN;
			break;
		case 11:
		case 23:
			EN_H_ELEVEN;
			break;
		}
		break;
	case LANGUAGE_ES:
		switch (hours) {
		case 0:
		case 12:
		case 24:
			ES_H_DOCE;
			break;
		case 1:
		case 13:
			ES_H_UNA;
			break;
		case 2:
		case 14:
			ES_H_DOS;
			break;
		case 3:
		case 15:
			ES_H_TRES;
			break;
		case 4:
		case 16:
			ES_H_CUATRO;
			break;
		case 5:
		case 17:
			ES_H_CINCO;
			break;
		case 6:
		case 18:
			ES_H_SEIS;
			break;
		case 7:
		case 19:
			ES_H_SIETE;
			break;
		case 8:
		case 20:
			ES_H_OCHO;
			break;
		case 9:
		case 21:
			ES_H_NUEVE;
			break;
		case 10:
		case 22:
			ES_H_DIEZ;
			break;
		case 11:
		case 23:
			ES_H_ONCE;
			break;
		}
		break;
	case LANGUAGE_FR:
		switch (hours) {
		case 0:
		case 24:
			FR_H_MINUIT;
			break;
		case 12:
			FR_H_MIDI;
			break;
		case 1:
		case 13:
			FR_H_UNE;
			break;
		case 2:
		case 14:
			FR_H_DEUX;
			break;
		case 3:
		case 15:
			FR_H_TROIS;
			break;
		case 4:
		case 16:
			FR_H_QUATRE;
			break;
		case 5:
		case 17:
			FR_H_CINQ;
			break;
		case 6:
		case 18:
			FR_H_SIX;
			break;
		case 7:
		case 19:
			FR_H_SEPT;
			break;
		case 8:
		case 20:
			FR_H_HUIT;
			break;
		case 9:
		case 21:
			FR_H_NEUF;
			break;
		case 10:
		case 22:
			FR_H_DIX;
			break;
		case 11:
		case 23:
			FR_H_ONZE;
			break;
		}
		break;
	case LANGUAGE_IT:
		switch (hours) {
		case 0:
		case 12:
		case 24:
			IT_H_DODICI;
			break;
		case 1:
		case 13:
			IT_H_LUNA;
			break;
		case 2:
		case 14:
			IT_H_DUE;
			break;
		case 3:
		case 15:
			IT_H_TRE;
			break;
		case 4:
		case 16:
			IT_H_QUATTRO;
			break;
		case 5:
		case 17:
			IT_H_CINQUE;
			break;
		case 6:
		case 18:
			IT_H_SEI;
			break;
		case 7:
		case 19:
			IT_H_SETTE;
			break;
		case 8:
		case 20:
			IT_H_OTTO;
			break;
		case 9:
		case 21:
			IT_H_NOVE;
			break;
		case 10:
		case 22:
			IT_H_DIECI;
			break;
		case 11:
		case 23:
			IT_H_UNDICI;
			break;
		}
		break;
	case LANGUAGE_NL:
		if (glatt) NL_UUR;
		switch (hours) {
		case 0:
		case 12:
		case 24:
			NL_H_TWAALF;
			break;
		case 1:
		case 13:
			NL_H_EEN;
			break;
		case 2:
		case 14:
			NL_H_TWEE;
			break;
		case 3:
		case 15:
			NL_H_DRIE;
			break;
		case 4:
		case 16:
			NL_H_VIER;
			break;
		case 5:
		case 17:
			NL_H_VIJF;
			break;
		case 6:
		case 18:
			NL_H_ZES;
			break;
		case 7:
		case 19:
			NL_H_ZEVEN;
			break;
		case 8:
		case 20:
			NL_H_ACHT;
			break;
		case 9:
		case 21:
			NL_H_NEGEN;
			break;
		case 10:
		case 22:
			NL_H_TIEN;
			break;
		case 11:
		case 23:
			NL_H_ELF;
			break;
		}
		break;
	default:
		;
	}
}

void Renderer::clearEntryWords(uint8_t language, word matrix[16]) {
	switch (language) {
	case LANGUAGE_DE_DE:
	case LANGUAGE_DE_SW:
	case LANGUAGE_DE_BA:
	case LANGUAGE_DE_SA:
		matrix[0] &= 0b0010001111111111; // ES IST weg
		break;
	case LANGUAGE_DE_MKF_DE:
	case LANGUAGE_DE_MKF_SW:
	case LANGUAGE_DE_MKF_BA:
	case LANGUAGE_DE_MKF_SA:
		matrix[0] &= 0b0010001111111111; // ES IST weg
		break;
	case LANGUAGE_D3:
		matrix[0] &= 0b0010000111111111; // ES ISCH weg
		break;
	case LANGUAGE_CH:
	case LANGUAGE_CH_GS:
		matrix[0] &= 0b0010000111111111; // ES ISCH weg
		break;
	case LANGUAGE_EN:
		matrix[0] &= 0b0010011111111111; // IT IS weg
		break;
	case LANGUAGE_ES:
		matrix[0] &= 0b1000100011111111; // SON LAS weg
		matrix[0] &= 0b0011100111111111; // ES LA weg
		break;
	case LANGUAGE_FR:
		matrix[0] &= 0b0010001111111111; // IL EST weg
		break;
	case LANGUAGE_IT:
		matrix[0] &= 0b0000100111111111; // SONO LE weg
		matrix[1] &= 0b0111111111111111; // E (L'UNA) weg
		break;
	case LANGUAGE_NL:
		matrix[0] &= 0b0001001111111111; // HET IS weg
		break;
	default:
		;
	}
}

// AM oder PM einschalten
void Renderer::setAMPM(uint8_t hours, uint8_t language, word matrix[16]) {
	switch (language) {
	case LANGUAGE_DE_DE:
	case LANGUAGE_DE_SW:
	case LANGUAGE_DE_BA:
	case LANGUAGE_DE_SA:
		if (hours < 12) DE_AM;
		else DE_PM;
		break;
	case LANGUAGE_DE_MKF_DE:
	case LANGUAGE_DE_MKF_SW:
	case LANGUAGE_DE_MKF_BA:
	case LANGUAGE_DE_MKF_SA:
		if (hours < 12) DE_MKF_AM;
		else DE_MKF_PM;
		break;
	case LANGUAGE_D3:
		if (hours < 12) D3_AM;
		else D3_PM;
		break;
	case LANGUAGE_CH:
	case LANGUAGE_CH_GS:
		if (hours < 12) CH_AM;
		else CH_PM;
		break;
	case LANGUAGE_EN:
		if (hours < 12) EN_AM;
		else EN_PM;
		break;
	case LANGUAGE_ES:
		if (hours < 12) ES_AM;
		else ES_PM;
		break;
	case LANGUAGE_FR:
		if (hours < 12) FR_AM;
		else FR_PM;
		break;
	case LANGUAGE_IT:
		if (hours < 12) IT_AM;
		else IT_PM;
		break;
	case LANGUAGE_NL:
		if (hours < 12) NL_AM;
		else NL_PM;
		break;
	default:
		;
	}
}

// Sonderfall ES
void Renderer::ES_hours(uint8_t hours, word matrix[16]) {
	if ((hours == 1) || (hours == 13)) ES_ESLA;
	else ES_SONLAS;
}

// Sonderfall FR
void Renderer::FR_hours(uint8_t hours, word matrix[16]) {
	if ((hours == 1) || (hours == 13)) FR_HEURE;
	else if ((hours == 0) || (hours == 12) || (hours == 24));
	else FR_HEURES;
}

// Sonderfall IT
void Renderer::IT_hours(uint8_t hours, word matrix[16]) {
	if ((hours != 1) && (hours != 13)) IT_SONOLE;
	else IT_E;
}

// Minuten in den Screebuffer schreiben
void Renderer::setCorners(uint8_t minutes, word matrix[16]) {
	uint8_t b_minutes = minutes % 5;
	for (uint8_t i = 0; i < b_minutes; i++) {
		uint8_t j;
		j = (1 - i + 4) % 4;
		bitSet(matrix[j], 4);
	}
}

// Alarm-LED setzen
void Renderer::activateAlarmLed(word matrix[16]) {
	bitSet(matrix[4], 4);
}

// Alarm-LED setzen
void Renderer::deactivateAlarmLed(word matrix[16]) {
	bitClear(matrix[4], 4);
}

// Menuetext in den Screenbuffer schreiben
void Renderer::setSmallText(String menuText, eTextPos textPos, word matrix[16]) {
	if (menuText.length() == 2) {
		for (uint8_t i = 0; i < 5; i++) {
			for (uint8_t j = 0; j < menuText.length(); j++) {
				if (!isNumber(menuText[j])) matrix[textPos + i] |= (staben[menuText[j] - 'A'][i]) << (5 + ((j + 1) % 2) * 6);
				else matrix[textPos + i] |= (zahlenKlein[menuText[j] - '0'][i]) << (5 + ((j + 1) % 2) * 5);
			}
		}
	}
	else if (menuText.length() == 1) {
		for (uint8_t i = 0; i < 5; i++) {
			if (!isNumber(menuText[0])) matrix[textPos + i] |= (staben[menuText[0] - 'A'][i]) << 8;
			else matrix[textPos + i] |= (zahlenKlein[menuText[0] - '0'][i]) << 8;
		}
	}
}

// Test ob Zahl
boolean Renderer::isNumber(char symbol) {
	if ((symbol >= '0') && (symbol <= '9')) return true;
	else return false;
}

// Einen Pixel in den Screenbuffer schreiben
void Renderer::setPixelInScreenBuffer(uint8_t x, uint8_t y, word matrix[16]) {
	bitSet(matrix[y], 15-x);
}

// Einen Pixel aus dem Screenbuffer loeschen
void Renderer::unsetPixelInScreenBuffer(uint8_t x, uint8_t y, word matrix[16]) {
	bitClear(matrix[y], 15-x);
}

// Screenbuffer loeschen
void Renderer::clearScreenBuffer(word matrix[16]) {
	for (uint8_t i = 0; i < 16; i++) matrix[i] = 0b0000000000000000;
}

// Screenbuffer komplett einschalten
void Renderer::setAllScreenBuffer(word matrix[16]) {
	for (uint8_t i = 0; i < 16; i++) matrix[i] = 0b1111111111111111;
}
