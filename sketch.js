/*
Serial data - from Arduino to computer
Sends a byte to a webSocket server which sends the same byte
out through a serial port.
You can use this with the included Arduino example called PhysicalPixel.
Works with P5 editor as the socket/serial server, version 0.5.5 or later.
written 2 Oct 2015
by Tom Igoe

Edited by Carol Cheung April 4, 2018
p5 with Flora Neopixels, clicking through buttons to change colours between Red, Green and Blue.
Paired with with an Arduino code called neopixel.
*/

// Declare a "SerialPort" object
var serial;

var portName = '/dev/cu.usbmodem1421'; // fill in your serial port name here

let voice = new p5.Speech(); // speech synthesis object

function setup() {
    createCanvas(windowWidth, windowHeight);

    // make an instance of the SerialPort object
    serial = new p5.SerialPort();

    // Get a list the ports available
    // You should have a callback defined to see the results. See gotList, below:
    serial.list();

    // Assuming our Arduino is connected,  open the connection to it
    serial.open(portName);

    // When you get a list of serial ports that are available
    serial.on('list', gotList);

    // When you some data from the serial port
    serial.on('data', gotData);
    
}


// Got the list of ports
function gotList(thelist) {
  console.log("List of Serial Ports:");
  // theList is an array of their names
  for (var i = 0; i < thelist.length; i++) {
    // Display in the console
    console.log(i + " " + thelist[i]);
  }
}

// Called when there is data available from the serial port
function gotData() {
    var currentString = serial.readLine();
    console.log(currentString);
    
    if (currentString.length > 0) {
        if (currentString == "5 in") {
            voice.speak('red'); // say something
        } else if (currentString == "6 in") {
            voice.speak('orange');
        } else if (currentString == "7 in") {
            voice.speak('yellow');
        } else if (currentString == "8 in") {
            voice.speak('green');
        } else if (currentString == "9 in") {
            voice.speak('blue');
        } else if (currentString == "10 in") {
            voice.speak('indigo');
        } else if (currentString == "11 in") {
            voice.speak('violet');
        } else {
            voice.cancel();
        }
    }

}

function draw() {
    background(255,255,255);
    fill(0,0,0);
    text('I am a Rainbow Lamp.', 10, 30);
    text('Play with me!', 10, 50);
    text('Try standing further and closer to me!', 10, 70);
    textSize(20);
    textFont('Helvetica');
}
