/*
 * Player.h
 *
 *  Created on: Jul 24, 2017
 *      Author: ksp
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_
#include <string>
#include "ppapi/cpp/instance.h"
#include "nacl_player/media_player.h"
#include "nacl_player/media_data_source.h"
#include "nacl_player/media_events_listener.h"
#include "ppapi/utility/threading/simple_thread.h"
#include "ppapi/utility/completion_callback_factory.h"
#include "nacl_player/common.h"

#include "nacl_player/error_codes.h"
#include "nacl_player/url_data_source.h"

#include "PlayerBufferingListener.h"
#include "PlayerMediaEventsListener.h"

#include "ppapi/cpp/var_dictionary.h"

#include "messages.h"

using namespace std;
using namespace Samsung::NaClPlayer;

template <typename T, class... Args>
std::unique_ptr<T> MakeUnique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


class Player {
public:
	Player(pp::Instance* naClInstance, PP_Instance instance );
	virtual ~Player();
	void Play(string url,Rect view_rect);
	void Stop();
	void HandleMessage(const pp::Var& message);
private:
	shared_ptr<MediaPlayer> player;
	pp::Instance* naClInstance;
	PP_Instance ppInstance;
	shared_ptr<MediaDataSource> dataSource;
	unique_ptr<pp::SimpleThread> playerThread;
	pp::CompletionCallbackFactory<Player> ccFactory;
	shared_ptr<PlayerMediaEventsListener> mediaEventsListener;
	 std::shared_ptr<PlayerBufferingListener> bufferingListener;
	void Run(int32_t /*result*/, string url,Rect viewRect);
	void Clean();
	void proccessStartPlay(pp::VarDictionary msg);
	void sendError(std::string message);

};

#endif /* SRC_PLAYER_H_ */
