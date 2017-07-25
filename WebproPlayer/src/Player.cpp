/*
 * Player.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: ksp
 */

#include <Player.h>

Player::Player(pp::Instance* naClInstance, PP_Instance instance ):ccFactory(this),naClInstance(naClInstance){
	 this->ppInstance = instance;

	 pp::InstanceHandle instanceHandle(this->ppInstance);
	 playerThread = MakeUnique<pp::SimpleThread>(instanceHandle);
	 playerThread->Start();


}

void Player::Play(string url,Rect viewRect){
	  this->Stop();
	  playerThread->message_loop().PostWork(
			  ccFactory.NewCallback(
	          &Player::Run,url,viewRect));
}

void Player::Stop(){
 this->Clean();
}

void Player::HandleMessage(const pp::Var& message){

	if (message.is_dictionary()) {
		 pp::VarDictionary msg(message);
		 pp::Var value = msg.Get(Communication::keyMessageToPlayer);
		 if(value.is_string()){
		    std::string messageToPlayer = value.AsString();
		    if(messageToPlayer == Communication::valuePlay){
		    	this->proccessStartPlay(msg);
		    }
		 } else {
			   this->sendError("value of: " + Communication::keyMessageToPlayer + " is not a string");
		 }
	 }else{
		 this->sendError("Command is not a json object");
	 }
}

void Player::proccessStartPlay(pp::VarDictionary msg){
	 pp::Var value = msg.Get(Communication::keyUrl);
    if(!value.is_string()){ this->sendError("value of: " + Communication::keyUrl + " is not a string or undefined"); return;}
    std::string url = value.AsString();
    value = msg.Get(Communication::keyX);
    if(!value.is_int()){this->sendError("value of: " + Communication::keyX + " is not a int or undefined"); return;}
    int x = value.AsInt();
    value = msg.Get(Communication::keyY);
    if(!value.is_int()){this->sendError("value of: " + Communication::keyY + " is not a int or undefined"); return;}
    int y = value.AsInt();
    value = msg.Get(Communication::keyWidth);
    if(!value.is_int()){this->sendError("value of: " + Communication::keyWidth + " is not a int or undefined"); return;}
    int width = value.AsInt();
    value = msg.Get(Communication::keyHeight);
    if(!value.is_int()){this->sendError("value of: " + Communication::keyHeight + " is not a int or undefined"); return;}
    int height = value.AsInt();
	Samsung::NaClPlayer::Rect view_rect_(x,y,width,height);
    this->Play(url,view_rect_);

}


void Player::Run(int32_t /*result*/,string url,Rect viewRect){

	  player = make_shared<MediaPlayer>();
	  bufferingListener = std::make_shared<PlayerBufferingListener>(naClInstance);
	  player->SetBufferingListener(bufferingListener);

	  mediaEventsListener = std::make_shared<PlayerMediaEventsListener>(naClInstance);
	  player->SetMediaEventsListener(mediaEventsListener);
	  dataSource =
	    std::make_shared<Samsung::NaClPlayer::URLDataSource>(url);
	  player->AttachDataSource(*dataSource);
	  int32_t ret = player->SetDisplayRect(viewRect);
	  int32_t ret1 = player->Play();
}



void Player::Clean(){
	 if (!player) return;
	    player->SetMediaEventsListener(nullptr);
	    player->SetSubtitleListener(nullptr);
	    player->SetBufferingListener(nullptr);
	    player->SetDRMListener(nullptr);
	    mediaEventsListener.reset();
	    bufferingListener.reset();
	    dataSource.reset();
	    player.reset();
};

void Player::sendError(std::string errorMessage){
	  pp::VarDictionary message;
	  message.Set(Communication::keyMessageFromPlayer, Communication::valueInitError);
	  message.Set(Communication::keyError, errorMessage);
	  naClInstance->PostMessage(message);
}

Player::~Player() {
	 this->Clean();
}

