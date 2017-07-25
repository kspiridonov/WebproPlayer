/*
 * PlayerBufferingListener.cpp
 *
 *  Created on: Jul 25, 2017
 *      Author: ksp
 */

#include <PlayerBufferingListener.h>



void PlayerBufferingListener::OnBufferingStart(){
}

void PlayerBufferingListener::OnBufferingProgress(uint32_t percent){

}


void PlayerBufferingListener::OnBufferingComplete(){
	  pp::VarDictionary message;
	  message.Set(Communication::keyMessageFromPlayer, Communication::valueBuffefingComplete);
	  PostMessage(message);
}
