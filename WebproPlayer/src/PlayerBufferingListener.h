/*
 * PlayerBufferingListener.h
 *
 *  Created on: Jul 25, 2017
 *      Author: ksp
 */

#ifndef SRC_PLAYERBUFFERINGLISTENER_H_
#define SRC_PLAYERBUFFERINGLISTENER_H_
#include "ppapi/cpp/instance.h"
#include "nacl_player/buffering_listener.h"
#include "ppapi/cpp/var_dictionary.h"
#include "messages.h"
using namespace Samsung::NaClPlayer;
class PlayerBufferingListener : public BufferingListener {
 public:
	PlayerBufferingListener(pp::Instance* instance): instance(instance){}

  // This event is delivered when NaCl player starts buffering data. It is
  // delivered in both URLDataSource and ESDataSource scenarios.
  void OnBufferingStart();

  // This event indicates a percentage of data buffered so far. It is delivered
  // only in the URLDataSource scenario.
  void OnBufferingProgress(uint32_t percent);

  // This event is delivered when NaCl player finishes buffering data. It is
  // delivered in both URLDataSource and ESDataSource scenarios.
  void OnBufferingComplete();


 protected:
  pp::Instance* instance;
  void PostMessage(const pp::Var& message) {
    instance->PostMessage(message);
  }
};

#endif /* SRC_PLAYERBUFFERINGLISTENER_H_ */
