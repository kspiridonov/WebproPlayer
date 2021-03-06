/**
 * @file common.js
 * @brief Common NaCl application page configuration.
 */

var logs;
var kLogPrefix = "LOG:";
var kErrorPrefix = "ERROR:";

function updateStatus(message) {
  document.getElementById("status").innerHTML = message;
}

/**
 * Return true when |s| starts with the string |prefix|.
 *
 * @param {string} s The string to search.
 * @param {string} prefix The prefix to search for in |s|.
 */
function startsWith(s, prefix) {
  return s.indexOf(prefix) === 0;
}

/**
 * Print message in the logs area if it has a specific prefix (defined in 
 * kLogPrefix or kErrorPrefix).
 * @param message - a string message
 * @returns true - if this message was a log or error message. 
 */
function printIfLog(message) {
  if (uses_logging == true) {
	if(typeof(message) == "object"){
		message = JSON.stringify(message);
	}
    logs.value += message;
    logs.scrollTop = logs.scrollHeight;
    return true;
  }
  return false;
}

function handleNaclCrash(event) {
  var nacl_module = document.getElementById("nacl_module");
  updateStatus("Crashed/exited with status: " + nacl_module.exitStatus);
}

function handleNaclLoad(event) {
  updateStatus("Loaded successfully.");
  if (exampleSpecificActionAfterNaclLoad && typeof(exampleSpecificActionAfterNaclLoad) == "function") {
    exampleSpecificActionAfterNaclLoad();
  }
  
  startPlay();

}

function proccessMessageFromPlayer(message){
	if(message.messageFromPlayer){
		if(message.messageFromPlayer == "PLAYING_END"){
			startPlay();
		}
	}
} 

function startPlay(){
	  var app = document.getElementById('nacl_module');
	  app.postMessage({
		  'messageToPlayer':'START_PLAY',
		  'url':url,
		  'x':0,
		  'y':0,
		  'width':1920,
		  'height':1080
			  })
} 

/**
 * Creates a NaCl module with params from project.js and attach listeners.
 * 
 * @param nmf_path_name - complete manifest file path with name
 * @param width - of a NaCl module"s view in pixels
 * @param height - of a NaCl module"s view in pixels
 */
function createNaclModule(nmf_path_name, left, top, width, height) {
  var nacl_elem = document.createElement("embed");
  nacl_elem.setAttribute("name", "nacl_module");
  nacl_elem.setAttribute("id", "nacl_module");
  nacl_elem.setAttribute("type", "application/x-nacl");
  nacl_elem.setAttribute("src", nmf_path_name);
  nacl_elem.setAttribute("width", width);
  nacl_elem.setAttribute("height", height);

  if ((top >= 0) && (left >= 0)) {
    nacl_elem.setAttribute("style","position:absolute; top:" + top + "px; left:" + left + "px;");
  }

  var listenerDiv = document.getElementById("listener");
  listenerDiv.appendChild(nacl_elem);

  // attach common listeners
  listenerDiv.addEventListener("message", handleNaclMessage, true);
  listenerDiv.addEventListener("crash", handleNaclCrash, true);
  listenerDiv.addEventListener("load", handleNaclLoad, true);
}

function getRAMUsageInfo() {
    try {
        var totalRAM = tizen.systeminfo.getTotalMemory();
        var availableRAM = tizen.systeminfo.getAvailableMemory();
        console.trace("The total memory size is " + totalRAM + " bytes.");
        console.trace("The available memory size is " + availableRAM + " bytes.");
        ramUsageInPercents = ((totalRAM - availableRAM) * 100) / totalRAM;
        console.log("RAM Usage in %: " + ramUsageInPercents);
        document.getElementById("ram").innerHTML = "RAM Usage: " + ramUsageInPercents + "%, date: " + (new Date()).toString();
    } catch (error) {
        console.error("Error get RAM usage: ", error);
    }
}

/**
 * Configure this page with project specific elements when document finishes
 * loading.
 */
document.addEventListener("DOMContentLoaded", function() {
  logs = document.getElementById("logs");
  if (uses_logging == false) {
    document.getElementById("logs_area").style.display = "none";
  }
  createNaclModule(nmf_path_name, nacl_left, nacl_top, nacl_width, nacl_height);
  updateStatus("Loading...");
  setInterval(getRAMUsageInfo,5000);
 
  
});
