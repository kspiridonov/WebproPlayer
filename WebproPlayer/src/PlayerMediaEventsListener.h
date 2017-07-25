/*
 * PlayerMediaEventsListener.h
 *
 *  Created on: Jul 25, 2017
 *      Author: ksp
 */

#ifndef PLAYERMEDIAEVENTSLISTENER_H_
#define PLAYERMEDIAEVENTSLISTENER_H_
#include "ppapi/cpp/instance.h"
#include "nacl_player/media_events_listener.h"
#include "ppapi/cpp/var_dictionary.h"
#include "messages.h"
class PlayerMediaEventsListener  : public Samsung::NaClPlayer::MediaEventsListener {
 public:

  PlayerMediaEventsListener(pp::Instance* instance): instance(instance){}

  void OnTimeUpdate(Samsung::NaClPlayer::TimeTicks time);

  void OnEnded();

  void OnError(Samsung::NaClPlayer::MediaPlayerError error);

 protected:
  pp::Instance* instance;
  void PostMessage(const pp::Var& message) {
    instance->PostMessage(message);
  }
};

#endif /* PLAYERMEDIAEVENTSLISTENER_H_ */
