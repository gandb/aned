var five = require("johnny-five");
var board = new five.Board({ port: "COM4" });

board.on("ready", function() {
  var led = new five.Led(6);
  //led.blink(500);
  
  led.pulse();
});