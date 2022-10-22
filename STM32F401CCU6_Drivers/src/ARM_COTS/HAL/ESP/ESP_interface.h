/* FILENAME: ESP_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 10/17/2022
*/
#ifndef _ESP_interface_H
#define _ESP_interface_H



void MESP_vInit(void) ;

void MESP_vConnectToAccessPoint( c8* ssid, c8* password ) ;

void MESP_vOpenServerTCPConnection( c8* serverip, c8* portnum ) ;

void MESP_vSendHttpRequest( c8* url, c8* length ) ;



#endif //_ESP_interface_H
