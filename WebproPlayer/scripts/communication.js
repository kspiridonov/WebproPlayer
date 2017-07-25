/**
 * @file communication.js
 * @brief NaCl application communication handler.
 * All NaCl <-> JS communication should be implemented in this file.
 */

/**
 * This function is called when a message from NaCl arrives.
 */
function handleNaclMessage(message_event) {
  var message = message_event.data;
  proccessMessageFromPlayer(message);
}
