#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "Player.h"

class NaClInstance : public pp::Instance {
 public:
	Player player;

  explicit NaClInstance(PP_Instance instance)
  : pp::Instance(instance),player(this,instance) {
  };

  /**
   * Handles messages from JS sent by <code>nacl_module.postMessage(...)</code>.
   * @see <code>HandleMessage</code> in <toolchain>/ppapi/cpp/instance.h file for more details.
   */
  virtual void HandleMessage(const pp::Var& message) {
	  player.HandleMessage(message);
  };

  /**
   * Initializes this instance with provided arguments listed in the <embed>
   * tag.
   * @see <code>Init()</code> in <toolchain>/ppapi/cpp/instance.h file for more details.
   */
  virtual bool Init(uint32_t argc, const char* argn[], const char* argv[]) {
	    return true;
	  };
};


/**
 * A NaCl app must have one class that implements <code>pp::Module</code>.
 */
class NaClModule : public pp::Module {
 public:
  NaClModule()
      : pp::Module() {
  }

  virtual ~NaClModule() {
  }

  /**
   * This method is called every time a browser encounters an <embed> element
   * on a web page.
   */
  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new NaClInstance(instance);
  }
};

namespace pp {

/**
 * This function is an entry point to a NaCl application.
 */
Module* CreateModule() {
  return new NaClModule();
}

}  // namespace pp




