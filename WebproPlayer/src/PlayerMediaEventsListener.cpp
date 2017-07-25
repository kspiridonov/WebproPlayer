/*
 * PlayerMediaEventsListener.cpp
 *
 *  Created on: Jul 25, 2017
 *      Author: ksp
 */

#include "PlayerMediaEventsListener.h"

void PlayerMediaEventsListener::OnEnded(){
	  pp::VarDictionary message;
	  message.Set(Communication::keyMessageFromPlayer, Communication::valuePlayingEnd);
	  PostMessage(message);

}

void PlayerMediaEventsListener::OnTimeUpdate(Samsung::NaClPlayer::TimeTicks time){
	  pp::VarDictionary message;
	  message.Set(Communication::keyMessageFromPlayer, Communication::valueTimeUpdate);
	  message.Set(Communication::keyTime, time);
	  PostMessage(message);

}

void PlayerMediaEventsListener::OnError(Samsung::NaClPlayer::MediaPlayerError error){
	  pp::VarDictionary message;
	  message.Set(Communication::keyMessageFromPlayer, Communication::valuePlayError);
	  message.Set(Communication::keyError, error);
	  PostMessage(message);
}
