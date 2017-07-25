/*!
 * messages.h (https://github.com/SamsungDForum/NativePlayer)
 * Copyright 2016, Samsung Electronics Co., Ltd
 * Licensed under the MIT license
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @author Tomasz Borkowski
 * @author Michal Murgrabia
 */

#ifndef NATIVE_PLAYER_INC_COMMUNICATOR_MESSAGES_H_
#define NATIVE_PLAYER_INC_COMMUNICATOR_MESSAGES_H_

#include <string>

namespace Communication {
//keys
const std::string keyMessageToPlayer = "messageToPlayer";
const std::string keyMessageFromPlayer = "messageFromPlayer";
const std::string keyUrl = "url";
const std::string keyX = "x";
const std::string keyY = "y";
const std::string keyWidth = "width";
const std::string keyHeight = "height";
const std::string keyTime = "time";
const std::string keyError = "error";
// values
const std::string valueBuffefingComplete = "BUFFERING_COMPLETE";
const std::string valuePlayingEnd = "PLAYING_END";
const std::string valueTimeUpdate = "TIME_UPDATE";
const std::string valuePlayError = "PLAY_ERROR";
const std::string valueInitError = "INIT_ERROR";
const std::string valuePlay = "START_PLAY";
const std::string valueStop = "STOP_PLAY";
}  // namespace Communication

#endif  // NATIVE_PLAYER_INC_COMMUNICATOR_MESSAGES_H_
