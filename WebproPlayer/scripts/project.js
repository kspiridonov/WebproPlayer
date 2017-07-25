/**
 * @file project.js
 * @brief Project specific UI configuration.
 * Variables below will configure project related data.
 * @see common.js for more details.
 */

var nmf_path_name = "CurrentBin/WebproPlayer.nmf";

// Size in pixels of NaCl plugin on page.
var nacl_width = 1920;
var nacl_height = 1080;

// Define top/left position of plugin to use absolute positioning
// of the plugin on page or set -1.
var nacl_top = -1;
var nacl_left = -1;

var uses_logging = false;  // If "false" - hides logs area on the HTML page.

function exampleSpecificActionAfterNaclLoad() {
  /* Fill this function with your code (if needed). */
}
var url = "file:///opt/usr/apps/"+tizen.application.getAppInfo().packageId+"/res/wgt/resources/red.mp4";